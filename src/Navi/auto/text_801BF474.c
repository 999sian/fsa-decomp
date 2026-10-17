#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bf474-0x801c0018 (19 functions). split_file divides it into the game's real files.

extern u8 Scb_802F6CC0[];
extern "C" void fn_801BF7E0(u32 param_1, u32 param_2);
extern "C" BOOL OSDisableInterrupts(void);
extern "C" BOOL OSRestoreInterrupts(BOOL level);
extern "C" u64 OSGetTime(void);
extern "C" u32 fn_801BF4D4(u8* param_1, u32 param_2, u32 param_3);
extern "C" void fn_801BF474(void) {
    u8* puVar3 = Scb_802F6CC0;
    u32* puVar4 = (u32*)(puVar3 + 0x40);
    u32 uVar1 = *puVar4;
    *(u32*)(puVar3 + 0x4c) = fn_801BF4D4(puVar3 + uVar1, uVar1, 0x40 - uVar1);
    if (*(volatile s32*)(puVar3 + 0x4c) != 0) {
        *puVar4 = 0x40;
    }
}

extern "C" u8* __OSLockSram(void) {
    u8* puVar3 = Scb_802F6CC0;
    BOOL uVar2 = OSDisableInterrupts();
    s32* flag = (s32*)(puVar3 + 0x48);
    if (*flag != 0) {
        OSRestoreInterrupts(uVar2);
        puVar3 = 0;
    } else {
        *(BOOL*)(puVar3 + 0x44) = uVar2;
        *flag = 1;
    }
    return puVar3;
}

extern "C" u8* __OSLockSramEx(void) {
    u8* puVar3 = Scb_802F6CC0;
    BOOL uVar2 = OSDisableInterrupts();
    s32* flag = (s32*)(puVar3 + 0x48);
    if (*flag != 0) {
        OSRestoreInterrupts(uVar2);
        return 0;
    } else {
        *(BOOL*)(puVar3 + 0x44) = uVar2;
        *flag = 1;
    }
    return puVar3 + 0x14;
}

extern "C" void __OSUnlockSramEx(u32 param_1) {
    fn_801BF7E0(param_1, 0x14);
}

extern "C" u32 __OSSyncSram(void) {
    return *(u32*)(Scb_802F6CC0 + 0x4c);
}

extern "C" BOOL fn_801BFB74(void) {
    u8* puVar3 = Scb_802F6CC0;
    BOOL uVar2 = OSDisableInterrupts();
    s32* flag = (s32*)(puVar3 + 0x48);
    if (*flag != 0) {
        OSRestoreInterrupts(uVar2);
        puVar3 = 0;
    } else {
        *(BOOL*)(puVar3 + 0x44) = uVar2;
        *flag = 1;
    }
    BOOL bVar1 = (puVar3[0x13] & 4) ? 1 : 0;
    fn_801BF7E0(0, 0);
    return bVar1;
}

extern "C" u8 fn_801BFBF4(void) {
    u8* puVar3 = Scb_802F6CC0;
    BOOL uVar2 = OSDisableInterrupts();
    s32* flag = (s32*)(puVar3 + 0x48);
    if (*flag != 0) {
        OSRestoreInterrupts(uVar2);
        puVar3 = 0;
    } else {
        *(BOOL*)(puVar3 + 0x44) = uVar2;
        *flag = 1;
    }
    u8 bVar1 = (puVar3[0x13] >> 7) & 1;
    fn_801BF7E0(0, 0);
    return bVar1;
}

extern "C" u16 fn_801BFC64(u32 param_1) {
    u8* puVar3 = Scb_802F6CC0;
    BOOL uVar2 = OSDisableInterrupts();
    s32* flag = (s32*)(puVar3 + 0x48);
    u8* p;
    if (*flag != 0) {
        OSRestoreInterrupts(uVar2);
        p = 0;
    } else {
        *(BOOL*)(puVar3 + 0x44) = uVar2;
        *flag = 1;
        p = puVar3 + 0x14;
    }
    u16 uVar1 = *(u16*)(p + param_1 * 2 + 0x1c);
    fn_801BF7E0(0, 0x14);
    return uVar1;
}

extern "C" void fn_801BFCE8(u32 param_1, u16 param_2) {
    u8* puVar3 = Scb_802F6CC0;
    BOOL uVar2 = OSDisableInterrupts();
    s32* flag = (s32*)(puVar3 + 0x48);
    u8* p;
    if (*flag != 0) {
        OSRestoreInterrupts(uVar2);
        p = 0;
    } else {
        *(BOOL*)(puVar3 + 0x44) = uVar2;
        *flag = 1;
        p = puVar3 + 0x14;
    }
    u16* pVar = (u16*)(p + param_1 * 2 + 0x1c);
    if (*pVar == param_2) {
        fn_801BF7E0(0, 0x14);
    } else {
        *pVar = param_2;
        fn_801BF7E0(1, 0x14);
    }
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

extern "C" void fn_801BFFF0(u32* param_1) {
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    param_1[5] = 0xffffffff;
    param_1[4] = 0;
    param_1[7] = 0;
    param_1[6] = 0;
}

