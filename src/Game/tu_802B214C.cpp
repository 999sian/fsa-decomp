#include "Game/Actor.h"


extern "C" char lbl_804A8588[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802B214C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8588;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" u8 fn_802B21AC(Actor* param_1, int param_2, f32* param_3)
{
    u8 ret = param_1->Actor::v17(param_2, param_3);
    if (ret == 0) {
        *((u8*)param_1 + 0x27c) = 0;
    }
    return ret;
}
