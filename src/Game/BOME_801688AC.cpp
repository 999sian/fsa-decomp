#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/Actor.h"
#include <float.h>
#include <math.h>

struct JMathSinCos { f32 sin; f32 cos; };

static inline f32 bomeInvSqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return y;
}
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" u32 lbl_804A0718[];
extern "C" void fn_8016890C(void* this_, void* pos, s32 room, void* out);
extern "C" s32 fn_8023DE58(s32 idx);

extern "C" {
void* fn_8023E724(s32 idx);
u8 fn_8023EA28(s32 idx);
u8 fn_8022E438(s32 idx, s32 other);
u8 fn_80235580(s32 idx);
s32 fn_8023B0F4(s32 idx, void* box, s32 a2, s32 a3, f32 f);
s32 fn_8022CAF8(s32 idx);
s32 fn_8022E23C(s32 idx, void* p);
void fn_8022CC20(s32 idx);
u8 fn_8022F514(s32 idx);
void fn_8023DFF4(s32 idx);
}

struct SwbmDrawParam {
    SwbmDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};

struct SwbmResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, const char* name);
};

extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char lbl_80466350[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, SwbmDrawParam* prm);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" char __vt__4BOME[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_801688AC(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4BOME;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" s32 fn_80168C38(char* this_) {
    f32 rel[2];
    Vec d;
    f32 box[4];
    Vec* ptr;
    f32 px;
    f32 py;
    s32 found = -1;
    s32 i;

    ptr = (Vec*)fn_8023E724(*(s32*)(this_ + 0x90));
    rel[0] = ptr->x;
    rel[1] = ptr->y;
    px = *(f32*)(this_ + 0xc);
    py = *(f32*)(this_ + 0x10);
    rel[0] = rel[0] - px;
    rel[1] = rel[1] - py;
    box[0] = *(f32*)(this_ + 0x60);
    box[1] = *(f32*)(this_ + 0x64);
    box[2] = *(f32*)(this_ + 0x68);
    box[3] = *(f32*)(this_ + 0x6c);
    box[0] = box[0] + px;
    box[1] = box[1] + py;
    box[2] = box[2] + px;
    box[3] = box[3] + py;
    box[0] = box[0] - 4.0f;
    box[1] = box[1] - 4.0f;
    box[2] = box[2] + 4.0f;
    box[3] = box[3] + 4.0f;
    for (i = 0; i < 4; i++) {
        if (fn_8023EA28(i) != 1) {
            if (fn_8022E438(i, *(s32*)(this_ + 0x90)) == 0) {
                goto hit;
            }
            if (fn_8022E438(i, *(s32*)(this_ + 0x90)) == 1 && i != *(s32*)(this_ + 0x90) &&
                fn_80235580(i) == 1) {
                goto hit;
            }
        }
        continue;
    hit:
        if (fn_8023B0F4(i, box, *(s32*)(this_ + 4), 0, 0.0f)) {
            found = i;
        }
    }
    if (found < 0) {
        return 0;
    }
    if (fn_8022CAF8(found) == 4) {
        *(u8*)(this_ + 0x261) = 1;
        return fn_8022E23C(found, *(void**)(this_ + 0x198));
    }
    for (i = 0; i < 4; i++) {
        if (fn_8022E438(i, found) == 1) {
            *(u8*)(this_ + 0x261) = 1;
            fn_8022E23C(i, *(void**)(this_ + 0x198));
            fn_8022CC20(i);
            if (fn_8022F514(i) == 1) {
                d = *(Vec*)(this_ + 0xc);
                ptr = (Vec*)fn_8023E724(i);
                d.x = d.x - ptr->x;
                d.y = d.y - ptr->y;
                d.z = d.z - ptr->z;
                fn_8023DFF4(i);
            }
        }
    }
    return 1;
}

extern "C" void fn_80168E78(char* this_) {
    SwbmDrawParam prm;
    prm.reset();
    prm.m60 = 0x11;
    s32 id = *(s32*)(this_ + 0x250) + 0x69;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(SwbmResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80466350);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, 1.0f, 1.0f, &prm);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x250) + 0x69, 0, 2,
                -1, 0, 0, 0);
}

