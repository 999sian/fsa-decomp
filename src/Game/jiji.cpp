// TU 0x8037b374-0x8037d784 (actor JIJI).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/Jiji_ctor_8037CE00.cpp ----
// fn_8037CE00 - "JIJI" real constructor. Identical shape to FTGL/TWTG -
// see Ftgl_ctor_80317C38.cpp for the full technique writeup. Base Actor
// ctor + own vtable install, allocates a 0x1c-byte resource handle and
// resets it via fn_8031709C if allocation succeeded,
// storing the handle (or null) at +0x274.



struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_8031709C(void* h);

class ResourceHandle {
public:
    ResourceHandle() { fn_8031709C(this); }
    ~ResourceHandle();
private:
    unsigned char pad[0x1c];
};

extern "C" void* lbl_804AEED0[];

class Jiji : public Actor {
public:
    Jiji();
};

Jiji::Jiji() : Actor() {
    *(void**)this = lbl_804AEED0;
    ResourceHandle* h = new ResourceHandle();
    *(ResourceHandle**)((char*)this + 0x274) = h;
}

// ---- JIJI small state helpers (0x8037B374-0x8037B7EC) ----
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

struct JijiRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct JijiGame { u8 pad[0xb4]; JijiRandom rnd; };
extern JijiGame* lbl_8053AAF8;

struct JijiWork {
    u8 pad0[0xc];
    JGeometry::TVec3<f32> pos;
    u8 pad18[0x234 - 0x18];
    s32 m234;
    u32 m238;
    u32 m23C;
    u8 pad240[0x248 - 0x240];
    s32 m248;
    u8 pad24C[0x273 - 0x24C];
    u8 m273;
};

extern u8 lbl_8053A1D0[4];
extern u8 lbl_8053A1D4[4];
extern u8 lbl_8053A1D8[2];
extern u8 lbl_8053A1DC[4];
extern u8 lbl_8053A1E0[4];
extern u8 lbl_8053A1E4[4];
extern u8 lbl_8053A1E8[4];
extern u8 lbl_8053A1EC[4];
extern u8 lbl_8053A1F0[4];
extern u8 lbl_8053A1F4[2];
extern u8 lbl_8053A1F8[4];
extern u8 lbl_8053A1FC[4];
extern u8 lbl_8053A200[4];
extern u8 lbl_8053A204[2][4];
extern u8 lbl_8053A20C[2];

extern "C" void fn_8037B374(JijiWork* w, const JGeometry::TVec3<f32>* pos, s32 n) {
    w->pos = *pos;
    w->m248 = n / 3;
    w->m273 = 1;
}

extern "C" void fn_8037B3A8(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m238 = w->m238 + 1;
        w->m238 = w->m238 & 1;
        w->m234 = lbl_8053A20C[w->m238];
    }
}

extern "C" void fn_8037B3E0(JijiWork* w) {
    if (w->m248 < 3) {
        if (w->m234 == 10) {
            w->m238 = 1;
        } else if (w->m234 <= 0) {
            w->m234 = (s32)(50.0f * lbl_8053AAF8->rnd.get_ufloat_1()) + 40;
            w->m238 = 0;
        }
    } else {
        w->m234 = 0;
        w->m238 = 0;
    }
}

extern "C" void fn_8037B488(JijiWork* w) {
    if (w->m234 == 25) {
        w->m238 = 1;
    } else if (w->m234 == 10) {
        w->m238 = 2;
    } else if (w->m234 <= 0) {
        w->m234 = 30;
        w->m238 = 0;
    }
}

extern "C" void fn_8037B4D0(JijiWork* w) {
    if (w->m234 == 35) {
        w->m238 = 1;
    } else if (w->m234 == 20) {
        w->m238 = 2;
    } else if (w->m234 == 18) {
        w->m238 = 0;
    } else if (w->m234 == 17) {
        w->m238 = 1;
    } else if (w->m234 == 2) {
        w->m238 = 2;
    } else if (w->m234 <= 0) {
        w->m238 = 0;
        w->m234 = 55;
    }
}

