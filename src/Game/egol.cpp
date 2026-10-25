// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801AFB38-801B0A00 (EGOL). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// from src/Game/fn_801AFB38_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3548[];

extern "C" void* fn_801AFB38(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3548;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct EgolRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct EgolGame { u8 pad[0xb4]; EgolRandom rnd; };
extern EgolGame* lbl_8053AAF8;

extern "C" void fn_801B0654(char* this_) {
    if (*(s32*)(this_ + 0x254) == *(s32*)(this_ + 0x108)) {
        return;
    }
    *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x108);
    if (*(s32*)(this_ + 0x258) > 0) {
        (*(s32*)(this_ + 0x258))--;
    }
    if (*(s32*)(this_ + 0x258) <= 0) {
        *(u32*)(this_ + 0xb0) = 0;
    }
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x250) = *(s32*)(this_ + 0x98) + 0x10;
    EgolGame* g = lbl_8053AAF8;
    *(s32*)(this_ + 0x23c) = (s32)(60.0f * g->rnd.get_ufloat_1()) + 0x3c;
    *(s32*)(this_ + 0x230) = 0;
}

// EGOL init (vtable slot 1)
extern "C" void fn_801B0710(char* this_) {
    *(f32*)(this_ + 0x60) = -12.0f;
    *(f32*)(this_ + 0x64) = -22.0f;
    *(f32*)(this_ + 0x68) = 12.0f;
    *(f32*)(this_ + 0x6c) = 2.0f;
    *(f32*)(this_ + 0x80) = -12.0f;
    *(f32*)(this_ + 0x84) = -22.0f;
    *(f32*)(this_ + 0x88) = 12.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(f32*)(this_ + 0x70) = -16.0f;
    *(f32*)(this_ + 0x74) = -24.0f;
    *(f32*)(this_ + 0x78) = 16.0f;
    *(f32*)(this_ + 0x7c) = 6.0f;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0xb8) = 1;
    *(s32*)(this_ + 0x98) = 2;
    *(s32*)(this_ + 0x250) = 0x12;
    *(s32*)(this_ + 0xbc) = 4;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(s32*)(this_ + 0x108) = 0x3ef;
    *(s32*)(this_ + 0x258) = 2;
    *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x230) = 0;
}

struct EgolResMgr {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void v03();
    virtual void* getRes(u32 type, const char* name);
};
extern "C" void fn_801EFD34(void* this_, void* res, void* data, s32 mode, f32 a, f32 b, f32 c);
extern const char* lbl_804A34F8[];
extern const f32 lbl_8053E888;
extern const f32 lbl_8053E88C;
extern const f32 lbl_8053E890;
extern const f32 lbl_8053E894;

extern "C" void fn_801AFB98(char* this_) {
    u8 buf[0x40];
    f32 mtx[3][4];

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;

    for (u8 i = 0; i < 16; i++) {
        buf[i] = i;
    }

    f32 m00 = lbl_8053E888;
    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    buf[0x2e] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;

    if (*(s32*)(this_ + 0x98) == 0) {
        m00 = lbl_8053E88C;
    }
    mtx[0][0] = m00;
    mtx[0][1] = lbl_8053E890;
    mtx[0][2] = lbl_8053E890;
    mtx[1][1] = lbl_8053E888;
    mtx[1][0] = lbl_8053E890;
    mtx[1][2] = lbl_8053E890;
    mtx[2][0] = lbl_8053E890;
    mtx[2][1] = lbl_8053E890;
    mtx[0][3] = lbl_8053E890;
    mtx[2][2] = lbl_8053E888;
    mtx[1][3] = lbl_8053E890;
    mtx[2][3] = lbl_8053E890;
    *(void**)(buf + 0x18) = mtx;
    void* res = ((EgolResMgr*)*(void**)((char*)lbl_8053AAF8 + 0xa4))->getRes('TIMG', lbl_804A34F8[*(s32*)(this_ + 0x250)]);
    fn_801EFD34(this_, res, buf, 3, lbl_8053E890, lbl_8053E894, lbl_8053E890);
}

extern "C" int fn_801F3D94(char* this_, s32 flag);
extern "C" void fn_801F2618(char* this_, s32 a, s32 b);
extern "C" void fn_801EF510(char* this_);
extern "C" void fn_801F71A4(void* vec, f32 a, f32 b, f32 c);
extern "C" int fn_801F285C(char* this_, s32 a, s32 b, s32 c, s32 idx);
extern "C" u8 fn_80237948(s32 idx, f32* pt);
extern "C" void fn_8013CC50(s32 room, void* pos, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void fn_801F0E34(char* this_, u32 id, s32 mode);
extern "C" void fn_801F2B7C(char* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801EEC98(char* this_, s32 res, s32 a, s32* out0, s32* out1, s32 b, s32 c, s32 d, s32 e);
extern "C" const f32 lbl_8053E888;
extern "C" const f32 lbl_8053E890;
extern "C" const f32 lbl_8053E898;
extern const f32 lbl_8053E89C;
extern const f32 lbl_8053E898;
extern "C" void fn_801AFD54(char* this_) {
    s32 idx;
    f32 fv;
    f32 pt[2];
    s32 i;

    idx = -1;
    if (fn_801F3D94(this_, 1) != 0) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (*(s32*)(this_ + 0x108) >= 0x3e8) {
        ((void (*)(char*))(*(void***)this_)[9])(this_);
        *(s32*)(this_ + 0xb0) = 0;
        return;
    }
    fn_801EF510(this_);
    fn_801F71A4(this_ + 0x3c, *(f32*)(this_ + 0x25c), lbl_8053E898, lbl_8053E888);
    fn_801F71A4(this_ + 0x40, *(f32*)(this_ + 0x260), lbl_8053E898, lbl_8053E888);
    *(f32*)(this_ + 0xc) += *(f32*)(this_ + 0x3c);
    *(f32*)(this_ + 0x10) += *(f32*)(this_ + 0x40);
    *(f32*)(this_ + 0x14) += *(f32*)(this_ + 0x44);
    for (i = 0; i < 4; i++) {
        idx = fn_801F285C(this_, 0, 0, 0, i);
        if (idx < 0) {
            continue;
        }
        {
            f32 x0 = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
            f32 x1 = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
            f32 y0 = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
            f32 y1 = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
            pt[0] = lbl_8053E89C * (x0 - x1) + x1;
            pt[1] = lbl_8053E89C * (y0 - y1) + y1;
        }
        if (fn_80237948(idx, pt) != 0) {
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E888, 0x117, 0, 1, 0, 0, 1);
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E888, 0x118, 0, 1, 0, 0, 1);
        }
        fn_801F0E34(this_, 0x400d1, 0);
    }
    fn_801F2B7C(this_, -100, -1, 1);
    fn_801EEC98(this_, *(s32*)(this_ + 0x198), 0, &idx, (s32*)&fv, 0, 0, 0, 0);
    fn_801F2618(this_, 0, 0);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
