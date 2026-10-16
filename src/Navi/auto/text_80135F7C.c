#include "types.h"
extern "C" f32 fn_80137F4C(void* param_1);
extern "C" f64 fn_80137F58(void* p, f32 x);
extern "C" f64 fn_80137F88(void* p, f32 x);


extern "C" f32 fn_801375FC(void* param_1, u32* param_2);
extern "C" f64 fn_80137610(void* param_1, f64* param_2);
extern "C" f64 fn_80137644(void* param_1, f64* param_2);
extern "C" void fn_801376D0(void* param_1, void* param_2);

struct NaviTracker {
    virtual void fn_0();
    virtual void fn_1();
    virtual void fn_2();
    virtual void fn_3();
    virtual u32 fn_4();
    virtual void fn_5(u32);
    virtual u32 fn_6();
    virtual void fn_7(u32);
    virtual void fn_8();
    virtual void fn_9();
    virtual void fn_10();
    virtual void fn_11();
    virtual void fn_12();
    virtual s32 fn_13(u32*, u32, s32);
    virtual void fn_14();
    virtual s32 fn_15(u32*, u32, s32);
};

struct It_80138B20 { void* p; };
struct Tag_80138B20 {};
struct It2_80138DA8 { void* a; void* b; };
extern "C" void fn_80138E2C(void*, It2_80138DA8, It2_80138DA8, It2_80138DA8, void*, Tag_80138B20);
extern "C" It_80138B20 fn_80138B7C(It_80138B20, It_80138B20, It_80138B20, void*, Tag_80138B20);

struct VObj_801398CC {
    virtual void v0();
    virtual void v1();
    virtual void v2(void*);
};

extern void* lbl_8029320C[];
extern "C" void* fn_80133C0C(void* ptr, s16 param_2);

extern f32 lbl_802FEAB0[];
extern void* lbl_80292BB4[];
extern void* lbl_80292974[];
extern char lbl_802911A0[];
extern char lbl_80292C80[];
extern void* lbl_80292A08[];
extern "C" void fn_8013BC94(void* a, void* b, void* c, void* d, void* e);
extern "C" void fn_8013C544(void* a, void* b);
extern void fn_80167CD8(void*, u32, u32);
extern void* lbl_802985C8[];
extern void* lbl_80298B14[];
extern void* lbl_80292EC4[];
extern void* lbl_80292EB4[];
extern "C" void fn_80167BB0(void* p, u32 x);
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80135f7c-0x8013c97c (185 functions). split_file divides it into the game's real files.

extern void* lbl_80292BB4[];
extern "C" void fn_8015AB1C(void* ptr);

