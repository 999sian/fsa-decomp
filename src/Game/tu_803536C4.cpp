#include "Game/Actor.h"


extern "C" char lbl_804ACC68[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803536C4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804ACC68;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
