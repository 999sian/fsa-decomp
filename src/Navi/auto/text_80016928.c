#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80016928-0x8001757c (13 functions). split_file divides it into the game's real files.

extern void* lbl_80205090[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_8029FDB4[];
extern char lbl_80205058[];
extern char lbl_802B488C[];
extern "C" void fn_8001A53C(void);
extern "C" void fn_80019A24(void);
extern "C" void fn_8001978C(void);
extern "C" void fn_8001D288(s32, void (*)(void));
extern "C" void fn_801149B0(s32);
extern "C" void fn_8001D434(void);
extern "C" void fn_8001A59C(void);
extern "C" void fn_80019AE0(void);
extern "C" void fn_80019790(void);
extern "C" void fn_8001AB40(void);
extern "C" void fn_8001A4AC(s32, s32, s32, s32);
extern "C" u8 fn_800126C8(void*, void*, void*);
extern "C" void fn_801D7F2C(u8 param_1, u32 param_2, void* param_3);
extern u8 lbl_802AE880[];


extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" s64 OSGetTime(void);
extern "C" void fn_801E4250(void*, s32, void*, ...);
extern "C" void fn_801C20AC(s64, u32*);
extern u8 lbl_80204FF0[];
extern void* lbl_802FECC4;
extern "C" void fn_80016D58(void* param_1)
{
    u8* self = (u8*)param_1;
    u8* base = lbl_80204FF0;
    u32 buf[8];
    u8* r30;
    u8* r31;

    fn_801E4250(self + 0x1c00, 0x20, base);
    fn_801C20AC(OSGetTime(), buf);
    fn_801E4250(self + 0x1c20, 0x20, base + 0x1c, buf[4] + 1, buf[3]);
    r30 = (u8*)((void* (*)(void*, void*))(*(void**)((u8*)*(void**)lbl_802FECC4 + 0x14)))(lbl_802FECC4, base + 0x3c);
    r31 = (u8*)((void* (*)(void*, void*))(*(void**)((u8*)*(void**)lbl_802FECC4 + 0x14)))(lbl_802FECC4, base + 0x54);
    memcpy(self, r30 + *(u32*)(r30 + 0x1c), (u32)*(u16*)(r30 + 0xa) * 2 + 0xc00);
    memcpy(self + 0xe00, r31 + *(u32*)(r31 + 0x1c), (u32)*(u16*)(r31 + 0xa) * 2 + 0x400);
}

extern "C" int fn_80016FA0(u8* param_1)
{
    u8 buf[0x78];
    u16 a;
    u16 b;

    fn_801D7F2C(lbl_802AE880[0x1fa4], *(u32*)(param_1 + 4), buf);
    if (*(u32*)(buf + 0x30) == 0 && *(u32*)(buf + 0x38) == 0x1c00 && (buf[0x2e] & 3) == 1 && !(buf[0x2e] & 4)) {
        a = *(u16*)(buf + 0x34);
        if ((a & 3) == 1 && ((a >> 2) & 3) == 0 && ((a >> 4) & 3) == 0 && ((a >> 6) & 3) == 0 && ((a >> 8) & 3) == 0 && ((a >> 10) & 3) == 0 && ((a >> 12) & 3) == 0 && ((a >> 14) & 3) == 0) {
            b = *(u16*)(buf + 0x36);
            if ((b & 3) == 3 && ((b >> 2) & 3) == 0 && ((b >> 4) & 3) == 0 && ((b >> 6) & 3) == 0 && ((b >> 8) & 3) == 0 && ((b >> 10) & 3) == 0 && ((b >> 12) & 3) == 0 && ((b >> 14) & 3) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

extern "C" u32 fn_800170A0(u16* p, u32 n)
{
    u32 sum = 0;
    u32 nsum = 0;
    s32 i;

    n >>= 1;
    if (n > 0) {
        i = n >> 3;
        if (i != 0) {
            do {
                sum += p[0];
                nsum = (u16)(nsum + ~p[0]);
                sum += p[1];
                nsum = (u16)(nsum + ~p[1]);
                sum += p[2];
                nsum = (u16)(nsum + ~p[2]);
                sum += p[3];
                nsum = (u16)(nsum + ~p[3]);
                sum += p[4];
                nsum = (u16)(nsum + ~p[4]);
                sum += p[5];
                nsum = (u16)(nsum + ~p[5]);
                sum += p[6];
                nsum = (u16)(nsum + ~p[6]);
                sum += p[7];
                nsum = (u16)(nsum + ~p[7]);
                p += 8;
            } while (--i != 0);
        }
        i = n & 7;
        if (i != 0) {
            do {
                sum += p[0];
                nsum = (u16)(nsum + ~p[0]);
                p++;
            } while (--i != 0);
        }
    }
    return (sum << 16) | nsum;
}

extern "C" u32 fn_8001719C(u8* param_1)
{
    u8* p = param_1;
    u32 nsum = 0;
    u32 sum = 0;
    s32 i;
    u8 b;

    for (i = 0x164; i != 0; i--) {
        b = p[0];
        sum += b;
        nsum += ~b;
        b = p[1];
        sum += b;
        nsum += ~b;
        b = p[2];
        sum += b;
        nsum += ~b;
        b = p[3];
        sum += b;
        nsum += ~b;
        b = p[4];
        sum += b;
        nsum += ~b;
        b = p[5];
        sum += b;
        nsum += ~b;
        b = p[6];
        sum += b;
        nsum += ~b;
        p += 7;
    }
    return ((nsum ^ *(u32*)(param_1 + 0x9c0)) | (sum ^ *(u32*)(param_1 + 0x9bc))) == 0;
}

extern "C" void fn_80017248(u8* base, u8 idx)
{
    u8* q = base + idx * 0x9c4 + 0x258;
    u8* p = q;
    u32 nsum = 0;
    u32 sum = 0;
    s32 i;
    u8 b;

    for (i = 0x164; i != 0; i--) {
        b = p[0];
        sum += b;
        nsum += ~b;
        b = p[1];
        sum += b;
        nsum += ~b;
        b = p[2];
        sum += b;
        nsum += ~b;
        b = p[3];
        sum += b;
        nsum += ~b;
        b = p[4];
        sum += b;
        nsum += ~b;
        b = p[5];
        sum += b;
        nsum += ~b;
        b = p[6];
        sum += b;
        nsum += ~b;
        p += 7;
    }
    *(u32*)(q + 0x9c0) = nsum;
    *(u32*)(q + 0x9bc) = sum;
}

extern "C" void fn_80017468(void)
{
    fn_8001A53C();
    fn_80019A24();
    fn_8001978C();
}

extern "C" void fn_80017490(void)
{
    fn_8001D288(0, fn_80017468);
    fn_801149B0(0);
}

extern "C" void fn_800174C4(void)
{
    fn_8001D434();
    fn_8001A59C();
    fn_80019AE0();
    fn_80019790();
    fn_8001AB40();
    fn_8001A4AC(1, 0x7fff, 0, 0);
    lbl_802B488C[4] = fn_800126C8(lbl_8029FDB4 + 4, lbl_80205058, lbl_802B488C);
}

extern "C" void* fn_80017534(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80205090;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
