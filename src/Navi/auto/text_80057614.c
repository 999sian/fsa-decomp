#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80057614-0x800618fc (176 functions). split_file divides it into the game's real files.

extern u8 lbl_802C05F0[];
extern char lbl_8027D36C[];
extern char lbl_8027D49C[];
extern "C" void fn_8005C330(const char*, ...);

inline BOOL fn_8005A74C_isBadPtr(void* p) {
    if (((u32)p & 0xF0000000) != 0x80000000) {
        fn_8005C330((const char*)1, lbl_8027D36C, lbl_8027D49C, p);
        return TRUE;
    }
    return FALSE;
}
extern u8 lbl_802FF0F8;
extern u32 lbl_802FF0FC;
extern s32 lbl_802FF104;
extern s32 lbl_802FF108;
extern "C" s32 fn_8005C248(s32 idx);
extern u8 lbl_802C2130[];
extern char lbl_8027D730[];
extern "C" void fn_8005C21C(s32 idx);
extern "C" void OSRestoreInterrupts(u32 level);
extern u8 lbl_802B7CA0[];
extern u8 lbl_802BB0FC[];
extern "C" void fn_8002F8D4(void*);
extern "C" double fn_80059DA0(void*);
extern "C" void fn_80059338(void*);
extern "C" void fn_80059768(void*);
extern "C" void fn_80059B68(void*);
extern const double lbl_803002B0;
extern "C" unsigned char lbl_802C05B0[];
extern "C" void fn_8005869C(s32 param_1, s32 param_2);
extern "C" s32 fn_8005871C(s32 p);
extern "C" void fn_800583D8(s32 idx);
extern u8 lbl_8026D4BC[];
extern "C" void fn_800592CC(void* p);
extern "C" void fn_80059290(void* p);
extern "C" s32 fn_80058D70(s32 idx);
extern u8 lbl_802FC71C[4];
extern void* lbl_802FE960;
extern "C" void fn_801BBDC4(void*, s32);
extern "C" void fn_8005C170(s32 param_1);
extern char lbl_8027D714[];
extern "C" void* fn_801BBCC8(void*, s32);
extern "C" void fn_8005C0BC(void*, s32, s32, s32);
extern "C" void fn_80058E5C(s32 idx, s32* a, s32* b);
extern void* lbl_8027EC78[];
extern void* lbl_80299A8C[];
extern void* lbl_802044AC[];
extern u8 lbl_8027D7C0[];
extern s32 lbl_8027D340[];
extern u8 lbl_802FF140;
extern f32 lbl_802FF144;
extern const f32 lbl_802FF148;
extern const f32 lbl_803002D0;
extern const f32 lbl_803002F4;
extern const f32 lbl_80300338;
extern const f32 lbl_80300340;
extern u8 lbl_802C2D7C[];
extern void* lbl_802FF328;
extern u8 lbl_802BF75C[];
extern u8 lbl_8027EA6C[];
extern "C" void fn_801DC264(s32, s32, s32, s32);
extern "C" void fn_801DBBFC(s32, s32, s32, s32);
extern "C" void fn_801DBCAC(s32, s32, s32, s32);
extern "C" void fn_801DC5E8(void*, u8);
extern "C" void fn_801DB4F8(void);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void*, void*, s32, ...);
extern "C" void fn_80007AB8(void*, s32, ...);
extern "C" void fn_80089634(void* p, s32 n);
extern "C" void fn_80058B64(s32 a);
extern "C" void fn_80057EE0(void);
extern "C" void fn_80058D00(void);
extern "C" void fn_8005A484(void);
extern s32 lbl_80249DA0[];
extern u8 lbl_802FF100;
extern u8 lbl_802FF101;
extern s32 lbl_802FF10C;
extern s32 lbl_802FF110;
extern s32 lbl_802FF114;
extern u8 lbl_802C2D30[];
extern u8 lbl_8027D790[];
extern u8 lbl_8027D780[];
extern u8 lbl_802C2D60[];
extern "C" void fn_801473F8(s32, void*, void*, s32, s32, void*, void*, s32, s32);
extern "C" void fn_8005C5DC(void);
extern "C" void fn_8017E1A4(void*, s32);
extern "C" void fn_80057AE0(s32);
extern "C" void fn_80057D38(void);
extern "C" void fn_8005CB00(void);
extern "C" void fn_8005B400(void);
extern "C" void fn_80058C5C(void);
extern "C" void fn_80057D70(void);
extern "C" void fn_8005C380(void);
extern "C" void fn_8005CAC8(void);
extern "C" void fn_8005C710(void);
extern "C" void fn_80057CF8(void);
extern "C" void fn_8015AB1C(void*);
extern void* lbl_8027EC68[];
extern "C" void fn_801BFEBC(void* param_1, void* param_2);
extern "C" void fn_801BFEE8(void* param_1);
extern "C" void fn_801BFF24(void* param_1);
extern "C" void fn_801BFFF0(void* param_1);
extern u8 lbl_802FC720[4];
extern "C" void fn_80057DF0(void);
extern "C" void fn_8005C3CC(void);
extern "C" void fn_8005CB14(void);
extern "C" void fn_80058CB0(void);
extern "C" void fn_8005A480(void);
extern "C" void fn_8005B450(void);
extern "C" s32 fn_80058A88(s32);
extern "C" void fn_80075618(s32);
extern "C" void fn_80089634(void*, s32);
extern "C" void fn_80147300(s32);
extern u32 lbl_802FBA78;
extern "C" void fn_801DA39C(s32, s32, s32, s32, s32);
extern "C" void fn_801DA364(void);
extern "C" void fn_801D9F18(s32, s32);
extern "C" void fn_801DAC08(s32, void*, s32);
extern "C" void fn_801DF2A4(void*, s32);
extern "C" void fn_801DF344(s32);
extern "C" void fn_801DE4F4(s32, void*);
extern "C" void fn_801DF0BC(void*, s32);
extern "C" void fn_801DEE10(s32);
extern "C" void fn_801DEE3C(s32);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8005845C(void*, s32, s32, f32, s32, s32);
extern "C" void fn_8005C424(void);
extern "C" void fn_8005B454(s32, s32, s32);
extern "C" s32 fn_80058DB8(s32);
extern "C" s32 fn_8005B82C(s32, s32, s32);
extern "C" u32 fn_8005B97C(s32, s32, s32);
extern "C" void fn_8005B6CC(s32, s32, s32);
extern "C" void fn_8005C460(void);
extern "C" s32 fn_80059190(s32 idx);
extern "C" void fn_800595FC(void);
struct VObj_8005E8B8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56(s32, s32, s32, s32);
};

extern "C" void fn_80057614(u8* p) {
    *(u32*)(p + 0xf6c) = 0;
}

extern "C" void fn_80057734(u8* p) {
    *(u32*)(p + 0xf6c) = 0;
    fn_80075618(0);
}

extern "C" void fn_80057868(void) {
}

extern "C" void fn_8005786C(void* param_1) {
    s32 i;
    s32 v;
    s32 flag = 1;
    for (i = 0; (v = lbl_80249DA0[i]) != 0; i++) {
        if (fn_80058A88(v) == 0) {
            flag = 0;
        }
    }
    if (flag != 0) {
        fn_80089634(param_1, 2);
    }
}

