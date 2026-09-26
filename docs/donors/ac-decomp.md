# Donor evaluation: Animal Crossing (ACreTeam/ac-decomp)

Evaluated 2026-09-26 against G4SE01 `main.dol`, ac-decomp commit `09ca8e8`.

- **Licence:** CC0 1.0 Universal (public-domain dedication) — reuse is
  unrestricted; still credit it in `NOTICE` if code is imported.
- **Era:** 2001/2002 (GAFE01). Dolphin SDK built with GC/1.2.5n (mtx: GC/1.2.5),
  JSystem with GC/1.3.2 `-O4,s`, MSL with GC/1.3, Runtime/TRK with GC/1.3.2.
  FSA's SDK stamps are 2003, so drift is expected.

## Method

Every `.c/.cpp` under `src/static/{dolphin,TRK_MINNOW_DOLPHIN,MSL_C.PPCEABI.bare.H,Runtime.PPCEABI.H,JSystem}`
(209 files) was compiled twice, sequentially:

1. **AC flags/compiler** (from AC's `configure.py`: `DolphinLib`, `JSystemLib`, MSL/Runtime blocks);
2. **FSA flags/compiler** (SDK: GC/1.2.5n + `cflags_sdk_runtime` + per-lib extras from
   the `sdk` branch; JSystem: GC/2.6 + `cflags_jsystem`).

Each object was scored with `tools/compiler_test/find.py` (masked relocations,
functions >= 6 instructions) in the SDK window (`0x8003F610–0x80077300`) or the
JSystem core window. "FULL" = every instruction of the function matches at a
unique best address. The better of the two builds is counted. Matches were
then checked against the `.text` ranges of objects already `Matching` on the
`sdk` branch (SDK/MSL/Runtime/TRK) and `main` (JSystem).
Only `OSStopwatch.c` failed to compile.

For the Dolphin SDK the two flag sets give identical results (same compiler);
MSL matches only with AC's GC/1.3 flags; JSystem matches noticeably better
with FSA's GC/2.6 `-O4,p` than with AC's GC/1.3.2 `-O4,s`.

## Results

| Library | AC files | fns scored | FULL | FULL bytes | FULL **not** already Matching in our tree |
|---|---:|---:|---:|---:|---|
| dolphin/gba | 6 | 34 | 30 | 6456 | **12 fns, 4152 B** (GBAJoyBoot.c TU) |
| dolphin/os | 23 | 182 | 105 | 18572 | 0 |
| dolphin/card | 18 | 121 | 72 | 20560 | 0 |
| dolphin/dvd | 6 | 144 | 59 | 9664 | 0 |
| dolphin/gx | 21 | 264 | 31 | 4840 | 0 |
| dolphin/si | 2 | 29 | 20 | 4164 | 0 |
| dolphin/pad | 2 | 32 | 12 | 3116 | 0 |
| dolphin/OdemuExi2 | 1 | 18 | 12 | 2680 | 0 |
| dolphin/ai, ar, vi, mtx, db, dsp, base | 11 | 86 | 45 | 5816 | 0 |
| dolphin/exi (incl. EXIAd16) | 3 | 36 | 4 | 1024 | 0 |
| dolphin/amcstubs, odenotstub | 2 | 0 (all < 6 instrs) | – | – | already Matching on `sdk` |
| MSL_C | 38 | 83 | 46 | 14776 | 0 |
| Runtime | 9 | 26 | 20 | 2360 | 0 |
| TRK_MINNOW_DOLPHIN | 22 | 130 | 41 | 6924 | 0 |
| JSystem/JKernel | 22 | 318 | 140 | 15668 | 0 real (6 hits are ambiguous tiny ctors/dtors) |
| JSystem/JUtility | 14 | 198 | 97 | 22008 | 16 fns, 3136 B — but mkdd already matches 11 of them |
| JSystem/JSupport, J2DGraph, JFramework, JGadget | 8 | 118 | 50 | 5116 | 0 |

### Where AC beats our donors

1. **GBAJoyBoot.c (0x8007581C–0x8007689C)** — the only substantial win.
   The `sdk` branch has it `NonMatching` (tww-derived). AC's `GBAJoyBoot.c` +
   `GBAGetProcessStatus.c` match **every function except `GBAJoyBoot`**
   exactly under FSA's GC/1.2.5n flags: `GBAGetProcessStatus` (93/93 instrs;
   sdk: 28/90), `F29` (32/32; sdk: 42/235), `__GBAX01`, and all of
   `GBAJoyBootAsync, F23–F39`. The `sdk` version matches `GBAJoyBoot` itself
   (18/18, AC 9/17). Combining the two (AC's bodies + sdk's `GBAJoyBoot`, both
   in one TU as FSA links them) should give a full match of this 4.2 KB TU.
   AC's static helpers `F72/F95/F104` have no standalone copy in FSA (inlined).
2. **GBAKey.c (0x80076EBC–0x80077124, 616 B)** — AC has it as
   `jaudio_NES/internal/dsp_GBAKey.c`. Same size (154 instrs) but only 31 %
   masked match (AC forces `DEBUG 1`, panic/`__FILE__` scheduling differs).
   Useful as a starting point; nothing else public has it.
3. **JUtility**, over mkdd: 5 extra exact functions —
   `JUTGamePad::init`, `JUTGamePad::CRumble::startMotor`, `JUTFader::control`,
   `JUTException::run` (+ one more small ctor). JUTException/JUTGamePad/JUTFader
   are not yet Matching; mkdd remains the base (JUTException 92.5 % vs AC 80 %).

Everything else AC matches (OS, CARD, DVD, SI, PAD, OdemuExi2, MSL, Runtime,
TRK…) is already `Matching` on `sdk` via pikmin2/dolsdk2004/tww. AC does not
have `GBAKey.c`/`dsp_task.c`/`gd` as SDK files, and its EXIAd16/CARDRaw/
CARDDelete/CARDRename/CARDStatEx/GX verifier files have no FSA counterpart (0 FULL).

## Recommendation

Not a general donor — its SDK is older and fully covered. Use it **targeted**:
the `sdk` owner should take AC's `GBAJoyBoot.c`/`GBAGetProcessStatus.c` to
finish FSA's `GBAJoyBoot.c`, and look at `dsp_GBAKey.c` for `GBAKey.c`;
JUtility work may cross-check the 5 functions above. Credit it in `NOTICE` when
anything is imported.
