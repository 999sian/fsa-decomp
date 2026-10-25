// OKTA_8013F9A8: .text 0x8013F9A8-0x80140E24 (actor OKTA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/ItemBase.h"

// ---- from Game/fn_8013F9A8_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F208[];

extern const f32 lbl_8053CE28;
extern const f32 lbl_8053CE2C;
extern const f32 lbl_8053CE34;
extern const f32 lbl_8053CE3C;
extern const f32 lbl_8053CE50;
extern const f32 lbl_8053CE54;
extern const f32 lbl_8053CE80;
extern const f32 lbl_8053CE84;
extern const f32 lbl_8053CE88;
extern const f32 lbl_8053CE8C;
extern const f32 lbl_8053CE90;
extern const f32 lbl_8053CE94;
extern const f32 lbl_8053CE98;

struct OktaVec3 {
    f32 x, y, z;
};

struct OktaVec4 {
    f32 x, y, z, w;
};

struct OktaBlk {
    s32 a;
    s32 b;
    void* c;
    u8 d[11];
    s32 e;
    u8 f[3];
    s32 g;
    s32 h;
    s32 i;
};

extern "C" void* fn_802D6A9C();
extern "C" void fn_801EF574(u8* lbl, s32 idx, OktaVec3* pos, u8* arr);
extern "C" void fn_803075AC(void* a, s32 room, void* c, void* d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void fn_801F02BC(u8* this_, u8* lbl, u32 idx, u8* arr, u32 a, s32 b, u8 c, f32 f1, f32 f2);
extern u8 lbl_80465A80[];
extern u32 lbl_8049F1E0[];
extern u32 lbl_8049F1C0[];

struct OktaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053CE2C;
    }
};
struct OktaGame { u8 pad[0xb4]; OktaRandom rnd; };
extern OktaGame* lbl_8053AAF8;
extern s32 lbl_8053AB28;

extern "C" void* fn_8013F9A8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F208;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void fn_8013FA08(u8* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    s32 sel;
    f32 s;
    s32 iVar3;
    u8* iVar1;


    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    rec.ids[3] = this_[0x278];
    if (*(s32*)(this_ + 0x230) == 2 || *(s32*)(this_ + 0x230) == 1) {
        sel = *(u32*)(this_ + 0x24c) + 2;
    } else if (*(u32*)(this_ + 0x90) == 1) {
        sel = (*(u32*)(this_ + 0x234) >> 3) & 1;
    } else {
        sel = (*(u32*)(this_ + 0x234) >> 2) & 1;
    }
    s = *(f32*)(this_ + 0x260);
    mtx[0][0] = s;
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[1][0] = 0.0f;
    mtx[1][1] = s;
    mtx[1][2] = 0.0f;
    mtx[2][0] = 0.0f;
    mtx[2][1] = 0.0f;
    mtx[2][2] = s;
    rec.w18 = mtx;

    if (*(s32*)(this_ + 4) == 8) {
        iVar3 = 0;
        u8* p = (u8*)fn_802D6A9C();
        OktaVec4 tmp = *(OktaVec4*)(p + 0xcc);
        OktaVec3 pos;
        pos.x = *(f32*)(this_ + 0xc);
        pos.y = *(f32*)(this_ + 0x10);
        pos.z = *(f32*)(this_ + 0x14);
        pos.x += tmp.x;
        pos.y += tmp.y;
        if (*(u32*)(this_ + 0x90) == 1) {
            iVar3 = 0x446;
        }
        fn_801EF574(lbl_80465A80, iVar3 + *(u32*)(this_ + 0x98) * 4 + sel, &pos, (u8*)&rec);
        if (*(s32*)(this_ + 0x230) == 2 || *(s32*)(this_ + 0x230) == 1) {
            iVar1 = (u8*)lbl_8049F1E0[*(u32*)(this_ + 0x258)];
        } else {
            u32 index = *(u32*)(this_ + 0x98) * 2;
            u32 bit = (*(u32*)(this_ + 0x234) >> 3) & 1;
            iVar1 = (u8*)lbl_8049F1C0[index + bit];
        }
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, iVar1 + 0x158, 0, 2, -1, 0, 0, 0);
    } else if (*(u32*)(this_ + 0x90) == 1) {
        s32 index = *(s32*)(this_ + 0x98);
        s32 frame = (s32)((char*)(index * 4) + sel);
        fn_801F02BC(this_, lbl_80465A80, frame + 0x446, (u8*)&rec, 7, 0, 0, lbl_8053CE2C, lbl_8053CE2C);
    } else {
        fn_801F02BC(this_, lbl_80465A80, (s32)((char*)(*(u32*)(this_ + 0x98) * 4) + sel), (u8*)&rec, 7, 0, 0, lbl_8053CE2C, lbl_8053CE2C);
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
extern const f32 lbl_8053CE30;
extern u8* lbl_8053AB10;
extern "C" void fn_8030C210(void* p);
extern "C" void fn_801F71A4(u8* p, f32 a, f32 b, f32 c);
extern "C" void fn_801F2618(u8* this_, s32 a, s32 b);
extern "C" void fn_801F2B7C(u8* this_, s32 a, s32 b, s32 c);
extern "C" void fn_8013FD50(u8* this_) {
    if (*(s32*)(this_ + 0x90) == 2) {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24));
    }
    fn_801F71A4(this_ + 0x260, *(f32*)(this_ + 0x264), lbl_8053CE30, *(f32*)(this_ + 0x26c));
    fn_801F2B7C(this_, -100, -1, 1);
    fn_801F2618(this_, 0, 0);
}

