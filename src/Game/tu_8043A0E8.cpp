#include "types.h"


extern void* lbl_8053AED0;
extern "C" void* fn_8043DF8C(void* game);
extern char* lbl_8053AAF8;
extern const f32 lbl_80543CFC;
extern const f32 lbl_80543CF8;
extern "C" void fn_8041E708(void* p);
extern "C" void fn_80425234(void* p);
extern "C" void fn_8043EDE8(char* param_1, s32 param_2) {
    *(s32*)(param_1 + 0xe0) = param_2;
    *(s32*)(param_1 + 0xe4) = 0x1e;
}

extern "C" void* fn_80440928(void) { return fn_8043DF8C(lbl_8053AED0); }
