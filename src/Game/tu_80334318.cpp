#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" char lbl_804AB9C0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80334318(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB9C0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* m, u32 code, s32 i);
extern "C" void* fn_801F666C(void* m, s32 i);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801F349C(Actor* a, u32 x, f32* p);
extern "C" void fn_802F86CC(void*, void*, void*, s32, void*, f32, f32);
extern "C" void fn_80307AC8(u32, u32, void*, s32, s32, u32, s32);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" double sin(double x);
extern "C" double cos(double x);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" char lbl_80471AB8[];
extern "C" char lbl_80471AC8[];
extern const f32 lbl_80541F80;
extern const f32 lbl_80541F84;
extern const f32 lbl_80541F88;
extern const f32 lbl_80541F8C;

class ResMgr {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void* v18(u32 type, const char* name);
};
extern const f32 lbl_80541F70;
extern const f32 lbl_80541F74;
extern const f32 lbl_80541F84;
extern const f32 lbl_80541F88;
extern const f32 lbl_80541FA8;
extern const f32 lbl_80541FB0;
extern const f32 lbl_80541FB4;
extern const f32 lbl_80541FD0;
extern const f32 lbl_80541FD4;
extern const f32 lbl_80541FD8;
extern const f32 lbl_80541FDC;
extern const f32 lbl_80541FE0;
extern const f32 lbl_80541FE4;
extern const f32 lbl_80541FE8;
extern const f32 lbl_80541FEC;
extern const f32 lbl_80541FF0;
extern "C" s32 fn_80334378(Actor* a) {
    s32 i = -1;
    u8* e;
    u32 st;
    do {
        do {
            i = fn_801F78F4(fn_801F856C(), 0x57415250, i);
            if (i < 0) {
                goto done;
            }
            e = (u8*)fn_801F666C(fn_801F856C(), i);
        } while (e == 0);
        st = *(u32*)(e + 0x90);
    } while ((u8)st != 7);
    u32 idx = (st >> 24) & 7;
    f32 fx;
    f32 fy;
    if (idx == 0) {
        register u8* m = (u8*)fn_802D6A9C();
        fx = *(f32*)(m + 0xcc);
        fy = *(f32*)(m + 0xd0);
    } else {
        fy = lbl_80541F70;
        idx += 7;
        fx = fy;
    }
    f32 pos[3];
    pos[0] = lbl_80541F74 + ((f32)((st >> 13) & 0x1f8) + fx);
    pos[1] = lbl_80541F74 + ((f32)((st >> 5) & 0x1f8) + fy);
    pos[2] = lbl_80541F70;
    fn_801F349C(a, idx, pos);
done:
    return i;
}

