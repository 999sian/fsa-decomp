#include "types.h"
#include "JSystem/JMath/JMath.h"

struct PopoGame {
    u8 pad[0xb4];
    JMARandFast rnd;
};
extern PopoGame* lbl_8053AAF8;

extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern const char lbl_80465B68[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_8049F3B0[];
extern "C" void* fn_80143874(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F3B0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801438D4(u8* this_) {
    fn_801F06F0(this_, lbl_80465B68, *(s32*)(this_ + 0x240) + 0x1a, 0, 0, 1.0f, 1.0f);
}

extern "C" void fn_80143DD8(u8* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x98) = 0;
    PopoGame* g = lbl_8053AAF8;
    s32 r = (s32)(2.0f * g->rnd.get_ufloat_1());
    switch (r) {
    case 0:
        *(f32*)(this_ + 0x3c) = 1.0f;
        break;
    case 1:
        *(f32*)(this_ + 0x3c) = -1.0f;
        *(s32*)(this_ + 0x98) = 1;
        break;
    }
    *(s32*)(this_ + 0x234) = 0;
    PopoGame* g2 = lbl_8053AAF8;
    *(s32*)(this_ + 0x238) = (s32)(50.0f * g2->rnd.get_ufloat_1());
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x230) = 0;
}

