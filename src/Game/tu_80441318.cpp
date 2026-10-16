#include "Game/Actor.h"
#include "types.h"


extern "C" char lbl_804B19E0[];
extern "C" void fn_802D6A9C(void);
extern "C" u8 fn_802D39CC(void);
extern "C" int fn_80231A50(void);
extern "C" s32 fn_8022F340(s32 p);
extern "C" u8* sManager__8JUTVideo;
extern "C" u8* lbl_8053AB10;
extern "C" void fn_80441318(u8* param_1) {
    s32 r = fn_80231A50();
    if (r < 0) {
        s32 n = *(s32*)(param_1 + 8);
        if (n < 3) {
            *(s32*)(param_1 + 8) = n + 1;
        } else {
            *(s32*)(param_1 + 4) = r;
        }
    } else {
        *(s32*)(param_1 + 4) = fn_8022F340(r);
        *(s32*)(param_1 + 8) = 0;
    }
    s32 v = *(s32*)(param_1 + 4);
    if (v >= 0) {
        u8* mode = *(u8**)(*(u8**)sManager__8JUTVideo + 4);
        u8* obj = *(u8**)(lbl_8053AB10 + 0x20);
        u16 w = *(u16*)(mode + 4);
        u16 h = *(u16*)(mode + 6);
        *(s32*)(obj + 0x22c) = v;
        *(s32*)(obj + 0x238) = (w - 0x16d) / 2;
        *(s32*)(obj + 0x23c) = (h - 0x105) / 2;
        *(s32*)(obj + 0x240) = 0x16d;
        *(s32*)(obj + 0x244) = 0x105;
        *(s32*)(obj + 0x234) = 0;
    } else {
        param_1[0xe] = 1;
    }
}

extern "C" void fn_804413F0(u8* param_1) {
    u16 n = *(u16*)(param_1 + 0xc);
    if (n < 300) {
        *(u16*)(param_1 + 0xc) = n + 1;
    } else if (fn_80231A50() >= 0) {
        param_1[0xe] = 2;
    }
}

extern "C" void fn_80441444(u8* param_1) {
    fn_802D6A9C();
    if (fn_802D39CC() == 0) {
        param_1[0xe] = 1;
        *(u16*)(param_1 + 0xc) = 0;
    }
}

extern "C" void fn_8044148C(void) {
}

extern "C" void fn_8044172C(void) {
}

extern "C" u8* fn_80441730(u8* param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B19E0;
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80441778(void* p) {
    *(void**)p = lbl_804B19E0;
    *(s16*)((u8*)p + 0xc) = 0;
    *(u8*)((u8*)p + 0xe) = 0;
    *(u8*)((u8*)p + 0xf) = 0;
    *(s32*)((u8*)p + 0x4) = -1;
    *(s32*)((u8*)p + 0x8) = 0;
}
