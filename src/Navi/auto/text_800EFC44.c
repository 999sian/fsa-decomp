#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800efc44-0x800f2894 (21 functions). split_file divides it into the game's real files.

extern void* lbl_80222428[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_8028C4BC[];
extern "C" u8 fn_800F2750(u8* param_1, s32 param_2) {
    s32 v = *(s32*)(param_1 + 0xd8);
    s32 r = v % 5;
    s32 t = v + (param_2 - r);
    if (param_2 < r) {
        t += 5;
    }
    return t;
}

extern "C" void* fn_800F2838(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028C4BC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
