#!/usr/bin/env python3
"""Locate a Matching object's `.sdata2` constant-pool range in the JP/PAL DOLs.

Multi-version linking of FSA needs each object's non-.text sections placed at the
correct regional address. For `.sdata2` the raw constant bytes are NOT unique
(e.g. {0.5, 1.0} appears in dozens of pools), so a byte search is ambiguous.
The unambiguous locator uses the object's own `R_PPC_EMB_SDA21` relocations:

  * MWCC references each per-TU anonymous constant (`@N`, a LOCAL OBJECT symbol
    defined in the object's `.sdata2`) with an `lfs`/`lfd rX, off(r2)` instruction.
  * `r2` holds `_SDA2_BASE_`, set once at boot in `__init_registers`
    (`addis r2,r0,HI; ori r2,r2,LO`). We decode it straight from each DOL.
  * Because the linked `.text` is byte-identical across versions for a Matching
    object, the relocation's text offset lands on the same instruction in every
    DOL. Decoding the signed 16-bit field gives `const_addr = _SDA2_BASE_ + off`,
    and `pool_start = const_addr - symval` (symval = offset of `@N` in the pool).

Only LOCAL OBJECT symbols in the object's own `.sdata2` are used (shared globals
like `__GXData` are excluded). Every retained relocation must agree on one
aligned start, and the padded blob is then byte-verified against the DOL.

Usage:
  tools/sda21_locate.py <object.c> [--version G4SJ01|G4SP01|G4SE01]
  # default: self-validate on G4SE01, then print JP and PAL ranges.
"""
import argparse, csv, os, pathlib, re, struct, subprocess, sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
FUNCMAP = pathlib.Path(os.environ.get("FSA_FUNCMAP", ROOT / "docs/versions/function_map.csv"))


def dol_load(path):
    d = pathlib.Path(path).read_bytes()
    offs = struct.unpack(">18I", d[0:72])
    addrs = struct.unpack(">18I", d[72:144])
    sizes = struct.unpack(">18I", d[144:216])
    return d, [(offs[i], addrs[i], sizes[i]) for i in range(18) if sizes[i]]


def dol_read(d, secs, vaddr, n):
    for off, addr, sz in secs:
        if addr <= vaddr < addr + sz:
            fo = off + (vaddr - addr)
            return d[fo:fo + n]
    return None


def dol_w32(d, secs, vaddr):
    b = dol_read(d, secs, vaddr, 4)
    return struct.unpack(">I", b)[0] if b else None


def sda2_base(d, secs):
    """Decode r2 (_SDA2_BASE_) from __init_registers: addis rX,r0,HI ; ori rX,rX,LO."""
    base = next(((off, a, sz) for off, a, sz in secs if a <= 0x80003100 < a + sz), None)
    _, a0, sz0 = base
    for va in range(a0, a0 + sz0 - 4, 4):
        ins = dol_w32(d, secs, va)
        if (ins >> 26) == 15 and ((ins >> 21) & 31) == 2 and ((ins >> 16) & 31) == 0:
            nxt = dol_w32(d, secs, va + 4)
            if (nxt >> 26) == 24 and ((nxt >> 21) & 31) == 2 and ((nxt >> 16) & 31) == 2:
                return ((ins & 0xFFFF) << 16) | (nxt & 0xFFFF)
    raise RuntimeError("could not decode _SDA2_BASE_ from __init_registers")


def se_splits():
    secs_of, curr = {}, None
    for l in (ROOT / "config/G4SE01/splits.txt").read_text().splitlines():
        s = l.strip()
        if s.endswith(":"):
            curr = s[:-1]; secs_of[curr] = {}
        elif curr and s.startswith("."):
            p = s.split(); st = en = None
            for t in p:
                if t.startswith("start:"): st = int(t.split(":")[1], 16)
                if t.startswith("end:"): en = int(t.split(":")[1], 16)
            if st is not None: secs_of[curr][p[0]] = (st, en)
    return secs_of


def funcmap(path=FUNCMAP):
    m = {}
    with open(path) as f:
        for row in csv.reader(f):
            if len(row) < 14 or row[0] == "section": continue
            try: us = int(row[2], 16)
            except ValueError: continue
            m[us] = (int(row[4], 16) if row[4] else None, int(row[8], 16) if row[8] else None)
    return m


