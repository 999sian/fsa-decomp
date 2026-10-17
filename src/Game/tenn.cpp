// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A0710-801A35AC (TENN). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern const char lbl_804684E8[];

// from src/Game/fn_801A0710.cpp
extern "C" void fn_801A0910(void* this_);
extern "C" void fn_801A0754(void* this_);

// TENN (vtable lbl_804A2BF4, ctor fn_80201294) cluster, part 1/9.
// draw() dispatcher - calls 2 sub-pieces (fn_801A0754/fn_801A0910).
extern "C" void fn_801A0710(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x274);
    if (state == 0) {
        goto call0910;
    }
    if (state < 0) {
        goto skip;
    }
    if (state >= 3) {
        goto skip;
    }
    goto call0754;
call0910:
    fn_801A0910(this_);
    goto skip;
call0754:
    fn_801A0754(this_);
skip:
    return;
}

// from src/Game/Tenn_update_801A0B8C.cpp
extern "C" void fn_801A17B8(void* this_);
extern "C" void fn_801A0F90(void* this_);
extern "C" void fn_801A0BE4(void* this_);

// TENN cluster, part 4/9 (88B). update() dispatcher - routes to 3
// private state handlers (fn_801A0BE4/fn_801A0F90/fn_801A17B8, landed
// alongside).
extern "C" void fn_801A0B8C(void* this_) {
    switch (*(s32*)((char*)this_ + 0x274)) {
        case 0: fn_801A17B8(this_); break;
        case 1: fn_801A0F90(this_); break;
        case 2: fn_801A0BE4(this_); break;
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_8022AF2C(void);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_80458508(void* snd, s32 a);
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;

struct Handles_tenn { u8 pad[0x344]; void* h[4]; };
// TENN destructor
extern void* lbl_804A2BF4[];
extern "C" void* fn_801A2F90(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2BF4;
        if (*(s32*)(this_ + 0x274) == 0) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 5 || state == 6) {
                fn_8022AF2C();
                if (*(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            fn_801EE434(((Handles_tenn*)this_)->h[i]);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
