#include "types.h"
#include "types.h"
extern "C" void fn_80191388(int, void*);
extern "C" void fn_80191220(int, void*);
extern "C" void* lbl_8029AA18[];
extern void* lbl_8029A0D4[];
extern u32 lbl_80301CF8;

extern "C" void* lbl_8029AF34[];
extern void* lbl_8029A150[];
extern "C" void fn_801A605C(int, void*);
extern "C" void fn_801BC250(int, int);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80196344-0x801a537c (574 functions). split_file divides it into the game's real files.
extern "C" u8 fn_801A602C(u32 p);
extern "C" u16 fn_801A6050(u32 p);
extern "C" void fn_801915BC(u8 a, void* b, f32 c, f32 d, f32 e, f32 f);
extern "C" void fn_80191924(u8 a, u16 b, void* c);
extern "C" void fn_801E012C(void);

extern "C" void fn_801A7E24(int);
extern "C" void fn_801A7D78(void* p);
struct NaviSrc4 { u16 a; u8 b, c; };
struct NaviRect16 { s16 x, y, w, h; };
struct NaviColor8 { u8 r, g, b, a; };
struct NaviBytes4 { u8 b[4]; };
typedef void (*NaviVFn)(void* self);
extern u8 lbl_802EE470[];
extern "C" void fn_80193D9C(u32* p);
extern "C" void fn_80193DFC(u32* p);
extern "C" void fn_80198620(u8* p);
struct NaviRectHolder {
    u8 unk_0x0[0xda];
    NaviRect16 rects[4];
    NaviColor8 colors[4];
};
extern void* lbl_80299E68[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80196388(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299E68;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801979BC(int param_1) {
    int size = 0;
    switch (param_1) {
    case 0:
        size = 0x20;
        break;
    case 0x40000000:
        size = 0x4c;
        break;
    case (int)0x80000000:
        size = 0x28;
        break;
    }
    return size;
}

extern "C" int fn_80197A0C(int param_1) {
    int size = 0x6c;
    switch (param_1) {
    case 0:
        break;
    case 0x8000000:
        return 0x6c;
    }
    return size;
}

extern "C" int fn_80197A38(int param_1) {
    int size = 0;
    if (param_1 <= 1) {
        size = 0x1c;
    } else if (param_1 == 2) {
        size = 0x6c;
    } else if (param_1 <= 4) {
        size = 0x94;
    } else if (param_1 <= 0x10) {
        size = 0x174;
    }
    return size;
}

extern "C" u32 fn_80197A80(int param_1) {
    if (param_1 != 0) {
        return 0x7c;
    }
    return 4;
}

extern "C" u32 fn_80197A94(u32 param_1, u32 param_2) {
    u32 r5 = 0;
    if (param_1 == 0) {
        if (param_2 & 1) {
            r5 = 4;
        } else if (param_2 & 2) {
            r5 = 4;
        } else if (param_2 & 4) {
            r5 = 4;
        }
    } else if (param_1 == 0x10000000) {
        r5 = 0x40;
    } else if (param_1 == 0x20000000) {
        r5 = 0x10;
    }
    return r5;
}

extern "C" void fn_80197AFC(void* param_1) {
    u8* p = (u8*)param_1;
    *(u32*)(p + 0x8) = 0;
    *(u32*)(p + 0x4) = 0;
    *(u32*)(p + 0xc) = 0;
    *(u32*)(p + 0x10) = 1;
    *(u16*)(p + 0x14) = 0xffff;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x24) = 0;
    *(u32*)(p + 0x28) = 0;
    *(u32*)(p + 0x2c) = 0;
    *(u32*)(p + 0x30) = 0;
    *(u32*)(p + 0x34) = 0;
    *(u32*)(p + 0x38) = 0;
    *(u32*)(p + 0x3c) = 0;
    *(u32*)(p + 0x48) = 0;
}

typedef u32 (*NaviVFunc)(void*);
struct NaviVObj {
    virtual void vf0(void);
    virtual void vf1(void);
    virtual void vf2(void);
    virtual void vf3(void);
    virtual void vf4(void);
    virtual u32 vf5(void);
    virtual void vf6(void);
    virtual void vf7(void);
    virtual u32 vf8(void);
    virtual void vf9(void);
    virtual u32 vf10(void);
    virtual void vf11(void);
    virtual u32 vf12(void);
    virtual void vf13(void);
    virtual void vf14(void);
    virtual void vf15(void);
    virtual void vf16(void);
    virtual u32 vf17(void);
};
extern "C" u32 fn_80197B4C(void* param_1) {
    u8* p = (u8*)param_1;
    void* obj;
    u32 a;
    u32 b;
    u32 c;
    obj = *(void**)(p + 0x28);
    a = (*(NaviVFunc**)obj)[0x30 / 4](obj);
    obj = *(void**)(p + 0x24);
    b = (*(NaviVFunc**)obj)[0x28 / 4](obj);
    obj = *(void**)(p + 0x2c);
    a += (*(NaviVFunc**)obj)[0x44 / 4](obj);
    obj = *(void**)(p + 0x30);
    a += (*(NaviVFunc**)obj)[0x14 / 4](obj);
    obj = *(void**)(p + 0x34);
    c = (*(NaviVFunc**)obj)[0x20 / 4](obj);
    return (b + (a + c + 0x1f)) & ~0x1f;
}

extern "C" void fn_80198298(u8* param_1) {
    *(u32*)(*(u8**)(lbl_802EE470 + 0x3c) + 0x34) = *(u32*)(param_1 + 0x20);
    fn_80193D9C((u32*)*(u32*)(*(u8**)(lbl_802EE470 + 0x3c) + 0x20));
    ((NaviVObj*)*(void**)(param_1 + 0x2c))->vf10();
    ((NaviVObj*)*(void**)(param_1 + 0x24))->vf4();
    ((NaviVObj*)*(void**)(param_1 + 0x28))->vf8();
    fn_80193DFC((u32*)*(u32*)(*(u8**)(lbl_802EE470 + 0x3c) + 0x20));
}

extern "C" void fn_801985AC(u8* param_1) {
    if ((*(u32*)(lbl_802EE470 + 0x34) & 0x40000000) == 0) {
        ((NaviVObj*)*(void**)(param_1 + 0x28))->vf4();
    } else {
        ((NaviVObj*)*(void**)(param_1 + 0x28))->vf6();
    }
}

extern "C" void fn_80198608(u8* param_1) {
    u8* p = *(u8**)(param_1 + 8);
    *(u32*)(p + 0x40) = *(u32*)(param_1 + 0x40);
    *(u32*)(p + 0x44) = *(u32*)(param_1 + 0x44);
}

extern "C" void fn_801989A4(u8* param_1) {
    if ((*(u32*)(param_1 + 0x20) & 0xC0000000) != 0) {
        return;
    }
    *(u32*)(param_1 + 0x20) |= 0x80000000;
    *(u32*)(param_1 + 0x3C) = 0;
}

extern "C" void* fn_8015A90C(u32 size);
extern "C" int fn_80193B74(void* p, u32 v);
extern "C" int fn_801989C4(u8* param_1, u32 param_2) {
    u8* p;
    int r;
    if (*(u32*)(param_1 + 0x48) == 0) {
        p = (u8*)fn_8015A90C(0x10);
        if (p != 0) {
            *(u32*)(p + 0x0) = 0;
            *(u32*)(p + 0x4) = 0;
            *(u32*)(p + 0x8) = 0;
            *(u32*)(p + 0xc) = 0;
        }
        *(u8**)(param_1 + 0x48) = p;
        if (*(u32*)(param_1 + 0x48) == 0) {
            return 4;
        }
        r = fn_80193B74(*(u8**)(param_1 + 0x48), param_2);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

extern "C" int fn_80193BD4(void* p, u32 v);
extern "C" int fn_80198A58(u8* param_1, u32 param_2) {
    u8* p;
    int r;
    if (*(u32*)(param_1 + 0x48) == 0) {
        p = (u8*)fn_8015A90C(0x10);
        if (p != 0) {
            *(u32*)(p + 0x0) = 0;
            *(u32*)(p + 0x4) = 0;
            *(u32*)(p + 0x8) = 0;
            *(u32*)(p + 0xc) = 0;
        }
        *(u8**)(param_1 + 0x48) = p;
        if (*(u32*)(param_1 + 0x48) == 0) {
            return 4;
        }
        r = fn_80193BD4(*(u8**)(param_1 + 0x48), param_2);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

extern "C" void fn_80198AEC(void* param_1) {
    u8* p = (u8*)param_1;
    *(u32*)(p + 0x8) = 0;
    *(u32*)(p + 0x4) = 0;
    *(u32*)(p + 0xc) = 0;
    *(u32*)(p + 0x10) = 1;
    *(u16*)(p + 0x14) = 0xffff;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x24) = 0;
    *(u32*)(p + 0x28) = 0;
    *(u32*)(p + 0x2c) = 0;
    *(u32*)(p + 0x30) = 0;
    *(u32*)(p + 0x34) = 0;
    *(u32*)(p + 0x38) = 0;
    *(u32*)(p + 0x3c) = 0;
    *(u32*)(p + 0x48) = 0;
}

extern "C" void fn_80198B3C(void) {
}

extern "C" void fn_80198B40(void) {
}

extern u8 lbl_802EE470[];
extern "C" void fn_80193CB4(void* param_1);
extern "C" void fn_80198B44(void* param_1) {
    *(u32*)(lbl_802EE470 + 0x54) = *(u32*)((u8*)param_1 + 0x10);
    if (*(volatile u32*)(lbl_802EE470 + 0x34) & 2) {
        return;
    }
}

extern "C" void fn_80198B60(void* param_1) {
    *(u32*)(lbl_802EE470 + 0x54) = *(u32*)((u8*)param_1 + 0x10);
    if (!(*(volatile u32*)(lbl_802EE470 + 0x34) & 2)) {
        fn_80193CB4(*(void**)((u8*)param_1 + 0x48));
    }
}

extern "C" void fn_80198BA0(void) {
}

extern "C" void fn_80198BA4(void) {
}

extern "C" void fn_80198BA8(void* param_1) {
    u8* p = (u8*)param_1;
    *(u32*)(p + 0x8) = 0;
    *(u32*)(p + 0x4) = 0;
    *(u32*)(p + 0xc) = 0;
    *(u32*)(p + 0x10) = 1;
    *(u16*)(p + 0x14) = 0xffff;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x24) = 0;
    *(u32*)(p + 0x28) = 0;
    *(u32*)(p + 0x2c) = 0;
    *(u32*)(p + 0x30) = 0;
    *(u32*)(p + 0x34) = 0;
    *(u32*)(p + 0x38) = 0;
    *(u32*)(p + 0x3c) = 0;
    *(u32*)(p + 0x48) = 0;
}

extern "C" void fn_80198BF8(void) {
}

extern "C" void fn_80198BFC(void) {
}

extern "C" void fn_80198C00(void* param_1) {
    *(u32*)(lbl_802EE470 + 0x54) = *(u32*)((u8*)param_1 + 0x10);
    if (*(volatile u32*)(lbl_802EE470 + 0x34) & 2) {
        return;
    }
}

extern "C" void fn_80198C1C(void* param_1) {
    *(u32*)(lbl_802EE470 + 0x54) = *(u32*)((u8*)param_1 + 0x10);
    if (!(*(volatile u32*)(lbl_802EE470 + 0x34) & 2)) {
        fn_80193CB4(*(void**)((u8*)param_1 + 0x48));
    }
}

extern "C" void fn_80198C5C(void) {}

extern "C" void fn_80198C60(void) {}

extern "C" void fn_80198C64(void) {}

extern "C" void fn_80198C68(void) {
}

extern "C" void fn_80198C6C(void) {
}

extern "C" void* fn_80198C70(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AF34;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A150;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029A150[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80198CCC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A150;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80198D14(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AA18;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A0D4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029A0D4[];
extern "C" void* fn_80198D70(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A0D4;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029AE58[];
extern "C" void* fn_80198DB8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AE58;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029A078[];
extern "C" void* fn_80198E00(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A078;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299F88[];
extern "C" void* fn_80198E48(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299F88;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_80198E90()
{
	return 0;
}

extern "C" int fn_80198E98()
{
	return 0;
}

extern "C" int fn_80198EA0()
{
	return 0;
}

extern "C" int fn_80198EA8()
{
	return 0;
}

extern "C" int fn_80198EB0()
{
	return 0;
}

extern "C" void fn_80198EB8()
{
}

extern "C" u32 fn_80198EBC(void) {
    return 2;
}

extern "C" void fn_80198EC4()
{
}

extern "C" int fn_80198EC8()
{
	return 0;
}

extern "C" void fn_80198ED0()
{
}

extern "C" void fn_80198ED4(void) {
}

extern "C" void fn_80198ED8(void) {
}

extern "C" void fn_80198EDC(void) {
}

extern "C" void fn_80198EE0(void) {
}

extern "C" void fn_80198EE4(void) {}

extern "C" void fn_80198EE8(void) {}

extern "C" void fn_80198EEC(void) {}

extern "C" void fn_80198EF0(void) {
    return;
}

extern "C" void fn_80198EF4(void) {
    return;
}

extern "C" void fn_80198EF8(void) {
    return;
}

extern "C" void fn_80198EFC(void) {}

extern "C" void fn_80198F00(void) {}

extern "C" void fn_80198F04(void) {}

extern "C" void fn_80198F08(void) {}

extern "C" void fn_80198F0C()
{
}

extern "C" void fn_80198F10()
{
}

extern "C" void fn_80198F14()
{
}

extern "C" int fn_80198F18()
{
	return 0;
}

extern "C" int fn_80198F20()
{
	return 0;
}

extern "C" void fn_80198F28(void) {}

extern "C" void fn_80198F2C(void) {}

extern "C" void fn_80198F30(void) {}

extern "C" void fn_80198F34(void) {}

extern "C" u32 fn_80198F38(void) {
    return 0x49424C4E;
}

extern void* lbl_8029A02C[];
extern "C" void* fn_80198F44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A02C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A078;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80198FA0(void) {}

extern "C" void fn_80198FA4(void) {}

extern "C" void fn_80198FA8(void) {}

extern "C" void fn_80198FAC(void) {}

extern "C" void fn_80198FB0(void) {}

extern "C" void fn_80198FB4(void) {}

extern "C" void fn_80198FB8(void) {}

extern "C" void fn_80198FBC(void) {}

extern "C" int fn_80198FC0()
{
	return 0;
}

extern "C" void fn_80198FC8(void) {}

extern "C" void fn_80198FCC(void) {}

extern "C" void fn_80198FD0(void) {}

extern "C" void fn_80198FD4(void) {}

extern "C" void fn_80198FD8(void) {}

extern "C" void fn_80198FDC(void) {}

extern "C" void fn_80198FE0(void) {}

extern "C" void fn_80198FE4(void) {}

extern "C" void fn_80198FE8(void) {
}

extern "C" int fn_80198FEC()
{
	return 0;
}

extern "C" void fn_80198FF4(void)
{
}

extern "C" int fn_80198FF8()
{
	return 0;
}

extern "C" int fn_80199000()
{
	return 0;
}

extern "C" void fn_80199008(void)
{
}

extern "C" void fn_8019900C(void)
{
}

extern "C" void fn_80199010(void* param_1) {
    u8* p = (u8*)param_1;
    u32 a = lbl_80301CF8;
    u32 zero = 0;
    u32 tmp = a;
    u8* t = (u8*)&tmp;
    p[0xc] = zero;
    p[4] = t[0];
    p[5] = t[1];
    p[6] = t[2];
    p[7] = t[3];
    tmp = a;
    p[8] = t[0];
    p[9] = t[1];
    p[0xa] = t[2];
    p[0xb] = t[3];
    *(u32*)(p + 0x18) = zero;
    *(u32*)(p + 0x1c) = zero;
}

extern u32 lbl_80301CF8;
extern u32 lbl_80301CFC;
extern "C" void fn_80199078(void* param_1) {
    u8* p = (u8*)param_1;
    u32 a = lbl_80301CF8;
    u32 b = lbl_80301CFC;
    u32 tmp = a;
    u8* t = (u8*)&tmp;
    p[0xc] = 0;
    p[4] = t[0];
    p[5] = t[1];
    p[6] = t[2];
    p[7] = t[3];
    tmp = a;
    p[8] = t[0];
    p[9] = t[1];
    p[0xa] = t[2];
    p[0xb] = t[3];
    tmp = b;
    p[0x20] = t[0];
    p[0x21] = t[1];
    p[0x22] = t[2];
    p[0x23] = t[3];
    tmp = b;
    p[0x24] = t[0];
    p[0x25] = t[1];
    p[0x26] = t[2];
    p[0x27] = t[3];
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
}

extern "C" void fn_80199200(void* param_1) {
    s32* p = (s32*)param_1;
    p[1] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[18] = 0;
    p[19] = 0;
    p[20] = 0;
    p[21] = 0;
    p[22] = 0;
}

extern "C" void fn_80199230(void* param_1) {
    s32* p = (s32*)param_1;
    p[1] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[22] = 0;
}

extern "C" void fn_80199250(void* param_1) {
    s32* p = (s32*)param_1;
    p[1] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[18] = 0;
    p[19] = 0;
    p[20] = 0;
    p[21] = 0;
    p[22] = 0;
}

extern "C" void fn_80199280(void* param_1) {
    s32* p = (s32*)param_1;
    p[1] = 0;
}

extern "C" void fn_80199450(u8* p) {
    *(u16*)(p + 0x8) = 0xffff;
    p[0xe] = 0xc0;
    p[0x12] = 0xc1;
    *(u32*)(p + 0x4) = 0;
}

extern "C" void fn_80199984(void* param_1) {
    *(u8*)((char*)param_1 + 4) = 0;
}

extern "C" void fn_80199990(u8 *p)
{
	*(u16 *)(p + 0x4) = 0xffff;
	*(u16 *)(p + 0xc) = 0xffff;
	p[0xe] = 0xff;
	p[0xf] = 1;
}

extern "C" void fn_801999B4(u8 *p)
{
	*(u16 *)(p + 0x30) = 0xffff;
	*(u16 *)(p + 0x38) = 0xffff;
	p[0x3a] = 0xff;
	p[0x3b] = 1;
	*(u32 *)(p + 0x3c) = 0;
}

extern "C" int fn_801999E0(void)
{
	return 0x22;
}

extern "C" s32 fn_801999E8(void) {
    return 0x2f;
}

extern "C" s32 fn_801999F0(void) {
    return 0x26f;
}

extern "C" s32 fn_801999F8(void) {
    return 0x1a8;
}

extern "C" u32 fn_80199A00(void) {
    return 0xfe;
}

extern "C" u32 fn_80199A08(void) {
    return 0x1f2;
}

extern "C" u32 fn_80199A10(void) {
    return 0x230;
}

extern "C" int fn_80199A18(void)
{
	return 0x69;
}

extern "C" int fn_80199A20(void)
{
	return 0x14f;
}

extern "C" int fn_80199A28() {
    return 0x244;
}

extern "C" int fn_80199A30() {
    return 0x3e8;
}

extern "C" int fn_80199A38() {
    return 0x8c;
}

extern "C" int fn_80199A40() {
    return 0x1e;
}

extern "C" int fn_80199A48() {
    return 0x1e;
}

extern "C" int fn_80199A50() {
    return 0x1e;
}

extern "C" int fn_80199A58() {
    return 0x1e;
}

extern "C" s32 fn_80199A60(void) {
    return 0x55;
}

extern "C" void fn_8019ACF0(NaviVObj* p) {
    p->vf3();
    p->vf4();
}

extern "C" void fn_8019B320(NaviVObj* p) {
    p->vf3();
    p->vf4();
}

extern "C" void fn_8019B97C(NaviVObj* p, u32 flags) {
    if (flags & 1) {
        p->vf6();
    }
    if (flags & 2) {
        p->vf7();
    }
}

extern "C" void fn_8019B9E4(int param_1)
{
	extern int* lbl_802FFA80;
	extern int lbl_802FE708;
	extern void fn_801E012C(void);
	u32 w;

	if ((u32)(lbl_802FFA80[2] + lbl_802FE708) > (u32)lbl_802FFA80[3]) {
		fn_801E012C();
	}
	*(*(u8**)&lbl_802FFA80[2])++ = 0x10;
	*(*(u8**)&lbl_802FFA80[2])++ = 0;
	*(*(u8**)&lbl_802FFA80[2])++ = 1;
	*(*(u8**)&lbl_802FFA80[2])++ = 0x10;
	*(*(u8**)&lbl_802FFA80[2])++ = 0xc;

	w = *(u32*)(param_1 + 4);
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
	*(*(u8**)&lbl_802FFA80[2])++ = w;

	w = *(u32*)(param_1 + 8);
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
	*(*(u8**)&lbl_802FFA80[2])++ = w;
}

extern "C" void fn_8019BF64(NaviVObj* p, u32 flags) {
    if (flags & 1) {
        p->vf6();
    }
    if ((flags & 2) || ((flags >> 4) & 0xf)) {
        p->vf7();
    }
}

extern "C" void fn_8019BFD4(int param_1)
{
	extern int* lbl_802FFA80;
	extern int lbl_802FE708;
	extern void fn_801E012C(void);
	u32 w;

	if ((u32)(lbl_802FFA80[2] + lbl_802FE708) > (u32)lbl_802FFA80[3]) {
		fn_801E012C();
	}
	*(*(u8**)&lbl_802FFA80[2])++ = 0x10;
	*(*(u8**)&lbl_802FFA80[2])++ = 0;
	*(*(u8**)&lbl_802FFA80[2])++ = 1;
	*(*(u8**)&lbl_802FFA80[2])++ = 0x10;
	*(*(u8**)&lbl_802FFA80[2])++ = 0xc;

	w = *(u32*)(param_1 + 4);
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
	*(*(u8**)&lbl_802FFA80[2])++ = w;

	w = *(u32*)(param_1 + 8);
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
	*(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
	*(*(u8**)&lbl_802FFA80[2])++ = w;
}

extern "C" void fn_8019C584(int param_1)
{
	extern int* lbl_802FFA80;
	extern void fn_801A598C(u32, u32);
	extern void fn_801A5454(u32, void*);
	*(int *)(param_1 + 0x58) = lbl_802FFA80[2] - lbl_802FFA80[0];

	int p = param_1;
	int q = param_1;
	unsigned int i = 0;
	do {
		if (*(u32 *)(p + 0x38) != 0 && *(unsigned char *)(q + 10) != 0x3c) {
			fn_801A598C(*(u32 *)(p + 0x38), i);
		}
		i++;
		p += 4;
		q += 6;
	} while (i < 4);

	if (*(u32 *)(param_1 + 4) != 0) {
		fn_801A5454(*(u32 *)(param_1 + 4), (void *)(param_1 + 8));
	}
}

extern "C" void fn_8019C62C(int param_1)
{
	extern int* lbl_802FFA80;
	extern void fn_801A598C(u32, u32);
	extern void fn_801A5454(u32, void*);
	*(int *)(param_1 + 0x58) = lbl_802FFA80[2] - lbl_802FFA80[0];

	int p = param_1;
	int q = param_1;
	unsigned int i = 0;
	do {
		if (*(u32 *)(p + 0x38) != 0 && *(unsigned char *)(q + 10) != 0x3c) {
			fn_801A598C(*(u32 *)(p + 0x38), i);
		}
		i++;
		p += 4;
		q += 6;
	} while (i < 8);

	if (*(u32 *)(param_1 + 4) != 0) {
		fn_801A5454(*(u32 *)(param_1 + 4), (void *)(param_1 + 8));
	}
}

extern "C" void fn_8019C6D4(int param_1)
{
	extern int* lbl_802FFA80;
	extern void fn_801A598C(u32, u32);
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 0x58);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];

	int p = param_1;
	unsigned int i = 0;
	do {
		if (*(u32 *)(p + 0x38) != 0) {
			fn_801A598C(*(u32 *)(p + 0x38), i);
		}
		i++;
		p += 4;
	} while (i < 8);

	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_8019C764(int param_1)
{
	extern int* lbl_802FFA80;
	extern void fn_801A598C(u32, u32);
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 0x58);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];

	int p = param_1;
	int q = param_1;
	unsigned int i = 0;
	do {
		if (*(u32 *)(p + 0x38) != 0 && *(unsigned char *)(q + 10) != 0x3c) {
			fn_801A598C(*(u32 *)(p + 0x38), i);
		}
		i++;
		p += 4;
		q += 6;
	} while (i < 4);

	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_8019C810(int param_1)
{
	extern int* lbl_802FFA80;
	extern void fn_801A598C(u32, u32);
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 0x58);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];

	int p = param_1;
	int q = param_1;
	unsigned int i = 0;
	do {
		if (*(u32 *)(p + 0x38) != 0 && *(unsigned char *)(q + 10) != 0x3c) {
			fn_801A598C(*(u32 *)(p + 0x38), i);
		}
		i++;
		p += 4;
		q += 6;
	} while (i < 8);

	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_8019C8BC(NaviVObj* p, u32 flags) {
    if ((flags >> 8) & 0xf) {
        p->vf8();
        if (flags & 0x1000) {
            p->vf9();
        }
    }
}

extern "C" void fn_801A598C(u32, u32);
extern "C" void fn_8019C924(int param_1) {
    u8* p = (u8*)param_1;
    u32 i = 0;
    do {
        if (*(u32*)(p + 0x38) != 0) {
            fn_801A598C(*(u32*)(p + 0x38), i);
        }
        i++;
        p += 4;
    } while (i < 8);
}

extern "C" void fn_801A5454(u32, void*);
extern "C" void fn_8019C97C(int param_1) {
    u8* p = (u8*)param_1;
    if (*(u32*)(p + 4) != 0) {
        fn_801A5454(*(u32*)(p + 4), p + 8);
    }
}

extern "C" void fn_8019DB60(int param_1)
{
	extern int* lbl_802FFA80;
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 4);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];
	
	int ptr = param_1;
	unsigned int i = 0;
	do {
		unsigned short check = *(unsigned short *)(ptr + 8);
		if (check != 0xffff) {
			fn_801A605C((int)i, (void *)(ptr + 8));
		}
		i++;
		ptr += 2;
	} while (i < 8);
	
	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_8019DE38(NaviVObj* p) {
    p->vf9();
    p->vf10();
}

extern "C" void fn_8019DE84(int param_1)
{
	extern int* lbl_802FFA80;
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 4);
	lbl_802FFA80[2] = sum;
	unsigned short check = *(unsigned short *)(param_1 + 8);
	int saved = lbl_802FFA80[2];
	
	if (check != 0xffff) {
		fn_801A605C(0, (void *)(param_1 + 8));
	}
	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_801A605C(int, void*);
extern "C" void fn_801BC250(int, int);
extern "C" void fn_8019DEF0(void)
{
	return;
}

extern "C" void fn_8019DFD8(void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14();
    };
    ((Obj*)p)->v9();
}

extern "C" void fn_8019E004(int param_1)
{
	extern int* lbl_802FFA80;
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 4);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];
	
	int ptr = param_1;
	unsigned int i = 0;
	do {
		unsigned short check = *(unsigned short *)(ptr + 8);
		if (check != 0xffff) {
			fn_801A605C((int)i, (void *)(ptr + 8));
		}
		i++;
		ptr += 2;
	} while (i < 2);
	
	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_8019E2C4(NaviVObj* p) {
    p->vf9();
    p->vf10();
}

extern "C" void fn_8019E310(int param_1)
{
	extern int* lbl_802FFA80;
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 4);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];
	
	int ptr = param_1;
	unsigned int i = 0;
	do {
		unsigned short check = *(unsigned short *)(ptr + 8);
		if (check != 0xffff) {
			fn_801A605C((int)i, (void *)(ptr + 8));
		}
		i++;
		ptr += 2;
	} while (i < 4);
	
	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_8019E5E8(NaviVObj* p) {
    p->vf9();
    p->vf10();
}

extern "C" void fn_8019E634(int param_1)
{
	extern int* lbl_802FFA80;
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 4);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];
	
	int ptr = param_1;
	unsigned int i = 0;
	do {
		unsigned short check = *(unsigned short *)(ptr + 8);
		if (check != 0xffff) {
			fn_801A605C((int)i, (void *)(ptr + 8));
		}
		i++;
		ptr += 2;
	} while (i < 8);
	
	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}

extern "C" void fn_8019E90C(NaviVObj* p) {
    p->vf9();
    p->vf10();
}

extern "C" void fn_8019EA14(int param_1) {
    u8* p = (u8*)param_1;
    u32 i = 0;
    do {
        if (*(u16*)(p + 8) != 0xffff) {
            fn_801A605C(i, p + 8);
        }
        i++;
        p += 2;
    } while (i < 8);
}

extern "C" void fn_8019EB78(int param_1) {
    extern int* lbl_802FFA80;
    u32 i;
    u32 n = *(u8*)(param_1 + 0xd0);
    for (i = 0; i < n; i++) {
        u32 w = *(u32*)(param_1 + 0x78) | ((u8)(i + 0x10) << 24);
        u8* out;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = 0x61;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 24;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 16;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 8;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w;
        param_1 += 4;
    }
}

extern "C" void fn_8019EC20(int param_1) {
    struct NaviPair8 {
        u32 a;
        u32 b;
    };
    NaviPair8 pair;
    u32 i;
    u8* p;
    u32 val;
    u32 b;
    u32 a;

    p = (u8*)param_1;
    for (i = 0; i < 3; i++) {
        a = *(u32*)(p + 0x98);
        b = *(u32*)(p + 0x9c);
        pair.a = a;
        pair.b = b;
        fn_80191388(i + 1, &pair);
        p += 8;
    }
    i = 0;
    p = (u8*)param_1;
    for (; i < 4; i++) {
        val = *(u32*)(p + 0xb8);
        fn_80191220(i, &val);
        p += 4;
    }
}

extern "C" void fn_8019EDAC(int param_1)
{
	if (*(unsigned short *)(param_1 + 8) != 0xffff) {
		fn_801A605C(0, (void *)(param_1 + 8));
	}
}

extern "C" void fn_8019EDE0(void) {
}

extern "C" void fn_8019EED4(int param_1) {
    extern int* lbl_802FFA80;
    u32 w = *(u32*)(param_1 + 0x18) | 0x10000000;
    *(*(u8**)&lbl_802FFA80[2])++ = 0x61;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
    *(*(u8**)&lbl_802FFA80[2])++ = w;
}

extern "C" void fn_8019019C(u8, u16, int, int, u16, int, int);
extern "C" u16 lbl_802EE5D4[][4];
extern "C" void fn_8019EF54(int param_1) {
    u16* e = lbl_802EE5D4[*(u8*)(param_1 + 0xb) & 7];
    fn_8019019C(*(u8*)(param_1 + 0xa), e[0], e[2] == 1, 0, e[1], e[3] == 1, 0);
}

extern "C" void fn_8019EFBC(int param_1) {
    u8* p = (u8*)param_1;
    u32 i = 0;
    for (i = 0; i < 2; i++) {
        if (*(u16*)(p + 8) != 0xffff) {
            fn_801A605C(i, p + 8);
        }
        p += 2;
    }
}

extern "C" void fn_8019F018(int param_1) {
    struct NaviPair8 {
        u32 a;
        u32 b;
    };
    NaviPair8 pair;
    u32 i;
    u8* p;
    u32 val;
    u32 b;
    u32 a;

    p = (u8*)param_1;
    for (i = 0; i < 3; i++) {
        a = *(u32*)(p + 0x14);
        b = *(u32*)(p + 0x18);
        pair.a = a;
        pair.b = b;
        fn_80191388(i + 1, &pair);
        p += 8;
    }
    i = 0;
    p = (u8*)param_1;
    for (; i < 4; i++) {
        val = *(u32*)(p + 0x45);
        fn_80191220(i, &val);
        p += 4;
    }
}

extern "C" void fn_8019F1B8(int param_1) {
    extern int* lbl_802FFA80;
    u8 n = *(u8*)(param_1 + 0x34);
    u32 i;
    u8* p = (u8*)param_1;
    for (i = 0; i < n; i++) {
        u32 w = *(u32*)(p + 0x60) | ((i + 0x10) << 24);
        u8* out;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = 0x61;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 24;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 16;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 8;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w;
        p += 4;
    }
}

extern "C" void fn_8019F324(int param_1) {
    u8* p = (u8*)param_1;
    u32 i = 0;
    do {
        if (*(u16*)(p + 8) != 0xffff) {
            fn_801A605C(i, p + 8);
        }
        i++;
        p += 2;
    } while (i < 4);
}

extern "C" void fn_8019F380(int param_1) {
    struct Pair { u32 a, b; };
    u32 i;
    u8* p;
    u32 word;
    for (i = 0, p = (u8*)param_1; i < 3; i++, p += 8) {
        Pair pair = *(Pair*)(p + 0x42);
        fn_80191388(i + 1, (u32*)&pair);
    }
    for (i = 0, p = (u8*)param_1; i < 4; i++, p += 4) {
        word = *(u32*)(p + 0x62);
        fn_80191220(i, &word);
    }
}

extern "C" void fn_8019F520(int param_1) {
    extern int* lbl_802FFA80;
    u8 n = *(u8*)(param_1 + 0x20);
    u32 i;
    u8* p = (u8*)param_1;
    for (i = 0; i < n; i++) {
        u32 w = *(u32*)(p + 0x80);
        w |= (i + 0x10) << 24;
        u8* out;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = 0x61;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 24;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 16;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 8;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w;
        p += 4;
    }
}

extern "C" void fn_8019F6BC(int param_1) {
    u8* p = (u8*)param_1;
    u32 i = 0;
    do {
        if (*(u16*)(p + 8) != 0xffff) {
            fn_801A605C(i, p + 8);
        }
        i++;
        p += 2;
    } while (i < 8);
}

extern "C" void fn_8019F718(int param_1) {
    u32 pair[2];
    u32 word;
    u32 i = 0;
    u8* p = (u8*)param_1;
    do {
        u32 a = *(u32*)(p + 0xda);
        u32 b = *(u32*)(p + 0xde);
        pair[0] = a;
        pair[1] = b;
        fn_80191388(i + 1, pair);
        i++;
        p += 8;
    } while (i < 3);
    i = 0;
    p = (u8*)param_1;
    do {
        word = *(u32*)(p + 0xfa);
        fn_80191220(i, &word);
        i++;
        p += 4;
    } while (i < 4);
}

extern "C" void fn_8019F8B8(int param_1) {
    extern int* lbl_802FFA80;
    u32 i = 0;
    u8 n = *(u8*)(param_1 + 0x58);
    u8* p = (u8*)param_1;
    for (i = 0; i < n; i++) {
        u32 w = *(u32*)(p + 0x130) | ((i + 0x10) << 24);
        u8* out;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = 0x61;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 24;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 16;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w >> 8;
        out = (u8*)lbl_802FFA80[2];
        lbl_802FFA80[2] = (int)(out + 1);
        *out = w;
        p += 4;
    }
}

extern "C" void fn_801A6214(int, void*);
#pragma use_lmw_stmw off
extern "C" void fn_8019FA54(int param_1)
{
	extern int* lbl_802FFA80;
	int base = lbl_802FFA80[0];
	int sum = base + *(int *)(param_1 + 4);
	lbl_802FFA80[2] = sum;
	int saved = lbl_802FFA80[2];

	int ptr = param_1;
	int off = 0;
	unsigned int i = 0;
	do {
		unsigned short check = *(unsigned short *)(ptr + 8);
		if (check != 0xffff) {
			lbl_802FFA80[2] = (*(int *)(param_1 + 4)) + (lbl_802FFA80[0] + off);
			fn_801A6214((int)i, (void *)(ptr + 8));
			off += 0x14;
			if (*(u8*)(*(u8**)(*(u8**)(lbl_802EE470 + 0x58) + 4) + *(unsigned short *)(ptr + 8) * 0x20 + 8) == 1) {
				off += 0x23;
			}
		}
		i++;
		ptr += 2;
	} while (i < 8);

	int final = lbl_802FFA80[2];
	fn_801BC250(saved, final - saved);
}
#pragma use_lmw_stmw on
extern "C" void fn_8019FC0C(void* param_1, s32 param_2) {
    extern u32* lbl_802FFA80;
    u32 start;
    u32 cur;
    s32 i = 0;
    u16 val;
    lbl_802FFA80[2] = lbl_802FFA80[0] + param_2;
    start = lbl_802FFA80[2];
    cur = *(volatile u32*)&lbl_802FFA80[2];
    while (true) {
        if (!fn_801A602C(cur)) {
            break;
        }
        val = fn_801A6050(cur);
        fn_801A605C(i, &val);
        i++;
    }
    fn_801BC250(start, lbl_802FFA80[2] - start);
}

extern "C" void fn_801A146C(u8* param_1) {
    extern u32* lbl_802FFA80;
    u32 start;
    u32 local;
    lbl_802FFA80[2] = lbl_802FFA80[0] + *(u32*)(param_1 + 0x3c);
    if ((lbl_802FFA80[2] + 0x37) > lbl_802FFA80[3]) {
        fn_801E012C();
    }
    start = lbl_802FFA80[2];
    local = *(u32*)(param_1 + 0x18);
    fn_801915BC(param_1[4], &local, *(f32*)(param_1 + 0x8), *(f32*)(param_1 + 0xc), *(f32*)(param_1 + 0x10), *(f32*)(param_1 + 0x14));
    fn_80191924(param_1[5], *(u16*)(param_1 + 6), param_1 + 0x1c);
    fn_801BC250(start, lbl_802FFA80[2] - start);
}

extern "C" void fn_801A151C(u8* param_1) {
    extern u32* lbl_802FFA80;
    u32 local;
    if ((lbl_802FFA80[2] + 0x37) > lbl_802FFA80[3]) {
        fn_801E012C();
    }
    local = *(u32*)(param_1 + 0x18);
    fn_801915BC(param_1[4], &local, *(f32*)(param_1 + 0x8), *(f32*)(param_1 + 0xc), *(f32*)(param_1 + 0x10), *(f32*)(param_1 + 0x14));
    fn_80191924(param_1[5], *(u16*)(param_1 + 6), param_1 + 0x1c);
}

extern "C" void fn_801A188C(NaviVObj* p, u32 flags) {
    if (flags & 0x10000000) {
        p->vf4();
    }
    if (flags & 0x20000000) {
        p->vf5();
    }
}

extern "C" void fn_801A34DC(void) {
}

extern "C" void fn_801A34E0(void) {
}

extern "C" void fn_801A34E4(void) {
}

extern "C" void fn_801A34E8(void) {
}

extern "C" void fn_801A34EC(void) {
}

extern "C" u32 fn_801A34F0(void) {
    return 0x5045464c;
}

extern "C" void fn_801A34FC(void* param_1) {
    fn_801A7D78((u8*)param_1 + 4);
}

extern "C" void fn_801A3520(void* param_1) {
    fn_801A7D78((u8*)param_1 + 4);
}

extern "C" int fn_801A3544(int p) { return p + 4; }

extern "C" void fn_801A7D78(void* p);
extern "C" void fn_801A354C(u8* param_1, u8* param_2) {
    u16 a = *(u16*)param_2;
    u8 b;
    u8 c;
    b = param_2[2];
    *(u16*)(param_1 + 0x30) = a;
    c = param_2[3];
    param_1[0x32] = b;
    param_1[0x33] = c;
}

extern "C" void* fn_801A3584(void* param_1) {
    return (u8*)param_1 + 0x30;
}

extern "C" void fn_801A358C(void* param_1, u32* param_2) {
    *(u32*)((u8*)param_1 + 0x34) = *param_2;
}

extern "C" void fn_801A3598(void* param_1, u32* param_2) {
    *(u32*)((u8*)param_1 + 0x34) = *param_2;
}

extern "C" void* fn_801A35A4(void* param_1) {
    return (u8*)param_1 + 0x34;
}

extern "C" void fn_801A35AC(void* param_1, u16* param_2) {
    *(u16*)((u8*)param_1 + 0x38) = *param_2;
}

extern "C" void fn_801A35B8(void* param_1, u16* param_2) {
    *(u16*)((u8*)param_1 + 0x38) = *param_2;
}

extern "C" void* fn_801A35C4(void* param_1) {
    return (u8*)param_1 + 0x38;
}

extern "C" void fn_801A35CC(void* param_1, u8 param_2) {
    *(u8*)((u8*)param_1 + 0x3a) = param_2;
}

extern "C" void fn_801A35D4(void* param_1, u8* param_2) {
    *(u8*)((u8*)param_1 + 0x3a) = *param_2;
}

extern "C" u8 fn_801A35E0(void* param_1) {
    return *(u8*)((u8*)param_1 + 0x3a);
}

extern "C" void fn_801A35E8(u8* param_1, u8 param_2) {
    param_1[0x3b] = param_2;
}

extern "C" void fn_801A35F0(u8* param_1, u8* param_2) {
    param_1[0x3b] = *param_2;
}

extern "C" u8 fn_801A35FC(int param_1) {
    return *(u8*)(param_1 + 0x3b);
}

extern "C" u32 fn_801A3604(void* param_1) {
    return *(u32*)((u8*)param_1 + 0x3c);
}

extern "C" void fn_801A360C(int param_1, u32 param_2) {
    *(u32*)(param_1 + 0x3c) = param_2;
}

extern void* lbl_8029A2C0[];
extern "C" void* fn_801A3614(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A2C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A3670(int* param_1, u32 param_2) {
    if (param_2 & 0x20000000) {
        void (*pfVar1)(int*) = ((void (**)(int*))(*(void**)param_1))[7];
        pfVar1(param_1);
    }
}

extern "C" u32 fn_801A36A4(void) {
    return 0x50454647;
}

extern u32* lbl_802FFA80;
extern "C" u8 fn_801A602C(u32 p);
extern "C" u16 fn_801A6050(u32 p);
extern "C" void fn_801A36B0(int param_1, u8* param_2) {
    u16 h = *(u16*)param_2;
    u8 t = param_2[2];
    *(u16*)(param_1 + 4) = h;
    u8 b = param_2[3];
    *(u8*)(param_1 + 6) = t;
    *(u8*)(param_1 + 7) = b;
}

extern "C" int fn_801A36E8(int p) { return p + 4; }

extern "C" void fn_801A36F0(int param_1, u32* param_2) {
    *(u32*)(param_1 + 8) = *param_2;
}

extern "C" void fn_801A36FC(int param_1, u32* param_2) {
    *(u32*)(param_1 + 8) = *param_2;
}

extern "C" int fn_801A3708(int param_1) {
    return param_1 + 8;
}

extern "C" void fn_801A3710(int param_1, u16* param_2) {
    *(u16*)(param_1 + 0xc) = *param_2;
}

extern "C" void fn_801A371C(int param_1, u16* param_2) {
    *(u16*)(param_1 + 0xc) = *param_2;
}

extern "C" int fn_801A3728(int param_1) {
    return param_1 + 0xc;
}

extern "C" void fn_801A3730(int param_1, u8 param_2) {
    *(u8*)(param_1 + 0xe) = param_2;
}

extern "C" void fn_801A3738(int param_1, u8* param_2) {
    *(u8*)(param_1 + 0xe) = *param_2;
}

extern "C" u8 fn_801A3744(int param_1) {
    return *(u8*)(param_1 + 0xe);
}

extern "C" void fn_801A374C(int param_1, u8 param_2) {
    *(u8*)(param_1 + 0xf) = param_2;
}

extern "C" void fn_801A3754(int param_1, u8* param_2) {
    *(u8*)(param_1 + 0xf) = *param_2;
}

extern "C" u8 fn_801A3760(u8* param_1) {
    return param_1[0xf];
}

extern void* lbl_8029A35C[];
extern "C" void* fn_801A3768(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A35C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A37C4(int param_1) {
    u16 tmp;
    int i = 0;
    lbl_802FFA80[2] = lbl_802FFA80[0] + *(u32*)(param_1 + 4);
    u32 start = *(volatile u32*)&lbl_802FFA80[2];
    u32 p = *(volatile u32*)&lbl_802FFA80[2];
    while (true) {
        if (!fn_801A602C(p)) {
            break;
        }
        tmp = fn_801A6050(p);
        fn_801A605C(i, &tmp);
        i++;
    }
    fn_801BC250(start, lbl_802FFA80[2] - start);
}

extern "C" u32 fn_801A3864(void) { return 0x54563136; }

extern "C" void fn_801A3870(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A3880(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A3894(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void fn_801A38A4(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" void fn_801A38B8(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" u8* fn_801A38CC(u8* p, s32 i) {
    return p + 0x18 + i * 4;
}

extern "C" void fn_801A38E0(u8* p, s32 i, s16* src) {
    s32 off = i << 3;
    *(s16*)(p + off + 0xda) = src[0];
    *(s16*)(p + off + 0xdc) = src[1];
    *(s16*)(p + off + 0xde) = src[2];
    *(s16*)(p + off + 0xe0) = src[3];
}

extern "C" u8* fn_801A3938(u8* p, s32 i) {
    return p + 0xda + i * 8;
}

extern "C" void fn_801A394C(u8* p, s32 i, u8* src) {
    s32 off = i * 4;
    u8 r = src[0];
    u8* base = p + off;
    base[0xfa] = r;
    base[0xfb] = src[1];
    base[0xfc] = src[2];
    base[0xfd] = src[3];
}

extern "C" s32 fn_801A39A4(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 4 + 0xfa;
}

extern "C" void fn_801A39B8(u8* param_1, int param_2, u8 param_3) {
    param_1 += param_2;
    param_1[0x10a] = param_3;
}

extern "C" void fn_801A39C4(u8* param_1, int param_2, u8* param_3) {
    u8 v = *param_3;
    *(param_1 + param_2 + 0x10a) = v;
}

extern "C" u8 fn_801A39D4(u8* param_1, int param_2) {
    return *(param_1 + param_2 + 0x10a);
}

extern "C" void fn_801A39E0(u8* p1, int p2, u8 p3) {
    p1[p2 + 0x11a] = p3;
}

extern "C" void fn_801A39EC(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x11a] = *p3;
}

extern "C" u8 fn_801A39FC(u8* p1, int p2) {
    return p1[p2 + 0x11a];
}

extern "C" void fn_801A3A08(u8* param_1, u8 param_2) {
    param_1[0x58] = param_2;
}

extern "C" void fn_801A3A10(u8* p, u8* src) {
    p[0x58] = src[0];
}

extern "C" u8 fn_801A3A1C(u8* p) {
    return p[0x58];
}

extern "C" void fn_801A3A24(u8* p, u32 i, u8* src) {
    u8 a = src[1];
    u8* d = p + i * 8;
    d[0x5a] = a;
    d[0x5b] = src[2];
    d[0x5c] = src[3];
    d[0x5e] = src[5];
    d[0x5f] = src[6];
    d[0x60] = src[7];
}

extern "C" s32 fn_801A3A9C(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 8 + 0x59;
}

extern "C" void fn_801A3AB0(s32 param_1, s32 param_2, u8* param_3) {
    u8* p = (u8*)(param_1 + param_2 * 8);
    u8 b1 = param_3[1];
    u8 b0 = param_3[0];
    p[0x60] = (p[0x60] & ~0x0C) | ((b1 & 0xFF) << 2);
    p[0x60] = (p[0x60] & ~0x03) | b0;
}

extern "C" void fn_801A3B20(u8* param_1, int param_2, u8* param_3) {
    param_1[param_2 + 0x12a] = *param_3;
}

extern "C" void fn_801A3B30(u8* param_1, int param_2, u8* param_3) {
    param_1[param_2 + 0x12a] = *param_3;
}

extern "C" u8* fn_801A3B40(u8* param_1, int param_2) {
    return (param_1 + 0x12a) + param_2;
}

extern "C" void fn_801A3B50(u8* param_1, int param_2, u32* param_3) {
    ((u32*)(param_1 + 0x130))[param_2] = *param_3;
}

extern "C" void fn_801A3B64(u8* param_1, int param_2, u32* param_3) {
    ((u32*)(param_1 + 0x130))[param_2] = *param_3;
}

extern "C" s32 fn_801A3B78(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 4 + 0x130;
}

extern "C" void* fn_801A3B8C(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" u32 fn_801A3B94(u8* p) {
    return *(u32*)(p + 0x170);
}

extern "C" void fn_801A3B9C(u8* p, u32 v) {
    *(u32*)(p + 0x170) = v;
}

extern void* lbl_8029A400[];
extern "C" void* fn_801A3BA4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A400;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A3C00(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern "C" void fn_801A3C08(void) {
}

extern "C" s32 fn_801A3CAC(void) {
    return 0x54564234;
}

extern "C" void fn_801A3CB8(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A3CC8(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A3CDC(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void fn_801A3CEC(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x10)) = *pv;
}

extern "C" void fn_801A3D00(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x10)) = *pv;
}

extern "C" s32 fn_801A3D14(s32 p, s32 i) {
    return p + i * 4 + 0x10;
}

extern "C" void fn_801A3D28(u8* p, s32 i, s16* src) {
    u8* d = p + (i << 3);
    *(s16*)(d + 0x42) = src[0];
    *(s16*)(d + 0x44) = src[1];
    *(s16*)(d + 0x46) = src[2];
    *(s16*)(d + 0x48) = src[3];
}

extern "C" s32 fn_801A3D80(s32 p, s32 i) {
    return p + i * 8 + 0x42;
}

extern "C" void fn_801A3D94(s32 p, u32 i, u8* src) {
    u8* d = (u8*)(p + (i << 2));
    u8 a = src[0];
    d[0x62] = a;
    d[0x63] = src[1];
    d[0x64] = src[2];
    d[0x65] = src[3];
}

extern "C" int fn_801A3DEC(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 0x62;
}

extern "C" void fn_801A3E00(u8* p, s32 i, u8 v) {
    p[i + 0x72] = v;
}

extern "C" void fn_801A3E0C(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x72] = *p3;
}

extern "C" u8 fn_801A3E1C(u8* p1, int p2) {
    return p1[p2 + 0x72];
}

extern "C" void fn_801A3E28(u8* p1, int p2, u8 p3) {
    p1[p2 + 0x76] = p3;
}

extern "C" void fn_801A3E34(u8* p, s32 i, u8* src) {
    p[i + 0x76] = *src;
}

extern "C" u8 fn_801A3E44(u8* p, s32 i) {
    return p[i + 0x76];
}

extern "C" void fn_801A3E50(u8* p, u8 v) {
    p[0x20] = v;
}

extern "C" void fn_801A3E58(u8* p, u8* src) {
    p[0x20] = *src;
}

extern "C" u8 fn_801A3E64(u8* p) {
    return p[0x20];
}

extern "C" void fn_80191388(int, void*);
extern "C" void fn_80191220(int, void*);
extern "C" void fn_801A3E6C(u8* p, s32 i, u8* src) {
    u8* d = p + (i << 3);
    u8 a = src[1];
    u8 b = src[2];
    d[0x22] = a;
    u8 c = src[3];
    d[0x23] = b;
    b = src[5];
    d[0x24] = c;
    c = src[6];
    d[0x26] = b;
    b = src[7];
    d[0x27] = c;
    d[0x28] = b;
}

extern "C" int fn_801A3EE4(int param_1, int param_2) {
    return param_1 + param_2 * 8 + 0x21;
}

extern "C" void fn_801A3EF8(u8* param_1, s32 param_2, u8* param_3) {
    u8 b1 = param_3[1];
    u8 b0 = param_3[0];
    u8* p = param_1 + param_2 * 8;
    p[0x28] = (p[0x28] & ~0x0c) | ((b1 & 0xff) << 2);
    p[0x28] = (p[0x28] & ~0x03) | b0;
}

extern "C" void fn_801A3F68(int param_1, int param_2, u8* param_3) {
    param_1 += param_2;
    *(u8*)(param_1 + 0x7a) = *param_3;
}

extern "C" void fn_801A3F78(int param_1, int param_2, u8* param_3) {
    param_1 += param_2;
    *(u8*)(param_1 + 0x7a) = *param_3;
}

extern "C" s32 fn_801A3F88(s32 p, s32 i) {
    return p + i + 0x7a;
}

extern "C" void fn_801A3E64_unused_placeholder(void);
extern "C" void fn_801A3F98(u32* p, s32 i, u32* pv) {
    p[i + 0x20] = *pv;
}

extern "C" void fn_801A3FAC(u32* p, s32 i, u32* pv) {
    p[i + 0x20] = *pv;
}

extern "C" s32 fn_801A3FC0(s32 p, s32 i) {
    return p + i * 4 + 0x80;
}

extern "C" void* fn_801A3FD4(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" u32 fn_801A3FDC(u8* p) { return *(u32*)(p + 0x90); }

extern "C" void fn_801A3FE4(int param_1, u32 param_2) {
    *(u32*)(param_1 + 0x90) = param_2;
}

extern void* lbl_8029A4F8[];
extern "C" void* fn_801A3FEC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A4F8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A4048(void) {
}

extern "C" u32 fn_801A40EC(void) { return 0x54564232; }

extern "C" void fn_801A40F8(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A4108(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A411C(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void fn_801A412C(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0xc)) = *pv;
}

extern "C" void fn_801A4140(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0xc)) = *pv;
}

extern "C" int fn_801A4154(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 0xc;
}

extern "C" void fn_801A4168(u8* p, s32 i, s16* src) {
    s16 a = src[0];
    s32 off = i * 8;
    p = p + off;
    s16 b = src[1];
    *(s16*)(p + 0x14) = a;
    s16 c = src[2];
    *(s16*)(p + 0x16) = b;
    s16 e = src[3];
    *(s16*)(p + 0x18) = c;
    *(s16*)(p + 0x1a) = e;
}

extern "C" s32 fn_801A41C0(s32 p, s32 i) {
    return p + i * 8 + 0x14;
}

extern "C" void fn_801A41D4(u8* p, s32 i, u8* src) {
    u8* d = p + i * 4;
    u8 a = src[0];
    d[0x45] = a;
    u8 b = src[1];
    d[0x46] = b;
    u8 c = src[2];
    d[0x47] = c;
    u8 e = src[3];
    d[0x48] = e;
}

extern "C" int fn_801A422C(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 0x45;
}

extern "C" void fn_801A4240(u8* p, s32 i, u8 v) {
    *(p + i + 0x55) = v;
}

extern "C" void fn_801A424C(u8* param_1, int param_2, u8* param_3) {
    param_1[param_2 + 0x55] = *param_3;
}

extern "C" u8 fn_801A425C(u8* param_1, int param_2) {
    return param_1[param_2 + 0x55];
}

extern "C" void fn_801A4268(u8* param_1, int param_2, u8 param_3) {
    param_1[param_2 + 0x57] = param_3;
}

extern "C" void fn_801A4274(u8* p, s32 i, u8* src) {
    p[i + 0x57] = *src;
}

extern "C" u8 fn_801A4284(s32 p, s32 i) {
    s32 q = p + i;
    return *(u8*)(q + 0x57);
}

extern "C" void fn_801A4290(s32 p, u8 v) {
    *(u8*)(p + 0x34) = v;
}

extern "C" void fn_801A4298(u8* p, u8* src) {
    p[0x34] = *src;
}

extern "C" u8 fn_801A42A4(int p1) { return *(u8*)(p1 + 0x34); }

extern "C" void fn_801A42AC(u8* p, s32 i, u8* src) {
    u8 a = src[1];
    u8* d = p + (i << 3);
    u8 b = src[2];
    d[0x36] = a;
    u8 c = src[3];
    d[0x37] = b;
    b = src[5];
    d[0x38] = c;
    c = src[6];
    d[0x3a] = b;
    b = src[7];
    d[0x3b] = c;
    d[0x3c] = b;
}

extern "C" int fn_801A4324(int p1, int p2) {
    return p1 + p2 * 8 + 0x35;
}

extern "C" void fn_801A4338(u8* param_1, s32 param_2, u8* param_3) {
    u8* p = param_1 + param_2 * 8;
    u8 b1 = param_3[1];
    u8 b0 = param_3[0];
    p[0x3c] = (p[0x3c] & ~0x0c) | ((b1 & 0xff) << 2);
    p[0x3c] = (p[0x3c] & ~0x03) | b0;
}

extern "C" void fn_801A43A8(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x59] = *p3;
}

extern "C" void fn_801A43B8(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x59] = *p3;
}

extern "C" s32 fn_801A43C8(s32 p, s32 i) {
    return p + i + 0x59;
}

extern "C" void fn_801A43D8(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x60))[p2] = *p3; }

extern "C" void fn_801A43EC(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x60))[p2] = *p3; }

