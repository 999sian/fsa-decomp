#include "Game/Actor.h"


extern "C" char lbl_804AC810[];
extern "C" u32 fn_801F856C(void);
extern "C" int fn_801F666C(u32 a, u32 b);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_80349B14(void)
{
}

extern "C" void fn_8034A380(Actor* param_1)
{
    *(u32*)((u8*)param_1 + 0x230) = 0;
    *(u32*)((u8*)param_1 + 0x234) = 0;
    *(s32*)((u8*)param_1 + 0x238) = -1;
    *(s32*)((u8*)param_1 + 0x23c) = -1;
    *(u32*)((u8*)param_1 + 0x278) = param_1->field_90 & 0xF;
    *(u16*)((u8*)param_1 + 0x280) = 0;
    *(u8*)((u8*)param_1 + 0x282) = 0;
    *(s32*)((u8*)param_1 + 0x240) = -1;
    *(s32*)((u8*)param_1 + 0x244) = -1;
    *(s32*)((u8*)param_1 + 0x248) = -1;
    *(s32*)((u8*)param_1 + 0x24c) = -1;
    *(s32*)((u8*)param_1 + 0x250) = -1;
    *(s32*)((u8*)param_1 + 0x254) = -1;
    *(s32*)((u8*)param_1 + 0x258) = -1;
    *(s32*)((u8*)param_1 + 0x25c) = -1;
    *(s32*)((u8*)param_1 + 0x260) = -1;
    *(s32*)((u8*)param_1 + 0x264) = -1;
    *(s32*)((u8*)param_1 + 0x268) = -1;
    *(s32*)((u8*)param_1 + 0x26c) = -1;
    *(s32*)((u8*)param_1 + 0x270) = -1;
    *(s32*)((u8*)param_1 + 0x274) = -1;
}

extern "C" Actor* fn_8034A3E8(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        u32* slot = (u32*)param_1;
        s32 i = 0;
        *(void**)param_1 = lbl_804AC810;
        do {
            u32 r = fn_801F856C();
            u32 h = fn_801F666C(r, slot[0x90]);
            if (h != 0) {
                ((Actor*)h)->detach();
            }
            i++;
            slot++;
        } while (i < 0xe);
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

