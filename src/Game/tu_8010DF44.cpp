// tu_8010DF44: .text 0x8010DF44-0x8010E2D4
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8010E074_ctor.cpp
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049D140[];

extern "C" void* fn_8010E074(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049D140;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
