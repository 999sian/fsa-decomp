#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80041c10-0x8004dcf8 (82 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80041C10(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}
