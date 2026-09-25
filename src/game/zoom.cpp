// TU 0x802e694c-0x802e6ec4 (actor ZOOM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Zoom_dtor_802E694C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9DF8[];

extern "C" void* fn_802E694C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9DF8;
        dtor_801F593C(this_, 0);
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
