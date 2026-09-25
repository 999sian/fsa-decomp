#!/usr/bin/env python3
"""Compare the call targets of every function in a unit, name by name.

The project's matching mask is `-c functionRelocDiffs=none`, which normalises relocation
*operands* - that is what makes dtk's reconstructed relocations comparable, but it also
means **objdiff will not tell you that a `bl` points at the wrong function**. A unit can
read 100 % per function and still link to the wrong addresses, and the only other gate
(the DOL hash) cannot run while the unit is `NonMatching`.

So when a unit is heading for a `Matching` flip, check the call targets explicitly: this
lists, per function, the sequence of `bl` target names in the retail object and in ours,
and reports the first difference.

Usage: tools/check_call_targets.py <worktree> <unit-path-without-ext> [max_functions]
"""
import json
import os
import re
import subprocess
import sys

BL = re.compile(r"^bl\s+(\S+)")


def calls(stream):
    out = []
    for entry in stream:
        ins = entry.get("instruction")
        if not ins:
            continue
        m = BL.match(ins["formatted"].strip())
        if m:
            out.append(m.group(1))
    return out


def main():
    wt, unit = sys.argv[1], sys.argv[2]
    limit = int(sys.argv[3]) if len(sys.argv) > 3 else 10 ** 6
    json_path = "/tmp/call_targets.json"
    # objdiff-cli is built per worktree; fall back to a sibling worktree that has it.
    cand = [os.environ.get("OBJDIFF", ""), os.path.join(wt, "build/tools/objdiff-cli"),
            os.path.expanduser("~/Documents/FSA-worktrees/actor-base/build/tools/objdiff-cli")]
    bin_ = next((c for c in cand if c and os.path.exists(c)), None)
    if bin_ is None:
        raise SystemExit("objdiff-cli not found - build it in the worktree or set OBJDIFF")
    subprocess.run([bin_, "diff", "-p", ".", "-u", "main/" + unit,
                    "-c", "functionRelocDiffs=none", "-o", json_path, "--format", "json"],
                   cwd=wt, capture_output=True, check=True)
    d = json.load(open(json_path))
    left = {s["name"]: s for s in d["left"]["symbols"] if "instructions" in s}
    right = {s["name"]: s for s in d["right"]["symbols"] if "instructions" in s}

    bad = []
    for name, t in left.items():
        b = right.get(name)
        if b is None:
            continue  # not implemented yet
        tc, bc = calls(t.get("instructions", [])), calls(b.get("instructions", []))
        if tc != bc:
            first = next((i for i, (x, y) in enumerate(zip(tc, bc)) if x != y), min(len(tc), len(bc)))
            bad.append((name, len(tc), len(bc), tc[first:first + 3], bc[first:first + 3]))
    print("%s: %d functions with instructions on both sides; %d with a call-target difference"
          % (unit, sum(1 for n in left if n in right), len(bad)))
    for name, lt, lb, tv, bv in bad[:limit]:
        print("  %s: target has %d calls, ours %d" % (name, lt, lb))
        print("     retail: %s" % " ".join(tv))
        print("     ours  : %s" % " ".join(bv))
    if not bad:
        print("  every implemented function's `bl` sequence is name-identical to retail.")


if __name__ == "__main__":
    main()