extern "C" void fn_800578E8(void) {
    if (lbl_802B7CA0[0x141a] != 0) {
        if (*(u32*)(lbl_802B7CA0 + 0x3f4) & 1) {
            *(u32*)(lbl_802BB0FC + 0x44) = 6;
        } else {
            *(u32*)(lbl_802BB0FC + 0x44) = 4;
        }
        fn_8002F8D4(*(void**)(lbl_802BB0FC + 0x420));
    } else {
        *(u32*)(lbl_802BB0FC + 0x44) = 1;
    }
}

extern "C" void fn_8005796C(void* p) {
    s32 i;
    s32 v;
    if (*(s32*)(lbl_802BB0FC + 0x44) == 8) {
        fn_80089634(p, 3);
        for (i = 0; (v = ((s32*)lbl_80249DA0)[i]) != 0; i++) {
            fn_80058B64(v);
        }
    }
}

extern "C" void fn_800579CC(void) {
    *(s32*)(lbl_802BB0FC + 0x44) = 0x13;
}

extern "C" void fn_800579E0(void) {
}

extern "C" void fn_800579E4(void) {
    *(s32*)(lbl_802BB0FC + 0x44) = 0x12;
}

extern "C" void fn_800579F8(void) {
}

extern u8 lbl_802FF0F0;
extern u32 lbl_80300228;
extern u32 lbl_8030022C;
extern u8 lbl_8027D350[];
extern u8 lbl_8027D35C[];
extern "C" void fn_801CF638(void* p, s32 n);
extern "C" void fn_801CEFCC(s32 n);
extern "C" void fn_801554E0(s32, s32, s32, s32, s32, s32);
extern "C" void fn_80158214(s32 p);
extern "C" void fn_801472A0(void* p1, void* p2, void* p3);
extern "C" void fn_8005A33C(void);
extern "C" void fn_801D1148(void);
extern "C" void fn_8005C074(void);
extern "C" void fn_800579FC(void) {
    u32 buf[2];

    buf[0] = lbl_80300228;
    buf[1] = lbl_8030022C;
    fn_8005C330(0, lbl_8027D350);
    lbl_802FF100 = 1;
    lbl_802FF0F8 = 0;
    fn_801CF638(&lbl_802FF0F0, 2);
    fn_801D1148();
    fn_801CEFCC(0);
    fn_8005C074();
    fn_80158214((s32)buf);
    fn_801554E0(0x40, 0x20, 0x20, 1, 0, 0x800000);
    fn_80057AE0(lbl_802FF101);
    fn_80057D38();
    fn_8005CB00();
    fn_8005B400();
    fn_8005A33C();
    fn_80058C5C();
    fn_80057D70();
    fn_8005C380();
    fn_8005CAC8();
    fn_801472A0((void*)0x7f, 0, (void*)0xff);
    fn_8005C710();
    fn_80057CF8();
    fn_8005C330(0, lbl_8027D35C);
}

extern "C" void fn_80057AE0(s32 param_1) {
    if (lbl_802FF100 != 0 && lbl_802FF101 < 2) {
        lbl_802FF101 = param_1;
        fn_80147300(lbl_802FC720[param_1]);
    }
}

extern "C" void fn_80057B24(void) {
    if (lbl_802FF100 != 0) {
        fn_8005C424();
        fn_80057DF0();
        fn_8005CB14();
        fn_80058CB0();
        fn_8005A480();
        fn_8005B450();
        fn_8005C460();
        fn_8005C3CC();
    }
}

extern "C" void fn_80057B6C(void) {
    fn_8005C424();
    fn_80057EE0();
    fn_80058D00();
    fn_8005A484();
    fn_8005C460();
}

#pragma use_lmw_stmw off
extern "C" void fn_80057B9C(s32 param_1) {
    u32 max = 0x10000;
    s32 i;
    u8* p;
    void fn_80058D50(void* p);
    fn_8005C424();
    i = 0;
    p = lbl_802C05F0;
    do {
        if (p[0x12] != 0) {
            if (p[0x12] == 1) {
                fn_80058D50(p);
            } else {
                p[0x13] = 3;
                if (param_1 > 0) {
                    *(s16*)(p + 0x10) = *(u16*)(p + 0xa) / param_1;
                } else {
                    *(s16*)(p + 0x10) = (u16)max - 0x218;
                }
            }
        }
        i++;
        p += 0x18;
    } while (i < 0x10);
    fn_8005C460();
}
#pragma use_lmw_stmw reset
extern "C" void fn_80057C38(s32 param_1) {
    s32 i;
    u8* p;
    void fn_80058D50(void* p);
    fn_8005C424();
    i = 0;
    p = lbl_802C05F0;
    do {
        if (p[0x12] != 0 && (s32)lbl_8026D4BC[*(s32*)p * 0xc] == 1) {
            if (p[0x12] == 1) {
                fn_80058D50(p);
            } else {
                p[0x13] = 3;
                if (param_1 > 0) {
                    *(s16*)(p + 0x10) = *(u16*)(p + 0xa) / param_1;
                } else {
                    *(s16*)(p + 0x10) = (0x10000 - 0x218);
                }
            }
        }
        i++;
        p += 0x18;
    } while (i < 0x10);
    fn_8005C460();
}

extern "C" void fn_80057CF8(void) {
    u8 n = lbl_802FF0F8;
    if (n != 0) {
        n--;
        lbl_802FF0F8 = n;
        if (n == 0) {
            OSRestoreInterrupts(lbl_802FF0FC);
        }
    }
}

extern u8 lbl_802FF0F8;
extern u32 lbl_802FF0FC;
extern "C" BOOL OSDisableInterrupts(void);
extern "C" void fn_80057F74(u8* p);
extern "C" void fn_80057D38(void) {
    u8 n = lbl_802FF0F8;
    lbl_802FF0F8 = n + 1;
    if (n == 0) {
        lbl_802FF0FC = OSDisableInterrupts();
    }
}

extern "C" void fn_80057D70(void) {
    u32* base = (u32*)lbl_802C05B0;
    u32* p = base;
    s32 i = 0;
    base[0] = 0;
    base[1] = 0;
    do {
        fn_80057F74((u8*)(p + 2));
        i++;
        p++;
    } while (i < 2);
    base[4] = 0;
    base[5] = -1;
    base[6] = 0;
    *(u8*)&base[7] = 0;
}

extern "C" void fn_80057EE0(void) {
    s32 i = 0;
    do {
        fn_800583D8(i);
        i++;
    } while (i < 2);
    u32* base = (u32*)lbl_802C05B0;
    u32* p = base;
    i = 0;
    base[0] = 0;
    base[1] = 0;
    do {
        fn_80057F74((u8*)(p + 2));
        i++;
        p++;
    } while (i < 2);
    base[4] = 0;
    base[5] = -1;
    base[6] = 0;
    *(u8*)&base[7] = 0;
}

extern "C" void fn_80057F74(u8* p) {
    if (p == nullptr) {
        return;
    }
    *(u16*)p = 0;
    p[2] = 0;
    p[3] = 1;
}

