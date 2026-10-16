#include "Game/ItemBase.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804AB3A8[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80541B70;
extern "C" char lbl_8047184C[];
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_802F86CC(void*, void*, void*, f32, f32, s32, void*);
extern "C" void* fn_80324570(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB3A8;
        fn_801EE434(*(void**)(this_ + 0x26c));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
