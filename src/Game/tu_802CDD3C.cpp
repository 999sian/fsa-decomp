#include "Game/Actor.h"


extern "C" char lbl_804A927C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802CDD3C(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A927C;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