extern "C" void fn_800581CC(void) {
    unsigned char* base = lbl_802C05B0;
    if (base[0xa] == 1) {
        s32 v = 1;
        s32 old = base[0xb];
        if (base[0xe] == 1) {
            v = 2;
        }
        base[0xb] = v;
        if ((unsigned char)v != old) {
            fn_8005869C(0x8000, (unsigned char)v);
        }
    }
}

extern "C" void fn_80058230(void) {
    s32 i = 0;
    do {
        s32 id = i + 0x8000;
        if (lbl_802C05B0[i * 4 + 0xa] != 0 && fn_8005871C(id) == 0) {
            fn_800583D8(i);
        }
        i++;
    } while (i < 2);
}

extern "C" void fn_800583D8(s32 idx);
extern "C" void fn_80058628(void* a, s32 b, s32 c);
extern "C" void fn_800582A0(s32 idx, s32 val) {
    unsigned char* base = lbl_802C05B0;
    unsigned char* e = base + idx * 4 + 8;
    if (idx < 0 || idx >= 2) {
        return;
    }
    fn_800583D8(idx);
    bool b = false;
    if (idx == 0 && base[0xe] == 1) {
        b = true;
    }
    s32 mode = 1;
    if (b) {
        mode = 2;
    }
    fn_80058628((void*)(idx + 0x8000), val, mode);
    *(unsigned short*)e = val;
    e[2] = 1;
    e[3] = mode;
}

extern "C" void fn_8005835C(s32 idx) {
    s32 id = idx + 0x8000;
    unsigned char* e = lbl_802C05B0 + idx * 4 + 8;
    switch (idx) {
    case 0:
    case 1:
        if (e[2] == 1) {
            fn_8005869C(id, 3);
            e[2] = 2;
            e[3] = 3;
        }
        break;
    }
}

extern "C" unsigned char lbl_802C05B0[];
extern "C" void fn_8005869C(s32 param_1, s32 param_2);

extern "C" unsigned char lbl_802C05B0[];
extern "C" void fn_800589CC(s32 param_1);
extern "C" void fn_800583D8(s32 idx) {
    s32 id = idx + 0x8000;
    unsigned char* e = lbl_802C05B0 + idx * 4 + 8;
    switch (idx) {
    case 0:
    case 1:
        if (e[2] != 0) {
            fn_800589CC(id);
        }
        if (e != 0) {
            *(unsigned short*)e = 0;
            e[2] = 0;
            e[3] = 1;
        }
        break;
    }
}

extern "C" void fn_80058628(void* a, s32 b, s32 c) {
    fn_8005845C(a, b, c, 0.0f, -1, -1);
}

extern "C" void fn_80058654(void* a, s32 b, s32 c, f32 d) {
    fn_8005845C(a, b, c, d, -1, -1);
}

extern "C" void fn_8005867C(void* a, s32 b, s32 c, f32 d, s32 e, s32 f) {
    fn_8005845C(a, b, c, d, e, f);
}

extern "C" void fn_8005869C(s32 param_1, s32 param_2) {
    fn_8005C424();
    if (param_1 >= 1 && param_1 <= 0xffff && param_2 >= 1 && param_2 <= 3) {
        u8* p = (u8*)fn_80059190(param_1);
        if (p != 0) {
            p[0x13] = param_2;
            *(u16*)(p + 0x10) = 0x80;
        }
    }
    fn_8005C460();
}

extern "C" s32 fn_80058740(s32, s32);
extern "C" s32 fn_8005871C(s32 p) {
    return fn_80058740(p, 0);
}

extern "C" s32 fn_80058740(s32 param_1, s32 param_2) {
    s32 result = 0;
    fn_8005C424();
    if (param_1 >= 1 && param_1 <= 0xffff) {
        s32* p = (s32*)fn_80059190(param_1);
        if (p != 0 && (param_2 == 0 || param_2 == *p)) {
            result = 1;
        }
    }
    fn_8005C460();
    return result;
}

extern "C" s32 fn_800587CC(s32 param_1, s32 param_2) {
    s32 result = 0;
    fn_8005C424();
    if (param_1 >= 1 && param_1 <= 0xffff) {
        s32* p = (s32*)fn_80059190(param_1);
        if (p != 0 && (param_2 == 0 || param_2 == *p)) {
            switch (((u8*)p)[0x12]) {
            case 1:
                result = 1;
                break;
            case 2:
                result = 2;
                break;
            }
        }
    }
    fn_8005C460();
    return result;
}

extern "C" s32 fn_801E6840(s32);
extern "C" s32 fn_801E6510(s32, void*, s32);
extern u32 lbl_802FC724;
extern "C" s32 fn_8005887C(s32 param_1) {
    extern f64 lbl_80300238;
    extern f64 lbl_80300240;
    extern f64 lbl_80300248;
    union {
        f64 d;
        u32 w[2];
    } u;
    u8* p;
    s32 r;
    u32 v;
    if (fn_80058D70(param_1) == 0) {
        return 0;
    }
    p = lbl_8026D4BC + param_1 * 0xc;
    v = *(u32*)(p + 4);
    u.w[0] = 0x43300000;
    u.w[1] = v ^ 0x80000000;
    r = lbl_8027D340[p[0]];
    r += (s32)((lbl_80300238 * (u.d - lbl_80300248)) / lbl_80300240);
    if (v == 1000000) {
        r = 1000000;
    }
    return r;
}

extern "C" s32 fn_80058930(s32 idx) {
    extern f64 lbl_80300238;
    extern f64 lbl_80300240;
    extern f64 lbl_80300248;
    union {
        f64 d;
        u32 w[2];
    } u;
    u32 v;
    s32 r;
    if (fn_80058D70(idx) == 0) {
        return 0;
    }
    v = *(u32*)(lbl_8026D4BC + idx * 0xc + 4);
    u.w[0] = 0x43300000;
    u.w[1] = v ^ 0x80000000;
    r = (s32)((lbl_80300238 * (lbl_80300248 - u.d)) / lbl_80300240);
    if (v == 1000000) {
        r = 1000000;
    }
    return r;
}

extern "C" void fn_800589CC(s32 param_1) {
    fn_8005C424();
    if (param_1 >= 1 && param_1 <= 0xffff) {
        if ((u32)fn_80059190(param_1) != 0) {
            fn_800595FC();
        }
    }
    fn_8005C460();
}

extern "C" void fn_80058A28(s32 param_1) {
    fn_8005C424();
    fn_8005B454(1, param_1, 0);
    if (fn_80058DB8(param_1) != 0) {
        fn_8005B454(1, param_1, 1);
    }
    fn_8005C460();
}

extern "C" s32 fn_80058A88(s32 param_1) {
    s32 result;
    fn_8005C424();
    result = fn_8005B82C(1, param_1, 0) != 0;
    if (result != 0) {
        if (fn_80058DB8(param_1) != 0) {
            result = fn_8005B82C(1, param_1, 1) != 0;
        }
    }
    fn_8005C460();
    return result;
}

extern "C" BOOL fn_80058B18(s32 param_1) {
    u32 result;
    fn_8005C424();
    result = fn_8005B97C(1, param_1, 0);
    fn_8005C460();
    return !result;
}

extern "C" void fn_80058B64(s32 param_1) {
    fn_8005C424();
    fn_8005B6CC(1, param_1, 0);
    if (fn_80058DB8(param_1) != 0) {
        fn_8005B6CC(1, param_1, 1);
    }
    fn_8005C460();
}

