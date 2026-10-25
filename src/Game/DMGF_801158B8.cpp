#include "types.h"
#include "JSystem/JGeometry.h"
#include "std/math.h"
#include "JSystem/JMath/JMath.h"

union EffWord {
    u32 w;
    u8 b[4];
};

struct EffArgs {
    u8 order[0x10];
    EffWord f10;
    EffWord f14;
    void* ptr;
    u8 b1c, b1d, b1e, b1f, b20, b21, b22, b23, b24, b25, b26;
    u8 pad0;
    u32 w28;
    u8 b2c, b2d, b2e;
    u8 pad1;
    u32 x30, x34, x38;
};

extern "C" void fn_801158B8(u8* this_ = 0);
extern "C" void fn_8010DF58(void*);
extern "C" void fn_802F745C(void* mgr, f32* pos, void* tgt, EffArgs* args);
extern void* lbl_8053AB10;
extern f32 lbl_8053C730;
extern "C" void PSMTXTrans(f32 m[3][4], f32 x, f32 y, f32 z);
extern f32 lbl_8053C6D4;
extern f32 lbl_8053C6D8;

extern "C" char lbl_8049D940[];
extern f32 lbl_8053C6D0;
extern const f32 lbl_8053C6DC;
extern f32 lbl_8053C6E0;
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" void fn_80115BC4(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* b);
extern "C" void fn_8023DFF4(s32 i, JGeometry::TVec3<f32>* pos);
extern "C" void fn_80230498(s32 i, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" void fn_801EB950(void*);
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void*);
extern "C" void dtor_801EB8CC(void*, s32);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8010DF78(void);
extern "C" void* fn_8011921C(void);
extern "C" void fn_801183BC(void);
extern "C" void fn_8030C210(void* a, void* b);
extern "C" void fn_801F0E34(void* p, s32 a, s32 b);
extern "C" void fn_8022FE80(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_803865B8(s32 a);
extern "C" void fn_80388EEC(s32 a);
extern "C" void fn_8013CB44(void* p, void* a, s32 b, s32 c, s32 d);
extern "C" void fn_801EB418(void* a, void* b);
extern "C" u8 fn_801EB648(void* a);
extern "C" void fn_801CD950(void* p, f32 a, f32 b);
extern s16 lbl_8053AA88;
extern s8 lbl_8053AA8A;
extern f32 lbl_8053C704;
extern f32 lbl_8053C710;
extern f32 lbl_8053C714;
extern f32 lbl_8053C718;
extern f32 lbl_8053C71C;
extern f32 lbl_8053C720;
extern f32 lbl_8053C724;
extern f32 lbl_8053C734;
extern "C" void fn_801158B8(u8* this_) {
    EffArgs args;
    f32 mtx[3][4];
    JGeometry::TVec3<f32> pos;
    args.f10.w = -1;
    args.f14.w = -1;
    for (u8 i = 0; i < 0x10; i++) {
        args.order[i] = i;
    }
    args.f10.w = -1;
    args.f14.w = 0;
    args.ptr = 0;
    args.b1c = 0;
    args.b1d = 0;
    args.b1e = 0;
    args.b1f = 1;
    args.b20 = 1;
    args.b21 = 0;
    args.b22 = 0;
    args.b23 = 0;
    args.b24 = 0;
    args.b25 = 0;
    args.b26 = 1;
    args.w28 = 3;
    args.b2c = 1;
    args.b2d = 0;
    args.b2e = 0;
    args.x30 = -1;
    args.x34 = 0;
    args.x38 = 2;
    PSMTXTrans(mtx, lbl_8053C6D0, lbl_8053C6D0, lbl_8053C6D0);
    register f32 zero = lbl_8053C6D0;
    f32 s = lbl_8053C6D4;
    f32 t = lbl_8053C6D8;
    mtx[0][0] = s;
    mtx[0][1] = zero;
    mtx[0][2] = zero;
    mtx[1][0] = zero;
    mtx[1][1] = t;
    mtx[1][2] = zero;
    mtx[2][0] = zero;
    mtx[2][2] = s;
    mtx[2][1] = zero;
    args.f14.b[0] = 0;
    args.f14.b[1] = 0;
    args.f14.b[2] = 0;
    args.f14.b[3] = 0xff;
    args.ptr = mtx;
    args.b1c = 1;
    args.b1d = 3;
    args.b2d = 1;
    pos = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    pos.z = zero;
    void* tgt = *(void**)(this_ + 0x32c);
    if (*(s32*)(this_ + 4) < 8) {
        fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos.x, tgt, &args);
    }
}

