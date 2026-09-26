#!/bin/bash
# Reproduce the integration check: merge every  bootstrap branch into a base ref
# (default: main), build, and print the linked-DOL proof.
#
# The five  branches all fork from 7d76751 and each appends independent blocks to
# configure.py / splits.txt / symbols.txt, so the merges conflict textually. This
# script resolves exactly those conflicts by keeping BOTH sides (the blocks are
# independent address ranges) and then proves the union is sane before building:
#   * one cflags_game, one def GameLib, one GameLib(...) call
#   * no duplicated Game/actors object entries
#   * per-unit split blocks still parse
#
# Usage: tools/check_omp_merge.sh [base-ref]
# Leaves nothing behind: the worktree and temp branch are removed on exit.
set -u
base="${1:-main}"
repo="$(cd "$(dirname "$0")/.." && pwd)"
wt=/tmp/-merge-check
branches="actor-base actors actors actors actors"

cleanup() {
  git -C "$repo" worktree remove --force "$wt" >/dev/null 2>&1
  git -C "$repo" branch -D tmp/-merge-check >/dev/null 2>&1
}
trap cleanup EXIT

git -C "$repo" worktree add -f "$wt" -b tmp/-merge-check "$base" >/dev/null || exit 1
mkdir -p "$wt/orig/G4SE01/sys"
cp "$repo/orig/G4SE01/sys/main.dol" "$wt/orig/G4SE01/sys/" || exit 1

for b in $branches; do
  git -C "$wt" -c user.name=check -c user.email=check@local merge --no-edit "$b" >/dev/null 2>&1
  if git -C "$wt" status --short | grep -qE '^(UU|AA)'; then
    git -C "$wt" status --short | grep -E '^(UU|AA)' | sed 's/^/  conflict: /'
    python3 - "$wt" <<'PY'
import re, sys
root = sys.argv[1]
for p in ("config/G4SE01/splits.txt", "config/G4SE01/symbols.txt", "configure.py"):
    path = root + "/" + p
    s = open(path).read()
    if "<<<<<<<" in s:
        s = re.sub(r"<<<<<<< [^\n]*\n(.*?)=======\n(.*?)>>>>>>> [^\n]*\n",
                   lambda m: m.group(1) + m.group(2), s, flags=re.S)
        open(path, "w").write(s)
        print("  union-resolved:", p)
PY
    git -C "$wt" add -A
    git -C "$wt" -c user.name=check -c user.email=check@local commit -q --no-edit
  fi
done

echo "--- union sanity (expect 1 / 1 / 1 and no duplicate object entries):"
echo "  cflags_game=$(grep -c '^cflags_game = \[' "$wt/configure.py") GameLib-def=$(grep -c '^def GameLib' "$wt/configure.py") GameLib-call=$(grep -c '^    GameLib(' "$wt/configure.py")"
echo "  game objects: $(grep -o 'Object(Matching, "Game/actors/[A-Z]*\.cpp")' "$wt/configure.py" | sort | uniq -c | tr '\n' ' ')"

cd "$wt" || exit 1
python3 configure.py >/dev/null 2>&1 || { echo "configure.py FAILED"; exit 1; }
ninja -j8 >/tmp/-merge-check.log 2>&1
echo "--- link: $(grep -c 'build/G4SE01/main.dol: OK' /tmp/-merge-check.log) OK line(s), sha1=$(sha1sum build/G4SE01/main.dol | cut -c1-40)"
python3 - <<'PY'
import json
r = json.load(open("build/G4SE01/report.json"))
m = r["measures"]
print("--- totals: %s/%s code bytes (%.2f%%), %s/%s functions (%.2f%%)"
      % (m["matched_code"], m["total_code"], float(m["matched_code_percent"]),
         m["matched_functions"], m["total_functions"], float(m["matched_functions_percent"])))
for u in r["units"]:
    if u["name"].startswith("main/Game/") and u["measures"].get("matched_code") != "0":
        print("   ", u["name"].split("/", 1)[1], u["measures"]["matched_code"], "bytes,",
              u["measures"]["matched_functions"], "functions")
print("--- JSystem units matched:",
      sum(1 for u in r["units"] if u["name"].startswith("main/JSystem/")
          and u["measures"].get("matched_code") != "0"))
PY
