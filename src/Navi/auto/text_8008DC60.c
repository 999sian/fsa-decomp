#include "types.h"
#include "math.h"
extern void* lbl_80286BA8[];
extern f32 lbl_80300AB0;
extern f32 lbl_80300AB4;
extern f32 lbl_80300AB8;
extern f32 lbl_80300ABC;
extern f32 lbl_80300AC0;
extern f32 lbl_80300AC4;
extern f32 lbl_80300AC8;
extern f32 lbl_80300ACC;
extern f32 lbl_80300AD0;
extern f32 lbl_80300AD4;
extern f32 lbl_80300AD8;
extern f32 lbl_80300ADC;
extern f32 lbl_80300AE0;
extern f32 lbl_80300AE4;
extern f32 lbl_80300AE8;
extern f32 lbl_80300AEC;
extern f32 lbl_80300AFC;
extern "C" f32 fn_80116064(f32 x);
extern "C" s32 fn_80096F0C(void* p);
extern "C" u8 fn_800C6E38(void* p);
extern "C" u8 fn_800C6FD4(void* p);
extern "C" void fn_800CBB28(void* p);
extern "C" void fn_800EF4D0(void* p, s32 v);
extern "C" void fn_80097180(void* p);
extern "C" s32 fn_8009D0D8(s16* param_1);
struct NaviObjTbl_80097EB0 { u8 pad[0x64c]; u8* objs[1]; };
extern f32 lbl_80300B40;
struct VObj_8009F478 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(f32, f32);
    virtual void v5();
    virtual void v6(f32, f32);
};
extern "C" void fn_800F4C70(void* p);
extern void* lbl_80286A98[];
extern void* lbl_8028E870[];
extern "C" void fn_8010B64C(void* p);
extern "C" void fn_800A5338(void* p);

typedef struct NaviColor4 { u8 r, g, b, a; } NaviColor4;
extern void* lbl_80289A14[];
extern "C" char lbl_802C545C[];
extern "C" char lbl_802BB0FC[];
extern "C" char lbl_802864E4[];
extern "C" void fn_801E10DC(void* p, void* q);
extern f32 lbl_80300B20;
extern "C" f32 fn_800A1774(void*, s32, s32, u8);
extern f64 lbl_80300B00;
extern f64 lbl_80300B58;
extern f64 lbl_80300B60;
extern f32 lbl_80300B38;
extern f64 lbl_80300B68;
extern f32 lbl_80300B70;
extern f32 lbl_80300B74;
extern f32 lbl_80300AFC;
extern f32 lbl_802FEAB0[];
extern f32 lbl_802F0BC0[];
extern f32 lbl_80300AF0;

#pragma fp_contract off
static inline f32 navi_sqrtf_800A1774(f32 x)
{
    f32 r;
    if (x > lbl_80300AF0) {
        f64 guess = __frsqrte((f64)x);
        guess = lbl_80300B58 * guess * (lbl_80300B60 - guess * guess * x);
        guess = lbl_80300B58 * guess * (lbl_80300B60 - guess * guess * x);
        guess = lbl_80300B58 * guess * (lbl_80300B60 - guess * guess * x);
        r = (f32)(x * guess);
    } else if (x < lbl_80300B68) {
        r = lbl_802FEAB0[0];
    } else if (fpclassify(x) == 1) {
        r = lbl_802FEAB0[0];
    } else {
        r = x;
    }
    return r;
}
#pragma fp_contract reset
extern "C" void fn_800D1EE8(void* p);
struct DtorVObj_800A0008 { virtual void Destroy(int); };
extern "C" void fn_800D3274(u8* p);
extern "C" u8 fn_800BC784(void* p);
extern "C" void fn_800C55B8(void* p, u8 v);
extern "C" void fn_800C1278(void* p);
extern "C" void fn_800C3EE8();
extern "C" void fn_800E29CC(void* p);
class NaviState_8008DC60;
extern void (NaviState_8008DC60::*lbl_8028635C[])();
extern "C" void fn_800CAB58(void* p);
extern "C" void fn_800C6CA4(void* p);
extern "C" char lbl_802AE880[];
extern "C" void* fn_80016320(void* p);
extern "C" void fn_800CA7C4(void* p);
extern "C" u8 fn_800FFBBC(void* p);
struct VObj_80098354 {
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
    virtual void v14(f32, f32);
    virtual void v15(f32, f32);
    virtual void v16(f32, f32, f32, f32);
    virtual void v17(f32, f32);
};

extern void* lbl_80283F48[];
extern void* lbl_802886F8[];

extern void* lbl_80283F48[];
extern void* lbl_80289A14[];
extern void* lbl_80289110[];
extern void* lbl_80286964[];

extern void* lbl_80283F48[];

struct NaviState_8009E6F0 {
    void f();
};
typedef void (NaviState_8009E6F0::*NaviStateFunc_8009E6F0)();
extern NaviStateFunc_8009E6F0 lbl_802865A4[];
extern NaviStateFunc_8009E6F0 lbl_802862F0[];
extern NaviStateFunc_8009E6F0 lbl_802863BC[];
extern u32 lbl_802FEDD8;
extern s32 lbl_802FEDE4;
extern char lbl_802B7CA0[];
extern f32 lbl_80300AF0;
extern "C" void fn_8015FDA8(void*, void*);
extern "C" char lbl_802BB0FC[];
extern "C" u8 fn_8010B734(void*);
extern "C" void fn_8010BAA0(void*);
extern "C" u8 fn_8010B8D4(void*);
extern "C" void fn_800C55B8(void*, u8);
extern "C" u8 fn_800BC8A4(void*);
extern "C" u8 fn_800F39B4(void*);
extern "C" u8 fn_800A79FC(void*);
extern "C" void fn_800F3D84(void*);
extern "C" void fn_800FFBCC(void*);
extern "C" u8 fn_800FFBC4(void*);
extern "C" void fn_80109960(void*);
extern "C" void fn_800F2CD4(void*);
extern "C" void fn_800F3888(void*);
extern "C" void fn_800C5548(void*);
extern "C" void* fn_8015A90C(u32);
extern void* lbl_802869B4[];
extern void* lbl_8028C578[];
extern void* lbl_8027EC78[];
extern void* lbl_80286948[];
struct Pair_800936E0 {
    s32 a, b;
};
extern void* lbl_802893EC[];
extern "C" void fn_800D0910(void*);
extern "C" void fn_801E0DB8(void* arr, void* ctor, s32 dtor, s32 size, s32 n);
struct Obj_8009287C {
    u8 pad[0x7e8];
    u8 state;
};
typedef void (Obj_8009287C::*StateFn_8009287C)();
extern StateFn_8009287C lbl_80285C30[];
struct VObj_80098918 {
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
};

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80092228(void);
extern "C" void fn_80092444(void);
extern "C" void fn_800911F0(void);
extern "C" void fn_8006F0F4(void);
extern void* lbl_80286B1C[];
extern void* lbl_8028F164[];
extern "C" void fn_8011093C(void*);
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008dc60-0x800a1dc0 (285 functions). split_file divides it into the game's real files.

extern void* lbl_80286A30[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80286908[];
extern void* lbl_8027EC78[];
extern void* lbl_80286B38[];
extern void* lbl_80288854[];
extern void* lbl_8028B3B8[];
extern void* lbl_80288B1C[];
extern void* lbl_80288EDC[];
extern void* lbl_80288520[];
extern void* lbl_8028699C[];
extern void* lbl_80288988[];
extern void* lbl_802995E0[];
extern void* lbl_80299580[];
extern void* lbl_8029970C[];
extern void* lbl_80286A4C[];
extern void* lbl_80286A30[];
extern void* lbl_80285CCC[];
extern void fn_801E10DC();
extern void fn_800CAB58();
extern "C" void fn_8008DC60(u8* p) {
    s32 zero = 0;
    s16 neg = -1;
    *(void**)p = lbl_80286BA8;
    p[0x4] = neg;
    *(s32*)(p + 0x8) = zero;
    *(f32*)(p + 0xc) = lbl_80300AB0;
    *(f32*)(p + 0x10) = lbl_80300AB0;
    *(s16*)(p + 0x14) = zero;
    *(s16*)(p + 0x16) = zero;
    *(s16*)(p + 0x1a) = neg;
    p[0x1c] = zero;
    p[0x1e] = zero;
    p[0x1d] = zero;
    *(s16*)(p + 0x20) = 8;
    *(s16*)(p + 0x22) = 0xc;
    *(s16*)(p + 0x24) = 0xb4;
    p[0x26] = 0x1e;
    p[0x27] = 0x1e;
    p[0x28] = 0x1e;
    *(s16*)(p + 0x2a) = 0x258;
    p[0x2c] = 0xf;
    *(f32*)(p + 0x30) = lbl_80300AB4;
    *(f32*)(p + 0x34) = lbl_80300AB8;
    p[0x38] = 8;
    p[0x39] = 0xf;
    *(f32*)(p + 0x3c) = lbl_80300ABC;
    *(f32*)(p + 0x40) = lbl_80300AC0;
    *(f32*)(p + 0x44) = lbl_80300AC4;
    *(f32*)(p + 0x48) = lbl_80300AC8;
    p[0x4c] = 0xa;
    *(f32*)(p + 0x50) = lbl_80300ACC;
    *(f32*)(p + 0x54) = lbl_80300AD0;
    p[0x58] = 5;
    p[0x59] = 5;
    p[0x5a] = 0x14;
    p[0x5b] = 0xf;
    p[0x5c] = 0xa;
    *(f32*)(p + 0x60) = lbl_80300AD4;
    p[0x64] = 0xa;
    *(f32*)(p + 0x68) = lbl_80300AD4;
    *(f32*)(p + 0x6c) = lbl_80300AD8;
    *(f32*)(p + 0x70) = lbl_80300ADC;
    p[0x74] = 0x80;
    *(f32*)(p + 0x78) = lbl_80300AE0;
    *(f32*)(p + 0x7c) = lbl_80300AE4;
    *(f32*)(p + 0x80) = lbl_80300AE8;
    p[0x84] = zero;
    p[0x85] = zero;
    p[0x86] = zero;
    p[0x87] = zero;
    p[0x88] = zero;
    p[0x89] = zero;
    p[0x8a] = zero;
    *(f32*)(p + 0x8c) = lbl_80300AEC;
}

extern "C" void* fn_8008DDD4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286908;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80286928[];
extern void* lbl_8027EC78[];
extern "C" void* fn_8008DE30(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286928;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8028B8A8[];
extern "C" void* fn_8008E134(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B8A8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8008F374(void) {}

extern "C" int fn_8008F378()
{
	return 0;
}

extern "C" void fn_80090D44(void) {}

extern "C" void fn_80090D48(void) {}

extern char lbl_802C545C[];
extern f32 lbl_80300AF8;
extern "C" void fn_800A15D8(void*, s32, s32, f32, f32, u8, f32, f32, s32, s32);
extern void* lbl_80286B04[];
extern void* lbl_802880BC[];
#pragma use_lmw_stmw off
extern "C" void fn_80090D4C(u8* p) {
    s32 i;
    *(s16*)(p + 0x7fa) = 0;
    for (i = 0; i < 4; i++) {
        fn_800A15D8(p, i, *(s16*)(p + 0x7fa), lbl_80300AF0, lbl_80300AF0, *(u8*)(lbl_802C545C + 0x4c), lbl_80300AF8, lbl_80300AF0, 0, 2);
        p[i + 0x875] = 0xff;
        p[i + 0x491] = 0;
        p[i + 0x499] = 0;
        *(s32*)(p + i * 4 + 0x348) = 0;
        *(s32*)(p + i * 4 + 0x358) = 0;
    }
    p[0x874] = 0;
    *(s32*)(p + 0x860) = 0;
    *(s32*)(p + 0x864) = 0;
}
extern "C" void* fn_80091918(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286B38;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288854;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8009198C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80091A00(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286B04;
        if ((s32)ptr + (unsigned)0x20 != 0) {
            ((void**)ptr)[8] = lbl_802880BC;
            if ((s32)ptr + 0x20 != 0) {
                ((void**)ptr)[8] = lbl_8027EC78;
            }
        }
        if ((s32)ptr + (unsigned)0x18 != 0) {
            ((void**)ptr)[6] = lbl_802880BC;
            if ((s32)ptr + 0x18 != 0) {
                ((void**)ptr)[6] = lbl_8027EC78;
            }
        }
        if ((s32)ptr + (unsigned)0x10 != 0) {
            ((void**)ptr)[4] = lbl_802880BC;
            if ((s32)ptr + 0x10 != 0) {
                ((void**)ptr)[4] = lbl_8027EC78;
            }
        }
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)ptr)[2] = lbl_802880BC;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)ptr)[2] = lbl_8027EC78;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80091AEC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)(ptr))[1] = lbl_802886F8;
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