extern "C" s32 fn_80115A7C(char* p) {
    JGeometry::TVec3<f32> b;
    JGeometry::TVec3<f32> a;
    f32 maxDist = lbl_8053C6DC;
    for (s32 i = 0; i < 4; i++) {
        a = *fn_8023E724(i);
        fn_80115BC4(p, &a, &b);
        a += b;
        f32 dx = a.x - *(f32*)(p + 0xc);
        f32 dy = a.y - *(f32*)(p + 0x10);
        f32 dx2 = dx * dx;
        f32 dy2 = dy * dy;
        if (JMAFastSqrt(dx2 + dy2) <= maxDist) {
            fn_80230498(i, &a, *(s32*)(p + 0x280) + 0x3b5, (s32)lbl_8053C6E0, -0x80, -0x80, 1);
        } else {
            fn_8023DFF4(i, &a);
        }
    }
    fn_801D1C18(p + 0x270);
    return 1;
}

extern "C" void fn_80115D8C(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* b);
extern f32 lbl_8053C6E4;
extern f32 lbl_8053C6E8;
extern f32 lbl_8053C6D8;
extern f32 lbl_8053C6EC;
extern f32 lbl_8053C6F0;
extern "C" void fn_80115BC4(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* out) {
    JGeometry::TVec3<f32> dir;
    JGeometry::TVec3<f32> b;

    dir.zero();
    if (!(a->z <= lbl_8053C6E4)) {
        f32 dx = a->x - *(f32*)(p + 0xc);
        f32 dy = a->y - *(f32*)(p + 0x10);
        f32 dx2 = dx * dx;
        f32 dy2 = dy * dy;
        f32 dist = JMAFastSqrt(dx2 + dy2);
        if (!(dist <= lbl_8053C6DC)) {
            f32 t = (dist - lbl_8053C6DC) * lbl_8053C6E8;
            if (t > lbl_8053C6D8) {
                t = lbl_8053C6D8;
            } else if (t < lbl_8053C6D0) {
                t = lbl_8053C6D0;
            }
            f32 w = t * lbl_8053C6F0 + lbl_8053C6EC;
            dir.sub(*(JGeometry::TVec3<f32>*)(p + 0xc), *a);
            dir.z = 0.0f;
            dir.normalize();
            dir.scale((dist < w) ? dist : w);
        }
    }
    fn_80115D8C(p, a, &b);
    *out = dir;
    *out += b;
}

extern "C" void fn_80115D8C(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* out) {
    extern int __float_epsilon[];
    extern f32 lbl_8053C6F4;
    extern f32 lbl_8053C6FC;
    extern f32 lbl_8053C700;
    extern f32 lbl_8053C704;
    extern f32 lbl_8053C708;
    extern f32 lbl_8053C70C;
    extern f32 sincosTable___5JMath[];
    extern void fn_801CD950(f32* value, f32 target, f32 step);

    f32 az = a->z;
    out->zero();
    if (az <= lbl_8053C6E4) {
        f32 dx = a->x - *(f32*)(p + 0xc);
        f32 dy = a->y - *(f32*)(p + 0x10);
        f32 dxx = dx * dx;
        f32 dyy = dy * dy;
        f32 d2 = dxx + dyy;
        if (d2 <= lbl_8053C6FC) {
            f32 s = sincosTable___5JMath[4000];
            f32 c = sincosTable___5JMath[4001];
            f32 x = dx * c - dy * s;
            f32 y = dx * s + dy * c;
            f32 r2 = x * x + y * y;
            f32 len;
            if (r2 <= lbl_8053C6F4 * *(f32*)__float_epsilon) {
                x = 0.0f;
                y = lbl_8053C700;
            } else {
                if (r2 <= 0.0f) {
                    len = r2;
                } else {
                    f32 y2 = (f32)__frsqrte(r2);
                    len = r2 * ((0.5f * y2) * (3.0f - r2 * (y2 * y2)));
                }
                fn_801CD950(&len, lbl_8053C704, lbl_8053C708);
                if (r2 > lbl_8053C6F4 * *(f32*)__float_epsilon) {
                    if (r2 > 0.0f) {
                        f32 y2 = (f32)__frsqrte(r2);
                        r2 = (0.5f * y2) * (3.0f - r2 * (y2 * y2));
                    }
                    x *= r2;
                    y *= r2;
                }
                x *= len;
                y *= len;
            }
            x += *(f32*)(p + 0xc);
            y += *(f32*)(p + 0x10);
            JGeometry::TVec3<f32> pos;
            pos.x = x;
            pos.y = y;
            pos.z = a->z;
            out->sub(pos, *a);
            out->z = lbl_8053C70C;
        }
    }
}

