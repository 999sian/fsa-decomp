// Poon actor ("Poon" actor id, mixed case in the table). TU 80167938-801688AC.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), init (slot 1).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "std/math.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A06C0[];

// Poon destructor
extern "C" void* fn_80167938(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A06C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


struct PoonDrawParam {
    PoonDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};

struct PoonResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};

extern "C" double sin(double);
extern "C" double cos(double);
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern const char lbl_80466338[];
extern "C" void fn_802F86CC(void* map, void* pos, void* res, s32 id, PoonDrawParam* prm, f32 a, f32 b);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);

#pragma opt_strength_reduction off
extern "C" void fn_80167998(char* this_) {
             if (*(s32*)(this_ + 0x230) == 2) {
                 PoonDrawParam prm;
                 f32 mtx[3][4];
              register f32 scale;
            f32 ry;
            register f32 cx;
                 prm.reset();
                 mtx[0][3] = 0.0f;
                 mtx[1][3] = 0.0f;
                 mtx[2][3] = 0.0f;
                 prm.mMtx = mtx;
                 f32 rx = 0.0f;
               ry = *(f32*)(this_ + 0x258);
               scale = *(f32*)(this_ + 0x254);
                 f32 rz = 0.0f;
                 f32 sx = sin(rx);
                 f32 sy = sin(ry);
                 f32 sz = sin(rz);
                 cx = cos(rx);
                 f32 cy = cos(ry);
                 f32 sxsy;
                 f32 cz = cos(rz);
          f32 cxsz, cxcz;
        cxcz = cx * cz;
        sxsy = sx * sy;
        cxsz = cx * sz;
                 mtx[0][0] = scale * (cy * cz);
                 mtx[1][0] = scale * (cy * sz);
                 mtx[2][0] = scale * -sy;
                 mtx[0][1] = scale * (sxsy * cz - cxsz);
                 mtx[1][1] = scale * (sxsy * sz + cxcz);
                 mtx[2][1] = scale * (sx * cy);
                 mtx[0][2] = scale * (cxcz * sy + sx * sz);
                 mtx[1][2] = scale * (cxsz * sy - sx * cz);
                 mtx[2][2] = scale * (cx * cy);
                 prm.mMtx = mtx;
                 s32 id = *(s32*)(this_ + 0x250) + 0x92;
                 if (*(s32*)(this_ + 0x4) < 8) {
                     void* res = (*(PoonResMgr**)(lbl_8053AAF8 + 0xa4))->get('SOB ', lbl_80466338);
                     fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, &prm, 1.0f, 1.0f);
                 }
             } else {
                 fn_801F06F0(this_, lbl_80466338, *(s32*)(this_ + 0x250) + 0x92, 0, 0, 1.0f, 1.0f);
             }
         }
