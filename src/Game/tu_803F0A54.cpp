#include "types.h"

extern "C" void fn_8043670C(void* p, s32 a);

extern "C" void fn_803F1C18(u8* p) {
    fn_8043670C(*(void**)(p + 0x58), 1);
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xc;
}

extern "C" void fn_803F1C5C(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xb;
}
