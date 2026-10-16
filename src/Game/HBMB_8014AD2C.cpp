#include "types.h"

extern "C" char lbl_8049F784[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* p);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_8013CB44(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" void* fn_8014CF28(u32* this_, s16 freeFlag) {
    if (this_ != 0) {
        u32* p = this_;
        s32 i = 0;
        *(char**)this_ = lbl_8049F784;
        do {
            fn_801EE434((void*)p[0xa4]);
            i++;
            p++;
        } while (i < 3);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8014D304(int* this_) {
    (*(void (**)(void))(*this_ + 0x54))();
}

extern "C" void fn_8014DA20(u8* this_) {
    s32 idx = *(s32*)(this_ + 0xa0);
    if (idx >= 0) {
        void* p = fn_801F666C(fn_801F856C(), idx);
        if (p != 0 && *(u32*)((u8*)p + 0x1a0) == 0x41525257) {
            fn_8013CB44(*(void**)(this_ + 0x294), this_ + 0xc, 0, 0, 0);
            fn_8013CB44(*(void**)(this_ + 0x298), this_ + 0xc, 0, 0, 0);
        }
    }
}