extern "C" void fn_80115F9C(u8* this_, s32 state) {
    extern void fn_801EB710(void*, s32, void*);
    extern void fn_80134DE4(void*, s32, s32);
    extern void* lbl_8053AAF8;
    extern void* fn_8011921C(void);
    extern void fn_80118454(void);
    extern void fn_80230FD0(s32, s32);
    extern s32 fn_8013CC50(f32, s32, void*, s32, s32, s32, s32, s32, s32);
    extern void fn_801F0E34(void*, s32, s32);
    extern void fn_801EE434(void*);
    extern s32 fn_80119DD0(void);
    extern void fn_80119998(s32, s32, s32, s32, s32, s32, s32, s32);
    extern void* fn_801F856C(void);
    extern u32 fn_801F7A08(void*, u32);
    extern u32 fn_801F666C(void*, u32);
    extern void fn_802B3A3C(void);
    extern void fn_8022FE80(s32, s32, void*, s32, s32, f32);
    extern u8 fn_8038BD08(s32, s32, s32, void*, s32);
    extern void fn_80136798(void*, s32, s32);
    extern u8* sManager__8JUTVideo;
    extern u8 lbl_8050EC80[];
    extern u8 lbl_80529DEC[];

    u32 t;
    switch (state) {
    case 0:
        fn_801EB710(this_ + 0x2a8, *(s32*)(this_ + 4), this_ + 0x308);
        break;
    case 1:
        *(f32*)(this_ + 0x300) = lbl_8053C6E0;
        fn_80134DE4(lbl_8053AAF8, 5, 0);
        break;
    case 2:
        fn_8011921C();
        fn_80118454();
        break;
    case 3:
        *(f32*)(this_ + 0x40) = lbl_8053C6D0;
        for (s32 i = 0; i < 4; i++) {
            fn_80230FD0(i, 0x10003);
        }
        break;
    case 4:
        *(u8*)(this_ + 0x11d) = 1;
        *(s32*)(this_ + 0x314) = fn_8013CC50(lbl_8053C6D8, *(s32*)(this_ + 4), this_ + 0xc, 0x228, 1, 1, 0, 0, 1);
        *(s32*)(this_ + 0x318) = fn_8013CC50(lbl_8053C6D8, *(s32*)(this_ + 4), this_ + 0xc, 0x229, 1, 1, 0, 0, 1);
        fn_801F0E34(this_, 0x40089, 0);
        break;
    case 5:
        fn_801F0E34(this_, 0x40041, 0);
        break;
    case 6:
        *(u8*)(this_ + 0x11d) = 0;
        fn_801EE434(*(void**)(this_ + 0x314));
        *(s32*)(this_ + 0x314) = 0;
        fn_801EE434(*(void**)(this_ + 0x318));
        *(s32*)(this_ + 0x318) = 0;
        *(f32*)(this_ + 0x300) = lbl_8053C6D0;
        *(u8*)(this_ + 0x304) = 1;
        fn_801F0E34(this_, 0x400ba, 0);
        break;
    case 7:
        fn_80119998(fn_80119DD0(), 0x78, 0, 1, 0, 0, 0x46, 0);
        t = fn_801F7A08(fn_801F856C(), 0x53574556);
        if (fn_801F666C(fn_801F856C(), t)) {
            fn_802B3A3C();
        }
        break;
    case 8: {
        JGeometry::TVec3<f32> v;
        *(u8*)(this_ + 0x11d) = 1;
        v.x = (f32)(s16)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4) * lbl_8053C6F0;
        v.y = (f32)(s16)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6) * lbl_8053C6F0 - lbl_8053C6E4;
        v.z = lbl_8053C6D0;
        fn_8022FE80(0, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 1, 0, v.x);
        if (fn_8038BD08(0, 0x4b4, *(s32*)(this_ + 4), &v, 0x62)) {
            fn_8011921C();
            fn_80118454();
            fn_801F0E34(this_, 0x4006c, 0);
        }
        break;
    }
    case 9: {
        u8* e;
        *(u8*)(lbl_80529DEC + 0x237) = 6;
        *(s32*)(lbl_80529DEC + 0x118) = 0;
        *(s32*)(lbl_80529DEC + 0x11c) = 0;
        e = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
        e[0x85] |= 1;
        fn_80136798(lbl_8053AAF8, 6, 0);
        break;
    }
    case 10:
    case 11:
        break;
    }
    *(s32*)(this_ + 0x230) = state;
}

