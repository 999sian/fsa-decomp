#include "types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013e314-0x8013eb20 (13 functions). split_file divides it into the game's real files.

struct PmfObj_8013E374;
typedef void (PmfObj_8013E374::*PmfFunc_8013E374)();

extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013CD54(void*);
extern "C" void fn_801E0DB8(void*, void*, void*, u32, u32);
extern void* lbl_8029260C[];
extern void* lbl_802922F4[];
extern void* lbl_8029383C[];
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

extern "C" void fn_8013E374(void* param_1, void* param_2) {
    PmfFunc_8013E374* pmf = (PmfFunc_8013E374*)((u8*)param_1 + 8);
    (((PmfObj_8013E374*)*(void**)((u8*)param_2 + 0x88))->*(*pmf))();
}

extern "C" void fn_8013E9E4(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x114), param_3, param_4, param_5, param_6);
}

struct PmfObj_8013E374;
typedef void (PmfObj_8013E374::*PmfFunc_8013E374)();
extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013BD54(void*);
extern "C" void fn_8013EA90(void* param_1) {
    fn_8013BD54(*(void**)((u8*)param_1 + 0x114));
}

extern "C" void fn_8013EAB4(void* param_1, void* param_2) {
    *(u32*)((u8*)param_2 + 0x118) = *(u32*)((u8*)param_1 + 8);
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

