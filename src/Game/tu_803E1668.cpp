#include "types.h"

class Screen803E4650 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual class Pane803E4650* v3C(s32 a, s32 b);
};
class Pane803E4650 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(f32 x, f32 y);
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void setAlpha(s32 a);
};
class Screen803EDBF0 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual class Pane803E4650* v3C(s32 a, s32 b, s32 c);
};
extern "C" u8 lbl_80477970[];
extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* this_, f32 x, f32 y, void* ctx);
extern "C" void fn_80440EE8(void* p);
extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AED8;

extern "C" void* fn_804031C4(u32 type, void* name);
extern "C" void fn_803832BC(char* s, s32 a, s32 b, s32 c, s32 d);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);

class J2DGrafContext;
class J2DScreen {
public:
    void draw(f32, f32, const J2DGrafContext*);
};
struct Tu803E1668Obj {};
typedef void (Tu803E1668Obj::*Tu803E1668Fn)();
struct T803ED83C;
typedef void (T803ED83C::*PMF803ED83C)();
extern PMF803ED83C lbl_804B0754[];
extern "C" void* lbl_8053AD30;
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_804B0B00[];
class T803EDF94Obj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08(s32 a);
};
extern "C" u32 fn_80309C4C(void* a, s32 b, s32 c);
extern "C" u32 fn_80309A9C(void* a, s32 b, s32 c);


extern void* lbl_8053AF80;
extern "C" u8* lbl_8053AAF8;
extern "C" void* lbl_8053AD30;
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* a, s32 b);
extern "C" int fn_804366B8(void* p);
extern "C" void fn_80436668(void* p);
extern "C" void fn_80458880(void* mgr, s32 id, s32 a);
extern void* lbl_8053AEC0;
extern "C" void fn_8043670C(void* p, s32 a);
extern "C" void fn_80431A9C(void* mgr, s32 id, u8 v, s32 a);
extern "C" u8 fn_80402940(void* p, s32 id, f32 a, f32 b, s32 c);
extern "C" void fn_803E29C8(u8* param_1) {
    fn_8043670C(*(void**)(param_1 + 0x5c), 0);
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xe;
}

extern "C" void fn_803E2A0C(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xd;
}

extern "C" void fn_803E3320(u8* param_1) {
    s32 j = 0;
    s32 i;
    *(s16*)(param_1 + 0x254) = j;
    *(s32*)(param_1 + 0x1e0) = 5;
    if (*(s32*)(param_1 + 0x1bc) == 0) {
        if (*(s32*)(param_1 + 0x1b8) == 1) {
            lbl_8053AAF8[0x82] |= 0x10;
            lbl_8053AAF8[0x82] &= ~0x20;
            lbl_8053AAF8[0x82] &= ~0x40;
            lbl_8053AAF8[0x82] &= 0x7f;
            lbl_8053AAF8[0x82] |= 0x1;
            lbl_8053AAF8[0x82] &= ~0x2;
            lbl_8053AAF8[0x82] &= ~0x4;
            lbl_8053AAF8[0x82] &= ~0x8;
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
                u8* p = lbl_8053AAF8;
                p[0x83] &= ~0x3;
                p[0x83] |= 0x1;
            } else {
                u8* p = lbl_8053AAF8;
                p[0x83] &= ~0x3;
                p[0x83] |= 0x2;
            }
            lbl_8053AAF8[0x83] &= ~0xc;
            lbl_8053AAF8[0x83] &= ~0x30;
            lbl_8053AAF8[0x83] &= 0x3f;
        }
    } else if (*(s32*)(param_1 + 0x1b8) == 0) {
        for (i = 0; i < 4; i++) {
            if (i < *(s32*)(param_1 + 0x1bc) + 1) {
                lbl_8053AAF8[0x82] |= (u8)(1 << i);
                u8* p = lbl_8053AAF8;
                p[0x83] &= ~(u8)(3 << j);
                p[0x83] |= (u8)(1 << j);
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
            }
            j += 2;
        }
    }
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xb;
}

extern "C" void fn_803E3548(u8* param_1) {
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 10;
}

extern "C" void fn_803E3C00(u8* param_1) {
    s32 n = *(s32*)(param_1 + 0x1bc);
    if (n == 0) {
        fn_80431A9C(lbl_8053AEC0, 0xa9, (u8)(n + 1), 0);
    } else {
        fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(n + 1), 0);
    }
    param_1[0x26c] = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 8;
}

extern "C" void fn_803E3C80(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 7;
}

extern "C" void fn_803E3C94(u8* param_1) {
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 6;
}

