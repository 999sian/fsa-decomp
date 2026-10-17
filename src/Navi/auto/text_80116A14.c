#include "types.h"

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80116a14-0x801182c8 (18 functions). split_file divides it into the game's real files.

extern "C" void fn_801178BC(u8* param_1, s32 param_2);
extern "C" void fn_80118104(void);
extern "C" void fn_801DB1BC(void);
extern "C" void fn_801DB3E0(void);
extern "C" void fn_80117BE0(void* param_1, s32 param_2, s32 param_3, u16 param_4, u16 param_5, u32* param_6);
extern "C" void fn_80120C98(void);
extern "C" void fn_80120704(void);
extern "C" void fn_8015AB1C(void* param_1);
extern void* lbl_802FF328;
extern s32 lbl_802FF330;
extern u8 lbl_80290024[];
extern u8 lbl_802C5F84[];
extern u8 lbl_802C5F90[];
extern u8 lbl_8028FF00[];
extern f32 lbl_803014B0;
extern "C" void fn_80166FC4(void* a, void* b);
extern "C" void fn_801C0EEC(u32 a);
extern "C" void fn_80166B58(void* a, void* b);
extern "C" void OSCreateAlarm(void* alarm);
extern "C" u32 fn_801C027C(void);
extern "C" u32 OSDisableInterrupts(void);
extern "C" void fn_80166C84(void* a, void* b);
extern "C" void OSSetAlarm(void* alarm, u64 tick, void (*handler)(void*, void*));
extern "C" void fn_801C1174(u32 a);
extern "C" void OSRestoreInterrupts(u32 level);
extern "C" void fn_80166B70(void* a, u32 b);
extern "C" void fn_801DCFB8(void* a, void* b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_801DD24C(void* a, int b, int c, int d, int e, int f, f32 g, f32 h, f32 i);
extern "C" void fn_8011790C(void* a, u16 b);
extern "C" void fn_80116A14(u16* param_1, u32 param_2)
{
    u32 n = param_2 >> 1;
    u16 zero = 0;
    if (n <= 0) {
        return;
    }
    u32 blocks = n >> 3;
    if (blocks != 0) {
        do {
            param_1[0] = zero;
            param_1[1] = zero;
            param_1[2] = zero;
            param_1[3] = zero;
            param_1[4] = zero;
            param_1[5] = zero;
            param_1[6] = zero;
            param_1[7] = zero;
            param_1 += 8;
        } while (--blocks != 0);
    }
    n &= 7;
    if (n == 0) {
        return;
    }
    do {
        *param_1++ = zero;
    } while (--n != 0);
}

extern "C" void* fn_80116DC4(void* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(u8**)param_1 = lbl_80290024;
        if (lbl_802FF328 != 0) {
            fn_801178BC((u8*)param_1, 2);
        }
        fn_80120C98();
        fn_80120704();
        *(s32*)((u8*)param_1 + 0x10) = 0;
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801178BC(u8* param_1, s32 param_2)
{
    while (param_2-- > 0) {
        fn_8011790C(*(void**)(param_1 + 0x20), *(u16*)(param_1 + 0x1c));
    }
}

extern "C" void fn_80117A2C(u8* param_1)
{
    fn_80166FC4(lbl_802C5F84, param_1 + 0x2c);
    fn_801C0EEC(*(u32*)(param_1 + 0x28));
}

extern "C" void fn_80117A2C(u8* param_1);
extern "C" void fn_80117A6C(void* param_1, void* param_2, u64 param_3)
{
    u8 alarm[44];
    u8 buf[44];
    u8* ptr;
    u32 local_30;
    u32 level;

    fn_80166B58(buf, alarm);
    OSCreateAlarm(alarm);
    local_30 = fn_801C027C();
    level = OSDisableInterrupts();
    fn_80166C84(lbl_802C5F84, buf);
    OSSetAlarm(alarm, param_3, (void (*)(void*, void*))fn_80117A2C);
    fn_801C1174(local_30);
    OSRestoreInterrupts(level);
    ptr = buf;
    if (ptr != 0) {
        fn_80166B70(ptr, 0);
    }
}

extern "C" void fn_80117B28(void)
{
    fn_801DCFB8(lbl_802C5F90, lbl_8028FF00, 4, 4, 0x16, 1, 1, 0);
    fn_801DD24C(lbl_802C5F90, 0, 0, 0, 0, 0, lbl_803014B0, lbl_803014B0, lbl_803014B0);
}

extern "C" void fn_80117BE0(void* param_1, s32 param_2, s32 param_3, u16 param_4, u16 param_5, u32* param_6);
extern "C" void fn_80120C98(void);
extern "C" void fn_80120704(void);
extern "C" void fn_8015AB1C(void* param_1);
extern void* lbl_802FF328;
extern s32 lbl_802FF330;
extern u8 lbl_80290024[];
extern "C" void fn_801178BC(u8* param_1, s32 param_2);
extern "C" void fn_80117B9C(void* param_1, u32* param_2)
{
    s32 local[1];
    local[0] = *param_2;
    u8* p = *(u8**)((u8*)lbl_802FF328 + 4);
    fn_80117BE0(param_1, 0, 0, *(u16*)(p + 4), *(u16*)(p + 6), (u32*)local);
}

extern "C" void fn_80117F60(u8* param_1)
{
    s32 step = lbl_802FF330;
    s32 pos = step;
    u32 period = *(u32*)(param_1 + 0x30);
    s32 lim = period * 2;
    while (pos < lim) {
        pos += step;
    }
    s32 x = (pos - lim) - *(s32*)(param_1 + 0x34);
    if (x < 0) {
        x += step;
    }
    *(f32*)(param_1 + 0x28) = (f32)(f64)(u32)x / (f32)(f64)period;
    if (*(f32*)(param_1 + 0x28) > 1.0f) {
        *(f32*)(param_1 + 0x28) = 1.0f;
    }
}

extern "C" void fn_801180DC(void)
{
    fn_80118104();
    fn_801DB1BC();
    fn_801DB3E0();
}