extern "C" void fn_80058BC4(void) {
    fn_8005C424();
    fn_8005B6CC(1, -1, 0);
    fn_8005B6CC(1, -1, 1);
    fn_8005C460();
}

extern "C" s32 fn_80058C08(s32 idx) {
    u8* p = lbl_8026D4BC + idx * 0xc;
    if (fn_80058D70(idx) != 0) {
        return (p[1] << 3) + 0x4000;
    }
    return 0;
}

extern "C" void fn_80058C5C(void) {
    s32 i = 0;
    do {
        fn_80059290(&lbl_802C05F0[i * 0x18]);
        lbl_802C05F0[i * 0x18 + 0x16] = i;
        i++;
    } while (i < 0x10);
}

extern "C" void fn_80058CB0(void) {
    s32 i = 0;
    do {
        fn_800592CC(&lbl_802C05F0[i * 0x18]);
        i++;
    } while (i < 0x10);
}

extern "C" void fn_80058D00(void) {
    void fn_800595FC(void* p);
    s32 i = 0;
    do {
        fn_800595FC(&lbl_802C05F0[i * 0x18]);
        i++;
    } while (i < 0x10);
}

extern "C" void fn_80058D50(void) {
    fn_800595FC();
}

extern "C" s32 fn_80058D70(s32 idx) {
    u8* base = lbl_8026D4BC;
    s32 off = idx * 0xc;
    u8 t;
    if (idx <= 0 || idx > 0x152a) {
        return 0;
    }
    t = base[off];
    if (t == 0 || t >= 4) {
        return 0;
    }
    return 1;
}

extern "C" s32 fn_80058DB8(s32 param_1) {
    u8* p;
    s32 valid;
    s32 t;
    s32 r;
    p = lbl_8026D4BC + param_1 * 0xc;
    if (param_1 <= 0 || param_1 > 0x152a) {
        valid = 0;
    } else if (p[0] == 0 || p[0] >= 4) {
        valid = 0;
    } else {
        valid = 1;
    }
    if (valid == 0) {
        return 0;
    }
    t = fn_801E6840(*(s32*)(p + 8));
    t += *(s32*)(p + 8);
    t -= 6;
    r = fn_801E6510(t, &lbl_802FC724, 3);
    return (u32)r == 0 ? 1 : 0;
}

extern "C" void fn_800590D0(s32 param_1, s32* param_2, s32* param_3) {
    s32 local_14;
    s32 local_18;
    fn_80058E5C(param_1, &local_14, &local_18);
    if (*param_2 == -1) {
        *param_2 = local_14;
    }
    if (*param_2 < 0) {
        *param_2 = 0;
    }
    if (*param_2 > 0x7f) {
        *param_2 = 0x7f;
    }
    if (*param_3 == -1) {
        *param_3 = local_18;
    }
    if (*param_3 < 0) {
        *param_3 = 0;
    }
    if (*param_3 > 0x7f) {
        *param_3 = 0x7f;
    }
    *param_3 = 0;
}

extern "C" s32 fn_80059190(s32 idx)
{
    u8* p = lbl_802C05F0;
    u8* ret = NULL;
    s32 i;

    if (idx >= 0 && idx <= 0xffff) {
        for (i = 0; i < 16; i++) {
            if (*(u16*)(p + 0x8) == idx) {
                ret = p;
                break;
            }
            p += 0x18;
        }
    }
    return (s32)ret;
}

extern "C" float lbl_80300230;
extern "C" void fn_80059290(void* p) {
    unsigned char* q = (unsigned char*)p;
    if (q == 0) {
        return;
    }
    *(s32*)(q + 0x0) = 0;
    *(s32*)(q + 0x4) = 0;
    *(s16*)(q + 0x8) = 0;
    q[0x12] = 0;
    q[0x13] = 0;
    *(s16*)(q + 0xa) = 0;
    *(float*)(q + 0xc) = 0.0f;
    q[0x14] = 0x40;
    q[0x15] = 0;
}

extern "C" void fn_800592CC(void* p) {
    if (p != nullptr && *((u8*)p + 0x12) != 0) {
        if (*((u8*)p + 0x12) == 1) {
            fn_80059338(p);
        }
        if (*((u8*)p + 0x12) == 2) {
            fn_80059768(p);
        }
        if (*((u8*)p + 0x12) == 2) {
            fn_80059B68(p);
        }
    }
}

extern "C" s32 fn_80059FE8(s32 mode, void* p) {
    s32 result;
    double v = fn_80059DA0(p);
    if (v > lbl_803002B0) {
        v = lbl_803002B0;
    }
    switch (mode) {
    default:
        result = 0;
        break;
    case 1:
        result = (s32)v;
        break;
    case 2:
        result = (s32)v / 2;
        break;
    }
    return result;
}

extern "C" void fn_8005A480(void) {}

extern "C" void fn_80059338(void*);
extern "C" void fn_80059768(void*);
extern "C" void fn_80059B68(void*);
extern "C" double fn_80059DA0(void*);
extern const double lbl_803002B0;
extern u8 lbl_802C0770[];
extern "C" void fn_8005ABF0(void*);
extern "C" void fn_8005A484(void) {
    s32 i = 0;
    do {
        fn_8005ABF0(&lbl_802C0770[i * 0x2c]);
        i++;
    } while (i < 0x10);
}

extern "C" void* fn_8005AE08(void*);
extern "C" void fn_8005AAC0(void*, f32, int, int, int);
extern "C" void fn_8005A688(void* a, f32 f, int b, int c, int d) {
    void* p = fn_8005AE08(a);
    if (p != 0) {
        fn_8005AAC0(p, f, b, c, d);
    }
}

extern "C" void fn_8005A6F4(void* a) {
    void* p = fn_8005AE08(a);
    if (p != 0) {
        fn_8005ABF0(p);
    }
}

extern "C" BOOL fn_8005A720(void* a) {
    return fn_8005AE08(a) != 0;
}

extern "C" void fn_8005A74C(u8* p) {
    u8 n;
    f32 f;
    if (fn_8005A74C_isBadPtr(p)) {
        return;
    }
    n = lbl_802FF0F8;
    lbl_802FF0F8 = n + 1;
    if (n == 0) {
        lbl_802FF0FC = OSDisableInterrupts();
    }
    *(u32*)(p + 0x14) = 0;
    f = lbl_80300230;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x1c) = 0;
    *(f32*)(p + 0x20) = f;
    p[0x24] = 0;
    p[0x25] = 0x40;
    p[0x26] = 0;
    *(u32*)(p + 0xc) = 0;
    p[0x27] = 0;
    p[0x28] = 0;
    *(u32*)(p + 0x10) = 0;
    n = lbl_802FF0F8;
    if (n != 0) {
        n--;
        lbl_802FF0F8 = n;
        if (n == 0) {
            OSRestoreInterrupts(lbl_802FF0FC);
        }
    }
}

extern char lbl_8027D36C[];
extern char lbl_8027D510[];
extern "C" void fn_8005C330(const char*, ...);
extern "C" BOOL fn_8005AD7C(u32 p) {
    BOOL bad;
    if ((p & 0xF0000000) != 0x80000000) {
        fn_8005C330((const char*)1, lbl_8027D36C, lbl_8027D510, p);
        bad = TRUE;
    } else {
        bad = FALSE;
    }
    if (bad) {
        return FALSE;
    }
    return *(s32*)(p + 0x14) >= 1;
}

