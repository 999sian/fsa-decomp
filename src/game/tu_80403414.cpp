// TU 0x80403414-0x80403d84.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_80403804_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0FE0[];

extern "C" void* fn_80403804(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B0FE0;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
