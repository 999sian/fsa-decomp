#!/usr/bin/env python3
"""Check a unit's function order against the retail layout.

A `NonMatching` unit is not linked, so objdiff pairs functions by name and nobody
notices the order. The moment the unit is flipped to `Matching` its object IS linked,
and then the functions must sit at the retail addresses in the retail order - which
means the order of the definitions in the source file matters.

This reports the two orders side by side and lists the functions that are out of place,
so the fix is "move this definition", not "re-derive anything".

Usage: tools/check_unit_order.py <worktree> <unit-path-without-ext>
   e.g. tools/check_unit_order.py ~/Documents/FSA-worktrees/atu-integrated Game/Actor
"""
import re
import subprocess
import sys

sym_re = re.compile(r"^(\S+) = \.text:0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)")


def main():
    wt = sys.argv[1]
    unit = sys.argv[2]
    obj = "%s/build/G4SE01/src/%s.o" % (wt, unit)

    # retail order: symbols.txt, by address, inside the unit's split ranges
    ranges = []
    blk = None
    for line in open("%s/config/G4SE01/splits.txt" % wt):
        m = re.match(r"^(\S+):\s*$", line)
        if m:
            blk = m.group(1)
        m2 = re.match(r"^\s+\.text\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)", line)
        if m2 and blk == unit + ".cpp":
            ranges.append((int(m2.group(1), 16), int(m2.group(2), 16)))
    retail = []
    for line in open("%s/config/G4SE01/symbols.txt" % wt):
        m = sym_re.match(line)
        if not m:
            continue
        a, sz = int(m.group(2), 16), int(m.group(3), 16)
        if any(lo <= a < hi for lo, hi in ranges):
            retail.append((a, sz, m.group(1)))
    retail.sort()

    # object order: nm sorted by value == .text layout order
    out = subprocess.run(["nm", "--defined-only", "-S", obj], capture_output=True, text=True).stdout
    objf = []
    for line in out.splitlines():
        p = line.split()
        if len(p) >= 4 and p[2] == "T":
            objf.append((int(p[0], 16), int(p[1], 16), p[3]))
    objf.sort()

    retail_names = [n for _a, _s, n in retail]
    obj_names = [n for _a, _s, n in objf]
    print("%s: %d functions in the split range, %d defined in the object"
          % (unit, len(retail), len(objf)))
    common = set(retail_names) & set(obj_names)
    only_retail = [n for n in retail_names if n not in common]
    only_obj = [n for n in obj_names if n not in common]
    print("  defined in the object but not in the split range:", only_obj[:6] or "none")
    print("  in the split range but not defined yet:", len(only_retail), "function(s)")

    seq_r = [n for n in retail_names if n in common]
    seq_o = [n for n in obj_names if n in common]
    if seq_r == seq_o:
        print("  ORDER: identical for the %d shared functions" % len(common))
        return
    # first divergence + the offending functions
    for i, (a, b) in enumerate(zip(seq_r, seq_o)):
        if a != b:
            print("  ORDER: first divergence at position %d" % i)
            print("    retail wants: %s" % " ".join(seq_r[i:i + 5]))
            print("    object has  : %s" % " ".join(seq_o[i:i + 5]))
            break
    missing = [n for n in seq_r if n not in seq_o]
    print("  %d of %d shared functions are in a different position" % (
        sum(1 for a, b in zip(seq_r, seq_o) if a != b), len(common)))
    print("  -> reorder the definitions in the source file; no function needs re-deriving.")


if __name__ == "__main__":
    main()
