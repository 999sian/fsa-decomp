#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8007bcd0-0x80080620 (44 functions). split_file divides it into the game's real files.

extern void* lbl_80283014[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8007BF20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283014;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_8007C494(void);
extern "C" BOOL fn_8007C494(void)
{
    return TRUE;
}

extern "C" void fn_8007C698(void);
extern "C" void fn_8007C5E4(void) {
    fn_8007C698();
}

extern "C" void fn_8007C604(void);
extern "C" void fn_80080430(void) {
    fn_8007C604();
}

extern "C" void fn_8007FD34(void);
extern "C" void fn_80080564(void) {
    fn_8007FD34();
}

extern "C" void fn_8007CFC4(void);
extern "C" void fn_80080584(void) {
    fn_8007CFC4();
}

extern "C" BOOL fn_800805A4(void);
extern "C" BOOL fn_800805A4(void)
{
    return TRUE;
}

extern void* lbl_80282FE8[];
extern void* lbl_80281904[];
extern "C" void* fn_800805AC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80282FE8;
        if ((s32)param_1 + 0x38 != 0) {
            *(void**)((char*)param_1 + 0x38) = lbl_80283014;
        }
        if ((s32)param_1 + 0xc != 0) {
            *(void**)((char*)param_1 + 0xc) = lbl_80281904;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

