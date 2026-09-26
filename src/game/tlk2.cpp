// TU 0x803b8970-0x803b8c74 (actor TLK2).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_803B8970_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFAD8[];

extern "C" void* fn_803B8970(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFAD8;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/Tlk2_EmptyHook1.cpp ----
// fn_803B89D0/fn_803B89D4 - TLK2: 2 empty no-op overrides (0x4 each)
extern "C" {

void fn_803B89D0(void) {}

void fn_803B89D4(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
