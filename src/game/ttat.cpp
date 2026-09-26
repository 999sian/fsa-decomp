// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A908C-801AAC8C (TTAT). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801A908C.cpp
extern "C" void fn_801A90D4(void* this_);
extern "C" void fn_801A9374(void* this_);

// TTAT (vtable lbl_804A2FB0, ctor fn_80200D10, GOMA's direct neighbor -
// see project_fsa_goma_actor_progress.md) cluster, part 1/9. draw()
// dispatcher - calls 2 sub-pieces (fn_801A90D4/fn_801A9374).
extern "C" void fn_801A908C(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x258);
    if (state == 5) {
        goto piece0;
    }
    if (state >= 5) {
        goto skip;
    }
    if (state == 0) {
        goto piece0;
    }
    if (state >= 0) {
        goto piece1;
    }
    goto skip;
piece0:
    fn_801A90D4(this_);
    goto skip;
piece1:
    fn_801A9374(this_);
skip:
    return;
}

// from src/Game/TtatStateHelper_801AA8F4.cpp
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);

// TTAT cluster, part 9/9. Private helper called from state handler #2
// (fn_801A9CF4) - uses fn_801F0E34 (settings-gated event).
extern "C" void fn_801AA8F4(void* this_) {
    char* t = (char*)this_;
    if (*(s32*)(t + 0x234) != 0) {
        return;
    }

    *(s32*)(t + 0x24c) = *(s32*)(t + 0x25c) + *(s32*)(t + 0x240);

    switch (*(s32*)(t + 0x260)) {
    case 0:
        *(s32*)(t + 0x234) = 6;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) + 1;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) & 1;
        if (*(s32*)(t + 0x240) != 0) {
            fn_801F0E34(this_, 0x5002c, 0);
        }
        break;
    case 1:
        *(s32*)(t + 0x234) = 5;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) + 1;
        if (*(s32*)(t + 0x240) > 3) {
            *(s32*)(t + 0x240) = 3;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    case 2:
        *(s32*)(t + 0x234) = 5;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) - 1;
        if (*(s32*)(t + 0x240) < 0) {
            *(s32*)(t + 0x240) = 0;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    case 3:
        *(s32*)(t + 0x234) = 6;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) + 1;
        if (*(s32*)(t + 0x240) > 3) {
            *(s32*)(t + 0x240) = 3;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    case 4:
        *(s32*)(t + 0x234) = 6;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) - 1;
        if (*(s32*)(t + 0x240) < 0) {
            *(s32*)(t + 0x240) = 0;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    default:
        break;
    }
}

extern "C" void fn_801A96B4(void* this_);
extern "C" void fn_801A9CF4(void* this_);
struct TtatTimers { u8 pad[0x234]; s32 t[3]; };

// TTAT update (vtable slot 3)
extern "C" void fn_801A961C(char* this_) {
    switch (*(s32*)(this_ + 0x258)) {
    case 0:
    case 5:
        fn_801A96B4(this_);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        fn_801A9CF4(this_);
        break;
    }
    for (int i = 0; i < 3; i++) {
        if (((TtatTimers*)this_)->t[i] > 0) {
            ((TtatTimers*)this_)->t[i]--;
        }
    }
}

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_80138B7C(void* game);
extern void* lbl_804A2FB0[];
extern char* lbl_8053AAF8;
extern s32 lbl_8053ABD0;

// TTAT destructor
extern "C" void* fn_801AA464(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2FB0;
        fn_801EE434(*(void**)(this_ + 0x2b8));
        if (*(s32*)(this_ + 0x258) == 0 && *(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
            fn_80138B7C(lbl_8053AAF8);
        }
        if (*(s32*)(this_ + 0x258) == 5) {
            lbl_8053ABD0--;
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
