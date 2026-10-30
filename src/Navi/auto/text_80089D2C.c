#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80089d2c-0x8008adf4 (11 functions). split_file divides it into the game's real files.

extern "C" void fn_8008A15C(void);
extern void fn_80022D74(int);
extern void fn_8011AED8(int, int, int);
extern void fn_801E10DC(int);
extern u16 lbl_802BB8D0[];
extern u32* lbl_80225C94[];
extern int lbl_80284458[];
void fn_8008AAD0(u32 param_1, int param_2)
{
    u32 uVar1;
    int iVar2;
    u32 uVar3;
    u16 *puVar5;
    u32 uVar6;
    u32 *puVar7;
    
    uVar6 = 0;
    puVar5 = (u16 *)&lbl_802BB8D0;
    puVar7 = *(u32 **)(((int)lbl_80225C94) + param_2 * 4);
    
    while (1) {
        uVar1 = *puVar7;
        if ((uVar1 & 0x8000000) != 0) break;
        if ((uVar1 & 0x1ff0000) == 0x1fe0000) {
            *((u16 *)(puVar5 + 0x6)) = (u16)uVar1;
            puVar5 = puVar5 + 1;
            uVar6 = uVar6 + 1;
        }
        puVar7 = puVar7 + 1;
    }
    
    uVar3 = 0x10 - uVar6;
    if ((int)uVar6 < 0x10) {
        uVar6 = (uVar3 >> 3);
        if (uVar6 != 0) {
            do {
                iVar2 = (int)puVar5;
                *(u16 *)(iVar2 + 0xc) = 0;
                *(u16 *)(iVar2 + 0xe) = 0;
                *(u16 *)(iVar2 + 0x10) = 0;
                *(u16 *)(iVar2 + 0x12) = 0;
                *(u16 *)(iVar2 + 0x14) = 0;
                *(u16 *)(iVar2 + 0x16) = 0;
                *(u16 *)(iVar2 + 0x18) = 0;
                *(u16 *)(iVar2 + 0x1a) = 0;
                puVar5 = (u16 *)((int)puVar5 + 0x10);
                uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            uVar3 = uVar3 & 7;
            if (uVar3 == 0) {
                return;
            }
        }
        do {
            *((u16 *)((int)puVar5 + 0xc)) = 0;
            puVar5 = (u16 *)((int)puVar5 + 2);
            uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
    }
}

int fn_8008ACE8(int param_1)
{
    fn_80022D74(param_1 + 0x1c4);
    return 1;
}

extern "C" void fn_8008AD10(void) {
    fn_8008A15C();
}

int fn_8008AD30(int param_1)
{
    int *r31;
    int r30;
    
    r31 = (int *)&lbl_80284458;
    fn_8011AED8(0x104, 0x32, (int)r31 + 0x30);
    fn_801E10DC(param_1);
    fn_8011AED8(0x118, 0x154, (int)r31 + 0x3c);
    fn_8011AED8(0x118, 0x168, (int)r31 + 0x54);
    fn_8011AED8(0x118, 0x17c, (int)r31 + 0x6c);
    fn_8011AED8(0x118, 0x190, (int)r31 + 0x84);
    return 1;
}

extern "C" BOOL fn_8008ADEC(void) {
    return TRUE;
}

