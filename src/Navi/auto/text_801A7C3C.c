#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801a7c3c-0x801ba678 (389 functions). split_file divides it into the game's real files.

extern void* lbl_8029B220[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_801A8574(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B220;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029B5F8[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_801AE580(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B5F8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

