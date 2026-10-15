#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80086930-0x8008729c (9 functions). split_file divides it into the game's real files.

extern void* lbl_80283C78[];
extern u8 lbl_802B7CA0[];
extern u8 lbl_80283B28[];
extern u8 lbl_8029FDB4[];
extern u8 lbl_802C5364[];
extern f32 lbl_803009B0;
extern "C" void fn_800636F4(void*, void*, s32);
extern "C" void* fn_800638A4(void*, void*, s32);
extern "C" void fn_800127A0(void*);
extern "C" s32 fn_8000E124(void*, void*, void*, s32, s32, s32, s32, f32);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80086950(void);
extern "C" void fn_80086930(void) {
    fn_80086950();
}

extern "C" BOOL fn_8008724C()
{
	return TRUE;
}

extern "C" void* fn_80087254(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283C78;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
