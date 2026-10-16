#include "Game/Actor.h"


extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, char*, u32, s32, s32);
extern "C" char lbl_804AAFB8[];
extern "C" void (Actor::*lbl_804AAED4[])();
extern "C" Actor* fn_80317EB8(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AAFB8;
        param_1->Actor::~Actor();
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_803199AC(u32* param_1)
{
    u32 state;
    u8 cVar1;
    if (param_1[0x90] != 0) {
        cVar1 = ((u8 (*)(Actor*))((void**)*param_1)[13])((Actor*)param_1);
        state = param_1[0x90];
        if ((state == 1 && cVar1 == 1) || (state == 2 && cVar1 == 0)) {
            *(u8*)(param_1 + 0x9c) = 0;
        } else {
            *(u8*)(param_1 + 0x9c) = 1;
        }
    }
    if (*(u8*)(param_1 + 0x9c) == 1) {
        (((Actor*)param_1)->*lbl_804AAED4[param_1[0x8e]])();
    }
}

