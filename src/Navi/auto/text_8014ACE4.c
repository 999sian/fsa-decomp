#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014ace4-0x8014ad64 (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_8014999C(u16 a);
extern "C" u32 fn_8014ACE4(u32 param_1, u16 param_2) {
    u8* base;
    u32 idx;
    u32 lo;
    u32 frac;
    u32 pad[2];

    if (param_2 != 0xffff) {
        base = (u8*)fn_8014999C(param_2);
        if (base != NULL) {
            idx = param_1 >> 16;
            frac = param_1 & 0xffff;
            if (idx < 0x7f) {
                lo = base[idx];
                return frac * (base[idx + 1] - lo) + (lo << 16);
            }
            return base[idx] << 16;
        }
    }
    return param_1;
}
