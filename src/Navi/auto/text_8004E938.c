#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004e938-0x8004e9f4 (2 functions). split_file divides it into the game's real files.

extern void* lbl_80247270[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004E938(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247270;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247244[];
extern void* lbl_80222428[];
extern "C" void* fn_8004E980(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247244;
        if ((s32)ptr + 0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80247270;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

