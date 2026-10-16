#include "Game/Actor.h"


struct Unk8035A1D4;
typedef void (Unk8035A1D4::*Unk8035A1D4Func)();
extern Unk8035A1D4Func lbl_804AD30C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804AD348[];
extern "C" Actor* fn_80358460(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AD348;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8035A1D4(Unk8035A1D4* self) {
    u32 v = *(u32*)((u8*)self + 0x90);
    (self->*lbl_804AD30C[(v >> 7) & 0x1f])();
}
