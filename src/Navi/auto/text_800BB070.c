#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800bb070-0x800be068 (37 functions). split_file divides it into the game's real files.

extern void* lbl_80287BCC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800BE020(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287BCC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
