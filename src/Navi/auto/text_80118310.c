#include "types.h"
#include "types.h"
#include <cstring>

extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_80118B58(void*, int, int);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80118310-0x8011c4b8 (86 functions). split_file divides it into the game's real files.

extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_80118B58(void*, int, int);
extern "C" void* fn_80118310(void* param_1, s16 param_2) {
    if (!param_1) return param_1;
    fn_80166C08(param_1, 0);
    if (param_2 > 0) {
        fn_8015AB1C(param_1);
    }
    return param_1;
}

extern "C" void fn_80118364(void* param_1) {
    *(float*)((char*)param_1 + 0x54) = 1.0f;
    *(float*)((char*)param_1 + 0x58) = 100000.0f;
}

extern "C" void fn_801189FC(void* param_1, int param_2, int param_3, int param_4) {
    char* p1 = (char*)param_1;
    fn_801670D0(param_2, p1, 1);
    fn_801670D0(param_2, p1 + 1, 1);
    fn_801670D0(param_2, p1 + 2, p1[1]);
    
    if (p1[0] == 2 || p1[0] == 3 || p1[0] == 4) {
        p1[p1[1] + 2] = 0;
    }
    fn_80118B58(p1, param_3, param_4);
}

