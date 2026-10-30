// BOYO_8015B98C: .text 0x8015B98C-0x8015C828 (actor BOYO)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
#include <math.h>

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return tmpd * 0.5 * (3.0 - mag * (tmpd * tmpd));
}
static inline f32 dolsqrtfull(f32 mag) {
    if (mag > 0.0f) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < 0.0) {
        return NAN;
    } else if (fpclassify(mag) == 1) {
        return NAN;
    } else {
        return mag;
    }
}

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
    f32 cx; f32 ry; f32 sx; f32 sy; f32 sz; f32 cy; f32 sxsy; f32 cz;
    ry = *(u16*)(this_ + 0x25c) / lbl_8053D4BC;
    sx = sin(lbl_8053D4B8);
    sy = sin(ry);
    sz = sin(lbl_8053D4B8);
    cx = cos(lbl_8053D4B8);
    cy = cos(ry);
    cz = cos(lbl_8053D4B8);
    f32 sc = lbl_8053D4C0;
    sxsy = sx * sy;
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

extern "C" s32 fn_8023DE58(s32);
extern "C" void* fn_8023E724(s32);
extern "C" void fn_80239914(f32* box, s32 room, s32 p);
extern "C" s32 fn_8022CAF8(s32);
extern "C" bool fn_8022F478(s32);
extern "C" bool fn_8023B0F4(s32, f32*, s32, s32, f32);
extern "C" s32 fn_801F285C(void*, s32, s32, s32, s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F82CC(void*, void*, u8, f32);
extern "C" s32 fn_801A4D1C(s32, f32*, f32*);
extern "C" s32 fn_801A6108(s32, f32*, f32*);
extern "C" s32 fn_801A46FC(s32, f32*, f32*);
extern "C" s32 fn_801A4F5C(s32, f32*, f32*);
extern "C" void fn_80134DE4(void*, s32, s32);
extern "C" void fn_802378AC(s32, f32*);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_801F71A4(f32*, f32, f32, f32);
extern void* lbl_8053AAF8;
extern s32 lbl_804A0228[];
extern s32 lbl_804A0244[];
extern const f32 lbl_8053D4D0;
extern const f32 lbl_8053D4D4;
extern const f32 lbl_8053D4D8;
extern const f32 lbl_8053D4DC;
extern const f32 lbl_8053D4E0;
extern const f32 lbl_8053D500;
extern const f32 lbl_8053D504;
extern const f32 lbl_8053D508;
extern const f32 lbl_8053D50C;
extern "C" void fn_8015BC7C(char* this_) {
    s32 n;
    s32 room;
    s32 k;
    s32 target;
    s32 i, j;
    s32 r22;
    s32 r3v;
    f32 boxA[4];
    f32 boxB[4];
    f32 dist[4];
    s32 idx[4];
    f32 pos[2];
    f32 cen[2];

    *(f32*)(this_ + 0x60) = lbl_8053D4D0;
    *(f32*)(this_ + 0x64) = lbl_8053D4D0;
    *(f32*)(this_ + 0x68) = lbl_8053D4D4;
    *(f32*)(this_ + 0x6c) = lbl_8053D4D4;
    *(f32*)(this_ + 0x80) = lbl_8053D4D8;
    *(f32*)(this_ + 0x84) = lbl_8053D4D8;
    *(f32*)(this_ + 0x88) = lbl_8053D4DC;
    *(f32*)(this_ + 0x8c) = lbl_8053D4DC;
    *(s32*)(this_ + 0x108) = 1000;
    *(u16*)(this_ + 0x25c) -= 0x100;

    boxA[0] = *(f32*)(this_ + 0x80);
    boxA[1] = *(f32*)(this_ + 0x84);
    boxA[2] = *(f32*)(this_ + 0x88);
    boxA[3] = *(f32*)(this_ + 0x8c);
    boxB[0] = *(f32*)(this_ + 0x60);
    boxB[1] = *(f32*)(this_ + 0x64);
    boxB[2] = *(f32*)(this_ + 0x68);
    boxB[3] = *(f32*)(this_ + 0x6c);
    {
        f32 y = *(f32*)(this_ + 0x10);
        f32 x = *(f32*)(this_ + 0xc);
        pos[0] = x;
        pos[1] = y;
        boxA[0] += x;
        boxA[1] += y;
        boxA[2] += x;
        boxA[3] += y;
    }
    fn_80239914(boxA, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
    boxB[0] += pos[0];
    boxB[1] += pos[1];
    boxB[2] += pos[0];
    boxB[3] += pos[1];

    for (n = 0; n < 4; n++) {
        dist[n] = lbl_8053D4E0;
        idx[n] = -1;
        room = *(s32*)(this_ + 4);
        if (fn_8023DE58(n) == room) {
            f32 dx = *(f32*)fn_8023E724(n) - *(f32*)(this_ + 0xc);
            f32 dy = ((f32*)fn_8023E724(n))[1] - *(f32*)(this_ + 0x10);
            dist[n] = dolsqrtfull(dx * dx + dy * dy);
            idx[n] = n;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i < j && fn_8023DE58(i) == fn_8023DE58(j) && dist[i] > dist[j]) {
                idx[i] = j;
                idx[j] = i;
                dist[i] = dist[j];
                dist[j] = (f32)idx[i];
            }
        }
    }

    target = -1;
    for (k = 0; k < 4; k++) {
        if (idx[k] >= 0) {
            bool ok = false;
            if (fn_8022CAF8(idx[k]) != 4 && fn_8022CAF8(idx[k]) != 5) {
                ok = true;
            } else if (!fn_8022F478(idx[k])) {
                ok = true;
            }
            if (ok == true && fn_8023B0F4(idx[k], boxB, *(s32*)(this_ + 4), 0, lbl_8053D4B8)) {
                target = idx[k];
                break;
            }
        }
    }

    r22 = fn_801F285C(this_, 0, 0, 0, -1);
    r3v = fn_801F82CC(fn_801F856C(), this_, *(u8*)(this_ + 0x195), lbl_8053D500);
    *(s32*)(this_ + 0xb0) = 0x42304;

    if (target >= 0 || r22 >= 0 || r3v >= 0 || *(s32*)(this_ + 0x9c) >= 0 ||
        *(u16*)(this_ + 0x94) == 1 ||
        fn_801A4D1C(*(s32*)(this_ + 0x198), boxA, pos) != 0 ||
        fn_801A6108(*(s32*)(this_ + 0x198), boxA, pos) != 0 ||
        fn_801A46FC(*(s32*)(this_ + 0x198), boxA, pos) != 0 ||
        fn_801A4F5C(*(s32*)(this_ + 0x198), boxA, pos) != 0) {
        cen[0] = lbl_8053D504 * (boxB[0] - boxB[2]) + boxB[2];
        cen[1] = lbl_8053D504 * (boxB[1] - boxB[3]) + boxB[3];
        *(s16*)(this_ + 0x94) = 0;
        if (target >= 0) {
            fn_80134DE4(lbl_8053AAF8, 1, 0);
            fn_802378AC(target, cen);
        } else if (r22 >= 0) {
            fn_80134DE4(lbl_8053AAF8, 1, 0);
            fn_802378AC(r22, cen);
        }
        if (*(s32*)(this_ + 0x230) != 1) {
            fn_801F0E34(this_, 0x30012, 0);
            *(s32*)(this_ + 0x230) = 1;
            *(s32*)(this_ + 0xb0) = 0x2000;
        }
    }

    switch (*(s32*)(this_ + 0x90)) {
    case 1:
        if (*(s32*)(this_ + 0x240) == 0) {
            f32 t = lbl_8053D508 * (lbl_8053D50C * (f32)*(s32*)(this_ + 0x238)) + lbl_8053D508;
            switch (*(s32*)(this_ + 0x98)) {
            case 0:
                *(f32*)(this_ + 0x260) = t;
                *(f32*)(this_ + 0x264) = lbl_8053D4B8;
                *(f32*)(this_ + 0x268) = lbl_8053D4B8;
                break;
            case 1:
                *(f32*)(this_ + 0x260) = -t;
                *(f32*)(this_ + 0x264) = lbl_8053D4B8;
                *(f32*)(this_ + 0x268) = lbl_8053D4B8;
                break;
            case 2:
                *(f32*)(this_ + 0x260) = lbl_8053D4B8;
                *(f32*)(this_ + 0x264) = t;
                *(f32*)(this_ + 0x268) = lbl_8053D4B8;
                break;
            case 3:
                *(f32*)(this_ + 0x260) = lbl_8053D4B8;
                *(f32*)(this_ + 0x264) = -t;
                *(f32*)(this_ + 0x268) = lbl_8053D4B8;
                break;
            }
            *(s32*)(this_ + 0x240) = 500;
            if (*(s32*)(this_ + 0x238) != 0) {
                *(s32*)(this_ + 0x240) = 165;
            }
            *(s32*)(this_ + 0x98) = *(s32*)(this_ + 0x98) ^ 1;
        }
        fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x260), lbl_8053D508, lbl_8053D4C0);
        fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x264), lbl_8053D508, lbl_8053D4C0);
        *(JGeometry::TVec3<f32>*)(this_ + 0xc) += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        *(s32*)(this_ + 0x24c) += *(s32*)(this_ + 0x250);
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x234) * JMASSin(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x234) * JMASCos(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x270);
        break;
    }

    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        break;
    case 1:
        if (*(s32*)(this_ + 0x23c) == 0) {
            *(s32*)(this_ + 0x248) = *(s32*)(this_ + 0x248) + 1;
            if (*(s32*)(this_ + 0x248) > 6) {
                *(s32*)(this_ + 0x258) = 0;
                *(s32*)(this_ + 0x248) = 0;
                *(s32*)(this_ + 0x230) = 0;
            } else {
                *(s32*)(this_ + 0x258) = lbl_804A0228[*(s32*)(this_ + 0x248)];
                *(s32*)(this_ + 0x23c) = lbl_804A0244[*(s32*)(this_ + 0x248)];
            }
        }
        break;
    }
    if (*(s32*)(this_ + 0x23c) > 0) *(s32*)(this_ + 0x23c) -= 1;
    if (*(s32*)(this_ + 0x240) > 0) *(s32*)(this_ + 0x240) -= 1;
    if (*(s32*)(this_ + 0x244) > 0) *(s32*)(this_ + 0x244) -= 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
