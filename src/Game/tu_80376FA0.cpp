#include "Game/Actor.h"


extern "C" char lbl_804AE7D8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80376FA0(Actor* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE7D8;
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