extern "C" s32 fn_801A4400(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 4 + 0x60;
}

extern "C" void* fn_801A4414(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" u32 fn_801A441C(u8* p1) {
    return *(u32*)(p1 + 0x68);
}

extern "C" void fn_801A4424(u8* p1, u32 p2) {
    *(u32*)(p1 + 0x68) = p2;
}

extern void* lbl_8029A5F0[];
extern "C" void* fn_801A442C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A5F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A4488(void) {}

extern "C" unsigned int fn_801A452C(void) {
    return 0x54564231;
}

extern "C" void fn_801A4538(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A4548(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A455C(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void fn_801A456C(u8* p1, s32 i, u32* pv) {
    *((u32*)(p1 + (i << 2) + 0xa)) = *pv;
}

extern "C" void fn_801A4580(u8* p1, s32 i, u32* pv) {
    *((u32*)(p1 + (i << 2) + 0xa)) = *pv;
}

extern "C" u8* fn_801A4594(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" void fn_801A45A8(void) {
}

extern "C" void fn_801A45AC(void) {
}

extern "C" BOOL fn_801A45B0(void);
extern "C" BOOL fn_801A45B0(void)
{
    return TRUE;
}

extern "C" void fn_801A45B8(u8* p, s32 i, u8* src) {
    u8* dst;
    dst = p + i * 8;
    dst[0xf] = src[1];
    dst[0x10] = src[2];
    dst[0x11] = src[3];
    dst[0x13] = src[5];
    dst[0x14] = src[6];
    dst[0x15] = src[7];
}

extern "C" s32 fn_801A4630(s32 p, s32 i) {
    return p + i * 8 + 0xe;
}

extern "C" void fn_801A4644(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x18))[p2] = *p3; }

extern "C" void fn_801A4658(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x18))[p2] = *p3; }

