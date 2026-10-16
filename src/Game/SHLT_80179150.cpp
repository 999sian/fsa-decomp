#include "types.h"
#include "Game/Actor.h"

extern "C" char lbl_804A0FF8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80179150(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A0FF8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
