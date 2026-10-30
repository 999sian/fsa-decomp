// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8018EB94-801902C0 (DGT2). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

struct JMathSinCos { f32 sin; f32 cos; };
extern "C" JMathSinCos sincosTable___5JMath[];
extern void* lbl_8053AAF8;
extern s32 lbl_8053AB88;

// Copy the actor position (+0xc) into dst.
static inline void dgt2CopyPos(char* dst, char* src) {
    *(f32*)(dst + 0x0) = *(f32*)(src + 0xc);
    *(f32*)(dst + 0x4) = *(f32*)(src + 0x10);
    *(f32*)(dst + 0x8) = *(f32*)(src + 0x14);
}

// Sine table index for an angle of 4000 * m (the table is indexed by bits 5..15).
static inline u32 dgt2Idx(s32 m) {
    return ((u32)(s32)(4000.0f * (f32)m) >> 5) & 0x7ff;
}

static inline f32 dgt2Sin(s32 m) {
    return sincosTable___5JMath[(u16)(s32)(4000.0f * m) >> 5].sin;
}

static inline f32 dgt2Cos(s32 m) {
    return sincosTable___5JMath[(u16)(s32)(4000.0f * m) >> 5].cos;
}

static inline void dgt2SetVel(char* p) {
    *(f32*)(p + 0x27c) = *(f32*)(p + 0x278) * dgt2Sin(*(s32*)(p + 0x98));
    *(f32*)(p + 0x280) = *(f32*)(p + 0x278) * dgt2Cos(*(s32*)(p + 0x98));
}

static inline void dgt2SetPoint(char* dst, char* p, s32 d) {
    dgt2CopyPos(dst, p);
    s32 a = (*(s32*)(p + 0x98) + d) & 0xf;
    *(f32*)(dst + 0x0) += 6.0f * dgt2Sin(a);
    *(f32*)(dst + 0x4) += 6.0f * dgt2Cos(a);
}

// from src/Game/fn_8018FB24_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A1FA0[];
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" void fn_801F06F0(void* a, const char* tbl, s32 idx, DrawRec* rec, s32 p5, f32 f6, f32 f7);
extern const f32 lbl_8053E1D8;
extern const f32 lbl_8053E1DC;
extern const f32 lbl_8053E1E0;
extern char lbl_804674F0[];

struct Dgt2Vec { f32 x; f32 y; f32 z; };

static inline f32 dgt2Sinf(f32 x) { return sin(x); }
static inline f32 dgt2Cosf(f32 x) { return cos(x); }

static inline void dgt2RotMtx(f32 m[3][4], f32 ax, f32 ay, f32 az, f32 s) {
    f32 cx;
    f32 sx = dgt2Sinf(ax);
    f32 sy = dgt2Sinf(ay);
    f32 sz = dgt2Sinf(az);
    cx = dgt2Cosf(ax);
    f32 cy = dgt2Cosf(ay);
    f32 cz = dgt2Cosf(az);
    f32 cc = cx * cz;
    f32 ss = sx * sy;
    f32 cs = cx * sz;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (ss * cz - cs);
    m[1][1] = s * (ss * sz + cc);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cc * sy + sx * sz);
    m[1][2] = s * (cs * sy - sx * cz);
    m[2][2] = s * (cx * cy);
}

static inline void dgt2DrawAt(void* this_, s32 idx, DrawRec* rec, const JGeometry::TVec3<f32>* pos, f32 z, f32 a, f32 b) {
    char* p = (char*)this_;
    *(JGeometry::TVec3<f32>*)(p + 0xc) = *pos;
    *(f32*)(p + 0x14) = z;
    fn_801F06F0(this_, lbl_804674F0, idx, rec, -1, a, b);
}

static inline void dgt2DrawAtK(void* this_, s32 idx, DrawRec* rec, s8 kind, const JGeometry::TVec3<f32>* pos, f32 z, f32 a, f32 b) {
    char* p = (char*)this_;
    *(JGeometry::TVec3<f32>*)(p + 0xc) = *pos;
    *(f32*)(p + 0x14) = z;
    rec->b1d = kind;
    fn_801F06F0(this_, lbl_804674F0, idx, rec, -1, a, b);
}