struct fn_80139DB0_Obj {
    u8 pad[8];
    virtual void fn_0(s32);
};
extern void* lbl_8029270C[];
extern void* lbl_80292694[];
extern "C" void* fn_80135F7C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029270C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292788[];
extern "C" void* fn_80135FD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292788;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292800[];
extern "C" void* fn_80136034(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292800;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292878[];
extern "C" void* fn_80136090(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292878;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802928F0[];
extern "C" void* fn_801360EC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802928F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801E10DC(void* p, int a, void* b, int c);
extern "C" f64 fn_801E9FA0(f64 a, f64 b);
extern "C" u32 lbl_80201F60[];
extern f32 lbl_80301828;
extern "C" void fn_80136148(void* self, void* p, f32 x) {
    int v = 0;
    if (x >= 0.5f) {
        v = 1;
    }
    fn_801E10DC(p, 2, &v, 4);
}

extern "C" u32 fn_80136314(u32 i) {
    u32 tmp = 0;
    u32* p = &lbl_80201F60[i];
    if (i >= 4) {
        p = &tmp;
    }
    if (*p == 0) {
        return lbl_80201F60[0];
    }
    return *p;
}

extern "C" void* fn_8013635C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292BB4;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" f64 fn_801363A4(f64 a, f64 b) {
    f64 m = 2.0 * b;
    f64 r = fn_801E9FA0(a, m);
    if (r < 0.0) {
        r += m;
    }
    if (r >= b) {
        r = m - r;
    }
    return r;
}

extern "C" void fn_80136404(f64* p, f64 a, f64 b) {
    p[0] = a;
    p[1] = b;
    p[2] = b - a;
}

extern "C" void fn_80136418(void* param_1) {
    *(void**)param_1 = lbl_802985C8;
    *(void**)((u8*)param_1 + 4) = lbl_80298B14;
    *(u32*)((u8*)param_1 + 8) = 0;
    *(u32*)((u8*)param_1 + 0xc) = 0;
}

extern "C" BOOL fn_8013647C(void);
extern "C" BOOL fn_8013647C(void)
{
    return TRUE;
}

extern "C" void fn_80136484(void* param_1, void* param_2) {
    if (param_2 != nullptr) {
        param_2 = (void*)((u8*)param_2 + 4);
    }
    *(void**)param_1 = param_2;
    *(u32*)((u8*)param_1 + 4) = 0;
    *(u32*)((u8*)param_1 + 8) = 0;
}

extern "C" void fn_801364A4(void* param_1) {
    fn_80167CD8((u8*)param_1 + 4, *(u32*)((u8*)param_1 + 8), *(u32*)((u8*)param_1 + 0xc));
    *(u32*)((u8*)param_1 + 0x18) = 0;
    u64 tmp = 0;
    *(u64*)((u8*)param_1 + 0x20) = tmp;
}

extern "C" void fn_801364F0(void) {
}

extern "C" void fn_801364F4(void* param_1) {
    ((void (*)(void*, void*))*(void**)((u8*)param_1 + 0x18))((u8*)param_1 + 4, (u8*)param_1 + 0x20);
}

extern "C" f64 fn_80136528(void* param_1, u32* param_2) {
    void** begin = *(void***)((u8*)param_1 + 4);
    u32 idx = *param_2;
    s32 count;
    if (begin == nullptr) {
        count = 0;
    } else {
        count = (s32)(*(u32*)((u8*)param_1 + 8) - (u32)begin) / 4;
    }
    if (idx >= count) {
        return 0.0;
    }
    void* elem = begin[idx];
    return ((f64 (*)(void*))(*(void***)elem)[7])(elem);
}

extern "C" void fn_80136700(void* param_1, f64 param_2, f64* param_3) {
    void** volatile end = *(void***)((u8*)param_1 + 8);
    void** volatile cur = *(void***)((u8*)param_1 + 4);
    f64 d = param_2 - *param_3;
    while (cur != end) {
        void* elem = *cur;
        cur++;
        ((void (*)(void*, f64))(*(void***)elem)[7])(elem, d);
    }
}

extern "C" u32 fn_80136A68(void) {
    return 2;
}

extern "C" void fn_80136A70(void* param_1) {
    *(u32*)param_1 = 0;
    *(u32*)((u8*)param_1 + 4) = 0;
    *(u32*)((u8*)param_1 + 8) = 0;
}

extern "C" void fn_80136A94(void) {}

extern "C" u32 fn_80136B14(void) {
    return 3;
}

extern "C" void fn_80136B1C(void* p, unsigned int q) {
    unsigned int a = q;
    unsigned int b = q;
    if (q != 0) {
        b = b + 0x40;
    }
    if (q != 0) {
        a = q + 8;
    }
    *(u32*)p = 0;
    *(u32*)((u8*)p + 4) = a;
    *(u32*)((u8*)p + 8) = b;
}

extern "C" void fn_80136B94(void* p) {
    switch (*(s8*)((u8*)p + 0x20)) {
    case 0:
    default:
        *(f64*)((u8*)p + 0x28) = 0.0;
        *(f64*)((u8*)p + 0x30) = 1.0;
        break;
    case 1:
        *(f64*)((u8*)p + 0x28) = 0.0;
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    case 2:
        *(f64*)((u8*)p + 0x28) = *(f64*)((u8*)p + 0x8);
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    case 3:
        *(f64*)((u8*)p + 0x28) = *(f64*)((u8*)p + 0x10);
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    case 4:
        *(f64*)((u8*)p + 0x28) = 0.5 * (*(f64*)((u8*)p + 0x8) + *(f64*)((u8*)p + 0x10));
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    }
}

extern "C" void fn_80136EA0(void* p) {
    extern void* lbl_80292A64[];
    *(void**)p = lbl_80292BB4;
    *(f64*)((u8*)p + 0x8) = *(f32*)&lbl_802FEAB0;
    *(f64*)((u8*)p + 0x10) = *(f64*)((u8*)p + 0x8);
    *(f64*)((u8*)p + 0x18) = *(f64*)((u8*)p + 0x8);
    *(u8*)((u8*)p + 0x20) = 0;
    *(u8*)((u8*)p + 0x21) = 0;
    *(f64*)((u8*)p + 0x28) = *(f64*)((u8*)p + 0x8);
    *(f64*)((u8*)p + 0x30) = *(f64*)((u8*)p + 0x8);
    *(s32*)((u8*)p + 0x38) = 0;
    *(s32*)((u8*)p + 0x3c) = 0;
    *(s32*)((u8*)p + 0x40) = 0;
    *(void**)p = lbl_80292A64;
    *(s32*)((u8*)p + 0x44) = 0;
    *(s32*)((u8*)p + 0x48) = 0;
    *(f64*)((u8*)p + 0x50) = *(f32*)&lbl_802FEAB0;
    *(s32*)((u8*)p + 0x58) = 0;
}

extern "C" int fn_80136F18(void) {
    return 4;
}

extern "C" void fn_80136F20(void* p, unsigned int q) {
    unsigned int a = q;
    unsigned int b = q;
    if (q != 0) {
        b = b + 0x40;
    }
    if (q != 0) {
        a = q + 8;
    }
    *(u32*)p = 0;
    *(u32*)((u8*)p + 4) = a;
    *(u32*)((u8*)p + 8) = b;
}

extern "C" void fn_80136F50(void* p) {
    *(f64*)((u8*)p + 0x8) = *(f32*)&lbl_802FEAB0;
    *(f64*)((u8*)p + 0x10) = *(f64*)((u8*)p + 0x8);
    *(f64*)((u8*)p + 0x18) = *(f64*)((u8*)p + 0x8);
    *(u8*)((u8*)p + 0x20) = 0;
    *(u8*)((u8*)p + 0x21) = 0;
    *(s32*)((u8*)p + 0x38) = 0;
    *(s32*)((u8*)p + 0x3c) = 0;
    *(s32*)((u8*)p + 0x40) = 0;
    *(s32*)((u8*)p + 0x44) = 0;
    *(s32*)((u8*)p + 0x48) = 0;
    *(f64*)((u8*)p + 0x50) = *(f32*)&lbl_802FEAB0;
    *(s32*)((u8*)p + 0x58) = 0;
}

extern "C" void fn_80136F9C(u8* p) {
    switch (*(s8*)(p + 0x20)) {
    case 0:
    default:
        *(f64*)(p + 0x28) = 0.0;
        *(f64*)(p + 0x30) = 1.0;
        break;
    case 1:
        *(f64*)(p + 0x28) = 0.0;
        *(f64*)(p + 0x30) = -1.0;
        break;
    case 2:
        *(f64*)(p + 0x28) = *(f64*)(p + 0x8);
        *(f64*)(p + 0x30) = -1.0;
        break;
    case 3:
        *(f64*)(p + 0x28) = *(f64*)(p + 0x10);
        *(f64*)(p + 0x30) = -1.0;
        break;
    case 4:
        *(f64*)(p + 0x28) = 0.5 * (*(f64*)(p + 0x8) + *(f64*)(p + 0x10));
        *(f64*)(p + 0x30) = -1.0;
        break;
    }
    switch (*(s32*)(p + 0x40)) {
    case 0:
    default:
        *(void**)(p + 0x58) = (void*)fn_801375FC;
        break;
    case 1:
        *(void**)(p + 0x58) = (void*)fn_80137610;
        break;
    case 2:
        *(void**)(p + 0x58) = (void*)fn_80137644;
        break;
    case 3:
        *(void**)(p + 0x58) = (void*)fn_801376D0;
        if (*(u32*)(p + 0x48) == 2) {
            *(void**)(p + 0x58) = (void*)fn_80137610;
        }
        break;
    }
}


extern "C" f32 fn_801375FC(void* param_1, u32* param_2) {
    f32* table = *(f32**)((u8*)param_1 + 0x44);
    return table[param_2[4]];
}

#pragma fp_contract off
extern "C" f64 fn_80137610(void* param_1, f64* param_2) {
    f32* table = *(f32**)((u8*)param_1 + 0x44);
    u32 idx = ((u32*)param_2)[4];
    f64 a = table[idx];
    f64 b = table[idx + 1];
    return a + (b - a) * (param_2[0] - param_2[1]);
}
#pragma fp_contract reset
extern "C" f64 fn_80137644(void* param_1, f64* param_2) {
    return 0.0;
}

extern "C" void fn_801377A0(void* param_1) {
    u8* p = (u8*)param_1;
    void* vt2 = lbl_80292A08;
    *(void**)(p + 0x0) = lbl_80292BB4;
    *(f64*)(p + 0x8) = *(f32*)&lbl_802FEAB0;
    *(f64*)(p + 0x10) = *(f64*)(p + 0x8);
    *(f64*)(p + 0x18) = *(f64*)(p + 0x8);
    *(u8*)(p + 0x20) = 0;
    *(u8*)(p + 0x21) = 0;
    *(f64*)(p + 0x28) = *(f64*)(p + 0x8);
    *(f64*)(p + 0x30) = *(f64*)(p + 0x8);
    *(s32*)(p + 0x38) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0x40) = 0;
    *(void**)(p + 0x0) = vt2;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x50) = *(s32*)(p + 0x4c);
    *(s32*)(p + 0x54) = *(s32*)(p + 0x4c);
    *(s32*)(p + 0x58) = 0;
}

