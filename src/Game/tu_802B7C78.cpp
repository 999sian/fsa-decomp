#include "Game/Actor.h"


extern "C" char lbl_804A886C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_802D6A9C(void);
extern "C" void fn_802D9FBC(void);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void*, u32, s32);
extern f32 lbl_80540ACC;
extern "C" Actor* fn_802B7C78(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A886C;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
