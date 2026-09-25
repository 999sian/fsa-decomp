#!/usr/bin/env python3
"""Map a compiled MWCC object onto the retail main.dol.

usage: objmap.py OBJ.o ANCHOR_FUNC=0xADDR [--apply] [--unit path/to/file.cpp]

Given one known retail address of a (non-weak) function in OBJ, walks the
object's .text in order (skipping weak functions that the retail linker
deduplicated), then resolves every relocation against the retail bytes to find
the retail address of each referenced symbol (functions, data, externals).
Data sections are placed from resolved symbol addresses.

Prints the proposed symbol renames and the split ranges. With --apply, edits
config/G4SE01/symbols.txt (renaming/adding symbols) and, with --unit, appends
the split to config/G4SE01/splits.txt.
"""
import re
import struct
import sys
from collections import defaultdict

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = "/home/sian/Documents/FSA Decomp"
DOL = f"{ROOT}/orig/G4SE01/sys/main.dol"
SYMS = f"{ROOT}/config/G4SE01/symbols.txt"
SPLITS = f"{ROOT}/config/G4SE01/splits.txt"
SDA_BASE = 0x80541BC0
SDA2_BASE = 0x80542FA0

d = open(DOL, "rb").read()
offs = struct.unpack(">18I", d[0:72])
addrs = struct.unpack(">18I", d[72:144])
sizes = struct.unpack(">18I", d[144:216])


def rd(a, n=4):
    for o, ad, s in zip(offs, addrs, sizes):
        if s and ad <= a < ad + s:
            return d[o + a - ad : o + a - ad + n]
    return None


def rw(a):
    b = rd(a)
    return struct.unpack(">I", b)[0] if b else None


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


# ---- symbols.txt ----
SYMLINE = re.compile(r"^(\S+) = (\S+):0x([0-9A-Fa-f]+); //(.*)$")


def load_syms():
    out = []
    for line in open(SYMS):
        line = line.rstrip("\n")
        m = SYMLINE.match(line)
        if not m:
            out.append([None, None, None, line])
            continue
        out.append([m.group(1), m.group(2), int(m.group(3), 16), m.group(4)])
    return out


def sec_of_addr(syms, a):
    # section = that of the closest symbol at or below a
    best = None
    for n, s, ad, _ in syms:
        if n is None:
            continue
        if ad <= a and (best is None or ad > best[1]):
            best = (s, ad)
    return best[0] if best else None


# ---- object ----
REL24, ADDR32, HA, LO, SDA21, ADDR16_HI, ADDR16 = 10, 1, 6, 4, 109, 5, 3


