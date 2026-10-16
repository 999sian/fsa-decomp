#include "Game/Actor.h"

/* Actor with the 0x18 bytes of members that follow the base (size 0x250). */
struct ActorExt : Actor {
    /* 0x230 */ u32 m230;
    /* 0x234 */ u32 m234;
    /* 0x238 */ u32 m238;
    /* 0x23C */ u32 m23C;
    /* 0x240 */ s32 m240;
    /* 0x244 */ s32 m244;
    /* 0x248 */ u32 m248;
    /* 0x24C */ s32 m24C;
};


extern "C" char lbl_804A8010[];
extern "C" Actor* fn_802A8220(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8010;
        param_1->Actor::~Actor();
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802A8280(void)
{
    return;
}

extern "C" void fn_802A92FC(ActorExt* param_1)
{
    param_1->m248 = 0;
    param_1->m24C = 0;
    param_1->m230 = 0;
    param_1->m23C = 0;
    param_1->m240 = 0;
    param_1->m244 = (u8)param_1->field_90;
    if (param_1->m244 != 3 && param_1->m244 != 0xc && (u8)param_1->v11()) {
        param_1->field_11C = 0;
    }
    param_1->m240 = (param_1->field_90 >> 12) & 0xff;
    if (param_1->m240 == 0) {
        param_1->m240 = 0x100;
    }
    param_1->m234 = 1;
    param_1->m238 = 0;
    if (param_1->m240 == 0x78) {
        param_1->m238 = 2;
    } else if (param_1->m240 < 0x78) {
        if (param_1->m240 == 0x28) {
            param_1->m238 = 1;
        }
    } else if (param_1->m240 == 200) {
        param_1->m238 = 3;
    }
    if (param_1->m244 != 2 && param_1->m244 != 4 && param_1->m244 > 1 && param_1->m244 - 8 > 3 && param_1->m244 == 0xd) {
        param_1->m24C = 0x28;
    }
}

