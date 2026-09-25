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
