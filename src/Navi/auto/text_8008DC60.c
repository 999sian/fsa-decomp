#include "types.h"
extern char lbl_802B7CA0[];
extern f32 lbl_80300AF0;
extern "C" void fn_8015FDA8(void*, void*);
extern "C" char lbl_802BB0FC[];
extern "C" u8 fn_8010B734(void*);
extern "C" void fn_8010BAA0(void*);
extern "C" u8 fn_8010B8D4(void*);
extern "C" void fn_800C55B8(void*, u8);
struct Obj_8009287C {
    u8 pad[0x7e8];
    u8 state;
};
typedef void (Obj_8009287C::*StateFn_8009287C)();
extern StateFn_8009287C lbl_80285C30[];
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

extern "C" int fn_8008F378()
{
	return 0;
}

extern "C" void* fn_80091918(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286B38;
        volatile void* vptr = ptr;
        if ((s32)(vptr) + 0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288854;
            if ((s32)(vptr) + 0x8 != 0) {
                ((void**)(ptr))[2] = lbl_8027EC78;
            }
        }
        if (param_2 > 0) {
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

extern StateFn_8009287C lbl_80285FE8[];
extern "C" void fn_8009456C(Obj_8009287C* param_1) {
    (param_1->*lbl_80285FE8[param_1->state])();
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

extern StateFn_8009287C lbl_802860CC[];
extern "C" void fn_80094DCC(Obj_8009287C* param_1) {
    (param_1->*lbl_802860CC[param_1->state])();
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

extern StateFn_8009287C lbl_80286144[];
extern "C" void fn_80095084(Obj_8009287C* param_1) {
    (param_1->*lbl_80286144[param_1->state])();
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

extern "C" void* fn_800A0098(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B3B8;
        if ((s32)ptr + 0x8 != 0) {
            ((void**)(ptr))[2] = lbl_80288B1C;
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

