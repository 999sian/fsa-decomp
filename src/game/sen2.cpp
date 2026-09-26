// TU 0x802e7634-0x802e794c (actor SEN2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Pnp2_dtor_802E7634.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern void* lbl_804A9F00[];

extern "C" void* fn_802E7634(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9F00;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Pnp2_EmptyHook.cpp ----
// Pnp2_EmptyHook - PNP2: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Pnp2_EmptyHook(void) {}

}

// fn_802E7698 - SEN2: update(). Counts down this->0x238; when it is zero,
// optionally (this->0x230 == 0) calls fn_801F0D20 with a table id, then
// clears the flag byte this->0x11c.
extern "C" void fn_801F0D20(void* this_, u32 id);
extern const u32 lbl_80541250[2];

extern "C" void fn_802E7698(void* this_) {
    s32 t = *(s32*)((char*)this_ + 0x238);
    if (t == 0) {
        if (*(s32*)((char*)this_ + 0x230) == 0) {
            fn_801F0D20(this_, lbl_80541250[*(s32*)((char*)this_ + 0x234)]);
        }
        *(u8*)((char*)this_ + 0x11c) = 0;
    } else {
        *(s32*)((char*)this_ + 0x238) = t - 1;
    }
}

// ---- Pnp2_SetParams.cpp ----
#include "game/esd/Actor.h"

// PNP2: setParams. Extracts 3 bitfields from this->0x90, re-reading the field independently for each extraction (matching retail's own redundant reloads).
extern "C" {
void Pnp2_SetParams(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 v1 = ((Actor*)thisPtr)->spawnParam;
	*(u32*)(p + 0x230) = (v1 >> 26) & 0x1;
	u32 v2 = ((Actor*)thisPtr)->spawnParam;
	*(u32*)(p + 0x234) = v2 & 0xFF;
	u32 v3 = ((Actor*)thisPtr)->spawnParam;
	*(u32*)(p + 0x238) = (v3 >> 8) & 0xFFF;
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
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
