// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8018EB94-801902C0 (DGT2). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_8018FB24_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A1FA0[];

extern "C" void* fn_8018FB24(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1FA0;
        char* p = (char*)this_;
        for (s32 i = 0; i < 3; i++) {
            fn_801EE434(*(void**)(p + 0x3c0));
            p += 4;
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

