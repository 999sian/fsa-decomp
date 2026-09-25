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
    "G4SE01",  # 0
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


config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    DolphinLib(
        "base",
        [
            Object(NonMatching, "dolphin/base/PPCArch.c"),
        ],
    ),
    DolphinLib(
        "db",
        [
            Object(NonMatching, "dolphin/db/db.c"),
        ],
    ),
    DolphinLib(
        "os",
        [
            Object(NonMatching, "dolphin/os/OS.c"),
            Object(NonMatching, "dolphin/os/OSAlarm.c"),
            Object(NonMatching, "dolphin/os/OSAlloc.c"),
            Object(NonMatching, "dolphin/os/OSArena.c"),
            Object(NonMatching, "dolphin/os/OSAudioSystem.c"),
            Object(NonMatching, "dolphin/os/OSCache.c"),
            Object(NonMatching, "dolphin/os/OSContext.c"),
            Object(NonMatching, "dolphin/os/OSError.c"),
            Object(NonMatching, "dolphin/os/OSFont.c"),
            Object(NonMatching, "dolphin/os/OSInterrupt.c"),
            Object(NonMatching, "dolphin/os/OSLink.c"),
            Object(NonMatching, "dolphin/os/OSMessage.c"),
            Object(NonMatching, "dolphin/os/OSMemory.c"),
            Object(NonMatching, "dolphin/os/OSMutex.c"),
            Object(NonMatching, "dolphin/os/OSReboot.c"),
            Object(NonMatching, "dolphin/os/OSReset.c"),
            Object(NonMatching, "dolphin/os/OSResetSW.c"),
            Object(NonMatching, "dolphin/os/OSRtc.c"),
            Object(NonMatching, "dolphin/os/OSSync.c"),
            Object(NonMatching, "dolphin/os/OSThread.c"),
            Object(NonMatching, "dolphin/os/OSTime.c"),
            Object(NonMatching, "dolphin/os/__start.c"),
            Object(NonMatching, "dolphin/os/__ppc_eabi_init.cpp"),
        ],
    ),
    DolphinLib(
        "mtx",
        [
            Object(NonMatching, "dolphin/mtx/mtx.c"),
            Object(NonMatching, "dolphin/mtx/mtxvec.c"),
            Object(NonMatching, "dolphin/mtx/mtx44.c"),
            Object(NonMatching, "dolphin/mtx/vec.c"),
        ],
    ),
    DolphinLib(
        "dvd",
        [
            Object(NonMatching, "dolphin/dvd/dvdlow.c"),
            Object(NonMatching, "dolphin/dvd/dvdfs.c"),
            Object(NonMatching, "dolphin/dvd/dvd.c"),
            Object(NonMatching, "dolphin/dvd/dvdqueue.c"),
            Object(NonMatching, "dolphin/dvd/dvderror.c"),
            Object(NonMatching, "dolphin/dvd/dvdidutils.c"),
            Object(NonMatching, "dolphin/dvd/dvdFatal.c"),
            Object(NonMatching, "dolphin/dvd/fstload.c"),
        ],
    ),
    DolphinLib(
        "vi",
        [
            Object(NonMatching, "dolphin/vi/vi.c"),
        ],
    ),
    DolphinLib(
        "pad",
        [
            Object(NonMatching, "dolphin/pad/Padclamp.c"),
            Object(NonMatching, "dolphin/pad/Pad.c"),
        ],
    ),
    DolphinLib(
        "ai",
        [
            Object(NonMatching, "dolphin/ai/ai.c"),
        ],
    ),
    DolphinLib(
        "ar",
        [
            Object(NonMatching, "dolphin/ar/ar.c"),
            Object(NonMatching, "dolphin/ar/arq.c"),
        ],
    ),
    DolphinLib(
        "dsp",
        [
            Object(NonMatching, "dolphin/dsp/dsp.c"),
            Object(NonMatching, "dolphin/dsp/dsp_debug.c"),
            Object(NonMatching, "dolphin/dsp/dsp_task.c"),
        ],
    ),
    DolphinLib(
        "card",
        [
            Object(NonMatching, "dolphin/card/CARDBios.c"),
            Object(NonMatching, "dolphin/card/CARDUnlock.c"),
            Object(NonMatching, "dolphin/card/CARDRdwr.c"),
            Object(NonMatching, "dolphin/card/CARDBlock.c"),
            Object(NonMatching, "dolphin/card/CARDDir.c"),
            Object(NonMatching, "dolphin/card/CARDCheck.c"),
            Object(NonMatching, "dolphin/card/CARDMount.c"),
            Object(NonMatching, "dolphin/card/CARDFormat.c"),
            Object(NonMatching, "dolphin/card/CARDOpen.c"),
            Object(NonMatching, "dolphin/card/CARDCreate.c"),
            Object(NonMatching, "dolphin/card/CARDRead.c"),
            Object(NonMatching, "dolphin/card/CARDWrite.c"),
            Object(NonMatching, "dolphin/card/CARDStat.c"),
            Object(NonMatching, "dolphin/card/CARDNet.c"),
        ],
    ),
    DolphinLib(
        "gx",
        [
            Object(NonMatching, "dolphin/gx/GXInit.c"),
            Object(NonMatching, "dolphin/gx/GXFifo.c"),
            Object(NonMatching, "dolphin/gx/GXAttr.c"),
            Object(NonMatching, "dolphin/gx/GXMisc.c"),
            Object(NonMatching, "dolphin/gx/GXGeometry.c"),
            Object(NonMatching, "dolphin/gx/GXFrameBuf.c"),
            Object(NonMatching, "dolphin/gx/GXLight.c"),
            Object(NonMatching, "dolphin/gx/GXTexture.c"),
            Object(NonMatching, "dolphin/gx/GXBump.c"),
            Object(NonMatching, "dolphin/gx/GXTev.c"),
            Object(NonMatching, "dolphin/gx/GXPixel.c"),
            Object(NonMatching, "dolphin/gx/GXDraw.c"),
            Object(NonMatching, "dolphin/gx/GXDisplayList.c"),
            Object(NonMatching, "dolphin/gx/GXTransform.c"),
            Object(NonMatching, "dolphin/gx/GXPerf.c"),
        ],
    ),
    SdkLib(
        "TRK_MINNOW_DOLPHIN",
        "GC/2.6",
        [*cflags_sdk_runtime, "-inline deferred", "-sdata 0", "-sdata2 0"],
        [
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mainloop.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/nubevent.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/nubinit.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/msg.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/msgbuf.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/serpoll.c", extra_cflags=["-sdata 8"]),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/usr_put.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/dispatch.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/msghndlr.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/support.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mutex_TRK.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/notify.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/flush_cache.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mem_TRK.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/targimpl.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/targsupp.s"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mpc_7xx_603e.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/__exception.s"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/dolphin_trk.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/main_TRK.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/dolphin_trk_glue.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/targcont.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/target_options.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mslsupp.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/UDP_Stubs.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/ddh/main.c", extra_cflags=["-sdata 8"]),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/CircleBuffer.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/gdev/main.c", extra_cflags=["-sdata 8"]),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/MWTrace.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/MWCriticalSection_gc.cpp"),
        ],
    ),
    SdkLib(
        "Runtime.PPCEABI.H",
        "GC/2.6",
        [*cflags_sdk_runtime, "-inline deferred"],
        [
            Object(NonMatching, "Runtime.PPCEABI.H/__mem.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/__va_arg.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/NMWException.cp", extra_cflags=["-Cpp_exceptions on"]),
            Object(NonMatching, "Runtime.PPCEABI.H/ptmf.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/runtime.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
            Object(NonMatching, "Runtime.PPCEABI.H/Gecko_ExceptionPPC.cp", extra_cflags=["-Cpp_exceptions on"]),
            Object(NonMatching, "Runtime.PPCEABI.H/GCN_mem_alloc.c"),
        ],
    ),
    SdkLib(
        "MSL_C.PPCEABI.bare.H",
        "GC/2.6",
        [*cflags_sdk_runtime, "-inline deferred"],
        [
            Object(NonMatching, "MSL_C/PPC_EABI/abort_exit.c"),
            Object(NonMatching, "MSL_C/MSL_Common/alloc.c"),
            Object(NonMatching, "MSL_C/MSL_Common/errno.c"),
            Object(NonMatching, "MSL_C/MSL_Common/ansi_files.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/ansi_fp.c", extra_cflags=["-str pool"]),
            Object(NonMatching, "MSL_C/MSL_Common/arith.c"),
            Object(NonMatching, "MSL_C/MSL_Common/buffer_io.c"),
            Object(NonMatching, "MSL_C/PPC_EABI/critical_regions.gamecube.c"),
            Object(NonMatching, "MSL_C/MSL_Common/ctype.c"),
            Object(NonMatching, "MSL_C/MSL_Common/locale.c", extra_cflags=["-str pool"]),
            Object(NonMatching, "MSL_C/MSL_Common/direct_io.c"),
            Object(NonMatching, "MSL_C/MSL_Common/file_io.c"),
            Object(NonMatching, "MSL_C/MSL_Common/FILE_POS.C"),
            Object(NonMatching, "MSL_C/MSL_Common/mbstring.c", extra_cflags=["-inline noauto,deferred"]),
            Object(NonMatching, "MSL_C/MSL_Common/mem.c"),
            Object(NonMatching, "MSL_C/MSL_Common/mem_funcs.c"),
            Object(NonMatching, "MSL_C/MSL_Common/misc_io.c"),
            Object(NonMatching, "MSL_C/MSL_Common/printf.c", extra_cflags=["-str pool"]),
            Object(NonMatching, "MSL_C/MSL_Common/float.c"),
            Object(NonMatching, "MSL_C/MSL_Common/scanf.c"),
            Object(NonMatching, "MSL_C/MSL_Common/string.c"),
            Object(NonMatching, "MSL_C/MSL_Common/strtoul.c"),
            Object(NonMatching, "MSL_C/MSL_Common/wchar_io.c"),
            Object(NonMatching, "MSL_C/PPC_EABI/uart_console_io_gcn.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_asin.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_atan2.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_rem_pio2.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/k_cos.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/k_rem_pio2.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/k_sin.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_atan.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ceil.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_copysign.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_cos.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_floor.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_frexp.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ldexp.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_modf.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/s_sin.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/w_asin.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/w_atan2.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/e_sqrt.c"),
            Object(NonMatching, "MSL_C/PPC_EABI/math_ppc.c"),
            Object(NonMatching, "MSL_C/MSL_Common_Embedded/Math/Double_precision/w_sqrt.c"),
        ],
    ),
    DolphinLib(
        "amcstubs",
        [
            Object(NonMatching, "dolphin/amcstubs/AmcExi2Stubs.c"),
        ],
    ),
    DolphinLib(
        "odenotstub",
        [
            Object(NonMatching, "dolphin/odenotstub/odenotstub.c"),
        ],
    ),
    DolphinLib(
        "OdemuExi2",
        [
            Object(NonMatching, "dolphin/OdemuExi2/DebuggerDriver.c"),
        ],
    ),
    DolphinLib(
        "gd",
        [
            Object(NonMatching, "dolphin/gd/GDBase.c"),
            Object(NonMatching, "dolphin/gd/GDGeometry.c"),
        ],
    ),
    DolphinLib(
        "exi",
        [
            Object(NonMatching, "dolphin/exi/EXIBios.c"),
            Object(NonMatching, "dolphin/exi/EXIUart.c"),
        ],
    ),
    DolphinLib(
        "si",
        [
            Object(NonMatching, "dolphin/si/SIBios.c"),
            Object(NonMatching, "dolphin/si/SISamplingRate.c"),
        ],
    ),
    DolphinLib(
        "gba",
        [
            Object(NonMatching, "dolphin/gba/GBA.c"),
            Object(NonMatching, "dolphin/gba/GBAJoyBoot.c"),
            Object(NonMatching, "dolphin/gba/GBARead.c"),
            Object(NonMatching, "dolphin/gba/GBAWrite.c"),
            Object(NonMatching, "dolphin/gba/GBAXfer.c"),
            Object(NonMatching, "dolphin/gba/GBAKey.c"),
        ],
    ),
    JSystemLib(
        "JKernel",
        [
            Object(Matching, "JSystem/JKernel/JKRDisposer.cpp"),
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
