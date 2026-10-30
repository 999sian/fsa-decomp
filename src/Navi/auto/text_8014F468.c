#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014f468-0x8014f4ac (1 functions). split_file divides it into the game's real files.

extern "C" s32 fn_8014F314(u8 *param_1, u32 param_2);
extern "C" s32 fn_8014F468(u8 *param_1) {
    s32 state = *param_1;
    if (state < 2) {
        if (state >= 0) {
            return fn_8014F314(param_1, *(u32 *)(param_1 + 0x20));
        }
    }
    return 0;
}
