#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8010E074(u8* this_);
extern "C" void fn_801D267C(u8* p);
extern u8 lbl_8049D740[];
extern u8 lbl_8049CC34[];
extern const f32 lbl_8053C628;
extern const f32 lbl_8053C65C;

extern const f32 lbl_8053C644;
extern const f32 lbl_8053C64C;
extern const f32 lbl_8053C650;
extern const f32 lbl_8053C654;
extern "C" void fn_8010F668(f32 m[3][4], f32 axis[3], f32 angle);
typedef struct MtxBox {
    Mtx m;
} MtxBox;
typedef struct MtxD {
    f64 d[6];
} MtxD;
extern "C" void* fn_801902C0(void);

extern "C" s32 fn_801123C8(s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0:
            switch (param_2) {
                case 0: return 0x2fd;
                case 1: return 0x307;
                case 2: return 0x301;
                case 3: return 0x2ff;
                case 4: return 0x305;
                case 5:
                default: return 0x303;
            }
        case 1:
            switch (param_2) {
                case 0: return 0x2fe;
                case 1: return 0x308;
                case 2: return 0x302;
                case 3: return 0x300;
                case 4: return 0x306;
                case 5:
                default: return 0x304;
            }
        case 2:
            switch (param_2) {
                case 0: return 0x2cf;
                case 1: return 0x2de;
                case 2: return 0x2d5;
                case 3: return 0x2d2;
                case 4: return 0x2db;
                case 5:
                default: return 0x2d8;
            }
        case 3:
            switch (param_2) {
                case 0: return 0x2d0;
                case 1: return 0x2df;
                case 2: return 0x2d6;
                case 3: return 0x2d3;
                case 4: return 0x2dc;
                case 5:
                default: return 0x2d9;
            }
        case 4:
            switch (param_2) {
                case 0: return 0x2d1;
                case 1: return 0x2e0;
                case 2: return 0x2d7;
                case 3: return 0x2d4;
                case 4: return 0x2dd;
                case 5:
                default: return 0x2da;
            }
        case 5:
        default:
            switch (param_2) {
                case 0: return 0x2e4;
                case 1: return 0x2e9;
                case 2: return 0x2e6;
                case 3: return 0x2e5;
                case 4: return 0x2e8;
                case 5:
                default: return 0x2e7;
            }
    }
}

extern "C" void fn_80112654(u8* this_, s32 n) {
    extern s32 fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
    extern void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
    extern void fn_801D1F14(void* p, f32 f);
    extern const f32 lbl_8053C648;

    switch ((u32)n) {
    case 3:
        *(s32*)(this_ + 0x298) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, fn_801123C8(0, *(s32*)(this_ + 0x234)), 0, 0, 0, 0, 1);
        *(s32*)(this_ + 0x29c) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, fn_801123C8(1, *(s32*)(this_ + 0x234)), 0, 0, 0, 0, 1);
        fn_801D22DC(this_ + 0x260, 0xa, 0, 0);
        fn_801D1F14(this_ + 0x260, lbl_8053C628);
        break;
    case 4:
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, fn_801123C8(2, *(s32*)(this_ + 0x234)), 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, fn_801123C8(3, *(s32*)(this_ + 0x234)), 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, fn_801123C8(4, *(s32*)(this_ + 0x234)), 0, 0, 0, 0, 1);
        *(s32*)(this_ + 0x2a0) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, fn_801123C8(5, *(s32*)(this_ + 0x234)), 0, 0, 0, 0, 1);
        break;
    case 5:
        fn_801D22DC(this_ + 0x260, 0x8, 0x2, 0);
        fn_801D1F14(this_ + 0x260, lbl_8053C628);
        break;
    case 6: {
        u8* e;
        e = *(u8**)(this_ + 0x298);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
            *(s32*)(e + 0x24) = 1;
            *(s32*)(this_ + 0x298) = 0;
        }
        e = *(u8**)(this_ + 0x29c);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
            *(s32*)(e + 0x24) = 1;
            *(s32*)(this_ + 0x29c) = 0;
        }
        e = *(u8**)(this_ + 0x2a0);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
            *(s32*)(e + 0x24) = 1;
            *(s32*)(this_ + 0x2a0) = 0;
        }
        fn_801D22DC(this_ + 0x260, 0xb, 0, 0);
        fn_801D1F14(this_ + 0x260, lbl_8053C628);
        break;
    }
    case 7: {
        JGeometry::TVec3<f32> v(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
        v.y += lbl_8053C648;
        fn_8013CC50(*(s32*)(this_ + 0x4), &v, lbl_8053C644, 0x33b, 0, 0, 0, 0, 1);
        break;
    }
    case 8:
        switch (*(s32*)(this_ + 0x234)) {
        case 0:
            fn_801D22DC(this_ + 0x260, 1, 2, 0);
            break;
        case 1:
            fn_801D22DC(this_ + 0x260, 1, 2, 0);
            break;
        case 2:
            fn_801D22DC(this_ + 0x260, 3, 2, 0);
            break;
        case 3:
            fn_801D22DC(this_ + 0x260, 3, 2, 0);
            break;
        case 4:
            fn_801D22DC(this_ + 0x260, 2, 2, 0);
            break;
        case 5:
            fn_801D22DC(this_ + 0x260, 2, 2, 0);
            break;
        }
        fn_801D1F14(this_ + 0x260, lbl_8053C628);
        break;
    case 9:
        fn_801D22DC(this_ + 0x260, 3, 2, 0);
        fn_801D1F14(this_ + 0x260, lbl_8053C628);
        break;
    case 10:
        fn_801D22DC(this_ + 0x260, 6, 0, 0);
        fn_801D1F14(this_ + 0x260, lbl_8053C628);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, 0xc1, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, 0xc2, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, 0xc3, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053C644, 0xc4, 0, 0, 0, 0, 1);
        break;
    case 11:
        break;
    case 0:
    case 1:
    case 2:
    case 12:
    case 13:
    case 14:
    case 15:
        goto set_state;
    }
    this_[0x230] = 1;
