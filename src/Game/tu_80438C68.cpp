#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JParticle/JPAEmitter.h"


extern "C" f32 lbl_80543C40;
extern "C" f32 lbl_80543C44;
extern "C" void fn_80438E10(u8* p, u8 flag)
{
    *(u8*)(p + 0x40) = flag;
    if (flag) {
        return;
    }
    *(u8*)(p + 0x40) = 0;
    *(u8*)(p + 0x42) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(s32*)(p + 0x44) = -1;
    *(s32*)(p + 0x48) = 0;
    *(u8*)(p + 0x58) = 0;
    *(u8*)(p + 0x59) = 0xff;
    *(u8*)(p + 0x5a) = 0xff;
    *(f32*)(p + 0x4c) = 255.0f;
    *(f32*)(p + 0x50) = 0.0f;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
    *(s32*)(p + 0x30) = 0;
    *(u8*)(p + 0x5f) = 0;
}

extern "C" f32 lbl_80543C78;
extern "C" f32 lbl_80543C7C;
extern "C" f32 lbl_80543C80;
extern "C" void* lbl_8053AB10;
extern "C" u8* lbl_8053ADC8;
extern "C" void fn_8013B490(void* p);
extern "C" void fn_804399A0(u8* param_1)
{
    fn_8013B490(lbl_8053AB10);
    s32 frame = (s32)*(f32*)(param_1 + 0x50);
    void** obj = *(void***)(param_1 + 0x34);
    ((void (*)(void*, s32))(*(void***)obj)[9])(obj, frame);
    obj = *(void***)(param_1 + 0x34);
    ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))(*(void***)obj)[59])(obj, 0, 0, 0, lbl_80543C78, lbl_80543C78, lbl_80543C7C, lbl_80543C80);
    *(f32*)(*(u8**)(param_1 + 8) + 8) = (f32)*(s32*)(param_1 + 0x3c);
    (*(J2DPane**)(param_1 + 4))->search(0x004e646174613031ULL)->animationTransform();
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543C44, lbl_80543C44, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    if (*(u8*)(param_1 + 0x40) == 3) {
        *(u8*)((u8*)lbl_8053ADC8 + 0x20) = 1;
        *(u8*)((u8*)lbl_8053ADC8 + 0x21) = 0;
    }
}

extern "C" void fn_80439AB0(u8* p)
{
    *(u8*)(p + 0x40) = 0;
    *(u8*)(p + 0x42) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(s32*)(p + 0x44) = -1;
    *(s32*)(p + 0x48) = 0;
    *(u8*)(p + 0x58) = 0;
    *(u8*)(p + 0x59) = 0xff;
    *(u8*)(p + 0x5a) = 0xff;
    *(f32*)(p + 0x4c) = 255.0f;
    *(f32*)(p + 0x50) = 0.0f;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
    *(s32*)(p + 0x30) = 0;
    *(u8*)(p + 0x5f) = 0;
}

