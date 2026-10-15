#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800b0ee8-0x800bace4 (71 functions). split_file divides it into the game's real files.

extern void* lbl_8028794C[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80287910[];
extern void* lbl_80286A30[];
extern "C" void* fn_800B9970(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287910;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_800BAC9C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028794C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
