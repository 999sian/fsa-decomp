// TU 0x802e5c44-0x802e694c (actor BGMN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Bgmn_dtor_802E5C44.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9DA0[];

extern "C" void* fn_802E5C44(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9DA0;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Bgmn_EmptyHook.cpp ----
// Bgmn_EmptyHook - BGMN: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Bgmn_EmptyHook(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
