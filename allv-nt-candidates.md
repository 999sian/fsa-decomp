# NT (framework.dol, G4SJ01_NT) auto-chunk → TWW candidate mapping

Read-only research. No source, config, or symbol edits. Branch `omp/allv-tww-research` (from `omp/all-version-round8` @ 1458d15).

## Inputs and gates

- NT binary: `orig/G4SJ01/framework.dol`, SHA1 `ab5f67bcf0687923d8dc1caf5afeb3bb9fe69011` (matches the G4SJ01_NT gate).
- NT auto chunks: `build/G4SJ01_NT/report.json` + `config/G4SJ01_NT/symbols.txt` (fn_ labels with sizes), read from the shared checkout `FSA-worktrees/actor-round8-clean` (dtk output; not committed to this branch). 145 auto `.text`/`.init` units, 2,018,056 bytes.
- TWW: `zeldaret/tww` shallow clone at `FSA-worktrees/tww-clone`, commit `4d78c99` (outside the FSA repo). Used `config/GZLE01/symbols.txt` (13,758 `.text` function entries with address/size/mangled name) and `config/GZLE01/splits.txt` (671 TUs with `.text` ranges, paths relative to `src/`).

## What the clone can and cannot prove

- **No TWW retail DOL is available.** `tww-clone/orig/*` is empty (gitignored), so no TWW byte is available for comparison. No chunk is byte-matched or byte-ruled-out. Every "candidate" below is structural, not byte-level.
- **Method A (file-string identity):** NT's `.rodata` `__FILE__`/assert strings (e.g. `f_op_scene_mng.cpp`, `JKRAramStream.cpp`, `d_s_play.cpp`) were tied to the chunk whose code references them via `lis`/`addi|lo` pairs. Each filename was then searched in `tww-clone/src/`.
- **Method B (exact size run):** NT function sizes (fn_ labels) inside each chunk were matched against consecutive TWW function sizes within each GZLE01 TU. Score = longest exact contiguous run of sizes; TWW span and first matched name reported.
- **Confidence rule (honest ceilings):** High = run ≥15 fns AND ≥1 KiB of TWW bytes; Medium = run ≥8 AND ≥256 B; Low = run ≥4 or file-string only; None = otherwise. Any candidate whose TWW span or start address is shared with another chunk is marked **Ambiguous**. Size-only evidence is weak for tiny getter/dtor runs, so the byte threshold is the main guard.
- Byte confirmation requires a TWW GZLE01 `main.dol` (or `rels`) placed into `tww-clone/orig/GZLE01/` and an objdiff/ninja run on the NT side. Not done (assignment: no build).

## Summary


- Chunks: 145. High 2, Medium 7, Low 32, Ambiguous 6, None 98.
- Chunks with any TWW candidate (run ≥4 or file-string): 47.
- NT contains TWW-era framework code (`f_op_*`, `f_pc_*`, `d_*`, `m_Do_*`, `J3D*`, `JKR*`, `JStudio`, `dolphin/os`, `TRK`/`Metrowerks`) but also NT-only file names (`d_a_tetora.cpp`, `d_naviCardResult.cpp`, `d_fileSave.cpp`, `d_gbaCheck.cpp`, `d_information.cpp`, `d_a_studio.cpp`), which have no TWW source and should be treated as NT-specific.
- NT strings `08May2003` and `/bin/Final/framework.map` place the build around May 2003; TWW GZLE01 is a different build, so size equality is not guaranteed even for shared sources.
- The JAudio/BTMS/NEMO importer question is not answered: the only chunk carrying `bgm_aka_l.dsp`/`mrvsndInitEnd` strings (`auto_03_80057614`) matched `d/d_drawlist.cpp` on sizes alone, which is suspect; no TWW source contains those strings.


## Top candidates (≥8 required)

Each row = NT chunk → TWW TU / first matched symbol. Confidence is structural; none is byte-confirmed.

