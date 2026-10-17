#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_8010DF58();
extern "C" void fn_8010DF98();
extern "C" void fn_801D2608(void* p, u32 a, u32 b);
extern "C" void fn_801D22DC(void* p, u32 a, u32 b, u32 c);
extern "C" void fn_801D1F14(void* p);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7440(void* p, u32 a);
extern "C" void __dt__13Base_8010E074Fv(void* p, int how);
extern "C" void fn_801EE434(void* p);
extern void operator delete(void* p);
extern f32 lbl_8053C7D0;

extern void* lbl_8049DB30[];
extern void* lbl_8049CC34[];

extern f32 lbl_8053C7D0;
extern "C" u32 fn_8011AAB0(void* param_1) {
    u32 val = *(u32*)((u8*)param_1 + 0x234);
    return ((3U - val) | (val - 3U)) >> 31;
}

extern "C" s32 fn_8011AAC8(char* p) {
    return *(s32*)(p + 0x234);
}

extern "C" void fn_8011AD30() {
    fn_8010DF58();
}

extern "C" void fn_8011AF9C(void* param_1) {
    fn_8010DF98();
    u32 val = *(u32*)((u8*)param_1 + 0x90);
    *(u32*)((u8*)param_1 + 0x238) = val & 0xf;
    *(u32*)((u8*)param_1 + 0x23c) = (val >> 4) & 0xf;
    fn_801D2608((u8*)param_1 + 0x25c, 0x80539F18, 1);
    fn_801D22DC((u8*)param_1 + 0x25c, 0, 2, 0);
    fn_801D1F14((u8*)param_1 + 0x25c);
    void* result = fn_802D6A9C();
    fn_802D7440(result, 0);
}

extern "C" void* fn_8011B01C(void* this_, s16 freeFlag) {
    if (this_) {
        *(void**)this_ = lbl_8049DB30;
        fn_801EE434(*(void**)((u8*)this_ + 0x24c));
        *(void**)((u8*)this_ + 0x24c) = 0;
        fn_801EE434(*(void**)((u8*)this_ + 0x250));
        *(void**)((u8*)this_ + 0x250) = 0;
        fn_801EE434(*(void**)((u8*)this_ + 0x254));
        *(void**)((u8*)this_ + 0x254) = 0;
        fn_801EE434(*(void**)((u8*)this_ + 0x258));
        *(void**)((u8*)this_ + 0x258) = 0;
        if ((void*)((u8*)this_ + 0x25c) != 0 && (void*)((u8*)this_ + 0x280) != 0) {
            *(void**)((u8*)this_ + (unsigned short)0x280) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8010E074(void* this_);
extern "C" void fn_801D267C(void* p);
extern "C" void* fn_8011B0DC(void* this_) {
    fn_8010E074(this_);
    *(void**)this_ = lbl_8049DB30;
    *((u8*)this_ + 0x230) = 1;
    *(s32*)((u8*)this_ + 0x234) = 0;
    *(s32*)((u8*)this_ + 0x238) = 0;
    *(s32*)((u8*)this_ + 0x23c) = 0;
    *(s32*)((u8*)this_ + 0x240) = 0;
    *((u8*)this_ + 0x244) = 0x9f;
    *((u8*)this_ + 0x245) = 0xaf;
    *((u8*)this_ + 0x246) = 0xff;
    *((u8*)this_ + 0x247) = 0;
    *((u8*)this_ + 0x248) = 0xff;
    *(s32*)((u8*)this_ + 0x24c) = 0;
    *(s32*)((u8*)this_ + 0x250) = 0;
    *(s32*)((u8*)this_ + 0x254) = 0;
    *(s32*)((u8*)this_ + 0x258) = 0;
    fn_801D267C((u8*)this_ + 0x25c);
    return this_;
}

