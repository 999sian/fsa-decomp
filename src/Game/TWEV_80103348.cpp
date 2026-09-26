// TWEV_80103348: .text 0x80103348-0x801042D0 (actor TWEV)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80103F28_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CA40[];

extern "C" void* fn_80103F28(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049CA40;
        char* p = (char*)this_;
        void* handle = *(void**)(p + 0x260);
        if (handle != 0) {
            fn_801EE434(handle);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
