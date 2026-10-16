#include "Game/Actor.h"

/* Actor with the 0x18 bytes of members that follow the base (size 0x250). */
struct ActorExt : Actor {
    /* 0x230 */ u32 m230;
    /* 0x234 */ u32 m234;
    /* 0x238 */ u32 m238;
    /* 0x23C */ u32 m23C;
    /* 0x240 */ u32 m240;
    /* 0x244 */ u32 m244;
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
