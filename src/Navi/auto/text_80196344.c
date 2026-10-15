#include "types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80196344-0x801a537c (574 functions). split_file divides it into the game's real files.

extern void* lbl_80299E68[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80196388(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299E68;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029A150[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80198CCC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A150;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

