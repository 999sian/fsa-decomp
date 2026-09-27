#!/usr/bin/env python3
"""General per-object multi-version linker for FSA (G4SJ01 / G4SP01).

For a G4SE01-Matching object whose `.text` functions all have JP+PAL addresses in
`function_map` (status `exact` or `masked`), this:
  1. names every `.text` function at its regional address,
  2. locates every non-`.text` section by decoding the object's own `.text`
     relocations *in the regional DOL* (`@sda21` for `.sdata2`/`.sdata`/`.sbss`
     via r2/r13 bases; `ADDR16_HA/LO` for `.data`/`.rodata`/`.bss`/`.ctors`),
     validating each against the known US split first,
  3. writes the split + symbol renames.

`masked` functions link byte-identically because dtk applies each region's
relocations at build time — so the authoritative gate is the retail-DOL build
hash, which the caller/driver runs after this applies. This tool only refuses
when it cannot *locate* a section consistently (US self-check fails).

Usage: import and call `plan(name)` -> dict of edits per version, or run as a
driver over candidate objects (see __main__).
"""
import csv, os, pathlib, re, struct, subprocess, sys, bisect

ROOT = pathlib.Path(__file__).resolve().parent.parent
_FM_DEFAULT = ROOT / "docs/versions/function_map.csv"
FUNCMAP = pathlib.Path(os.environ.get("FSA_FUNCMAP", _FM_DEFAULT))
VERS = ["G4SE01", "G4SJ01", "G4SP01"]
SHA1 = {"G4SE01": "d86b3d9f785566e34264035e140ef3daf3cc19f0",
        "G4SJ01": "56097356bceafde9a64abeab8501b909746ac03c",
        "G4SP01": "66dbc77f258a64d8bc8d7b0041c619ed70d0c00b"}


def dol_load(p):
    d = pathlib.Path(p).read_bytes()
    o = struct.unpack(">18I", d[0:72]); a = struct.unpack(">18I", d[72:144]); s = struct.unpack(">18I", d[144:216])
    return d, [(o[i], a[i], s[i]) for i in range(18) if s[i]]


def w32(dols, v, va):
    d, secs = dols[v]; va &= ~3
    for off, addr, sz in secs:
        if addr <= va < addr + sz:
            fo = off + (va - addr); return struct.unpack(">I", d[fo:fo + 4])[0]
    return None


def rd(dols, v, va, n):
    d, secs = dols[v]
    for off, addr, sz in secs:
        if addr <= va < addr + sz:
            fo = off + (va - addr); return d[fo:fo + n]
    return None


def sda_base(dols, v, reg):
    """r2 (_SDA2_BASE_) or r13 (_SDA_BASE_) from __init_registers."""
    d, secs = dols[v]
    base = next((x for x in secs if x[1] <= 0x80003100 < x[1] + x[2]))
    _, a0, sz0 = base
    for va in range(a0, a0 + sz0 - 4, 4):
        ins = w32(dols, v, va)
        if (ins >> 26) == 15 and ((ins >> 21) & 31) == reg and ((ins >> 16) & 31) == 0:
            nxt = w32(dols, v, va + 4)
            if (nxt >> 26) == 24 and ((nxt >> 21) & 31) == reg and ((nxt >> 16) & 31) == reg:
                return ((ins & 0xFFFF) << 16) | (nxt & 0xFFFF)
    raise RuntimeError(f"no _SDA{'2' if reg==2 else ''}_BASE_ for {v}")


def splits(cfg):
    out = {}; curr = None
    for l in pathlib.Path(f"config/{cfg}/splits.txt").read_text().splitlines():
        s = l.strip()
        if s.endswith(":") and not s.startswith("."): curr = s[:-1]; out[curr] = {}
        elif curr and s.startswith("."):
            p = s.split(); st = en = None
            for t in p:
                if t.startswith("start:"): st = int(t.split(":")[1], 16)
                if t.startswith("end:"): en = int(t.split(":")[1], 16)
            if st is not None: out[curr][p[0]] = (st, en)
    return out


def funcmap():
    if not FUNCMAP.exists():
        sys.exit(f"function_map.csv not found at {FUNCMAP}; set $FSA_FUNCMAP or place it at docs/versions/")
    m = {}
    with open(FUNCMAP) as f:
        for r in csv.reader(f):
            if len(r) < 14 or not r[2] or r[0] == "us_addr": continue
            try: us = int(r[2], 16)
            except ValueError: continue
            m[us] = (int(r[4], 16) if r[4] else None, int(r[8], 16) if r[8] else None)
    return m


