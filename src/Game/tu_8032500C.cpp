#include "Game/Actor.h"


extern "C" char lbl_804AB464[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8032500C(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AB464;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
