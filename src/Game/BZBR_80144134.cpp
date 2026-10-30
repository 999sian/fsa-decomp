// BZBR_80144134: .text 0x80144134-0x8014529C (actor BZBR)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/ItemBase.h"
#include "Game/TlwpDrawParam.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801F06F0(void* actor, const char* res, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, DrawRec* rec, f32 sx, f32 sy);
extern char lbl_80465B80[];
extern s32 lbl_8049F408[];
extern s32 lbl_8049F418[];
extern char* lbl_8053AB10;
struct BzbrGame;
extern "C" s32 fn_801F3D94(void* a, s32 b);
extern "C" u8 fn_801F2618(void* a, f32* out, u32 c);
extern "C" void fn_801F0E34(void* a, s32 id, s32 z);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" s32 fn_8023B004(f32* box, s32 room);
extern "C" u8 fn_8023E854(void);
extern "C" void fn_80238548(s32 i, s32 b, f32* p, s32 n);
extern "C" s32 fn_801F285C(void* a, f32* b, u32* c, u32 e, s32 d);
extern "C" u8 fn_801F2FAC(void* a);
extern "C" u32 fn_801F2DB4(void* a, u32 b, u32 c, void* buf);
extern "C" void fn_801EE8F4(void* a, void* outDir, f32* outLen, s32 n);
extern "C" void fn_801EEC98(void* unused, s32 idx, u16* angOut, s32* quadOut, f32* distOut, s32* idxOut, s32 sel, s32 mode);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_801F23BC(void* a, u32 id, void* f0C, void* f18, void* p80, f32* out1, f32* out2, u32 c);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern const f32 lbl_8053CFDC;
extern const f32 lbl_8053CFD8;
struct BzbrRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053CFDC;
    }
};
struct BzbrGame { u8 pad[0xb4]; BzbrRandom rnd; };
extern BzbrGame* lbl_8053AAF8;
extern const f32 lbl_8053CFE0;
extern const f32 lbl_8053CFE4;
extern const f32 lbl_8053CFE8;
extern const f32 lbl_8053CFEC;
extern const f32 lbl_8053CFF0;
extern const f32 lbl_8053CFF4;
extern const f32 lbl_8053CFF8;
extern const f32 lbl_8053CFFC;
extern const f32 lbl_8053D000;
extern const f32 lbl_8053D004;
extern const f32 lbl_8053D008;
extern const f32 lbl_8053D00C;

// Resource manager at game+0xa4; vtable +0x18 looks a resource up by type and name.
struct BzbrResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};

// ---- from Game/fn_80144134_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F444[];

extern "C" void* fn_80144134(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F444;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

static inline void bzbrRotScale(f32 m[3][4], const f32* angle, const f32* scale) {
    f32 ang;
    f32 s;
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    ang = *angle;
    s = *scale;
    f32 sz, sy, sx;
    f32 cz, cx;
    f32 rx = 0.0f;
    sx = sin(rx);
    sy = sin(ang);
    sz = sin(rx);
    cx = cos(rx);
    ang = cos(ang);
    cz = cos(rx);
    f32 cxcz = cx * cz;
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    m[0][0] = s * (ang * cz);
    m[1][0] = s * (ang * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * ang);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * ang);
}

static inline void bzbrRotScaleActor(f32 m[3][4], const u8* actor) {
    f32 ang;
    f32 s;
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    ang = *(const f32*)(actor + 0x254);
    s = *(const f32*)(actor + 0x250);
    f32 sz, sy, sx;
    f32 cz, cx;
    f32 rx = 0.0f;
    sx = sin(rx);
    sy = sin(ang);
    sz = sin(rx);
    cx = cos(rx);
    ang = cos(ang);
    cz = cos(rx);
    f32 cxcz = cx * cz;
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    m[0][0] = s * (ang * cz);
    m[1][0] = s * (ang * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * ang);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * ang);
}

