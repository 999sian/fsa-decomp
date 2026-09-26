// TU 0x802e038c-0x802e07c8 (actor VWMD).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_802E038C_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9A18[];

extern "C" void* fn_802E038C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9A18;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- stub_802e03ec.cpp ----
// VWMD cluster, part 2/4. fn_802E03EC - empty override (bare blr), no
// extab. Likely a "do nothing" draw() or similar no-op virtual.
extern "C" {

void fn_802E03EC(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
