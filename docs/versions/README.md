# Cross-version map (G4SE01 / G4SJ01 / G4SP01)

G4SE01 (USA Rev 0) is the primary, default target. G4SJ01 and G4SP01 have
their own `config/<ID>/` (dtk auto-split, no hand splits yet) and can be
configured and split with `python3 configure.py --version G4SJ01` (or
`G4SP01`) followed by `ninja`.

`tools/version_map.py` pairs every `.init`/`.text` function of the three DOLs
(raw hash, relocation-masked hash, then alignment/similarity for code that
changed) and writes `docs/versions/function_map.csv` (generated, not
committed). Build each version once first so `build/<ID>/asm/` exists.
`--propagate [--splits]` copies hand-chosen US names (and splits) onto the other
versions' configs.

## Results (2026-09-25)

| Pair | Funcs | exact | masked | aligned (changed) | only in A | only in B |
|---|---|---|---|---|---|---|
| US -> JP  | 11556 / 11558 | 32.6% | 65.1% | 2.0% (236) | 22 | 24 |
| US -> PAL | 11556 / 11584 | 34.1% | 57.7% | 8.1% (939) | 11 | 39 |
| JP -> PAL | 11558 / 11584 | 31.2% | 59.3% | 9.2% (1059) | 35 | 61 |

"masked" = same code, only relocated addresses differ, so a matching US TU is
expected to match there too once splits/symbols are ported.

## Version-specific functions

* **SDK (0x8003F960–0x800459B8):** PAL has the newer OS (May 2004) with
  `__OSGetExecParams`, `__OSReboot` rewrite, `__OSCallResetFunctions`,
  `KillThreads` and ~20 other new/changed OS helpers; JP shares some of these
  (JP is between US and PAL). SDK must be decompiled per version.
* **JP-only (JP addrs):** 0x802A8794–0x802DF330 (13 funcs) and
  0x8036D554–0x8036E678 (11 funcs) — most likely text/font (kanji) handling.
* **US-only vs JP (US addrs):** 0x80021840 (jas-sinit stub), 0x801365A8,
  0x80196020, 0x801F3780, 0x8023561C, 0x80286E10, 0x8037F580–0x803837A4,
  0x80398700–0x8039C630, 0x803A2CB0, 0x803B7F6C–0x803B8188,
  0x80430368–0x80431A9C, 0x8045A0D8.
* **PAL-only (PAL addrs):** SDK block above, 0x80117D68, 0x801F4650/46A8,
  0x802FC484, 0x803641DC, 0x80365470, 0x8036D144/D178, 0x80372A10,
  0x8037CD1C/CFF0, 0x803979C4, 0x8039B058–0x8039BC10, 0x803D0EBC,
  0x803F6230/6408, 0x803FA598/A6D8, 0x8044B808 (language selection /
  multi-language message code).
* **US-only vs PAL (US addrs):** 0x8003F960 (`ClearArena`), 0x8004394C,
  0x80043968, 0x8004D388, 0x8013AAD4/AB00, 0x8037F580, 0x80381560,
  0x8038DA00, 0x803A3210, 0x80403204.

Full per-function detail (kind, similarity, confidence) is in the CSV.

## Promotion sweep

`tools/promote_sweep.py` promotes each G4SE01 unit that `tools/mvlink.py`
places in both G4SJ01 and G4SP01 (`Linker.plan`). Each unit is applied to the
two configs (split block plus symbol renames), then both DOLs are built and
checked against `config/<V>/build.sha1`. A unit that fails is reverted alone.
`--dry-run` lists the candidates; results go to `build/promote_sweep.json`.

## Navi Trackers (`G4SJ01_NT`)

Navi Trackers is a separate executable on the Japanese disc, not another
regional FSA main DOL. Its original is `files/DOL/framework.dol`, with SHA1
`ab5f67bcf0687923d8dc1caf5afeb3bb9fe69011`. Put the Japanese disc in
`orig/G4SJ01/`, or supply the extracted binary at
`orig/G4SJ01/files/DOL/framework.dol`. It has separate configuration,
symbols, splits, progress, and build products.

```sh
python3 configure.py --version G4SJ01_NT
ninja -j3
sha1sum -c config/G4SJ01_NT/build.sha1
python3 tools/progress.py --version G4SJ01_NT --test
```

The output is `build/G4SJ01_NT/framework.dol`. The other targets retain their
`main.dol` outputs and original version numbers. NT uses `BUILD_VERSION=3`
and `VERSION_G4SJ01_NT`.

The CI progress matrix includes all four targets and uses their individual
committed snapshots when retail assets are unavailable. Refresh a target's
`config/<target>/progress.json` only from a freshly hash-verified build.
Progress queries must not regenerate `build.ninja` or switch the selected
build target; importing `configure.py` only constructs its configuration.

The FSA `function_map.csv` does not map Navi Trackers. Wind Waker candidates
in `allv-nt-candidates.md` are research leads, not verified names or matches.
Compile donor source against the actual NT binary before accepting it.

The 2026-10-14 NT recovery links `OS.c`, `EXIBios.c`, `mutex_TRK.c`, and
`dolphin_trk_glue.c` from the existing verified SDK sources: 54 additional
functions and 10,808 bytes. All four retail hash gates pass. NT's OS banner
and kernel-report strings identify `Nov 26 2003 05:18:37`; these are selected
only under `VERSION_G4SJ01_NT`. This raises NT source-linked code to
25,232 / 2,010,060 bytes (1.26%), not to complete decompilation.

Wind Waker's `c_node.cpp`, `c_list.cpp`, `c_tag.cpp` and `c_tree.cpp` now have
direct NT verification: all 28 functions match the retail instruction stream,
and all four source objects pass the linked `framework.dol` hash. They contribute
2,008 bytes, bringing NT source-linked code to 27,240 bytes (1.36%) and matched
functions to 222 / 8,120. These are the first source-linked NT framework
components beyond shared SDK/runtime objects. A native smoke run exercised tag
ownership, duplicate-add rejection, empty-list removal, tree bounds and node
insertion. The retail node-order boundary behavior is retained, not normalized.

The MetroTRK architecture audit also source-links `targsupp.s` and
`__exception.s` in all four targets, adding 8,020 bytes per target. These are
PowerPC monitor-call traps and interrupt vectors, retained as architecture
assembly, not claimed as new C/C++ recovery. The vector source is identical
to the public Wind Waker donor; each target's reset/handler relocations are
verified by its retail hash. USA now links all 174 SDK report units.

NT now source-links 35,260 bytes (1.75%), including its 7,988-byte vector table.
That newly classified `.init` table raises the report's total code denominator
from 2,010,060 to 2,018,048 bytes; the retail binary itself has not changed.
FSA source-linked code is now 18.23% USA, 8.73% Japan and 8.51% Europe.

The existing USA `JASHeapCtrl.cpp` remains NonMatching despite 100% per-function
objdiff scores: source linkage moves its initializer from `0x80028CA4` to
`0x80028CB0` and fails the retail hash. Weak-function emission order still
needs reconciliation; do not promote it from objdiff scores alone.

The Actor recovery corrected `fn_801F2618` to return success even when its
optional output vector is null, as retail does. Its 180-byte function now
matches exactly, including its `fn_801F23BC` call target; the Actor TU remains
NonMatching. Reordering `fn_801F3128` temporaries also improves its score to
96.81%. No other Actor function score regressed, and all four hash gates pass.


Passing the retail hash while assembly fallback remains is not a claim of
complete source decompilation; track source-linked code separately.
