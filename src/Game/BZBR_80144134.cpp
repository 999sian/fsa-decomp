// BZBR_80144134: .text 0x80144134-0x8014529C (actor BZBR)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

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

extern const f32 lbl_8053CFD8;
extern const f32 lbl_8053CFDC;
extern const f32 lbl_8053D010;
extern const f32 lbl_8053D014;
extern const f32 lbl_8053D018;

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
