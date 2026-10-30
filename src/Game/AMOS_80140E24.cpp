#include "types.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

extern void* lbl_8049F260[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_80140E24(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F260;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F02BC(void* a, u8* p2, void* p3, DrawRec* p4, s32 p5, s32 p6, u8 p7, f32 f6, f32 f7);
extern "C" f32 lbl_8053CEA0;
extern "C" f32 lbl_8053CEA4;
extern "C" u8 lbl_80465AC8[];
extern "C" u8 lbl_80465ADC[];
extern "C" void fn_80140E84(void* this_) {
    DrawRec r;
    f32 m[3][4];
    s32 p5 = 0;
    s32 p6 = 0;
    m[0][3] = lbl_8053CEA0;
    m[1][3] = lbl_8053CEA0;
    m[2][3] = lbl_8053CEA0;
    r.b20 = 0;
    if (*(s32*)((u8*)this_ + 0x31c) != 0) {
        p5 = 3;
        p6 = 1;
        m[0][0] = lbl_8053CEA4;
        m[0][1] = lbl_8053CEA0;
        m[0][2] = lbl_8053CEA0;
        m[1][0] = lbl_8053CEA0;
        m[1][1] = lbl_8053CEA4;
        m[1][2] = lbl_8053CEA0;
        m[2][0] = lbl_8053CEA0;
        m[2][1] = lbl_8053CEA0;
        m[2][2] = lbl_8053CEA4;
        r.w18 = m;
    }
    s16 sVar1 = *(s16*)((u8*)this_ + 0x94);
    if (sVar1 == 3 || (u16)(sVar1 - 4) < 2 || sVar1 == 7) {
        fn_801F02BC(this_, lbl_80465AC8, (u8*)*(void**)((u8*)this_ + 0x318) + 0x444, &r, 3, p6, 0, lbl_8053CEA4, lbl_8053CEA4);
    } else {
        fn_801F02BC(this_, lbl_80465ADC, (u8*)*(void**)((u8*)this_ + 0x318) + 0x152, &r, p5, p6, 0, lbl_8053CEA4, lbl_8053CEA4);
    }
}

#include "JSystem/JGeometry/Box.h"
#include "sdk/stl/math.h"
extern "C" int fn_801F3D94(void* this_, int = 1);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u8 fn_801F305C(void* this_);
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" u8 fn_80237948(void* a, void* b);
extern "C" void fn_8013CC50(s32 obj, void* pos, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 v);
extern "C" void fn_80239914(void* a, s32 b, s32 c);
extern "C" void fn_801EF510(void* this_);
extern "C" f32 lbl_8053CEA8;
extern "C" f32 lbl_8053CEB4;
extern "C" f32 lbl_8053CEB8;
extern "C" f32 lbl_8053CEBC;
extern "C" f32 lbl_8053CEC0;
extern "C" f32 lbl_8053CEAC;
extern "C" f32 lbl_8053CEB0;

extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" void fn_801F2B7C(void*, s32, s32, s32);
extern "C" void fn_801EEC98(void*, s32, s32, s32*, s32, s32*, s32, s32);
extern "C" s32 fn_80230CFC(s32);
extern "C" void fn_801EE8F4(void*, void*, s32, s32);
extern "C" u8* fn_8020D58C();
extern "C" void fn_8020D7D0(void*, s32);
extern "C" u8 fn_802265DC(void*, s32, s32);
extern "C" u16 fn_80226850(void*, s32);
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F7818(void*, u32, s32, void*, s32);
extern "C" s32 fn_80239558(void*, s32, s32);
extern "C" s32 fn_80239470(void*, s32, s32);
extern "C" u8 fn_800FE3EC(void*, s32, void*, s32);
extern "C" void fn_800FDEA0(void*, void*, void*, void*, void*, s32, f32);
extern "C" void* fn_801F8108(void*, u32, s32, f32);
extern "C" void* fn_801F666C(void*, void*);
extern "C" void fn_801BEDBC(void*);
extern f32 lbl_8053CEC4, lbl_8053CECC, lbl_8053CEE8;
extern JGeometry::TVec3f lbl_80465A98[4];
extern "C" void fn_80141064(u8* this_) {
    f32 pos[3];
    f32 box[6];
    u8 buf[0x1000];
    f32 d[4];

    d[0] = *(f32*)(this_ + 0x60);
    d[1] = *(f32*)(this_ + 0x64);
    d[2] = *(f32*)(this_ + 0x68);
    d[3] = *(f32*)(this_ + 0x6c);
    d[0] = d[0] + *(f32*)(this_ + 0x10);
    d[1] = d[1] + *(f32*)(this_ + 0xc);
    *(f32*)(buf + 0xb4) = d[1];
    if (fn_801F3D94(this_) != 0) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    (void)pos;
    (void)box;
}

extern f32 lbl_8053CEB8;
extern f32 lbl_8053CEF8;
extern f32 lbl_8053CEFC;
extern f32 lbl_8053CF00;
extern f32 lbl_8053CF04;
extern f32 lbl_8053CF08;
extern f32 lbl_8053CF0C;
extern f32 lbl_8053CF10;
extern f32 lbl_8053CF14;
extern f32 lbl_8053CF18;
extern f32 lbl_8053CF1C;
extern f32 lbl_8053CF20;
extern "C" void fn_80142224(u8* this_) {
    const f32 e = lbl_8053CF08;
    const f32 d = lbl_8053CF04;
    const f32 c = lbl_8053CF00;
    const f32 b = lbl_8053CEFC;
    const f32 a = lbl_8053CEF8;

    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = c;
    *(f32*)(this_ + 0x74) = d;
    *(f32*)(this_ + 0x78) = e;
    *(f32*)(this_ + 0x7c) = e;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(u32*)(this_ + 0x300) = 0;
    *(u32*)(this_ + 0x30c) = 0;
    *(u32*)(this_ + 0xb0) = 0xa040004;
    *(s32*)(this_ + 0x310) = -1;
    *(s32*)(this_ + 0x314) = -1;
    *(s32*)(this_ + 0x31c) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    if (*(s32*)(this_ + 0x31c) != 0) {
        *(f32*)(this_ + 0x60) = c;
        *(f32*)(this_ + 0x64) = c;
        *(f32*)(this_ + 0x68) = e;
        *(f32*)(this_ + 0x6c) = e;
        *(s32*)(this_ + 0xc0) = 3;
    }
    *(u16*)(this_ + 0x94) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x308) = (*(u32*)(this_ + 0x90) >> 8) & 0xff;
    *(s32*)(this_ + 0x318) = 1;
    *(s32*)(this_ + 0x304) = 0;
    *(s32*)(this_ + 0xbc) = 3;

    if (*(u16*)(this_ + 0x94) == 3 || (u16)(*(u16*)(this_ + 0x94) - 4) <= 1 || *(u16*)(this_ + 0x94) == 7) {
        *(s32*)(this_ + 0xc0) = 3;
        *(f32*)(this_ + 0x60) = lbl_8053CF0C;
        *(f32*)(this_ + 0x64) = lbl_8053CF10;
        *(f32*)(this_ + 0x68) = lbl_8053CF14;
        *(f32*)(this_ + 0x6c) = lbl_8053CF18;
        *(f32*)(this_ + 0x70) = d;
        *(f32*)(this_ + 0x74) = lbl_8053CF1C;
        *(f32*)(this_ + 0x78) = lbl_8053CF20;
        *(f32*)(this_ + 0x7c) = lbl_8053CEB8;
        *(f32*)(this_ + 0x80) = lbl_8053CF0C;
        *(f32*)(this_ + 0x84) = lbl_8053CF10;
        *(f32*)(this_ + 0x88) = lbl_8053CF14;
        *(f32*)(this_ + 0x8c) = lbl_8053CF18;
    }
    *(s32*)(this_ + 0x2f8) = 3;

    switch (*(u16*)(this_ + 0x94)) {
    case 1:
    case 4:
    case 6:
    case 7:
        *(u8*)(this_ + 0x196) = 1;
        *(u8*)(this_ + 0x1a8) = 0;
        return;
    case 5:
        *(u8*)(this_ + 0x196) = 1;
        *(u8*)(this_ + 0x1a8) = 0;
        *(s32*)(this_ + 0xb8) = 1;
        *(s32*)(this_ + 0x318) = 0;
        *(s32*)(this_ + 0x2f8) = 4;
        return;
    case 3:
        *(u8*)(this_ + 0x196) = 1;
    default:
        *(s32*)(this_ + 0xb8) = 1;
        *(s32*)(this_ + 0x2f8) = 0;
        return;
    }
}

