// TU 0x802ef448-0x802ef76c (actor ELSK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Emsk_dtor_802EF448.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA498[];

extern "C" void* fn_802EF448(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA498;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Emsk_EmptyHook.cpp ----
// Emsk_EmptyHook - EMSK: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Emsk_EmptyHook(void) {}

}

// fn_802EF4AC - update(): counts down this->0x234; on expiry notifies the
// room config (fn_802D9FF4) with the pair selected by this->0x230 and plays
// sound 0xf through the global sound object.
struct ElskPair { u32 a; u32 b; };
extern const ElskPair lbl_8046F610[3];
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* rec, u32 a, u32 b);
extern "C" void fn_80136798(void* obj, int id, int arg);
extern void* lbl_8053AAF8[2];

extern "C" void fn_802EF4AC(void* this_) {
    *(s32*)((char*)this_ + 0x234) = *(s32*)((char*)this_ + 0x234) - 1;
    if (*(s32*)((char*)this_ + 0x234) == 0) {
        // NONMATCHING (99.2%): retail swaps r30/r31 (offset vs value).
        s32 i = *(s32*)((char*)this_ + 0x230);
        u32 a = lbl_8046F610[i].a;
        fn_802D9FF4(fn_802D6A9C(), a, lbl_8046F610[i].b);
        fn_80136798(lbl_8053AAF8[0], 0xf, 0);
    }
}

// ---- Emsk_SetParams.cpp ----
#include "game/esd/Actor.h"

// EMSK: setParams.
extern "C" {
void Emsk_SetParams(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 v = ((Actor*)thisPtr)->spawnParam;
	*(u32*)(p + 0x230) = v & 0x7F;
	*(s32*)(p + 0x234) = 0x1f4;
}
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