#pragma opt_strength_reduction reset
extern "C" u8 sincosTable___5JMath[];
extern "C" u16 fn_8022461C(void* p, s32 room);
extern "C" u8 fn_802DE9A0(void);
extern "C" s32 fn_801F3D94(char* this_, s32 a);
extern "C" u8 fn_801F2DB4(char* this_, u32 a, u32 b, s32 c);
extern "C" void fn_801F2618(char* this_, s32 a, s32 b);
extern "C" s32 fn_801F285C(char* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801F71A4(void* p, f32 a, f32 b, f32 c);
extern "C" void fn_801EEC98(char* this_, s32 h, s16* a, s32* b, f32* c, s32 d, s32 e, s32 f);
extern "C" u8 fn_801F2B7C(char* this_, s32 a, s32 b, s32 c);
extern "C" u8 fn_80237948(s32 a, void* v);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_801F0E34(char* this_, s32 a, s32 b);
extern "C" void fn_8013CC50(s32 a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void detach__5ActorFv(void* this_);
extern "C" double sqrt(double);
static inline f32 poonSqrt(f32 x) {
    if (x > 0.0f) {
        f64 g = __frsqrte(x);
        g = 0.5 * g * (3.0 - g * g * x);
        g = 0.5 * g * (3.0 - g * g * x);
        g = 0.5 * g * (3.0 - g * g * x);
        x = x * g;
    } else if (x < 0.0 || isnan(x)) {
        x = NAN;
    }
    return x;
}

static inline void poonTickTimers(char* p) {
    for (int i = 0; i < 4; i++, p += 4) {
        if (*(s32*)(p + 0x234) > 0) {
            --*(s32*)(p + 0x234);
        }
    }
}

#pragma opt_propagation reset
static inline JGeometry::TVec2f poonCenter(const JGeometry::TVec3f& pos, const f32* bounds) {
    f32 x0 = bounds[0] + pos.x;
    f32 y0 = bounds[1] + pos.y;
    f32 x1 = bounds[2] + pos.x;
    f32 y1 = bounds[3] + pos.y;
    return JGeometry::TVec2f((x0 - x1) * 0.5f + x1, (y0 - y1) * 0.5f + y1);
}
#pragma opt_strength_reduction reset
#pragma peephole off
extern "C" void fn_80167C94(char* this_) {
    s32 i;
    s32 r29;
    u16 ang = 0;
    s32 flag = 0;
    f32 fv = 0.0f;
    if (*(s32*)(this_ + 0x230) != 2) {
        if (*(s32*)(this_ + 0x23c) != 0) {
            *(f32*)(this_ + 0x260) = *(f32*)(this_ + 0xc);
            *(f32*)(this_ + 0x264) = *(f32*)(this_ + 0x10);
            *(f32*)(this_ + 0x268) = *(f32*)(this_ + 0x14);
            *(f32*)(this_ + 0x260) = (f32)((s32)*(f32*)(this_ + 0x260) & 0xfff8);
            *(f32*)(this_ + 0x264) = (f32)((s32)*(f32*)(this_ + 0x264) & 0xfff8);
            *(f32*)(this_ + 0x260) = -16.0f * *(f32*)(sincosTable___5JMath + ((*(u32*)(this_ + 0x24c) >> 2) & 0x3ff8)) + *(f32*)(this_ + 0x260);
            *(f32*)(this_ + 0x264) = -16.0f * *(f32*)(sincosTable___5JMath + ((*(u32*)(this_ + 0x24c) >> 2) & 0x3ff8) + 4) + *(f32*)(this_ + 0x264);
            r29 = (u16)fn_8022461C(this_ + 0x260, *(s32*)(this_ + 4));
            if ((u32)(r29 - 2) <= 1 || r29 == 0xe) {
                if (fn_802DE9A0() == 1 && r29 == 0xe) {
                    *(u8*)(this_ + 0x25c) = 1;
                }
                *(s32*)(this_ + 0xd8) = 0;
                *(s32*)(this_ + 0xdc) = 0;
                *(f32*)(this_ + 0x44) = 0.0f;
                *(f32*)(this_ + 0x40) = 0.0f;
                *(f32*)(this_ + 0x3c) = 0.0f;
                *(f32*)(this_ + 0x274) = 0.0f;
                *(f32*)(this_ + 0x270) = 0.0f;
                *(f32*)(this_ + 0x26c) = 0.0f;
                *(f32*)(this_ + 0x258) = 0.0f;
                *(s32*)(this_ + 0x234) = 0;
                *(s32*)(this_ + 0x238) = 0x1e;
                *(s32*)(this_ + 0x230) = 2;
            }
        }
        if (fn_801F3D94(this_, 1) != 0 || fn_801F2DB4(this_, 0x4e554c4c, 0x4e554c4c, 0) != 0) {
            *(s32*)(this_ + 0x23c) = 0x14;
            fn_801F2618(this_, 0, 0);
            return;
        } else {
            fn_801F71A4(this_ + 0x3c, *(f32*)(this_ + 0x26c), 0.1f, *(f32*)(this_ + 0x278));
            fn_801F71A4(this_ + 0x40, *(f32*)(this_ + 0x270), 0.1f, *(f32*)(this_ + 0x27c));
            ((JGeometry::TVec3f*)(this_ + 0xc))->add(*(JGeometry::TVec3f*)(this_ + 0x3c));
            fn_801EEC98(this_, *(s32*)(this_ + 0x198), (s16*)&ang, &flag, &fv, 0, 0, 0);
            if (fn_801F2B7C(this_, -100, -1, 1) && *(s32*)(this_ + 0x230) == 0) {
                *(f32*)(this_ + 0x3c) = -2.0f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8));
                *(f32*)(this_ + 0x40) = -2.0f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8) + 4);
                *(f32*)(this_ + 0x26c) = 0.0f;
                *(f32*)(this_ + 0x270) = 0.0f;
                *(f32*)(this_ + 0x274) = 0.0f;
                *(s32*)(this_ + 0x248) = 0;
                *(s32*)(this_ + 0x230) = 1;
            }
            fn_801F2618(this_, 0, 0);
        }
    }
    for (int timer = 0; timer < 4; timer++) {
        if (((s32*)(this_ + 0x234))[timer] > 0) {
            ((s32*)(this_ + 0x234))[timer]--;
        }
    }
    switch (*(s32*)(this_ + 0x230)) {
    case 0: {
        if (*(s32*)(this_ + 0x238) == 0) {
            *(f32*)(this_ + 0x26c) = 0.5f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8));
            *(f32*)(this_ + 0x270) = 0.5f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8) + 4);
            if (flag < 0) {
                *(f32*)(this_ + 0x274) = 0.0f;
                *(f32*)(this_ + 0x270) = 0.0f;
                *(f32*)(this_ + 0x26c) = 0.0f;
            }
            *(s32*)(this_ + 0x238) = 0x1e;
        }
        r29 = *(s32*)(this_ + 0x9c);
        void* o;
        if (r29 >= 0 && (o = fn_801F666C(fn_801F856C(), r29)) != 0) {
            f32 angle = JMath::atanTable_.atan2_(*(f32*)((char*)o + 0xc) - *(f32*)(this_ + 0xc), *(f32*)((char*)o + 0x10) - *(f32*)(this_ + 0x10));
            angle *= 10430.4f;
            ang = angle;
            *(f32*)(this_ + 0x3c) = -2.0f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8));
            *(f32*)(this_ + 0x40) = -2.0f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8) + 4);
            *(f32*)(this_ + 0x274) = 0.0f;
            *(f32*)(this_ + 0x270) = 0.0f;
            *(f32*)(this_ + 0x26c) = 0.0f;
            *(s32*)(this_ + 0x248) = 0;
            if (*(s32*)(this_ + 0x240) == 0) {
                fn_801F0E34(this_, 0x400d4, 0);
                *(s32*)(this_ + 0x240) = 8;
            }
            *(s32*)(this_ + 0x230) = 1;
        } else {
            for (i = 0; i < 4; i++) {
                r29 = fn_801F285C(this_, 0, 0, 1, i);
                if (r29 >= 0) {
                    JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(this_ + 0xc));
                    f32 x0, x1, y0, y1;
                    const f32 half = 0.5f;
                    x0 = *(f32*)(this_ + 0x60);
                    x1 = *(f32*)(this_ + 0x68);
                    y0 = *(f32*)(this_ + 0x64);
                    y1 = *(f32*)(this_ + 0x6c);
                    x0 += pos.x;
                    x1 += pos.x;
                    y0 += pos.y;
                    y1 += pos.y;
                    JGeometry::TVec2f center;
                    x0 -= x1;
                    y0 -= y1;
                    x0 = half * x0 + x1;
                    y0 = half * y0 + y1;
                    center.set(x0, y0);
                    if (fn_80237948(r29, &center) && *(s32*)(this_ + 0x240) == 0) {
                        ((void (*)(s32,void*,s32,s32,s32,s32,s32,s32,f32))fn_8013CC50)(*(s32*)(this_ + 4), this_ + 0xc, 0x117, 0, 1, 0, 0, 1, 1.0f);
                        ((void (*)(s32,void*,s32,s32,s32,s32,s32,s32,f32))fn_8013CC50)(*(s32*)(this_ + 4), this_ + 0xc, 0x118, 0, 1, 0, 0, 1, 1.0f);
                        fn_801F0E34(this_, 0x400d4, 0);
                        *(s32*)(this_ + 0x240) = 8;
                    }
                    ang += (s32)(4096.0f - 8192.0f * ((JMARandFast*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1());
                    *(f32*)(this_ + 0x3c) = -6.0f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8));
                    *(f32*)(this_ + 0x40) = -6.0f * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8) + 4);
                    *(f32*)(this_ + 0x26c) = 0.0f;
                    *(f32*)(this_ + 0x270) = 0.0f;
                    *(f32*)(this_ + 0x274) = 0.0f;
                    *(s32*)(this_ + 0x248) = r29 + 1;
                    *(s32*)(this_ + 0x24c) = (u16)ang;
                    *(s32*)(this_ + 0x230) = 1;
                }
            }
        }
    } break;
    case 1: {
        if (*(s32*)(this_ + 0x248) != 0) {
            *(s32*)(this_ + 0x23c) = 10;
        }
        if (*(f32*)(this_ + 0x3c) < 0.2f && *(f32*)(this_ + 0x40) < 0.2f) {
            *(s32*)(this_ + 0x230) = 0;
        }
    } break;
    case 2: {
        fn_801F71A4(this_ + 0xc, *(f32*)(this_ + 0x260), 0.2f, 1.0f);
        fn_801F71A4(this_ + 0x10, *(f32*)(this_ + 0x264), 0.2f, 1.0f);
        {
            f32 dx = *(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x260);
            f32 dy = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x264);
            if (*(s32*)(this_ + 0x238) == 0) {
            f32 d2 = dx * dx + dy * dy;
            if (d2 > 0.0f) {
                f64 g = __frsqrte(d2);
                g = 0.5 * g * (3.0 - g * g * d2);
                g = 0.5 * g * (3.0 - g * g * d2);
                g = 0.5 * g * (3.0 - g * g * d2);
                d2 = d2 * g;
            } else if (d2 < 0.0) {
                d2 = NAN;
            } else if (isnan(d2)) {
                d2 = NAN;
            }
            if (d2 < 2.0f) {
                if (*(s32*)(this_ + 0x250) != 3) {
                    fn_801F0E34(this_, 0x4001a, 0);
                }
                *(s32*)(this_ + 0x250) = 3;
                *(f32*)(this_ + 0x258) += 0.1f;
                *(f32*)(this_ + 0x254) -= 0.02f;
                if (*(f32*)(this_ + 0x254) < 0.1f) {
                    if (*(u8*)(this_ + 0x25c) == 1) {
                        ((void (*)(s32,void*,s32,s32,s32,s32,s32,s32,f32))fn_8013CC50)(*(s32*)(this_ + 4), this_ + 0xc, 0x2a9, -1, 1, 0, 0, 1, 1.0f);
                        ((void (*)(s32,void*,s32,s32,s32,s32,s32,s32,f32))fn_8013CC50)(*(s32*)(this_ + 4), this_ + 0xc, 0x2aa, -1, 0, 0, 0, 1, 1.0f);
                        fn_801F0E34(this_, 0x5005f, 0);
                    }
                    detach__5ActorFv(this_);
                }
                break;
            }
            }
        }
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x234) = 3;
            *(s32*)(this_ + 0x250) += 1;
            if (*(s32*)(this_ + 0x250) > 2) {
                *(s32*)(this_ + 0x250) = 0;
            }
        }
    }
    break;
    }
    if (*(s32*)(this_ + 0x230) != 2 && *(s32*)(this_ + 0x234) == 0) {
        *(s32*)(this_ + 0x234) = 6;
        *(s32*)(this_ + 0x250) += 1;
        if (*(s32*)(this_ + 0x250) > 2) {
            *(s32*)(this_ + 0x250) = 0;
        }
    }
}
#pragma opt_strength_reduction reset
#pragma peephole reset
struct PoonVec { f32 x, y, z; };

// Poon init (vtable slot 1)
extern "C" void fn_801685C8(char* this_) {
    *(f32*)(this_ + 0x60) = -6.0f;
    *(f32*)(this_ + 0x64) = -6.0f;
    *(f32*)(this_ + 0x68) = 6.0f;
    *(f32*)(this_ + 0x6c) = 6.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x278) = 0.2f;
    *(f32*)(this_ + 0x27c) = 0.2f;
    *(f32*)(this_ + 0x280) = 0.2f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(u8*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x254) = 1.0f;
    ((PoonVec*)(this_ + 0x260))->x = ((PoonVec*)(this_ + 0xc))->x;
    ((PoonVec*)(this_ + 0x260))->y = ((PoonVec*)(this_ + 0xc))->y;
    ((PoonVec*)(this_ + 0x260))->z = ((PoonVec*)(this_ + 0xc))->z;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0xb8) = 1;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
