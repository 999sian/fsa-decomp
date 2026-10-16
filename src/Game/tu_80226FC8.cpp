#include "types.h"


extern "C" void fn_801EE434(void* p);
extern "C" void __dt__5ActorFv(void* p, int how);
extern void operator delete(void* p);
extern void* lbl_804A6DC8[];
extern "C" void* fn_80228AEC(void* this_, s16 freeFlag) {
    if (this_) {
        *(void**)this_ = lbl_804A6DC8;
        fn_801EE434(*(void**)((u8*)this_ + 0x24c));
        fn_801EE434(*(void**)((u8*)this_ + 0x250));
        __dt__5ActorFv(this_, 0);
        s32 f = freeFlag;
        if (f > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
