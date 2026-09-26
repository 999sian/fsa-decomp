// TU 0x802e5c44-0x802e694c (actor BGMN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Bgmn_dtor_802E5C44.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
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

extern "C" void* fn_802D6A9C(void);
// fn_802E6638 - BGMN: setParams(). Area size comes from the spawn params
// (in 16-unit tiles).
extern const f32 lbl_80541228;
extern "C" void fn_802E6638(char* p) {
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0x7f;
    *(s32*)(p + 0x238) = ((*(u32*)(p + 0x90) >> 22) & 0x1f) + 1;
    *(s32*)(p + 0x23c) = ((*(u32*)(p + 0x90) >> 17) & 0x1f) + 1;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
    *(u32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 7) & 1;
    *(s32*)(p + 0x248) = *(s32*)((char*)fn_802D6A9C() + 0x34);
    f32 h = lbl_80541228 * *(s32*)(p + 0x23c);
    f32 w = lbl_80541228 * *(s32*)(p + 0x238);
    *(f32*)(p + 0x60) = -w;
    *(f32*)(p + 0x64) = -h;
    *(f32*)(p + 0x68) = w;
    *(f32*)(p + 0x6c) = h;
    *(u16*)(p + 0x94) = 0xffff;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x24c) = -1;
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
