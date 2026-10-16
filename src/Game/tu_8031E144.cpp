#include "Game/Actor.h"


extern "C" char lbl_804AB1F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" Actor* fn_8031ECBC(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB1F0;
        fn_801EE434(*(void**)((char*)p + 0x268));
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
