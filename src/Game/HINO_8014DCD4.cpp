#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

extern "C" char lbl_80465D60[];
extern "C" f32 lbl_8053D1D0;
extern "C" f32 lbl_8053D1D4;
extern "C" void fn_801F06F0(void* this_, char* str, s32 a, s32 b, s32 c, f32 f1, f32 f2);
extern "C" void fn_8014DCD4(u8* this_) {
    const f32 f = lbl_8053D1D0;
    fn_801F06F0(this_, lbl_80465D60, *(s32*)(this_ + 0x264) + 0x2b, 0, 7, f, f);
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 fn_801F0E34(void* a, u32 code, u32 z);
extern "C" f32 lbl_8053D1D4;
extern "C" f32 lbl_8053D1EC;
extern "C" f32 lbl_8053D1DC;
extern "C" f32 lbl_8053D210;
extern "C" f32 lbl_8053D21C;
extern "C" f32 lbl_8053D250;
extern "C" f32 lbl_8053D254;

struct HinoRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053D1D0;
    }
};
struct HinoGame { u8 pad[0xb4]; HinoRandom rnd; };
extern HinoGame* lbl_8053AAF8;
extern "C" void fn_8014F76C(u8* this_) {
    s32 id = *(s32*)(this_ + 0x250);
    if (id >= 0) {
        u8* p = (u8*)fn_801F666C(fn_801F856C(), id);
        if (p != 0) {
            JGeometry::TVec3f v;
            v.y = lbl_8053D1D4;
            v.x = lbl_8053D1D4;
            v.z = lbl_8053D1D4;
            v.z = lbl_8053D1EC;
            *(JGeometry::TVec3f*)(p + 0x3c) = v;
            *(s32*)(this_ + 0x250) = -1;
            fn_801F0E34(this_, 0x40008, 0);
        }
    }
}

extern "C" char lbl_8049F9B4[];
extern "C" f32 lbl_8053D1E0;
extern "C" f32 lbl_8053D1E4;
extern "C" f32 lbl_8053D1E8;
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_801F2618(void* this_, void* out, s32 a);
extern "C" void __dt__5ActorFv(void* this_, s32 in);
extern "C" int fn_8022F784(int index, int a0, const JGeometry::TVec3<f32>& a1);
extern "C" void* fn_8014F7FC(u8* this_, int flag) {
    s32 id;
    u8* self = this_;
    int del = flag;
    JGeometry::TVec3f w;
    JGeometry::TVec3f v;
    if (self != 0) {
        *(void**)self = lbl_8049F9B4;
        v.z = 0.0f;
        v.y = 0.0f;
        v.x = 0.0f;
        if (*(s32*)(self + 0x98) == 2) {
            v.x = 0.0f;
            v.y = lbl_8053D1E0;
            v.z = 0.0f;
        } else {
            v.x = 0.0f;
            v.y = lbl_8053D1E4;
            v.z = 0.0f;
        }
        if (*(s32*)(self + 0x254) >= 0) {
            f32 ox = *(f32*)(self + 0xc);
            f32 oy = *(f32*)(self + 0x10);
            f32 oz = *(f32*)(self + 0x14);
            f32* t = (f32*)fn_8023E724(*(s32*)(self + 0x254));
            *(f32*)(self + 0xc) = t[0];
            *(f32*)(self + 0x10) = t[1];
            *(f32*)(self + 0x14) = t[2];
            if (fn_801F2618(self, 0, 0)) {
                f32 ang = JMath::atanTable_.atan2_(ox - *(f32*)(self + 0xc), oy - *(f32*)(self + 0x10));
                s32 idx = (s32)(ang * lbl_8053D1E8);
                v.x = lbl_8053D1EC * JMath::sincosTable_.sinShort(idx);
                v.y = lbl_8053D1EC * JMath::sincosTable_.cosShort(idx);
            }
            *(f32*)(self + 0xc) = ox;
            *(f32*)(self + 0x10) = oy;
            *(f32*)(self + 0x14) = oz;
            fn_8022F784(*(s32*)(self + 0x254), *(s32*)(self + 0x198), v);
        }
        id = *(s32*)(self + 0x250);
        if (id >= 0) {
            u8* p = (u8*)fn_801F666C(fn_801F856C(), id);
            if (p != 0) {
                w.y = 0.0f;
                w.x = 0.0f;
                w.z = 0.0f;
                w.z = lbl_8053D1EC;
                *(JGeometry::TVec3f*)(p + 0x3c) = w;
                *(s32*)(self + 0x250) = -1;
                fn_801F0E34(self, 0x40008, 0);
            }
        }
        __dt__5ActorFv(self, 0);
        if ((s16)del > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" void fn_8014F9FC(u8* this_) {
    f32 a = lbl_8053D250;
    f32 c = lbl_8053D21C;
    *(f32*)(this_ + 0x60) = a;
    f32 b = lbl_8053D254;
    *(f32*)(this_ + 0x64) = a;
    f32 d = lbl_8053D210;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = c;
    *(f32*)(this_ + 0x80) = d;
    *(f32*)(this_ + 0x84) = d;
    *(f32*)(this_ + 0x88) = c;
    *(f32*)(this_ + 0x8c) = c;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x90) &= 1;
    *(s32*)(this_ + 0x264) = 0;
    *(s32*)(this_ + 0x268) = -1;
    if (*(u32*)(this_ + 0x90) != 1) {
        *(u32*)(this_ + 0xb0) = 0x9042012;
    }
    *(s32*)(this_ + 0xbc) = 3;
    *(s32*)(this_ + 0xb8) = 1;
    f32 one = lbl_8053D1D0;
    *(s32*)(this_ + 0x98) = 2;
    f32 lim = lbl_8053D1DC;
    HinoRandom* rnd = &lbl_8053AAF8->rnd;
    rnd->seed = rnd->seed * 0x19660d + 0x3c6ef35f;
    union {
        f32 f;
        u32 s;
    } u;
    u.s = (rnd->seed >> 9) | 0x3f800000;
    if (u.f - one < lim) {
        *(s32*)(this_ + 0x98) = 3;
    }
    *(s16*)(this_ + 0x26c) = 0;
    f32 z = lbl_8053D1D4;
    *(f32*)(this_ + 0x278) = z;
    *(f32*)(this_ + 0x274) = z;
    *(f32*)(this_ + 0x270) = z;
    *(f32*)(this_ + 0x284) = z;
    *(f32*)(this_ + 0x280) = z;
    *(f32*)(this_ + 0x27c) = z;
    *(s16*)(this_ + 0x26e) = 0;
    *(s32*)(this_ + 0x250) = -1;
    *(s32*)(this_ + 0x254) = -1;
    *(s32*)(this_ + 0x230) = 0;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
