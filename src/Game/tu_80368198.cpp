

#include "types.h"

struct Sub8036C69C {
    virtual void v0();
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