#define JIJI_CYCLE4(name, a, b)                  \
    extern "C" void name(JijiWork* w) {          \
        if (w->m234 <= 0) {                      \
            w->m23C = w->m23C + 1;               \
            w->m23C = w->m23C & 3;               \
            w->m234 = a[w->m23C];                \
            w->m238 = b[w->m23C];                \
        }                                        \
    }
#define JIJI_CYCLE2(name, a)                     \
    extern "C" void name(JijiWork* w) {          \
        if (w->m234 <= 0) {                      \
            w->m238 = w->m238 + 1;               \
            w->m238 = w->m238 & 1;               \
            w->m234 = a[w->m238];                \
        }                                        \
    }

extern "C" void fn_8037B554(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m23C = w->m23C + 1;
        w->m23C = w->m23C & 3;
        w->m234 = lbl_8053A200[w->m23C];
        w->m238 = lbl_8053A204[w->m248 / 2][w->m23C];
    }
}

JIJI_CYCLE4(fn_8037B5B4, lbl_8053A1F8, lbl_8053A1FC)
JIJI_CYCLE2(fn_8037B5FC, lbl_8053A1F4)
JIJI_CYCLE4(fn_8037B634, lbl_8053A1EC, lbl_8053A1F0)
JIJI_CYCLE4(fn_8037B67C, lbl_8053A1E4, lbl_8053A1E8)
JIJI_CYCLE4(fn_8037B6C4, lbl_8053A1DC, lbl_8053A1E0)
JIJI_CYCLE2(fn_8037B70C, lbl_8053A1D8)
JIJI_CYCLE4(fn_8037B744, lbl_8053A1D0, lbl_8053A1D4)

extern "C" void fn_8037B78C(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m234 = w->m23C;
        w->m238 = w->m238 + 1;
        w->m238 = w->m238 & 7;
    }
}

extern "C" void fn_8037B7BC(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m234 = w->m23C;
        w->m238 = w->m238 + 1;
        w->m238 = w->m238 & 1;
    }
}

extern "C" void fn_8037B7EC(JijiWork* w) {
    w->m238 = 0;
}

