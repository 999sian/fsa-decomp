#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004f844-0x800575d8 (67 functions). split_file divides it into the game's real files.

extern void* lbl_80222428[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80249D24[];
extern "C" void fn_80021DDC(void* p);
extern char lbl_802BB0FC[];
extern int lbl_802FF0E4;
extern "C" char lbl_802BB0FC[];
extern "C" int lbl_802FF0E4;
extern "C" char lbl_802C050C[];
extern "C" float lbl_803001FC;
extern int lbl_802FF0EC;
extern int lbl_802FF0E8;
extern "C" char lbl_802C05A0[];
extern "C" char lbl_802B7CA0[];
extern "C" u32 lbl_802313F8[];
extern "C" u8 lbl_802FEE34;
extern "C" u32 lbl_802FF1D0;
extern "C" u32 fn_80030390(u32);
extern "C" u32 lbl_8023133C[];
extern "C" void fn_800279A8(void* p, u32 a, s32 b, s32 c, s32 d);
extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_8002A3CC(void* p, void* q, s32 a, s32 b);
extern "C" void fn_80056B08(void* p);
extern "C" void fn_80058B64(s32 a);
extern "C" void fn_80089634(void* p, s32 n);
extern "C" void fn_8004FA30(void) {}

extern "C" void fn_800505D4(void* param_1)
{
    u32 r = fn_80030390(*(u8*)(lbl_802B7CA0 + 0x1419));
    u32 v;
    lbl_802FEE34 = 1;
    v = *(u32*)((u8*)lbl_802313F8 + r * 4);
    lbl_802FF1D0 = 1;
    *(u32*)(lbl_802BB0FC + 0xfc) = v;
    *(u32*)((u8*)param_1 + 0xf6c) = 0;
}

extern "C" void fn_800508D8(void* param_1)
{
    fn_800279A8((u8*)param_1 + 0x1cc, lbl_8023133C[*(u32*)(lbl_802BB0FC + 0x420)], 0, 0, 1);
    fn_8002F358(0x7a, 0);
    lbl_802FF1D0 = 0;
}

extern "C" void fn_80052AFC(void) {
    char* b = lbl_802BB0FC;
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x8)) + *(int*)(b + 0x58);
}

extern "C" void fn_80052B3C(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0xc)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052B7C(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x40)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052BBC(void* param_1) {
    fn_8002A3CC(param_1, lbl_802C05A0, 0x93, 1);
}

extern "C" void fn_80052BEC(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x14)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052C2C(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x18)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052C6C(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x1c)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052CAC(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x24)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052CEC(void) {
    lbl_802FF0E4 = (s32)(lbl_803001FC * *(f32*)(lbl_802C050C + 0x28)) + *(s32*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052D2C(void) {
    lbl_802FF0E4 = (s32)(lbl_803001FC * *(f32*)(lbl_802C050C + 0x2c)) + *(s32*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052D6C(void) {
    lbl_802FF0E4 = (s32)(lbl_803001FC * *(f32*)(lbl_802C050C + 0x30)) + *(s32*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052DAC(void) {
    lbl_802FF0E4 = (s32)(lbl_803001FC * *(f32*)(lbl_802C050C + 0x34)) + *(s32*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052DEC(void)
{
	int base = *(int*)(lbl_802BB0FC + 0x58);
	lbl_802FF0E4 = (int)(lbl_803001FC * *(float*)(lbl_802C050C + 0x38)) + base;
}

extern "C" void fn_80052E2C(void)
{
	lbl_802FF0E4 = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" char lbl_802C050C[];
extern "C" float lbl_803001FC;
extern "C" void fn_80052E44(void)
{
	lbl_802FF0E4 = *(int*)(lbl_802BB0FC + 0x58) + 500;
}

extern "C" void fn_80052E5C(void)
{
	int base = *(int*)(lbl_802BB0FC + 0x58);
	lbl_802FF0E4 = (int)(lbl_803001FC * *(float*)(lbl_802C050C + 0x3c)) + base;
}

extern "C" void fn_8005556C(void* self, void* p) {
    fn_80021DDC(p);
}

extern "C" void fn_80055950(const char*, ...) {
}

extern "C" void fn_80055C08(void) {}

extern int lbl_802FF0E8;
extern "C" void fn_80055C0C(void)
{
	lbl_802FF0E8 = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" void fn_80055C24(void* param_1) {
    lbl_802FF0E8 = *(int*)(lbl_802BB0FC + 0x58) + 1000;
    fn_8002A3CC(param_1, lbl_802C05A0, 0xa3, 1);
}

extern "C" void fn_80055C68(void) {
    *(u32*)(lbl_802BB0FC + 0x108) |= 0x4000;
}

extern "C" void fn_80055C80(void* param_1) {
    *(u32*)((u8*)param_1 + 0xf6c) = 0;
    *(s32*)(lbl_802BB0FC + 0x44) = 0xf;
}

extern "C" void fn_80056374(void) {
    lbl_802FF0E8 = lbl_802FF0EC + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" int fn_800572C0(int a, u32 mask) {
    u8 m = *(u32*)(lbl_802B7CA0 + 0x3444);
    u8 v = mask & m;
    if (v != 0 && (v ^ m) == 0) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_8005757C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80249D24;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
