#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800872f8-0x80089858 (57 functions). split_file divides it into the game's real files.

extern void* lbl_80283F48[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_802883C4[];
extern void* lbl_8027EC78[];
extern "C" void* fn_80087788(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802883C4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800885B4(void);
extern "C" void fn_80088574(void) {
    fn_800885B4();
}

extern "C" void fn_80088690(void);
extern "C" void fn_80088594(void) {
    fn_80088690();
}

extern "C" void* fn_800888E0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80119978(void*, int);
extern char lbl_80283FC4[];
extern "C" void* fn_80088D50(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80283FC4;
        fn_80119978(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80088ED4(void);
extern "C" void fn_80088E74(void) {
    fn_80088ED4();
}

