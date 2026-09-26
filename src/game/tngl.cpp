// TU 0x803d9944-0x803da6b4 (actor TNGL).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/Tngl_dtor_803DA260.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0478[];

extern "C" void* fn_803DA260(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804B0478;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(*(void**)((char*)this_ + 0x290 + i * 4));
        }
        dtor_801F593C(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
