#include "types.h"
#include "Game/FsaMenuAction.h"
#include "JSystem/J2D/J2DPane.h"
extern const f32 lbl_805436E8;
extern const f32 lbl_805436EC;

extern const f32 lbl_80543664;
extern const f32 lbl_805436A8;
extern const f32 lbl_805436AC;
extern const f32 lbl_805436F0;
extern const f32 lbl_805436F4;
extern const f32 lbl_80543668;
extern const f32 lbl_8054368C;
extern const f32 lbl_805436F8;
extern const f32 lbl_805436C0;
extern const f32 lbl_805436B0;
extern const f32 lbl_805436C4;
extern const f32 lbl_80543694;
extern const f32 lbl_805436FC;
extern const f32 lbl_80543698;
extern const f32 lbl_805436B4;
extern const f32 lbl_80543668;
extern const f32 lbl_805436BC;
extern const f32 lbl_805436C8;
extern const f64 lbl_80543678;
extern const f64 lbl_80543670;
static inline f32 MenuSlideExit803E(s32 elapsed, const f32 magnitude, const f32 multiplier) {
    f32 square=(f32)(elapsed*elapsed);
    return magnitude*(square*multiplier);
}
static inline f32 MenuSlide803E(s32 remaining, const f32 magnitude, const f32 denominator) {
    f32 square=(f32)(remaining*remaining);
    return magnitude*(square/denominator);
}

class Screen803E4650 {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual class Pane803E4650* v3C(s32 a, s32 b);
};
class Pane803E4650 {
public:
    virtual void v08(); virtual void v0C();
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

class Picture803E3CB0 {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51();
    virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55();
    virtual void p56(); virtual void p57(); virtual void p58(); virtual void p59();
    virtual void p60(); virtual void p61(); virtual void p62(); virtual void p63();
    virtual void p64(); virtual void p65();
    virtual void* changeTexture(void* img, u8 id);
};
extern "C" void fn_803E3564(u8* p) {
    u8* base = lbl_80477970;
    char* a;
    char* b;
    char* c;
    Pane803E4650* pane;

    a = getStringPtr__10J2DTextBoxCFv((Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5468 << 32) | 0x616e3031));
    b = getStringPtr__10J2DTextBoxCFv((Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5473 << 32) | 0x74613031));
    c = getStringPtr__10J2DTextBoxCFv((Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x547275 << 32) | 0x6c653031));
    if (*(s32*)(p + 0x1bc) == 0) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5067 << 32) | 0x62613032);
            ((u8*)pane)[0xb0] = 0;
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5063 << 32) | 0x6f6e3032);
            ((u8*)pane)[0xb0] = 1;
        } else {
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5067 << 32) | 0x62613032);
            ((u8*)pane)[0xb0] = 1;
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5063 << 32) | 0x6f6e3032);
            ((u8*)pane)[0xb0] = 0;
        }
        fn_803832BC(b, 0x11b, 0, 0, 0);
        fn_803832BC(a, 0x11b, 0, 0, 0);
        fn_803832BC(c, 0xf7, 0, 0, 0);
        void* g = fn_804031C4(0x54494d47, base + 0xfd8);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
        ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
        ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x507374 << 32) | 0x61623034);
        ((u8*)pane)[0xb0] = 0;
    } else {
        fn_803832BC(b, 0x11b, 0, 0, 0);
        fn_803832BC(a, 0xac, 0, 0, 0);
        fn_803832BC(c, 0xf7, 0, 0, 0);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5067 << 32) | 0x62613032);
        ((u8*)pane)[0xb0] = 0;
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5063 << 32) | 0x6f6e3032);
        ((u8*)pane)[0xb0] = 1;
        if (*(s32*)(p + 0x1bc) == 1) {
            void* g = fn_804031C4(0x54494d47, base + 0xfec);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        } else if (*(s32*)(p + 0x1bc) == 2) {
            void* g = fn_804031C4(0x54494d47, base + 0x1000);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        } else {
            void* g = fn_804031C4(0x54494d47, base + 0x1014);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        }
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x507374 << 32) | 0x61623034);
        ((u8*)pane)[0xb0] = 1;
    }
    *(f32*)(p + 0x164) = -200.0f;
    *(f32*)(p + 0x168) = -200.0f;
    *(f32*)(p + 0x184) = 300.0f;
    *(f32*)(p + 0x188) = 300.0f;
    *(f32*)(p + 0x18c) = 300.0f;
    *(f32*)(p + 0x198) = -450.0f;
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506d6164 << 32) | 0x62623037);
    pane->v10(*(f32*)(p + 0x15c), *(f32*)(p + 0x160) + *(f32*)(p + 0x164));
    fn_80402E08(*(void**)(p + 0x78), 0.0f, *(f32*)(p + 0x168));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x507374 << 32) | 0x61623034);
    pane->v10(*(f32*)(p + 0x16c) + *(f32*)(p + 0x184), *(f32*)(p + 0x178));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506861 << 32) | 0x6e623034);
    pane->v10(*(f32*)(p + 0x170) + *(f32*)(p + 0x188), *(f32*)(p + 0x17c));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5072 << 32) | 0x75623034);
    pane->v10(*(f32*)(p + 0x174) + *(f32*)(p + 0x18c), *(f32*)(p + 0x180));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506c6962 << 32) | 0x6b6b3033);
    pane->v10(*(f32*)(p + 0x190) + *(f32*)(p + 0x198), *(f32*)(p + 0x194));
    *(s32*)(p + 0x220) = 0;
    *(s32*)(p + 0x1e0) = 0;
    *(s16*)(p + 0x254) = 0;
    *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
    *(s32*)(p + 0x1d4) = 9;
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

