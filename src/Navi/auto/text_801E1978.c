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
extern "C" void __begin_critical_region(int);
extern "C" void __end_critical_region(int);
extern "C" void __kill_critical_regions(void);
extern "C" void _ExitProcess(void);
extern s32 lbl_802FFA94;
extern void (*lbl_802F85E0[])(void);
extern void (*lbl_802FFA9C)(void);
extern "C" void __exit(int) {
    __begin_critical_region(0);
    while (lbl_802FFA94 > 0) {
        lbl_802FFA94--;
        lbl_802F85E0[lbl_802FFA94]();
    }
    __end_critical_region(0);
    __kill_critical_regions();
    if (lbl_802FFA9C != NULL) {
        lbl_802FFA9C();
        lbl_802FFA9C = NULL;
    }
    _ExitProcess();
}

extern "C" void* fn_801E1DB0(void) {
    if (lbl_802FFAA0 == 0) {
        fn_801E1DF4(lbl_802F86E0);
        lbl_802FFAA0 = 1;
    }
    return lbl_802F86E0;
}

extern "C" void fn_801E1DF4(void* param_1) {
    memset(param_1, 0, 0x34);
}

extern "C" void fn_801E1E24(u32* param_1, u32* param_2) {
    u32* block = (u32*)(param_2[-1] & ~1);
    fn_801E20C8(block, param_2 - 2);
    BOOL bVar1 = 0;
    if ((block[4] & 2) == 0) {
        if ((block[4] & ~7) == ((block[3] & ~7) - 0x18)) {
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

extern "C" s64 fn_801E2F18(s32 n, s32 d) {
    union {
        struct {
            s32 quot;
            s32 rem;
        } s;
        s64 v;
    } ret;
    int sn = 1;
    int sd = 1;
    if (n < 0) {
        n = -n;
        sn = -1;
    }
    if (d < 0) {
        d = -d;
        sd = -1;
    }
    ret.s.quot = (n / d) * (sn * sd);
    ret.s.rem = n * sn - sd * (*(volatile s32*)&ret.s.quot * d);
    return ret.v;
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
