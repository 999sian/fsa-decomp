#include "Game/Actor.h"


extern "C" char lbl_804AC6B0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80346E24(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC6B0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
