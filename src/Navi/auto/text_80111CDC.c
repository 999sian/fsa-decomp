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

extern "C" void* fn_8011461C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F648;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