extern "C" void* fn_80091B60(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80091DD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80091E4C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)(ptr))[1] = lbl_80289A14;
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

extern "C" void* fn_80091FD4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80092048(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802995E0;
        if ((s32)ptr + 0x70 != 0) {
            ((void**)(ptr))[0x1c] = lbl_80286A4C;
        }
        if ((s32)ptr + 0x38 != 0) {
            ((void**)(ptr))[0xe] = lbl_80286A4C;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_800920D0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299580;
        if ((s32)ptr + 0x3c != 0) {
            ((void**)(ptr))[0xf] = lbl_80286A4C;
        }
        if ((s32)ptr + 0x28 != 0) {
            ((void**)(ptr))[0xa] = lbl_80286A4C;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80286A1C[];
extern "C" void* fn_80092158(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286A1C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_800921B4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029970C;
        if ((s32)ptr + 0x20 != 0) {
            ((void**)(ptr))[8] = lbl_80286A4C;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8009287C(Obj_8009287C* param_1) {
    (param_1->*lbl_80285C30[param_1->state])();
}

extern void* lbl_80286D24[];
extern "C" void* fn_80092A44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286D24;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8028EAA0[];
extern "C" void* fn_80092AA0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028EAA0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80092C00(char* param_1) {
    if (fn_8010B734(*(void**)(param_1 + 0x29c)) == 1) {
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x29c) + 0x9d));
        param_1[0x7e8] = 3;
    }
}

extern "C" void fn_80092C54(char* param_1) {
    fn_8010BAA0(*(void**)(param_1 + 0x29c));
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x29c) + 0x9d));
    if (*(*(u8**)(param_1 + 0x29c) + 0x9c) == 1) {
        param_1[0x7e8] = 4;
    }
}

extern "C" void fn_80092CAC(char* param_1) {
    if (fn_8010B8D4(*(void**)(param_1 + 0x29c)) == 1) {
        char* p = *(char**)(param_1 + 0x264);
        p[0x19a] = 3;
        p[0x19b] = 0;
        param_1[0x7e8] = 1;
    }
}

extern "C" void fn_80092D04(void* param_1) {
    u8 state = *(u8*)((char*)param_1 + 0x7e8);
    u32 fn_base = (u32)lbl_80285CCC;
    u32 fn_ptr = fn_base + state * 0xc;
    fn_801E10DC();
    if (*(void**)((char*)param_1 + 0x280) != nullptr) {
        fn_800CAB58();
    }
}

extern void* lbl_80288854[];
extern "C" void* fn_80092F20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288854;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80092F7C(s32* param_1) {
    *param_1 = -1;
}

extern void* lbl_80287344[];
extern "C" void* fn_80092F88(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287344;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80092FE4(char* param_1) {
    if (fn_800A79FC(*(void**)(param_1 + 0x268)) == 1) {
        param_1[0x7e8] = 3;
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x268) + 0x3da));
    }
}

extern "C" void fn_800A7EBC(u8* p);
extern "C" void fn_80093038(u8* param_1) {
    if (*(u8**)(param_1 + 0x268) != 0) {
        fn_800A7EBC(*(u8**)(param_1 + 0x268));
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x268) + 0x3da));
        u8 v = *(*(u8**)(param_1 + 0x268) + 0x3d2);
        if (v != 0) {
            if (v == 3) {
                param_1[0x7e8] = 5;
            } else {
                param_1[0x7e8] = 4;
            }
        }
    }
}

extern "C" void fn_80093234(u8* p) {
    if (fn_8010B734(*(u8**)(p + 0x29c)) == 1) {
        fn_800C55B8(*(u8**)(p + 0x284), *(*(u8**)(p + 0x29c) + 0x9d));
        *(u8*)(p + 0x282e) = 0;
        *(u8*)(p + 0x7e8) = 6;
    }
}

extern "C" void fn_80093290(u8* p) {
    u32 flag = (u8)lbl_802AE880[0x1fa6];
    if ((flag == 0 || flag == 1) && p[0x282e] == 0) {
        fn_800C55B8(*(void**)(p + 0x284), 1);
        fn_8010B64C(*(void**)(p + 0x29c));
        p[0x85c] = 0;
        p[0x7e8] = 1;
        p[0x282c] = 0;
        fn_800A5338(*(void**)(p + 0x268));
    } else {
        fn_8010BAA0(*(void**)(p + 0x29c));
        fn_800C55B8(*(void**)(p + 0x284), (*(u8**)(p + 0x29c))[0x9d]);
        if ((*(u8**)(p + 0x29c))[0x9c] == 1) {
            p[0x7e8] = 7;
        }
        if ((*(u8**)(p + 0x29c))[0x9c] == 2) {
            p[0x282e] = 1;
        }
    }
    lbl_802AE880[0x1fa6] = 2;
}

extern "C" u8 fn_8010B8D4(void* p);
extern "C" void fn_8009336C(char* param_1)
{
    if (fn_8010B8D4(*(void**)(param_1 + 0x29c)) == 1) {
        char* p = *(char**)(param_1 + 0x268);
        p[0x3d2] = 0;
        p[0x3ac] = p[0x3db];
        param_1[0x7e8] = 3;
    }
}

extern "C" u8 lbl_80285DF8[];
extern "C" s32 lbl_802FEBC0;
extern "C" void fn_800933C4(u8* p) {
    u32 flag = (u8)lbl_802AE880[0x1fa6];
    if ((flag == 0 || flag == 1) && lbl_802FEBC0 == 0 && p[0x282e] == 0 && (*(u8**)(p + 0x280))[0x159] == 1) {
        fn_800CA7C4(*(u8**)(p + 0x280));
        *(u16*)(p + 0x2830) = 0xffff;
        p[0x282d] = 0;
        p[0x282c] = 2;
    }
    (((NaviState_8008DC60*)p)->*lbl_8028635C[p[0x282c]])();
    lbl_802AE880[0x1fa6] = 2;
}

extern "C" u32 fn_80016294(void* a, void* b, u32 c, s32 d);
extern "C" void fn_800A5338(void*);
extern "C" void fn_800C6CA4(void*);
extern "C" void fn_800936E0(u8* p) {
    s32 r = fn_80016294(lbl_802AE880, p + 0x883, 0x1fa4, 0);
    if (r != 0) {
        if (r == 1) {
            if (*(u8*)(lbl_802B7CA0 + 0x1372) != 0) {
                *(u8*)(lbl_802B7CA0 + 0x1372) = 0;
            }
            if (p[0x282f] == 0) {
                s32* src = (s32*)(lbl_802AE880 + 0x1fd0);
                s32* dst = (s32*)(lbl_802B7CA0 + 0x1378);
                s32 a = src[0];
                s32 b = src[1];
                dst[0] = a;
                dst[1] = b;
                fn_800A5338(*(void**)(p + 0x268));
                p[0x7e8] = 2;
                p[0x85c] = 1;
            } else {
                fn_800C6CA4(*(void**)(p + 0x27c));
                p[0x2a5] = 2;
                p[0x85c] = 5;
            }
        } else if (r == 2) {
            p[0x282c] = 0;
        }
    }
}

