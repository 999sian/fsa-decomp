// TU 0x80220f54-0x80221b44.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- stub_80221158.cpp ----
// fn_80221158 - universal shared-actor-default hook: unconditionally
// returns 0, no arguments. Referenced only from actor vtable listings
// in data_80498528.s; the specific method this slot represents (which
// virtual call it answers) is not confirmed.
extern "C" {

int fn_80221158(void) { return 0; }

}

// ---- fn_80221160.cpp ----
extern "C" void fn_8022149C(void* this_, s32 param);

// fn_80221160 - GENERIC default for vtable offset 0x74 (see
// project_fsa_growing_area_extension.md). Thin wrapper: fn_8022149C(this, 0).
extern "C" void fn_80221160(void* this_) {
    fn_8022149C(this_, 0);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
