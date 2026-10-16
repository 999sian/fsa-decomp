#include "Game/Actor.h"


extern "C" char lbl_804ACBF0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8035280C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804ACBF0;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8035286C(void)
{
    return;
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8018330C(u32* out);
extern "C" void fn_8035335C(char* p) {
    char* mgr;
    u32 buf;
    u32 b;
    u32 a;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x238) = 0;
    mgr = (char*)fn_802D6A9C();
    a = *(u32*)(mgr + 0xcc);
    b = *(u32*)(mgr + 0xd0);
    *(u32*)(p + 0x26c) = a;
    *(u32*)(p + 0x270) = b;
    a = *(u32*)(mgr + 0xd4);
    b = *(u32*)(mgr + 0xd8);
    *(u32*)(p + 0x274) = a;
    *(u32*)(p + 0x278) = b;
    *(u32*)(p + 0x230) = 0;
    fn_8018330C(&buf);
    *(u32*)(p + 0x23c) = buf;
    *(u32*)(p + 0x240) = *(u32*)(p + 0x23c);
    *(f32*)(p + 0x244) = (f32)(*(u32*)(p + 0x23c) >> 24);
    *(f32*)(p + 0x248) = (f32)((*(u32*)(p + 0x23c) >> 16) & 0xff);
    *(f32*)(p + 0x24c) = (f32)((*(u32*)(p + 0x23c) >> 8) & 0xff);
    *(f32*)(p + 0x250) = (f32)(*(u32*)(p + 0x23c) & 0xff);
    *(f32*)(p + 0x254) = -(0.4f * *(f32*)(p + 0x244)) / 30.0f;
    *(f32*)(p + 0x258) = -(0.4f * *(f32*)(p + 0x248)) / 30.0f;
    *(f32*)(p + 0x25c) = -(0.4f * *(f32*)(p + 0x24c)) / 30.0f;
    *(f32*)(p + 0x264) = 0.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x260) = 0.0f;
}

