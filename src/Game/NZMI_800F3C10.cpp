// NZMI_800F3C10: .text 0x800F3C10-0x800F46C0 (actor NZMI)
// NOTE: all functions match except fn_800F3E08, which differs only in stack
// slot assignment of the rand/seek temporaries (0x10-0x18).
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
static inline s32 NZMI_rand(f32 r) { return r * lbl_8053AAF8->rnd.get(); }

// ---- fn_800F3E08: update (wander / chase the nearest player / flee)
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" u8 v17__5ActorFv(void* this_, s32 room, void* pos);
extern "C" void fn_801EEC98(void* this_, void* room, s16* a, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern f32 lbl_8049C3E0[4][2];

class NZMI_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20();
    virtual void vf24();
};

static inline void NZMI_move(u8* this_) {
    *(f32*)(this_ + 0xC) += lbl_8049C3E0[lbl_80539E68[*(u8*)(this_ + 0x235)]][0];
    *(f32*)(this_ + 0x10) += lbl_8049C3E0[lbl_80539E68[*(u8*)(this_ + 0x235)]][1];
}

static inline void NZMI_restartWander(u8* this_) {
    *(s32*)(this_ + 0x244) = NZMI_rand(50.0f) + 0x32;
    *(s32*)(this_ + 0x230) = 1;
    *(s32*)(this_ + 0x23C) = 0;
}

static inline bool NZMI_seek(u8* this_) {
    s16 a = 0;
    f32 dist = 0.0f;
    s32 dir = 0;
    s32 player = 0;
    fn_801EEC98(this_, *(void**)(this_ + 0x198), &a, &dir, &dist, &player, 0, 0);
    if (player != -1 && dist < 120.0f) {
        *(s32*)(this_ + 0x230) = 2;
        *(s32*)(this_ + 0x23C) = 0;
        for (u8 i = 0; i < 4; i++) {
            if (dir == lbl_80539E68[i]) {
                *(u8*)(this_ + 0x235) = i;
                break;
            }
        }
        return true;
    }
    return false;
}

static inline void NZMI_face(u8* this_) {
    s16 a = 0;
    f32 dist = 0.0f;
    s32 dir = 0;
    s32 player = 0;
    fn_801EEC98(this_, *(void**)(this_ + 0x198), &a, &dir, &dist, &player, 0, 0);
    if (player != -1 && dist < 120.0f) {
        for (u8 i = 0; i < 4; i++) {
            if (dir == lbl_80539E68[i]) {
                *(u8*)(this_ + 0x235) = i;
                break;
            }
        }
    }
}

extern "C" void fn_800F3E08(u8* this_) {
    if (fn_801F3D94(this_, 1) != 0 || fn_801F305C(this_)) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    *(s32*)(this_ + 0x238) += 1;
    if (*(s32*)(this_ + 0x238) == 4) {
        *(s32*)(this_ + 0x240) += 1;
        if (*(s32*)(this_ + 0x240) == 2) {
            *(s32*)(this_ + 0x240) = 0;
        }
        *(s32*)(this_ + 0x238) = 0;
    }
    bool hit;
    if (*(u32*)(this_ + 0x90) != 0) {
        hit = fn_801F2B7C(this_, *(u32*)(this_ + 0x114), -1, 4);
    } else {
        hit = fn_801F2B7C(this_, *(u32*)(this_ + 0x114), -1, 1);
    }
    u8 wall = fn_801F2618(this_, 0, 0);
    if (wall && v17__5ActorFv(this_, *(s32*)(this_ + 4), this_ + 0xC) == 1) {
        ((NZMI_Actor*)this_)->vf24();
        return;
    }
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
    case 3: {
        *(u8*)(this_ + 0x234) = 0;
        if (wall) {
            *(u8*)(this_ + 0x235) += 1;
        }
        *(u8*)(this_ + 0x235) &= 3;
        if (*(u32*)(this_ + 0x90) != 0 && *(s32*)(this_ + 0x230) == 0) {
            if (NZMI_seek(this_)) {
                return;
            }
        }
        NZMI_move(this_);
        *(s32*)(this_ + 0x23C) += 1;
        if (*(s32*)(this_ + 0x23C) == *(s32*)(this_ + 0x244)) {
            NZMI_restartWander(this_);
        }
        break;
    }
    case 1:
        *(u8*)(this_ + 0x234) = 1;
        *(s32*)(this_ + 0x23C) += 1;
        if (*(s32*)(this_ + 0x23C) == *(s32*)(this_ + 0x244)) {
            *(s32*)(this_ + 0x244) = NZMI_rand(80.0f) + 10;
            *(u8*)(this_ + 0x235) = NZMI_rand(4.0f);
            *(s32*)(this_ + 0x230) = 0;
            fn_801F0E34(this_, 0x400A6, 0);
            *(s32*)(this_ + 0x23C) = 0;
        }
        break;
    case 2: {
        *(u8*)(this_ + 0x235) &= 3;
        NZMI_move(this_);
        if ((*(s32*)(this_ + 0x23C) & 0x1111) == 0) {
            NZMI_face(this_);
        }
        if (hit == true) {
            *(s32*)(this_ + 0x244) = 100;
            *(s32*)(this_ + 0x230) = 3;
            *(s32*)(this_ + 0x23C) = 0;
        } else {
            *(s32*)(this_ + 0x23C) += 1;
            if (*(s32*)(this_ + 0x23C) == 100 || wall) {
                NZMI_restartWander(this_);
            }
        }
        break;
    }
    }
}

// ---- fn_800F43D0: init

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
    *(s32*)(this_ + 0x244) = NZMI_rand(50.0f) + 0x32;
    *(u32*)(this_ + 0x90) &= 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
