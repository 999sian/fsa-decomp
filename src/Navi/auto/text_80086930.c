#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80086930-0x8008729c (9 functions). split_file divides it into the game's real files.

extern void* lbl_80283C78[];
extern u8 lbl_802B7CA0[];
extern u8 lbl_80283B28[];
extern u8 lbl_8029FDB4[];
extern u8 lbl_802C5364[];
extern f32 lbl_803009B0;
extern "C" void fn_800636F4(void*, void*, s32);
extern "C" void* fn_800638A4(void*, s32, void*, s32);
extern "C" void fn_800127A0(void*);
extern "C" s32 fn_8000E124(void*, void*, void*, s32, s32, s32, s32, f32);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80086950(void);
extern u32 lbl_802C5278[];
extern "C" void fn_8000DDAC(void*, void*, s32);
extern "C" void fn_8000EBB8(void*);
extern "C" void fn_801AFE98(void*, void*);
extern "C" void fn_80010CE4(void*);
extern "C" void fn_8000E414(void*, void*, f32);
extern "C" void fn_801B002C(void*, void*);
extern "C" void fn_80086930(void) {
    fn_80086950();
}

extern "C" BOOL fn_80086B88(u8* self, s32 arg1)
{
	u8* obj = *(u8**)(*(u8**)(self + 0x45c) + 4);
	void* res = fn_800638A4(lbl_80283B28, arg1, lbl_802B7CA0 + 0x2200, 0x40);
	if (res == NULL) {
		return FALSE;
	}
	return fn_8000E124(self + 0x460, obj + 0x58, res, 1, 2, 0, -1, lbl_803009B0) != 0;
}

extern "C" BOOL fn_80086E18()
{
	fn_800636F4(lbl_80283B28, lbl_802B7CA0 + 0x2200, 0x40);
	u8* p = lbl_802C5364;
	if (*(s8*)(p + 4) >= 0) {
		if (--*(s32*)(p + 8) == 0) {
			fn_800127A0(lbl_8029FDB4 + 4);
			*(s8*)((unsigned)p + 4) = -1;
		}
	}
	return TRUE;
}

#pragma use_lmw_stmw off
extern "C" int fn_80087160(u8* param_1) {
    s32 i;
    u8* obj;
    u32* flag = lbl_802C5278;
    u8* p2 = param_1;
    u8* p1 = param_1;
    for (i = 0; i < 0x18; i++) {
        if ((flag[0x18] & 1) == 0) {
            obj = *(u8**)(*(u8**)(p1 + 0x24c) + 4);
            fn_8000DDAC(p2 + 0x30c, obj + 0x58, (s32)*(f32*)(*(u8**)(p2 + 0x310) + 0x10));
            fn_8000EBB8(*(void**)(p1 + 0x24c));
            fn_801AFE98(obj + 0x58, *(void**)(p2 + 0x314));
        }
        p1 += 4;
        p2 += 12;
        flag++;
    }
    if (lbl_802C5278[50] & 1) {
        obj = *(u8**)(*(u8**)(param_1 + 0x45c) + 4);
        fn_8000E414(param_1 + 0x460, obj + 0x58, *(f32*)(*(u8**)(param_1 + 0x464) + 0x10));
        fn_8000EBB8(*(void**)(param_1 + 0x45c));
        fn_801B002C(obj + 0x58, *(void**)(param_1 + 0x468));
    }
    return 1;
}
#pragma use_lmw_stmw reset
extern "C" BOOL fn_8008724C()
{
	return TRUE;
}

extern "C" void* fn_80087254(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283C78;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
