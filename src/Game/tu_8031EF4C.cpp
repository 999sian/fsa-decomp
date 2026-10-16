#include "Game/Actor.h"


extern "C" char lbl_804AB258[];
extern "C" void __dt__5ActorFv(Actor*, s32);
struct Init48 {
    u8 idx[0x10];
    s32 w18;
    s32 w1c;
    s32 w20;
    u8 b24[0xc];
    s32 w30;
    u8 b34[3];
    s32 w38;
    s32 w3c;
    s32 w40;
};
extern s32 lbl_804AB248[];

extern "C" Actor* fn_8031EF4C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AB258;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" u16 fn_80226850(void* pos, s32 room);
extern void* lbl_8053AAF8;
extern "C" void fn_8031F97C(Actor* this_) {
    u8* p = (u8*)this_;
    if (((u8*)lbl_8053AAF8)[0x7f] == 0) {
        this_->detach();
    } else {
        *(u32*)(p + 0x244) = this_->field_90 & 3;
        *(u32*)(p + 0x248) = (this_->field_90 >> 8) & 0xff;
        this_->field_94 = (this_->field_90 >> 16) & 0xff;
        *(u16*)(p + 0x26c) = 0;
        *(u32*)(p + 0x238) = 0;
        *(u32*)(p + 0x234) = 0;
        *(u32*)(p + 0x24c) = 0;
        *(u32*)(p + 0x25c) = 0;
        *(u32*)(p + 0x250) = 0;
        *(u32*)(p + 0x260) = 0;
        *(u32*)(p + 0x254) = 0;
        *(u32*)(p + 0x264) = 0;
        *(u32*)(p + 0x258) = 0;
        *(u32*)(p + 0x268) = 0;
        this_->field_108 = 10000;
        *(u32*)(p + 0x23c) = 0;
        *(s32*)(p + 0x240) = -1;
        *(u32*)(p + 0x230) = 0;
        *(f32*)(p + 0xc) = (f32)((s32)*(f32*)(p + 0xc) / 16) * 16.0f + 8.0f;
        *(f32*)(p + 0x10) = (f32)((s32)*(f32*)(p + 0x10) / 16) * 16.0f + 8.0f;
        if (this_->field_94 == 1 || this_->field_94 == 4) {
            *(u32*)(p + 0x230) = 1;
            *(u16*)(p + 0x26c) = fn_80226850(p + 0xc, this_->field_04);
        }
        if (this_->field_94 == 2) {
            *(u32*)(p + 0x230) = 2;
        }
        if (this_->field_94 == 3 || this_->field_94 == 5) {
            *(u32*)(p + 0x230) = 2;
        }
        *(f32*)(p + 0x3c) = 0.0f;
        *(f32*)(p + 0x40) = 0.0f;
        *(f32*)(p + 0x44) = 0.0f;
        *(f32*)(p + 0x80) = -8.0f;
        *(f32*)(p + 0x84) = -8.0f;
        *(f32*)(p + 0x88) = 8.0f;
        *(f32*)(p + 0x8c) = 8.0f;
        *(f32*)(p + 0x60) = -4.0f;
        *(f32*)(p + 0x64) = -4.0f;
        *(f32*)(p + 0x68) = 4.0f;
        *(f32*)(p + 0x6c) = 4.0f;
    }
}

