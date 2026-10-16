

#include "types.h"

typedef void VFn_80169B1C(u32*, int);
struct UnkVObj_80166424 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u8);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8 vf18(void*);
};
extern "C" void* lbl_80298644[];
extern "C" u8 lbl_80298660[];
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8016B170(u32*, int);

extern "C" void fn_80166B58(u32* param_1, u32 param_2)
{
	param_1[1] = 0;
	*param_1 = param_2;
	param_1[2] = 0;
	param_1[3] = 0;
}

extern "C" void fn_80168E00(void)
{
}

extern "C" int fn_8016997C()
{
	return 0;
}

extern "C" int fn_8016999C()
{
	return 0;
}

extern "C" int fn_801699A4()
{
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

extern "C" int fn_801699CC(void)
{
    return 1;
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

extern "C" u32* fn_80169B1C(u32* self, short param_2)
{
    if (self != NULL) {
        self[0] = (u32)lbl_80298644;
        u32* p = (u32*)self[0x1c];
        if (p != NULL) {
            VFn_80169B1C** vt = (VFn_80169B1C**)*p;
            vt[0xb8 / 4](p, 1);
        }
        p = (u32*)self[0x1d];
        if (p != NULL) {
            ((VFn_80169B1C**)*p)[0x34 / 4](p, 1);
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

extern void* lbl_802985C8[];
extern void* lbl_80298600[];
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

extern "C" void fn_8016AD04() {}

extern "C" void fn_8016AD08() {}

extern "C" void fn_8016AD0C() {}

extern "C" int fn_801719B4(void* param_1, void* param_2) {
    if (param_2 == 0) {
        return 0;
    }
    if (*(u8*)((u8*)param_1 + 0x1b1) != 0 && *(void**)((u8*)param_1 + 0x1ac) != 0) {
        void* obj = *(void**)((u8*)param_1 + 0x1ac);
        (*(void (**)(void*, int))(*(u32*)obj + 8))(obj, 1);
    }
    *(u8*)((u8*)param_1 + 0x1b1) = 0;
    *(void**)((u8*)param_1 + 0x1ac) = param_2;
    return 1;
}

extern "C" u8 lbl_80301ADC;
extern "C" void fn_801721F0(u8* p) {
    *p = lbl_80301ADC;
}

extern "C" void fn_80172464(void)
{
}

extern "C" u32 fn_801725E4(void) { return 0x10; }

extern "C" void fn_801725EC(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" unsigned short fn_80172614(int param_1) {
    return *(unsigned short*)(param_1 + 0x14);
}

extern "C" s32 fn_80172640(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" void fn_8017288C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" unsigned short fn_801728B4(int param_1) {
    return *(unsigned short*)(param_1 + 0x14);
}

extern "C" s32 fn_801728E0(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" void fn_80172974(u8* p, s32 i, u8 v) {
    p[i + 0xa8] = v;
}

extern "C" u8 fn_80172980(u8* p, s32 i) {
    return p[i + 0xa8];
}

extern "C" void fn_8017298C(u8* p, s32 i, u8 v) {
    p[i + 0xb0] = v;
}

extern "C" unsigned char fn_80172998(int param_1, int param_2) {
    return ((unsigned char*)(param_1 + 0xb0))[param_2];
}

extern "C" void fn_801729A4(int param_1, unsigned char param_2) {
    *(unsigned char*)(param_1 + 0x56) = param_2;
}

extern "C" unsigned char fn_801729AC(int param_1) {
    return *(unsigned char*)(param_1 + 0x56);
}

extern "C" void fn_801729B4(u8* p, s32 i, u8* src) {
    u8* d = p + i * 8;
    d[0x58] = src[1];
    d[0x59] = src[2];
    d[0x5a] = src[3];
    d[0x5c] = src[5];
    d[0x5d] = src[6];
    d[0x5e] = src[7];
}

extern "C" s32 fn_801729F0(s32 p, s32 i) {
    return p + i * 8 + 0x57;
}

extern "C" void fn_80172A04(u8* p, s32 i, s8* src) {
    p += i * 8;
    u8 a = src[0];
    p[0x5e] = (p[0x5e] & ~0xC) | ((u8)src[1] << 2);
    p[0x5e] = (p[0x5e] & ~0x3) | a;
}

extern "C" void fn_80172B2C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" s32 fn_80172BC0(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 8 + 0x1e;
}

extern "C" s32 fn_80172C00(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 4 + 0x60;
}

extern "C" void fn_80172C2C(u8* param_1, u32 param_2, u8 param_3) {
    (param_1 + param_2)[0x74] = param_3;
}

extern "C" u8 fn_80172C38(u8* param_1, u32 param_2) {
    return (param_1 + param_2)[0x74];
}

extern "C" s32 fn_80172CEC(s32 p, s32 i) {
    return p + i + 0x78;
}

extern "C" void fn_80172CFC(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x7c))[p2] = *p3; }

extern "C" s32 fn_80172D10(s32 p, s32 i) {
    return p + i * 4 + 0x7c;
}

extern "C" u32 fn_80172DBC(void) { return 0x54564232; }

extern "C" void fn_80172DD0(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u8* fn_80172E24(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" u8 fn_80172EC4(u8* p, s32 i) { return *(p + i + 0x54); }

extern "C" void fn_80172ED0(u8* p, s32 i, u8 v) { *(p + i + 0x56) = v; }

extern "C" u8 fn_80172EDC(u8* p, s32 i) { return *(p + i + 0x56); }

extern "C" void fn_80172FA0(u8* p, s32 i, u32* src)
{
	((u32*)(p + 0x5c))[i] = *src;
}

extern "C" s32 fn_80172FB4(s32 p, s32 i)
{
	return p + i * 4 + 0x5c;
}

extern "C" u32 fn_80172FF8(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    u32* p = (u32*)(param_1 + param_2 * 4);
    return p[0x64 / 4];
}

extern "C" u32 fn_80173018(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    u8* p = (u8*)param_1 + param_2 * 4;
    return *(u32*)(p + 0x6c);
}

extern "C" unsigned int fn_80173060(void) {
    return 0x54564231;
}

extern "C" void fn_80173074(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" void fn_801730A4(int param_1, int param_2, u8* param_3) {
    u8 uVar0 = param_3[0];
    u8* p = (u8*)(param_1 + param_2 * 4);
    p[8] = uVar0;
    p[9] = param_3[1];
    p[10] = param_3[2];
}

extern "C" s32 fn_801730C8(s32 p, s32 i)
{
	return p + i * 4 + 8;
}

extern "C" void fn_801730DC(u8* p, s32 i, s16* src)
{
	s16 v0;
	s16 v1;
	s16 v2;
	s16 v3;
	s16* q;

	v0 = src[0];
	q = (s16*)(p + i * 8);
	v1 = src[1];
	q[6] = v0;
	v2 = src[2];
	q[7] = v1;
	v3 = src[3];
	q[8] = v2;
	q[9] = v3;
}

extern "C" u8* fn_80173108(u8* p, s32 i)
{
    return p + i * 8 + 0xc;
}

extern "C" void fn_8017311C(u8* p, s32 i, u8* src)
{
    u8* dst = p + i * 4;
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

extern "C" void fn_80173300(void)
{
}

extern "C" void fn_80173304(void)
{
}

extern "C" void fn_80173308(void)
{
}

extern "C" void fn_8017330C(void)
{
}

extern "C" void fn_80173310(void)
{
}

extern "C" void fn_80173314(void)
{
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

extern "C" void* fn_80174B70(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B88(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BB8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" u8 fn_80177F0C(char* self, void* arg)
{
    char* n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        if ((*(UnkVObj_80166424**)(n + 0xc))->vf18(arg)) {
            return 1;
        }
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
    return 0;
}

extern "C" void fn_801780D4(char* self, u8 v)
{
    char* n;
    *(u8*)(self + 0xb1) = v;
    n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        (*(UnkVObj_80166424**)(n + 0xc))->vf6(v);
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
}

extern "C" void* fn_80178424(char* self)
{
    char* l = *(char**)(self + 0xdc);
    char* n = l;
    if (l != 0) {
        n = l - 0xc;
    }
    if (n == 0) {
        return 0;
    }
    if (l != 0) {
        l -= 0xc;
    }
    return *(void**)(l + 0xc);
}

extern "C" void fn_80178DA4(void* param_1)
{
}

extern "C" void fn_80178DB0(void* param_1) {
    register void* vtable = *(void**)param_1;
    void (*func)(void) = *(void(**)(void))((u8*)vtable + 0x74);
    func();
}

extern "C" u32 fn_80178E08(void) { return 0x10; }

extern "C" int fn_80178E4C(int param_1) {
    *(u8*)(param_1 + 0xb5) = 0;
    return 0;
}

extern "C" void fn_80178E5C(void* param_1)
{
}

extern "C" void fn_80178E60(void) {
}

