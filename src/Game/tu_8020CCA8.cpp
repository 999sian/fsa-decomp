#include "types.h"
#include "JSystem/JGeometry.h"
#include "Game/SinitPoolChain.h"

extern "C" const f32 lbl_8053FA0C;
extern "C" u16 fn_8022461C(void* p, u32 b);
extern "C" u8 fn_801CD2F8(u32 o);
extern "C" u8 fn_802DEB58();
extern "C" void fn_801F0E34(void* a, u32 code, u32 z);


extern "C" u8* fn_8013CC50(f32 scale, u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" bool fn_801E1D9C();
extern "C" u8 fn_801E1D7C(u8* o);
extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);
extern "C" void fn_801EF574(u8* a, s32 b, f32* v, u8* rec);
extern "C" void fn_801CD0D0(f32* a, f32* b);
extern "C" void fn_802F86CC(void* a, void* b, void* c, u32 d, f32 e, f32 f, void* g);
extern "C" int __float_epsilon[];
struct CCA8Loc {
    u8 idx[16];
    s32 a;
    s32 b;
    f32* c;
    u8 d[11];
    s32 e;
    u8 f;
    u8 g;
    u8 h;
    s32 i;
    s32 j;
    s32 k;
};
struct CCA8ResMgr {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void* get(u32 type, void* name);
};
extern "C" void fn_803075AC(u32 x, u32 y, void* v, void* p, int sign, int two, int minus1, u8 p7, u32 u, int zero);
extern "C" u8 lbl_8046A3C0[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" const f32 lbl_8053FA00;
extern "C" const f32 lbl_8053FA04;
extern "C" const f32 lbl_8053FA08;
extern "C" const f32 lbl_8053FA10;
extern "C" const f32 lbl_8053FA14;
extern "C" void fn_8020CF7C(u8* o) {
    u8* pos = o + 0xc;
    fn_8013CC50(lbl_8053FA08, *(u32*)(o + 4), pos, 0x48d, 0, 0, 0, 0, 1);
}

extern "C" void fn_8020CFC4(u8* o) {
    u16 r = fn_8022461C(o + 0xc, *(u32*)(o + 4));
    switch (r) {
    case 0xd:
        fn_8013CC50(lbl_8053FA0C, *(u32*)(o + 4), o + 0xc, 0x3d0, 0, 1, 0, 0, 1);
        fn_8013CC50(lbl_8053FA08, *(u32*)(o + 4), o + 0xc, 0x15b, 0, 1, 0, 0, 1);
        fn_8013CC50(lbl_8053FA08, *(u32*)(o + 4), o + 0xc, 0x15c, -1, 0, 0, 0, 1);
        fn_801F0E34(o, 0x30022, 0);
        break;
    case 0xe:
        if (fn_801CD2F8(*(u32*)(o + 4))) {
            fn_801F0E34(o, 0x4003e, 0);
        } else {
            fn_8013CC50(lbl_8053FA08, *(u32*)(o + 4), o + 0xc, 0x2a9, -1, 0, 0, 0, 1);
            fn_8013CC50(lbl_8053FA08, *(u32*)(o + 4), o + 0xc, 0x2aa, 0, 1, 0, 0, 1);
            if (fn_802DEB58()) {
                fn_801F0E34(o, 0x30022, 0);
            } else {
                fn_801F0E34(o, 0x5005f, 0);
            }
        }
        break;
    default:
        fn_801F0E34(o, 0x4003e, 0);
        break;
    }
}

extern const f32 lbl_8053FA08;
extern "C" u16 fn_8022461C(void* p, u32 b);
extern "C" u8 fn_80224B88(void* p, u32 b);
extern "C" u8 fn_8022517C(void* p, u32 b);
extern "C" u8 fn_80224E88(void* p, u32 b);
extern "C" void fn_801F0E34(void* a, u32 code, u32 z);
extern "C" void fn_8020D16C(u8* a) {
    u32 id = *(u32*)(a + 4);
    if (fn_8022461C(a + 0xc, id) == 0x39) {
        fn_8013CC50(lbl_8053FA08, id, a + 0xc, 0x15b, 0, 1, 0, 0, 1);
        fn_8013CC50(lbl_8053FA08, id, a + 0xc, 0x15c, -1, 0, 0, 0, 1);
        fn_801F0E34(a, 0x400e0, 0);
    } else if (fn_80224B88(a + 0xc, id) & 0xff) {
        fn_801F0E34(a, 0x400e1, 0);
    } else if (fn_8022517C(a + 0xc, id) & 0xff) {
        fn_801F0E34(a, 0x400df, 0);
    } else if (fn_80224E88(a + 0xc, id) & 0xff) {
        fn_801F0E34(a, 0x50071, 0);
    } else {
        fn_801F0E34(a, 0x4004f, 0);
    }
}

extern "C" void fn_8020D2AC(u8* o) {
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(o + 0xc));
    pos.y -= lbl_8053FA10;
    if (!fn_801E1D9C()) {
        switch (*(s32*)(o + 0x98)) {
        case 0:
            pos.x += lbl_8053FA14;
            break;
        case 1:
            pos.x -= lbl_8053FA14;
            break;
        }
    }
    fn_8013CC50(lbl_8053FA08, *(u32*)(o + 4), &pos, 0x33a, 0, 1, 0, 0, 1);
}