extern "C" int fn_80137824(void) {
    return 5;
}

extern "C" void fn_8013782C(void* p, unsigned int q) {
    unsigned int a = q;
    unsigned int b = q;
    if (q != 0) {
        b = b + 0x40;
    }
    if (q != 0) {
        a = q + 8;
    }
    *(u32*)p = 0;
    *(u32*)((u8*)p + 4) = a;
    *(u32*)((u8*)p + 8) = b;
}

extern "C" void fn_8013785C(void* param_1, s32 param_2, s32 param_3) {
    *(s32*)((u8*)param_1 + 0x44) = param_2;
    *(s32*)((u8*)param_1 + 0x48) = param_3;
    *(s32*)((u8*)param_1 + 0x4c) = *(s32*)((u8*)param_1 + 0x44);
    *(s32*)((u8*)param_1 + 0x50) = *(s32*)((u8*)param_1 + 0x44) + *(s32*)((u8*)param_1 + 0x48) * 8;
    *(s32*)((u8*)param_1 + 0x54) = *(s32*)((u8*)param_1 + 0x4c);
}

extern "C" void fn_8013788C(void* param_1) {
    *(f64*)((u8*)param_1 + 0x8) = *(f32*)&lbl_802FEAB0;
    *(f64*)((u8*)param_1 + 0x10) = *(f64*)((u8*)param_1 + 0x8);
    *(f64*)((u8*)param_1 + 0x18) = *(f64*)((u8*)param_1 + 0x8);
    *(u8*)((u8*)param_1 + 0x20) = 0;
    *(u8*)((u8*)param_1 + 0x21) = 0;
    *(s32*)((u8*)param_1 + 0x38) = 0;
    *(s32*)((u8*)param_1 + 0x3c) = 0;
    *(s32*)((u8*)param_1 + 0x40) = 0;
    *(s32*)((u8*)param_1 + 0x44) = 0;
    *(s32*)((u8*)param_1 + 0x48) = 0;
    *(s32*)((u8*)param_1 + 0x4c) = 0;
    *(s32*)((u8*)param_1 + 0x50) = *(s32*)((u8*)param_1 + 0x4c);
    *(s32*)((u8*)param_1 + 0x54) = *(s32*)((u8*)param_1 + 0x4c);
    *(s32*)((u8*)param_1 + 0x58) = 0;
}