void* fn_8005AE08(s32 param_1)
{
    u8* p;
    s32 i;

    if (param_1 <= 0) {
        return NULL;
    }
    p = lbl_802C0770;
    for (i = 0; i < 2; i++) {
        if (*(s32*)(p + 0x14) == param_1) {
            return p;
        }
        if (*(s32*)(p + 0x40) == param_1) {
            return p + 0x2c;
        }
        if (*(s32*)(p + 0x6c) == param_1) {
            return p + 0x58;
        }
        if (*(s32*)(p + 0x98) == param_1) {
            return p + 0x84;
        }
        if (*(s32*)(p + 0xc4) == param_1) {
            return p + 0xb0;
        }
        if (*(s32*)(p + 0xf0) == param_1) {
            return p + 0xdc;
        }
        if (*(s32*)(p + 0x11c) == param_1) {
            return p + 0x108;
        }
        if (*(s32*)(p + 0x148) == param_1) {
            return p + 0x134;
        }
        p += 0x160;
    }
    return NULL;
}

extern char lbl_8027D550[];
extern "C" void fn_8005AEFC(void*);
extern "C" u32 fn_8005B2C8(void* a, u32 b, void* c, u32 d, void* e) {
    if (b + d < 0x4d0) {
        return 0;
    }
    if (b + d > 0x9a0) {
        fn_8005C330((const char*)1, lbl_8027D550);
    }
    fn_8005AEFC(e);
    return 0x4d0;
}

extern char lbl_8027D56C[];
extern "C" double fn_801E9FC0(double a, double b);
extern const double lbl_803002B8;
extern const double lbl_803002C0;
extern "C" u32 fn_8005B32C(u8* p) {
    BOOL bad;
    u8* q = *(u8**)(p + 0x18);
    u32 v;
    if (((u32)q & 0xF0000000) != 0x80000000) {
        fn_8005C330((const char*)1, lbl_8027D36C, lbl_8027D56C, q);
        bad = TRUE;
    } else {
        bad = FALSE;
    }
    if (bad) {
        return 24000;
    }
    v = (u32)(fn_801E9FC0(lbl_803002B8, *(f32*)(p + 0x20) / lbl_803002C0) * (double)*(u32*)(q + 8));
    if (v > 48000) {
        v = 48000;
    }
    if (v < 12000) {
        v = 12000;
    }
    return v;
}

extern u8 lbl_802C0A30[];
extern "C" void fn_8005BB28(u8* p);
extern "C" void fn_8005B400(void) {
    s32 i = 0;
    do {
        fn_8005BB28(&lbl_802C0A30[i * 0x5c]);
        i++;
    } while (i < 0x40);
}

extern "C" void fn_8005B450(void) {}

extern "C" u8 fn_8005BAB4(s32 idx) {
    u8* base = lbl_8026D4BC;
    s32 off = idx * 0xc;
    int t;
    if (!fn_80058D70(idx)) {
        return 1;
    }
    t = base[off];
    if (t >= 4) {
        return 1;
    }
    return lbl_802FC71C[t];
}

extern "C" void fn_8005BB28(u8* p) {
    u8 n = lbl_802FF0F8;
    lbl_802FF0F8 = n + 1;
    if (n == 0) {
        lbl_802FF0FC = OSDisableInterrupts();
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[18] = 0;
    *(u32*)(p + 0x14) = 0;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x1c) = 0;
    n = lbl_802FF0F8;
    if (n != 0) {
        n--;
        lbl_802FF0F8 = n;
        if (n == 0) {
            OSRestoreInterrupts(lbl_802FF0FC);
        }
    }
}

extern "C" s32 fn_801C7D34(void* p);
extern "C" void fn_8005BE20(void);
extern char lbl_8027D65C[];
extern char lbl_8027D69C[];
extern char lbl_8027D6C4[];
extern "C" void fn_8005BD38(s32 p1, u8* p2) {
    u8* p = lbl_802C0A30;
    if (fn_801C7D34(p2) == 0) {
        fn_8005C330((const char*)1, lbl_8027D65C, p2);
    }
    if (p1 <= 0) {
        fn_8005C330((const char*)1, lbl_8027D69C, p1);
    } else {
        u8* q = p;
        for (s32 i = 0; i < 0x40; i++) {
            if (q + 0x20 == p2) {
                if (q[0] == 2) {
                    fn_8005BE20();
                } else {
                    q[0] = 3;
                }
                return;
            }
            q += 0x5c;
        }
        fn_8005C330((const char*)0, lbl_8027D6C4);
    }
}

extern "C" void* fn_8005BF40(s32 param_1, s32 param_2, s32 param_3) {
    void* p = fn_801BBCC8(lbl_802FE960, param_1);
    if (p == 0) {
        fn_8005C330((const char*)1, lbl_8027D714);
    } else {
        fn_8005C0BC(p, param_1, param_2, param_3);
    }
    return p;
}

extern "C" void* fn_8005BFC8(s32 param_1) {
    void* p = fn_801BBCC8(lbl_802FE960, param_1);
    if (p == 0) {
        fn_8005C330((const char*)1, lbl_8027D714);
    } else {
        fn_8005C0BC(p, param_1, 1, 0);
    }
    return p;
}

extern "C" void fn_8005C038(s32 param_1) {
    fn_801BBDC4(lbl_802FE960, param_1);
    fn_8005C170(param_1);
}

extern "C" void fn_8005C074(void) {
    s32 i = 0;
    lbl_802FF104 = 0;
    lbl_802FF108 = 0;
    do {
        fn_8005C21C(i);
        i++;
    } while (i < 0x100);
}

extern "C" void fn_8005C0BC(void* param_1, s32 param_2, s32 param_3, s32 param_4) {
    s32 idx = fn_8005C248(0);
    if (idx >= 0) {
        u8* p = lbl_802C2130 + idx * 12;
        *(void**)p = param_1;
        *(s32*)(p + 4) = param_2;
        p[0xa] = param_3;
        *(s16*)(p + 8) = param_4;
        lbl_802FF104 = lbl_802FF104 + 1;
        lbl_802FF108 = lbl_802FF108 + param_2;
    } else {
        fn_8005C330(0, lbl_8027D730, param_3, param_4);
    }
}

extern char lbl_8027D758[];
extern "C" void fn_8005C170(s32 param_1) {
    s32 idx = fn_8005C248(param_1);
    if (idx >= 0) {
        lbl_802FF104 = lbl_802FF104 - 1;
        lbl_802FF108 = lbl_802FF108 - *(s32*)((u8*)lbl_802C2130 + 4 + idx * 12);
        fn_8005C21C(idx);
    } else {
        fn_8005C330(0, lbl_8027D758, param_1);
    }
}

extern "C" s32 fn_8005C1F0(s32 idx) {
    if (idx < 0x2e) {
        return 3;
    }
    return idx >= 0x128 ? 5 : 4;
}