extern "C" void fn_80169DCC(char* this_) {
    char* p;
    s32 i;
    f32 x;
    f32 y;
    f32 lenSq;

    *(s32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 7;
    *(s32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 8) & 1;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 3;
    *(f32*)(this_ + 0x80) = -4.0f;
    *(f32*)(this_ + 0x84) = -4.0f;
    *(f32*)(this_ + 0x88) = 4.0f;
    *(f32*)(this_ + 0x8c) = 4.0f;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0x10);
    *(s32*)(this_ + 0x284) = *(s32*)(this_ + 0x4);
    *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x290) = *(f32*)(this_ + 0x10);
    *(s32*)(this_ + 0x29c) = *(s32*)(this_ + 0x4);
    *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2a8) = *(f32*)(this_ + 0x10);
    *(s32*)(this_ + 0x2b4) = *(s32*)(this_ + 0x4);
    *(f32*)(this_ + 0x2bc) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2c0) = *(f32*)(this_ + 0x10);
    *(s32*)(this_ + 0x2cc) = *(s32*)(this_ + 0x4);
    *(f32*)(this_ + 0x2d4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2d8) = *(f32*)(this_ + 0x10);
    *(s32*)(this_ + 0x2e4) = *(s32*)(this_ + 0x4);
    p = this_;
    for (i = 0; i < 5; i++) {
        f32* v = (f32*)fn_8023E724(*(s32*)(this_ + 0x90));
        *(f32*)(p + 0x2f4) = v[0];
        *(f32*)(p + 0x2f8) = v[1];
        *(s32*)(p + 0x300) = fn_8023DE58(*(s32*)(this_ + 0x90));
        p += 0x18;
    }
    *(s32*)(this_ + 0x264) = 0;
    *(s32*)(this_ + 0x268) = 0;
    *(s32*)(this_ + 0x26c) = 0;
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x36c) = 0.0f;
    *(f32*)(this_ + 0x368) = 0.0f;
    *(f32*)(this_ + 0x364) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    fn_8016890C(this_, this_ + 0xc, *(s32*)(this_ + 4), this_ + 0x370);
    y = 1000.0f * sincosTable___5JMath[(u16)lbl_804A0718[*(s32*)(this_ + 0x98)] >> 5].cos;
    x = 1000.0f * sincosTable___5JMath[(u16)lbl_804A0718[*(s32*)(this_ + 0x98)] >> 5].sin;
    lenSq = x * x + y * y;
    if (lenSq > 32.0f * FLT_EPSILON) {
        if (lenSq > 0.0f) {
            f32 r = __frsqrte(lenSq);
            lenSq = 0.5f * r * (3.0f - (lenSq * (r * r)));
        }
        x *= lenSq;
        y *= lenSq;
    }
    if (*(s32*)(this_ + 0x25c) != 0) {
        *(f32*)(this_ + 0x3c) = 9.0f * x;
        *(f32*)(this_ + 0x40) = 9.0f * y;
    } else {
        *(f32*)(this_ + 0x3c) = 6.0f * x;
        *(f32*)(this_ + 0x40) = 6.0f * y;
    }
    *(s16*)(this_ + 0x94) = 0;
    *(s32*)(this_ + 0x23c) = 4;
    if (*(s32*)(this_ + 0x98) > 3) {
        *(f32*)(this_ + 0x3c) = *(f32*)(this_ + 0x3c) * 1.2f;
        *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x40) * 1.2f;
    }
    *(s32*)(this_ + 0x254) = 0;
    *(u8*)(this_ + 0x260) = 0;
    *(u8*)(this_ + 0x261) = 0;
    *(s32*)(this_ + 0x258) = 300;
    *(s32*)(this_ + 0x180) = 60;
    *(f32*)(this_ + 0x184) = 80.0f;
    *(s32*)(this_ + 0x230) = 0;
}