extern "C" void fn_80334488(Actor* a) {
    u8* p = (u8*)a;
    if (*(s32*)(p + 0x230) == 5) {
        return;
    }
    DrawRec rB;
    DrawRec rA;
    f32 vA[3];
    f32 vB[3];
    f32 mtx[3][4];
    f32 ss;
    f32 cz;
    f32 cs,a0,a1,a2,a3,a4,a5,a6,a7,a8;
    f32 cc;
    f32 sa;
    f32 sb;
    f32 sc;
    f32 ca;
    f32 cb;
    f32 s;
    PSMTXIdentity(mtx);
    rB.b1d = -1;
    if (*(s32*)(p + 0x230) == 7) {
        s = *(f32*)(p + 0x240);
        sa = sin(lbl_80541F70);
        sb = sin(lbl_80541F70);
        sc = sin(lbl_80541F70);
        ca = cos(lbl_80541F70);
        cb = cos(lbl_80541F70);
        cz = cos(lbl_80541F70);
        rA.w18 = mtx;
        cc = ca * cz;
        ss = sa * sb;
        cs = ca * sc;
        a0 = cb * cz;
        a1 = cb * sc;
        a2 = -sb;
        a3 = ss * cz - cs;
        a4 = ss * sc + cc;
        a5 = sa * cb;
        a6 = cc * sb + sa * sc;
        a7 = cs * sb - sa * cz;
        a8 = ca * cb;
        mtx[0][0] = s * a0;
        mtx[1][0] = s * a1;
        mtx[2][0] = s * a2;
        mtx[0][1] = s * a3;
        mtx[1][1] = s * a4;
        mtx[2][1] = s * a5;
        mtx[0][2] = s * a6;
        mtx[1][2] = s * a7;
        mtx[2][2] = s * a8;
    }
    if (*(s32*)(p + 0x250) == 0) {
        if (*(s32*)(p + 0x230) != 7) {
            f32* pos = (f32*)(p + 0xc);
            f32 y = lbl_80541F80 + pos[1];
            f32 x = pos[0];
            vA[0] = x;
            vA[1] = y;
            vA[2] = lbl_80541F70;
            if (*(s32*)(p + 4) < 8) {
                void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AB8);
                fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), vA, obj, 0, &rB, lbl_80541F84, lbl_80541F84);
            }
        }
        s32 id = *(s32*)(p + 0x24c) + 0x25;
        if (*(s32*)(p + 4) < 8) {
            void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AC8);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, obj, id, &rA, lbl_80541F84, lbl_80541F84);
        }
        fn_80307AC8(*(u32*)(p + 0x198), *(u32*)(p + 4), p + 0xc, *(s32*)(p + 0x24c) + 0x25, 0, 0, -1);
    } else {
        if (*(s32*)(p + 0x230) != 7) {
            f32* pos = (f32*)(p + 0xc);
            f32 y = lbl_80541F88 + pos[1];
            f32 x = pos[0];
            vB[0] = x;
            vB[1] = y;
            vB[2] = lbl_80541F70;
            if (*(s32*)(p + 4) < 8) {
                void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AB8);
                fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), vB, obj, 3, &rB, lbl_80541F8C, lbl_80541F84);
            }
        }
        s32 id = *(s32*)(p + 0x24c) + 0x27;
        if (*(s32*)(p + 4) < 8) {
            void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AC8);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, obj, id, &rA, lbl_80541F84, lbl_80541F84);
        }
        fn_80307AC8(*(u32*)(p + 0x198), *(u32*)(p + 4), p + 0xc, *(s32*)(p + 0x24c) + 0x27, 0, 0, -1);
    }
}

extern int __float_epsilon[];
extern const f32 lbl_80541F98;

// The SBAL actor adds one virtual after Actor's 19.
struct SBALActor : public Actor {
    virtual s32 v19();
};

static inline bool SBAL_epsEquals(f32 a, const f32& b, f32 eps) {
    bool r = false;
    f32 d = a - b;
    if (-eps <= d && d <= eps) {
        r = true;
    }
    return r;
}

// True when all three components of v are within 32*epsilon of zero.
static inline bool SBAL_isNearZero(const f32* v) {
    f32 eps = lbl_80541F98 * *(f32*)__float_epsilon;
    bool all = false;
    bool xy = false;
    if (SBAL_epsEquals(v[0], lbl_80541F70, eps) && SBAL_epsEquals(v[1], lbl_80541F70, eps)) {
        xy = true;
    }
    if (xy && SBAL_epsEquals(v[2], lbl_80541F70, eps)) {
        all = true;
    }
    return all;
}

