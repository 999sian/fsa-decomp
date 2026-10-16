#include "types.h"

extern "C" void* lbl_8053AAF8;
extern "C" void* fn_801902C0(void) {
    return *(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x20);
}

extern "C" f32 lbl_8053E218;
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void fn_8019169C(u8* param_1) {
    *(u8*)(param_1 + 0x64) = 0;
    *(f32*)(param_1 + 0x50) = lbl_8053E218;
    *(s32*)(param_1 + 0x58) = 0;
    *(u8*)(param_1 + 0xc4) = 0;
    *(f32*)(param_1 + 0xb0) = lbl_8053E218;
    *(s32*)(param_1 + 0xb8) = 0;
    *(u8*)(param_1 + 0x124) = 0;
    *(f32*)(param_1 + 0x110) = lbl_8053E218;
    *(s32*)(param_1 + 0x118) = 0;
    *(u8*)(param_1 + 0x184) = 0;
    *(f32*)(param_1 + 0x170) = lbl_8053E218;
    *(s32*)(param_1 + 0x178) = 0;
    *(u8*)(param_1 + 0x1e4) = 0;
    *(f32*)(param_1 + 0x1d0) = lbl_8053E218;
    *(s32*)(param_1 + 0x1d8) = 0;
    *(u8*)(param_1 + 0x244) = 0;
    *(f32*)(param_1 + 0x230) = lbl_8053E218;
    *(s32*)(param_1 + 0x238) = 0;
    *(u8*)(param_1 + 0x2a4) = 0;
    *(f32*)(param_1 + 0x290) = lbl_8053E218;
    *(s32*)(param_1 + 0x298) = 0;
    *(u8*)(param_1 + 0x2c0) = 0;
    *(u8*)(param_1 + 0x2dc) = 0;
    *(u8*)(param_1 + 0x2fc) = 0;
    *(u8*)(param_1 + 0x31c) = 0;
    *(u8*)(param_1 + 0x33c) = 0;
    *(s32*)(param_1 + 0x338) = 0;
    *(s32*)(param_1 + 0x4a8) = 0;
    *(s32*)(param_1 + 0x5ec) = 0;
    *(s32*)(param_1 + 0x618) = 0;
    *(s32*)(param_1 + 0x79c) = 0;
    *(u8*)(param_1 + 0x7a8) = 0;
    *(s32*)(param_1 + 0x7a4) = 300;
    *(s32*)(param_1 + 0x7a0) = 0;
    *(u8*)(param_1 + 0x7c0) = 0;
    *(s32*)(param_1 + 0x7bc) = 0;
    *(u8*)(param_1 + 0x7ec) = 0;
    *(s32*)(param_1 + 4) = 0;
}

extern "C" void** fn_80191744(void** param_1, s16 param_2) {
    if (param_1 != NULL) {
        void* obj = param_1[499];
        if (obj != NULL) {
            ((void (*)(void*, int))((void**)(*(void***)obj))[12])(obj, 1);
        }
        obj = param_1[0x1ee];
        if (obj != NULL) {
            ((void (*)(void*, int))((void**)(*(void***)obj))[12])(obj, 1);
        }
        destroy__7JKRHeapFv(*param_1);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80191E00(void) {}

extern "C" void fn_80191E04(void) {}

extern "C" void fn_80191E08(void) {}

extern "C" void fn_80191E0C(void) {}

extern "C" void fn_80191E10(void) {}

