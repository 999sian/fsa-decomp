# Community research notes

Facts gathered from community sources that help with naming and understanding
FSA's code. Addresses are for **G4SE01 (USA)** unless marked otherwise.

## Sources

- **Zelda-FSA-Modding** (Venomalia et al.): https://github.com/Venomalia/Zelda-FSA-Modding
  - `Reverse engineering/main.dol_Strings.csv`: string dump of **our** `main.dol`
    (5,009 of 5,026 entries sit at the same address in G4SE01).
  - `Reverse engineering/framework.dol_Strings.csv` and `Map/framework.dol.map`: these
    are from **`framework.dol`, the Navi Trackers executable on the Japanese disc**, not
    FSA. It uses the Wind Waker-style framework (`m_Do_main.cpp`, `f_op_actor.cpp`,
    `f_pc_deletor.cpp`…). The map is a hand-made Ghidra export, not a linker map.
    FSA's `main.dol` does **not** use that framework (see `docs/gamemap/GAMEMAP.md`).
  - `FSA_Documentation.pdf`: disc layout, level list and file formats (summarised below).
  - Discord: "Four Swords Plus" (linked from the repo README).
- **The Cutting Room Floor**: https://tcrf.net/The_Legend_of_Zelda:_Four_Swords_Adventures
  and its `/Debug_Content`, `/Navi_Trackers`, `/Regional_Differences` sub-pages.

## Debug features (Action Replay RAM writes)

| Feature | JP | US | EU |
|---|---|---|---|
| Debug mode (two 32-bit flags = 1) | `805A18E0`, `805A1904` | `805AACE0`, `805AAD04` | `805C8380`, `805C83A4` |
| Stage select: patch `li r0,1` | `80339EF8` | `8040F564` | `80406AD0` |

- Debug mode also enables the crash debugger (JUTException-style screen).
- In the stage-select menu: L+Y to activate, Down to cycle levels.
- The two debug-mode flags are `.bss` globals: good candidates to name
  (e.g. `g_debugMode…`) once the code reading them is decompiled.
- The US stage-select patch site `0x8040F564` is inside the map/stage-select scene
  code (scene 6 in `fn_80135A04`).

## Debug and unused actors (4-character actor IDs)

| ID | What it is |
|---|---|
| `STGN` | "Stage情報NPC" (stage information NPC), debug actor |
| `DWAP` | debug warp; variables choose the destination on the map |
| `ANHO` | unused but working digging minigame |
| `BRBL` | unused small crate that can be pushed and burned |
| `DEAL` | unused but working (expensive) item shop |
| `DETH` | spawns Vaati, who chases and KOs the Links |
| `WPCN` | large cannon that warps you when fired |
| `TRAP` | purple spiny trap (unused behaviour: var3 = 1) |
| `FLYO` | red tile dropping 100 force gems (var1 = 128) |
| `SLR1` | soldier (var1 = 1 yellow; var4 = 6 large green knock-back soldier) |
| `BMTY` | bombchu (all vars 0 = carryable/throwable in boss000) |
| `CIRC` | moon gate (var1 = 1 variants) |
| `GFBS`, `TLWP`, `BTIN` | examples from the room actor lists |

`docs/gamemap/actors.csv` lists all 355 IDs handled by the actor factory
`fn_801F9484` with their constructor, vtable and TU range.

## Level data formats (from FSA_Documentation.pdf)

- **Room actor list `bin`**: 11-byte entries `AAAA B C D E F G H`, where `AAAA` is the
  actor ID, `B` layer, `C` X, `D` Y, and `E`–`H` four variables (the actor "vars").
  Ends with a marker sequence.
- **`map/mapNNN.csv`**: first line `name,startX,startY,bgmId,showE3Banner,tilesetId,?,overlayTexId,?,?`,
  then a 10×10 grid of room numbers (or `NULL`), then `end,,,,`.
- **`szs/*.szs` room layers**: 16 per room (8 areas × low `1_x` / high `2_x` layer);
  1,024 little-endian u16 tile entries as four 16×16 quadrants.
- Containers: Yaz0, RARC; J3D `bmd`/`btk`/`brk`; J2D `blo` (SCRNblo2); JParticle
  `jpc` (JPAC2-10); messages `bmg` (MESGbmg1) and `bmc`; fonts `bfn`; JAudio `aw`,
  DSP, THP video; GBA ROMs for the link-cable clients.

## Stage archive names (`files/GC4Sword_usa/Boss/bossNNN.arc`)

`boss0X0–0X3` are the eight worlds' stages (e.g. `boss010` = 1-1 Lake Hylia,
`boss011` = 1-2 Cave of No Return, `boss013` = 1-3 Hyrule Castle; `boss0X2` are cut levels).
Test/demo stages: `boss000–002` (Test-1.x), `boss004–006` (ECTS 2003), `boss007–009`
(E3 2003), `boss090–097` (boss tests), `boss992` (deleted E3-4, crashes).
Others: `boss100–116` credits scenes, `boss200–207` Tingle's Tower minigames,
`boss500` Shadow Battle, `boss990` opening, `boss991` credits.

## Navi Trackers (JP only)

The Japanese disc has a second executable, `framework.dol` (Navi Trackers / Tetra's
Trackers), built on a Wind Waker-style framework with its own resources under `tetora/`.
It is out of scope for the G4SE01 target, but it shares SDK/JSystem vintage with FSA
and could be added as a separate target later.
