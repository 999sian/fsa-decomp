#include "types.h"
#include "Game/SinitPoolChain.h"


extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AD68;
extern "C" f32 lbl_80543534;
extern "C" f32 lbl_80543568;
extern "C" f32 lbl_8054356C;
extern "C" void fn_8013B490(void*);
extern "C" void fn_803D75B0(void);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern "C" void fn_803D82EC(u8* param_1) {
    u8* obj;

    fn_8013B490(lbl_8053AB10);
    obj = *(u8**)(param_1 + 0x1c);
    ((void (*)(u8*, u8))(*(void***)obj)[0x24 / 4])(obj, param_1[0x77]);
    obj = *(u8**)(param_1 + 0x1c);
    ((void (*)(u8*, s32, s32, s32, f32, f32, f32, f32))(*(void***)obj)[0xec / 4])(obj, 0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" void fn_803D8670(u8* param_1) {
    u8* obj;

    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 4), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 8), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    obj = *(u8**)(param_1 + 0x1c);
    ((void (*)(u8*, u8))(*(void***)obj)[0x24 / 4])(obj, param_1[0x77]);
    ((void (*)(u8*, s32, s32, s32, f32, f32, f32, f32))(*(void***)(*(u8**)(param_1 + 0x1c)))[0xec / 4])(*(u8**)(param_1 + 0x1c), 0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" void fn_803D8718(u8* param_1) {
    s32 bVar1 = param_1[0x76];

    switch (bVar1) {
    case 6:
        if (param_1[0x77] >= 0xf5) {
            param_1[0x77] = 0xff;
            param_1[0x76] = 5;
        } else {
            param_1[0x77] += 10;
        }
        break;
    case 5:
        if (param_1[0x77] <= 10) {
            param_1[0x77] = 0;
            ((u8*)lbl_8053AD68)[0x1d] = 1;
            param_1[0x76] = 2;
        } else {
            param_1[0x77] -= 10;
        }
        break;
    case 2:
        fn_803D75B0();
        break;
    }
}