extern "C" s32 fn_801162B8(char* p) {
    switch (*(s32*)(p + 0x230)) {
    case 11:
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801162D8(char* p) {
    return *(s32*)(p + 0x230);
}

extern "C" void fn_801162E0(void* this_) {
    extern s32 lbl_804649A4[];
    extern void* fn_8011921C(void);
    extern void fn_80115F9C(void*, s32);

    if (*(s32*)((char*)fn_8011921C() + 4) == 2) {
        s32 v = *(s32*)((char*)fn_8011921C() + 8);
        if (v == lbl_804649A4[1]) {
            fn_80115F9C(this_, 1);
        } else if (v == lbl_804649A4[2]) {
            fn_80115F9C(this_, 2);
        } else if (v == lbl_804649A4[3]) {
            fn_80115F9C(this_, 3);
        } else if (v == lbl_804649A4[4]) {
            fn_80115F9C(this_, 4);
        } else if (v == lbl_804649A4[5]) {
            fn_80115F9C(this_, 5);
        } else if (v == lbl_804649A4[6]) {
            fn_80115F9C(this_, 6);
        } else if (v == lbl_804649A4[7]) {
            fn_80115F9C(this_, 7);
        } else if (v == lbl_804649A4[8]) {
            fn_80115F9C(this_, 8);
        } else if (v == lbl_804649A4[9]) {
            fn_80115F9C(this_, 9);
        } else if (v == lbl_804649A4[10]) {
            fn_80115F9C(this_, 10);
        } else if (v == lbl_804649A4[11]) {
            fn_80115F9C(this_, 11);
        }
    }
}

extern "C" void fn_80116458(u8* this_) {
    EffArgs args;
    f32 vec[4][3];
    if (*(s32*)(this_ + 0x230) >= 10) {
        fn_801158B8();
    }
    fn_8010DF58(this_);
    args.f10.w = -1;
    args.f14.w = -1;
    for (u8 i = 0; i < 0x10; i++) {
        args.order[i] = i;
    }
    args.x30 = -1;
    args.f10.w = -1;
    args.f14.w = 0;
    args.ptr = 0;
    args.b1c = 0;
    args.b1d = 0;
    args.b1e = 0;
    args.b1f = 1;
    args.b20 = 1;
    args.b21 = 0;
    args.b22 = 0;
    args.b23 = 0;
    args.b24 = 0;
    args.b25 = 0;
    args.b26 = 1;
    args.w28 = 3;
    args.b2c = 1;
    args.b2d = 0;
    args.b2e = 0;
    args.x34 = 0;
    args.x38 = 2;
    args.x30 = 8;
    args.f10.b[3] = *(u8*)(this_ + 0x234);
    args.b1c = 1;
    args.b1d = 1;
    f32 zero = lbl_8053C6D0;
    f32 s = lbl_8053C730;
    vec[1][0] = zero;
    vec[2][1] = zero;
    vec[3][2] = zero;
    vec[0][0] = s;
    vec[0][1] = zero;
    vec[0][2] = zero;
    vec[1][1] = zero;
    vec[1][2] = s;
    vec[2][0] = zero;
    vec[2][2] = zero;
    vec[3][0] = zero;
    vec[3][1] = s;
    args.ptr = vec;
    s32 idx = *(s32*)(this_ + 0x254);
    if (idx < 4) {
        u8* p = this_ + idx * 4;
        void* tgt = *(void**)(p + 0x31c);
        f32* pos = (f32*)(this_ + 0xc);
        if (tgt != 0 && *(s32*)(this_ + 4) < 8) {
            fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, tgt, &args);
        }
    }
}

extern "C" void fn_8011661C(u8* this_) {
    fn_8010DF78();
    if (*(s32*)(this_ + 0x230) >= 2 && *(s32*)(this_ + 0x230) <= 0xa) {
        u8* obj = *(u8**)((u8*)lbl_8053AB10 + 0x30);
        if (obj[0x284] == 0) {
            f32 value = lbl_8053C734;
            obj[0x284] = 1;
            *(f32*)(obj + 0x28c) = value;
        }
        fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), this_ + 0xc);
        JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        u8* p = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        if (p[0x7f5] == 0) {
            p[0x7f4] = 1;
            *(s32*)(p + 0x7f8) = 4;
            *(f32*)(p + 0x7fc) = pos.x;
            *(f32*)(p + 0x800) = pos.y;
            *(f32*)(p + 0x804) = pos.z;
            p[0x7f6] = 0;
        }
    }
    switch (*(u32*)(this_ + 0x230)) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 9:
    case 11:
    default:
        break;
    case 3:
        if (*(f32*)(this_ + 0x28) - *(f32*)(this_ + 0x10) <= lbl_8053C710) {
            fn_801CD950(this_ + 0x40, lbl_8053C714, lbl_8053C718);
        } else {
            fn_801CD950(this_ + 0x40, lbl_8053C6D0, lbl_8053C71C);
        }
        if (*(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x28) >= lbl_8053C720) {
            fn_8011921C();
            fn_801183BC();
        }
        fn_80115A7C((char*)this_);
        break;
    case 4:
        fn_80115A7C((char*)this_);
        break;
    case 6:
        if (this_[0x234] < 0xfe) {
            this_[0x234] += 5;
            if (this_[0x234] >= 0xfe) {
                this_[0x234] = 0xfe;
            }
        }
        if (lbl_8053AA8A == 0) {
            lbl_8053AA88 = 0;
            lbl_8053AA8A = 1;
        }
        *(f32*)(this_ + 0x14) = lbl_8053C724 * JMath::sincosTable_.mTable[(u16)lbl_8053AA88 >> 5].first + lbl_8053C704;
        lbl_8053AA88 += 0x1f4;
        if (*(void**)(this_ + 0x314) != 0) {
            fn_8013CB44(*(void**)(this_ + 0x314), this_ + 0xc, 1, 1, 1);
        }
        if (*(void**)(this_ + 0x318) != 0) {
            fn_8013CB44(*(void**)(this_ + 0x318), this_ + 0xc, 1, 1, 1);
        }
        break;
    case 7:
        if (lbl_8053AA8A == 0) {
            lbl_8053AA88 = 0;
            lbl_8053AA8A = 1;
        }
        *(f32*)(this_ + 0x14) = lbl_8053C724 * JMath::sincosTable_.mTable[(u16)lbl_8053AA88 >> 5].first + lbl_8053C704;
        lbl_8053AA88 += 0x1f4;
        if (*(void**)(this_ + 0x314) != 0) {
            fn_8013CB44(*(void**)(this_ + 0x314), this_ + 0xc, 1, 1, 1);
        }
        if (*(void**)(this_ + 0x318) != 0) {
            fn_8013CB44(*(void**)(this_ + 0x318), this_ + 0xc, 1, 1, 1);
        }
        break;
    case 8:
        if (this_[0x234] != 0) {
            this_[0x234] -= 5;
            if (this_[0x234] == 0) {
                this_[0x234] = 0;
            }
        }
        break;
    case 10:
        switch (*(s32*)((u8*)fn_8011921C() + 8)) {
        case 0x889:
        case 0x8ac:
        case 0x8ca:
            fn_801F0E34(this_, 0x4006b, 0);
            break;
        }
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    }
    *(JGeometry::TVec3<f32>*)(this_ + 0xc) += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);
    if (*(s32*)(this_ + 0x230) <= 6) {
        *(f32*)(this_ + 0x308) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x30c) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x310) = *(f32*)(this_ + 0x14);
    }
    fn_801EB418(this_ + 0x2a8, this_ + 0x308);
    if (fn_801EB648(this_ + 0x2a8)) {
        fn_801F0E34(this_, 0x40051, 0);
    }
    fn_801D1C18(this_ + 0x238);
}

