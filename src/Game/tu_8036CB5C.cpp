#include "Game/Actor.h"


extern "C" char lbl_804AE230[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8036CB5C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AE230;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
