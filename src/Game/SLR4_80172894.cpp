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

extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 b);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern void* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern "C" void fn_801744E4(void* this_) {
    char* p = (char*)this_;
    if (*(u32*)(p + 0x90) == 2 || *(u32*)(p + 0x90) == 3) {
        *(u32*)(p + 0x90) += 2;
        *(s32*)(p + 0x240) = 0;
        *(s32*)(p + 0x264) = 0;
        *(s32*)(p + 0x250) = 0x14;
        if (*(s32*)(p + 0x23c) == 0 && *(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
            fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
        }
        *(s32*)(p + 0x288) = 2;
        if (*(u8*)(p + 0x2a5) == 1) {
            fn_801F0E34(this_, 0x5001f, 0);
        }
        *(s32*)(p + 0x230) = 2;
    }
    s32 state = *(u32*)(p + 0x90) & 0xff;
    if (state != 7 && state != 8 && *(s32*)(p + 0x108) <= 0) {
        s32 idx = *(s32*)(p + 0x238);
        if (idx >= 0) {
            void* obj = fn_801F666C(fn_801F856C(), idx);
            if (obj != 0) {
                *(u8*)((char*)obj + 0x11c) = 0;
            }
        }
        *(s32*)(p + 0x238) = -1;
    }
}

