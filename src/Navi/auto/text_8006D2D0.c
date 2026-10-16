#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006d2d0-0x8006f1b4 (29 functions). split_file divides it into the game's real files.

extern void* lbl_80280910[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8006D320(void);
extern void* lbl_802473D8[];
extern "C" void fn_8006D2D0(void* p);
extern "C" void fn_8006D2D0(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_802473D8;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void fn_8006D300(void) {
    fn_8006D320();
}

extern u8 lbl_802FC990;
extern "C" void fn_800636F4(void*, void*, s32);
extern char lbl_802B7CA0[];
extern "C" int fn_8006D760(void)
{
    fn_800636F4(&lbl_802FC990, lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern "C" BOOL fn_8006D9C0(void);
extern "C" BOOL fn_8006D9C0(void)
{
    return TRUE;
}

extern "C" void fn_8006DAD4(void);
extern "C" void fn_8006D9C8(void) {
    fn_8006DAD4();
}

extern "C" void fn_8006D9E8(void);
extern "C" void fn_8006EA60(void) {
    fn_8006D9E8();
}

extern "C" void fn_8006DEC4(void);
extern "C" void fn_8006EC94(void) {
    fn_8006DEC4();
}

extern "C" BOOL fn_8006ECB4(void);
extern "C" BOOL fn_8006ECB4(void)
{
    return TRUE;
}

extern "C" void* fn_8006F16C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80280910;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
