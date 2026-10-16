#include "Game/Actor.h"

extern void* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern s32 lbl_804AB248[];
extern char lbl_8047174C[];
extern f32 lbl_80541A58;
extern "C" void fn_802F86CC(u32, void*, u32, s32, f32, f32, void*);
extern "C" void fn_80307AC8(u32, s32, void*, s32, s32, s32, s32);


extern "C" char lbl_804AB258[];
extern "C" void __dt__5ActorFv(Actor*, s32);
struct SlotVirt6 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual u32 v06(u32 a, char* b);
};
struct Init48 {
    u8 idx[0x10];
    s32 w18;
    s32 w1c;
    s32 w20;
    s8 b24[0xc];
    s32 w30;
    u8 b34[3];
    s32 w38;
    s32 w3c;
    s32 w40;
};
extern s32 lbl_804AB248[];
extern u8* lbl_8053AB10;
extern char lbl_8047174C[];
extern f32 lbl_80541A58;
extern "C" void fn_802F86CC(u32, void*, u32, s32, f32, f32, void*);
extern "C" void fn_80307AC8(u32, s32, void*, s32, s32, s32, s32);

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

extern "C" void fn_8031EFAC(char* this_) {
    Init48 s;
    s32 i;
    s.w18 = -1;
    s.w1c = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        s.idx[(u8)i] = i;
        s.idx[(u8)(i + 1)] = i + 1;
        s.idx[(u8)(i + 2)] = i + 2;
        s.idx[(u8)(i + 3)] = i + 3;
        s.idx[(u8)(i + 4)] = i + 4;
        s.idx[(u8)(i + 5)] = i + 5;
        s.idx[(u8)(i + 6)] = i + 6;
        s.idx[(u8)(i + 7)] = i + 7;
    }
    s.w18 = -1;
    s.w1c = 0;
    s.w20 = 0;
    s.b24[0] = 0;
    s.b24[1] = 0;
    s.b24[2] = 0;
    s.b24[3] = 1;
    s.b24[4] = 1;
    s.b24[5] = 0;
    s.b24[6] = 0;
    s.b24[7] = 0;
    s.b24[8] = 0;
    s.b24[9] = 0;
    s.b24[10] = 1;
    s.w30 = 3;
    s.b34[0] = 1;
    s.b34[1] = 0;
    s.b34[2] = 0;
    s.w38 = -1;
    s.w3c = 0;
    s.w40 = 2;
    s.b24[1] = -2;
    s.b24[0] = 0;
    s.b34[1] = 1;
    if (*(s32*)(this_ + 0x230) == 0) {
        s32 iVar1 = *(s32*)(this_ + 0x238) + lbl_804AB248[*(s32*)(this_ + 0x244)];
        if (*(s32*)(this_ + 0x4) < 8) {
            u32 uVar2 = ((SlotVirt6*)*(char**)((u8*)lbl_8053AAF8 + 0xa4))->v06(0x534f4220, lbl_8047174C);
            fn_802F86CC(*(u32*)(lbl_8053AB10 + 0x20), this_ + 0xc, uVar2, iVar1, lbl_80541A58, lbl_80541A58, &s);
        }
        fn_80307AC8(*(s32*)(this_ + 0x198), *(s32*)(this_ + 0x4), this_ + 0xc, *(s32*)(this_ + 0x238) + lbl_804AB248[*(s32*)(this_ + 0x244)], 0, 0, -1);
    }
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