static inline void dgt2Rot(f32 (*m)[4], f32 th) {
    f32 cZ, sZ, sT, sA, cT, cA;
    sA = sin(lbl_8053E1D8);
    sT = sin(th);
    sZ = sin(lbl_8053E1D8);
    cA = cos(lbl_8053E1D8);
    cT = cos(th);
    cZ = cos(lbl_8053E1D8);
    f32 sacz, sasz, cacz, casz, sast;
    sast = sA * sT;
    casz = cA * sZ;
    cacz = cA * cZ;
    sasz = sA * sZ;
    sacz = sA * cZ;
    const f32 s = lbl_8053E1DC;
    m[0][0] = s * (cT * cZ);
    m[1][0] = s * (cT * sZ);
    m[2][0] = s * -sT;
    m[0][1] = s * (sast * cZ - casz);
    m[1][1] = s * (sast * sZ + cacz);
    m[2][1] = s * (sA * cT);
    m[0][2] = s * (cacz * sT + sasz);
    m[1][2] = s * (casz * sT - sacz);
    m[2][2] = s * (cA * cT);
}

extern "C" void* fn_8018FB24(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1FA0;
        char* p = (char*)this_;
        for (s32 i = 0; i < 3; i++) {
            fn_801EE434(*(void**)(p + 0x3c0));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8018FBB8(void* this_) {
    char* p = (char*)this_;
    *(f32*)(p + 0x80) = -6.0f;
    *(f32*)(p + 0x84) = -6.0f;
    *(f32*)(p + 0x88) = 6.0f;
    *(f32*)(p + 0x8c) = 6.0f;
    *(f32*)(p + 0x60) = -6.0f;
    *(f32*)(p + 0x64) = -6.0f;
    *(f32*)(p + 0x68) = 6.0f;
    *(f32*)(p + 0x6c) = 6.0f;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;

    dgt2CopyPos(p + 0x288, p);
    dgt2CopyPos(p + 0x294, p);
    dgt2CopyPos(p + 0x2a0, p);
    dgt2CopyPos(p + 0x2ac, p);
    dgt2CopyPos(p + 0x2b8, p);
    dgt2CopyPos(p + 0x2c4, p);

    char* q = p;
    for (s32 i = 0; i < 2; i++) {
        dgt2CopyPos(q + 0x2d0, p);
        dgt2CopyPos(q + 0x2dc, p);
        dgt2CopyPos(q + 0x2e8, p);
        dgt2CopyPos(q + 0x2f4, p);
        dgt2CopyPos(q + 0x300, p);
        dgt2CopyPos(q + 0x30c, p);
        dgt2CopyPos(q + 0x318, p);
        dgt2CopyPos(q + 0x324, p);
        dgt2CopyPos(q + 0x330, p);
        dgt2CopyPos(q + 0x33c, p);
        q += 0x78;
    }

    *(s32*)(p + 0x3c0) = 0;
    *(s32*)(p + 0x3c4) = 0;
    *(s32*)(p + 0x3c8) = 0;

    u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660du + 0x3c6ef35fu;
    u32 bits = (*seed >> 9) | 0x3f800000u;
    *(s32*)(p + 0x98) = (s32)(15.0f * (*(f32*)&bits - 1.0f));
    *(s32*)(p + 0x25c) = *(s32*)(p + 0x98);
    *(s32*)(p + 0x260) = *(s32*)(p + 0x98);
    *(s32*)(p + 0x264) = -1;
    dgt2SetVel(p);
    *(f32*)(p + 0x284) = 0.0f;
    *(s32*)(p + 0x23c) = 8;
    *(f32*)(p + 0x44) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x268) = 0.3f;
    *(f32*)(p + 0x26c) = 1.0f;
    *(f32*)(p + 0x270) = 1.0f;
    *(f32*)(p + 0x274) = 0.0f;
    *(f32*)(p + 0x278) = 1.3f;

    if ((lbl_8053AB88 & 1) == 0) {
        *(s32*)(p + 0x254) = 1;
    } else {
        *(s32*)(p + 0x254) = -1;
    }
    lbl_8053AB88++;
    lbl_8053AB88 &= 1;
    *(s32*)(p + 0xb0) = 0x12202;
    *(s32*)(p + 0x230) = 0;

    dgt2SetVel(p);
    dgt2SetPoint(p + 0x2ac, p, -2);
    dgt2SetPoint(p + 0x2b8, p, 2);
}

struct Dgt2Child { u8 pad[0x24]; s32 dead; u8 pad2[0xf4 - 0x28]; u32 flags; };
struct Dgt2Links { u8 pad[0x3c0]; Dgt2Child* child[3]; };

// Release the three linked child actors.
extern "C" void fn_8018EB94(void* this_) {
    char* p = (char*)this_;
    DrawRec rec;
    f32 mtx[3][4];
    f32 z = *(f32*)(p + 0x14);
    if ((*(u32*)(p + 0x240) & 1) != 0) {
        u8* r = (u8*)&rec;
        r[0x17] = 0;
        r[0x14] = 0x80;
        r[0x15] = 0x80;
        r[0x16] = 0x80;
    }
    rec.b1d = 1;

    PSMTXIdentity(mtx);
    dgt2Rot(mtx, *(f32*)(p + 0x270));
    rec.w18 = mtx;
    dgt2DrawAt(this_, 0x29, &rec, (JGeometry::TVec3<f32>*)(p + 0x2a0), z, lbl_8053E1E0, lbl_8053E1E0);

    PSMTXIdentity(mtx);
    dgt2Rot(mtx, *(f32*)(p + 0x270));
    rec.w18 = mtx;
    dgt2DrawAtK(this_, 0x27, &rec, 2, (JGeometry::TVec3<f32>*)(p + 0x294), z, lbl_8053E1E0, lbl_8053E1E0);

    PSMTXIdentity(mtx);
    dgt2Rot(mtx, *(f32*)(p + 0x270));
    rec.w18 = mtx;
    dgt2DrawAtK(this_, 0x26, &rec, 3, (JGeometry::TVec3<f32>*)(p + 0x288), z, lbl_8053E1E0, lbl_8053E1E0);

    rec.b1d = 4;
    PSMTXIdentity(mtx);
    dgt2Rot(mtx, *(f32*)(p + 0x274));
    rec.w18 = mtx;
    dgt2DrawAt(this_, 0x2a, &rec, (JGeometry::TVec3<f32>*)(p + 0x2ac), z, lbl_8053E1E0, lbl_8053E1E0);

    PSMTXIdentity(mtx);
    dgt2Rot(mtx, -*(f32*)(p + 0x274));
    rec.w18 = mtx;
    dgt2DrawAt(this_, 0x2a, &rec, (JGeometry::TVec3<f32>*)(p + 0x2b8), z, lbl_8053E1E0, lbl_8053E1E0);

    *(JGeometry::TVec3<f32>*)(p + 0xc) = *(JGeometry::TVec3<f32>*)(p + 0x288);
    *(f32*)(p + 0x14) = z;
}

extern "C" s32 fn_801F3D94(void* a, s32 b);
extern "C" u8 fn_801F305C(void* a);
extern "C" u8 fn_801F2618(void* a, s32 b, s32 c);
extern "C" void fn_801F71A4(void* v, f32 a, f32 b, f32 c);
extern "C" void fn_801F2B7C(void* a, s32 hit, s32 b, s32 c);
extern "C" void fn_801F0E34(void* a, s32 flags, s32 b);
extern "C" s32 fn_8013CC50(s32 room, void* v, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_8013CB44(void* h, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_801EEC98(void* a, void* h, u16* out, s32 x6, s32 x7, s32 x8, s32 x9, s32 x10);
extern s32 lbl_80539FE0[2];
extern s32 lbl_80539FD8[2];
extern const f32 lbl_8053E1E4;
extern const f32 lbl_8053E1E8;
extern const f32 lbl_8053E1EC;
extern const f32 lbl_8053E1C8;

static inline s32 dgt2AngleSlot(f32 x) {
    s32 n;
    for (n = 0; n < 15; n++) {
        x -= lbl_8053E1C8;
        if (x < lbl_8053E1D8) {
            break;
        }
    }
    return n;
}

extern "C" void fn_8018F2DC(void* this_) {
    s32 found = 0;
    char* p = (char*)this_;
    JGeometry::TVec3<f32> pos0 = *(JGeometry::TVec3<f32>*)(p + 0xc);
    JGeometry::TVec3<f32> vel0 = *(JGeometry::TVec3<f32>*)(p + 0x3c);
    f32 z0 = *(f32*)(p + 0x14);

    {
        char* t = p;
        for (s32 m = 0; m < 5; m++, t += 4) {
            if (*(s32*)(t + 0x234) > 0) {
                *(s32*)(t + 0x234) = *(s32*)(t + 0x234) - 1;
            }
        }
    }

    switch (*(s32*)(p + 0x230)) {
    case 0: {
        char* q;
        s32 i;
        for (i = 0, q = p; i < 3; i++, q += 0xc) {
            *(JGeometry::TVec3<f32>*)(p + 0xc) = *(JGeometry::TVec3<f32>*)(q + 0x288);
            if (fn_801F3D94(p, 1) != 0 || fn_801F305C(p)) {
                fn_801F2618(p, 0, 0);
                found = 1;
                break;
            }
        }

        if (found == 0) {
            *(JGeometry::TVec3<f32>*)(p + 0xc) = pos0;
            *(f32*)(p + 0x14) = z0;
            fn_801F71A4(p + 0x3c, *(f32*)(p + 0x27c), *(f32*)(p + 0x268), *(f32*)(p + 0x26c));
            fn_801F71A4(p + 0x40, *(f32*)(p + 0x280), *(f32*)(p + 0x268), *(f32*)(p + 0x26c));

            ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));

            fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 1);
            if (fn_801F2618(p, 0, 0) && *(s32*)(p + 0x238) == 0) {
                *(s32*)(p + 0x98) = *(s32*)(p + 0x98) + 8;
                *(s32*)(p + 0x98) = *(s32*)(p + 0x98) & 0xf;
                if (*(s32*)(p + 0x264) == *(s32*)(p + 0x98)) {
                    *(s32*)(p + 0x98) = *(s32*)(p + 0x98) + (*(s32*)(p + 0x254) << 2);
                    *(s32*)(p + 0x98) = *(s32*)(p + 0x98) & 0xf;
                }
                *(s32*)(p + 0x264) = *(s32*)(p + 0x260);
                *(s32*)(p + 0x260) = *(s32*)(p + 0x98);
                *(s32*)(p + 0x25c) = *(s32*)(p + 0x98);
                *(s32*)(p + 0x238) = 8;
                *(s32*)(p + 0x23c) = 8;

                u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
                *seed = *seed * 0x19660du + 0x3c6ef35fu;
                u32 bits = (*seed >> 9) | 0x3f800000u;
                if (*(f32*)&bits - lbl_8053E1E0 < lbl_8053E1DC) {
                    *(s32*)(p + 0x254) *= -1;
                }

                fn_801F0E34(p, 0x4000b, 0);
                dgt2SetVel(p);
                *(JGeometry::TVec3<f32>*)(p + 0x3c) = *(JGeometry::TVec3<f32>*)(p + 0x27c);
            }
        }

        for (s32 j = 0x12; j >= 0; j--) {
            *(JGeometry::TVec3<f32>*)(p + 0x2d0 + (j + 1) * 12) = *(JGeometry::TVec3<f32>*)(p + 0x2d0 + j * 12);
            *(f32*)(p + 0x2e4 + j * 12) = z0;
        }
        *(f32*)(p + 0x14) = z0;
        dgt2CopyPos(p + 0x2d0, p);

        char* s;
        if (found != 0) {
            s = p + lbl_80539FE0[0] * 12;
            *(f32*)(p + 0x294) = *(f32*)(s + 0x2d0);
            *(f32*)(p + 0x298) = *(f32*)(s + 0x2d4);
            *(f32*)(p + 0x29c) = *(f32*)(s + 0x2d8);
            s = p + lbl_80539FE0[1] * 12;
            *(f32*)(p + 0x2a0) = *(f32*)(s + 0x2d0);
            *(f32*)(p + 0x2a4) = *(f32*)(s + 0x2d4);
            *(f32*)(p + 0x2a8) = *(f32*)(s + 0x2d8);
            *(f32*)(p + 0x288) = *(f32*)(p + 0x2d0);
            *(f32*)(p + 0x28c) = *(f32*)(p + 0x2d4);
            *(f32*)(p + 0x290) = *(f32*)(p + 0x2d8);
        } else {
            s = p + lbl_80539FD8[0] * 12;
            *(f32*)(p + 0x294) = *(f32*)(s + 0x2d0);
            *(f32*)(p + 0x298) = *(f32*)(s + 0x2d4);
            *(f32*)(p + 0x29c) = *(f32*)(s + 0x2d8);
            s = p + lbl_80539FD8[1] * 12;
            *(f32*)(p + 0x2a0) = *(f32*)(s + 0x2d0);
            *(f32*)(p + 0x2a4) = *(f32*)(s + 0x2d4);
            *(f32*)(p + 0x2a8) = *(f32*)(s + 0x2d8);
            *(f32*)(p + 0x288) = *(f32*)(p + 0x2d0);
            *(f32*)(p + 0x28c) = *(f32*)(p + 0x2d4);
            *(f32*)(p + 0x290) = *(f32*)(p + 0x2d8);
        }

        if (*(void**)(p + 0x3c4) == 0) {
            *(s32*)(p + 0x3c4) = fn_8013CC50(*(s32*)(p + 0x4), p + 0x294, lbl_8053E1E4, 0x11c, 0, -1, 0, 0, 1);
        } else {
            fn_8013CB44(*(void**)(p + 0x3c4), p + 0x294, 0, -1, 1);
        }

        if (*(s32*)(p + 0x23c) == 0 && found == 0) {
            u16 v = 0;
            u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
            *seed = *seed * 0x19660du + 0x3c6ef35fu;
            u32 bits = (*seed >> 9) | 0x3f800000u;
            *(s32*)(p + 0x23c) = (s32)(lbl_8053E1E8 * (*(f32*)&bits - lbl_8053E1E0)) + 0x1e;
            fn_801EEC98(p, *(void**)(p + 0x198), &v, 0, 0, 0, 0, 0);
            *(s32*)(p + 0x25c) = dgt2AngleSlot(v);
        }

        if (*(s32*)(p + 0x25c) != *(s32*)(p + 0x98) && (*(s32*)(p + 0x23c) & 3) == 0) {
            *(s32*)(p + 0x98) = *(s32*)(p + 0x98) + *(s32*)(p + 0x254);
            *(s32*)(p + 0x98) = *(s32*)(p + 0x98) & 0xf;
        }

        dgt2SetVel(p);
        dgt2SetPoint(p + 0x2ac, p, -2);
        dgt2SetPoint(p + 0x2b8, p, 2);

        *(f32*)(p + 0x270) = *(f32*)(p + 0x270) + lbl_8053E1EC;
        break;
    }
    }
    if (*(s32*)(p + 0x234) == 0) {
        *(s32*)(p + 0x234) = 2;
        *(f32*)(p + 0x274) = *(f32*)(p + 0x274) + lbl_8053E1DC;
    }
}

extern "C" void fn_8018FAB4(Dgt2Links* this_) {
    for (int i = 0; i < 3; i++) {
        Dgt2Child* c = this_->child[i];
        if (c != 0) {
            c->flags |= 1;
            c->dead = 1;
            this_->child[i] = 0;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
