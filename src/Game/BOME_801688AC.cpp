#include "types.h"
#include "Game/Actor.h"

extern "C" char __vt__4BOME[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_801688AC(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4BOME;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
