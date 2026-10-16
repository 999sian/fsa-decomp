#include "Game/Actor.h"


extern "C" char lbl_804AA9F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8030E9A0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AA9F0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8030EA00(void* p) {
    *(s32*)((u8*)p + 0x230) = 7;
}

extern "C" u32 fn_8030EA0C(void* p) {
    s32 v = *(s32*)((u8*)p + 0x230) ^ 6;
    return (u32)((v >> 1) - (v & 6)) >> 31;
}

