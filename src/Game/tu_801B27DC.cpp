// Game TU 801B27DC-801B3F60 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" u8* fn_802D6A9C(void);

extern "C" u8 fn_801B27DC(void* this_, s32 room, void* pos) {
    s32 kind = fn_8022461C(pos, room);
    s32 attr = fn_80226850(pos, room);
    if ((u32)(attr - 0x230) <= 1 || attr == 0x234) {
        return 0;
    }
    if (kind != 0 && kind != 4 && kind != 5 && kind != 6 && kind != 7 && kind != 2 && kind != 3 && kind != 0x50 && kind != 0xE && kind != 0xC && kind != 0x27 && kind != 0x28 && kind != 0x29 && kind != 0x2A && kind != 0x2B && kind != 0x2C && kind != 0x2D && kind != 0x2E && kind != 0x2F && kind != 0x20 && kind != 0xD && kind != 0x39 && kind != 0x3A && kind != 0x3B && kind != 0x4C && kind != 0x4D && kind != 0x4E && kind != 0x4F && kind != 0x24) {
        if (kind == 0x25) {
            return fn_802D6A9C()[0x171] == 0;
        }
        if (kind == 0x26) {
            return fn_802D6A9C()[0x171] == 1;
        }
        if (kind != 0x22 || fn_802D6A9C()[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 idx, s32 a, s32 b, f32 x, f32 y);
extern const char lbl_804690E0[];

extern "C" void fn_801B2998(u8* this_) {
    s32 f = *(s32*)(this_ + 0x308);
    if (f == 0 || (f & 2)) {
        fn_801F06F0(this_, lbl_804690E0, *(s32*)(this_ + 0x320) + 0x9B, 0, 7, 1.0f, 1.0f);
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3698[];

extern u8 lbl_8053ABE8;
extern s32 lbl_8053ABEC;
extern u8 lbl_8053ABF0;
extern void* lbl_8053AED0;
extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* mgr, s32 id);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" void fn_8022ADE4(void);
extern "C" void fn_8043A450(void* p, s32 a, s32 b);

extern "C" void fn_801B3B7C(u8* this_) {
    lbl_8053ABF0 = 0;
    *(f32*)(this_ + 0x80) = -4.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 4.0f;
    *(f32*)(this_ + 0x8C) = 8.0f;
    *(s32*)(this_ + 0x30C) = 0;
    *(s32*)(this_ + 0x310) = 0;
    *(s32*)(this_ + 0x314) = 0;
    *(s32*)(this_ + 0x318) = 0;
    *(s32*)(this_ + 0x31C) = 0;
    *(s32*)(this_ + 0x300) = 0;
    *(s32*)(this_ + 0x304) = 0;
    *(s32*)(this_ + 0x308) = 0;
    *(s32*)(this_ + 0x330) = *(u32*)(this_ + 0x90) & 7;
    *(s32*)(this_ + 0x328) = 5;
    *(s32*)(this_ + 0x324) = Actor_CreateByID(fn_801F856C(), 'LIMT', *(s32*)(this_ + 4), this_ + 0xC, 0, -1, -1);
    *(u8*)(this_ + 0x11E) = 1;
    fn_8022ADE4();
    s32 id = *(s32*)(this_ + 0x324);
    if (id >= 0) {
        u8* a = fn_801F666C(fn_801F856C(), id);
        if (a != 0) {
            s32 v = *(s32*)(this_ + 0x328);
            *(s32*)(a + 0x250) = *(s32*)(this_ + 0x198);
            *(f32*)(a + 0x254) = -28.0f;
            *(s32*)(a + 0x24C) = v;
        }
    }
    fn_8043A450(lbl_8053AED0, 6, 3);
    *(s32*)(this_ + 0x320) = 1;
    *(f32*)(this_ + 0x33C) = 0.0f;
    *(f32*)(this_ + 0x338) = 0.0f;
    *(f32*)(this_ + 0x334) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3C) = 0.0f;
    *(f32*)(this_ + 0x340) = *(f32*)(this_ + 0x10);
    lbl_8053ABEC = 0;
    *(u8*)(this_ + 0x2FC) = 0;
    *(u8*)(this_ + 0x32D) = 0;
    *(u8*)(this_ + 0x32C) = 0;
    *(u8*)(this_ + 0x1A8) = 0;
    lbl_8053ABE8 = 0;
    *(s32*)(this_ + 0x2F8) = 0;
}

extern "C" void* fn_801B3CD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3698;
        lbl_8053ABE8 = 0;
        lbl_8053ABF0 = 0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
