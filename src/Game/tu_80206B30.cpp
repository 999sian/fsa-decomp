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
