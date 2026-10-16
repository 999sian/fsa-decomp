#include "types.h"
extern u8 lbl_8029F8D8[];
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
extern "C" void fn_800636F4(s32, void*, s32);
extern "C" void fn_8000DDAC(void*, void*, s32);
extern "C" void fn_80010CE4(void*);
extern "C" void fn_801AFE98(void*, void*);
extern "C" void fn_8000EBB8(void*);
extern "C" void fn_80022438(void*, s32, u16, u16);
extern u8 lbl_802FF17C;
extern s32 lbl_802FF170;
extern s32 lbl_802FC910;
extern "C" int fn_80068190(u8* p);
extern "C" int fn_801E2F8C(s32 v);
extern u16 lbl_80280080[];
extern u16 lbl_802FC94C[];
extern int lbl_802FC930;  // SDA label
extern void* lbl_802B7CA0[];  // Address table
extern void* lbl_802BB0FC[];
extern void* lbl_802BF814[];
extern f64 lbl_80300470;  // SDA label
extern void fn_8002F358(int, int);
extern f32 lbl_80300468;  // SDA label
extern f32 lbl_8030046C;  // SDA label
extern void* lbl_80280230[];
extern "C" void fn_8006C404(void);
extern "C" void fn_8006C5B0(s32);
extern "C" void fn_80030534(void*, int, int);
extern "C" void* fn_80022434(s32);
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

extern "C" void fn_80063E60(void* param_1, void* param_2) {
    fn_801AE194();
    u32 fn_addr = *(u32*)((u8*)param_1 + 0xf4);
    if (fn_addr != 0) {
        ((void (*)(void*, void*))(fn_addr))(param_1, param_2);
    }
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

extern "C" int fn_801E10A0(void* p);
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

extern "C" void fn_80064D18(void** p) {
    p[0] = lbl_8027F6DC;
    p[1] = 0;
    p[0] = lbl_8027FB48;
    p[2] = 0;
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

extern "C" void fn_800680A4(void);
extern "C" void fn_80067FE8(void) {
    fn_800680A4();
}

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

extern "C" void fn_80068B30(void);
extern "C" void fn_80068B10(void) {
    fn_80068B30();
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
        fn_80022438(ptr, 0, idx_val, data_1);
        
        void* ptr2 = *(void**)((u8*)param_1 + 0x24c);
        f32 f0 = *(f32*)((u8*)ptr2 + 0x1c);
        *(f32*)((u8*)param_1 + 0x274) = f0;
    }
    return 0;
}

extern "C" void fn_80069DE0(void);
extern "C" void fn_8006AF00(void) {
    fn_80069DE0();
}

extern "C" int fn_8006AF20(void) {
    fn_800636F4(0, (void*)0x1e258, 0x40);
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

extern "C" void fn_8006B9A4(void* param_1) {
    fn_8006C404();
    if (*(u32*)((u8*)param_1 + 0x2fc) < 480000) {
        *(s32*)((u8*)param_1 + 0x2cc) = *(s32*)((u8*)param_1 + 0x2cc) - 1;
        if (*(s32*)((u8*)param_1 + 0x2cc) == 0) {
            u32 rng = *(u32*)(0x802FC710);
            rng = rng * 0x19660d + 0x3c6f35f;
            *(u32*)(0x802FC710) = rng;
            u16 val = *(u16*)((u8*)param_1 + 0x30e);
            val = val + ((rng >> 1) & 0x6000);
            *(u16*)((u8*)param_1 + 0x30e) = val;
            fn_8006C5B0((s32)param_1);
        }
    } else {
        fn_8006C5B0((s32)param_1);
    }
}

extern "C" void fn_8006BA44(void* param_1) {
    *(u16*)((u8*)param_1 + 0x310) = 0;
    fn_80030534((u8*)param_1 + 0x2ec, 0x58, 1);
}

extern "C" void fn_8006BA78(void* param_1) {
    fn_8006C404();
    
    void* ptr = &lbl_802BF814;
    s16 offset1 = *(s16*)((u8*)ptr + 0x1fc);
    s16 offset2 = *(s16*)((u8*)ptr + 0x1fa);
    
    u16 val = *(u16*)((u8*)param_1 + 0x310);
    val = val + offset1;
    *(u16*)((u8*)param_1 + 0x310) = val;
    
    if ((s32)val >= (s32)offset2) {
        *(u16*)((u8*)param_1 + 0x310) = (u16)offset2;
        fn_8006C5B0((s32)param_1);
    }
}

extern "C" void fn_8006BADC(void) {
}

extern "C" void fn_8006BAE0(void* param_1) {
    fn_8006C404();
    
    s32 limit = *(s32*)((u8*)&lbl_802BB0FC + 0x58);
    s32 val = *(s32*)((u8*)param_1 + 0x2fc);
    
    if (val <= limit) {
        fn_8006C5B0((s32)param_1);
        
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
    f64 const_val = lbl_80300470;
    
    u16 val1 = *(u16*)((u8*)param_1 + 0x30e);
    u16 masked = val1 & 0xf000;
    *(u16*)((u8*)param_1 + 0x312) = masked + 0x800;
    
    u16 val2 = *(u16*)((u8*)param_1 + 0x310);
    
    union { u32 i[2]; f64 d; } conv;
    conv.i[0] = 0x43300000;
    conv.i[1] = val2;
    
    f64 double_val = conv.d;
    f32 result = (f32)(double_val - const_val);
    *(f32*)((u8*)param_1 + 0x2dc) = result;
    
    *(s32*)((u8*)param_1 + 0x2cc) = 0;
    
    fn_80030534((void*)((u8*)param_1 + 0x2ec), 0x59, 1);
    fn_8002F358(0x6a, 0);
}

extern "C" void fn_8006C38C(void) {}

extern "C" void fn_8006B15C(void);
extern "C" void fn_8006CDCC(void) {
    fn_8006B15C();
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

