#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80111cdc-0x80114664 (28 functions). split_file divides it into the game's real files.

extern void* lbl_8028F648[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80111E64(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80111EE0(void);
extern "C" void fn_80111EA0(void) {
    fn_80111EE0();
}

extern "C" void fn_80111FE0(void);
extern "C" void fn_80111EC0(void) {
    fn_80111FE0();
}

extern "C" void fn_8011217C(void);
extern "C" void fn_80114118(void) {
    fn_8011217C();
}

extern "C" void fn_801123B4(void);
extern "C" void fn_801143FC(void) {
    fn_801123B4();
}

extern "C" BOOL fn_8011441C(void);
extern "C" BOOL fn_8011441C(void)
{
    return TRUE;
}

extern "C" void fn_801145CC(f32* out, u8* obj) {
    out[0] = *(f32*)(obj + 0x414);
    out[1] = *(f32*)(obj + 0x418);
    out[2] = *(f32*)(obj + 0x41c);
}

extern u8 lbl_8028F1E0[];
extern u8 lbl_80301398;
extern "C" void fn_801145E8(void* out, s32 idx) {
    u8* tbl = &lbl_80301398;
    s32 off = tbl[idx] * 0x18;
    u32* src = (u32*)(lbl_8028F1E0 + off);
    u32* dst = (u32*)out;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

extern "C" void* fn_8011461C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F648;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