extern "C" s32 fn_8005C248(s32 idx) {
    s32 i;
    s32 ret = -1;
    for (i = 0; i < 0x100; i++) {
        if ((u32)idx == *(u32*)(lbl_802C2130 + i * 12)) {
            ret = i;
            break;
        }
    }
    return ret;
}

extern "C" void fn_8005C330(const char*, ...) {
}

extern "C" void fn_8005C380(void) {
    lbl_802FF114 = 0;
    lbl_802FF110 = 0;
    lbl_802FF10C = 0;
    fn_801BFEBC(lbl_802C2D30, lbl_8027D780);
    fn_801BFFF0(lbl_802C2D30);
}

extern "C" void fn_8005C3CC(void) {
    s32 t = *(s32*)(lbl_802C2D30 + 0x8);
    lbl_802FF110 = t;
    lbl_802FF114 = *(s32*)(lbl_802C2D30 + 0xc);
    fn_801BFFF0(lbl_802C2D30);
    if (lbl_802FF10C != 0) {
        fn_8005C330(0, lbl_8027D790);
    }
}

extern "C" void fn_8005C424(void) {
    lbl_802FF10C = lbl_802FF10C + 1;
    if (lbl_802FF10C == 1) {
        fn_801BFEE8(lbl_802C2D30);
    }
}

extern "C" void fn_8005C460(void) {
    lbl_802FF10C = lbl_802FF10C - 1;
    if (lbl_802FF10C == 0) {
        fn_801BFF24(lbl_802C2D30);
    }
}

extern "C" void* lbl_802FF118;
extern "C" void* fn_8005C498(void)
{
	return lbl_802FF118;
}

extern "C" void* lbl_802FF11C;
extern "C" void* fn_8005C4A0(void)
{
	return lbl_802FF11C;
}

extern "C" void* memset(void*, int, unsigned long);
extern "C" void fn_8005C4A8(u8 flag, s32** bufs)
{
    if (flag == 0) {
        s32* b;
        s32* a;
        int i;
        s32 first;
        BOOL same;
        s32 max;
        max = 0;
        b = bufs[1];
        a = bufs[0];
        same = TRUE;
        first = (a[0] + b[0]) / 2;
        for (i = 0; i < 160; i++) {
            s32 v = (a[i] + b[i]) / 2;
            s32 av = v < 0 ? -v : v;
            if (av > max) {
                max = av;
            }
            if (v != first) {
                same = FALSE;
            }
        }
        if (same) {
            max = 0;
        }
        memset(bufs[0], 0, 0x280);
        memset(bufs[1], 0, 0x280);
        memset(bufs[2], 0, 0x280);
        *(s32*)&lbl_802FF118 = max;
    }
}

extern "C" void fn_8005C710(void) {
    fn_801473F8(0, (void*)fn_8005C4A8, lbl_802C2D60, 0xff, 0, (void*)fn_8005C5DC, lbl_802C2D60, 0xff, 0);
}

extern "C" s32 fn_8005C764(s32 idx) {
    s32 i;
    s32 count;
    s32 flag = 0;
    u8* found;
    u8* p;

    if ((idx >= 0x107 && idx <= 0x10c) || idx == 0xcb || idx == 0xcc) {
        flag = 1;
    }
    if (flag == 0) {
        return idx;
    }
    count = 0;
    found = NULL;
    p = lbl_802C05F0;
    for (i = 0; i < 4; i++) {
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        count += 3;
    }
    if (found == NULL) {
        return count;
    }
    found[0x13] = 2;
    *(u16*)(found + 0x10) = *(u16*)(found + 0xa) >> 2;
    return count;
}

extern "C" s32 fn_8005C854(s32 param) {
    u8* found;
    u8* p;
    s32 count;
    s32 i;
    s32 inRange = 0;

    if (param >= 0x107) {
        if (param <= 0x10c) {
            inRange = 1;
        }
    }
    if (param == 0xcb || param == 0xcc) {
        inRange = 1;
    }
    if (inRange == 0) {
        return param;
    }
    found = 0;
    p = lbl_802C05F0;
    count = 0;
    for (i = 0; i < 4; i++) {
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        if (p[0x12] != 0 && *(s32*)p == 0x24) {
            found = p;
        }
        p += 0x18;
        count += 3;
    }
    if (found == 0) {
        return count;
    }
    found[0x13] = 1;
    *(u16*)(found + 0x10) = 0x80;
    return 1;
}

extern int lbl_802FF128;
extern int lbl_802FF12C;
extern int lbl_802FF130;
extern "C" void fn_8005CAC8(void) {
    lbl_802FF128 = 0;
}

extern "C" void fn_8005CAD4(int param_1) {
    if (param_1 != 0x13) {
        return;
    }
    lbl_802FF128 = 0;
}

extern "C" void fn_8005CAE8(int param_1, int param_2) {
    if (param_1 != 0x13) {
        return;
    }
    lbl_802FF128 += param_2;
}

extern "C" void fn_8005CB00(void) {
    lbl_802FF12C = 0;
    lbl_802FF130 = 0x20;
}

extern "C" void fn_8005CB14(void) {
    if (lbl_802FF130 >= 0x20) {
        return;
    }
    lbl_802FF130++;
}

extern "C" void fn_8005CB2C(int param_1) {
    s32 prev = lbl_802FF12C;
    if (lbl_802FF12C == 0 && param_1 == 0xd4) {
        lbl_802FF12C = 1;
    } else if (lbl_802FF12C != 0 && param_1 == 0xd3) {
        lbl_802FF12C = 0;
    }
    if (lbl_802FF12C != prev) {
        lbl_802FF130 = 1;
    }
}

extern "C" int fn_8005CB7C(int param_1) {
    if (param_1 == 0xd4 || param_1 == 0xd3) {
        return 0;
    }
    return 1;
}

extern "C" s32 fn_8005CB9C(s32 param_1, s32 param_2) {
    s32 bVar1;
    s32 flag;
    s32 lvl;
    s32 v;
    if (param_1 == 0xd4 || param_1 == 0xd3) {
        bVar1 = 0;
    } else {
        bVar1 = 1;
    }
    if (!bVar1) {
        return param_2;
    }
    if (param_2 <= 0) {
        return param_2;
    }
    flag = lbl_802FF12C;
    lvl = lbl_802FF130;
    if (flag != 0) {
        v = param_2 * (0x21 - lvl) / 32;
        if (v != 0) {
            return v;
        }
    }
    return 1;
}

extern "C" void fn_8005CC04(void* self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    *(f32*)((u8*)self + 0x0) = a;
    *(f32*)((u8*)self + 0x4) = b;
    *(f32*)((u8*)self + 0x8) = c;
    *(f32*)((u8*)self + 0xc) = d;
    *(f32*)((u8*)self + 0x10) = e;
    *(f32*)((u8*)self + 0x14) = f;
}

extern "C" void fn_8005CC20(void* self, f32 a, f32 b, f32 c, f32 d) {
    *(f32*)((u8*)self + 0x18) = a;
    *(f32*)((u8*)self + 0x1c) = b;
    *(f32*)((u8*)self + 0x20) = c;
    *(f32*)((u8*)self + 0x24) = d;
}

