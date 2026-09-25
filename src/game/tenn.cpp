// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A0710-801A35AC (TENN). Remaining functions are not yet decompiled.
#include "types.h"

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

