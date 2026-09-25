# FSA (G4SE01) main.dol game map

Built only from `build/G4SE01/main.dol` (byte-identical retail), the dtk asm in `build/G4SE01/asm/`, `config/G4SE01/symbols.txt`, and the Ghidra MCP (for spot checks). Nothing in the repo was modified.

Machine-readable outputs in this directory:

| file | contents |
|---|---|
| `tu_boundaries.csv` | 572 rows: 37 library ranges (JAudio2/SDK/MSL/TRK/Runtime/JSystem) plus 535 inferred game TUs (start, end, size, #funcs, actor IDs, evidence, sample strings) |
| `actors.csv` | 355 factory entries: 4CC ID, alloc size, ctor, parent ctor, vtable, overridden vslots, method range, owning TU |
| `strings_by_addr.tsv` | every NUL-terminated string in the data sections (9821) with the functions that reference it |
| `strings_useful.tsv` | 4657 of those filtered to readable text, tagged format / source_file / asset_path / sdk_version / other |
| `first_targets.csv` | the 30 recommended first targets (section 4) |
| `work/*.py`, `work/*.pkl` | the scripts that produce all of the above (`load.py` parses the asm, `factory.py` gives actor IDs, `bound.py` + `tus.py` give TU boundaries, `out.py` writes the CSVs) |

**How string→function attribution works.** MWCC loads a TU's string pool through one base register (`addi r31, r3, lbl_804652F0@l`, then `addi r3, r31, 0x324`). `work/baserefs.py` follows these base+offset uses within a function, so most attributions are exact. When a string has no exact use, the tool falls back to the function that loads the containing dtk label. That fallback is right at TU level but can be wrong per function. Use Ghidra `xrefs` to confirm a specific one.

---

## 1. `.text` address-range map

DOL sections: `.init` 0x80003100–0x80005600, extab 0x80005600–0x80011860, extabindex 0x80011860–0x80021840, `.text` 0x80021840–0x8045BD00, `.ctors` 0x8045BD00 (587 entries), `.dtors` 0x8045C640, `.rodata` 0x8045C660, `.data` 0x804916A0, `.bss` 0x804B2140, `.sdata` 0x80539BC0, `.sbss` 0x8053A280, `.sdata2` 0x8053AFA0, `.sbss2` 0x80543F00. `_SDA_BASE_` (r13) is 0x80541BC0, and `sManager__8JUTVideo` is r13-0x7240.

The link order is **JAudio2 → Dolphin SDK → TRK → Runtime → MSL → SDK stubs/EXI/SI/GBA → JSystem → game**. This differs from both TWW and MKDD: here JAudio sits at the very start of `.text`.

| range | subsystem | evidence |
|---|---|---|
| 80003100–80003458 | `.init`: `__start.c` | named `__start`, `__init_registers`, `__init_data`, `__init_hardware`, `__flush_cache` |
| 80003458–8000540C | `.init`: TRK `__exception.s` | `gTRKInterruptVectorTable`..`End` |
| 8000540C–80005600 | `.init`: Runtime `__mem.c` + `_rom_copy_info` / `_bss_init_info` | named |
| **80021840–800276F0** | **JAudio2 JAI (Interface)** | "cannot new Se %08x." @80023750 (JAISeMgr.cpp), "It cost %d steps to prepare Sound" @8002585C (JAISound.cpp). 13 `__sinit`. First function 80021840 is a 2-instr `return 0` (the region-code getter called by the game) |
| **800276F0–80039B80** | **JAudio2 JAS (System)** | "SFR-UPDATE / DSP-MAIN / MONO-MIX / UPDATE-DAC" @80029A94–8002A958 (JASAiCtrl.cpp), "/AudioRes/Waves/" @80030EF8 (JASWaveArcLoader.cpp), "JASTrack (%8x) dump" @80034CAC (JASSeqParser.cpp). `fn_80028974` = `JASGenericMemPool::JASGenericMemPool()` |
| 80039B80–8003A500 | JAudio2 Task (C: dspproc/dsptask/osdsp/osdsp_task) | 32-byte padded C functions, "Already inited prior DSP task" @8003A0A0 |
| 8003A500–8003F610 | JAudio2 JAU (Utility) | `bitset::set/test/reset` range asserts @8003DDA4.. (JAUSectionHeap.cpp). 11 `__sinit` |
| 8003F610–8003F810 | SDK base (PPCArch) + db | named |
| 8003F810–80046804 | SDK os | `OSInit` references "<< Dolphin SDK - OS release build: Jul 23 2003 >>" |
| 80046804–80046898 | Runtime `__ppc_eabi_init` | `__init_user`, `_ExitProcess` |
| 80046898–80047258 | SDK mtx / vec (paired-single) | ps-heavy, unnamed |
| 80047258–8004B7DC | SDK dvd (+fstload) | "dvdfs.c" / "dvd.c", DVD version string @800489B4 |
| 8004B7DC–8004D4A0 | SDK vi | VI version @8004BD78 |
| 8004D4A0–8004F8C0 | SDK pad | PAD version @8004E5D4 |
| 8004F8C0–80051AE8 | SDK ai, ar, arq | version strings @8004F908, 8004FFB0, 80051AE8 |
| 80051AE8–80052200 | SDK dsp | DSP version @80051D40 |
| 80052200–80058ABC | SDK card | CARD version @80053128 |
| 80058ABC–80060B88 | SDK gx | `GXInit` @80058ABC |
| 80060B88–80066DE0 | TRK_MINNOW_DOLPHIN | named `TRK*`, `udp_cc`, `ddh_cc`, `gdev_cc`, `MWTRACE` |
| 80066DE0–80067AF4 | Runtime (PowerPC_EABI_Support) | `__va_arg`, `__destroy_global_chain`, `__save_fpr`, `__div2u`, `__init_cpp_exceptions` |
| 80067AF4–80070608 | MSL_C | "GCN_Mem_Alloc.c" @80067AF4, `exit`, `printf` family, `strlen`, math |
| 80070608–80071204 | SDK amcstubs / odenotstub / OdemuExi2 | `AMC_IsStub`, `Hu_IsStub` |
| 80071204–80073C20 | SDK exi | EXI version @80072E5C |
| 80073C20–80075580 | SDK si | SI version @800744B8 |
| 80075580–80077124 | SDK gba (GBA.c … GBAKey.c) | "GBAKey.c", "// Coded by Kawasedo" |
| 80077124–800790A8 | JSystem JMessage (maybe JGadget too) | 4CC `MESG`/`MGCL` @800773AC, `DAT1`/`STR1` @80077538 |
| 800790A8–80086E2C | JSystem JKernel | JKR*.cpp names in panic strings; earlier objdiff matched MKDD `JKRCompArchive`, `JKRDisposer`, `JKRDvd*`, `JKRFileLoader` 100% (`scratchpad/find.txt`) |
| 80086E2C–8008770C | JSystem JSupport | `JSUPtrList`/`JSUPtrLink` named, JSUMemoryStream @8008735C and JSUFileStream @800874D0 matched |
| 8008770C–80093600 | JSystem JUtility | JUTException strings @8008A324–8008C608, "JUTResFont" @80091204. JUTFont/NameTab/Palette/Resource/Texture/Video matched |
| 80093600–800AF584 | JSystem J2DGraph | 4CC `PIC1`/`TBX1`/`PAC3` (J2DScreen/Picture/TextBox), `PAF1`/`TPT1`/`VAF1`/`VCF1` @800A5ACC (J2DAnmLoader), `TV16`..`TVB1` @800AE16C (J2D material/TEV blocks) |
| 800AF584–800CC000 | JSystem J3DGraphBase + J3DGraphAnimator | GX-heavy, `J3DErrType` strings in rodata @804632EC. The start is approximate |
| 800CC000–800E3F1C | JSystem J3DGraphLoader | `DRT1 DRW1 EVP1 SHP1 TEX1 VTX1` @800CC2E8 / 800E2B80 (J3DModelLoader + CalcSize), `PAF1..` @800CF3E8 (J3DAnmLoader), `PEFG`/`TGB4`/`PEED`/`TVPT` @800DD148–800DF454 (J3DMaterialFactory) |
| 800E3F1C–800E413C | JSystem JMath | paired-single |
| 800E413C–800E6540 | JSystem JFramework (JFWSystem, JFWDisplay) | calls `OSInit`/`DVDInit`; "GP hang due to XF stall bug" @800E633C = JFWDisplay.cpp |
| 800E6540–800F37A8 | JSystem JParticle | ps-heavy; `BSP1 ESP1 ETX1 SSA1 SSP1 TDB1` @800F3398 (JPAResourceLoader) |
| **800F37A8–8045BCE4** | **Game code (FSA)** | 6778 functions, 527 `__sinit`, `main` @801344C0 |

JSystem sub-ranges up to JKernel/JSupport/JUtility are firm. The J2D/J3D split point (~800AF584) and the JMessage/JGadget split are approximate. The JSystem order (JMessage, JKernel, JSupport, JUtility, J2D, J3D, JMath, JFramework, JParticle) does not match MKDD's linker order.

**Does FSA use the TWW framework?** No. The DOL contains no `fopAc`, `fpc`, `f_pc`, `mDo*`, `dStage`, `dBgS`, `cM3d`, `c_xyz` or DynamicLink strings. It has no process-profile table and no `.rel` modules. RTTI is off, so there are no class names at all. What FSA has is JSystem (JKR/JUT/J2D/J3D/JPA/JFW/JMessage/JAudio2) under its own game engine:

- 4-char IDs.
- An `Actor` base class with a single vtable.
- One `switch(id)` factory.
- Singleton managers reached through r13.

The string "/DOL/framework.dol" exists (@80477898, in the pool of the TU around 803DD764). It is a stray debug path, not TWW's Framework. TWW is still useful for JSystem headers and idioms, but not for the game layer.

---

## 2. Game code structure

### 2.1 main loop (`main` @801344C0)

`main` does the following, in order:

1. Copies and checks the reset/boot-info block at 0x80700000 into `lbl_80529DEC`.
2. Calls `OSGetResetCode`.
3. Calls `fn_800E49E0` (JFWSystem-style init in the JFramework range; it `new`s three JSystem singletons at `lbl_8053AA30`/`34`/`38`, with ctors `800855CC`, `800891B8` and `80090DF0`).
4. Initializes 4× `fn_8008CF54` (JUTGamePad).
5. Calls `fn_800E4DAC` / `fn_800E5FC4` (JFWDisplay create).
6. Calls `fn_803BA980(&lbl_8051C1A0)` (a game-side object that is polled every frame by `fn_803B9E2C`; probably input or controller-port handling, not verified).
7. Creates the heaps (`fn_80084BAC`, `fn_800814D4`) and a 0x90 system object `fn_8045A080`, which is the r13-0x6C40 singleton and has 256 users.
8. Calls `fn_80401FEC` (thread/DVD loader).
9. Creates the boot object: `new(0x7C) fn_804009CC`, r13-0x70D0. It loads "/GC4Sword_usa/agb/client_thread.arc", `MESGbmg1`, "Reading the Game Disc...", and the disc-cover messages. Its methods are `fn_803FF420` / `fn_803FFAA8` (logo.arc, "ZelPac_NIN_logo.blo", progressive_choice).

The endless loop then runs:

- `fn_803B9E2C(pad)`, `DVDGetDriveStatus`, GBA/SI polling (`fn_802B1D60..DCC`), `fn_80401518`.
- While the boot phase is below 4: `display->beginRender` (vfunc +8), then boot calc and draw, then `endRender` (+0x10).
- When the boot phase finishes, it creates **the Game object**: `new(0x11C) fn_80139300`. That is vtable 8049EF20 and singleton **r13-0x70C8 = `lbl_8053AAF8`**, referenced by 966 functions. `fn_80138C9C` initializes it.
- From then on, every frame runs `display+8` → `fn_80136828(game)` (calc) → `display+0xC` → `fn_80137300(game)` (draw) → `display+0x10`.

`fn_80139300` (the Game ctor) creates the managers:

- `fn_8038DA00` (0x158): message/text, r13-0x6E48.
- `fn_8013BFEC` (0x3C): render/camera manager, r13-0x70B0, 569 users.
- `fn_802ACBE8` (0x1C).
- `fn_803DA8FC` (0x24): title "pressstart.blo".
- `fn_8044243C` (0x28).
- `fn_80440FDC` (0x14): r13-0x6CE8.
- `fn_80431D84` (0xF0): r13-0x6D00.
- `fn_803A59E0` (0x158).
- 2× `fn_80097800`: J2DPicture from `'TIMG' "kk_rival_01.bti"`.
- 4× `fn_8009E648`: J2DTextBox with "rock_24_20_4i_{j,e}.bfn".

It then registers the exception map "GC4Swords.MAP" (`fn_8008C494`) and the exception callback `fn_80134C04`.

### 2.2 Scene system (the Game object, TU 801344C0–8013F9A8)

The scene/mode system lives inside the Game object. The current scene is at `game+0x4C` and the next scene is passed to `fn_80135A04`, a scene-change loader driven by jumptable 8049EF94. Each case frees the other scenes' archives (`fn_801352F4(game, n)`), loads the arc for the new scene, and prints a heap report:

| scene id | name (heap-report string) | archive(s) loaded in 80135A04 | per-frame handler in `fn_80136828` |
|---|---|---|---|
| 1 | Title | – | `fn_8013B4F8` + `fn_803A44D8` |
| 2, 5 | ModeSelect | /GC4Sword(_usa)/gamemode.arc | `fn_803DF624` (2), `fn_803A71F0` (5) |
| 3 | FileSelect | file.arc | `fn_803CEED4` (TU with the "%02d.%02d.%04d %02d:%02d:%02d" save-date format) |
| 4 | Menu | entry.arc | `fn_803A8664` |
| 6 | MapSelect | map1.arc / map2.arc | `fn_8039013C` |
| 7 (8) | Game (+ Result) | Boss/bossNNN.arc, boss500.arc, game2D.arc | `fn_80139D3C` / `CC4` / `C84` / `C5C` + `fn_8043D39C` / `fn_8043DB58` / `fn_803DA6B4` |

`fn_8013A538` prints "Expヒープ%fKの確保失敗…" and "領域確保成功" (heap alloc fail/success). `fn_804122F4` prints "***** heap check …".

### 2.3 Actor system

- **Factory: `fn_801F9484`** (0x801F9484–0x801FF630, the largest function in the game). It is a binary-search `switch` on a 4CC ID (`lis/addi` + `cmpw r29`). Each case runs `new(size)` via `fn_8008440C` (`operator new(size, heap, align)`) → `XXXX::XXXX()` and stores the result into a 0x400-slot table at `mgr+8+i*4`. It has **355 cases**. 350 have a ctor. DMCS, FGAM, ZNLE, ZNLG and ZNLI have no ctor (unused IDs). Full list in `actors.csv`.
- **Factory TU 801F9484–80204638** (322 functions) holds the factory plus almost every actor constructor, because the ctors are inline and emitted where they are used. Example: `fn_80200CD4` = OKAM ctor, which calls `fn_801F5AE0` (Actor ctor) and stores vtable 804A3448.
- **Base class `Actor`**: ctor `fn_801F5AE0`, base vtable `lbl_804A5770`. The vtable is `{0,0}` followed by the entries. Most concrete actors have 19 slots:
  - slot 0 = dtor
  - slot 1 = setParams / init (unique per actor)
  - slot 3 = update / calc
  - slot 6 = draw
  - slots 2, 4, 5, 7–18 = shared defaults: `fn_801F5790`, `801F4F28`, `801F4E0C`, `801F4850`, … `801F15BC`, `801F165C`
  
  The base TU is 801EE24C–801F6058. It holds base methods 801F4704–801F5AE0 and the "SWBMFIREBLZEHBMBFLME…" drop/hit-type ID table, and ends with `__sinit` 801F5E34. It is followed by the EnemyParam.csv loader TU 801F6058–801F9484 (`fn_801F62AC`).
- **Intermediate bases** (parent ctor ≠ 801F5AE0):

  | parent ctor | actors |
  |---|---|
  | 801D0F40 | 31 actors (e.g. FSPO/FSOB item-like) |
  | 8010E074 | 10 actors: the DMxx demo/cutscene family DMZL, DMMD, DMGF, DMSW, DMGL, DMLK, DMGA, DMNR, SPFR, … |
  | 801247C8 | EZZR, OPGL |
  | 801D30B8 | ARSH, ZNSH, FBAL |
  | 80207AC0, 80210AB4, 801D1974, 802218C8 | 2 each |
  | 801BB3B0 | LTZR |

- **Where actor code is.** The link order of actor TUs follows vtable order in `.data`, with 0 inversions across 350 actors. That makes vtable address a reliable way to order and bound TUs. Actor code spans 800F3C10 (NZMI) to 804432DC (DTLK). 348 of the 535 inferred game TUs contain exactly one actor, e.g. OKAM TU 801AE7A0.., YASI 802DF458.., STGN 802F4820–802F4AEC. The only multi-actor TUs are IWAG+OIWA, BWRT+WRTC and CLOD+ARSH+ZNSH.
- **Per-TU boilerplate.** 482 game TUs end in an identical 137-instruction `__sinit` that initializes the header-static `JASPoolAllocObject<...>::memPool_` guard objects (`JASGenericMemPool` ctor `fn_80028974`, dtors `fn_80021AC0`..`fn_80021D0C`, guard bytes `lbl_8053A2AC`..B4). The game includes a JAudio2 header everywhere, so once that header is right the `__sinit` matches in every TU.

### 2.4 Managers and singletons (r13-relative, by number of functions using them)

| global | r13 off | users | created by | likely role |
|---|---|---|---|---|
| lbl_8053AAF8 | -0x70C8 | 966 | `main` → `fn_80139300` | Game / scene manager |
| lbl_8053AB10 | -0x70B0 | 569 | `fn_8013BFEC` | render/camera/2D-overlay manager ("kk_black.bti") |
| lbl_8053AC90 | -0x6F30 | 363 | `fn_8023F7F8` / `F8B0` | player manager (`fn_8023E724`: players[0..3]) |
| lbl_8053AF80 | -0x6C40 | 256 | `fn_8045A080` (from `main`) | system/audio manager (last game region, "JaiInit.baa" nearby) |
| lbl_8053AD30 | -0x6E90 | 149 | `fn_8030ABFC` | BG / map manager ("bg_%s_sch.szs", `fn_8030C210` area test) |
| lbl_8053AC98 | -0x6F28 | 112 | `fn_802A3DA4` | ? (near the HOUS/THCL/BHRT TUs) |
| lbl_8053AED0 | -0x6CF0 | 104 | `fn_8043EED8` | ? (used by the Game draw path, `fn_8043D39C`) |
| lbl_8053AD78 | -0x6E48 | 91 | `fn_8038DA00` | message manager (gc_four_swords_text_e.bmg, "rock_24_20_4i_e.bfn") |
| lbl_8053AAF0 | -0x70D0 | – | `main` → `fn_804009CC` | boot / disc-check / logo |
| lbl_8053AA48 | -0x7178 | – | JFW | JFWDisplay |

### 2.5 Large non-actor game regions (these are engine/systems, see `tu_boundaries.csv`)

| range | contents |
|---|---|
| 801344C0–8013F9A8 | main + Game + scene loader + render manager (`fn_8013BFEC`) |
| 801C5B08–801D46FC, 801D8400–801EBC84 (gaps) | effect/particle helpers, item bases (801D0F40) |
| 801ED3DC–80204D44 | Actor base, EnemyParam, factory |
| 8022AD64–80255F4C | 627 functions in 2 TUs: player / Link code. `fn_8023E724` player getter, 323 callers |
| 80256C74–80289648 | 374 functions: player/collision/camera systems ("player_sob.bin") |
| 802D39B8–802DF458 | map / stage loader ("map500.csv", "map500_ctrl.csv", "d_map%s_%d%d_mmm_2_%d.szs") |
| 802F5040–8030E9A0 | BG manager, GBA link ("client_thread.bin", "bg_%s_sch.szs") |
| 8037DF68–8038DE74 | font / message ("rock_24_20_4i_e.bfn", ".bmg") |
| 803944C8–803B8970 | 2D UI (hukidashi*.blo, op_zelda.blo, option.blo) |
| 803B8C74–803D6434 | save / file select ("Four Swords Adventures", "%d/%d Save Data", Tf1fir..) |
| 803DA6B4–80437C10 | title / menus / map-select / result / heap-check UI (P* texture-name tables) |
| 80438C68–80442C64 | gameover.blo, GBA connect error, "/GC4Sword_usa/AudioRes/JaiInit.baa" |
| 804432DC–8045BCE4 | map editor / yagura / sound-system glue (`fn_8045A080`) |

---

## 3. Strings useful for naming

There are only 17 source-file strings. Assertion/panic sites (`OSPanic(file, line, msg)`) are:

| string | referencing function | meaning |
|---|---|---|
| `RailBase.cpp`, "RailBase: Buffsize Error\n" | `fn_800FD894` | the only game `.cpp` name. RAIL actor TU 800FD438–800FD4C0, and the rail-base TU follows (OSPanic line 0x1A3) |
| `JKRAram.cpp`, `JKRAramArchive.cpp`, `JKRAramPiece.cpp`, `JKRAramStream.cpp`, `JKRCompArchive.cpp`, `JKRDvdFile.cpp`, `JKRDvdArchive.cpp`, `JKRDvdRipper.cpp`, `JKRExpHeap.cpp`, `JKRHeap.cpp`, `JKRMemArchive.cpp`, `JUTPalette.cpp` | 80079358 … 8008EB34 | JSystem TU identity |
| `GBAKey.c`, `dvdfs.c`, `dvd.c`, `vi.c`, `GCN_Mem_Alloc.c` | SDK / MSL | – |

Debug formats (game):

| function | string(s) |
|---|---|
| `fn_80135A04` | "Game / Result / Title / ModeSelect / FileSelect / Menu / MapSelect　連続空き容量 %fK 残り空き容量 %fK" |
| `fn_8013A538` | "Expヒープ%fKの確保失敗…", "領域確保成功" |
| `fn_804122F4` | "***** heap check … *****" |
| `fn_803865B8` | "====>%d, %d" |
| `fn_803B6FD8` | "Tmmt01===>%d" |
| `fn_803BBF08` | "%d/%d Save Data", "Four Swords Adventures" |
| `fn_803CE4CC` | "%02d.%02d.%04d %02d:%02d:%02d" |
| `fn_80382B48`, 8039A638.., 8042EF9C | "CR[%d]" |

Asset names map strongly to actors and systems (1828 asset paths; `grep asset_path strings_useful.tsv`):

| example | string(s) | TU / actor |
|---|---|---|
| bosses | "wart_eye*.bti", "wart_child*.bti" | WRTC/BWRT TU 800F7FCC |
| rocks | "hahen_*.bti" | NZMI TU 800F3C10 |
| breakables | "gareki.bti", "kowareyuka_*.bti" | 80103348 (TWEV) |
| sky | "bg_tenkuu.bti" | 801045D8 (SIBT) |
| HOUS | "house*_smp.bin" | 802957CC |
| crystals | "suisyo_%d.bmd/.btk/.brk" | 801902C0 |
| enemy params | "EnemyParam.csv" | 801F62AC |
| player objects | "gb_ch_obj_base_sch.szs", "player_sch.szs" | 803DD764 / 803A8884 / 8039027C |

The "enemy_gc_sob.bin" / "enemy_both(2)_sob.bin" strings appear in almost every actor TU. They are per-TU copies (each actor's shadow/effect resource name), and each one marks the start of an actor's rodata.

In-code 4CC tables name the actors that interact with each other, e.g.

- "SWBMFIREBLZEHBMBFLMETHCLGRASSSTNSTONROCKRCK2BORDTUBOKEY0YASISMRINULL" @80465D78: what a sword or bomb can hit.
- "PEACOKTAAMOSBZBR…" @80464204.
- "TUBOKEY0YASI…".

Full list: `strings_by_addr.tsv` (all) and `strings_useful.tsv` (filtered, categorized).

---

## 4. Recommended decompilation order

1. **Infrastructure first (it unlocks many TUs at once):**
   - JAudio2 `JASGenericMemPool` and `JASPoolAllocObject<T>::memPool_`. This fixes the 137-instruction `__sinit` in 482 game TUs. MKDD `libs/JSystem/JAudio/System/JASHeapCtrl.cpp` and the `JASPoolAllocObject` headers are the reference.
   - The `Actor` base header: ctor `801F5AE0`, 19-slot vtable `804A5770`, size about 0x230. The FSA repo's `include/Game/Actor.h` is a usable field-default hint, not a verified layout.
2. **Trivial actor TUs.** 15 TUs contain only a dtor (24 instrs: `this->vt=…; Actor::~Actor(); if (flag>0) delete`), `blr` virtuals and the shared `__sinit`. They establish the per-actor TU template and each gives a quick 100% TU.
3. **Actor ctors in the factory TU.** About 300 functions of about 15 instructions, one pattern. They carry each actor's vtable symbol and class size (the `li r3, size` in the factory).
4. **Small helpers with many callers** (player getters, chase-float, resource getters, 2D setters). Naming these propagates meaning into hundreds of callers.
5. **Small real actors**, ordered by `method_hi - method_lo` in `actors.csv`: DWAP, RAIL, BOTS, DBMS, IFCK, ICOB, OGST, then 4–6-function actors such as DEAL, WIND, LOSW and SIBT. Next come intermediate bases (801D0F40 with 31 children, 8010E074 DM* demo family) before their children.
6. **Last:** the Game object and managers, then the big systems (player 8022AD64–80289648, BG/map, UI).

### 30 first targets (`first_targets.csv`)

**Whole actor TUs** (start–end, bytes). Each is a dtor, one-instruction virtuals and the shared `__sinit`:

| # | actor | range | bytes |
|---|---|---|---|
| 1 | BOTS | 800FEDD0–800FF060 | 0x290 |
| 2 | TJIJ | 80372EA8–80373138 | 0x290 |
| 3 | GFBS | 8012679C–80126A4C | 0x2B0 |
| 4 | DWAP | 8010307C–80103348 | 0x2CC |
| 5 | STGN | 802F4820–802F4AEC | 0x2CC |
| 6 | BGWC | 802BA048–802BA334 | 0x2EC |
| 7 | URAC | 802E07C8–802E0AB4 | 0x2EC |
| 8 | ELNK | 8035E8CC–8035E9A0 | 0xD4 (no `__sinit` seen; boundary uncertain) |
| 9 | TMI2 | 80376850–80376B4C | 0x2FC |
| 10 | TLK2 | 803B8970–803B8C74 | 0x304 |
| 11 | LCLS | 802E8DFC–802E910C | 0x310 |
| 12 | SEN2 | 802E7634–802E794C | 0x318 |
| 13 | GLBS | 802E910C–802E9428 | 0x31C |
| 14 | ICOB | 8012F8AC–8012FBCC | 0x320 |
| 15 | PLAS | 802AC58C–802AC8AC | 0x320 |

**Functions:**

| # | function | size | notes |
|---|---|---|---|
| 16 | `fn_80028974` | 0x18 | `JASGenericMemPool` ctor (MKDD source) |
| 17 | `fn_80200CD4` | 0x3C | OKAM ctor (template for about 300 actor ctors) |
| 18 | `fn_801F4704` | 0x4 | Actor empty virtual |
| 19 | `fn_801F4710` | 0xC | Actor virtual |
| 20 | `fn_801F577C` | 0x14 | Actor virtual |
| 21 | `fn_801F71A4` | 0x44 | chase-float, 92 callers |
| 22 | `fn_8023E724` | 0x8C | player getter, 323 callers |
| 23 | `fn_8023DE58` | 0x84 | player accessor, 225 callers |
| 24 | `fn_8023F264` | 0x58 | player accessor, 114 callers |
| 25 | `fn_80402E08` | 0x68 | 2D set-pos, 117 callers |
| 26 | `fn_804030C4` | 0x40 | archive getResource('TIMG', name), 60 callers |
| 27 | `fn_804032E8` | 0x40 | sibling of 26 |
| 28 | `fn_8013B490` | 0x30 | 65 callers |
| 29 | `fn_80138A30` | 0x80 | Game method, 80 callers |
| 30 | `fn_8030C210` | 0x98 | BG area point test, 89 callers |

### Caveats

- TU boundaries are inferred. They come from:
  - `__sinit` ends (strong; 527 in game code).
  - Actor vtable ownership (strong).
  - A monotonic `.sdata2`/`.rodata` ordering check plus duplicate-float-constant detection (medium).
  
  Non-actor regions between two `__sinit`s may still contain several TUs, e.g. the 627-function 8022AD64 block. The 5 rows marked "no sdata2-consistent point" put the boundary at the next actor's first method.
- The slot semantics (1 = setParams, 3 = update, 6 = draw) follow the FSA repo's analysis and fit the patterns seen here (6 = draw uses the effect/GX helpers), but they are not proven.
- The EverydaySimpleDev repo's names (e.g. "Okam_PartNof7", "oscluster_*" in `src/Dolphin/os/`) are unreliable; its actor 4CCs do agree with the factory table here.

---
Generated by the scripts in `tools/gamemap/` (they expect intermediate pickles that
are not committed; rerun them from the build asm). Strings dumps (`strings_*.tsv`)
are not committed because they are raw game text.
