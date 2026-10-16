#include "types.h"


extern "C" void fn_80168280(void);
extern "C" void fn_80166C70(void*);
extern "C" void* fn_80166BD0(void* param_1, u8 param_2)
{
	if (param_2) {
		fn_80166C70(param_1);
	}
	return param_1;
}

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

extern u8 lbl_80298644[];
extern u8 lbl_80298660[];
typedef void (*VFn_80169B1C)(void*, int);
extern "C" void fn_8016B170(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" u32* fn_80169B1C(u32* self, short param_2)
{
    if (self != NULL) {
        self[0] = (u32)lbl_80298644;
        u32* p = (u32*)self[0x1c];
        if (p != NULL) {
            (*(VFn_80169B1C*)(p[0] + 0xb8))(p, 1);
        }
        p = (u32*)self[0x1d];
        if (p != NULL) {
            (*(VFn_80169B1C*)(p[0] + 0x34))(p, 1);
        }
        fn_8015AB1C((void*)self[0x21]);
        fn_8016B170(self + 10, -1);
        if ((u8*)self + 0x10 != NULL) {
            self[9] = (u32)lbl_80298660;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
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
extern u8 lbl_80298644[];
extern u8 lbl_80298660[];
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

extern "C" s32 fn_8016BC8C(void* self, u32 param_2, void* param_3) {
    u8* p = (u8*)self;
    if (param_2 == 0) {
        if (p[0x5c] & 1) {
            fn_80118BD0(*(void**)(p + 0x50), 1);
        }
        *(void**)(p + 0x50) = param_3;
        p[0x5c] &= 0x80;
        fn_8015AB1C(*(void**)(p + 0x54));
        *(void**)(p + 0x54) = 0;
        *(u16*)(p + 4) = 0xFFFF;
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

extern "C" s32 fn_80172AB4(s32 p, u32 i) {
    if (i >= 8) {
        return 0;
    }
    p = p + (i << 2);
    return *(s32*)(p + 0xdc);
}

extern "C" s32 fn_80172AD4(s32 p, u32 i) {
    if (i >= 8) {
        return 0;
    }
    p = p + (i << 2);
    return *(s32*)(p + 0xfc);
}

extern "C" s32 fn_80172B18(void) {
    return 0x54564234;
}

extern "C" s32 fn_80172B80(s32 p, s32 i) {
    return p + i * 4 + 0xe;
}

extern "C" void fn_80172C54(u8* p1, int p2, u8* p3) {
    u8 v1;
    u8 v2;
    u8* dst = p1 + p2 * 8;
    v1 = p3[2];
    dst[0x40] = p3[1];
    v2 = p3[3];
    dst[0x41] = v1;
    v1 = p3[5];
    dst[0x42] = v2;
    v2 = p3[6];
    dst[0x44] = v1;
    v1 = p3[7];
    dst[0x45] = v2;
    dst[0x46] = v1;
}

extern "C" s32 fn_80172C90(s32 p, s32 i) {
    return p + i * 8 + 0x3f;
}

extern "C" void fn_80172CA4(s32 p, s32 i, u8* param_3) {
    u8* item = (u8*)(p + i * 8);
    item[0x46] = (item[0x46] & 0xf3) | (param_3[1] << 2);
    item[0x46] = (item[0x46] & 0xfc) | param_3[0];
}

extern "C" void fn_80172CDC(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x78] = *p3;
}

extern "C" s32 fn_80172CEC(s32 p, s32 i) {
    return p + i + 0x78;
}

extern "C" s32 fn_80172D10(s32 p, s32 i) {
    return p + (i << 2) + 0x7c;
}

extern "C" u8* fn_80172E24(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" u8 fn_80172EC4(u8* p, s32 i) { return *(p + i + 0x54); }

extern "C" void fn_80172ED0(u8* p, s32 i, u8 v) { *(p + i + 0x56) = v; }

extern "C" u8 fn_80172EDC(u8* p, s32 i) { return *(p + i + 0x56); }

extern "C" void fn_80172EE8(void* p, u8 v) {
    *(u8*)((u8*)p + 0x32) = v;
}

extern "C" u8 fn_80172EF0(u8* p) {
    return p[0x32];
}

extern "C" void fn_80172EF8(u8* p1, int p2, u8* p3) {
    u8 v1;
    u8 v2;
    u8* dst = p1 + p2 * 8;
    v1 = p3[2];
    dst[0x34] = p3[1];
    v2 = p3[3];
    dst[0x35] = v1;
    v1 = p3[5];
    dst[0x36] = v2;
    v2 = p3[6];
    dst[0x38] = v1;
    v1 = p3[7];
    dst[0x39] = v2;
    dst[0x3a] = v1;
}

extern "C" s32 fn_80172F34(s32 p, s32 i) {
    return p + i * 8 + 0x33;
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

extern "C" void* fn_80174A68(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A80(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A98(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AB0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AE0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AF8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B10(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B28(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B40(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B58(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B70(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" u8 fn_80177F0C(u8* self, void* arg)
{
    u8* it = *(u8**)(self + 0xdc);
    if (it != 0) it -= 0xc;
    while (it != 0) {
        void* obj = *(void**)(it + 0xc);
        if (((u8 (*)(void*, void*))(*(void***)obj)[20])(obj, arg)) return 1;
        it = *(u8**)(it + 0x18);
        if (it != 0) it -= 0xc;
    }
    return 0;
}

extern "C" void fn_801780D4(u8* self, u8 flag)
{
    self[0xb1] = flag;
    u8* it = *(u8**)(self + 0xdc);
    if (it != 0) it -= 0xc;
    while (it != 0) {
        void* obj = *(void**)(it + 0xc);
        ((void (*)(void*, u8))(*(void***)obj)[8])(obj, flag);
        it = *(u8**)(it + 0x18);
        if (it != 0) it -= 0xc;
    }
}

extern "C" void* fn_80178424(u8* self)
{
    u8* p = *(u8**)(self + 0xdc);
    u8* it = p;
    if (p != 0) it = p - 0xc;
    if (it == 0) return 0;
    if (p != 0) p -= 0xc;
    return *(void**)(p + 0xc);
}

extern "C" void fn_80178DA4(void* param_1)
{
}

