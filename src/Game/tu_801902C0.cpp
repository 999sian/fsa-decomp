#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void* lbl_8053AAF8;
extern "C" void fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void);
extern "C" u8 fn_80239D38(void);
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_8053AEC8[];

extern "C" void* fn_801902C0(void) {
    return *(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x20);
}

extern "C" void fn_801914C4(u8* p) {
    bool f = false;
    u8* g = (u8*)lbl_8053AAF8;
    if (g[0x7f] != 0) {
        switch (*(s32*)(g + 0x4c)) {
        case 7:
        case 8:
        case 9:
        case 0x16:
        case 0xa:
        case 0xb:
            f = true;
            break;
        }
    } else {
        switch (*(s32*)(g + 0x4c)) {
        case 7:
        case 8:
        case 9:
        case 0x16:
        case 0xa:
        case 0xb:
        case 0xc:
            f = true;
            break;
        }
    }
    if (f) {
        fn_802D6A9C();
        if (fn_802DCD0C()) {
            goto end;
        }
    }
    g = (u8*)lbl_8053AAF8;
    if (g[0x94] != 0 || g[0x96] != 0) {
        goto end;
    }
    if (g[0x7f] != 0) {
        bool b;
        if (fn_80239D38()) {
            goto end;
        }
        g = (u8*)lbl_8053AAF8;
        if (*(s32*)(g + 0x4c) == 0xb) {
            b = true;
        } else {
            b = (g[0x88] == 2);
        }
        if (b) {
            goto end;
        }
    }
    if (lbl_80529DEC[0x240] == 0 && lbl_8053AEC8[0x5d] == 0) {
        p[0x64] = 0;
        p[0xc4] = 0;
        p[0x124] = 0;
        p[0x184] = 0;
        p[0x1e4] = 0;
        p[0x244] = 0;
        p[0x2a4] = 0;
        p[0x2c0] = 0;
        p[0x2dc] = 0;
        p[0x2fc] = 0;
        p[0x31c] = 0;
        p[0x33c] = 0;
        *(s32*)(p + 0x4a8) = 0;
        *(s32*)(p + 0x5ec) = 0;
        *(s32*)(p + 0x618) = 0;
        *(s32*)(p + 0x79c) = 0;
        p[0x7a8] = 0;
        p[0x7c0] = 0;
        p[0x7ec] = 0;
    }
end:
    *(s32*)(p + 4) = *(s32*)(p + 4) + 1;
}

extern "C" f32 lbl_8053E218;
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void fn_8019169C(u8* param_1) {
    f32 fzero = lbl_8053E218;
    *(u8*)(param_1 + 0x64) = 0;
    *(f32*)(param_1 + 0x50) = fzero;
    *(s32*)(param_1 + 0x58) = 0;
    *(u8*)(param_1 + 0xc4) = 0;
    *(f32*)(param_1 + 0xb0) = fzero;
    *(s32*)(param_1 + 0xb8) = 0;
    *(u8*)(param_1 + 0x124) = 0;
    *(f32*)(param_1 + 0x110) = fzero;
    *(s32*)(param_1 + 0x118) = 0;
    *(u8*)(param_1 + 0x184) = 0;
    *(f32*)(param_1 + 0x170) = fzero;
    *(s32*)(param_1 + 0x178) = 0;
    *(u8*)(param_1 + 0x1e4) = 0;
    *(f32*)(param_1 + 0x1d0) = fzero;
    *(s32*)(param_1 + 0x1d8) = 0;
    *(u8*)(param_1 + 0x244) = 0;
    *(f32*)(param_1 + 0x230) = fzero;
    *(s32*)(param_1 + 0x238) = 0;
    *(u8*)(param_1 + 0x2a4) = 0;
    *(f32*)(param_1 + 0x290) = fzero;
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
            void** vt = *(void***)((u8*)obj + 8);
            ((void (*)(void*, int))vt[12])(obj, 1);
        }
        obj = param_1[0x1ee];
        if (obj != NULL) {
            void** vt = *(void***)((u8*)obj + 8);
            ((void (*)(void*, int))vt[12])(obj, 1);
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