extern "C" void fn_801D9F18(s32 a, s32 b);
extern "C" void fn_801DCCA0(s32 a);
extern "C" void fn_801DCCDC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern "C" void fn_801DCBB0(s32 a, void* b);
extern "C" void fn_801DAF24(s32 a);
extern "C" void fn_801DEA4C(s32 a);
extern "C" void fn_801DE8B0(s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801DE310(s32 a, s32 b);
extern "C" void fn_801DEDBC(s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801DBA5C(s32 a, s32 b);
extern "C" void fn_801DB8C4(s32 a, s32 b, s32 c);
extern "C" void fn_8005CDE8(u8* param_1) {
    u32 local[2];
    s16 a;
    s16 b;
    volatile s16* hw;
    fn_801DA364();
    fn_801D9F18(9, 1);
    fn_801DCCA0(1);
    fn_801DCCDC(4, 0, 0, 0, 0, 0, 2);
    local[0] = *(u32*)(param_1 + 8);
    fn_801DCBB0(4, local);
    fn_801DAF24(0);
    fn_801DEA4C(1);
    fn_801DE8B0(0, 0xff, 0xff, 4);
    fn_801DE310(0, 4);
    fn_801DEDBC(1, 4, 5, 0xf);
    fn_801DBA5C(param_1[0xc], 0);
    fn_801DB8C4(0xb8, 0, 1);
    a = *(s16*)(param_1 + 6);
    hw = (volatile s16*)0xCC008000;
    b = *(s16*)(param_1 + 4);
    *hw = b;
    *hw = a;
    *hw = 0;
}

extern "C" void* fn_8005E7D8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EC78;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8005E820(void* self) {
    ((void (*)(void*, u8))(*(void***)((u8*)self + 8))[0x24 / 4])((u8*)self + 8, *((u8*)self + 0x174));
    s16 x = *(s16*)((u8*)self + 0x170);
    s16 y = *(s16*)((u8*)self + 0x172);
    ((void (*)(void*, s32, s32, s32, f32, f32))(*(void***)((u8*)self + 8))[0xe4 / 4])((u8*)self + 8, 0, 0, 0, x, y);
}

extern "C" void fn_8005E8B8(void* self, s32 a, s32 b, s32 c) {
    ((VObj_8005E8B8*)self)->v56(0, a, b, c);
}

extern "C" void fn_8005E8F8(void* self, u8 idx, f32 p1, f32 p2, s32 a, s32 b, s32 c) {
    if (idx < *((u8*)self + 0x110)) {
        void* slot = *(void**)((u8*)self + (idx << 2) + 0x100);
        if (slot != nullptr) {
            u8* q = *(u8**)((u8*)slot + 0x20);
            s32 y = *(u16*)(q + 4);
            s32 x = *(u16*)(q + 2);
            ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))(*(void***)self)[0xec / 4])(self, a, b, c, p1, p2, (f32)x, (f32)y);
        }
    }
}

extern "C" void fn_8005E990(void* self, s16 a, s16 b) {
    *(s16*)((u8*)self + 0x170) = a;
    *(s16*)((u8*)self + 0x172) = b;
}

extern "C" void* fn_8005F864(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8005F8A0(void) {
}

extern "C" void fn_801DF0BC(void* p, s32 n);
extern "C" void fn_80158E18(void* p);
extern "C" void fn_80159138(s32 a, void* p);
extern "C" void fn_801DF628(s32 v);
extern "C" void fn_8005F258(void* a, void* b);
extern "C" void fn_80159528(s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8005F8A4(u8* p, void* arg) {
    u8* base = lbl_8027D7C0;
    u8* q;
    s32 i;
    if (*(s16*)(p + 6) == 0) {
        return 0;
    }
    fn_801DF0BC(base + 0xe00, 0x60);
    fn_80158E18(base + 0xe64);
    fn_80159138(0, base + 0xe74);
    fn_801DF628(0);
    q = *(u8**)(p + 8);
    for (i = 0; i < *(s16*)(p + 6); i++) {
        fn_8005F258(q, arg);
        q += 8;
    }
    fn_80159528(0, 0, 0, 0, 1, 0, 1);
    return 1;
}

extern "C" void fn_8005FCEC(void* self) {
    u8* base = lbl_8027D7C0;
    u32 buf[2];
    fn_801DA39C(0, 9, 1, 4, 0);
    fn_801DA364();
    fn_801D9F18(9, 2);
    fn_801DAC08(9, base + 0x111c, 0xc);
    fn_801DF2A4((u8*)self + 0x10, 0);
    fn_801DF344(0);
    buf[0] = lbl_802FBA78;
    fn_801DE4F4(1, buf);
    fn_801DF0BC(base + 0x1240, 0x60);
    fn_801DF0BC(base + 0x11e0, 0x40);
    fn_801DEE10(1);
    fn_801DEE3C(0);
}

extern "C" void fn_801E0DB8(void* self, void* a, void* b, u32 size, u32 count);
extern "C" void fn_8005FEB4(u8* self);
extern "C" void fn_8005FE84(void** p);
extern "C" void fn_80011E54(void);
extern "C" u8* fn_8005FDAC(u8* p) {
    fn_801E0DB8(p + 0x2c0, (void*)fn_8005FEB4, 0, 0x110, 8);
    *(u8*)(p + 0x2b8) = 0;
    fn_801E0DB8(p + 0xb88, (void*)fn_8005FE84, (void*)fn_80011E54, 0x14, 2);
    *(u8*)(p + 0xbb0) = 0;
    *(u8**)(p + 0x70) = p + 0x6c;
    *(u8**)(p + 0xb8) = p + 0xb4;
    *(u8**)(p + 0x100) = p + 0xfc;
    *(u8**)(p + 0x208) = p + 0x204;
    *(u8**)(p + 0x290) = p + 0x28c;
    *(u32*)(p + 0x0) = 0;
    *(u32*)(p + 0x4) = 0;
    *(u32*)(p + 0x8) = 0;
    *(u32*)(p + 0xc) = 0;
    *(u32*)(p + 0x10) = 0;
    *(u32*)(p + 0x14) = 0;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x1c) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x24) = 0;
    *(u32*)(p + 0x28) = 0;
    *(u32*)(p + 0x2ac) = 0;
    *(u32*)(p + 0x2b0) = 0;
    *(u32*)(p + 0xdb4) = 0;
    return p;
}

extern "C" void fn_8005FE84(void** p) {
    p[0] = lbl_80299A8C;
    p[1] = nullptr;
    p[2] = nullptr;
    p[3] = nullptr;
    p[0] = lbl_802044AC;
    p[4] = nullptr;
}

extern "C" void fn_8005FEB4(u8* self) {
    *self = 0;
}

