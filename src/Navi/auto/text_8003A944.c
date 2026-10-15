#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8003a944-0x80041b7c (90 functions). split_file divides it into the game's real files.

extern void* lbl_802469E8[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8003CC2C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80041B34(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802469E8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
