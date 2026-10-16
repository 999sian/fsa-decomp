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

extern "C" int fn_801A3544(int p) { return p + 4; }

extern "C" u8 fn_801A35FC(int param_1) {
    return *(u8*)(param_1 + 0x3b);
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

extern "C" int fn_801A36E8(int p) { return p + 4; }

extern "C" void fn_801A36F0(int param_1, u32* param_2) {
    *(u32*)(param_1 + 8) = *param_2;
}

extern "C" void fn_801A36FC(int param_1, u32* param_2) {
    *(u32*)(param_1 + 8) = *param_2;
}

extern "C" void fn_801A3710(int param_1, u16* param_2) {
    *(u16*)(param_1 + 0xc) = *param_2;
}

extern "C" void fn_801A371C(int param_1, u16* param_2) {
    *(u16*)(param_1 + 0xc) = *param_2;
}

extern "C" u8 fn_801A3744(int param_1) {
    return *(u8*)(param_1 + 0xe);
}

extern "C" void fn_801A374C(int param_1, u8 param_2) {
    *(u8*)(param_1 + 0xf) = param_2;
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

extern "C" void fn_801A3EF8(int param_1, int param_2, u8* param_3) {
    u8* p = (u8*)(param_1 + param_2 * 8);
    u8 bVar1 = *param_3;
    p[0x28] = (p[0x28] & 0xf3) | (param_3[1] << 2);
    p[0x28] = (p[0x28] & 0xfc) | bVar1;
}

extern "C" void fn_801A3F68(int param_1, int param_2, u8* param_3) {
    *(u8*)(param_1 + param_2 + 0x7a) = *param_3;
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

extern "C" void fn_801A43A8(u8* p1, int p2, u8* p3) {
    p1[p2 + 0x59] = *p3;
}

extern "C" void fn_801A43D8(int p1, int p2, u32* p3) { *(u32*)(p1 + p2 * 4 + 0x60) = *p3; }

extern "C" void* fn_801A4414(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" u32 fn_801A441C(u8* p1) {
    return *(u32*)(p1 + 0x68);
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

extern "C" void fn_801A4538(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A4548(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A455C(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" u8* fn_801A4594(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" BOOL fn_801A45B0(void);
extern "C" BOOL fn_801A45B0(void)
{
    return TRUE;
}

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

extern "C" int fn_801A46F8()
{
	return 0;
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

extern "C" int fn_801A5368()
{
	return 0;
}