extern "C" void* fn_804031C4(u32 type, void* name);
extern "C" void fn_803832BC(char* s, s32 a, s32 b, s32 c, s32 d);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);
extern "C" void fn_803E3CB0(u8* p) {
    u8* base = lbl_80477970;
    s32 i;
    s32 j;
    u8* q;
    u8* tA;
    u8* tB;
    u8* tC;
    u8* b;
    if (*(s32*)(p + 0x1bc) == 1) {
        void* g = fn_804031C4(0x54494d47, base + 0xfec);
        void* t = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50746e3032ULL);
        ((void (**)(void*, void*, s32))*(void**)t)[68](t, g, 0);
        t = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50746e3031ULL);
        ((void (**)(void*, void*, s32))*(void**)t)[68](t, g, 0);
    } else if (*(s32*)(p + 0x1bc) == 2) {
        void* g = fn_804031C4(0x54494d47, base + 0x1000);
        void* t = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50746e3032ULL);
        ((void (**)(void*, void*, s32))*(void**)t)[68](t, g, 0);
        t = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50746e3031ULL);
        ((void (**)(void*, void*, s32))*(void**)t)[68](t, g, 0);
    } else {
        void* g = fn_804031C4(0x54494d47, base + 0x1014);
        void* t = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50746e3032ULL);
        ((void (**)(void*, void*, s32))*(void**)t)[68](t, g, 0);
        t = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50746e3031ULL);
        ((void (**)(void*, void*, s32))*(void**)t)[68](t, g, 0);
    }
    {
        char* s1 = getStringPtr__10J2DTextBoxCFv(((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x54746b673031ULL));
        char* s2 = getStringPtr__10J2DTextBoxCFv(((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x54746b673032ULL));
        fn_803832BC(s1, 0x3e, 0, 0, 0);
        fn_803832BC(s2, 0x3e, 0, 0, 0);
    }
    {
        void* o;
        *(f32*)(p + 0xa0) = -300.0f;
        o = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x4e646174613033ULL);
        ((void (**)(void*, f32, f32))*(void**)o)[4](o, *(f32*)(p + 0x98), *(f32*)(p + 0x9c) + *(f32*)(p + 0xa0));
        *(f32*)(p + 0xac) = -100.0f;
        o = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x4e646174613035ULL);
        ((void (**)(void*, f32, f32))*(void**)o)[4](o, *(f32*)(p + 0xa4), *(f32*)(p + 0xa8) + *(f32*)(p + 0xac));
        *(f32*)(p + 0xb8) = -200.0f;
        o = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x4e646174613036ULL);
        ((void (**)(void*, f32, f32))*(void**)o)[4](o, *(f32*)(p + 0xb0), *(f32*)(p + 0xb4) + *(f32*)(p + 0xb8));
        *(f32*)(p + 0xbc) = -200.0f;
        fn_80402E08(*(void**)(p + 0x78), 0.0f, *(f32*)(p + 0xbc));
        *(f32*)(p + 0xe0) = 200.0f;
        o = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50706c6c626b3032ULL);
        ((void (**)(void*, f32, f32))*(void**)o)[4](o, *(f32*)(p + 0xc0), *(f32*)(p + 0xd0) + *(f32*)(p + 0xe0));
        *(f32*)(p + 0xe4) = 200.0f;
        o = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50706c6c626b3132ULL);
        ((void (**)(void*, f32, f32))*(void**)o)[4](o, *(f32*)(p + 0xc4), *(f32*)(p + 0xd4) + *(f32*)(p + 0xe4));
        *(f32*)(p + 0xe8) = 200.0f;
        o = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50706c6c626b3232ULL);
        ((void (**)(void*, f32, f32))*(void**)o)[4](o, *(f32*)(p + 0xc8), *(f32*)(p + 0xd8) + *(f32*)(p + 0xe8));
        *(f32*)(p + 0xec) = 200.0f;
        o = ((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), 0x50706c6c626b3332ULL);
        ((void (**)(void*, f32, f32))*(void**)o)[4](o, *(f32*)(p + 0xcc), *(f32*)(p + 0xdc) + *(f32*)(p + 0xec));
    }
    tA = base + 0x840;
    tB = base + 0x8e0;
    tC = base + 0x8c0;
    q = p;
    for (i = 0; i < 4; i++) {
        if (i <= *(s32*)(p + 0x1bc)) {
            u8* a = (u8*)((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), *(u64*)tA);
            a[0xb0] = 1;
            b = tB + 0x10;
            for (j = 2; j < 4; j++) {
                u8* c = (u8*)((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), *(u64*)b);
                c[0xb0] = 1;
                b += 8;
            }
            {
                u8* c = (u8*)((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), *(u64*)tC);
                ((void (**)(void*, s32))*(void**)c)[9](c, 0xff);
            }
            *(s32*)(q + 0x230) = *(s16*)(*(u8**)(q + 0x38) + 6);
            *(s32*)(q + 0x240) = *(s16*)(*(u8**)(q + 0x48) + 6);
        } else {
            u8* a = (u8*)((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), *(u64*)tA);
            a[0xb0] = 0;
            b = tB + 0x10;
            for (j = 2; j < 4; j++) {
                u8* c = (u8*)((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), *(u64*)b);
                c[0xb0] = 0;
                b += 8;
            }
            {
                u8* c = (u8*)((void* (**)(void*, u64))*(void**)*(void**)(p + 8))[15](*(void**)(p + 8), *(u64*)tC);
                ((void (**)(void*, s32))*(void**)c)[9](c, 0x80);
            }
            *(s32*)(q + 0x230) = 0;
            *(s32*)(q + 0x240) = 0;
        }
        tA += 8;
        tB += 0x20;
        tC += 8;
        q += 4;
    }
    *(s16*)(p + 0x254) = 0;
    *(s16*)(p + 0x25e) = 0;
    *(s16*)(p + 0x25c) = 0;
    p[0x26b] = 0;
    *(s16*)(p + 0x250) = -1;
    *(s16*)(p + 0x252) = -1;
    *(s16*)(p + 0x262) = 0;
    *(s32*)(p + 0x220) = 0;
    *(s32*)(p + 0x224) = 0;
    *(s32*)(p + 0x228) = 0;
    *(s32*)(p + 0x22c) = 0;
    *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
    *(s32*)(p + 0x1d4) = 5;
}

