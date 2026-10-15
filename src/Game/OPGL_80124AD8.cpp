#include "types.h"

extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" u8 lbl_8049E198[];
extern "C" f32 lbl_8053CA40;
extern "C" void fn_80121DB0(void);
extern "C" void fn_80123D88(void);
extern "C" void fn_80124C2C(void) {
    fn_80121DB0();
}

extern "C" void fn_80124C4C(u8* this_) {
    fn_801D2608(this_ + 0x230, lbl_8049E198, 0xe);
    fn_801D22DC(this_ + 0x230, 7, 2, 0);
    fn_801D1F14(this_ + 0x230, lbl_8053CA40);
}
