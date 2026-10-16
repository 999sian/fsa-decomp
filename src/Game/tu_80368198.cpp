

#include "types.h"

struct Sub8036C69C {
    virtual void v0(int);
    virtual void v1();
    virtual void v2(int);
};
struct Unk8036C300;
typedef void (Unk8036C300::*Unk8036C300Func)();
extern Unk8036C300Func lbl_804AE070[];
extern char lbl_804AE088[];
extern char lbl_8049CC34[];
extern "C" void __dt__13Base_8010E074Fv(void* this_, int how);
extern "C" void fn_8036A65C(void* this_);
extern "C" void fn_801F0E34(void* self, u32 msg, s32 flag);
extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_803683AC(void* this_);
extern "C" void fn_8036A894(void* this_);
extern "C" void fn_8036AC58(void* this_, void* param);
extern "C" void fn_80368660(void* this_);
extern void* lbl_80474C48[];

extern "C" u8 fn_8036B018(u8* this_) {
    s32 v = *(s32*)(this_ + 0x240);
    if (v == 0x11 || v == 0x26) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_8036C69C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = (void*)lbl_804AE088;
        Sub8036C69C* sub = *(Sub8036C69C**)((char*)this_ + 0x314);
        if (sub) {
            sub->v0(1);
        }
        *(void**)((char*)this_ + 0x314) = 0;
        fn_8036A65C(this_);
        if ((s32)this_ != -0x318 && (s32)this_ != -0x33c) {
            *(void**)((char*)this_ + 0x33c) = (void*)lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8036C8F4(void* this_) {
    return *(s32*)((char*)this_ + 0x240);
}

void fn_8036C8FC(void)
{
  extern void __ct__17JASGenericMemPoolFv(void);
  extern void __register_global_object(void*, void*, void*);
  extern char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;

  if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
    __ct__17JASGenericMemPoolFv();
    __register_global_object(0, 0, 0);
  }
}
