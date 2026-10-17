#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_801E67C4(s32* this_, s32 flag);
extern "C" void fn_801D1C18(s32* this_);
extern "C" u8 fn_801D21F0(s32* this_);
extern "C" s32 fn_8023E724(s32 idx);
extern "C" void fn_80230498(s32 idx, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void fn_801D267C(void* this_);
extern "C" void fn_801D2608(void* this_, void* tbl, s32 n);
extern "C" char lbl_8053A158;
extern "C" s32 fn_801E667C(s32* this_)
{
    s32 i;
    s32 val;
    s32 ret = 0;
    this_[1]++;
    if (this_[1] < 0) {
        this_[1] = 0;
    }
    switch (this_[0]) {
    case 0:
        break;
    case 1:
        if (this_[1] >= 400) {
            fn_801E67C4(this_, 2);
        }
        break;
    case 2:
        fn_801D1C18(this_ + 4);
        val = this_[8];
        for (i = 0; i < 4; i++) {
            if (*(u8*)((u8*)this_ + (i + 0xc)) != 0) {
                fn_80230498(i, fn_8023E724(i), val, 0xff, -0x80, -0x80, 1);
            }
        }
        if (fn_801D21F0(this_ + 4) != 0) {
            fn_801E67C4(this_, 3);
        }
        break;
    case 3:
        if (this_[1] >= 0x82) {
            fn_801E67C4(this_, 4);
        }
        break;
    case 4:
        ret = 1;
        break;
    }
    return ret;
}

extern "C" void fn_801E6A84(s32* this_, s32 val) {
    if (this_[0] == 0) {
        this_[2] = val;
        fn_801E67C4(this_, 1);
    }
}

extern "C" s32* fn_801E6AB8(s32* this_) {
    this_[0] = 0;
    this_[1] = 0;
    this_[2] = 1;
    fn_801D267C(this_ + 4);
    ((u8*)this_)[0xc] = 0;
    ((u8*)this_)[0xd] = 0;
    ((u8*)this_)[0xe] = 0;
    ((u8*)this_)[0xf] = 0;
    fn_801D2608(this_ + 4, &lbl_8053A158, 1);
    return this_;
}

void __sinit_tu_801E667C_cpp(void) {}