extern "C" char lbl_8049D930[];
extern "C" void fn_8010DF98(void*);
extern "C" s32 fn_804032E8(u32 tag, u32 id);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" s32 lbl_80539F08;
extern "C" char lbl_80464A14[];
extern void* lbl_8053AAF8;
extern f32 lbl_8053C704;
extern f32 lbl_8053C6D0;
extern "C" void fn_801169E8(char* p) {
    fn_8010DF98(p);
    u32* ids = (u32*)lbl_8049D930;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(p + 0x31c + i * 4) = fn_804032E8(0x54494D47, ids[i]);
    }
    void* obj = *(void**)((char*)lbl_8053AAF8 + 0xa4);
    *(s32*)(p + 0x32c) = ((s32 (**)(void*, u32, void*))(*(void**)obj))[6](obj, 0x3f3f3f3f, lbl_80464A14);
    *(f32*)(p + 0x14) = lbl_8053C704;
    *(f32*)(p + 0x3c) = *(f32*)(p + 0x40) = *(f32*)(p + 0x44) = lbl_8053C6D0;
    *(u8*)(p + 0x11d) = 0;
    fn_801D2608(p + 0x238, &lbl_80539F08, 1);
    fn_801D22DC(p + 0x238, 0, 2, 0);
    fn_801D1F14(p + 0x238, lbl_8053C6D0);
    fn_801D2608(p + 0x270, &lbl_80539F08, 1);
    fn_801D22DC(p + 0x270, 0, 2, 0);
    fn_801D1F14(p + 0x270, lbl_8053C6D0);
    *(JGeometry::TVec3<f32>*)(p + 0x308) = *(JGeometry::TVec3<f32>*)(p + 0xc);
}

