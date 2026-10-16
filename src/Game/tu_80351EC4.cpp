#include "types.h"

extern void* lbl_804ACB40[];

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" f32 lbl_80542684;
extern "C" f32 lbl_80542688;

extern "C" void* fn_80351EC4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804ACB40;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80351F24(void) {}
