#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004e268-0x8004e8fc (12 functions). split_file divides it into the game's real files.

extern void* lbl_80247174[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8004E298(void) {}

extern "C" void* fn_8004E71C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247174;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8024719C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004E764(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024719C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802471C4[];
extern "C" void* fn_8004E7AC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802471C4;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802471EC[];
extern "C" void* fn_8004E7F4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802471EC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