set_state:
    *(s32*)(this_ + 0x238) = n;
}

extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);
extern "C" void fn_80112AE8(u8* this_) {
    Mtx m1;
    Mtx m2;
    Vec v1;
    Vec v2;
    u8* e;
    s32 idx;
    s32 n;
    f32 z;

    *(f32*)(this_ + 0x248) = *(f32*)(this_ + 0x248) + lbl_8053C64C;
    PSMTXTrans(m1, *(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
    v1.y = lbl_8053C628;
    v1.x = lbl_8053C644;
    v1.z = lbl_8053C628;
    fn_8010F668(m1, (f32*)&v1, lbl_8053C650);
    m2[2][3] = lbl_8053C628;
    m2[1][3] = lbl_8053C628;
    m2[0][3] = lbl_8053C628;
    m2[2][2] = lbl_8053C628;
    m2[1][2] = lbl_8053C628;
    m2[0][2] = lbl_8053C628;
    m2[2][1] = lbl_8053C628;
    m2[1][1] = lbl_8053C628;
    m2[0][1] = lbl_8053C628;
    m2[2][0] = lbl_8053C628;
    m2[1][0] = lbl_8053C628;
    m2[0][0] = lbl_8053C628;
    v2.x = lbl_8053C628;
    v2.y = lbl_8053C628;
    v2.z = lbl_8053C644;
    fn_8010F668(m2, (f32*)&v2, *(f32*)(this_ + 0x248));
    PSMTXConcat(m1, m2, m1);

    n = *(s32*)(this_ + 0x244) + 1;
    *(s32*)(this_ + 0x244) = n;
    if (*(s32*)(this_ + 0x244) >= 0xc8) {
        *(s32*)(this_ + 0x244) = 0;
    }
    n = *(s32*)(this_ + 0x244);
    idx = *(s32*)(this_ + 0x234);
    z = *(f32*)(this_ + 0x250);
    e = (u8*)fn_801902C0() + idx * 0x60 + 8;
    if (*(u32*)(e + 0x3c) != 0 && e[0x5c] == 0) {
        e[0x5c] = 1;
        *(f32*)(e + 0x0) = z;
        *(f32*)(e + 0x4) = z;
        *(f32*)(e + 0x8) = z;
        *(MtxD*)(e + 0xc) = *(MtxD*)m1;
        *(f32*)(e + 0x48) = lbl_8053C654;
        *(s32*)(e + 0x4c) = n;
        *(s32*)(e + 0x54) = 0;
        *(s32*)(e + 0x58) = 1;
    }
}

extern "C" s32 fn_80112C8C(void) {
    return 1;
}

extern "C" s32 fn_80112C94(u8* this_) {
    return *(s32*)(this_ + 0x238);
}

extern "C" void fn_80112C9C(u8* this_) {
    extern s32 lbl_80464678[];
    extern void* fn_8011921C(void);
    extern void fn_80112654(u8* this_, s32 n);

    s32* tbl = lbl_80464678;
    s32* p;
    s32* idx_tbl;
    s32 v = *(s32*)((char*)fn_8011921C() + 8);
    if (*(s32*)(this_ + 0x23c) == 0) {
        p = tbl + 0x29;
        idx_tbl = tbl + 0x39;
        if (v == p[2]) {
            fn_80112654(this_, 2);
        } else {
            s32 idx = *(s32*)(this_ + 0x234);
            if (v == p[3] + idx_tbl[idx]) {
                fn_80112654(this_, 3);
            } else if (v == p[4]) {
                fn_80112654(this_, 4);
            } else if (v == p[5]) {
                fn_80112654(this_, 5);
            } else if (v == p[6]) {
                fn_80112654(this_, 6);
            } else if (v == p[7]) {
                fn_80112654(this_, 7);
            } else if (v == p[8]) {
                fn_80112654(this_, 8);
            } else if (v == p[9] + tbl[0x45 + idx]) {
                fn_80112654(this_, 9);
            } else if (v == p[10]) {
                fn_80112654(this_, 10);
            } else if (v == p[11]) {
                fn_80112654(this_, 11);
            } else if (v == p[12] + tbl[0x3f + idx]) {
                fn_80112654(this_, 12);
            } else if (v == p[14]) {
                fn_80112654(this_, 15);
            }
        }
    }
}

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern s32 lbl_80464704[];
extern const char lbl_804647B0[];
extern const f32 lbl_8053C644;
extern "C" void fn_80112E68(u8* this_) {
    fn_8010DF58(this_);
    if (this_[0x230] == 0) {
        s32 id = lbl_80464704[*(s32*)(this_ + 0x234)];
        DrawRec rec;
        fn_801F06F0(this_, lbl_804647B0, id + *(s32*)(this_ + 0x270), &rec, 7, lbl_8053C644, lbl_8053C644);
    }
}

extern const f32 lbl_8053C63C;
static inline f32 dmmdAngle(const f32 angle) {
 return angle*lbl_8053C63C;
}
#pragma opt_propagation off
extern "C" void fn_80112FC8(u8* this_) {
    extern void fn_8010DF78(u8*);
    extern void fn_80239914(void*, s32, s32);
    extern void fn_8030C210(void*, void*);
    extern void fn_8022FEB8(void*, s32, s32, s32, s32);
    extern s32 fn_8022FD8C(s32);
    extern u8 fn_8038AD24(s32, s32, s32, s32, JGeometry::TVec3f, s32);
    extern void fn_8022FF8C(s32, void*, s32, s32, s32, s32);
    extern u8 fn_80388CAC(s32, s32);
    extern u8 fn_801D208C(void*);
    extern void fn_801D22DC(void*, s32, s32, s32);
    extern void fn_801D1F14(void*, f32);
    extern s32 fn_801CD950(f32*, f32, f32);
    extern void fn_801D1C18(void*);
    extern void* lbl_8053AB10;
    extern void* lbl_8053AAF8;
    extern const f32 lbl_8053C62C;
    extern const f32 lbl_8053C630;
    extern const f32 lbl_8053C634;
    extern const f32 lbl_8053C638;
    extern const f32 lbl_8053C63C;
    extern const f32 lbl_8053C640;
    extern const f32 lbl_8053C658;
    struct JMathSinCos { f32 sin; f32 cos; };
    extern JMathSinCos sincosTable___5JMath[];

    fn_8010DF78(this_);
    f32 box[4];
    box[0] = *(f32*)(this_ + 0x60);
    box[1] = *(f32*)(this_ + 0x64);
    box[2] = *(f32*)(this_ + 0x68);
    box[3] = *(f32*)(this_ + 0x6c);
    box[0] += *(f32*)(this_ + 0xc);
    box[1] += *(f32*)(this_ + 0x10);
    box[2] += *(f32*)(this_ + 0xc);
    box[3] += *(f32*)(this_ + 0x10);

    if (*(s32*)(this_ + 0x238) == 0 || *(s32*)(this_ + 0x238) == 1) {
        fn_80239914(box, *(s32*)(this_ + 0x4), *(s32*)(this_ + 0x198));
    }
    if (*(s32*)(this_ + 0x238) >= 2 && *(s32*)(this_ + 0x238) <= 5) {
        fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), this_ + 0xc);
    }

    switch (*(s32*)(this_ + 0x238)) {
    case 0: {
        fn_8022FEB8(box, *(s32*)(this_ + 0x4), *(s32*)(this_ + 0x198), 1, 0);
        s32 r = fn_8022FD8C(*(s32*)(this_ + 0x198));
        if (r >= 0 && r < 4 && (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << r))) {
            JGeometry::TVec3f v = *(JGeometry::TVec3f*)(this_ + 0xc);
            v.y += lbl_8053C658;
            s32 h = *(s32*)(this_ + 0x198);
            s32 room = *(s32*)(this_ + 0x4);
            if (fn_8038AD24(r, 0x23e, h, room, v, 0x20)) {
                *(s32*)(this_ + 0x240) = r;
                fn_80112654(this_, 1);
            }
        }
        break;
    }
    case 1:
        fn_8022FF8C(*(s32*)(this_ + 0x240), box, *(s32*)(this_ + 0x4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(this_ + 0x240), *(s32*)(this_ + 0x198))) {
            *(s32*)(this_ + 0x240) = -1;
            fn_80112654(this_, 0);
        }
        break;
    case 2:
        break;
    case 3:
        if (fn_801D208C(this_ + 0x260) && *(s32*)(this_ + 0x268) == 0xa) {
            fn_801D22DC(this_ + 0x260, 0, 2, 0);
            fn_801D1F14(this_ + 0x260, lbl_8053C628);
        }
        break;
    case 4:
        if (fn_801D208C(this_ + 0x260) && *(s32*)(this_ + 0x268) == 0xa) {
            fn_801D22DC(this_ + 0x260, 0, 2, 0);
            fn_801D1F14(this_ + 0x260, lbl_8053C628);
        }
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        break;
    case 12: {
        *(f32*)(this_ + 0x248) += lbl_8053C630;
        fn_801CD950((f32*)(this_ + 0x24c), lbl_8053C634, lbl_8053C638);
        f32 rad = JMath::atanTable_.atan2_(*(f32*)(this_ + 0x254) - *(f32*)(this_ + 0xc), *(f32*)(this_ + 0x258) - *(f32*)(this_ + 0x10));
        rad *= lbl_8053C63C;
        s32 ang = (s32)rad;
        *(f32*)(this_ + 0x3c) = *(f32*)(this_ + 0x24c) * sincosTable___5JMath[(u16)ang >> 5].sin;
        *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x24c) * sincosTable___5JMath[(u16)ang >> 5].cos;
        s32 r29 = fn_801CD950((f32*)(this_ + 0xc), *(f32*)(this_ + 0x254), *(f32*)(this_ + 0x3c));
        s32 r30 = fn_801CD950((f32*)(this_ + 0x10), *(f32*)(this_ + 0x258), *(f32*)(this_ + 0x40));
        fn_801CD950((f32*)(this_ + 0x250), lbl_8053C638, lbl_8053C640);
        u8 done;
        if (r29 == 0 && r30 == 0) {
            done = 1;
        } else {
            done = 0;
        }
        if (done) {
            fn_80112654(this_, 0xd);
        }
        break;
    }
    case 13:
        fn_801CD950((f32*)(this_ + 0x250), lbl_8053C628, lbl_8053C62C);
        break;
    case 14:
        break;
    case 15:
        this_[0x11d] = 0;
        break;
    }

    fn_801D1C18(this_ + 0x260);
    if (this_[0x230] != 0) {
        fn_80112AE8(this_);
    }
}
#pragma opt_propagation reset
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F7A08(void* a, u32 b);
extern "C" void* fn_801F666C(void* a, void* b);
extern "C" void fn_80113358(u8* self) {
    void* p = fn_801F666C(fn_801F856C(), fn_801F7A08(fn_801F856C(), 0x444d474c));
    if (p != 0) {
        JGeometry::setTVec3f((f32*)((u8*)p + 0xc), (f32*)(self + 0x254));
    }
}