def se_names():
    m = {}
    for l in pathlib.Path("config/G4SE01/symbols.txt").read_text().splitlines():
        if "=" in l and ".text:" in l:
            m[int(l.split(".text:")[1].split(";")[0], 16)] = l.split("=")[0].strip()
    return m


def obj_sections(o):
    """name -> (size, align); and idx->name."""
    res = {}; idx2name = {}
    for line in subprocess.check_output(["readelf", "-SW", o], stderr=subprocess.DEVNULL).decode().splitlines():
        m = re.match(r"\s*\[\s*(\d+)\]\s+(\S+)\s+\w+\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)\s+\S+\s+\S+\s+\d+\s+\d+\s+(\d+)", line)
        if m:
            idx2name[int(m.group(1))] = m.group(2)
            res[m.group(2)] = (int(m.group(3), 16), int(m.group(4)))
    return res, idx2name


def sym_table(o, idx2name):
    """symidx -> (section_name, value)."""
    res = {}
    for line in subprocess.check_output(["readelf", "-sW", o], stderr=subprocess.DEVNULL).decode().splitlines():
        m = re.match(r"\s*(\d+):\s+([0-9a-f]+)\s+\d+\s+\S+\s+\S+\s+\S+\s+(\S+)\s", line)
        if m:
            ndx = m.group(3); sec = idx2name.get(int(ndx)) if ndx.isdigit() else ndx
            res[int(m.group(1))] = (sec, int(m.group(2), 16))
    return res


def relocs(o):
    """list of (text_off, type, symidx, addend)."""
    res = []
    for line in subprocess.check_output(["readelf", "-rW", o], stderr=subprocess.DEVNULL).decode().splitlines():
        m = re.match(r"\s*([0-9a-f]{8})\s+([0-9a-f]{8})\s+(R_PPC_\S+)\s+[0-9a-f]+\s+(.*?)\s*([+-]\s*[0-9a-fA-Fx]+)?\s*$", line)
        if m:
            addend = int(m.group(5).replace(" ", ""), 16) if m.group(5) else 0
            res.append((int(m.group(1), 16), m.group(3), int(m.group(2), 16) >> 8, addend))
    return res


