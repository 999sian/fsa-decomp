#!/usr/bin/env python3
"""Cross-version function mapper for FSA (G4SE01 <-> G4SJ01 / G4SP01).

usage:
  tools/version_map.py [--csv docs/versions/function_map.csv] [--stats]
  tools/version_map.py --propagate [--splits] [--dry-run] [--targets G4SJ01,G4SP01]

Inputs (per version <ID>): orig/<ID>/sys/main.dol, config/<ID>/symbols.txt,
config/<ID>/splits.txt and the dtk disassembly in build/<ID>/asm/ (which
carries the relocation info). Build every version once first so the asm is
current:  python3 configure.py --version <ID> && ninja

Matching
  Every function (.init/.text symbol) gets two hashes: the raw bytes and the
  bytes with relocated fields masked (branch targets of b/bl/bc to symbols,
  the 16-bit immediates of @ha/@h/@l relocs, the rA+d fields of @sda21
  relocs). Functions are aligned in address order with difflib on the masked
  hashes (the link order is the same in all releases), which resolves
  duplicate hashes (stubs, inlined templates) by position. Runs that do not
  align are paired by a Needleman-Wunsch pass on instruction similarity, and
  leftovers with a unique masked hash are paired as moved functions.

  kind   exact    raw bytes identical
         masked   identical after masking relocations (addresses shifted)
         aligned  code differs; paired by position/similarity (see sim)
         none     no counterpart

  A pair is "confident" when it is exact/masked and either its hash is unique
  in both versions or a neighbouring function is paired with the neighbouring
  function on the other side, and no call target contradicts the map.

  Data symbols are mapped by relocation votes from confident function pairs
  (and from pointer words inside mapped data), then by neighbour deltas.

--propagate
  Copies non-auto names (anything but fn_/lbl_/dtor_/jumptable_/@... names)
  from config/G4SE01/symbols.txt onto confidently mapped functions and data in
  the other versions' symbols.txt. With --splits, every G4SE01 TU in
  splits.txt whose sections all map with one delta each and whose bytes match
  (relocations masked) is copied too, together with all of its symbols, so the
  same source object links into the other versions. Rebuild each version and
  check the hash afterwards.
"""
import argparse
import csv
import difflib
import hashlib
import os
import re
import struct
import sys
from bisect import bisect_right
from collections import Counter, defaultdict
from typing import Dict, List, Optional, Tuple

ROOT = os.environ.get("FSA_ROOT") or os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = "G4SE01"
OTHERS = ["G4SJ01", "G4SP01"]
SHORT = {"G4SE01": "us", "G4SJ01": "jp", "G4SP01": "pal"}
CODE_SECTIONS = (".init", ".text")
BSS_SECTIONS = (".bss", ".sbss", ".sbss2")

AUTO_NAME = re.compile(r"^(fn_|lbl_|dtor_|jumptable_|gap_|@)|_[0-9A-F]{8}$")
SYMLINE = re.compile(r"^(\S+|\"[^\"]+\") = (\S+):0x([0-9A-Fa-f]+); //(.*)$")


def is_auto(name: str) -> bool:
    return bool(AUTO_NAME.search(name.strip('"')))


# --------------------------------------------------------------------------
# Per-version data


class Sym:
    __slots__ = ("name", "sec", "addr", "size", "attrs", "type")

    def __init__(self, name, sec, addr, attrs):
        self.name = name
        self.sec = sec
        self.addr = addr
        self.attrs = attrs
        m = re.search(r"\bsize:0x([0-9A-Fa-f]+)", attrs)
        self.size = int(m.group(1), 16) if m else 0
        m = re.search(r"\btype:(\w+)", attrs)
        self.type = m.group(1) if m else ""

    def line(self) -> str:
        return f"{self.name} = {self.sec}:0x{self.addr:08X}; //{self.attrs}"


class Func:
    __slots__ = ("sym", "raw", "masked", "hraw", "hmask", "relocs")

    def __init__(self, sym, raw, masked, relocs):
        self.sym = sym
        self.raw = raw
        self.masked = masked
        self.relocs = relocs  # list of (offset, target_addr or None)
        self.hraw = hashlib.sha1(raw).digest()
        self.hmask = hashlib.sha1(struct.pack(f">{len(masked)}I", *masked)).digest()

    @property
    def addr(self):
        return self.sym.addr

    @property
    def size(self):
        return self.sym.size


