// DBRK_8014529C: .text 0x8014529C-0x80145F60 (actor DBRK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8014529C_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F498[];

extern "C" void* fn_8014529C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F498;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