extern "C" void fn_80138004(void* param_1, void* param_2);
extern "C" void fn_801378E4(u8* p) {
    switch (*(s8*)(p + 0x20)) {
    case 0:
    default:
        *(f64*)(p + 0x28) = 0.0;
        *(f64*)(p + 0x30) = 1.0;
        break;
    case 1:
        *(f64*)(p + 0x28) = 0.0;
        *(f64*)(p + 0x30) = -1.0;
        break;
    case 2:
        *(f64*)(p + 0x28) = *(f64*)(p + 0x8);
        *(f64*)(p + 0x30) = -1.0;
        break;
    case 3:
        *(f64*)(p + 0x28) = *(f64*)(p + 0x10);
        *(f64*)(p + 0x30) = -1.0;
        break;
    case 4:
        *(f64*)(p + 0x28) = 0.5 * (*(f64*)(p + 0x8) + *(f64*)(p + 0x10));
        *(f64*)(p + 0x30) = -1.0;
        break;
    }
    switch (*(s32*)(p + 0x40)) {
    case 0:
    default:
        *(void**)(p + 0x58) = (void*)fn_80137F4C;
        break;
    case 1:
        *(void**)(p + 0x58) = (void*)fn_80137F58;
        break;
    case 2:
        *(void**)(p + 0x58) = (void*)fn_80137F88;
        break;
    case 3:
        *(void**)(p + 0x58) = (void*)fn_80138004;
        if (*(u32*)(p + 0x48) == 2) {
            *(void**)(p + 0x58) = (void*)fn_80137F58;
        }
        break;
    }
}

extern "C" f32 fn_80137F4C(void* param_1) {
    return *(f32*)(*(u8**)((u8*)param_1 + 0x54) - 4);
}

extern "C" f64 fn_80137F58(void* p, f32 x) {
    f32* q = *(f32**)((u8*)p + 0x54);
    return q[-1] + ((f64)q[1] - q[-1]) * ((f64)x - q[-2]) / ((f64)q[0] - q[-2]);
}

extern "C" f64 fn_80137F88(void* p, f32 x) {
    f32* q = *(f32**)((u8*)p + 0x54);
    f64 dx = (f64)x - q[-2];
    f64 t = dx * (1.0 / ((f64)q[0] - q[-2]));
    f64 tt = t * t;
    f64 h2 = (3.0 + -2.0 * t) * tt;
    f64 u = t - 1.0;
    f64 h1 = 1.0 - h2;
    f64 uu = u * u;
    f64 b = t * (u * dx);
    f64 a = dx * uu;
    return b * 0.0 + (a * 0.0 + (h1 * q[-1] + h2 * q[1]));
}

