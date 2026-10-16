#include "Game/Actor.h"


extern "C" u32 fn_801F132C(Actor* a, s32 b, s32 c, s32* d);
extern "C" char __vt__4RCK2[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_8034C9B0(Actor* a, s32 b, s32 c) {
    fn_801F132C(a, b, c, (s32*)((u8*)a + 0x378));
}
