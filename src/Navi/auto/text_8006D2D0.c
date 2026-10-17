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

extern "C" void fn_80041268(void*, void*, s32);
extern "C" void fn_8000E0F0(void*, void*, f32);
extern "C" void fn_8000EBB8(void*);
extern "C" void fn_80115914(f32*, void*);
extern "C" void fn_801C61AC(void*, f32, f32, f32);
extern "C" void fn_8000C950(void*, s32, s32, s32);
extern "C" void fn_801C5D74(void*, void*);
extern "C" BOOL fn_801E10A0(void*);
extern "C" BOOL fn_801E1070(void*);
extern "C" void fn_801E10DC(void*, void*);
extern u8 lbl_8029F8D8[];
extern f32 lbl_802BF784[];
extern "C" BOOL fn_8006D5A8(char* p) {
    if (p[0x26c] == 0) {
        p[0x26c]++;
    }
    return TRUE;
}

extern u8 lbl_802FC990;
extern "C" void fn_800636F4(void*, void*, s32);
extern char lbl_802B7CA0[];
extern "C" int fn_8006D760(void)
{
    fn_800636F4(&lbl_802FC990, lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern "C" BOOL fn_8006D93C(u8* p) {
    fn_80041268(*(void**)(p + 0x24c), p + 0x180, 5);
    fn_8000E0F0(p + 0x254, *(u8**)(*(u8**)(p + 0x24c) + 4) + 0x58, *(f32*)(*(u8**)(p + 0x258) + 0x10));
    fn_8000EBB8(*(void**)(p + 0x24c));
    fn_8000E0F0(p + 0x260, *(u8**)(*(u8**)(p + 0x250) + 4) + 0x58, *(f32*)(*(u8**)(p + 0x264) + 0x10));
    fn_8000EBB8(*(void**)(p + 0x250));
    return TRUE;
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
