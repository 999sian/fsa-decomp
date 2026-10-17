#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80114f44-0x80115078 (2 functions). split_file divides it into the game's real files.

extern "C" s32 fn_80114F44(void* param_1, s32 (*param_2)(void*, void*), void* param_3) {
    s32 ret = 1;
    void* node = param_1;
    void* next = param_1 ? ((void**)param_1)[2] : 0;
    while (node != 0) {
        if (param_2(node, param_3) == 0) {
            ret = 0;
        }
        node = next;
        next = node ? ((void**)node)[2] : 0;
    }
    return ret;
}

extern "C" s32 fn_80114FE4(void* param_1, u32 (*param_2)(void*, void*), void* param_3) {
    void* node = param_1;
    void* next = param_1 ? ((void**)param_1)[2] : 0;
    u32 r;
    while (node != 0) {
        r = param_2(node, param_3);
        if (r != 0) {
            return r;
        }
        node = next;
        next = node ? ((void**)node)[2] : 0;
    }
    return 0;
}
