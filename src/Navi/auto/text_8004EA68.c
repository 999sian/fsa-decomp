// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004ea68-0x8004eaec (1 functions). split_file divides it into the game's real files.

#include "types.h"

extern void* lbl_80222428[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_802472CC[];
extern "C" void fn_8000CEC4(void);
extern "C" void fn_801E0D40(void* dst, void* fn, s32 size, s32 count);

extern "C" void* fn_8004EA68(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_802472CC;
        fn_801E0D40((char*)param_1 + 0x2c, &fn_8000CEC4, 0xc, 0x4);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}
