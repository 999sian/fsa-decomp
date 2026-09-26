// IWAG_800F46C0: .text 0x800F46C0-0x800F4C70 (actor IWAG)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_800F46C0_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C46C[];

extern "C" void* fn_800F46C0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C46C;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}
