#!/usr/bin/env python3
"""Mechanical fixes applied to a multi-branch TU before compiling.

Each workstream writes its own block and each block is right on its own branch; a few
spellings only conflict once the blocks share a file. These fixes are codegen-neutral by
construction, so they are safe to apply to the union.

Currently: a global declared as an array (needed by `@ha`/`@l` index sites) cannot be used
bare - `32.0f * lbl_X` is a type error. `X[0]` materialises the same address as `X`, so the
scalar use is rewritten. Asm blocks and relocation expressions are never touched.

Usage: integration_fixes.py FILE [FILE...]   (prints what it changed; exit 1 if it changed any)
"""
import re
import sys

VAR = re.compile(
    r'^\s*(?:extern\s+"C"\s+|extern\s+)?'
    r'(?:const\s+)?(?:unsigned\s+|signed\s+)?'
    r'(?:void|char|short|int|long|float|double|bool|u8|u16|u32|u64|s8|s16|s32|s64|f32|f64)'
    r'[\w\s\*&]*?(\w+)\s*(\[\s*\])?\s*;\s*$'
)


def array_globals(lines):
    inside = False
    names = set()
    for line in lines:
        if line.startswith('extern "C" {') or line.startswith('extern "C"{'):
            inside = True
            continue
        if inside and line.startswith("}"):
            inside = False
            continue
        if not (inside or line.startswith("extern ")):
            continue
        m = VAR.match(line)
        if m and "(" not in line and m.group(2):
            names.add(m.group(1))
    return names


def fix(path):
    lines = open(path).read().splitlines(True)
    names = array_globals(lines)
    if not names:
        print("  integration fixes: nothing to do")
        return 0
    changed = 0
    out = []
    in_asm = 0
    for line in lines:
        # track the asm region rather than skipping any line that mentions __asm: real asm
        # blocks are multi-line, but a one-liner would otherwise hide normal code on the
        # same line (and the rewrite is not valid inside asm)
        if "__asm" in line and "{" in line:
            in_asm += line.count("{") - line.count("}")
            out.append(line)
            continue
        if in_asm:
            in_asm += line.count("{") - line.count("}")
            out.append(line)
            continue
        if "@ha" in line or "@l" in line or "@sda21" in line:
            out.append(line)
            continue
        new = line
        for name in names:
            # skip the declaration itself, member accesses, and existing index uses
            if re.match(r'^\s*(?:extern\s+)?[\w\s\*&]*' + re.escape(name) + r'\s*\[\s*\]\s*;', line):
                continue
            new = re.sub(r'(?<![\w.>&])' + re.escape(name) + r'(?!\s*\[)(?![\w])', name + "[0]", new)
        if new != line:
            changed += 1
            print("  scalar use of array global -> %s" % new.strip()[:96])
        out.append(new)
    if changed:
        open(path, "w").write("".join(out))
        print("  integration fixes: %d line(s) rewritten" % changed)
    else:
        print("  integration fixes: array globals %s, no bare uses" % ", ".join(sorted(names)))
    return 1 if changed else 0


if __name__ == "__main__":
    rc = 0
    for p in sys.argv[1:]:
        rc |= fix(p)
    sys.exit(rc)
