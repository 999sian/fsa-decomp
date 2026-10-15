#include "types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004ef64-0x8004f7c4 (19 functions). split_file divides it into the game's real files.

extern void* lbl_8024745C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004F154(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024745C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247430[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004F19C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247430;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247404[];
extern "C" void* fn_8004F1E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247404;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

