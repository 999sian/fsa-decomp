// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801AE9C4-801AFB38 (OKAM). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801AE9C4_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3448[];

extern "C" void* fn_801AE9C4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3448;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// OKAM: change animation state
extern "C" void fn_801AF7D0(char* this_, s32 state) {
    s32 cur = *(s32*)(this_ + 0x258);
    if (cur == state) {
        return;
    }
    if ((cur == 2 && state == 1) || (cur == 6 && state == 5)) {
        return;
    }
    *(s32*)(this_ + 0x258) = state;
    *(u8*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x240) = 0;
    switch (*(s32*)(this_ + 0x258)) {
    case 0:
        *(s32*)(this_ + 0x254) = 0;
        break;
    case 1:
        *(s32*)(this_ + 0x254) = 4;
        if (*(f32*)(this_ + 0x260) > 0.0f) {
            *(f32*)(this_ + 0x278) = 16.0f;
        } else {
            *(f32*)(this_ + 0x278) = -16.0f;
        }
        break;
    case 2:
        *(f32*)(this_ + 0x280) = 0.0f;
        *(f32*)(this_ + 0x27c) = 0.0f;
        *(f32*)(this_ + 0x278) = 0.0f;
        *(s32*)(this_ + 0x254) = 0x18;
        break;
    case 3:
        *(s32*)(this_ + 0x254) = 8;
        break;
    case 4:
        *(s32*)(this_ + 0x254) = 0xc;
        break;
    case 5:
        *(s32*)(this_ + 0x254) = 0x10;
        if (*(f32*)(this_ + 0x264) > 0.0f) {
            *(f32*)(this_ + 0x27c) = 16.0f;
        } else {
            *(f32*)(this_ + 0x27c) = -16.0f;
        }
        break;
    case 6:
        *(f32*)(this_ + 0x280) = 0.0f;
        *(f32*)(this_ + 0x27c) = 0.0f;
        *(f32*)(this_ + 0x278) = 0.0f;
        *(s32*)(this_ + 0x254) = 0x1b;
        break;
    case 7:
        *(s32*)(this_ + 0x254) = 0x14;
        break;
    }
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x254);
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) + *(s32*)(this_ + 0x240);
}

// OKAM: advance animation frame
extern "C" void fn_801AF678(char* this_) {
    if (*(s32*)(this_ + 0x234) != 0) {
        return;
    }
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x254);
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) + *(s32*)(this_ + 0x240);
    *(s32*)(this_ + 0x234) = 5;
    switch (*(s32*)(this_ + 0x258)) {
    case 0:
    case 2:
    case 4:
    case 6:
        (*(s32*)(this_ + 0x240))++;
        *(s32*)(this_ + 0x240) &= 3;
        break;
    case 1:
        (*(s32*)(this_ + 0x240))++;
        *(s32*)(this_ + 0x240) &= 3;
        if (*(s32*)(this_ + 0x240) == 0) {
            fn_801AF7D0(this_, 2);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    case 3:
        (*(s32*)(this_ + 0x240))++;
        if (*(s32*)(this_ + 0x240) > 2) {
            fn_801AF7D0(this_, 0);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    case 5:
        (*(s32*)(this_ + 0x240))++;
        *(s32*)(this_ + 0x240) &= 3;
        if (*(s32*)(this_ + 0x240) == 0) {
            fn_801AF7D0(this_, 6);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    case 7:
        (*(s32*)(this_ + 0x240))++;
        if (*(s32*)(this_ + 0x240) > 2) {
            fn_801AF7D0(this_, 4);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    }
}

extern void* lbl_8053AAF8;
extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F9484(void* mgr, u32 id, u32 arg, void* pos, u32 arg2, s32 a, s32 b);
extern u32 lbl_804A33B8[];
extern u32 lbl_804A33C4[];

// OKAM init (vtable slot 1). In multiplayer with a variant > 2 it spawns a
// replacement actor (OKTA / PEAC / STAL table) instead.
extern "C" void fn_801AF05C(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    if (fn_80138A30(lbl_8053AAF8) <= 1 && (s32)((*(u32*)(this_ + 0x90) >> 8) & 0xf) > 2) {
        s32 i = 0;
        u32 arg = lbl_804A33C4[i];
        u32 id = lbl_804A33B8[i];
        if (fn_801F9484(fn_801F856C(), id, *(u32*)(this_ + 4), this_ + 0xc, arg, -1, -1) >= 0) {
            *(u8*)(this_ + 0x11c) = 0;
        }
        return;
    }
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x280) = 0.0f;
    *(f32*)(this_ + 0x27c) = 0.0f;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = -1;
    *(u8*)(this_ + 0x25c) = 0;
    *(u32*)(this_ + 0x250) = *(u32*)(this_ + 0x90) & 1;
    if (*(s32*)(this_ + 0x250) == 0) {
        *(s32*)(this_ + 0x98) = 0;
        fn_801AF7D0(this_, 0);
    } else {
        *(s32*)(this_ + 0x98) = 2;
        fn_801AF7D0(this_, 4);
    }
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0xa042004;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
