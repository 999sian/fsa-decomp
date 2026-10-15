#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800cc7b4-0x800cddd0 (18 functions). split_file divides it into the game's real files.

extern void* lbl_80288B0C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800CDD88(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288B0C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
