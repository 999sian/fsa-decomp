#include "types.h"

extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049DE18[];
extern const f32 lbl_8053C8BC;
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CC34[];
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_80539F28[8];
extern const f32 lbl_8053C8B8;
extern const f32 lbl_8053C8C0;
extern const f32 lbl_8053C8DC;
extern const f32 lbl_8053C8E0;
extern const f32 lbl_8053C8E4;
extern const f32 lbl_8053C8E8;
extern const f32 lbl_8053C8EC;
extern const f32 lbl_8053C8F0;
extern "C" void fn_8011E4FC(u8* this_) {
    v01__5ActorFv(this_);
    *(s32*)(this_ + 0x230) = *(s32*)(this_ + 0x90) & 0xF;
    *(s32*)(this_ + 0x238) = (*(s32*)(this_ + 0x90) >> 4) & 0xF;
    *(s32*)(this_ + 0x23C) = (*(s32*)(this_ + 0x90) >> 8) & 0xFF;
    switch (*(s32*)(this_ + 0x230)) {
    case 1: {
        f32 f0 = lbl_8053C8C0;
        f32 f1 = lbl_8053C8E4;
        f32 f2 = lbl_8053C8E0;
        f32 f3 = lbl_8053C8DC;
        *(f32*)(this_ + 0x240) = f0;
        f32 f4 = *(f32*)(this_ + 0x240);
        *(f32*)(this_ + 0x54) = f4;
        *(f32*)(this_ + 0x58) = f4;
        *(f32*)(this_ + 0x5C) = f4;
        *(f32*)(this_ + 0x60) = f3;
        *(f32*)(this_ + 0x64) = f3;
        *(f32*)(this_ + 0x68) = f2;
        *(f32*)(this_ + 0x6C) = f2;
        *(f32*)(this_ + 0x80) = f1;
        *(f32*)(this_ + 0x84) = f1;
        f0 = lbl_8053C8E8;
        *(f32*)(this_ + 0x88) = f0;
        *(f32*)(this_ + 0x8C) = f0;
        break;
    }
    case 0:
    default: {
        f32 f0 = lbl_8053C8EC;
        f32 f1 = lbl_8053C8DC;
        f32 f2 = lbl_8053C8F0;
        *(f32*)(this_ + 0x60) = f0;
        *(f32*)(this_ + 0x64) = f0;
        f0 = lbl_8053C8E0;
        *(f32*)(this_ + 0x68) = f2;
        *(f32*)(this_ + 0x6C) = f2;
        *(f32*)(this_ + 0x80) = f1;
        *(f32*)(this_ + 0x84) = f1;
        *(f32*)(this_ + 0x88) = f0;
        *(f32*)(this_ + 0x8C) = f0;
        break;
    }
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7C) = *(f32*)(this_ + 0x6C);
    *(s32*)(this_ + 0xB8) = 1;
    *(s32*)(this_ + 0xB0) = 0x06040304;
    *(s32*)(this_ + 0x118) = 0;
    *(s32*)(this_ + 0xBC) = 3;
    fn_801D2608(this_ + 0x244, lbl_80539F28, 1);
    fn_801D22DC(this_ + 0x244, 0, 2, 0);
    fn_801D1F14(this_ + 0x244, lbl_8053C8B8);
}

extern "C" void* fn_8011E650(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049DE18;
        fn_801EE434(*(void**)(p + 0x27c));
        *(s32*)(p + 0x27c) = 0;
        if (p + 0x244 != 0) {
            if (p + 0x268 != 0) {
                *(void**)(p + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8011E6E0(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049DE18;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(f32*)(p + 0x240) = lbl_8053C8BC;
    fn_801D267C(p + 0x244);
    *(s32*)(p + 0x27c) = 0;
    return p;
}

void __sinit_ICWL_8011DA20_cpp(void) {}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
