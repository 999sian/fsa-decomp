#include "types.h"
#include "types.h"
extern "C" void* lbl_8029AA18[];
extern void* lbl_8029A0D4[];

extern "C" void* lbl_8029AF34[];
extern void* lbl_8029A150[];
extern "C" void fn_801A605C(int, void*);
extern "C" void fn_801BC250(int, int);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80196344-0x801a537c (574 functions). split_file divides it into the game's real files.

extern "C" void fn_801A7E24(int);
extern "C" void fn_801A7D78(void* p);
struct NaviRect16 { s16 x, y, w, h; };
struct NaviColor8 { u8 r, g, b, a; };
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
extern "C" u32 fn_80197B4C(void* param_1) {
    u8* p = (u8*)param_1;
    void* obj;
    u32 a;
    u32 b;
    u32 c;
    obj = *(void**)(p + 0x28);
    a = ((NaviVFunc)(*(void***)obj)[0x30 / 4])(obj);
    obj = *(void**)(p + 0x24);
    b = ((NaviVFunc)(*(void***)obj)[0x28 / 4])(obj);
    obj = *(void**)(p + 0x2c);
    a += ((NaviVFunc)(*(void***)obj)[0x44 / 4])(obj);
    obj = *(void**)(p + 0x30);
    a += ((NaviVFunc)(*(void***)obj)[0x14 / 4])(obj);
    obj = *(void**)(p + 0x34);
    c = ((NaviVFunc)(*(void***)obj)[0x20 / 4])(obj);
    return (b + (a + c + 0x1f)) & ~0x1f;
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

extern "C" int fn_80198FC0()
{
	return 0;
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

extern "C" void fn_8019DE38(int *param_1)
{
	typedef void (*fnptr)(void);
	int *ptr = param_1;
	int *vtable;
	
	vtable = (int *)(*ptr);
	fnptr fn = (fnptr)(vtable[0x2c/4]);
	fn();
	
	int *ptr2 = ptr;
	ptr = ptr2;
	vtable = (int *)(*ptr);
	fn = (fnptr)(vtable[0x30/4]);
	fn();
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
extern "C" void fn_801A354C(u8* param_1, u16* param_2) {
    u16 uVar0 = param_2[0];
    u8 uVar1 = *(u8*)(param_2 + 1);
    *(u16*)(param_1 + 0x30) = uVar0;
    u8 uVar2 = *((u8*)param_2 + 3);
    *(u8*)(param_1 + 0x32) = uVar1;
    *(u8*)(param_1 + 0x33) = uVar2;
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
    u32 start = lbl_802FFA80[2];
    u32* p = lbl_802FFA80 + 2;
    while (true) {
        if (!fn_801A602C((u32)p)) {
            break;
        }
        tmp = fn_801A6050((u32)p);
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

extern "C" void fn_801A38E0(NaviRectHolder* p, s32 i, NaviRect16* src) {
    p->rects[i].x = src->x;
    p->rects[i].y = src->y;
    p->rects[i].w = src->w;
    p->rects[i].h = src->h;
}

extern "C" u8* fn_801A3938(u8* p, s32 i) {
    return p + 0xda + i * 8;
}

extern "C" void fn_801A394C(NaviRectHolder* p, s32 i, NaviColor8* src) {
    p->colors[i].r = src->r;
    p->colors[i].g = src->g;
    p->colors[i].b = src->b;
    p->colors[i].a = src->a;
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
    u8* d = p + i * 8;
    d[0x5a] = src[1];
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

extern "C" void fn_801A3D28(s32 p, s32 i, s16* src) {
    s32 d = i * 8 + p;
    *(s16*)(d + 0x42) = src[0];
    *(s16*)(d + 0x44) = src[1];
    *(s16*)(d + 0x46) = src[2];
    *(s16*)(d + 0x48) = src[3];
}

extern "C" s32 fn_801A3D80(s32 p, s32 i) {
    return p + i * 8 + 0x42;
}

extern "C" void fn_801A3D94(s32 p, s32 i, u8* src) {
    s32 d = p + i * 4;
    *(u8*)(d + 0x62) = src[0];
    *(u8*)(d + 0x63) = src[1];
    *(u8*)(d + 0x64) = src[2];
    *(u8*)(d + 0x65) = src[3];
}

extern "C" int fn_801A3DEC(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 0x62;
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

extern "C" void fn_801A3E6C(u8* p, s32 i, u8* src) {
    u8 a = src[1];
    u8 b = src[2];
    u8* d = p + (i << 3);
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

extern "C" void fn_801A3EF8(int param_1, int param_2, u8* param_3) {
    u8 b1 = param_3[1];
    u8* p = (u8*)(param_1 + param_2 * 8);
    u8 b0 = param_3[0];
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
    u8* d = p + i * 8;
    *(s16*)(d + 0x14) = src[0];
    *(s16*)(d + 0x16) = src[1];
    *(s16*)(d + 0x18) = src[2];
    *(s16*)(d + 0x1a) = src[3];
}

extern "C" s32 fn_801A41C0(s32 p, s32 i) {
    return p + i * 8 + 0x14;
}

extern "C" void fn_801A41D4(u8* p, s32 i, u8* src) {
    u8 a;
    u8 b;
    u8 c;
    p = p + i * 4;
    a = src[1];
    *(p + 0x45) = src[0];
    b = src[2];
    *(p + 0x46) = a;
    a = src[3];
    *(p + 0x47) = b;
    *(p + 0x48) = a;
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

extern "C" u8 fn_801A42A4(int p1) { return *(u8*)(p1 + 0x34); }

extern "C" void fn_801A42AC(u8* p1, int p2, u8* p3) {
    u8* d = p1 + p2 * 8;
    u8 t;
    t = p3[1]; d[0x36] = t;
    t = p3[2]; d[0x37] = t;
    t = p3[3]; d[0x38] = t;
    t = p3[5]; d[0x3a] = t;
    t = p3[6]; d[0x3b] = t;
    t = p3[7]; d[0x3c] = t;
}

extern "C" int fn_801A4324(int p1, int p2) {
    return p1 + p2 * 8 + 0x35;
}

extern "C" void fn_801A43A8(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x59] = *p3;
}

extern "C" void fn_801A43B8(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x59] = *p3;
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

extern "C" BOOL fn_801A45B0(void);
extern "C" BOOL fn_801A45B0(void)
{
    return TRUE;
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
    u8* p = p1 + p2 * 8;
    p[0x39] = p3[1];
    p[0x3a] = p3[2];
    p[0x3b] = p3[3];
    p[0x3d] = p3[5];
    p[0x3e] = p3[6];
    p[0x3f] = p3[7];
}

extern "C" void fn_801A48CC(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x78))[p2] = *p3; }

extern "C" void fn_801A48E0(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x78))[p2] = *p3; }

extern "C" int fn_801A4960(int param_1, int param_2) {
    return param_1 + param_2 * 8 + 0x98;
}

extern "C" void fn_801A4974(u8* p1, int p2, const u8* p3) {
    u8* p = p1 + p2 * 4;
    p[0xb8] = p3[0];
    p[0xb9] = p3[1];
    p[0xba] = p3[2];
    p[0xbb] = p3[3];
}

extern "C" void* fn_801A4A08(void* p) {
    return *(void**)((char*)p + 4);
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

extern "C" void* fn_801A4B58(void* p) {
    return *(void**)((char*)p + 4);
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

extern "C" void* fn_801A4E10(u8* p) {
    return *(void**)(p + 0x48);
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

extern "C" void fn_801A5274(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x6c)) = *pv;
}

extern "C" void fn_801A5288(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x6c)) = *pv;
}

extern "C" void fn_801A534C(void) {}

extern "C" void fn_801A5350(void) {}

extern "C" void fn_801A5354(void) {}

extern "C" int fn_801A5368()
{
	return 0;
}
struct B4_801A4974 { u8 c[4]; };
struct B3_801A4840 { u8 c[3]; };
struct E_801A4840 { u8 x; B3_801A4840 rgb; };
