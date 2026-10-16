#include "Game/Actor.h"


extern "C" char lbl_804AB5D8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80328D6C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AB5D8;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}