class Linker:
    def __init__(self):
        self.dols = {v: dol_load(ROOT / f"orig/{v}/sys/main.dol") for v in VERS}
        self.sda2 = {v: sda_base(self.dols, v, 2) for v in VERS}
        self.sda = {v: sda_base(self.dols, v, 13) for v in VERS}
        self.se = splits("G4SE01")
        self.fm = funcmap()
        self.names = se_names()
        self.faddrs = sorted(self.fm)

    def contain(self, us):
        i = bisect.bisect_right(self.faddrs, us) - 1
        if i < 0: return None
        fu = self.faddrs[i]; nxt = self.faddrs[i + 1] if i + 1 < len(self.faddrs) else fu + 0x2000
        if us >= nxt: return None
        jp, pal = self.fm[fu]
        return fu, jp, pal

    def us_by_name(self):
        if not hasattr(self, "_ubn"):
            m = {}
            for l in pathlib.Path("config/G4SE01/symbols.txt").read_text().splitlines():
                if "=" in l and ".text:" in l:
                    m[l.split("=")[0].strip()] = int(l.split(".text:")[1].split(";")[0], 16)
            self._ubn = m
        return self._ubn

    def o_func_table(self, o):
        ubn = self.us_by_name(); tbl = []
        for line in subprocess.check_output(["nm", o], stderr=subprocess.DEVNULL).decode().splitlines():
            p = line.split()
            if len(p) == 3 and p[1] in ("T", "t", "W", "w"):
                us = ubn.get(p[2])
                if us is not None: tbl.append((int(p[0], 16), us))
        tbl.sort()
        return tbl

    def reg_instr_addr(self, tbl, offs, o_off, version):
        i = bisect.bisect_right(offs, o_off) - 1
        if i < 0: return None
        fo, us = tbl[i]
        if version == "G4SE01": return us + (o_off - fo)
        jp, pal = self.fm.get(us, (None, None))
        base = jp if version == "G4SJ01" else pal
        if base is None: return None
        return base + (o_off - fo)

    def locate_section(self, name, sec, version):
        o = str(ROOT / "build/G4SE01/src" / (name.rsplit(".", 1)[0] + ".o"))
        secinfo, idx2name = obj_sections(o)
        if sec not in secinfo: return None
        size, align = secinfo[sec]
        syms = sym_table(o, idx2name)
        rl = relocs(o)
        tbl = self.o_func_table(o); offs = [t[0] for t in tbl]
        ha = {}; lo = {}; sda = []
        for toff, typ, si, addend in rl:
            sinfo = syms.get(si)
            if not sinfo or sinfo[0] != sec: continue
            effval = sinfo[1] + addend
            if typ == "R_PPC_EMB_SDA21": sda.append((toff, effval))
            elif typ == "R_PPC_ADDR16_HA": ha.setdefault(effval, []).append(toff)
            elif typ == "R_PPC_ADDR16_LO": lo.setdefault(effval, []).append(toff)
        starts = set()
        reg = 2 if sec == ".sdata2" else 13
        base = (self.sda2 if sec == ".sdata2" else self.sda)[version]
        LOAD_OPS = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 48, 49, 50, 51, 52, 53, 54, 55}  # all 16-bit D-form load/stores
        for toff, effval in sda:
            ia = self.reg_instr_addr(tbl, offs, toff & ~3, version)
            if ia is None: continue
            ins = w32(self.dols, version, ia)
            if ins is None or (ins >> 26) not in LOAD_OPS or ((ins >> 16) & 31) != reg:
                continue  # skip paired-single / mis-mapped / wrong base
            off = ins & 0xFFFF; off = off - 0x10000 if off & 0x8000 else off
            starts.add(base + off - effval)
        for effval, hoffs in ha.items():
            if len(hoffs) != len(lo.get(effval, [])): return None
            for hoff, loff in zip(sorted(hoffs), sorted(lo.get(effval, []))):
                iha = self.reg_instr_addr(tbl, offs, hoff & ~3, version)
                ilo = self.reg_instr_addr(tbl, offs, loff & ~3, version)
                if iha is None or ilo is None: continue
                a = w32(self.dols, version, iha); b = w32(self.dols, version, ilo)
                if a is None or b is None or (a >> 26) != 15: continue
                hi = a & 0xFFFF; low = b & 0xFFFF; low = low - 0x10000 if low & 0x8000 else low
                starts.add(((hi << 16) + low) - effval)
        if len(starts) != 1: return None
        start = starts.pop()
        return start, start + (size + align - 1) // align * align

    def plan(self, name):
        """Returns {version: (funcs[(realname,addr)], sections[(sec,start,end)])} or None."""
        ts, te = self.se[name][".text"]
        us_funcs = [a for a in self.fm if ts <= a < te]
        if not us_funcs or not all(self.fm[a][0] and self.fm[a][1] for a in us_funcs):
            return None
        nontext = [s for s in self.se[name] if s != ".text"]
        # US self-validate every section locator
        for sec in nontext:
            r = self.locate_section(name, sec, "G4SE01")
            if r is None or r != self.se[name][sec]:
                return ("SECTION-FAIL", sec, r, self.se[name][sec])
        out = {}
        for v in ("G4SJ01", "G4SP01"):
            funcs = []
            for a in sorted(us_funcs):
                jp, pal = self.fm[a]
                funcs.append((self.names.get(a), jp if v == "G4SJ01" else pal))
            secs = []
            tstart = min((jp if v == "G4SJ01" else pal) for jp, pal in [self.fm[us_funcs[0]]]) \
                if False else (self.fm[min(us_funcs)][0] if v == "G4SJ01" else self.fm[min(us_funcs)][1])
            secs.append((".text", tstart, tstart + (te - ts)))
            for sec in nontext:
                r = self.locate_section(name, sec, v)
                if r is None:
                    return ("SECTION-FAIL", sec, v)
                secs.append((sec, r[0], r[1]))
            out[v] = (funcs, secs)
        return out


if __name__ == "__main__":
    L = Linker()
    for name in sys.argv[1:]:
        r = L.plan(name)
        print(name, "->", "OK" if isinstance(r, dict) else r)
        if isinstance(r, dict):
            for v, (funcs, secs) in r.items():
                print(f"  {v}: {len(funcs)} fns; secs " + ", ".join(f"{s}:{hex(a)}-{hex(b)}" for s, a, b in secs))
