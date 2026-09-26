// TU 0x8038f9f4-0x8039003c (actor KNBN).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_8038F9F4_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF428[];

extern "C" void* fn_8038F9F4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF428;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/Knbn_EmptyHook.cpp ----
// fn_8038FA54 - KNBN: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void fn_8038FA54(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
