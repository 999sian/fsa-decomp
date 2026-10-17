// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801AC8EC-801AE9C4 (DDGO). Remaining functions are not yet decompiled.
#include "types.h"

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
    u8 i;

    blk.a = -1;
    blk.b = -1;
    for (i = 0; i < 16; i += 8) {
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
        if (r5 > 2 && r5 - 12 > 2 && r5 - 24 > 1 && r5 == 0x20) {
            local_78[0] = -1.0f * *(f32*)((char*)this_ + 0x274);
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
            blk.b = r5;
        }
        if (*(s32*)((char*)this_ + 0x294) == 1) {
            uVar1 = fn_804032E8(0x54494D47, lbl_804A3208[r5 + 0x24]);
        } else {
            uVar1 = ((void* (*)(void*, u32, const char*))((void**)*(void**)lbl_8053AAF8)[6])(
                *(void**)((char*)lbl_8053AAF8 + 0xa4), 0x54494D47, lbl_804A3208[r5]);
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

extern "C" void fn_801ACFF4(void* this_);
extern "C" void fn_801ACCF0(void* this_);
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
