#include "Game/Actor.h"


extern "C" char lbl_804A9328[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802CFDCC(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A9328;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802D0900(void) {
}

