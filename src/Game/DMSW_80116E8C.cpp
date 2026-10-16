#include "types.h"

extern "C" char lbl_8049DA0C[];
extern "C" char lbl_8049CC34[];
extern "C" f32 lbl_8053C75C;
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" s32 fn_80117498(char* p) {
    switch (*(s32*)(p + 0x234)) {
    case 12:
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801174B8(char* p) {
    return *(s32*)(p + 0x234);
}

extern s32 lbl_80464A7C[];
extern "C" void* fn_8011921C(void);
extern "C" void fn_80117074(void* p, s32 n);
extern "C" void fn_801174C0(void* param_1) {
    if (*(s32*)((char*)fn_8011921C() + 4) == 2) {
        s32 v = *(s32*)((char*)fn_8011921C() + 8);
        if (v == lbl_80464A7C[2]) {
            fn_80117074(param_1, 2);
        } else if (v == lbl_80464A7C[3]) {
            fn_80117074(param_1, 3);
        } else if (v == lbl_80464A7C[4]) {
            fn_80117074(param_1, 4);
        } else if (v == lbl_80464A7C[5]) {
            fn_80117074(param_1, 5);
        } else if (v == lbl_80464A7C[7]) {
            fn_80117074(param_1, 7);
        } else if (v == lbl_80464A7C[8]) {
            fn_80117074(param_1, 8);
        } else if (v == lbl_80464A7C[9]) {
            fn_80117074(param_1, 9);
        } else if (v == lbl_80464A7C[11]) {
            fn_80117074(param_1, 11);
        } else if (v == lbl_80464A7C[12]) {
            fn_80117074(param_1, 12);
        }
    }
}

extern "C" void fn_8010DF98(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" char lbl_8049DA00[];
extern "C" f32 lbl_8053C750;
extern "C" f32 lbl_8053C754;
extern "C" void fn_80117F34(char* p) {
    struct Box4 {
        f32 a, b, c, d;
    };
    f32 pos[3];

    fn_8010DF98(p);
    fn_801D2608(p + 0x250, lbl_8049DA00, 3);
    fn_801D22DC(p + 0x250, 0, 2, 0);
    fn_801D1F14(p + 0x250, lbl_8053C75C);
    Box4 box = *(Box4*)((char*)fn_802D6A9C() + 0xCC);
    pos[0] = (box.a - box.c) * lbl_8053C750 + box.c;
    pos[1] = (box.b - box.d) * lbl_8053C750 + box.d;
    pos[2] = lbl_8053C75C;
    *(void**)(p + 0x2a8) = fn_8013CC50(*(s32*)(p + 4), pos, 0x33e, 0, 0, 0, 0, 1, lbl_8053C754);
}

extern "C" void* fn_80118018(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_8049DA0C;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x288 + i * 4));
            *(void**)(p + 0x288 + i * 4) = 0;
            fn_801EE434(*(void**)(p + 0x298 + i * 4));
            *(void**)(p + 0x298 + i * 4) = 0;
            fn_801EE434(*(void**)(p + 0x2a8));
            *(void**)(p + 0x2a8) = 0;
        }
        if (p + 0x250 != 0 && p + 0x274 != 0) {
            *(void**)(p + 0x274) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_801180D0(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049DA0C;
    f32 f = lbl_8053C75C;
    *(u8*)(p + 0x230) = 0;
    *(u8*)(p + 0x231) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = -1;
    *(f32*)(p + 0x23c) = f;
    *(f32*)(p + 0x240) = f;
    fn_801D267C(p + 0x250);
    *(s32*)(p + 0x2a8) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(p + 0x288 + i * 4) = 0;
        *(s32*)(p + 0x298 + i * 4) = 0;
    }
    return p;
}

