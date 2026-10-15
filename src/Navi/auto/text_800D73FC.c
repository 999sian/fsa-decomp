#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d73fc-0x800ee3f0 (167 functions). split_file divides it into the game's real files.

extern void* lbl_8028B80C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800EE3A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B80C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
