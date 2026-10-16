#include "types.h"

extern "C" void __ct__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_801D267C(void* this_);
extern void* lbl_8049E424[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053CAA4;
extern const f32 lbl_8053CAA8;
extern "C" u8 fn_80126EF8(u8* this_) {
    s32 v = *(s32*)(this_ + 0x230);
    if (v == 1 || v == 0xc) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_80127AAC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049E424;
        fn_801EE434(*(void**)(p + 0x37c));
        fn_801EE434(*(void**)(p + 0x380));
        *(s32*)(p + 0x37c) = 0;
        *(s32*)(p + 0x380) = 0;
        if (p + 0x27c != 0) {
            if (p + 0x2a0 != 0) {
                *(void**)(p + 0x2a0) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80127B48(void* this_) {
    __ct__5ActorFv(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_8049E424;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0xff;
    *(u8*)(p + 0x258) = 0;
    *(u8*)(p + 0x259) = 0;
    *(f32*)(p + 0x25c) = lbl_8053CAA8;
    *(f32*)(p + 0x260) = lbl_8053CAA4;
    *(f32*)(p + 0x264) = lbl_8053CAA8;
    *(f32*)(p + 0x268) = lbl_8053CAA8;
    *(f32*)(p + 0x26c) = lbl_8053CAA8;
    *(f32*)(p + 0x270) = lbl_8053CAA8;
    *(f32*)(p + 0x274) = lbl_8053CAA8;
    *(f32*)(p + 0x278) = lbl_8053CAA8;
    fn_801D267C(p + 0x27c);
    *(s32*)(p + 0x37c) = 0;
    *(s32*)(p + 0x380) = 0;
    return this_;
}

