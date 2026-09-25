#!/bin/bash
# Integrate a swarm round of Actor-TU work into one branch, then verify it.
#
# Usage: tools/integrate_actor_swarm.sh <content-base> <default-fork> <branch>[=<fork>]...
#   content-base : the branch whose src/Game/Actor.cpp we extend (e.g. atu-integrated)
#   default-fork : the commit the swarm branches forked from (e.g. bdf810d)
#   branch=fork  : optional per-branch fork point - use it when a branch was integrated
#                  earlier and has advanced since, otherwise its diff repeats what is
#                  already in the content base.
#
# Integration is by `git apply -3` of each branch's delta, i.e. a patch with the branch's
# own fork point as the merge base. Plain concatenation cannot express "this branch
# replaced an existing function", and hand-rolled definition removal truncated a body in
# testing; `git apply` handles additions, rewrites and deletions and fails loudly.
#
# Then it builds, runs the DOL gate and prints the verified total.
set -u
repo="/home/sian/Documents/FSA Decomp"
wt=/tmp/atu-integrate
base="${1:?content base branch}"; fork="${2:?default fork point}"; shift 2
branches="$*"
path=src/Game/Actor.cpp

cleanup() {
  git -C "$repo" worktree remove --force "$wt" >/dev/null 2>&1
  git -C "$repo" branch -D tmp/atu-integrate >/dev/null 2>&1
}
trap cleanup EXIT

git -C "$repo" worktree add -f "$wt" -b tmp/atu-integrate "$base" >/dev/null || exit 1
mkdir -p "$wt/orig/G4SE01/sys"
cp "$repo/orig/G4SE01/sys/main.dol" "$wt/orig/G4SE01/sys/" || exit 1

for spec in $branches; do
  b="${spec%%=*}"; f="${spec#*=}"
  if [ "$f" = "$spec" ]; then f="$fork"; fi
  if git -C "$repo" diff "$f..$b" -- "$path" > /tmp/atu-patch.diff 2>/dev/null && [ -s /tmp/atu-patch.diff ]; then
    added=$(grep -c '^+' /tmp/atu-patch.diff || true)
    git -C "$wt" apply -3 --whitespace=nowarn /tmp/atu-patch.diff 2>/tmp/atu-apply.err
    rc=$?
    if [ $rc -eq 0 ]; then
      echo "  applied $added added-line(s) from $b (fork $f)"
    elif grep -q "with conflicts" /tmp/atu-apply.err; then
      # the branch touched a line the content base already normalised (e.g. a shared
      # declaration one of us re-spelled) - keep both sides and let the build judge
      echo "  applied $added added-line(s) from $b (fork $f) WITH CONFLICTS (union-resolved below)"
    else
      echo "  PATCH FAILED for $b (fork $f):"
      head -3 /tmp/atu-apply.err
      exit 1
    fi
  else
    echo "  $b: no change vs fork $f"
  fi
  # resolve any markers this patch left and stage the result, otherwise the index stays
  # unmerged and the next `git apply` refuses to run
  python3 - "$wt/$path" <<'PYEOF'
import re, sys
path = sys.argv[1]
s = open(path).read()
if "<<<<<<<" in s:
    s = re.sub(r"<<<<<<< [^\n]*\n(.*?)=======\n(.*?)>>>>>>> [^\n]*\n",
               lambda m: m.group(1) + m.group(2), s, flags=re.S)
    open(path, "w").write(s)
    print("     markers union-resolved (disjoint function sets, both sides kept)")
PYEOF
  git -C "$wt" add -- "$path"
done

python3 - "$wt/$path" <<'PY'
import re, sys
path = sys.argv[1]
s = open(path).read()
decl = re.compile(r'^(?:extern\s+"C"\s+)?[A-Za-z_][\w:]*[\w\s\*&]*?(\w+)\s*\([^;{]*\)\s*;\s*$')
kept, problems = {}, 0
for line in s.splitlines(True):
    m = decl.match(line)
    if not m:
        continue
    name, norm = m.group(1), re.sub(r"\s+", " ", line.strip())
    if name in kept:
        if kept[name] != norm:
            problems += 1
            print("  DECLARATION DISAGREEMENT for %s:" % name)
            print("    first: %s" % kept[name])
            print("    other: %s" % norm)
    else:
        kept[name] = norm
print("  declarations: %d names, %d disagreement(s)" % (len(kept), problems))
PY

cd "$wt" || exit 1
python3 configure.py >/dev/null 2>&1
ninja -j8 >/tmp/atu-integrate.log 2>&1
if ! grep -q 'build/G4SE01/main.dol: OK' /tmp/atu-integrate.log; then
  echo "--- BUILD/GATE FAILED:"
  grep -A3 -iE "error|FAILED" /tmp/atu-integrate.log | head -12
  exit 1
fi
echo "--- link OK (build/G4SE01/main.dol byte-identical to retail)"
git -C "$wt" add -A src/Game/Actor.cpp
git -C "$wt" -c user.name=swarm -c user.email=swarm@local commit -q -m "Actor TU: integrate swarm round ($(date +%H:%M))"
round_commit=$(git -C "$wt" rev-parse HEAD)
git -C "$repo" branch -f "$base" "$round_commit" >/dev/null 2>&1 && echo "--- committed to $base ($round_commit)"
od=/home/sian/Documents/FSA-worktrees/actor-base/build/tools/objdiff-cli
"$od" diff -p . -u main/Game/Actor -c functionRelocDiffs=none -o /tmp/atu-integrate.json --format json >/dev/null 2>&1
python3 - <<'PY'
import json
d = json.load(open('/tmp/atu-integrate.json')); t = d['left']
fn = [s for s in t['symbols'] if 'instructions' in s]
ok = [s for s in fn if round(s.get('match_percent') or 0, 2) == 100.0]
print("INTEGRATED: %d/%d at 100%%, %d bytes; partial %d; untouched %d"
      % (len(ok), len(fn), sum(int(s['size']) for s in ok),
         sum(1 for s in fn if 0 < round(s.get('match_percent') or 0, 2) < 100.0),
         sum(1 for s in fn if round(s.get('match_percent') or 0, 2) == 0.0)))
PY
