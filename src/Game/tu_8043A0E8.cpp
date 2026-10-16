#include "types.h"


extern void* lbl_8053AED0;
extern "C" void* fn_8043DF8C(void* game);
extern char* lbl_8053AAF8;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern "C" void fn_8043A450(void* param_1, s32 param_2, s32 param_3);
extern const f32 lbl_80543CFC;
extern const f32 lbl_80543CF8;
extern "C" void fn_8041E708(void* p);
extern "C" void fn_80425234(void* p);
extern "C" void fn_8043A608(void* param_1) {
    fn_8043A450(param_1, *(s32*)(lbl_80529DEC + 0x118), *(s32*)(lbl_80529DEC + 0x11c));
}

extern "C" void fn_8043D874(char* param_1) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041E708(*(void**)(param_1 + 0x290));
    } else {
        fn_80425234(*(void**)(param_1 + 0x294));
    }
}

extern "C" s32 fn_8043DF24(f32 x, f32 y, f32 px, f32 py, f32 r) {
    f32 a = lbl_80543CFC;
    f32 b = lbl_80543CF8;
    f32 left = (x - a) - r;
    f32 right = r + (a + x);
    f32 bottom = (y - b) - r;
    f32 top = r + (b + y);
    if (px >= left && px <= right && py >= bottom && py <= top) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8043EDE8(char* param_1, s32 param_2) {
    *(s32*)(param_1 + 0xe0) = param_2;
    *(s32*)(param_1 + 0xe4) = 0x1e;
}

extern "C" void* fn_80440928(void) { return fn_8043DF8C(lbl_8053AED0); }
