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

