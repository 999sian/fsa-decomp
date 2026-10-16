#include "types.h"

extern f32 lbl_802FEAB0[];
extern void* lbl_80292A08[];
extern void fn_80167CD8(void*, u32, u32);
extern void* lbl_802985C8[];
extern void* lbl_80298B14[];
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80135f7c-0x8013c97c (185 functions). split_file divides it into the game's real files.

extern void* lbl_80292BB4[];
extern "C" void fn_8015AB1C(void* ptr);
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
extern "C" void fn_80136148(void* self, void* p, f32 x) {
    int v = 0;
    u8* q = (u8*)self + 4;
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

extern "C" u32 fn_80136A68(void) {
    return 2;
}

extern "C" void fn_80136A70(void* param_1) {
    *(u32*)param_1 = 0;
    *(u32*)((u8*)param_1 + 4) = 0;
    *(u32*)((u8*)param_1 + 8) = 0;
}

extern "C" u32 fn_80136B14(void) {
    return 3;
}

extern "C" int fn_80136F18(void) {
    return 4;
}

extern "C" f32 fn_801375FC(void* param_1, u32* param_2) {
    f32* table = *(f32**)((u8*)param_1 + 0x44);
    return table[param_2[4]];
}

#pragma fp_contract off
extern "C" f64 fn_80137610(void* param_1, f64* param_2) {
    f32* table = *(f32**)((u8*)param_1 + 0x44);
    u32 idx = ((u32*)param_2)[4];
    f64 d = param_2[0] - param_2[1];
    f64 a = table[idx];
    f64 b = table[idx + 1];
    return a + (b - a) * d;
}
#pragma fp_contract reset
extern "C" f64 fn_80137644(void* param_1, f64* param_2) {
    return 0.0;
}

extern "C" void fn_801377A0(void* param_1) {
    void* vt = lbl_80292BB4;
    *(void**)((u8*)param_1 + 0x0) = vt;
    *(f64*)((u8*)param_1 + 0x8) = *(f32*)&lbl_802FEAB0;
    *(f64*)((u8*)param_1 + 0x10) = *(f64*)((u8*)param_1 + 0x8);
    *(f64*)((u8*)param_1 + 0x18) = *(f64*)((u8*)param_1 + 0x8);
    *(u8*)((u8*)param_1 + 0x20) = 0;
    *(u8*)((u8*)param_1 + 0x21) = 0;
    *(f64*)((u8*)param_1 + 0x28) = *(f64*)((u8*)param_1 + 0x8);
    *(f64*)((u8*)param_1 + 0x30) = *(f64*)((u8*)param_1 + 0x8);
    *(s32*)((u8*)param_1 + 0x38) = 0;
    *(s32*)((u8*)param_1 + 0x3c) = 0;
    *(s32*)((u8*)param_1 + 0x40) = 0;
    *(void**)((u8*)param_1 + 0x0) = lbl_80292A08;
    *(s32*)((u8*)param_1 + 0x44) = 0;
    *(s32*)((u8*)param_1 + 0x48) = 0;
    *(s32*)((u8*)param_1 + 0x4c) = 0;
    *(s32*)((u8*)param_1 + 0x50) = *(s32*)((u8*)param_1 + 0x4c);
    *(s32*)((u8*)param_1 + 0x54) = *(s32*)((u8*)param_1 + 0x4c);
    *(s32*)((u8*)param_1 + 0x58) = 0;
}

extern "C" int fn_80137824(void) {
    return 5;
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

extern "C" f32 fn_80137F4C(void* param_1) {
    return *(f32*)(*(u8**)((u8*)param_1 + 0x54) - 4);
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

extern "C" void fn_80139DB0(void* param_1, void* param_2) {
    if (param_2 != nullptr) {
        ((void (*)(void*, s32))((void**)*(void**)((u8*)param_2 + 8))[2])(param_2, 1);
    }
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

extern void* lbl_80292D58[];
extern void* lbl_80292EB4[];
extern void* lbl_80292B94[];
extern "C" u8 fn_8013A48C(void* p, u32 x);
extern "C" void fn_80167BB0(void* p, u32 x);
extern "C" void* fn_80167818(void* x);
extern void* lbl_80292EC4[];
extern "C" void fn_8013A388(void** a, void** b, void** c, u32 d) {
    while (*c != *b && !fn_8013A48C((u8*)*b - 0xc, d)) {
        *b = *(void**)*b;
    }
    *a = *b;
}

extern "C" void fn_8013A424(void** a, s32* b) {
    void* r = fn_80167818(*a);
    if (*b == 0) {
        ((void**)b)[2] = 0;
        ((void**)b)[3] = r;
    } else {
        ((void**)b)[2] = r;
        ((void**)b)[3] = (u8*)r + ((*b + 3) & ~3);
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

