#include "types.h"

class J2DGrafContext;
class J2DScreen {
public:
    void draw(f32, f32, const J2DGrafContext*);
};
struct Tu803E1668Obj {};
typedef void (Tu803E1668Obj::*Tu803E1668Fn)();


extern void* lbl_8053AF80;
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

extern "C" void fn_803ED5B4(u8* param_1) {
    if (param_1[0x26e] == 0) {
        *(s32*)(param_1 + 0x1dc) = 9;
        param_1[0x26e] = 1;
    }
    *(s32*)(param_1 + 0x1b8) = 1;
    fn_80458880(lbl_8053AF80, 0xb, -1);
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