extern "C" void fn_803E4308(u8* param_1) {
    *(s32*)(param_1 + 0x220) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1e0) = 5;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 4;
}

extern "C" void fn_803E4330(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 3;
}

extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern "C" void fn_803E4344(u8* param_1) {
    void* obj;
    void* p;

    *(f32*)(param_1 + 0xf8) = -150.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x62620000, 0x506d6164, 0x62623037);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0xf0), *(f32*)(param_1 + 0xf4) + *(f32*)(param_1 + 0xf8));
    *(f32*)(param_1 + 0xfc) = -200.0f;
    fn_80402E08(*(void**)(param_1 + 0x78), 0.0f, *(f32*)(param_1 + 0xfc));
    *(f32*)(param_1 + 0x120) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x70620000, 0x506e6f, 0x70623034);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0x100) + *(f32*)(param_1 + 0x120), *(f32*)(param_1 + 0x110));
    *(f32*)(param_1 + 0x124) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x70620000, 0x506e6f, 0x70623038);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0x104) + *(f32*)(param_1 + 0x124), *(f32*)(param_1 + 0x114));
    *(f32*)(param_1 + 0x128) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x70620000, 0x506e6f, 0x70623132);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0x108) + *(f32*)(param_1 + 0x128), *(f32*)(param_1 + 0x118));
    *(f32*)(param_1 + 0x12c) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x70620000, 0x506e6f, 0x70623136);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0x10c) + *(f32*)(param_1 + 0x12c), *(f32*)(param_1 + 0x11c));
    *(f32*)(param_1 + 0x138) = 400.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x74610000, 0x4e6461, 0x74613032);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0x130) + *(f32*)(param_1 + 0x138), *(f32*)(param_1 + 0x134));
    *(f32*)(param_1 + 0x14c) = 400.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x74610000, 0x4e6461, 0x74613035);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0x13c) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x140));
    obj = *(void**)(param_1 + 4);
    p = ((void* (**)(void*, s32, s32, s32))*(void**)obj)[15](obj, 0x4e0000, 0x4e6461, 0x74613037);
    ((void (**)(void*, f32, f32))*(void**)p)[4](p, *(f32*)(param_1 + 0x144) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x148));
    *(s32*)(param_1 + 0x220) = 0;
    *(s32*)(param_1 + 0x1e0) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 2;
}

extern "C" void fn_803E45FC(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 1;
}

extern "C" void fn_803E4610(u8* param_1) {
    *(s32*)(param_1 + 0x1e0) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0;
}

extern "C" void fn_803E462C(u8* param_1) {
    fn_80436668(*(void**)(param_1 + 0x5c));
}

extern "C" void fn_803E4650(u8* p) {
    s32 i;
    s32 k;
    s32 n;
    f32 t;
    f32 off;
    s32* tA = (s32*)(lbl_80477970 + 0x9c0);
    s32* tB = (s32*)(lbl_80477970 + 0x9e0);
    s32* tC = (s32*)(lbl_80477970 + 0xa00);
    Pane803E4650* pane;

    n = *(s32*)(p + 0x1e0);
    if (n < 30) {
        t = (f32)(n * n) / 900.0f;
    } else {
        n -= 30;
        t = 1.0f - (f32)(n * n) / 900.0f;
    }
    for (i = 0; i < 4; i++, tA += 2, tB += 2, tC += 2) {
        if (i <= *(s32*)(p + 0x1bc)) {
            if (*(s32*)(p + 0x1c0 + i * 4) < 4) {
                pane = ((Screen803E4650*)*(void**)(p + 0x10))->v3C(tA[0], tA[1]);
                pane->setAlpha((s32)(160.0f * t));
            }
            if (*(s32*)(p + 0x1c0 + i * 4) == 3) {
                pane = ((Screen803E4650*)*(void**)(p + 0x10))->v3C(tB[0], tB[1]);
                pane->setAlpha((s32)(t * (f32)p[0x26a]));
                pane = ((Screen803E4650*)*(void**)(p + 0x10))->v3C(tC[0], tC[1]);
                pane->setAlpha((s32)(t * (f32)p[0x26a]));
            }
            if (*(s32*)(p + 0x1d4) != 0xc) {
                k = *(s16*)(p + 0x254 + i * 2);
                if (k >= 5) {
                    k = 10 - k;
                }
                off = (5.0f * (f32)(k * k)) / 25.0f;
                pane = ((Screen803E4650*)*(void**)(p + 0x10))->v3C(tB[0], tB[1]);
                t = getBounds__7J2DPaneFv(pane)[0];
                pane = ((Screen803E4650*)*(void**)(p + 0x10))->v3C(tB[0], tB[1]);
                pane->v10(t, *(f32*)(p + 0x1b0) + off);
                if (*(s32*)(p + 0x1c0 + i * 4) >= 3) {
                    fn_80402E08(*(void**)(p + 0x68 + i * 4), 0.0f, off);
                }
            }
        }
    }
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0x10), 0.0f, 0.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}

