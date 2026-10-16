#include "Game/esd/types.h"


extern "C" s32 fn_802C8500(f32 a, f32 b, f32 c) {
    f32 d = a - b;
    if (-c <= d && d <= c) {
        return 1;
    }
    return 0;
}

extern "C" void fn_802C89F8(void) {}

extern "C" void fn_802C9284(u8* p) {
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0x3ff;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xf;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 20) & 0x7;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 23) & 0x7;
    *(u32*)(p + 0x244) = (*(u32*)(p + 0x90) >> 12) & 0xf;
    *(u32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 10) & 0x3;
}

