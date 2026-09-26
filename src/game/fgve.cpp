// TU 0x802dfce8-0x802e038c (actor FGVE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802DFCE8_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A99C0[];

extern "C" void* fn_802DFCE8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A99C0;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// fn_802DFD48 / fn_802E0128 - FGVE: draw effect once armed; setParams.
extern const f32 lbl_80541188;
extern const f32 lbl_8054118C;
extern const f32 lbl_80541190;
extern const f32 lbl_80541194;
extern const char lbl_8046E9C0[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);

extern "C" void fn_802DFD48(char* p) {
    if (*(s32*)(p + 0x230) >= 2) {
        fn_801F06F0(p, lbl_8046E9C0, 0x16d, 0, 7, lbl_80541188, lbl_80541188);
    }
}

extern "C" void fn_802E0128(char* p) {
    *(f32*)(p + 0x60) = lbl_80541194;
    *(f32*)(p + 0x64) = lbl_80541194;
    *(f32*)(p + 0x68) = lbl_8054118C;
    *(f32*)(p + 0x6c) = lbl_80541190;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0x3F;
    *(s32*)(p + 0x238) = -1;
    *(f32*)(p + 0x23c) = lbl_80541190;
    *(s32*)(p + 0x230) = 0;
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
