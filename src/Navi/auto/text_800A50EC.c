#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800a50ec-0x800b08f8 (97 functions). split_file divides it into the game's real files.

extern void* lbl_8028739C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800B08B0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028739C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
