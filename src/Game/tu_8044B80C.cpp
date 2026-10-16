#include "types.h"


extern "C" char lbl_804B1D10[];
extern "C" void* lbl_8053AF30;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80543DC0;
extern "C" void fn_8013B490(void*);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern "C" void fn_8044B8EC(u8* p)
{
    if (p[0x14] != 0 && p[0x16] == 3 && *(void**)(p + 8) != NULL) {
        fn_8013B490(lbl_8053AB10);
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 8), lbl_80543DC0, lbl_80543DC0, *(void**)((u8*)lbl_8053AB10 + 0x10));
        p[0x14] = 0;
    }
}

extern "C" void fn_8044BDCC(u8* p)
{
    *(char**)p = lbl_804B1D10;
    lbl_8053AF30 = p;
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 8) = 0;
    *(u32*)(p + 0xc) = 0;
    *(u32*)(p + 0x10) = 0;
    p[0x14] = 0;
    p[0x15] = 0xff;
    p[0x16] = 0;
}