def mask(w, rtype):
    op = w >> 26
    if op == 18:
        return 0xFC000003
    if op == 16:
        return 0xFFFF0003
    if rtype == SDA21:
        return 0xFC000000 | (0x1F << 21)  # keep rD, drop rA+imm
    if rtype is not None:
        return 0xFFFF0000
    return 0xFFFFFFFF


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    args = [a for a in args if a != "--apply"]
    unit = None
    if "--unit" in args:
        i = args.index("--unit")
        unit = args[i + 1]
        del args[i : i + 2]
    objpath = args[0]
    anchor_name, anchor_addr = args[1].split("=")
    anchor_addr = int(anchor_addr, 16)

    f = ELFFile(open(objpath, "rb"))
    secs = {i: s for i, s in enumerate(f.iter_sections())}
    symtab = f.get_section_by_name(".symtab")
    syms = list(symtab.iter_symbols())
    relocs = defaultdict(list)  # secidx -> [(off, type, symidx, addend)]
    for s in f.iter_sections():
        if isinstance(s, RelocationSection):
            tgt = s["sh_info"]
            for r in s.iter_relocations():
                relocs[tgt].append((r["r_offset"], r["r_info_type"], r["r_info_sym"], r["r_addend"]))

    text_idx = [i for i, s in secs.items() if s.name == ".text"][0]
    text = secs[text_idx].data()
    rel_at = {o: t for o, t, _, _ in relocs[text_idx]}
    funcs = sorted(
        [s for s in syms if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] == text_idx],
        key=lambda s: s["st_value"],
    )

    def matches(fs, addr):
        o, n = fs["st_value"], fs["st_size"]
        for k in range(0, n, 4):
            w = struct.unpack(">I", text[o + k : o + k + 4])[0]
            m = mask(w, rel_at.get(o + k) or rel_at.get(o + k + 2))
            r = rw(addr + k)
            if r is None or (r & m) != (w & m):
                return False
        return True

    ai = [i for i, s in enumerate(funcs) if s.name == anchor_name]
    assert ai, "anchor not in obj"
    ai = ai[0]
    # try each possible start such that walking reaches anchor at anchor_addr
    placement = None
    pre = funcs[:ai]
    for mask_bits in range(1 << sum(1 for s in pre if s["st_info"]["bind"] == "STB_WEAK")):
        # choose which preceding weak funcs are retained
        keep, bit = [], 0
        for s in pre:
            if s["st_info"]["bind"] == "STB_WEAK":
                keep.append(bool(mask_bits >> bit & 1))
                bit += 1
            else:
                keep.append(True)
        start = anchor_addr - sum(s["st_size"] for s, k in zip(pre, keep) if k)
        cur, pl, ok = start, {}, True
        for s, k in zip(pre, keep):
            if k:
                if not matches(s, cur):
                    ok = False
                    break
                pl[s.name] = cur
                cur += s["st_size"]
        if ok:
            placement = (start, pl)
            break
    assert placement, "cannot place preceding functions"
    start, fplace = placement
    cur = anchor_addr
    dropped = []
    for s in funcs[ai:]:
        if matches(s, cur):
            fplace[s.name] = cur
            cur += s["st_size"]
        elif s["st_info"]["bind"] == "STB_WEAK":
            dropped.append(s.name)
        else:
            sys.exit(f"mismatch at {s.name} (expected {cur:08x})")
    text_range = (start, cur)
    func_off = {s.name: s["st_value"] for s in funcs}

    # resolve relocs in .text
    resolved = {}  # symname -> addr
    conflicts = []

    def note(name, addr):
        if name in resolved and resolved[name] != addr:
            conflicts.append((name, resolved[name], addr))
        resolved.setdefault(name, addr)

    for n, a in fplace.items():
        note(n, a)
    hilo = defaultdict(lambda: [None, None])
    for off, t, si, add in relocs[text_idx]:
        fn = max((s for s in funcs if s["st_value"] <= off), key=lambda s: s["st_value"])
        if fn.name not in fplace:
            continue
        ra = fplace[fn.name] + (off - fn["st_value"])
        sym = syms[si]
        name = sym.name if sym["st_info"]["type"] != "STT_SECTION" else "$sec:" + secs[sym["st_shndx"]].name
        if t == REL24:
            w = rw(ra)
            li = w & 0x03FFFFFC
            if li & 0x02000000:
                li -= 0x04000000
            note(name, ra + li - add)
        elif t == SDA21:
            w = rw(ra)
            rA = (w >> 16) & 0x1F
            base = SDA_BASE if rA == 13 else SDA2_BASE if rA == 2 else 0
            note(name, base + sext16(w & 0xFFFF) - add)
        elif t in (HA, LO):
            w = struct.unpack(">H", rd(ra, 2))[0]
            key = (name, add)
            hilo[key][0 if t == HA else 1] = w
        else:
            print(f"warn: unhandled reloc type {t} for {name}")
    for (name, add), (hi, lo) in hilo.items():
        if hi is None or lo is None:
            print(f"warn: unpaired ha/lo for {name}")
            continue
        note(name, ((hi << 16) + sext16(lo) - add) & 0xFFFFFFFF)

    # place data sections
    placed = {text_idx: text_range}
    sym_by_sec = defaultdict(list)
    for s in syms:
        if isinstance(s["st_shndx"], int) and s["st_shndx"] > 0 and s["st_info"]["type"] in ("STT_OBJECT", "STT_NOTYPE", "STT_FUNC"):
            sym_by_sec[s["st_shndx"]].append(s)
    for idx, sec in secs.items():
        if idx == text_idx or not (sec["sh_flags"] & 2) or sec["sh_size"] == 0:
            continue
        bases = defaultdict(int)
        for s in sym_by_sec[idx]:
            if s.name in resolved:
                bases[resolved[s.name] - s["st_value"]] += 1
        if "$sec:" + sec.name in resolved:
            bases[resolved["$sec:" + sec.name]] += 100
        if not bases:
            print(f"warn: section {sec.name} not placed (unreferenced)")
            continue
        if len(bases) > 1:
            print(f"warn: section {sec.name} has several bases {[hex(b) for b in bases]}")
        base = max(bases, key=bases.get)
        placed[idx] = (base, base + sec["sh_size"])
        for s in sym_by_sec[idx]:
            note(s.name, base + s["st_value"])
        # data relocs (vtables etc.)
        for off, t, si, add in relocs[idx]:
            sym = syms[si]
            name = sym.name if sym["st_info"]["type"] != "STT_SECTION" else "$sec:" + secs[sym["st_shndx"]].name
            if t == ADDR32:
                v = rw(base + off)
                if v:
                    note(name, v - add)
    if conflicts:
        print("CONFLICTS:")
        for c in conflicts:
            print(f"  {c[0]} {c[1]:08x} vs {c[2]:08x}")

    # symbol info
    info = {}
    for s in syms:
        if not s.name or s["st_info"]["type"] in ("STT_FILE", "STT_SECTION"):
            continue
        defined = isinstance(s["st_shndx"], int) and s["st_shndx"] > 0
        info[s.name] = dict(
            defined=defined,
            size=s["st_size"] if defined else None,
            bind=s["st_info"]["bind"],
            type=s["st_info"]["type"],
            sec=secs[s["st_shndx"]].name if defined else None,
        )

    print(f"dropped weak funcs (defined elsewhere): {dropped}")
    print("sections:")
    for idx, (a, b) in placed.items():
        print(f"  {secs[idx].name:10s} {a:08x}-{b:08x}")

    ss = load_syms()
    by_addr = defaultdict(list)
    for i, (n, s, a, rest) in enumerate(ss):
        if n is not None:
            by_addr[a].append(i)
    names = {e[0]: i for i, e in enumerate(ss) if e[0]}
    changes = []
    for name, addr in sorted(resolved.items(), key=lambda x: x[1]):
        if name.startswith("$sec:"):
            continue
        inf = info.get(name, {})
        cands = [i for i in by_addr.get(addr, []) if "type:label" not in ss[i][3]]
        cur = ss[cands[0]][0] if cands else None
        if name in names and ss[names[name]][2] != addr:
            print(f"!! {name} already in symbols.txt at {ss[names[name]][2]:08x}, now {addr:08x}")
            continue
        if cur == name:
            continue
        changes.append((name, addr, cur, inf))
        print(f"  {addr:08x} {cur or '(new)':30s} -> {name}")

    if not apply:
        return
    for name, addr, cur, inf in changes:
        bind = inf.get("bind")
        scope = {"STB_GLOBAL": "global", "STB_LOCAL": "local", "STB_WEAK": "weak"}.get(bind, "global")
        if not inf.get("defined") and name in dropped:
            scope = "weak"
        if cur is not None:
            i = names[cur]
            rest = ss[i][3]
            rest = re.sub(r"scope:\S+", f"scope:{scope}", rest) if "scope:" in rest else rest + f" scope:{scope}"
            if inf.get("defined") and inf.get("size"):
                rest = re.sub(r"size:0x[0-9A-Fa-f]+", f"size:0x{inf['size']:X}", rest)
            ss[i][0] = name
            ss[i][3] = rest
            names[name] = i
        else:
            sec = sec_of_addr(ss, addr)
            typ = "function" if inf.get("type") == "STT_FUNC" else "object"
            size = f" size:0x{inf['size']:X}" if inf.get("size") else ""
            ss.append([name, sec, addr, f" type:{typ}{size} scope:{scope}"])
            names[name] = len(ss) - 1
    # remove auto symbols strictly inside defined objects of this unit
    kill = set()
    for name, addr in resolved.items():
        inf = info.get(name)
        if not inf or not inf["defined"] or not inf["size"]:
            continue
        for i, e in enumerate(ss):
            if e[0] and addr < e[2] < addr + inf["size"] and re.match(r"^(lbl_|fn_|@)", e[0]) and e[0] not in resolved:
                kill.add(i)
    ss = [e for i, e in enumerate(ss) if i not in kill]
    ss.sort(key=lambda e: (e[2] if e[2] is not None else 0))
    with open(SYMS, "w") as fo:
        for n, s, a, rest in ss:
            if n is None:
                fo.write(rest + "\n")
            else:
                fo.write(f"{n} = {s}:0x{a:08X}; //{rest}\n")
    print(f"applied {len(changes)} renames, removed {len(kill)} inner symbols")
    if unit:
        with open(SPLITS, "a") as fo:
            fo.write(f"\n{unit}:\n")
            order = [".text", ".ctors", ".dtors", ".rodata", ".data", ".bss", ".sdata", ".sbss", ".sdata2", ".sbss2"]
            for sname in order:
                for idx, (a, b) in placed.items():
                    if secs[idx].name == sname:
                        fo.write(f"\t{sname:11s} start:0x{a:08X} end:0x{b:08X}\n")
        print("split appended")


main()
