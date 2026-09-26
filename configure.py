#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "G4SE01",  # 0 USA
    "G4SJ01",  # 1 Japan
    "G4SP01",  # 2 Europe (PAL)
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-2"
config.compilers_tag = "20260305"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.6.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Warning flags
if args.warn == "all":
    cflags_base.append("-W all")
elif args.warn == "off":
    cflags_base.append("-W off")
elif args.warn == "error":
    cflags_base.append("-W error")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

# JSystem flags (from mkdd decomp's cflags_jsystem, but -O4,p)
cflags_jsystem = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-use_lmw_stmw on",
    "-common on",
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-multibyte",
    "-i include",
    "-i libs/PowerPC_EABI_Support/include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
    "-lang=c++",
    "-fp fmadd",
    "-char signed",
    "-rostr",
    "-DNDEBUG=1" if not args.debug else "-DDEBUG=1",
]

# JAudio/Interface (JAI) flags: JSystem flags plus MATCHING, which enables the
# JASFakeMatch*.h headers that emit the per-TU JASPoolAllocObject memPool_
# instances (and their __sinit guards) exactly as the retail objects have them.
cflags_jai = [
    *cflags_jsystem,
    "-DMATCHING=1",
]
# JAudio/Utility + JAudio/Task flags (jau-task unit)
cflags_jau = [*cflags_jsystem, "-DMATCHING=1"]
# Extra flags for JAudio/Task (DSP driver), as in the mkdd decomp
cflags_jaudio_task = ["-O4,s", "-inline noauto", "-use_lmw_stmw off", "-func_align 32"]
# J3D/GraphBase flags: JSystem flags + retail volatile GXWGFifo (see dolphin/gx/GXVert.h)
cflags_j3d_base = [
    *cflags_jsystem,
    "-DGX_WGPIPE_VOLATILE",
]

config.linker_version = "GC/1.3.2"


# SDK / MSL / Runtime / MetroTRK flags. Sources and headers (include/sdk) were
# imported from the Pikmin 2 decomp (projectPiki/pikmin2), whose SDK build
# stamps match FSA's; flags follow that project's configure.py.
cflags_sdk_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-w off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",
    "-i include/sdk",
    "-i include/sdk/stl",
    f"-i build/{config.version}/include",
    f"-DVERSION_{config.version}",
]

cflags_sdk_runtime = [
    *cflags_sdk_base,
    "-use_lmw_stmw on",
    "-str reuse,readonly",
    "-common off",
    "-inline auto",
]

# Per-library extra flags for Dolphin SDK libraries (GC/1.2.5n)
dolphin_lib_cflags = {
    "OdemuExi2": ["-inline deferred"],
    "ai": ["-str noreadonly"],
    "ar": ["-str noreadonly"],
    "card": ["-str noreadonly"],
    "db": ["-str noreadonly"],
    "dsp": ["-str noreadonly"],
    "dvd": ["-str noreadonly"],
    "exi": ["-str noreadonly"],
    "gba": ["-str noreadonly"],
    "gx": ["-str noreadonly", "-fp_contract off"],
    "os": ["-str noreadonly"],
    "pad": ["-fp_contract off", "-str noreadonly"],
    "si": ["-str noreadonly"],
    "vi": ["-str noreadonly"],
}


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": [*cflags_sdk_runtime, *dolphin_lib_cflags.get(lib_name, [])],
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for MSL / Runtime / MetroTRK libraries
def SdkLib(lib_name: str, mw_version: str, cflags: List[str], objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": mw_version,
        "cflags": cflags,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for JSystem libraries (source imported from the mkdd decomp)
def JSystemLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/2.6",
        "cflags": cflags_jsystem,
        "progress_category": "jsys",
        "objects": objects,
    }


# Game code flags (FSA game engine, Metrowerks GC/2.6).
# -Cpp_exceptions on: retail actor TUs DO carry extab/extabindex (BOTS dtor has
# @etb_80005898 / @eti_80011C14); with `off` MWCC emits none. `.text`/`.data`
# are byte-identical either way.
cflags_game = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions on",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-use_lmw_stmw on",
    "-common on",
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-multibyte",
    "-i include",
    "-i libs/PowerPC_EABI_Support/include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
    "-lang=c++",
    "-fp fmadd",
    "-char signed",
    "-rostr",
    "-DNDEBUG=1" if not args.debug else "-DDEBUG=1",
]


# Helper function for game (FSA engine) libraries
def GameLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/2.6",
        "cflags": cflags_game,
        "progress_category": "game",
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_rel,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


# JAudio/System flags (jas-a unit)
cflags_jas_a = [*cflags_jsystem, "-DMATCHING=1"]