| # | NT chunk | NT run start | TWW TU | TWW run start | Run (fns / bytes) | Why it is a candidate | Caveat |
|---|---|---|---|---|---|---|---|
| 1 | `auto_03_80196344_text` (0x80196344, 61496 B) | 0x801A4B74 | `src/JSystem/J3DGraphBase/J3DMatBlock.cpp` | 0x802EB400 `getTexCoord__21J3DTexGenBlockPatchedFUl` | 65 / 1608 | Longest large-run match; contiguous J3DTexGen/MatBlock names | Chunk has 574 fns; only 65 are contiguous matches |
| 2 | `auto_03_801BA958_text` (0x801BA958, 156380 B) | 0x801C009C | `src/dolphin/os/OSThread.c` | 0x80307854 `DefaultSwitchThreadCallback` | 29 / 7576 | Strongest byte-bearing run in the set; file string `FPU-unavailable handler installed` sits in chunk | Chunk is 704 fns; OS thread code likely shared with other SDK units |
| 3 | `auto_03_80015D50_text` (0x80015D50, 3028 B) | 0x80016320 | `src/m_Do/m_Do_MemCard.cpp` | 0x8001931C `SaveSync__15mDoMemCd_Ctrl_cFv` | 8 / 1136 | Name-pattern match on `mDoMemCd_Ctrl_c` methods | Only 8 fns; no file string |
| 4 | `auto_03_80019470_text` (0x80019470, 31652 B) | 0x8001BEA4 | `src/f_pc/f_pc_layer.cpp` | 0x8003D800 `fpcLy_CancelQTo__FP24process_method_tag_class` | 15 / 372 | File strings `f_op_overlap_mng.cpp`, `f_op_scene_mng.cpp`, `f_pc_deletor.cpp` sit in chunk | Chunk spans several TWW TUs; match covers only f_pc layer |
| 5 | `auto_03_80057614_text` (0x80057614, 41704 B) | 0x80061548 | `src/d/d_drawlist.cpp` | 0x80086AE0 `__dt__22dDlst_alphaModelPacketFv` | 10 / 948 | Destructor/packet name run | Sizes only; its file strings `bgm_aka_l.dsp`/`mrvsndInitEnd` do not belong to d_drawlist (suspect) |
| 6 | `auto_03_800872F8_text` (0x800872F8, 9568 B) | 0x80088D50 | `src/d/d_s_menu.cpp` | 0x8022F748 `__dt__11myFontClassFv` | 9 / 292 | `myFontClass` names; file string `d_s_play.cpp` is a sibling TU | Could be coincidental small-function run |
| 7 | `auto_03_801146E4_text` (0x801146E4, 5360 B) | 0x80115610 | `src/SSystem/SComponent/c_tag.cpp` | 0x80245410 `cTg_IsUse__FP16create_tag_class` | 8 / 508 | `cTg_*` tag list functions | No file string; sizes only |
| 8 | `auto_03_80135F7C_text` (0x80135F7C, 27136 B) | 0x80135F7C | `src/JSystem/JParticle/JPADrawVisitor.cpp` | 0x802664F4 `__dt__24JPADrawCalcChildAlphaOutFv` | 10 / 920 | JPAD visitor/draw-calc classes | Sizes only; no file string |
| 9 | `auto_03_801E1910_text` (0x801E1910, 62132 B) | 0x801F013C | `src/OdemuExi2/DebuggerDriver.c` | 0x80337BE0 `DBClose` | 14 / 2688 | Debugger/DB API; file strings `GCN_Mem_Alloc.c`, `MetroTRK` in same chunk | `GCN_Mem_Alloc.c` not in TWW src; Metrowerks/TRK region may be shared SDK code |
## Sailed / ambiguous candidates (why not used)

- **`auto_03_80077DA0`, `auto_03_8007BCD0`, `auto_03_8008065C`** (`d_a_npc_fa1` run of 4 fns, 188 B each): all three NT chunks match the same TWW start `0x800FD71C`. Duplicate hits mean the size pattern is common, not identity. Marked Ambiguous.
- **`auto_03_80166424`, `auto_03_80178E80`, `auto_03_801A7C3C`** (`J3DMaterialFactory.cpp` `JSUConvertOffsetToPtr<…>` template run, 13–19 fns, 312–456 B): all three share TWW start `0x802F9848`. Template instantiations repeat; Ambiguous.
- **`auto_03_8011F23C`** (`JSGCamera.cpp` run of 17 fns but only 84 B): tiny accessor functions; sizes meaningless without bytes. Low.
- **`auto_03_8000D404`** (`m_Do_ext.cpp`, run 25 / 0xcc B, file string `m_Do_ext.cpp` present): run is J3DPEBlock/J3DColorBlock getters, mostly ≤0x20 B. TU identity from the file string is real; code identity is not byte-proven. Table: Low (+file-string).
- **`auto_03_80006500_text`** (OSReport chunk, file string `m_Do_graphic.cpp`): OSReport functions exist in TWW `m_Do_printf.cpp`, but the largest run is 3 fns. Low.
- **Data-only chunks** (`.sdata`, `.sbss`, `.sdata2`, `.bss`-style units in the report) are not text and are excluded from the function match.

