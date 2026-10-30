#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008729c-0x800872f8 (1 functions). split_file divides it into the game's real files.

extern void* lbl_80283C78[];
extern u8 lbl_802C5364[];
extern u8 lbl_802C5358[];
extern "C" void* fn_80087254(void* ptr, s16 param_2);
extern "C" void __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_8008729C(void) {
    *(void**)lbl_802C5364 = lbl_80283C78;
    *(s8*)(lbl_802C5364 + 4) = -1;
    *(s32*)(lbl_802C5364 + 8) = 0;
    lbl_802C5364[14] = 0;
    *(u16*)(lbl_802C5364 + 12) = 0x2000;
    __register_global_object(lbl_802C5364, (void*)fn_80087254, lbl_802C5358);
}