extern "C" void fn_801382A8(void* param_1) {
    *(void**)param_1 = lbl_80292BB4;
    *(f64*)((u8*)param_1 + 0x8) = lbl_802FEAB0[0];
    *(f64*)((u8*)param_1 + 0x10) = *(f64*)((u8*)param_1 + 0x8);
    *(f64*)((u8*)param_1 + 0x18) = *(f64*)((u8*)param_1 + 0x8);
    *(u8*)((u8*)param_1 + 0x20) = 0;
    *(u8*)((u8*)param_1 + 0x21) = 0;
    *(f64*)((u8*)param_1 + 0x28) = *(f64*)((u8*)param_1 + 0x8);
    *(f64*)((u8*)param_1 + 0x30) = *(f64*)((u8*)param_1 + 0x8);
    *(u32*)((u8*)param_1 + 0x38) = 0;
    *(u32*)((u8*)param_1 + 0x3c) = 0;
    *(void**)param_1 = lbl_80292974;
    *(u32*)((u8*)param_1 + 0x40) = 0;
    *(u32*)((u8*)param_1 + 0x44) = 0;
    *(u32*)((u8*)param_1 + 0x48) = 0;
    *(u32*)((u8*)param_1 + 0x4c) = 0;
    *(u32*)((u8*)param_1 + 0x50) = *(u32*)((u8*)param_1 + 0x48);
    *(u32*)((u8*)param_1 + 0x54) = *(u32*)((u8*)param_1 + 0x4c);
    *(u32*)((u8*)param_1 + 0x58) = *(u32*)((u8*)param_1 + 0x50);
    *(u32*)((u8*)param_1 + 0x5c) = *(u32*)((u8*)param_1 + 0x4c);
    *(u32*)((u8*)param_1 + 0x60) = *(u32*)((u8*)param_1 + 0x50);
}

extern "C" u32 fn_80138340(void) {
    return 6;
}

extern "C" void fn_80138348(void* param_1, unsigned int param_2) {
    if (param_2 != 0) {
        param_2 = param_2 + 8;
    }
    *(u32*)param_1 = 0;
    *(u32*)((u8*)param_1 + 4) = param_2;
    *(u32*)((u8*)param_1 + 8) = 0;
}

extern "C" void fn_80138368(void* param_1, u32 param_2, u32 param_3, u32 param_4) {
    u32 temp0, temp1, temp2;
    
    *(u32*)((u8*)param_1 + 0x40) = param_2;
    *(u32*)((u8*)param_1 + 0x44) = param_3;
    *(u32*)((u8*)param_1 + 0x48) = param_4;
    
    temp2 = *(u32*)((u8*)param_1 + 0x48);
    temp0 = *(u32*)((u8*)param_1 + 0x40);
    *(u32*)((u8*)param_1 + 0x4c) = temp0;
    *(u32*)((u8*)param_1 + 0x50) = temp2;
    
    temp1 = *(u32*)((u8*)param_1 + 0x48);
    temp0 = *(u32*)((u8*)param_1 + 0x44);
    temp2 = *(u32*)((u8*)param_1 + 0x40);
    *(u32*)((u8*)param_1 + 0x54) = temp2 + temp0 * temp1 * 4;
    *(u32*)((u8*)param_1 + 0x58) = temp1;
    
    *(u32*)((u8*)param_1 + 0x5c) = *(u32*)((u8*)param_1 + 0x4c);
    *(u32*)((u8*)param_1 + 0x60) = *(u32*)((u8*)param_1 + 0x50);
}

extern "C" void fn_801383B8(void* param_1) {
    *(f64*)((u8*)param_1 + 0x8) = *(f32*)&lbl_802FEAB0;
    *(f64*)((u8*)param_1 + 0x10) = *(f64*)((u8*)param_1 + 0x8);
    *(f64*)((u8*)param_1 + 0x18) = *(f64*)((u8*)param_1 + 0x8);
    *(u8*)((u8*)param_1 + 0x20) = 0;
    *(u8*)((u8*)param_1 + 0x21) = 0;
    *(u32*)((u8*)param_1 + 0x38) = 0;
    *(u32*)((u8*)param_1 + 0x3c) = 0;
    *(u32*)((u8*)param_1 + 0x40) = 0;
    *(u32*)((u8*)param_1 + 0x44) = 0;
    *(u32*)((u8*)param_1 + 0x48) = 0;
    u32 temp = *(u32*)((u8*)param_1 + 0x48);
    *(u32*)((u8*)param_1 + 0x4c) = 0;
    *(u32*)((u8*)param_1 + 0x50) = temp;
    *(u32*)((u8*)param_1 + 0x54) = *(u32*)((u8*)param_1 + 0x4c);
    *(u32*)((u8*)param_1 + 0x58) = *(u32*)((u8*)param_1 + 0x50);
    *(u32*)((u8*)param_1 + 0x5c) = *(u32*)((u8*)param_1 + 0x4c);
    *(u32*)((u8*)param_1 + 0x60) = *(u32*)((u8*)param_1 + 0x50);
}

