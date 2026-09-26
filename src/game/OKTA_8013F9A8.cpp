// OKTA_8013F9A8: .text 0x8013F9A8-0x80140E24 (actor OKTA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8013F9A8_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F208[];

extern "C" void* fn_8013F9A8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F208;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
