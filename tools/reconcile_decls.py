#!/usr/bin/env python3
"""Reconcile conflicting `extern "C"` declarations in a swarm-built TU.

Each agent's block declares the externals it calls, so two blocks can spell the same
function with different parameter lists. MWCC rejects that ("illegal function
overloading"), so before building we keep one spelling per name and drop the others.

Only real declarations are considered: a single-line `extern "C" ...;` at column 0, or a
line inside an `extern "C" { ... }` block. That deliberately excludes call statements
inside function bodies, which a naive regex would match and delete.

Usage: reconcile_decls.py FILE [--keep last]
  --keep first (default) keeps the earliest spelling, last keeps the newest.
Exit code 1 if any declaration was dropped, 0 otherwise, so callers can see it acted.
"""
import re
import sys

# a global declared as an array in one block and a scalar in another: the array form is the
# superset (it can be indexed and dereferenced), so it wins.
VAR = re.compile(r'^\s*(?:extern\s+"C"\s+|extern\s+)?'
                 r'(?:const\s+)?(?:unsigned\s+|signed\s+)?'
                 r'(?:void|char|short|int|long|float|double|bool|u8|u16|u32|u64|s8|s16|s32|s64|f32|f64)'
                 r'[\w\s\*&]*?'
                 r'(\w+)\s*(\[\s*\])?\s*;\s*$')

DECL = re.compile(
    r'^\s*(?:extern\s+"C"\s+)?'
    r'(?:const\s+)?(?:unsigned\s+|signed\s+)?'
    r'(?:void|char|short|int|long|float|double|bool|u8|u16|u32|u64|s8|s16|s32|s64|f32|f64)'
    r'[\w\s\*&]*?'
    r'(\w+)\s*\([^;{]*\)\s*;\s*$'
)


def declaration_lines(lines, only=None):
    """Yield (index, name, normalized) for lines that really declare something.

    With `only`, the matcher is deliberately loose: the caller got the name from the
    compiler, so every line that mentions `name(` and ends in `;` is a candidate and a
    false positive is impossible.
    """
    inside = False
    for i, line in enumerate(lines):
        if line.startswith('extern "C" {') or line.startswith('extern "C"{'):
            if inside:
                print("  ERROR: nested `extern \"C\" {` at line %d - the merge put a block "
                      "inside another one; fix the placement, do not patch around it" % (i + 1))
                sys.exit(2)
            inside = True
            continue
        if inside and line.startswith("}"):
            inside = False
            continue
        single = line.startswith('extern "C" ') and line.rstrip().endswith(";")
        if not (inside or single):
            continue
        if only:
            if only in line and line.rstrip().endswith(";"):
                yield i, only, re.sub(r"\s+", " ", line.strip())
            continue
        m = DECL.match(line)
        if m:
            yield i, m.group(1), re.sub(r"\s+", " ", line.strip())


def variable_lines(lines):
    """Yield (index, name, is_array, normalized) for global variable declarations."""
    inside = False
    for i, line in enumerate(lines):
        if line.startswith('extern "C" {') or line.startswith('extern "C"{'):
            inside = True
            continue
        if inside and line.startswith("}"):
            inside = False
            continue
        single = line.startswith('extern ')
        if not (inside or single):
            continue
        m = VAR.match(line)
        if m and "(" not in line:
            yield i, m.group(1), bool(m.group(2)), re.sub(r"\s+", " ", line.strip())


def main():
    path = sys.argv[1]
    keep = "last" if "--keep" in sys.argv and sys.argv[sys.argv.index("--keep") + 1] == "last" else "first"
    only = sys.argv[sys.argv.index("--only") + 1] if "--only" in sys.argv else None
    lines = open(path).read().splitlines(True)

    by_name = {}
    for i, name, norm in declaration_lines(lines, only):
        by_name.setdefault(name, []).append((i, norm))

    drop = set()
    for name, hits in sorted(by_name.items()):
        spellings = {norm for _i, norm in hits}
        if len(spellings) < 2:
            continue
        keep_idx = hits[-1][0] if keep == "last" else hits[0][0]
        kept = next(norm for i, norm in hits if i == keep_idx)
        for i, norm in hits:
            if i != keep_idx:
                drop.add(i)
        print("  %s: kept %s" % (name, kept))
        for i, norm in hits:
            if i != keep_idx:
                print("    dropped %s" % norm)

    by_var = {}
    for i, name, is_arr, norm in variable_lines(lines):
        by_var.setdefault(name, []).append((i, is_arr, norm))
    for name, hits in sorted(by_var.items()):
        if len({norm for _i, _a, norm in hits}) < 2:
            continue
        # prefer the array spelling; it can be indexed and dereferenced, a scalar cannot
        keep_idx = next((i for i, a, _n in hits if a), hits[0][0])
        print("  variable %s: kept %s" % (name, next(n for i, _a, n in hits if i == keep_idx)))
        for i, _a, norm in hits:
            if i != keep_idx:
                drop.add(i)
                print("    dropped %s" % norm)

    if not drop:
        print("  declarations: no conflicts")
        return 0
    open(path, "w").write("".join(l for i, l in enumerate(lines) if i not in drop))
    print("  dropped %d conflicting declaration(s); the build then judges the call sites" % len(drop))
    return 1


if __name__ == "__main__":
    sys.exit(main())