extern "C" u8* fn_801A466C(u8* p, s32 i) {
    return p + 0x18 + i * 4;
}

extern "C" void* fn_801A4680(void* p) {
    return *(void**)((char*)p + 4);
}

extern void* lbl_8029A6E8[];
extern "C" void* fn_801A4688(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A6E8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A46E4(void) {
}

extern "C" void fn_801A46E8(void) {
}

extern "C" void fn_801A46EC(void) {
}

extern "C" void fn_801A46F0(void) {
}

extern "C" void fn_801A46F4(void) {
}

extern "C" int fn_801A46F8()
{
	return 0;
}

extern "C" void fn_801A4700(void) { }

extern "C" void fn_801A4704(void) { }

extern "C" u32 fn_801A47A8(void) { return 0x54565054; }

extern "C" void fn_801A47B4(u8* p, u8 v) {
    p[0xd0] = v;
}

extern "C" void fn_801A47BC(u8* p, const u8* src) {
    p[0xd0] = src[0];
}

extern "C" u8 fn_801A47C8(u8* p) {
    return p[0xd0];
}

extern "C" void fn_801A47D0(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A47E0(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A47F4(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void fn_801A4804(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" void fn_801A4818(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" u8* fn_801A482C(u8* p, s32 i) {
    return p + 0x18 + i * 4;
}

extern "C" void fn_801A4840(u8* p1, int p2, const u8* p3) {
    u8 a = p3[1];
    u8* p = p1 + p2 * 8;
    p[0x39] = a;
    p[0x3a] = p3[2];
    p[0x3b] = p3[3];
    p[0x3d] = p3[5];
    p[0x3e] = p3[6];
    p[0x3f] = p3[7];
}

extern "C" s32 fn_801A48B8(s32 p, s32 i) {
    return p + i * 8 + 0x38;
}

extern "C" void fn_801A48CC(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x78))[p2] = *p3; }

extern "C" void fn_801A48E0(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x78))[p2] = *p3; }

extern "C" s32 fn_801A48F4(s32 p, s32 i) {
    return p + i * 4 + 0x78;
}

extern "C" void fn_801A4908(u8* p, s32 i, s16* src) {
    s32 off = i << 3;
    s16 a = src[0];
    u8* d = p + off;
    *(s16*)(d + 0x98) = a;
    *(s16*)(d + 0x9a) = src[1];
    *(s16*)(d + 0x9c) = src[2];
    *(s16*)(d + 0x9e) = src[3];
}

extern "C" int fn_801A4960(int param_1, int param_2) {
    return param_1 + param_2 * 8 + 0x98;
}

extern "C" void fn_80193D9C(u32* p);
extern "C" void fn_80193DFC(u32* p);
extern "C" void fn_80198620(u8* p);
extern "C" void fn_801A4974(u8* p1, int p2, const u8* p3) {
    NaviBytes4* d = (NaviBytes4*)(p1 + 0xb8) + p2;
    d->b[0] = p3[0];
    d->b[1] = p3[1];
    d->b[2] = p3[2];
    d->b[3] = p3[3];
}

extern "C" s32 fn_801A49CC(s32 p, s32 i) {
    return p + i * 4 + 0xb8;
}

extern "C" void fn_801A49E0(u8* p, s32 i, u8 v) {
    p[i + 0xc8] = v;
}

extern "C" void fn_801A49EC(u8* p, s32 i, u8* src) {
    p[i + 0xc8] = *src;
}

extern "C" u8 fn_801A49FC(u8* p, s32 i) {
    return p[i + 0xc8];
}

extern "C" void* fn_801A4A08(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" s32 fn_801A4A10(u8* p) {
    return *(s32*)(p + 0xd4);
}

extern "C" void fn_801A4A18(int param_1, int param_2) {
    *(int*)(param_1 + 0xd4) = param_2;
}

extern void* lbl_8029A7E4[];
extern "C" void* fn_801A4A20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A7E4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801A4A7C(void) {
    return 0x54474243;
}

extern "C" void fn_801A4A88(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" void fn_801A4AAC(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" int fn_801A4AD0(int param_1) {
    return param_1 + 0x5c;
}

extern "C" void* lbl_8029A91C[];
extern "C" void* lbl_8029AA18[];
extern "C" void* fn_801A4AD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A91C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AA18;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8029A0D4;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A4B44(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern "C" void fn_801A4B4C(u8* p, u32* src) {
    *(u32*)(p + 4) = *src;
}

extern "C" void* fn_801A4B58(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" void fn_801A4B60(u8* p, s32 i, u32* src) {
    *(u32*)(p + i * 6 + 8) = *src;
}

extern "C" s32 fn_801A4B74(s32 p, s32 i) {
    return p + i * 6 + 8;
}

extern "C" void fn_801A4B88(u8* p1, int p2, u32 p3) {
    ((u32*)(p1 + 0x38))[p2] = p3;
}

extern "C" u32 fn_801A4B98(u8* p1, int p2) {
    return ((u32*)(p1 + 0x38))[p2];
}

extern "C" u32 fn_801A4BA8(void* param_1) {
    return *(u32*)((u8*)param_1 + 0x58);
}

extern "C" void fn_801A4BB0(u8* p, u32 v) {
    *(u32*)(p + 0x58) = v;
}

extern "C" u32 fn_801A4BB8(void) {
    return 0x54474234;
}

extern "C" void fn_801A4BC4(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" void fn_801A4BE8(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" int fn_801A4C0C(int param_1) {
    return param_1 + 0x5c;
}

extern "C" void* lbl_8029A9AC[];
extern "C" void* fn_801A4C14(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A9AC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AA18;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8029A0D4;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A4C80(void) {
}

extern "C" u32 fn_801A4C84(void) {
    return 0x54475054;
}

extern "C" u32 fn_801A4C90(void) {
    return 0x434c4f4e;
}

extern "C" void fn_801A4C9C(u8* param_1, s32 param_2, NaviColor8* param_3) {
    ((NaviColor8*)(param_1 + 4))[param_2] = *param_3;
}

extern "C" int fn_801A4CF4(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 4;
}

extern "C" void fn_801A4D08(u8* param_1, s32 param_2, u8* param_3) {
    u8* dst = param_1 + param_2 * 4;
    dst[0xc] = param_3[0];
    dst[0xd] = param_3[1];
    dst[0xe] = param_3[2];
    dst[0xf] = param_3[3];
}

extern "C" int fn_801A4D60(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 0xc;
}

extern "C" void fn_801A4D74(u8* param_1, u8* param_2) {
    param_1[0x14] = param_2[0];
}

extern "C" void fn_801A4D80(u8* param_1, u8 param_2) {
    param_1[0x14] = param_2;
}

extern "C" u8 fn_801A4D88(u8* p) {
    return p[0x14];
}

extern "C" void fn_801A4D90(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 0x16))[i] = *pv;
}

extern "C" void fn_801A4DA4(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 0x16))[i] = *pv;
}

extern "C" s32 fn_801A4DB8(s32 p, s32 i) {
    return p + i * 2 + 0x16;
}

extern "C" void fn_801A4DCC(u8* param_1, s32 param_2, u32 param_3) {
    ((u32*)(param_1 + 0x20))[param_2] = param_3;
}

extern "C" u32 fn_801A4DDC(u8* param_1, s32 param_2) {
    return ((u32*)(param_1 + 0x20))[param_2];
}

extern "C" void fn_801A4DEC(u8* param_1, u8 param_2) {
    param_1[0x40] = param_2;
}

extern "C" void fn_801A4DF4(int param_1, u8* param_2) {
    *(u8*)(param_1 + 0x40) = *param_2;
}

extern "C" u8 fn_801A4E00(int param_1) {
    return *(u8*)(param_1 + 0x40);
}

extern "C" u32 fn_801A4E08(int param_1) {
    return *(u32*)(param_1 + 0x44);
}

extern "C" void* fn_801A4E10(u8* p) {
    return *(void**)(p + 0x48);
}

extern "C" void fn_801A4E18(void* p, s32 v) {
    *(s32*)((u8*)p + 0x44) = v;
}

extern "C" void fn_801A4E20(u8* p, u32 v) {
    *(u32*)(p + 0x48) = v;
}

extern void* lbl_8029AAB8[];
extern "C" void* fn_801A4E28(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AAB8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A150;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801A4E84(void) {
    return 0x434C4142;
}

extern "C" void fn_801A4E90(void* p, s32 i, u8* src) {
    u8* dst = (u8*)p + i * 4;
    dst[0x20] = src[0];
    dst[0x21] = src[1];
    dst[0x22] = src[2];
    dst[0x23] = src[3];
}

extern "C" u8* fn_801A4EE8(u8* p, s32 i) {
    return p + i * 4 + 0x20;
}

extern "C" void* lbl_8029AB90[];
extern "C" void* lbl_8029AF34[];
extern "C" void* fn_801A4EFC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AB90;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AF34;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8029A150;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801A4FC0(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 4;
}

extern "C" void fn_801A4FD4(void* p, u8* src) {
    *((u8*)p + 0xc) = *src;
}

extern "C" void fn_801A4FE0(void* p, u8 v) {
    *((u8*)p + 0xc) = v;
}

extern "C" u8 fn_801A4FE8(u8* param_1) {
    return param_1[0xc];
}

extern "C" void fn_801A4FF0(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 0xe))[i] = *pv;
}

