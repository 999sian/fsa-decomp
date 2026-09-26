// TU 0x802a964c-0x802aa364 (actor SWT4).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_802A964C_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A80A0[];

extern "C" void* fn_802A964C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A80A0;
        __dt__5ActorFv(this_, 0);
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

// ---- fn_802AA0B8 ----
extern const u32 lbl_8046C850[4];

extern "C" void fn_802AA0B8(u8* this_) {
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0x1F;
    if (*(s32*)(this_ + 0x234) != 5) {
        *(u32*)(this_ + 0x230) = 0;
    } else {
        *(u32*)(this_ + 0x230) = 7;
    }
    const u32* sh = lbl_8046C850;
    *(u32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> sh[0]) & 0x1F;
    *(u32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> sh[1]) & 0x1F;
    *(u32*)(this_ + 0x24C) = (*(u32*)(this_ + 0x90) >> sh[2]) & 0x1F;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> sh[3]) & 0x1F;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