extern "C" void fn_801A73A4(u32);
extern "C" void fn_80060EF0(void* param_1);
extern u8 lbl_802EE470[];
extern "C" void fn_8006069C(u32* p) {
    fn_801A73A4(p[0]);
    fn_801A73A4(p[1]);
    fn_801A73A4(p[2]);
    fn_801A73A4(p[3]);
    fn_801A73A4(p[4]);
    fn_801A73A4(p[5]);
    fn_801A73A4(p[6]);
    fn_801A73A4(p[7]);
    fn_801A73A4(p[8]);
    fn_801A73A4(p[9]);
    fn_801A73A4(p[10]);
    *(u32*)(lbl_802EE470 + 0x48) = p[4];
    *(u32*)(lbl_802EE470 + 0x4c) = p[5];
    p[0x1b] = (u32)(p + 0xb);
    p[0x2d] = (u32)(p + 0x1d);
    p[0x3f] = (u32)(p + 0x2f);
    p[0x81] = (u32)(p + 0x41);
    p[0xa3] = (u32)(p + 0x83);
    *(s16*)(*(u8**)(lbl_802B7CA0 + 0x16d0) + 6) = 0;
    *(s16*)(*(u8**)(lbl_802B7CA0 + 0x16d4) + 6) = 0;
    *(s16*)(*(u8**)(lbl_802B7CA0 + 0x16d8) + 6) = 0;
    fn_80060EF0(p + 0xae);
    p[0x2e6] = 0;
    p[0x2eb] = 0;
}

extern "C" BOOL fn_80060794(void* param_1, u32* param_2, u32* param_3, u32 param_4) {
    if (*param_2 >= *param_3) {
        return 0;
    }
    *(u32*)*param_2 = param_4;
    *param_2 += 4;
    return 1;
}

extern "C" void fn_800607C4(void* self, VObj_8005E8B8** start, VObj_8005E8B8** end) {
    for (; start < end; start++) {
        (*start)->v1();
    }
}

extern "C" void fn_8006081C(void) {
}

extern "C" void fn_800609E8(void) {
    if (lbl_802FF140 == 0) {
        return;
    }
    f32 v = lbl_802FF144 + lbl_802FF148;
    lbl_802FF144 = v;
    if (v < lbl_803002D0) {
        lbl_802FF144 = lbl_803002D0;
    } else if (v > lbl_803002F4) {
        lbl_802FF144 = lbl_803002F4;
        lbl_802FF140 = 0;
    }
    u8* obj = lbl_802C2D7C;
    f32 a = lbl_80300338 * lbl_802FF144;
    *(f32*)(obj + 0x34) = a;
    *(f32*)(obj + 0x38) = lbl_80300340 * a;
    u8* base = lbl_802B7CA0;
    if (*(u8**)(base + 0x1628) >= *(u8**)(base + 0x162c)) {
        return;
    }
    **(u8***)(base + 0x1628) = obj;
    *(u8**)(base + 0x1628) = *(u8**)(base + 0x1628) + 4;
}

extern "C" void fn_80060A80(void* self) {
    s32 v = *(s32*)((u8*)lbl_802FF328 + 4);
    fn_801DC264(0, v + 0x1a, 0, v + 0x32);
    fn_801DBBFC(0, 0, 0x168, 0x120);
    fn_801DBCAC(0x168, 0x120, 6, 0);
    fn_801DC5E8(*(void**)((u8*)self + 0xdb4), lbl_802BF75C[0xf]);
    fn_801DB4F8();
    v = *(s32*)((u8*)lbl_802FF328 + 4);
    fn_801DC264(1, v + 0x1a, 1, v + 0x32);
}

extern "C" u32 fn_801DCD94(u32, u32, u32, u32, u32);
extern "C" void* fn_8015AA60(u32, u32);
extern "C" void fn_801DCFB8(void*, void*, u32, u32, u32, u32, u32, u32);
extern "C" void fn_801DD24C(void*, u32, u32, f32, f32, f32, u32, u32, u32);
extern "C" void fn_80060E18(u8* p) {
    u8* q;
    u8* r;
    u32 size;
    s32 i;
    size = fn_801DCD94(0x1c0, 0x1c0, 5, 0, 0);
    q = p;
    r = p;
    for (i = 0; i < 2; i++) {
        *(void**)(q + 0x8c8) = fn_8015AA60(size, 0x20);
        fn_801DCFB8(r + 0x888, *(void**)(q + 0x8c8), 0x1c0, 0x1c0, 5, 0, 0, 0);
        fn_801DD24C(r + 0x888, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);
        q += 4;
        r += 0x20;
    }
}

extern "C" void* memset(void* s, int c, unsigned long n);
extern "C" void fn_80060EF0(void* param_1) {
    u8* p = (u8*)param_1 + 8;
    s32 i;
    s32 j;
    u32* w;
    for (i = 0; i < 8; i++) {
        if (p[0] == 1) {
            p[0] = 2;
        } else {
            p[0] = 0;
            ((s8*)p)[1] = -1;
        }
        p[3] = 0;
        w = (u32*)p;
        for (j = 42; j < 68; j++) {
            w[j] = 0;
        }
        p += 0x110;
    }
}

extern const f32 lbl_8030036C;
extern "C" f32* fn_8003C318(f32* out);
extern "C" u8 fn_80060B20(u8* a, u8* b, u8* c, f32* d, s32 e, f32 f, f32 g, f32 h);
extern "C" BOOL fn_800612EC(u8* self, f32 a, f32 b, s8 kind, s32 c, u8* d) {
    f32 tmp[3];
    f32 v[3];
    f32 scale;

    fn_8003C318(tmp);
    v[0] = tmp[0];
    v[1] = tmp[1];
    v[2] = tmp[2];
    if (d != NULL) {
        v[0] = *(f32*)(d + 0x74);
        v[1] = *(f32*)(d + 0x78);
        v[2] = *(f32*)(d + 0x7c);
    }
    if (kind == 0) {
        scale = lbl_803002D0;
    } else {
        scale = lbl_8030036C * b;
    }
    self[0xa] = fn_80060B20(self + 0x10, self + 0x40, self + 0x80, v, c, a, b, scale);
    self[8] = 1;
    self[9] = kind;
    return 1;
}

extern "C" s32 fn_800613EC(void* self, s32 val) {
    u8* base = (u8*)self + 8;
    if (val == 0) {
        return 0;
    }
    if (base[3] >= 0x1a) {
        fn_8011FD18(fn_8011FD10(), lbl_8027EA6C, 0x111b, "%s", "mModelNum < MODE");
        fn_80007AB8(lbl_8027EA6C, 0x111b, "Halt");
    }
    u32 idx = base[3];
    base[3] = idx + 1;
    u8* p = base + ((idx & 0xff) << 2);
    *(s32*)(p + 0xa8) = val;
    return 1;
}

extern void* lbl_8027EB8C[];
extern void* lbl_80299A8C[];
extern "C" void* fn_80061490(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EB8C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EBC4[];
extern "C" void* fn_800614EC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EBC4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EBFC[];
extern "C" void* fn_80061548(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EBFC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EC40[];
extern "C" void* fn_800615A4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EC40;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80061600(void* param_1, s16 param_2) {
    s16 n = param_2;
    void** p = (void**)param_1;
    if (p != 0) {
        p[0] = lbl_8027EC68;
        fn_8017E1A4((u8*)p + 8, -1);
        if (p != 0) {
            p[0] = lbl_8027EC78;
        }
        if (n > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern void* lbl_8027ECA4[];
extern "C" void* fn_80061678(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECA4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECCC[];
extern "C" void* fn_800616D4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECF4[];
extern "C" void* fn_80061730(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECF4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED20[];
extern "C" void* fn_8006178C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED20;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED48[];
extern "C" void* fn_800617E8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED48;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED74[];
extern "C" void* fn_80061844(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED74;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EDA0[];
extern "C" void* fn_800618A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EDA0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
