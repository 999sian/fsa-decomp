#include "types.h"
#include "Game/Actor.h"


extern "C" char lbl_804ADFE8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8036766C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804ADFE8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_803676CC(u8* param_1) {
    u8* p = *(u8**)(param_1 + 0x270);
    if (p != 0) {
        *(u32*)(p + 0xf4) |= 0x100;
        *(u8**)(param_1 + 0x270) = 0;
    }
    p = *(u8**)(param_1 + 0x274);
    if (p == 0) {
        return;
    }
    *(u32*)(p + 0xf4) |= 0x100;
    *(u8**)(param_1 + 0x274) = 0;
}