extern "C" void* fn_80116B08(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_8049D940;
        *(s32*)(p + 0x31c) = 0;
        *(s32*)(p + 0x320) = 0;
        *(s32*)(p + 0x324) = 0;
        *(s32*)(p + 0x328) = 0;
        *(s32*)(p + 0x32c) = 0;
        fn_801EE434(*(void**)(p + 0x314));
        *(s32*)(p + 0x314) = 0;
        fn_801EE434(*(void**)(p + 0x318));
        *(s32*)(p + 0x318) = 0;
        dtor_801EB8CC(p + 0x2a8, -1);
        if (p + 0x270 != 0) {
            if (p + 0x294 != 0) {
                *(void**)(p + 0x294) = lbl_8049CC34;
            }
        }
        if (p + 0x238 != 0) {
            if (p + 0x25c != 0) {
                *(void**)(p + 0x25c) = lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_80116BE8(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049D940;
    *(s32*)(p + 0x230) = 0;
    *(u8*)(p + 0x234) = 0;
    fn_801D267C(p + 0x238);
    fn_801D267C(p + 0x270);
    fn_801EB950(p + 0x2a8);
    *(s32*)(p + 0x314) = 0;
    *(s32*)(p + 0x318) = 0;
    *(s32*)(p + 0x32c) = 0;
    *(s32*)(p + 0x31c) = 0;
    *(s32*)(p + 0x320) = 0;
    *(s32*)(p + 0x324) = 0;
    *(s32*)(p + 0x328) = 0;
    return p;
}

