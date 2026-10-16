#include "Game/Actor.h"


extern "C" char lbl_804ACC68[];
extern u8* lbl_8053AAF8;
extern f32 lbl_80542720;
extern f32 lbl_80542724;
extern f32 lbl_80542728;
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803536C4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804ACC68;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_80353B98(u8* p) {
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x234) = 9;
    *(s32*)(p + 0x238) = 300;
    *(u32*)(p + 0x248) = *(u32*)(p + 0x90) & 3;
    *(s32*)(p + 0x240) = 0x3c;
    *(s32*)(p + 0x244) = 0;
    *(u32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(bool*)(p + 0x250) = ((*(u32*)(p + 0x90) >> 8) & 3) != 0;
    if (*(bool*)(p + 0x250) == 0) {
        fn_801F0E34(p, 0x50050, 0);
    } else {
        fn_801F0E34(p, 0x50055, 0);
    }
    *(s32*)(p + 0x230) = 0;
}

