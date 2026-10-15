#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011093c-0x80111bac (17 functions). split_file divides it into the game's real files.

extern void* lbl_8028F1BC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80111B64(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F1BC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
