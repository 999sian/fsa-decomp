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

extern "C" void fn_80118BD0(void* p, s32 n);
extern u8 lbl_80202218[];
extern "C" u32 fn_8016AC94(void) {
    return 0x49424C4E;
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

extern "C" void fn_8016AD0C(void) {
}

extern "C" s32 fn_8016BC8C(void* self, s32 param_2, void* param_3) {
    u8* p = (u8*)self;
    if (param_2 == 0) {
        if (p[0x5c] & 1) {
            fn_80118BD0(*(void**)(p + 0x50), 1);
        }
        *(void**)(p + 0x50) = param_3;
        p[0x5c] &= 0x80;
        fn_8015AB1C(*(void**)(p + 0x54));
        *(void**)(p + 0x54) = nullptr;
        *(s16*)(p + 4) = -1;
        return 1;
    }
    return 0;
}

extern "C" u32 fn_80172468(void)
{
    return 0x49424c46;
}

extern "C" s32 fn_80172640(s32 p, s32 i)
{
	return p + i * 4 + 0x16;
}

extern "C" s32 fn_80172750(s32 p, s32 i)
{
	return p + i * 8 + 0x77;
}

extern "C" s32 fn_801728E0(s32 p, s32 i)
{
	return p + i * 4 + 0x16;
}

extern "C" void fn_801729A4(s32 p, u8 v)
{
	*(u8*)(p + 0x56) = v;
}

extern "C" u8 fn_801729AC(s32 p)
{
	return *(u8*)(p + 0x56);
}

extern "C" s32 fn_801729F0(s32 p, s32 i) {
    return p + i * 8 + 0x57;
}

extern "C" void fn_80172A3C(u8* p1, s32 p2, u8* p3) {
    p1[p2 + 0xb8] = *p3;
}

extern "C" u8* fn_80172A4C(u8* p, s32 i) {
    return p + i + 0xb8;
}

extern "C" s32 fn_80172B18(void) {
    return 0x54564234;
}

extern "C" s32 fn_80172CEC(s32 p, s32 i) {
    return p + i + 0x78;
}

extern "C" unsigned int fn_80173060(void) {
    return 0x54564231;
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
    u8* dst = (u8*)(p + i * 4);
    dst[0x34] = src[0];
    dst[0x35] = src[1];
    dst[0x36] = src[2];
    dst[0x37] = src[3];
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

