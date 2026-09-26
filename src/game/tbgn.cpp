// TU 0x802f3f7c-0x802f43c0 (actor TBGN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Tbgn_dtor_802F3F7C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA6F8[];

extern "C" void* fn_802F3F7C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA6F8;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Tbgn_EmptyHook1.cpp ----
// Tbgn_EmptyHook1 / Tbgn_EmptyHook2 - TBGN: 2 empty no-op overrides (0x4 each, leaf, no extab needed)
extern "C" {

void Tbgn_EmptyHook1(void) {}

void Tbgn_EmptyHook2(void) {}

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
