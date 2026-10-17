// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801cac6c-0x801cad94 (2 functions). split_file divides it into the game's real files.

#include "types.h"

extern void (*lbl_802FF8C8)(void);
extern "C" s32 fn_801E6510(void*, void*, s32);
extern "C" void fn_801CAD64(void)
{
    if (lbl_802FF8C8 != 0) {
        lbl_802FF8C8();
    }
}
