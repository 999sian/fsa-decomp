#include "types.h"

extern "C" void fn_801E67C4(s32* this_, s32 flag);
extern "C" void fn_801D267C(void* this_);
extern "C" void fn_801D2608(void* this_, void* tbl, s32 n);
extern "C" char lbl_8053A158;
extern "C" void fn_801E6A84(s32* this_, s32 val) {
    if (this_[0] == 0) {
        this_[2] = val;
        fn_801E67C4(this_, 1);
    }
}
