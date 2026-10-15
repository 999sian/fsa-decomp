#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800c9c64-0x800cb9f4 (21 functions). split_file divides it into the game's real files.

extern void* lbl_802888AC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800CB9AC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802888AC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