extern "C" void fn_803E64A0(u8* p) {
    s32 i;
    s32 k;
    s32 n;
    s32 st;
    f32 u;
    f32 f30;
    f32 f31;
    f32 off;
    f32 h;
    s32* tA = (s32*)(lbl_80477970 + 0xea8);
    s32* tB = (s32*)(lbl_80477970 + 0xec8);
    s32* tC = (s32*)(lbl_80477970 + 0xee8);
    Screen803E4650* scr = (Screen803E4650*)*(void**)(p + 4);
    Pane803E4650* pane;

    st = *(s32*)(p + 0x1d4);
    n = *(s32*)(p + 0x1e0);
    if (n < 30) {
        if (n < 15) {
            u = (f32)(n * n) / 225.0f;
        } else {
            u = (f32)((n - 15) * (n - 15)) / 225.0f;
        }
        f30 = 230.0f * u;
    } else {
        n -= 30;
        u = 1.0f - (f32)(n * n) / 900.0f;
        f30 = u * (f32)p[0x268];
    }
    k = 0;
    if (st == 3 || (st == 4 && *(s16*)(p + 0x254) <= 10)) {
        k = *(s16*)(p + 0x254);
        if (k >= 5) {
            k = 10 - k;
        }
    }
    f31 = 80.0f * u;
    off = (5.0f * (f32)(k * k)) / 25.0f;
    for (i = 0; i < 4; i++, tA += 2, tB += 2, tC += 2) {
        if (i == *(s32*)(p + 0x1bc)) {
            if (i == 0) {
                pane = scr->v3C(0x50736375, 0x726f3032);
                h = getBounds__7J2DPaneFv(pane)[0];
                pane = scr->v3C(0x50736375, 0x726f3032);
                pane->v10(h, *(f32*)(p + 0x1a0) + off);
            } else {
                pane = scr->v3C(tA[0], tA[1]);
                h = getBounds__7J2DPaneFv(pane)[1];
                pane = scr->v3C(tA[0], tA[1]);
                pane->v10(h, *(f32*)(p + 0x110 + i * 4) + off);
            }
        } else {
            pane = scr->v3C(tB[0], tB[1]);
            h = getBounds__7J2DPaneFv(pane)[0];
            pane = scr->v3C(tB[0], tB[1]);
            pane->v10(h, *(f32*)(p + 0x110 + i * 4));
        }
    }
    draw__9J2DScreenFffPC14J2DGrafContext(scr, 0.0f, 0.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}

extern "C" void fn_803E6A28(void) {}

extern "C" void fn_803E6A2C(u8* param_1) {
    if (fn_804366B8(*(void**)(param_1 + 0x5c)) != 0) {
        if (param_1[0x26e] == 0) {
            *(s32*)(param_1 + 0x1dc) = 9;
            param_1[0x26e] = 1;
        }
        if (*(s32*)(param_1 + 0x1bc) == 0) {
            *(s32*)(param_1 + 0x1b8) = 1;
        } else {
            *(s32*)(param_1 + 0x1b8) = 0;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" void fn_803E8210(u8* p) {
    s32 t;
    u8* q;
    u8 a;
    u8 b;
    u8 c;
    s32 i;

    a = 0;
    b = 0;
    c = 0;
    *(s16*)(p + 0x260) = *(s16*)(p + 0x260) + 1;
    if (*(s16*)(p + 0x260) > 0) {
        a = fn_80402940(*(void**)(p + 0x64), 0x16, -200.0f, 0.0f, 0);
    }
    if (*(s16*)(p + 0x260) > 0x10) {
        b = fn_80402940(*(void**)(p + 0x78), 0x18, -200.0f, 0.0f, 0);
    }
    q = p;
    i = 0;
    t = 4;
    for (; i < 4; i++, q += 4) {
        if (i <= *(s32*)(p + 0x1bc) && *(s16*)(p + 0x260) > t) {
            c = fn_80402940(*(void**)(q + 0x68), 0x12, 150.0f, 0.0f, 0);
        }
        t += 5;
    }
    if (a != 0 && b != 0 && c != 0) {
        *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
        *(s32*)(p + 0x1d4) = 0xd;
    }
}

extern "C" void fn_803E9034(u8* p) {
	s32 n;
	s32 t = *(s16*)(p + 0x254);
	if (t != 0) {
		*(s16*)(p + 0x254) = t + 1;
		if (*(s16*)(p + 0x254) > 10) {
			*(s16*)(p + 0x254) = 0;
		}
	}
	*(s32*)(p + 0x220) = *(s32*)(p + 0x220) + 1;
	if (*(s32*)(p + 0x220) >= 0x1e) {
		*(s32*)(p + 0x220) = 0;
	}
	n = *(s32*)(p + 0x1bc);
	if (*(s32*)(p + 0x1d0) != n + 1 && n > 0) {
		p[0x26c] = 0xff;
		(((T803ED83C*)p)->*lbl_804B0754[5])();
	} else {
		if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23c] + 1) != 0) {
			if (*(s32*)(p + 0x1b8) < 3) {
				*(s32*)(p + 0x1dc) = 0xf;
				fn_803E3320(p);
			}
			fn_80458880(lbl_8053AF80, 0xb, -1);
		} else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23c] + 1) != 0) {
			*(s32*)(p + 0x1dc) = 2;
			(((T803ED83C*)p)->*lbl_804B0754[11])();
			fn_80458880(lbl_8053AF80, 0xc, -1);
		} else if (fn_80309A9C(lbl_8053AD30, 4, lbl_80529DEC[0x23c] + 1) != 0) {
			*(s32*)(p + 0x1b8) = *(s32*)(p + 0x1b8) + 1;
			if (*(s32*)(p + 0x1b8) >= 3) {
				*(s32*)(p + 0x1b8) = 0;
			}
			*(s16*)(p + 0x254) = 1;
			*(s32*)(p + 0x1e0) = 0x1e;
			fn_80458880(lbl_8053AF80, 0x26, -1);
		} else if (fn_80309A9C(lbl_8053AD30, 8, lbl_80529DEC[0x23c] + 1) != 0) {
			*(s32*)(p + 0x1b8) = *(s32*)(p + 0x1b8) - 1;
			if (*(s32*)(p + 0x1b8) < 0) {
				*(s32*)(p + 0x1b8) = 2;
			}
			*(s16*)(p + 0x254) = 1;
			*(s32*)(p + 0x1e0) = 0x1e;
			fn_80458880(lbl_8053AF80, 0x26, -1);
		}
	}
	*(s32*)(p + 0x1e0) = *(s32*)(p + 0x1e0) + 1;
	if (*(s32*)(p + 0x1e0) >= 0x3c) {
		*(s32*)(p + 0x1e0) = 0;
	}
}

