#include "Game/Actor.h"

struct Unk8030EC18Buf {
    u8 idx[16];
    s32 w20;
    s32 w24;
    s32 w28;
    u8 b2c;
    u8 b2d;
    u8 b2e;
    u8 b2f;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
    u8 b36;
    s32 w38;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    s32 w40;
    s32 w44;
    s32 w48;
};


extern "C" char lbl_804AA9F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u16 fn_8022461C(f32* pos, u32 room);
extern "C" u16 fn_80226850(f32* pos, u32 room);
extern "C" u8* fn_802D6A9C(void);
extern "C" Actor* fn_8030E9A0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AA9F0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8030EA00(void* p) {
    *(s32*)((u8*)p + 0x230) = 7;
}

extern "C" u32 fn_8030EA0C(void* p) {
    s32 m = 6;
    s32 v = *(s32*)((u8*)p + 0x230) ^ m;
    return (u32)((v & m) - (v >> 1)) >> 31;
}

extern "C" u32 fn_8030EA2C(Actor* p, s32 room, f32* pos) {
    s32 kind;
    s32 x;

    if (*((u8*)p + 0x245) != 0) {
        return 0;
    }
    kind = fn_8022461C(pos, room);
    x = fn_80226850(pos, room);
    if ((u32)(kind - 0x10) <= 7 || (x >= 0x140 && x <= 0x15f)) {
        *((u8*)p + 0x245) = 1;
        return 0;
    }
    if (kind != 0 && kind != 4 && kind != 5 && kind != 6 && kind != 7 && kind != 2 && kind != 3 && kind != 0xe && kind != 0x50 && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 && kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f && kind != 0x20 && kind != 0xd && kind != 0x3b && kind != 0x39 && kind != 0x3a && kind != 0x4c && kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24) {
        if (kind == 0x25) {
            return fn_802D6A9C()[0x171] == 0;
        }
        if (kind == 0x26) {
            return fn_802D6A9C()[0x171] == 1;
        }
        if (kind != 0x22 || fn_802D6A9C()[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" char lbl_804713A8[];
extern "C" f32 lbl_80541744;
extern "C" s32 fn_8023CB24(void*);
extern "C" s32 fn_8023CA88(void*);
extern "C" void fn_801F06F0(Actor* p, void* a, s32 b, u8* buf, s32 c, f32 d, f32 e);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, u8 h, s32 i, s32 j);
extern "C" void fn_8030EC18(Actor* p) {
    Unk8030EC18Buf buf;
    s32 i;

    if (*(s32*)((u8*)p + 0x230) <= 7) {
        buf.w20 = -1;
        buf.w24 = -1;
        for (i = 0; (u8)i < 0x10; i += 8) {
            buf.idx[(u8)i] = i;
            buf.idx[(u8)(i + 1)] = i + 1;
            buf.idx[(u8)(i + 2)] = i + 2;
            buf.idx[(u8)(i + 3)] = i + 3;
            buf.idx[(u8)(i + 4)] = i + 4;
            buf.idx[(u8)(i + 5)] = i + 5;
            buf.idx[(u8)(i + 6)] = i + 6;
            buf.idx[(u8)(i + 7)] = i + 7;
        }
        buf.w20 = -1;
        buf.w24 = 0;
        buf.w28 = 0;
        buf.b2c = 0;
        buf.b2d = 0;
        buf.b2e = 0;
        buf.b2f = 1;
        buf.b30 = 1;
        buf.b31 = 0;
        buf.b32 = 0;
        buf.b33 = 0;
        buf.b34 = 0;
        buf.b35 = 0;
        buf.b36 = 1;
        buf.w38 = 3;
        buf.b3c = 1;
        buf.b3d = 0;
        buf.b3e = 0;
        buf.w40 = -1;
        buf.w44 = 0;
        buf.w48 = 2;
        if (*((u8*)p + 0xc4) != 0) {
            buf.b30 = 0;
            buf.b2d = fn_8023CB24(*(void**)((u8*)p + 0xc8)) + 1;
            buf.b2c = fn_8023CA88(*(void**)((u8*)p + 0xc8));
        }
        fn_801F06F0(p, lbl_804713A8, *(s32*)((u8*)p + 0x24c) + 0x2ff, (u8*)&buf, 0, lbl_80541744, lbl_80541744);
        fn_803075AC(*(void**)((u8*)p + 0x198), *(void**)((u8*)p + 4), (u8*)p + 0xc, 0x2ff, 0, 2, -1, *((u8*)p + 0xc4), 0, 0);
    }
}

extern "C" f32 lbl_80471368[];
extern "C" f32 lbl_8054173C;
extern "C" f32 lbl_80541740;
extern "C" f32 lbl_8054174C;
extern "C" f32 lbl_80541760;
extern "C" f32 lbl_80541768;
extern "C" f32 lbl_8054176C;
extern "C" f32 lbl_80541770;
extern "C" f32 lbl_80541774;
extern "C" s32 fn_80230CFC(void*);
extern "C" s32 fn_801F2618(void*, s32, s32);
extern "C" void fn_8030F9E4(u8* this_) {
    f32 f0 = lbl_8054173C;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f31;
    s32 i = 0;
    *(f32*)(this_ + 0x3c) = f0;
    *(f32*)(this_ + 0x40) = f0;
    *(f32*)(this_ + 0x44) = f0;
    f3 = lbl_80541768;
    *(f32*)(this_ + 0x60) = f3;
    *(f32*)(this_ + 0x64) = f3;
    f31 = lbl_8054174C;
    f2 = lbl_8054176C;
    *(f32*)(this_ + 0x68) = f2;
    *(f32*)(this_ + 0x6c) = f2;
    f1 = lbl_80541760;
    *(f32*)(this_ + 0x80) = f1;
    *(f32*)(this_ + 0x84) = f1;
    f0 = lbl_80541770;
    *(f32*)(this_ + 0x88) = f0;
    *(f32*)(this_ + 0x8c) = f0;
    *(s32*)(this_ + 0x1a4) = 0;
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x240) = -1;
    this_[0x245] = 0;
    this_[0x246] = 0;
    this_[0x247] = 0;
    this_[0x248] = 0;
    this_[0x249] = 0;
    *(s32*)(this_ + 0x23c) = -1;
    this_[0x244] = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    while (fn_801F2618(this_, 0, 0) & 0xff) {
        s32 idx = fn_80230CFC(*(void**)(this_ + 0x110)) ^ 1;
        f32* v = (f32*)((u8*)lbl_80471368 + idx * 12);
        i++;
        *(f32*)(this_ + 0xc) += f31 * v[0];
        *(f32*)(this_ + 0x10) += f31 * v[1];
        if (i > 8) {
            break;
        }
    }
    f1 = lbl_80541774;
    *(f32*)(this_ + 0x80) = f1;
    *(f32*)(this_ + 0x84) = f1;
    f0 = lbl_80541740;
    *(f32*)(this_ + 0x88) = f0;
    *(f32*)(this_ + 0x8c) = f0;
}