extern "C" void fn_80144194(u8* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    if (*(s32*)(this_ + 0x230) == 4) {
        DrawRec rec2;
        f32 m2[3][4];
        bzbrRotScaleActor(m2, this_);
        rec2.w18 = m2;
        s32 id = lbl_8049F408[*(s32*)(this_ + 0x244)] + 0x10;
        if (*(s32*)(this_ + 4) < 8) {
            void* res = (*(BzbrResMgr**)((u8*)lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_80465B80);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, &rec2, 1.0f, 1.0f);
        }
    } else if (*(s32*)(this_ + 0x230) != 3) {
        f32 ys = *(f32*)(this_ + 0x25c);
        f32 xs = *(f32*)(this_ + 0x258);
        mtx[0][0] = xs;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = ys;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = ys;
        rec.w18 = mtx;
        f32 zero = mtx[0][1];
        if (*(f32*)(this_ + 0x14) != zero) {
            rec.w30 = 0x11;
        }
        fn_801F06F0(this_, lbl_80465B80, lbl_8049F408[*(s32*)(this_ + 0x244)] + 0x10, &rec, 0, 1.0f, 1.0f);
    } else {
        fn_801F06F0(this_, lbl_80465B80, lbl_8049F418[*(s32*)(this_ + 0x244)] + 0x10, 0, 0, 1.0f, 1.0f);
    }
}