// Picture pane view: changeTexture(img, id) at vtable 0x110.
extern "C" void fn_803E3CB0(u8* p) {
    u8* base = lbl_80477970;
    u8 v;
    u64* b;
    u64* tA;
    u64* tB;
    u64* tC;
    u8* q;
    if (*(s32*)(p + 0x1bc) == 1) {
        void* g = fn_804031C4(0x54494d47, base + 0xfec);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3032ULL))->changeTexture(g, 0);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3031ULL))->changeTexture(g, 0);
    } else if (*(s32*)(p + 0x1bc) == 2) {
        void* g = fn_804031C4(0x54494d47, base + 0x1000);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3032ULL))->changeTexture(g, 0);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3031ULL))->changeTexture(g, 0);
    } else {
        void* g = fn_804031C4(0x54494d47, base + 0x1014);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3032ULL))->changeTexture(g, 0);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3031ULL))->changeTexture(g, 0);
    }
    {
        char* s1 = getStringPtr__10J2DTextBoxCFv((*(J2DPane**)(p + 8))->search(0x54746b673031ULL));
        char* s2 = getStringPtr__10J2DTextBoxCFv((*(J2DPane**)(p + 8))->search(0x54746b673032ULL));
        fn_803832BC(s1, 0x3e, 0, 0, 0);
        fn_803832BC(s2, 0x3e, 0, 0, 0);
    }
    *(f32*)(p + 0xa0) = -300.0f;
    (*(J2DPane**)(p + 8))->search(0x4e646174613033ULL)->move(*(f32*)(p + 0x98), *(f32*)(p + 0x9c) + *(f32*)(p + 0xa0));
    *(f32*)(p + 0xac) = -100.0f;
    (*(J2DPane**)(p + 8))->search(0x4e646174613035ULL)->move(*(f32*)(p + 0xa4), *(f32*)(p + 0xa8) + *(f32*)(p + 0xac));
    *(f32*)(p + 0xb8) = -200.0f;
    (*(J2DPane**)(p + 8))->search(0x4e646174613036ULL)->move(*(f32*)(p + 0xb0), *(f32*)(p + 0xb4) + *(f32*)(p + 0xb8));
    *(f32*)(p + 0xbc) = -200.0f;
    fn_80402E08(*(void**)(p + 0x78), 0.0f, *(f32*)(p + 0xbc));
    *(f32*)(p + 0xe0) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3032ULL)->move(*(f32*)(p + 0xc0), *(f32*)(p + 0xd0) + *(f32*)(p + 0xe0));
    *(f32*)(p + 0xe4) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3132ULL)->move(*(f32*)(p + 0xc4), *(f32*)(p + 0xd4) + *(f32*)(p + 0xe4));
    *(f32*)(p + 0xe8) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3232ULL)->move(*(f32*)(p + 0xc8), *(f32*)(p + 0xd8) + *(f32*)(p + 0xe8));
    *(f32*)(p + 0xec) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3332ULL)->move(*(f32*)(p + 0xcc), *(f32*)(p + 0xdc) + *(f32*)(p + 0xec));
    q = p;
    tA = (u64*)(base + 0x840);
    tB = (u64*)(base + 0x8e0);
    tC = (u64*)(base + 0x8c0);
    for (s32 i = 0; i < 4; i++) {
        if (i <= *(s32*)(p + 0x1bc)) {
            J2DPane* o = (*(J2DPane**)(p + 8))->search(*tA);
            v = 1;
            b = tB + 2;
            ((u8*)o)[0xb0] = v;
            for (s32 j = 2; j < 4; j++) {
                ((u8*)(*(J2DPane**)(p + 8))->search(*b))[0xb0] = v;
                b++;
            }
            (*(J2DPane**)(p + 8))->search(*tC)->setAlpha(0xff);
            *(s32*)(q + 0x230) = *(s16*)(*(u8**)(q + 0x38) + 6);
            *(s32*)(q + 0x240) = *(s16*)(*(u8**)(q + 0x48) + 6);
        } else {
            J2DPane* o = (*(J2DPane**)(p + 8))->search(*tA);
            v = 0;
            b = tB + 2;
            ((u8*)o)[0xb0] = v;
            for (s32 j = 2; j < 4; j++) {
                ((u8*)(*(J2DPane**)(p + 8))->search(*b))[0xb0] = v;
                b++;
            }
            (*(J2DPane**)(p + 8))->search(*tC)->setAlpha(0x80);
            *(s32*)(q + 0x230) = 0;
            *(s32*)(q + 0x240) = 0;
        }
        tA++;
        tB += 4;
        tC++;
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
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x62620000, 0x506d6164, 0x62623037);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0xf0), *(f32*)(param_1 + 0xf4) + *(f32*)(param_1 + 0xf8));
    *(f32*)(param_1 + 0xfc) = -200.0f;
    fn_80402E08(*(void**)(param_1 + 0x78), 0.0f, *(f32*)(param_1 + 0xfc));
    *(f32*)(param_1 + 0x120) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x506e6f, 0x70623034);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0x100) + *(f32*)(param_1 + 0x120), *(f32*)(param_1 + 0x110));
    *(f32*)(param_1 + 0x124) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x506e6f, 0x70623038);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0x104) + *(f32*)(param_1 + 0x124), *(f32*)(param_1 + 0x114));
    *(f32*)(param_1 + 0x128) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x506e6f, 0x70623132);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0x108) + *(f32*)(param_1 + 0x128), *(f32*)(param_1 + 0x118));
    *(f32*)(param_1 + 0x12c) = -350.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x506e6f, 0x70623136);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0x10c) + *(f32*)(param_1 + 0x12c), *(f32*)(param_1 + 0x11c));
    *(f32*)(param_1 + 0x138) = 400.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x74610000, 0x4e6461, 0x74613032);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0x130) + *(f32*)(param_1 + 0x138), *(f32*)(param_1 + 0x134));
    *(f32*)(param_1 + 0x14c) = 400.0f;
    obj = *(void**)(param_1 + 4);
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x74610000, 0x4e6461, 0x74613035);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0x13c) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x140));
    obj = *(void**)(param_1 + 4);
    p = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x4e0000, 0x4e6461, 0x74613037);
    ((void (*)(void*, f32, f32))(*(void***)p)[4])(p, *(f32*)(param_1 + 0x144) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x148));
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

