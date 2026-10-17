#include "types.h"
extern "C" void fn_8003ABDC(void*, u32, u32, s32, s32);
extern "C" void fn_8003ABF0(void*, u32, s32, u32, s32, s32, s32, s32);
extern "C" void fn_801E6768(void*, char*);
extern "C" int fn_800D6904(void*, s16, u8, s32, s32);
extern f32 lbl_80300FD8;
extern f32 lbl_80300FE8;
struct VObj_800BD938 {
    virtual void d0();
    virtual void d1();
    virtual void v4(f32, f32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32);
};
extern "C" float fn_800D6DE8(char*, u8, short);
extern float lbl_80300FDC;
extern char lbl_802C579C[];
extern char lbl_802B7CA0[];
extern u32 lbl_80231428[];
extern u8 lbl_802FEE42;
extern "C" int fn_800D6700(void*, s16, u8, s32, s32, f32, f32, f32, f32);
extern "C" int fn_800D6A94(void*, s16, u8, s32, s32, f32, f32);
extern "C" void fn_8002FB68(u32, u8);
extern u32 lbl_802FF208;
extern "C" int fn_80021994(void*);
extern "C" int fn_8002185C(void*);
extern char lbl_802BB0FC[];
extern "C" void fn_8017A4F8(void*);
extern "C" u8 fn_8010E8CC(void*);
extern "C" void fn_800C55B8(void*, u8);
extern unsigned short lbl_802FD540[2];
extern unsigned short lbl_802FD544[2];
extern unsigned short lbl_802FD548[2];
struct NaviState_800D6308;
typedef void (NaviState_800D6308::*NaviStateFn_800D6308)();
extern NaviStateFn_800D6308 lbl_802899D4[];
extern void* lbl_80289A64[];
extern void* lbl_8027EC78[];
extern void* lbl_8028EFB0[];
struct DtorVObj_800D64E4 { virtual void Destroy(int); };
struct VObj_800D65E8 {
    virtual void d0();
    virtual void d1();
    virtual void v4(f32, f32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32);
};
struct VObj_800D69D4 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int);
};
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d36d0-0x800d70bc (46 functions). split_file divides it into the game's real files.

