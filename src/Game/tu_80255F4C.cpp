#include "Game/Actor.h"


extern "C" char lbl_804A6F6C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80255F4C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A6F6C;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
