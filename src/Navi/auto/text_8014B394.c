#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014b394-0x8014b3f8 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80157210(void *param_1, u32 param_2, s16 param_3);
extern u32 lbl_802D5364[];
extern "C" void fn_8014B394(void *param_1, u32 param_2, u32 param_3, u32 param_4)
{
    u32 idx;

    if (param_2 != 0) {
        fn_80157210(param_1, param_3, (s16)param_4);
        return;
    }
    idx = param_3 & 0x1f;
    if (idx < 0x10) {
        *(u32 *)((u8 *)param_1 + 0xac + idx * 4) = param_4;
    } else {
        lbl_802D5364[idx - 16] = param_4;
    }
}
