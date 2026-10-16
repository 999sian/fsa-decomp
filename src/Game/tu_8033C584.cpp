#include "Game/Actor.h"


extern "C" char lbl_804AC250[];
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8033CA4C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AC250;
        fn_801EE434(*(void**)((u8*)param_1 + 0x254));
        fn_801EE434(*(void**)((u8*)param_1 + 0x258));
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}
