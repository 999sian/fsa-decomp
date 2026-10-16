#include "Game/Actor.h"


extern "C" char __vt__4YNSW[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8034DFF0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4YNSW;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
