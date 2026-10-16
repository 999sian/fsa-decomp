#include "types.h"


void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A7960[];
extern "C" void fn_801EE434(void* handle);
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