#pragma opt_common_subs off
extern "C" void fn_80140920(u8* this_) {
    f32 random;
    *(f32*)(this_ + 0x60) = lbl_8053CE80;
    *(f32*)(this_ + 0x64) = lbl_8053CE80;
    *(f32*)(this_ + 0x68) = lbl_8053CE84;
    *(f32*)(this_ + 0x6c) = lbl_8053CE84;
    *(f32*)(this_ + 0x80) = lbl_8053CE80;
    *(f32*)(this_ + 0x84) = lbl_8053CE28;
    *(f32*)(this_ + 0x88) = lbl_8053CE84;
    *(f32*)(this_ + 0x8c) = lbl_8053CE84;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(f32*)(this_ + 0x260) = lbl_8053CE2C;
    *(f32*)(this_ + 0x264) = lbl_8053CE2C;
    *(f32*)(this_ + 0x268) = lbl_8053CE2C;
    *(f32*)(this_ + 0x26c) = lbl_8053CE50;
    *(s32*)(this_ + 0x274) = lbl_8053AB28 & 31;
    lbl_8053AB28++;
    *(u32*)(this_ + 0x90) &= 0xff;
    random = lbl_8053AAF8->rnd.get_ufloat_1();
    *(s32*)(this_ + 0x98) = (s32)(lbl_8053CE88 * random) & 3;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x270) = 0;
    *(f32*)(this_ + 0x25c) = lbl_8053CE2C;
    this_[0x278] = 3;
    random = lbl_8053AAF8->rnd.get_ufloat_1();
    *(s32*)(this_ + 0x234) = (s32)(lbl_8053CE54 * random) + 0x32;
    random = lbl_8053AAF8->rnd.get_ufloat_1();
    *(s32*)(this_ + 0x238) = (s32)(lbl_8053CE54 * random) + 0x64;
    switch (*(s32*)(this_ + 0x90)) {
    case 0: break;
    case 1: {
        *(f32*)(this_ + 0x25c) = lbl_8053CE8C;
        *(s32*)(this_ + 0xc0) = 3;
        *(s32*)(this_ + 0x108) = 0x30;
        *(f32*)(this_ + 0x260) = lbl_8053CE34;
        *(f32*)(this_ + 0x264) = lbl_8053CE34;
        *(f32*)(this_ + 0x268) = lbl_8053CE34;
        this_[0x278] = 4;
        *(f32*)(this_ + 0x60) = lbl_8053CE90;
        *(f32*)(this_ + 0x64) = lbl_8053CE90;
        *(f32*)(this_ + 0x68) = lbl_8053CE3C;
        *(f32*)(this_ + 0x6c) = lbl_8053CE3C;
        *(f32*)(this_ + 0x80) = lbl_8053CE94;
        *(f32*)(this_ + 0x84) = lbl_8053CE90;
        *(f32*)(this_ + 0x88) = lbl_8053CE98;
        *(f32*)(this_ + 0x8c) = lbl_8053CE98;
    } break;
    case 2: {
        *(s32*)(this_ + 0x238) = 10000;
        *(s32*)(this_ + 0x270) = 400;
        *(u32*)(this_ + 0xb8) = 1;
        this_[0x278] = 5;
    } break;
    case 3:
    default: break;
    }
    switch (*(s32*)(this_ + 0x98)) {
    case 0:
        *(f32*)(this_ + 0x27c) = *(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x280) = lbl_8053CE28;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    case 1:
        *(f32*)(this_ + 0x27c) = -*(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x280) = lbl_8053CE28;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    case 2: {
        f32 speed = *(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x27c) = lbl_8053CE28;
        *(f32*)(this_ + 0x280) = speed;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    }
    case 3: {
        f32 speed = -*(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x27c) = lbl_8053CE28;
        *(f32*)(this_ + 0x280) = speed;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    }
    }
    *(s32*)(this_ + 0x230) = 0;
}
#pragma opt_common_subs reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
