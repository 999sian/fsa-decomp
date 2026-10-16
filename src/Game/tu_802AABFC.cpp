#include "Game/Actor.h"


extern "C" char lbl_804A8170[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802AABFC(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8170;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802AAC5C(void)
{
    return;
}
