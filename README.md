# The Legend of Zelda: Four Swords Adventures

[![Build Status](https://github.com/999sian/fsa-decomp/actions/workflows/build.yml/badge.svg)](https://github.com/999sian/fsa-decomp/actions/workflows/build.yml)
[![Matched Code](https://img.shields.io/badge/Code-29.74%25-yellow.svg)](https://github.com/999sian/fsa-decomp)
[![Matched Functions](https://img.shields.io/badge/Functions-59.06%25-green.svg)](https://github.com/999sian/fsa-decomp)
[![Linked Objects](https://img.shields.io/badge/Linked_Files-444%20%2F%20889-blue.svg)](https://github.com/999sian/fsa-decomp)

A matching decompilation of **The Legend of Zelda: Four Swords Adventures** (GameCube), targeting **G4SE01 — USA, Rev 0**.

The goal of this project is to produce readable, idiomatic C/C++ source code that compiles with the original Metrowerks compiler and links to a `main.dol` binary that is **byte-for-byte identical** to the retail release.

> **Note**: This repository contains **no copyrighted game assets or retail binaries**. An existing, legally acquired copy of the game is required to extract original files and build the target executable.

---

## Target Releases

| ID | Region | Disc SHA-1 | `main.dol` SHA-1 | Status |
| :--- | :--- | :--- | :--- | :--- |
| **G4SE01** | USA (Rev 0) | `4bd926835dfbeaae72d01abe5fb581b527154a30` | `d86b3d9f785566e34264035e140ef3daf3cc19f0` | **Primary Target** (29.74% code matched) |
| **G4SJ01** | Japan | `520d86a7b82c45aaa26cb6dd29300ccfb671cd95` | `56097356bceafde9a64abeab8501b909746ac03c` | **Supported** (0.11% code matched, retail verified) |
| **G4SP01** | Europe | `e9842565f6f39a321f28f56e621a0b6de58bc960` | `66dbc77f258a64d8bc8d7b0041c619ed70d0c00b` | **Supported** (0.11% code matched, retail verified) |
---

## Progress Tracker

Current progress is automatically tracked against compiler-verified metadata from `main.dol`:

<!-- PROGRESS_START -->
| Category | Matched Code | Matched Functions | Linked Files | Progress |
| :--- | :--- | :--- | :--- | :--- |
| **Overall** | **29.74%** (1,321,260 / 4,442,032 B) | **59.06%** (6,826 / 11,558 fns) | **444 / 889** | `████░░░░░░░░░░░` |
| **Game Code** | **16.35%** (583,840 / 3,570,768 B) | **42.10%** (2,852 / 6,774 fns) | **104 / 531** | `██░░░░░░░░░░░░░` |
| **SDK Code** | **96.57%** (229,256 / 237,392 B) | **99.81%** (1,064 / 1,066 fns) | **172 / 175** | `██████████████░` |
| **JSystem Code** | **97.24%** (508,164 / 522,584 B) | **99.18%** (2,910 / 2,934 fns) | **168 / 183** | `███████████████` |

*Fuzzy code matching stands at **34.50%** (includes near-matches).*
<!-- PROGRESS_END -->
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
