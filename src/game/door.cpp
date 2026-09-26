// TU 0x802c5950-0x802c8500 (actor DOOR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802C5950_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A8D88[];

extern "C" void* fn_802C5950(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8D88;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- oscluster_802c59d4.cpp ----
extern "C" {

// fn_802C59D4(this) - DOOR's real draw(). A pure no-op override (just
// `blr`) - DOOR renders nothing itself, confirming its visual
// representation is static level geometry rather than an actor-drawn
// model. See [[project_fsa_door_key0_full_depth]].
void fn_802C59D4(void)
{
}

} // extern "C"

// ---- Actor_SetVec3_0x0.cpp ----
// Actor_SetVec3_0x0 - trivial 3-float vector setter (this->0x0/0x4/0x8 = x,y,z).
extern "C" void Actor_SetVec3_0x0(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
