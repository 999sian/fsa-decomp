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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
