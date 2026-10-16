#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8007bcd0-0x80080620 (44 functions). split_file divides it into the game's real files.

extern void* lbl_80283014[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8007BF20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283014;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_8007C494(void);
extern "C" BOOL fn_8007C494(void)
{
    return TRUE;
}

extern "C" int fn_80020EA4(void* p, int x);
extern "C" void fn_8007BF68(u8* p);
extern "C" int fn_800183AC(void* p, void* f, s32 a);
extern "C" int fn_8007CEDC(u8* p);
extern "C" void fn_8007C5E4(void);
extern u8 lbl_802FCBA0[];
extern u8 lbl_802EE470[];
extern u8 lbl_803007FC[];
extern void* lbl_802FF0BC;
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern "C" void fn_8007C540(u8* p, u8* q) {
    u32 i = 0;
    s32 off = 0;
    do {
        if (*(u16*)(p + off + 0x16)) {
            u8* r28 = *(u8**)(*(u8**)(lbl_802EE470 + 0x38) + 0x14);
            u8* obj0 = *(u8**)(q + 0x28);
            u8* obj = ((u8* (*)(u8*, s32))*(void**)(*(u8**)obj0 + 0x50))(obj0, i);
            *(f32*)(obj + 0x1c) = *(f32*)(obj + 0x1c) + *(f32*)(r28 + 0x414);
            *(f32*)(obj + 0x20) = *(f32*)(obj + 0x20) + *(f32*)(r28 + 0x418);
        }
        i++;
        off += 8;
    } while (i < 8);
}

extern "C" void fn_8007C698(void);
extern "C" void fn_8007C5E4(void) {
    fn_8007C698();
}

extern u8 lbl_8029F8D8[];
extern u8 lbl_802FCBA0[];
extern u8 lbl_802EE470[];
extern u8 lbl_803007FC[];
extern void* lbl_802FF0BC;
extern "C" int fn_80020EA4(void* p, int x);
extern "C" void fn_8007BF68(u8* p);
extern "C" int fn_800183AC(void* p, void* f, s32 a);
extern "C" int fn_8007CEDC(u8* p);
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern u8 lbl_802FCBA0[];
extern u8 lbl_802EE470[];
extern u8 lbl_803007FC[];
extern void* lbl_802FF0BC;
extern "C" int fn_80020EA4(void* p, int x);
extern "C" void fn_8007BF68(u8* p);
extern "C" int fn_800183AC(void* p, void* f, s32 a);
extern "C" int fn_8007CEDC(u8* p);
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern s32 lbl_802821C0[];
extern "C" void fn_801C61AC(void* p, f32 x, f32 y, f32 z);
extern "C" void fn_8000C8A4(void* m, s32 a, s32 b, s32 c);
extern "C" void fn_801C5D74(void* p, void* q);
extern "C" void fn_8007E888(u8* p, void* a);
extern "C" void fn_8007D940(u8* p)
{
	u8* q = *(u8**)(*(u8**)(p + 0x358) + 4);
	*(f32*)(q + 0x18) = *(f32*)(p + 0x144);
	*(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
	*(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
	fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
	fn_8000C8A4(lbl_8029F8D8, *(s16*)(p + 0x13c), *(s16*)(p + 0x13e), *(s16*)(p + 0x140));
	fn_801C5D74(lbl_8029F8D8, *(u8**)(*(u8**)(p + 0x358) + 4) + 0x24);
}

extern "C" void fn_8007E758(u8* p, s32 idx)
{
	s32* table;

	*(s32*)(p + 0x3dc) = idx;
	*(s32*)(p + 0x3e0) = 0;
	table = (s32*)lbl_802821C0[*(s32*)(p + 0x3dc)];
	fn_8007E888(p, (void*)table[*(s32*)(p + 0x3e0) * 2]);
	*(s32*)(p + 0x3e4) = table[*(s32*)(p + 0x3e0) * 2 + 1];
}

extern "C" BOOL fn_8007E7CC(u8* p)
{
	if (*(s8*)(p + 0x445) != 0) {
		s32* table = (s32*)lbl_802821C0[*(s32*)(p + 0x3dc)];
		s32 n = *(s32*)(p + 0x3e4);
		if (n == 0) {
			*(s32*)(p + 0x3e0) += 1;
			fn_8007E888(p, (void*)table[*(s32*)(p + 0x3e0) * 2]);
			*(s32*)(p + 0x3e4) = table[*(s32*)(p + 0x3e0) * 2 + 1];
		} else if (n > 0) {
			*(s32*)(p + 0x3e4) = n - 1;
			fn_8007E888(p, (void*)table[*(s32*)(p + 0x3e0) * 2]);
		} else {
			return 1;
		}
	}
	return 0;
}

extern "C" int fn_8007C604(u8* p);
extern "C" void fn_80080430(u8* p) {
    fn_8007C604(p);
}

extern "C" void fn_8007FD34(void);
extern "C" void fn_80080564(void) {
    fn_8007FD34();
}

extern "C" void fn_8007CFC4(void);
extern "C" void fn_80080584(void) {
    fn_8007CFC4();
}

extern "C" BOOL fn_800805A4(void);
extern "C" BOOL fn_800805A4(void)
{
    return TRUE;
}

extern void* lbl_80282FE8[];
extern void* lbl_80281904[];
extern "C" void* fn_800805AC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80282FE8;
        if ((s32)param_1 + 0x38 != 0) {
            *(void**)((char*)param_1 + 0x38) = lbl_80283014;
        }
        if ((s32)param_1 + 0xc != 0) {
            *(void**)((char*)param_1 + 0xc) = lbl_80281904;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

