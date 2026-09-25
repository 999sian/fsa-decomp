#!/usr/bin/env python3
"""Classify an objdiff residue: branch *labels* differ by display address, not by code.

Usage: tools/branch_residue.py <worktree> <unit> <symbol>

Compares the target (dtk-extracted) and base (our compile) objects for one function:
  * the number of differing raw bytes in .text
  * each branch's displacement relative to the function start
Reported as "display artifact" when the sizes match and every relative displacement
matches; otherwise it prints the branches that really differ, with the byte delta.
"""
import re
import struct
import subprocess
import sys


def load(obj, sym):
    size = off = None
    for l in subprocess.run(["objdump", "-t", obj], capture_output=True, text=True).stdout.splitlines():
        if l.rstrip().endswith(sym):
            p = l.split()
            if len(p) >= 6:
                off, size = int(p[0], 16), int(p[4], 16)
    if off is None:
        raise SystemExit("%s: symbol %s not found" % (obj, sym))
    dump = subprocess.run(["objdump", "-s", "-j", ".text", obj], capture_output=True, text=True).stdout
    blob, base = bytearray(), None
    for l in dump.splitlines():
        m = re.match(r"\s*([0-9a-f]{4,})\s((?:[0-9a-f]{2,8}\s){1,4})", l)
        if not m:
            continue
        a = int(m.group(1), 16)
        if base is None:
            base = a
        data = bytes.fromhex(m.group(2).replace(" ", ""))
        if a - base > len(blob):
            blob.extend(b"\0" * (a - base - len(blob)))
        blob.extend(data)
    return size, bytes(blob[off - base:off - base + size])


def branches(code, size):
    out = []
    for i in range(0, size, 4):
        w = struct.unpack_from(">I", code, i)[0]
        op = w >> 26
        if op == 18:
            d = w & 0x03FFFFFC
            out.append((i // 4, d - (1 << 26) if d & (1 << 25) else d))
        elif op == 16:
            d = w & 0xFFFC
            out.append((i // 4, d - (1 << 16) if d & 0x8000 else d))
    return out


def main():
    wt, unit, sym = sys.argv[1], sys.argv[2], sys.argv[3]
    tsize, tcode = load("%s/build/G4SE01/obj/%s.o" % (wt, unit), sym)
    bsize, bcode = load("%s/build/G4SE01/src/%s.o" % (wt, unit), sym)
    n = min(tsize, bsize)
    ndiff = sum(1 for i in range(n) if tcode[i] != bcode[i])
    tb, bb = branches(tcode, tsize), branches(bcode, bsize)
    bad = [(a[0], a[1], b[1]) for a, b in zip(tb, bb) if a != b]
    print("%s: target %#x bytes / base %#x; differing bytes %d; branches %d vs %d"
          % (sym, tsize, bsize, ndiff, len(tb), len(bb)))
    if tsize != bsize:
        print("VERDICT: different size - not a display artifact")
    elif bad:
        print("VERDICT: real branch differences (index, retail disp, ours) = %s" % bad)
    elif ndiff:
        print("VERDICT: real, non-branch code differences: %d byte(s) outside any branch displacement"
              % ndiff)
    else:
        print("VERDICT: identical - any branch-label differences objdiff showed are display artifacts")


if __name__ == "__main__":
    main()
