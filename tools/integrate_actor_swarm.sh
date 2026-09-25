#!/bin/bash
# Integrate an Actor-TU swarm round by CONCATENATION (the agents are append-only) and
# reconcile the shared external-helper prototypes that make a plain merge illegal.
#
# Usage: tools/integrate_actor_swarm.sh <content-base> <fork-point> <branch>...
#   content-base : branch whose src/Game/Actor.cpp is the file we extend (e.g. atu-integrated)
#   fork-point   : the commit the swarm branches forked from (their diff base)
#
# Why concatenation and not `git merge`: every agent appends its own complete block at
# EOF and edits nothing else, so the file is just base + each branch's added lines. A
# textual union merge of two appended C++ blocks produced unbalanced braces and nested
# `extern "C" {` errors; concatenation cannot.
#
# Why the reconciliation step: the mask used for per-unit matching
# (-c functionRelocDiffs=none) ignores relocation NAMES, so two agents can declare the
# same extern "C" helper with different prototypes and both still read 100 % - the
# conflict only appears when the file is compiled as one TU. RECONCILE below rewrites
# the known-different spellings to the one prototype the retail call sites prove.
set -u
repo="/home/sian/Documents/FSA Decomp"
wt=/tmp/atu-integrate
base="${1:?content base branch}"; fork="${2:?fork point}"; shift 2
branches="$*"
cleanup() { git -C "$repo" worktree remove --force "$wt" >/dev/null 2>&1; git -C "$repo" branch -D tmp/atu-integrate >/dev/null 2>&1; }
trap cleanup EXIT

git -C "$repo" worktree add -f "$wt" -b tmp/atu-integrate "$base" >/dev/null || exit 1
mkdir -p "$wt/orig/G4SE01/sys"; cp "$repo/orig/G4SE01/sys/main.dol" "$wt/orig/G4SE01/sys/" || exit 1

python3 - "$repo" "$wt" "$base" "$fork" $branches <<'PY'
import re, subprocess, sys
repo, wt, base, fork = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
# each branch may carry its own fork point as `branch=fork` (needed when a *content* branch has
# advanced since it was last integrated, so its diff would otherwise repeat what is already in base)
specs = []
for a in sys.argv[5:]:
    b, _, f = a.partition("=")
    specs.append((b, f or fork))
path = "src/Game/Actor.cpp"
out = subprocess.run(["git", "-C", repo, "show", "%s:%s" % (base, path)],
                     capture_output=True, text=True, check=True).stdout
if not out.endswith("\n"):
    out += "\n"
total = 0
for b, fork_b in specs:
    diff = subprocess.run(["git", "-C", repo, "diff", "%s..%s" % (fork_b, b), "--", path],
                          capture_output=True, text=True).stdout
    added = [l[1:] for l in diff.splitlines() if l.startswith("+") and not l.startswith("+++")]
    removed = sum(1 for l in diff.splitlines() if l.startswith("-") and not l.startswith("---"))
    if not added and not removed:
        print("  %-14s no change (fork %s)" % (b, fork_b[:7])); continue
    if removed:
        # which functions does this branch (re)define? drop the base's stale copies of them
        names = set()
        for l in added:
            m = re.match(r"^\s*(?:extern\s+\"C\"\s+)?[A-Za-z_][\w:<>,\s\*&]*?\b([A-Za-z_]\w*(?:::\w+)?)\s*\(", l)
            if m and "{" in l:
                names.add(m.group(1))
        for n in sorted(names):
            pat = re.compile(r"^[^\n]*\b" + re.escape(n) + r"\s*\([^;{]*\)[^;\n]*\{[\s\S]*?^\}\n", re.M)
            out, k = pat.subn("", out)
            if k:
                print("     dropped %d stale definition(s) of %s from the base" % (k, n))
    total += len(added)
    out += "\n/* ==== integrated from %s ==== */\n" % b + "\n".join(added) + "\n"
    print("  %-14s +%d lines, -%d lines%s" % (b, len(added), removed,
          "   WARNING: touched existing lines, review by hand" if removed else ""))

