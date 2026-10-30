#!/usr/bin/env python3
"""Scope every `Object(Matching, ...)` in configure.py to the versions that actually link it.

A plain `Matching` links the unit in *every* version the config builds. That is only true for
objects verified in all of them: an object matched from the US source links its compiled
object, and if the regional retail unit has different functions (or the same functions under
regional names) the regional link fails with undefined symbols. tww solves this with
`MatchingFor("GZLJ01", "GZLE01", "GZLP01")` per object.

This derives the per-object version list from what each version already links today: a unit
present in `config/<V>/splits.txt` at HEAD is one that version has been building, so keep V
in the list; a unit added since (e.g. by `version_map.py --propagate --splits`, which makes a
version *measure* a unit without proving it links) is left out, so it is diffed from the
compiled source but linked from the retail asm.

    tools/scope_matching.py --dry-run          # what would change
    tools/scope_matching.py                    # rewrite configure.py
"""
import argparse
import pathlib
import re
import subprocess
import sys
from collections import Counter

ROOT = pathlib.Path(__file__).resolve().parent.parent
DEFAULT = "G4SE01"
OTHERS = ["G4SJ01", "G4SP01"]
ENTRY = re.compile(r'Object\(Matching,\s*"([^"]+)"')  # keeps any trailing args (extra_cflags, ...)


def head_units(version: str) -> set[str]:
    """Source paths the version's committed splits build (git HEAD: config/<V>/splits.txt)."""
    try:
        text = subprocess.run(["git", "show", f"HEAD:config/{version}/splits.txt"], cwd=ROOT,
                              capture_output=True, text=True, check=True).stdout
    except subprocess.CalledProcessError:
        sys.exit(f"no HEAD:config/{version}/splits.txt (run from the repository)")
    return {m.group(1) for m in re.finditer(r"^(\S.*?):\s*$", text, re.M)}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--configure", default=str(ROOT / "configure.py"))
    ap.add_argument("--versions", default=",".join(OTHERS), help="versions that may be added to the list")
    ap.add_argument("--base", default=DEFAULT)
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    path = pathlib.Path(args.configure)
    text = path.read_text()
    if "def MatchingFor" not in text:
        sys.exit(f"{path} has no `def MatchingFor`, so per-version matching cannot be written")
    others = [v for v in args.versions.split(",") if v]
    units = {v: head_units(v) for v in others}

    seen = Counter()

    def repl(m: re.Match) -> str:
        src = m.group(1)
        versions = [args.base] + [v for v in others if src in units[v]]
        seen[tuple(versions)] += 1
        return "Object(MatchingFor(%s), \"%s\"" % (", ".join(f'"{v}"' for v in versions), src)

    new, n = ENTRY.subn(repl, text)
    print(f"{n} Matching entries in {path.name}")
    for versions, count in sorted(seen.items(), key=lambda kv: -kv[1]):
        print(f"   {count:4}  MatchingFor({', '.join(versions)})")
    print(f"   {len(re.findall(r'Object\(Matching,', new)):4}  still plain Matching")
    if args.dry_run or new == text:
        return 0
    path.write_text(new)
    print(f"wrote {path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
