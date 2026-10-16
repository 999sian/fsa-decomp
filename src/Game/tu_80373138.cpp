#include "Game/Actor.h"


extern "C" char lbl_804AE574[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80373138(Actor* this_, s16 del) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE574;
        __dt__5ActorFv(this_, 0);
        if (del > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