extern "C" char* lbl_8053AC98;
extern "C" void fn_802A1688(char* self, JGeometry::TVec3<f32>* pos, u32 room, u32 kind);
extern "C" u8 fn_801F2618(void* a, s32 b, s32 c);
extern "C" void fn_801EEC98(void* unused, s32 idx, u16* angOut, s32* quadOut, f32* distOut, s32* idxOut, s32 sel, s32 mode);
extern "C" Vec* fn_8023E724();
extern "C" u8 fn_801F2B7C(void* a, s32 b, s32 c, s32 d);
extern "C" void fn_801F71A4(f32* v, f32 target, f32 a, f32 b);
extern "C" void fn_802D79E8(void* m, u32 room, s32 a, f32 b, f32 c);
extern "C" void fn_801F0E34(void* a, u32 b, s32 c);
extern const f32 lbl_80541F90;
extern const f32 lbl_80541F94;
extern const f32 lbl_80541F9C;
extern const f32 lbl_80541FA0;
extern const f32 lbl_80541FA4;
extern const f32 lbl_80541FAC;
extern const f32 lbl_80541FB8;
extern const f32 lbl_80541FBC;
extern const f32 lbl_80541FC0;
extern const f32 lbl_80541FC4;
extern "C" void fn_80334A04(u8* p) {
    u16 ang;
    s32 idx;
    JGeometry::TVec3<f32> v;
    JGeometry::TVec3<f32> off;
    u8 hit;
    ang = 0;
    JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), (Vec*)(p + 0x3c), (Vec*)(p + 0xc));
    if (*(u32*)(p + 0x90) & 1) {
        v = *(JGeometry::TVec3<f32>*)(p + 0xc);
        off.x = lbl_80541F90 * JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c));
        off.y = lbl_80541F90 * JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c));
        v.add(off);
        fn_802A1688(lbl_8053AC98, &v, *(u32*)(p + 4), 'SBAL');
        v = *(JGeometry::TVec3<f32>*)(p + 0xc);
        off.x = lbl_80541F90 * JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c) + 0x1500);
        off.y = lbl_80541F90 * JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c) + 0x1500);
        v.add(off);
        fn_802A1688(lbl_8053AC98, &v, *(u32*)(p + 4), 'SBAL');
        v = *(JGeometry::TVec3<f32>*)(p + 0xc);
        off.x = lbl_80541F90 * JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c) - 0x1500);
        off.y = lbl_80541F90 * JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c) - 0x1500);
        v.add(off);
        fn_802A1688(lbl_8053AC98, &v, *(u32*)(p + 4), 'SBAL');
    } else {
        v = *(JGeometry::TVec3<f32>*)(p + 0xc);
        off.x = lbl_80541F94 * JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c));
        off.y = lbl_80541F94 * JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c));
        v.add(off);
        fn_802A1688(lbl_8053AC98, &v, *(u32*)(p + 4), 'SBAL');
        v = *(JGeometry::TVec3<f32>*)(p + 0xc);
        off.x = lbl_80541F94 * JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c) + 0x1500);
        off.y = lbl_80541F94 * JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c) + 0x1500);
        v.add(off);
        fn_802A1688(lbl_8053AC98, &v, *(u32*)(p + 4), 'SBAL');
        v = *(JGeometry::TVec3<f32>*)(p + 0xc);
        off.x = lbl_80541F94 * JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c) - 0x1500);
        off.y = lbl_80541F94 * JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c) - 0x1500);
        v.add(off);
        fn_802A1688(lbl_8053AC98, &v, *(u32*)(p + 4), 'SBAL');
    }
    hit = fn_801F2618(p, 0, 0);
    fn_801EEC98(p, *(s32*)(p + 0x198), &ang, 0, 0, &idx, 0, 1);
    if (idx >= 0) {
        *(JGeometry::TVec3<f32>*)(p + 0x260) = *(JGeometry::TVec3<f32>*)fn_8023E724();
    }
    if (lbl_80541F70 == *(f32*)(p + 0x14) && *(s32*)(p + 0x230) != 7) {
        bool r;
        if (*(s32*)(p + 0x250) == 1) {
            r = fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 5) != 0;
        } else {
            r = fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 4) != 0;
        }
        if (r) {
            *(f32*)(p + 0x3c) = -*(f32*)(p + 0x3c);
            *(f32*)(p + 0x40) = -*(f32*)(p + 0x40);
            *(f32*)(p + 0x44) = lbl_80541F70;
            *(s32*)(p + 0x244) = 20;
            *(s32*)(p + 0x230) = 3;
        }
    }
    switch (*(s32*)(p + 0x230)) {
    case 0:
        *(s32*)(p + 0x244) -= 1;
        if (*(s32*)(p + 0x244) <= 0) {
            *(s32*)(p + 0x230) = 1;
            *(s32*)(p + 0x244) = 0;
        }
        break;
    case 1:
        ang = 0;
        if (*(s32*)(p + 0x254) == 0 && idx >= 0) {
            if (hit) {
                *(u16*)(p + 0x26c) += 0x2000;
                *(s32*)(p + 0x254) = 10;
            }
        } else if (SBAL_isNearZero((f32*)(p + 0x260))) {
            *(u16*)(p + 0x26c) = 0;
        } else {
            *(u16*)(p + 0x26c) = (s32)(JMath::atanTable_.atan2_(*(f32*)(p + 0x260) - *(f32*)(p + 0xc), *(f32*)(p + 0x264) - *(f32*)(p + 0x10)) * lbl_80541F9C);
        }
        *(s32*)(p + 0x254) -= 1;
        *(s32*)(p + 0x244) += 1;
        *(f32*)(p + 0x23c) = (f32)(*(s32*)(p + 0x244) * *(s32*)(p + 0x244)) / lbl_80541F90;
        if (*(s32*)(p + 0x244) >= 5) {
            *(s32*)(p + 0x230) = 2;
        }
        if (idx >= 0 || !SBAL_isNearZero((f32*)(p + 0x260))) {
            *(f32*)(p + 0x3c) = *(f32*)(p + 0x23c) * JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c));
            *(f32*)(p + 0x40) = *(f32*)(p + 0x23c) * JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c));
        } else {
            *(f32*)(p + 0x3c) = lbl_80541F70;
            *(f32*)(p + 0x40) = lbl_80541F70;
        }
        *(s32*)(p + 0x248) -= 1;
        break;
    case 2:
        ang = 0;
        if (*(s32*)(p + 0x254) == 0 && idx >= 0) {
            if (hit) {
                *(u16*)(p + 0x26c) += 0x2000;
                *(s32*)(p + 0x254) = 10;
            }
        } else if (SBAL_isNearZero((f32*)(p + 0x260))) {
            *(u16*)(p + 0x26c) = 0;
        } else {
            *(u16*)(p + 0x26c) = (s32)(JMath::atanTable_.atan2_(*(f32*)(p + 0x260) - *(f32*)(p + 0xc), *(f32*)(p + 0x264) - *(f32*)(p + 0x10)) * lbl_80541F9C);
        }
        *(s32*)(p + 0x254) -= 1;
        if (idx >= 0 || !SBAL_isNearZero((f32*)(p + 0x260))) {
            *(f32*)(p + 0x3c) = JMath::sincosTable_.sinShort(*(u16*)(p + 0x26c));
            *(f32*)(p + 0x40) = JMath::sincosTable_.cosShort(*(u16*)(p + 0x26c));
        } else {
            *(f32*)(p + 0x3c) = lbl_80541F70;
            *(f32*)(p + 0x40) = lbl_80541F70;
        }
        *(s32*)(p + 0x248) -= 1;
        break;
    case 3:
    case 4:
        *(s32*)(p + 0x244) -= 1;
        if (((JGeometry::TVec3<f32>*)(p + 0x3c))->squared() > lbl_80541FA0) {
            fn_801F71A4((f32*)(p + 0x3c), lbl_80541F70, lbl_80541FA4, lbl_80541FA4);
            fn_801F71A4((f32*)(p + 0x40), lbl_80541F70, lbl_80541FA4, lbl_80541FA4);
        }
        if (*(s32*)(p + 0x244) <= 0) {
            *(s32*)(p + 0x230) = 0;
            ((JGeometry::TVec3<f32>*)(p + 0x3c))->zero();
            *(s32*)(p + 0x244) = 0x5a;
        }
        break;
    case 5:
        if (((u8 (*)(u8*))(*(void***)p)[13])(p)) {
            *(f32*)(p + 0x14) = lbl_80541FA8;
            *(s32*)(p + 0x230) = 6;
        }
        break;
    case 6:
        *(f32*)(p + 0x44) = *(f32*)(p + 0x44) - lbl_80541FAC;
        if (*(f32*)(p + 0x44) <= lbl_80541FB0) {
            *(f32*)(p + 0x44) = lbl_80541FB0;
        }
        if (*(f32*)(p + 0x14) <= lbl_80541F70 && *(f32*)(p + 0x44) < lbl_80541F70) {
            *(f32*)(p + 0x44) = lbl_80541F70;
            *(f32*)(p + 0x40) = lbl_80541F70;
            *(f32*)(p + 0x3c) = lbl_80541F70;
            *(f32*)(p + 0x14) = lbl_80541F70;
            *(s32*)(p + 0x230) = 0;
            *(s32*)(p + 0x244) = 0x28;
            if (*(u32*)(p + 0x90) & 1) {
                fn_802D79E8(fn_802D6A9C(), *(u32*)(p + 4), 0, lbl_80541F74, lbl_80541F70);
            } else {
                fn_802D79E8(fn_802D6A9C(), *(u32*)(p + 4), 0, lbl_80541FB4, lbl_80541F70);
            }
            fn_801F0E34(p, 0x3000f, 0);
        }
        break;
    case 7:
        if (*(s32*)(p + 0x25c) > 0) {
            *(s32*)(p + 0x25c) -= 1;
        } else {
            *(f32*)(p + 0x240) = *(f32*)(p + 0x240) - lbl_80541FB8;
            ((JGeometry::TVec3<f32>*)(p + 0x3c))->scale(lbl_80541FBC);
            if (*(f32*)(p + 0x240) < lbl_80541FC0) {
                ((JGeometry::TVec3<f32>*)(p + 0x3c))->zero();
                if (((s32 (*)(u8*))(*(void***)p)[21])(p) < 0) {
                    ((Actor*)p)->detach();
                } else {
                    *(f32*)(p + 0x240) = lbl_80541F84;
                    *(f32*)(p + 0x14) = lbl_80541FC4;
                    *(s32*)(p + 0x230) = 6;
                }
            }
        }
        break;
    }
    if (*(s32*)(p + 0x230) == 1 || *(s32*)(p + 0x230) == 2) {
        if (*(s32*)(p + 0x248) <= 5) {
            *(s32*)(p + 0x24c) = 1;
            if (*(s32*)(p + 0x248) <= 0) {
                *(s32*)(p + 0x248) = 10;
                *(s32*)(p + 0x24c) = 0;
            }
        }
        if (*(s32*)(p + 0x258) <= 0) {
            fn_801F0E34(p, 0x30019, 0);
            *(s32*)(p + 0x258) = 0x46;
        }
        *(s32*)(p + 0x258) -= 1;
    }
}