extern "C" void fn_80138424(void* p) {
    switch (*(s8*)((u8*)p + 0x20)) {
    case 0:
    default:
        *(f64*)((u8*)p + 0x28) = 0.0;
        *(f64*)((u8*)p + 0x30) = 1.0;
        break;
    case 1:
        *(f64*)((u8*)p + 0x28) = 0.0;
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    case 2:
        *(f64*)((u8*)p + 0x28) = *(f64*)((u8*)p + 0x8);
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    case 3:
        *(f64*)((u8*)p + 0x28) = *(f64*)((u8*)p + 0x10);
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    case 4:
        *(f64*)((u8*)p + 0x28) = 0.5 * (*(f64*)((u8*)p + 0x8) + *(f64*)((u8*)p + 0x10));
        *(f64*)((u8*)p + 0x30) = -1.0;
        break;
    }
}

extern "C" void fn_80138AB4(void) {}

extern "C" f64 fn_80138AB8(f64 a, f64 b) {
    f64 r = fn_801E9FA0(a, b);
    if (r < 0.0) {
        r += b;
    }
    return r;
}

extern "C" f64 fn_80138AF4(f64 a, f64 b) {
    if (a <= 0.0) {
        return 0.0;
    }
    if (b <= a) {
        return a;
    }
    return b;
}

void fn_80138B7C(void*, It_80138B20, It_80138B20, It_80138B20, void*, Tag_80138B20);
extern "C" void fn_80138B7C(void*, It_80138B20, It_80138B20, It_80138B20, void*, Tag_80138B20);
extern "C" It_80138B20 fn_80138B20(It_80138B20* a, It_80138B20* b, It_80138B20* c, void* d) {
    Tag_80138B20 t;
    return fn_80138B7C(*a, *b, *c, d, t);
}

extern "C" void fn_80138DA8(void* p, It2_80138DA8 a, It2_80138DA8 b, It2_80138DA8 c, void* d) {
}

