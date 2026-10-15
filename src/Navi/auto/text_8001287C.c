#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8001287c-0x80013a30 (29 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80012970(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" char lbl_80204E88[];
extern "C" void* fn_80012E08(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

