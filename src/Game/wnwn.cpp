// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80184D64-80187144 (WNWN). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80184D64_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A18E0[];

extern "C" void* fn_80184D64(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A18E0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
