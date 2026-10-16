#include "types.h"


extern void* lbl_8053AED0;
extern "C" void* fn_8043DF8C(void* game);
extern char* lbl_8053AAF8;
extern const f32 lbl_80543CFC;
extern const f32 lbl_80543CF8;
extern "C" void fn_8041E708(void* p);
extern "C" void fn_80425234(void* p);
extern "C" void fn_8043D874(char* param_1) {
    if (lbl_8053AAF8[0x7f] != 0) {
        fn_8041E708(*(void**)(param_1 + 0x290));
    } else {
        fn_80425234(*(void**)(param_1 + 0x294));
    }
}

extern "C" s32 fn_8043DF24(f32 x, f32 y, f32 px, f32 py, f32 r) {
    if (px >= (x - lbl_80543CFC) - r && px <= r + (lbl_80543CFC + x) && py >= (y - lbl_80543CF8) - r && py <= r + (lbl_80543CF8 + y)) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8043EDE8(char* param_1, s32 param_2) {
    *(s32*)(param_1 + 0xe0) = param_2;
    *(s32*)(param_1 + 0xe4) = 0x1e;
}

extern "C" void* fn_80440928(void) { return fn_8043DF8C(lbl_8053AED0); }