class Version:
    def __init__(self, vid: str):
        self.vid = vid
        self.dol = open(f"{ROOT}/orig/{vid}/sys/main.dol", "rb").read()
        hdr = self.dol
        self.segs = [
            (o, a, s)
            for o, a, s in zip(
                struct.unpack(">18I", hdr[0:72]),
                struct.unpack(">18I", hdr[72:144]),
                struct.unpack(">18I", hdr[144:216]),
            )
            if s
        ]
        self.sym_path = f"{ROOT}/config/{vid}/symbols.txt"
        self.split_path = f"{ROOT}/config/{vid}/splits.txt"
        self.syms: List[Sym] = []
        self.sym_lines_other: List[str] = []
        for line in open(self.sym_path):
            line = line.rstrip("\n")
            m = SYMLINE.match(line)
            if not m:
                if line.strip():
                    self.sym_lines_other.append(line)
                continue
            self.syms.append(Sym(m.group(1), m.group(2), int(m.group(3), 16), m.group(4)))
        self.by_name: Dict[str, Sym] = {}
        for s in self.syms:
            self.by_name.setdefault(s.name.strip('"'), s)
        self.by_addr: Dict[int, List[Sym]] = defaultdict(list)
        for s in self.syms:
            self.by_addr[s.addr].append(s)
        # sized symbols per section, sorted, for containment lookups
        self.sec_syms: Dict[str, List[Sym]] = defaultdict(list)
        for s in self.syms:
            if s.type in ("function", "object") and s.size:
                self.sec_syms[s.sec].append(s)
        for lst in self.sec_syms.values():
            lst.sort(key=lambda s: s.addr)
        self.sec_starts = {k: [s.addr for s in v] for k, v in self.sec_syms.items()}
        self.code_relocs: Dict[int, Tuple[str, Optional[int]]] = {}
        self.data_relocs: Dict[int, Optional[int]] = {}
        self.asm_warnings = 0
        self._parse_asm(f"{ROOT}/build/{vid}/asm")
        self.funcs: Dict[str, List[Func]] = {}
        for sec in CODE_SECTIONS:
            fl = []
            for s in self.sec_syms.get(sec, []):
                if s.type == "function":
                    fl.append(self._make_func(s))
            self.funcs[sec] = fl
        self.func_at = {f.addr: f for fl in self.funcs.values() for f in fl}

    # ---- DOL access
    def read(self, addr: int, n: int) -> Optional[bytes]:
        for o, a, s in self.segs:
            if a <= addr and addr + n <= a + s:
                return self.dol[o + addr - a : o + addr - a + n]
        return None

    def containing(self, sec: str, addr: int) -> Optional[Sym]:
        starts = self.sec_starts.get(sec)
        if not starts:
            return None
        i = bisect_right(starts, addr) - 1
        if i < 0:
            return None
        s = self.sec_syms[sec][i]
        if s.addr <= addr < s.addr + s.size:
            return s
        return None

    def section_of(self, addr: int) -> Optional[str]:
        for sec, starts in self.sec_starts.items():
            lst = self.sec_syms[sec]
            if lst and lst[0].addr <= addr < lst[-1].addr + lst[-1].size:
                return sec
        return None

    def resolve(self, target: str) -> Optional[int]:
        m = re.match(r'^("?)(.+?)\1(?:([+-])0x([0-9A-Fa-f]+))?$', target.strip())
        if not m:
            return None
        name = m.group(2)
        add = int(m.group(4), 16) if m.group(4) else 0
        if m.group(3) == "-":
            add = -add
        s = self.by_name.get(name)
        if s is not None:
            return s.addr + add
        m2 = re.search(r"_([0-9A-F]{8})(?:_\w+)?$", name)
        if m2:
            return int(m2.group(1), 16) + add
        return None

    # ---- asm parsing (relocations)
    INS = re.compile(r"^/\* ([0-9A-F]{8}) [0-9A-F]{8}  [0-9A-F ]{11} \*/\t(\S+)(?:\s+(.*))?$")
    RELOP = re.compile(r'((?:"[^"]+"|[^\s,()"]+)(?:[+-]0x[0-9A-Fa-f]+)?)@(ha|h|l|sda21|sda2)\b')
    OBJHDR = re.compile(r"^# (\S+):0x[0-9A-Fa-f]+ \| 0x([0-9A-Fa-f]+) \| size: 0x([0-9A-Fa-f]+)")

    def _parse_asm(self, d: str):
        if not os.path.isdir(d):
            sys.exit(f"missing {d}: build {self.vid} first (configure.py --version {self.vid} && ninja)")
        for root, _, files in os.walk(d):
            for fn in files:
                if fn.endswith(".s"):
                    self._parse_asm_file(os.path.join(root, fn))

    def _parse_asm_file(self, path: str):
        cur = None  # current address inside a data object
        end = None
        relocs: List[Tuple[int, str]] = []
        ok = True
        for line in open(path, encoding="utf-8", errors="replace"):
            if line.startswith("/*"):
                m = self.INS.match(line.rstrip("\n"))
                if not m:
                    continue
                ops = m.group(3) or ""
                mn = m.group(2)
                if "@" in ops:
                    r = self.RELOP.search(ops)
                    if r:
                        self.code_relocs[int(m.group(1), 16)] = (r.group(2), self.resolve(r.group(1)))
                        continue
                if mn[0] == "b" and ops:
                    tgt = ops.split(",")[-1].strip()
                    if tgt and not tgt.startswith(".L_") and not re.match(r"^(-?0x|-?\d|cr\d|r\d)", tgt):
                        self.code_relocs[int(m.group(1), 16)] = ("rel", self.resolve(tgt))
                continue
            if line.startswith("# "):
                m = self.OBJHDR.match(line)
                if m and m.group(1) not in CODE_SECTIONS:
                    cur = int(m.group(2), 16)
                    end = cur + int(m.group(3), 16)
                    relocs = []
                    ok = True
                continue
            if cur is None:
                continue
            s = line.strip()
            if not s or s.startswith(("#", "*")):
                continue
            if s.startswith(".endobj"):
                if ok and cur == end:
                    for a, t in relocs:
                        self.data_relocs[a] = self.resolve(t)
                else:
                    self.asm_warnings += 1
                cur = None
                continue
            if s.startswith((".obj", ".hidden", ".sym", ".L_", ".balign", ".section", ".text", ".data", ".rodata")):
                continue
            d, _, rest = s.partition(" ")
            rest = rest.strip()
            try:
                if d == ".4byte":
                    for v in rest.split(","):
                        v = v.strip()
                        if not re.match(r"^-?0x[0-9A-Fa-f]+$|^-?\d+$", v):
                            relocs.append((cur, v))
                        cur += 4
                elif d == ".rel":
                    relocs.append((cur, rest.split(",")[0].strip()))
                    cur += 4
                elif d == ".2byte":
                    cur += 2 * len(rest.split(","))
                elif d == ".byte":
                    cur += len(rest.split(","))
                elif d == ".float":
                    cur += 4 * len(rest.split(","))
                elif d == ".double":
                    cur += 8 * len(rest.split(","))
                elif d == ".skip":
                    cur += int(rest, 0)
                elif d in (".string", ".ascii"):
                    n = _strlen(rest)
                    cur += n + (1 if d == ".string" else 0)
                else:
                    ok = False
            except ValueError:
                ok = False

    def _make_func(self, s: Sym) -> Func:
        raw = self.read(s.addr, s.size) or b""
        n = len(raw) // 4
        words = list(struct.unpack(f">{n}I", raw[: n * 4]))
        masked = list(words)
        relocs = []
        for i in range(n):
            r = self.code_relocs.get(s.addr + 4 * i)
            if r is None:
                continue
            kind, tgt = r
            w = words[i]
            op = w >> 26
            if kind == "rel":
                masked[i] = w & ~(0x03FFFFFC if op == 18 else 0x0000FFFC)
            elif kind == "sda21":
                masked[i] = w & ~0x001FFFFF
            else:
                masked[i] = w & ~0x0000FFFF
            relocs.append((4 * i, tgt))
        return Func(s, raw, masked, relocs)