extern "C" void fn_80403680(void* p);
extern "C" void fn_803EC804(u8* p) {
    s32 j;
    s32 i;
    if (*(s16*)(p + 0x254) != 0) {
        *(s16*)(p + 0x254) += 1;
        if (*(s16*)(p + 0x254) > 10) {
            *(s16*)(p + 0x254) = 0;
        }
    }
    *(s32*)(p + 0x220) += 1;
    if (*(s32*)(p + 0x220) >= 0x1e) {
        *(s32*)(p + 0x220) = 0;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        if (*(s32*)(p + 0x1bc) == 0) {
            *(s32*)(p + 0x1b8) = 1;
            lbl_8053AAF8[0x7e] = 0;
            lbl_8053AAF8[0x82] |= 0x10;
            lbl_8053AAF8[0x82] &= ~0x20;
            lbl_8053AAF8[0x82] &= ~0x40;
            lbl_8053AAF8[0x82] &= 0x7f;
            lbl_8053AAF8[0x82] |= 0x1;
            lbl_8053AAF8[0x82] &= ~0x2;
            lbl_8053AAF8[0x82] &= ~0x4;
            lbl_8053AAF8[0x82] &= ~0x8;
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
                u8* q = lbl_8053AAF8;
                q[0x83] &= ~0x3;
                q[0x83] |= 0x1;
            } else {
                u8* q = lbl_8053AAF8;
                q[0x83] &= ~0x3;
                q[0x83] |= 0x2;
            }
            lbl_8053AAF8[0x83] &= ~0xc;
            lbl_8053AAF8[0x83] &= ~0x30;
            lbl_8053AAF8[0x83] &= 0x3f;
            *(s32*)(p + 0x1dc) = 0xf;
            *(s32*)(p + 0x220) = 0;
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1e0) = 5;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 4;
        } else {
            *(s32*)(p + 0x1b8) = j = 0;
            lbl_8053AAF8[0x7e] = 1;
            if (*(s32*)(p + 0x1d0) == *(s32*)(p + 0x1bc) + 1) {
                for (i = 0; i < 4; i++) {
                    if (i < *(s32*)(p + 0x1bc) + 1) {
                        lbl_8053AAF8[0x82] |= (u8)(1 << i);
                        u8* q = lbl_8053AAF8;
                        q[0x83] &= ~(u8)(3 << j);
                        q[0x83] |= (u8)(1 << j);
                    } else {
                        lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                        lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
                    }
                    j += 2;
                }
                *(s32*)(p + 0x1dc) = 0xf;
            }
            *(s32*)(p + 0x220) = 0;
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1e0) = 5;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 4;
            if (*(s32*)(p + 0x1bc) != lbl_80529DEC[0x23c]) {
                *(s32*)(lbl_80529DEC + 0x130) = 0;
                *(s32*)(lbl_80529DEC + 0x134) = 0;
                *(s32*)(lbl_80529DEC + 0x138) = 0;
                *(s32*)(lbl_80529DEC + 0x13c) = 0;
                *(s32*)(lbl_80529DEC + 0x64) = -1;
            }
        }
        if (*(s32*)(p + 0x1bc) != lbl_80529DEC[0x23c]) {
            fn_80403680(lbl_80529DEC);
        }
        lbl_80529DEC[0x23c] = *(s32*)(p + 0x1bc);
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(p + 0x360) = 2;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        *(s32*)(p + 0x1bc) += 1;
        if (*(s32*)(p + 0x1bc) >= 4) {
            *(s32*)(p + 0x1bc) = 0;
        }
        *(s16*)(p + 0x254) = 1;
        *(s32*)(p + 0x1e0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        *(s32*)(p + 0x1bc) -= 1;
        if (*(s32*)(p + 0x1bc) < 0) {
            *(s32*)(p + 0x1bc) = 3;
        }
        *(s16*)(p + 0x254) = 1;
        *(s32*)(p + 0x1e0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    }
    *(s32*)(p + 0x1e0) += 1;
    if (*(s32*)(p + 0x1e0) >= 0x3c) {
        *(s32*)(p + 0x1e0) = 0;
    }
}