# RECONCILE: fn_8013CC50 - retail's 23 call sites set f1 (float) + r5..r10, so the canonical
# prototype is s32(u32, void*, f32, u32 x5). Keep one declaration, permute the call sites
# that spell the same registers differently.
CANON = "s32 fn_8013CC50(u32, void*, f32, u32, u32, u32, u32, u32, u32);"
out = out.replace("void fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);", CANON)
out = out.replace("s32 fn_8013CC50(u32 a, void* b, f32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);", CANON)
out = out.replace('extern "C" void fn_8013CC50(u32 a, void* b, u32 c, void* d, u32 e, u32 f, u32 g, u32 h, f32 i);\n', "")
for code in ("0x6d", "0x6a", "0x6b", "0x6c"):
    out = out.replace("fn_8013CC50(a->field_04, &v, %s, p, 0, 0, 0, 1, lbl_8053F774);" % code,
                      "fn_8013CC50(a->field_04, &v, lbl_8053F774, %s, (u32)p, 0, 0, 0, 1);" % code)
# Every agent declares the helpers it needs, so the same function can arrive declared
# two different ways - C++ forbids overloading an `extern "C"` name, and the compile
# failure that follows is opaque. Dedupe identical declarations and REPORT differing
# ones with both spellings, so the fix is obvious.
decl_re = re.compile(r"^\s*(?:extern\s+\"C\"\s+)?[A-Za-z_][\w:]*[\w\s\*&]*?(\w+)\s*\(([^;{]*)\)\s*;\s*$")
seen, keep, conflicts = {}, [], {}
for l in out.splitlines():
    m = decl_re.match(l)
    if not m:
        keep.append(l); continue
    name = m.group(1)
    # normalise whitespace so cosmetic differences are not reported
    norm = re.sub(r"\s+", " ", l.strip())
    if name in seen:
        if seen[name] != norm:
            conflicts.setdefault(name, {seen[name]}).add(norm)
        continue
    seen[name] = norm
    keep.append(l)
out = "\n".join(keep) + "\n"
if conflicts:
    print("  DECLARATION CONFLICTS (kept the first spelling; review these!):")
    for name, spellings in conflicts.items():
        print("    %s:" % name)
        for sp in spellings:
            print("      %s" % sp)
open(wt + "/" + path, "w").write(out)
print("  merged %d added lines; fn_8013CC50 reconciled to one prototype" % total)
PY

cd "$wt" || exit 1
python3 configure.py >/dev/null 2>&1
ninja -j8 >/tmp/atu-integrate.log 2>&1
if ! grep -q 'build/G4SE01/main.dol: OK' /tmp/atu-integrate.log; then
  echo "--- BUILD FAILED; first errors:"; grep -A2 -iE "error|declarator|overloading" /tmp/atu-integrate.log | head -16; exit 1
fi
echo "--- link OK (main.dol byte-identical to retail)"
build/tools/objdiff-cli diff -p . -u main/Game/Actor -c functionRelocDiffs=none -o /tmp/atu-integrate.json --format json >/dev/null 2>&1
python3 - <<'PY'
import json
d=json.load(open('/tmp/atu-integrate.json')); t=d['left']
fn=[s for s in t['symbols'] if 'instructions' in s]
ok=[s for s in fn if round(s.get('match_percent') or 0,2)==100.0]
print("INTEGRATED: %d/%d at 100%%, %d bytes; partial %d; untouched %d"
      % (len(ok), len(fn), sum(int(s['size']) for s in ok),
         sum(1 for s in fn if 0<round(s.get('match_percent') or 0,2)<100.0),
         sum(1 for s in fn if round(s.get('match_percent') or 0,2)==0.0)))
PY
