// TU 0x802c1614-0x802c5950 (actor KEY0).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"

// ---- fn_802C1614_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A8CD8[];

extern "C" void* fn_802C1614(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8CD8;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// KEY0: register this key's tile with the room config.
struct Key0Pt {
    f32 x, y;
    Key0Pt(f32 x_, f32 y_) { x = x_; y = y_; }
};
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D6C10(void* rec, Key0Pt pt, u32 id);

static inline void key0Register(char* p) {
    u32 id = *(u32*)(p + 0x238);
    fn_802D6C10(fn_802D6A9C(), Key0Pt(*(f32*)(p + 0x230), *(f32*)(p + 0x234)), id);
}

// fn_802C1D30 - KEY0: store the target position and remember the current room pair.
extern "C" void fn_802C1D30(char* p, const JGeometry::TVec3<f32>* pos, s32 v) {
    *(JGeometry::TVec3<f32>*)(p + 0x260) = *pos;
    *(s32*)(p + 0x26c) = v;
    u32 lo = *(u32*)((char*)fn_802D6A9C() + 0x18);
    u32 hi = *(u32*)((char*)fn_802D6A9C() + 0x14);
    *(u16*)(p + 0x2aa) = ((u8)hi << 8) | (u8)lo;
}

extern "C" void fn_802C1D90(char* p) {
    key0Register(p);
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_802C2B64(char* p) {
    if (*(s32*)(p + 0x240) == 2) {
        *(u8*)(p + 0x2b0) = 1;
        key0Register(p);
    }
}

extern "C" void fn_802C2BD0(char* p) {
    *(u8*)(p + 0x2b0) = 1;
    key0Register(p);
}

extern "C" void fn_802C5284(char* p) {
    key0Register(p);
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