extern void* lbl_80289AD0[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_8028EB48[];
extern void* lbl_8027EC78[];
extern "C" void* fn_800D3844(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028EB48;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_800D65E8(void* param_1, s16 param_2, f32 param_3, f32 param_4, u8 param_5, u32 unused, s32 param_7);
extern "C" void fn_800D4E58(void* param_1) {
    u8* p = (u8*)param_1;
    *(s16*)(p + 0x134) = 0;
    fn_800D6700(param_1, *(s16*)(p + 0x134), lbl_802C579C[0xc], 0, 0, lbl_80300FD8, lbl_80300FD8, *(f32*)(lbl_802C579C + 0x10), lbl_80300FD8);
    fn_800D65E8(param_1, *(s16*)(p + 0x134), *(f32*)(lbl_802C579C + 0x10), lbl_80300FD8, lbl_802C579C[0x14], 0, 0);
}

extern "C" unsigned short fn_800D5324(void) {
    u32 idx = (*(u32*)(lbl_802BB0FC + 0x40) >> 1) & 1;
    if (fn_80021994(lbl_802BB0FC) != -1) {
        return lbl_802FD544[idx];
    }
    if (fn_8002185C(lbl_802BB0FC) > 1) {
        return lbl_802FD540[idx];
    }
    return lbl_802FD548[idx];
}

extern unsigned short lbl_802FD54C[2];
extern unsigned short lbl_802FD550[2];
extern unsigned short lbl_802FD554[2];
extern "C" unsigned short fn_800D53A4(void) {
    u32 idx = (*(u32*)(lbl_802BB0FC + 0x40) >> 1) & 1;
    if (fn_80021994(lbl_802BB0FC) != -1) {
        return lbl_802FD550[idx];
    }
    if (fn_8002185C(lbl_802BB0FC) > 1) {
        return lbl_802FD54C[idx];
    }
    return lbl_802FD554[idx];
}

extern "C" void fn_800D54EC(char* p)
{
    if (lbl_802FF208 & 2) {
        if (*(u8*)(p + 0x131) == 0) {
            *(u8*)(p + 0x131) = 1;
            *(u8*)(p + 0x130) = 5;
        }
    } else {
        if (*(u8*)(p + 0x131) == 1) {
            *(u8*)(p + 0x131) = 0;
            *(u8*)(p + 0x130) = 6;
        }
    }
}

extern "C" void fn_801E6768(void*, char*);
extern "C" int fn_800D6904(void*, s16, u8, s32, s32);
extern "C" void fn_800D55F0(void* param_1) {
    u8* p = (u8*)param_1;
    char* q = lbl_802C579C;
    s32 r = fn_800D65E8(param_1, *(s16*)(p + 0x134), *(f32*)(q + 0x18), lbl_80300FD8, q[0x14], 0, 0);
    s32 r2 = fn_800D6904(param_1, *(s16*)(p + 0x134), q[0x14], 0, 0);
    (*(s16*)(p + 0x134))++;
    if (r == 1 && r2 == 1) {
        *(s16*)(p + 0x134) = 0;
        p[0x130] = 0;
    }
}

extern "C" void fn_800D5690(void* param_1) {
    u8* p = (u8*)param_1;
    char* q = lbl_802C579C;
    s32 r = fn_800D6700(param_1, *(s16*)(p + 0x134), q[0xc], 0, 1, lbl_80300FD8, lbl_80300FD8, lbl_80300FD8, *(f32*)(q + 0x10));
    (*(s16*)(p + 0x134))++;
    if (r == 1) {
        *(s16*)(p + 0x134) = 0;
        p[0x130] = 0;
    }
}

extern "C" void fn_800D5954(char* p) {
    s32 a = fn_800D6700(p, *(s16*)(p + 0x134), lbl_802C579C[0x20], 0, 2, lbl_80300FE8, lbl_80300FD8, lbl_80300FD8, lbl_80300FD8);
    s32 b = fn_800D6A94(p, *(s16*)(p + 0x134), lbl_802C579C[0x20], 0, 2, lbl_80300FE8, lbl_80300FD8);
    *(s16*)(p + 0x134) = *(s16*)(p + 0x134) + 1;
    if (a == 1 && b == 1) {
        *(s16*)(p + 0x134) = 0;
        p[0x130] = 0;
    }
}

extern "C" int fn_800D6700(void*, s16, u8, s32, s32, f32, f32, f32, f32);
extern "C" int fn_800D6A94(void*, s16, u8, s32, s32, f32, f32);
extern "C" void fn_8003ABDC(void*, u32, u32, s32, s32);
extern "C" void fn_8003ABF0(void*, u32, s32, u32, s32, s32, s32, s32);
extern "C" void fn_8002FB68(u32, u8);
extern "C" void fn_8015FDA8(void*, void*);
extern f32 lbl_80300FE8;
extern char lbl_802C579C[];
extern u32 lbl_80231428[];
extern u8 lbl_802FEE42;
extern "C" void fn_800D5D74(char* p) {
    if (*(u32*)(lbl_802BB0FC + 0x104) & 2) {
        char* q = p + ((*(u8*)(p + 0x5e) ^ 1) * 8);
        fn_8003ABDC(*(void**)(p + 0xc), *(u32*)(q + 0x70), *(u32*)(q + 0x74), 0, 0);
        q = p + ((*(u8*)(p + 0x5e) ^ 1) * 4);
        fn_8003ABF0(*(void**)(p + 0xc), *(u32*)(q + 0x60), 0, *(u32*)(q + 0x54), 0, 0x3de, 1, 0);
        p[0x130] = 0xb;
    }
}

extern "C" void fn_800D61D0(char* p) {
    if (*(u8*)(p + 0x138) != 0) {
        (*(u8*)(p + 0x138))--;
    } else {
        fn_8002FB68(lbl_80231428[((u8*)lbl_802B7CA0)[0x1419]], *(u8*)(p + 0xfa));
        lbl_802FEE42 = *(u8*)(p + 0xfa);
        *(u8*)(p + 0x138) = 0x3c;
        p[0x130] = 0xf;
    }
}

extern "C" void fn_800D624C(char* param_1) {
    if (*(u8*)(param_1 + 0x138) != 0) {
        (*(u8*)(param_1 + 0x138))--;
        return;
    }
    *(u32*)(lbl_802BB0FC + 0x104) |= 4;
    param_1[0x130] = 0;
}

extern "C" void fn_800D6284(void) {
}

extern "C" void fn_800D6288(char* param_1) {
    if (*(u8*)(param_1 + 0xf8) != 0) {
        (*(s32*)(param_1 + 0xf4))++;
        s16* p = (s16*)(*(char**)(param_1 + 0xf0) + 6);
        s32 cnt = *(s32*)(param_1 + 0xf4);
        if (cnt >= *p) {
            *(s32*)(param_1 + 0xf4) = cnt - *p;
        }
        *(f32*)(*(char**)(param_1 + 0xf0) + 8) = *(s32*)(param_1 + 0xf4);
        fn_8017A4F8(*(void**)(param_1 + 8));
    }
}

extern "C" void fn_800D6308(NaviState_800D6308* p) {
    (p->*lbl_802899D4[((u8*)p)[0x137]])();
}

extern "C" void* fn_8015A90C(unsigned long);
extern "C" void fn_8010D1DC(void*);
extern "C" void fn_800C5444(void*, int);
extern "C" void fn_800D6340(char* p) {
    if (*(void**)(p + 0x20) == 0) {
        void** o = (void**)fn_8015A90C(0xd8);
        if (o != 0) {
            o[0] = lbl_80289A64;
            o[1] = lbl_8027EC78;
            o[1] = lbl_8028EFB0;
        }
        *(void***)(p + 0x20) = o;
        *(void**)(*(char**)(p + 0x20) + 0xc) = *(void**)(p + 0xc);
        fn_8010D1DC(*(void**)(p + 0x20));
    }
    fn_800C5444(*(void**)(p + 0x18), 0);
    p[0x137] = 1;
}

extern void* lbl_8028EFB0[];
extern "C" void* fn_800D63D4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028EFB0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800D6430(char* param_1) {
    if (fn_8010E8CC(*(void**)(param_1 + 0x20)) == 1) {
        fn_800C55B8(*(void**)(param_1 + 0x18), *(*(u8**)(param_1 + 0x20) + 0xd7));
        param_1[0x137] = 2;
    }
}

extern "C" void fn_8010EC3C(void*);
extern "C" void fn_800C55B8(void*, u8);
extern "C" void fn_800D6484(char* param_1) {
    if (*(void**)(param_1 + 0x20) != 0) {
        fn_8010EC3C(*(void**)(param_1 + 0x20));
    }
    fn_800C55B8(*(void**)(param_1 + 0x18), *(*(u8**)(param_1 + 0x20) + 0xd7));
    if (*(*(u8**)(param_1 + 0x20) + 0xd6) == 1) {
        param_1[0x137] = 3;
    }
}

extern "C" unsigned char fn_8010EA18(void*);
extern "C" void fn_801103DC(void*);
extern char lbl_802BB0FC[];
extern "C" void fn_800D64E4(char* p) {
    if (fn_8010EA18(*(void**)(p + 0x20)) == 1) {
        if (*(void**)(p + 0x20) != 0) {
            fn_801103DC(*(void**)(p + 0x20));
            DtorVObj_800D64E4* o = *(DtorVObj_800D64E4**)(p + 0x20);
            if (o != 0) {
                o->Destroy(1);
            }
            *(void**)(p + 0x20) = 0;
        }
        *(unsigned int*)(lbl_802BB0FC + 0xf8) |= 0x400;
        *(unsigned char*)(p + 0x130) = 0;
    }
}

extern void* lbl_80283F48[];
extern "C" void* fn_800D6574(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)(ptr))[1] = lbl_8028EFB0;
            if ((s32)ptr + 0x4 != 0) {
                ((void**)(ptr))[1] = lbl_8027EC78;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_800D65E8(void* param_1, s16 param_2, f32 param_3, f32 param_4, u8 param_5, u32 unused, s32 param_7) {
    u8* p = (u8*)param_1;
    if (param_2 < 0) {
        return 0;
    }
    s32 idx = param_2;
    s32 max = param_5;
    if (idx > max) {
        return 1;
    }
    f32 t = fn_800D6DE8((char*)param_1, max, idx);
    f32 d = t * (param_4 - param_3);
    (*(VObj_800BD938**)(p + 0x24))->v4(*(f32*)(p + 0x28), *(f32*)(p + 0x2c) + (param_3 + d));
    if (param_7 != 2) {
        if (param_7 == 1) {
            t = lbl_80300FDC - t;
        }
        (*(VObj_800BD938**)(p + 0x24))->v9((s32)((f32)*(u8*)(p + 0x30) * t));
    }
    return 0;
}

extern "C" float fn_800D6DE8(char*, u8, short);
extern float lbl_80300FDC;
extern "C" int fn_800D69D4(char* param_1, short param_2, u8 param_3, int param_4, int param_5) {
    float f;
    if (param_2 < 0) {
        return 0;
    }
    if (param_2 > param_3) {
        return 1;
    }
    f = fn_800D6DE8(param_1, (u8)param_3, (short)param_2);
    if (param_5 != 2) {
        if (param_5 == 1) {
            f = lbl_80300FDC - f;
        }
        (*(VObj_800D69D4**)(param_1 + 0x80))->v7((int)((float)*(u8*)(param_1 + 0x84) * f));
    }
    return 0;
}

extern "C" void* fn_800D6D48(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)(ptr))[1] = lbl_8028EB48;
            if ((s32)ptr + 0x4 != 0) {
                ((void**)(ptr))[1] = lbl_8027EC78;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800D6DBC(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 0x10));
}

extern char lbl_802B7CA0[];
extern f32 lbl_80300FD8;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_800D7010(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300FD8;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800D7074(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80289AD0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
extern u32 lbl_802FF208;