extern "C" u16 fn_8022461C(s32 a);
extern "C" s32 fn_80335688(Actor* p, s32 a, s32 b) {
    s32 st;
    s32 r = fn_8022461C(b);
    st = *(s32*)((u8*)p + 0x230);
    r = (u16)r;
    if (st != 3 && (r == 0xc || r == 3 || r == 0xe)) {
        if (st != 7) {
            *(s32*)((u8*)p + 0x25c) = 0x1e;
        }
        *(s32*)((u8*)p + 0x230) = 7;
        return 0;
    }
    if (r != 0 && r != 0x22) return 1;
    return 0;
}

extern "C" void fn_8033571C(char* p) {
    *(u32*)(p + 0x108) = 0x80;
    *(u32*)(p + 0xb0) = 0x42304;
    if (*(u32*)(p + 0x90) & 1) {
        *(s32*)(p + 0x250) = 1;
        *(f32*)(p + 0x60) = lbl_80541FD0;
        *(f32*)(p + 0x64) = lbl_80541FD4;
        *(f32*)(p + 0x68) = lbl_80541F74;
        *(f32*)(p + 0x6c) = lbl_80541F88;
        *(f32*)(p + 0x80) = lbl_80541FD8;
        *(f32*)(p + 0x84) = lbl_80541FD0;
        *(f32*)(p + 0x88) = lbl_80541FDC;
        *(f32*)(p + 0x8c) = lbl_80541FE0;
    } else {
        *(s32*)(p + 0x250) = 0;
        *(f32*)(p + 0x60) = lbl_80541FD4;
        *(f32*)(p + 0x64) = lbl_80541FE4;
        *(f32*)(p + 0x68) = lbl_80541FB4;
        *(f32*)(p + 0x6c) = lbl_80541FE8;
        *(f32*)(p + 0x80) = lbl_80541FEC;
        *(f32*)(p + 0x84) = lbl_80541FB0;
        *(f32*)(p + 0x88) = lbl_80541FF0;
        *(f32*)(p + 0x8c) = lbl_80541F74;
    }
    *(u16*)(p + 0x94) = (*(u32*)(p + 0x90) >> 4) & 1;
    *(f32*)(p + 0x234) = lbl_80541F70;
    *(f32*)(p + 0x238) = lbl_80541F70;
    *(f32*)(p + 0x23c) = lbl_80541F70;
    *(f32*)(p + 0x240) = lbl_80541F84;
    *(f32*)(p + 0x268) = lbl_80541F70;
    *(f32*)(p + 0x264) = lbl_80541F70;
    *(f32*)(p + 0x260) = lbl_80541F70;
    if (*(u16*)(p + 0x94) == 0) {
        *(s32*)(p + 0x230) = 0;
    } else {
        *(s32*)(p + 0x230) = 5;
        *(f32*)(p + 0x14) = lbl_80541FA8;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = 10;
    *(s32*)(p + 0x244) = 100;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(u16*)(p + 0x26c) = 0;
    *(s32*)(p + 0xb8) = 1;
}

extern "C" void fn_80335858(void) {
}

