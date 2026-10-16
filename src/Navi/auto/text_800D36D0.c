#include "types.h"
extern u32 lbl_802FF208;
extern "C" int fn_80021994(void*);
extern "C" int fn_8002185C(void*);
extern char lbl_802BB0FC[];
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
