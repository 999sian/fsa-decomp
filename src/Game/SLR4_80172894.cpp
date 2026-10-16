#include "types.h"

extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void v07__5ActorFv(void* this_);
extern "C" void fn_80172894(void* this_) {
    char* p = (char*)this_;
    if ((s32)(*(u32*)(p + 0x90) & 0xff) == 6) {
        *(s32*)(p + 0x18c) = 0;
        Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
    }
    v07__5ActorFv(this_);
}
