// OIWA_800F4C70: .text 0x800F4C70-0x800F6820 (actor OIWA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

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

extern "C" void fn_800F5E08(char* this_);
extern "C" void fn_800F555C(char* this_);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void fn_801F0E34(void* actor, u32 msg, s32 arg);
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, s32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, u32 room, s32 b, f32 x, f32 y);

#define OIWA_POS(p) (*(JGeometry::TVec3<f32>*)((p) + 0xc))
static inline bool oiwaIsZero(const JGeometry::TVec3<f32>& v) {
    f32 z = 0.0f;
    return v.x == z && v.y == z && v.z == z;
}
#define OIWA_VEL(p) (*(JGeometry::TVec3<f32>*)((p) + 0x3c))

extern "C" void fn_800F5248(char* this_) {
    switch (*(u8*)(this_ + 0x230)) {
    case 0:
    case 4:
        fn_800F5E08(this_);
        break;
    case 1:
        f32 z = 0.0f;
        if (*(f32*)(this_ + 0x3c) != z || *(f32*)(this_ + 0x40) != z || *(f32*)(this_ + 0x44) != z) {
            fn_801F2B7C(this_, 2, -1, 6);
            *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.2f;
        } else {
            *(s32*)(this_ + 0x23c) = 0;
        }
        OIWA_POS(this_) += OIWA_VEL(this_);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            fn_801F0E34(this_, 0x30075, 0);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x76, 0, 0, 0, 0, 1, 0.8f);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x77, 0, 0, 0, 0, 1, 0.8f);
            fn_802D79E8(fn_802D6A9C(), *(u32*)(this_ + 4), 0, 4.0f, 0.0f);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    case 2:
        fn_801F2B7C(this_, 1, -1, 1);
        *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.2f;
        OIWA_POS(this_) += OIWA_VEL(this_);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x76, 0, 0, 0, 0, 1, 0.2f);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x77, 0, 0, 0, 0, 1, 0.2f);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    case 3:
        fn_800F555C(this_);
        break;
    case 5:
        *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.03f;
        *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + *(s32*)(this_ + 0x248);
        OIWA_POS(this_) += OIWA_VEL(this_);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            f32 scale = 1.0f;
            if (*(s32*)(this_ + 0x240) > 1) {
                scale = 0.5f;
            }
            fn_801F0E34(this_, 0x3005a, 0);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x497, 0, 0, 0, 0, 1, scale);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x498, 0, 0, 0, 0, 1, scale);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