extern "C" void fn_803E4940(u8* p) {
    s32 state = *(s32*)(p + 0x1d4);
    f32 f31;
    if (state == 0xb) {
        return;
    }
    {
        s32 v = *(s32*)(p + 0x1e0);
        f32 f2;
        if (v < 0x1e) {
            f2 = (f32)(v * v) / lbl_805436B4;
        } else {
            f2 = lbl_80543668 - (f32)((v - 0x1e) * (v - 0x1e)) / lbl_805436B4;
        }
        f31 = f2 * ((f32)*(u8*)(p + 0x269) - lbl_80543670);
    }
}

extern "C" void fn_803E64A0(u8* p) {
    s32 i;
    s32 k;
    s32 n;
    s32 st;
    f32 u;
    f32 f31;
    f32 f30;
    f32 off;
    f32 h;
    f32 h2;
    f32 t;
    u8* q;
    s32* tA = (s32*)(lbl_80477970 + 0xea8);
    s32* tB = (s32*)(lbl_80477970 + 0xec8);
    s32* tC = (s32*)(lbl_80477970 + 0xee8);
    Pane803E4650* pane;

    st = *(s32*)(p + 0x1d4);
    if (st != 4) {
        n = *(s32*)(p + 0x1e0);
        if (n < 30) {
            u = (f32)(n * n) / 900.0f;
        } else {
            n -= 30;
            t = (f32)(n * n) / 900.0f;
            u = 1.0f - t;
        }
        f30 = u * (f32)p[0x268];
    } else {
        n = *(s32*)(p + 0x1e0);
        if (n < 15) {
            u = (f32)(n * n) / 225.0f;
        } else {
            u = (f32)((n - 15) * (n - 15)) / 225.0f;
        }
        f30 = 230.0f * u;
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
    q = p;
    for (i = 0; i < 4; i++, tA += 2, tB += 2, tC += 2, q += 4) {
        if (i == *(s32*)(p + 0x1bc)) {
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tA[0], tA[1]);
            h = getBounds__7J2DPaneFv(pane)[0];
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tA[0], tA[1]);
            pane->v10(h, *(f32*)(q + 0x110) + off);
            if (i == 0) {
                pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(0x50736375, 0x726f3032);
                h = getBounds__7J2DPaneFv(pane)[0];
                pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(0x50736375, 0x726f3032);
                pane->v10(h, *(f32*)(p + 0x1a0) + off);
            } else {
                h = getBounds__7J2DPaneFv(((Screen803E4650*)*(void**)(p + 4))->v3C(tA[0], tA[1]))[1];
                h2 = getBounds__7J2DPaneFv(((Screen803E4650*)*(void**)(p + 4))->v3C(tA[0], tA[1]))[1];
                h2 = (*(f32*)(p + 0x1a0) + h2) - h;
                pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(0x50736375, 0x726f3032);
                h = getBounds__7J2DPaneFv(pane)[0];
                pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(0x50736375, 0x726f3032);
                pane->v10(h, h2);
            }
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tB[0], tB[1]);
            *((u8*)pane + 0xb0) = 0;
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tC[0], tC[1]);
            *((u8*)pane + 0xb0) = 1;
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tC[0], tC[1]);
            pane->setAlpha((s32)f31);
        } else {
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tB[0], tB[1]);
            h = getBounds__7J2DPaneFv(pane)[0];
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tB[0], tB[1]);
            pane->v10(h, *(f32*)(q + 0x110));
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tB[0], tB[1]);
            *((u8*)pane + 0xb0) = 1;
            pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(tC[0], tC[1]);
            *((u8*)pane + 0xb0) = 0;
        }
    }
    pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(0x50736375, 0x726f3031);
    pane->setAlpha((s32)f30);
    pane = ((Screen803E4650*)*(void**)(p + 4))->v3C(0x50736375, 0x726f3032);
    pane->setAlpha((s32)f30);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 4), 0.0f, 0.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
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

