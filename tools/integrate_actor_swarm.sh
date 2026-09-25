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
    # The swarm convention is "append your block at the end of the file", so most deltas are
    # pure EOF appends. Their 3 context lines are whatever happened to be last at fork time,
    # which the content base has since replaced, so a 3-way apply conflicts over nothing.
    # Detect that case and append at the true end of file instead.
    hunks=$(grep -c '^@@' /tmp/atu-patch.diff || true)
    removed=$(grep -c '^-[^-]' /tmp/atu-patch.diff || true)
    if [ "$hunks" = "1" ] && [ "$removed" = "0" ]; then
      flines=$(git -C "$repo" show "$f:$path" | wc -l)
      pre=$(grep -m1 '^@@' /tmp/atu-patch.diff | sed 's/^@@ -\([0-9]*\),\([0-9]*\).*/\1 \2/')
      pre_start=${pre% *}; pre_len=${pre#* }
      if [ $((pre_start + pre_len - 1)) -ge "$flines" ]; then
        grep '^+' /tmp/atu-patch.diff | grep -v '^+++' | sed 's/^+//' >> "$wt/$path"
        echo "  appended $added line(s) from $b at EOF (pure append, context stale in the base)"
        git -C "$wt" add -- "$path"
        continue
      fi
    fi
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
lines = open(path).read().splitlines(True)
if any(l.startswith(("<<<<<<<", ">>>>>>>")) or l.rstrip("\n") == "=======" for l in lines):
    # Drop the marker lines and keep both sides (the agents' function sets are disjoint, so
    # the union is what we want). Pairing the markers with a regex is not robust: a conflict
    # can nest inside another one's resolution and leave a stray `>>>>>>>` behind.
    kept = [l for l in lines
            if not l.startswith(("<<<<<<<", ">>>>>>>")) and l.rstrip("\n") != "======="]
    open(path, "w").write("".join(kept))
    print("     markers stripped, both sides kept (union)")
PYEOF
  git -C "$wt" add -- "$path"
done

# two blocks can spell the same external differently, which MWCC rejects outright
python3 "$(dirname "$0")/reconcile_decls.py" "$wt/$path" || true

cd "$wt" || exit 1
python3 configure.py >/dev/null 2>&1
# Repair loop: two blocks can spell the same external differently and MWCC refuses outright
# ("illegal function overloading"). The compiler names the offending declaration, so target
# exactly that name and rebuild rather than guessing which spelling is the odd one out.
for attempt in 1 2 3; do
  ninja -j8 >/tmp/atu-integrate.log 2>&1
  grep -q 'build/G4SE01/main.dol: OK' /tmp/atu-integrate.log && break
  bad=$(grep -B3 'illegal function overloading' /tmp/atu-integrate.log | grep -oE '[A-Za-z_][A-Za-z0-9_]*\(' | tail -1 | tr -d '(')
  if [ -n "$bad" ] && [ "$attempt" -lt 3 ]; then
    echo "  MWCC rejects a second spelling of $bad; keeping one and rebuilding"
    python3 "$(dirname "$0")/reconcile_decls.py" "$wt/$path" --only "$bad" || true
    continue
  fi
  break
done
if ! grep -q 'build/G4SE01/main.dol: OK' /tmp/atu-integrate.log; then
  echo "--- BUILD/GATE FAILED:"
  grep -E '^#|Error|FAILED' /tmp/atu-integrate.log | grep -v '^build/tools' | head -10
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
