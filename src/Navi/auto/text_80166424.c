#include "types.h"


extern "C" void fn_80168280(void);
extern "C" void fn_80167CB8(void) {
    fn_80168280();
}

extern "C" int fn_8016997C()
{
	return 0;
}

extern "C" int fn_8016999C()
{
	return 0;
}

extern "C" int fn_801699A4() {
    return 0;
}

extern "C" int fn_801699AC()
{
	return 0;
}

extern "C" int fn_801699B4(void) {
    return 0xFFFF;
}

extern "C" int fn_801699C0(void) {
    return 0xFFFF;
}

extern void* lbl_802985C8[];
extern void* lbl_80298600[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" BOOL fn_801699CC(void);
extern "C" BOOL fn_801699CC(void)
{
    return TRUE;
}

extern "C" int fn_801699D4()
{
	return 0;
}

extern "C" int fn_801699DC()
{
	return 0;
}

extern "C" int fn_801699E4()
{
	return 0;
}

extern "C" int fn_801699EC()
{
	return 0;
}

extern "C" void* fn_8016ABEC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298600;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8016ACA0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802985C8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298600;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8016AD04(void) {
}

extern "C" void fn_8016AD08(void) {
}

extern "C" void fn_801730DC(s16 (*p)[4], s32 i, s16* src)
{
	s16 a = src[0];
	p[i][6] = a;
	s16 b = src[1];
	p[i][7] = b;
	s16 c = src[2];
	p[i][8] = c;
	s16 d = src[3];
	p[i][9] = d;
}

extern "C" s32 fn_80173108(s32 p, s32 i)
{
    return p + i * 8 + 0xc;
}

extern "C" void fn_8017311C(s32 p, s32 i, u8* src)
{
	u8 a = src[0];
	u32 off = i << 2;
	u8* dst = (u8*)(p + off);
	u8 b = src[1];
	dst[0x34] = a;
	u8 c = src[2];
	dst[0x35] = b;
	u8 d = src[3];
	dst[0x36] = c;
	dst[0x37] = d;
}

extern "C" void fn_8017318C(void)
{
}

extern "C" BOOL fn_80173190(void)
{
    return TRUE;
}

extern "C" int fn_8017334C()
{
	return 0;
}

extern "C" int fn_80173354()
{
	return 0;
}

extern "C" int fn_8017335C()
{
	return 0;
}

extern "C" int fn_80173364()
{
	return 0;
}

extern "C" int fn_8017336C()
{
	return 0;
}

extern "C" int fn_80173374()
{
	return 0;
}

extern "C" int fn_8017337C()
{
	return 0;
}