extern "C" void fn_801A5004(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 0xe))[i] = *pv;
}

extern "C" s32 fn_801A5018(s32 p, s32 i) {
    return p + i * 2 + 0xe;
}

extern "C" void fn_801A502C(u8* p, u8 v) {
    p[0x16] = v;
}

extern "C" void fn_801A5034(u8* p, u8* pv) {
    p[0x16] = *pv;
}

extern "C" u8 fn_801A5040(int param_1)
{
    return *(u8*)(param_1 + 0x16);
}

extern "C" u32 fn_801A5048(int param_1)
{
    return *(u32*)(param_1 + 0x18);
}

extern "C" u32 fn_801A5050(int param_1)
{
    return *(u32*)(param_1 + 0x1c);
}

extern "C" void fn_801A5058(int param_1, u32 param_2)
{
    *(u32*)(param_1 + 0x18) = param_2;
}

extern "C" void fn_801A5060(u8* p, u32 v) {
    *((u32*)(p + 0x1c)) = v;
}

extern "C" u32 fn_801A5068(void) {
    return 0x5045584c;
}

extern void* lbl_8029AC34[];
extern "C" void* fn_801A5074(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AC34;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801A50D0(void) {
    return 0x50454544;
}

extern void* lbl_8029ACD0[];
extern "C" void* fn_801A50DC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029ACD0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801E0D40(void*, void*, int, int);
extern void* lbl_8029AE0C[];
extern "C" void fn_8000EE0C(void);
extern "C" void fn_8000EE4C(void);
extern "C" u32 fn_801A5138(void) {
    return 0x50454f50;
}

extern void* lbl_8029AD68[];
extern "C" void* fn_801A5144(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AD68;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801A51A0(void)
{
    return 0x49424c46;
}

extern "C" void fn_801A51AC(int param_1, u8 param_2)
{
    *(u8*)(param_1 + 4) = param_2;
}

extern "C" u8 fn_801A51B4(int param_1)
{
    return *(u8*)(param_1 + 4);
}

extern "C" void fn_801A51BC(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x5)) = *pv;
}

