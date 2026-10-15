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
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80118364(void* param_1) {
    *(float*)((char*)param_1 + 0x54) = 1.0f;
    *(float*)((char*)param_1 + 0x58) = 100000.0f;
}

extern "C" void fn_801189FC(char *param_1, int param_2, int param_3, int param_4) {
    fn_801670D0(param_2, param_1, 1);
    fn_801670D0(param_2, param_1 + 1, 1);
    fn_801670D0(param_2, param_1 + 2, (u32)(u8)param_1[1]);
    
    u8 b0 = (u8)param_1[0];
    if ((unsigned)b0 == 2 || (unsigned)b0 == 3 || (unsigned)b0 == 4) {
        register u8 b1 = (u8)param_1[1];
        param_1[b1 + 2] = 0;
    }
    fn_80118B58(param_1, param_3, param_4);
}

extern "C" void fn_80118AB4(char *param_1, char *param_2, int param_3, int param_4) {
    u8 byte1 = (u8)param_2[1];
    u8 byte0 = (u8)param_2[0];
    param_1[0] = (char)byte0;
    param_1[1] = (char)byte1;
    
    u8 stored_byte1 = (u8)param_1[1];
    if (stored_byte1 != 0) {
        memcpy(param_1 + 2, param_2 + 2, stored_byte1);
    }
    
    u8 stored_byte0 = (u8)param_1[0];
    if (stored_byte0 == 2 || stored_byte0 == 3 || stored_byte0 == 4) {
        u8 b1 = (u8)param_1[1];
        param_1[b1 + 2] = 0;
    }
    fn_80118B58(param_1, param_3, param_4);
}

