#include "types.h"
#include "Game/Actor.h"


extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" const f32 lbl_80540A3C;
extern "C" char lbl_8046CAB8[];
extern "C" char lbl_804A8750[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802B61C8(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_804A8750;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B6358(void* this_) {
    fn_801F06F0(this_, lbl_8046CAB8, 0x29, 0, 0, lbl_80540A3C, lbl_80540A3C);
}
