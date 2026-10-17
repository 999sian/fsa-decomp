// BOYO_8015B98C: .text 0x8015B98C-0x8015C828 (actor BOYO)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// ---- from Game/fn_8015B98C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A0260[];

extern "C" void* fn_8015B98C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0260;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" u16 fn_801F6874(s32 dir);
extern const f32 lbl_8053D4B8;
extern const f32 lbl_8053D518;
extern const f32 lbl_8053D51C;

extern "C" void fn_8015C42C(char* this_) {
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(f32*)(this_ + 0x260) = *(f32*)(this_ + 0x264) = *(f32*)(this_ + 0x268) = lbl_8053D4B8;
    *(s16*)(this_ + 0x94) = 0;
    *(s32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 8) & 3;
    *(s32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 16) & 1;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 7;
    *(s16*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x24) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x28) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2c) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0x258) = 0;
    *(JGeometry::TVec3<f32>*)(this_ + 0x26c) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    *(s32*)(this_ + 0x24c) = fn_801F6874(*(s32*)(this_ + 0x98));
    *(s32*)(this_ + 0x250) = 100;
    *(f32*)(this_ + 0x234) = lbl_8053D4B8;
    if (*(u32*)(this_ + 0x90) == 2 || *(u32*)(this_ + 0x90) == 3) {
        *(f32*)(this_ + 0x234) = lbl_8053D518;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x234) * JMASSin(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x234) * JMASCos(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x270);
    }
    if (*(u32*)(this_ + 0x90) == 4 || *(u32*)(this_ + 0x90) == 5) {
        *(f32*)(this_ + 0x234) = lbl_8053D51C;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x234) * JMASSin(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x234) * JMASCos(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x270);
    }
    if (*(u32*)(this_ + 0x90) == 2 || *(u32*)(this_ + 0x90) == 4) {
        *(s32*)(this_ + 0x250) = -100;
    }
    if (*(s32*)(this_ + 0x238) != 0) {
        *(s32*)(this_ + 0x250) <<= 1;
    }
    *(s32*)(this_ + 0xbc) = 4;
    *(s32*)(this_ + 0x230) = 0;
}

struct BoyoDrawKey {
    s32 a, b;
    BoyoDrawKey() { a = -1; b = -1; }
};

struct BoyoDrawParam {
    u8 map[16];      // 0x00
    BoyoDrawKey key; // 0x10
    void* mtx;       // 0x18
    u8 palette;      // 0x1c
    s8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    BoyoDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        mtx = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801F06F0(void* actor, const char* tbl, s32 idx, BoyoDrawParam* param, s32 p5, f32 a, f32 b);
extern const char lbl_804660E0[];
extern const f32 lbl_8053D4BC;
extern const f32 lbl_8053D4C0;

struct BoyoMtx {
    f32 m[3][4];
    BoyoMtx() {
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
    }
};

extern "C" void fn_8015B9EC(char* this_) {
    BoyoMtx mtx;
    BoyoDrawParam param;
    f32 cx; f32 ry; f32 sx; f32 sy; f32 sz; f32 cy; f32 cz;
    ry = *(u16*)(this_ + 0x25c) / lbl_8053D4BC;
    sx = sin(lbl_8053D4B8);
    sy = sin(ry);
    sz = sin(lbl_8053D4B8);
    cx = cos(lbl_8053D4B8);
    cy = cos(ry);
    cz = cos(lbl_8053D4B8);
    f32 sc = lbl_8053D4C0;
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 cxcz = cx * cz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    mtx.m[0][0] = sc * (cy * cz);
    mtx.m[1][0] = sc * (cy * sz);
    mtx.m[2][0] = sc * -sy;
    mtx.m[0][1] = sc * (sxsy * cz - cxsz);
    mtx.m[1][1] = sc * (sxsy * sz + cxcz);
    mtx.m[2][1] = sc * (sx * cy);
    mtx.m[0][2] = sc * (cxcz * sy + sxsz);
    mtx.m[1][2] = sc * (cxsz * sy - sxcz);
    mtx.m[2][2] = sc * (cx * cy);
    param.mtx = &mtx;
    fn_801F06F0(this_, lbl_804660E0, *(s32*)(this_ + 0x258) + 0x70, &param, 0, sc, sc);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
