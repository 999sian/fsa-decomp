#include "types.h"


extern const f32 lbl_80543D78;
extern const f32 lbl_80543D7C;
extern "C" u8 fn_80402940(void*, s32, s32, f32, f32);
extern "C" void fn_80443D5C(u8* p) {
    if (fn_80402940(*(void**)(p + 8), 10, 0, lbl_80543D78, lbl_80543D7C)) {
        p[0x4d] = 4;
    }
}