#pragma opt_common_subs off
extern "C" void fn_803E831C(u8* p) {
    u8* tbl = (u8*)lbl_80477970;
    s32 i;
    s32 val;
    Pane803E4650* pane;
    f32 v;

    if (*(s32*)(p + 0x1bc) != 3) {
        if (*(s32*)(p + 0x220) < 0x64) {
            *(s32*)(p + 0x220) = 0;
        } else if (*(s32*)(p + 0x220) < 0x70) {
            *(s32*)(p + 0x220) += 1;
        } else if (*(s32*)(p + 0x220) < 0xd4) {
            *(s32*)(p + 0x220) = 0x70;
        } else {
            *(s32*)(p + 0x220) += 1;
            if (*(s32*)(p + 0x220) >= 0xe0) {
                *(s32*)(p + 0x220) = 0;
            }
        }
    }

    *(s16*)(p + 0x254) += 1;
    if (*(s16*)(p + 0x254) > 0x14) {
        if (*(s16*)(p + 0x254) < 0x1c) {
            s32 d=*(s16*)(p+0x254)-20;
 f32 fraction=(f32)(d*d);
 fraction*=lbl_805436E8;
 *(f32*)(p+0x164)=lbl_8054368C*fraction;
            v = (f32)(8 - (*(s16*)(p + 0x254) - 0x14)) * lbl_805436EC;
            if (v < lbl_80543664) {
                v = lbl_80543664;
            }
            else if (v > lbl_80543668) {
                v = lbl_80543668;
            }
            s32 j;u64* names=(u64*)(tbl+0x650);
            for (j = 0; j < 0x11; j++,names++) {
                pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);
                val = (s32)((f32)(u32)p[0x322 + j] * v);
                pane->setAlpha(val);
            }
        } else {
            *(f32*)(p + 0x164) = lbl_8054368C;
            s32 j;u64* names=(u64*)(tbl+0x650);
            for (j = 0; j < 0x11; j++,names++) {
                pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);
                val = (s32)((f32)(u32)p[0x322 + j] * lbl_80543664);
                pane->setAlpha(val);
            }
        }
    }

 if(*(s16*)(p+0x254)>0){
 if(*(s16*)(p+0x254)<10){s32 t=*(s16*)(p+0x254);*(f32*)(p+0x168)=lbl_8054368C*((f32)(t*t)/lbl_805436F0);}
 else *(f32*)(p+0x168)=lbl_8054368C;
 }
 s16 ids[2];s16* id=ids;s16* write=id;
 for(s32 j=0;j<3;j++){if(j!=*(s32*)(p+0x1b8))*write++=j;}
 if(*(s32*)(p+0x1dc)==2){
 s32 lo=0;u8* offsets=p;s32 lo2=lo;u8* bytes=p;u64* keys=(u64*)(tbl+0x6d8);s32 group=0;s32 hi=10;
 for(;group<3;group++,hi+=10,lo2+=30,offsets+=4,bytes+=5,keys+=5,lo+=10){
 if(*(s16*)(p+0x254)>lo){
 if(*(s16*)(p+0x254)<hi){
 s32 d=*(s16*)(p+0x254)-lo;
 f32 fraction=(f32)(d*d);fraction/=lbl_805436F0;
 *(f32*)(offsets+0x184)=lbl_80543694*fraction;
 v=(f32)(10-(*(s16*)(p+0x254)-lo2))/lbl_805436F4;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 u8* alpha=bytes;u64* name=keys;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);pane->setAlpha((s32)((f32)alpha[0x333]*v));}
 }else{
 *(f32*)(offsets+0x184)=lbl_80543694;
 u8* alpha=bytes;u64* name=keys;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);pane->setAlpha((s32)((f32)alpha[0x333]*lbl_80543664));}
 }}}
 }else{
 s32 lo=0;s32 group=0;s32 lo2=0;s32 hi=10;
 for(;group<2;group++,hi+=10,id++,lo2+=30,lo+=10){
 if(*(s16*)(p+0x254)>lo){
 if(*(s16*)(p+0x254)<hi){
 s32 d=*(s16*)(p+0x254)-lo;
 s32 idx=*id; s32 cell=idx*4+0x184;
 f32 fraction=(f32)(d*d);fraction/=lbl_805436F0;
 *(f32*)(p+cell)=lbl_80543694*fraction;
 v=(f32)(10-(*(s16*)(p+0x254)-lo2))/lbl_805436F4;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 u8* alpha=p+idx*5;u64* name=((u64*)(tbl+0x6d8))+idx*5;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);pane->setAlpha((s32)((f32)alpha[0x333]*v));}
 }else{
 s32 idx=*id; s32 cell=idx*4+0x184;
 *(f32*)(p+cell)=lbl_80543694;
 u8* alpha=p+idx*5;u64* name=((u64*)(tbl+0x6d8))+idx*5;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);pane->setAlpha((s32)((f32)alpha[0x333]*lbl_80543664));}
 }}}
 if(*(s16*)(p+0x254)>15){
 if(*(s16*)(p+0x254)<23){
 s32 d=*(s16*)(p+0x254)-15;
 ((f32*)(p+0x184))[*(s32*)(p+0x1b8)]=(f32)(d*d)*lbl_805436E8*lbl_80543694;
 v=(f32)(8-(*(s16*)(p+0x254)-15))*lbl_805436EC;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 s32 idx=*(s32*)(p+0x1b8);u8* alpha=p+idx*5;u64* name=((u64*)(tbl+0x6d8))+idx*5;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);pane->setAlpha((s32)((f32)alpha[0x333]*v));}
 }else{
 s32 idx=*(s32*)(p+0x1b8);
 ((f32*)(p+0x184))[idx]=lbl_80543694;
 u8* alpha=p+idx*5;u64* name=((u64*)(tbl+0x6d8))+idx*5;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);pane->setAlpha((s32)((f32)alpha[0x333]*lbl_80543664));}
 }}
 }

 if(*(s16*)(p+0x254)>15){
 if(*(s16*)(p+0x254)<23){
 s32 d=*(s16*)(p+0x254)-15;
 *(f32*)(p+0x198)=(f32)(d*d)*lbl_805436E8*lbl_80543698;
 v=(f32)(8-(*(s16*)(p+0x254)-15))*lbl_805436EC;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 u64* names=(u64*)(tbl+0x750);for(i=0;i<26;i++,names++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);pane->setAlpha((s32)((f32)p[0x342+i]*v));}
 }else{
 *(f32*)(p+0x198)=lbl_80543698;
 u64* names=(u64*)(tbl+0x750);for(i=0;i<26;i++,names++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);pane->setAlpha((s32)((f32)p[0x342+i]*lbl_80543664));}
 }}
 if(*(s16*)(p+0x254)>=48){
 if(*(s32*)(p+0x1dc)==2) *(s32*)(p+0x360)=6;
 else if(*(s32*)(p+0x1bc)==0){
 if(*(s32*)(p+0x1b8)==1) *(s32*)(p+0x360)=6;
 else if(*(s32*)(p+0x1b8)==1) {if(p[0x26e]==0){*(s32*)(p+0x1dc)=1;p[0x26e]=1;}}
 else {if(p[0x26e]==0){*(s32*)(p+0x1dc)=14;p[0x26e]=1;}}
 }else{
 if(*(s32*)(p+0x1b8)==0) *(s32*)(p+0x360)=6;
 else if(*(s32*)(p+0x1b8)==1) {if(p[0x26e]==0){*(s32*)(p+0x1dc)=12;p[0x26e]=1;}}
 else {if(p[0x26e]==0){*(s32*)(p+0x1dc)=14;p[0x26e]=1;}}
 }
 *(s16*)(p+0x254)=0;
 }
 *(s32*)(p+0x1e0)+=1;
 if(*(s32*)(p+0x1e0)>=30)*(s32*)(p+0x1e0)=0;
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x506d616462623037ULL);
 pane->v10(*(f32*)(p+0x15c),*(f32*)(p+0x160)+*(f32*)(p+0x164));
 fn_80402E08(*(void**)(p+0x78),lbl_80543664,*(f32*)(p+0x168));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x0050737461623034ULL);
 pane->v10(*(f32*)(p+0x16c)+*(f32*)(p+0x184),*(f32*)(p+0x178));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x005068616e623034ULL);
 pane->v10(*(f32*)(p+0x170)+*(f32*)(p+0x188),*(f32*)(p+0x17c));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x507275623034ULL);
 pane->v10(*(f32*)(p+0x174)+*(f32*)(p+0x18c),*(f32*)(p+0x180));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x506c69626b6b3033ULL);
 pane->v10(*(f32*)(p+0x190)+*(f32*)(p+0x198),*(f32*)(p+0x194));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x50736375726f3032ULL);
 f32 h=getBounds__7J2DPaneFv(pane)[1];
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x50736375726f3032ULL);
 pane->v10(*(f32*)(p+0x1a4)+((f32*)(p+0x184))[*(s32*)(p+0x1b8)],h);
}
#pragma opt_common_subs reset

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