extern void* lbl_80292974[];
extern "C" void* fn_80139110(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292974;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292A08[];
extern "C" void* fn_8013916C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292A08;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292A64[];
extern "C" void* fn_801391C8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292A64;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292AC4[];
extern "C" void* fn_80139224(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292AC4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292B14[];
extern "C" void* fn_80139280(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292B14;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801396C0(u32* dst, u32* src) {
    *dst = *src;
}

extern "C" void fn_801396CC(u32* dst, u32* src) {
    *dst = *src;
}

extern char lbl_80201F70[];
extern "C" void fn_801396D8(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_801396E4(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_801396F0(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_801396FC(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_80139708(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_80139714(void* param_1, void* param_2) {
    f64 v;
    u32* p = *(u32**)((char*)param_2 + 8);
    char* e = lbl_80201F70 + *p * 8;
    (*(void (**)(f64*, void*))(e + 4))(&v, p + 1);
    *(u32*)((char*)param_1 + 0x30) = *(u32*)e;
    *(f64*)((char*)param_1 + 0x38) = v;
}

extern "C" void fn_80139780(void* param_1, void* param_2) {
    *(f64*)((char*)param_1 + 0x20) = **(f32**)((char*)param_2 + 8);
}

extern u8 lbl_80292CD8[];
extern "C" void fn_801679DC(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80167A44(void*, void*, void*);
extern "C" void fn_80139830(void** p) {
    p[0] = lbl_80292CD8;
    p[1] = 0;
    p[3] = 0;
    p[4] = 0;
    p[2] = 0;
    p[3] = &p[3];
    p[4] = &p[3];
}

extern "C" void* fn_80139860(u8* p, s16 del) {
    if (p) {
        *(u8**)p = lbl_80292CD8;
        if (p + 8) {
            fn_801679DC(p + 8, 0);
        }
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_801398CC(u8* p) {
    u8* node;
    u8* head = p + 0xc;
    u8* it[3];
    it[2] = head;
    it[1] = head;
    while (*(u32*)(p + 8) != 0) {
        node = *(u8**)(head + 4) - 0xc;
        fn_80167A44(it, p + 8, node + 0xc);
        (*(VObj_801398CC**)(p + 4))->v2(node);
    }
}

extern "C" void fn_8013A388(void** a, void** b, void** c, u32 d);
extern "C" void* fn_80139950(u8* self, u32 a, u32 b) {
    u32 key[2];
    void* first[2];
    void* last[2];
    void* res[2];
    void* tmp[2];
    void* end = self + 0xc;
    void* head = *(void**)(self + 0xc);
    key[0] = a;
    key[1] = b;
    first[0] = head;
    first[1] = end;
    last[0] = end;
    last[1] = end;
    fn_8013A388(res, first, last, (u32)key);
    tmp[0] = res[0];
    if (tmp[0] != end) return (u8*)tmp[0] - 0xc;
    return 0;
}

extern "C" void* fn_801399E4(void* list, u32 index)
{
    struct Iter {
        void** p;
    };
    if (index >= *(u32*)((char*)list + 0x8)) {
        return 0;
    }
    Iter a;
    a.p = *(void***)((char*)list + 0xc);
    Iter b = a;
    void** cur = b.p;
    for (; index != 0; index--) {
        cur = (void**)*cur;
    }
    return (char*)cur - 0xc;
}

extern void* lbl_80292CAC[];
extern "C" void* fn_80139A60(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292CAC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80139DB0(void* param_1, fn_80139DB0_Obj* param_2) {
    if (param_2 != nullptr) {
        param_2->fn_0(1);
    }
}

extern "C" void fn_80139DEC(void** param_1, u32 param_2) {
    char* base = lbl_802911A0;
    char* derived = lbl_80292C80;
    param_1[0] = base;
    param_1[0] = derived;
    ((u32*)param_1)[1] = param_2;
}

extern "C" void fn_80167880(void*, int);
extern char lbl_80292C80[];
extern "C" void* fn_80139E0C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80292C80;
        fn_80167880(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" int fn_801E3C54(const void*, const void*, u32);
extern "C" char lbl_80301880[4];
extern void* lbl_80292D58[];
extern void* lbl_80292EC4[];
extern void* lbl_80292974[];
extern void* lbl_80292EB4[];
extern void* lbl_80292B94[];
extern "C" u8 fn_8013A48C(void* p, u32 x);
extern "C" void fn_80167BB0(void* p, u32 x);
extern "C" BOOL fn_80139E6C(void* param_1, u8** param_2, u32* param_3) {
    u8* p = *param_2;
    *param_2 = p + 0x10;
    *param_3 = *(u32*)(p + 0xc);
    if (fn_801E3C54(p, lbl_80301880, 4) != 0) {
        return FALSE;
    }
    if (*(u16*)(p + 4) != 0xFEFF) {
        return FALSE;
    }
    u32 n = *(u16*)(p + 6);
    if (n < 2) {
        return FALSE;
    }
    return n <= 0x100;
}

extern "C" void* fn_8013A024(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((u8*)ptr + 8) = lbl_80292D58;
        if ((u8*)ptr + 0x18 != nullptr) {
            *(void**)((u8*)ptr + 0x18) = lbl_80292974;
            fn_8013635C((u8*)ptr + 0x18, 0);
        }
        if (ptr != nullptr) {
            *(void**)((u8*)ptr + 8) = lbl_80292EC4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8013A2E0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((u8*)ptr + 8) = lbl_80292EB4;
        if ((u8*)ptr + 0x18 != nullptr) {
            *(void**)((u8*)ptr + 0x18) = lbl_80292B94;
            if ((u8*)ptr + 0x1c != nullptr) {
                fn_80167BB0((u8*)ptr + 0x1c, 0);
            }
        }
        fn_8013635C((u8*)ptr + 0x18, 0);
        if (ptr != nullptr) {
            *(void**)((u8*)ptr + 8) = lbl_80292EC4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292D58[];
extern void* lbl_80292EB4[];
extern void* lbl_80292B94[];
extern "C" u8 fn_8013A48C(void* p, u32 x);
extern "C" void fn_80167BB0(void* p, u32 x);
extern "C" void* fn_80167818(void* x, void* y, void* z, u32 w);
extern void* lbl_80292EC4[];
extern "C" void fn_8013A388(void** a, void** b, void** c, u32 d) {
    while (*c != *b && !fn_8013A48C((u8*)*b - 0xc, d)) {
        *b = *(void**)*b;
    }
    *a = *b;
}

extern "C" void fn_8013A424(void** a, u32* b) {
    void* r = fn_80167818(a[0], b, b + 1, 0);
    u32 n = *b;
    if (n == 0) {
        ((void**)b)[2] = 0;
        ((void**)b)[3] = r;
    } else {
        ((void**)b)[2] = r;
        ((void**)b)[3] = (u8*)r + ((n + 3) & ~3);
    }
}

extern void* lbl_80292F5C[];
extern "C" void* fn_8013AF0C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292F5C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_8013AF54()
{
	return 0;
}

extern "C" void fn_8013AF5C(void* param_1, fn_80139DB0_Obj* param_2) {
    if (param_2 != nullptr) {
        param_2->fn_0(1);
    }
}

extern "C" void fn_80167880(void*, int);
extern char lbl_80292F24[];
extern "C" void* fn_8013AFB8(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80292F24;
        fn_80167880(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" BOOL fn_8013B138(void);
extern "C" BOOL fn_8013B138(void)
{
    return TRUE;
}

extern "C" void fn_80132C50(void*, int);
extern char lbl_8029308C[];
extern "C" void* fn_8013B42C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_8029308C;
        fn_80132C50(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801C61AC(void* p, f32 x, f32 y, f32 z);
extern "C" void fn_801C5DA8(void* a, void* b, void* c);
extern "C" void fn_801C5E74(void* a, void* b);
extern "C" void fn_80133000(void* a, void* b, void* c, void* d);
extern "C" s32 fn_8013BAB4(void* a, f32* b, void* c, u32 d) {
    u8 pos[48];
    u8 out[48];
    if (c == nullptr) {
        return 0;
    }
    if (!((u8 (*)(void*, u32, void*))(*(void***)c)[14])(c, d, out)) {
        return 0;
    }
    fn_801C61AC(pos, b[0], b[1], b[2]);
    fn_801C5DA8(out, pos, a);
    return 1;
}

extern "C" s32 fn_8013BB4C(void* a, u8* b, void* c, u32 d) {
    u8 pos[48];
    u8 tmp[48];
    u8 out[48];
    if (c == nullptr) {
        return 0;
    }
    if (!((u8 (*)(void*, u32, void*))(*(void***)c)[14])(c, d, out)) {
        return 0;
    }
    fn_80133000(tmp, b + 0x18, b + 0xc, b);
    fn_801C5E74(out, pos);
    fn_801C5DA8(pos, tmp, a);
    return 1;
}

extern "C" s32 fn_8013BBF0(void* a, f32* b, void* c, u32 d) {
    u8 pos[48];
    u8 tmp[48];
    u8 out[48];
    if (c == nullptr) {
        return 0;
    }
    if (!((u8 (*)(void*, u32, void*))(*(void***)c)[14])(c, d, out)) {
        return 0;
    }
    fn_801C61AC(tmp, b[0], b[1], b[2]);
    fn_801C5E74(out, pos);
    fn_801C5DA8(pos, tmp, a);
    return 1;
}

extern "C" u32 fn_8013BCDC(NaviTracker* param_1, u32 param_2) {
    u32 out;
    if (param_1->fn_13(&out, param_2, 0) != 0) {
        return 0;
    }
    return out;
}

extern void* lbl_8029320C[];
extern "C" void* fn_80133C0C(void* ptr, s16 param_2);
extern "C" void* fn_8013BEB0(NaviTracker* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029320C;
        ptr->fn_3();
        fn_80133C0C(ptr, 0);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013C0E4(void* param_1) {
    NaviTracker* piVar1 = *(NaviTracker**)((u8*)param_1 + 0x128);
    piVar1->fn_5(piVar1->fn_4() & 0xfffffffe);
}

extern "C" void fn_8013C138(void* param_1, void* param_2) {
    fn_8013C544(param_1, *(void**)((u8*)param_2 + 0x14));
    void* obj = *(void**)((u8*)param_1 + 0x128);
    ((void (*)(void*))(*(void***)obj)[5])(obj);
}

extern "C" void fn_8013C17C(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x128), param_3, param_4, param_5, param_6);
}

extern void* lbl_802930A0[];
extern "C" void fn_8013C508(void* a, void* b, void* c, void* d, void* e);
extern "C" void fn_8013BC94(void* a, void* b, void* c, void* d, void* e);
extern "C" void fn_8013C544(void* a, void* b);
extern "C" void fn_8013C1B0(void* param_1, void* param_2, void* param_3, void* param_4) {
    void* local[3];
    local[0] = lbl_802930A0[0];
    local[1] = lbl_802930A0[1];
    local[2] = lbl_802930A0[2];
    fn_8013C508(param_1, local, param_2, param_3, param_4);
}

extern void* lbl_802930AC[];
extern "C" void fn_8013C204(void* param_1, void* param_2, void* param_3, void* param_4) {
    void* local[3];
    local[0] = lbl_802930AC[0];
    local[1] = lbl_802930AC[1];
    local[2] = lbl_802930AC[2];
    fn_8013C508(param_1, local, param_2, param_3, param_4);
}

extern "C" void fn_8013C258(void* param_1, s32 param_2, void** param_3) {
    if (param_2 != 2) {
        return;
    }
    *(void**)((u8*)param_1 + 0x12c) = *param_3;
}

extern void* lbl_802930B8[];
extern "C" void fn_8013C26C(void* param_1, void* param_2, void* param_3, void* param_4) {
    void* local[3];
    local[0] = lbl_802930B8[0];
    local[1] = lbl_802930B8[1];
    local[2] = lbl_802930B8[2];
    fn_8013C508(param_1, local, param_2, param_3, param_4);
}

extern "C" void fn_80133414(void*, int);
extern char lbl_80293190[];
extern "C" void* fn_8013C91C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80293190;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

