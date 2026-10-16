#include "types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013e314-0x8013eb20 (13 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_80293738[];
extern "C" void* fn_8013E314(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80293738;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

struct PmfObj_8013E374;
typedef void (PmfObj_8013E374::*PmfFunc_8013E374)();
extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013BD54(void*);
extern "C" void fn_8013EA90(void* param_1) {
    fn_8013BD54(*(void**)((u8*)param_1 + 0x114));
}

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_802937C0[];
extern "C" void* fn_8013EAC0(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802937C0;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