#include "Game/AnimEffectRec.h"
extern "C" void fn_801EE434(void* h);
extern "C" void __dt__13AnimEffectRecFv(void* p, int flag);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_8037CD78(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AEED0;
        if (*(AnimEffectRec**)((char*)this_ + 0x274) != 0) {
            __dt__13AnimEffectRecFv(*(AnimEffectRec**)((char*)this_ + 0x274), 1);
        }
        if (*(void**)((char*)this_ + 0x278) != 0) {
            fn_801EE434(*(void**)((char*)this_ + 0x278));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "Game/ItemBase.h"
struct JijiTable {
    u8 pad0[0xd8];
    s32 frames[11][4];
    char res0[0x14];
    char res1[0x14];
    char res2[0x18];
};
extern const JijiTable lbl_804753C0;
static inline s32 jijiFrame(const s32 (*fr)[4], u8* p) { return fr[*(s32*)(p + 0x264)][*(s32*)(p + 0x248)]; }
#define JIJI_FRAME(t, p) (*(s32*)((p) + 0x238) + ((const s32(*)[4])((const u8*)(t) + 0xd8))[*(s32*)((p) + 0x264)][*(s32*)((p) + 0x248)])
extern "C" void fn_801F06F0(void* actor, const char* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F0E34(void* actor, u32 msg, s32 arg);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80307AC8(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c);

extern "C" void fn_8037B7F8(u8* this_) {
    const JijiTable* t = &lbl_804753C0;
    if (*(s32*)(this_ + 0x230) == 5 && *(AnimEffectRec**)(this_ + 0x274) != 0) {
        u32 snd = fn_80316E74(*(AnimEffectRec**)(this_ + 0x274), *(s32*)(this_ + 0x244));
        if (snd != 0xffffffff) {
            fn_801F0E34(this_, snd, 0);
        }
    }
    if (*(s32*)(this_ + 0x230) == 4) {
        return;
    }
    if (*(s32*)(this_ + 0x258) == 0x15) {
        return;
    }
    if (*(s32*)(this_ + 0x258) == 0x11 && *(s32*)(this_ + 0x230) == 2) {
        fn_801F06F0(this_, t->res0, 0x2b1, 0, 7, 1.0f, 1.0f);
    } else if (*(s32*)(this_ + 0x258) == 0x12 || *(s32*)(this_ + 0x258) == 0x13 || *(s32*)(this_ + 0x258) == 0x14) {
        DrawRec rec;
        ((u8*)&rec.w10)[3] = *(u8*)(this_ + 0x270);
        fn_801F06F0(this_, t->res0,
                    *(s32*)(this_ + 0x25c) + JIJI_FRAME(t, this_),
                    &rec, 7, 1.0f, 1.0f);
    } else if (*(s32*)(this_ + 0x258) == 0x23 && *(AnimEffectRec**)(this_ + 0x274) != 0 &&
               fn_80316E34(*(AnimEffectRec**)(this_ + 0x274)) >= 0) {
        fn_801F06F0(this_, t->res1, *(s32*)(this_ + 0x25c) + fn_80316E34(*(AnimEffectRec**)(this_ + 0x274)), 0, 7, 1.0f, 1.0f);
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                    *(s32*)(this_ + 0x25c) + fn_80316E34(*(AnimEffectRec**)(this_ + 0x274)), 0, 2, -1, 0, 0, 0);
    } else if (*(s32*)(this_ + 0x260) == 0) {
        fn_801F06F0(this_, t->res0,
                    *(s32*)(this_ + 0x25c) + JIJI_FRAME(t, this_),
                    0, -1, 1.0f, 1.0f);
    } else if (*(s32*)(this_ + 0x260) == 1) {
        fn_801F06F0(this_, t->res2,
                    *(s32*)(this_ + 0x25c) + JIJI_FRAME(t, this_),
                    0, 7, 1.0f, 1.0f);
        fn_80307AC8(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                    *(s32*)(this_ + 0x25c) + JIJI_FRAME(t, this_),
                    0, 0, -1);
    } else {
        fn_801F06F0(this_, t->res1,
                    *(s32*)(this_ + 0x25c) + JIJI_FRAME(t, this_),
                    0, 7, 1.0f, 1.0f);
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                    *(s32*)(this_ + 0x25c) + JIJI_FRAME(t, this_),
                    0, 2, -1, 0, 0, 0);
    }
}

struct JijiAnimEntry { u16 a, b; };
extern "C" void fn_801EE558(void* this_, JGeometry::TVec3<f32>* dir, f32* dist, s32 p);

extern "C" void fn_8037C788(u8* this_) {
    f32 dist;
    JGeometry::TVec3<f32> dir;
    *(s32*)(this_ + 0x230) = 0;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) & 0xfff) + 0x12b;
    *(u32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 24) & 1;
    *(u32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 16) & 0xff;
    *(u8*)(this_ + 0x271) = (*(u32*)(this_ + 0x90) >> 25) & 1;
    *(u32*)(this_ + 0x268) = (*(u32*)(this_ + 0x90) >> 12) & 3;
    *(u8*)(this_ + 0x272) = 1;
    *(s32*)(this_ + 0x26c) = 0;
    *(u8*)(this_ + 0x270) = 0;
    if (*(u8*)(this_ + 0x271) == 1) {
        *(s32*)(this_ + 0x230) = 2;
    }
    if (*(s32*)(this_ + 0x258) > 54) {
        *(s32*)(this_ + 0x258) = 0;
    }
    s32 k = *(s32*)(this_ + 0x258);
    if (k == 6 || k == 11 || k == 16 || k == 25) {
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 16.0f;
        *(f32*)(this_ + 0x6c) = 8.0f;
    } else {
        *(f32*)(this_ + 0x60) = -8.0f;
        *(f32*)(this_ + 0x64) = -8.0f;
        *(f32*)(this_ + 0x68) = 8.0f;
        *(f32*)(this_ + 0x6c) = 8.0f;
    }
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    if (*(u8*)(this_ + 0x271) == 1) {
        *(f32*)(this_ + 0x44) = 4.0f;
    }
    *(s32*)(this_ + 0x108) = 1;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x248) = 2;
    *(s32*)(this_ + 0x24c) = 0;
    if (*(s32*)(this_ + 0x24c) != 0) {
        *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) - 1;
    } else {
        *(s32*)(this_ + 0x24c) = 20;
        fn_801EE558(this_, &dir, &dist, 0);
        if (dist < 100.0f) {
            u16 ang = 10430.378f * JMAAtan2Radian(-dir.x, -dir.y);
            if (ang < 0x2000 || ang >= 0xe000) {
                *(s32*)(this_ + 0x248) = 3;
            } else if (ang >= 0x2000 && ang < 0x6000) {
                *(s32*)(this_ + 0x248) = 1;
            } else if (ang >= 0x6000 && ang <= 0xa000) {
                *(s32*)(this_ + 0x248) = 2;
            } else {
                *(s32*)(this_ + 0x248) = 0;
            }
        } else {
            *(s32*)(this_ + 0x248) = 2;
        }
    }
    *(s32*)(this_ + 0x244) = -1;
    *(u32*)(this_ + 0x25c) = ((const JijiAnimEntry*)&lbl_804753C0)[*(s32*)(this_ + 0x258)].a;
    *(u32*)(this_ + 0x260) = ((const JijiAnimEntry*)&lbl_804753C0)[*(s32*)(this_ + 0x258)].b;
    *(u8*)(this_ + 0x273) = 0;
    switch (*(u32*)(this_ + 0x258)) {
    case 1:
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 2:
        *(s32*)(this_ + 0x23c) = 3;
        *(s32*)(this_ + 0x234) = 3;
        *(s32*)(this_ + 0x264) = 6;
        break;
    case 3:
    case 22:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 4;
        break;
    case 4:
    case 23:
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 5:
    case 24:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 4;
        break;
    case 6:
    case 25:
        *(s32*)(this_ + 0x234) = 12;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 5;
        break;
    case 7:
        *(s32*)(this_ + 0x23c) = 6;
        *(s32*)(this_ + 0x234) = 6;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 8:
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 9:
        *(s32*)(this_ + 0x23c) = 10;
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 10:
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 11:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 7;
        break;
    case 12:
        *(s32*)(this_ + 0x234) = 7;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 13:
        *(s32*)(this_ + 0x234) = 12;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 8;
        break;
    case 14:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 6;
        break;
    case 15:
        *(s32*)(this_ + 0x234) = 7;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 16:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 17:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 1;
        break;
    case 18:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 19:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 20:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 21:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 26:
        *(s32*)(this_ + 0x234) = 55;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 27:
        *(s32*)(this_ + 0x234) = 40;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 28:
        *(s32*)(this_ + 0x234) = 90;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 29:
    case 30:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 31:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 32:
    case 33:
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 34:
        *(s32*)(this_ + 0x264) = 2;
        *(s32*)(this_ + 0x234) = 60;
        *(s32*)(this_ + 0x23c) = 0;
        break;
    case 35:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 9;
        break;
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x264) = 10;
        break;
    case 42:
        *(s32*)(this_ + 0x23c) = 40;
        *(s32*)(this_ + 0x234) = 40;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 43:
        *(s32*)(this_ + 0x23c) = 18;
        *(s32*)(this_ + 0x234) = 18;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 44:
    case 45:
    case 46:
    case 47:
        *(s32*)(this_ + 0x23c) = 16;
        *(s32*)(this_ + 0x234) = 16;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 48:
        *(s32*)(this_ + 0x23c) = 10;
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 49:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 50:
    case 51:
    case 52:
    case 53:
        *(s32*)(this_ + 0x23c) = 16;
        *(s32*)(this_ + 0x234) = 16;
        *(s32*)(this_ + 0x264) = 2;
        break;
    default:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 0;
        break;
    }
    if (*(AnimEffectRec**)(this_ + 0x274) != 0) {
        fn_80316E50(*(AnimEffectRec**)(this_ + 0x274), *(s32*)(this_ + 4), JGeometry::TVec3<f32>(*(JGeometry::TVec3<f32>*)(this_ + 0xc)));
    }
    *(s32*)(this_ + 0x278) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
