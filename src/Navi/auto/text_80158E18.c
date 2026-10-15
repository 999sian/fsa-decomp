#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158e18-0x8015db8c (138 functions). split_file divides it into the game's real files.

extern void* lbl_8029796C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80159DB4(void);
extern u32 lbl_802FF540;
extern "C" u32 fn_80159B94(u32 param_1) {
    u32 old = lbl_802FF540;
    lbl_802FF540 = param_1;
    return old;
}

extern "C" void fn_8015D030(void) {
    fn_80159DB4();
}

extern "C" void* fn_8015DA4C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029796C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
