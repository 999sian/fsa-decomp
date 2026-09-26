// ARSH_80105DD4: .text 0x80105DD4-0x80106040 (actor ARSH/ZNSH)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80105DD4_dtor.cpp

void operator delete(void* p);
extern void* lbl_8049CC34[];

extern "C" void* fn_80105DD4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049CC34;
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
