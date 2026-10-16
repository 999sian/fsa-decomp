#include "types.h"
#include "Game/Actor.h"

extern "C" char lbl_8049E5B8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_80129200(Actor*);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" Actor* fn_801291A0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049E5B8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8012952C(Actor* p, s32 state) {
    switch (state) {
    case 0:
        break;
    case 1:
        *(s32*)((u8*)p + 0x23c) = -1;
        *(s32*)((u8*)p + 0x238) = 0;
        break;
    case 2:
        fn_80129200(p);
        break;
    }
    *(s32*)((u8*)p + 0x230) = state;
}

