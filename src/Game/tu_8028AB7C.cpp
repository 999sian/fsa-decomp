#include "types.h"
#include "Game/SinitPoolChain.h"


void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A7960[];
extern "C" void fn_801EE434(void* handle);
extern "C" u8 fn_80303750(s32 i);
extern "C" u8 fn_8028B850(u8* this_);
extern "C" f32 lbl_805404CC;
extern "C" f32 lbl_805404C0;
extern "C" void fn_8028BA5C(u8* this_) {
    s32 i;
    this_[0x250] = 1;
    for (i = 0; i < 4; i++) {
        if (fn_80303750(i)) {
            this_[0x250] = 0;
            break;
        }
    }
    if (this_[0x250] == 1) {
        this_[0x234] = fn_8028B850(this_);
    }
    *(f32*)(this_ + 0x240) = (this_[0x234] == 1) ? lbl_805404CC : lbl_805404C0;
    *(s32*)(this_ + 0x244) = (this_[0x234] == 1) ? 0x6e : 0;
}

extern "C" void* fn_8028BDD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7960;
        fn_801EE434(*(void**)((u8*)this_ + 0x274));
        fn_801EE434(*(void**)((u8*)this_ + 0x278));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