def _strlen(q: str) -> int:
    q = q.strip()
    if not (q.startswith('"') and q.endswith('"')):
        raise ValueError(q)
    body = q[1:-1]
    n = 0
    i = 0
    while i < len(body):
        c = body[i]
        if c == "\\":
            nx = body[i + 1]
            if nx == "x":
                j = i + 2
                while j < len(body) and j < i + 4 and body[j] in "0123456789abcdefABCDEF":
                    j += 1
                i = j
            elif nx in "01234567":
                j = i + 1
                while j < len(body) and j < i + 4 and body[j] in "01234567":
                    j += 1
                i = j
            else:
                i += 2
            n += 1
        else:
            n += len(c.encode("utf-8")) if ord(c) < 0xDC80 or ord(c) > 0xDCFF else 1
            i += 1
    return n


# --------------------------------------------------------------------------
# Function mapping


class Pair:
    __slots__ = ("a", "b", "kind", "sim", "confident", "moved")

    def __init__(self, a, b, kind, sim=1.0, moved=False):
        self.a = a
        self.b = b
        self.kind = kind
        self.sim = sim
        self.confident = False
        self.moved = moved


def similarity(fa: Func, fb: Func, cutoff: bool = True) -> float:
    la, lb = len(fa.masked), len(fb.masked)
    if not la or not lb:
        return 0.0
    if cutoff and min(la, lb) / max(la, lb) < 0.5:
        return 0.0
    sm = difflib.SequenceMatcher(None, fa.masked, fb.masked, autojunk=False)
    if cutoff and (sm.real_quick_ratio() < 0.5 or sm.quick_ratio() < 0.5):
        return 0.0
    return sm.ratio()


