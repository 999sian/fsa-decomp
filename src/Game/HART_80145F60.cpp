#include "types.h"

extern "C" const f32 lbl_8053D050;
extern "C" void fn_80146890(void* this_) {
    f32 val = lbl_8053D050;
    *(f32*)((u8*)this_ + 0x44) = val;
    *(f32*)((u8*)this_ + 0x40) = val;
    *(f32*)((u8*)this_ + 0x3c) = val;
    *(u32*)((u8*)this_ + 0x230) = 4;
}
