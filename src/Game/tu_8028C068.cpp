#include "Game/Actor.h"


extern "C" char lbl_804A7A10[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8028C068(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804A7A10;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" s16 fn_8022461C(float*);
extern "C" int fn_8028D470(Actor* this_, int a, float* b) {
    if ((s32)(u16)fn_8022461C(b) == 0xd) {
        return 0;
    }
    return this_->Actor::v17(a, b);
}

