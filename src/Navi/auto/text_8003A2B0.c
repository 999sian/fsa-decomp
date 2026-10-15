#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8003a2b0-0x8003a908 (8 functions). split_file divides it into the game's real files.

extern void* lbl_80246388[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8003A680(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80246388;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802463B0[];
extern "C" void* fn_8003A6C8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802463B0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

