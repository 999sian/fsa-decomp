#include "types.h"
#include "Game/Actor.h"


extern "C" char __vt__4NWOK[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804720E8[];
extern "C" f32 lbl_80542518;
extern "C" void fn_801F06F0(void*, const char*, s32, f32, f32, s32, s32);
extern "C" Actor* fn_8034AA40(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4NWOK;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