extern "C" void fn_8013CC50(s32 room, void* pos, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
void detach__5ActorFv(void* this_);
extern "C" void fn_8014462C(u8* this_) {
    f32 box[4];
    JGeometry::TVec3<f32> v;
    f32 pt[2];
    f32 pt2[2];
    f32 dist;
    s32 idx;
    s32 quad;
    u16 ang;
    s32 r;

    if (fn_801F3D94(this_, 1) != 0) {
        *(f32*)(this_ + 0x258) = lbl_8053CFDC;
        *(f32*)(this_ + 0x25c) = lbl_8053CFDC;
        *(f32*)(this_ + 0x260) = lbl_8053CFDC;
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (*(s32*)(this_ + 0x234) > 0) *(s32*)(this_ + 0x234) -= 1;
    if (*(s32*)(this_ + 0x238) > 0) *(s32*)(this_ + 0x238) -= 1;
    if (*(s32*)(this_ + 0x23c) > 0) *(s32*)(this_ + 0x23c) -= 1;
    if (*(s32*)(this_ + 0x240) > 0) *(s32*)(this_ + 0x240) -= 1;
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(this_ + 0xc);
    r = 0;
    *pos += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);

    if (*(s32*)(this_ + 0x230) != 4) {
        if ((s32)fn_8022461C(pos, *(s32*)(this_ + 4)) == 0xe) {
            fn_801F0E34(this_, 0x4001a, 0);
            *(s32*)(this_ + 0x230) = 4;
        } else {
            box[0] = ((f32*)(this_ + 0x60))[0];
            box[1] = ((f32*)(this_ + 0x60))[1];
            box[2] = ((f32*)(this_ + 0x60))[2];
            box[3] = ((f32*)(this_ + 0x60))[3];
            {
                f32 px;
                f32 py;
                py = *(f32*)(this_ + 0x10);
                px = *(f32*)(this_ + 0xc);
                box[0] += px;
                box[1] += py;
                box[2] += px;
                box[3] += py;
            }
            r = fn_8023B004(box, *(s32*)(this_ + 4));
            if (r >= 0 && fn_8023E854() == 0) {
                f32 x1 = box[2];
                f32 x0 = box[0];
                f32 y1 = box[3];
                f32 y0 = box[1];
                pt[0] = lbl_8053CFE0 * (x0 - x1) + x1;
                pt[1] = lbl_8053CFE0 * (y0 - y1) + y1;
                fn_80238548(r, 1, pt, 0xa);
                fn_801F0E34(this_, 0x4000c, 0);
                *(f32*)(this_ + 0x258) = lbl_8053CFDC;
                *(f32*)(this_ + 0x25c) = lbl_8053CFDC;
                *(f32*)(this_ + 0x260) = lbl_8053CFDC;
                *(s32*)(this_ + 0x244) = 0;
                *(s32*)(this_ + 0x23c) = 4;
                *(f32*)(this_ + 0x3c) = lbl_8053CFD8;
                *(f32*)(this_ + 0x40) = lbl_8053CFD8;
                *(f32*)(this_ + 0x44) = lbl_8053CFD8;
                *(f32*)(this_ + 0x258) = lbl_8053CFDC;
                *(f32*)(this_ + 0x25c) = lbl_8053CFDC;
                *(f32*)(this_ + 0x260) = lbl_8053CFDC;
                *(s32*)(this_ + 0x230) = 3;
            }
            for (r = 0; r < 4; r++) {
                s32 p = fn_801F285C(this_, 0, 0, 1, r);
                if (p >= 0) {
                    if (fn_8023E854() == 0) {
                        f32 y = *(f32*)(this_ + 0x10);
                        pt2[0] = *(f32*)(this_ + 0xc);
                        pt2[1] = y;
                        fn_80238548(p, 1, pt2, 0xa);
                        fn_801F0E34(this_, 0x4000c, 0);
                        if (*(s32*)(this_ + 0x230) != 3) {
                            *(s32*)(this_ + 0x244) = 0;
                            *(s32*)(this_ + 0x23c) = 4;
                            *(f32*)(this_ + 0x3c) = lbl_8053CFD8;
                            *(f32*)(this_ + 0x40) = lbl_8053CFD8;
                            *(f32*)(this_ + 0x258) = lbl_8053CFDC;
                            *(f32*)(this_ + 0x25c) = lbl_8053CFDC;
                            *(f32*)(this_ + 0x260) = lbl_8053CFDC;
                            *(s32*)(this_ + 0x230) = 3;
                        }
                    } else {
                        fn_801F2FAC(this_);
                    }
                }
            }
        }
    }
    fn_801F2DB4(this_, 'NULL', 'NULL', 0);
    r = fn_801F2618(this_, 0, 0);
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if ((u8)r != 0 || *(s32*)(this_ + 0x238) == 0) {
            *(s32*)(this_ + 0x238) = (s32)(lbl_8053CFE4 * lbl_8053AAF8->rnd.get_ufloat_1()) + 0x32;
            fn_801EE8F4(this_, &v, 0, 0);
            v.scale(lbl_8053CFE8);
            *(f32*)(this_ + 0x3c) = v.x + lbl_8053CFE8 * lbl_8053AAF8->rnd.get_ufloat_1();
            if (lbl_8053AAF8->rnd.get_ufloat_1() < lbl_8053CFE0) {
                *(f32*)(this_ + 0x3c) = *(f32*)(this_ + 0x3c) * lbl_8053CFEC;
            }
            *(f32*)(this_ + 0x40) = v.y + lbl_8053CFE8 * lbl_8053AAF8->rnd.get_ufloat_1();
            if (lbl_8053AAF8->rnd.get_ufloat_1() < lbl_8053CFE0) {
                *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x40) * lbl_8053CFEC;
            }
        }
        if (*(u32*)(this_ + 0x90) == 1 && *(s32*)(this_ + 0x240) == 0) {
            ang = 0;
            idx = -1;
            dist = lbl_8053CFD8;
            quad = -1;
            fn_801EEC98(this_, *(s32*)(this_ + 0x198), &ang, &quad, &dist, &idx, 0, 0);
            if (quad >= 0) {
                if ((f32)__fabs(((f32*)fn_8023E724(idx))[1] - *(f32*)(this_ + 0x10)) < lbl_8053CFF0 ||
                    (f32)__fabs(((f32*)fn_8023E724(idx))[0] - *(f32*)(this_ + 0xc)) < lbl_8053CFF0) {
                    if (!fn_801F23BC(this_, *(s32*)(this_ + 4), this_ + 0xc, fn_8023E724(idx), this_ + 0x80, 0, 0, 0)) {
                        *(s32*)(this_ + 0x98) = quad;
                        *(s32*)(this_ + 0x230) = 1;
                    }
                }
            }
        }
        break;
    case 1:
        *(f32*)(this_ + 0x44) = lbl_8053CFD8;
        *(f32*)(this_ + 0x40) = lbl_8053CFD8;
        *(f32*)(this_ + 0x3c) = lbl_8053CFD8;
        switch (*(s32*)(this_ + 0x98)) {
        case 0:
            *(s32*)(this_ + 0x244) = 0;
            break;
        case 1:
            *(s32*)(this_ + 0x244) = 2;
            break;
        default:
            *(s32*)(this_ + 0x244) = 1;
            break;
        }
        *(s32*)(this_ + 0x240) = 0x14;
        *(s32*)(this_ + 0x230) = 2;
    case 2:
        if (*(s32*)(this_ + 0x240) != 0) {
            fn_801F71A4((f32*)(this_ + 0x258), lbl_8053CFF4, lbl_8053CFF8, lbl_8053CFFC);
            fn_801F71A4((f32*)(this_ + 0x25c), lbl_8053D000, lbl_8053CFF8, lbl_8053CFFC);
            if (*(s32*)(this_ + 0x240) == 1) {
                switch (*(s32*)(this_ + 0x98)) {
                case 0:
                    *(f32*)(this_ + 0x3c) = lbl_8053D004;
                    *(f32*)(this_ + 0x40) = lbl_8053CFD8;
                    *(f32*)(this_ + 0x44) = lbl_8053D008;
                    break;
                case 1:
                    *(f32*)(this_ + 0x3c) = -lbl_8053D004;
                    *(f32*)(this_ + 0x40) = lbl_8053CFD8;
                    *(f32*)(this_ + 0x44) = lbl_8053D008;
                    break;
                case 2:
                    *(f32*)(this_ + 0x3c) = lbl_8053CFD8;
                    *(f32*)(this_ + 0x40) = lbl_8053D004;
                    *(f32*)(this_ + 0x44) = lbl_8053D008;
                    break;
                case 3:
                    *(f32*)(this_ + 0x3c) = lbl_8053CFD8;
                    *(f32*)(this_ + 0x40) = -lbl_8053D004;
                    *(f32*)(this_ + 0x44) = lbl_8053D008;
                    break;
                }
            }
        } else {
            fn_801F71A4((f32*)(this_ + 0x258), lbl_8053CFDC, lbl_8053CFF8, lbl_8053CFFC);
            fn_801F71A4((f32*)(this_ + 0x25c), lbl_8053CFDC, lbl_8053CFF8, lbl_8053CFFC);
            f32 h = *(f32*)(this_ + 0x14);
            if (h > lbl_8053CFD8) {
                *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - lbl_8053CFE0;
            } else {
                *(f32*)(this_ + 0x14) = lbl_8053CFD8;
                *(f32*)(this_ + 0x44) = lbl_8053CFD8;
                *(f32*)(this_ + 0x40) = lbl_8053CFD8;
                *(f32*)(this_ + 0x3c) = lbl_8053CFD8;
                *(f32*)(this_ + 0x258) = lbl_8053CFDC;
                *(f32*)(this_ + 0x25c) = lbl_8053CFDC;
                *(f32*)(this_ + 0x260) = lbl_8053CFDC;
                *(s32*)(this_ + 0x240) = (s32)(lbl_8053CFE4 * lbl_8053AAF8->rnd.get_ufloat_1()) + 0x1e;
                *(s32*)(this_ + 0x230) = 0;
            }
        }
        break;
    case 3: {
        f32 h = *(f32*)(this_ + 0x14);
        if (h > lbl_8053CFD8) {
            *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - lbl_8053CFE0;
        } else {
            *(f32*)(this_ + 0x14) = lbl_8053CFD8;
            *(f32*)(this_ + 0x44) = lbl_8053CFD8;
        }
        if (*(s32*)(this_ + 0x23c) == 0) {
            *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + 1;
            *(s32*)(this_ + 0x23c) = 4;
            if (*(s32*)(this_ + 0x244) > 10) {
                *(s32*)(this_ + 0x244) = 0;
                *(s32*)(this_ + 0x230) = 0;
            }
        }
        break;
    }
    case 4:
        *(f32*)(this_ + 0x254) = *(f32*)(this_ + 0x254) + lbl_8053CFF8;
        *(f32*)(this_ + 0x250) = *(f32*)(this_ + 0x250) - lbl_8053D00C;
        if (*(f32*)(this_ + 0x250) < lbl_8053CFF8) {
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053CFDC, 0x2a9, -1, 1, 0, 0, 1);
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053CFDC, 0x2aa, -1, 0, 0, 0, 1);
            fn_801F0E34(this_, 0x5005f, 0);
            detach__5ActorFv(this_);
        }
        break;
    }
    s32 st = *(s32*)(this_ + 0x230);
    if (st != 3 && st != 1 && st != 2 && st != 4 && *(s32*)(this_ + 0x234) <= 0) {
        *(s32*)(this_ + 0x234) = 8;
        *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + 1;
        *(s32*)(this_ + 0x244) &= 3;
    }
}

