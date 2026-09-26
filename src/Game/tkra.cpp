// TU 0x802eb21c-0x802ec1d4 (actor TKRA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tkra_dtor_802EB21C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA178[];

extern "C" void* fn_802EB21C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA178;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Tkra_EmptyHook.cpp ----
// Tkra_EmptyHook - TKRA: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Tkra_EmptyHook(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
