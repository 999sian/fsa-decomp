#include "types.h"


extern void* lbl_804AC0A8[];
extern "C" void fn_801EE434(void* obj);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_80338AE0(void) {
}

extern "C" u32 fn_8013CC50(u32 a, void* pos, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" void fn_80339374(u8* p) {
    *(u16*)(p + 0x94) = *(u32*)(p + 0x90) & 0xf;
    *(u32*)(p + 0x108) = 10000;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x240) = 0;
    *(u32*)(p + 0x244) = 0;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 8) & 0xf;
    *(f32*)(p + 0x258) = 0.0f;
    *(u32*)(p + 0x264) = 0;
    *(u32*)(p + 0x268) = 0;
    *(u8*)(p + 0x25c) = 0;
    *(u32*)(p + 0x26c) = 0;
    *(u32*)(p + 0x248) = 0;
    *(u8*)(p + 0x260) = 0;
    *(u8*)(p + 0x25d) = 0;
    *(u32*)(p + 0x270) = 0;
    *(u32*)(p + 0x24c) = 0;
    *(u8*)(p + 0x261) = 0;
    *(u8*)(p + 0x25e) = 0;
    *(u32*)(p + 0x274) = 0;
    *(u32*)(p + 0x250) = 0;
    *(u8*)(p + 0x262) = 0;
    *(u8*)(p + 0x25f) = 0;
    *(u32*)(p + 0x278) = 0;
    *(u32*)(p + 0x254) = 0;
    *(u8*)(p + 0x263) = 0;

    if (*(u32*)(p + 0x264) == 0) {
        f32 pos[3] = { *(f32*)(p + 0xc), 16.0f + *(f32*)(p + 0x10), *(f32*)(p + 0x14) };
        *(u32*)(p + 0x264) = fn_8013CC50(*(u32*)(p + 4), pos, 0x4e0, 1, 2, 0, 0, 1, 1.0f);
    }
    if (*(u32*)(p + 0x268) == 0) {
        f32 pos[3] = { *(f32*)(p + 0xc), 16.0f + *(f32*)(p + 0x10), *(f32*)(p + 0x14) };
        *(u32*)(p + 0x268) = fn_8013CC50(*(u32*)(p + 4), pos, 0x4e1, 1, 2, 0, 0, 1, 1.0f);
    }
    *(f32*)(p + 0x60) = -47.0f;
    *(f32*)(p + 0x64) = -47.0f;
    *(f32*)(p + 0x68) = 47.0f;
    *(f32*)(p + 0x6c) = 15.0f;
}

extern "C" void* fn_803394F8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC0A8;
        fn_801EE434(*(void**)((char*)this_ + 0x264));
        fn_801EE434(*(void**)((char*)this_ + 0x268));
        char* p;
        s32 i;
        for (i = 0, p = (char*)this_; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x26c));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

