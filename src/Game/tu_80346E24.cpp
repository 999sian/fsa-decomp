#include "Game/Actor.h"


extern "C" char lbl_804AC6B0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80346E24(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC6B0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" Vec lbl_80472010[];
extern "C" void fn_80347B20(Actor* this_) {
    u8* p = (u8*)this_;
    *(f32*)(p + 0x60) = -4.0f;
    *(f32*)(p + 0x64) = -4.0f;
    *(f32*)(p + 0x68) = 4.0f;
    *(f32*)(p + 0x6c) = 4.0f;
    *(f32*)(p + 0x80) = -4.0f;
    *(f32*)(p + 0x84) = -4.0f;
    *(f32*)(p + 0x88) = 4.0f;
    *(f32*)(p + 0x8c) = 4.0f;
    *(u32*)(p + 0x108) = 8;
    *(u16*)(p + 0x264) = 0;
    *(f32*)(p + 0x26c) = 1.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x23c) = 0.0f;
    *(f32*)(p + 0x238) = 0.0f;
    *(f32*)(p + 0x234) = 0.0f;
    *(u8*)(p + 0x270) = (this_->field_90 >> 8) & 1;
    *(u32*)(p + 0x24c) = 0x400;
    if (((this_->field_90 >> 4) & 1) == 1) {
        *(u32*)(p + 0x230) = 1;
        *(u16*)(p + 0x264) = fn_80226850(p + 0xc, *(u32*)(p + 0x4));
        *(u32*)(p + 0xb0) = 0;
    } else {
        *(u32*)(p + 0x230) = 0;
        *(u32*)(p + 0xb0) = 0x20000;
    }
    *(s32*)(p + 0x254) = (this_->field_90 >> 27) & 3;
    if (*(s32*)(p + 0x254) != 0) {
        Vec* v;
        *(s32*)(p + 0x258) = (this_->field_90 >> 22) & 3;
        v = &lbl_80472010[*(s32*)(p + 0x258) | ((*(s32*)(p + 0x254) - 1) << 2)];
        *(f32*)(p + 0x3c) = v->x;
        *(f32*)(p + 0x40) = v->y;
        *(f32*)(p + 0x44) = v->z;
    }
    *(s32*)(p + 0x250) = -1;
    *(u8*)(p + 0x271) = this_->field_90 & 1;
    *(u32*)(p + 0x25c) = 0;
}

