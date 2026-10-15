#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8000d404-0x80012630 (157 functions). split_file divides it into the game's real files.

extern "C" void fn_8000EAE0(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern void* lbl_80204948[];
extern "C" void fn_8015AB1C(void);
extern "C" void* fn_8000EB44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204948;
        if (param_2 > 0) {
            fn_8015AB1C();
        }
    }
    return ptr;
}

extern "C" void fn_8000EBAC(void) {
}

extern "C" void fn_8000EBB0(void) {
}

extern "C" void fn_8000EBB4(void) {
}

extern "C" void fn_800120AC(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

