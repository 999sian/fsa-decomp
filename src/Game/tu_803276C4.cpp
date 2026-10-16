#include "Game/Actor.h"


extern "C" char __vt__4OSIN[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803276C4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4OSIN;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
