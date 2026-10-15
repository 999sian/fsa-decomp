#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800eeec0-0x800efb88 (17 functions). split_file divides it into the game's real files.

extern void* lbl_8028B900[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800EFB40(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B900;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
