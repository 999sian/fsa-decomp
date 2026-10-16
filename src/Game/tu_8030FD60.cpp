#include "Game/Actor.h"


extern "C" char lbl_804AAA70[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8030FD60(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AAA70;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8030FDC0(char* p, s32 v) {
    *(s32*)(p + 0x25c) = v;
    *(s32*)(p + 0x234) = 0x3c;
    *(s32*)(p + 0x230) = 6;
}

