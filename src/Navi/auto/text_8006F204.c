#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006f204-0x80070d28 (26 functions). split_file divides it into the game's real files.

extern void* lbl_80280CEC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80070CE0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80280CEC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