extern "C" void fn_803ED5B4(u8* param_1) {
    if (param_1[0x26e] == 0) {
        *(s32*)(param_1 + 0x1dc) = 9;
        param_1[0x26e] = 1;
    }
    *(s32*)(param_1 + 0x1b8) = 1;
    fn_80458880(lbl_8053AF80, 0xb, -1);
}

extern "C" void fn_803ED604(u8* p) {
    s32 n;
    if (*(s16*)(p + 0x254) != 0) {
        *(s16*)(p + 0x254) += 1;
        if (*(s16*)(p + 0x254) > 10) {
            *(s16*)(p + 0x254) = 0;
        }
    }
    *(s32*)(p + 0x220) += 1;
    if (*(s32*)(p + 0x220) >= 0x1e) {
        *(s32*)(p + 0x220) = 0;
    }
    n = *(s32*)(p + 0x1bc);
    if (*(s32*)(p + 0x1d0) != n + 1 && n > 0) {
        p[0x26c] = 0xff;
        (((T803ED83C*)p)->*lbl_804B0754[5])();
    } else {
        u8* q = lbl_80529DEC;
        if (fn_80309C4C(lbl_8053AD30, 0x1100, q[0x23c] + 1) != 0) {
            if (*(s32*)(p + 0x1b8) < 3) {
                *(s32*)(p + 0x1dc) = 0xf;
                fn_803E3320(p);
            }
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else if (fn_80309C4C(lbl_8053AD30, 0x200, q[0x23c] + 1) != 0) {
            *(s32*)(p + 0x1dc) = 2;
            (((T803ED83C*)p)->*lbl_804B0754[11])();
            fn_80458880(lbl_8053AF80, 0xc, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 4, q[0x23c] + 1) != 0) {
            if (*(s32*)(p + 0x1b8) == 1) {
                *(s32*)(p + 0x1b8) = 2;
            } else {
                *(s32*)(p + 0x1b8) = 1;
            }
            *(s16*)(p + 0x254) = 1;
            *(s32*)(p + 0x1e0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 8, q[0x23c] + 1) != 0) {
            if (*(s32*)(p + 0x1b8) == 1) {
                *(s32*)(p + 0x1b8) = 2;
            } else {
                *(s32*)(p + 0x1b8) = 1;
            }
            *(s16*)(p + 0x254) = 1;
            *(s32*)(p + 0x1e0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    }
    *(s32*)(p + 0x1e0) += 1;
    if (*(s32*)(p + 0x1e0) >= 0x3c) {
        *(s32*)(p + 0x1e0) = 0;
    }
}

extern "C" void fn_80456154(void* p);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* a, s32 b);
extern "C" u8 fn_8030A3B0(void* a, s32 b);
extern "C" void* lbl_8053AD30;
extern "C" u8* lbl_8053AAF8;
struct T803ED83C;
typedef void (T803ED83C::*PMF803ED83C)();
extern PMF803ED83C lbl_804B08BC[];
extern "C" void fn_8013B490(void* p);
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AED8;
extern "C" void* fn_804030C4(u32 tag, const char* name);
extern "C" void fn_80440D78(void* p, void* r);
extern "C" void fn_80440CE4(void* p, void* r);
class Pane803EDA2C {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void setAlpha(u8 a);
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90(); virtual void v94();
    virtual void v98(); virtual void v9C(); virtual void vA0(); virtual void vA4();
    virtual void vA8(); virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void vB8(); virtual void vBC(); virtual void vC0(); virtual void vC4();
    virtual void vC8(); virtual void vCC(); virtual void vD0(); virtual void vD4();
    virtual void vD8(); virtual void vDC(); virtual void vE0(); virtual void vE4();
    virtual void vE8();
    virtual void vEC(s32 a, f32 x, f32 y, s32 b, s32 c, f32 w, f32 h);
};
extern PMF803ED83C lbl_804B0A24[];
extern PMF803ED83C lbl_804B0754[];
extern "C" const char lbl_80478920[];
extern "C" const char lbl_80478934[];
extern "C" void fn_803ED83C(u8* p) {
    s32 i;

    *(s32*)(p + 0x1d0) = 0;
    if (*(s32*)(p + 0x1bc) == 0) {
        if (fn_8030A3B0(lbl_8053AD30, fn_8030AAF4(0))) {
            lbl_8053AAF8[0x82] |= 0x10;
            *(s32*)(p + 0x1d0) += 1;
        } else {
            lbl_8053AAF8[0x82] &= ~0x10;
        }
        lbl_8053AAF8[0x82] &= ~0x20;
        lbl_8053AAF8[0x82] &= ~0x40;
        lbl_8053AAF8[0x82] &= ~0x80;
    } else {
        for (i = 0; i < 4; i++) {
            if (i <= *(s32*)(p + 0x1bc)) {
                if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
                    lbl_8053AAF8[0x82] |= (u8)(1 << (i + 4));
                    *(s32*)(p + 0x1d0) += 1;
                } else {
                    lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
                }
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
            }
        }
    }
    if (p[0x26e] == 0 || *(s32*)(p + 0x1d4) == 6) {
        if (*(s32*)(p + 0x1d4) != 0xf) {
            (((T803ED83C*)p)->*lbl_804B08BC[*(s32*)(p + 0x1d4)])();
        } else {
            (((T803ED83C*)p)->*lbl_804B08BC[*(s32*)(p + 0x1d8)])();
        }
        for (i = 0; i < 4; i++, p += 4) {
            fn_80456154(*(void**)(p + 0x7c));
        }
    }
}

extern "C" void fn_803EDA2C(u8* p) {
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(p + 0x14))->draw(0.0f, 0.0f, *(const J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    if (*(s32*)(p + 0x1d4) != 0xf) {
        (((T803ED83C*)p)->*lbl_804B0A24[*(s32*)(p + 0x1d4)])();
    } else {
        (((T803ED83C*)p)->*lbl_804B0A24[*(s32*)(p + 0x1d8)])();
    }
    if (p[0x26e] != 0) {
        switch (p[0x26e]) {
        case 1:
            if (p[0x26d] >= 0xf5) {
                if (*(s32*)(p + 0x1dc) == 9) {
                    fn_80440D78(lbl_8053AED8, fn_804030C4(0x54494d47, lbl_80478920));
                    fn_80440CE4(lbl_8053AED8, fn_804030C4(0x54494d47, lbl_80478934));
                }
                p[0x26d] = 0xff;
                p[0x26e] = 2;
                (((T803ED83C*)p)->*lbl_804B0754[*(s32*)(p + 0x1dc)])();
            } else {
                p[0x26d] += 10;
            }
            break;
        case 2:
            if (p[0x26d] <= 10) {
                p[0x26d] = 0;
                p[0x26e] = 0;
            } else {
                p[0x26d] -= 10;
            }
            break;
        }
        fn_8013B490(lbl_8053AB10);
        (*(Pane803EDA2C**)(p + 0x60))->setAlpha(p[0x26d]);
        (*(Pane803EDA2C**)(p + 0x60))->vEC(0, 0.0f, 0.0f, 0, 0, 800.0f, 600.0f);
    }
}

extern "C" void fn_804310CC(void* p);
extern "C" u8 fn_8030A388(void* a, s32 b);
extern "C" void fn_803E3564(u8* p);
extern "C" void fn_803EDBF0(u8* param_1, u8 param_2) {
    void* obj;
    Pane803E4650* pane;
    s32 i;

    fn_804310CC(lbl_8053AEC0);
    switch (param_2) {
    case 1:
        *(s32*)(param_1 + 0x1d4) = 10;
        fn_803E3564(param_1);
        break;
    case 2:
        *(s32*)(param_1 + 0x1d4) = 9;
        fn_803E3564(param_1);
        break;
    default:
        if (fn_8030A388(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
            *(s32*)(param_1 + 0x1bc) = 0;
        } else {
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
                *(s32*)(param_1 + 0x1bc) = 0;
                i = 1;
                do {
                    if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i)) == 0) {
                        break;
                    }
                    i++;
                    *(s32*)(param_1 + 0x1bc) += 1;
                } while (i < 4);
            }
        }
        *(s32*)(param_1 + 0x1d4) = 2;
        *(f32*)(param_1 + 0xf8) = -150.0f;
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x62620000, 0x506d6164, 0x62623037);
        pane->v10(*(f32*)(param_1 + 0xf0), *(f32*)(param_1 + 0xf4) + *(f32*)(param_1 + 0xf8));
        *(f32*)(param_1 + 0xfc) = -200.0f;
        fn_80402E08(*(void**)(param_1 + 0x78), 0.0f, *(f32*)(param_1 + 0xfc));
        *(f32*)(param_1 + 0x120) = -350.0f;
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x70620000, 0x506e6f, 0x70623034);
        pane->v10(*(f32*)(param_1 + 0x100) + *(f32*)(param_1 + 0x120), *(f32*)(param_1 + 0x110));
        *(f32*)(param_1 + 0x124) = -350.0f;
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x70620000, 0x506e6f, 0x70623038);
        pane->v10(*(f32*)(param_1 + 0x104) + *(f32*)(param_1 + 0x124), *(f32*)(param_1 + 0x114));
        *(f32*)(param_1 + 0x128) = -350.0f;
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x70620000, 0x506e6f, 0x70623132);
        pane->v10(*(f32*)(param_1 + 0x108) + *(f32*)(param_1 + 0x128), *(f32*)(param_1 + 0x118));
        *(f32*)(param_1 + 0x12c) = -350.0f;
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x70620000, 0x506e6f, 0x70623136);
        pane->v10(*(f32*)(param_1 + 0x10c) + *(f32*)(param_1 + 0x12c), *(f32*)(param_1 + 0x11c));
        *(f32*)(param_1 + 0x138) = 400.0f;
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x74610000, 0x4e6461, 0x74613032);
        pane->v10(*(f32*)(param_1 + 0x130) + *(f32*)(param_1 + 0x138), *(f32*)(param_1 + 0x134));
        *(f32*)(param_1 + 0x14c) = 400.0f;
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x74610000, 0x4e6461, 0x74613035);
        pane->v10(*(f32*)(param_1 + 0x13c) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x140));
        obj = *(void**)(param_1 + 4);
        pane = ((Screen803EDBF0*)obj)->v3C(0x4e0000, 0x4e6461, 0x74613037);
        pane->v10(*(f32*)(param_1 + 0x144) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x148));
        *(s32*)(param_1 + 0x220) = 0;
        *(s32*)(param_1 + 0x1e0) = 0;
        *(s16*)(param_1 + 0x254) = 0;
        *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
        *(s32*)(param_1 + 0x1d4) = 2;
        break;
    }
    *(s32*)(param_1 + 0x360) = 4;
}