extern "C" void fn_803E926C(u8* p) {
    u8* base = lbl_80477970;
    s32 k;
    u32* tb;
    u8* bytes;
    u8* f;
    s32 lo;
    s32 hi;
    s32 lo2;
    s32 v;
    s32 i;
    s32 d;
    f32 t;
    Pane803E4650* pane;

    *(s16*)(p + 0x254) += 1;
    v = *(s16*)(p + 0x254);
    if (v > 0) {
        if (v < 25) {
            d = 25 - v;
            *(f32*)(p + 0x164) = lbl_8054368C * ((f32)(d * d) / lbl_805436F8);
            t = (f32)v / lbl_805436C0;
            if (t < lbl_80543664) {
                t = lbl_80543664;
            } else if (t > lbl_80543668) {
                t = lbl_80543668;
            }
        } else {
            *(f32*)(p + 0x164) = lbl_80543664;
            t = lbl_80543668;
        }
        tb = (u32*)(base + 0x650);
        for (i = 0; i < 17; i++) {
            pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(tb[0], tb[1]);
            pane->setAlpha((s32)((f32)p[0x322 + i] * t));
            tb += 2;
        }
    }

    v = *(s16*)(p + 0x254);
    if (v > 25) {
        if (v < 45) {
            d = 45 - v;
            *(f32*)(p + 0x168) = lbl_8054368C * ((f32)(d * d) / lbl_805436B0);
        } else {
            *(f32*)(p + 0x168) = lbl_80543664;
        }
    }

    lo = 0;
    hi = 15;
    bytes = p;
    f = p;
    tb = (u32*)(base + 0x6d8);
    for (k = 0; k < 3; k++) {
        v = *(s16*)(p + 0x254);
        if (v > lo) {
            if (v < hi) {
                d = hi - v;
                *(f32*)(f + 0x184) = lbl_80543694 * ((f32)(d * d) / lbl_805436C4);
                lo2 = lo;
                t = (f32)(v - lo2) / lbl_805436FC;
                if (t < lbl_80543664) {
                    t = lbl_80543664;
                } else if (t > lbl_80543668) {
                    t = lbl_80543668;
                }
            } else {
                *(f32*)(f + 0x184) = lbl_80543664;
                t = lbl_80543668;
            }
            for (i = 0; i < 5; i++) {
                pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(tb[0], tb[1]);
                pane->setAlpha((s32)((f32)bytes[0x333 + i] * t));
                tb += 2;
            }
        }
        lo += 10;
        hi += 10;
        f += 4;
        bytes += 5;
    }

    v = *(s16*)(p + 0x254);
    if (v > 0) {
        if (v < 15) {
            d = 15 - v;
            *(f32*)(p + 0x198) = lbl_80543698 * ((f32)(d * d) / lbl_805436C4);
            t = (f32)v / lbl_805436FC;
            if (t < lbl_80543664) {
                t = lbl_80543664;
            } else if (t > lbl_80543668) {
                t = lbl_80543668;
            }
        } else {
            *(f32*)(p + 0x198) = lbl_80543664;
            t = lbl_80543668;
        }
        tb = (u32*)(base + 0x750);
        for (i = 0; i < 26; i++) {
            pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(tb[0], tb[1]);
            pane->setAlpha((s32)((f32)p[0x342 + i] * t));
            tb += 2;
        }
    }

    if (*(s16*)(p + 0x254) >= 75) {
        *(s16*)(p + 0x254) = 0;
        if (*(s32*)(p + 0x1bc) == 0) {
            *(s32*)(p + 0x1e0) = 0;
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 0;
        } else {
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 10;
        }
    }

    pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(0x506d6164, 0x62623037);
    pane->v10(*(f32*)(p + 0x15c), *(f32*)(p + 0x160) + *(f32*)(p + 0x164));
    fn_80402E08(*(void**)(p + 0x78), lbl_80543664, *(f32*)(p + 0x168));

    pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(0x507374, 0x61623034);
    pane->v10(*(f32*)(p + 0x16c) + *(f32*)(p + 0x184), *(f32*)(p + 0x178));

    pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(0x506861, 0x6e623034);
    pane->v10(*(f32*)(p + 0x170) + *(f32*)(p + 0x188), *(f32*)(p + 0x17c));

    pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(0x5072, 0x75623034);
    pane->v10(*(f32*)(p + 0x174) + *(f32*)(p + 0x18c), *(f32*)(p + 0x180));

    pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(0x506c6962, 0x6b6b3033);
    pane->v10(*(f32*)(p + 0x190) + *(f32*)(p + 0x198), *(f32*)(p + 0x194));

    pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(0x50736375, 0x726f3032);
    f32 h = getBounds__7J2DPaneFv(pane)[1];
    pane = ((Screen803E4650*)*(void**)(p + 0xc))->v3C(0x50736375, 0x726f3032);
    pane->v10(*(f32*)(p + 0x1a4), h);
}

