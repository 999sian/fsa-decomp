#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e1978-0x801e30a0 (31 functions). split_file divides it into the game's real files.

extern "C" void* memset(void* p, int c, size_t n);
extern "C" void fn_801E20C8(u32* a, u32* b);
extern "C" void fn_801E1978(u32* a);
extern "C" void fn_801E1C2C(void* param_1, u32* param_2, u32 param_3);
extern "C" void __destroy_global_chain(void);
extern "C" void __exit(int);
extern s32 __aborting;
extern void (*_dtors[])(void);
extern void (*__stdio_exit)(void);
extern "C" void fn_801E1E24(u32* param_1, u32* param_2);
extern "C" void* fn_801E1DB0(void);
extern "C" void fn_801E1B90(void* param_1, u8* param_2);
extern "C" void fn_801E1B54(u8* param_1);
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
extern "C" void fn_801E23D4(u8* d, double x);
extern "C" void fn_801E2CB4(u8* param_1, s32 param_2);
extern "C" void fn_801E2D28(u8* param_1, s32 param_2);
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

#pragma dont_inline on
extern "C" void exit(int volatile status) {
    if (__aborting == 0) {
        void (**p)(void) = _dtors;
        __begin_critical_region(0);
        __end_critical_region(0);
        __destroy_global_chain();
        p = _dtors;
        while (*p != 0) {
            (*p)();
            p++;
        }
        if (__stdio_exit != 0) {
            __stdio_exit();
            __stdio_exit = 0;
        }
    }
    __exit(status);
}
#pragma dont_inline reset
extern "C" void fn_801E1B54(u8* volatile param_1) {
    __begin_critical_region(1);
    void* p = fn_801E1DB0();
    fn_801E1B90(p, param_1);
    __end_critical_region(1);
}

extern "C" void fn_801E1B90(void* volatile param_1, u8* param_2) {
    if (param_2 != 0) {
        u32* p = (u32*)param_2;
        u32 size;
        if ((p[-1] & 1) == 0) {
            size = ((u32*)p[-1])[2];
        } else {
            size = (p[-2] & ~7) - 8;
        }
        if (size > 0x44) {
            fn_801E1E24((u32*)param_1, p);
        } else {
            fn_801E1C2C(param_1, p, size);
        }
    }
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

extern "C" void fn_801E1F1C(volatile u32* b, volatile u32* volatile* list) {
    register volatile u32* next = (volatile u32*)((char*)b + (*b & ~7));
    register u32 size;
    if (!(*next & 2)) {
        size = (*b & ~7) + (*next & ~7);
        *b &= 7;
        *b |= size & ~7;
        if (!(*b & 2)) {
            *(volatile u32*)((char*)b + size - 4) = size;
        }
        if (!(*b & 2)) {
            *(volatile u32*)((char*)b + size) &= ~4;
        } else {
            *(volatile u32*)((char*)b + size) |= 4;
        }
        if (*list == next) {
            *list = (volatile u32*)(*list)[3];
        }
        if (*list == next) {
            *list = 0;
        }
        ((volatile u32*)next[3])[2] = next[2];
        ((volatile u32*)next[2])[3] = next[3];
    }
}

extern "C" void fn_801E2000(u32* param_1, u32** param_2) {
    u32 uVar1;
    u32* puVar2;
    if ((*param_1 & 4) == 0 && (uVar1 = param_1[-1], (uVar1 & 2) == 0)) {
        puVar2 = (u32*)((u32)param_1 - uVar1);
        *puVar2 = *puVar2 & 7;
        *puVar2 = *puVar2 | ((uVar1 + (*param_1 & ~7)) & ~7);
        if ((*puVar2 & 2) == 0) {
            *(u32*)((u8*)puVar2 + uVar1 + ((*param_1 & ~7) - 4)) = uVar1 + (*param_1 & ~7);
        }
        if (*param_2 == param_1) {
            *param_2 = *(u32**)((u8*)*param_2 + 0xc);
        }
        *(u32*)(param_1[3] + 8) = param_1[2];
        *(u32*)(*(u32*)(param_1[3] + 8) + 0xc) = param_1[3];
    }
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

#pragma push
#pragma optimization_level 0
extern "C" void fn_801E22E8(u8* fmt, double x, u8* d) {
    register u8* f = fmt;
    s16 digits = *(s16*)(f + 2);
    int i;
    fn_801E23D4(d, x);
    if (d[5] > 9) {
        return;
    }
    if (digits > 36) {
        digits = 36;
    }
    fn_801E2CB4(d, digits);
    while (d[4] < digits) {
        d[d[4]++ + 5] = 0;
    }
    *(s16*)(d + 2) -= d[4] - 1;
    for (i = 0; i < d[4]; i++) {
        d[i + 5] += '0';
    }
}

extern "C" void fn_801E28E8(u8* param_1, char* param_2, s16 param_3) {
    s32 i = 0;
    char* q;
    *(s16*)(param_1 + 2) = param_3;
    param_1[0] = 0;
    for (; i < 0x24 && *param_2 != 0; ) {
        param_1[i + 5] = *param_2++ - '0';
        i++;
    }
    param_1[4] = i;
    if (*param_2 == 0) {
        return;
    }
    if (*param_2 < 5) {
        return;
    }
    if (*param_2 <= 5) {
        q = param_2 + 1;
        while (*q != 0) {
            if (*q != '0') {
                break;
            }
            q++;
        }
        if ((param_1[i + 4] & 1) == 0) {
            return;
        }
    }
    fn_801E2D28(param_1, param_1[4]);
}

#pragma pop
extern "C" s32 fn_801E2D9C(u8* param_1, s32 param_2);
extern "C" void fn_801E2D28(u8* param_1, s32 param_2);
extern "C" void fn_801E367C(u8* param_1);
extern "C" void fn_801E1B54(u8* param_1);
extern "C" void* fn_801E1DB0(void);
extern "C" void fn_801E1B90(void* param_1, u8* param_2);
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

extern "C" void fn_801E3068(u8* p);
extern "C" void fn_801E309C(void* p, u32* n);

extern "C" int fn_801E2F8C(int param_1) {
    if (param_1 >= 0) {
        return param_1;
    }
    param_1 = -param_1;
    return param_1;
}

#pragma dont_inline on
extern "C" int fn_801E2F9C(u32* p, u32* out) {
    u32 n;
    int r;
    if ((n = p[9] - p[7]) != 0) {
        p[10] = n;
        if (!((((u8*)p)[5] >> 3) & 1)) {
            fn_801E309C((void*)p[7], &p[10]);
        }
        r = ((int (*)(u32, u32, u32*, u32))p[0x10])(p[0], p[7], &p[10], p[0x12]);
        if (out != 0) {
            *out = p[10];
        }
        if (r != 0) {
            return r;
        }
        p[6] += p[10];
    }
    fn_801E3068((u8*)p);
    return 0;
}
#pragma dont_inline reset

extern "C" void fn_801E3068(u8* p) {
    *(u32*)(p + 0x24) = *(u32*)(p + 0x1c);
    *(u32*)(p + 0x28) = *(u32*)(p + 0x20);
    *(u32*)(p + 0x28) -= *(u32*)(p + 0x18) & *(u32*)(p + 0x2c);
    *(u32*)(p + 0x34) = *(u32*)(p + 0x18);
}

extern "C" void fn_801E309C(void* p, u32* n) {}