extern const f32 lbl_8053CFD8;
extern const f32 lbl_8053CFDC;
extern const f32 lbl_8053D010;
extern const f32 lbl_8053D014;
extern const f32 lbl_8053D018;
extern const f32 lbl_8053CFE0;
extern const f32 lbl_8053CFE4;
extern const f32 lbl_8053CFE8;
extern const f32 lbl_8053CFEC;
extern const f32 lbl_8053CFF0;
extern const f32 lbl_8053CFF4;
extern const f32 lbl_8053CFF8;
extern const f32 lbl_8053CFFC;
extern const f32 lbl_8053D000;
extern const f32 lbl_8053D004;
extern const f32 lbl_8053D008;
extern "C" s32 fn_801F3D94(void* a, s32 b);
extern "C" u8 fn_801F2618(void* a, f32* out, u32 c);
extern "C" void fn_801F0E34(void* a, s32 id, s32 z);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" s32 fn_8023B004(f32* box, s32 room);
extern "C" u8 fn_8023E854(void);
extern "C" void fn_80238548(s32 i, s32 b, f32* p, s32 n);
extern "C" s32 fn_801F285C(void* a, f32* b, u32* c, u32 e, s32 d);
extern "C" u8 fn_801F2FAC(void* a);
extern "C" u32 fn_801F2DB4(void* a, u32 b, u32 c, void* buf);
extern "C" void fn_801EE8F4(void* a, void* outDir, f32* outLen, s32 n);
extern "C" void fn_801EEC98(void* unused, s32 idx, u16* angOut, s32* quadOut, f32* distOut, s32* idxOut, s32 sel, s32 mode);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_801F23BC(void* a, u32 id, void* f0C, void* f18, void* p80, f32* out1, f32* out2, u32 c);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);


extern "C" void fn_80144F9C(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053D010;
    *(f32*)(this_ + 0x64) = lbl_8053D010;
    *(f32*)(this_ + 0x68) = lbl_8053D014;
    *(f32*)(this_ + 0x6c) = lbl_8053D014;
    *(f32*)(this_ + 0x80) = lbl_8053D010;
    *(f32*)(this_ + 0x84) = lbl_8053D010;
    *(f32*)(this_ + 0x88) = lbl_8053D014;
    *(f32*)(this_ + 0x8c) = lbl_8053D014;
    *(u32*)(this_ + 0x90) &= 1;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x244) = (s32)(lbl_8053D018 * lbl_8053AAF8->rnd.get_ufloat_1());
    *(f32*)(this_ + 0x254) = lbl_8053CFD8;
    *(f32*)(this_ + 0x250) = lbl_8053CFDC;
    *(f32*)(this_ + 0x258) = lbl_8053CFDC;
    *(f32*)(this_ + 0x25c) = lbl_8053CFDC;
    *(f32*)(this_ + 0x260) = lbl_8053CFDC;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
