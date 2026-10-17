#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804A6E20[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8022979C(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A6E20;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
