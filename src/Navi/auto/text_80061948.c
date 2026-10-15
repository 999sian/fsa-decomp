#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80061948-0x8006cfd8 (186 functions). split_file divides it into the game's real files.

extern void* lbl_8027F1FC[];
extern char lbl_8027F098[];
extern void* lbl_80247430[];
extern void* lbl_802474F4[];
extern "C" f32 fn_80116064(f32 x);
extern "C" void* fn_8004F19C(void* ptr, s16 param_2);
extern "C" void fn_801E0DB8(void* arr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void fn_80067EEC(void* p);
extern "C" int fn_801E6578(void* a, void* b);
extern "C" void fn_800074C0(const char* fmt, ...);
extern "C" int fn_80062FE4(void* p);
extern "C" void* fn_800637F0(void* a, u8* p, int n);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80062E28(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80062E64(s16* p) {
    p[0] = 0;
    p[1] = 1;
    *(s32*)(p + 2) = 0;
}

extern "C" void* fn_80062E7C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80062EB8(s16* p) {
    p[0] = 0;
    p[1] = 1;
    *(s32*)(p + 2) = 0;
}

extern "C" void* fn_80062ED0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F1FC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80062F18(void** p) {
    p[0] = lbl_8027F1FC;
    ((s16*)p)[2] = 0;
    ((s16*)p)[3] = 1;
    p[2] = 0;
}

extern "C" void* fn_80062F3C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80062F78(s16* p) {
    p[0] = 0;
    p[1] = 1;
    *(s32*)(p + 2) = 0;
}

extern "C" void* fn_80062F90(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80062FCC(s16* p) {
    p[0] = 0;
    p[1] = 1;
    *(s32*)(p + 2) = 0;
}

extern "C" int fn_800636A0(void* a, u8* p, int n) {
    void* r = fn_800637F0(a, p, n);
    if (r == 0) {
        fn_800074C0(lbl_8027F098, a);
        return 1;
    }
    return fn_80062FE4(r);
}

extern "C" void* fn_800637F0(void* a, u8* p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if ((int)*(u16*)(p + 0xe) != 0 && fn_801E6578(a, p) == 0) {
            return p;
        }
        p += 0x24;
    }
    return 0;
}

extern void* lbl_8027F214[];
extern "C" void* fn_80063BA4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F214;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027F2AC[];
extern void* lbl_8027F2C0[];
extern void* lbl_8027F240[];
extern "C" void* fn_80063BF4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F2AC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F2C0;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F240;
                if (ptr != nullptr) {
                    *(void**)ptr = lbl_8027F214;
                }
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800641AC(void);
extern "C" void fn_80064100(void) {
    fn_800641AC();
}

extern void* lbl_8027F6DC[];
extern "C" void* fn_800643E8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F6DC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80064120(void);
extern "C" void fn_800648CC(void) {
    fn_80064120();
}

extern void* lbl_8027F6D0[];
extern "C" void* fn_80064BE4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F6D0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027FB48[];
extern "C" void* fn_80064CBC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FB48;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027FB70[];
extern "C" void* fn_80064D40(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FB70;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80064FB0(void);
extern "C" void fn_80064DEC(void) {
    fn_80064FB0();
}

extern "C" void fn_80064E0C(void);
extern "C" void fn_80066B88(void) {
    fn_80064E0C();
}

extern "C" void fn_80066748(void);
extern "C" void fn_80066C5C(void) {
    fn_80066748();
}

extern "C" void fn_80065DC4(void);
extern "C" void fn_80066C7C(void) {
    fn_80065DC4();
}

extern void* lbl_8027FBE0[];
extern "C" void* fn_80066CA4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FBE0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80066DBC(void);
extern "C" void fn_80066D04(void) {
    fn_80066DBC();
}

extern "C" void fn_80066D24(void);
extern "C" void fn_80067BE4(void) {
    fn_80066D24();
}

extern "C" void fn_80067564(void);
extern "C" void fn_80067C54(void) {
    fn_80067564();
}

extern void* lbl_8027FCA8[];
extern "C" void* fn_80067DDC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FCA8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027FCD0[];
extern "C" void* fn_80067E38(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FCD0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u16 fn_80067E94(u16* p) {
    if (*p != 0) {
        (*p)--;
    }
    return *p;
}

extern "C" f32 fn_80067EB0(f32 a, f32 b) {
    return a + fn_80116064(b);
}

extern void* lbl_8027FDCC[];
extern "C" void* fn_80067F8C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FDCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800680A4(void);
extern "C" void fn_80067FE8(void) {
    fn_800680A4();
}

extern "C" void fn_80068008(void);
extern "C" void fn_80068804(void) {
    fn_80068008();
}

extern "C" void fn_80068B30(void);
extern "C" void fn_80068B10(void) {
    fn_80068B30();
}

extern "C" void fn_80069EA4(void);
extern "C" void fn_80069DC0(void) {
    fn_80069EA4();
}

extern "C" void fn_80069DE0(void);
extern "C" void fn_8006AF00(void) {
    fn_80069DE0();
}

extern "C" void fn_8006A29C(void);
extern "C" void fn_8006AF58(void) {
    fn_8006A29C();
}

extern "C" void fn_8006B240(void);
extern "C" void fn_8006B13C(void) {
    fn_8006B240();
}

extern "C" void fn_8006B15C(void);
extern "C" void fn_8006CDCC(void) {
    fn_8006B15C();
}

extern "C" void fn_8006B6D8(void);
extern "C" void fn_8006CE28(void) {
    fn_8006B6D8();
}

