#include "Game/Actor.h"


extern "C" char lbl_804ABA90[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_80336294(void) {
}

extern "C" Actor* fn_80337010(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804ABA90;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(*(void**)((u8*)p + 0x2a0 + i * 4));
            fn_801EE434(*(void**)((u8*)p + 0x2b0 + i * 4));
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

