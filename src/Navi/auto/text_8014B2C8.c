#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014b2c8-0x8014b32c (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_80157170(void *param_1, u32 param_2);
extern u32 lbl_802D5364[];
extern "C" u32 fn_8014B2C8(void *param_1, u32 param_2, u32 param_3)
{
    if (param_2 != 0) {
        return fn_80157170(param_1, param_3) & 0xffff;
    }
    if ((param_3 & 0x1f) < 0x10) {
        return ((u32 *)param_1)[43 + (param_3 & 0x1f)];
    }
    return lbl_802D5364[(param_3 & 0x1f) - 16];
}