extern "C" s32 fn_804317AC(void*);
extern "C" s32 fn_80431740(void*);
extern "C" void fn_8013CC50(s32, f32*, s32, s32, s32, s32, s32, s32, f32);
extern "C" u8* sManager__8JUTVideo;
extern "C" const u64 lbl_80478190[];
extern const f32 lbl_80543658;
extern const f32 lbl_80543660;
extern const f32 lbl_80543664;
extern const f32 lbl_80543668;
extern const f32 lbl_805436D8;
extern const f32 lbl_805436DC;
extern const f32 lbl_80543700;
extern const f32 lbl_80543704;
extern "C" void fn_803E9A20(u8* p) {
    s32 i;
    f32 span;
    void* r;
    u32 t1;
    u32 t2;
    JGeometry::TVec3f v1;
    JGeometry::TVec3f v2;

    switch (p[0x26c]) {
    case 0:
        if (fn_804317AC(lbl_8053AEC0)) {
            p[0x26c] = 1;
        }
        break;
    case 2:
        if (fn_80431740(lbl_8053AEC0)) {
            p[0x26c] = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 7;
        }
        break;
    case 1:
    default:
        if (*(s32*)(p + 0x1d0) == *(s32*)(p + 0x1bc) + 1) {
            p[0x26c] = 2;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else if ((lbl_8053AAF8[0x82] & 0x10) && fn_8030A308(lbl_8053AD30, fn_8030AAF4(0))) {
            if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23c] + 1)) {
                p[0x26c] = 2;
                fn_80458880(lbl_8053AF80, 0xb, -1);
            } else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23c] + 1)) {
                p[0x26c] = 2;
                fn_80458880(lbl_8053AF80, 0xc, -1);
            }
        } else if (fn_80309C4C(lbl_8053AD30, 0x1300, lbl_80529DEC[0x23c] + 1)) {
            p[0x26c] = 2;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        }
        break;
    }

    *(s16*)(p + 0x25e) += 1;
    if (*(s16*)(p + 0x25e) >= 100) {
        *(s16*)(p + 0x25e) = 0;
    }
    *(s16*)(p + 0x25c) += 1;
    if (*(s16*)(p + 0x25c) >= 100) {
        *(s16*)(p + 0x25c) = 0;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) {
            *(s32*)(p + i * 4 + 0x220) += 1;
            if (*(s32*)(p + i * 4 + 0x220) >= 0x82) {
                *(s32*)(p + i * 4 + 0x220) = 0x64;
            }
            if (*(s32*)(p + i * 4 + 0x220) == 0xb) {
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t1 = 0x10001;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t1);
            } else if (*(s32*)(p + i * 4 + 0x220) == 0x24) {
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x8c) = (lbl_805436D8 * (span * lbl_80543658 + *(f32*)((u8*)r + 0x30))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x90) = (lbl_805436DC * (lbl_80543660 + (span * lbl_80543658 + *(f32*)((u8*)r + 0x34)))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
                *(f32*)(p + 0x94) = lbl_80543664;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t2 = 0x2000E;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t2);
                v1.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v1.x, 0xcb, 1, 0, 0, 0, 1, lbl_80543668);
                v2.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v2.x, 0xcc, 1, 0, 0, 0, 1, lbl_80543668);
            }
        } else {
            *(s32*)(p + i * 4 + 0x220) = 0;
        }
    }
}

extern "C" s32 fn_80403414(s32 a);
extern "C" s32 fn_804033D4(s32 a);
extern "C" s32 fn_8040336C(s32 a);
extern "C" void fn_8013CC50(s32 a, f32* v, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" void fn_803E9EE8(u8* p) {
    s32 i;
    f32 span;
    void* r;
    u32 t1;
    u32 t2;
    JGeometry::TVec3f v1;
    JGeometry::TVec3f v2;

    if (p[0x26c] == 0xff) {
        if (*(s32*)(p + 0x1bc) == 0) {
            fn_80431A9C(lbl_8053AEC0, 0xa9, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
        } else {
            fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
        }
        p[0x26c] = 0;
        *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
        *(s32*)(p + 0x1d4) = 8;
    } else if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23c] + 1)) {
        if (*(s32*)(p + 0x1d0) == *(s32*)(p + 0x1bc) + 1) {
            *(s32*)(p + 0x1b8) = 0;
            for (i = 0; i < 4; i++) {
                *(s32*)(p + i * 4 + 0x1f0) = fn_80403414(i);
                *(s32*)(p + i * 4 + 0x200) = fn_804033D4(i);
                *(s32*)(p + i * 4 + 0x210) = fn_8040336C(i);
                *(s32*)(p + i * 4 + 0x1c0) = 0;
            }
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 6;
        } else {
            if (*(s32*)(p + 0x1bc) == 0) {
                fn_80431A9C(lbl_8053AEC0, 0xa9, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
            } else {
                fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
            }
            p[0x26c] = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 8;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23c] + 1)) {
        (((T803ED83C*)p)->*lbl_804B0754[2])();
        fn_80458880(lbl_8053AF80, 0xc, -1);
    }

    *(s32*)(p + 0x1e0) += 1;
    if (*(s32*)(p + 0x1e0) >= 0x3c) {
        *(s32*)(p + 0x1e0) = 0;
    }
    *(s16*)(p + 0x25e) += 1;
    if (*(s16*)(p + 0x25e) >= 100) {
        *(s16*)(p + 0x25e) = 0;
    }
    *(s16*)(p + 0x25c) += 1;
    if (*(s16*)(p + 0x25c) >= 100) {
        *(s16*)(p + 0x25c) = 0;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) {
            *(s32*)(p + i * 4 + 0x220) += 1;
            if (*(s32*)(p + i * 4 + 0x220) >= 0x82) {
                *(s32*)(p + i * 4 + 0x220) = 0x64;
            }
            if (*(s32*)(p + i * 4 + 0x220) == 0xb) {
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t1 = 0x10001;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t1);
            } else if (*(s32*)(p + i * 4 + 0x220) == 0x24) {
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x8c) = (lbl_805436D8 * (span * lbl_80543658 + *(f32*)((u8*)r + 0x30))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x90) = (lbl_805436DC * (lbl_80543660 + (span * lbl_80543658 + *(f32*)((u8*)r + 0x34)))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
                *(f32*)(p + 0x94) = lbl_80543664;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t2 = 0x2000E;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t2);
                v1.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v1.x, 0xcb, 1, 0, 0, 0, 1, lbl_80543668);
                v2.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v2.x, 0xcc, 1, 0, 0, 0, 1, lbl_80543668);
            }
        } else {
            *(s32*)(p + i * 4 + 0x220) = 0;
        }
    }
}

