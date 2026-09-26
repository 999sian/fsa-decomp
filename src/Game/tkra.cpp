// TU 0x802eb21c-0x802ec1d4 (actor TKRA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tkra_dtor_802EB21C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA178[];

extern "C" void* fn_802EB21C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA178;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// fn_802EB27C - TKRA: releases every linked actor that is in state 3;
// returns whether any was found.
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 fn_801597B8(void* a);
extern "C" void fn_801597C0(void* a);
struct TkraObj {
    u8 pad[0x24c];
    s32 ids[4];
};
extern "C" u8 fn_802EB27C(TkraObj* p) {
    u8 found = 0;
    for (s32 i = 0; i < 4; i++) {
        s32 v = p->ids[i];
        if (v >= 0) {
            void* a = fn_801F666C(fn_801F856C(), v);
            v = (s32)a;
            if (v != 0 && fn_801597B8((void*)v) == 3) {
                fn_801597C0((void*)v);
                found = 1;
            }
        }
    }
    return found;
}

// ---- Tkra_EmptyHook.cpp ----
// Tkra_EmptyHook - TKRA: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Tkra_EmptyHook(void) {}

}

#include "JSystem/JGeometry/Vec.h"
struct TkraG { u8 pad[0x131df]; u8 arr[4]; };
extern "C" TkraG* fn_802D6A9C(void);
extern "C" u32 fn_80226BC4(f32* pos, s32 room);
extern "C" u8 fn_802D49A8(void* g, s32 room, u16 idx);
extern const f32 lbl_805413B4;
extern const f32 lbl_805413B8;
extern const f32 lbl_805413BC;
extern const f32 lbl_805413C0;
extern const f32 lbl_805413C8;
extern const f32 lbl_805413CC;
extern const f32 lbl_805413D0;
extern const f32 lbl_805413D4;
extern const f32 lbl_805413E8;

struct TkraV2 { f32 x, y; };
extern "C" void fn_802EBDCC(char* this_) {
    *(s32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xff;
    *(s32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    if (*(s32*)(this_ + 0x244) >= 4) {
        *(s32*)(this_ + 0x244) = -1;
    }
    s32 k = *(s32*)(this_ + 0x234);
    if ((k >= 0x1a && k < 0x20) || (k >= 0x26 && k < 0x2a) || (k >= 0x3b && k < 0x40) || k >= 0x4b ||
        (k == 0x2e && *(s32*)(this_ + 0x4) >= 8)) {
        *(s32*)(this_ + 0x234) = 0;
    }
    *(JGeometry::TVec3<f32>*)(this_ + 0x25c) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    *(f32*)(this_ + 0xc) += lbl_805413B8;
    *(f32*)(this_ + 0x10) += lbl_805413B4;
    s32 room = *(s32*)(this_ + 0x4);
    TkraG* g = fn_802D6A9C();
    if (g->arr[room] != 0) {
        *(f32*)(this_ + 0x60) = lbl_805413C0;
        *(f32*)(this_ + 0x64) = lbl_805413E8;
        *(f32*)(this_ + 0x68) = lbl_805413C8;
        *(f32*)(this_ + 0x6c) = lbl_805413CC;
    } else {
        *(f32*)(this_ + 0x60) = lbl_805413D0;
        *(f32*)(this_ + 0x64) = lbl_805413BC;
        *(f32*)(this_ + 0x68) = lbl_805413D4;
        *(f32*)(this_ + 0x6c) = lbl_805413CC;
    }
    JGeometry::TVec2<f32> p(*(f32*)(this_ + 0x25c), *(f32*)(this_ + 0x260));
    *(u32*)(this_ + 0x23c) = fn_80226BC4((f32*)&p, *(s32*)(this_ + 0x4));
    if (fn_802D49A8(fn_802D6A9C(), *(s32*)(this_ + 0x4), *(u32*)(this_ + 0x23c)) == 1) {
        this_[0x11c] = 0;
    }
    if (*(s32*)(this_ + 0x238) == 0) {
        *(s32*)(this_ + 0x230) = 0;
    } else if (*(s32*)(this_ + 0x238) == 2) {
        *(s32*)(this_ + 0x230) = 3;
    } else {
        *(s32*)(this_ + 0x230) = 2;
    }
    *(s32*)(this_ + 0x248) = -1;
    *(s32*)(this_ + 0x24c) = -1;
    *(s32*)(this_ + 0x250) = -1;
    *(s32*)(this_ + 0x254) = -1;
    *(s32*)(this_ + 0x258) = -1;
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
