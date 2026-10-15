#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80013a80-0x80015cc0 (55 functions). split_file divides it into the game's real files.

extern void* lbl_80204F9C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80015C5C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204F9C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
