// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801AC8EC-801AE9C4 (DDGO). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JParticle/JPAEmitter.h"

// from src/Game/Ddgo_ApplyState_801AE5AC.cpp
// DDGO cluster, part 8/8. Private helper shared by update() state
// handler #2 and setParams. Gated by ->0x238 (a busy/sub-state timer):
// while it's nonzero this is a no-op. Otherwise it dispatches on the
// ->0x290 state field and computes a movement/animation accumulator
// (->0x258) from a per-state speed formula, advancing a step counter
// (->0x24c) and eventually flagging completion via ->0x298. Uses
// fn_801F0E34 (settings-gated event) to fire audio/visual cues at
// specific step counts.
extern "C" void fn_801F0E34(void* this_, int code, int arg2);

struct Ddgo {
    u8 pad0[0x98];
    s32 speed;       // 0x98
    u8 pad1[0x238 - 0x9c];
    s32 subState;    // 0x238
    u8 pad2[0x24c - 0x23c];
    s32 counter;     // 0x24c
    u8 pad3[0x258 - 0x250];
    s32 accum;       // 0x258
    u8 pad4[0x28c - 0x25c];
    s32 base;        // 0x28c
    s32 state;       // 0x290
    u8 pad5[0x298 - 0x294];
    u8 flag;         // 0x298
};

extern "C" void fn_801AE5AC(void* this_) {
    Ddgo* t = (Ddgo*)this_;

    if (t->subState != 0) {
        return;
    }

    switch (t->state) {
    case 0:
        t->subState = 6;
        t->accum = t->base;
        t->accum = t->counter + t->speed * 3 + t->accum;
        t->counter = t->counter + 1;
        if (t->counter > 2) {
            t->counter = 0;
            fn_801F0E34(this_, 0x50029, 0);
        }
        break;

    case 1:
        t->subState = 9;
        t->accum = t->base;
        t->accum = t->counter + t->speed * 3 + t->accum;
        if (t->counter == 0) {
            fn_801F0E34(this_, 0x5002a, 0);
        }
        t->counter = t->counter + 1;
        if (t->counter > 2) {
            t->counter = 2;
            t->flag = 1;
        }
        break;

    case 2:
        t->subState = 9;
        t->accum = t->base;
        t->accum = t->counter + t->speed * 2 + t->accum;
        t->counter = t->counter + 1;
        if (t->counter > 1) {
            t->counter = 1;
            t->flag = 1;
        }
        break;

    case 3:
        t->accum = t->base;
        t->accum = t->accum + t->speed;
        break;

    case 4:
        if (t->counter > 2) {
            t->counter = 3;
            t->flag = 1;
            break;
        }
        t->accum = t->base;
        t->accum = t->accum + t->counter;
        t->subState = 0xa;
        t->counter = t->counter + 1;
        break;

    default:
        break;
    }
}

extern "C" void fn_801AC930(void* this_);

// DDGO update (vtable slot 3)
extern "C" void fn_801AC8EC(char* this_) {
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
    case 2:
        fn_801AC930(this_);
        break;
    case 1:
        break;
    }
}

extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void fn_801EFD34(void* this_, void* res, void* rec, s32 n, f32 a, f32 b, f32 c);
extern const char* lbl_804A3208[];
extern void* lbl_8053AAF8;
extern "C" void fn_801AC930(void* this_) {
    struct {
        u8 idx[16];
        s32 a;
        s32 b;
        f32* p;
        u8 c[11];
        s32 d;
        u8 e[3];
        s32 f;
        s32 g;
        s32 h;
    } blk;
    f32 local_78[12];
    s32 r5;
    void* uVar1;
    s32 i;
    s32 k;

    blk.a = -1;
    blk.b = -1;
    for (i = 0; (u8)i < 16; i += 8) {
        blk.idx[(u8)i] = i;
        blk.idx[(u8)(i + 1)] = i + 1;
        blk.idx[(u8)(i + 2)] = i + 2;
        blk.idx[(u8)(i + 3)] = i + 3;
        blk.idx[(u8)(i + 4)] = i + 4;
        blk.idx[(u8)(i + 5)] = i + 5;
        blk.idx[(u8)(i + 6)] = i + 6;
        blk.idx[(u8)(i + 7)] = i + 7;
    }
    blk.a = -1;
    blk.b = 0;
    blk.p = 0;
    blk.c[0] = 0;
    blk.c[1] = 0;
    blk.c[2] = 0;
    blk.c[3] = 1;
    blk.c[4] = 1;
    blk.c[5] = 0;
    blk.c[6] = 0;
    blk.c[7] = 0;
    blk.c[8] = 0;
    blk.c[9] = 0;
    blk.c[10] = 1;
    blk.d = 3;
    blk.e[0] = 1;
    blk.e[1] = 0;
    blk.e[2] = 0;
    blk.f = -1;
    blk.g = 0;
    blk.h = 2;

    r5 = *(s32*)((char*)this_ + 0x258);
    if ((*(u32*)((char*)this_ + 0x244) & 2) == 0) {
        if ((u32)r5 > 2 && (u32)r5 - 12 > 2 && (u32)r5 - 24 > 1 && r5 == 0x20) {
            local_78[0] = *(f32*)((char*)this_ + 0x274) * -1.0f;
            local_78[1] = 0.0f;
            local_78[2] = 0.0f;
            local_78[3] = 0.0f;
            local_78[4] = 0.0f;
            local_78[5] = *(f32*)((char*)this_ + 0x278);
            local_78[6] = 0.0f;
            local_78[7] = 0.0f;
            local_78[8] = 0.0f;
            local_78[9] = 0.0f;
            local_78[10] = *(f32*)((char*)this_ + 0x278);
            local_78[11] = 0.0f;
            blk.p = local_78;
        }
        if (*(s32*)((char*)this_ + 0x294) == 1) {
            k = r5 + 0x24;
            uVar1 = fn_804032E8(0x54494D47, lbl_804A3208[k]);
        } else {
            void* obj = *(void**)((char*)lbl_8053AAF8 + 0xa4);
            uVar1 = ((void* (*)(void*, u32, const char*))((void**)*(void**)obj)[6])(obj, 0x54494D47, lbl_804A3208[r5]);
        }
        fn_801EFD34(this_, uVar1, &blk, 7, 0.0f, -2.0f, 0.0f);
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* mgr, s32 handle);
extern s32 lbl_8053ABE0;

struct Handles_ddgo { u8 pad[0x29c]; void* h[2]; };
// DDGO destructor
extern void* lbl_804A3334[];
extern "C" void* fn_801ACC14(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3334;
        s32 h;
        for (int i = 0; i < 2; i++) {
            fn_801EE434(((Handles_ddgo*)this_)->h[i]);
        }
        h = *(s32*)(this_ + 0x260);
        if (h >= 0) {
            char* c = fn_801F666C(fn_801F856C(), h);
            if (c != 0) {
                *(s32*)(this_ + 0x260) = -1;
                *(s32*)(c + 0x108) = 0;
            }
        }
        if (*(s32*)(this_ + 0x234) == 2) {
            lbl_8053ABE0--;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8013CC50(u32 id, void* pos, f32 scale, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void fn_8013CB44(void* em, void* pos, s32 a, s32 b, s32 c);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" u8 fn_801F2B20(void* this_, u32 v);
extern "C" u16 fn_8022461C(f32* p, s32 room);
extern "C" u8 fn_8022517C(f32* p, s32 room);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
void JPAGetXYZRotateMtx(s16, s16, s16, f32 (*)[4]);
extern s32 lbl_804689C0[];
extern f32 lbl_804A31C8[][4];
extern f32 lbl_8053E7D0;
extern f32 lbl_8053E7E0;
extern f32 lbl_8053E7E4;
#pragma opt_lifetimes off
#pragma opt_propagation off
extern "C" void fn_801ACCF0(char* t) {
    s32 j;
    s32 i;
    s32 flags;
    f32 stepY;
    f32 stepX;
    f32 scale = 1.0f;
    f32 p[3];
    f32* b;
    s32 one;
    u32 bits;
    s32 zero;
    char* em;

    if (*(s32*)(t + 0x294) == 1) {
        scale = lbl_8053E7E0;
    }
        switch (*(s32*)(t + 0x230)) {
        case 0xc:
            *(void**)(t + 0x29c) = fn_8013CC50(*(u32*)(t + 4), t + 0xc, scale, 0x1ac, 1, 1, 0, 0, 1);
            if (*(void**)(t + 0x29c) == 0) {
                return;
            }
            *(s32*)(t + 0x238) = 8;
            *(s32*)(t + 0x230) = 0xd;
        case 0xd:

        if (*(void**)(t + 0x29c) != 0) {
            flags = 0;
            if (*(s32*)(t + 0x98) == 2) {
                flags = 0x4000;
            }
            fn_8013CB44(*(void**)(t + 0x29c), t + 0xc, 1, 1, 1);
            s16 xrot=(s16)flags;
            const s32* __restrict angles = lbl_804689C0;
            JPAGetXYZRotateMtx(xrot, (s16)angles[*(s32*)(t + 0x98)], -0x8000, (f32(*)[4])(*(char**)(t + 0x29c) + 0x68));
            fn_801F0E34(t, 0x30011, 0);
        }

        if (*(s32*)(t + 0x238) == 0) {
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
            s32 dir = *(s32*)(t+0x98);
            left = ((f32*)lbl_804A31C8)[dir*4];
            b = lbl_804A31C8[dir];
            top = b[1];
            bottom = b[3];
            right = b[2];
            left=scale*left; top=scale*top; bottom=scale*bottom;
            *(f32*)(t+0x60)=left;
            *(f32*)(t+0x64)=top;
            *(f32*)(t+0x68)=scale*right;
            *(f32*)(t+0x6c)=bottom;
            fn_801F2B7C(t, *(s32*)(t + 0x114), -1, 9);
            fn_801F2B20(t, 5);
            *(JGeometry::TVec3f*)p = *(JGeometry::TVec3f*)(t+0xc);

            if (*(s32*)(t + 0x254) == 0) {
                f32 eighth;
                f32 width;
                f32 minx;
                eighth = 0.125f;
                *(s32*)(t + 0x254) = 1;
                width = *(f32*)(t+0x68)-(minx=*(f32*)(t+0x60));
                stepX = width * eighth;
                f32 height=*(f32*)(t+0x6c)-*(f32*)(t+0x64);
                stepY=height*eighth;
                p[0] = *(f32*)(t + 0xc) + minx;
                for (i = 0; i < 8; i++) {
                    p[1] = *(f32*)(t + 0x10) + *(f32*)(t + 0x64);
                    for (j = 0; j < 8; j++) {
                        if ((s32)fn_8022461C(p, *(s32*)(t + 4)) == 0x21 || fn_8022517C(p, *(s32*)(t + 4)) == 1) {
                            Actor_CreateByID(fn_801F856C(), 0x424c5a45, *(u32*)(t + 4), p, 0xE0C0, -1, -1);
                        }
                        p[1] += stepY;
                    }
                    p[0] += stepX;
                }
            }
        }

    if (*(s32*)(t + 0x108) > 0) {
        return;
    }
    one=1;
    zero=0;
    em = *(char**)(t + 0x29c);
    if (em != 0) {
        bits=*(u32*)(em+0xf4);
        *(u32*)(em+0xf4)=bits|1;
        *(s32*)(em + 0x24) = one;
        *(char**)(t + 0x29c) = (char*)zero;
    }
    em = *(char**)(t + 0x2a0);
    if (em != 0) {
        *(s32*)(em + 0xf4) |= 1;
        *(s32*)(em + 0x24) = one;
        *(char**)(t + 0x2a0) = (char*)zero;
    }
    *(u8*)(t + 0x11c) = 0;
    break;
    default: break;
    }
}
#pragma opt_propagation reset
#pragma opt_lifetimes reset
extern "C" void fn_801AE5AC(void* this_);
extern void* lbl_8053AF80;
extern "C" void fn_80458F9C(void* a, u32 b);
extern "C" void fn_801AE32C(void* this_) {
    char* t = (char*)this_;
    u32* seed;
    u32 bits;
    f32 r;

    *(f32*)(t + 0x60) = -8.0f;
    *(f32*)(t + 0x64) = -8.0f;
    *(f32*)(t + 0x68) = 8.0f;
    *(f32*)(t + 0x6c) = 8.0f;
    *(f32*)(t + 0x80) = -8.0f;
    *(f32*)(t + 0x84) = -8.0f;
    *(f32*)(t + 0x88) = 8.0f;
    *(f32*)(t + 0x8c) = 8.0f;
    *(s32*)(t + 0x234) = *(u32*)(t + 0x90) & 0xf;
    *(s32*)(t + 0x294) = (*(u32*)(t + 0x90) >> 4) & 0xf;
    *(s32*)(t + 0x24c) = 0;
    *(s32*)(t + 0x250) = 0;
    *(s32*)(t + 0x254) = 0;
    *(s32*)(t + 0x238) = 0;
    *(s32*)(t + 0x23c) = 0;
    *(s32*)(t + 0x240) = 0;
    *(s32*)(t + 0x244) = 0;
    *(s32*)(t + 0x248) = 0;
    *(s32*)(t + 0x29c) = 0;
    *(s32*)(t + 0x2a0) = 0;
    *(f32*)(t + 0x274) = 1.0f;
    *(f32*)(t + 0x278) = 1.0f;
    *(f32*)(t + 0x27c) = 1.0f;
    *(f32*)(t + 0x280) = 1.0f;
    *(f32*)(t + 0x284) = 1.0f;
    *(f32*)(t + 0x288) = 1.0f;
    *(s32*)(t + 0x264) = -1;
    *(s32*)(t + 0x28c) = 0;
    *(s32*)(t + 0x290) = -1;
    *(s32*)(t + 0x260) = -1;
    *(u8*)(t + 0x298) = 0;

    seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    bits = (*seed >> 9) | 0x3f800000;
    r = *(f32*)&bits;
    *(s32*)(t + 0x98) = (s32)(4.0f * (r - 1.0f));
    *(s32*)(t + 0x98) = *(s32*)(t + 0x98) & 3;

    if (*(s32*)(t + 0x290) != 0) {
        *(s32*)(t + 0x290) = 0;
        *(u8*)(t + 0x298) = 0;
        *(s32*)(t + 0x238) = 0;
        *(s32*)(t + 0x24c) = 0;
        switch (*(s32*)(t + 0x290)) {
        case 0:
            *(s32*)(t + 0x28c) = 0;
            break;
        case 1:
            *(s32*)(t + 0x28c) = 0xc;
            *(s32*)(t + 0x258) = *(s32*)(t + 0x28c);
            break;
        case 2:
            *(s32*)(t + 0x28c) = 0x18;
            break;
        case 3:
            *(s32*)(t + 0x28c) = 0x20;
            break;
        case 4:
            *(s32*)(t + 0x28c) = 0x24;
            break;
        }
    }

    fn_801AE5AC(this_);
    *(f32*)(t + 0x270) = 0.0f;
    *(f32*)(t + 0x26c) = 0.0f;
    *(f32*)(t + 0x268) = 0.0f;
    *(f32*)(t + 0x44) = 0.0f;
    *(f32*)(t + 0x40) = 0.0f;
    *(f32*)(t + 0x3c) = 0.0f;
    *(s32*)(t + 0x108) = 10000;
    *(s32*)(t + 0x25c) = 3;

    if (*(s32*)(t + 0x234) == 0 || *(s32*)(t + 0x234) == 2) {
        *(s32*)(t + 0xb8) = 1;
        *(s32*)(t + 0xb0) = 0xa040004;
    }

    switch (*(s32*)(t + 0x234)) {
    case 0:
        *(s32*)(t + 0x230) = 1;
        break;
    case 1:
        *(s32*)(t + 0x230) = 0xc;
        break;
    case 2:
        if (lbl_8053ABE0 == 0) {
            fn_80458F9C(lbl_8053AF80, 0x3c);
            *(s32*)(t + 0x230) = 0;
            lbl_8053ABE0++;
        } else {
            *(s32*)(t + 0x230) = 1;
        }
        break;
    }
}

#include "JSystem/JMath/JMath.h"
extern void* lbl_8053AB10;
extern f32 lbl_804A3108[];
extern u16 lbl_8053A110[];
extern f32 lbl_8053E7D8, lbl_8053E7E8, lbl_8053E7EC, lbl_8053E7F0, lbl_8053E7F4;
extern f32 lbl_8053E7F8, lbl_8053E7FC, lbl_8053E800, lbl_8053E804, lbl_8053E808, lbl_8053E80C;
extern f32 lbl_8053E810, lbl_8053E814, lbl_8053E818, lbl_8053E81C, lbl_8053E820, lbl_8053E824;
extern "C" void fn_8030C210(void*, void*);
extern "C" void fn_801F71A4(f32*, f32, f32, f32);
extern "C" void fn_801F3D94(void*, s32);
extern "C" void fn_801EF510(void*);
extern "C" u8 fn_801F2618(void*, s32, s32);
extern "C" s32 fn_801F285C(void*, s32, s32, s32, s32);
extern "C" u8 fn_80237948(s32, f32*);
extern "C" void fn_80458FF0(void*, u32, s32, s32);
extern "C" void fn_801EEC98(void*, s32, s32, s32*, s32, s32, s32, s32);
extern "C" s32 fn_801F2718(void*, u32);
extern "C" s32 ClassifyBamAngleToQuadrant(u16);
extern "C" void fn_80134DE4(void*, s32, s32);
static inline void DdgoChangeState(char* t, s32 state) {
    if (*(s32*)(t+0x290) != state) {
        *(s32*)(t+0x290)=state;
        *(u8*)(t+0x298)=0;
        *(s32*)(t+0x238)=0;
        *(s32*)(t+0x24c)=0;
        switch (*(s32*)(t+0x290)) {
        case 0: *(s32*)(t+0x28c)=0; break;
        case 1: *(s32*)(t+0x28c)=12; *(s32*)(t+0x258)=*(s32*)(t+0x28c); break;
        case 2: *(s32*)(t+0x28c)=24; break;
        case 3: *(s32*)(t+0x28c)=32; break;
        case 4: *(s32*)(t+0x28c)=36; break;
        }
    }
}
static inline void DdgoSetVelocity(char* t, f32 a, f32 b) {
    *(f32*)(t+0x44)=*(f32*)(t+0x40)=*(f32*)(t+0x3c)=0.0f;
    switch (*(s32*)(t+0x98)) {
    case 0: *(f32*)(t+0x268)=a; *(f32*)(t+0x26c)=0; *(f32*)(t+0x270)=0; break;
    case 1: *(f32*)(t+0x268)=b; *(f32*)(t+0x26c)=0; *(f32*)(t+0x270)=0; break;
    case 2: *(f32*)(t+0x268)=0; *(f32*)(t+0x26c)=a; *(f32*)(t+0x270)=0; break;
    case 3: *(f32*)(t+0x268)=0; *(f32*)(t+0x26c)=b; *(f32*)(t+0x270)=0; break;
    }
}
static inline void DdgoStop(char* t) {
    *(f32*)(t+0x270)=*(f32*)(t+0x26c)=*(f32*)(t+0x268)=
    *(f32*)(t+0x44)=*(f32*)(t+0x40)=*(f32*)(t+0x3c)=0.0f;
}
static inline s32 DdgoOldDirection(char* t) {
    s32 dir=3;
    s32 frame=*(s32*)(t+0x258);
    if (frame<3) dir=0;
    if (frame>=3 && frame<=5) dir=1;
    if (frame>=6 && frame<=8) dir=2;
    return dir;
}
static inline f32 DdgoRandom() {
    u32* seed=(u32*)((char*)lbl_8053AAF8+0xb4);
    *seed=*seed*0x19660d+0x3c6ef35f;
    u32 bits=(*seed>>9)|0x3f800000;
    return *(f32*)&bits-1.0f;
}
static inline void DdgoBox(char* t, f32* box, f32 scale) {
    f32 l=box[0], top=box[1], b=box[3], r=box[2];
    l=scale*l; top=scale*top; b=scale*b;
    *(f32*)(t+0x60)=l; *(f32*)(t+0x64)=top;
    *(f32*)(t+0x68)=scale*r; *(f32*)(t+0x6c)=b;
}

extern "C" void fn_801ACFF4(void* this_);
extern "C" void fn_801ACCF0(char* this_);
struct DdgoTimers { u8 pad[0x238]; s32 t[5]; };

// DDGO update
extern "C" void fn_801ACB50(char* this_) {
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
    case 2:
        fn_801ACFF4(this_);
        break;
    case 1:
        fn_801ACCF0(this_);
        break;
    }
    for (int i = 0; i < 5; i++) {
        if (((DdgoTimers*)this_)->t[i] > 0) {
            ((DdgoTimers*)this_)->t[i]--;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
