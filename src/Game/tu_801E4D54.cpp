#include "types.h"

extern "C" void fn_801E4D54(u8* this_) {
    *(u32*)(this_ + 0x230) &= ~0x4000;
    this_[0x5ce] = 0;
    *(f32*)(this_ + 0x4bc) = 0.0f;
}

extern "C" void fn_801E4D74(u8* this_) {
    this_[0x5ce] = 0x32;
    *(f32*)(this_ + 0x4bc) = 255.0f;
}
