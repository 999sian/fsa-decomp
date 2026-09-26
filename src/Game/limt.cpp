// TU 0x80438540-0x80438c68 (actor LIMT).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_80438540_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B174C[];

extern "C" void* fn_80438540(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B174C;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
