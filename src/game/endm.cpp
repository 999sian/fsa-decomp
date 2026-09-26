// TU 0x802e9428-0x802eb21c (actor ENDM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Endm_dtor_802E9428.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA0FC[];

extern "C" void* fn_802E9428(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA0FC;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Endm_EmptyHook.cpp ----
// Endm_EmptyHook - ENDM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Endm_EmptyHook(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
