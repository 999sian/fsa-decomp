// Game TU 801B27DC-801B3F60 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" u8* fn_802D6A9C(void);

#pragma opt_propagation off
extern "C" u8 fn_801B27DC(void* this_, s32 room, void* pos) {
    s32 r = room;
    void* p = pos;
    s32 kind = (u16)fn_8022461C(p, r);
    s32 attr = (u16)fn_80226850(p, r);
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
#pragma opt_propagation reset
extern "C" void fn_801F06F0(void* this_, const char* name, s32 idx, s32 a, s32 b, f32 x, f32 y);
extern const char lbl_804690E0[];

extern "C" void fn_801B2998(u8* this_) {
    s32 f = *(s32*)(this_ + 0x308);
    if (f == 0 || (f & 2)) {
        fn_801F06F0(this_, lbl_804690E0, *(s32*)(this_ + 0x320) + 0x9B, 0, 7, 1.0f, 1.0f);
    }
}

#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

struct LimtTable {
    s32 dir[4];
    s32 anim[5];
    s32 time[5];
};
extern LimtTable lbl_804A3660;
extern u8 lbl_8053ABE8;
extern s32 lbl_8053ABEC;
extern u8 lbl_8053ABF0;
extern u8* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern f32 lbl_8053E930, lbl_8053E934, lbl_8053E938, lbl_8053E93C, lbl_8053E940, lbl_8053E944, lbl_8053E948,
    lbl_8053E94C, lbl_8053E950, lbl_8053E954, lbl_8053E958, lbl_8053E95C, lbl_8053E960, lbl_8053E964, lbl_8053E968,
    lbl_8053E96C, lbl_8053E970, lbl_8053E974, lbl_8053E978, lbl_8053E97C, lbl_8053E980, lbl_8053E984, lbl_8053E988,
    lbl_8053E98C, lbl_8053E9A8, lbl_8053E9AC, lbl_8053E9B0;
extern const f64 lbl_8053E990, lbl_8053E998, lbl_8053E9A0;
extern "C" {
void* fn_801F856C(void);
u8* fn_801F666C(void* mgr, s32 id);
void fn_8022ADE4(void);
void fn_802D79E8(u8*, s32, s32, f32, f32);
void fn_802D79A4(u8*, s32, f32, f32, f32);
u8 fn_8023F264(s32);
void fn_800FDEA0(void*, void*, void*, s32*, void*, s32, f32);
void fn_801F3D94(void*, s32);
void fn_801F71A4(void*, f32, f32, f32);
void fn_801EEC98(void*, s32, s32, s32*, f32*, s32, s32, s32);
void fn_801F2618(void*, void*, s32);
s32 fn_801F2718(void*, u32);
void fn_801F0E34(void*, s32, s32);
void* fn_8013CC50(void* a, void* pos, s32 kind, s32 b, s32 c, s32 d, void* e, s32 f, f32 scale);
u8 fn_800FE3EC(void*, s32, void*, s32);
s32 fn_8023DE58(s32);
s32 fn_8022EA0C(s32);
u8 fn_80230188(s32);
u8 fn_8022DCD8(s32);
u8 fn_80236B50(s32);
u8 fn_8022D534(s32);
Vec* fn_8023E724(s32);
s32 fn_80138A30(void*);
void fn_80458FF0(void*, s32, s32, s32);
void fn_8022ADCC(void);
u8 fn_802DCD0C(u8*);
}
struct LimtState {
    JGeometry::TVec3<f32> v;
    u32 box[4];
};
static inline f32 limtSqrt(const f32 mag) {
    if (mag > lbl_8053E934) {
        f64 xd = mag;
        f64 tmpd = __frsqrte(xd);
        tmpd = lbl_8053E990 * tmpd * (lbl_8053E998 - (tmpd * tmpd * xd));
        tmpd = lbl_8053E990 * tmpd * (lbl_8053E998 - (tmpd * tmpd * xd));
        tmpd = lbl_8053E990 * tmpd * (lbl_8053E998 - (tmpd * tmpd * xd));
        return (f32)(xd * tmpd);
    } else if (mag < lbl_8053E9A0) {
        return *(f32*)__float_nan;
    } else if (fpclassify(mag) == 1) {
        return *(f32*)__float_nan;
    } else {
        return mag;
    }
}
static inline f32 limtRandom() {
    union {
        f32 f;
        u32 s;
    } out;
    JMath::TRandom_fast_* rnd = (JMath::TRandom_fast_*)(lbl_8053AAF8 + 0xb4);
    out.s = (rnd->get() >> 9) | 0x3f800000;
    return out.f - lbl_8053E930;
}

extern "C" void fn_801B29EC(u8* p) {
    LimtTable* tbl = &lbl_804A3660;
    s32 room = *(s32*)(p + 0x4);
    u8* m = fn_802D6A9C();
    u32* b = room < 8 ? (u32*)(m + 0xcc) : (u32*)(m + 0xdc);
    LimtState s;
    s32 rm;
    s32 out;
    s32 hit;
    f32 hitf;
    s.v.x = lbl_8053E934;
    s.v.y = lbl_8053E934;
    s.v.z = lbl_8053E934;
    s.box[0] = b[0];
    s.box[1] = b[1];
    s.box[2] = b[2];
    s.box[3] = b[3];
    rm = *(s32*)(p + 0x4);
    fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, lbl_8053E930, lbl_8053E934);
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023F264(i)) {
            fn_802D79A4(fn_802D6A9C(), i, lbl_8053E938, lbl_8053E930, lbl_8053E930);
        }
    }
    if (*(s32*)(p + 0x2f8) != 0) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
        fn_800FDEA0(p + 0x230, &pos, &s, &rm, &out, 0x200, lbl_8053E93C);
    }
    fn_801F3D94(p, 1);
    fn_801F71A4(p + 0x3c, *(f32*)(p + 0x334), lbl_8053E940, lbl_8053E930);
    fn_801F71A4(p + 0x40, *(f32*)(p + 0x338), lbl_8053E940, lbl_8053E930);
    *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
    fn_801EEC98(p, *(s32*)(p + 0x198), 0, &hit, &hitf, 0, 0, 0);
    JGeometry::TVec3<f32> v2;
    v2.x = v2.y = v2.z = lbl_8053E934;
    if (*(s32*)(p + 0x2f8) != 9) {
        fn_801F2618(p, &v2, 0);
    }
    *(s32*)(p + 0x108) = 10000;
    if (*(s32*)(p + 0x308) == 0 || *(s32*)(p + 0x2f8) == 7) {
        if (*(s32*)(p + 0x2f8) == 2 || *(s32*)(p + 0x2f8) == 6 || *(s32*)(p + 0x2f8) == 7) {
            if (*(s32*)(p + 0x314) == 0) {
                s32 n = *(s32*)((u8*)fn_801F856C() + 0x1008);
                *(u8*)(p + 0x32c) = 0;
                for (s32 i = 0; i < n; i++) {
                    u8* a = ((u8**)((u8*)fn_801F856C() + 8))[i];
                    if (a == NULL || *(u8*)(a + 0x1a8) != 1) {
                        continue;
                    }
                    *(f32*)(p + 0x60) = lbl_8053E944;
                    *(f32*)(p + 0x64) = lbl_8053E948;
                    *(f32*)(p + 0x68) = lbl_8053E94C;
                    *(f32*)(p + 0x6c) = lbl_8053E950;
                    if (*(s32*)(p + 0x308) == 0 && fn_801F2718(p, *(u32*)(a + 0x1a0)) >= 0) {
                        *(f32*)(p + 0x334) = lbl_8053E934;
                        *(f32*)(p + 0x44) = lbl_8053E934;
                        *(f32*)(p + 0x40) = lbl_8053E934;
                        *(f32*)(p + 0x3c) = lbl_8053E934;
                        *(s32*)(p + 0x2f8) = 0xb;
                        break;
                    }
                    if (*(s32*)(p + 0x2f8) == 7) {
                        *(f32*)(p + 0x60) = lbl_8053E968;
                        *(f32*)(p + 0x64) = lbl_8053E958;
                        *(f32*)(p + 0x68) = lbl_8053E96C;
                        *(f32*)(p + 0x6c) = lbl_8053E960;
                        if (fn_801F2718(p, *(u32*)(a + 0x1a0)) >= 0) {
                            *(u8*)(p + 0x32c) = 1;
                            break;
                        }
                    } else if (*(u32*)(a + 0x1a0) != 'KETH') {
                        *(f32*)(p + 0x60) = lbl_8053E954;
                        *(f32*)(p + 0x64) = lbl_8053E958;
                        *(f32*)(p + 0x68) = lbl_8053E95C;
                        *(f32*)(p + 0x6c) = lbl_8053E960;
                        if (fn_801F2718(p, *(u32*)(a + 0x1a0)) >= 0) {
                            *(s32*)(p + 0x304) = (s32)(lbl_8053E93C * limtRandom()) + 0x14;
                            if (*(s32*)(p + 0x2f8) != 6) {
                                fn_801F0E34(p, 0x400b5, 0);
                                Vec q;
                                q.x = *(f32*)(p + 0xc);
                                q.y = *(f32*)(p + 0x10);
                                q.z = *(f32*)(p + 0x14);
                                q.y -= lbl_8053E964;
                                fn_8013CC50((void*)*(s32*)(p + 0x4), &q, 0x33b, 0, 1, 0, 0, 1, lbl_8053E930);
                            }
                            hit = *(s32*)(p + 0x98);
                            *(f32*)(p + 0x334) = lbl_8053E934;
                            *(f32*)(p + 0x44) = lbl_8053E934;
                            *(f32*)(p + 0x40) = lbl_8053E934;
                            *(f32*)(p + 0x3c) = lbl_8053E934;
                            *(u8*)(p + 0x32d) = 1;
                            *(s32*)(p + 0x2f8) = 6;
                            break;
                        }
                    }
                }
            }
            *(s32*)(p + 0x314) = (*(s32*)(p + 0x314) + 1);
            *(s32*)(p + 0x314) &= 3;
        }
    }
    *(f32*)(p + 0x60) = lbl_8053E944;
    *(f32*)(p + 0x64) = lbl_8053E948;
    *(f32*)(p + 0x68) = lbl_8053E94C;
    *(f32*)(p + 0x6c) = lbl_8053E950;
    if (*(s32*)(p + 0x324) >= 0) {
        *(s32*)(p + 0x328) += lbl_8053ABEC / 4;
        lbl_8053ABEC = 0;
        if (*(s32*)(p + 0x328) > 5) {
            *(s32*)(p + 0x328) = 5;
        }
        u8* a = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x324));
        if (a != 0) {
            s32 v = *(s32*)(p + 0x328);
            *(s32*)(a + 0x250) = *(s32*)(p + 0x198);
            *(f32*)(a + 0x254) = lbl_8053E970;
            *(s32*)(a + 0x24c) = v;
        }
    }
    switch (*(s32*)(p + 0x2f8)) {
    case 0: {
        JGeometry::TVec3<f32> pos2(*(JGeometry::TVec3<f32>*)(p + 0xc));
        if (!fn_800FE3EC(p + 0x230, *(s32*)(p + 0x330), &pos2, *(s32*)(p + 0x4))) {
            break;
        }
    }
    case 1:
        *(s32*)(p + 0x310) = -1;
        *(u8*)(p + 0x2fc) = 0;
        *(u8*)(p + 0x32d) = 0;
        *(f32*)(p + 0x340) = *(f32*)(p + 0x10);
        *(s32*)(p + 0x31c) = 0;
        *(s32*)(p + 0x2f8) = 2;
    case 2: {
        s32 id = fn_801F2718(p, 'ZDCO');
        u8* a;
        if (id >= 0 && (a = fn_801F666C(fn_801F856C(), id)) != 0 && *(u16*)(a + 0x94) == 0) {
            *(s32*)(a + 0x25c) = 1;
            JGeometry::TVec3<f32> tmp(*(JGeometry::TVec3<f32>*)(p + 0xc));
            *(f32*)(a + 0x26c) = tmp.x;
            *(f32*)(a + 0x270) = tmp.y;
            *(f32*)(a + 0x274) = tmp.z;
            *(s32*)(p + 0x310) = id;
            switch (*(s32*)(a + 0x250)) {
            case 4:
                *(s32*)(p + 0x2f8) = 3;
                break;
            case 6:
                *(s32*)(p + 0x318) = 0;
                *(s32*)(p + 0x2f8) = 8;
                break;
            case 2:
                *(f32*)(p + 0x334) = lbl_8053E934;
                *(f32*)(p + 0x44) = lbl_8053E934;
                *(f32*)(p + 0x40) = lbl_8053E934;
                *(f32*)(p + 0x3c) = lbl_8053E934;
                *(s32*)(p + 0x320) = *(s32*)(p + 0x98) << 3;
                *(s32*)(p + 0x304) = 100;
                *(s32*)(p + 0x2f8) = 7;
                break;
            default:
                if (hit >= 0) {
                    *(s32*)(p + 0x98) = hit;
                    *(s32*)(p + 0x320) = *(s32*)(p + 0x98) << 3;
                    *(s32*)(p + 0x300) = 5;
                }
                *(s32*)(p + 0x2f8) = 5;
                break;
            }
            break;
        }
        if (lbl_8053E934 == v2.y) {
            if (*(s32*)(p + 0x308) == 0 && *(f32*)(p + 0x340) < *(f32*)(p + 0x10) - lbl_8053E964) {
                *(f32*)(p + 0x3c) = lbl_8053E934;
                *(f32*)(p + 0x334) = lbl_8053E934;
                *(u8*)(p + 0x2fc) = 1;
            }
        } else {
            *(f32*)(p + 0x340) = *(f32*)(p + 0x10);
            if (*(u8*)(p + 0x2fc) == 1) {
                *(s32*)(p + 0x2f8) = 0xb;
                break;
            }
        }
        *(f32*)(p + 0x338) = lbl_8053E974;
        *(f32*)(p + 0x334) = s.v.x;
        if (s.v.x != lbl_8053E934) {
            if ((f32)__fabs(*(f32*)(p + 0xc) - *(f32*)(p + 0x18)) <= lbl_8053E978) {
                *(s32*)(p + 0x31c) = *(s32*)(p + 0x31c) + 1;
                if (*(s32*)(p + 0x31c) > 10) {
                    *(s32*)(p + 0x2f8) = 0;
                }
            } else {
                *(s32*)(p + 0x31c) = 0;
            }
        }
        *(s32*)(p + 0x98) = 1;
        if (*(f32*)(p + 0x334) > lbl_8053E934) {
            *(s32*)(p + 0x98) = 0;
        }
        break;
    }
    case 3:
        *(f32*)(p + 0x33c) = lbl_8053E934;
        *(f32*)(p + 0x338) = lbl_8053E934;
        *(f32*)(p + 0x334) = lbl_8053E934;
        *(f32*)(p + 0x44) = lbl_8053E934;
        *(f32*)(p + 0x40) = lbl_8053E934;
        *(f32*)(p + 0x3c) = lbl_8053E934;
        *(s32*)(p + 0x304) = 0;
        *(s32*)(p + 0x2f8) = 4;
    case 4: {
        s32 id = *(s32*)(p + 0x310);
        if (id < 0) {
            break;
        }
        u8* a = fn_801F666C(fn_801F856C(), id);
        if (a == 0) {
            *(s32*)(p + 0x2f8) = 0;
            break;
        }
        Vec q;
        q.x = *(f32*)(a + 0xc);
        q.y = *(f32*)(a + 0x10);
        q.z = *(f32*)(a + 0x14);
        q.x += lbl_8053E94C;
        if ((f32)__fabs(*(f32*)(p + 0xc) - q.x) > lbl_8053E97C) {
            fn_801F71A4(p + 0xc, q.x, lbl_8053E980, lbl_8053E984);
            *(s32*)(p + 0x98) = 0;
            if (*(f32*)(p + 0xc) > q.x) {
                *(s32*)(p + 0x98) = 1;
            }
            *(s32*)(p + 0x304) = 0x14;
            break;
        }
        *(f32*)(p + 0xc) = q.x;
        *(s32*)(p + 0x98) = 3;
        *(f32*)(p + 0x338) = lbl_8053E988;
        if (*(s32*)(p + 0x304) == 0 && v2.y < lbl_8053E934) {
            *(u8*)(a + 0x11c) = 0;
            *(s32*)(p + 0x2f8) = 0;
        }
        break;
    }
    case 5:
        *(f32*)(p + 0x334) = lbl_8053E934;
        *(f32*)(p + 0x44) = lbl_8053E934;
        *(f32*)(p + 0x40) = lbl_8053E934;
        *(f32*)(p + 0x3c) = lbl_8053E934;
        *(u8*)(p + 0x32d) = 0;
        *(s32*)(p + 0x2f8) = 6;
    case 6: {
        if (*(u8*)(p + 0x32d) == 0 && hit >= 0) {
            *(s32*)(p + 0x98) = hit;
            *(s32*)(p + 0x320) = *(s32*)(p + 0x98) << 3;
        }
        if (lbl_8053E934 == v2.y) {
            if (*(s32*)(p + 0x308) == 0 && *(f32*)(p + 0x340) < *(f32*)(p + 0x10) - lbl_8053E964) {
                *(f32*)(p + 0x3c) = lbl_8053E934;
                *(f32*)(p + 0x334) = lbl_8053E934;
                *(u8*)(p + 0x2fc) = 1;
            }
        } else {
            *(f32*)(p + 0x340) = *(f32*)(p + 0x10);
            if (*(u8*)(p + 0x2fc) == 1) {
                *(s32*)(p + 0x2f8) = 0xb;
                break;
            }
        }
        *(s32*)(p + 0x300) = 5;
        if (*(u8*)(p + 0x32d) == 1) {
            if (hit >= 0 && *(s32*)(p + 0x304) == 0) {
                *(s32*)(p + 0x2f8) = 1;
            }
            break;
        }
        s32 id = *(s32*)(p + 0x310);
        if (id >= 0) {
            u8* a = fn_801F666C(fn_801F856C(), id);
            if (a == 0 || *(u16*)(a + 0x94) != 0) {
                *(s32*)(p + 0x2f8) = 1;
            }
            break;
        }
        if (hit >= 0 && hitf < lbl_8053E98C && *(s32*)(p + 0x304) == 0) {
            *(s32*)(p + 0x2f8) = 1;
        }
        break;
    }
    case 7: {
        if (*(s32*)(p + 0x304) != 0 || *(u8*)(p + 0x32c) == 1) {
            break;
        }
        s32 id = *(s32*)(p + 0x310);
        if (id >= 0) {
            u8* a = fn_801F666C(fn_801F856C(), id);
            if (a != 0) {
                *(u8*)(a + 0x11c) = 0;
            }
        }
        fn_80458FF0(lbl_8053AF80, 0x1000022, 0, 0);
        *(s32*)(p + 0x310) = -1;
        *(s32*)(p + 0x2f8) = 1;
        break;
    }
    case 8: {
        *(f32*)(p + 0x33c) = lbl_8053E934;
        *(f32*)(p + 0x338) = lbl_8053E934;
        *(f32*)(p + 0x334) = lbl_8053E934;
        *(f32*)(p + 0x44) = lbl_8053E934;
        *(f32*)(p + 0x40) = lbl_8053E934;
        *(f32*)(p + 0x3c) = lbl_8053E934;
        if (hit >= 0) {
            *(s32*)(p + 0x98) = hit;
            *(s32*)(p + 0x320) = *(s32*)(p + 0x98) << 3;
        }
        s32 cnt = 0;
        for (s32 i = 0; i < 4; i++) {
            if (fn_8023F264(i) && *(s32*)(p + 0x4) == fn_8023DE58(i) && i == fn_8022EA0C(i) && !fn_80230188(i) &&
                !fn_8022DCD8(i) && !fn_80236B50(i) && !fn_8022D534(i)) {
                f32 dx = fn_8023E724(i)->x - *(f32*)(p + 0xc);
                f32 dy = fn_8023E724(i)->y - *(f32*)(p + 0x10);
                if (limtSqrt(dx * dx + dy * dy) < lbl_8053E9A8) {
                    cnt++;
                }
            }
        }
        if (cnt < fn_80138A30(lbl_8053AAF8)) {
            break;
        }
        if (hit < 0) {
            break;
        }
        if (hitf > lbl_8053E9AC) {
            break;
        }
        *(s32*)(p + 0x2f8) = 9;
    }
    case 9: {
        s32 id = *(s32*)(p + 0x310);
        if (id < 0) {
            break;
        }
        u8* a = fn_801F666C(fn_801F856C(), id);
        if (a == 0) {
            break;
        }
        Vec q;
        q.x = *(f32*)(a + 0xc);
        q.y = *(f32*)(a + 0x10);
        q.z = *(f32*)(a + 0x14);
        q.x += lbl_8053E94C;
        if ((f32)__fabs(*(f32*)(p + 0xc) - q.x) > lbl_8053E97C) {
            fn_801F71A4(p + 0xc, q.x, lbl_8053E980, lbl_8053E984);
            *(s32*)(p + 0x98) = 0;
            if (*(f32*)(p + 0xc) > q.x) {
                *(s32*)(p + 0x98) = 1;
            }
            *(s32*)(p + 0x304) = 100;
            break;
        }
        *(f32*)(p + 0xc) = q.x;
        *(s32*)(p + 0x98) = 3;
        *(f32*)(p + 0x338) = lbl_8053E930;
        if (*(s32*)(p + 0x304) != 0) {
            break;
        }
        if (!(*(f32*)(p + 0x10) > lbl_8053E964 + *(f32*)&s.box[3])) {
            break;
        }
        *(u8*)(a + 0x11c) = 0;
        fn_8022ADCC();
        *(f32*)(p + 0x33c) = lbl_8053E934;
        *(f32*)(p + 0x338) = lbl_8053E934;
        *(f32*)(p + 0x334) = lbl_8053E934;
        *(f32*)(p + 0x44) = lbl_8053E934;
        *(f32*)(p + 0x40) = lbl_8053E934;
        *(f32*)(p + 0x3c) = lbl_8053E934;
        *(s32*)(p + 0x2f8) = 0xa;
        break;
    }
    case 10:
        if (fn_802DCD0C(fn_802D6A9C())) {
            fn_8022ADE4();
            *(s32*)(p + 0x2f8) = 0;
        }
        break;
    case 11:
        *(f32*)(p + 0x334) = lbl_8053E934;
        *(f32*)(p + 0x44) = lbl_8053E934;
        *(f32*)(p + 0x40) = lbl_8053E934;
        *(f32*)(p + 0x3c) = lbl_8053E934;
        fn_801F0E34(p, 0x400b6, 0);
        *(f32*)(p + 0x44) = lbl_8053E9B0;
        *(s32*)(p + 0x2f8) = 0xc;
        break;
    case 12:
        if (*(f32*)(p + 0x14) > lbl_8053E934) {
            *(f32*)(p + 0x44) -= lbl_8053E930;
            break;
        }
        *(f32*)(p + 0x14) = lbl_8053E934;
        *(f32*)(p + 0x44) = lbl_8053E934;
        *(s32*)(p + 0x328) = *(s32*)(p + 0x328) - 1;
        if (*(s32*)(p + 0x328) > 0) {
            *(s32*)(p + 0x308) = 300;
            s32 id = *(s32*)(p + 0x310);
            if (id >= 0) {
                u8* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0 && *(s32*)(a + 0x250) == 2) {
                    *(u8*)(p + 0x32c) = 1;
                    *(s32*)(p + 0x2f8) = 7;
                    break;
                }
            }
            if (*(u8*)(p + 0x2fc) == 1) {
                *(s32*)(p + 0x2f8) = 0;
            } else {
                *(s32*)(p + 0x2f8) = 1;
            }
        } else {
            *(s32*)(p + 0x2f8) = 0xd;
        }
        break;
    case 13:
        *(s32*)(p + 0x30c) = 0;
        *(s32*)(p + 0x310) = 0;
        *(s32*)(p + 0x314) = 0;
        *(s32*)(p + 0x318) = 0;
        *(s32*)(p + 0x31c) = 0;
        *(s32*)(p + 0x300) = 0;
        *(s32*)(p + 0x304) = 0;
        *(s32*)(p + 0x308) = 0;
        fn_801F0E34(p, 0x400b7, 0);
        for (s32 i = 0; i < 4; i++) {
            if (*(s32*)(p + 0x98) == tbl->dir[i]) {
                *(s32*)(p + 0x30c) = i;
                *(s32*)(p + 0x300) = 8;
                *(s32*)(p + 0x2f8) = 0xe;
                break;
            }
        }
        break;
    case 14:
        if (*(s32*)(p + 0x300) == 0) {
            *(s32*)(p + 0x30c) = *(s32*)(p + 0x30c) + 1;
            *(s32*)(p + 0x30c) &= 3;
            *(s32*)(p + 0x300) = 8;
            *(s32*)(p + 0x98) = tbl->dir[*(s32*)(p + 0x30c)];
            *(s32*)(p + 0x310) = *(s32*)(p + 0x310) + 1;
            if (*(s32*)(p + 0x310) >= 12 && *(s32*)(p + 0x98) == 0) {
                *(s32*)(p + 0x2f8) = 0xf;
                break;
            }
        }
        *(s32*)(p + 0x320) = *(s32*)(p + 0x98) << 3;
        break;
    case 15:
        *(s32*)(p + 0x30c) = 0;
        *(s32*)(p + 0x300) = tbl->time[*(s32*)(p + 0x30c)];
        *(s32*)(p + 0x320) = tbl->anim[*(s32*)(p + 0x30c)];
        *(s32*)(p + 0x2f8) = 0x10;
    case 16:
        if (*(s32*)(p + 0x300) != 0) {
            break;
        }
        *(s32*)(p + 0x30c) = *(s32*)(p + 0x30c) + 1;
        if (*(s32*)(p + 0x30c) > 4) {
            *(s32*)(p + 0x30c) = 0;
            lbl_8053ABF0 = 1;
            *(s32*)(p + 0x2f8) = 0x11;
            break;
        }
        *(s32*)(p + 0x300) = tbl->time[*(s32*)(p + 0x30c)];
        *(s32*)(p + 0x320) = tbl->anim[*(s32*)(p + 0x30c)];
        break;
    case 17:
        if (lbl_8053ABE8 == 1) {
            lbl_8053ABE8 = 0;
            lbl_8053ABF0 = 0;
            *(s32*)(p + 0x2f8) = 0x12;
        }
        break;
    case 18:
        *(s32*)(p + 0x30c) = 4;
        *(s32*)(p + 0x300) = tbl->time[*(s32*)(p + 0x30c)];
        *(s32*)(p + 0x320) = tbl->anim[*(s32*)(p + 0x30c)];
        *(s32*)(p + 0x2f8) = 0x13;
    case 19:
        if (*(s32*)(p + 0x300) != 0) {
            break;
        }
        *(s32*)(p + 0x328) = *(s32*)(p + 0x328) + 1;
        if (*(s32*)(p + 0x328) > 5) {
            *(s32*)(p + 0x328) = 5;
        }
        *(s32*)(p + 0x30c) = *(s32*)(p + 0x30c) - 1;
        if (*(s32*)(p + 0x30c) < 0) {
            *(s32*)(p + 0x328) = 5;
            *(s32*)(p + 0x2f8) = 1;
            break;
        }
        *(s32*)(p + 0x300) = tbl->time[*(s32*)(p + 0x30c)];
        *(s32*)(p + 0x320) = tbl->anim[*(s32*)(p + 0x30c)];
        break;
    }
    s32 st = *(s32*)(p + 0x2f8);
    if ((st == 2 || st == 4 || st == 6 || st == 0xc || st == 9 || st == 0xa) && *(s32*)(p + 0x300) == 0) {
        *(s32*)(p + 0x320) = (*(s32*)(p + 0x98) << 3) + *(s32*)(p + 0x30c);
        *(s32*)(p + 0x300) = 5;
        *(s32*)(p + 0x30c) = *(s32*)(p + 0x30c) + 1;
        *(s32*)(p + 0x30c) &= 7;
    }
    if (*(s32*)(p + 0x300) > 0) {
        *(s32*)(p + 0x300) -= 1;
    }
    if (*(s32*)(p + 0x304) > 0) {
        *(s32*)(p + 0x304) -= 1;
    }
    if (*(s32*)(p + 0x308) > 0) {
        *(s32*)(p + 0x308) -= 1;
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
