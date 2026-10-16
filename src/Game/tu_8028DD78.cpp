#include "types.h"


extern "C" char __vt__4RASN[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_8028DD78(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4RASN;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8028E1E8(void) {
}

