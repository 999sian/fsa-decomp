#include "types.h"
#include "Game/Actor.h"


extern "C" s16 fn_8022461C(s32);
extern "C" char lbl_804AC658[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8034543C(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_804AC658;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_803466C0(s32 param_1, s32 param_2, s32 param_3) {
    s32 r = (u16)fn_8022461C(param_3);
    if (r == 0xd || r == 0x3a) {
        return 0;
    }
    return 1;
}