extern "C" void fn_800CA434(void* a, u16 b, s32 c);
extern "C" void fn_800937C0(u8* p) {
    u8* q = *(u8**)(p + 0x280);
    if (q[0x159] == 2) {
        if (*(u16*)(p + 0x2830) != 0xffff) {
            fn_800CA434(q, *(u16*)(p + 0x2830), 0);
        }
        *(u8*)(p + 0x282c) = *(u8*)(p + 0x282d);
    }
}

extern "C" void fn_80093814(u8* p) {
    u8* q = *(u8**)(p + 0x280);
    if (q[0x159] == 2) {
        if (*(u16*)(p + 0x2830) != 0xffff) {
            fn_800CA434(q, *(u16*)(p + 0x2830), 0);
            *(u16*)(p + 0x2830) = 0xffff;
            *(u8*)(p + 0x282c) = 3;
        } else {
            fn_800CA434(q, *(u16*)(p + 0x2832), 0);
            *(u8*)(p + 0x282c) = *(u8*)(p + 0x282d);
        }
    }
}

extern "C" void fn_8009388C(char* param_1) {
    if (*(u8*)(*(char**)(param_1 + 0x280) + 0x159) == 2) {
        fn_800C6CA4(*(void**)(param_1 + 0x27c));
        param_1[0x2a5] = 2;
        param_1[0x85c] = 5;
    }
}

extern "C" void* memset(void* p, s32 c, u32 n);
extern "C" void fn_800F0D04(void* a, void* b, s32 c);
extern "C" void fn_80017248(void* p, s32 v);
extern "C" void fn_800938DC(u8* p) {
    if ((*(u8**)(p + 0x280))[0x159] == 2) {
        if ((u8)((*(u8**)(p + 0x280))[0x158] ^ 1)) {
            memset(p + 0x883, 0, 0x258);
            fn_800F0D04(lbl_802B7CA0, p + 0x883, 0);
            fn_80017248(p + 0x883, 0);
            fn_800F0D04(lbl_802B7CA0, p + 0x883, 1);
            fn_80017248(p + 0x883, 1);
            fn_800F0D04(lbl_802B7CA0, p + 0x883, 2);
            fn_80017248(p + 0x883, 2);
            *(u8*)(lbl_802B7CA0 + 0x1372) = 1;
            fn_800A5338(*(void**)(p + 0x268));
            p[0x7e8] = 2;
            p[0x85c] = 1;
        } else {
            p[0x282c] = 0;
        }
    }
}

extern "C" void fn_800939C8(u8* p) {
    u8* q = *(u8**)(p + 0x280);
    if (q[0x159] == 2) {
        if ((u8)(q[0x158] ^ 1)) {
            fn_800CA434(q, 0x242, 0);
            *(u8*)(p + 0x282c) = 7;
        } else {
            if (*(u8*)(p + 0x282f) == 0) {
                fn_800CA434(q, 0x241, 0);
                *(u8*)(p + 0x282d) = 5;
                *(u16*)(p + 0x2830) = 0x24b;
                *(u8*)(p + 0x282c) = 2;
            } else {
                fn_800CA434(q, 0x252, 0);
                *(u8*)(p + 0x282c) = 4;
            }
        }
    }
}

extern "C" void fn_80016170(void* p);
extern "C" void fn_80093A70(u8* p) {
    u8* q = *(u8**)(p + 0x280);
    if (q[0x159] == 2) {
        if ((u8)(q[0x158] ^ 1)) {
            fn_80016170(lbl_802AE880);
            fn_800CA434(*(u8**)(p + 0x280), 0x243, 1);
            *(u8*)(p + 0x282c) = 8;
            *(u8*)(p + 0x282e) = 1;
        } else {
            if (*(u8*)(p + 0x282f) == 0) {
                fn_800CA434(q, 0x241, 0);
                *(u8*)(p + 0x282d) = 5;
                *(u16*)(p + 0x2830) = 0x24b;
                *(u8*)(p + 0x282c) = 2;
            } else {
                fn_800CA434(q, 0x252, 0);
                *(u8*)(p + 0x282c) = 4;
            }
        }
    }
}

extern "C" void* fn_800164D0(void* p);
extern "C" void fn_80093B30(u8* p) {
    *(s32*)(p + 0x2828) = (s32)fn_800164D0(lbl_802AE880);
    if (*(s32*)(p + 0x2828) != 0) {
        fn_800CA7C4(*(void**)(p + 0x280));
        p[0x282c] = 9;
    }
}

extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" void fn_80093B84(u8* p) {
    u8* q = *(u8**)(p + 0x280);
    if (q[0x159] == 2) {
        if (*(s32*)(p + 0x2828) == 2) {
            *(u16*)(p + 0x2830) = 0xffff;
            p[0x282d] = 0;
            fn_800CA434(*(u8**)(p + 0x280), 0x245, 0);
            p[0x282c] = 2;
        } else if (*(s32*)(p + 0x2828) == 1) {
            fn_8002F458(0xac, 0);
            *(u16*)(p + 0x2830) = 0xffff;
            p[0x282d] = 0;
            fn_800CA434(*(u8**)(p + 0x280), 0x244, 0);
            (*(u8**)(p + 0x280))[0x15f] = 1;
            p[0x282c] = 2;
        }
        p[0x282e] = 0;
        *(u16*)(p + 0x2830) = 0xff;
    }
}

extern "C" void fn_80093D90(u8* p) {
    *(s32*)(p + 0x2828) = (s32)fn_80016320(lbl_802AE880);
    if (*(s32*)(p + 0x2828) != 0) {
        fn_800CA7C4(*(void**)(p + 0x280));
        p[0x282c] = 0xc;
    }
}

extern "C" void fn_800A5338(void* p);
extern "C" void fn_80093F00(u8* p) {
    if (*(u8*)(p + 0x282f) == 0) {
        fn_800A5338(*(void**)(p + 0x268));
        *(u8*)(p + 0x7e8) = 1;
        *(u8*)(p + 0x282c) = 0;
        *(u8*)(p + 0x85c) = 0;
    } else {
        fn_800C6CA4(*(void**)(p + 0x27c));
        *(u8*)(p + 0x2a5) = 1;
        *(u8*)(p + 0x282c) = 0;
        *(u8*)(p + 0x85c) = 0;
    }
}

extern "C" void fn_80093F70(u8* p) {
    u8* q = *(u8**)(p + 0x280);
    if (q[0x159] == 2) {
        if ((u8)(q[0x158] ^ 1)) {
            if (*(u8*)(p + 0x282f) == 0) {
                *(u8*)(p + 0x282c) = 0x10;
            } else {
                fn_800CA434(q, 0x265, 0);
                *(u8*)(p + 0x282c) = 0xf;
            }
        } else {
            if (*(u8*)(p + 0x282f) == 0) {
                fn_800CA434(q, 0x24b, 0);
                *(u8*)(p + 0x282c) = 5;
            } else {
                fn_800C6CA4(*(void**)(p + 0x27c));
                *(u8*)(p + 0x2a5) = 2;
                *(u8*)(p + 0x85c) = 5;
            }
        }
    }
}

extern "C" void fn_80094024(u8* p) {
    u8* q = *(u8**)(p + 0x280);
    if (q[0x159] == 2) {
        if ((u8)(q[0x158] ^ 1)) {
            *(u8*)(p + 0x282c) = 0x10;
        } else {
            fn_800C6CA4(*(void**)(p + 0x27c));
            *(u8*)(p + 0x2a5) = 2;
            *(u8*)(p + 0x85c) = 5;
        }
    }
}

extern "C" void OSResetSystem(int, u32, int);
extern "C" void fn_80094090(void) {
    OSResetSystem(1, 1, 1);
}

extern StateFn_8009287C lbl_80285F58[];
extern "C" void fn_800940BC(Obj_8009287C* param_1) {
    (param_1->*lbl_80285F58[param_1->state])();
}

extern void* lbl_80287ADC[];
extern "C" void* fn_80094284(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287ADC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800942E0(char* param_1) {
    if (fn_800BC784(*(void**)(param_1 + 0x26c)) == 1) {
        param_1[0x7e8] = 2;
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x26c) + 0xe4));
    }
}

extern "C" void fn_800BC984(void*);
extern "C" void fn_80094334(char* param_1) {
    if (*(void**)(param_1 + 0x26c) != nullptr) {
        fn_800BC984(*(void**)(param_1 + 0x26c));
    }
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x26c) + 0xe4));
    s32 x = *(*(u8**)(param_1 + 0x26c) + 0xe1);
    switch (x) {
    case 2:
        param_1[0x7e8] = 5;
        break;
    case 1:
    case 3:
        param_1[0x7e8] = 3;
        break;
    }
}

extern "C" void fn_800943BC(void* p) {
    if (fn_800BC8A4(*(void**)((char*)p + 0x26c))) {
        if (*(unsigned char*)(*(char**)((char*)p + 0x26c) + 0xe1) == 3) {
            *(unsigned char*)((char*)p + 0x7e8) = 0;
            *(unsigned int*)((char*)lbl_802BB0FC + 0x44) = 2;
            *(unsigned char*)((char*)p + 0x85c) = 7;
        } else {
            *(unsigned char*)((char*)p + 0x7e8) = 0;
            *(unsigned char*)((char*)p + 0x2836) = 0;
            *(unsigned int*)((char*)lbl_802BB0FC + 0x44) = 4;
        }
    }
}

extern "C" void fn_80094444(void* ptr) {
    if (((u8*)ptr)[0x85d] != 0) {
        ((u8*)ptr)[0x85d]--;
        return;
    }
    ((u8*)ptr)[0x7e8] = 0;
}

extern "C" void fn_80094468(char* param_1) {
    if (fn_8010B734(*(void**)(param_1 + 0x29c)) == 1) {
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x29c) + 0x9d));
        param_1[0x7e8] = 6;
    }
}

extern "C" void fn_8010BAA0(void* p);
extern "C" void fn_800C55B8(void* p, u8 x);
extern "C" void fn_800944BC(char* param_1) {
    fn_8010BAA0(*(void**)(param_1 + 0x29c));
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x29c) + 0x9d));
    if (*(*(u8**)(param_1 + 0x29c) + 0x9c) == 1) {
        param_1[0x7e8] = 7;
    }
}

