#include "types.h"
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" u8 fn_802308E0(s32 p);
extern void* lbl_804B1A48[];
extern "C" void* fn_80442C64(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1A48;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_80443064(void* this_)
{
    if (fn_802308E0(*(u32*)((u8*)this_ + 0x90) >> 28) == 0) {
        *((u8*)this_ + 0x11c) = 0;
    }
    *(s32*)((u8*)this_ + 0x230) = 0;
    *(s32*)((u8*)this_ + 0x234) = 1;
}
