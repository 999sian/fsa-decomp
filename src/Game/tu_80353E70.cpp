#include "Game/Actor.h"


extern "C" char __vt__4TUGF[];
extern "C" void dtor_801EB8CC(void*, s32);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80353E70(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = __vt__4TUGF;
        dtor_801EB8CC((char*)param_1 + 0x230, -1);
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}
