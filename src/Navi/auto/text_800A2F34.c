#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800a2f34-0x800a4f9c (25 functions). split_file divides it into the game's real files.

extern void* lbl_80286DC8[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800A4F54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286DC8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
