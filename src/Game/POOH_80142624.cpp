#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

extern "C" char lbl_8049F330[];
extern "C" void __dt__5ActorFv(Actor* this_, s32 flag);
extern "C" Actor* fn_80142624(Actor* this_, s16 flag) {
    if (this_) {
        *(void**)this_ = lbl_8049F330;
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

void __sinit_POOH_80142624_cpp(void) {}

