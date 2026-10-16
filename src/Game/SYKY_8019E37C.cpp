#include "types.h"

extern "C" void fn_80458880(void*, s32, s32);
extern const f32 lbl_8053E4A4;
extern const f32 lbl_8053E4A8;
extern void* lbl_8053AF80;
extern "C" void fn_8019EE04(u8* p) {
    if (*(s32*)(p + 0x268) == 3 && *(s32*)(p + 0x230) != 0xf) {
        *(f32*)(p + 0x290) = lbl_8053E4A4;
        *(f32*)(p + 0x10) -= lbl_8053E4A8;
        fn_80458880(lbl_8053AF80, 6, -1);
        *(s32*)(p + 0x230) = 0xf;
    }
}
