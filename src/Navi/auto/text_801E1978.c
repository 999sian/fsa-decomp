#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e1978-0x801e30a0 (31 functions). split_file divides it into the game's real files.

extern "C" void* memset(void* p, int c, size_t n);
extern "C" void fn_801E20C8(u32* a, u32* b);
extern "C" void fn_801E1978(u32* a);
extern "C" u32* fn_801E1EBC(u32* param_1, u32* param_2);
extern u8 lbl_802FFAA0;
extern u8 lbl_802F86E0[];
extern "C" void fn_801E1DF4(void* param_1);
extern "C" void* fn_801E1DB0(void) {
    if (lbl_802FFAA0 == 0) {
        fn_801E1DF4(lbl_802F86E0);
        lbl_802FFAA0 = 1;
    }
    return lbl_802F86E0;
}

extern "C" void fn_801E1DF4(void* param_1) {
    void* p = param_1;
    memset(p, 0, 0x34);
}

extern "C" void fn_801E1E24(u32* param_1, u32* param_2) {
    u32* block = (u32*)(param_2[-1] & ~1);
    fn_801E20C8(block, param_2 - 2);
    u32* piVar2 = block + 4;
    BOOL bVar1 = 0;
    if ((*piVar2 & 2) == 0) {
        if ((*piVar2 & ~7) == ((block[3] & ~7) - 0x18)) {
            bVar1 = 1;
        }
    }
    if (bVar1) {
        fn_801E1EBC(param_1, block);
        fn_801E1978(block);
    }
}

extern "C" u32* fn_801E1EBC(u32* param_1, u32* param_2) {
    u32* piVar1 = (u32*)param_2[1];
    if (piVar1 == param_2) {
        piVar1 = nullptr;
    }
    if ((u32*)*param_1 == param_2) {
        *param_1 = (u32)piVar1;
    }
    if (piVar1 != nullptr) {
        piVar1[0] = param_2[0];
        ((u32*)piVar1[0])[1] = (u32)piVar1;
    }
    param_2[1] = 0;
    param_2[0] = 0;
    return piVar1;
}

extern "C" int fn_801E2F8C(int param_1) {
    if (param_1 >= 0) {
        return param_1;
    }
    param_1 = -param_1;
    return param_1;
}

extern "C" void fn_801E3068(u8* p) {
    *(u32*)(p + 0x24) = *(u32*)(p + 0x1c);
    *(u32*)(p + 0x28) = *(u32*)(p + 0x20);
    *(u32*)(p + 0x28) -= *(u32*)(p + 0x18) & *(u32*)(p + 0x2c);
    *(u32*)(p + 0x34) = *(u32*)(p + 0x18);
}

extern "C" void fn_801E309C(void) {}
