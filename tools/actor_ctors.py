#!/usr/bin/env python3
"""Map the actor factory TU's constructors to their actor class (from the DOL).

The retail TU at 0x801F9484-0x80204638 holds the per-actor factory functions.
An actor constructor there is recognisable without any source: it calls
`Actor::Actor()` (0x801F5AE0) and then stores a vtable pointer into offset 0:

    801FF7BC  bl    __ct__5ActorFv
    801FF7D4  lis   r4, 0x804B0000     -> lbl_804AA7A8@ha
    801FF7DC  addi  r0, r4, 0xA7A8     -> + 0xA7A8 = 0x804AA7A8
    801FF7E0  stw   r0, 0x0(r31)         0x804AA7A8 is __vt__4STGN

The vtable address is the class key: it joins the factory function to the actor
TU's own `__vt__<class>` symbol once that unit is named in symbols.txt.

Usage:  tools/actor_ctors.py [worktree]      (default: the current directory)

Reads config/G4SE01/symbols.txt and orig/G4SE01/sys/main.dol (both offline; no
build output involved) and writes docs/gamemap/actor_ctors.csv.
"""
import csv
import os
import re
import struct
import sys

FACTORY_START, FACTORY_END = 0x801F9484, 0x80204638
ACTOR_CTOR = 0x801F5AE0

# main.dol: .text is at 0x80021840 in memory, 0x2600 in the file (dtk dol info)
TEXT_VA, TEXT_OFF = 0x80021840, 0x2600

sym_re = re.compile(
    r"^(\S+) = \.(text|data):0x([0-9A-Fa-f]+); // type:(function|object) size:0x([0-9A-Fa-f]+)"
)


def sx(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def decode(dol, addr, size):
    """Yield (addr, opcode, rd, ra, rb, simm, target_or_none) for one function."""
    out = []
    off = TEXT_OFF + (addr - TEXT_VA)
    for _ in range(size // 4):
        w = struct.unpack_from(">I", dol, off)[0]
        op = w >> 26
        rd = (w >> 21) & 31
        ra = (w >> 16) & 31
        rb = (w >> 11) & 31
        simm = sx(w & 0xFFFF, 16)
        tgt = None
        if op == 18 and (w & 1):  # bl
            tgt = addr + sx((w & 0x03FFFFFC), 26)
        out.append((addr, op, rd, ra, rb, simm, tgt))
        addr += 4
        off += 4
        if op == 19 and ((w >> 1) & 0x3FF) == 16:  # blr
            break
    return out


def classify(dol, addr, size):
    """-> (vtable_addr or None, calls_actor_ctor)"""
    ins = decode(dol, addr, size)
    calls = any(t == ACTOR_CTOR for *_x, t in ins if t)
    hi = {}
    vt = None
    for i, (a, op, rd, ra, rb, simm, tgt) in enumerate(ins):
        if op == 15 and ra == 0:  # lis
            hi[rd] = simm << 16
        elif op == 14 and ra in hi:  # addi rD, rA, imm
            val = (hi[ra] + simm) & 0xFFFFFFFF
            if 0x80480000 <= val < 0x804B0000 and vt is None:
                vt = val
            hi[rd] = val
        elif op == 24 and ra in hi:  # ori rD, rA, imm  (second half of an address)
            val = hi[ra] | (simm & 0xFFFF)
            if 0x80480000 <= val < 0x804B0000 and vt is None:
                vt = val
    return vt, calls


# Two constructors whose vtable is established independently (BOTS' __vt__4BOTS is
# named in symbols.txt; 0x804AA7A8 is __vt__4STGN on the actor's own branch). The
# tool must reproduce both or the decoder is wrong.
ANCHORS = {0x802020F0: 0x8049C7F0, 0x801FF7BC: 0x804AA7A8}


def selftest(root):
    dol = open(os.path.join(root, "orig/G4SE01/sys/main.dol"), "rb").read()
    for addr, want in ANCHORS.items():
        vt, calls = classify(dol, addr, 0x3C)
        ok = calls and vt == want
        print("%s 0x%08X -> vtable 0x%08X (want 0x%08X), calls Actor::Actor()=%s"
              % ("PASS" if ok else "FAIL", addr, vt or 0, want, calls))
        if not ok:
            return False
    return True


def main():
    root = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    if "--selftest" in sys.argv:
        raise SystemExit(0 if selftest(root) else 1)
    funcs, names = [], {}
    with open(os.path.join(root, "config/G4SE01/symbols.txt")) as fh:
        for line in fh:
            m = sym_re.match(line)
            if not m:
                continue
            name, sec, addr, kind, size = (
                m.group(1), m.group(2), int(m.group(3), 16), m.group(4), int(m.group(5), 16)
            )
            names[addr] = name
            if sec == "text" and kind == "function":
                funcs.append((addr, size, name))
    dol = open(os.path.join(root, "orig/G4SE01/sys/main.dol"), "rb").read()

    rows = []
    for addr, size, name in sorted(funcs):
        if not (FACTORY_START <= addr < FACTORY_END):
            continue
        vt, calls = classify(dol, addr, size)
        vt_name = names.get(vt, "") if vt else ""
        rows.append({
            "ctor": "0x%08X" % addr,
            "size": "0x%X" % size,
            "calls_Actor_ctor": "yes" if calls else "no",
            "vtable": "0x%08X" % vt if vt else "",
            "vtable_symbol": vt_name,
            "class": vt_name[6:] if vt_name.startswith("__vt__") else "",
        })
    out = os.path.join(root, "docs/gamemap/actor_ctors.csv")
    with open(out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()), lineterminator="\n")
        w.writeheader()
        w.writerows(rows)
    actors = [r for r in rows if r["calls_Actor_ctor"] == "yes" and r["vtable"]]
    print("wrote %s: %d functions, of which %d actor constructors (%d already named)"
          % (out, len(rows), len(actors), sum(1 for r in actors if r["class"])))


if __name__ == "__main__":
    main()
