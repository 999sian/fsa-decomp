#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008ae90-0x8008bd90 (14 functions). split_file divides it into the game's real files.

extern void* lbl_80284A14[];
extern u8 lbl_802FCE94;
extern u8 lbl_8027F6DC[];
extern u8 lbl_8027FB70[];
extern "C" void fn_800175B8(void* param_1);
extern "C" s32 fn_80020EA4(void* param_1, void* param_2);
extern "C" void fn_801E0DB8(void* param_1, void* param_2, void* param_3, s32 param_4, s32 param_5);
extern "C" void fn_80064D9C(void);
extern "C" void fn_80064D40(void);
extern "C" s32 fn_800183AC(void* param_1, void* param_2, s32 param_3);
extern "C" s32 fn_8008B4E4(void* param_1);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8008AF98(void);
extern "C" void fn_8008AE90(void) {
    fn_8008AF98();
}

extern "C" s32 fn_8008AEB0(u8* param_1);
extern "C" void fn_8008BC64(u8* param_1) {
    fn_8008AEB0(param_1);
}

extern void fn_8008BA14(void* param);
extern s32 fn_800126C8(void* param1, void* param2, void* param3);
extern void fn_800636F4(void* param1, void* param2, s32 size);
extern void fn_800127A0(void* param);
extern u8 lbl_802FCE90;
extern u8 lbl_802FCE94;
extern f32 lbl_80300A54;
extern s8 lbl_802C5394[];
extern u8 lbl_8029FDB4[];
extern u32 lbl_80284940[];
extern u8 lbl_802B7CA0[];
extern "C" s32 fn_8008B4E4(void* param_1);
extern u8 lbl_802FCE9C;
extern u8 lbl_802FCEA0;
extern f32 lbl_80300A50;
extern char lbl_802848B0[];
extern char lbl_8028494C[];
extern "C" void* fn_800638A4(void*, void*, void*, s32);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void*, char*, s32, void*, void*, ...);
extern "C" void fn_80007AB8(char*, s32, void*, ...);
extern "C" s32 fn_8000DE00(void*, void*, void*, s32, s32, s32, s32, f32);
extern "C" s32 fn_8008B4E4(void* param_1)
{
    f32 f0 = lbl_80300A54;
    *((u8*)param_1 + 0x2b7) = 0;
    lbl_802FCE90 = 1;
    f32 f2 = *((f32*)((u8*)param_1 + 0x130));
    f32 f1 = *((f32*)((u8*)param_1 + 0x128));
    *((f32*)((u8*)param_1 + 0x2a4)) = f1;
    *((f32*)((u8*)param_1 + 0x2a8)) = f0;
    *((f32*)((u8*)param_1 + 0x2ac)) = f2;
    fn_8008BA14(param_1);
    
    s8* ptr = &lbl_802C5394[0];
    if (ptr[4] < 0) {
        u8* p1 = &lbl_8029FDB4[4];
        u32* p2 = &lbl_80284940[0];
        s32 res = fn_800126C8(p1, p2, ptr);
        ptr[4] = (s8)res;
    }
    ((u32*)ptr)[2]++;
    return 4;
}

extern "C" BOOL fn_8008B888(void* param_1, void* param_2, void* param_3, void* param_4)
{
    void* iVar1;
    void* uVar2;

    iVar1 = fn_800638A4(&lbl_802FCE94, param_4, (u8*)lbl_802B7CA0 + 0x2200, 0x40);
    if (iVar1 == NULL) {
        uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_802848B0, 0x212, &lbl_802FCE9C, lbl_8028494C);
        fn_80007AB8(lbl_802848B0, 0x212, &lbl_802FCEA0);
    }
    if (fn_8000DE00(param_2, (u8*)param_3 + 0x58, iVar1, 1, 2, 0, -1, lbl_80300A50) == 0) {
        return FALSE;
    }
    return TRUE;
}

extern "C" s32 fn_8008BC84(void)
{
    void* addr = (u8*)lbl_802B7CA0 + 0x2200;
    fn_800636F4(&lbl_802FCE94, addr, 0x40);

    s8* ptr = &lbl_802C5394[0];
    s8 flag = ptr[4];
    if (flag >= 0) {
        u32 count = *((u32*)(ptr + 8)) - 1;
        *((u32*)(ptr + 8)) = count;
        if (count == 0) {
            fn_800127A0(&lbl_8029FDB4[4]);
            ptr[4] = -1;
        }
    }
    return 1;
}

extern "C" void fn_8008B95C(void);
extern "C" void fn_8008BD00(void) {
    fn_8008B95C();
}

extern "C" void fn_8008B580(void);
extern "C" void fn_8008BD20(void) {
    fn_8008B580();
}

extern "C" BOOL fn_8008BD40()
{
	return TRUE;
}

extern "C" void* fn_8008BD48(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80284A14;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
