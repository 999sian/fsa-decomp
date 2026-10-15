// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern volatile s32 lbl_8053BC70;

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

extern "C" void fn_800C9D04(void) {
}

extern "C" void fn_800C9D08(void) {
}

extern "C" s32 fn_800C9D0C(void) {
    return 0;
}

extern "C" void fn_800C9D14(void) {
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
    int p2_4 = *(int *)(param_2 + 4);
    int p2_8 = *(int *)(param_2 + 8);
    int p2_10 = *(int *)(param_2 + 0x10);
    s32 default_val = lbl_8053BC70;
    ushort idx1 = *(ushort *)(p2_8 + param_3 * 2);
    ushort uVar1 = *(ushort *)(p2_4 + idx1 * 0x14c + 8 + param_4 * 2);
    
    if (uVar1 != 0xffff) {
        *param_1 = *(int *)(p2_10 + ((uint)uVar1 << 2));
    } else {
        *param_1 = default_val;
    }
}

extern "C" void fn_800CBD64(void) {
}

extern "C" void fn_800CBD68(void) {
}

extern "C" s32 fn_800CBD6C(void) {
    return 0;
}

extern "C" void fn_800CBD74(void) {
}

extern "C" void fn_800CBD78(void)
{
}

void fn_800CBD7C(void)
{
}

s32 fn_800CBD80(void)
{
    return 0;
}

void fn_800CBD88(void)
{
}

extern "C" s32 fn_800CBD8C(void) {
    return 0;
}

extern "C" void fn_800CBD94(void) {
}

extern "C" void fn_800CBD98(void) {
}

extern "C" void fn_800CBD9C(void) {
}

extern "C" void fn_800CBDA0(void) {
}

extern "C" void fn_800CBDA4(void) {
}

extern "C" int fn_800CBDA8(void) {
    return 0;
}

extern "C" void fn_800CBDB0(void) {
}

extern "C" int fn_800CBDB4(void) {
    return 0;
}

extern "C" int fn_800CBDBC(void) {
    return 0;
}

extern "C" int fn_800CBDC4(void) {
    return 0;
}

extern "C" void fn_800CBDCC(void) {
}

