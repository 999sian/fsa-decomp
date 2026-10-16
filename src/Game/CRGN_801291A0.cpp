#include "types.h"
#include "Game/Actor.h"

extern "C" char lbl_8049E5B8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_80129200(Actor*);
extern "C" Actor* fn_801291A0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049E5B8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
