// OKTA_8013F9A8: .text 0x8013F9A8-0x80140E24 (actor OKTA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8013F9A8_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F208[];

extern const f32 lbl_8053CE28;
extern const f32 lbl_8053CE2C;
extern const f32 lbl_8053CE34;
extern const f32 lbl_8053CE3C;
extern const f32 lbl_8053CE50;
extern const f32 lbl_8053CE54;
extern const f32 lbl_8053CE80;
extern const f32 lbl_8053CE84;
extern const f32 lbl_8053CE88;
extern const f32 lbl_8053CE8C;
extern const f32 lbl_8053CE90;
extern const f32 lbl_8053CE94;
extern const f32 lbl_8053CE98;

struct OktaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053CE2C;
    }
};
struct OktaGame { u8 pad[0xb4]; OktaRandom rnd; };
extern OktaGame* lbl_8053AAF8;
extern s32 lbl_8053AB28;

extern "C" void* fn_8013F9A8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F208;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