def nw_align(la: List[Func], lb: List[Func], min_sim: float) -> List[Tuple[int, int, float]]:
    """Order-preserving alignment maximising summed similarity."""
    n, m = len(la), len(lb)
    if n * m > 250000:
        # too big: pair by position only where sizes agree closely
        out = []
        for i in range(min(n, m)):
            s = similarity(la[i], lb[i])
            if s >= min_sim:
                out.append((i, i, s))
        return out
    sim = [[0.0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            sim[i][j] = similarity(la[i], lb[j])
    score = [[0.0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            best = max(score[i - 1][j], score[i][j - 1])
            s = sim[i - 1][j - 1]
            if s >= min_sim:
                best = max(best, score[i - 1][j - 1] + s)
            score[i][j] = best
    out = []
    i, j = n, m
    while i > 0 and j > 0:
        s = sim[i - 1][j - 1]
        if s >= min_sim and score[i][j] == score[i - 1][j - 1] + s:
            out.append((i - 1, j - 1, s))
            i -= 1
            j -= 1
        elif score[i][j] == score[i - 1][j]:
            i -= 1
        else:
            j -= 1
    out.reverse()
    return out


class FuncMap:
    def __init__(self, A: Version, B: Version, min_sim: float = 0.5):
        self.A = A
        self.B = B
        self.pairs: List[Pair] = []
        self.a2b: Dict[int, Pair] = {}
        self.b2a: Dict[int, Pair] = {}
        for sec in CODE_SECTIONS:
            self._map_section(A.funcs.get(sec, []), B.funcs.get(sec, []), min_sim)
        self._confidence()

    def _add(self, p: Pair):
        self.pairs.append(p)
        self.a2b[p.a.addr] = p
        self.b2a[p.b.addr] = p

    def _pair(self, fa: Func, fb: Func, sim: float = 1.0):
        kind = "exact" if fa.hraw == fb.hraw else "masked" if fa.hmask == fb.hmask else "aligned"
        self._add(Pair(fa, fb, kind, sim))

    def _align_runs(self, la: List[Func], lb: List[Func], min_sim: float, use_nw: bool, min_block: int) -> int:
        """difflib alignment of two ordered runs; returns number of new pairs."""
        n0 = len(self.pairs)
        ka = [f.hmask for f in la]
        kb = [f.hmask for f in lb]
        sm = difflib.SequenceMatcher(None, ka, kb, autojunk=False)
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag == "equal":
                blk = la[i1:i2]
                if i2 - i1 < min_block and sum(len(f.masked) for f in blk) < 8 * min_block:
                    continue
                for k in range(i2 - i1):
                    self._pair(la[i1 + k], lb[j1 + k])
            elif tag == "replace" and use_nw:
                for i, j, s in nw_align(la[i1:i2], lb[j1:j2], min_sim):
                    self._pair(la[i1 + i], lb[j1 + j], s)
        return len(self.pairs) - n0

    def _gaps(self, la: List[Func], lb: List[Func]):
        """Yield (gap_a, gap_b, bounded) for runs of unpaired functions."""
        pos_b = {f.addr: i for i, f in enumerate(lb)}
        i = 0
        while i < len(la):
            if la[i].addr in self.a2b:
                i += 1
                continue
            j = i
            while j < len(la) and la[j].addr not in self.a2b:
                j += 1
            gap_a = la[i:j]
            prev = self.a2b[la[i - 1].addr].b if i > 0 else None
            nxt = self.a2b[la[j].addr].b if j < len(la) else None
            pi = pos_b.get(prev.addr) if prev is not None else None
            ni = pos_b.get(nxt.addr) if nxt is not None else None
            gap_b: List[Func] = []
            # the B functions after the left neighbour's image (or, at the
            # edge of a moved block, before the right neighbour's image)
            if pi is not None:
                k = pi + 1
                while k < len(lb) and lb[k].addr not in self.b2a:
                    gap_b.append(lb[k])
                    k += 1
            if not gap_b and ni is not None:
                k = ni - 1
                while k >= 0 and lb[k].addr not in self.b2a:
                    gap_b.insert(0, lb[k])
                    k -= 1
            bounded = pi is not None and ni is not None and ni - pi - 1 == len(gap_b)
            if gap_b:
                yield gap_a, gap_b, bounded
            i = j

    def _map_section(self, la: List[Func], lb: List[Func], min_sim: float):
        # 1. solid blocks, repeated on the leftovers so that blocks of TUs that
        #    were linked in a different order still align
        for _ in range(8):
            ua = [f for f in la if f.addr not in self.a2b]
            ub = [f for f in lb if f.addr not in self.b2a]
            if not ua or not ub or not self._align_runs(ua, ub, min_sim, False, 3):
                break
        # 2. fill the gaps between paired neighbours
        for _ in range(8):
            new = 0
            for gap_a, gap_b, _bounded in self._gaps(la, lb):
                new += self._align_runs(gap_a, gap_b, min_sim, True, 1)
            if not new:
                break
        # 2b. equal-sized gaps enclosed by lockstep neighbours: pair by position
        for gap_a, gap_b, bounded in list(self._gaps(la, lb)):
            if bounded and len(gap_a) == len(gap_b):
                for fa, fb in zip(gap_a, gap_b):
                    self._pair(fa, fb, similarity(fa, fb, cutoff=False))
        # 3. moved functions: unique masked hash among the leftovers
        ua = [f for f in la if f.addr not in self.a2b]
        ub = [f for f in lb if f.addr not in self.b2a]
        ca = Counter(f.hmask for f in ua)
        cb = Counter(f.hmask for f in ub)
        idx = {f.hmask: f for f in ub}
        for fa in ua:
            if ca[fa.hmask] == 1 and cb.get(fa.hmask) == 1 and len(fa.masked) > 2:
                fb = idx[fa.hmask]
                self._add(Pair(fa, fb, "exact" if fa.hraw == fb.hraw else "masked", moved=True))

    def _confidence(self):
        A, B = self.A, self.B
        ca = Counter(f.hmask for fl in A.funcs.values() for f in fl)
        cb = Counter(f.hmask for fl in B.funcs.values() for f in fl)
        order_a = {}
        order_b = {}
        for sec in CODE_SECTIONS:
            for i, f in enumerate(A.funcs.get(sec, [])):
                order_a[f.addr] = (sec, i)
            for i, f in enumerate(B.funcs.get(sec, [])):
                order_b[f.addr] = (sec, i)
        pos_a = {v: k for k, v in order_a.items()}
        pos_b = {v: k for k, v in order_b.items()}

        def neighbour_ok(p: Pair) -> bool:
            sa, ia = order_a[p.a.addr]
            sb, ib = order_b[p.b.addr]
            for d in (-1, 1):
                na = pos_a.get((sa, ia + d))
                nb = pos_b.get((sb, ib + d))
                if na is not None and nb is not None:
                    q = self.a2b.get(na)
                    if q is not None and q.b.addr == nb:
                        return True
            return False

        for p in self.pairs:
            if p.kind == "aligned":
                # changed code: trust it only when nearly identical and in step
                # with a neighbour
                same_size = abs(p.a.size - p.b.size) <= max(8, p.a.size // 10)
                p.confident = p.sim >= 0.9 and same_size and neighbour_ok(p)
                continue
            unique = ca[p.a.hmask] == 1 and cb[p.b.hmask] == 1
            p.confident = unique or neighbour_ok(p)
        # call-target consistency: a confident pair whose calls land on
        # functions that are mapped elsewhere is demoted
        for p in self.pairs:
            if not p.confident:
                continue
            for (oa, ta), (ob, tb) in zip(p.a.relocs, p.b.relocs):
                if oa != ob or ta is None or tb is None:
                    continue
                if ta in A.func_at and tb in B.func_at:
                    q = self.a2b.get(ta)
                    if q is not None and q.confident and q.b.addr != tb:
                        p.confident = False
                        break
# --------------------------------------------------------------------------
# EH table mapping (extab/extabindex ownership via function map)
#
# Why this exists: section_delta resolves data sections through DataMap
# votes, but nothing ever votes for @etb_/@eti_ symbols (no code references
# them via @ha/@l relocs, and DataMap._infer_neighbours only bridges voted
# anchors). So every Game TU split, which always carries extab+extabindex
# ranges, died with "extab: 0 candidate deltas".
#
# Each extabindex entry is 12 bytes (func_addr, func_size, etb_addr) owned by
# exactly one TU: the TU whose .text range contains func_addr. The TU's
# extab range is exactly the union of the etb blobs its entries point at
# (verified: all 531 US Game TUs, byte-exact, no strays). So the owning
# functions' mapped images determine the EH delta: no byte search, no global
# constant-delta assumption.

EH_SECTIONS = ("extab", "extabindex")


class EHMap:
    """func addr -> (eti_addr, eti_size_field, etb_addr) per version, live only.

    An entry is live when its func word names a function symbol and the size
    field equals that symbol's size; DOL section tails carry non-entry words
    (link metadata) that must not be treated as EH ownership.
    """

    def __init__(self, V: "Version"):
        self.V = V
        self.by_func: Dict[int, Tuple[int, int, int]] = {}
        syms = V.sec_syms.get("extabindex", [])
        if not syms:
            return
        lo = syms[0].addr
        hi = syms[-1].addr + syms[-1].size
        blob = V.read(lo, hi - lo)
        if blob is None:
            return
        for off in range(0, (hi - lo) // 12 * 12, 12):
            func, size, etb = struct.unpack(">3I", blob[off : off + 12])
            f = V.func_at.get(func)
            if f is not None and f.size == size:
                self.by_func[func] = (lo + off, size, etb)


def eh_delta(
    fm: FuncMap, sec: str, start: int, end: int
) -> Tuple[Optional[int], str]:
    """Delta for an extab/extabindex split range via owning functions.

    Every extabindex entry in the TU's range must name a TU-owned function
    (func word inside a .text/.init function symbol); each such function
    must be confidently mapped with identical size on both sides, and the
    mapped images' EH entries must preserve entry order and etb blob sizes.
    For sec == "extab", the range must additionally be exactly covered by
    the owned etb blobs (no gaps, no strays). Returns (delta, "") or
    (None, reason); ambiguity and divergence are rejections, not guesses.
    """
    A, B = fm.A, fm.B
    ea = getattr(fm, "_eh_a", None)
    if ea is None:
        ea = fm._eh_a = EHMap(A)  # ponytail: cached per FuncMap; EH blobs are immutable retail bytes
    eb = getattr(fm, "_eh_b", None)
    if eb is None:
        eb = fm._eh_b = EHMap(B)
    # TU-owned functions: entries of the extabindex range name them; but
    # section_delta calls us per section, so derive ownership from the A-side
    # extabindex range when sec == "extabindex", and peer through the owning
    # TU's extabindex range otherwise (callers pass the TU's own ranges).
    if sec == "extabindex":
        if (end - start) % 12:
            return None, f"{sec}: range not a multiple of 12"
        span = range(start, end, 12)
    else:
        span = None  # resolved below via the owning functions' etb blobs
    # Collect owned (func, eti_a, size, etb_a) in entry order.
    owned: List[Tuple[int, int, int, int]] = []
    if span is not None:
        for eti in span:
            w = A.read(eti, 12)
            if w is None:
                return None, f"{sec}: unreadable"
            func, size, etb = struct.unpack(">3I", w)
            rec = ea.by_func.get(func)
            if rec is None or rec[0] != eti:
                return None, f"{sec}: entry at {eti:#x} names no live function"
            owned.append((func, eti, size, etb))
    else:
        # sec == "extab": ownership comes from A etb symbols in range, each
        # of which must be pointed at by exactly one live A-side entry whose
        # func is a TU function; then the range must equal their union.
        syms = [s for s in A.sec_syms.get("extab", []) if start <= s.addr < end]
        if not syms or syms[0].addr != start or syms[-1].addr + syms[-1].size != end:
            return None, f"{sec}: range does not align to etb symbols"
        for i in range(len(syms) - 1):
            if syms[i].addr + syms[i].size != syms[i + 1].addr:
                return None, f"{sec}: etb symbols not contiguous"
        etb2func = {etb: func for func, (_, _, etb) in ea.by_func.items()}
        seen_funcs = set()
        for s in syms:
            func = etb2func.get(s.addr)
            if func is None or func in seen_funcs:
                return None, f"{sec}: etb at {s.addr:#x} has no unique owner"
            seen_funcs.add(func)
            eti, size, _ = ea.by_func[func]
            owned.append((func, eti, size, s.addr))
        owned.sort(key=lambda r: r[1])  # entry order, not etb order
    if not owned:
        return None, f"{sec}: no owned functions"
    deltas = set()
    prev_b = -1
    for func, eti_a, size, etb_a in owned:
        p = fm.a2b.get(func)
        if p is None or not p.confident:
            return None, f"{sec}: owner {func:#x} not confidently mapped"
        rec_b = eb.by_func.get(p.b.addr)
        if rec_b is None:
            return None, f"{sec}: owner {func:#x} has no live image entry"
        eti_b, size_b, etb_b = rec_b
        if size_b != size or p.b.size != p.a.size:
            return None, f"{sec}: owner {func:#x} size-divergent"
        sa = A.containing("extab", etb_a)
        sb = B.containing("extab", etb_b)
        if sa is None or sb is None or sa.addr != etb_a or sb.addr != etb_b or sa.size != sb.size:
            return None, f"{sec}: owner {func:#x} etb-size-divergent"
        if eti_b <= prev_b:
            return None, f"{sec}: image entry order differs"
        prev_b = eti_b
        deltas.add((eti_b if sec == "extabindex" else etb_b) - (eti_a if sec == "extabindex" else etb_a))
    if len(deltas) != 1:
        return None, f"{sec}: {len(deltas)} candidate deltas"
    d = deltas.pop()
    # Image side must be contiguous: entries back to back for extabindex,
    # etb blobs exactly tiling the image range for extab.
    if sec == "extabindex":
        if prev_b - (owned[0][1] + d) != end - start - 12:
            return None, f"{sec}: image entries not contiguous"
    else:
        lo_b = owned[0][3] + d if owned[0][3] + d == min(
            eb.by_func[fm.a2b[f].b.addr][2] for f, _, _, _ in owned
        ) else None
        if lo_b is None:
            return None, f"{sec}: image blobs do not tile the range"
        # every image blob must sit inside [start+d, end+d) and tile it fully
        cov = bytearray(end - start)
        for func, _, _, _ in owned:
            _, _, etb_b = eb.by_func[fm.a2b[func].b.addr]
            sb = B.containing("extab", etb_b)
            o = etb_b - (start + d)
            if o < 0 or o + sb.size > end - start:
                return None, f"{sec}: image blob outside range"
            for k in range(o, o + sb.size):
                if cov[k]:
                    return None, f"{sec}: image blobs overlap"
                cov[k] = 1
        if not all(cov):
            return None, f"{sec}: image blobs do not tile the range"
    return d, ""

# --------------------------------------------------------------------------
# Data mapping (relocation votes)


class DataMap:
    def __init__(self, fm: FuncMap):
        A, B = fm.A, fm.B
        self.A, self.B = A, B
        votes: Dict[int, Counter] = defaultdict(Counter)

        def vote(ta, tb):
            if ta is None or tb is None:
                return
            seca = A.section_of(ta)
            secb = B.section_of(tb)
            if seca is None or seca != secb or seca in CODE_SECTIONS:
                return
            sa = A.containing(seca, ta)
            sb = B.containing(secb, tb)
            if sa is None or sb is None or ta - sa.addr != tb - sb.addr:
                return
            votes[sa.addr][sb.addr] += 1

        for p in fm.pairs:
            if not p.confident:
                continue
            for (oa, ta), (ob, tb) in zip(p.a.relocs, p.b.relocs):
                if oa == ob:
                    vote(ta, tb)
        self.a2b: Dict[int, int] = {}
        self._settle(votes)
        # pointer words inside mapped, equally sized data objects
        for _ in range(2):
            for sa_addr, sb_addr in list(self.a2b.items()):
                sa = self._sym(A, sa_addr)
                sb = self._sym(B, sb_addr)
                if sa is None or sb is None or sa.size != sb.size:
                    continue
                for off in range(0, sa.size, 4):
                    ta = A.data_relocs.get(sa.addr + off, -1)
                    tb = B.data_relocs.get(sb.addr + off, -1)
                    if ta != -1 and tb != -1:
                        vote(ta, tb)
            self._settle(votes)
        self._infer_neighbours()

    @staticmethod
    def _sym(V: Version, addr: int) -> Optional[Sym]:
        for s in V.by_addr.get(addr, []):
            if s.size and s.type == "object":
                return s
        lst = V.by_addr.get(addr)
        return lst[0] if lst else None

    def _settle(self, votes):
        used = Counter()
        for sa, c in votes.items():
            if len(c) == 1:
                used[next(iter(c))] += 1
        for sa, c in votes.items():
            if len(c) == 1:
                sb = next(iter(c))
                if used[sb] == 1:
                    self.a2b[sa] = sb
        self.voted = set(self.a2b)

    def _infer_neighbours(self):
        A, B = self.A, self.B
        b_taken = set(self.a2b.values())
        for sec, lst in A.sec_syms.items():
            if sec in CODE_SECTIONS:
                continue
            anchors = [(i, self.a2b[s.addr] - s.addr) for i, s in enumerate(lst) if s.addr in self.a2b]
            for k in range(len(anchors) - 1):
                i0, d0 = anchors[k]
                i1, d1 = anchors[k + 1]
                if d0 != d1:
                    continue
                for i in range(i0 + 1, i1):
                    s = lst[i]
                    t = B.containing(sec, s.addr + d0)
                    if t is not None and t.addr == s.addr + d0 and t.addr not in b_taken:
                        if t.size == s.size or s.type != "object":
                            self.a2b[s.addr] = t.addr
                            b_taken.add(t.addr)


# --------------------------------------------------------------------------
# Output


def write_csv(path: str, V: Dict[str, Version], maps: Dict[Tuple[str, str], FuncMap]):
    us, jp, pal = V["G4SE01"], V["G4SJ01"], V["G4SP01"]
    m_uj, m_up, m_jp = maps[("G4SE01", "G4SJ01")], maps[("G4SE01", "G4SP01")], maps[("G4SJ01", "G4SP01")]
    rows = []

    def cell(p: Optional[Pair], side_b: bool):
        if p is None:
            return ["", "", "none", ""]
        f = p.b if side_b else p.a
        return [f"0x{f.addr:08X}", f"0x{f.size:X}", p.kind + ("*" if p.moved else ""), f"{p.sim:.2f}"]

    for sec in CODE_SECTIONS:
        for f in us.funcs.get(sec, []):
            pj = m_uj.a2b.get(f.addr)
            pp = m_up.a2b.get(f.addr)
            rows.append(
                [sec, f.sym.name, f"0x{f.addr:08X}", f"0x{f.size:X}"]
                + cell(pj, True)
                + cell(pp, True)
                + ["yes" if pj and pj.confident else "", "yes" if pp and pp.confident else ""]
            )
        # functions absent from US
        for f in jp.funcs.get(sec, []):
            if f.addr in m_uj.b2a:
                continue
            pp = m_jp.a2b.get(f.addr)
            if pp is not None and pp.b.addr in m_up.b2a:
                pp = None
            rows.append(
                [sec, f.sym.name, "", "", f"0x{f.addr:08X}", f"0x{f.size:X}", "none", ""]
                + cell(pp, True)
                + ["", ""]
            )
        for f in pal.funcs.get(sec, []):
            if f.addr in m_up.b2a:
                continue
            pj = m_jp.b2a.get(f.addr)
            if pj is not None:
                continue  # already emitted from the JP side
            rows.append([sec, f.sym.name, "", "", "", "", "none", "", f"0x{f.addr:08X}", f"0x{f.size:X}", "none", "", "", ""])

    rows.sort(key=lambda r: (r[0] != ".init", int(r[2] or r[4] or r[8], 16)))
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="") as fh:
        w = csv.writer(fh, lineterminator="\n")
        w.writerow(
            ["section", "name", "us_addr", "us_size", "jp_addr", "jp_size", "jp_kind", "jp_sim",
             "pal_addr", "pal_size", "pal_kind", "pal_sim", "jp_confident", "pal_confident"]
        )
        w.writerows(rows)
    return len(rows)


def region_stats(fm: FuncMap) -> Dict[str, Tuple[int, int]]:
    """count/bytes per kind, split by rough code region (base addresses)."""
    out = {}
    for p in fm.pairs:
        k = p.kind
        c, b = out.get(k, (0, 0))
        out[k] = (c + 1, b + p.a.size)
    na = [f for fl in fm.A.funcs.values() for f in fl if f.addr not in fm.a2b]
    nb = [f for fl in fm.B.funcs.values() for f in fl if f.addr not in fm.b2a]
    out[f"only-{SHORT[fm.A.vid]}"] = (len(na), sum(f.size for f in na))
    out[f"only-{SHORT[fm.B.vid]}"] = (len(nb), sum(f.size for f in nb))
    return out


def print_stats(fm: FuncMap):
    A, B = fm.A, fm.B
    tot = sum(len(fl) for fl in A.funcs.values())
    totb = sum(f.size for fl in A.funcs.values() for f in fl)
    print(f"== {A.vid} -> {B.vid}: {tot} / {sum(len(fl) for fl in B.funcs.values())} functions")
    st = region_stats(fm)
    for k in ("exact", "masked", "aligned", f"only-{SHORT[A.vid]}", f"only-{SHORT[B.vid]}"):
        c, b = st.get(k, (0, 0))
        print(f"   {k:10s} {c:6d} funcs  {b:#9x} bytes  ({100.0 * c / tot:5.1f}% funcs, {100.0 * b / totb:5.1f}% bytes)")
    conf = sum(1 for p in fm.pairs if p.confident)
    moved = sum(1 for p in fm.pairs if p.moved)
    print(f"   confident {conf}, moved {moved}, asm warnings {A.asm_warnings}/{B.asm_warnings}")


# --------------------------------------------------------------------------
# Propagation


def load_splits(path: str):
    """-> (header lines, [(unit, [(sec, start, end, extra)])])"""
    header, units = [], []
    cur = None
    for line in open(path):
        line = line.rstrip("\n")
        if not line.strip():
            cur = None
            continue
        if not line.startswith("\t") and line.endswith(":") and line != "Sections:":
            cur = (line[:-1], [])
            units.append(cur)
            continue
        if cur is None:
            header.append(line)
            continue
        m = re.match(r"^\t(\S+)\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)(.*)$", line)
        if m:
            cur[1].append((m.group(1), int(m.group(2), 16), int(m.group(3), 16), m.group(4)))
    return header, units


def write_splits(path: str, header: List[str], units):
    with open(path, "w") as fh:
        fh.write("\n".join(header) + "\n")
        for name, secs in units:
            fh.write(f"\n{name}:\n")
            for sec, s, e, extra in secs:
                fh.write(f"\t{sec:<11} start:0x{s:08X} end:0x{e:08X}{extra}\n")


def rename_addr_suffix(name: str, delta: int) -> str:
    def sub(m):
        return f"_{int(m.group(1), 16) + delta:08X}"

    q = name.startswith('"')
    n = name.strip('"')
    n2 = re.sub(r"_([0-9A-F]{8})(?=$|_)", sub, n) if is_auto(n) else n
    return f'"{n2}"' if q else n2


def section_delta(fm: FuncMap, dm: DataMap, sec: str, start: int, end: int) -> Tuple[Optional[int], str]:
    A, B = fm.A, fm.B
    syms = [s for s in A.syms if s.sec == sec and start <= s.addr < end and s.type != "label"]
    if sec in CODE_SECTIONS:
        funcs = [s for s in syms if s.type == "function"]
        if not funcs:
            return None, "no functions"
        deltas = set()
        for s in funcs:
            p = fm.a2b.get(s.addr)
            if p is None or not p.confident:
                return None, f"{s.name} not confidently mapped"
            deltas.add(p.b.addr - s.addr)
        if len(deltas) != 1:
            return None, "functions not contiguous"
        return deltas.pop(), ""
    if sec in (".ctors", ".dtors"):
        words = A.read(start, end - start)
        if words is None:
            return None, "unreadable"
        tgts = []
        for i in range(0, len(words), 4):
            w = struct.unpack(">I", words[i : i + 4])[0]
            p = fm.a2b.get(w)
            if p is None or not p.confident:
                return None, f"{sec} target {w:#x} unmapped"
            tgts.append(p.b.addr)
        pat = b"".join(struct.pack(">I", t) for t in tgts)
        bs = [s for s in B.syms if s.sec == sec]
        lo = min(s.addr for s in bs) if bs else None
        seg = None
        for o, a, sz in B.segs:
            if lo is not None and a <= lo < a + sz:
                seg = (o, a, sz)
        if seg is None:
            return None, f"{sec} not found"
        blob = B.dol[seg[0] : seg[0] + seg[2]]
        k = blob.find(pat)
        if k < 0 or blob.find(pat, k + 1) >= 0:
            return None, f"{sec} pattern not unique"
        return seg[1] + k - start, ""
    deltas = Counter()
    for s in syms:
        t = dm.a2b.get(s.addr)
        if t is not None and s.addr in dm.voted:
            deltas[t - s.addr] += 1
    if len(deltas) != 1:
        return None, f"{sec}: {len(deltas)} candidate deltas"
    return next(iter(deltas)), ""


def verify_range(fm: FuncMap, dm: DataMap, sec: str, start: int, end: int, d: int) -> str:
    A, B = fm.A, fm.B
    # no B symbol may straddle the range boundaries
    for s in B.sec_syms.get(sec, []):
        if s.addr < start + d < s.addr + s.size or s.addr < end + d < s.addr + s.size:
            return f"{sec}: B symbol {s.name} straddles the range"
    if sec in BSS_SECTIONS:
        return ""
    if sec in CODE_SECTIONS:
        return ""  # functions verified through the function map
    ba = A.read(start, end - start)
    bb = B.read(start + d, end - start)
    if ba is None or bb is None:
        return f"{sec}: unreadable"
    for off in range(0, end - start, 4):
        ra = A.data_relocs.get(start + off, -1)
        rb = B.data_relocs.get(start + d + off, -1)
        if (ra == -1) != (rb == -1):
            return f"{sec}: relocation layout differs at +{off:#x}"
        if ra != -1:
            if ra is not None and rb is not None and ra in A.func_at:
                p = fm.a2b.get(ra)
                if p is None or p.b.addr != rb:
                    return f"{sec}: pointer at +{off:#x} does not map"
            continue
        if ba[off : off + 4] != bb[off : off + 4]:
            return f"{sec}: bytes differ at +{off:#x}"
    return ""


def propagate(fm: FuncMap, dm: DataMap, do_splits: bool, dry: bool):
    A, B = fm.A, fm.B
    renames: Dict[int, Tuple[Sym, Sym]] = {}  # b addr -> (a sym, b sym)
    conflicts = []
    b_names = Counter(s.name for s in B.syms)

    def want(sa: Sym, sb: Sym):
        if is_auto(sa.name):
            return
        if sb.name == sa.name:
            return
        if not is_auto(sb.name):
            conflicts.append((sa.name, sb.name, sb.addr))
            return
        renames[sb.addr] = (sa, sb)

    for p in fm.pairs:
        if p.confident:
            want(p.a.sym, p.b.sym)
    for aa, ba in dm.a2b.items():
        sa = DataMap._sym(A, aa)
        sb = DataMap._sym(B, ba)
        if sa is not None and sb is not None and sa.type == sb.type:
            want(sa, sb)

    # unit splits
    new_units = []
    unit_syms: List[Sym] = []
    drop_ranges: List[Tuple[str, int, int]] = []
    skipped = []
    if do_splits:
        _, a_units = load_splits(A.split_path)
        b_header, b_units = load_splits(B.split_path)
        have = {u for u, _ in b_units}
        for unit, secs in a_units:
            out = []
            why = ""
            for sec, s, e, extra in secs:
                d, why = section_delta(fm, dm, sec, s, e)
                if d is None:
                    break
                why = verify_range(fm, dm, sec, s, e, d)
                if why:
                    break
                out.append((sec, s + d, e + d, extra, d))
            if why or len(out) != len(secs):
                skipped.append((unit, why))
                continue
            new_units.append((unit, [(sec, s, e, x) for sec, s, e, x, _ in out]))
            for sec, s, e, x, d in out:
                drop_ranges.append((sec, s, e))
                for sa in A.syms:
                    if sa.sec == sec and s - d <= sa.addr < e - d:
                        nb = Sym(rename_addr_suffix(sa.name, d), sa.sec, sa.addr + d, sa.attrs)
                        unit_syms.append(nb)

    # apply symbol edits
    names_in_use = set(b_names)
    new_syms = []
    n_ren = 0
    dup = []
    for sb in B.syms:
        if any(sb.sec == sec and s <= sb.addr < e for sec, s, e in drop_ranges):
            continue
        r = renames.get(sb.addr)
        if r is not None and r[1] is sb:
            sa = r[0]
            scope_global = "scope:local" not in sa.attrs
            if scope_global and sa.name in names_in_use and b_names[sa.name] > 0:
                dup.append(sa.name)
                new_syms.append(sb)
                continue
            attrs = sb.attrs
            m = re.search(r"scope:\w+", sa.attrs)
            if m:
                attrs = re.sub(r"scope:\w+", m.group(0), attrs) if "scope:" in attrs else attrs + " " + m.group(0)
            new_syms.append(Sym(sa.name, sb.sec, sb.addr, attrs))
            names_in_use.add(sa.name)
            n_ren += 1
            continue
        new_syms.append(sb)
    new_syms.extend(unit_syms)
    new_syms.sort(key=lambda s: s.addr)

    print(f"== propagate {A.vid} -> {B.vid}: {n_ren} renames, {len(conflicts)} name conflicts kept, "
          f"{len(dup)} duplicates skipped, {len(new_units)} splits ({len(unit_syms)} symbols)")
    for a, b, addr in conflicts[:20]:
        print(f"   keep {B.vid} {b} @ {addr:#010x} (US says {a})")
    if len(conflicts) > 20:
        print(f"   ... {len(conflicts) - 20} more conflicts")
    for u, why in skipped:
        print(f"   split skipped: {u}: {why}")
    if dry:
        return
    with open(B.sym_path, "w") as fh:
        for s in new_syms:
            fh.write(s.line() + "\n")
    if do_splits:
        b_header, b_units = load_splits(B.split_path)
        names = {u for u, _ in new_units}
        merged = [u for u in b_units if u[0] not in names]
        # keep base-version order
        order = {u: i for i, (u, _) in enumerate(load_splits(A.split_path)[1])}
        merged = sorted(merged + new_units, key=lambda u: (order.get(u[0], 1 << 30), u[1][0][1] if u[1] else 0))
        write_splits(B.split_path, b_header, merged)


# --------------------------------------------------------------------------


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--csv", default=f"{ROOT}/docs/versions/function_map.csv")
    ap.add_argument("--no-csv", action="store_true")
    ap.add_argument("--propagate", action="store_true", help="copy G4SE01 names into the other versions")
    ap.add_argument("--splits", action="store_true", help="with --propagate: also copy TU splits")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--targets", default=",".join(OTHERS))
    ap.add_argument("--min-sim", type=float, default=0.5)
    args = ap.parse_args()

    targets = [t.strip().upper() for t in args.targets.split(",") if t.strip()]
    need = [BASE] + (OTHERS if not args.no_csv else targets)
    V = {v: Version(v) for v in dict.fromkeys(need)}
    maps = {}
    for t in (OTHERS if not args.no_csv else targets):
        maps[(BASE, t)] = FuncMap(V[BASE], V[t], args.min_sim)
        print_stats(maps[(BASE, t)])
    if not args.no_csv:
        maps[("G4SJ01", "G4SP01")] = FuncMap(V["G4SJ01"], V["G4SP01"], args.min_sim)
        print_stats(maps[("G4SJ01", "G4SP01")])
        n = write_csv(args.csv, V, maps)
        print(f"wrote {n} rows to {os.path.relpath(args.csv, ROOT)}")
    if args.propagate:
        for t in targets:
            fm = maps[(BASE, t)]
            dm = DataMap(fm)
            print(f"   {t}: {len(dm.voted)} data symbols by votes, {len(dm.a2b)} total")
            propagate(fm, dm, args.splits, args.dry_run)


if __name__ == "__main__":
    main()
