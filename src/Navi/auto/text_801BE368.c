#include "dolphin/os/OSMutex.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801be368-0x801bf0c8 (21 functions). split_file divides it into the game's real files.

extern "C" void fn_801C13D0(int);
extern "C" OSThread* fn_801C027C(void);
void fn_801BE544(int param_1)
{
    int iVar1;
    int iVar2;

    iVar2 = *(int *)(param_1 + 0x2f4);
    while (iVar2 != 0) {
        iVar1 = *(int *)(iVar2 + 0x10);
        if (iVar1 == 0) {
            *(int *)(param_1 + 0x2f8) = 0;
        }
        else {
            *(int *)(iVar1 + 0x14) = 0;
        }
        *(int *)(param_1 + 0x2f4) = iVar1;
        *(int *)(iVar2 + 0xc) = 0;
        *(int *)(iVar2 + 8) = 0;
        fn_801C13D0(iVar2);
        iVar2 = *(int *)(param_1 + 0x2f4);
    }
}

extern "C" void fn_801BE670(OSThreadQueue* queue)
{
    OSInitThreadQueue(queue);
}

extern "C" void fn_801BE764(int param_1)
{
    fn_801C13D0(param_1);
}

extern "C" BOOL fn_801BE884(u32 param_1)
{
    u32 iVar1;

    for (iVar1 = *(u32*)(param_1 + 0x2f0); iVar1 != 0 && (iVar1 = *(u32*)(iVar1 + 8)) != 0;
         iVar1 = *(u32*)(iVar1 + 0x2f0)) {
        if (iVar1 == param_1) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL fn_801BE784(int);
extern "C" BOOL fn_801BE8BC(u32 param_1)
{
    u32 iVar1;

    iVar1 = *(u32*)(param_1 + 0x2f4);
    while (iVar1 != 0) {
        if (*(u32*)(iVar1 + 8) != param_1) {
            return FALSE;
        }
        if (fn_801BE784(iVar1) == 0) {
            return FALSE;
        }
        iVar1 = *(u32*)(iVar1 + 0x10);
    }
    return TRUE;
}

