#include "types.h"
#include "Game/SinitPoolChain.h"


extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804ABA38[];
struct Vec2_FSA {
    f32 x;
    f32 y;
};

extern "C" void* fn_80335A7C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804ABA38;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_80542020;
extern "C" f32 lbl_80541FF8;

static inline f32 rand01(void) {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = *s * 0x19660du + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - 1.0f;
}

extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void* fn_801F856C(void);
extern "C" void fn_80335D4C(void* this_) {
    u8* p = (u8*)this_;
    u32 seed;
    u32 bits;
    f32 rnd;

    *(u32*)(p + 0xb0) = 0x2000;
    *(f32*)(p + 0x238) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x23c) = lbl_80542020;
    p[0x244] = (*(u32*)(p + 0x90) >> 8) & 0xff;
    p[0x245] = (*(u32*)(p + 0x90) >> 16) & 0xff;
    seed = *(u32*)((u8*)lbl_8053AAF8 + 0xb4);
    seed = seed * 1664525 + 1013904223;
    *(u32*)((u8*)lbl_8053AAF8 + 0xb4) = seed;
    bits = (*(u32*)((u8*)lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
    rnd = *(f32*)&bits;
    *(s32*)(p + 0x240) = (s32)((f32)p[0x245] * (rnd - lbl_80541FF8));
    p[0x246] = 5;
    p[0x247] = *(u32*)(p + 0x90) & 0xf;
    p[0x248] = (*(u32*)(p + 0x90) >> 4) & 0xf;
}