extern "C" void fn_80094514(char* param_1) {
    if (fn_8010B8D4(*(void**)(param_1 + 0x29c)) == 1) {
        char* p = *(char**)(param_1 + 0x26c);
        p[0xe1] = 0;
        p[0xd4] = 7;
        param_1[0x7e8] = 2;
    }
}

extern StateFn_8009287C lbl_80285FE8[];
extern "C" void fn_8009456C(Obj_8009287C* param_1) {
    (param_1->*lbl_80285FE8[param_1->state])();
}

extern "C" void fn_800945A4(char* param_1) {
    if (*(void**)(param_1 + 0x278) == 0) {
        void** o = (void**)fn_8015A90C(100);
        if (o != 0) {
            o[0] = lbl_802869B4;
            o[1] = lbl_8027EC78;
            o[1] = lbl_8028C578;
        }
        *(void***)(param_1 + 0x278) = o;
        *(void**)(*(char**)(param_1 + 0x278) + 0xc) = *(void**)(param_1 + 0x260);
        *(*(u8**)(param_1 + 0x278) + 0x63) = 0;
        fn_800F2CD4(*(void**)(param_1 + 0x278));
    } else {
        *(*(u8**)(param_1 + 0x278) + 0x63) = 0;
        fn_800F3888(*(void**)(param_1 + 0x278));
    }
    fn_800C5548(*(void**)(param_1 + 0x284));
    param_1[0x85c] = 4;
    param_1[0x7e8] = 1;
}

extern void* lbl_8028C578[];
extern "C" void* fn_8009465C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028C578;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800946B8(char* param_1) {
    if (fn_800F39B4(*(void**)(param_1 + 0x278)) == 1) {
        param_1[0x7e8] = 2;
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x278) + 0x62));
    }
}

extern "C" void fn_8009470C(char* param_1) {
    if (*(void**)(param_1 + 0x278) != 0) {
        fn_800F3D84(*(void**)(param_1 + 0x278));
    }
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x278) + 0x62));
    if (*(*(u8**)(param_1 + 0x278) + 0x61) != 0) {
        *(u8*)(param_1 + 0x2837) = *(*(u8**)(param_1 + 0x278) + 0x58) ^ 1;
        param_1[0x7e8] = 3;
    }
}

extern "C" u8 fn_800F3C58(void* p);
extern "C" void fn_80094778(void* p) {
    if (fn_800F3C58(*(void**)((char*)p + 0x278))) {
        if (*(unsigned char*)(*(char**)((char*)p + 0x278) + 0x61) == 2) {
            *(unsigned char*)((char*)p + 0x7e8) = 0;
            *(unsigned int*)((char*)lbl_802BB0FC + 0x44) = 2;
            *(unsigned char*)((char*)p + 0x85c) = 7;
        } else {
            *(unsigned char*)((char*)p + 0x2836) = 1;
            if ((unsigned char)(*(unsigned char*)(*(char**)((char*)p + 0x278) + 0x58) ^ 1)) {
                *(unsigned char*)((char*)p + 0x7e8) = 0;
                *(unsigned char*)((char*)p + 0x2835) = 0;
                *(unsigned int*)((char*)lbl_802BB0FC + 0x44) = 5;
                *(unsigned char*)((char*)p + 0x85c) = 7;
            } else {
                *(unsigned char*)((char*)p + 0x7e8) = 0;
                *(unsigned char*)((char*)p + 0x85c) = 2;
                *(unsigned int*)((char*)lbl_802BB0FC + 0x44) = 4;
            }
        }
    }
}

extern void* lbl_80287888[];
extern "C" void* fn_80094AFC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287888;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern StateFn_8009287C lbl_80286054[];
extern "C" void fn_80094C90(Obj_8009287C* param_1) {
    (param_1->*lbl_80286054[param_1->state])();
}

extern "C" void fn_80094CC8(char* param_1) {
    if (fn_8010B734(*(void**)(param_1 + 0x29c)) == 1) {
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x29c) + 0x9d));
        param_1[0x7e8] = 3;
    }
}

extern "C" void fn_80094D1C(char* param_1) {
    fn_8010BAA0(*(void**)(param_1 + 0x29c));
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x29c) + 0x9d));
    if (*(*(u8**)(param_1 + 0x29c) + 0x9c) == 1) {
        param_1[0x7e8] = 4;
    }
}

extern "C" void fn_80094D74(char* param_1) {
    if (fn_8010B8D4(*(void**)(param_1 + 0x29c)) == 1) {
        char* p = *(char**)(param_1 + 0x270);
        p[0x3a1] = 0;
        *(s32*)(p + 0x378) = 9;
        param_1[0x7e8] = 1;
    }
}

extern StateFn_8009287C lbl_802860CC[];
extern "C" void fn_80094DCC(Obj_8009287C* param_1) {
    (param_1->*lbl_802860CC[param_1->state])();
}

extern "C" void fn_80094E04(u8* p) {
    void** o;
    if (*(void**)(p + 0x274) == 0) {
        o = (void**)fn_8015A90C(0x52c);
        if (o != 0) {
            o[0] = lbl_80286A98;
            o[2] = lbl_8027EC78;
            o[2] = lbl_8028E870;
            o[4] = lbl_8027EC78;
            o[4] = lbl_8028E870;
            o[6] = lbl_8027EC78;
            o[6] = lbl_8028E870;
            o[8] = lbl_8027EC78;
            o[8] = lbl_8028E870;
            o[10] = lbl_8027EC78;
            o[10] = lbl_8028E870;
            o[12] = lbl_8027EC78;
            o[12] = lbl_8028E870;
            o[14] = lbl_8027EC78;
            o[14] = lbl_8028E870;
            o[16] = lbl_8027EC78;
            o[16] = lbl_8028E870;
            o[18] = lbl_8027EC78;
            o[18] = lbl_8028E870;
            o[20] = lbl_8027EC78;
            o[20] = lbl_8028E870;
            o[22] = lbl_8027EC78;
            o[22] = lbl_8028E870;
        }
        *(void***)(p + 0x274) = o;
        *(void**)(*(u8**)(p + 0x274) + 0x60) = *(void**)(p + 0x260);
        (*(u8**)(p + 0x274))[0x52a] = p[0x2835];
        fn_800F4C70(*(void**)(p + 0x274));
    }
    p[0x7e8] = 1;
}

extern void* lbl_8028E870[];
extern "C" void* fn_80094EE8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028E870;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80094F44(char* param_1) {
    if (fn_800FFBBC(*(void**)(param_1 + 0x274)) == 1) {
        param_1[0x7e8] = 2;
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x274) + 0xf2));
    }
}

extern "C" void fn_80094F98(char* param_1) {
    if (*(void**)(param_1 + 0x274) != 0) {
        fn_800FFBCC(*(void**)(param_1 + 0x274));
    }
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x274) + 0xf2));
    if (*(*(u8**)(param_1 + 0x274) + 0xf1) == 1) {
        param_1[0x7e8] = 3;
    }
}

extern "C" void fn_80094FF8(char* param_1) {
    if (fn_800FFBC4(*(void**)(param_1 + 0x274)) == 1) {
        fn_80109960(*(void**)(param_1 + 0x274));
        DtorVObj_800A0008* o = *(DtorVObj_800A0008**)(param_1 + 0x274);
        if (o != 0) {
            o->Destroy(1);
        }
        *(void**)(param_1 + 0x274) = 0;
        param_1[0x7e8] = 0;
        param_1[0x85c] = 2;
        *(s32*)(lbl_802BB0FC + 0x44) = 4;
    }
}

extern "C" void fn_80095080(void) {}

extern StateFn_8009287C lbl_80286144[];
extern "C" void fn_80095084(Obj_8009287C* param_1) {
    (param_1->*lbl_80286144[param_1->state])();
}

extern "C" void fn_800950BC(char* param_1) {
    if (*(void**)(param_1 + 0x278) == 0) {
        void** o = (void**)fn_8015A90C(100);
        if (o != 0) {
            o[0] = lbl_802869B4;
            o[1] = lbl_8027EC78;
            o[1] = lbl_8028C578;
        }
        *(void***)(param_1 + 0x278) = o;
        *(void**)(*(char**)(param_1 + 0x278) + 0xc) = *(void**)(param_1 + 0x260);
        *(*(u8**)(param_1 + 0x278) + 0x63) = 1;
        fn_800F2CD4(*(void**)(param_1 + 0x278));
    } else {
        *(*(u8**)(param_1 + 0x278) + 0x63) = 1;
        fn_800F3888(*(void**)(param_1 + 0x278));
    }
    param_1[0x85c] = 4;
    param_1[0x7e8] = 1;
}

extern "C" void fn_8009516C(char* param_1) {
    if (fn_800F39B4(*(void**)(param_1 + 0x278)) == 1) {
        param_1[0x7e8] = 2;
        fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x278) + 0x62));
    }
}

extern "C" void fn_800951C0(char* param_1) {
    if (*(void**)(param_1 + 0x278) != 0) {
        fn_800F3D84(*(void**)(param_1 + 0x278));
    }
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x278) + 0x62));
    if (*(*(u8**)(param_1 + 0x278) + 0x61) != 0) {
        param_1[0x7e8] = 3;
    }
}

extern "C" void* fn_800954A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)(ptr))[1] = lbl_8028C578;
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

extern "C" void* fn_8009551C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80283F48[];
extern "C" void* fn_80095590(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)(ptr))[1] = lbl_80287ADC;
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

extern "C" void fn_80095604(void* ptr) {
    if (((u8*)ptr)[0x85d] != 0) {
        ((u8*)ptr)[0x85d]--;
        return;
    }
    ((u8*)ptr)[0x7e8] = 0;
}

extern StateFn_8009287C lbl_802861BC[];
extern "C" void fn_80095628(Obj_8009287C* param_1) {
    (param_1->*lbl_802861BC[param_1->state])();
}

