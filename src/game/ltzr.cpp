// TU 0x8033f9a0-0x80340ec8 (actor LTZR).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/Ltzr_ctor_80340C60.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801BB3B0(void* this_);
extern void* lbl_804AC3E0[];

extern "C" void* fn_80340C60(void* this_) {
    fn_801BB3B0(this_);
    *(void**)this_ = lbl_804AC3E0;
    *(s32*)((char*)this_ + 0x2b8) = 0;
    return this_;
}
