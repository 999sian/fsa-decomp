#include "dolphin/os/OSThread.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801be368-0x801bf0c8 (21 functions). split_file divides it into the game's real files.

void fn_801C13D0(int);
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

void fn_801BE670(OSThreadQueue* queue)
{
    OSInitThreadQueue(queue);
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

