// TU 0x802e694c-0x802e6ec4 (actor ZOOM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Zoom_dtor_802E694C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9DF8[];

extern "C" void* fn_802E694C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9DF8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Zoom_EmptyHook.cpp ----
// Zoom_EmptyHook - ZOOM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Zoom_EmptyHook(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
