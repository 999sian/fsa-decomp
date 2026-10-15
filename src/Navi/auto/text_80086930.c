#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80086930-0x8008729c (9 functions). split_file divides it into the game's real files.

extern void* lbl_80283C78[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80086950(void);
extern "C" void fn_80086930(void) {
    fn_80086950();
}

extern "C" void* fn_80087254(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283C78;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
