#include "types.h"

extern "C" f32 lbl_8053F0BC;
extern "C" f32 lbl_8053F510;
extern "C" f32 lbl_8053F554;
extern "C" f32 lbl_8053F558;
extern "C" f32 lbl_8053F55C;
extern "C" f32 lbl_8053F560;

extern "C" f32 lbl_8053F530;
extern "C" f32 lbl_8053F514;
extern "C" f32 lbl_8053F518;
extern "C" f32 lbl_8053F51C;
extern "C" f32 lbl_8053F520;
extern "C" f32 lbl_8053F524;
extern "C" f64 lbl_8053F528;
extern "C" char* fn_802D6A9C();
extern "C" u8 fn_801CD2F8(void* obj);
extern "C" s32 fn_801F2B7C(u8* p, s32 a, s32 b, s32 c);
extern "C" s32 fn_801E3A4C(u8* p) {
    s32 ret = 0;
    s32 state = *(s32*)(p + 0x248);
    u8 ok = 1;
    if (state < 9) {
        if (state != 5 && (state >= 5 || state >= 0)) {
            ok = 0;
        }
    } else if (state < 0x1b) {
        if (state >= 0x15) {
            ok = 0;
        }
    }
    if (ok && (*(u32*)(p + 0x230) & 0x2000) && fn_801CD2F8(*(void**)(p + 4))) {
        if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F530 &&
            *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F530) {
            ret = fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 1);
        }
    }
    return ret;
}

extern "C" void fn_801E4758(u8* p) {
    f32 a = lbl_8053F554 * lbl_8053F0BC;
    f32 b = lbl_8053F558 * lbl_8053F0BC;
    f32 c = lbl_8053F510 * lbl_8053F0BC;
    f32 d = lbl_8053F55C * lbl_8053F0BC;

    *(f32*)(p + 0x80) = a;
    *(f32*)(p + 0x84) = b;
    *(f32*)(p + 0x88) = c;
    *(f32*)(p + 0x8c) = d;
}

extern "C" void fn_801E4790(u8* p, u8 flag) {
    f32 s = lbl_8053F0BC;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    if (flag) {
        s = lbl_8053F560;
    }
    a = lbl_8053F554 * s;
    b = lbl_8053F558 * s;
    c = lbl_8053F510 * s;
    d = lbl_8053F55C * s;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = b;
    *(f32*)(p + 0x68) = c;
    *(f32*)(p + 0x6c) = d;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
}

