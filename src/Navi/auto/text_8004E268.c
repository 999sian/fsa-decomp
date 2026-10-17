#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004e268-0x8004e8fc (12 functions). split_file divides it into the game's real files.

extern void* lbl_80247174[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_801DE4F4(s32, void*);
extern "C" void fn_8004E268(void* param_1) {
    s32 local[1];
    local[0] = *(s32*)((u8*)param_1 + 4);
    fn_801DE4F4(2, local);
}

extern "C" void fn_8004E298(void) {}

extern char lbl_80247000[];
extern "C" void fn_801303BC(void*, int);
extern char lbl_802470CC[];
extern "C" void* fn_8004E29C(void** param_1, s16 param_2) {
    if (param_1 != nullptr) {
        param_1[0] = (void*)lbl_802470CC;
        if (param_1 != nullptr) {
            param_1[0] = (void*)lbl_80247000;
            fn_801303BC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

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

