#include "Game/Actor.h"


extern "C" char lbl_804AE620[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80374788(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AE620;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
