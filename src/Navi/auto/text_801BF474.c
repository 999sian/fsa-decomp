#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bf474-0x801c0018 (19 functions). split_file divides it into the game's real files.

extern u8 Scb_802F6CC0[];
extern "C" void fn_801BF7E0(u32 param_1, u32 param_2);
extern "C" BOOL OSDisableInterrupts(void);
extern "C" BOOL OSRestoreInterrupts(BOOL level);
extern "C" u32 fn_801BF4D4(u8* param_1, u32 param_2, u32 param_3);
extern "C" void fn_801BF474(void) {
    u32 uVar1 = *(u32*)(Scb_802F6CC0 + 0x40);
    *(u32*)(Scb_802F6CC0 + 0x4c) = fn_801BF4D4(Scb_802F6CC0 + uVar1, uVar1, 0x40 - uVar1);
    if (*(u32*)(Scb_802F6CC0 + 0x4c) != 0) {
        *(u32*)(Scb_802F6CC0 + 0x40) = 0x40;
    }
}

extern "C" void __OSUnlockSramEx(u32 param_1) {
    fn_801BF7E0(param_1, 0x14);
}

extern "C" u32 __OSSyncSram(void) {
    return *(u32*)(Scb_802F6CC0 + 0x4c);
}

extern "C" BOOL fn_801BFB74(void) {
    u8* scb = Scb_802F6CC0;
    u8* puVar3 = scb;
    BOOL uVar2 = OSDisableInterrupts();
    u32* flag = (u32*)(scb + 0x48);
    if (*flag == 0) {
        *flag = 1;
        *(BOOL*)(scb + 0x44) = uVar2;
    } else {
        OSRestoreInterrupts(uVar2);
        puVar3 = 0;
    }
    u8 bVar1 = puVar3[0x13];
    fn_801BF7E0(0, 0);
    return (bVar1 & 4) != 0;
}

extern "C" u8 fn_801BFBF4(void) {
    u8* scb = Scb_802F6CC0;
    u8* puVar3 = scb;
    BOOL uVar2 = OSDisableInterrupts();
    u32* flag = (u32*)(scb + 0x48);
    if (*flag == 0) {
        *flag = 1;
        *(BOOL*)(scb + 0x44) = uVar2;
    } else {
        OSRestoreInterrupts(uVar2);
        puVar3 = 0;
    }
    u8 bVar1 = puVar3[0x13];
    fn_801BF7E0(0, 0);
    return bVar1 >> 7;
}

extern "C" void fn_801BFEBC(s32* param_1, s32 param_2) {
    param_1[0] = param_2;
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    param_1[5] = -1;
    param_1[4] = 0;
    param_1[7] = 0;
    param_1[6] = 0;
}

extern "C" u64 OSGetTime(void);
extern "C" void fn_801BFFF0(s32* param_1) {
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    param_1[5] = -1;
    param_1[4] = 0;
    param_1[7] = 0;
    param_1[6] = 0;
}

