#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8010d1dc-0x80110794 (35 functions). split_file divides it into the game's real files.

extern void* lbl_8028F058[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8011074C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F058;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
