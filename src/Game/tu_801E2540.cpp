#include "types.h"
#include <JSystem/JGeometry/Box.h>

extern "C" void fn_802397B4(void* rect, u32 id, s32 v);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" const f32 lbl_8053F4D0;

extern "C" void fn_802397B4(void* rect, u32 id, s32 v);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" const f32 lbl_8053F4D0;
extern "C" void fn_801E2EE4(u8* this_) {
    f32 y = *(f32*)(this_ + 0x10);
    f32 c = lbl_8053F4D0;
    f32 x = *(f32*)(this_ + 0xc);
    f32 rect[4];
    rect[0] = x - c;
    rect[1] = y - c;
    rect[2] = c + x;
    rect[3] = c + y;
    fn_802397B4(rect, *(u32*)(this_ + 4), *(s32*)(this_ + 0x198));
}

extern "C" s32 fn_801E2F40(u8* this_) {
    s32 result = 0;
    u16 kind = fn_8022461C(this_ + 0xc, *(s32*)(this_ + 4));
    switch (kind) {
    case 3:
    case 13:
    case 14:
        result = 1;
        break;
    }
    return result;
}

