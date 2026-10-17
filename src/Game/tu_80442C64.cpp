#include "types.h"
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" u8 fn_802308E0(s32 p);
extern void* lbl_804B1A48[];
extern void* lbl_8053AD30;
extern u8* lbl_8053AED0;
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u32 fn_80309D24(void* p, s32 i, u32 mask);
extern "C" u32 fn_80309D6C(void* p, s32 i, u32 mask);
extern "C" void fn_8023061C(s32 p, s32 a);
extern "C" void fn_8022FE80(s32 a, void* b, void* c, s32 d, s32 e);
extern "C" s32 fn_8022FD8C(void* a);
extern "C" u8 fn_80388CAC(s32 a, void* b);
extern "C" u8 fn_8038C678(s32 a, s32 b, s32 c, s32 d, void* e, s32 f);
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
