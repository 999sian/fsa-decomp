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


def classify(tsize, tcode, bsize, bcode):
    """-> (verdict, detail) for one function's two object encodings."""
    if tsize != bsize:
        return "different-size", ""
    ndiff = sum(1 for i in range(tsize) if tcode[i] != bcode[i])
    tb, bb = branches(tcode, tsize), branches(bcode, bsize)
    if len(tb) != len(bb):
        return "branch-count", "%d vs %d" % (len(tb), len(bb))
    bad = [(a[0], a[1], b[1]) for a, b in zip(tb, bb) if a != b]
    if bad:
        return "branch-difference", str(bad)
    if ndiff:
        return "non-branch-difference", "%d byte(s) outside any branch displacement" % ndiff
    return "identical", ""


def selftest():
    """Synthetic cases, one per verdict: the classifier must separate a display-only
    difference from a real one without any repository state."""
    beq = lambda d: (0x41820000 | (d & 0xFFFC)).to_bytes(4, "big")   # conditional branch
    b_  = lambda d: (0x48000000 | (d & 0x03FFFFFC)).to_bytes(4, "big")  # unconditional
    addi = (0x38600001).to_bytes(4, "big")                            # not a branch
    cases = [
        ("identical",    b"".join([addi, beq(8), addi, addi]), b"".join([addi, beq(8), addi, addi])),
        ("placeholder",  None, None),
    ]
    cases[1] = ("branch-difference", b"".join([addi, beq(8), addi, addi]),
                b"".join([addi, beq(12), addi, addi]))
    cases.append(("non-branch-difference", b"".join([addi, b_(8), addi, addi]),
                  b"".join([(0x38600002).to_bytes(4, "big"), b_(8), addi, addi])))
    cases.append(("different-size", addi * 2, addi * 3))
    ok = True
    for want, tcode, bcode in cases:
        got, detail = classify(len(tcode), tcode, len(bcode), bcode)
        good = got == want
        ok = ok and good
        print("%s classify(%s) = %s %s" % ("PASS" if good else "FAIL", want, got, detail))
    return ok


def main():
    if "--selftest" in sys.argv:
        raise SystemExit(0 if selftest() else 1)
    wt, unit, sym = sys.argv[1], sys.argv[2], sys.argv[3]
    tsize, tcode = load("%s/build/G4SE01/obj/%s.o" % (wt, unit), sym)
    bsize, bcode = load("%s/build/G4SE01/src/%s.o" % (wt, unit), sym)
    verdict, detail = classify(tsize, tcode, bsize, bcode)
    print("%s: target %#x bytes / base %#x; verdict %s %s" % (sym, tsize, bsize, verdict, detail))


if __name__ == "__main__":
    main()
