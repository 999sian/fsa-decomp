// ANHO_80102278: .text 0x80102278-0x8010307C (actor ANHO)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80102278_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C970[];

extern "C" void* fn_80102278(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C970;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
