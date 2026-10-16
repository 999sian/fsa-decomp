#include "Game/Actor.h"


extern "C" char __vt__4MRTA[];
extern "C" void fn_801EE434(...);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80356514(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = __vt__4MRTA;
        if (*(void**)((char*)p + 0x2e0) != 0) {
            fn_801EE434();
        }
        __dt__5ActorFv(p, 0);
        s32 v = n;
        if (v > 0) {
            operator delete(p);
        }
    }
    return p;
}
