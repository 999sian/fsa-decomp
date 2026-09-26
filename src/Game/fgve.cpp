// TU 0x802dfce8-0x802e038c (actor FGVE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_802DFCE8_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A99C0[];

extern "C" void* fn_802DFCE8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A99C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// fn_802DFD48 / fn_802E0128 - FGVE: draw effect once armed; setParams.
extern const char lbl_8046E9C0[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);

extern "C" void fn_802DFD48(char* p) {
    if (*(s32*)(p + 0x230) >= 2) {
        fn_801F06F0(p, lbl_8046E9C0, 0x16d, 0, 7, 1.0f, 1.0f);
    }
}

// fn_802DFD90 - FGVE: update(). A grave/hole: detects a player standing
// on it (or digging), shows the reward, then sinks and spawns effects.
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
struct FgvePt { f32 x, y; };
struct FgveBox { FgvePt min, max; };
struct FgveReward { u16 a, b, c, d; };
extern const FgveReward lbl_8046E9B0[];
extern void* lbl_8053AC98;
extern "C" void fn_80239914(FgveBox* box, u32 room, u32 id);
extern "C" s32 fn_80239558(FgveBox* box, u32 room, u32 id);
extern "C" s32 fn_8023AF14(FgveBox* box, u32 room, s32 a, f32 f);
extern "C" s32 fn_80230CFC(s32 player);
extern "C" u8 fn_8023513C(s32 player);
extern "C" void fn_8029E050(void* mgr, JGeometry::TVec3<f32>* pos, u32 room, u16 a, u16 b, u16 c, u16 d);
extern "C" void fn_802A3948(void* mgr, JGeometry::TVec3<f32>* pos, s32 player, u32 room, s32 id);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_801F0D20(void* this_, s32 id);

static inline void fgveOpen(char* p) {
    *(s32*)(p + 0x230) = 2;
    *(JGeometry::TVec3<f32>*)(p + 0x240) = *(JGeometry::TVec3<f32>*)(p + 0xc);
    *(f32*)(p + 0xc) += 16.0f;
    *(f32*)(p + 0x10) += 16.0f;
    *(f32*)(p + 0x60) = -16.0f;
    *(f32*)(p + 0x64) = -16.0f;
    *(f32*)(p + 0x68) = 16.0f;
    *(f32*)(p + 0x6c) = 0.0f;
}

extern "C" void fn_802DFD90(char* p) {
    f32 x, y;
    if (*(s32*)(p + 0x230) < 2) {
        x = 16.0f + *(f32*)(p + 0xc);
        y = 16.0f + *(f32*)(p + 0x10);
    } else {
        x = *(f32*)(p + 0xc);
        y = *(f32*)(p + 0x10);
    }
    FgveBox box;
    box.min.x = *(f32*)(p + 0x60);
    box.min.y = *(f32*)(p + 0x64);
    box.max.x = *(f32*)(p + 0x68);
    box.max.y = *(f32*)(p + 0x6c);
    box.min.x += x;
    box.min.y += y;
    box.max.x += x;
    box.max.y += y;
    fn_80239914(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198));
    s32 player = fn_80239558(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198));
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        s32 digger = fn_8023AF14(&box, *(u32*)(p + 0x4), 0, 0.0f);
        if (player >= 0 && fn_80230CFC(player) == 3) {
            *(s32*)(p + 0x230) = 1;
            *(s32*)(p + 0x238) = player;
            *(f32*)(p + 0x23c) = 0.0f;
        } else if (digger >= 0 && fn_8023513C(digger) && fn_80230CFC(digger) == 3) {
            *(s32*)(p + 0x238) = digger;
            *(f32*)(p + 0x23c) = 0.0f;
            fgveOpen(p);
        }
        break;
    }
    case 1:
        if (player >= 0 && *(s32*)(p + 0x238) == player && fn_80230CFC(player) == 3) {
            *(f32*)(p + 0x23c) += 1.0f;
            if (*(f32*)(p + 0x23c) >= 25.0f) {
                fgveOpen(p);
            }
        } else if (*(s32*)(p + 0x238) != player) {
            *(s32*)(p + 0x238) = -1;
            *(s32*)(p + 0x230) = 0;
        }
        break;
    case 2: {
        s32 i = *(s32*)(p + 0x234);
        fn_8029E050(lbl_8053AC98, (JGeometry::TVec3<f32>*)(p + 0x240), *(u32*)(p + 0x4),
                    lbl_8046E9B0[i].a, lbl_8046E9B0[i].b, lbl_8046E9B0[i].c, lbl_8046E9B0[i].d);
        *(s32*)(p + 0x230) = 3;
        *(f32*)(p + 0x23c) = 0.0f;
        break;
    }
    case 3:
        if (((s32)*(f32*)(p + 0x23c) & 3) == 0) {
            fn_801F0E34(p, 0x3000e, 0);
        }
        *(f32*)(p + 0x23c) += 0.5;
        *(f32*)(p + 0x10) -= 0.5;
        if (*(f32*)(p + 0x23c) >= 16.0f) {
            *(f32*)(p + 0x244) = *(f32*)(p + 0x10) - 16.0f;
            fn_802A3948(lbl_8053AC98, (JGeometry::TVec3<f32>*)(p + 0x240), *(s32*)(p + 0x238), *(u32*)(p + 0x4), 0x266);
            *(f32*)(p + 0x240) += 16.0f;
            fn_802A3948(lbl_8053AC98, (JGeometry::TVec3<f32>*)(p + 0x240), *(s32*)(p + 0x238), *(u32*)(p + 0x4), 0x269);
            *(s32*)(p + 0x230) = 4;
        }
        break;
    case 4:
        if (*(s32*)(p + 0x234) == 1) {
            fn_801F0D20(p, 3);
        }
        *(u8*)(p + 0x11c) = 0;
        break;
    }
}

extern "C" void fn_802E0128(char* p) {
    *(f32*)(p + 0x60) = -16.0f;
    *(f32*)(p + 0x64) = -16.0f;
    *(f32*)(p + 0x68) = 16.0f;
    *(f32*)(p + 0x6c) = 0.0f;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0x3F;
    *(s32*)(p + 0x238) = -1;
    *(f32*)(p + 0x23c) = 0.0f;
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
