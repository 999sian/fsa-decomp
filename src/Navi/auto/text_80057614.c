#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80057614-0x800618fc (176 functions). split_file divides it into the game's real files.

extern u8 lbl_802C05F0[];
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
extern "C" void fn_80058E5C(s32 idx, s32* a, s32* b);
extern void* lbl_8027EC78[];
extern void* lbl_80299A8C[];
extern void* lbl_802044AC[];
extern u8 lbl_8027D7C0[];
extern s32 lbl_8027D340[];
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

extern "C" void fn_80057868(void) {
}

extern "C" void fn_800579E0(void) {
}

extern "C" void fn_800579F8(void) {
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

extern "C" void fn_8005B450(void) {}

extern "C" void fn_8005C330(const char*, ...) {
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
        i = 0;
        same = TRUE;
        first = (a[0] + b[0]) / 2;
        for (; i < 160; i++) {
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

extern int lbl_802FF128;
extern int lbl_802FF12C;
extern int lbl_802FF130;
extern "C" void fn_8005CAC8(void) {
    lbl_802FF128 = 0;
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
    if (param_1 != 0xd4 && param_1 != 0xd3) {
        return 1;
    }
    return 0;
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

extern "C" void fn_8006081C(void) {
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
