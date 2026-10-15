#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011f23c-0x80135cf8 (427 functions). split_file divides it into the game's real files.

extern void* lbl_80290ACC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80120B20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290ACC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80290F9C[];
extern "C" void* fn_8012F204(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290F9C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247020[];
extern "C" void* fn_801303BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247020;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

