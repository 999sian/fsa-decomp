#include "types.h"
extern void* lbl_80289A14[];

extern void* lbl_80283F48[];
extern void* lbl_802886F8[];

extern void* lbl_80283F48[];
extern void* lbl_80289A14[];

extern void* lbl_80283F48[];

struct NaviState_8009E6F0 {
    void f();
};
typedef void (NaviState_8009E6F0::*NaviStateFunc_8009E6F0)();
extern NaviStateFunc_8009E6F0 lbl_802865A4[];
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
extern "C" void fn_800F3D84(void*);
extern "C" void fn_800F2CD4(void*);
extern "C" void fn_800F3888(void*);
extern "C" void fn_800C5548(void*);
extern "C" void* fn_8015A90C(u32);
extern void* lbl_802869B4[];
extern void* lbl_8028C578[];
extern void* lbl_8027EC78[];
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

extern NaviStateFunc_8009E6F0 lbl_8028661C[];
extern "C" void fn_8009EBA0(NaviState_8009E6F0* p) {
    (p->*lbl_8028661C[((u8*)p)[0x800]])();
}

extern NaviStateFunc_8009E6F0 lbl_80286694[];
extern "C" void fn_8009F01C(NaviState_8009E6F0* p) {
    (p->*lbl_80286694[((u8*)p)[0x800]])();
}

extern NaviStateFunc_8009E6F0 lbl_8028673C[];
extern "C" void fn_8009F440(NaviState_8009E6F0* p) {
    (p->*lbl_8028673C[((u8*)p)[0x800]])();
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

extern f32 lbl_80300B20;
extern f64 lbl_80300B00;
extern f64 lbl_80300B58;
extern f64 lbl_80300B60;
extern f32 lbl_80300B38;
extern f64 lbl_80300B68;
extern f32 lbl_80300B70;
extern f32 lbl_80300B74;
extern f32 lbl_80300AFC;
extern f32 lbl_802FEAB0;
extern f32* lbl_802F0BC0;
extern "C" f32 fn_800A1774(s32 param_1, s32 param_2, u8 param_3)
{
    if (param_1 <= 0) {
        return lbl_80300B20;
    }
    
    if (param_2 < 0) {
        param_2 = 0;
    }
    
    if (param_2 > param_1) {
        param_2 = param_1;
    }
    
    // Convert to double using 2^52 trick and compute ratio
    f64 ratio = ((f64)(u32)param_2 - 4503599627370496.0) / ((f64)(u32)param_1 - 4503599627370496.0);
    f32 f4 = (f32)ratio;
    
    u8 mode = param_3 & 0xFF;
    
    switch (mode) {
    case 0:
        return f4 * f4;
    case 1: {
        if (f4 <= lbl_80300AF0) {
            if (f4 < lbl_80300B68) {
                return lbl_802FEAB0;
            }
            f32 x = f4;
            f32 bit_pattern = x;
            // Check for special values
            u32 bits;
            *(u32*)&bits = *(u32*)&bit_pattern;
            u32 exp = (bits >> 23) & 0xFF;
            if (exp == 0xFF) {
                // Infinity
                if ((bits & 0x7FFFFF) == 0) {
                    return lbl_802FEAB0;
                }
                // NaN
                return lbl_802FEAB0;
            }
            if (bits == 0) {
                // Zero
                return f4;
            }
            
            // Newton-Raphson sqrt
            f32 result = __frsqrte(f4);
            f64 magic3 = lbl_80300B58;
            f64 magic2 = lbl_80300B60;
            
            f64 res_d = (f64)result;
            f64 temp = res_d * res_d;
            f64 temp2 = magic3 * res_d;
            temp = (f64)f4 * temp;
            temp = magic2 - temp;
            res_d = temp2 * temp;
            
            temp = res_d * res_d;
            temp2 = magic3 * res_d;
            temp = (f64)f4 * temp;
            temp = magic2 - temp;
            res_d = temp2 * temp;
            
            temp = res_d * res_d;
            temp2 = magic3 * res_d;
            temp = (f64)f4 * temp;
            temp = magic2 - temp;
            res_d = temp2 * temp;
            
            result = (f32)(res_d * (f64)f4);
            return result;
        } else {
            return f4;
        }
    }
    case 2: {
        f32 threshold = lbl_80300B38;
        f32 bias = lbl_80300B20;
        f32 temp = threshold * f4;
        temp = temp - bias;
        temp = threshold * temp;
        return temp - bias;
    }
    case 3:
        return f4;
    case 4: {
        f32 scale = lbl_80300B70;
        f32 index_scale = lbl_80300AFC;
        f32 scaled = scale * f4;
        scaled = index_scale * scaled;
        s32 idx = (s32)scaled;
        idx = (idx << 2) & 0x3FF;
        f32 val = *(f32*)((u8*)lbl_802F0BC0 + idx);
        return val * val;
    }
    case 5: {
        f32 scale = lbl_80300B74;
        f32 index_scale = lbl_80300AFC;
        f32 scaled = scale * f4;
        scaled = index_scale * scaled;
        s32 idx = (s32)scaled;
        idx = (idx << 2) & 0x3FF;
        f32 val = *(f32*)((u8*)lbl_802F0BC0 + idx);
        return val * val;
    }
    default:
        return f4;
    }
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
