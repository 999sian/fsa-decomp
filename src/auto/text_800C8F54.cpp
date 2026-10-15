// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern s32 lbl_8053BC70;

#include <types.h>

void fn_800C9CF4(void)
{
}

void fn_800C9CF8(void)
{
}

void fn_800C9CFC(void)
{
}

void fn_800C9D04(void) {
}

void fn_800C9D08(void) {
}

void fn_800C9D0C(void) {
}

void fn_800C9D14(void) {
}

extern "C" void fn_800CAAA8(void) {
}

extern "C" void fn_800CAAAC(void* a, s32 v) {
    *(s32*)((u8*)a + 0x4) = v;
}

extern "C" s32 fn_800CAEC8(int param_1, u32 param_2) {
    s32 result = 0;
    if (param_2 == 0) {
        result = 100;
    }
    return result + 0x10;
}

extern "C" void fn_800CAEE0(s32 *param_1, int param_2, int param_3, int param_4) {
    ushort uVar1;
    
    uVar1 = *(ushort *)(*(int *)(param_2 + 4) + (uint)*(ushort *)(*(int *)(param_2 + 8) + param_3 * 2) * 0x14c + 8 + param_4 * 2);
    
    if (uVar1 == 0xffff) {
        *param_1 = lbl_8053BC70;
    } else {
        *param_1 = *(int *)(*(int *)(param_2 + 0x10) + (uint)uVar1 * 4);
    }
}

