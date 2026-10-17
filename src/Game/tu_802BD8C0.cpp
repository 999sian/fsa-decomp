#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804A8AC8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802BD8C0(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8AC8;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802BD920(void)
{
    return;
}

extern f64 lbl_80540BF8;
extern f32 lbl_80540BE8;
extern "C" void fn_802BDCC0(void);
extern "C" void fn_802BE008(u8* param_1)
{
    s32 t;
    s32 a;
    s32 b;
    f32 scale;

    *(s32*)(param_1 + 0x230) = 0;
    *(u32*)(param_1 + 0x234) = *(u32*)(param_1 + 0x90) & 0x1f;
    *(u32*)(param_1 + 0x238) = (*(u32*)(param_1 + 0x90) >> 7) & 0x1f;
    *(u32*)(param_1 + 0x258) = ((*(u32*)(param_1 + 0x90) >> 22) & 0x1f) + 1;
    *(u32*)(param_1 + 0x25c) = ((*(u32*)(param_1 + 0x90) >> 17) & 0x1f) + 1;
    *(u32*)(param_1 + 0x254) = (*(u32*)(param_1 + 0x90) >> 12) & 0x1f;
    *(u8*)(param_1 + 0x250) = 0;

    t = *(s32*)(param_1 + 0x234);
    if (t < 6) {
        if (t >= 4) {
            goto call;
        }
        if (t < 2) {
            return;
        }
    } else {
        if (t >= 10) {
            return;
        }
        if (t >= 8) {
            goto call;
        }
    }

    scale = lbl_80540BE8;
    a = *(s32*)(param_1 + 0x258);
    b = *(s32*)(param_1 + 0x25c);
    *(f32*)(param_1 + 0x23c) = scale * (f32)(-a);
    *(f32*)(param_1 + 0x240) = scale * (f32)(-b);
    *(f32*)(param_1 + 0x244) = scale * (f32)a;
    *(f32*)(param_1 + 0x248) = scale * (f32)b;
    *(f32*)(param_1 + 0x23c) = *(f32*)(param_1 + 0x23c) + *(f32*)(param_1 + 0xc);
    *(f32*)(param_1 + 0x240) = *(f32*)(param_1 + 0x240) + *(f32*)(param_1 + 0x10);
    *(f32*)(param_1 + 0x244) = *(f32*)(param_1 + 0x244) + *(f32*)(param_1 + 0xc);
    *(f32*)(param_1 + 0x248) = *(f32*)(param_1 + 0x248) + *(f32*)(param_1 + 0x10);
    return;

call:
    fn_802BDCC0();
}

