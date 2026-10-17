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
extern "C" void fn_8002A3CC(void* p, void* q, s32 a, s32 b);
extern "C" void fn_8004FA30(void) {}

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
