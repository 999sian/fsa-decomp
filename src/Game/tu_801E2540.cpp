#include "types.h"
#include <JSystem/JGeometry/Box.h>

extern "C" void fn_802397B4(void* rect, u32 id, s32 v);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" const f32 lbl_8053F4D0;

extern "C" void fn_802397B4(void* rect, u32 id, s32 v);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" const f32 lbl_8053F4D0;
extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_801E2540(u8* this_) {
    s32 kind;
    s32 ret = 0;

    if ((*(u32*)(this_ + 0x230) & 0x1000) == 0) {
        u8* p;
        f32 lo;
        f32 hi;

        kind = *(s32*)(this_ + 4);
        p = fn_802D6A9C();
        if (kind < 8) {
            p += 0xcc;
        } else {
            p += 0xdc;
        }
        lo = *(f32*)(p + 0xc) - 8.0f;
        if (*(f32*)(this_ + 0x10) > lo) {
            *(f32*)(this_ + 0x10) = lo;
            ret = 1;
            *(f32*)(this_ + 0x264) = 0.0f;
            *(f32*)(this_ + 0x268) = -1.0f;
            *(f32*)(this_ + 0x26c) = 0.0f;
        } else {
            hi = 24.0f + *(f32*)(p + 0x4);
            if (*(f32*)(this_ + 0x10) < hi) {
                *(f32*)(this_ + 0x10) = hi;
                ret = 1;
                *(f32*)(this_ + 0x264) = 0.0f;
                *(f32*)(this_ + 0x268) = 1.0f;
                *(f32*)(this_ + 0x26c) = 0.0f;
            }
        }
    }
    return ret;
}

extern "C" void fn_801E2EE4(u8* this_) {
    f32 c = lbl_8053F4D0;
    f32 x = *(f32*)(this_ + 0xc);
    f32 y = *(f32*)(this_ + 0x10);
    f32 rect[4];
    rect[0] = x - c;
    rect[1] = y - c;
    rect[2] = x + c;
    rect[3] = y + c;
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

