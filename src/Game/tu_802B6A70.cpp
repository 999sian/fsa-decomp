#include "Game/Actor.h"


extern "C" char lbl_804A87A8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" Actor* fn_802B74F4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A87A8;
        if (*(void**)((char*)p + 0x230)) {
            fn_801EE434(*(void**)((char*)p + 0x230));
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
