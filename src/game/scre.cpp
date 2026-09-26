// TU 0x80391ce4-0x80394134 (actor SCRE).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_80391CE4_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF4C0[];

extern "C" void* fn_80391CE4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF4C0;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_8039394C.cpp ----
// fn_8039394C - actor@lbl_804AF490: coordinator function. Dispatches
// on this->0x234 (mode): 0/4 -> fn_80393228(this); 1 -> nothing;
// 2 -> fn_80391F58(this); 3/5/6/7 -> if (!fn_80230188(this->0x238))
// fn_80391D44(this).
extern "C" void fn_80393228(void* this_);
extern "C" void fn_80391F58(void* this_);
extern "C" u8 fn_80230188(s32 a);
extern "C" void fn_80391D44(void* this_);

extern "C" void fn_8039394C(void* this_) {
    s32 mode = *(s32*)((char*)this_ + 0x234);
    if (mode == 0 || mode == 4) {
        fn_80393228(this_);
    } else if (mode == 1) {
        // nothing
    } else if (mode == 2) {
        fn_80391F58(this_);
    } else if (mode == 3 || mode == 5 || mode == 6 || mode == 7) {
        if (!fn_80230188(*(s32*)((char*)this_ + 0x238))) {
            fn_80391D44(this_);
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
