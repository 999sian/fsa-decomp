#include "Game/esd/types.h"
#include "Game/Actor.h"


extern "C" char lbl_804AABA8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void __dl__FPv(void*);
extern "C" Actor* fn_80312668(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AABA8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
