#include "types.h"
#include "sdk/Dolphin/vec.h"
extern u8 lbl_8029F8D8[];
extern u8 lbl_8029B5D0[];
extern u8 lbl_8027F308[];
extern "C" void fn_801AE124(void* p);
extern void* lbl_801F9650[];
extern "C" void fn_801C61AC(void* p, f32 x, f32 y, f32 z);
extern "C" void fn_8000C950(void* m, s32 a, s32 b, s32 c);
extern "C" void fn_801C5D74(void* p, void* q);
extern "C" int fn_800183AC(void* p, void* f, void* a);
extern "C" int fn_800175B8(void* p);
extern "C" int fn_80064430(u8* p);
extern u8 lbl_802EE470[];
extern "C" void fn_80041268(void* a, u8* b, int n);
extern "C" void fn_8000EB8C(void* a, void* b, f32 c);
extern "C" void fn_8000EBB8(void* a);
extern void* lbl_8027F2C0[];

extern void* lbl_8027F2C0[];

extern void* lbl_8027F240[];
extern void* lbl_8027F214[];

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
extern "C" f32 fn_801AB758(f32);
extern "C" void fn_801ACC40(void*, u32, void*);
extern "C" void* fn_800637F0(void* a, u8* p, int n);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" int fn_800636F4(s32, void*, s32);
extern "C" void fn_8000DDAC(void*, void*, s32);
extern "C" void fn_80010CE4(void*);
extern "C" void fn_801AFE98(void*, void*);
extern "C" void fn_8000EBB8(void*);
extern "C" void fn_80022438(void*, void*, s32, s32, f32, f32, f32, f32);
extern u8 lbl_802FF17C;
extern s32 lbl_802FF170;
extern s32 lbl_802FC910;
extern "C" int fn_80068190(u8* p);
extern "C" int fn_801E2F8C(s32 v);
extern void* lbl_8024745C[];
extern u16 lbl_80280080[];
extern u16 lbl_802FC94C[];
extern int lbl_802FC930;  // SDA label
extern void* lbl_802B7CA0[];  // Address table
extern void* lbl_802BB0FC[];
extern "C" void fn_8006A814(void* self, s32 mode);
extern "C" u8 fn_80010C6C(void* self, s32 a, s32 b, s32 c);
extern f32 lbl_80300418;
extern void* lbl_802BF814[];
extern f64 lbl_80300470;  // SDA label
extern "C" void fn_8002F358(int, int);
extern f32 lbl_80300468; // SDA label
extern f32 lbl_80300460; // SDA label
extern "C" int fn_80020EA4(void* a, void* b);
extern "C" int fn_8006A1D0(u8* p);
extern f32 lbl_80300448; // SDA label
extern f32 lbl_80300464; // SDA label
extern s32 lbl_802802A8[];
extern u8 lbl_80280248[];
extern f32 lbl_8030046C;  // SDA label
extern void* lbl_80280230[];
extern "C" void fn_8006C404(void);
extern "C" void fn_8006C5B0(s32, s32 = 0);
extern u32 lbl_802FC710;
extern "C" void fn_80030534(void*, int, int);
extern "C" void* fn_80022434(s32);
struct StateObj80066A80;
typedef void (StateObj80066A80::*StateFunc80066A80)(s32);
struct StateObj80066A80 {
    u8 pad[0x3ba];
    s8 m_3ba;
    u8 pad2[0x3c0 - 0x3bb];
    StateFunc80066A80 m_func;
};
extern StateFunc80066A80 lbl_8027FAC0;
struct StateObj8006792C;
typedef void (StateObj8006792C::*StateFunc8006792C)(s32);
struct StateObj8006792C {
    u8 pad[0x280];
    u16 m_280;
    s8 m_282;
    u8 pad2[0x284 - 0x283];
    StateFunc8006792C m_284;
    u8 pad3[0x296 - 0x290];
    u16 m_296;
};
extern StateFunc8006792C lbl_8027FC20;
extern "C" u16 fn_80067E94(u16* p);
struct StateObj8006A924;
typedef void (StateObj8006A924::*StateFunc8006A924)(s32);
struct StateObj8006A924 {
    u8 pad[0x27c];
    s8 m_27c;
    u8 pad2[0x280 - 0x27d];
    StateFunc8006A924 m_func;
};
extern StateFunc8006A924 lbl_802800FC;
struct VObj800636F4_10 { u8 pad[0x10]; virtual void Destroy(int); };
struct VObj800636F4_14 { virtual void f0(); virtual void Release(); };
extern "C" void fn_80061948(void* param_1) {
    *(u16*)((u8*)param_1 + 0xe) = 0;
    *(u32*)((u8*)param_1 + 0x10) = 0;
    *(u32*)((u8*)param_1 + 0x14) = 0;
    *(u32*)((u8*)param_1 + 0x18) = 0;
    *(u32*)((u8*)param_1 + 0x1c) = 0;
    *(u32*)((u8*)param_1 + 0x20) = 0;
}

