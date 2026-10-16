#include "types.h"
#include "Game/Actor.h"


extern "C" char lbl_804AB9C0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80334318(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB9C0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
