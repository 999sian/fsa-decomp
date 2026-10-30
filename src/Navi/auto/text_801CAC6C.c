// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801cac6c-0x801cad94 (2 functions). split_file divides it into the game's real files.

#include "types.h"

extern void (*lbl_802FF8C8)(void);
extern "C" s32 fn_801E6510(void*, void*, s32);
extern "C" BOOL fn_801CAC6C(u8* param1, u8* param2)
{
    if ((s8)param1[0] != 0 && (s8)param2[0] != 0 && fn_801E6510(&param1[0], &param2[0], 4) != 0) {
        return 0;
    }
    if ((s8)param1[4] == 0 || (s8)param2[4] == 0 || fn_801E6510(&param1[4], &param2[4], 2) != 0) {
        return 0;
    }
    if (param1[6] != 0xff && param2[6] != 0xff && param1[6] != param2[6]) {
        return 0;
    }
    if (param1[7] != 0xff && param2[7] != 0xff && param1[7] != param2[7]) {
        return 0;
    }
    return 1;
}

extern "C" void fn_801CAD64(void)
{
    if (lbl_802FF8C8 != 0) {
        lbl_802FF8C8();
    }
}
