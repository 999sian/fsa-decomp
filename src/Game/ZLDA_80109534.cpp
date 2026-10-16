#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void* fn_801F856C();
extern "C" s32 fn_801F7A08(void*, u32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_801F31C4(void*, f32*);
extern int __float_epsilon[];
extern const f32 lbl_8053C3E0;
extern const f32 lbl_8053C3EC;
extern const f32 lbl_8053C3F0;
extern const f32 lbl_8053C400;
extern const f32 lbl_8053C410;
extern const f32 lbl_8053C414;
extern const f32 lbl_8053C418;
extern "C" s32 fn_80109AE0(char* self, f32* out) {
    out[2] = lbl_8053C3E0;
    out[1] = lbl_8053C3E0;
    out[0] = lbl_8053C3E0;
    s32 id = fn_801F7A08(fn_801F856C(), 0x43495243);
    if (id < 0) return 0;
    char* o = (char*)fn_801F666C(fn_801F856C(), id);
    if (o == 0) return 0;
    if (*(u8*)(o + 0x11c) == 0) return 0;
    if (*(s32*)(self + 4) != *(s32*)(o + 4)) return 0;
    f32 a[4], b[4];
    fn_801F31C4(self, a);
    fn_801F31C4(o, b);
    b[0] += lbl_8053C410;
    b[1] += lbl_8053C410;
    b[2] += lbl_8053C3EC;
    b[3] += lbl_8053C3EC;
    f32 a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
    if (a0 <= b[0]) a0 = b[0];
    if (a1 <= b[1]) a1 = b[1];
    if (a2 >= b[2]) a2 = b[2];
    if (a3 >= b[3]) a3 = b[3];
    bool hit = false;
    if (a2 >= a0 && a3 >= a1) hit = true;
    if (hit) {
        Vec p;
        p = *(Vec*)(o + 0xc);
        Vec* v = (Vec*)out;
        out[0] = *(f32*)(self + 0xc) - p.x;
        out[1] = *(f32*)(self + 0x10) - p.y;
        out[2] = lbl_8053C3E0;
        f32 sq = JMathInlineVEC::PSVECSquareMag(v);
        if (!(sq <= lbl_8053C400 * *(f32*)__float_epsilon)) {
            f32 inv;
            if (sq <= lbl_8053C3E0) {
                inv = sq;
            } else {
                f32 y = __frsqrte(sq);
                inv = lbl_8053C3F0 * y * (lbl_8053C414 - sq * (y * y));
            }
            JMathInlineVEC::PSVECScale(v, v, inv);
        }
        JMathInlineVEC::PSVECScale(v, v, lbl_8053C418);
        return 1;
    }
    return 0;
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049CEE0[];
extern void* lbl_8049CC34[];
extern u8 lbl_8053AA81;
extern const f32 lbl_8053C3E8;
extern "C" void* fn_8010AF3C(u8* self, s16 deleting) {
    if (self) {
        *(void***)(self) = lbl_8049CEE0;
        lbl_8053AA81 = 0;
        if (self + 0x33c) {
            if (self + 0x360) {
                *(void***)(self + 0x360) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

