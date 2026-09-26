// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8015DE10-8015F454 (FLME). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_8015F19C_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A0330[];

extern "C" void* fn_8015F19C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0330;
        char* p = (char*)this_;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x264));
            p += 4;
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8015EA2C(void* this_);
extern "C" void fn_8015DF7C(void* this_);

struct FlmeTimers { u8 pad[0x234]; s32 t[3]; };
// FLME update (vtable slot 3)
extern "C" void fn_8015DEFC(char* this_) {
    fn_8015EA2C(this_);
    if (*(s32*)(this_ + 0x230) != 5) {
        fn_8015DF7C(this_);
    }
    for (int i = 0; i < 3; i++) {
        if (((FlmeTimers*)this_)->t[i] > 0) {
            ((FlmeTimers*)this_)->t[i]--;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
