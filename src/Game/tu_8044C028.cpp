#include "types.h"


extern "C" void fn_8044C028(u8* this_, f32 val) {
    this_[0x18] = 1;
    *(f32*)(this_ + 0x14) = val;
}
