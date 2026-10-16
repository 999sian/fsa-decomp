#include "types.h"
#include "Game/Actor.h"

extern "C" char lbl_8049E8A0[];
extern "C" f32 lbl_8053CC3C;
extern "C" void __ct__5ActorFv(Actor*);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" Actor* fn_8012E6EC(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_8049E8A0;
        if (*(void**)((char*)p + 0x240) != 0) {
            fn_801EE434(*(void**)((char*)p + 0x240));
            *(s32*)((char*)p + 0x240) = 0;
        }
        if (*(void**)((char*)p + 0x244) != 0) {
            fn_801EE434(*(void**)((char*)p + 0x244));
            *(s32*)((char*)p + 0x244) = 0;
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" Actor* fn_8012E780(Actor* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049E8A0;
    *(s32*)((char*)p + 0x230) = 0;
    *(s32*)((char*)p + 0x234) = 0;
    *(f32*)((char*)p + 0x238) = lbl_8053CC3C;
    *(s32*)((char*)p + 0x23c) = 0;
    *(s32*)((char*)p + 0x240) = 0;
    *(s32*)((char*)p + 0x244) = 0;
    return p;
}
