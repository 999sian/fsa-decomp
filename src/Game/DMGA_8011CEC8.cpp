#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern char lbl_8049DD68[];
extern char lbl_8049CC34[];
extern "C" void __dt__13Base_8010E074Fv(void* p, s32 n);
extern "C" char* fn_8011CEC8(char* p, s16 n) {
    if (p != 0) {
        *(char**)p = lbl_8049DD68;
        if (p + 0x274 != 0 && p + 0x298 != 0) {
            *(char**)(p + 0x298) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" u8 fn_8011D4B4(int param_1) {
    return *(int*)(param_1 + 0x234) == 9;
}

extern "C" s32 fn_8011D4C8(char* p) {
    return *(s32*)(p + 0x234);
}

extern s32 lbl_80464BBC[];
extern "C" void* fn_8011921C(void);
extern "C" void fn_8011D1B8(void* p, s32 n);
extern "C" void fn_8011D4D0(void* param_1) {
    if (*(s32*)((char*)fn_8011921C() + 4) == 0x11) {
        s32 v = *(s32*)((char*)fn_8011921C() + 8);
        if (v == lbl_80464BBC[2]) {
            fn_8011D1B8(param_1, 2);
        } else if (v == lbl_80464BBC[3]) {
            fn_8011D1B8(param_1, 3);
        } else if (v == lbl_80464BBC[4]) {
            fn_8011D1B8(param_1, 4);
        } else if (v == lbl_80464BBC[5]) {
            fn_8011D1B8(param_1, 5);
        } else if (v == lbl_80464BBC[6]) {
            fn_8011D1B8(param_1, 6);
        } else if (v == lbl_80464BBC[7]) {
            fn_8011D1B8(param_1, 7);
        } else if (v == lbl_80464BBC[8]) {
            fn_8011D1B8(param_1, 8);
        } else if (v == lbl_80464BBC[9]) {
            fn_8011D1B8(param_1, 9);
        }
    }
}

extern "C" void fn_8010DF58(void);
extern "C" void fn_8010DF98(void);
extern "C" void fn_801D2608(void* p, void* a, s32 b);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, u32 a);
extern "C" void fn_8011D5F4(void) {
    fn_8010DF58();
}

extern char lbl_80539F20;
extern "C" void fn_8011D77C(int param_1) {
    fn_8010DF98();
    fn_801D2608((void*)(param_1 + 0x274), &lbl_80539F20, 1);
    fn_801D22DC((void*)(param_1 + 0x274), 0, 2, 0);
    ((void (*)(void*, f32))fn_801D1F14)((void*)(param_1 + 0x274), 0.0f);
    *(JGeometry::TVec3f*)(param_1 + 0x240) = *(JGeometry::TVec3f*)(param_1 + 0xc);
    *(f32*)(param_1 + 0x258) = 284.0f;
    fn_802D7440(fn_802D6A9C(), 0);
}

