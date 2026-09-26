// OIWA_800F4C70: .text 0x800F4C70-0x800F6820 (actor OIWA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_800F659C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C4C0[];

extern "C" void* fn_800F659C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C4C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" u32 fn_8022461C(void* p);
extern "C" u8 fn_802265DC(void* a, void* b, u32 c);

extern "C" u8 fn_800F51D8(void* this_, void* a, void* b) {
    s32 kind = (u16)fn_8022461C(b);
    if (kind == 3 || kind == 14 || kind == 2) {
        return 0;
    }
    return fn_802265DC(b, a, 0);
}

struct OiwaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct OiwaGame { u8 pad[0xb4]; OiwaRandom rnd; };
extern OiwaGame* lbl_8053AAF8;

static inline void oiwaSetBox(char* this_, f32 lo, f32 hi) {
    *(f32*)(this_ + 0x60) = lo;
    *(f32*)(this_ + 0x64) = lo;
    *(f32*)(this_ + 0x68) = hi;
    *(f32*)(this_ + 0x6c) = hi;
    *(f32*)(this_ + 0x80) = lo;
    *(f32*)(this_ + 0x84) = lo;
    *(f32*)(this_ + 0x88) = hi;
    *(f32*)(this_ + 0x8c) = hi;
}

extern "C" void fn_800F6328(char* this_) {
    *(s32*)(this_ + 0x23c) = 0;
    *(u8*)(this_ + 0x231) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s8*)(this_ + 0x232) = -1;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(u8*)(this_ + 0x230) = *(u32*)(this_ + 0x90);
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x244) = 0;
    switch (*(u8*)(this_ + 0x230)) {
    case 0:
    case 4:
        oiwaSetBox(this_, -16.0f, 16.0f);
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.5f + lbl_8053AAF8->rnd.get_ufloat_1();
        *(f32*)(this_ + 0x44) = 1.0f;
        break;
    case 1:
        oiwaSetBox(this_, -10.0f, 10.0f);
        break;
    case 2:
        oiwaSetBox(this_, -6.0f, 6.0f);
        *(f32*)(this_ + 0x14) = 1.0f;
        break;
    case 3:
        oiwaSetBox(this_, -16.0f, 16.0f);
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 5:
        oiwaSetBox(this_, -16.0f, 16.0f);
        *(s32*)(this_ + 0x240) = (s32)(5.0f * lbl_8053AAF8->rnd.get_ufloat_1());
        *(s32*)(this_ + 0x244) = 0;
        *(s32*)(this_ + 0x248) = 0x300 - (s32)(1536.0f * lbl_8053AAF8->rnd.get_ufloat_1());
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
