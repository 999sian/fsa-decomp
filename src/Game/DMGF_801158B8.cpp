#include "types.h"
#include "JSystem/JGeometry.h"
#include "std/math.h"

extern "C" char lbl_8049D940[];
extern f32 lbl_8053C6D0;
extern f32 lbl_8053C6DC;
extern f32 lbl_8053C6E0;
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" void fn_80115BC4(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* b);
extern "C" void fn_8023DFF4(s32 i, JGeometry::TVec3<f32>* pos);
extern "C" void fn_80230498(s32 i, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" void fn_801EB950(void*);
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void*);
extern "C" void dtor_801EB8CC(void*, s32);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" s32 fn_80115A7C(char* p) {
    f32 maxSq = lbl_8053C6D0;
    f32 maxDist = lbl_8053C6DC;
    JGeometry::TVec3<f32> a;
    JGeometry::TVec3<f32> b;
    for (s32 i = 0; i < 4; i++) {
        a = *fn_8023E724(i);
        fn_80115BC4(p, &a, &b);
        a += b;
        f32 dx = a.x - *(f32*)(p + 0xc);
        f32 dy = a.y - *(f32*)(p + 0x10);
        f32 d2 = dx * dx + dy * dy;
        if (d2 > maxSq) {
            if (std::sqrtf(d2) <= maxDist) {
                fn_80230498(i, &a, *(s32*)(p + 0x280) + 0x3b5, (s32)lbl_8053C6E0, -0x80, -0x80, 1);
            } else {
                fn_8023DFF4(i, &a);
            }
        }
    }
    fn_801D1C18(p + 0x270);
    return 1;
}

extern "C" s32 fn_801162B8(char* p) {
    switch (*(s32*)(p + 0x230)) {
    case 11:
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801162D8(char* p) {
    return *(s32*)(p + 0x230);
}

extern "C" void fn_801162E0(void* this_) {
    extern s32 lbl_804649A4[];
    extern void* fn_8011921C(void);
    extern void fn_80115F9C(void*, s32);

    if (*(s32*)((char*)fn_8011921C() + 4) == 2) {
        s32 v = *(s32*)((char*)fn_8011921C() + 8);
        if (v == lbl_804649A4[1]) {
            fn_80115F9C(this_, 1);
        } else if (v == lbl_804649A4[2]) {
            fn_80115F9C(this_, 2);
        } else if (v == lbl_804649A4[3]) {
            fn_80115F9C(this_, 3);
        } else if (v == lbl_804649A4[4]) {
            fn_80115F9C(this_, 4);
        } else if (v == lbl_804649A4[5]) {
            fn_80115F9C(this_, 5);
        } else if (v == lbl_804649A4[6]) {
            fn_80115F9C(this_, 6);
        } else if (v == lbl_804649A4[7]) {
            fn_80115F9C(this_, 7);
        } else if (v == lbl_804649A4[8]) {
            fn_80115F9C(this_, 8);
        } else if (v == lbl_804649A4[9]) {
            fn_80115F9C(this_, 9);
        } else if (v == lbl_804649A4[10]) {
            fn_80115F9C(this_, 10);
        } else if (v == lbl_804649A4[11]) {
            fn_80115F9C(this_, 11);
        }
    }
}

extern "C" char lbl_8049D930[];
extern "C" void fn_8010DF98(void*);
extern "C" s32 fn_804032E8(u32 tag, u32 id);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" s32 lbl_80539F08;
extern "C" char lbl_80464A14[];
extern void* lbl_8053AAF8;
extern f32 lbl_8053C704;
extern f32 lbl_8053C6D0;
extern "C" void fn_801169E8(char* p) {
    fn_8010DF98(p);
    u32* ids = (u32*)lbl_8049D930;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(p + 0x31c + i * 4) = fn_804032E8(0x54494D47, ids[i]);
    }
    void* obj = *(void**)((char*)lbl_8053AAF8 + 0xa4);
    *(s32*)(p + 0x32c) = ((s32 (**)(void*, u32, void*))(*(void**)obj))[6](obj, 0x3f3f3f3f, lbl_80464A14);
    *(f32*)(p + 0x14) = lbl_8053C704;
    *(f32*)(p + 0x3c) = *(f32*)(p + 0x40) = *(f32*)(p + 0x44) = lbl_8053C6D0;
    *(u8*)(p + 0x11d) = 0;
    fn_801D2608(p + 0x238, (void*)lbl_80539F08, 1);
    fn_801D22DC(p + 0x238, 0, 2, 0);
    fn_801D1F14(p + 0x238, lbl_8053C6D0);
    fn_801D2608(p + 0x270, (void*)lbl_80539F08, 1);
    fn_801D22DC(p + 0x270, 0, 2, 0);
    fn_801D1F14(p + 0x270, lbl_8053C6D0);
    *(JGeometry::TVec3<f32>*)(p + 0x308) = *(JGeometry::TVec3<f32>*)(p + 0xc);
}

extern "C" void* fn_80116B08(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_8049D940;
        *(s32*)(p + 0x31c) = 0;
        *(s32*)(p + 0x320) = 0;
        *(s32*)(p + 0x324) = 0;
        *(s32*)(p + 0x328) = 0;
        *(s32*)(p + 0x32c) = 0;
        fn_801EE434(*(void**)(p + 0x314));
        *(s32*)(p + 0x314) = 0;
        fn_801EE434(*(void**)(p + 0x318));
        *(s32*)(p + 0x318) = 0;
        dtor_801EB8CC(p + 0x2a8, -1);
        if (p + 0x270 != 0) {
            if (p + 0x294 != 0) {
                *(void**)(p + 0x294) = lbl_8049CC34;
            }
        }
        if (p + 0x238 != 0) {
            if (p + 0x25c != 0) {
                *(void**)(p + 0x25c) = lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_80116BE8(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049D940;
    *(s32*)(p + 0x230) = 0;
    *(u8*)(p + 0x234) = 0;
    fn_801D267C(p + 0x238);
    fn_801D267C(p + 0x270);
    fn_801EB950(p + 0x2a8);
    *(s32*)(p + 0x314) = 0;
    *(s32*)(p + 0x318) = 0;
    *(s32*)(p + 0x32c) = 0;
    *(s32*)(p + 0x31c) = 0;
    *(s32*)(p + 0x320) = 0;
    *(s32*)(p + 0x324) = 0;
    *(s32*)(p + 0x328) = 0;
    return p;
}

