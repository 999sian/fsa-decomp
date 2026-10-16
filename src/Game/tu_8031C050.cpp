#include "Game/Actor.h"


extern "C" char lbl_804AB170[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8031C050(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB170;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
