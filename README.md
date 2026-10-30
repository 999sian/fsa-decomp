# The Legend of Zelda: Four Swords Adventures

[![Build Status](https://github.com/999sian/fsa-decomp/actions/workflows/build.yml/badge.svg)](https://github.com/999sian/fsa-decomp/actions/workflows/build.yml)
[![Matched Code](https://img.shields.io/badge/Code-59.03%25-green.svg)](https://github.com/999sian/fsa-decomp)
[![Matched Functions](https://img.shields.io/badge/Functions-88.13%25-green.svg)](https://github.com/999sian/fsa-decomp)
[![Linked Objects](https://img.shields.io/badge/Linked_Files-455%20%2F%201007-blue.svg)](https://github.com/999sian/fsa-decomp)
[![Navi Trackers](https://img.shields.io/badge/Navi_Trackers-15.47%25-orange.svg)](https://github.com/999sian/fsa-decomp)

A matching decompilation of **The Legend of Zelda: Four Swords Adventures** (GameCube), targeting **G4SE01 — USA, Rev 0**. The repository also covers the Japan-only **Navi Trackers** executable — later known as **Tetra's Trackers** — as a separate target.

The goal of this project is to produce readable, idiomatic C/C++ source code that compiles with the original Metrowerks compiler and links to binaries that are **byte-for-byte identical** to the retail releases.

> **Note**: This repository contains **no copyrighted game assets or retail binaries**. An existing, legally acquired copy of the game is required to extract original files and build the target executable.

---

## Target Releases

| ID | Region | Disc SHA-1 | `main.dol` SHA-1 | Status |
| :--- | :--- | :--- | :--- | :--- |
| **G4SE01** | USA (Rev 0) | `4bd926835dfbeaae72d01abe5fb581b527154a30` | `d86b3d9f785566e34264035e140ef3daf3cc19f0` | **Primary Target** (59.03% code matched) |
| **G4SJ01** | Japan | `520d86a7b82c45aaa26cb6dd29300ccfb671cd95` | `56097356bceafde9a64abeab8501b909746ac03c` | **Supported** (44.96% code matched, retail verified) |
| **G4SP01** | Europe | `e9842565f6f39a321f28f56e621a0b6de58bc960` | `66dbc77f258a64d8bc8d7b0041c619ed70d0c00b` | **Supported** (40.68% code matched, retail verified) |

### Navi Trackers / Tetra's Trackers (JP)

The Japanese disc ships a second executable, `files/DOL/framework.dol` — **Navi Trackers**, the mode later localised as **Tetra's Trackers**. It is not an FSA regional `main.dol`: it has its own configuration, symbols, splits and progress, and is built as the separate **`G4SJ01_NT`** target.

| ID | Executable | `framework.dol` SHA-1 | Status |
| :--- | :--- | :--- | :--- |
| **G4SJ01_NT** | `files/DOL/framework.dol` | `ab5f67bcf0687923d8dc1caf5afeb3bb9fe69011` | **In progress** (15.47% code matched, 4,178 / 8,121 functions) |

```sh
python3 configure.py --version G4SJ01_NT
ninja -j3
sha1sum -c config/G4SJ01_NT/build.sha1
```

See [`docs/versions/README.md`](docs/versions/README.md#navi-trackers-g4sj01_nt) for details.

---

## Progress Tracker

Current FSA progress is automatically tracked against compiler-verified metadata from `main.dol` (Navi Trackers is tracked separately with `tools/progress.py --version G4SJ01_NT`):

<!-- PROGRESS_START -->
| Category | Matched Code | Matched Functions | Linked Files | Progress |
| :--- | :--- | :--- | :--- | :--- |
| **Overall** | **59.03%** (2,622,048 / 4,442,032 B) | **88.13%** (10,186 / 11,558 fns) | **455 / 1007** | `█████████░░░░░░` |
| **Game Code** | **50.26%** (1,794,716 / 3,570,768 B) | **80.85%** (5,477 / 6,774 fns) | **105 / 610** | `████████░░░░░░░` |
| **SDK Code** | **99.94%** (237,244 / 237,392 B) | **99.91%** (1,065 / 1,066 fns) | **174 / 179** | `███████████████` |
| **JSystem Code** | **93.09%** (590,088 / 633,868 B) | **98.04%** (3,644 / 3,717 fns) | **176 / 218** | `██████████████░` |

*Fuzzy code matching stands at **89.93%** (includes near-matches).*
<!-- PROGRESS_END -->

### Navi Trackers (`G4SJ01_NT`)

| Metric | Progress | Count |
| :--- | :--- | :--- |
| **Matched Code** | **15.47%** | 312,136 / 2,018,048 B |
| **Matched Functions** | **51.45%** | 4,178 / 8,121 fns |
| **Fuzzy Code** | **17.97%** | includes near-matches |

*NT figures are measured by decompdecomp from the Japanese `framework.dol`; use `python3 tools/progress.py --version G4SJ01_NT` after a build.*

---

## Building

### Prerequisites

- **Python 3.10+**: Generator and configuration scripts
- **Ninja**: Build execution system (`ninja-build` or via `pip install ninja`)
- On Linux, [wibo](https://github.com/decompals/wibo) is automatically downloaded to run original Metrowerks 32-bit executables.

### Quickstart

1. **Clone the repository**:
   ```sh
   git clone https://github.com/999sian/fsa-decomp.git
   cd fsa-decomp
   ```

2. **Provide your original game disc**:
   Place an ISO, RVZ, or GCM of the USA retail release into `orig/G4SE01/`:
   ```sh
   mkdir -p orig/G4SE01
   cp /path/to/FourSwordsAdventures.iso orig/G4SE01/
   ```

3. **Configure the project**:
   ```sh
   python3 configure.py
   ```

4. **Build and verify**:
   ```sh
   ninja
   ```
   A successful build will link the executable and conclude with:
   ```text
   build/G4SE01/main.dol: OK
   ```
### Multi-Version Builds

All three retail releases configure and build cleanly to verified retail executables:

- **USA (`G4SE01`)**: `python3 configure.py --version G4SE01 && ninja` (default, links compiled C++ source files)
- **Japan (`G4SJ01`)**: `python3 configure.py --version G4SJ01 && ninja` (links assembly baseline slices)
- **Europe (`G4SP01`)**: `python3 configure.py --version G4SP01 && ninja` (links assembly baseline slices)

Each version expects its retail game disc in `orig/<VERSION>/` (e.g. `orig/G4SJ01/` or `orig/G4SP01/`).
All versions link to byte-identical retail executables (`build/<VERSION>/main.dol: OK`).

*Cross-version function correspondence and source split propagation are actively developed by the `versions` workflow (see [`docs/versions/README.md`](docs/versions/README.md)).*
---

## Diffing with objdiff

This project supports interactive diffing via [encounter/objdiff](https://github.com/encounter/objdiff):

1. Download the latest release of `objdiff` from [GitHub Releases](https://github.com/encounter/objdiff/releases).
2. Set the project directory in `objdiff` to the repository root. It will automatically load `objdiff.json`.
3. Select an object from the sidebar to inspect matched and unmatched functions with real-time rebuild on file save.

---

## Credits & Attributions

This decompilation stands on the shoulders of the wider GameCube and Zelda reverse engineering community.

### Donor Projects (Imported Source Code)

We gratefully acknowledge source code, structures, and headers adapted from the following donor projects:

- **[Mario Kart: Double Dash!! Decompilation](https://github.com/doldecomp/mkdd)** (`doldecomp/mkdd`):
  Base JSystem framework sources (`JKernel`, `JSupport`, `JUtility`), headers, and MSL C runtime.
- **[The Wind Waker Decompilation](https://github.com/zeldaret/tww)** (`zeldaret/tww`):
  GBA subsystem (`GBAJoyBoot`), JMessage processor structures, and Zelda framework architecture.
- **[Twilight Princess Decompilation](https://github.com/zeldaret/tp)** (`zeldaret/tp`):
  JAudio2 interface definitions, JParticle layout, J2DGraph (`J2DWindow`, `J2DPicture`), and J3D animator components.
- **[Pikmin 2 Decompilation](https://github.com/projectPiki/pikmin2)** (`projectPiki/pikmin2`):
  J3D (`GraphBase`, `GraphLoader`, `GraphAnimator`), Dolphin SDK / MSL runtime implementations.
- **[Dolphin SDK 2004](https://github.com/doldecomp/dolsdk2004)** (`doldecomp/dolsdk2004`):
  SDK function identification and GX/vec implementations.
- **[Animal Crossing Decompilation](https://github.com/ACreTeam/ac-decomp)** (`ACreTeam/ac-decomp`):
  GBA joybus communications (`GBAKey.c`, `GBAGetProcessStatus`).
- **[EverydaySimpleDev / FSA-Decomp](https://github.com/EverydaySimpleDev/FSA-Decomp)**:
  Initial actor research and game code exploration (reused under CC0 with permission).

*Canonical file-level attributions for all imported source code are tracked in [`NOTICE`](NOTICE).*

### Community Research & Tooling

- **[Zelda-FSA-Modding](https://github.com/Venomalia/Zelda-FSA-Modding)** (Venomalia et al.):
  Pioneering reverse engineering research on Four Swords Adventures, including `main.dol` string dumps, disc formats, file layouts, and `framework.dol` documentation (see [`docs/community_notes.md`](docs/community_notes.md)).
- **[decomp-toolkit (dtk)](https://github.com/encounter/decomp-toolkit)** & **[dtk-template](https://github.com/encounter/dtk-template)**:
  Build generator, DOL analysis, slicing tools, and CI framework by encounter.
- **[wibo](https://github.com/decompals/wibo)**:
  Lightweight Win32 wrapper for running Metrowerks compilers seamlessly on Linux.