extern void* lbl_80289A14[];
extern "C" void* fn_800957BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80289A14;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_80095E00(u8* p, u8* c) {
    u8 a, b;
    a = c[0];
    b = c[1];
    p[0x148] = a;
    a = c[2];
    p[0x149] = b;
    b = c[3];
    p[0x14a] = a;
    p[0x14b] = b;
    return 1;
}

extern "C" u8 fn_800D4FCC(void* p);
extern "C" void fn_800D6C70(void* p);
extern "C" void fn_800C57A8(void* p);
extern "C" void fn_80095F38(u8* p) {
    if (fn_800D4FCC(*(void**)(p + 0x28c)) == 1) {
        if (*(void**)(p + 0x28c) != 0) {
            fn_800D6C70(*(void**)(p + 0x28c));
            DtorVObj_800A0008* o = *(DtorVObj_800A0008**)(p + 0x28c);
            if (o != 0) {
                o->Destroy(1);
            }
            *(void**)(p + 0x28c) = 0;
        }
        if (*(void**)(p + 0x284) != 0) {
            fn_800C57A8(*(void**)(p + 0x284));
            DtorVObj_800A0008* o = *(DtorVObj_800A0008**)(p + 0x284);
            if (o != 0) {
                o->Destroy(1);
            }
            *(void**)(p + 0x284) = 0;
        }
        p[0x7e8] = 4;
    }
}

extern "C" void fn_80095FEC(void) {}

extern void* lbl_8028B750[];
extern "C" void* fn_8009672C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B750;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80096788(char* param_1) {
    fn_800E29CC(*(void**)(param_1 + 0x290));
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x290) + 0xb11));
    if (*(*(u8**)(param_1 + 0x290) + 0xb10) != 0) {
        param_1[0x2a4] = 1;
    }
}

extern "C" void fn_800967E0(void) {}

extern StateFn_8009287C lbl_802862A8[];
extern "C" void fn_800967E4(Obj_8009287C* param_1) {
    (param_1->*lbl_802862A8[param_1->state])();
}

