// NZMI_800F3C10: .text 0x800F3C10-0x800F46C0 (actor NZMI)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_800F3C10_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C400[];

extern "C" void* fn_800F3C10(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C400;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_800F3C70: draw
struct NZMI_DrawKey {
    s32 a, b;
    NZMI_DrawKey() { a = -1; b = -1; }
};
struct NZMI_DrawParam {
    u8 map[16];      // 0x00
    NZMI_DrawKey key; // 0x10
    void* c;         // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    NZMI_DrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_80463660[];
extern u8 lbl_80539E68[8];
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, NZMI_DrawParam* param, s32 a, f32 sx, f32 sy);

extern "C" void fn_800F3C70(u8* this_) {
    NZMI_DrawParam param;
    f32 m[3][4];
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    if (*(u32*)(this_ + 0x90) != 0) {
        m[0][1] = 0.0f;
        m[0][0] = 1.2f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.2f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.2f;
        param.c = m;
    }
    fn_801F06F0(this_, lbl_80463660,
                0xA1 + *(s32*)(this_ + 0x240) + *(u8*)(this_ + 0x234) * 2 + lbl_80539E68[*(u8*)(this_ + 0x235)] * 4,
                &param, 0, 1.0f, 1.0f);
}

// ---- fn_800F43D0: init

struct NZMI_Random {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct NZMI_Game { u8 pad[0xb4]; NZMI_Random rnd; };
extern NZMI_Game* lbl_8053AAF8;

extern "C" void fn_800F43D0(u8* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6C) = 8.0f;
    *(f32*)(this_ + 0x80) = -10.0f;
    *(f32*)(this_ + 0x84) = -10.0f;
    *(f32*)(this_ + 0x88) = 10.0f;
    *(f32*)(this_ + 0x8C) = 10.0f;
    *(u32*)(this_ + 0xB0) = 0x11101;
    *(s32*)(this_ + 0x240) = 0;
    *(u8*)(this_ + 0x235) = 0;
    *(s32*)(this_ + 0x230) = 1;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23C) = 0;
    *(u8*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x244) = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 0x32;
    *(u32*)(this_ + 0x90) &= 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
