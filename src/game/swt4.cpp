// TU 0x802a964c-0x802aa364 (actor SWT4).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802A964C_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A80A0[];

extern "C" void* fn_802A964C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A80A0;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Swt4_Draw.cpp ----
// Swt4_Draw(this) - SWT4's real draw(). A pure no-op (`blr`), matching
// the SAME pattern DOOR's draw uses ([[project_fsa_door_key0_full_depth]])
// - SWT4 renders nothing itself, relying on static level geometry or
// effects triggered from elsewhere rather than an actor-drawn model.
extern "C" {

void Swt4_Draw(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
