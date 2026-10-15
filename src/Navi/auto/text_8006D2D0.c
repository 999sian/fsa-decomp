#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006d2d0-0x8006f1b4 (29 functions). split_file divides it into the game's real files.

extern void* lbl_80280910[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8006D320(void);
extern "C" void fn_8006D300(void) {
    fn_8006D320();
}

extern "C" void* fn_8006F16C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80280910;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
