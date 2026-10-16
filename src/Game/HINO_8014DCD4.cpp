#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" char lbl_80465D60[];
extern "C" f32 lbl_8053D1D0;
extern "C" void fn_801F06F0(void* this_, char* str, s32 a, s32 b, s32 c, f32 f1, f32 f2);
extern "C" void fn_8014DCD4(u8* this_) {
    f32 f = lbl_8053D1D0;
    s32 n = *(s32*)(this_ + 0x264);
    fn_801F06F0(this_, lbl_80465D60, n + 0x2b, 0, 7, f, f);
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
            JGeometry::TVec3f v(lbl_8053D1D4, lbl_8053D1D4, lbl_8053D1D4);
            v.z = lbl_8053D1EC;
            *(JGeometry::TVec3f*)(p + 0x3c) = v;
            *(s32*)(this_ + 0x250) = -1;
            fn_801F0E34(this_, 0x40008, 0);
        }
    }
}

