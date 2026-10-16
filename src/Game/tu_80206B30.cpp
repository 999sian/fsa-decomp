#include "Game/esd/types.h"


extern "C" const f32 lbl_8053F8AC;
extern "C" const f32 lbl_8053F8BC;
extern "C" const f32 lbl_8053F8C0;
extern "C" const f32 lbl_8053F8C4;
extern "C" u8 lbl_8053EFC0;
extern "C" u8 fn_8020609C(u8* p);
extern "C" u8 fn_801F2618(u8* p, u8* q, u8 c);
extern "C" u8 fn_801F2DB4(u8* p, u32 a, u32 b, u32 c);
extern "C" void fn_80205E0C(u8* p, s32 n);
extern "C" u8 fn_80207004(u8* p) {
    u8 ret = 0;
    if (p[0xc4] == 0 && *(s32*)(p + 0x248) != 3 && *(s32*)(p + 0x248) != 4 &&
        *(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F8AC &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F8AC) {
        ret = fn_801F2DB4(p, 0x4e554c4c, 0x4e554c4c, 0);
        if (ret) {
            fn_80205E0C(p, 7);
        }
    }
    return ret;
}

extern "C" void fn_802072E4(u8* p) {
    *(f32*)(p + 0x60) = lbl_8053F8BC;
    *(f32*)(p + 0x64) = lbl_8053F8C0;
    *(f32*)(p + 0x68) = lbl_8053F8C4;
    *(f32*)(p + 0x6c) = lbl_8053F8C4;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
}