extern const f32 lbl_8054369C;
extern const f32 lbl_805436E8;
extern "C" void fn_803EA3F8(u8* p) {
    s16 cnt;
    cnt = *(s16*)(p + 0x254) + 1;
    *(s16*)(p + 0x254) = cnt;
    if (cnt > 0 && cnt < 8) {
        *(f32*)(p + 0xa0) = lbl_8054369C * (((f32)(cnt * cnt) - (f32)lbl_80543678) * lbl_805436E8);
    }
}

extern const f32 lbl_805436A0;
extern const f32 lbl_805436A4;
extern const f32 lbl_80543708;
extern "C" void fn_803EAEC8(u8* p) {
    s32 tm;
    s32 i;
    f32 f;
    void* obj;
    u32* e;

    *(s16*)(p + 0x254) = *(s16*)(p + 0x254) + 1;
    if (*(s16*)(p + 0x254) > 0) {
        if (*(s16*)(p + 0x254) < 25) {
            tm = *(s16*)(p + 0x254);
            *(f32*)(p + 0xa0) = MenuSlide803E(25 - tm, lbl_8054369C, lbl_805436F8);
            *(f32*)(p + 0xac) = MenuSlide803E(25 - tm, lbl_805436A0, lbl_805436F8);
            f = (f32)tm / lbl_805436C0;
            if (f < lbl_80543664) {
                f = lbl_80543664;
            } else if (f > lbl_80543668) {
                f = lbl_80543668;
            }
            e = (u32*)(lbl_80477970 + 0x420);
            for (i = 0; i < 0x22; i++) {
                obj = *(void**)(p + 8);
                ((void (*)(void*, s32, u32, u32))((void**)*(void**)obj)[15])(obj, 0, e[0], e[1]);
                obj = *(void**)(p + 8);
                ((void (*)(void*, s32))((void**)*(void**)obj)[9])(obj, (s32)((f32)p[0x2dc + i] * f));
                e += 2;
            }
        }
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

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void fn_803ECC64(u8* self) {
    u8* base=lbl_80477970;
    s32 j;
    s32 i;
    f32 t;
    ++*(s16*)(self+0x254);
    s32 time=*(s16*)(self+0x254);
    if(time>0) {
        if(time<25) {
            s32 d=25-time;
            f32 fraction=(f32)(d*d)/lbl_805436F8;
            *(f32*)(self+0xf8)=lbl_805436A8*fraction;
            t=(f32)*(s16*)(self+0x254)/lbl_805436C0;
            if(t<lbl_80543664) t=lbl_80543664;
            else if(t>lbl_80543668) t=lbl_80543668;
            {
                u64* names=(u64*)(base+0xb8);
                s32 i;
                for(i=0;i<17;i++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x26f+i];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        } else {
            *(f32*)(self+0xf8)=lbl_80543664;
            {
                u64* names=(u64*)(base+0xb8);
                s32 i;
                for(i=0;i<17;i++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x26f+i];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        }
    }
    time=*(s16*)(self+0x254);
    if(time>25) {
        if(time<45) {
            s32 d=20-(time-25);
            f32 fraction=(f32)(d*d)/lbl_805436B0;
            *(f32*)(self+0xfc)=lbl_8054368C*fraction;
        } else *(f32*)(self+0xfc)=lbl_80543664;
    }
    s32 lo;
    s32 hi;
    s32 lo2;
    u8* offsets;
    u8* bytes;
    u64* group;
    s32 k;
    offsets=self;
    lo2=0;
    bytes=self;
    group=(u64*)(base+0x140);
    k=0;
    hi=10;
    for(;k<4;k++,hi+=5,lo2+=5,offsets+=4,bytes+=6,group+=6) {
        lo=k*5;
        time=*(s16*)(self+0x254);
        if(time>lo) {
            if(time<hi) {
                s32 d=10-(time-lo2);
                f32 fraction=(f32)(d*d)/lbl_805436F0;
                *(f32*)(offsets+0x120)=lbl_805436AC*fraction;
                t=(f32)(*(s16*)(self+0x254)-lo2)/lbl_805436F4;
            if(t<lbl_80543664) t=lbl_80543664;
            else if(t>lbl_80543668) t=lbl_80543668;
                u8* alpha=bytes;
                u64* names=group;
                for(i=0;i<6;i++,alpha++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=alpha[0x280];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            } else {
                *(f32*)(offsets+0x120)=lbl_80543664;
                u8* alpha=bytes;
                u64* names=group;
                for(i=0;i<6;i++,alpha++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=alpha[0x280];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        }
    }
    time=*(s16*)(self+0x254);
    if(time>0) {
        if(time<15) {
            s32 d=15-time;
            f32 fraction=(f32)(d*d)/lbl_805436C4;
            f32 value=lbl_805436B0*fraction;
            *(f32*)(self+0x14c)=value;
            *(f32*)(self+0x138)=value;
            t=(f32)*(s16*)(self+0x254)/lbl_805436FC;
            if(t<lbl_80543664) t=lbl_80543664;
            else if(t>lbl_80543668) t=lbl_80543668;
            {
                u64* names=(u64*)(base+0x200);
                for(j=0;j<29;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x298+j];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
            {
                u64* names=(u64*)(base+0x2e8);
                for(j=0;j<22;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x2b5+j];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        } else {
            *(f32*)(self+0x14c)=lbl_80543664;
            *(f32*)(self+0x138)=lbl_80543664;
            {
                u64* names=(u64*)(base+0x200);
                for(j=0;j<29;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x298+j];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
            {
                u64* names=(u64*)(base+0x2e8);
                for(j=0;j<22;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x2b5+j];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        }
    }
    if(*(s16*)(self+0x254)>=75) {
        *(s16*)(self+0x254)=0;
        *(s32*)(self+0x1d8)=*(s32*)(self+0x1d4);
        *(s32*)(self+0x1d4)=3;
    }
    (*(J2DPane**)(self+4))->search(0x506d616462623037ULL)->move(*(f32*)(self+0xf0),*(f32*)(self+0xf4)+*(f32*)(self+0xf8));
    fn_80402E08(*(void**)(self+0x78),lbl_80543664,*(f32*)(self+0xfc));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623034ULL)->move(*(f32*)(self+0x100)+*(f32*)(self+0x120),*(f32*)(self+0x110));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623038ULL)->move(*(f32*)(self+0x104)+*(f32*)(self+0x124),*(f32*)(self+0x114));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623132ULL)->move(*(f32*)(self+0x108)+*(f32*)(self+0x128),*(f32*)(self+0x118));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623136ULL)->move(*(f32*)(self+0x10c)+*(f32*)(self+0x12c),*(f32*)(self+0x11c));
    (*(J2DPane**)(self+4))->search(0x004e646174613032ULL)->move(*(f32*)(self+0x130)+*(f32*)(self+0x138),*(f32*)(self+0x134));
    (*(J2DPane**)(self+4))->search(0x004e646174613035ULL)->move(*(f32*)(self+0x13c)+*(f32*)(self+0x14c),*(f32*)(self+0x140));
    (*(J2DPane**)(self+4))->search(0x004e646174613037ULL)->move(*(f32*)(self+0x144)+*(f32*)(self+0x14c),*(f32*)(self+0x148));
    t = (*(J2DPane**)(self+4))->search(0x50736375726f3032ULL)->getBounds()->i.y;
    (*(J2DPane**)(self+4))->search(0x50736375726f3032ULL)->move(*(f32*)(self+0x19c), t);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
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

extern "C" u32 lbl_804B06A0[];
static void fn_803F01F4(void) {
    u32* g = lbl_804B06A0;
    g[45] = g[0]; g[46] = g[1]; g[47] = g[2]; g[48] = g[3]; g[49] = g[4]; g[50] = g[5]; g[51] = g[6]; g[52] = g[7];
    g[53] = g[8]; g[54] = g[9]; g[55] = g[10]; g[56] = g[11]; g[57] = g[12]; g[58] = g[13]; g[59] = g[14]; g[60] = g[15];
    g[61] = g[16]; g[62] = g[17]; g[63] = g[18]; g[64] = g[19]; g[65] = g[20]; g[66] = g[21]; g[67] = g[22]; g[68] = g[23];
    g[69] = g[24]; g[70] = g[25]; g[71] = g[26]; g[72] = g[27]; g[73] = g[28]; g[74] = g[29]; g[75] = g[30]; g[76] = g[31];
    g[77] = g[32]; g[78] = g[33]; g[79] = g[34]; g[80] = g[35]; g[81] = g[36]; g[82] = g[37]; g[83] = g[38]; g[84] = g[39];
    g[85] = g[40]; g[86] = g[41];
    g[135] = g[90]; g[136] = g[91]; g[137] = g[92]; g[138] = g[93]; g[139] = g[94]; g[140] = g[95]; g[141] = g[96]; g[142] = g[97];
    g[143] = g[98]; g[144] = g[99]; g[145] = g[100]; g[146] = g[101]; g[147] = g[102]; g[148] = g[103]; g[149] = g[104]; g[150] = g[105];
    g[151] = g[106]; g[152] = g[107]; g[153] = g[108]; g[154] = g[109]; g[155] = g[110]; g[156] = g[111]; g[157] = g[112]; g[158] = g[113];
    g[159] = g[114]; g[160] = g[115]; g[161] = g[116]; g[162] = g[117]; g[163] = g[118]; g[164] = g[119]; g[165] = g[120]; g[166] = g[121];
    g[167] = g[122]; g[168] = g[123]; g[169] = g[124]; g[170] = g[125]; g[171] = g[126]; g[172] = g[127]; g[173] = g[128]; g[174] = g[129];
    g[175] = g[130]; g[176] = g[131];
    g[225] = g[180]; g[226] = g[181]; g[227] = g[182]; g[228] = g[183]; g[229] = g[184]; g[230] = g[185]; g[231] = g[186]; g[232] = g[187];
    g[233] = g[188]; g[234] = g[189]; g[235] = g[190]; g[236] = g[191]; g[237] = g[192]; g[238] = g[193]; g[239] = g[194]; g[240] = g[195];
    g[241] = g[196]; g[242] = g[197]; g[243] = g[198]; g[244] = g[199]; g[245] = g[200]; g[246] = g[201]; g[247] = g[202]; g[248] = g[203];
    g[249] = g[204]; g[250] = g[205]; g[251] = g[206]; g[252] = g[207]; g[253] = g[208]; g[254] = g[209]; g[255] = g[210]; g[256] = g[211];
    g[257] = g[212]; g[258] = g[213]; g[259] = g[214]; g[260] = g[215]; g[261] = g[216]; g[262] = g[217]; g[263] = g[218]; g[264] = g[219];
    g[265] = g[220]; g[266] = g[221]; g[267] = g[222]; g[268] = g[223]; g[269] = g[224];
}

