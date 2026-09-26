// TU 0x802f43c0-0x802f4820 (actor TBO2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tbo2_dtor_802F43C0.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA750[];

extern "C" void* fn_802F43C0(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA750;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