## Full mapping table (145 auto text/init chunks)

Columns: NT chunk | address | size | NT fn count (from NT fn_ labels) | best exact-size run (fns / TWW bytes) | TWW TU | TWW candidate span (GZLE01) | first matched TWW symbol | file-string evidence (→ TWW src) | confidence.


| NT auto-chunk | Addr | Size | NT fns | Best exact-size run (fns / TWW bytes) | TWW TU (`src/…`) | TWW candidate span (GZLE01) | First matched TWW fn | File-string evidence → TWW src | Confidence |
|---|---|---|---|---|---|---|---|---|---|
| `auto_00_80003100_init` | 0x80003100 | 0x2444 | 14 | 2 | — | — | — | — | None |
| `auto_03_80006500_text` | 0x80006500 | 0x4f70 | 36 | 3 | — | — | — | `src/m_Do/m_Do_graphic.cpp` | Low (file-string only) |
| `auto_03_8000B48C_text` | 0x8000B48C | 0x1efc | 30 | 8 / 0x74 | `src/d/actor/d_a_player_main.cpp` | 0x80147540–0x801475B4 | `checkCutCharge__9daPy_lk_cCFv` | — | Low |
| `auto_03_8000D404_text` | 0x8000D404 | 0x522c | 157 | 25 / 0xcc | `src/m_Do/m_Do_ext.cpp` | 0x800100F0–0x800101BC | `getZCompLoc__10J3DPEBlockCFv` | `src/m_Do/m_Do_ext.cpp` | Low (+file-string) |
| `auto_03_8001267C_text` | 0x8001267C | 0x188 | 4 | 2 | — | — | — | — | None |
| `auto_03_8001287C_text` | 0x8001287C | 0x11b4 | 29 | 4 / 0x140 | `src/m_Do/m_Do_hostIO.cpp` | 0x80017C00–0x80017D40 | `__dt__13mDoHIO_root_cFv` | — | Low |
| `auto_03_80013A80_text` | 0x80013A80 | 0x2240 | 55 | 4 / 0x90 | `src/f_pc/f_pc_method.cpp` | 0x8003EF38–0x8003EFC8 | `fpcMtd_Execute__FP20process_method_classPv` | — | Low |
| `auto_03_80015D50_text` | 0x80015D50 | 0xbd4 | 21 | 8 / 0x470 | `src/m_Do/m_Do_MemCard.cpp` | 0x8001931C–0x8001978C | `SaveSync__15mDoMemCd_Ctrl_cFv` | — | Medium |
| `auto_03_80016928_text` | 0x80016928 | 0xc54 | 13 | 3 | — | — | — | — | None |
| `auto_03_800175B8_text` | 0x800175B8 | 0x16d8 | 23 | 3 | — | — | — | — | None |
| `auto_03_80019470_text` | 0x80019470 | 0x7ba4 | 291 | 15 / 0x174 | `src/f_pc/f_pc_layer.cpp` | 0x8003D800–0x8003D974 | `fpcLy_CancelQTo__FP24process_method_tag_class` | `src/f_op/f_op_overlap_mng.cpp`, `src/f_op/f_op_scene_mng.cpp` | Medium |
| `auto_03_80021184_text` | 0x80021184 | 0x1564 | 25 | 2 | — | — | — | — | None |
| `auto_03_800227C8_text` | 0x800227C8 | 0x28b4 | 33 | 2 | — | — | — | — | None |
| `auto_03_80025170_text` | 0x80025170 | 0x2468 | 75 | 4 / 0x80 | `src/d/actor/d_a_arrow.cpp` | 0x800D8200–0x800D8280 | `daArrowCreate__FPv` | — | Low |
| `auto_03_80027638_text` | 0x80027638 | 0x9108 | 113 | 5 / 0xc8 | `src/f_pc/f_pc_method.cpp` | 0x8003EF00–0x8003EFC8 | `fpcMtd_Method__FPFPv_iPv` | — | Low |
| `auto_03_80030778_text` | 0x80030778 | 0x989c | 121 | 4 / 0x100 | `src/d/d_com_inf_game.cpp` | 0x800529DC–0x80052ADC | `createMagma__14dComIfG_play_cFv` | — | Low |
| `auto_03_8003A2B0_text` | 0x8003A2B0 | 0x658 | 8 | 5 / 0x168 | `src/d/d_s_play.cpp` | 0x8023658C–0x802366F4 | `__dt__17dScnPly_msg_HIO_cFv` | — | Low |
| `auto_03_8003A944_text` | 0x8003A944 | 0x7238 | 90 | 6 / 0xf8 | `src/d/d_kankyo_wether.cpp` | 0x800871A0–0x80087298 | `__dt__8RAIN_EFFFv` | — | Low |
| `auto_03_80041C10_text` | 0x80041C10 | 0xc0e8 | 82 | 4 / 0x10 | `src/m_Do/m_Do_ext.cpp` | 0x8000F758–0x8000F768 | `patchTexNoAndTexCoordScale__11J3DTevBlockFv` | `src/d/d_particle.cpp` | Low |
| `auto_03_8004E268_text` | 0x8004E268 | 0x694 | 12 | 4 / 0x120 | `src/d/d_meter.cpp` | 0x80205870–0x80205990 | `__dt__20dMeter_message_HIO_cFv` | — | Low |
| `auto_03_8004E938_text` | 0x8004E938 | 0xbc | 2 | 2 | — | — | — | — | None |
| `auto_03_8004EA68_text` | 0x8004EA68 | 0x84 | 1 | 1 | — | — | — | — | None |
| `auto_03_8004ECA8_text` | 0x8004ECA8 | 0xb8 | 2 | 2 | — | — | — | — | None |
| `auto_03_8004EF64_text` | 0x8004EF64 | 0x860 | 19 | 4 / 0x148 | `src/d/d_particle.cpp` | 0x8007D094–0x8007D1DC | `calc3D__13dPa_control_cFv` | — | Low |
| `auto_03_8004F844_text` | 0x8004F844 | 0x7d94 | 67 | 7 / 0x1c0 | `src/d/d_item.cpp` | 0x800C3AD4–0x800C3C94 | `item_func_sword__Fv` | — | Low |
| `auto_03_80057614_text` | 0x80057614 | 0xa2e8 | 176 | 10 / 0x3b4 | `src/d/d_drawlist.cpp` | 0x80086AE0–0x80086E94 | `__dt__22dDlst_alphaModelPacketFv` | — | Medium |
| `auto_03_80061948_text` | 0x80061948 | 0xb690 | 186 | 3 | — | — | — | `d_a_monitor.cpp` (no TWW src) | None |
| `auto_03_8006D2D0_text` | 0x8006D2D0 | 0x1ee4 | 29 | 2 | — | — | — | — | None |
| `auto_03_8006F204_text` | 0x8006F204 | 0x1b24 | 26 | 2 | — | — | — | `src/d/d_npc.cpp` | Low (file-string only) |
| `auto_03_80070D78_text` | 0x80070D78 | 0x6fec | 99 | 4 / 0xe8 | `src/SSystem/SComponent/c_cc_d.cpp` | 0x80242ABC–0x80242BA4 | `CrossCo__12cCcD_TriAttrCFRC12cCcD_CpsAttrPf` | — | Low |
| `auto_03_80077DA0_text` | 0x80077DA0 | 0x3ef4 | 37 | 4 / 0xbc | `src/d/actor/d_a_npc_fa1.cpp` | 0x800FD71C–0x800FD7D8 | `daNpc_Fa1_Execute__FP11daNpc_Fa1_c` | — | Ambiguous (span shared by 3 chunks) |
| `auto_03_8007BCD0_text` | 0x8007BCD0 | 0x4950 | 44 | 4 / 0xbc | `src/d/actor/d_a_npc_fa1.cpp` | 0x800FD71C–0x800FD7D8 | `daNpc_Fa1_Execute__FP11daNpc_Fa1_c` | — | Ambiguous (span shared by 3 chunks) |
| `auto_03_8008065C_text` | 0x8008065C | 0x6298 | 51 | 4 / 0xbc | `src/d/actor/d_a_npc_fa1.cpp` | 0x800FD71C–0x800FD7D8 | `daNpc_Fa1_Execute__FP11daNpc_Fa1_c` | `d_a_tetora.cpp` (no TWW src) | Ambiguous (span shared by 3 chunks) |
| `auto_03_80086930_text` | 0x80086930 | 0x96c | 9 | 2 | — | — | — | — | None |
| `auto_03_800872F8_text` | 0x800872F8 | 0x2560 | 57 | 9 / 0x124 | `src/d/d_s_menu.cpp` | 0x8022F748–0x8022F86C | `__dt__11myFontClassFv` | `src/d/d_s_play.cpp` | Medium |
| `auto_03_80089D2C_text` | 0x80089D2C | 0x10c8 | 11 | 2 | — | — | — | — | None |
| `auto_03_8008AE90_text` | 0x8008AE90 | 0xf00 | 14 | 3 | — | — | — | `d_a_studio.cpp` (no TWW src) | None |
| `auto_03_8008BE14_text` | 0x8008BE14 | 0x1d0c | 36 | 2 | — | — | — | — | None |
| `auto_03_8008DC60_text` | 0x8008DC60 | 0x14160 | 285 | 4 / 0x1cc | `src/d/d_stage.cpp` | 0x80042FC4–0x80043190 | `dStage_dt_c_offsetToPtr__FPv` | — | Low |
| `auto_03_800A2F34_text` | 0x800A2F34 | 0x2068 | 25 | 2 | — | — | — | — | None |
| `auto_03_800A50EC_text` | 0x800A50EC | 0xb80c | 97 | 2 | — | — | — | — | None |
| `auto_03_800B0EE8_text` | 0x800B0EE8 | 0x9dfc | 71 | 2 | — | — | — | — | None |
| `auto_03_800BB070_text` | 0x800BB070 | 0x2ff8 | 37 | 2 | — | — | — | — | None |
| `auto_03_800BE1CC_text` | 0x800BE1CC | 0x620c | 61 | 2 | — | — | — | `d_naviCardResult.cpp` (no TWW src) | None |
| `auto_03_800C4768_text` | 0x800C4768 | 0x1390 | 33 | 3 | — | — | — | — | None |
| `auto_03_800C5DA4_text` | 0x800C5DA4 | 0x3b14 | 48 | 2 | — | — | — | `d_fileSave.cpp` (no TWW src) | None |
| `auto_03_800C9C64_text` | 0x800C9C64 | 0x1d90 | 21 | 2 | — | — | — | — | None |
| `auto_03_800CBB28_text` | 0x800CBB28 | 0xb84 | 15 | 2 | — | — | — | — | None |
| `auto_03_800CC7B4_text` | 0x800CC7B4 | 0x161c | 18 | 2 | — | — | — | — | None |
| `auto_03_800CDE98_text` | 0x800CDE98 | 0x29ac | 21 | 2 | — | — | — | — | None |
| `auto_03_800D0910_text` | 0x800D0910 | 0x2cf0 | 24 | 3 | — | — | — | — | None |
| `auto_03_800D36D0_text` | 0x800D36D0 | 0x39ec | 46 | 2 | — | — | — | — | None |
| `auto_03_800D73FC_text` | 0x800D73FC | 0x16ff4 | 167 | 2 | — | — | — | — | None |
| `auto_03_800EEEC0_text` | 0x800EEEC0 | 0xcc8 | 17 | 2 | — | — | — | — | None |
| `auto_03_800EFC44_text` | 0x800EFC44 | 0x2c50 | 21 | 3 | — | — | — | — | None |
| `auto_03_800F2CD4_text` | 0x800F2CD4 | 0x1d80 | 24 | 2 | — | — | — | — | None |
| `auto_03_800F4B7C_text` | 0x800F4B7C | 0x15140 | 185 | 3 | — | — | — | `d_information.cpp` (no TWW src) | None |
| `auto_03_8010ABB0_text` | 0x8010ABB0 | 0x1fec | 30 | 2 | — | — | — | — | None |
| `auto_03_8010CD28_text` | 0x8010CD28 | 0x464 | 7 | 2 | — | — | — | `d_gbaCheck.cpp` (no TWW src) | None |
| `auto_03_8010D1DC_text` | 0x8010D1DC | 0x35b8 | 35 | 2 | — | — | — | — | None |
| `auto_03_8011093C_text` | 0x8011093C | 0x1270 | 17 | 2 | — | — | — | — | None |
| `auto_03_80111CDC_text` | 0x80111CDC | 0x2988 | 28 | 3 | — | — | — | — | None |
| `auto_03_801146E4_text` | 0x801146E4 | 0x14f0 | 68 | 8 / 0x1fc | `src/SSystem/SComponent/c_tag.cpp` | 0x80245410–0x8024560C | `cTg_IsUse__FP16create_tag_class` | — | Medium |
| `auto_03_80115D38_text` | 0x80115D38 | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_80115D98_text` | 0x80115D98 | 0x544 | 5 | 1 | — | — | — | — | None |
| `auto_03_801162F4_text` | 0x801162F4 | 0x668 | 12 | 3 | — | — | — | — | None |
| `auto_03_80116A14_text` | 0x80116A14 | 0x18b4 | 18 | 2 | — | — | — | — | None |
| `auto_03_80118310_text` | 0x80118310 | 0x41a8 | 86 | 5 / 0x294 | `src/JSystem/JUtility/JUTGamePad.cpp` | 0x802C3F10–0x802C41A4 | `checkResetSwitch__10JUTGamePadFv` | `src/JSystem/JUtility/JUTPalette.cpp` | Low |
| `auto_03_8011C5B4_text` | 0x8011C5B4 | 0x2c40 | 28 | 3 | — | — | — | — | None |
| `auto_03_8011F23C_text` | 0x8011F23C | 0x16abc | 427 | 17 / 0x54 | `src/JSystem/JStage/JSGCamera.cpp` | 0x8026DD9C–0x8026DDF0 | `JSGSetProjectionFar__Q26JStage7TCameraFf` | `src/JSystem/JUtility/JUTGba.cpp` | Low |
| `auto_03_80135F7C_text` | 0x80135F7C | 0x6a00 | 185 | 10 / 0x398 | `src/JSystem/JParticle/JPADrawVisitor.cpp` | 0x802664F4–0x8026688C | `__dt__24JPADrawCalcChildAlphaOutFv` | — | Medium |
| `auto_03_8013CD54_text` | 0x8013CD54 | 0xc50 | 28 | 4 / 0x15c | `src/JSystem/JStudio/JStudio_JStage/object-ambientlight.cpp` | 0x8027716C–0x802772C8 | `__dt__Q214JStudio_JStage21TAdaptor_ambientLightFv` | — | Low |
| `auto_03_8013DD14_text` | 0x8013DD14 | 0x3d8 | 9 | 2 | — | — | — | — | None |
| `auto_03_8013E314_text` | 0x8013E314 | 0x80c | 13 | 5 / 0x13c | `src/JSystem/JStudio/JStudio_JStage/object-light.cpp` | 0x802787C4–0x80278900 | `adaptor_do_data__Q214JStudio_JStage14TAdaptor_lightFPCQ27JStudio7TObjectPCvUlPCvUl` | — | Low |
| `auto_03_8013EDB8_text` | 0x8013EDB8 | 0x1dc8 | 37 | 6 / 0x92c | `src/dolphin/gba/GBAJoyBoot.c` | 0x802A0D38–0x802A1664 | `F31` | `GBAKey.c` (no TWW src) | Low |
| `auto_03_80140D7C_text` | 0x80140D7C | 0x168 | 3 | 2 | — | — | — | — | None |
| `auto_03_80141ABC_text` | 0x80141ABC | 0x64 | 1 | 1 | — | — | — | — | None |
| `auto_03_80141EA4_text` | 0x80141EA4 | 0x29c | 3 | 1 | — | — | — | — | None |
| `auto_03_80142810_text` | 0x80142810 | 0x330 | 3 | 1 | — | — | — | — | None |
| `auto_03_80143D68_text` | 0x80143D68 | 0x324 | 4 | 2 | — | — | — | — | None |
| `auto_03_80145B14_text` | 0x80145B14 | 0x150 | 1 | 1 | — | — | — | — | None |
| `auto_03_80146A6C_text` | 0x80146A6C | 0x7c | 2 | 2 | — | — | — | — | None |
| `auto_03_8014723C_text` | 0x8014723C | 0x20 | 1 | 1 | — | — | — | — | None |
| `auto_03_80147740_text` | 0x80147740 | 0xcc | 2 | 1 | — | — | — | — | None |
| `auto_03_80148084_text` | 0x80148084 | 0x4 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014810C_text` | 0x8014810C | 0x160 | 1 | 1 | — | — | — | — | None |
| `auto_03_80148518_text` | 0x80148518 | 0x34 | 1 | 1 | — | — | — | — | None |
| `auto_03_80148AB4_text` | 0x80148AB4 | 0x44 | 1 | 1 | — | — | — | — | None |
| `auto_03_801497B0_text` | 0x801497B0 | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_80149854_text` | 0x80149854 | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014998C_text` | 0x8014998C | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_80149A5C_text` | 0x80149A5C | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_80149AEC_text` | 0x80149AEC | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014A5DC_text` | 0x8014A5DC | 0x190 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014D134_text` | 0x8014D134 | 0xa4 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014D3BC_text` | 0x8014D3BC | 0xfc | 1 | 1 | — | — | — | — | None |
| `auto_03_8014D7C8_text` | 0x8014D7C8 | 0x194 | 3 | 2 | — | — | — | — | None |
| `auto_03_8014DCB0_text` | 0x8014DCB0 | 0x240 | 4 | 2 | — | — | — | — | None |
| `auto_03_8014E080_text` | 0x8014E080 | 0x448 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014E5AC_text` | 0x8014E5AC | 0x330 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014EBF4_text` | 0x8014EBF4 | 0x340 | 5 | 3 | — | — | — | — | None |
| `auto_03_8014F078_text` | 0x8014F078 | 0x274 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014F6D0_text` | 0x8014F6D0 | 0x120 | 1 | 1 | — | — | — | — | None |
| `auto_03_8014FE38_text` | 0x8014FE38 | 0xc | 1 | 1 | — | — | — | — | None |
| `auto_03_80150490_text` | 0x80150490 | 0x3cc | 3 | 2 | — | — | — | — | None |
| `auto_03_80153460_text` | 0x80153460 | 0x18c | 3 | 2 | — | — | — | — | None |
| `auto_03_80153EE4_text` | 0x80153EE4 | 0xc4 | 1 | 1 | — | — | — | — | None |
| `auto_03_80154C64_text` | 0x80154C64 | 0x244 | 2 | 2 | — | — | — | — | None |
| `auto_03_8015549C_text` | 0x8015549C | 0x44 | 1 | 1 | — | — | — | — | None |
| `auto_03_801555FC_text` | 0x801555FC | 0x188 | 3 | 2 | — | — | — | — | None |
| `auto_03_80155F70_text` | 0x80155F70 | 0x30c | 3 | 2 | — | — | — | — | None |
| `auto_03_80156318_text` | 0x80156318 | 0x1a4 | 3 | 2 | — | — | — | — | None |
| `auto_03_80156E1C_text` | 0x80156E1C | 0x354 | 2 | 1 | — | — | — | — | None |
| `auto_03_801572A8_text` | 0x801572A8 | 0x8c | 2 | 2 | — | — | — | — | None |
| `auto_03_801573CC_text` | 0x801573CC | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_80157424_text` | 0x80157424 | 0x8 | 1 | 1 | — | — | — | — | None |
| `auto_03_8015765C_text` | 0x8015765C | 0x4c | 5 | 3 | — | — | — | — | None |
| `auto_03_80157854_text` | 0x80157854 | 0x50 | 1 | 1 | — | — | — | — | None |
| `auto_03_80157A54_text` | 0x80157A54 | 0x70 | 5 | 4 / 0x50 | `src/m_Do/m_Do_ext.cpp` | 0x800173F0–0x80017440 | `@88@36@calc__25mDoExt_MtxCalcAnmBlendTblFUs` | — | Low |
| `auto_03_80157B00_text` | 0x80157B00 | 0x154 | 5 | 3 | — | — | — | — | None |
| `auto_03_80157F50_text` | 0x80157F50 | 0x28 | 1 | 1 | — | — | — | — | None |
| `auto_03_80158020_text` | 0x80158020 | 0xa4 | 1 | 1 | — | — | — | — | None |
| `auto_03_80158210_text` | 0x80158210 | 0x6c | 5 | 2 | — | — | — | — | None |
| `auto_03_80158728_text` | 0x80158728 | 0x20c | 4 | 1 | — | — | — | — | None |
| `auto_03_801589D8_text` | 0x801589D8 | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_80158B3C_text` | 0x80158B3C | 0x2c | 1 | 1 | — | — | — | — | None |
| `auto_03_80158E18_text` | 0x80158E18 | 0x4d74 | 138 | 6 / 0x270 | `src/JSystem/JKernel/JKRHeap.cpp` | 0x802B0224–0x802B0494 | `__dt__7JKRHeapFv` | `src/JSystem/JKernel/JKRHeap.cpp`, `src/JSystem/JKernel/JKRExpHeap.cpp` | Low (+file-string) |
| `auto_03_8015DBF4_text` | 0x8015DBF4 | 0xe84 | 12 | 3 | — | — | — | `src/JSystem/JKernel/JKRAram.cpp` | Low (file-string only) |
| `auto_03_8015EABC_text` | 0x8015EABC | 0x438 | 8 | 4 / 0x1e4 | `src/JSystem/JKernel/JKRAramHeap.cpp` | 0x802B55D8–0x802B57BC | `allocFromHead__11JKRAramHeapFUl` | — | Low |
| `auto_03_8015EF38_text` | 0x8015EF38 | 0x700 | 11 | 4 / 0x238 | `src/JSystem/JKernel/JKRAramPiece.cpp` | 0x802B5F68–0x802B61A0 | `startDMA__12JKRAramPieceFP12JKRAMCommand` | — | Low |
| `auto_03_8015F67C_text` | 0x8015F67C | 0x930 | 18 | 5 / 0x198 | `src/JSystem/JKernel/JKRAramStream.cpp` | 0x802B61E4–0x802B637C | `create__13JKRAramStreamFl` | `src/JSystem/JKernel/JKRAramStream.cpp` | Low (+file-string) |
| `auto_03_8015FFF0_text` | 0x8015FFF0 | 0x4988 | 90 | 2 | — | — | — | `src/JSystem/JKernel/JKRAramArchive.cpp`, `src/JSystem/JKernel/JKRCompArchive.cpp` | Low (file-string only) |
| `auto_03_801649BC_text` | 0x801649BC | 0xc00 | 8 | 2 | — | — | — | — | None |
| `auto_03_80165600_text` | 0x80165600 | 0xde0 | 14 | 2 | — | — | — | — | None |
| `auto_03_80166424_text` | 0x80166424 | 0x12a40 | 536 | 16 / 0x180 | `src/JSystem/J3DGraphLoader/J3DMaterialFactory.cpp` | 0x802F9848–0x802F99C8 | `JSUConvertOffsetToPtr<17J3DCurrentMtxInfo>__FPCvPCv` | — | Medium |
| `auto_03_80178E80_text` | 0x80178E80 | 0x19f98 | 416 | 13 / 0x138 | `src/JSystem/J3DGraphLoader/J3DMaterialFactory.cpp` | 0x802F9848–0x802F9980 | `JSUConvertOffsetToPtr<17J3DCurrentMtxInfo>__FPCvPCv` | — | Medium |
| `auto_03_80192E40_text` | 0x80192E40 | 0x3344 | 91 | 5 / 0x8c | `src/JSystem/J3DGraphBase/J3DShapeMtx.cpp` | 0x802DCE78–0x802DCF04 | `getType__19J3DShapeMtxMultiImmCFv` | — | Low |
| `auto_03_80196344_text` | 0x80196344 | 0xf038 | 574 | 65 / 0x648 | `src/JSystem/J3DGraphBase/J3DMatBlock.cpp` | 0x802EB400–0x802EBA48 | `getTexCoord__21J3DTexGenBlockPatchedFUl` | — | High |
| `auto_03_801A53A0_text` | 0x801A53A0 | 0x27a0 | 33 | 5 / 0x14c | `src/JSystem/J3DGraphBase/J3DDrawBuffer.cpp` | 0x802ECBEC–0x802ECD38 | `entryModelSort__13J3DDrawBufferFP12J3DMatPacket` | — | Low |
| `auto_03_801A7C3C_text` | 0x801A7C3C | 0x12a3c | 389 | 19 / 0x1c8 | `src/JSystem/J3DGraphLoader/J3DMaterialFactory.cpp` | 0x802F9848–0x802F9A10 | `JSUConvertOffsetToPtr<17J3DCurrentMtxInfo>__FPCvPCv` | — | Medium |
| `auto_03_801BA834_text` | 0x801BA834 | 0x10 | 1 | 1 | — | — | — | — | None |
| `auto_03_801BA958_text` | 0x801BA958 | 0x262dc | 704 | 29 / 0x1d98 | `src/dolphin/os/OSThread.c` | 0x80307854–0x803095EC | `DefaultSwitchThreadCallback` | — | High |
| `auto_03_801E0C7C_text` | 0x801E0C7C | 0x48 | 2 | 2 | — | — | — | — | None |
| `auto_03_801E1070_text` | 0x801E1070 | 0x82c | 19 | 7 / 0x3b0 | `src/PowerPC_EABI_Support/Runtime/Src/runtime.c` | 0x80328E10–0x803291C0 | `__cvt_fp2unsigned` | — | Low |
| `auto_03_801E1910_text` | 0x801E1910 | 0xf2b4 | 305 | 14 / 0xa80 | `src/OdemuExi2/DebuggerDriver.c` | 0x80337BE0–0x80338660 | `DBClose` | — | Medium |


## Next steps for the integrator (not done here)

1. Place a TWW GZLE01 `main.dol` in `tww-clone/orig/GZLE01/sys/` (not in the repo, not distributed) and run the TWW build's dtk path to get byte-level function comparison.
2. Byte-test rows 1–9 first: each candidate is a single TU with its span; compare NT's chunk bytes to TWW's span bytes after relocation masking.
3. Treat all `d_a_npc_fa1`/`J3DMaterialFactory` rows as needing per-function byte evidence before any naming.
4. Do not land any NT names from this table without byte confirmation; this file is a worklist only.
