#include "types.h"

extern "C" void fn_8015D29C(void* p, s32 a);
extern "C" void* fn_8015A9A8(s32 size, void* vtbl, s32 a);
extern "C" void* fn_8015DD38(void* p, void* a, void* b, s32 c);
extern "C" void fn_8015F67C(void* p);
extern "C" void fn_80166478(void* p);
extern "C" void fn_801C0EEC(void* p);
extern "C" void* lbl_802FF540;
extern "C" void* lbl_802FF5A0;
extern "C" char lbl_80297A5C[];

typedef void (*VirtualMethod0)(void*, s16);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015dbf4-0x8015ea78 (12 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
typedef void (*VirtualMethod0)(void*, s16);
extern "C" void* fn_8015DBF4(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_8015DC48(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