extern "C" void fn_801A51D0(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x5)) = *pv;
}

extern "C" void fn_801A7D54(s32, s32);
extern "C" s32 fn_801A51E4(s32 p, s32 i) {
    return p + i * 4 + 5;
}

extern "C" void fn_801A51F8(s32 p, s32 i, s32 v) {
    fn_801A7D54(p + i * 0x1c + 0x18, v);
}

extern "C" void fn_801A522C(s32 p, s32 i, s32 v) {
    fn_801A7D54(p + i * 0x1c + 0x18, v);
}

extern "C" s32 fn_801A5260(s32 p, s32 i) {
    return p + i * 0x1c + 0x18;
}

extern "C" void fn_801A5274(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x6c)) = *pv;
}

extern "C" void fn_801A5288(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x6c)) = *pv;
}

extern "C" s32 fn_801A529C(s32 p, s32 i) {
    return p + i * 4 + 0x6c;
}

extern "C" void* fn_801A52B0(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_8029AE0C;
        fn_801E0D40((u8*)param_1 + 0x6c, &fn_8000EE0C, 4, 4);
        fn_801E0D40((u8*)param_1 + 0x18, &fn_8000EE4C, 0x1c, 3);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_8029A078;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801A534C(void) {}

extern "C" void fn_801A5350(void) {}

extern "C" void fn_801A5354(void) {}

extern "C" void fn_801A5358(void) {
}

extern "C" void fn_801A535C(void) {
}

extern "C" void fn_801A5360(void) {
}

extern "C" void fn_801A5364(void) {
}

extern "C" int fn_801A5368()
{
	return 0;
}

extern "C" u32 fn_801A5370(void) {
    return 0x434c4f46;
}

struct B4_801A4974 { u8 c[4]; };
struct B3_801A4840 { u8 c[3]; };
struct E_801A4840 { u8 x; B3_801A4840 rgb; };
