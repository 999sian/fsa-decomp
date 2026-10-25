// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8018EB94-801902C0 (DGT2). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"

struct JMathSinCos { f32 sin; f32 cos; };
extern "C" JMathSinCos sincosTable___5JMath[];
extern void* lbl_8053AAF8;
extern s32 lbl_8053AB88;

// Copy the actor position (+0xc) into dst.
static inline void dgt2CopyPos(char* dst, char* src) {
    *(f32*)(dst + 0x0) = *(f32*)(src + 0xc);
    *(f32*)(dst + 0x4) = *(f32*)(src + 0x10);
    *(f32*)(dst + 0x8) = *(f32*)(src + 0x14);
}

// Sine table index for an angle of 4000 * m (the table is indexed by bits 5..15).
static inline u32 dgt2Idx(s32 m) {
    return ((u32)(s32)(4000.0f * (f32)m) >> 5) & 0x7ff;
}

static inline f32 dgt2Sin(s32 m) {
    return sincosTable___5JMath[(u16)(s32)(4000.0f * m) >> 5].sin;
}

static inline f32 dgt2Cos(s32 m) {
    return sincosTable___5JMath[(u16)(s32)(4000.0f * m) >> 5].cos;
}

static inline void dgt2SetVel(char* p) {
    *(f32*)(p + 0x27c) = *(f32*)(p + 0x278) * dgt2Sin(*(s32*)(p + 0x98));
    *(f32*)(p + 0x280) = *(f32*)(p + 0x278) * dgt2Cos(*(s32*)(p + 0x98));
}

static inline void dgt2SetPoint(char* dst, char* p, s32 d) {
    dgt2CopyPos(dst, p);
    s32 a = (*(s32*)(p + 0x98) + d) & 0xf;
    *(f32*)(dst + 0x0) += 6.0f * dgt2Sin(a);
    *(f32*)(dst + 0x4) += 6.0f * dgt2Cos(a);
}

// from src/Game/fn_8018FB24_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A1FA0[];
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" void fn_801F06F0(void* a, const char* tbl, s32 idx, DrawRec* rec, s32 p5, f32 f6, f32 f7);
extern f32 lbl_8053E1D8;
extern f32 lbl_8053E1DC;
extern f32 lbl_8053E1E0;
extern char lbl_804674F0[];

struct Dgt2Vec { f32 x; f32 y; f32 z; };

static void dgt2Rot(f32 (*m)[4], f32 th) {
    f32 sA = sin(lbl_8053E1D8);
    f32 sT = sin(th);
    f32 sZ = sin(lbl_8053E1D8);
    f32 cA = cos(lbl_8053E1D8);
    f32 cT = cos(th);
    f32 cZ = cos(lbl_8053E1D8);
    f32 S = lbl_8053E1DC;
    m[0][0] = S * (cT * cZ);
    m[0][1] = S * ((sA * sT) * cZ - cA * sZ);
    m[0][2] = S * ((cA * cZ) * sT + sA * sZ);
    m[1][0] = S * (cT * sZ);
    m[1][1] = S * ((sA * sT) * sZ + cA * cZ);
    m[1][2] = S * ((cA * sZ) * sT - sA * cZ);
    m[2][0] = S * -sT;
    m[2][1] = S * (sA * cT);
    m[2][2] = S * (cA * cT);
}

extern "C" void* fn_8018FB24(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1FA0;
        char* p = (char*)this_;
        for (s32 i = 0; i < 3; i++) {
            fn_801EE434(*(void**)(p + 0x3c0));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8018FBB8(void* this_) {
    char* p = (char*)this_;
    *(f32*)(p + 0x80) = -6.0f;
    *(f32*)(p + 0x84) = -6.0f;
    *(f32*)(p + 0x88) = 6.0f;
    *(f32*)(p + 0x8c) = 6.0f;
    *(f32*)(p + 0x60) = -6.0f;
    *(f32*)(p + 0x64) = -6.0f;
    *(f32*)(p + 0x68) = 6.0f;
    *(f32*)(p + 0x6c) = 6.0f;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;

    dgt2CopyPos(p + 0x288, p);
    dgt2CopyPos(p + 0x294, p);
    dgt2CopyPos(p + 0x2a0, p);
    dgt2CopyPos(p + 0x2ac, p);
    dgt2CopyPos(p + 0x2b8, p);
    dgt2CopyPos(p + 0x2c4, p);

    char* q = p;
    for (s32 i = 0; i < 2; i++) {
        dgt2CopyPos(q + 0x2d0, p);
        dgt2CopyPos(q + 0x2dc, p);
        dgt2CopyPos(q + 0x2e8, p);
        dgt2CopyPos(q + 0x2f4, p);
        dgt2CopyPos(q + 0x300, p);
        dgt2CopyPos(q + 0x30c, p);
        dgt2CopyPos(q + 0x318, p);
        dgt2CopyPos(q + 0x324, p);
        dgt2CopyPos(q + 0x330, p);
        dgt2CopyPos(q + 0x33c, p);
        q += 0x78;
    }

    *(s32*)(p + 0x3c0) = 0;
    *(s32*)(p + 0x3c4) = 0;
    *(s32*)(p + 0x3c8) = 0;

    u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660du + 0x3c6ef35fu;
    u32 bits = (*seed >> 9) | 0x3f800000u;
    *(s32*)(p + 0x98) = (s32)(15.0f * (*(f32*)&bits - 1.0f));
    *(s32*)(p + 0x25c) = *(s32*)(p + 0x98);
    *(s32*)(p + 0x260) = *(s32*)(p + 0x98);
    *(s32*)(p + 0x264) = -1;
    dgt2SetVel(p);
    *(f32*)(p + 0x284) = 0.0f;
    *(s32*)(p + 0x23c) = 8;
    *(f32*)(p + 0x44) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x268) = 0.3f;
    *(f32*)(p + 0x26c) = 1.0f;
    *(f32*)(p + 0x270) = 1.0f;
    *(f32*)(p + 0x274) = 0.0f;
    *(f32*)(p + 0x278) = 1.3f;

    if ((lbl_8053AB88 & 1) == 0) {
        *(s32*)(p + 0x254) = 1;
    } else {
        *(s32*)(p + 0x254) = -1;
    }
    lbl_8053AB88++;
    lbl_8053AB88 &= 1;
    *(s32*)(p + 0xb0) = 0x12202;
    *(s32*)(p + 0x230) = 0;

    dgt2SetVel(p);
    dgt2SetPoint(p + 0x2ac, p, -2);
    dgt2SetPoint(p + 0x2b8, p, 2);
}

struct Dgt2Child { u8 pad[0x24]; s32 dead; u8 pad2[0xf4 - 0x28]; u32 flags; };
struct Dgt2Links { u8 pad[0x3c0]; Dgt2Child* child[3]; };

// Release the three linked child actors.
extern "C" void fn_8018FAB4(Dgt2Links* this_) {
    for (int i = 0; i < 3; i++) {
        Dgt2Child* c = this_->child[i];
        if (c != 0) {
            c->flags |= 1;
            c->dead = 1;
            this_->child[i] = 0;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
