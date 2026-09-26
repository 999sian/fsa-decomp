// TU 0x802dfce8-0x802e038c (actor FGVE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802DFCE8_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A99C0[];

extern "C" void* fn_802DFCE8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A99C0;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
