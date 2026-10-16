#include "Game/Actor.h"


extern "C" char lbl_804AB850[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8032EEB8(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AB850;
        fn_801EE434(*(void**)((char*)p + 0x284));
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