extern void* lbl_802880BC[];
extern "C" void* fn_80096950(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802880BC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800969AC(u8* p) {
    fn_800C1278(*(void**)(p + 0x294));
    fn_800C55B8(*(void**)(p + 0x284), ((u8*)*(void**)(p + 0x294))[0x222]);
    if (((u8*)*(void**)(p + 0x294))[0x21d] != 0) {
        fn_800C3EE8();
        DtorVObj_800A0008* o = *(DtorVObj_800A0008**)(p + 0x294);
        if (o != 0) {
            o->Destroy(1);
        }
        *(void**)(p + 0x294) = 0;
        p[0x7e8] = 2;
        p[0x85c] = 7;
    }
}

extern "C" void fn_80096A38(void) {}

extern "C" void fn_80096A3C(NaviState_8009E6F0* p) {
    (p->*lbl_802862F0[((u8*)p)[0x2a6]])();
}

extern "C" void fn_80096A74(u8* p) {
    if (*(void**)(p + 0x2a0) == 0) {
        void** o = (void**)fn_8015A90C(0x120);
        if (o != 0) {
            o[0] = lbl_80286B1C;
            o[2] = lbl_8027EC78;
            o[2] = lbl_8028F164;
        }
        *(void***)(p + 0x2a0) = o;
        *(void**)(*(u8**)(p + 0x2a0) + 0x10) = *(void**)(p + 0x260);
        fn_8011093C(*(void**)(p + 0x2a0));
    }
    p[0x2a6] = 1;
}

extern void* lbl_8028F164[];
extern "C" void* fn_80096AFC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F164;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80111170(u8* p);
extern "C" void fn_80096B58(u8* p) {
    fn_80111170(*(u8**)(p + 0x2a0));
    if (*(u8*)(*(u8**)(p + 0x2a0) + 0x11e)) {
        *(s32*)(lbl_802BB0FC + 0x44) = 0x13;
        *(u8*)(p + 0x2a6) = 2;
    }
}

extern "C" void fn_80096BB0(void) {}

extern "C" void fn_80096BB4(u8* p) {
    (((NaviState_8008DC60*)p)->*lbl_8028635C[p[0x2a5]])();
    void* v = *(void**)(p + 0x280);
    if (v != 0) {
        fn_800CAB58(v);
    }
}

extern void* lbl_802886F8[];
extern "C" void* fn_80096D8C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802886F8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80096DE8(u8* p) {
    if (fn_80096F0C(p) == 1) {
        if (fn_800C6E38(*(void**)(p + 0x27c)) == 1) {
            fn_800C55B8(*(void**)(p + 0x284), *(*(u8**)(p + 0x27c) + 0x8d));
            p[0x2a5] = 3;
        }
    }
}

extern "C" void fn_800C719C(void* p);
extern "C" void fn_80096E48(char* param_1) {
    fn_800C719C(*(void**)(param_1 + 0x27c));
    fn_800C55B8(*(void**)(param_1 + 0x284), *(*(u8**)(param_1 + 0x27c) + 0x8d));
    if (*(*(u8**)(param_1 + 0x27c) + 0x8c) != 0) {
        param_1[0x2a5] = 4;
    }
}

extern "C" void fn_80096EA0(u8* p) {
    if (fn_800C6FD4(*(void**)(p + 0x27c))) {
        switch (*(*(u8**)(p + 0x27c) + 0x8c)) {
            case 2:
                p[0x282f] = 1;
                p[0x282c] = 0;
                p[0x85c] = 0;
                p[0x2a5] = 1;
                break;
            default:
                break;
        }
    }
}

extern "C" void fn_80096F08(void) {}

extern "C" void fn_8009702C(NaviState_8009E6F0* p) {
    (p->*lbl_802863BC[((u8*)p)[0x86d]])();
}

extern "C" void fn_80097064(u8* p) {
    if (*(void**)(p + 0x298) == 0) {
        void** o = (void**)fn_8015A90C(0x30);
        if (o != 0) {
            o[0] = lbl_8028699C;
            o[2] = lbl_8027EC78;
            o[2] = lbl_80288988;
        }
        *(void***)(p + 0x298) = o;
        *(void**)(*(u8**)(p + 0x298) + 0x10) = *(void**)(p + 0x260);
        fn_800CBB28(*(void**)(p + 0x298));
    }
    fn_800EF4D0(*(void**)(p + 0x288), 2);
    p[0x86d] = 1;
}

extern void* lbl_80288988[];
extern "C" void* fn_800970F8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288988;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800CBF78(void* p);
extern "C" void fn_80097154(u8* self) {
    void* p = *(void**)(self + 0x298);
    if (p != NULL) {
        fn_800CBF78(p);
    }
}

extern "C" void fn_80097EB0(u8* p, s32 idx, s16 x, s16 y);
extern "C" void fn_80097DE8(u8* p) {
    s32 i;
    char* tbl = lbl_802BB0FC;
    u8* self = p;
    if (*(s32*)(tbl + 0x44) != 0xa) {
        for (i = 0; i < 0xa; i++) {
            char* e = tbl + (i % 10) * 0xc;
            u16* flag = (u16*)(e + 0x2dc);
            if (*flag & 2) {
                *flag = *flag & ~2;
                if (*(u8*)(e + 0x2de) >= *(s32*)(tbl + 0x3f0)) {
                    fn_80097EB0(self, i, *(s16*)(e + 0x2d8), *(s16*)(e + 0x2da));
                }
            }
        }
    }
}

extern "C" void fn_80097EB0(u8* p, s32 idx, s16 x, s16 y) {
    s16 pos[2];
    u8* obj;
    pos[0] = x;
    pos[1] = y;
    if (fn_8009D0D8(pos) != 0) {
        obj = ((NaviObjTbl_80097EB0*)p)->objs[idx];
        if (obj[0xb2] != 0x78) {
            (*(void (***)(u8*, s32))obj)[9](obj, 0x78);
        }
    } else {
        obj = ((NaviObjTbl_80097EB0*)p)->objs[idx];
        if (obj[0xb2] != 0xff) {
            (*(void (***)(u8*, s32))obj)[9](obj, 0xff);
        }
    }
    pos[0] -= 0xe00;
    pos[1] -= 0x2c00;
    *(s16*)(lbl_802BB0FC + idx * 0xc + 0x2d4) = pos[0];
    *(s16*)(lbl_802BB0FC + idx * 0xc + 0x2d6) = pos[1];
}

extern "C" void fn_80098354(char* param_1) {
    if (*(void**)(param_1 + 0xec) != nullptr) {
        VObj_80098354* obj = (VObj_80098354*)param_1;
        obj->v15(*(f32*)(param_1 + 0xd4), *(f32*)(param_1 + 0xd8));
    }
}

extern "C" void fn_80098394(char* param_1, f32 param_2, f32 param_3) {
    VObj_80098354* obj = (VObj_80098354*)param_1;
    obj->v16(param_2, param_3, -*(f32*)(param_1 + 0x20), -*(f32*)(param_1 + 0x24));
}

extern "C" void fn_80098908(u8* p) {
    p[0x7b4] = 0;
    p[0x7b5] = 0;
}

extern "C" void fn_80098918(char* param_1) {
    if (*(s32*)(lbl_802BB0FC + 0x44) == 0xc && *(u8*)(param_1 + 0x7b2) == 0) {
        char* p = lbl_802C545C;
        f32 t = fn_800A1774(param_1, *(u8*)(p + 0x2c), *(u8*)(param_1 + 0x7b4), 2);
        if (*(u8*)(param_1 + 0x7b5) == 0) {
            t = lbl_80300B20 - t;
        }
        VObj_80098918* obj = *(VObj_80098918**)(param_1 + 0x2d0);
        f32 a = *(f32*)(lbl_802C545C + 0x34);
        f32 d = *(f32*)(lbl_802C545C + 0x30) - a;
        d *= t;
        f32 v = a + d;
        *(f32*)((char*)obj + 0xcc) = v;
        *(f32*)((char*)obj + 0xd0) = v;
        obj->v9();
        if (*(u8*)(param_1 + 0x7b4) == 0) {
            *(u8*)(param_1 + 0x7b4) = *(u8*)(p + 0x2c);
            *(u8*)(param_1 + 0x7b5) ^= 1;
        } else {
            *(u8*)(param_1 + 0x7b4) -= 1;
        }
    }
}

extern "C" void fn_80098B00(char* param_1, s32 param_2) {
    if (*(u8*)(param_1 + 0x719) != 0 && ((u16*)((char*)lbl_802BB0FC + 0xe4))[param_2] == 0x253 && *(u8*)(param_1 + 0x71a) == 0) {
        char* p = lbl_802C545C;
        *(u8*)(param_1 + 0x71a) = 1;
        char* obj = *(char**)(param_1 + 0x700);
        f32 d = *(f32*)(obj + 0x28) - *(f32*)(obj + 0x20);
        f32 r = fn_80116064(*(f32*)(p + 0x7c));
        f32 t = d * lbl_80300AFC;
        *(f32*)(param_1 + 0x720) = t + r;
        obj = *(char**)(param_1 + 0x700);
        d = *(f32*)(obj + 0x2c) - *(f32*)(obj + 0x24);
        r = fn_80116064(*(f32*)(p + 0x7c));
        t = d * lbl_80300AFC;
        *(f32*)(param_1 + 0x724) = t + r;
    }
}

extern "C" void fn_8009970C(u8* p, s32 idx) {
    if (*(u16*)(lbl_802BB0FC + 0xe4 + idx * 2) == 0x24d && p[0x754] == 0) {
        p[0x754] = 1;
        *(s32*)(p + 0x750) = 0;
        *(s32*)(p + 0x748) = 0;
        *(u8*)(*(u8**)(p + 0x740) + 0xb0) = 1;
        (*(void (**)(void*, void*, s32))(**(u32**)(p + 0x740) + 0x110))(*(void**)(p + 0x740), *(void**)(lbl_802B7CA0 + 0x21dc), 0);
    }
}

extern "C" void fn_800A1178(void* p, s32 idx);
extern "C" void fn_8009A394(u8* p) {
    u8* q = p;
    s32 i;
    for (i = 0; i < 10; i++) {
        if ((*(u16*)(lbl_802BB0FC + (i % 10) * 12 + 0x2dc) & 1) == 0) {
            if (((u8*)*(void**)(q + 0x64c))[0xb0] != 0) {
                ((u8*)*(void**)(q + 0x64c))[0xb0] = 0;
            }
        } else {
            if (((u8*)*(void**)(q + 0x64c))[0xb0] == 0) {
                ((u8*)*(void**)(q + 0x64c))[0xb0] = 1;
            }
            fn_800A1178(p, i);
        }
        q += 4;
    }
}

extern "C" void fn_8009CCD8();
extern "C" void fn_8009CF80(void* p);
extern "C" void fn_8002F358(void* p, s32 v);
extern "C" void fn_80130974(void* p);
extern "C" void* fn_8015A90C(u32 n);
extern "C" void fn_800CC7B4(void* p);
extern "C" void fn_800CDE98(void* p);
extern "C" void fn_801E0DB8(void* p, void* fn, s32 a, s32 b, s32 c);
extern "C" void* lbl_80285698[];
extern "C" void* lbl_80285708[];
extern "C" void* lbl_80286980[];
extern "C" void* lbl_80288AB4[];
extern "C" void* lbl_8027EC78[];
extern "C" void fn_8009AD78(u8* p) {
    u8* q = p;
    s32 i = 0;
    do {
        if (*(void**)(q + 0x860) != 0) {
            fn_80130974(*(void**)(q + 0x860));
            u8* r = *(u8**)(q + 0x860);
            *(u32*)(r + 0xf4) |= 1;
            *(u32*)(r + 0x24) = 1;
            *(void**)(q + 0x860) = 0;
        }
        i++;
        q += 4;
    } while (i < 2);
}

extern "C" s32 fn_8009B574(void);
extern "C" s32 fn_8009B220(void* p);
extern "C" s32 fn_8009B8B4(void* p);
extern "C" void fn_8009B154(u8* p) {
    s32 a = fn_8009B574();
    s32 b = fn_8009B220(p);
    a = b | a;
    unsigned c = fn_8009B8B4(p);
    if ((c | a) != 0) {
        if (p[0x718] == 0) {
            void* obj = *(void**)(p + 0x700);
            ((void (*)(void*, void*))(*(void***)obj)[25])(obj, *(void**)(p + 0x710));
            *(s32*)(p + 0x714) = 0;
            p[0x718] = 1;
        }
    } else {
        if (p[0x718] == 1) {
            *(s32*)(p + 0x714) = 0;
            *(f32*)(*(u8**)(p + 0x710) + 8) = (f32)*(s32*)(p + 0x714);
            p[0x718] = 0;
        }
    }
}

extern "C" void fn_8009C1A0(void* p) {
    *(u8*)((u8*)p + 0x7ba) = ((u8*)lbl_802C545C)[0x39];
    *(u8*)((u8*)p + 0x7bb) = 0;
}

extern "C" void fn_8009C1BC(u8* p) {
    if (p[0x7bc] != 0) {
        char* q = lbl_802C545C;
        f32 t = fn_800A1774(p, q[0x39], p[0x7ba], 2);
        if (p[0x7bb] == 0) {
            t = lbl_80300B20 - t;
        }
        s32 idx = *(s32*)(lbl_802BB0FC + 0x3f0) % 10;
        f32 a = *(f32*)(lbl_802C545C + 0x40);
        f32 d = *(f32*)(lbl_802C545C + 0x3c) - a;
        d *= t;
        f32 v = a + d;
        VObj_80098918* obj = (VObj_80098918*)((NaviObjTbl_80097EB0*)p)->objs[idx];
        *(f32*)((char*)obj + 0xcc) = v;
        *(f32*)((char*)obj + 0xd0) = v;
        obj->v9();
        if (p[0x7ba] == 0) {
            p[0x7ba] = q[0x39];
            p[0x7bb] ^= 1;
        } else {
            p[0x7ba] -= 1;
        }
    }
}

extern "C" void fn_8009C6A4(u8* p, u8 v) {
    void* o = *(void**)(p + 0x554);
    ((void (*)(void*, void*, s32))(*(void***)o)[0x114 / 4])(o, ((void**)lbl_80285698)[v / 10], 0);
    o = *(void**)(p + 0x558);
    ((void (*)(void*, void*, s32))(*(void***)o)[0x114 / 4])(o, ((void**)lbl_80285698)[v % 10], 0);
}

extern "C" void fn_8009CC30(u8* p) {
    if (p[0x7b2] != 0) {
        u32 n = *(u16*)(p + 0x7ae);
        if (n != 0) {
            n--;
            *(u16*)(p + 0x7ae) = n;
            if (*(u16*)(p + 0x7ae) == p[0x882]) {
                fn_8002F358(((void**)lbl_80285708)[p[0x7b1] - 1], 0);
            }
        } else {
            p[0x7b4] = 0;
            p[0x7b5] = 0;
            fn_8009CCD8();
            fn_8009CF80(p);
            if (p[0x7b8] != 0) {
                p[0x7bc] = 1;
            }
        }
    }
}

extern f32 lbl_80300B30;
extern "C" s32 fn_800A1488(void* p, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h);
extern "C" void fn_8017A4F8(void* p);
extern char lbl_801FDAF8[];
extern "C" s32 fn_8009D0D8(s16* param_1) {
    s32 uVar3 = 0;
    u8 mode = *(u8*)(lbl_802B7CA0 + 0x1419);
    if ((u8)lbl_801FDAF8[mode] != 0) {
        s16 sVar1 = param_1[0];
        s32 xHi = sVar1 >> 8;
        s32 yHi = param_1[1] >> 8;
        if (mode == 8) {
            if (xHi == 0xe && yHi == 0x2c) {
                uVar3 = 1;
                param_1[0] = sVar1 + 0x250;
                param_1[1] = param_1[1] + 0x120;
            }
            if (((xHi & 0xfe) == 0x12) && yHi == 0x2c) {
                uVar3 = 1;
                param_1[0] = param_1[0] + -0x1f0;
                param_1[1] = param_1[1] + 0x210;
            }
        } else if (yHi >= 0x31) {
            uVar3 = 1;
            param_1[0] = sVar1 + 0x30;
            param_1[1] = param_1[1] + -0x370;
        }
    }
    return uVar3;
}

extern "C" void fn_8009D2F0(u8* p) {
    if (((u8*)lbl_802BB0FC)[0xee] != 0) {
        if (p[0x70c] != 0) {
            *(s32*)(p + 0x708) = *(s32*)(p + 0x708) + 1;
            s16 sVar1 = *(s16*)(*(u8**)(p + 0x704) + 6);
            if (*(s32*)(p + 0x708) >= sVar1) {
                *(s32*)(p + 0x708) = *(s32*)(p + 0x708) - sVar1;
            }
            *(f32*)(*(u8**)(p + 0x704) + 8) = (f32)*(s32*)(p + 0x708);
        }
        if (p[0x718] != 0) {
            *(s32*)(p + 0x714) = *(s32*)(p + 0x714) + 1;
            s16 sVar1 = *(s16*)(*(u8**)(p + 0x710) + 6);
            if (*(s32*)(p + 0x714) >= sVar1) {
                *(s32*)(p + 0x714) = *(s32*)(p + 0x714) - sVar1;
            }
            *(f32*)(*(u8**)(p + 0x710) + 8) = (f32)*(s32*)(p + 0x714);
        }
        fn_8017A4F8(*(void**)(p + 0x250));
    }
}

extern "C" void fn_8009D3E0(u8* p) {
    s16 sVar1;
    s32 n;
    *(s32*)(p + 0x588) = *(s32*)(p + 0x588) + 1;
    sVar1 = *(s16*)(*(u8**)(p + 0x584) + 6);
    n = *(s32*)(p + 0x588);
    if (n >= sVar1) {
        *(s32*)(p + 0x588) = n - sVar1;
    }
    *(f32*)(*(u8**)(p + 0x584) + 8) = (f32)*(s32*)(p + 0x588);
    fn_8017A4F8(*(void**)(p + 0x250));
}

extern "C" void fn_8009D454(u8* p) {
    if (*(s32*)(lbl_802BB0FC + 0x44) == 0xc && p[0x754] != 0) {
        s32 n;
        s32 c;
        u8* a;
        (*(s32*)(p + 0x748))++;
        a = *(u8**)(p + 0x744);
        c = *(s32*)(p + 0x748);
        n = *(s16*)(a + 6);
        if (c >= n) {
            *(s32*)(p + 0x748) = n;
            p[0x754] = 0;
            *(*(u8**)(p + 0x740) + 0xb0) = 0;
        }
        *(f32*)(*(u8**)(p + 0x744) + 8) = *(s32*)(p + 0x748);
        (*(s32*)(p + 0x750))++;
        a = *(u8**)(p + 0x74c);
        c = *(s32*)(p + 0x750);
        n = *(s16*)(a + 6);
        if (c >= n) {
            *(s32*)(p + 0x750) = c - n;
        }
        *(f32*)(*(u8**)(p + 0x74c) + 8) = *(s32*)(p + 0x750);
        fn_8017A4F8(*(void**)(p + 0x250));
    }
}

extern "C" void fn_8009D544(char* p) {
    s8 s = p[0x7e0];
    if (s != -1) {
        fn_801E10DC(p, lbl_802864E4 + s * 12);
    }
}

extern "C" void fn_8009D784(u8* p) {
    f32 k = lbl_80300B30;
    u8* q = (u8*)lbl_802C545C;
    s32 r = fn_800A1488(p, *(s16*)(p + 0x7fa), q[0x64], 1, 0, *(f32*)(q + 0x68), k, *(f32*)(p + 0x7e4), *(f32*)(p + 0x7e4));
    (*(s16*)(p + 0x7fa))++;
    if (r == 1) {
        *(s16*)(p + 0x7fa) = 0;
        *(s8*)(p + 0x7e0) = -1;
    }
}

extern "C" void fn_8009D7FC(u8* p) {
    f32 k = lbl_80300B30;
    u8* q = (u8*)lbl_802C545C;
    s32 r = fn_800A1488(p, *(s16*)(p + 0x7fa), q[0x64], 0, 1, k, *(f32*)(q + 0x68), *(f32*)(p + 0x7e4), *(f32*)(p + 0x7e4));
    (*(s16*)(p + 0x7fa))++;
    if (r == 1) {
        *(u8*)(*(u8**)(p + 0x338) + 0xb0) = 0;
        *(s16*)(p + 0x7fa) = 0;
        *(s8*)(p + 0x7e0) = -1;
    }
}

extern "C" void fn_8009DE7C(void* param_1) {
    if (*(s32*)(lbl_802BB0FC + 0x424) == 2) {
        return;
    }
    *((u8*)param_1 + 0x7e0) = 8;
}

extern "C" void fn_8009E6F0(NaviState_8009E6F0* p);
extern "C" void fn_8009EBA0(NaviState_8009E6F0* p);
extern "C" void fn_8009F01C(NaviState_8009E6F0* p);
extern "C" void fn_8009F440(NaviState_8009E6F0* p);
extern "C" void fn_8009E640(NaviState_8009E6F0* p) {
    if (!(lbl_802FEDD8 & 1)) {
        if (((u8*)p)[0x800] != 0) {
            ((u8*)p)[0x800] = 2;
        } else {
            return;
        }
    }
    if ((lbl_802FEDD8 & 2) && ((u8*)p)[0x800] != 0) {
        ((u8*)p)[0x800] = 2;
    }
    switch (lbl_802FEDE4) {
    case 0:
    case 1:
        fn_8009E6F0(p);
        break;
    case 2:
    case 3:
        fn_8009EBA0(p);
        break;
    case 4:
        fn_8009F01C(p);
        break;
    case 5:
        fn_8009F440(p);
        break;
    }
}

extern "C" void fn_8009E6F0(NaviState_8009E6F0* p) {
    (p->*lbl_802865A4[((u8*)p)[0x800]])();
}

extern "C" void fn_8009E960(void) {
}

extern "C" void fn_8009EAD4(void) {
}

extern "C" void fn_8009EAD8(u8* p) {
    *(u8*)(p + 0x85d) = ((u8*)lbl_802C545C)[0x5a];
    fn_8006F0F4();
    p[0x7fe] = 1;
    p[0x800] = 5;
}

extern "C" void fn_8009EB24(u8* p) {
    if ((lbl_802FEDD8 & 4) == 0) {
        return;
    }
    p[0x7fe] = 0;
    s32 idx = *(s32*)((u8*)lbl_802BB0FC + 0x3f0);
    *(u16*)((u8*)lbl_802BB0FC + ((idx % 10) % 10) * 12 + 0x2dc) |= 1;
    p[0x7ff] = 0;
    p[0x800] = 1;
}

extern NaviStateFunc_8009E6F0 lbl_8028661C[];
extern "C" void fn_8009EBA0(NaviState_8009E6F0* p) {
    (p->*lbl_8028661C[((u8*)p)[0x800]])();
}

extern "C" void fn_8009EBD8(u8* p)
{
    *(s32*)(p + 0x798) = 0;
    *(u8*)(p + 0x800) = 3;
}

extern "C" void fn_8009EE18(u8* p) {
    *(u8*)(*(u8**)(p + 0x780) + 0xb0) = 0;
    p[0x800] = 0;
}

extern NaviStateFunc_8009E6F0 lbl_80286694[];
extern "C" void fn_8009F01C(NaviState_8009E6F0* p) {
    (p->*lbl_80286694[((u8*)p)[0x800]])();
}

extern "C" void fn_8009F2D4(u8* p) {
    if (p[0x85d] != 0) {
        p[0x85d]--;
        return;
    }
    p[0x800] = 4;
}

extern "C" void fn_8009F2F8(void) {}

extern "C" void fn_8009F43C(void) {}

extern NaviStateFunc_8009E6F0 lbl_8028673C[];
extern "C" void fn_8009F440(NaviState_8009E6F0* p) {
    (p->*lbl_8028673C[((u8*)p)[0x800]])();
}

extern "C" void fn_8009F478(u8* p) {
    s32 idx;
    s32 i;
    u8* obj;
    if (p[0x7bc] == 1) {
        p[0x7bc] = 0;
    }
    i = 0;
    idx = *(s32*)(lbl_802BB0FC + 0x3f0) % 10;
    p[0x79c] = idx;
    do {
        obj = *(u8**)(p + idx * 4 + 0x64c);
        ((VObj_8009F478*)obj)->v4(lbl_80300B40, lbl_80300B40);
        fn_800A1178(p, idx);
        i++;
        idx = (idx + 1) % 10;
    } while (i < 5);
    p[0x800] = 4;
}

extern "C" void fn_80177C20(void* p, f32 v);
extern "C" void fn_8009F560(u8* p) {
    u8* q = p;
    s32 i = 0;
    s32 idx = *(s32*)(lbl_802BB0FC + 0x3f0) % 10;
    for (i = 0; i < 5; i++) {
        fn_80177C20(*(void**)(p + idx * 4 + 0x64c), *(f32*)(q + 0x808));
        idx = (idx + 1) % 10;
        *(f32*)(q + 0x808) = *(f32*)(q + 0x808) + *(f32*)(q + 0x830);
        q += 4;
    }
}

extern "C" void fn_8009FBB0(void) {}

struct NaviState_8008DC60;
typedef void (NaviState_8008DC60::*NaviStateFn_8008DC60)();
extern NaviStateFn_8008DC60 lbl_802867B4[];
extern "C" void fn_8009FBB4(NaviState_8008DC60* p) {
    (p->*lbl_802867B4[((u8*)p)[0x2b4]])();
}

extern "C" void fn_8009FBEC(u8* p) {
    if (*(void**)(p + 0x2b0) == 0) {
        void** o = (void**)fn_8015A90C(0xa0);
        if (o != 0) {
            o[0] = lbl_80286980;
            o[2] = lbl_8027EC78;
            o[2] = lbl_80288AB4;
            ((s32*)o)[0x23] = -1;
            ((s32*)o)[0x24] = -1;
        }
        *(void***)(p + 0x2b0) = o;
        *(void**)(*(u8**)(p + 0x2b0) + 0x10) = *(void**)(p + 0x260);
        fn_800CC7B4(*(void**)(p + 0x2b0));
    }
    p[0x7e0] = 3;
    p[0x2b4] = 1;
}

extern void* lbl_80288AB4[];
extern "C" void* fn_8009FC88(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288AB4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800CCFEC(u8* self);
extern "C" void fn_8009FCE4(u8* p) {
    fn_800CCFEC(*(u8**)(p + 0x2b0));
    if (*(u8*)(*(u8**)(p + 0x2b0) + 0x9f)) {
        *(u8*)(p + 0x2b4) = 2;
    }
}

extern "C" void fn_800CDA38(void);
extern "C" void fn_8009FD2C(u8* p) {
    DtorVObj_800A0008* o = *(DtorVObj_800A0008**)(p + 0x2b0);
    if (o != 0) {
        fn_800CDA38();
        o = *(DtorVObj_800A0008**)(p + 0x2b0);
        if (o != 0) {
            o->Destroy(1);
        }
        *(void**)(p + 0x2b0) = 0;
    }
    if (*(s32*)(lbl_802BB0FC + 0x44) == 0xd) {
        *(u8*)(p + 0x7e0) = 6;
    } else {
        *(u8*)(p + 0x7e0) = 5;
    }
    *(u8*)(p + 0x2b4) = 3;
}

extern "C" void* fn_8009FDBC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8009FE30(void* param_1) {
    if (*(s32*)(lbl_802BB0FC + 0xf4) != 0x31) {
        return;
    }
    *((u8*)param_1 + 0x2b4) = 0;
}

struct NaviState_8009FE50;
typedef void (NaviState_8009FE50::*NaviStateFn_8009FE50)();
extern NaviStateFn_8009FE50 lbl_80286814[];
extern NaviStateFn_8009FE50 lbl_80286874[];
extern "C" void fn_8009FE50(NaviState_8009FE50* p) {
    (p->*lbl_80286814[((u8*)p)[0x2ac]])();
}

extern "C" void fn_8009FE88(u8* p) {
    if (*(void**)(p + 0x2a8) == 0) {
        void** o = (void**)fn_8015A90C(0x294);
        if (o != 0) {
            o[0] = lbl_80286964;
            o[2] = lbl_8027EC78;
            o[2] = lbl_80289110;
            fn_801E0DB8(o + 0x6b, (void*)fn_80092F7C, 0, 4, 0x14);
            fn_801E0DB8(o + 0x7f, (void*)fn_80092F7C, 0, 4, 0x14);
        }
        *(void***)(p + 0x2a8) = o;
        *(void**)(*(u8**)(p + 0x2a8) + 0x10) = *(void**)(p + 0x260);
        fn_800CDE98(*(void**)(p + 0x2a8));
    }
    (*(u8**)(p + 0x2a8))[0x28f] = p[0x2ad];
    p[0x7e0] = 3;
    p[0x2ac] = 1;
}

extern void* lbl_80289110[];
extern "C" void* fn_8009FF64(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80289110;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800CF138(u8* p);
extern "C" void fn_8009FFC0(u8* p) {
    fn_800CF138(*(u8**)(p + 0x2a8));
    if (*(u8*)(*(u8**)(p + 0x2a8) + 0x290)) {
        *(u8*)(p + 0x2ac) = 2;
    }
}

extern "C" void fn_800D044C(void*);
extern "C" void fn_800A0008(char* p) {
    if (*(void**)(p + 0x2a8) != 0) {
        fn_800D044C(*(void**)(p + 0x2a8));
        DtorVObj_800A0008* o = *(DtorVObj_800A0008**)(p + 0x2a8);
        if (o != 0) {
            o->Destroy(1);
        }
        *(void**)(p + 0x2a8) = 0;
    }
    if (*(s32*)(lbl_802BB0FC + 0x44) == 0xd) {
        *(u8*)(p + 0x7e0) = 6;
    } else {
        *(u8*)(p + 0x7e0) = 5;
    }
    *(u8*)(p + 0x2ac) = 3;
}

extern "C" void* fn_800A0098(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800A010C(void* p) {
    s32 v = *(s32*)(lbl_802BB0FC + 0xf4);
    if (v != 0x42) {
        return;
    }
    *(u8*)((u8*)p + 0x2ad) = v;
    *(u8*)((u8*)p + 0x2ac) = 0;
}

extern "C" void fn_800A0130(NaviState_8009FE50* p) {
    (p->*lbl_80286874[((u8*)p)[0x2bc]])();
}

extern "C" void fn_800A0168(u8* p) {
    if (*(void**)(p + 0x2b8) == 0) {
        void** o = (void**)fn_8015A90C(0x288);
        if (o != 0) {
            void** q = o;
            q[0] = lbl_80286948;
            q[2] = lbl_8027EC78;
            o[2] = lbl_802893EC;
            fn_801E0DB8(o + 0x29, (void*)fn_80092F7C, 0, 4, 0x10);
            fn_801E0DB8(o + 0x39, (void*)fn_80092F7C, 0, 4, 0x10);
        }
        *(void***)(p + 0x2b8) = o;
        *(void**)(*(u8**)(p + 0x2b8) + 0x10) = *(void**)(p + 0x260);
        fn_800D0910(*(void**)(p + 0x2b8));
    }
    p[0x7e0] = 3;
    p[0x2bc] = 1;
}

extern void* lbl_802893EC[];
extern "C" void* fn_800A0238(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802893EC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800A0294(u8* p) {
    fn_800D1EE8(*(u8**)(p + 0x2b8));
    if (*(u8*)(*(u8**)(p + 0x2b8) + 0x286)) {
        *(u8*)(p + 0x2bc) = 2;
    }
}

extern "C" void fn_800A02DC(char* p) {
    if (*(void**)(p + 0x2b8) != 0) {
        fn_800D3274(*(u8**)(p + 0x2b8));
        DtorVObj_800A0008* o = *(DtorVObj_800A0008**)(p + 0x2b8);
        if (o != 0) {
            o->Destroy(1);
        }
        *(void**)(p + 0x2b8) = 0;
    }
    if (*(s32*)(lbl_802BB0FC + 0x44) == 0xd) {
        *(u8*)(p + 0x7e0) = 6;
    } else {
        *(u8*)(p + 0x7e0) = 5;
    }
    *(u8*)(p + 0x2bc) = 3;
}

extern "C" void* fn_800A036C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288EDC;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288520;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)((unsigned)ptr))[2] = lbl_8027EC78;
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800A03E0(void* param_1) {
    if (*(s32*)(lbl_802BB0FC + 0xf4) != 0x4d) {
        return;
    }
    *((u8*)param_1 + 0x2bc) = 0;
}

extern "C" void fn_800A1748(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((char*)param_1 + 0x25c));
}

#pragma fp_contract off
extern "C" f32 fn_800A1774(void* unused, s32 param_1, s32 param_2, u8 param_3)
{
    f32 t;
    f32 result;
    if (param_1 <= 0) {
        return lbl_80300B20;
    }
    if (param_2 < 0) {
        param_2 = 0;
    } else if (param_2 > param_1) {
        param_2 = param_1;
    }
    t = (f32)param_2 / (f32)param_1;
    switch (param_3) {
    case 0:
        result = t * t;
        break;
    case 1:
        result = navi_sqrtf_800A1774(t);
        break;
    default:
        result = t;
        break;
    case 3: {
        f32 threshold = lbl_80300B38;
        f32 bias = lbl_80300B20;
        result = threshold * (threshold * t - bias) - bias;
        break;
    }
    case 4: {
        f32 val = *(f32*)((u8*)lbl_802F0BC0 + (((u32)(s32)(lbl_80300AFC * (lbl_80300B70 * t)) >> 2) & 0x3FF8));
        result = val * val;
        break;
    }
    case 5: {
        f32 val = *(f32*)((u8*)lbl_802F0BC0 + (((u32)(s32)(lbl_80300AFC * (lbl_80300B74 * t)) >> 2) & 0x3FF8));
        result = val * val;
        break;
    }
    }
    return result;
}
#pragma fp_contract reset
extern f32 lbl_80300B20;
extern f64 lbl_80300B00;
extern f64 lbl_80300B58;
extern f64 lbl_80300B60;
extern f32 lbl_80300B38;
extern f64 lbl_80300B68;
extern f32 lbl_80300B70;
extern f32 lbl_80300B74;
extern f32 lbl_80300AFC;
extern f32 lbl_802FEAB0[];
extern f32 lbl_802F0BC0[];


extern "C" void fn_800175B8(void*);
extern "C" void fn_8008DE8C(void*);
extern "C" void fn_800A199C(void* ptr)
{
	if (ptr != nullptr) {
		fn_800175B8(ptr);
		*(void**)((char*)ptr + 0x244) = lbl_8027EC78;
		*(void**)((char*)ptr + 0x244) = lbl_80286928;
		*(void**)((char*)ptr + 0x24c) = lbl_8027EC78;
		*(void**)((char*)ptr + 0x24c) = lbl_80286908;
	}
	fn_8008DE8C(ptr);
}

extern "C" void fn_800A19FC(void) {
    fn_800911F0();
}

extern "C" void fn_800A1A1C(void) {
    fn_80092444();
}

extern "C" void fn_800A1A3C(void) {
    fn_80092228();
}

extern "C" BOOL fn_800A1A5C(void);
extern "C" BOOL fn_800A1A5C(void)
{
    return TRUE;
}

extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern char lbl_802B7CA0[];
extern f32 lbl_80300AF0;
extern "C" void fn_80092228(void);
extern "C" void fn_80092444(void);
extern "C" void fn_800911F0(void);
extern "C" void fn_800A1A64(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300AF0;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void fn_800A1AC8(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300AF0;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" char lbl_802C545C[];
extern "C" char lbl_802BB0FC[];
extern "C" void fn_800A1B2C(s16* a, s16* b) {
    char* p = lbl_802C545C;
    s16 x = (s16)(*(s16*)(p + 0x14) + b[0] * *(f32*)(p + 0xc));
    s16 y = (s16)(*(s16*)(p + 0x16) + b[1] * *(f32*)(p + 0x10));
    a[0] = x;
    b[0] = x;
    b[1] = y;
    a[1] = y;
}

extern "C" int fn_800A1BE8(int i) {
    char* p = lbl_802BB0FC + i * 0x4c;
    s16 x = *(s16*)(p + 0x1a4) - 0xe00;
    s16 y = *(s16*)(p + 0x1a6) - 0x2c00;
    if (x < 0) {
        x = 0;
    } else if (x >= 0x600) {
        x = 0x5ff;
    }
    if ((s16)y < 0) {
        y = 0;
    } else if ((s16)(s32)(s16)y >= 0x600) {
        y = 0x5ff;
    }
    return x / 256 + (y / 256) * 6;
}

extern void* lbl_80286B38[];
extern void* lbl_8028B3B8[];
extern void* lbl_80288B1C[];
extern void* lbl_80288EDC[];
extern void* lbl_80288520[];
extern void* lbl_8028699C[];
extern "C" void* fn_800A1C6C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028699C;
        if ((s32)ptr + (unsigned)0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288988;
            if ((s32)ptr + 0x8 != 0) {
                ((void**)(ptr))[2] = lbl_8027EC78;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800A1CE0(void) {
}

extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_800A1CE4(void) {
}

extern "C" void* fn_800A1CE8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286A30;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80286A4C[];
extern "C" void* fn_800A1D30(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286A4C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80286BA8[];
extern "C" void* fn_800A1D78(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286BA8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
