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


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_base,
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
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "progress_category": "sdk",  # str | List[str]
        "objects": [
            Object(NonMatching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
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
            Object(Matching, "JSystem/JKernel/JKRMemArchive.cpp"),
        ],
    ),
    JSystemLib(
        "JSupport",
        [
            Object(Matching, "JSystem/JSupport/JSUFileStream.cpp"),
            Object(Matching, "JSystem/JSupport/JSUList.cpp"),
            Object(Matching, "JSystem/JSupport/JSUMemoryStream.cpp"),
        ],
    ),
    JSystemLib(
        "JUtility",
        [
            Object(Matching, "JSystem/JUtility/JUTAssert.cpp"),
            Object(Matching, "JSystem/JUtility/JUTConsole.cpp"),
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
            "-common off",
            "-RTTI on",
            "-inline auto",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "game/NZMI_800F3C10.cpp"),
            Object(NonMatching, "game/IWAG_800F46C0.cpp"),
            Object(NonMatching, "game/OIWA_800F4C70.cpp"),
            Object(NonMatching, "game/LPLK_800F6820.cpp"),
            Object(NonMatching, "game/WRTC_800F7FCC.cpp"),
            Object(NonMatching, "game/RAIL_800FD438.cpp"),
            Object(NonMatching, "game/tu_800FE8C0.cpp"),
            Object(NonMatching, "game/GSYA_800FF060.cpp"),
            Object(NonMatching, "game/MGYA_8010089C.cpp"),
            Object(NonMatching, "game/ANHO_80102278.cpp"),
            Object(NonMatching, "game/TWEV_80103348.cpp"),
            Object(NonMatching, "game/LOSW_80104C3C.cpp"),
            Object(NonMatching, "game/CLOD_80105368.cpp"),
            Object(NonMatching, "game/ARSH_80105DD4.cpp"),
            Object(NonMatching, "game/WLFT_80106040.cpp"),
            Object(NonMatching, "game/WIND_80106ADC.cpp"),
            Object(NonMatching, "game/CNON_80107360.cpp"),
            Object(NonMatching, "game/DEAL_80108414.cpp"),
            Object(NonMatching, "game/SHTM_80108A6C.cpp"),
            Object(NonMatching, "game/ICCL_8010B284.cpp"),
            Object(NonMatching, "game/DBMS_8010DA6C.cpp"),
            Object(NonMatching, "game/tu_8010DF44.cpp"),
            Object(NonMatching, "game/tu_8011A0F8.cpp"),
            Object(NonMatching, "game/BARI_8011EEEC.cpp"),
            Object(NonMatching, "game/RNBW_80129B0C.cpp"),
            Object(NonMatching, "game/BTBZ_8012CF5C.cpp"),
            Object(NonMatching, "game/IFCK_8012F008.cpp"),
            Object(NonMatching, "game/WPCN_80130FAC.cpp"),
            Object(NonMatching, "game/tu_80134C04.cpp"),
            Object(NonMatching, "game/tu_8013AAD4.cpp"),
            Object(NonMatching, "game/tu_8013C5C8.cpp"),
            Object(NonMatching, "game/OKTA_8013F9A8.cpp"),
            Object(NonMatching, "game/BZBR_80144134.cpp"),
            Object(NonMatching, "game/DBRK_8014529C.cpp"),
            Object(NonMatching, "game/TKTA_801549B0.cpp"),
            Object(NonMatching, "game/BOYO_8015B98C.cpp"),
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
            "-common off",
            "-RTTI on",
            "-char signed",
            "-Cpp_exceptions on",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "game/keth.cpp"),
            Object(NonMatching, "game/flme.cpp"),
            Object(NonMatching, "game/ezry.cpp"),
            Object(NonMatching, "game/arrw.cpp"),
            Object(NonMatching, "game/stal.cpp"),
            Object(NonMatching, "game/wizr.cpp"),
            Object(NonMatching, "game/rdvr.cpp"),
            Object(NonMatching, "game/gdmn.cpp"),
            Object(NonMatching, "game/fagn.cpp"),
            Object(NonMatching, "game/wnwn.cpp"),
            Object(NonMatching, "game/fgn2.cpp"),
            Object(NonMatching, "game/bph2.cpp"),
            Object(NonMatching, "game/dgt2.cpp"),
            Object(NonMatching, "game/gnon.cpp"),
            Object(NonMatching, "game/tu_80197070.cpp"),
            Object(NonMatching, "game/tenn.cpp"),
            Object(NonMatching, "game/enbz.cpp"),
            Object(NonMatching, "game/tu_801a3c50.cpp"),
            Object(NonMatching, "game/ryya.cpp"),
            Object(NonMatching, "game/hbb2.cpp"),
            Object(NonMatching, "game/ttat.cpp"),
            Object(NonMatching, "game/ddgo.cpp"),
            Object(NonMatching, "game/okam.cpp"),
            Object(NonMatching, "game/egol.cpp"),
        ],
    },
    # EverydaySimpleDev/FSA-Decomp harvest, slice e2 (.text 0x801B0A00-0x801EE24C)
    {
        "lib": "Game_esd_e2",
        "mw_version": "GC/2.6",
        "cflags": [
            "-nodefaults", "-proc gekko", "-align powerpc", "-enum int",
            "-fp hardware", "-Cpp_exceptions off", "-use_lmw_stmw on", "-O4,p",
            "-inline auto", '-pragma "cats off"', '-pragma "warn_notinlined off"',
            "-maxerrors 1", "-nosyspath", "-RTTI on", "-char signed",
            "-fp_contract on", "-str reuse,pool,readonly", "-common off",
            "-multibyte", "-i include", f"-i build/{config.version}/include",
            f"-DVERSION={version_num}",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "game/zld3_801B0A00.cpp"),
            Object(NonMatching, "game/tu_801B27DC.cpp"),
            Object(NonMatching, "game/zdco_801B3F60.cpp"),
            Object(NonMatching, "game/tlwp_801B4D0C.cpp"),
            Object(NonMatching, "game/safu_801B6634.cpp"),
            Object(NonMatching, "game/gewp_801B6C50.cpp"),
            Object(NonMatching, "game/rope_801B7784.cpp"),
            Object(NonMatching, "game/pame_801B80C0.cpp"),
            Object(NonMatching, "game/mira_801B9730.cpp"),
            Object(NonMatching, "game/znra_801BA65C.cpp"),
            Object(NonMatching, "game/fall_801BB618.cpp"),
            Object(NonMatching, "game/ezmr_801BD108.cpp"),
            Object(NonMatching, "game/ezob_801BD8C0.cpp"),
            Object(NonMatching, "game/bmst_801BDE5C.cpp"),
            Object(NonMatching, "game/lnbm_801BEDBC.cpp"),
            Object(NonMatching, "game/tndr_801BF810.cpp"),
            Object(NonMatching, "game/tu_801C0D70.cpp"),
            Object(NonMatching, "game/slk2_801C26D8.cpp"),
            Object(NonMatching, "game/tu_801C9AF8.cpp"),
            Object(NonMatching, "game/tu_801CB270.cpp"),
            Object(NonMatching, "game/tu_801CDC8C.cpp"),
            Object(NonMatching, "game/tu_801D1C18.cpp"),
            Object(NonMatching, "game/tu_801D2C60.cpp"),
            Object(NonMatching, "game/bogf_801D46FC.cpp"),
            Object(NonMatching, "game/tu_801D6CEC.cpp"),
            Object(NonMatching, "game/bgbl_801D7AFC.cpp"),
            Object(NonMatching, "game/tu_801D8400.cpp"),
            Object(NonMatching, "game/tu_801DAC6C.cpp"),
            Object(NonMatching, "game/ichl_801DB18C.cpp"),
            Object(NonMatching, "game/boit_801DC264.cpp"),
            Object(NonMatching, "game/boib_801DCC98.cpp"),
            Object(NonMatching, "game/thnk_801DE714.cpp"),
            Object(NonMatching, "game/tinb_801E31C0.cpp"),
            Object(NonMatching, "game/ipot_801E6D48.cpp"),
            Object(NonMatching, "game/fspo_801E7BF4.cpp"),
            Object(NonMatching, "game/fsob_801E801C.cpp"),
            Object(NonMatching, "game/hrmn_801EBC84.cpp"),
            Object(NonMatching, "game/tu_801ED3DC.cpp"),
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
            "-common off",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "game/tu_801F6058.cpp"),
            Object(NonMatching, "game/tu_801F68E0.cpp"),
            Object(NonMatching, "game/tu_801F9484.cpp"),
            Object(NonMatching, "game/tzok.cpp"),
            Object(NonMatching, "game/tu_80207548.cpp"),
            Object(NonMatching, "game/slmn.cpp"),
            Object(NonMatching, "game/fobr.cpp"),
            Object(NonMatching, "game/zasl.cpp"),
            Object(NonMatching, "game/tu_8020D58C.cpp"),
            Object(NonMatching, "game/flor.cpp"),
            Object(NonMatching, "game/ibbm.cpp"),
            Object(NonMatching, "game/rusa.cpp"),
            Object(NonMatching, "game/tu_80212AC0.cpp"),
            Object(NonMatching, "game/arij.cpp"),
            Object(NonMatching, "game/slef.cpp"),
            Object(NonMatching, "game/tu_80214244.cpp"),
            Object(NonMatching, "game/tu_802144F0.cpp"),
            Object(NonMatching, "game/tu_802153A8.cpp"),
            Object(NonMatching, "game/tu_802157B8.cpp"),
            Object(NonMatching, "game/tu_80215A94.cpp"),
            Object(NonMatching, "game/tu_802188B0.cpp"),
            Object(NonMatching, "game/kepo.cpp"),
            Object(NonMatching, "game/tu_8021A570.cpp"),
            Object(NonMatching, "game/tu_8021B904.cpp"),
            Object(NonMatching, "game/tu_8021BFA8.cpp"),
            Object(NonMatching, "game/tu_8021CDE4.cpp"),
            Object(NonMatching, "game/ezge.cpp"),
            Object(NonMatching, "game/navi.cpp"),
            Object(NonMatching, "game/tu_8021F064.cpp"),
            Object(NonMatching, "game/fbal.cpp"),
            Object(NonMatching, "game/znlj.cpp"),
            Object(NonMatching, "game/tu_80220F54.cpp"),
            Object(NonMatching, "game/tu_80221B44.cpp"),
            Object(NonMatching, "game/zsla.cpp"),
            Object(NonMatching, "game/tu_80222CC4.cpp"),
            Object(NonMatching, "game/tu_802233A4.cpp"),
            Object(NonMatching, "game/tu_8022461C.cpp"),
            Object(NonMatching, "game/tu_80234E30.cpp"),
            Object(NonMatching, "game/tu_8023FBF0.cpp"),
            Object(NonMatching, "game/tu_802684A4.cpp"),
            Object(NonMatching, "game/tu_8026FC20.cpp"),
            Object(NonMatching, "game/swt4.cpp"),
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
            "-common off",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "game/fire.cpp"),
            Object(NonMatching, "game/key0.cpp"),
            Object(NonMatching, "game/door.cpp"),
            Object(NonMatching, "game/onof.cpp"),
            Object(NonMatching, "game/yasi.cpp"),
            Object(NonMatching, "game/fgve.cpp"),
            Object(NonMatching, "game/vwmd.cpp"),
            Object(NonMatching, "game/urac.cpp"),
            Object(NonMatching, "game/prtc.cpp"),
            Object(NonMatching, "game/offs.cpp"),
            Object(NonMatching, "game/tu_802E2074.cpp"),
            Object(NonMatching, "game/gnl2.cpp"),
            Object(NonMatching, "game/senp.cpp"),
            Object(NonMatching, "game/sev2.cpp"),
            Object(NonMatching, "game/blz2.cpp"),
            Object(NonMatching, "game/bgmn.cpp"),
            Object(NonMatching, "game/zoom.cpp"),
            Object(NonMatching, "game/tu_802E6EC4.cpp"),
            Object(NonMatching, "game/wave.cpp"),
            Object(NonMatching, "game/sen2.cpp"),
            Object(NonMatching, "game/pnp2.cpp"),
            Object(NonMatching, "game/mjgr.cpp"),
            Object(NonMatching, "game/lcls.cpp"),
            Object(NonMatching, "game/glbs.cpp"),
            Object(NonMatching, "game/endm.cpp"),
            Object(NonMatching, "game/tkra.cpp"),
            Object(NonMatching, "game/gen3.cpp"),
            Object(NonMatching, "game/zomo.cpp"),
            Object(NonMatching, "game/sdsm.cpp"),
            Object(NonMatching, "game/stpn.cpp"),
            Object(NonMatching, "game/gnef.cpp"),
            Object(NonMatching, "game/chsw.cpp"),
            Object(NonMatching, "game/agbw.cpp"),
            Object(NonMatching, "game/elsk.cpp"),
            Object(NonMatching, "game/foev.cpp"),
            Object(NonMatching, "game/swdl.cpp"),
            Object(NonMatching, "game/tfl2.cpp"),
            Object(NonMatching, "game/dmyk.cpp"),
            Object(NonMatching, "game/tbgn.cpp"),
            Object(NonMatching, "game/tbo2.cpp"),
            Object(NonMatching, "game/gsck.cpp"),
            Object(NonMatching, "game/tu_80301CD0.cpp"),
            Object(NonMatching, "game/tu_803099FC.cpp"),
            Object(NonMatching, "game/twtg.cpp"),
            Object(NonMatching, "game/tu_80316E34.cpp"),
            Object(NonMatching, "game/ftgl.cpp"),
            Object(NonMatching, "game/gnld.cpp"),
            Object(NonMatching, "game/rupy.cpp"),
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
            "-O4,p",
            "-inline auto",
            "-RTTI on",
            "-str reuse,pool,readonly",
            "-common off",
        ],
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "game/ltzr.cpp"),
            Object(NonMatching, "game/jiji.cpp"),
            Object(NonMatching, "game/tu_8037e54c.cpp"),
            Object(NonMatching, "game/bery.cpp"),
            Object(NonMatching, "game/knbn.cpp"),
            Object(NonMatching, "game/tu_80390818.cpp"),
            Object(NonMatching, "game/scre.cpp"),
            Object(NonMatching, "game/talk.cpp"),
            Object(NonMatching, "game/tu_803944c8.cpp"),
            Object(NonMatching, "game/tu_803a60e4.cpp"),
            Object(NonMatching, "game/tu_803a85e4.cpp"),
            Object(NonMatching, "game/tu_803a8dfc.cpp"),
            Object(NonMatching, "game/tlk2.cpp"),
            Object(NonMatching, "game/tu_803b8c74.cpp"),
            Object(NonMatching, "game/tu_803b9940.cpp"),
            Object(NonMatching, "game/tu_803d2c34.cpp"),
            Object(NonMatching, "game/bfin.cpp"),
            Object(NonMatching, "game/tngl.cpp"),
            Object(NonMatching, "game/tu_803ff2c4.cpp"),
            Object(NonMatching, "game/tu_80401848.cpp"),
            Object(NonMatching, "game/tu_80403414.cpp"),
            Object(NonMatching, "game/tu_80403d84.cpp"),
            Object(NonMatching, "game/tu_80414f6c.cpp"),
            Object(NonMatching, "game/tu_80427d2c.cpp"),
            Object(NonMatching, "game/tu_8042e964.cpp"),
            Object(NonMatching, "game/limt.cpp"),
            Object(NonMatching, "game/tu_80442810.cpp"),
            Object(NonMatching, "game/tu_80455930.cpp"),
        ],
    },
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
