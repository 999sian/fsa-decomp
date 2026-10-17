#include "Game/SinitPoolChain.h"
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
extern void* lbl_80539EE8[2];
extern "C" void fn_8010D55C(u8* this_) {
    f32 t;
    v01__5ActorFv(this_);
    *(s32*)(this_ + 0x234) = *(s32*)(this_ + 0x90) & 0xf;
    if (((*(s32*)(this_ + 0x90)) >> 4 & 0xf) == 1) {
        *(f32*)(this_ + 0x260) = lbl_8053C4A4;
        t = *(f32*)(this_ + 0x260);
        *(f32*)(this_ + 0x54) = t;
        *(f32*)(this_ + 0x58) = t;
        *(f32*)(this_ + 0x5c) = t;
    }
    *(s32*)(this_ + 0x258) = (*(s32*)(this_ + 0x90) >> 8) & 0xff;
    *(s32*)(this_ + 0x25c) = (*(s32*)(this_ + 0x90) >> 16) & 0xff;
    if (*(s32*)(this_ + 0x258) > 0 && lbl_8053C4A4 == *(f32*)(this_ + 0x260)) {
        f32 b = lbl_8053C4A0;
        f32 a = lbl_8053C4F0;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
    } else {
        f32 b = lbl_8053C4BC;
        f32 a = lbl_8053C4F4;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x84) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x88) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x8c) = *(f32*)(this_ + 0x6c);
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0xb8) = 1;
    *(s32*)(this_ + 0xf8) = 2;
    *(s32*)(this_ + 0xbc) = 3;
    *(s32*)(this_ + 0x1a4) = 1;
    *(s32*)(this_ + 0x118) = 2;
    *(s32*)(this_ + 0x114) = 2;
    *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x98);
    *(s32*)(this_ + 0xb0) = 0xa040304;
    fn_801D2608(this_ + 0x274, lbl_80539EE8, 2);
    fn_801D22DC(this_ + 0x274, 0, 2, 0);
    fn_801D1F14(this_ + 0x274, lbl_8053C490);
    if (*(s32*)(this_ + 0x258) > 0) {
        fn_8010C294(this_, 3);
    }
}

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

