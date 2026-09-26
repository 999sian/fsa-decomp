#!/usr/bin/env python3
"""Per-function state and shape of the Actor base TU (0x801EE24C-0x801F6058).

Grinding a 32 KB TU needs a triage list, not a function count: this prints/saves
every function of the unit with its current match and a rough *shape* (instruction
count, psq usage, float ops, calls, branches, stmw frame), because the two things
that dominate the cost here are the paired-single idiom (which cannot be produced
from plain C++ - it needs inline asm) and the size of the body.

Usage: tools/actor_tu_functions.py <worktree> [out.csv]     (default docs/gamemap/actor_tu_functions.csv)
Reads config/G4SE01/symbols.txt and an objdiff JSON run of main/Game/Actor.
"""
import csv
import json
import os
import re
import subprocess
import sys

UNIT = "main/Game/Actor"
LO, HI = 0x801EE24C, 0x801F6058


def main():
    wt = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(wt, "docs/gamemap/actor_tu_functions.csv")
    json_path = "/tmp/actor_tu_diff.json"
    subprocess.run(["build/tools/objdiff-cli", "diff", "-p", ".", "-u", UNIT,
                    "-c", "functionRelocDiffs=none", "-o", json_path, "--format", "json"],
                   cwd=wt, capture_output=True, check=True)
    d = json.load(open(json_path))

    # address/size come from symbols.txt (the JSON gives size but not the address)
    addr = {}
    sym_re = re.compile(r"^(\S+) = \.text:0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)")
    for line in open(os.path.join(wt, "config/G4SE01/symbols.txt")):
        m = sym_re.match(line)
        if m and LO <= int(m.group(2), 16) < HI:
            addr[m.group(1)] = int(m.group(2), 16)

    rows = []
    for s in d["left"]["symbols"]:
        if "instructions" not in s:
            continue
        ins = [i["instruction"]["formatted"] for i in s["instructions"] if i.get("instruction")]
        txt = " ".join(ins)
        pct = round(s.get("match_percent") or 0, 2)
        rows.append({
            "address": "0x%08X" % addr.get(s["name"], 0),
            "function": s["name"],
            "size": int(s["size"]),
            "match_percent": pct,
            "state": "matched" if pct == 100.0 else ("partial" if pct else "untouched"),
            "instructions": len(ins),
            "psq_ops": len(re.findall(r"\bpsq_[ls]\b", txt)),
            "float_ops": len(re.findall(r"\b(lfs|stfs|fadds|fsubs|fmuls|fdivs|fcmpo)\b", txt)),
            "calls": len(re.findall(r"\bbl ", txt)),
            "branches": len(re.findall(r"\b(b|bne|beq|bge|blt|bgt|ble|bdnz)\b", txt)),
            "stmw_frame": "yes" if "stmw" in txt else "no",
        })
    rows.sort(key=lambda r: int(r["address"], 16))
    with open(out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()), lineterminator="\n")
        w.writeheader()
        w.writerows(rows)

    def cnt(st):
        sel = [r for r in rows if r["state"] == st]
        return len(sel), sum(r["size"] for r in sel), sum(r["instructions"] for r in sel)
    print("wrote %s: %d functions" % (out, len(rows)))
    for st in ("matched", "partial", "untouched"):
        n, b, i = cnt(st)
        print("  %-9s %2d functions  %6d bytes  %5d instructions" % (st, n, b, i))
    psq_free = [r for r in rows if r["state"] == "untouched" and r["psq_ops"] == 0]
    print("  untouched and psq-free (do these first, the PS idiom needs inline asm):")
    for r in sorted(psq_free, key=lambda r: r["instructions"]):
        print("    %-18s %6s  %3d insns  %2d calls  %2d branches"
              % (r["function"], r["address"], r["instructions"], r["calls"], r["branches"]))


if __name__ == "__main__":
    main()
