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

extern "C" u8 fn_801E1DB4(u8* this_);
extern "C" u8 fn_801D0DD4(u8* this_);
extern "C" const f32 lbl_8053F4D8;
extern "C" const f32 lbl_8053F4E0;
extern "C" const f32 lbl_8053F4EC;
extern "C" const f32 lbl_8053F4F0;
extern "C" const f32 lbl_8053F4F4;
extern "C" const f32 lbl_8053F4F8;
extern "C" const f32 lbl_8053F4FC;
extern "C" const f32 lbl_8053F500;
extern "C" const f32 lbl_8053F504;
extern "C" void fn_801E2D88(u8* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 0xe:
        *(f32*)(this_ + 0x60) = lbl_8053F4E0;
        *(f32*)(this_ + 0x64) = lbl_8053F4E0;
        *(f32*)(this_ + 0x68) = lbl_8053F4D8;
        *(f32*)(this_ + 0x6c) = lbl_8053F4D8;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        return;
    case 0xc:
        *(f32*)(this_ + 0x60) = lbl_8053F4EC;
        *(f32*)(this_ + 0x64) = lbl_8053F4EC;
        *(f32*)(this_ + 0x68) = lbl_8053F4D0;
        *(f32*)(this_ + 0x6c) = lbl_8053F4D0;
        *(f32*)(this_ + 0x70) = lbl_8053F4EC;
        *(f32*)(this_ + 0x74) = lbl_8053F4F0;
        *(f32*)(this_ + 0x78) = lbl_8053F4D0;
        *(f32*)(this_ + 0x7c) = lbl_8053F4D0;
        return;
    }
    if (fn_801E1DB4(this_)) {
        *(f32*)(this_ + 0x60) = lbl_8053F4F4;
        *(f32*)(this_ + 0x64) = lbl_8053F4F8;
        *(f32*)(this_ + 0x68) = lbl_8053F4FC;
        *(f32*)(this_ + 0x6c) = lbl_8053F500;
    } else {
        *(f32*)(this_ + 0x60) = lbl_8053F4EC;
        *(f32*)(this_ + 0x64) = lbl_8053F504;
        *(f32*)(this_ + 0x68) = lbl_8053F4D0;
        *(f32*)(this_ + 0x6c) = lbl_8053F500;
    }
    if (fn_801D0DD4(this_)) {
        *(f32*)(this_ + 0x64) += lbl_8053F500;
        *(f32*)(this_ + 0x6c) += lbl_8053F500;
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
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

