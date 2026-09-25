#!/usr/bin/env python3
"""Extract the actor-id -> constructor dispatch table from the retail DOL.

`fn_801F9484` (0x61AC bytes in the factory TU 0x801F9484-0x80204638) is the actor
factory: it binary-searches the 4-character actor id and calls the matching
constructor. The search is written out as `lis rX,<hi>; addi/ori rY,rX,<lo>;
cmpw <idReg>, rY; beq <node>`, so the ids are recoverable from the instruction
stream alone - together with `docs/gamemap/actor_ctors.csv` (ctor -> vtable ->
override set) that closes the chain id -> factory -> class.

Usage: tools/actor_ids.py [worktree]        (default: the current directory)

Method (and its limits, stated because this is a heuristic):
  * `lis`+`addi`/`ori` constants are tracked per register within the function;
  * a `cmpw`/`cmplw` against such a constant whose four bytes are all printable
    ASCII is taken as an id comparison, and the target of the next `beq` is
    recorded as that id's dispatch node;
  * the node is walked forward for up to 40 instructions looking for a `bl` to an
    address that appears as a constructor in actor_ctors.csv.
An id whose node does not reach a known ctor within that window is emitted with an
empty ctor column rather than guessed.

Self-check: the five ids that are known independently (BOTS/STGN/DWAP/GFBS/TJIJ)
must come out paired with their actors' ctor addresses from actor_ctors.csv.
"""
import csv
import os
import re
import struct
import sys

FACTORY_FN = 0x801F9484
FACTORY_SIZE = 0x61AC
TEXT_VA, TEXT_OFF = 0x80021840, 0x2600


def sx(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def decode(dol, addr, size):
    """-> list of (addr, op, xo, rd, ra, rb, simm, tgt, link, lk)"""
    out, off = [], TEXT_OFF + (addr - TEXT_VA)
    for _ in range(size // 4):
        w = struct.unpack_from(">I", dol, off)[0]
        op = w >> 26
        rd, ra, rb = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        xo = (w >> 1) & 0x3FF
        simm = sx(w & 0xFFFF, 16)
        tgt = addr + sx(w & 0xFFFC, 16) if op == 16 else None
        link = addr + sx(w & 0x03FFFFFC, 26) if op == 18 else None
        out.append((addr, op, xo, rd, ra, rb, simm, tgt, link, w & 1))
        addr += 4
        off += 4
    return out


# instructions that write a register (op -> which field is the destination)
LOADS = {32, 33, 34, 35, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51}


def fourcc(v):
    if not v or v > 0xFFFFFFFF:
        return ""
    b = v.to_bytes(4, "big")
    return b.decode("ascii") if all(0x20 <= c < 0x7F for c in b) else ""



def resolve(node, ins, at, ctors, depth=0):
    """Follow a dispatch node to the constructor it calls.

    A node is a basic block: scan it for the first `bl` to a known constructor, and
    follow at most three further branches (`beq`/`b`) if it is another search node.
    Returns "" when the walk does not find one - never a guess.
    """
    if node is None or depth > 3 or node not in at:
        return ""
    seen = set()
    i = at[node]
    while i < len(ins):
        addr, op, xo, rd, ra, rb, simm, tgt, link, lk = ins[i]
        if link is not None and lk and link in ctors:
            return "0x%08X" % link
        if op == 18 and not lk and link is not None:          # unconditional b
            return resolve(link, ins, at, ctors, depth + 1) if link not in seen else ""
        if op == 16 and tgt is not None:                      # conditional branch
            if tgt in seen:
                return ""
            seen.add(tgt)
            r = resolve(tgt, ins, at, ctors, depth + 1)
            if r:
                return r
        if op in (19, 18) and link is None and tgt is None:   # end of block
            return ""
        i += 1
        if i - at[node] > 400:
            break
    return ""


def main():
    root = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    ctors = {}
    with open(os.path.join(root, "docs/gamemap/actor_ctors.csv")) as fh:
        for r in csv.DictReader(fh):
            if r.get("calls_Actor_ctor") == "yes":
                ctors[int(r["ctor"], 16)] = r
    dol = open(os.path.join(root, "orig/G4SE01/sys/main.dol"), "rb").read()
    ins = decode(dol, FACTORY_FN, FACTORY_SIZE)
    at = {i[0]: k for k, i in enumerate(ins)}

    # constant tracking with invalidation: reg -> value (None = unknown)
    const = {}
    compares = []  # (addr, index, cmp_reg, value)
    for i, (addr, op, xo, rd, ra, rb, simm, tgt, link, lk) in enumerate(ins):
        if op == 15:                      # addis / lis
            const[rd] = (simm << 16) & 0xFFFFFFFF if ra == 0 else None
        elif op == 14:                    # addi
            const[rd] = ((0 if ra == 0 else const.get(ra)) + simm) & 0xFFFFFFFF \
                if ra == 0 or const.get(ra) is not None else None
        elif op == 24:                    # ori
            const[rd] = (const[ra] | (simm & 0xFFFF)) if const.get(ra) is not None else None
        elif op == 31:
            if xo == 0 and const.get(rb) is not None:      # cmpw crfD, rA, rB
                compares.append((addr, i, ra, const[rb]))
            elif xo == 32 and const.get(rb) is not None:   # cmplw
                compares.append((addr, i, ra, const[rb]))
            else:
                const[rd] = None                           # any other X-form write
        elif op in (10, 11):              # cmpwi / cmplwi: the id's low half alone
            pass
        elif op in LOADS or op in (18, 19, 36, 37, 38, 39, 30, 12, 13):
            if op not in (18, 19):
                const[rd] = None

    # the id register is the one compared against many distinct 4CC constants
    from collections import Counter
    cnt = Counter(r for (_a, _i, r, v) in compares if fourcc(v))
    if not cnt:
        print("no id comparisons found")
        return
    id_reg, _ = cnt.most_common(1)[0]

    rows, unresolved = [], 0
    for addr, idx, reg, val in compares:
        if reg != id_reg:
            continue
        cc = fourcc(val)
        if not cc:
            continue
        node = None
        for j in range(idx + 1, min(idx + 6, len(ins))):
            if ins[j][1] == 16:
                node = ins[j][7]
                break
        ctor = resolve(node, ins, at, ctors) if node is not None else ""
        if not ctor:
            unresolved += 1
        c = ctors.get(int(ctor, 16), {}) if ctor else {}
        rows.append({"id": "0x%08X" % val, "fourcc": cc, "cmp_addr": "0x%08X" % addr,
                     "node": "0x%08X" % node if node else "", "ctor": ctor,
                     "vtable": c.get("vtable", ""), "overrides": c.get("override_slots", "")})

    out = os.path.join(root, "docs/gamemap/actor_ids.csv")
    with open(out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()), lineterminator="\n")
        w.writeheader()
        w.writerows(rows)

    by_cc = {}
    for r in rows:
        by_cc.setdefault(r["fourcc"], r)
    print("wrote %s: %d ids for the id register r%d, %d resolved to a known ctor, %d unresolved"
          % (out, len(rows), id_reg, len(rows) - unresolved, unresolved))
    for cc in ("BOTS", "STGN", "DWAP", "GFBS", "TJIJ"):
        r = by_cc.get(cc)
        print("  anchor %-5s -> %s" % (cc, (r["ctor"], r["vtable"]) if r else "MISSING"))


if __name__ == "__main__":
    main()
