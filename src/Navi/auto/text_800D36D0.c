#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d36d0-0x800d70bc (46 functions). split_file divides it into the game's real files.

extern void* lbl_80289AD0[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800D7074(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80289AD0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
