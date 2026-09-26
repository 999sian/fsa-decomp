// DBRK_8014529C: .text 0x8014529C-0x80145F60 (actor DBRK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8014529C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F498[];

extern "C" void* fn_8014529C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F498;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* actor, const char* tbl, s32 idx, u32 p4, s32 p5, f32 a, f32 b);
extern const char lbl_80465BA8[];
extern const f32 lbl_8053D020;
extern const f32 lbl_8053D034;
extern const f32 lbl_8053D038;
extern const f32 lbl_8053D03C;

extern "C" void fn_801452FC(char* this_) {
    s32 state = *(s32*)(this_ + 0x230);
    s32 idx = *(s32*)(this_ + 0x244) + *(s32*)(this_ + 0x98) * 2;
    if (state == 3 || state == 4) {
        idx = 8;
    }
    if (state != 4 || (*(u32*)(this_ + 0x23c) & 1)) {
        fn_801F06F0(this_, lbl_80465BA8, idx + 0x1c, 0, 0, lbl_8053D020, lbl_8053D020);
    }
}

struct DbrkRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053D020;
    }
};
struct DbrkGame { u8 pad[0xb4]; DbrkRandom rnd; };
extern DbrkGame* lbl_8053AAF8;

extern "C" void fn_80145C70(char* this_) {
    f32 b = lbl_8053D03C;
    f32 a = lbl_8053D038;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(s32*)(this_ + 0x98) = (s32)(lbl_8053D034 * lbl_8053AAF8->rnd.get_ufloat_1()) & 3;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x108) = 4;
    *(s32*)(this_ + 0x250) = 1;
    *(u32*)(this_ + 0xb0) = 0x08042104;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
