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
extern "C" void OSReport(const char* fmt, ...);
extern "C" void* OSGetArenaLo(void);
extern "C" void* OSGetArenaHi(void);
extern "C" void OSSetArenaLo(void* p);
extern "C" void* fn_801BBE50(void* lo, void* hi, s32 align);
extern "C" void fn_801BBEC0(void* lo, void* hi);
extern "C" void fn_801BBE40(void);
extern "C" void fn_801BBDC4(s32 a, u32* b);
extern s32 lbl_802FE960;
extern char lbl_802026E8[];
extern char lbl_80202720[];
extern "C" void fn_801E1978(u32* param_1) {
    if (lbl_802FE960 == -1) {
        OSReport(lbl_802026E8);
        OSReport(lbl_80202720);
        u32 lo = (u32)OSGetArenaLo();
        u32 hi = (u32)OSGetArenaHi();
        lo = (u32)fn_801BBE50((void*)lo, (void*)hi, 1);
        OSSetArenaLo((void*)lo);
        u32 newLo = (lo + 0x1f) & ~0x1f;
        hi = hi & ~0x1f;
        fn_801BBEC0((void*)newLo, (void*)hi);
        fn_801BBE40();
        OSSetArenaLo((void*)hi);
    }
    fn_801BBDC4(lbl_802FE960, param_1);
}

extern "C" void __exit(int) {
    __begin_critical_region(0);
    while (lbl_802FFA94 > 0) {
        lbl_802F85E0[--lbl_802FFA94]();
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
    void* p = param_1;
    memset(p, 0, 0x34);
    return;
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
        piVar1 = 0;
    }
    if ((u32*)*param_1 == param_2) {
        *param_1 = (u32)piVar1;
    }
    if (piVar1 != 0) {
        *piVar1 = param_2[0];
        ((u32*)*piVar1)[1] = (u32)piVar1;
    }
    param_2[1] = 0;
    param_2[0] = 0;
    return piVar1;
}

extern "C" u8 lbl_8029E7B0[];
extern "C" int fn_801E3530(void* p);
extern "C" s32 fn_801E21CC(void) {
    u8* p = lbl_8029E7B0;
    s32 result = 0;
    while (p != 0) {
        if (((*(u16*)(p + 4) >> 6) & 7) != 0) {
            if (fn_801E3530(p) != 0) {
                result = -1;
            }
        }
        p = *(u8**)(p + 0x4c);
    }
    return result;
}

extern "C" s32 fn_801E2D9C(u8* param_1, s32 param_2);
extern "C" void fn_801E2D28(u8* param_1, s32 param_2);
extern "C" void fn_801E367C(u8* param_1);
extern "C" void fn_801E1B54(u8* param_1);
extern "C" void* fn_801E1DB0(void);
extern "C" void fn_801E1B90(void* param_1, u8* param_2);
extern "C" void fn_801E1C2C(void* param_1, u8* param_2, s32 param_3);
extern u8 lbl_8029E7B0[];
extern "C" void fn_801E2CB4(u8* param_1, s32 param_2) {
    if (param_2 > 0 && param_2 < param_1[4]) {
        s32 iVar1 = fn_801E2D9C(param_1, param_2);
        param_1[4] = param_2;
        if (iVar1 >= 0) {
            fn_801E2D28(param_1, param_2);
        }
    }
}

#pragma optimization_level 1
extern "C" void fn_801E2D28(register u8* p, register s32 n) {
    register u8* base;
    register u8* q;
    q = p + 5 + (n - 1);
    base = p + 5;
    while (1) {
        if (*q < 9) {
            *q = *q + 1;
            return;
        }
        if (q == base) {
            *q = 1;
            *(s16*)(p + 2) = *(s16*)(p + 2) + 1;
            return;
        }
        *q = 0;
        q--;
    }
}
#pragma optimization_level reset
extern "C" s32 fn_801E2D9C(u8* p, s32 n) {
    u8* q = p + (n + 5);
    u8* end;
    if (*q > 5) {
        return 1;
    }
    if (*q < 5) {
        return -1;
    }
    q++;
    end = p + (p[4] + 5);
    for (; q < end; q++) {
        if (*q != 0) {
            return 1;
        }
    }
    if (p[n + 4] & 1) {
        return 1;
    }
    return -1;
}

extern "C" s32 fn_801E2E8C(u32 x) {
    s32 bits = 32;
    s32 result = 0;
    s32 half = bits / 2;
    s32 step = half;
    u32 mask = 0xFFFFFFFF >> (bits - half);
    while (bits != 0) {
        if (!(x & mask)) {
            result += step;
            x >>= step;
            bits -= step;
        } else if (mask == 1) {
            break;
        }
        if (half > 1) {
            half /= 2;
        }
        if (mask > 1) {
            mask >>= half;
            step -= half;
        }
    }
    return result;
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
