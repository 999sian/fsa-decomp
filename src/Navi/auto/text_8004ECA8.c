#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004eca8-0x8004ed60 (2 functions). split_file divides it into the game's real files.

extern void* lbl_80247308[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004ECA8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247308;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
