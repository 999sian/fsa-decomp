#!/usr/bin/env python3
"""Inventory the game's actor vtables straight from the retail DOL.

Every game actor is an `Actor` subclass; its vtable in `.data` is
`{0, 0}` followed by the 19 `Actor` slots, where the ones the class overrides point
at its own functions and the rest point at the `Actor` base implementations. For
the author of an actor TU that override set is exactly what the class declaration
has to reproduce, so this tool lists it.

Usage: tools/actor_vtables.py [worktree]        (default: the current directory)

Reads config/G4SE01/symbols.txt and orig/G4SE01/sys/main.dol (offline, no build
output) and writes docs/gamemap/actor_vtables.csv - one row per vtable:

    vtable,vtable_symbol,slots,overrides,override_slots,override_names

`override_slots` counts the slots that differ from the Actor base vtable
(0x804A5770), and `override_names`/`override_slots` name them. Anchors: BOTS
(0x8049C7F0) overrides the dtor, v01, v06 and v03; STGN (0x804AA7A8) overrides the
dtor, v01, v03, v06.
"""
import csv
import os
import re
import struct
import sys

TEXT_VA, TEXT_OFF = 0x80021840, 0x2600
DATA_VA, DATA_OFF = 0x804916A0, 0x48E6A0
SLOTS = 19
BASE_VTABLE = 0x804A5770

sym_re = re.compile(
    r"^(\S+) = \.(text|data):0x([0-9A-Fa-f]+); // type:(function|object) size:0x([0-9A-Fa-f]+)"
)


def word(dol, va):
    if TEXT_VA <= va < TEXT_VA + 0x43A4A4:
        off = TEXT_OFF + (va - TEXT_VA)
    elif DATA_VA <= va < DATA_VA + 0x20A8C:
        off = DATA_OFF + (va - DATA_VA)
    else:
        return None
    return struct.unpack_from(">I", dol, off)[0]


def vtable(dol, va):
    return [word(dol, va + 4 * i) for i in range(2 + SLOTS)]


def main():
    root = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
    names = {}
    with open(os.path.join(root, "config/G4SE01/symbols.txt")) as fh:
        for line in fh:
            m = sym_re.match(line)
            if m:
                names[int(m.group(3), 16)] = m.group(1)
    dol = open(os.path.join(root, "orig/G4SE01/sys/main.dol"), "rb").read()

    GAME_START, GAME_END = 0x800F37A8, 0x8045BD00  # the game-code .text range

    base = vtable(dol, BASE_VTABLE)
    # every vtables.txt-named one, plus any {0,0} + 19 code pointers in .data
    cands = set(a for a, n in names.items() if n.startswith("__vt__"))
    for va in range(DATA_VA, DATA_VA + 0x1F000, 4):
        w0, w1 = word(dol, va), word(dol, va + 4)
        if w0 == 0 and w1 == 0:
            if all(isinstance(w, int) and TEXT_VA <= w < TEXT_VA + 0x43A4A4
                   for w in vtable(dol, va)[2:]):
                cands.add(va)

    rows = []
    for va in sorted(cands):
        vt = vtable(dol, va)
        if vt[2] is None or not all(isinstance(w, int) for w in vt[2:]):
            continue
        if not all(GAME_START <= w < GAME_END for w in vt[2:]):
            continue  # a JSystem/SDK class vtable, not an Actor subclass
        ov = [i for i in range(SLOTS) if vt[2 + i] != base[2 + i]]
        rows.append({
            "vtable": "0x%08X" % va,
            "vtable_symbol": names.get(va, ""),
            "overrides": len(ov),
            "override_slots": " ".join("dtor" if i == 0 else "v%02d" % i for i in ov),
            "override_names": " ".join(names.get(vt[2 + i], "fn_%08X" % vt[2 + i]) for i in ov),
        })
    out = os.path.join(root, "docs/gamemap/actor_vtables.csv")
    with open(out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()), lineterminator="\n")
        w.writeheader()
        w.writerows(rows)

    anchors = {0x8049C7F0: 4, 0x804AA7A8: 4}
    bad = [("%08X" % a, r["overrides"]) for a, want in anchors.items()
           for r in rows if r["vtable"] == "0x%08X" % a and r["overrides"] != want]
    print("wrote %s: %d vtables" % (out, len(rows)))
    print("anchor check BOTS/STGN (want 4 overrides each):", "FAIL " + str(bad) if bad else "PASS")


if __name__ == "__main__":
    main()
