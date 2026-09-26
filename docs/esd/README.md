# EverydaySimpleDev/FSA-Decomp ("ESD") audit

**What:** https://github.com/EverydaySimpleDev/FSA-Decomp, another G4SE01 decomp, audited at commit `09725c3`.
**Licence:** CC0. On 2026-09-25 the author also gave explicit permission to reuse anything
("Feel free to create your own github / or fork mine!").

## Bottom line
ESD's `configure.py` lists 2553 objects as `Matching`, but most of that count is not decompilation:

| Method | Count | Usable here? |
|---|---|---|
| `.s` objects (dtk disassembly run through `tools/asm_transcribe*.py`) | 1519 Matching (1552 `.s` files, ~30 MB, incl. 1340 `extab_*.s` and data/rodata/sdata dumps) | **No.** This is transcription, and the data dumps contain retail bytes (rules 4/5 spirit). |
| Byte-patched C/C++ objects (`patch=` → `config/G4SE01/patches/*.json`, `tools/patch_obj.py`) | 43 | **No.** Hard rule 3. |
| C/C++ with `opword 0x...` bodies | 14,088 opword lines in 49 files | **No.** This is disguised transcription. |
| `asm`/`ASM`-macro functions inside `.c/.cpp` | 3167 of 4368 scanned functions | **No** (apart from legitimate SDK asm such as PPCSync). |
| Genuine C/C++ that matches exactly under GC/2.6 (unpatched, not asm) | see below | **Yes, after re-verification.** |

Usable exact functions (`usable=y` in `functions.csv`):

| Range | Functions | Bytes |
|---|---|---|
| game (0x800F37A8+) | 821 | 61,824 |
| sdk | 25 | 380 |
| jcore (JKernel/JSupport/JUtility) | 6 | 604 |
| other JSystem | 0 (100% transcribed asm) | 0 |

These counts are a **lower bound**. `compare.py` masked SDA21 relocations incompletely: it did not mask the rA field (r0 in the `.o` becomes r13/r2 once linked). All 10 spot-checked "non-matching" functions were really matches. Re-check any `match_26` in the 95–99.9 range before rewriting the function yourself.

Most usable game functions are small (<100 B) and use raw `this+offset` access and `fn_`/`lbl_` names. Treat them as a starting body, then give them proper types and struct fields.

## Compiler findings
- Game code: all 879 exact game functions compile byte-identically under GC/1.3.2 and GC/2.6 with ESD's flags. There are **no discriminators**, so ESD neither confirms nor refutes our assumed 2.6.
- JSystem: no discriminators either (ESD's JSystem is almost all asm). Our own test already ruled out 1.3.2 for JSystem.
- SDK: OSReport, DSPReadMailFromDSP and DSPSendMailToDSP match only under GC/1.2.5/1.2.5n (they fail the same way under 1.3.2, 2.0, 2.6 and 2.7). This is consistent with the SDK being built with GC/1.2.5n.
- ESD builds everything with GC/1.3.2 + `-O4,p -inline auto -RTTI on -common off -str reuse,pool,readonly -gccinc`. Its flags are **not** ours; always compile with our `cflags_*`.

## How to use it
1. Look up the address in `docs/esd/functions.csv`.
2. If `usable=y` (`match_26=exact`, `asm=n`, `patched_object=n`), take the C body from the ESD source named in `esd_source` (a clone at commit 09725c3). Put it in the right TU of ours, fix the types/names, and compile with our flags.
3. Re-verify with objdiff/ninja. Mark the object `Matching` only when our build matches.
4. Never copy `.s` files, opword bodies, patch JSONs, `mine_text.bin`, `scratch_fileloader_dtor_retail.bin` or `config/G4SE01/reuse/framework.dol.ghidra.map`. Never run `updatel8iOJo/replacement_tmp` (an unknown 24 MB Windows exe).
5. Treat ESD symbol names as hints only. Some, such as `BmgMesgArchive`/`BmcMesgArchive` at 0x80077124+, are invented and conflict with real JMessage names.

Files: `functions.csv` (per-function scan; `asm` includes the ASM-macro fix, `usable` is derived), `knowledge.md` (identifications and naming hints), `tools.md`.
