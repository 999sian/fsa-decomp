#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80057614-0x800618fc (176 functions). split_file divides it into the game's real files.

extern void* lbl_8027EC78[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8005E7D8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EC78;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