extern "C" void fn_8010DF98(u8* this_);
extern "C" void fn_801D2608(void* p, void* a, s32 n);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p, f32 f);
extern u8 lbl_8049D710[];
extern "C" void fn_801133C0(u8* this_) {
    fn_8010DF98(this_);
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0x1f;
    fn_801D2608(this_ + 0x260, lbl_8049D710, 0xc);
    fn_801D22DC(this_ + 0x260, 5, 2, 0);
    fn_801D1F14(this_ + 0x260, lbl_8053C628);
}

extern "C" void* fn_8011342C(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_8049D740;
        fn_801EE434(*(void**)(p + 0x298));
        *(s32*)(p + 0x298) = 0;
        fn_801EE434(*(void**)(p + 0x29c));
        *(s32*)(p + 0x29c) = 0;
        fn_801EE434(*(void**)(p + 0x2a0));
        *(s32*)(p + 0x2a0) = 0;
        if (p + 0x260 != 0) {
            if (p + 0x284 != 0) {
                *(void**)(p + 0x284) = lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_8010E074(u8* this_);
extern "C" void fn_801D267C(u8* p);
extern u8 lbl_8049D740[];
extern "C" u8* fn_801134DC(u8* this_) {
    fn_8010E074(this_);
    *(u8**)(this_ + 0x0) = lbl_8049D740;
    f32 b = lbl_8053C65C;
    *(u8*)(this_ + 0x230) = 0;
    f32 a = lbl_8053C628;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = -1;
    *(s32*)(this_ + 0x244) = 0;
    *(f32*)(this_ + 0x248) = a;
    *(f32*)(this_ + 0x24c) = a;
    *(f32*)(this_ + 0x250) = b;
    fn_801D267C(this_ + 0x260);
    *(s32*)(this_ + 0x298) = 0;
    *(s32*)(this_ + 0x29c) = 0;
    *(s32*)(this_ + 0x2a0) = 0;
    return this_;
}

