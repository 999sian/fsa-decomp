#!/usr/bin/env python3
"""Hoist every `extern "C"` declaration above all function definitions in a multi-branch TU.

Each workstream's block starts with the declarations it needs, and blocks are appended, so a later
block's declaration can end up *after* an earlier block's use - which C++ rejects as an
undefined identifier. Merging the declaration blocks into one at the top fixes that, removes
the ordering hazard for good, and is what the unit needs at the flip anyway (declarations are
non-definition chunks and must not sit between definitions).

Everything else is left in place, including the blank lines between blocks: a naive line-level
pass over this file already produced an uncompilable result once.

Usage: hoist_declarations.py FILE   (prints counts; exit 1 if it moved anything)
"""
import re
import sys

SINGLE = re.compile(r'^extern\s+"C"\s+[^;{]*;\s*$')
# a top-level type definition: workstreams put `struct X { ... };` before the functions that use it,
# and a hoisted declaration that mentions X must not land above it
TYPE = re.compile(r'^(struct|union|class|enum)\s+(\w+)')


def split(lines):
    """Return (prelude, declaration_lines, body_lines, needed).

    `needed` is False when every declaration already precedes every definition - rewriting the
    file anyway would only shuffle blank lines, which makes the tool non-idempotent and hides
    real changes in the integrator's output.
    """
    prelude, decls, body, types = [], [], [], []
    needed = False
    first_body = None
    i = 0
    seen_definition = False
    while i < len(lines):
        line = lines[i]
        if TYPE.match(line) and ";" not in line.split("{")[0]:
            # take the whole top-level definition, including nested braces
            j, depth = i, 0
            while j < len(lines):
                depth += lines[j].count("{") - lines[j].count("}")
                if depth == 0 and j > i:
                    break
                j += 1
            if j < len(lines):
                types.append((TYPE.match(line).group(2), lines[i:j + 1]))
                if first_body is not None:
                    needed = True
                i = j + 1
                continue
        if line.startswith('extern "C" {') or line.startswith('extern "C"{'):
            # take the whole block, wherever it sits
            j = i + 1
            while j < len(lines) and not lines[j].startswith("}"):
                j += 1
            if first_body is not None:
                needed = True
            decls.extend(lines[i:j + 1])
            i = j + 1
            continue
        if SINGLE.match(line):
            if first_body is not None:
                needed = True
            decls.append(line)
            i += 1
            continue
        if not seen_definition and (line.startswith("#") or line.strip() == ""):
            prelude.append(line)
        else:
            seen_definition = True
            if first_body is None:
                first_body = i
            body.append(line)
        i += 1
    return prelude, decls, body, needed, types


def hoist(path):
    lines = open(path).read().splitlines(True)
    prelude, decls, body, needed, types = split(lines)
    if not decls:
        print("  hoist: no declarations found")
        return 0
    # merge into one block: keep the order of first appearance, drop exact duplicates
    inner, seen = [], set()
    for line in decls:
        s = line.strip()
        if s in ('extern "C" {', 'extern "C"{', '}'):
            continue
        key = re.sub(r"\s+", " ", s)
        if key in seen:
            continue
        seen.add(key)
        inner.append(line)
    merged = ['extern "C" {\n'] + inner + ['}\n']
    # types first, then declarations, then definitions - a declaration may name a type
    type_out, seen_types = [], set()
    for name, chunk in types:
        key = re.sub(r"\s+", " ", "".join(chunk).strip())
        if key in seen_types:
            continue
        seen_types.add(key)
        type_out.extend(chunk + ["\n"])
    if not needed and len(decls) == len(merged):
        print("  hoist: declarations already precede every definition")
        return 0
    open(path, "w").write("".join(prelude) + "".join(type_out) + "".join(merged) + "\n" + "".join(body))
    print("  hoist: %d type definition(s), %d declaration line(s) from %d block(s) merged above "
          "%d body line(s)" % (len(type_out), len(inner),
                               sum(1 for l in decls if l.startswith('extern "C" {')), len(body)))
    return 1


if __name__ == "__main__":
    rc = 0
    for p in sys.argv[1:]:
        rc |= hoist(p)
    sys.exit(rc)