extern "C" void* fn_803EDF94(u8* param_1, s16 param_2) {
    u8* p;
    s32 i;

    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B0B00;
        if (*(void**)(param_1 + 0x4) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x4))->v08(1);
        }
        *(void**)(param_1 + 0x4) = 0;
        if (*(void**)(param_1 + 0x8) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x8))->v08(1);
        }
        *(void**)(param_1 + 0x8) = 0;
        if (*(void**)(param_1 + 0xc) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0xc))->v08(1);
        }
        *(void**)(param_1 + 0xc) = 0;
        if (*(void**)(param_1 + 0x10) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x10))->v08(1);
        }
        *(void**)(param_1 + 0x10) = 0;
        if (*(void**)(param_1 + 0x14) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x14))->v08(1);
        }
        *(void**)(param_1 + 0x14) = 0;

        p = param_1;
        for (i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x18) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x18))->v08(1);
            }
            *(void**)(p + 0x18) = 0;
            if (*(void**)(p + 0x38) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x38))->v08(1);
            }
            *(void**)(p + 0x38) = 0;
            if (*(void**)(p + 0x28) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x28))->v08(1);
            }
            *(void**)(p + 0x28) = 0;
            if (*(void**)(p + 0x48) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x48))->v08(1);
            }
            *(void**)(p + 0x48) = 0;
        }

        if (*(void**)(param_1 + 0x64) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x64))->v08(1);
        }
        *(void**)(param_1 + 0x64) = 0;

        p = param_1;
        for (i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x68) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x68))->v08(1);
            }
            *(void**)(p + 0x68) = 0;
        }

        if (*(void**)(param_1 + 0x5c) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x5c))->v08(1);
        }
        *(void**)(param_1 + 0x5c) = 0;
        if (*(void**)(param_1 + 0x60) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x60))->v08(1);
        }
        *(void**)(param_1 + 0x60) = 0;

        p = param_1;
        for (i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x7c) != 0) {
                ((void (*)(void*, s32))((*(void***)((u8*)*(void**)(p + 0x7c) + 8))[12]))(*(void**)(p + 0x7c), 1);
            }
            *(void**)(p + 0x7c) = 0;
        }

        if (param_2 > 0) {
            delete param_1;
        }
    }
    return param_1;
}