def obj_sdata2_bytes(o):
    out = subprocess.check_output(["readelf", "-x", ".sdata2", o], stderr=subprocess.DEVNULL).decode()
    b = bytearray()
    for line in out.splitlines():
        m = re.match(r"\s*0x[0-9a-f]+\s+((?:[0-9a-f]{8}\s+){1,4})", line)
        if not m: continue
        for grp in m.group(1).split():
            for i in range(0, 8, 2): b.append(int(grp[i:i + 2], 16))
    return bytes(b)


def local_sdata2_syms(o):
    idx2name = {}
    for line in subprocess.check_output(["readelf", "-SW", o], stderr=subprocess.DEVNULL).decode().splitlines():
        m = re.match(r"\s*\[\s*(\d+)\]\s+(\S+)", line)
        if m: idx2name[int(m.group(1))] = m.group(2)
    good = set()
    for line in subprocess.check_output(["readelf", "-sW", o], stderr=subprocess.DEVNULL).decode().splitlines():
        m = re.match(r"\s*(\d+):\s+[0-9a-f]+\s+\d+\s+(\S+)\s+(\S+)\s+\S+\s+(\S+)\s", line)
        if not m: continue
        idx, typ, bind, ndx = int(m.group(1)), m.group(2), m.group(3), m.group(4)
        secname = idx2name.get(int(ndx)) if ndx.isdigit() else ndx
        if typ == "OBJECT" and bind == "LOCAL" and secname == ".sdata2":
            good.add(idx)
    return good


def sda21_relocs(o):
    res = []
    for line in subprocess.check_output(["readelf", "-rW", o], stderr=subprocess.DEVNULL).decode().splitlines():
        m = re.match(r"([0-9a-f]{8})\s+([0-9a-f]{8})\s+R_PPC_EMB_SDA21\s+([0-9a-f]{8})", line)
        if m: res.append((int(m.group(1), 16), int(m.group(2), 16) >> 8, int(m.group(3), 16)))
    return res


def sec_size_align(o, sec):
    for line in subprocess.check_output(["readelf", "-SW", o], stderr=subprocess.DEVNULL).decode().splitlines():
        m = re.search(r"\]\s+" + re.escape(sec) + r"\s+\w+\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)\s+\S+\s+\S+\s+\d+\s+\d+\s+(\d+)", line)
        if m: return int(m.group(1), 16), int(m.group(2))
    return None, None


def locate(name, version, dols, bases, secs_of, fmap):
    o = str(ROOT / "build/G4SE01/src" / (name.rsplit(".", 1)[0] + ".o"))
    if ".sdata2" not in secs_of.get(name, {}):
        return ("no-sdata2",)
    obj_text_start, obj_text_end = secs_of[name][".text"]
    split_size = obj_text_end - obj_text_start
    size, align = sec_size_align(o, ".sdata2")
    good = local_sdata2_syms(o)
    # Only relocations inside the linked split .text; weak-COMDAT tails (compiled
    # but excluded from the split) live at r_offset >= split_size and must be ignored.
    rl = [(t, sv) for (t, si, sv) in sda21_relocs(o) if si in good and sv < size and t < split_size]
    if not rl:
        return ("no-local-relocs",)
    d, secs = dols[version]
    tstart = obj_text_start if version == "G4SE01" else fmap.get(obj_text_start, (None, None))[0 if version == "G4SJ01" else 1]
    if tstart is None:
        return ("no-textmap",)
    starts = set()
    for toff, sv in rl:
        ins = dol_w32(d, secs, tstart + (toff & ~3))
        if ins is None: return ("no-instr",)
        off = ins & 0xFFFF; off = off - 0x10000 if off & 0x8000 else off
        starts.add(bases[version] + off - sv)
    if len(starts) != 1:
        return ("inconsistent", sorted(hex(x) for x in starts))
    start = starts.pop()
    end = start + (size + align - 1) // align * align
    blob = obj_sdata2_bytes(o)
    got = dol_read(d, secs, start, len(blob))
    return ("ok" if got == blob else "BYTEFAIL", start, end)


