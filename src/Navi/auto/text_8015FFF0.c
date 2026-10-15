#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015fff0-0x80164978 (90 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8015FC80(void*, int);
extern char lbl_80297CE8[];
extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_8015FFF0(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80160CDC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297CE8;
        fn_8015FC80(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8015D0B8(void*, int);
extern char lbl_80297E68[];
extern "C" void* fn_80162A70(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297E68;
        fn_8015D0B8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

