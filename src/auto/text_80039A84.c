#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8045D398[];
extern void *lbl_8053A398;
extern "C" s32 fn_80039A84(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 *param_5)
{
    if (param_2 < 0) {
        return 0;
    }
    lbl_8053A398 = lbl_8045D398;
    param_5[6] = param_2;
    param_5[8] = 1;
    param_5[7] = (s32)&lbl_8053A398;
    return 1;
}

extern "C" u32 fn_80039B18(void)
{
    return 0x564F4943;
}
