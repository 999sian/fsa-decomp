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
