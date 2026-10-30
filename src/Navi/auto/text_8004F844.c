#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004f844-0x800575d8 (67 functions). split_file divides it into the game's real files.

extern void* lbl_80222428[];
struct Unk802C04D0 { int id; int unk4; int value; };
extern "C" Unk802C04D0 lbl_802C04D0[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80249D24[];
extern "C" void fn_80021DDC(void* p);
extern void* lbl_80247684[];
extern "C" void fn_8004F77C(void);
extern "C" void fn_801E0D40(void* dst, void* fn, s32 size, s32 count);
extern char lbl_802BB0FC[];
extern int lbl_802FF0E4;
extern "C" char lbl_802BB0FC[];
extern "C" int lbl_802FF0E4;
extern "C" char lbl_802C050C[];
extern "C" float lbl_803001FC;
extern int lbl_802FF0EC;
extern int lbl_802FF0E8;
extern "C" char lbl_802C05A0[];
extern "C" char lbl_802B7CA0[];
extern "C" u32 lbl_802313F8[];
extern "C" u8 lbl_802FEE34;
extern "C" u32 lbl_802FF1D0;
extern "C" u32 fn_80030390(u32);
extern "C" u32 lbl_8023133C[];
extern "C" void fn_800279A8(void* p, u32 a, s32 b, s32 c, s32 d);
extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_8002A3CC(void* p, void* q, s32 a, s32 b);
extern "C" void fn_80056B08(void* p);
extern "C" int fn_800572C0(int a, u32 mask);
extern "C" void fn_80058B64(s32 a);
extern "C" void fn_80058A28(s32 a);
extern "C" char lbl_80247690[];
extern "C" void fn_800300C0(int id, unsigned int flags, int val, int idx, float f);
extern "C" void fn_80089634(void* p, s32 n);
extern "C" void fn_801BEC7C(u32 param_1, u32 param_2);
extern "C" u32 lbl_802FF0D4;
extern "C" char lbl_802BB924[];
extern "C" u32 lbl_802FF0D8;
extern "C" s32 lbl_802FF0D0;
extern "C" u8 lbl_802C0490[];
extern "C" u32 lbl_802FEE20;
extern "C" s32 fn_8002584C(void* p);
extern "C" void fn_80052A38(void);
extern "C" void* fn_8004F844(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80247684;
        fn_801E0D40((char*)param_1 + 0x8, &fn_8004F77C, 0x90, 5);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8004F9D8(void) {
    u8* src;
    s32 i;
    fn_801BEC7C(lbl_802FF0D4, lbl_802FF0D8);
    for (i = 0, src = lbl_802C0490; i < lbl_802FF0D0; i++) {
        ((u8*)lbl_802FF0D4)[i] = *src++;
    }
}

extern "C" void fn_8004FA30(void) {}

extern "C" void fn_8004FD8C(void* param_1) {
    if (fn_8002584C(lbl_802BB924) == 4) {
        fn_80089634(param_1, 4);
    }
}

extern "C" void fn_800505D4(void* param_1)
{
    u32 r = fn_80030390(*(u8*)(lbl_802B7CA0 + 0x1419));
    u32 v;
    lbl_802FEE34 = 1;
    v = *(u32*)((u8*)lbl_802313F8 + (r << 2));
    lbl_802FF1D0 = 1;
    *(u32*)(lbl_802BB0FC + 0xfc) = v;
    *(u32*)((u8*)param_1 + 0xf6c) = 0;
}

extern "C" void fn_800508D8(void* param_1)
{
    fn_800279A8((u8*)param_1 + 0x1cc, lbl_8023133C[*(u32*)(lbl_802BB0FC + 0x420)], 0, 0, 1);
    fn_8002F358(0x7a, 0);
    lbl_802FF1D0 = 0;
}

extern "C" void fn_80050938(void* param_1)
{
    u32 v;
    *(u32*)(lbl_802BB0FC + 0x44) = 0xb;
    v = *(u32*)((u8*)param_1 + 0xfec);
    if (v & 0x20000000) {
        *(u32*)((u8*)param_1 + 0xfec) = v | 0x100;
    } else if (*(s32*)(lbl_802BB0FC + 0x58) >= 90000) {
        *(u32*)((u8*)param_1 + 0xfec) = v | 0x100;
    }
    fn_80056B08(param_1);
    if (fn_800572C0((int)param_1, *(u8*)((u8*)param_1 + 0xffa)) != 0 && (*(u32*)((u8*)param_1 + 0xfec) & 0x100) != 0) {
        fn_80058B64(0x130);
        lbl_802FEE34 = 0;
        fn_80089634(param_1, 7);
    }
}

extern "C" void fn_800509E8(void) {
    *(u32*)(lbl_802BB0FC + 0x104) |= 0x2;
}

extern "C" void fn_80052818(void* param_1) {
    fn_80052A38();
    *(u32*)((u8*)param_1 + 0xf6c) = 0;
    lbl_802FEE20 = *(u32*)(lbl_802BB0FC + 0x70);
}

extern "C" void fn_80052AFC(void) {
    f32 f = *(f32*)(lbl_802C050C + 0x8);
    lbl_802FF0E4 = (s32)(lbl_803001FC * f) + *(s32*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052B3C(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0xc)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052B7C(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x40)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052BBC(void* param_1) {
    fn_8002A3CC(param_1, lbl_802C05A0, 0x93, 1);
}

extern "C" void fn_80052BEC(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x14)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052C2C(void) {
    char* p = lbl_802C050C;
    int base = *(int*)(lbl_802BB0FC + 0x58);
    lbl_802FF0E4 = (int)(lbl_803001FC * *(float*)(p + 0x18)) + base;
}

extern "C" void fn_80052C6C(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x1c)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052CAC(void) {
    char* p = lbl_802C050C;
    lbl_802FF0E4 = (int)(lbl_803001FC * *(f32*)(p + 0x24)) + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052CEC(void) {
    f32 f = *(f32*)(lbl_802C050C + 0x28);
    lbl_802FF0E4 = (s32)(lbl_803001FC * f) + *(s32*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80052D2C(void) {
    s32 t = *(s32*)(lbl_802BB0FC + 0x58);
    lbl_802FF0E4 = t + (s32)(lbl_803001FC * *(f32*)(lbl_802C050C + 0x2c));
}

extern "C" void fn_80052D6C(void) {
    s32 t = *(s32*)(lbl_802BB0FC + 0x58);
    lbl_802FF0E4 = t + (s32)(lbl_803001FC * *(f32*)(lbl_802C050C + 0x30));
}

extern "C" void fn_80052DAC(void) {
    s32 t = *(s32*)(lbl_802BB0FC + 0x58);
    lbl_802FF0E4 = t + (s32)(lbl_803001FC * *(f32*)(lbl_802C050C + 0x34));
}

extern "C" void fn_80052DEC(void)
{
	int base = *(int*)(lbl_802BB0FC + 0x58);
	lbl_802FF0E4 = (int)(lbl_803001FC * *(float*)(lbl_802C050C + 0x38)) + base;
}

extern "C" void fn_80052E2C(void)
{
	lbl_802FF0E4 = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" char lbl_802C050C[];
extern "C" float lbl_803001FC;
extern "C" void fn_80052E44(void)
{
	lbl_802FF0E4 = *(int*)(lbl_802BB0FC + 0x58) + 500;
}

extern "C" void fn_80052E5C(void)
{
	int base = *(int*)(lbl_802BB0FC + 0x58);
	lbl_802FF0E4 = (int)(lbl_803001FC * *(float*)(lbl_802C050C + 0x3c)) + base;
}

extern "C" u32 fn_80021D04(void);
extern "C" u32 fn_8002185C(void* p);
extern "C" u32 fn_800218C4(void* p);
extern "C" char lbl_80228748[];
extern "C" u32 lbl_80248A38[];
extern "C" s32 lbl_802FED8C;
extern "C" void fn_80053190(void* param_1) {
    u32 idx;
    lbl_802FED8C = 0;
    *(u32*)(lbl_802BB0FC + 0x40) |= 4;
    *(u32*)(lbl_802B7CA0 + 0x3448) = *(u32*)(lbl_802B7CA0 + 0x3440);
    *(u32*)((u8*)param_1 + 0xf84) = fn_80021D04();
    *((u8*)param_1 + 0x1006) = 0;
    idx = *(u32*)(lbl_802BB0FC + 0x420);
    fn_800279A8((u8*)param_1 + 0x1cc, (u32)lbl_80228748, 0, 0, 1);
    *(u32*)(lbl_802BB0FC + 0x100) = 0;
    fn_80058A28(lbl_80248A38[idx]);
    *(u32*)((u8*)param_1 + 0xf6c) = 0x7e;
    *(u32*)((u8*)param_1 + 0xfc0) = fn_8002185C(lbl_802BB0FC);
    *(u32*)((u8*)param_1 + 0xfc4) = fn_800218C4(lbl_802BB0FC);
}

extern "C" void fn_8005556C(void* self, void* p) {
    fn_80021DDC(p);
}

extern "C" void fn_80055950(const char*, ...) {
}

extern "C" void fn_80055C08(void) {}

extern int lbl_802FF0E8;
extern "C" void fn_80055C0C(void)
{
	lbl_802FF0E8 = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" void fn_80055C24(void* param_1) {
    lbl_802FF0E8 = *(int*)(lbl_802BB0FC + 0x58) + 1000;
    fn_8002A3CC(param_1, lbl_802C05A0, 0xa3, 1);
}

extern "C" void fn_80055C68(void) {
    *(u32*)(lbl_802BB0FC + 0x108) |= 0x4000;
}

extern "C" void fn_80055C80(void* param_1) {
    *(u32*)((u8*)param_1 + 0xf6c) = 0;
    *(s32*)(lbl_802BB0FC + 0x44) = 0xf;
}

extern "C" void fn_80056374(void) {
    lbl_802FF0E8 = lbl_802FF0EC + *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_80056390(void* p) {
    *(u32*)(lbl_802BB0FC + 0x44) = 0x11;
    *(u32*)(lbl_802BB0FC + 0x10c) = 0;
    *(u32*)((u8*)p + 0xf6c) = 0;
    fn_80058A28(0x37);
    fn_80058A28(0x99);
    *(u32*)(lbl_802BB0FC + 0x444) &= ~0x8;
}

extern "C" void fn_80056B08(void* p) {
    u32 bit;
    for (u8 i = 0; i < 4; i++) {
        bit = 1 << i;
        if (*(u32*)(lbl_802B7CA0 + 0x3440) & bit) {
            if (*(u16*)(lbl_802BB0FC + 0xe4 + i * 2) == 0x30 && !(((u8*)p)[0xffa] & bit)) {
                ((u8*)p)[0xffa] |= bit;
            }
        }
    }
}

extern "C" int fn_800572C0(int a, u32 mask) {
    u8 m = *(u32*)(lbl_802B7CA0 + 0x3444);
    u8 v = mask & m;
    if (v != 0 && (v ^ m) == 0) {
        return 1;
    }
    return 0;
}

extern "C" int fn_800572F4(int a, u32 mask) {
    u8 m = *(u8*)(lbl_802BB0FC + 0xec);
    u8 v = mask & m;
    if (v != 0 && (v ^ m) == 0) {
        return 1;
    }
    return 0;
}

extern "C" BOOL fn_80057324(void* p, u16 id) {
    u32 bit;
    for (u8 i = 0; i < 4; i++) {
        bit = 1 << i;
        if (*(u32*)(lbl_802B7CA0 + 0x3440) & bit) {
            if (id == *(u16*)(lbl_802BB0FC + 0xe4 + i * 2)) {
                ((u8*)p)[0xffc] |= bit;
            }
        }
    }
    u8 flags = ((u8*)p)[0xffc];
    u8 m = *(u32*)(lbl_802B7CA0 + 0x3444);
    flags &= m;
    if (flags != 0 && (flags ^ m) == 0) {
        return TRUE;
    }
    return FALSE;
}

extern "C" u16 fn_800F0E58(char* p);
extern "C" u8 lbl_802BB778[];
extern "C" BOOL fn_800573C0(void* p, s32 param_2) {
    u8 i;
    if (param_2 != 0) {
        if ((*(u16*)(lbl_802B7CA0 + 0x412) & (1 << *(u32*)(lbl_802B7CA0 + 0x343c))) == 0) {
            return 0;
        }
    } else if ((s32)fn_800F0E58(lbl_802B7CA0) == 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (*(u32*)(lbl_802B7CA0 + 0x3440) & (1 << i)) {
            if (lbl_802BB778[i * 0x50 + 0x32] & 1) {
                return 1;
            }
        }
    }
    return 0;
}

extern "C" int fn_80057488(u32 mask) {
    u32* bits = (u32*)(lbl_80247690 + 0x2590);
    f32* fs = (f32*)(lbl_80247690 + 0x2600);
    s16* vals = (s16*)(lbl_80247690 + 0x262c);
    u32* flags = (u32*)(lbl_80247690 + 0x25d4);
    s16* ids = (s16*)(lbl_80247690 + 0x25bc);
    int n = 0;
    int i = 0;
    do {
        if (mask & (1 << *bits)) {
            fn_800300C0(*ids, *flags, *vals, 0, *fs);
            vals++;
            n++;
        }
        i++;
        fs++;
        flags++;
        ids++;
        bits++;
    } while (i < 11);
    return n;
}

extern "C" int fn_80057530(int id) {
    int i;
    for (i = 0; i < 4; i++) {
        if (id == lbl_802C04D0[i].id) {
            return lbl_802C04D0[i].value;
        }
    }
    return -1;
}

extern "C" void* fn_8005757C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80249D24;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
extern "C" s32 lbl_802FF178;
extern "C" s32 lbl_802FEDDC;
extern "C" s32 lbl_802FEE0C;
extern "C" u8 lbl_802FF05A;
extern "C" u8 lbl_802FF05B;
