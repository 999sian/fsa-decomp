#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bf474-0x801c0018 (19 functions). split_file divides it into the game's real files.

extern u8 Scb_802F6CC0[];
extern "C" void fn_801BF7E0(u32 param_1, u32 param_2);
extern "C" BOOL OSDisableInterrupts(void);
extern "C" BOOL OSRestoreInterrupts(BOOL level);
extern "C" u32 __OSSyncSram(void) {
    return *(u32*)(Scb_802F6CC0 + 0x4c);
}