config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    DolphinLib(
        "base",
        [
            Object(Matching, "dolphin/base/PPCArch.c"),
        ],
    ),
    DolphinLib(
        "db",
        [
            Object(Matching, "dolphin/db/db.c"),
        ],
    ),
    DolphinLib(
        "os",
        [
            Object(Matching, "dolphin/os/OS.c"),
            Object(Matching, "dolphin/os/OSAlarm.c"),
            Object(Matching, "dolphin/os/OSAlloc.c"),
            Object(Matching, "dolphin/os/OSArena.c"),
            Object(Matching, "dolphin/os/OSAudioSystem.c"),
            Object(Matching, "dolphin/os/OSCache.c"),
            Object(Matching, "dolphin/os/OSContext.c"),
            Object(Matching, "dolphin/os/OSError.c"),
            Object(Matching, "dolphin/os/OSFont.c"),
            Object(Matching, "dolphin/os/OSInterrupt.c"),
            Object(Matching, "dolphin/os/OSLink.c"),
            Object(Matching, "dolphin/os/OSMessage.c"),
            Object(Matching, "dolphin/os/OSMemory.c"),
            Object(Matching, "dolphin/os/OSMutex.c"),
            Object(Matching, "dolphin/os/OSReboot.c"),
            Object(Matching, "dolphin/os/OSReset.c"),
            Object(Matching, "dolphin/os/OSResetSW.c"),
            Object(Matching, "dolphin/os/OSRtc.c"),
            Object(Matching, "dolphin/os/OSSync.c"),
            Object(Matching, "dolphin/os/OSThread.c"),
            Object(Matching, "dolphin/os/OSTime.c"),
            Object(Matching, "dolphin/os/__start.c"),
            Object(Matching, "dolphin/os/__ppc_eabi_init.cpp"),
        ],
    ),
    DolphinLib(
        "mtx",
        [
            Object(Matching, "dolphin/mtx/mtx.c"),
            Object(Matching, "dolphin/mtx/mtxvec.c"),
            Object(Matching, "dolphin/mtx/mtx44.c"),
            Object(Matching, "dolphin/mtx/vec.c", extra_cflags=["-fp_contract off"]),
        ],
    ),
    DolphinLib(
        "dvd",
        [
            Object(Matching, "dolphin/dvd/dvdlow.c"),
            Object(Matching, "dolphin/dvd/dvdfs.c"),
            Object(Matching, "dolphin/dvd/dvd.c"),
            Object(Matching, "dolphin/dvd/dvdqueue.c"),
            Object(Matching, "dolphin/dvd/dvderror.c"),
            Object(Matching, "dolphin/dvd/dvdidutils.c"),
            Object(Matching, "dolphin/dvd/dvdFatal.c"),
            Object(Matching, "dolphin/dvd/fstload.c"),
        ],
    ),
    DolphinLib(
        "vi",
        [
            Object(Matching, "dolphin/vi/vi.c"),
        ],
    ),
    DolphinLib(
        "pad",
        [
            Object(Matching, "dolphin/pad/Padclamp.c"),
            Object(Matching, "dolphin/pad/Pad.c"),
        ],
    ),
    DolphinLib(
        "ai",
        [
            Object(Matching, "dolphin/ai/ai.c"),
        ],
    ),
    DolphinLib(
        "ar",
        [
            Object(Matching, "dolphin/ar/ar.c"),
            Object(Matching, "dolphin/ar/arq.c"),
        ],
    ),
    DolphinLib(
        "dsp",
        [
            Object(Matching, "dolphin/dsp/dsp.c"),
            Object(Matching, "dolphin/dsp/dsp_debug.c"),
            Object(Matching, "dolphin/dsp/dsp_task.c"),
        ],
    ),
    DolphinLib(
        "card",
        [
            Object(Matching, "dolphin/card/CARDBios.c"),
            Object(Matching, "dolphin/card/CARDUnlock.c"),
            Object(Matching, "dolphin/card/CARDRdwr.c"),
            Object(Matching, "dolphin/card/CARDBlock.c"),
            Object(Matching, "dolphin/card/CARDDir.c"),
            Object(Matching, "dolphin/card/CARDCheck.c"),
            Object(Matching, "dolphin/card/CARDMount.c"),
            Object(Matching, "dolphin/card/CARDFormat.c"),
            Object(Matching, "dolphin/card/CARDOpen.c"),
            Object(Matching, "dolphin/card/CARDCreate.c"),
            Object(Matching, "dolphin/card/CARDRead.c"),
            Object(Matching, "dolphin/card/CARDWrite.c"),
            Object(Matching, "dolphin/card/CARDStat.c"),
            Object(Matching, "dolphin/card/CARDNet.c"),
        ],
    ),
    DolphinLib(
        "gx",
        [
            Object(Matching, "dolphin/gx/GXInit.c"),
            Object(Matching, "dolphin/gx/GXFifo.c"),
            Object(Matching, "dolphin/gx/GXAttr.c"),
            Object(Matching, "dolphin/gx/GXMisc.c"),
            Object(Matching, "dolphin/gx/GXGeometry.c"),
            Object(Matching, "dolphin/gx/GXFrameBuf.c"),
            Object(Matching, "dolphin/gx/GXLight.c"),
            Object(Matching, "dolphin/gx/GXTexture.c"),
            Object(Matching, "dolphin/gx/GXBump.c"),
            Object(Matching, "dolphin/gx/GXTev.c"),
            Object(Matching, "dolphin/gx/GXPixel.c"),
            Object(Matching, "dolphin/gx/GXDraw.c"),
            Object(Matching, "dolphin/gx/GXDisplayList.c"),
            Object(Matching, "dolphin/gx/GXTransform.c"),
            Object(Matching, "dolphin/gx/GXPerf.c"),
        ],
    ),
    SdkLib(
        "TRK_MINNOW_DOLPHIN",
        "GC/2.6",
        [*cflags_sdk_runtime, "-inline deferred", "-sdata 0", "-sdata2 0"],
        [
            Object(Matching, "TRK_MINNOW_DOLPHIN/mainloop.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/nubevent.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/nubinit.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/msg.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/msgbuf.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/serpoll.c", extra_cflags=["-sdata 8"]),
            Object(Matching, "TRK_MINNOW_DOLPHIN/usr_put.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/dispatch.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/msghndlr.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/support.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mutex_TRK.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/notify.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/flush_cache.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mem_TRK.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/targimpl.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/targsupp.s"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mpc_7xx_603e.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/__exception.s"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/dolphin_trk.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/main_TRK.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/dolphin_trk_glue.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/targcont.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/target_options.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mslsupp.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/UDP_Stubs.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/ddh/main.c", extra_cflags=["-sdata 8"]),
            Object(Matching, "TRK_MINNOW_DOLPHIN/CircleBuffer.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/gdev/main.c", extra_cflags=["-sdata 8"]),
            Object(Matching, "TRK_MINNOW_DOLPHIN/MWTrace.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/MWCriticalSection_gc.cpp"),
        ],
    ),
    SdkLib(
        "Runtime.PPCEABI.H",
        "GC/2.6",
        [*cflags_sdk_runtime, "-inline deferred"],
        [
            Object(Matching, "Runtime.PPCEABI.H/__mem.c"),
            Object(Matching, "Runtime.PPCEABI.H/__va_arg.c"),
            Object(Matching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(Matching, "Runtime.PPCEABI.H/NMWException.cp", extra_cflags=["-Cpp_exceptions on"]),
            Object(Matching, "Runtime.PPCEABI.H/ptmf.c"),
            Object(Matching, "Runtime.PPCEABI.H/runtime.c"),
            Object(Matching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
            Object(Matching, "Runtime.PPCEABI.H/Gecko_ExceptionPPC.cp", extra_cflags=["-Cpp_exceptions on"]),
            Object(Matching, "Runtime.PPCEABI.H/GCN_mem_alloc.c"),
        ],
    ),
    SdkLib(
        "MSL_C.PPCEABI.bare.H",
        "GC/2.6",
        [*cflags_sdk_runtime, "-inline deferred"],
        [
            Object(Matching, "MSL_C/PPC_EABI/abort_exit.c"),
            Object(Matching, "MSL_C/MSL_Common/alloc.c"),
            Object(Matching, "MSL_C/MSL_Common/errno.c"),
            Object(Matching, "MSL_C/MSL_Common/ansi_files.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/ansi_fp.c", extra_cflags=["-str pool"]),
            Object(Matching, "MSL_C/MSL_Common/arith.c"),
            Object(Matching, "MSL_C/MSL_Common/buffer_io.c"),
            Object(Matching, "MSL_C/PPC_EABI/critical_regions.gamecube.c"),
            Object(Matching, "MSL_C/MSL_Common/ctype.c"),
            Object(NonMatching, "MSL_C/MSL_Common/locale.c", extra_cflags=["-str pool"]),
            Object(Matching, "MSL_C/MSL_Common/direct_io.c"),
            Object(Matching, "MSL_C/MSL_Common/file_io.c"),
            Object(Matching, "MSL_C/MSL_Common/FILE_POS.C"),
            Object(Matching, "MSL_C/MSL_Common/mbstring.c", extra_cflags=["-inline noauto,deferred"]),
            Object(Matching, "MSL_C/MSL_Common/mem.c"),
            Object(Matching, "MSL_C/MSL_Common/mem_funcs.c"),
            Object(Matching, "MSL_C/MSL_Common/misc_io.c"),
            Object(Matching, "MSL_C/MSL_Common/printf.c", extra_cflags=["-str pool"]),
            Object(Matching, "MSL_C/MSL_Common/float.c"),
            Object(Matching, "MSL_C/MSL_Common/qsort.c"),
            Object(Matching, "MSL_C/MSL_Common/scanf.c"),
            Object(Matching, "MSL_C/MSL_Common/signal.c"),
            Object(Matching, "MSL_C/MSL_Common/string.c"),
            Object(Matching, "MSL_C/MSL_Common/strtoul.c"),
            Object(Matching, "MSL_C/MSL_Common/wchar_io.c"),
            Object(Matching, "MSL_C/PPC_EABI/uart_console_io_gcn.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_asin.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_atan2.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_rem_pio2.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/k_cos.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/k_rem_pio2.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/k_sin.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_atan.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ceil.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_copysign.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_cos.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_floor.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_frexp.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ldexp.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_modf.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_sin.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/w_asin.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/w_atan2.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_sqrt.c"),
            Object(Matching, "MSL_C/PPC_EABI/math_ppc.c"),
            Object(Matching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/w_sqrt.c"),
        ],
    ),
    DolphinLib(
        "amcstubs",
        [
            Object(Matching, "dolphin/amcstubs/AmcExi2Stubs.c"),
        ],
    ),
    DolphinLib(
        "odenotstub",
        [
            Object(Matching, "dolphin/odenotstub/odenotstub.c"),
        ],
    ),
    DolphinLib(
        "OdemuExi2",
        [
            Object(Matching, "dolphin/OdemuExi2/DebuggerDriver.c"),
        ],
    ),
    DolphinLib(
        "gd",
        [
            Object(Matching, "dolphin/gd/GDBase.c"),
            Object(Matching, "dolphin/gd/GDGeometry.c"),
        ],
    ),
    DolphinLib(
        "exi",
        [
            Object(Matching, "dolphin/exi/EXIBios.c"),
            Object(Matching, "dolphin/exi/EXIUart.c"),
        ],
    ),
    DolphinLib(
        "si",
        [
            Object(Matching, "dolphin/si/SIBios.c"),
            Object(Matching, "dolphin/si/SISamplingRate.c"),
        ],
    ),
    DolphinLib(
        "gba",
        [
            Object(Matching, "dolphin/gba/GBA.c"),
            Object(Matching, "dolphin/gba/GBAJoyBoot.c"),
            Object(Matching, "dolphin/gba/GBARead.c"),
            Object(Matching, "dolphin/gba/GBAWrite.c"),
            Object(Matching, "dolphin/gba/GBAXfer.c"),
            Object(Matching, "dolphin/gba/GBAKey.c"),
        ],
    ),
    # jas-sinit: first .text TU (shared per-TU JASPoolAllocObject __sinit pools).
    # MATCHING enables the JASFakeMatch*.h memPool_ definitions; retail has
    # extab entries for this TU, so it was built with C++ exceptions on.
    {
        "lib": "JAudio_PoolSinit",
        "mw_version": "GC/2.6",
        "cflags": [*cflags_jsystem, "-DMATCHING=1", "-Cpp_exceptions on"],
        "progress_category": "jsys",
        "objects": [
            Object(Matching, "JSystem/JAudio/JASPoolSinit.cpp"),
        ],
    },
    JSystemLib(
        "JKernel",
        [
            Object(Matching, "JSystem/JKernel/JKRAram.cpp"),
            Object(Matching, "JSystem/JKernel/JKRAramBlock.cpp"),
            Object(Matching, "JSystem/JKernel/JKRAramHeap.cpp"),
            Object(Matching, "JSystem/JKernel/JKRAramPiece.cpp"),
            Object(Matching, "JSystem/JKernel/JKRAramStream.cpp"),
            Object(Matching, "JSystem/JKernel/JKRArchivePri.cpp"),
            Object(Matching, "JSystem/JKernel/JKRArchivePub.cpp"),
            Object(Matching, "JSystem/JKernel/JKRCompArchive.cpp"),
            Object(Matching, "JSystem/JKernel/JKRDecomp.cpp"),
            Object(Matching, "JSystem/JKernel/JKRDisposer.cpp"),
            Object(Matching, "JSystem/JKernel/JKRDvdAramRipper.cpp"),
            Object(Matching, "JSystem/JKernel/JKRDvdArchive.cpp"),
            Object(Matching, "JSystem/JKernel/JKRDvdFile.cpp"),
            Object(Matching, "JSystem/JKernel/JKRDvdRipper.cpp"),
            Object(Matching, "JSystem/JKernel/JKRExpHeap.cpp"),
            Object(Matching, "JSystem/JKernel/JKRFileLoader.cpp"),
            Object(Matching, "JSystem/JKernel/JKRHeap.cpp"),
            Object(Matching, "JSystem/JKernel/JKRMemArchive.cpp"),
            Object(Matching, "JSystem/JKernel/JKRSolidHeap.cpp"),
            Object(Matching, "JSystem/JKernel/JKRThread.cpp"),
        ],
    ),
    JSystemLib(
        "JSupport",
        [
            Object(Matching, "JSystem/JSupport/JSUFileStream.cpp"),
            Object(Matching, "JSystem/JSupport/JSUInputStream.cpp"),
            Object(Matching, "JSystem/JSupport/JSUList.cpp"),
            Object(Matching, "JSystem/JSupport/JSUMemoryStream.cpp"),
        ],
    ),
    JSystemLib(
        "JUtility",
        [
            Object(Matching, "JSystem/JUtility/JUTAssert.cpp"),
            Object(Matching, "JSystem/JUtility/JUTConsole.cpp"),
            Object(Matching, "JSystem/JUtility/JUTDbPrint.cpp"),
            Object(Matching, "JSystem/JUtility/JUTDirectFile.cpp"),
            Object(Matching, "JSystem/JUtility/JUTDirectPrint.cpp"),
            Object(Matching, "JSystem/JUtility/JUTFont.cpp"),
            Object(Matching, "JSystem/JUtility/JUTGraphFifo.cpp"),
            Object(Matching, "JSystem/JUtility/JUTNameTab.cpp"),
            Object(Matching, "JSystem/JUtility/JUTPalette.cpp"),
            Object(Matching, "JSystem/JUtility/JUTProcBar.cpp"),
            Object(Matching, "JSystem/JUtility/JUTResFont.cpp"),
            Object(Matching, "JSystem/JUtility/JUTResource.cpp"),
            Object(Matching, "JSystem/JUtility/JUTTexture.cpp"),
            Object(Matching, "JSystem/JUtility/JUTVideo.cpp"),
            Object(Matching, "JSystem/JUtility/JUTXfb.cpp"),
        ],
    ),
    {
        "lib": "JAudio_Interface",
        "mw_version": "GC/2.6",
        "cflags": cflags_jai,
        "progress_category": "jsys",
        "objects": [
            Object(Matching, "JSystem/JAudio/Interface/JAIAudience.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISe.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISeMgr.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISeq.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISeqDataMgr.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISeqMgr.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISound.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISoundChild.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISoundHandles.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISoundInfo.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISoundParams.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAISoundStarter.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAIStream.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAIStreamDataMgr.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAIStreamMgr.cpp"),
            Object(Matching, "JSystem/JAudio/Interface/JAIAudible.cpp"),
        ],
    },
    JSystemLib(
        "jas-b",
        [
            Object(NonMatching, "JSystem/JAudio/System/JASHeapCtrl.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASInstRand.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASInstSense.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASLfo.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASOscillator.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASProbe.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASRegisterParam.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASReport.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASResArcLoader.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASSeqCtrl.cpp", extra_cflags=["-DMATCHING=1"]),
            Object(Matching, "JSystem/JAudio/System/JASSeqParser.cpp", extra_cflags=["-DMATCHING=1"]),
            Object(Matching, "JSystem/JAudio/System/JASSeqReader.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASSimpleWaveBank.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASSoundParams.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASTaskThread.cpp"),
            Object(NonMatching, "JSystem/JAudio/System/JASTrack.cpp", extra_cflags=["-DMATCHING=1"]),
            Object(Matching, "JSystem/JAudio/System/JASTrackPort.cpp"),
            Object(NonMatching, "JSystem/JAudio/System/JASWaveArcLoader.cpp"),
            # JASWaveBank.cpp (only JASWaveBank::isLoading) is dead-stripped in FSA:
            # it has no code or data in main.dol.
            Object(Matching, "JSystem/JAudio/System/JASWSParser.cpp"),
        ],
    ),
    # JSystem TUs not present in the mkdd decomp (JMessage, extra JGadget, ...)
    JSystemLib(
        "jextra",
        [
            Object(Matching, "JSystem/JMessage/resource.cpp"),
            Object(Matching, "JSystem/JMessage/data.cpp"),
            Object(Matching, "JSystem/JMessage/processor.cpp"),
            Object(Matching, "JSystem/JMessage/control.cpp"),
            Object(Matching, "JSystem/JGadget/binary.cpp"),
            Object(Matching, "JSystem/JGadget/std-vector.cpp"),
        ],
    ),
    {
        # JAudio/Utility + JAudio/Task (jau-task); -DMATCHING=1 enables the
        # donor's explicit static memPool_ definitions (JASFakeMatch*.h)
        "lib": "jau-task",
        "mw_version": "GC/2.6",
        "cflags": cflags_jau,
        "progress_category": "jsys",
        "objects": [
            # JAudio/Task: DSP driver, built with mkdd's per-file flags
            Object(Matching, "JSystem/JAudio/Task/dspproc.c", extra_cflags=cflags_jaudio_task),
            Object(Matching, "JSystem/JAudio/Task/dsptask.c", extra_cflags=cflags_jaudio_task),
            Object(Matching, "JSystem/JAudio/Task/osdsp.c", extra_cflags=cflags_jaudio_task),
            Object(Matching, "JSystem/JAudio/Task/osdsp_task.c", extra_cflags=cflags_jaudio_task),
            # JAudio/Utility
            Object(Matching, "JSystem/JAudio/Utility/JAUAudioArcInterpreter.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUAudioArcLoader.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUBankTable.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUClusterSound.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUInitializer.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUSectionHeap.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUSeqCollection.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUSeqDataBlockMgr.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUSoundMgr.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUSoundObject.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUSoundTable.cpp"),
            Object(Matching, "JSystem/JAudio/Utility/JAUStreamFileTable.cpp"),
        ],
    },
    JSystemLib(
        "JParticle",
        [
            Object(NonMatching, "JSystem/JParticle/JPABaseShape.cpp"),
            Object(Matching, "JSystem/JParticle/JPAChildShape.cpp"),
            Object(Matching, "JSystem/JParticle/JPADynamicsBlock.cpp"),
            Object(Matching, "JSystem/JParticle/JPAEmitter.cpp"),
            Object(Matching, "JSystem/JParticle/JPAEmitterManager.cpp"),
            Object(Matching, "JSystem/JParticle/JPAExTexShape.cpp"),
            Object(Matching, "JSystem/JParticle/JPAExtraShape.cpp"),
            Object(Matching, "JSystem/JParticle/JPAFieldBlock.cpp"),
            Object(Matching, "JSystem/JParticle/JPAKeyBlock.cpp"),
            Object(Matching, "JSystem/JParticle/JPAMath.cpp"),
            Object(Matching, "JSystem/JParticle/JPAParticle.cpp"),
            Object(Matching, "JSystem/JParticle/JPAResource.cpp"),
            Object(Matching, "JSystem/JParticle/JPAResourceLoader.cpp"),
            Object(Matching, "JSystem/JParticle/JPAResourceManager.cpp"),
            Object(Matching, "JSystem/JParticle/JPATexture.cpp"),
        ],
    ),
    JSystemLib(
        "j2d-a",
        [
            Object(Matching, "JSystem/J2DGraph/J2DAnimation.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DAnmLoader.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DBloSaver.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DGrafContext.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DManage.cpp"),
            Object(NonMatching, "JSystem/J2DGraph/J2DMatBlock.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DMaterial.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DMaterialFactory.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DOrthoGraph.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DPane.cpp"),
        ],
    ),
    {
        # J3D/GraphBase (source from the Pikmin 2 decomp; mkdd has none).
        # J3D needs the retail (volatile) GX write-gather pipe declaration.
        "lib": "j3d-base",
        "mw_version": "GC/2.6",
        "cflags": cflags_j3d_base,
        "progress_category": "jsys",
        "objects": [
            Object(Matching, "JSystem/J3D/GraphBase/J3DGD.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DTransform.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DSys.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DDrawBuffer.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DShapeDraw.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DVertex.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DPacket.cpp"),
            Object(NonMatching, "JSystem/J3D/GraphBase/J3DShape.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DMaterial.cpp"),
            Object(NonMatching, "JSystem/J3D/GraphBase/J3DTevs.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DShapeMtx.cpp"),
            Object(Matching, "JSystem/J3D/GraphBase/J3DStruct.cpp"),
        ],
    },
    {
        # JAudio/System (jas-a); -DMATCHING=1 enables the donor's explicit
        # JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_ definitions
        "lib": "jas-a",
        "mw_version": "GC/2.6",
        "cflags": cflags_jas_a,
        "progress_category": "jsys",
        "objects": [
            Object(Matching, "JSystem/JAudio/System/JASAiCtrl.cpp"),
            Object(NonMatching, "JSystem/JAudio/System/JASAramStream.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASAudioReseter.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASAudioThread.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASBank.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASBasicBank.cpp"),
            Object(NonMatching, "JSystem/JAudio/System/JASBasicInst.cpp"),
            Object(NonMatching, "JSystem/JAudio/System/JASBasicWaveBank.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASCalc.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASCallback.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASChannel.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASCmdStack.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASDriverIF.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASDSPChannel.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASDSPInterface.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASDrumSet.cpp"),
            Object(Matching, "JSystem/JAudio/System/JASDvdThread.cpp"),
        ],
    },
    # jmisc: J3DU + JMath + JGadget + JFramework
    JSystemLib(
        "jmisc",
        [
            Object(Matching, "JSystem/JFramework/JFWDisplay.cpp"),
            Object(Matching, "JSystem/JFramework/JFWSystem.cpp"),
            Object(Matching, "JSystem/JMath/JMath.cpp"),
            Object(Matching, "JSystem/JMath/random.cpp"),
            Object(Matching, "JSystem/JMath/JMATrigonometric.cpp"),
            Object(Matching, "JSystem/JGadget/linklist.cpp"),
        ],
    ),
    # Game code slice e0 (0x800F37A8-0x8015C828): function bodies from
    # EverydaySimpleDev/FSA-Decomp (CC0) that match under GC/2.6.
    {
        "lib": "Game_esd_e0",
        "mw_version": "GC/2.6",
        "cflags": [
            *cflags_base,
            "-use_lmw_stmw on",
            "-str reuse,pool,readonly",
            "-common on",
            "-RTTI on",
            "-inline auto",
            "-Cpp_exceptions on",
            "-DMATCHING=1",
            "-i libs/PowerPC_EABI_Support/include",
        ],
        "progress_category": "game",
        "objects": [
            Object(Matching, "Game/NZMI_800F3C10.cpp"),
            Object(NonMatching, "Game/IWAG_800F46C0.cpp"),
            Object(NonMatching, "Game/OIWA_800F4C70.cpp"),
            Object(NonMatching, "Game/LPLK_800F6820.cpp"),
            Object(NonMatching, "Game/WRTC_800F7FCC.cpp"),
            Object(NonMatching, "Game/RAIL_800FD438.cpp"),
            Object(NonMatching, "Game/tu_800FE8C0.cpp"),
            Object(NonMatching, "Game/GSYA_800FF060.cpp"),
            Object(NonMatching, "Game/MGYA_8010089C.cpp"),
            Object(NonMatching, "Game/ANHO_80102278.cpp"),
            Object(NonMatching, "Game/TWEV_80103348.cpp"),
            Object(Matching, "Game/LOSW_80104C3C.cpp"),
            Object(NonMatching, "Game/CLOD_80105368.cpp"),
            Object(Matching, "Game/ARSH_80105DD4.cpp"),
            Object(NonMatching, "Game/WLFT_80106040.cpp"),
            Object(NonMatching, "Game/WIND_80106ADC.cpp"),
            Object(NonMatching, "Game/CNON_80107360.cpp"),
            Object(Matching, "Game/DEAL_80108414.cpp"),
            Object(NonMatching, "Game/SHTM_80108A6C.cpp"),
            Object(NonMatching, "Game/ICCL_8010B284.cpp"),
            Object(Matching, "Game/DBMS_8010DA6C.cpp"),
            Object(Matching, "Game/tu_8010DF44.cpp"),
            Object(Matching, "Game/tu_8011A0F8.cpp"),
            Object(NonMatching, "Game/BARI_8011EEEC.cpp"),
            Object(NonMatching, "Game/RNBW_80129B0C.cpp"),
            Object(NonMatching, "Game/BTBZ_8012CF5C.cpp"),
            Object(Matching, "Game/IFCK_8012F008.cpp"),
            Object(NonMatching, "Game/WPCN_80130FAC.cpp"),
            Object(NonMatching, "Game/tu_80134C04.cpp"),
            Object(NonMatching, "Game/tu_8013AAD4.cpp"),
            Object(NonMatching, "Game/tu_8013C5C8.cpp"),
            Object(NonMatching, "Game/OKTA_8013F9A8.cpp"),
            Object(NonMatching, "Game/BZBR_80144134.cpp"),
            Object(NonMatching, "Game/DBRK_8014529C.cpp"),
            Object(NonMatching, "Game/TKTA_801549B0.cpp"),
            Object(NonMatching, "Game/BOYO_8015B98C.cpp"),
        ],
    },
    # EverydaySimpleDev/FSA-Decomp imports, slice e1 (0x8015C828-0x801B0A00)
    {
        "lib": "Game_esd_e1",
        "mw_version": "GC/2.6",
        "cflags": [
            *cflags_base,
            "-use_lmw_stmw on",
            "-str reuse,pool,readonly",
            "-common on",
            "-RTTI on",
            "-char signed",
            "-Cpp_exceptions on",
            "-DMATCHING=1",
            "-i libs/PowerPC_EABI_Support/include",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "Game/gnma.cpp"),
            Object(NonMatching, "Game/trap.cpp"),
            Object(NonMatching, "Game/mozo.cpp"),
            Object(NonMatching, "Game/puku.cpp"),
            Object(NonMatching, "Game/swbm.cpp"),
            Object(NonMatching, "Game/keth.cpp"),
            Object(NonMatching, "Game/flme.cpp"),
            Object(NonMatching, "Game/ezry.cpp"),
            Object(NonMatching, "Game/arrw.cpp"),
            Object(NonMatching, "Game/poon.cpp"),
            Object(NonMatching, "Game/popo.cpp"),
            Object(NonMatching, "Game/stal.cpp"),
            Object(NonMatching, "Game/wizr.cpp"),
            Object(NonMatching, "Game/rdvr.cpp"),
            Object(NonMatching, "Game/gdmn.cpp"),
            Object(NonMatching, "Game/fagn.cpp"),
            Object(NonMatching, "Game/wnwn.cpp"),
            Object(NonMatching, "Game/fgn2.cpp"),
            Object(NonMatching, "Game/bph2.cpp"),
            Object(NonMatching, "Game/dgt2.cpp"),
            Object(NonMatching, "Game/gnon.cpp"),
            Object(NonMatching, "Game/tu_80197070.cpp"),
            Object(NonMatching, "Game/tenn.cpp"),
            Object(NonMatching, "Game/enbz.cpp"),
            Object(NonMatching, "Game/tu_801a3c50.cpp"),
            Object(NonMatching, "Game/ryya.cpp"),
            Object(NonMatching, "Game/hbb2.cpp"),
            Object(NonMatching, "Game/ttat.cpp"),
            Object(NonMatching, "Game/ddgo.cpp"),
            Object(NonMatching, "Game/okam.cpp"),
            Object(NonMatching, "Game/egol.cpp"),
        ],
    },
    # EverydaySimpleDev/FSA-Decomp harvest, slice e2 (.text 0x801B0A00-0x801EE24C)
    {
        "lib": "Game_esd_e2",
        "mw_version": "GC/2.6",
        "cflags": [
            "-nodefaults", "-proc gekko", "-align powerpc", "-enum int",
            "-fp hardware", "-use_lmw_stmw on", "-O4,p",
            "-inline auto", '-pragma "cats off"', '-pragma "warn_notinlined off"',
            "-maxerrors 1", "-nosyspath", "-RTTI on", "-char signed",
            "-fp_contract on", "-str reuse,pool,readonly", "-common on",
            "-multibyte", "-i include", f"-i build/{config.version}/include",
            f"-DVERSION={version_num}",
            "-Cpp_exceptions on",
            "-DMATCHING=1",
            "-i libs/PowerPC_EABI_Support/include",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "Game/zld3_801B0A00.cpp"),
            Object(NonMatching, "Game/tu_801B27DC.cpp"),
            Object(NonMatching, "Game/zdco_801B3F60.cpp"),
            Object(NonMatching, "Game/tlwp_801B4D0C.cpp"),
            Object(NonMatching, "Game/safu_801B6634.cpp"),
            Object(NonMatching, "Game/gewp_801B6C50.cpp"),
            Object(NonMatching, "Game/rope_801B7784.cpp"),
            Object(NonMatching, "Game/pame_801B80C0.cpp"),
            Object(NonMatching, "Game/mira_801B9730.cpp"),
            Object(NonMatching, "Game/znra_801BA65C.cpp"),
            Object(NonMatching, "Game/fall_801BB618.cpp"),
            Object(NonMatching, "Game/ezmr_801BD108.cpp"),
            Object(Matching, "Game/ezob_801BD8C0.cpp"),
            Object(NonMatching, "Game/bmst_801BDE5C.cpp"),
            Object(NonMatching, "Game/lnbm_801BEDBC.cpp"),
            Object(NonMatching, "Game/tndr_801BF810.cpp"),
            Object(NonMatching, "Game/tu_801C0D70.cpp"),
            Object(NonMatching, "Game/slk2_801C26D8.cpp"),
            Object(NonMatching, "Game/tu_801C9AF8.cpp"),
            Object(NonMatching, "Game/tu_801CB270.cpp"),
            Object(NonMatching, "Game/tu_801CDC8C.cpp"),
            Object(NonMatching, "Game/tu_801D1C18.cpp"),
            Object(Matching, "Game/tu_801D2C60.cpp"),
            Object(NonMatching, "Game/bogf_801D46FC.cpp"),
            Object(NonMatching, "Game/tu_801D6CEC.cpp"),
            Object(NonMatching, "Game/bgbl_801D7AFC.cpp"),
            Object(NonMatching, "Game/tu_801D8400.cpp"),
            Object(NonMatching, "Game/tu_801DAC6C.cpp"),
            Object(NonMatching, "Game/ichl_801DB18C.cpp"),
            Object(NonMatching, "Game/boit_801DC264.cpp"),
            Object(Matching, "Game/boib_801DCC98.cpp"),
            Object(NonMatching, "Game/thnk_801DE714.cpp"),
            Object(Matching, "Game/tinb_801E31C0.cpp"),
            Object(NonMatching, "Game/ipot_801E6D48.cpp"),
            Object(NonMatching, "Game/fspo_801E7BF4.cpp"),
            Object(NonMatching, "Game/fsob_801E801C.cpp"),
            Object(NonMatching, "Game/hrmn_801EBC84.cpp"),
            Object(NonMatching, "Game/tu_801ED3DC.cpp"),
        ],
    },
    # EverydaySimpleDev/FSA-Decomp C bodies, .text 0x801F6058-0x802AFA10 (slice e3)
    {
        "lib": "Game_esd_e3",
        "mw_version": "GC/2.6",
        "cflags": [
            *cflags_base,
            "-Cpp_exceptions on",
            "-RTTI on",
            "-char signed",
            "-use_lmw_stmw on",
            "-str reuse,pool,readonly",
            "-gccinc",
            "-common on",
            "-DMATCHING=1",
            "-i libs/PowerPC_EABI_Support/include",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "Game/tu_801F6058.cpp"),
            Object(NonMatching, "Game/tu_801F68E0.cpp"),
            Object(Matching, "Game/tu_801F9484.cpp"),
            Object(NonMatching, "Game/tu_80204638.cpp"),
            Object(NonMatching, "Game/tzok.cpp"),
            Object(NonMatching, "Game/tu_80206B30.cpp"),
            Object(NonMatching, "Game/tu_80207548.cpp"),
            Object(NonMatching, "Game/slmn.cpp"),
            Object(NonMatching, "Game/tu_80208E5C.cpp"),
            Object(NonMatching, "Game/tu_80209C14.cpp"),
            Object(NonMatching, "Game/fobr.cpp"),
            Object(NonMatching, "Game/zasl.cpp"),
            Object(NonMatching, "Game/tu_8020CCA8.cpp"),
            Object(NonMatching, "Game/tu_8020D58C.cpp"),
            Object(NonMatching, "Game/flor.cpp"),
            Object(NonMatching, "Game/tu_8020F798.cpp"),
            Object(Matching, "Game/ibbm.cpp"),
            Object(NonMatching, "Game/tu_80210630.cpp"),
            Object(NonMatching, "Game/rusa.cpp"),
            Object(NonMatching, "Game/tu_80212AC0.cpp"),
            Object(NonMatching, "Game/arij.cpp"),
            Object(Matching, "Game/slef.cpp"),
            Object(Matching, "Game/tu_80214244.cpp"),
            Object(NonMatching, "Game/tu_802144F0.cpp"),
            Object(Matching, "Game/tu_802153A8.cpp"),
            Object(Matching, "Game/tu_802157B8.cpp"),
            Object(NonMatching, "Game/tu_80215A94.cpp"),
            Object(NonMatching, "Game/tu_8021693C.cpp"),
            Object(NonMatching, "Game/tu_80217374.cpp"),
            Object(NonMatching, "Game/tu_8021775C.cpp"),
            Object(NonMatching, "Game/tu_8021827C.cpp"),
            Object(Matching, "Game/tu_802188B0.cpp"),
            Object(NonMatching, "Game/kepo.cpp"),
            Object(NonMatching, "Game/tu_8021A570.cpp"),
            Object(NonMatching, "Game/tu_8021AF28.cpp"),
            Object(Matching, "Game/tu_8021B904.cpp"),
            Object(Matching, "Game/tu_8021BCBC.cpp"),
            Object(Matching, "Game/tu_8021BFA8.cpp"),
            Object(NonMatching, "Game/tu_8021C2B4.cpp"),
            Object(NonMatching, "Game/tu_8021C848.cpp"),
            Object(Matching, "Game/tu_8021CDE4.cpp"),
            Object(Matching, "Game/ezge.cpp"),
            Object(NonMatching, "Game/navi.cpp"),
            Object(NonMatching, "Game/tu_8021F064.cpp"),
            Object(NonMatching, "Game/tu_8021F4B0.cpp"),
            Object(NonMatching, "Game/tu_8021FDB8.cpp"),
            Object(Matching, "Game/fbal.cpp"),
            Object(Matching, "Game/znlj.cpp"),
            Object(NonMatching, "Game/tu_80220F54.cpp"),
            Object(Matching, "Game/tu_80221B44.cpp"),
            Object(NonMatching, "Game/zsla.cpp"),
            Object(Matching, "Game/tu_80222CC4.cpp"),
            Object(NonMatching, "Game/tu_802233A4.cpp"),
            Object(NonMatching, "Game/tu_802242F4.cpp"),
            Object(NonMatching, "Game/tu_8022461C.cpp"),
            Object(NonMatching, "Game/tu_80226FC8.cpp"),
            Object(NonMatching, "Game/tu_8022979C.cpp"),
            Object(NonMatching, "Game/tu_8022AD64.cpp"),
            Object(NonMatching, "Game/tu_80234E30.cpp", extra_cflags=["-RTTI off"]),
            Object(NonMatching, "Game/tu_8023FBF0.cpp"),
            Object(NonMatching, "Game/tu_80255F4C.cpp"),
            Object(NonMatching, "Game/tu_80256C74.cpp"),
            Object(NonMatching, "Game/tu_8025EB18.cpp"),
            Object(NonMatching, "Game/tu_80264998.cpp"),
            Object(NonMatching, "Game/tu_802684A4.cpp"),
            Object(NonMatching, "Game/tu_8026FC20.cpp"),
            Object(NonMatching, "Game/tu_8027E5BC.cpp"),
            Object(NonMatching, "Game/tu_80285E58.cpp"),
            Object(NonMatching, "Game/tu_80289648.cpp"),
            Object(NonMatching, "Game/tu_8028A33C.cpp"),
            Object(NonMatching, "Game/tu_8028AB7C.cpp"),
            Object(NonMatching, "Game/tu_8028C068.cpp"),
            Object(NonMatching, "Game/tu_8028DD78.cpp"),
            Object(NonMatching, "Game/tu_8028FBA0.cpp"),
            Object(NonMatching, "Game/tu_802957CC.cpp"),
            Object(NonMatching, "Game/tu_8029B75C.cpp"),
            Object(NonMatching, "Game/tu_8029BD18.cpp"),
            Object(NonMatching, "Game/tu_8029C584.cpp"),
            Object(NonMatching, "Game/tu_8029D430.cpp"),
            Object(NonMatching, "Game/tu_8029D898.cpp"),
            Object(NonMatching, "Game/tu_802A40B8.cpp"),
            Object(NonMatching, "Game/tu_802A4654.cpp"),
            Object(NonMatching, "Game/tu_802A6A4C.cpp"),
            Object(NonMatching, "Game/tu_802A7D3C.cpp"),
            Object(NonMatching, "Game/tu_802A8220.cpp"),
            Object(NonMatching, "Game/swt4.cpp"),
        ],
    },
    # EverydaySimpleDev/FSA-Decomp C bodies, .text 0x802AFA10-0x8033E638 (slice e4)
    {
        "lib": "Game_esd_e4",
        "mw_version": "GC/2.6",
        "cflags": [
            *cflags_base,
            "-Cpp_exceptions on",
            "-RTTI on",
            "-char signed",
            "-use_lmw_stmw on",
            "-str reuse,pool,readonly",
            "-gccinc",
            "-common on",
            "-DMATCHING=1",
            "-i libs/PowerPC_EABI_Support/include",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "Game/tu_802AA364.cpp"),
            Object(NonMatching, "Game/tu_802AABFC.cpp"),
            Object(NonMatching, "Game/tu_802AB1D4.cpp"),
            Object(NonMatching, "Game/tu_802ABC74.cpp"),
            Object(NonMatching, "Game/tu_802AC03C.cpp"),
            Object(NonMatching, "Game/tu_802AC58C.cpp"),
            Object(NonMatching, "Game/tu_802AC8AC.cpp"),
            Object(NonMatching, "Game/tu_802ACEA4.cpp"),
            Object(NonMatching, "Game/tu_802AF32C.cpp"),
            Object(NonMatching, "Game/tu_802AFA10.cpp"),
            Object(NonMatching, "Game/tu_802B055C.cpp"),
            Object(NonMatching, "Game/tu_802B0CD8.cpp"),
            Object(NonMatching, "Game/tu_802B1558.cpp"),
            Object(NonMatching, "Game/tu_802B214C.cpp"),
            Object(NonMatching, "Game/tu_802B334C.cpp"),
            Object(NonMatching, "Game/tu_802B3674.cpp"),
            Object(NonMatching, "Game/tu_802B61C8.cpp"),
            Object(NonMatching, "Game/tu_802B6A70.cpp"),
            Object(NonMatching, "Game/tu_802B7890.cpp"),
            Object(NonMatching, "Game/tu_802B7C78.cpp"),
            Object(NonMatching, "Game/tu_802B8F7C.cpp"),
            Object(NonMatching, "Game/tu_802B9CAC.cpp"),
            Object(NonMatching, "Game/tu_802BA048.cpp"),
            Object(NonMatching, "Game/tu_802BA334.cpp"),
            Object(NonMatching, "Game/fire.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tu_802BC83C.cpp"),
            Object(NonMatching, "Game/tu_802BD8C0.cpp"),
            Object(NonMatching, "Game/tu_802BE39C.cpp"),
            Object(NonMatching, "Game/tu_802BE8F8.cpp"),
            Object(NonMatching, "Game/tu_802BF03C.cpp"),
            Object(NonMatching, "Game/tu_802BF410.cpp"),
            Object(NonMatching, "Game/tu_802BFB7C.cpp"),
            Object(NonMatching, "Game/key0.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/door.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tu_802C8500.cpp"),
            Object(NonMatching, "Game/tu_802C94F4.cpp"),
            Object(NonMatching, "Game/tu_802C9944.cpp"),
            Object(NonMatching, "Game/tu_802CA284.cpp"),
            Object(NonMatching, "Game/onof.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tu_802CC1C4.cpp"),
            Object(NonMatching, "Game/tu_802CCEB0.cpp"),
            Object(NonMatching, "Game/tu_802CDD3C.cpp"),
            Object(NonMatching, "Game/tu_802CEB60.cpp"),
            Object(NonMatching, "Game/tu_802CFDCC.cpp"),
            Object(NonMatching, "Game/tu_802D0B24.cpp"),
            Object(NonMatching, "Game/tu_802D14DC.cpp"),
            Object(NonMatching, "Game/tu_802D2AA4.cpp"),
            Object(NonMatching, "Game/tu_802D3184.cpp"),
            Object(NonMatching, "Game/tu_802D39B8.cpp"),
            Object(Matching, "Game/yasi.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/fgve.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/vwmd.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/urac.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/prtc.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/offs.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tu_802E2074.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/gnl2.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/senp.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/sev2.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/blz2.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/bgmn.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/zoom.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/tu_802E6EC4.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/wave.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/sen2.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/pnp2.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/mjgr.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/lcls.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/glbs.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/endm.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tkra.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/gen3.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/zomo.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/sdsm.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/stpn.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/gnef.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/chsw.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/agbw.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/elsk.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/foev.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/swdl.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tfl2.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/dmyk.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/tbgn.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/tbo2.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/gsck.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tu_802F5040.cpp"),
            Object(NonMatching, "Game/tu_803006E8.cpp"),
            Object(NonMatching, "Game/tu_80301CD0.cpp"),
            Object(NonMatching, "Game/tu_803099FC.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tu_8030AE84.cpp"),
            Object(NonMatching, "Game/tu_8030C058.cpp"),
            Object(NonMatching, "Game/tu_8030E9A0.cpp"),
            Object(NonMatching, "Game/tu_8030FD60.cpp"),
            Object(NonMatching, "Game/tu_80310DE8.cpp"),
            Object(NonMatching, "Game/tu_8031179C.cpp"),
            Object(NonMatching, "Game/tu_80312668.cpp"),
            Object(NonMatching, "Game/twtg.cpp", extra_cflags=["-common on"]),
            Object(Matching, "Game/tu_80316E34.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/ftgl.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/tu_80317EB8.cpp"),
            Object(NonMatching, "Game/tu_8031A210.cpp"),
            Object(NonMatching, "Game/tu_8031C050.cpp"),
            Object(NonMatching, "Game/tu_8031E144.cpp"),
            Object(NonMatching, "Game/tu_8031EF4C.cpp"),
            Object(NonMatching, "Game/tu_8031FD60.cpp"),
            Object(NonMatching, "Game/tu_80320374.cpp"),
            Object(NonMatching, "Game/tu_803239A0.cpp"),
            Object(NonMatching, "Game/tu_8032500C.cpp"),
            Object(NonMatching, "Game/tu_80326A90.cpp"),
            Object(NonMatching, "Game/tu_803276C4.cpp"),
            Object(NonMatching, "Game/tu_803287F0.cpp"),
            Object(NonMatching, "Game/tu_80328D6C.cpp"),
            Object(NonMatching, "Game/gnld.cpp", extra_cflags=["-common on"]),
            Object(NonMatching, "Game/rupy.cpp", extra_cflags=["-common on"]),
        ],
    },
    # EverydaySimpleDev/FSA-Decomp imports, slice e5 (0x8033E638-0x8045BD00)
    {
        "lib": "Game_esd_e5",
        "mw_version": "GC/2.6",
        "cflags": [
            *cflags_base,
            "-Cpp_exceptions on",
            "-use_lmw_stmw on",
            "-common on",
            "-lang=c++",
            "-fp fmadd",
            "-char signed",
            "-rostr",
            "-DMATCHING=1",
            "-i libs/PowerPC_EABI_Support/include",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "Game/tu_8032DF94.cpp"),
            Object(NonMatching, "Game/tu_8032F148.cpp"),
            Object(NonMatching, "Game/tu_80333958.cpp"),
            Object(NonMatching, "Game/tu_80334318.cpp"),
            Object(NonMatching, "Game/tu_80335A7C.cpp"),
            Object(NonMatching, "Game/tu_80336040.cpp"),
            Object(NonMatching, "Game/tu_803372D0.cpp"),
            Object(NonMatching, "Game/tu_80337650.cpp"),
            Object(NonMatching, "Game/tu_80338AE0.cpp"),
            Object(NonMatching, "Game/tu_803397C0.cpp"),
            Object(NonMatching, "Game/tu_8033C080.cpp"),
            Object(NonMatching, "Game/tu_8033C584.cpp"),
            Object(NonMatching, "Game/tu_8033CCE4.cpp"),
            Object(NonMatching, "Game/tu_8033E638.cpp"),
            Object(NonMatching, "Game/tu_8033F448.cpp"),
            Object(NonMatching, "Game/ltzr.cpp"),
            Object(NonMatching, "Game/tu_80340EC8.cpp"),
            Object(NonMatching, "Game/tu_80341CB0.cpp"),
            Object(NonMatching, "Game/tu_80343A70.cpp"),
            Object(NonMatching, "Game/tu_8034543C.cpp"),
            Object(NonMatching, "Game/tu_80346E24.cpp"),
            Object(NonMatching, "Game/tu_803481B8.cpp"),
            Object(NonMatching, "Game/tu_803489A4.cpp"),
            Object(NonMatching, "Game/tu_80349914.cpp"),
            Object(NonMatching, "Game/tu_8034AA40.cpp"),
            Object(NonMatching, "Game/tu_8034C950.cpp"),
            Object(NonMatching, "Game/tu_8034DFF0.cpp"),
            Object(NonMatching, "Game/tu_8034EDDC.cpp"),
            Object(NonMatching, "Game/tu_80351EC4.cpp"),
            Object(NonMatching, "Game/tu_8035280C.cpp"),
            Object(NonMatching, "Game/tu_803536C4.cpp"),
            Object(NonMatching, "Game/tu_80353E70.cpp"),
            Object(NonMatching, "Game/tu_80354D64.cpp"),
            Object(NonMatching, "Game/tu_803567AC.cpp"),
            Object(NonMatching, "Game/tu_80357DE8.cpp"),
            Object(NonMatching, "Game/tu_80358460.cpp"),
            Object(NonMatching, "Game/tu_8035B5F0.cpp"),
            Object(NonMatching, "Game/tu_8035C940.cpp"),
            Object(NonMatching, "Game/tu_8035DED8.cpp"),
            Object(NonMatching, "Game/tu_8035E8CC.cpp"),
            Object(NonMatching, "Game/tu_8035F360.cpp"),
            Object(NonMatching, "Game/tu_80362634.cpp"),
            Object(NonMatching, "Game/tu_8036766C.cpp"),
            Object(NonMatching, "Game/tu_80368198.cpp"),
            Object(NonMatching, "Game/tu_8036CB5C.cpp"),
            Object(Matching, "Game/lfgn.cpp"),
            Object(Matching, "Game/rins.cpp"),
            Object(NonMatching, "Game/tu_8036DD6C.cpp"),
            Object(NonMatching, "Game/tu_8036E544.cpp"),
            Object(NonMatching, "Game/tu_8036FB60.cpp"),
            Object(NonMatching, "Game/tu_80373138.cpp"),
            Object(NonMatching, "Game/tu_80373BD8.cpp"),
            Object(NonMatching, "Game/tu_80374788.cpp"),
            Object(NonMatching, "Game/tu_80375970.cpp"),
            Object(NonMatching, "Game/tu_80376FA0.cpp"),
            Object(NonMatching, "Game/tu_80378294.cpp"),
            Object(NonMatching, "Game/tu_80379078.cpp"),
            Object(NonMatching, "Game/tu_80379870.cpp"),
            Object(NonMatching, "Game/tu_80379F84.cpp"),
            Object(NonMatching, "Game/tu_8037ACC4.cpp"),
            Object(NonMatching, "Game/tu_8037D784.cpp"),
            Object(NonMatching, "Game/tu_8039003C.cpp"),
            Object(NonMatching, "Game/tu_803A3484.cpp"),
            Object(NonMatching, "Game/tu_803B7DCC.cpp"),
            Object(NonMatching, "Game/tu_803BACF8.cpp"),
            Object(NonMatching, "Game/tu_803BC6F0.cpp"),
            Object(NonMatching, "Game/tu_803D7098.cpp"),
            Object(NonMatching, "Game/tu_803DA6B4.cpp"),
            Object(NonMatching, "Game/tu_803DAC3C.cpp"),
            Object(NonMatching, "Game/tu_803E1668.cpp"),
            Object(NonMatching, "Game/tu_803F0A54.cpp"),
            Object(NonMatching, "Game/tu_80400DC4.cpp"),
            Object(NonMatching, "Game/tu_804023D0.cpp"),
            Object(NonMatching, "Game/tu_80418B64.cpp"),
            Object(NonMatching, "Game/tu_8042165C.cpp"),
            Object(NonMatching, "Game/tu_80432638.cpp"),
            Object(NonMatching, "Game/tu_80434370.cpp"),
            Object(NonMatching, "Game/tu_80437C10.cpp"),
            Object(NonMatching, "Game/tu_80438C68.cpp"),
            Object(NonMatching, "Game/tu_8043A0E8.cpp"),
            Object(NonMatching, "Game/tu_80440BF4.cpp"),
            Object(NonMatching, "Game/tu_80441318.cpp"),
            Object(NonMatching, "Game/tu_80441A1C.cpp"),
            Object(NonMatching, "Game/tu_80442C64.cpp"),
            Object(NonMatching, "Game/tu_804432DC.cpp"),
            Object(NonMatching, "Game/tu_80443B0C.cpp"),
            Object(NonMatching, "Game/tu_804455E0.cpp"),
            Object(NonMatching, "Game/tu_804465B8.cpp"),
            Object(NonMatching, "Game/tu_80447618.cpp"),
            Object(NonMatching, "Game/tu_80447FAC.cpp"),
            Object(NonMatching, "Game/tu_80448940.cpp"),
            Object(NonMatching, "Game/tu_8044998C.cpp"),
            Object(NonMatching, "Game/tu_8044A828.cpp"),
            Object(NonMatching, "Game/tu_8044B80C.cpp"),
            Object(NonMatching, "Game/tu_8044C028.cpp"),
            Object(NonMatching, "Game/tu_8044C7F0.cpp"),
            Object(NonMatching, "Game/tu_80453AF8.cpp"),
            Object(NonMatching, "Game/tu_80455CA4.cpp"),
            Object(NonMatching, "Game/tu_80457C08.cpp"),
            Object(NonMatching, "Game/tu_80457DFC.cpp"),
            Object(NonMatching, "Game/tu_8045A640.cpp"),
            Object(NonMatching, "Game/tu_8045B010.cpp"),
            Object(NonMatching, "Game/tu_8045B6F0.cpp"),
            Object(Matching, "Game/tu_8045ba84.cpp"),
            Object(Matching, "Game/ssmi.cpp"),
            Object(Matching, "Game/endr.cpp"),
            Object(Matching, "Game/ptmi.cpp"),
            Object(Matching, "Game/htmk.cpp"),
            Object(Matching, "Game/svgt.cpp"),
            Object(Matching, "Game/szsc.cpp"),
            Object(Matching, "Game/rsnp.cpp"),
            Object(Matching, "Game/tmi2.cpp"),
            Object(NonMatching, "Game/jiji.cpp"),
            Object(NonMatching, "Game/tu_8037e54c.cpp"),
            Object(NonMatching, "Game/bery.cpp"),
            Object(Matching, "Game/knbn.cpp"),
            Object(NonMatching, "Game/tu_80390818.cpp"),
            Object(NonMatching, "Game/scre.cpp"),
            Object(Matching, "Game/talk.cpp"),
            Object(NonMatching, "Game/tu_803944c8.cpp"),
            Object(NonMatching, "Game/tu_803a60e4.cpp"),
            Object(NonMatching, "Game/tu_803a85e4.cpp"),
            Object(NonMatching, "Game/tu_803a8dfc.cpp"),
            Object(Matching, "Game/tlk2.cpp"),
            Object(NonMatching, "Game/tu_803b8c74.cpp"),
            Object(NonMatching, "Game/tu_803b9940.cpp"),
            Object(NonMatching, "Game/tu_803d2c34.cpp"),
            Object(NonMatching, "Game/bfin.cpp"),
            Object(NonMatching, "Game/tngl.cpp"),
            Object(NonMatching, "Game/tu_803ff2c4.cpp"),
            Object(NonMatching, "Game/tu_80401848.cpp"),
            Object(NonMatching, "Game/tu_80403414.cpp"),
            Object(NonMatching, "Game/tu_80403d84.cpp"),
            Object(NonMatching, "Game/tu_80414f6c.cpp"),
            Object(NonMatching, "Game/tu_80427d2c.cpp"),
            Object(NonMatching, "Game/tu_8042e964.cpp"),
            Object(Matching, "Game/limt.cpp"),
            Object(Matching, "Game/tu_80442810.cpp"),
            Object(Matching, "Game/tu_80455930.cpp"),
        ],
    },
    JSystemLib(
        "j3d-loader",
        [
            Object(Matching, "JSystem/J3D/GraphLoader/J3DBinaryFormat.cpp"),
            Object(Matching, "JSystem/J3D/GraphLoader/J3DModelLoader.cpp"),
            Object(Matching, "JSystem/J3D/GraphLoader/J3DModelLoaderCalcSize.cpp"),
            Object(Matching, "JSystem/J3D/GraphLoader/J3DJointFactory.cpp"),
            Object(Matching, "JSystem/J3D/GraphLoader/J3DShapeFactory.cpp"),
            Object(Matching, "JSystem/J3D/GraphLoader/J3DModelSaver.cpp"),
        ],
    ),
    JSystemLib(
        "J3DGraphAnimator",
        [
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DAnimation.cpp"),
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DCluster.cpp"),
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DJoint.cpp"),
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DJointTree.cpp"),
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DMaterialAnm.cpp"),
            Object(NonMatching, "JSystem/J3D/GraphAnimator/J3DMaterialAttach.cpp"),
            Object(NonMatching, "JSystem/J3D/GraphAnimator/J3DModel.cpp"),
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DModelData.cpp"),
            Object(NonMatching, "JSystem/J3D/GraphAnimator/J3DMtxBuffer.cpp"),
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DShapeTable.cpp"),
            Object(Matching, "JSystem/J3D/GraphAnimator/J3DSkinDeform.cpp"),
        ],
    ),
    JSystemLib(
        "j2d-b",
        [
            Object(Matching, "JSystem/J2DGraph/J2DPicture.cpp"),
            Object(NonMatching, "JSystem/J2DGraph/J2DPictureEx.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DPrint.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DScreen.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DTevs.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DTextBox.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DTextBoxEx.cpp"),
            Object(NonMatching, "JSystem/J2DGraph/J2DWindow.cpp"),
            Object(Matching, "JSystem/J2DGraph/J2DWindowEx.cpp"),
        ],
    ),
    GameLib(
        "Game",
        [
            Object(Matching, "Game/actors/BOTS.cpp"),
            Object(Matching, "Game/actors/DWAP.cpp"),
            Object(Matching, "Game/actors/GFBS.cpp"),
            Object(Matching, "Game/actors/STGN.cpp"),
            Object(Matching, "Game/actors/TJIJ.cpp"),
        ],
    ),
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
    ProgressCategory("jsys", "JSystem Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
