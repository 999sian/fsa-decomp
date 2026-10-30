#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014725c-0x801472a0 (1 functions). split_file divides it into the game's real files.

extern "C" unsigned int fn_8014DDC0(void);
extern "C" s32 fn_8014725C(s32 param_1) {
    s32 ret;
    if (fn_8014DDC0() == 0xffffffff) {
        ret = -1;
    } else {
        ret = param_1;
    }
    return ret;
}