def locate_direct(name, version, dols, bases, secs_of, fmap):
    """Robust locator: decode the object's own `.sdata2` pool straight from the
    regional DOL, independent of the `.o`'s layout.

    The linked `.text` is byte-identical across versions, so an own-pool load sits
    at the same offset-from-split-start in every DOL. We identify which `r2`-relative
    loads reference this object's *own* pool by checking, in G4SE01, that the target
    lands inside the known US `.sdata2` split range (this naturally excludes shared
    globals like `__GXData`), then decode those same offsets in the target version.
    """
    ts, te = secs_of[name][".text"]
    pool = secs_of[name].get(".sdata2")
    if not pool:
        return ("no-sdata2",)
    ps, pe = pool
    LOADS = (48, 50, 52, 54, 32, 36)  # lfs lfd stfs stfd lwz stw
    d_us, secs_us = dols["G4SE01"]
    own_offsets = []
    for off in range(0, te - ts, 4):
        ins = dol_w32(d_us, secs_us, ts + off)
        if ins is None:
            continue
        if (ins >> 26) in LOADS and ((ins >> 16) & 31) == 2:
            imm = ins & 0xFFFF
            tgt = bases["G4SE01"] + (imm - 0x10000 if imm & 0x8000 else imm)
            if ps <= tgt < pe:
                own_offsets.append(off)
    if not own_offsets:
        return ("no-own-loads",)
    if version == "G4SE01":
        vts = ts
    else:
        vts = fmap.get(ts, (None, None))[0 if version == "G4SJ01" else 1]
    if vts is None:
        return ("no-textmap",)
    d, secs = dols[version]
    targets = set()
    for off in own_offsets:
        ins = dol_w32(d, secs, vts + off)
        if ins is None:
            return ("no-instr",)
        imm = ins & 0xFFFF
        targets.add(bases[version] + (imm - 0x10000 if imm & 0x8000 else imm))
    start = min(targets)
    return ("ok", start, start + (pe - ps))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("object", help="source path relative to src/, e.g. dolphin/mtx/vec.c")
    ap.add_argument("--version", choices=["G4SE01", "G4SJ01", "G4SP01"], help="single version (default: validate+print all)")
    ap.add_argument("--funcmap", type=pathlib.Path, default=FUNCMAP,
                    help="path to function_map.csv (default: repo docs/versions, or $FSA_FUNCMAP)")
    args = ap.parse_args()

    dols = {v: dol_load(ROOT / f"orig/{v}/sys/main.dol") for v in ["G4SE01", "G4SJ01", "G4SP01"]}
    bases = {v: sda2_base(*dols[v]) for v in dols}
    secs_of = se_splits()
    if not args.funcmap.exists():
        sys.exit(f"function_map.csv not found at {args.funcmap}; pass --funcmap or set $FSA_FUNCMAP")
    fmap = funcmap(args.funcmap)

    if args.object not in secs_of:
        sys.exit(f"{args.object}: not found in config/G4SE01/splits.txt (must be a Matching object)")

    known = secs_of[args.object].get(".sdata2")
    versions = [args.version] if args.version else ["G4SE01", "G4SJ01", "G4SP01"]
    if not args.version:
        se = locate_direct(args.object, "G4SE01", dols, bases, secs_of, fmap)
        ok = se[0] == "ok" and known is not None and (se[1], se[2]) == known
        kn = f"{hex(known[0])}-{hex(known[1])}" if known else "n/a"
        print(f"G4SE01 self-check (direct): {se} known {kn} -> {'OK' if ok else 'MISMATCH'}")
        if not ok:
            sys.exit("self-validation failed; do not trust JP/PAL output")
        versions = ["G4SJ01", "G4SP01"]
    us_bytes = dol_read(dols["G4SE01"][0], dols["G4SE01"][1], known[0], known[1] - known[0]) if known else None
    for v in versions:
        r = locate_direct(args.object, v, dols, bases, secs_of, fmap)
        if r[0] != "ok":
            print(f"{v}: {r}")
            continue
        # cross-version byte check: same-source constants must be identical to US
        vb = dol_read(dols[v][0], dols[v][1], r[1], r[2] - r[1])
        note = "  (bytes match US)" if us_bytes is not None and vb == us_bytes else ""
        print(f"{v}: .sdata2 start:0x{r[1]:08X} end:0x{r[2]:08X}{note}")


if __name__ == "__main__":
    main()
