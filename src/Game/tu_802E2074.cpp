// TU 0x802e2074-0x802e2990.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_802E2074_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9BC8[];

extern "C" void* fn_802E2074(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9BC8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- EmptyHook_802E20D4.cpp ----
// Unnamed actor cluster, part 2/4. EmptyHook_802E20D4 - empty override (bare
// blr), no extab.
extern "C" {

void EmptyHook_802E20D4(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
