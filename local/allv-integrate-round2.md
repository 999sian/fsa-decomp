# allv-integrate round 2: merge omp/allv-promote-jas

Merged `omp/allv-promote-jas` (999f0bb) into `omp/allv-integrate` (6355bab), `--no-ff`.

## Conflicts resolved
- `config/G4SJ01/splits.txt`, `config/G4SP01/splits.txt`: kept both sides. HEAD's sdk-gba `dolphin/gba/GBA.c` split is not in the promote branch and is retained.
- `config/G4SJ01/symbols.txt`: took promote side for all blocks (auto `fn_`/`lbl_` labels renamed to real names at identical addresses). Block with `lbl_8048F1A8` → `XYPAL` + `@18` taken from promote.
- `config/G4SP01/symbols.txt`: took promote side, except four HEAD sdk-gba names that promote had auto-labelled, restored with HEAD's exact lines: `GBAInit` (0x800760F0), `ResetFunctionInfo` (0x804B53B8), `__GBAVersion` (0x805570A8, size 0x4), `__GBAInitFlag` (0x80557AE0, size 0x4).
- Note: an address-only resolution first dropped the four names and a size-0x8 `__GBAVersion` overlap failed the G4SP01 split check. Caught and fixed before commit.

## Gates (retail hash, sha1 of build/V/main.dol vs orig)
- G4SE01 main.dol: d86b3d9f785566e34264035e140ef3daf3cc19f0 OK
- G4SJ01 main.dol: 56097356bceafde9a64abeab8501b909746ac03c OK
- G4SP01 main.dol: 66dbc77f258a64d8bc8d7b0041c619ed70d0c00b OK
- G4SJ01_NT framework.dol: ab5f67bcf0687923d8dc1caf5afeb3bb9fe69011 OK

No unit reverted; no gate failure attributable to a specific promoted unit.

## Progress (tools/progress.py --version V)
- G4SE01: matched code 30.69%; game code 17.53% (3271/6774 fns)
- G4SJ01: matched code 10.46%; game code 0.45% (3/200 fns)
- G4SP01: matched code 10.20%; game code 0.45% (3/200 fns)
- G4SJ01_NT: matched code 0.72%
