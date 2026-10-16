#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049D020[];
extern void* lbl_8049CC34[];
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void* p, void* sym, s32 n);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p, f32 f);
extern "C" void fn_8010C294(void* this_, s32 mode);
extern f32 lbl_8053C4A4;
extern f32 lbl_8053C4A0;
extern f32 lbl_8053C4BC;
extern f32 lbl_8053C4F0;
extern f32 lbl_8053C4F4;
extern f32 lbl_8053C490;
extern void* lbl_80539EE8[];
extern "C" void* fn_8010D6F0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049D020;
        fn_801EE434(*(void**)(p + 0x374));
        *(s32*)(p + 0x374) = 0;
        fn_801EE434(*(void**)(p + 0x378));
        *(s32*)(p + 0x378) = 0;
        fn_801EE434(*(void**)(p + 0x37c));
        *(s32*)(p + 0x37c) = 0;
        if (p + 0x274 != 0) {
            if (p + 0x298 != 0) {
                *(void**)(p + 0x298) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern f32 lbl_8053C4D4;
extern f32 lbl_8053C490;
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* p);
extern "C" u8* fn_8010D7A0(u8* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_8049D020;
    f32 b = lbl_8053C490;
    f32 a = lbl_8053C4D4;
    *(u16*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = -1;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x260) = a;
    *(f32*)(this_ + 0x264) = b;
    *(f32*)(this_ + 0x268) = b;
    *(f32*)(this_ + 0x26c) = a;
    *(f32*)(this_ + 0x270) = a;
    fn_801D267C(this_ + 0x274);
    *(s32*)(this_ + 0x374) = 0;
    *(s32*)(this_ + 0x378) = 0;
    *(s32*)(this_ + 0x37c) = 0;
    return this_;
}

