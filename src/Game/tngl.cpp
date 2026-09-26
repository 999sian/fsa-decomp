// TU 0x803d9944-0x803da6b4 (actor TNGL).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" s32 fn_80237060(s32 arg);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" s32 fn_8022EA0C(s32 arg);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);

// TNGL sound/effect update
extern "C" void fn_803D9944(u8* this_) {
    s32 snd;
    u8* q;
    s32 base;
    s32 i;
    if (*(s32*)(this_ + 0x248) == 0) {
        base = 0x34C;
        if (fn_80237060(0) >= 2) {
            base = 0x364;
        }
        if (*(s32*)(this_ + 0x90) == 0) {
            f32 x = *(f32*)(this_ + 0xC);
            f32 y = *(f32*)(this_ + 0x10);
            f32 z = *(f32*)(this_ + 0x14);
            q = this_;
            for (i = 0; i < 4; i++) {
                if (fn_8023DE58(i) >= 8) {
                    *(f32*)(this_ + 0xC) = *(f32*)(q + 0x260);
                    *(f32*)(this_ + 0x10) = *(f32*)(q + 0x264);
                    *(f32*)(this_ + 0x14) = *(f32*)(q + 0x268);
                    snd = base + *(s32*)(this_ + 0x24C);
                    s32 room = fn_8023DE58(i);
                    fn_803075AC((void*)(i - 0x22B), room, this_ + 0xC, snd, 0, 2, -1, 1, 0, 1);
                }
                q += 0xC;
            }
            *(f32*)(this_ + 0xC) = x;
            *(f32*)(this_ + 0x10) = y;
            *(f32*)(this_ + 0x14) = z;
        } else {
            fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xC,
                        base + *(s32*)(this_ + 0x24C), 0, 2, -1, 1, 0, 1);
        }
    }
}

// ---- from src/Game/Tngl_dtor_803DA260.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0478[];

extern "C" void* fn_803DA260(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804B0478;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(*(void**)((char*)this_ + 0x290 + i * 4));
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// TNGL init (vtable slot 1)
extern "C" void fn_803DA2F4(u8* this_) {
    *(f32*)(this_ + 0x60) = -1280.0f;
    *(f32*)(this_ + 0x64) = -1280.0f;
    *(f32*)(this_ + 0x68) = 1280.0f;
    *(f32*)(this_ + 0x6C) = 1280.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8C) = 8.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23C) = 0;
    *(s32*)(this_ + 0x24C) = 0;
    *(u8*)(this_ + 0x250) = 1;
    *(void**)(this_ + 0x290) = 0;
    *(void**)(this_ + 0x294) = 0;
    *(void**)(this_ + 0x298) = 0;
    *(void**)(this_ + 0x29C) = 0;
    *(u8*)(this_ + 0x251) = 0;
    *(u8*)(this_ + 0x11F) = 1;
    if (*(s32*)(this_ + 0x90) == 0) {
        s32 p = fn_8022EA0C(0);
        if (p >= 0) {
            fn_8023DE58(p);
            *(JGeometry::TVec3<f32>*)(this_ + 0xC) = *fn_8023E724(p);
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) + 16.0f;
            *(s32*)(this_ + 4) = fn_8023DE58(p);
        }
    }
    u8* q = this_;
    for (s32 i = 0; i < 4; i++) {
        *(JGeometry::TVec3<f32>*)(q + 0x260) = *fn_8023E724(i);
        *(f32*)(q + 0x264) = *(f32*)(q + 0x264) + 16.0f;
        q += 0xC;
    }
    *(f32*)(this_ + 0x254) = *(f32*)(this_ + 0xC);
    *(f32*)(this_ + 0x258) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x25C) = *(f32*)(this_ + 0x14);
    if (*(s32*)(this_ + 0x90) == 0) {
        *(s32*)(this_ + 0x248) = 1;
        *(s32*)(this_ + 0x230) = 0;
    } else {
        *(s32*)(this_ + 0x230) = 5;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