extern "C" void fn_8000FA24(void* p);
extern "C" u8* fn_80061968(u8* p, s16 n) {
    u8* obj;

    if (p != 0) {
        obj = *(u8**)(p + 0x10);
        if (obj != 0) {
            (*(void (**)(u8*, s32))(*(u8**)(obj + 0x10) + 8))(obj, 1);
            *(u32*)(p + 0x10) = 0;
        } else if (*(u32*)(p + 0x14) != 0) {
            if (*(void**)(p + 0x1c) != 0) {
                fn_8000FA24(*(void**)(p + 0x1c));
                *(u32*)(p + 0x1c) = 0;
            }
            if (*(u32*)(p + 0x20) != 0) {
                *(u32*)(p + 0x20) = 0;
            }
            (*(void (**)(u8*))(**(u8***)(p + 0x14) + 0xc))(*(u8**)(p + 0x14));
            *(u32*)(p + 0x14) = 0;
        }
        if (n > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void* fn_80062D60(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F2C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F240;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801AE194(void);
extern "C" void fn_80017FEC(int, u32, void*, void*, int, int, int);
extern void* lbl_801F9320[];
extern void* lbl_80247404[];

extern "C" void* fn_80062DCC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F240;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

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

extern char lbl_8027F0BC[];
#pragma dont_inline on
extern "C" int fn_800636F4(s32 a, void* p, s32 n) {
    u8* r = (u8*)fn_800637F0((void*)a, (u8*)p, n);
    if (r == 0) {
        fn_800074C0(lbl_8027F0BC, a);
        return 0;
    }
    u16 c = *(u16*)(r + 0xe) - 1;
    *(u16*)(r + 0xe) = c;
    if (c == 0 && r != 0) {
        VObj800636F4_10* obj = *(VObj800636F4_10**)(r + 0x10);
        if (obj != 0) {
            if (obj != 0) {
                obj->Destroy(1);
            }
            *(u32*)(r + 0x10) = 0;
        } else if (*(u32*)(r + 0x14) != 0) {
            if (*(void**)(r + 0x1c) != 0) {
                fn_8000FA24(*(void**)(r + 0x1c));
                *(u32*)(r + 0x1c) = 0;
            }
            if (*(u32*)(r + 0x20) != 0) {
                *(u32*)(r + 0x20) = 0;
            }
            (*(VObj800636F4_14**)(r + 0x14))->Release();
            *(u32*)(r + 0x14) = 0;
        }
    }
    return 1;
}
#pragma dont_inline reset

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

extern "C" int fn_8006387C(void* param_1, int param_2) {
    int i = 0;
    while (param_2 > i) {
        if (*(s16*)((u8*)param_1 + 0xe) == 0) {
            return (int)param_1;
        }
        param_1 = (void*)((u8*)param_1 + 0x24);
        i += 1;
    }
    return 0;
}

extern "C" int fn_80063AF8(u8* p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (*(u32*)(p + 0x10) != 0 && fn_80062FE4(p) > 0) {
            return 1;
        }
        p += 0x24;
    }
    return 0;
}

extern "C" void fn_80063B74(u8* p, void* a) {
    fn_801ACC40(*(void**)(p + 8), (int)*(u16*)(p + 4), a);
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

extern "C" int fn_80063BEC() {
    return 0;
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

extern "C" int fn_80063C70(void) {
    return 8;
}

extern "C" f32 fn_80063C78(void* p) {
    return fn_801AB758(((f32*)p)[2]);
}

extern "C" void* fn_80063C9C(void* p) {
    void* lbl = lbl_8029B5D0;
    *(void**)p = lbl;
    fn_801E0DB8((u8*)p + 0x4, (void*)fn_80062FCC, (void*)fn_80062F90, 8, 2);
    fn_801E0DB8((u8*)p + 0x14, (void*)fn_80062F78, (void*)fn_80062F3C, 8, 8);
    fn_801E0DB8((u8*)p + 0x54, (void*)fn_80062F18, (void*)fn_80062ED0, 0xc, 8);
    fn_801E0DB8((u8*)p + 0xb4, (void*)fn_80062EB8, (void*)fn_80062E7C, 8, 4);
    fn_801E0DB8((u8*)p + 0xd4, (void*)fn_80062E64, (void*)fn_80062E28, 8, 4);
    fn_801AE124(p);
    *(void**)p = lbl_8027F308;
    *(u32*)((u8*)p + 0xf4) = 0;
    return p;
}

extern "C" void fn_801E0D40(void*, void*, s32, s32);
extern u8 lbl_8029B5D0[];
extern "C" void* fn_80063D90(void* p, s16 param_2) {
    if (p != 0) {
        *(void**)p = lbl_8029B5D0;
        fn_801E0D40((u8*)p + 0xd4, (void*)&fn_80062E28, 8, 4);
        fn_801E0D40((u8*)p + 0xb4, (void*)&fn_80062E7C, 8, 4);
        fn_801E0D40((u8*)p + 0x54, (void*)&fn_80062ED0, 0xc, 8);
        fn_801E0D40((u8*)p + 0x14, (void*)&fn_80062F3C, 8, 8);
        fn_801E0D40((u8*)p + 0x4, (void*)&fn_80062F90, 8, 2);
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_80063E60(void* param_1, void* param_2) {
    fn_801AE194();
    u32 fn_addr = *(u32*)((u8*)param_1 + 0xf4);
    if (fn_addr != 0) {
        ((void (*)(void*, void*))(fn_addr))(param_1, param_2);
    }
}

extern u8 lbl_8027F308[];
extern "C" void* fn_80063EB4(void* p, s16 param_2) {
    if (p != 0) {
        *(void**)p = lbl_8027F308;
        if (p != 0) {
            *(void**)p = lbl_8029B5D0;
            fn_801E0D40((u8*)p + 0xd4, (void*)&fn_80062E28, 8, 4);
            fn_801E0D40((u8*)p + 0xb4, (void*)&fn_80062E7C, 8, 4);
            fn_801E0D40((u8*)p + 0x54, (void*)&fn_80062ED0, 0xc, 8);
            fn_801E0D40((u8*)p + 0x14, (void*)&fn_80062F3C, 8, 8);
            fn_801E0D40((u8*)p + 0x4, (void*)&fn_80062F90, 8, 2);
        }
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_80063F94(void) {
    u8* ptr = (u8*)&lbl_801F9320;
    for (int i = 0; i < 0x1d; i++) {
        f32 floats[3];
        s16 shorts[3];
        
        floats[0] = *(f32*)(ptr + 0x4);
        floats[1] = *(f32*)(ptr + 0x8);
        floats[2] = *(f32*)(ptr + 0xc);
        
        shorts[0] = *(s16*)(ptr + 0x10);
        shorts[1] = *(s16*)(ptr + 0x12);
        shorts[2] = *(s16*)(ptr + 0x14);
        
        u8 b = *(u8*)(ptr + 0x2);
        s16 first = *(s16*)(ptr + 0x0);
        u32 u = *(u32*)(ptr + 0x18);
        
        fn_80017FEC((int)first, u, floats, shorts, 0, (int)(s8)b, 0);
        ptr += 0x1c;
    }
}

extern "C" void fn_80064030(void* param_1) {
    *(void**)param_1 = lbl_80247404;
    u16 zero = 0;
    u16 val_258 = 0x258;
    u8 one = 1;
    *(u16*)((u8*)param_1 + 0x28) = zero;
    *(u16*)((u8*)param_1 + 0x2a) = val_258;
    *(u8*)((u8*)param_1 + 0x2c) = one;
}

extern void* lbl_80247544[];
extern f32 lbl_801F96C4[];
extern "C" void* fn_8004F1E4(void* ptr, s16 param_2);
extern "C" void* fn_80064058(void* p) {
    *(void**)p = lbl_80247544;
    fn_801E0DB8((u8*)p + 4, fn_80064030, fn_8004F1E4, 0x30, 0x1d);
    f32* src = lbl_801F96C4;
    u8* dst = (u8*)p;
    f32 a, b, c;
    for (int i = 0x1d; i > 0; i--) {
        a = src[0];
        b = src[1];
        *(f32*)(dst + 0x8) = a;
        c = src[2];
        *(f32*)(dst + 0xc) = b;
        a = src[3];
        *(f32*)(dst + 0x10) = c;
        b = src[4];
        *(f32*)(dst + 0x14) = a;
        a = src[5];
        *(f32*)(dst + 0x18) = b;
        *(f32*)(dst + 0x1c) = a;
        src += 6;
        dst += 0x30;
    }
    return p;
}

extern "C" void fn_800641AC(void);
extern "C" void fn_80064100(void) {
    fn_800641AC();
}

#pragma dont_inline on
extern "C" int fn_80064120(u8* p) {
    if ((*(u32*)(p + 0xf8) & 8) == 0) {
        if (p != nullptr) {
            fn_800175B8(p);
        }
        *(u32*)(p + 0xf8) |= 8;
    }
    if ((u8)fn_800183AC(p, (void*)fn_80064100, lbl_801F9650[*(s8*)(p + 0x240)])) {
        return fn_80064430(p);
    }
    return 5;
}
#pragma dont_inline reset

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

extern "C" void fn_800645A8(u8* p) {
    u8* q = *(u8**)(p + 0x24c);
    *(f32*)(q + 0x18) = *(f32*)(p + 0x144);
    *(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
    *(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
    fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
    fn_8000C950(lbl_8029F8D8, *(s16*)(p + 0x13c), *(s16*)(p + 0x13e), *(s16*)(p + 0x140));
    fn_801C5D74(lbl_8029F8D8, *(u8**)(p + 0x24c) + 0x24);
}

struct Unk8027FC14 {
    u32 a;
    u32 b;
    u32 c;
};
extern struct Unk8027FC14 lbl_8027FC14;
struct StateObj_80067840;
typedef void (StateObj_80067840::*StateFunc_80067840)(s32);
struct StateObj_80067840 {
    u8 pad[0x282];
    s8 m_state;
    u8 pad2;
    StateFunc_80067840 m_func;
};
extern "C" int fn_801E10A0(void* p, void* q = 0);
extern "C" int fn_801E1070(void* p);
extern "C" void fn_801E10DC(void* p, void* q);
extern "C" int fn_80064630(u8* p, u32* src, void* arg) {
    if (fn_801E10A0(p + 0x258)) {
        if (fn_801E1070(p + 0x258)) {
            *(s8*)(p + 0x254) = -1;
            fn_801E10DC(p, arg);
        }
        *(u32*)(p + 0x258) = src[0];
        *(u32*)(p + 0x25c) = src[1];
        *(u32*)(p + 0x260) = src[2];
        *(s8*)(p + 0x254) = 0;
        fn_801E10DC(p, arg);
    }
    return 1;
}

extern "C" BOOL fn_800646E4(s8* p) {
    if (p[0x254] == 0) {
        p[0x254]++;
    }
    return TRUE;
}

extern "C" int fn_80064120(u8* p);
extern "C" void fn_800648CC(u8* p) {
    fn_80064120(p);
}

extern "C" BOOL fn_800648EC(void)
{
    return TRUE;
}

extern "C" int fn_80064B20(u8* p) {
    *(u32*)(lbl_802EE470 + 0x48) = *(u32*)((u8*)lbl_802B7CA0 + 0x142c);
    *(u32*)(lbl_802EE470 + 0x4c) = *(u32*)((u8*)lbl_802B7CA0 + 0x1430);
    fn_80041268(*(void**)(p + 0x24c), p + 0x180, 5);
    if (*(s8*)(p + 0x240) == 0x1b || *(s8*)(p + 0x240) == 0x1c || *(s8*)(p + 0x240) == 0xa) {
        fn_8000EB8C(*(void**)(p + 0x250), *(void**)(*(u8**)(p + 0x24c) + 4),
                    *(f32*)(*(u8**)(*(u8**)(p + 0x250) + 4) + 0x10));
    }
    fn_8000EBB8(*(void**)(p + 0x24c));
    *(u32*)(lbl_802EE470 + 0x48) = *(u32*)((u8*)lbl_802B7CA0 + 0x1434);
    *(u32*)(lbl_802EE470 + 0x4c) = *(u32*)((u8*)lbl_802B7CA0 + 0x1438);
    return 1;
}

extern "C" BOOL fn_80064BDC(void)
{
    return TRUE;
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

extern "C" int fn_80064C40(s16 a, s16 b) {
    f32 x = fn_80116064((f32)b);
    return (int)((f32)a + x);
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

extern "C" void fn_801163D4(void* a, void* b);
extern "C" void fn_80017FCC(void* p);
extern u8 lbl_802804C0[];
extern u8 lbl_80280418[];
extern f32 lbl_80300478;
extern "C" void* fn_80064D18(void** p) {
    p[0] = lbl_8027F6DC;
    p[1] = 0;
    p[0] = lbl_8027FB48;
    p[2] = 0;
    return p;
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

extern "C" void fn_80064DC4(void** p) {
    void* z = 0;
    void* a = lbl_8027F6DC;
    void* b = lbl_8027F6D0;
    p[0] = a;
    p[1] = z;
    p[0] = b;
    p[3] = z;
}

extern "C" void fn_80064FB0(void);
extern "C" void fn_80064DEC(void) {
    fn_80064FB0();
}

extern "C" void fn_8006686C(void);
extern "C" u8 fn_8000D6F4(void* self);
extern "C" s32 fn_80065DA0(void) {
    fn_8006686C();
    return 4;
}

extern "C" void fn_800667B4(u8* p) {
    u8* a;
    u8* b;
    s32 i;

    a = p;
    b = p;
    for (i = 0; i < 4; i++, a += 0x10, b += 0xc) {
        fn_8000D6F4(a + 0x29c);
        fn_8000D6F4(b + 0x33c);
        fn_8000D6F4(b + 0x378);
    }
    fn_8000D6F4(p + 0x2dc);
    fn_8000D6F4(p + 0x36c);
    fn_8000D6F4(p + 0x3a8);
    fn_8000D6F4(p + 0x2ec);
    fn_8000D6F4(p + 0x2fc);
    fn_8000D6F4(p + 0x30c);
    fn_8000D6F4(p + 0x31c);
    fn_8000D6F4(p + 0x32c);
}

extern "C" void fn_80066A80(StateObj80066A80* self, s32 param) {
    if (!self->m_func) {
        StateFunc80066A80 f = lbl_8027FAC0;
        if (self->m_func != f) {
            if (self->m_func) {
                self->m_3ba = -1;
                (self->*self->m_func)(0);
            }
            self->m_func = f;
            self->m_3ba = 0;
            (self->*self->m_func)(0);
        }
    }
    (self->*self->m_func)(param);
}

extern "C" BOOL fn_80066B6C(char* p) {
    if (p[0x3ba] == 0) {
        p[0x3ba]++;
    }
    return TRUE;
}

extern "C" void fn_80064E0C(void);
extern "C" void fn_80066B88(void) {
    fn_80064E0C();
}

extern "C" BOOL fn_80066BA8(u8* p) {
    void* obj;

    obj = *(void**)(p + 0x288);
    if (obj) {
        *(u32*)((u8*)obj + 0xf4) |= 1;
        *(s32*)((u8*)obj + 0x24) = 1;
        *(void**)(p + 0x288) = 0;
    }
    obj = *(void**)(p + 0x28c);
    if (obj) {
        *(u32*)((u8*)obj + 0xf4) |= 1;
        *(s32*)((u8*)obj + 0x24) = 1;
        *(void**)(p + 0x28c) = 0;
    }
    p += 8;
    obj = *(void**)(p + 0x288);
    if (obj) {
        *(u32*)((u8*)obj + 0xf4) |= 1;
        *(s32*)((u8*)obj + 0x24) = 1;
        *(void**)(p + 0x288) = 0;
    }
    obj = *(void**)(p + 0x28c);
    if (obj) {
        *(u32*)((u8*)obj + 0xf4) |= 1;
        *(s32*)((u8*)obj + 0x24) = 1;
        *(void**)(p + 0x28c) = 0;
    }
    obj = *(void**)(p + 0x290);
    if (obj) {
        *(u32*)((u8*)obj + 0xf4) |= 1;
        *(s32*)((u8*)obj + 0x24) = 1;
        *(void**)(p + 0x290) = 0;
    }
    return 1;
}

extern "C" void fn_80066748(void);
extern "C" void fn_80066C5C(void) {
    fn_80066748();
}

extern "C" void fn_80065DC4(void);
extern "C" void fn_80066C7C(void) {
    fn_80065DC4();
}

extern "C" BOOL fn_80066C9C(void);
extern "C" BOOL fn_80066C9C(void)
{
    return TRUE;
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

extern u8 lbl_80247308[];
extern "C" void fn_80066CEC(void** p) {
    p[0] = lbl_80247308;
    *(u16*)(p + 1) = 0;
}

extern "C" void fn_80066DBC(void);
extern "C" void fn_80066D04(void) {
    fn_80066DBC();
}

extern "C" void fn_800677B8(u8* p) {
    u8* q = *(u8**)(p + 0x24c);
    *(f32*)(q + 0x18) = *(f32*)(p + 0x144);
    *(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
    *(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
    fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
    fn_8000C950(lbl_8029F8D8, *(s16*)(p + 0x13c), *(s16*)(p + 0x13e), *(s16*)(p + 0x140));
    fn_801C5D74(lbl_8029F8D8, *(u8**)(p + 0x24c) + 0x24);
}

extern "C" void fn_80067840(StateObj_80067840* self, s32 arg) {
    struct Unk8027FC14 tbl;
    if (fn_801E1070(&self->m_func) == 0) {
        tbl = lbl_8027FC14;
        if (fn_801E10A0(&self->m_func, &tbl) != 0) {
            if (fn_801E1070(&self->m_func) != 0) {
                self->m_state = -1;
                (self->*self->m_func)(0);
            }
            *(struct Unk8027FC14*)&self->m_func = tbl;
            self->m_state = 0;
            (self->*self->m_func)(0);
        }
    }
    (self->*self->m_func)(arg);
}

extern "C" s32 fn_8006792C(StateObj8006792C* self) {
    if (self->m_282 == 0) {
        self->m_296 = self->m_280;
        self->m_282++;
    } else if (self->m_282 != -1 && fn_80067E94(&self->m_296) == 0) {
        StateFunc8006792C f = lbl_8027FC20;
        if (fn_801E10A0(&self->m_284, &f) != 0) {
            if (fn_801E1070(&self->m_284)) {
                self->m_282 = -1;
                (self->*self->m_284)(0);
            }
            self->m_284 = f;
            self->m_282 = 0;
            (self->*self->m_284)(0);
        }
    }
    return 1;
}

extern "C" void fn_80067B74(u8* p) {
    s32 t = (s8)p[0x240];

    if (t == 5) {
        fn_8000D6F4(*(void**)(p + 0x258));
        fn_8000D6F4(*(void**)(p + 0x250));
    } else if (t == 6) {
        fn_8000D6F4(*(void**)(p + 0x250));
    } else if (t == 7) {
        fn_8000D6F4(*(void**)(p + 0x25c));
    }
}

extern "C" void fn_80066D24(void);
extern "C" void fn_80067BE4(void) {
    fn_80066D24();
}

extern "C" BOOL fn_80067C04(u8* p) {
    void* obj = *(void**)(p + 0x260);
    if (obj != nullptr) {
        *(u32*)((u8*)obj + 0xf4) |= 1;
        *(s32*)((u8*)obj + 0x24) = 1;
        *(void**)(p + 0x260) = nullptr;
    }
    obj = *(void**)(p + 0x264);
    if (obj != nullptr) {
        *(u32*)((u8*)obj + 0xf4) |= 1;
        *(s32*)((u8*)obj + 0x24) = 1;
        *(void**)(p + 0x264) = nullptr;
    }
    return TRUE;
}

extern "C" void fn_80067564(void);
extern "C" void fn_80067C54(void) {
    fn_80067564();
}

extern "C" BOOL fn_80067DD4(void);
extern "C" BOOL fn_80067DD4(void)
{
    return TRUE;
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

extern "C" void fn_80067EEC(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_80247430;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void* fn_80067F1C(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_802474F4;
    fn_801E0DB8((u8*)p + 4, fn_80067EEC, fn_8004F19C, 0x1c, 1);
    f[8] = 10.0f;
    f[9] = -5.0f;
    f[10] = 0.5f;
    return p;
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

extern "C" void* fn_800638A4(void* a, void* b, void* c, s32 n);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void* a, const char* file, s32 line, s32 b, ...);
extern "C" void fn_80007AB8(const char* file, s32 line, s32 b, ...);
extern "C" void* fn_80011CF4(void* res, s32 a, u32 flags);
extern "C" s32 fn_800680A4(u8* self);
extern "C" void fn_80067FE8(u8* self) {
    fn_800680A4(self);
}

#pragma dont_inline on
extern "C" int fn_80068008(u8* p) {
    if ((*(u32*)(p + 0xf8) & 8) == 0) {
        if (p != nullptr) {
            fn_800175B8(p);
            *(void**)(p + 0x250) = lbl_8027F6DC;
            *(u32*)(p + 0x254) = 0;
            *(void**)(p + 0x250) = lbl_8027FDCC;
            *(u32*)(p + 0x25c) = 0;
        }
        *(u32*)(p + 0xf8) |= 8;
    }
    if ((u8)fn_800183AC(p, (void*)fn_80067FE8, 0)) {
        return fn_80068190(p);
    }
    return 5;
}

extern char lbl_8027FCE0[];
extern char lbl_802FC8E0[8];
extern char lbl_802FC8E8[4];
extern char lbl_802FC8EC[8];
extern "C" s32 fn_800680A4(u8* self) {
    char* str = lbl_8027FCE0;
    void* res = fn_800638A4(lbl_802FC8E0, (void*)0x23, (u8*)lbl_802B7CA0 + 0x2200, 0x40);
    if (res == 0) {
        fn_8011FD18(fn_8011FD10(), str + 0x18, 0xd5, (s32)lbl_802FC8E8, str + 0x28);
        fn_80007AB8(str + 0x18, 0xd5, (s32)lbl_802FC8EC);
    }
    *(void**)(self + 0x24c) = fn_80011CF4(res, 0, 0x11020203);
    if (*(void**)(self + 0x24c) == 0) {
        fn_8011FD18(fn_8011FD10(), str + 0x18, 0xd9, (s32)lbl_802FC8E8, str + 0x3c);
        fn_80007AB8(str + 0x18, 0xd9, (s32)lbl_802FC8EC);
    }
    return 1;
}

#pragma dont_inline reset

extern "C" void fn_8000C8A4(void* m, s32 a, s32 b, s32 c);
extern "C" void fn_800682B0(u8* p) {
    u8* q = *(u8**)(p + 0x24c);
    *(f32*)(q + 0x18) = *(f32*)(p + 0x144);
    *(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
    *(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
    fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
    fn_8000C8A4(lbl_8029F8D8, *(s16*)(p + 0x13c), *(s16*)(p + 0x13e), *(s16*)(p + 0x140));
    fn_801C5D74(lbl_8029F8D8, *(u8**)(p + 0x24c) + 0x24);
}

extern "C" BOOL fn_800683EC(char* p) {
    if (p[0x28c] == 0) {
        p[0x28c]++;
    }
    return TRUE;
}

extern "C" int fn_80068008(u8* p);
extern "C" void fn_80068804(u8* p) {
    fn_80068008(p);
}

extern "C" int fn_80068190(u8* p);
extern "C" void fn_80068AD0(void* p);
extern "C" void* fn_8004F154(void* ptr, s16 param_2);
extern void* lbl_802474D0[];
extern f32 lbl_803003D0;
extern f32 lbl_803003D4;
extern f32 lbl_803003D8;
extern f32 lbl_803003DC;
extern f32 lbl_803003E0;
extern f32 lbl_803003E4;
extern "C" BOOL fn_80068824(u8* p) {
    u8* obj = *(u8**)(p + 0x264);
    if (obj != nullptr) {
        *(u32*)(obj + 0xf4) |= 1;
        *(s32*)(obj + 0x24) = 1;
        *(void**)(p + 0x264) = nullptr;
    }
    return TRUE;
}

extern "C" BOOL fn_800689C4(u8* p) {
    fn_8000EBB8(*(void**)(p + 0x24c));
    u8* obj = *(u8**)(p + 0x264);
    if (obj != nullptr) {
        f32 f0 = *(f32*)(p + 0x128);
        f32 f1 = *(f32*)(p + 0x12c);
        f32 f2 = *(f32*)(p + 0x130);
        f32 f3 = *(f32*)(p + 0x144);
        f32 f4 = *(f32*)(p + 0x148);
        f32 f5 = *(f32*)(p + 0x14c);
        *(f32*)(obj + 0xa4) = f0;
        *(f32*)(obj + 0xa8) = f1;
        *(f32*)(obj + 0xac) = f2;
        obj = *(u8**)(p + 0x264);
        *(f32*)(obj + 0x98) = f3;
        *(f32*)(obj + 0x9c) = f4;
        *(f32*)(obj + 0xa0) = f5;
        *(f32*)(obj + 0xb0) = f3;
        *(f32*)(obj + 0xb4) = f4;
    }
    return TRUE;
}

extern "C" BOOL fn_80068A40(void);
extern "C" BOOL fn_80068A40(void)
{
    return TRUE;
}

extern "C" void* fn_80068A48(void* p) {
    *(void**)p = lbl_802474D0;
    fn_801E0DB8((u8*)p + 4, fn_80068AD0, fn_8004F154, 0x24, 8);
    f32 f3 = lbl_803003D0;
    *(u8*)((u8*)p + 0x13c) = 0;
    f32* f = (f32*)p;
    f32 f2 = lbl_803003D4;
    f[0x49] = f3;
    f32 f1 = lbl_803003D8;
    f[0x4a] = f3;
    f32 f0 = lbl_803003DC;
    f[0x4b] = f3;
    f[0x4c] = f2;
    f[0x4d] = f1;
    f[0x4e] = f0;
    return p;
}

extern f32 lbl_803003E0;
extern f32 lbl_803003E4;
extern "C" void fn_80068AD0(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_8024745C;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
    *(s16*)((u8*)p + 0x20) = 100;
    f[7] = 0.0f;
}

extern "C" void fn_80068B30(void);
extern "C" void fn_80068B10(void) {
    fn_80068B30();
}

extern "C" void fn_80069680(u8* p, s32 param_2) {
    s32 v = fn_801E2F8C(param_2);
    if (v > 0x8000) {
        s32 adj = param_2 - 0x10000;
        if (param_2 < 0) {
            adj = param_2 + 0x10000;
        }
        param_2 = adj;
    }
    v = fn_801E2F8C(param_2);
    if (v > 0x2000) {
        s16 r = -0x2000;
        if (param_2 < 0) {
            r = 0x2000;
        }
        *(s16*)(p + 0x138) = r;
    } else {
        *(s16*)(p + 0x138) = -param_2;
    }
}

extern "C" int fn_800698DC(void) {
    fn_800636F4((s32)&lbl_802FC910, (u8*)lbl_802B7CA0 + 0x2200, 0x40);
    if (lbl_802FF170 != 0) {
        lbl_802FF170--;
    }
    return 1;
}

extern "C" BOOL fn_80069BE4(void);
extern "C" BOOL fn_80069BE4(void)
{
    return TRUE;
}

extern "C" void fn_80069EA4(void);
extern "C" void fn_80069DC0(void) {
    fn_80069EA4();
}

#pragma dont_inline on
extern "C" int fn_80069DE0(u8* p) {
    int iVar1 = fn_80020EA4(p + 0x244, (void*)&lbl_802FC930);
    if (iVar1 == 4) {
        if ((*(u32*)(p + 0xf8) & 8) == 0) {
            if (p != nullptr) {
                fn_800175B8(p);
                *(void**)(p + 0x250) = lbl_8027F6DC;
                *(u32*)(p + 0x254) = 0;
                *(void**)(p + 0x250) = lbl_8027FB48;
                *(u32*)(p + 0x258) = 0;
                *(void**)(p + 0x260) = lbl_8027F6DC;
                *(u32*)(p + 0x264) = 0;
                *(void**)(p + 0x260) = lbl_8027FB48;
                *(u32*)(p + 0x268) = 0;
            }
            *(u32*)(p + 0xf8) |= 8;
        }
        if ((u8)fn_800183AC(p, (void*)fn_80069DC0, (void*)0x4200)) {
            iVar1 = fn_8006A1D0(p);
        } else {
            iVar1 = 5;
        }
    }
    return iVar1;
}

extern "C" void fn_8006A490(void* p);
extern "C" void fn_80010DF0(void* p);
extern "C" int fn_8006A5D0(void* param_1, int param_2);
extern f32 lbl_801F9A48[];
extern s32 lbl_802FF178;
extern "C" int fn_8006A1D0(u8* p) {
    f32* v = (f32*)((u8*)lbl_801F9A48 + *(s32*)((u8*)lbl_802BB0FC + 0x424) * 12);
    f32 x = v[0];
    f32 y = v[1];
    *(f32*)(p + 0x144) = x;
    f32 z = v[2];
    *(f32*)(p + 0x148) = y;
    *(f32*)(p + 0x14c) = z;
    lbl_802FF178 = 0;
    fn_8006A490(p);
    u8* g = (u8*)lbl_802BF814;
    *(f32*)(g + 0x21c) = *(f32*)(p + 0x100);
    *(f32*)(g + 0x220) = *(f32*)(p + 0x104);
    *(f32*)(g + 0x224) = *(f32*)(p + 0x108);
    *(f32*)(g + 0x228) = *(f32*)(p + 0x144);
    *(f32*)(g + 0x22c) = *(f32*)(p + 0x148);
    *(f32*)(g + 0x230) = *(f32*)(p + 0x14c);
    lbl_802FF17C = 0;
    fn_8006A5D0(p, 3);
    fn_80010DF0(*(void**)(p + 0x24c));
    p[0x27f] = 0;
    p[0x27e] = 0;
    return 4;
}

#pragma dont_inline reset

extern "C" int fn_8006A5D0(void* param_1, int param_2) {
    s32 old_val = *(s32*)((u8*)param_1 + 0x26c);
    if (old_val != param_2) {
        *(s32*)((u8*)param_1 + 0x26c) = param_2;
        
        u8* data = (u8*)lbl_80280080 + param_2 * 0x14;
        f32 f1 = *(f32*)(data + 0x4);
        u16 data_0 = *(u16*)(data + 0x0);
        f32 f2 = *(f32*)(data + 0x8);
        
        *(u16*)((u8*)param_1 + 0x278) = data_0;
        *(u8*)((u8*)param_1 + 0x27d) = 0;
        
        u16 idx = data_0;
        u16 idx_val = lbl_802FC94C[idx];
        u16 data_1 = *(u16*)(data + 0x2);
        f32 f3 = *(f32*)(data + 0xc);
        f32 f4 = *(f32*)(data + 0x10);
        
        void* ptr = *(void**)((u8*)param_1 + 0x24c);
        ((void (*)(void*, s32, u16, u16))fn_80022438)(ptr, 0, idx_val, data_1);
        
        void* ptr2 = *(void**)((u8*)param_1 + 0x24c);
        f32 f0 = *(f32*)((u8*)ptr2 + 0x1c);
        *(f32*)((u8*)param_1 + 0x274) = f0;
    }
    return 0;
}

extern "C" void fn_8006A668(u8* param_1) {
    if (*(s32*)((u8*)lbl_802BB0FC + 0x46c) & 1) {
        fn_8006A814(param_1, 1);
    } else {
        fn_8006A814(param_1, 0);
    }
    *(u8*)(param_1 + 0x27d) = fn_80010C6C(*(void**)(param_1 + 0x24c), 0, 0, 0);
    if (*(f32*)(*(u8**)(param_1 + 0x24c) + 0x18) < lbl_80300418) {
        if (*(f32*)(param_1 + 0x274) < *(f32*)(*(u8**)(param_1 + 0x24c) + 0x1c)) {
            *(u8*)(param_1 + 0x27d) = 1;
        }
    } else if (*(f32*)(param_1 + 0x274) > *(f32*)(*(u8**)(param_1 + 0x24c) + 0x1c)) {
        *(u8*)(param_1 + 0x27d) = 1;
    }
    *(f32*)(param_1 + 0x274) = *(f32*)(*(u8**)(param_1 + 0x24c) + 0x1c);
    fn_8000D6F4(param_1 + 0x250);
}

extern "C" void* fn_800638A4(void* a, void* b, void* c, s32 n);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void* a, const char* file, s32 line, s32 b, ...);
extern "C" void fn_80007AB8(const char* file, s32 line, s32 b, ...);
extern "C" int fn_8000DABC(void* a, u8* b, void* c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern char lbl_80280014[];
extern char lbl_80280074[];
extern char lbl_802FC938;
extern char lbl_802FC93C;
#pragma push
#pragma use_lmw_stmw off
extern "C" bool fn_8006A72C(void* param_1, void* param_2, u8* param_3, void* param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, f32 param_9) {
    void* r = fn_800638A4(&lbl_802FC930, param_4, (u8*)lbl_802B7CA0 + 0x2200, 0x40);
    if (r == 0) {
        void* uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_80280014, 0x26c, (s32)&lbl_802FC938, lbl_80280074);
        fn_80007AB8(lbl_80280014, 0x26c, (s32)&lbl_802FC93C);
    }
    if (fn_8000DABC(param_2, param_3 + 0x58, r, param_5, param_6, param_7, param_8, param_9) == 0) {
        return false;
    }
    return true;
}

extern "C" void fn_8006A924(StateObj8006A924* self, s32 param) {
    if (!self->m_func) {
        StateFunc8006A924 f = lbl_802800FC;
        if (self->m_func != f) {
            if (self->m_func) {
                self->m_27c = -1;
                (self->*self->m_func)(0);
            }
            self->m_func = f;
            self->m_27c = 0;
            (self->*self->m_func)(0);
        }
    }
    (self->*self->m_func)(param);
}

#pragma pop
extern "C" int fn_80069DE0(u8* p);
extern "C" void fn_8006AF00(u8* p) {
    fn_80069DE0(p);
}

extern "C" int fn_8006AF20(void) {
    fn_800636F4((s32)&lbl_802FC930, (u8*)lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern "C" void fn_8006A29C(void);
extern "C" void fn_8006AF58(void) {
    fn_8006A29C();
}

extern "C" int fn_8006AF78(void* param_1) {
    if (lbl_802FF17C == 1) {
        void* p_24c = *(void**)((u8*)param_1 + 0x24c);
        void* p2 = *(void**)((u8*)p_24c + 4);
        void* p3 = *(void**)((u8*)p2 + 4);
        f32 f0 = *(f32*)((u8*)*(void**)((u8*)param_1 + 0x254) + 0x10);
        int i0 = (int)f0;
        fn_8000DDAC((void*)((u8*)param_1 + 0x250), (void*)((u8*)p3 + 0x58), i0);
        fn_80010CE4(*(void**)((u8*)param_1 + 0x24c));
        
        void* p_24c_2 = *(void**)((u8*)param_1 + 0x24c);
        p2 = *(void**)((u8*)p_24c_2 + 4);
        p3 = *(void**)((u8*)p2 + 4);
        void* p6 = *(void**)((u8*)param_1 + 0x258);
        fn_801AFE98((void*)((u8*)p3 + 0x58), p6);
        
        if (*(u8*)((u8*)param_1 + 0x27e) != 0) {
            void* p7 = *(void**)((u8*)param_1 + 0x25c);
            void* p8 = *(void**)((u8*)p7 + 4);
            u8 p9 = *(u8*)((u8*)param_1 + 0x27f);
            fn_8000DDAC((void*)((u8*)param_1 + 0x260), (void*)((u8*)p8 + 0x58), (s32)p9);
            fn_8000EBB8(*(void**)((u8*)param_1 + 0x25c));
        }
    }
    return 1;
}

extern "C" BOOL fn_8006B028(void);
extern "C" BOOL fn_8006B028(void)
{
    return TRUE;
}

extern "C" u8 fn_8006B030(u8* param_1) {
    u8 val = *param_1;
    if (val != 0) {
        val = val - 1;
        *param_1 = val;
    }
    return *param_1;
}

extern u8 lbl_80247484[];
extern f32 lbl_80300438;
extern f32 lbl_8030043C;
extern f32 lbl_80300440;
extern f32 lbl_80300444;
extern f32 lbl_80300448;
extern f32 lbl_8030044C;
extern f32 lbl_80300450;
extern "C" void fn_8006B04C(u8* p) {
    *(void**)(p + 0x0) = lbl_80247484;
    *(f32*)(p + 0x4) = -38.0f;
    *(f32*)(p + 0x8) = 397.0f;
    *(f32*)(p + 0xc) = 335.0f;
    *(f32*)(p + 0x10) = 0.55f;
    *(f32*)(p + 0x14) = 0.55f;
    *(f32*)(p + 0x18) = 1.0f;
    *(s16*)(p + 0x1c) = 0;
    *(s16*)(p + 0x1e) = 0;
    *(s16*)(p + 0x20) = 0;
    *(s16*)(p + 0x3c) = 0x32;
    *(s16*)(p + 0x3e) = 0x400;
    *(s16*)(p + 0x40) = 0x10;
    *(s16*)(p + 0x42) = 7;
    *(s16*)(p + 0x44) = 0x78;
    *(s16*)(p + 0x48) = 0x300;
    *(u8*)(p + 0x4a) = 0;
    *(u8*)(p + 0x4b) = 0;
    *(u8*)(p + 0x4c) = 0;
    *(u8*)(p + 0x4d) = 0;
    *(s16*)(p + 0x46) = 0;
    *(f32*)(p + 0x30) = 0.001f;
    *(s16*)(p + 0x36) = 0xb;
    *(s16*)(p + 0x38) = 7;
    *(s16*)(p + 0x34) = 7;
    *(s16*)(p + 0x3a) = 8;
    *(f32*)(p + 0x24) = 0.01f;
    *(f32*)(p + 0x28) = *(s16*)(p + 0x42);
    *(f32*)(p + 0x2c) = 1.0f;
    *(u8*)(p + 0x4e) = 0;
    *(u8*)(p + 0x4f) = 0;
}

extern "C" void fn_8006B240(void);
extern "C" void fn_8006B13C(void) {
    fn_8006B240();
}

extern "C" void fn_8006B8A0(void) {
}

extern "C" void fn_8006B8A4(void* param_1) {
    s32 val = *(s32*)((u8*)lbl_802BB0FC + 0x44);
    if (val < 0xc) return;
    if (0xe <= val) return;
    
    u32 flags = *(u32*)((u8*)lbl_802B7CA0 + 0x3f4);
    if ((flags & 0x08) == 0) return;
    
    *(u8*)((u8*)param_1 + 0x31b) = 1;
    
    u32 flags2 = *(u32*)((u8*)lbl_802B7CA0 + 0x3f4);
    if ((flags2 & 0x80) != 0) {
        void* ptr_base = *(void**)((u8*)param_1 + 0x2a4);
        *(f32*)((u8*)ptr_base + 0x10) = lbl_80300468;
    } else {
        void* ptr_base = *(void**)((u8*)param_1 + 0x2a4);
        *(f32*)((u8*)ptr_base + 0x10) = lbl_8030046C;
    }
    fn_8006C5B0(1);
}

extern "C" void fn_8006B928(void* param_1) {
    u32* arr = (u32*)lbl_80280230;
    u32 i = 0;
    
    for (int j = 0; j < 5; j++) {
        u32 arr_val = arr[j];
        u32 saved_val = *(u32*)((u8*)param_1 + 0x2fc);
        if (arr_val <= saved_val) {
            u32 idx_val = arr[i];
            *(u32*)((u8*)param_1 + 0x2fc) = idx_val;
            return;
        }
        i++;
    }
    
    void* result = (void*)fn_80022434(0x3c);
    *(u32*)((u8*)param_1 + 0x2cc) = (u32)result;
}

extern u32 lbl_802FC710;
extern "C" void fn_8006B9A4(void* param_1) {
    fn_8006C404();
    if (*(s32*)((u8*)param_1 + 0x2fc) < 480000) {
        *(s32*)((u8*)param_1 + 0x2cc) = *(s32*)((u8*)param_1 + 0x2cc) - 1;
        if (*(s32*)((u8*)param_1 + 0x2cc) == 0) {
            lbl_802FC710 = lbl_802FC710 * 0x19660d + 0x3c6ef35f;
            *(u16*)((u8*)param_1 + 0x30e) += (lbl_802FC710 << 1) & 0xC000;
            fn_8006C5B0((s32)param_1, 2);
        }
    } else {
        fn_8006C5B0((s32)param_1, 6);
    }
}

extern "C" void fn_8006BA44(void* param_1) {
    *(u16*)((u8*)param_1 + 0x310) = 0;
    fn_80030534((u8*)param_1 + 0x2ec, 0x58, 1);
}

extern "C" void fn_8006BA78(void* param_1) {
    fn_8006C404();
    *(u16*)((u8*)param_1 + 0x310) += *(s16*)((u8*)lbl_802BF814 + 0x1fc);
    if (*(u16*)((u8*)param_1 + 0x310) >= *(s16*)((u8*)lbl_802BF814 + 0x1fa)) {
        *(u16*)((u8*)param_1 + 0x310) = *(s16*)((u8*)lbl_802BF814 + 0x1fa);
        fn_8006C5B0((s32)param_1, 3);
    }
}

extern "C" void fn_8006BADC(void) {
}

extern "C" void fn_8006BAE0(void* param_1) {
    fn_8006C404();

    s32 limit = *(s32*)((u8*)&lbl_802BB0FC + 0x58);
    s32 val = *(s32*)((u8*)param_1 + 0x2fc);
    s32 flag = 0;

    if (val <= limit) {
        flag = 1;
    }
    if (flag != 0) {
        fn_8006C5B0((s32)param_1, 4);

        void* ptr = &lbl_802BF814;
        s16 counter = *(s16*)((u8*)ptr + 0x1f8);
        counter += 10;
        *(s16*)((u8*)ptr + 0x1f8) = counter;

        if ((s32)counter > 0xff) {
            *(s16*)((u8*)ptr + 0x1f8) = 0xff;
        }
    }
}

extern "C" void fn_8006BB68(void* param_1) {
    u32 val1 = *(u16*)((u8*)param_1 + 0x30e);
    *(u16*)((u8*)param_1 + 0x312) = (val1 & 0xf000) + 0x800;

    u16 val2 = *(u16*)((u8*)param_1 + 0x310);

    union { u32 i[2]; f64 d; } conv;
    conv.i[0] = 0x43300000;
    conv.i[1] = val2;

    f32 diff = conv.d - lbl_80300470;
    *(f32*)((u8*)param_1 + 0x2dc) = diff;

    *(s32*)((u8*)param_1 + 0x2cc) = 0;

    fn_80030534((void*)((u8*)param_1 + 0x2ec), 0x59, 1);
    fn_8002F358(0x6a, 0);
}

extern "C" f32 fn_80116314(void* p, f32 a, f32 b, f32 c, f32 d);
extern "C" void fn_8006BBDC(u8* p) {
    fn_8006C404();
    if (fn_80116314(p + 0x2dc, lbl_80300460, *(f32*)((u8*)lbl_802BF814 + 0x1e0), *(f32*)((u8*)lbl_802BF814 + 0x1e4), *(f32*)((u8*)lbl_802BF814 + 0x1e8)) == lbl_80300460) {
        fn_8006C5B0((s32)p, 5);
    }
    *(s16*)(p + 0x310) = (s16)*(f32*)(p + 0x2dc);
    if ((int)*(u16*)(p + 0x310) < (int)*(s16*)((u8*)lbl_802BF814 + 0x204)) {
        if (*(u16*)(p + 0x312) < *(u16*)(p + 0x30e) && (*(u16*)(p + 0x312) != 0x800 || *(u16*)(p + 0x30e) < 0x1800)) {
            fn_8002F358(0xf6, 0);
            *(u16*)(p + 0x312) = *(u16*)(p + 0x312) + 0x1000;
            *(s32*)(p + 0x2cc) = *(s32*)(p + 0x2cc) + 1;
            *(u32*)(p + 0x2cc) = *(u32*)(p + 0x2cc) & 0xf;
        }
    } else {
        *(u16*)(p + 0x312) = (*(u16*)(p + 0x30e) & 0xf000) + 0x800;
    }
}

extern "C" void fn_8006BCD0(void* param_1) {
    *(s32*)((u8*)param_1 + 0x2cc) = 0;
    *(void**)((u8*)param_1 + 0x2d0) = fn_80022434(0x1e);
}

extern "C" void fn_8006C38C(void) {}

extern "C" void fn_8006C390(s32 param_1) {
    f32 v[3];
    v[0] = lbl_80300460;
    v[1] = lbl_80300460;
    v[2] = lbl_80300460;
    fn_801163D4((u8*)param_1 + 0x144, v);
    if (lbl_80300478 == lbl_80300460) {
        *(u8*)((u8*)param_1 + 0x31b) = 0;
        fn_80017FCC((void*)param_1);
    }
}

extern "C" void fn_8006C5B0(s32 param_1, s32 param_2) {
    u32* e = (u32*)(lbl_802804C0 + param_2 * 12);
    u32 a;
    u32 b;
    *(s32*)((u8*)param_1 + 0x2c8) = param_2;
    a = e[0];
    b = e[1];
    *(u32*)((u8*)param_1 + 0x2bc) = a;
    *(u32*)((u8*)param_1 + 0x2c0) = b;
    *(u32*)((u8*)param_1 + 0x2c4) = e[2];
    *(u32*)((u8*)param_1 + 0x2cc) = 0;
    *(u32*)((u8*)param_1 + 0x2d0) = 0;
    *(u32*)((u8*)param_1 + 0x2d4) = 0;
    *(u32*)((u8*)param_1 + 0x2d8) = 0;
    *(u32*)((u8*)param_1 + 0x2e8) = 1;
}

extern "C" void fn_8006C5FC(s32 param_1) {
    if (*(s32*)((u8*)param_1 + 0x2e8) != 0) {
        fn_801E10DC((void*)param_1, lbl_80280418 + *(s32*)((u8*)param_1 + 0x2c8) * 12);
        *(u32*)((u8*)param_1 + 0x2e8) = 0;
    }
    fn_801E10DC((void*)param_1, (u8*)param_1 + 0x2bc);
}

extern s32 lbl_80280284[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_8006C950(u8* param_1) {
    s32* tbl;
    u8* base;
    u8* p;
    s32 i;
    param_1[0x318] = 0;
    tbl = lbl_80280284;
    base = lbl_80280248;
    p = param_1;
    for (i = 0; i <= 5; i++) {
        if (*tbl >= 0) {
            fn_80022438(*(void**)(p + 0x270), base, *tbl, 0, lbl_80300460, lbl_8030046C, lbl_80300460, lbl_80300464);
            param_1[0x318] |= 1 << i;
        }
        p += 4;
        tbl++;
    }
}
#pragma pop

#pragma use_lmw_stmw off
extern "C" void fn_8006C9F4(u8* p) {
    s32 i;
    s32 val;
    *(u32*)(p + 0x308) = 0;
    for (i = 0; i <= 7; i++) {
        val = lbl_802802A8[i];
        if (val >= 0) {
            fn_80022438(*(void**)(p + 0x270 + i * 4), lbl_80280248, val, 0, lbl_80300460, lbl_80300448, lbl_80300460, lbl_80300464);
            *(u32*)(p + 0x308) = *(u32*)(p + 0x308) | (1 << i);
        }
    }
}

extern s32 lbl_802802C8[];
extern "C" void fn_8006CA98(u8* p) {
    s32 i;
    s32 val;
    *(u32*)(p + 0x308) = 0;
    for (i = 0; i <= 7; i++) {
        val = lbl_802802C8[i];
        if (val >= 0) {
            fn_80022438(*(void**)(p + 0x270 + i * 4), lbl_80280248, val, 0, lbl_80300460, lbl_80300448, lbl_80300460, lbl_80300464);
            *(u32*)(p + 0x308) = *(u32*)(p + 0x308) | (1 << i);
        }
    }
}

extern "C" void fn_8006CC58(void) {}

struct UnkVObj6CC5C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(s32); virtual void v26(); virtual u8* v27(s32);
};
typedef void (*VFn_vi)(void*, s32);
typedef void (*VFn_v)(void*);
typedef u8* (*VFn_pi)(void*, s32);
extern "C" void fn_8006CC5C(u8* p) {
    u16 num;
    u8* model;
    UnkVObj6CC5C* obj;
    s32 i;
    u16 j;
    for (i = 0; i <= 5; i++) {
        model = *(u8**)(*(u8**)(*(u8**)(p + 0x270 + i * 4) + 4) + 4);
        num = *(u16*)(model + 0x5c);
        for (j = 0; j < num; j++) {
            obj = (*(UnkVObj6CC5C***)(model + 0x60))[j];
            (*(UnkVObj6CC5C**)((u8*)obj + 0x24))->v25(0);
            obj->v9();
            u8* r = (*(UnkVObj6CC5C**)((u8*)obj + 0x2c))->v27(2);
            r[3] = ((u8*)lbl_802BF814)[0x20c + i];
        }
    }
}

extern "C" u32 fn_8006CD30(void* param_1) {
    return ((s32)(*(u16*)((u8*)param_1 + 0x30e) + 0x2000) / 0x4000) & 3;
}

extern "C" u32 fn_8006CD48(void* param_1) {
    u8* p = (u8*)param_1;
    u32 r;
    if (*(s32*)(p + 0x300) < 0) {
        u32 v = ((s32)(*(u16*)(p + 0x30e) + 0x2000) / 0x4000) & 3;
        *(u32*)(p + 0x300) = v;
        r = v;
    } else {
        r = *(s32*)(p + 0x300);
    }
    *(s32*)(p + 0x300) += 1;
    *(u32*)(p + 0x300) &= 3;
    return r;
}

extern "C" u32 fn_8006CD98(void* param_1, u8 param_2) {
    u8* p = (u8*)param_1;
    if (*(s32*)(p + 0x2c8) > 4) {
        return 0;
    }
    return (u32)__cntlzw(p[0x31a] & (1 << param_2)) >> 5;
}

extern "C" int fn_8006B15C(void);
extern "C" void fn_8006CDCC(void) {
    fn_8006B15C();
}

extern "C" int fn_8006CDEC(void) {
    fn_800636F4((s32)&lbl_80280248, (u8*)lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern "C" void fn_8006B6D8(void);
extern "C" void fn_8006CE28(void) {
    fn_8006B6D8();
}

extern "C" BOOL fn_8006CFD0(void);
extern "C" BOOL fn_8006CFD0(void)
{
    return TRUE;
}

