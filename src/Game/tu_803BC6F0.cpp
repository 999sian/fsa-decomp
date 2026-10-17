#include "types.h"

struct VtSlot9 {
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    void* v5;
    void* v6;
    void* v7;
    void* v8;
    void (*v9)(void* a, s32 b);
};

extern "C" void* lbl_8053AD30;
extern "C" void* lbl_8053AF80;
extern "C" u32 fn_80309C4C(void* a, u32 b, int c);
extern "C" void fn_80458880(void* a, int b, int c);
extern "C" void fn_803C0018(char* p);


extern "C" void OSResetSystem(int reset, unsigned long resetCode, int forceMenu);
extern "C" u32 fn_80309A9C(void* a, u32 b, int c);
extern "C" void fn_803C05D8(u8* p);
extern "C" void fn_8040245C(void* a, s32 b, s32 c, u8 d, s32 e);
extern "C" f32 lbl_80543458;

extern "C" char lbl_804AFF60[];
extern "C" char lbl_80529DEC[];
extern "C" u32 lbl_8053ADB0;
extern "C" u32 getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void __dl__FPv(void* p);

struct DtorVt {
    void* v0;
    void* v1;
    void (*v2)(void* a, s32 b);
    void (*v3)(void* a);
};

static inline void releaseSlot(void* obj) {
    if (obj != 0) {
        ((void (*)(void*, s32))((*(u32**)obj)[2]))(obj, 1);
    }
}

struct J2DTextBoxVt {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(u32 a);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void* v15(u32 a, u32 b, u32 c);
};
extern "C" char lbl_8051C1A0[];
extern "C" char lbl_8050EC80[];
extern "C" u8* lbl_8053AAF8;
extern "C" int fn_803B9A94(void* a, u32 b, int c, u32 d, int e, int f);
extern "C" void fn_803C24BC(char* p);
extern "C" s32 fn_803B9BDC(char* this_);
extern "C" void fn_803BF004(char* this_);
extern "C" void fn_803B93E8(void* a, void* b, void* c, s32 d);
extern "C" void fn_803BACF8(void* a, u8 b);
extern "C" u32 lbl_80476938[];
extern "C" u32 lbl_80476980[];
extern "C" f32 lbl_80543458;
extern "C" f32 lbl_80543498;
extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" u32 fn_803B9940(void* a, s32 b);
extern "C" u8 fn_803B90E4(u32 a, s32 b);
extern "C" u8 fn_803B8CAC(u32 a, s32 b);
extern "C" void fn_803B9B8C(void* a);
extern "C" void fn_80402B10(void* a, s16 b, u8 c, f32 d);
extern "C" void fn_80402628(void* a, s16 b, u8 c, s32 d);
extern "C" void fn_804023D0(void* a, void* b, u8 c);
extern "C" void fn_803B9D54(void* a, void* b, u32 c, void* d, u32 e, s32 f);
extern "C" s32 CARDGetSerialNo(s32 chan, u64* serial);
extern "C" void fn_803CE4CC(char* p);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);
extern "C" f32 lbl_80543494;
extern "C" void fn_803832BC(char* a, s32 b, int c, int d, int e);
extern "C" u8 lbl_804765D0[];
extern "C" u8 lbl_8050DB0C[];
extern "C" f32 lbl_8054349C;
extern "C" u8 fn_80402940(void* p, s32 id, f32 a, f32 b, s32 c);

struct Clr {
    u8 r, g, b, a;
};

struct ColorVt {
    void* v[15];
    void* (*v15)(void* self, u32 a, u64 b);
    void* v16[60];
    void (*v76)(void* self, void* a, void* b);
};

struct TextBoxVt15 {
    void* v[15];
    void* (*v15)(void* a, u64 b);
};

extern u8 lbl_804765D0[];
typedef void* (*KeyGetFn)(void* self, u64 key);
typedef void (*Fn5Fn)(void* a, s16 b, s32 c, f32 d, f32 e);

// Virtual slot 15 of this_+8 maps a u64 key from the lbl_804765D0 table to an object, which is set on this_[cell+idx*4].
static inline void setCell(u8* this_, s32 cell, s32 idx, s32 keyOff, u8 flag) {
    u8* sub = *(u8**)(this_ + 8);
    void* o = ((KeyGetFn)(*(void***)sub)[15])(sub, *(u64*)(lbl_804765D0 + keyOff + idx * 8));
    fn_804023D0(*(void**)(this_ + cell + idx * 4), o, flag);
}

static inline void drawTextRow(u8* p, u8* q, u8* t) {
    s32 k;
    for (k = 0; k < 4; k++) {
        void* s = (*(TextBoxVt15**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u64*)t);
        fn_804023D0(*(void**)(q + 0x24), s, p[k + 0x19f]);
        t += 8;
    }
}

struct PaneVt9 {
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    void* v5;
    void* v6;
    void* v7;
    void* v8;
    void (*v9)(void* a, s32 b);
};

static inline void stopPane(void* obj) {
    (*(PaneVt9**)obj)->v9(obj, 0);
}
extern "C" void fn_80402E08(void* state, f32 x, f32 y);
extern "C" void fn_803BD5E0(u8* p, u32 idx) {
    u8* base = lbl_804765D0;
    u32 off = idx * 8;
    void* r;
    Clr a;
    a.r = 0x80; a.g = 0x80; a.b = 0x80; a.a = 0xff;
    Clr b;
    b.r = 0; b.g = 0; b.b = 0; b.a = 0;
    {
        Clr a2 = a;
        Clr b2 = b;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), idx, *(u64*)(base + 0x5d8 + off));
        (*(ColorVt**)r)->v76(r, &b2, &a2);
    }
    Clr c;
    c.r = 0xb4; c.g = 0xb4; c.b = 0xb4; c.a = 0xff;
    Clr d;
    d.r = 0x82; d.g = 0x82; d.b = 0x82; d.a = 0x00;
    {
        Clr d2 = d;
        Clr c2 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&d, *(u64*)(base + 0x5c0 + off));
        (*(ColorVt**)r)->v76(r, &d2, &c2);
    }
    {
        Clr d3 = d;
        Clr c3 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&c, *(u64*)(base + 0x5a8 + off));
        (*(ColorVt**)r)->v76(r, &d3, &c3);
    }
    {
        Clr d4 = d;
        Clr c4 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&c, *(u64*)(base + 0x590 + off));
        (*(ColorVt**)r)->v76(r, &d4, &c4);
    }
    {
        Clr d5 = d;
        Clr c5 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&c, *(u64*)(base + 0x578 + off));
        (*(ColorVt**)r)->v76(r, &d5, &c5);
    }
    {
        Clr n;
        n.r = d.r; n.g = d.g; n.b = d.b; n.a = 0xff;
        Clr n2 = n;
        Clr c6 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), d.b, *(u64*)(base + 0x560 + off));
        (*(ColorVt**)r)->v76(r, &n2, &c6);
    }
    Clr g;
    g.r = 0x50; g.g = 0x50; g.b = 0x50; g.a = 0x00;
    Clr f;
    f.r = 0x80; f.g = 0x80; f.b = 0x80; f.a = 0xff;
    {
        Clr g2 = g;
        Clr f2 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), 0, *(u64*)(base + 0x548 + off));
        (*(ColorVt**)r)->v76(r, &g2, &f2);
    }
    {
        Clr g3 = g;
        Clr f3 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x530 + off));
        (*(ColorVt**)r)->v76(r, &g3, &f3);
    }
    {
        Clr g4 = g;
        Clr f4 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x518 + off));
        (*(ColorVt**)r)->v76(r, &g4, &f4);
    }
    {
        Clr g5 = g;
        Clr f5 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x500 + off));
        (*(ColorVt**)r)->v76(r, &g5, &f5);
    }
    {
        Clr g6 = g;
        Clr f6 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x4e8 + off));
        (*(ColorVt**)r)->v76(r, &g6, &f6);
    }
    Clr h;
    h.r = 0x82; h.g = 0x82; h.b = 0x82; h.a = 0xff;
    Clr i;
    i.r = 0x64; i.g = 0x64; i.b = 0x64; i.a = 0x00;
    {
        Clr i2 = i;
        Clr h2 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&i, *(u64*)(base + 0x6c8 + off));
        (*(ColorVt**)r)->v76(r, &i2, &h2);
    }
    {
        Clr i3 = i;
        Clr h3 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&h, *(u64*)(base + 0x6b0 + off));
        (*(ColorVt**)r)->v76(r, &i3, &h3);
    }
    {
        Clr i4 = i;
        Clr h4 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&h, *(u64*)(base + 0x698 + off));
        (*(ColorVt**)r)->v76(r, &i4, &h4);
    }
    {
        Clr i5 = i;
        Clr h5 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&h, *(u64*)(base + 0x680 + off));
        (*(ColorVt**)r)->v76(r, &i5, &h5);
    }
    {
        Clr n3;
        n3.r = i.r; n3.g = i.g; n3.b = i.b; n3.a = 0xff;
        Clr n4 = n3;
        Clr h6 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), i.b, *(u64*)(base + 0x668 + off));
        (*(ColorVt**)r)->v76(r, &n4, &h6);
    }
    Clr j;
    j.r = 0xb4; j.g = 0xb4; j.b = 0xb4; j.a = 0xff;
    Clr k;
    k.r = 0xb4; k.g = 0xb4; k.b = 0xb4; k.a = 0x00;
    {
        Clr k2 = k;
        Clr j2 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), 0, *(u64*)(base + 0x650 + off));
        (*(ColorVt**)r)->v76(r, &k2, &j2);
    }
    {
        Clr k3 = k;
        Clr j3 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&j, *(u64*)(base + 0x638 + off));
        (*(ColorVt**)r)->v76(r, &k3, &j3);
    }
    {
        Clr k4 = k;
        Clr j4 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&j, *(u64*)(base + 0x620 + off));
        (*(ColorVt**)r)->v76(r, &k4, &j4);
    }
    {
        Clr k5 = k;
        Clr j5 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&j, *(u64*)(base + 0x608 + off));
        (*(ColorVt**)r)->v76(r, &k5, &j5);
    }
}

extern "C" void fn_803BDD44(u8* p, s32 idx) {
    s32 off;
    void* q;
    u32 v08, v0c, v10, v14, v18, v1c, v20, v24, v28, v2c, v30, v34, v38, v3c, v40, v44;
    u32 v48, v4c, v50, v54, v58, v5c, v60, v64, v68, v6c, v70, v74, v78, v7c, v80, v84;
    u32 v88, v8c, v90, v94, v98, v9c, va0, va4, va8, vb0, vb4, vb8, vbc, vc0, vc4, vc8, vcc;

    off = idx * 8;
    vc8 = *(u32*)(p + 0xe8);
    vcc = *(u32*)(p + 0xfc);
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), idx, *(u32*)(lbl_804765D0 + 0x5d8 + off), *(u32*)(lbl_804765D0 + 0x5dc + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &vcc, &vc8);

    vc0 = *(u32*)(p + 0xec);
    v80 = vc0;
    v7c = *(u32*)(p + 0x100);
    vc4 = v7c;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vc4, *(u32*)(lbl_804765D0 + 0x5c0 + off), *(u32*)(lbl_804765D0 + 0x5c4 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v7c, &v80);

    v88 = vc0;
    v84 = vc4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vc0, *(u32*)(lbl_804765D0 + 0x5a8 + off), *(u32*)(lbl_804765D0 + 0x5ac + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v84, &v88);

    v90 = vc0;
    v8c = vc4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vc0, *(u32*)(lbl_804765D0 + 0x590 + off), *(u32*)(lbl_804765D0 + 0x594 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v8c, &v90);

    v98 = vc0;
    v94 = vc4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vc0, *(u32*)(lbl_804765D0 + 0x578 + off), *(u32*)(lbl_804765D0 + 0x57c + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v94, &v98);

    va4 = vc0;
    ((u8*)&va0)[0] = ((u8*)&vc4)[0];
    ((u8*)&va0)[1] = ((u8*)&vc4)[1];
    ((u8*)&va0)[2] = ((u8*)&vc4)[2];
    ((u8*)&va0)[3] = 0xff;
    v9c = va0;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), ((u8*)&vc4)[2], *(u32*)(lbl_804765D0 + 0x560 + off), *(u32*)(lbl_804765D0 + 0x564 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v9c, &va4);

    vb8 = *(u32*)(p + 0xf0);
    vbc = *(u32*)(p + 0x104);
    v58 = vb8;
    v54 = vbc;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vbc, *(u32*)(lbl_804765D0 + 0x548 + off), *(u32*)(lbl_804765D0 + 0x54c + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v54, &v58);

    v60 = vb8;
    v5c = vbc;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb8, *(u32*)(lbl_804765D0 + 0x530 + off), *(u32*)(lbl_804765D0 + 0x534 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v5c, &v60);

    v68 = vb8;
    v64 = vbc;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb8, *(u32*)(lbl_804765D0 + 0x518 + off), *(u32*)(lbl_804765D0 + 0x51c + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v64, &v68);

    v70 = vb8;
    v6c = vbc;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb8, *(u32*)(lbl_804765D0 + 0x500 + off), *(u32*)(lbl_804765D0 + 0x504 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v6c, &v70);

    v78 = vb8;
    v74 = vbc;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb8, *(u32*)(lbl_804765D0 + 0x4e8 + off), *(u32*)(lbl_804765D0 + 0x4ec + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v74, &v78);

    vb0 = *(u32*)(p + 0xf4);
    vb4 = *(u32*)(p + 0x108);
    v2c = vb0;
    v28 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb4, *(u32*)(lbl_804765D0 + 0x6c8 + off), *(u32*)(lbl_804765D0 + 0x6cc + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v28, &v2c);

    v34 = vb0;
    v30 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb0, *(u32*)(lbl_804765D0 + 0x6b0 + off), *(u32*)(lbl_804765D0 + 0x6b4 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v30, &v34);

    v3c = vb0;
    v38 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb0, *(u32*)(lbl_804765D0 + 0x698 + off), *(u32*)(lbl_804765D0 + 0x69c + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v38, &v3c);

    v44 = vb0;
    v40 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb0, *(u32*)(lbl_804765D0 + 0x680 + off), *(u32*)(lbl_804765D0 + 0x684 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v40, &v44);

    ((u8*)&v4c)[0] = ((u8*)&vb4)[0];
    ((u8*)&v4c)[1] = ((u8*)&vb4)[1];
    ((u8*)&v4c)[2] = ((u8*)&vb4)[2];
    ((u8*)&v4c)[3] = 0xff;
    v48 = v4c;
    v50 = vb0;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), ((u8*)&vb4)[2], *(u32*)(lbl_804765D0 + 0x668 + off), *(u32*)(lbl_804765D0 + 0x66c + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v48, &v50);

    va8 = *(u32*)(p + 0xf8);
    vb4 = *(u32*)(p + 0x10c);
    v0c = va8;
    v08 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), vb4, *(u32*)(lbl_804765D0 + 0x650 + off), *(u32*)(lbl_804765D0 + 0x654 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v08, &v0c);

    v14 = va8;
    v10 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), va8, *(u32*)(lbl_804765D0 + 0x638 + off), *(u32*)(lbl_804765D0 + 0x63c + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v10, &v14);

    v1c = va8;
    v18 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), va8, *(u32*)(lbl_804765D0 + 0x620 + off), *(u32*)(lbl_804765D0 + 0x624 + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v18, &v1c);

    v24 = va8;
    v20 = vb4;
    q = ((void* (*)(void*, s32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), va8, *(u32*)(lbl_804765D0 + 0x608 + off), *(u32*)(lbl_804765D0 + 0x60c + off));
    ((void (*)(void*, void*, void*))(*(void***)q)[76])(q, &v20, &v24);
}

extern "C" void fn_803BF3BC(u8* this_) {
    u32 i;
    u32* tbl;
    void* o;

    *(u8*)(*(u8**)(*(u8**)(this_ + 0x20) + 4) + 0xb0) = 1;
    fn_80402E08(*(void**)(this_ + 0x50), lbl_80543494, lbl_80543458);
    *(u16*)(*(u8**)(this_ + 0x50) + 0x20) = 0;
    o = *(void**)(*(u8**)(this_ + 0x50) + 4);
    ((void (*)(void*, s32))(*(void***)o)[9])(o, 0);
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 0x8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 0x8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 0x8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 0x8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));

    if ((this_[0x115] & (u8)(1 << *(s32*)(this_ + 0xa4))) != 0) {
        *(u16*)(*(u8**)(this_ + 0x20) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x20) + 0x26) = 0;
    } else {
        *(u16*)(*(u8**)(this_ + 0x14) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x14) + 0x26) = 0;
        *(u16*)(*(u8**)(this_ + 0x18) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x18) + 0x26) = 0;
        *(u16*)(*(u8**)(this_ + 0x1c) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x1c) + 0x26) = 0;
        fn_80402E08(*(void**)(this_ + 0x20), lbl_80543498,
                    *(f32*)(*(u8**)(this_ + 0x3c) + 0xc) - *(f32*)(*(u8**)(this_ + 0x38) + 0xc));
        *(u16*)(*(u8**)(this_ + 0x20) + 0x20) = 0;
        o = *(void**)(*(u8**)(this_ + 0x20) + 4);
        ((void (*)(void*, s32))(*(void***)o)[9])(o, 0);
        tbl = lbl_80476938;
        for (i = 0; i < 9; i++) {
            fn_804023D0(*(void**)(this_ + 0x20), ((J2DTextBoxVt*)*(void**)(this_ + 0x4))->v15(0, tbl[0], tbl[1]), this_[0x196 + i]);
            tbl += 2;
        }
        *(u16*)(*(u8**)(this_ + 0x20) + 0x26) = 0;
    }
    o = *(void**)(*(u8**)(this_ + 0x34) + 4);
    ((void (*)(void*, s32))(*(void***)o)[9])(o, 0);
    fn_804023D0(*(void**)(this_ + 0x34), ((J2DTextBoxVt*)*(void**)(this_ + 0x8))->v15(0x50610000, 0x50616363, 0x75723031), *(u8*)(*(u8**)(this_ + 0x34) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x34) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x26) = 0;
    *(u16*)(this_ + 0xd8) = 0;
    *(u16*)(this_ + 0xda) = 0;
    this_[0x112] = this_[0x110];
    this_[0x110] = 0x16;
}

extern "C" void fn_803C02CC(u8* p) {
    s32 state = 0x117;
    if (lbl_8053AAF8[0x7f] != 0) {
        state = 0x116;
    }
    *(s32*)(p + 0x84) = state;
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(p + 8))->v15((u32)lbl_8053AAF8, 0x54, 0x66743031)), *(s32*)(p + 0x84), 0, 0, 0);
    if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
        *(s32*)(p + 0xb0) = 0x5a;
    }
    (*(PaneVt9**)(*(u8**)(*(u8**)(p + 0x50) + 4)))->v9(*(void**)(*(u8**)(p + 0x50) + 4), 0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;
    (*(PaneVt9**)(*(u8**)(*(u8**)(p + 0x34) + 4)))->v9(*(void**)(*(u8**)(p + 0x34) + 4), 0);
    fn_804023D0(*(void**)(p + 0x34), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x50610000, 0x50616363, 0x75723031), *(u8*)(*(u8**)(p + 0x34) + 0x28));
    if (p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) {
        *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    } else {
        *(s16*)(*(u8**)(p + 0x14) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x14) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x18) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x18) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x1c) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x1c) + 0x26) = 0;
    }
    *(s16*)(*(u8**)(p + 0x24) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x24) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x26) = 0;
    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x1c;
}

extern "C" void fn_803C05D8(u8* this_) {
    u32* tbl;
    s32 i;
    u8* q;
    void* o;

    tbl = lbl_80476980;
    i = 0;
    for (; i < 8; i++, tbl += 2) {
        u32 x;
        if (fn_803B90E4(*(u32*)(this_ + 0xa0), i)) {
            o = ((J2DTextBoxVt*)*(void**)(this_ + 4))->v15(x, tbl[4], tbl[5]);
            *(u8*)((u8*)o + 0xb0) = 0;
        } else {
            o = ((J2DTextBoxVt*)*(void**)(this_ + 4))->v15(x, tbl[4], tbl[5]);
            *(u8*)((u8*)o + 0xb0) = 1;
        }
    }

    *(u32*)(this_ + 0xa8) = *(u32*)(this_ + 0xa0);
    q = this_;
    for (i = 0; i < 8; i++) {
        *(u32*)(q + 0xb8) = fn_803B8CAC(*(u32*)(this_ + 0xa0), i);
        q += 4;
    }

    o = *(void**)(*(u8**)(this_ + 0x50) + 4);
    (*(VtSlot9**)o)->v9(o, 0);
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));

    *(u16*)(*(u8**)(this_ + 0x38) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x26) = 0;

    o = *(void**)(*(u8**)(this_ + 0x34) + 4);
    (*(VtSlot9**)o)->v9(o, 0);
    fn_804023D0(*(void**)(this_ + 0x34), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x50610000, 0x50616363, 0x75723031), *(u8*)(*(u8**)(this_ + 0x34) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x34) + 0x26) = 0;

    if ((this_[0x115] & (u8)(1 << *(s32*)(this_ + 0xa0))) != 0) {
        *(u8*)(*(u8**)(*(u8**)(this_ + 0x20) + 4) + 0xb0) = 1;
        fn_80402E08(*(void**)(this_ + 0x20), lbl_80543498, lbl_80543458);
        *(u16*)(*(u8**)(this_ + 0x20) + 0x20) = 0;
        o = *(void**)(*(u8**)(this_ + 0x20) + 4);
        (*(VtSlot9**)o)->v9(o, 0);
        tbl = lbl_80476938;
        for (i = 0; i < 9; i++, tbl += 2) {
            o = ((J2DTextBoxVt*)*(void**)(this_ + 4))->v15(0, tbl[0], tbl[1]);
            fn_804023D0(*(void**)(this_ + 0x20), o, this_[0x196 + i]);
        }
        *(u16*)(*(u8**)(this_ + 0x20) + 0x26) = 0;
    } else {
        *(u16*)(*(u8**)(this_ + 0x14) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x14) + 0x26) = 0;
        *(u16*)(*(u8**)(this_ + 0x18) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x18) + 0x26) = 0;
        *(u16*)(*(u8**)(this_ + 0x1c) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x1c) + 0x26) = 0;
    }

    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x74720000, 0x5473, 0x74723031)), 0x11e, 0, 0, 0);
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x6f700000, 0x5463, 0x6f703031)), 0x11f, 0, 0, 0);

    *(u16*)(*(u8**)(this_ + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x26) = 0;
    *(u16*)(this_ + 0xd8) = 0;
    *(u16*)(this_ + 0xda) = 0;
    this_[0x112] = this_[0x110];
    this_[0x110] = 0x1a;
}

extern "C" void fn_803C1054(u8* p) {
    s32 i;
    u32* pair;

    ((u8*)*(void**)(*(u8**)(p + 0x20) + 4))[0xb0] = 1;
    fn_80402E08(*(void**)(p + 0x50), -300.0f, 0.0f);
    *(u16*)(*(u8**)(p + 0x50) + 0x20) = 0;
    ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x50) + 4))->v9(0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723031), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723032), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723033), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723034), (*(u8**)(p + 0x50))[0x28]);

    if (p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) {
        *(u16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    } else {
        *(u16*)(*(u8**)(p + 0x14) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x14) + 0x26) = 0;
        *(u16*)(*(u8**)(p + 0x18) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x18) + 0x26) = 0;
        *(u16*)(*(u8**)(p + 0x1c) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x1c) + 0x26) = 0;
        fn_80402E08(*(void**)(p + 0x20), 600.0f, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
        *(u16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x20) + 4))->v9(0);
        pair = lbl_80476938;
        for (i = 0; i < 9; i++) {
            fn_804023D0(*(void**)(p + 0x20), ((J2DTextBoxVt*)*(void**)(p + 4))->v15(0, pair[0], pair[1]), p[0x196 + i]);
            pair += 2;
        }
        *(u16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    }
    ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x34) + 4))->v9(0);
    fn_804023D0(*(void**)(p + 0x34), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x50610000, 0x50616363, 0x75723031), (*(u8**)(p + 0x34))[0x28]);
    *(u16*)(*(u8**)(p + 0x34) + 0x26) = 0;
    *(u16*)(*(u8**)(p + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(p + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(p + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(p + 0x28) + 0x26) = 0;
    *(u16*)(p + 0xd8) = 0;
    *(u16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x16;
}

extern "C" void fn_803C21A8(u8* this_) {
    void* o;
    u32 state;

    fn_803CE4CC((char*)this_);
    state = 0x117;
    if (lbl_8053AAF8[0x7f] != 0) {
        state = 0x116;
    }
    *(u32*)(this_ + 0x84) = state;
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(state, 0x54, 0x66743031)), *(s32*)(this_ + 0x84), 0, 0, 0);
    if (*(u32*)(this_ + 0x84) == 0x60 || *(u32*)(this_ + 0x84) == 0x64) {
        *(s32*)(this_ + 0xb0) = 0x5a;
    }
    fn_80402E08(*(void**)(this_ + 0x50), lbl_80543494, lbl_80543458);
    *(u16*)(*(u8**)(this_ + 0x50) + 0x20) = 0;
    o = *(void**)(*(u8**)(this_ + 0x50) + 4);
    ((void (*)(void*, s32))(*(void***)o)[9])(o, 0);
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x38) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x14) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x14) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x18) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x18) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x1c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x1c) + 0x26) = 0;
    o = *(void**)(*(u8**)(this_ + 0x34) + 4);
    ((void (*)(void*, s32))(*(void***)o)[9])(o, 0);
    fn_804023D0(*(void**)(this_ + 0x34), ((J2DTextBoxVt*)*(void**)(this_ + 8))->v15(0x50610000, 0x50616363, 0x75723031), *(u8*)(*(u8**)(this_ + 0x34) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x2c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x2c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x30) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x30) + 0x26) = 0;
    *(u16*)(this_ + 0xd8) = 0;
    *(u16*)(this_ + 0xda) = 0;
    this_[0x112] = this_[0x110];
    this_[0x110] = 6;
}

extern u8 lbl_804765D0[];
typedef void* (*KeyGetFn)(void* self, u64 key);
typedef void (*Fn5Fn)(void* a, s16 b, s32 c, f32 d, f32 e);
extern "C" void fn_803C3904(u8* this_) {
    s32 order[3];
    s32* ord;
    s32 k;
    s32 off;
    s32 idx;
    s16 a = *(s16*)(lbl_8050DB0C + 0x200);
    s16 b = *(s16*)(lbl_8050DB0C + 0x202);
    s16 c = *(s16*)(lbl_8050DB0C + 0x1fe);
    s16 total = a + b + c;

    ord = order;
    if (*(s32*)(this_ + 0xa4) != 0) {
        *ord = 0;
        ord++;
    }
    if (*(s32*)(this_ + 0xa4) != 1) {
        *ord = 1;
        ord++;
    }
    if (*(s32*)(this_ + 0xa4) != 2) {
        *ord = 2;
    }
    *(s16*)(this_ + 0xd8) = *(s16*)(this_ + 0xd8) + 1;

    k = 0;
    off = 0;
    ord = order;
    do {
        if (c + off < *(s16*)(this_ + 0xd8)) {
            idx = *ord;
            ((Fn5Fn)fn_80402B10)(*(void**)(this_ + 0x38 + idx * 4), a, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(this_ + 0x38 + idx * 4), a, 0, *(u8*)(*(u8**)(this_ + 0x38 + idx * 4) + 0x28));
            idx = *ord;
            setCell(this_, 0x38, idx, 0x780, this_[0x125]);
            setCell(this_, 0x38, idx, 0x768, this_[0x126]);
            setCell(this_, 0x38, idx, 0x750, this_[0x127]);
            setCell(this_, 0x38, idx, 0x6c8, this_[0x128]);
            setCell(this_, 0x38, idx, 0x6b0, this_[0x129]);
            setCell(this_, 0x38, idx, 0x698, this_[0x12a]);
            setCell(this_, 0x38, idx, 0x680, this_[0x12b]);
            setCell(this_, 0x38, idx, 0x668, this_[0x12c]);
            setCell(this_, 0x38, idx, 0x650, this_[0x12d]);
            setCell(this_, 0x38, idx, 0x638, this_[0x12e]);
            setCell(this_, 0x38, idx, 0x620, this_[0x12f]);
            setCell(this_, 0x38, idx, 0x608, this_[0x130]);
            setCell(this_, 0x38, idx, 0x5f0, this_[0x131]);
            ((Fn5Fn)fn_80402B10)(*(void**)(this_ + 0x44 + idx * 4), a, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(this_ + 0x44 + idx * 4), a, 0, *(u8*)(*(u8**)(this_ + 0x44 + idx * 4) + 0x28));
            setCell(this_, 0x44, idx, 0x5d8, this_[0x118]);
            setCell(this_, 0x44, idx, 0x5c0, this_[0x119]);
            setCell(this_, 0x44, idx, 0x5a8, this_[0x11a]);
            setCell(this_, 0x44, idx, 0x590, this_[0x11b]);
            setCell(this_, 0x44, idx, 0x578, this_[0x11c]);
            setCell(this_, 0x44, idx, 0x560, this_[0x11d]);
            setCell(this_, 0x44, idx, 0x548, this_[0x11e]);
            setCell(this_, 0x44, idx, 0x530, this_[0x11f]);
            setCell(this_, 0x44, idx, 0x518, this_[0x120]);
            setCell(this_, 0x44, idx, 0x500, this_[0x121]);
            setCell(this_, 0x44, idx, 0x4e8, this_[0x122]);
            setCell(this_, 0x44, idx, 0x4d0, this_[0x123]);
            setCell(this_, 0x44, idx, 0x4b8, this_[0x124]);
        }
        off += b;
        ord++;
        k++;
    } while (k < 2);

    if (*(s32*)(this_ + 0xa4) != 0 && *(s16*)(this_ + 0xd8) > c) {
        idx = *(s32*)(this_ + 0xa4);
        ((Fn5Fn)fn_80402940)(*(void**)(this_ + 0x38 + idx * 4), a, 0,
                             *(f32*)(*(u8**)(this_ + 0x38) + 0xc) - *(f32*)(*(u8**)(this_ + 0x38 + idx * 4) + 0xc), lbl_80543458);
        ((Fn5Fn)fn_80402940)(*(void**)(this_ + 0x44 + idx * 4), a, 0,
                             *(f32*)(*(u8**)(this_ + 0x44) + 0xc) - *(f32*)(*(u8**)(this_ + 0x44 + idx * 4) + 0xc), lbl_80543458);
    }
    if (*(s16*)(this_ + 0xd8) > total) {
        this_[0x112] = this_[0x110];
        this_[0x110] = 5;
    }
}

extern "C" f32 lbl_805434A4;
extern "C" f32 lbl_805434A8;
extern "C" void fn_803BF3BC(u8* p);
extern "C" void fn_803BF698(u8* p);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void fn_8040245C(void* a, s32 b, s32 c, u8 d, s32 e);
extern "C" f64 lbl_80543468;
extern "C" void fn_803C4054(u8* p) {
    f32 zero;
    f32 v;
    s16 t;
    s32 i;
    void* r;
    u8* q;

    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            *(s16*)(p + 0xda) = 1;
            *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                *(s16*)(p + 0xda) = 1;
                *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
                if (p[0x114] == 0) {
                    fn_803BF3BC(p);
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0;
                    fn_803BF698(p);
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }

    if (p[0x110] == 0x25) {
        t = *(s16*)(p + 0xda);
        v = lbl_80543458;
        if (t != 0) {
            if (t < 5) {
                v = (f32)(t * t) * lbl_805434A4 / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else if (t < 10) {
                v = (f32)((10 - t) * (10 - t)) * lbl_805434A4 / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else {
                *(s16*)(p + 0xda) = 0;
            }
        }
        zero = lbl_80543458;
        for (i = 0; i < 2; i++) {
            if (zero != v && i == p[0x114]) {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), zero, v);
            } else {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), lbl_80543458, lbl_80543458);
            }
        }
        q = p + p[0x114] * 4;
        fn_80402E08(*(void**)(p + 0x34), *(f32*)(*(u8**)(q + 0x24) + 8) - *(f32*)(*(u8**)(p + 0x24) + 8), v);
        fn_8040245C(*(void**)(p + 0x34), 0x3c, 0, (*(u8**)(p + 0x34))[0x28], 1);
        r = ((void* (*)(void*, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), 0x50616363, 0x75723031);
        fn_804023D0(*(void**)(p + 0x34), r, (*(u8**)(p + 0x34))[0x28]);
    }
}

extern "C" void fn_803C4330(char* p) {
    s32 state;

    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        fn_803CE4CC(p);
        state = 0x117;
        if (lbl_8053AAF8[0x7f] != 0) {
            state = 0x116;
        }
        *(s32*)(p + 0x84) = state;
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(p + 8))->v15(state, 0x54, 0x66743031)), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        fn_80402E08(*(void**)(p + 0x50), lbl_80543494, lbl_80543458);
        *(s16*)(*(char**)(p + 0x50) + 0x20) = 0;
        (*(PaneVt9**)(*(char**)(*(char**)(p + 0x50) + 4)))->v9(*(void**)(*(char**)(p + 0x50) + 4), 0);
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(char**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(char**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(char**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(char**)(p + 0x50) + 0x28));
        *(s16*)(*(char**)(p + 0x38) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x38) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x38) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x44) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x44) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x44) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x3c) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x3c) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x3c) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x48) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x48) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x48) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x40) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x40) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x40) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x4c) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x4c) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x4c) + 0x26) = 0;
        (*(PaneVt9**)(*(char**)(*(char**)(p + 0x34) + 4)))->v9(*(void**)(*(char**)(p + 0x34) + 4), 0);
        fn_804023D0(*(void**)(p + 0x34), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x50610000, 0x50616363, 0x75723031), *(u8*)(*(char**)(p + 0x34) + 0x28));
        *(s16*)(p + 0xd8) = 0;
        *(s16*)(p + 0xda) = 0;
        p[0x112] = p[0x110];
        p[0x110] = 0x26;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" void fn_803C579C(char* this_) {
    s32 r = fn_803B9BDC(lbl_8051C1A0);
    if (r == 2) {
        *(u32*)(this_ + 0x84) = 0;
        *(u32*)(this_ + 0x80) = 0x68;
        *(u8*)(this_ + 0x112) = *(u8*)(this_ + 0x110);
        *(u8*)(this_ + 0x110) = 0;
    } else if (r == 1) {
        fn_803BF004(this_);
    }
}

extern "C" void fn_803C61C4(u8* p) {
    s16 sVar;
    s16 E;
    s16 F;
    u8* tbl;
    s32 off;
    u8* q;
    s16 B;
    s16 C;
    s32 hi;
    s16 A;
    s32 i;
    s32 EF;
    s32 j;
    s32 lo;
    s32 n;

    tbl = lbl_804765D0;
    A = *(s16*)(lbl_8050DB0C + 0x1e2);
    B = *(s16*)(lbl_8050DB0C + 0x1e4);
    C = *(s16*)(lbl_8050DB0C + 0x1e0);
    sVar = *(s16*)(lbl_8050DB0C + 0x1e6);
    E = *(s16*)(lbl_8050DB0C + 0x1e8);
    F = *(s16*)(lbl_8050DB0C + 0x1ea);
    n = C + (B + A + 1);
    if (sVar < n) {
        sVar = n;
    }
    *(s16*)(p + 0xd8) += 1;
    if (p[0x112] != 5) {
        q = p;
        off = 0;
        for (i = 0; i < 4; i++) {
            lo = C + off;
            hi = A + lo;
            if (*(s16*)(p + 0xd8) > lo && *(s16*)(p + 0xd8) <= hi) {
                fn_80402940(*(void**)(q + 0x24), A, lbl_80543458, lbl_8054349C, 0);
                fn_80402628(*(void**)(q + 0x24), A, *(u8*)(*(u8**)(q + 0x24) + 0x28), 0);
                switch (i) {
                case 0:
                    drawTextRow(p, q, tbl + 0x7f8);
                    break;
                case 1:
                    drawTextRow(p, q, tbl + 0x7d8);
                    break;
                case 2:
                    drawTextRow(p, q, tbl + 0x7b8);
                    break;
                case 3:
                    drawTextRow(p, q, tbl + 0x798);
                    break;
                }
                if (*(s16*)(p + 0xd8) == hi) {
                    if (i == 0) {
                        char* s = getStringPtr__10J2DTextBoxCFv((*(TextBoxVt15**)(p + 0x8))->v15(*(void**)(p + 0x8), 0x547374723031ULL));
                        fn_803832BC(s, 0x11e, 0, 0, 0);
                        *(s16*)(*(u8**)(q + 0x24) + 0x22) = 0;
                        *(s16*)(*(u8**)(q + 0x24) + 0x26) = 0;
                    } else if (i == 1) {
                        char* s = getStringPtr__10J2DTextBoxCFv((*(TextBoxVt15**)(p + 0x8))->v15(*(void**)(p + 0x8), 0x54636F703031ULL));
                        fn_803832BC(s, 0x11f, 0, 0, 0);
                        *(s16*)(*(u8**)(q + 0x24) + 0x22) = 0;
                        *(s16*)(*(u8**)(q + 0x24) + 0x26) = 0;
                    }
                }
            }
            off += B;
            q += 4;
        }
    }

    q = p;
    off = 0;
    EF = E + F;
    for (j = 0; j < 2; j++) {
        if (*(s16*)(p + 0xd8) > sVar + off) {
            fn_80402940(*(void**)(q + 0x24), E, lbl_8054349C, lbl_80543458, 0);
            fn_80402628(*(void**)(q + 0x24), E, 0, *(u8*)(*(u8**)(q + 0x24) + 0x28));
            switch (j) {
            case 0:
                drawTextRow(p, q, tbl + 0x7f8);
                break;
            case 1:
                drawTextRow(p, q, tbl + 0x7d8);
                break;
            case 2:
                drawTextRow(p, q, tbl + 0x7b8);
                break;
            case 3:
                drawTextRow(p, q, tbl + 0x798);
                break;
            }
        }
        off += F;
        q += 4;
    }
    if (*(s16*)(p + 0xd8) > sVar + EF) {
        p[0x112] = p[0x110];
        p[0x110] = 0x25;
    }
}

extern "C" u8 lbl_8050DB0C[];
extern "C" u8 fn_80402940(void* p, s32 id, f32 a, f32 b, s32 c);
extern "C" void fn_803BC6F0(char* this_, u32 a, f32 t);
extern "C" void fn_803C6690(char* p) {
    s16 start = *(s16*)(lbl_8050DB0C + 0x1cc);
    s16 dur = *(s16*)(lbl_8050DB0C + 0x1ce);
    s32 end = start + dur;
    s32 i;
    *(s16*)(p + 0xd8) += 1;
    if (*(s16*)(p + 0xd8) > start) {
        for (i = 0; i < 3; i++) {
            fn_80402940(*(void**)(p + 0x38 + i * 4), dur, *(f32*)(p + 0x70 + i * 4), 0.0f, 0);
            fn_80402940(*(void**)(p + 0x44 + i * 4), dur, *(f32*)(p + 0x64 + i * 4), 0.0f, 0);
        }
        fn_803BC6F0(p, *(u32*)(p + 0xa4), 1.0f - (f32)(*(s16*)(p + 0xd8) - start) / (f32)dur);
    }
    if (*(s16*)(p + 0xd8) > end) {
        p[0x112] = p[0x110];
        p[0x110] = 5;
    }
}

extern "C" void fn_803C1054(u8* p);
extern "C" void fn_803C02CC(u8* p);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void fn_8040245C(void* a, s32 b, s32 c, u8 d, s32 e);
extern "C" f32 lbl_805434A4;
extern "C" f32 lbl_805434A8;
extern "C" void fn_803C7CA0(u8* p) {
    s32 i;
    f32 f31;
    f32 f30;
    s16 t;
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            *(s16*)(p + 0xda) = 1;
            *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                *(s16*)(p + 0xda) = 1;
                *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
                if (p[0x114] == 0) {
                    fn_803C1054(p);
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0;
                    fn_803C02CC(p);
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
    if (p[0x110] == 0x1b) {
        t = *(s16*)(p + 0xda);
        f30 = lbl_80543458;
        if (t) {
            if (t < 5) {
                f30 = lbl_805434A4 * (f32)(t * t) / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else if (t < 10) {
                f30 = lbl_805434A4 * (f32)((10 - t) * (10 - t)) / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else {
                *(s16*)(p + 0xda) = 0;
            }
        }
        f31 = lbl_80543458;
        for (i = 0; i < 2; i++) {
            if (f31 != f30 && i == p[0x114]) {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), f31, f30);
            } else {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), lbl_80543458, lbl_80543458);
            }
        }
        {
            u8* q = p + p[0x114] * 4;
            fn_80402E08(*(void**)(p + 0x34), *(f32*)(*(u8**)(q + 0x24) + 8) - *(f32*)(*(u8**)(p + 0x24) + 8), f30);
        }
        fn_8040245C(*(void**)(p + 0x34), 0x3c, 0, *(u8*)(*(u8**)(p + 0x34) + 0x28), 1);
        fn_804023D0(*(void**)(p + 0x34), ((J2DTextBoxVt*)*(void**)(p + 0x8))->v15(0x50610000, 0x50616363, 0x75723031), *(u8*)(*(u8**)(p + 0x34) + 0x28));
    }
}

extern "C" void fn_803C8B80(u8* p) {
    s32 i;
    f32 f31;
    f32 f30;
    s16 t;
    s32 state;

    if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) - 1;
        if (*(s32*)(p + 0xa0) < 0) {
            *(s32*)(p + 0xa0) = 2;
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) - 1;
            if (*(s32*)(p + 0xa0) < 0) {
                *(s32*)(p + 0xa0) = 2;
            }
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) - 1;
            if (*(s32*)(p + 0xa0) < 0) {
                *(s32*)(p + 0xa0) = 2;
            }
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
        if (*(s32*)(p + 0xa0) > 2) {
            *(s32*)(p + 0xa0) = 0;
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 2) {
                *(s32*)(p + 0xa0) = 0;
            }
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 2) {
                *(s32*)(p + 0xa0) = 0;
            }
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        p[0x114] = 1;
        *(s32*)(p + 0x84) = 0x62;
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x1100, 0x54, 0x66743031)), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        if (p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) {
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(p + 4))->v15(0x64620000, 0x54, 0x64623031)), 0x66, 0, 0, 0);
        } else {
            *(s32*)(p + 0x80) = 0;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
        fn_803C05D8(p);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(p + 0x80) = 0;
        state = 0x117;
        if (lbl_8053AAF8[0x7f] != 0) {
            state = 0x116;
        }
        *(s32*)(p + 0x84) = state;
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(p + 8))->v15(state, 0x54, 0x66743031)), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        fn_80402E08(*(void**)(p + 0x50), lbl_80543494, lbl_80543458);
        *(s16*)(*(u8**)(p + 0x50) + 0x20) = 0;
        ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x50) + 4))->v9(0);
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;
        *(s16*)(p + 0xd8) = 0;
        *(s16*)(p + 0xda) = 0;
        p[0x112] = p[0x110];
        p[0x110] = 0x1e;
        fn_80458880(lbl_8053AF80, 0xc, -1);
        if (p[0x110] == 0x19) {
            t = *(s16*)(p + 0xda);
            f30 = lbl_80543458;
            if (t != 0) {
                if (t < 5) {
                    f30 = lbl_805434A4 * (f32)(t * t) / lbl_805434A8;
                    *(s16*)(p + 0xda) = t + 1;
                } else if (t < 10) {
                    f30 = lbl_805434A4 * (f32)((10 - t) * (10 - t)) / lbl_805434A8;
                    *(s16*)(p + 0xda) = t + 1;
                } else {
                    *(s16*)(p + 0xda) = 0;
                }
            }
            f31 = lbl_80543458;
            for (i = 0; i < 3; i++) {
                if (f31 != f30 && *(s32*)(p + 0xa0) == i) {
                    fn_80402E08(*(void**)(p + 0x44 + i * 4), f31, *(f32*)(p + 0x64 + i * 4) + f30);
                } else {
                    fn_80402E08(*(void**)(p + 0x44 + i * 4), lbl_80543458, *(f32*)(p + 0x64 + i * 4));
                }
            }
            fn_80402E08(*(void**)(p + 0x50), lbl_80543458, *(f32*)((u8*)getBounds__7J2DPaneFv(*(void**)(*(u8**)(p + 0x44 + *(s32*)(p + 0xa0) * 4) + 4)) + 4) - *(f32*)(*(u8**)(p + 0x44) + 0xc));
            fn_8040245C(*(void**)(p + 0x50), 0x3c, 0, *(u8*)(*(u8**)(p + 0x50) + 0x28), 1);
        }
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    }
}

extern "C" void fn_803C92B8(char* p) {
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        fn_803C0018(p);
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" void fn_803C0A34(char* p);
extern "C" void fn_803CE4CC(char* p);
extern "C" void fn_803C9F14(char* this_) {
    s32 r = fn_803B9BDC(lbl_8051C1A0);
    if (r == 2) {
        *(u32*)(this_ + 0x84) = 0;
        *(u32*)(this_ + 0x80) = 0x69;
        *(u8*)(this_ + 0x112) = *(u8*)(this_ + 0x110);
        *(u8*)(this_ + 0x110) = 0;
    } else if (r == 1) {
        fn_803C0A34(this_);
    }
}

extern "C" void fn_803CBE38(char* p) {
    int r;
    r = fn_803B9A94(lbl_8051C1A0, *(u32*)(p + 0x5c), 0x258, *(u32*)(p + 0x60), 0x1d4c, 0);
    if (r != 0) {
        if (r == 1) {
            lbl_8053AAF8[0xff] = 1;
            fn_803C24BC(p);
            *(u64*)(lbl_8050EC80 + 8) = *(u64*)(lbl_8051C1A0 + 0x1ff8);
        } else if (r == 2) {
            p[0x112] = p[0x110];
            p[0x110] = 1;
        }
    }
}

extern "C" void fn_803CBEE0(void) {
    OSResetSystem(1, 1, 1);
}

extern "C" void fn_803CBF0C(char* p) {
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (*(u8*)(p + 0x114) != 0) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
        if (*(u8*)(p + 0x114) < 1) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) + 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
        if (*(u8*)(p + 0x114) == 0) {
            *(s32*)(p + 0x80) = 0;
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 0x10;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            if (*(u8*)((u8*)lbl_8053AAF8 + 0x7f) != 0) {
                *(s32*)(p + 0x80) = 0x5c;
            } else {
                *(s32*)(p + 0x80) = 0x256;
            }
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 3;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
    }
}

extern "C" void* lbl_8053AD30;
extern "C" void* lbl_8053AF80;
extern "C" u32 fn_80309C4C(void* a, u32 b, int c);
extern "C" void fn_80458880(void* a, int b, int c);
extern "C" void fn_803CC048(char* p) {
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        *(s32*)(p + 0x80) = 0;
        p[0x112] = p[0x110];
        p[0x110] = 1;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" char lbl_80529DEC[];
extern "C" int fn_803B9C5C(void* a);
extern "C" void fn_803CC0D8(char* p) {
    int r = fn_803B9C5C(lbl_8051C1A0);
    if (r == 1) {
        *(s32*)(p + 0x80) = 0x55;
        p[0x112] = p[0x110];
        p[0x110] = 0xe;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
        *(s32*)(p + 0xb0) = 0x5a;
    } else if (r == 2) {
        *(s32*)(p + 0x80) = 0x56;
        p[0x112] = p[0x110];
        p[0x110] = 0;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
    }
}

extern "C" void fn_803B9DDC(void* a);
extern "C" void fn_803CC17C(u8* p) {
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
                if (p[0x114] == 0) {
                    fn_803B9DDC(lbl_8051C1A0);
                    *(s32*)(p + 0x80) = 0x54;
                    p[0x112] = p[0x110];
                    p[0x110] = 0xd;
                    p[0x113] = 1;
                    lbl_80529DEC[0x24c] = 1;
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0x52;
                    p[0x112] = p[0x110];
                    p[0x110] = 2;
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
}

extern "C" void fn_803CC2BC(char* p) {
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (*(u8*)(p + 0x114) != 0) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
        if (*(u8*)(p + 0x114) < 1) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) + 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
        if (*(u8*)(p + 0x114) == 0) {
            *(s32*)(p + 0x80) = 0x53;
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 0xc;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            *(s32*)(p + 0x80) = 0x52;
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 2;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
    }
}

extern "C" void fn_803CC3DC(char* p) {
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        *(s32*)(p + 0x80) = 0;
        lbl_8053AAF8[0xff] = 1;
        fn_803C24BC(p);
        fn_80458880(lbl_8053AF80, 0xb, -1);
        *(u64*)(lbl_8050EC80 + 8) = *(u64*)(lbl_8051C1A0 + 0x1ff8);
    }
}

extern "C" void fn_803CC490(char* p) {
    int r = fn_803B9BDC(lbl_8051C1A0);
    if (r == 1) {
        *(s32*)(p + 0x80) = 0x5b;
        p[0x112] = p[0x110];
        p[0x110] = 0xa;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
        *(s32*)(p + 0xb0) = 0x5a;
    } else if (r == 2) {
        *(s32*)(p + 0x80) = 0x5a;
        fn_803CE4CC(p);
        p[0x112] = p[0x110];
        p[0x110] = 0;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
    }
}

extern "C" void fn_803CC53C(char* p) {
    u64 serial;
    fn_803B93E8(lbl_8050EC80, *(void**)(p + 0x5c), *(void**)(p + 0x60), 0);
    fn_803BACF8(*(void**)(p + 0x5c), 0);
    fn_803B93E8(lbl_8050EC80, *(void**)(p + 0x5c), *(void**)(p + 0x60), 1);
    fn_803BACF8(*(void**)(p + 0x5c), 1);
    fn_803B93E8(lbl_8050EC80, *(void**)(p + 0x5c), *(void**)(p + 0x60), 2);
    fn_803BACF8(*(void**)(p + 0x5c), 2);
    fn_803B9D54(lbl_8051C1A0, *(void**)(p + 0x5c), 0x258, *(void**)(p + 0x60), 0x1d4c, 0);
    p[0x112] = p[0x110];
    p[0x110] = 9;
    CARDGetSerialNo(((u8*)lbl_8051C1A0)[0x1ff4], &serial);
    *(u64*)(lbl_8051C1A0 + 0x1ff8) = serial;
}

extern "C" void fn_803CC62C(u8* p) {
    u32 r;
    r = fn_80309C4C(lbl_8053AD30, 1, 1);
    if (r != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        r = fn_80309C4C(lbl_8053AD30, 2, 1);
        if (r != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            r = fn_80309C4C(lbl_8053AD30, 0x100, 1);
            if (r != 0) {
                if (p[0x114] == 0) {
                    *(s32*)(p + 0x80) = 0x59;
                    p[0x112] = p[0x110];
                    p[0x110] = 8;
                    p[0x113] = 1;
                    lbl_80529DEC[0x24c] = 1;
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0x58;
                    p[0x112] = p[0x110];
                    p[0x110] = 2;
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
}

extern "C" void* lbl_8053AEC0;
extern "C" void fn_803C1734(u8* p);
extern "C" void fn_803BF9C4(u8* p);
extern "C" void fn_804310BC(void* a);
extern "C" u32 fn_80309A9C(void* a, u32 b, int c);
extern "C" u32 fn_80309A9A(void* a, u32 b, int c);
extern "C" void fn_803CD2DC(u8* p) {
    u8 flags;
    if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        flags = p[0x115];
        if (flags & (u8)(1 << *(s32*)(p + 0xa4))) {
            p[0x114] = 1;
            *(s32*)(p + 0x84) = 0x5e;
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(p + 8))->v15(flags, 0x54, 0x66743031)), *(s32*)(p + 0x84), 0, 0, 0);
            if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
                *(s32*)(p + 0xb0) = 0x5a;
            }
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DTextBoxVt*)*(void**)(p + 4))->v15(0x64620000, 0x54, 0x64623031)), 0x65, 0, 0, 0);
            fn_803BF9C4(p);
        } else {
            *(s32*)(p + 0xa0) = 0;
            fn_803C1734(p);
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        if (p[0x116] != 0) {
            fn_804310BC(lbl_8053AEC0);
            p[0x1a3] = 0;
        }
        *(s32*)(p + 0x1a8) = 2;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        fn_80458880(lbl_8053AF80, 0x26, -1);
        *(s32*)(p + 0xa4) = *(s32*)(p + 0xa4) + 1;
        if (*(s32*)(p + 0xa4) >= 3) {
            *(s32*)(p + 0xa4) = 0;
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
    } else if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        fn_80458880(lbl_8053AF80, 0x26, -1);
        *(s32*)(p + 0xa4) = *(s32*)(p + 0xa4) - 1;
        if (*(s32*)(p + 0xa4) < 0) {
            *(s32*)(p + 0xa4) = 2;
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
    }
    if (p[0x110] == 5) {
        f32 f30 = 0.0f;
        f32 f31;
        u8* q;
        s32 i;
        s16 t = *(s16*)(p + 0xda);
        if (t != 0) {
            if (t < 5) {
                f30 = (5.0f * (f32)(t * t)) / 25.0f;
                *(s16*)(p + 0xda) = t + 1;
            } else if (t < 10) {
                f30 = (5.0f * (f32)((10 - t) * (10 - t))) / 25.0f;
                *(s16*)(p + 0xda) = t + 1;
            } else {
                *(s16*)(p + 0xda) = 0;
            }
        }
        f31 = 0.0f;
        q = p;
        for (i = 0; i < 3; i++) {
            if (f31 != f30 && i == *(s32*)(p + 0xa4)) {
                fn_80402E08(*(void**)(q + 0x44), f31, f30);
            } else {
                fn_80402E08(*(void**)(q + 0x44), 0.0f, 0.0f);
            }
            q += 4;
        }
        f32* bounds = getBounds__7J2DPaneFv(*(void**)(((u8**)(p + 0x44))[*(s32*)(p + 0xa4)] + 4));
        fn_80402E08(*(void**)(p + 0x50), 0.0f, bounds[1] - *(f32*)(*(u8**)(p + 0x44) + 0xc));
        fn_8040245C(*(void**)(p + 0x50), 0x3c, 0, *(u8*)(*(u8**)(p + 0x50) + 0x28), 1);
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723031), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723032), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723033), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DTextBoxVt*)*(void**)(p + 8))->v15(0x500000, 0x506663, 0x75723034), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    }
}

extern "C" void fn_803B950C(void* a, void* b);
extern "C" void fn_80403680(void* p);
extern "C" void fn_803CDEE8(u8* p) {
    u32 r;
    u8* a;
    u8* b;
    int i;
    r = fn_80309C4C(lbl_8053AD30, 1, 1);
    if (r != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        r = fn_80309C4C(lbl_8053AD30, 2, 1);
        if (r != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            r = fn_80309C4C(lbl_8053AD30, 0x100, 1);
            if (r != 0) {
                if (p[0x114] == 0) {
                    b = (u8*)lbl_8050EC80;
                    *(s32*)(p + 0x80) = 0;
                    a = b;
                    lbl_8053AAF8[0xff] = 0;
                    for (i = 0; i < 3; i++) {
                        fn_803B950C(a + 0x20, b + 0x280);
                        a = a + 0xc8;
                        b = b + 0x9c4;
                    }
                    fn_80403680(&lbl_80529DEC);
                    fn_803C24BC((char*)p);
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0;
                    p[0x112] = p[0x110];
                    p[0x110] = 1;
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
}

extern "C" void fn_803CE05C(char* p) {
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0) {
        if (*(u32*)(p + 0x7c) == 0x51) {
            *(s32*)(p + 0x80) = 0x83;
        } else if (*(u32*)(p + 0x7c) == 0x83) {
            *(s32*)(p + 0x80) = 0x84;
            p[0x112] = p[0x110];
            p[0x110] = 0xf;
        } else {
            if (lbl_8053AAF8[0x7f] != 0) {
                *(s32*)(p + 0x80) = 0x5c;
            } else {
                *(s32*)(p + 0x80) = 0x256;
            }
            p[0x112] = p[0x110];
            p[0x110] = 3;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" void fn_803CE11C(char* p) {
    s32 i;
    u32* pair;
    u32 state;
    f32* bounds;

    state = fn_803B9940(lbl_8051C1A0, 0);
    bounds = getBounds__7J2DPaneFv(*(void**)(*(char**)(p + 0x20) + 4));
    if (*bounds - *(f32*)(*(char**)(p + 0x20) + 8) < lbl_80543498) {
        fn_80402B10(*(void**)(p + 0x20), *(s16*)(lbl_8050DB0C + 0x1d2), 0, lbl_80543458);
        fn_80402628(*(void**)(p + 0x20), *(s16*)(lbl_8050DB0C + 0x1d2), *(u8*)(*(char**)(p + 0x20) + 0x28), 0);
        pair = lbl_80476938;
        for (i = 0; i < 9; i++) {
            fn_804023D0(*(void**)(p + 0x20), ((J2DTextBoxVt*)*(void**)(p + 4))->v15(0, pair[0], pair[1]), p[0x196 + i]);
            pair += 2;
        }
        p[0x117] = 0;
    } else {
        switch (state) {
        case 0:
            *(s32*)(p + 0x80) = 0x4c;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            fn_803C24BC(p);
            p[0x110] = 2;
            *(u32*)((u8*)lbl_8050EC80 + 0xc) = 0;
            *(u32*)((u8*)lbl_8050EC80 + 0x8) = 0;
            break;
        case 1:
            *(s32*)(p + 0x80) = 0x4d;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 2:
            *(s32*)(p + 0x80) = 0x4e;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 3:
            *(s32*)(p + 0x80) = 0x4f;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 4:
            *(s32*)(p + 0x80) = 0x50;
            p[0x112] = p[0x110];
            p[0x110] = 0xb;
            break;
        case 5:
            *(s32*)(p + 0x80) = 0x51;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 6:
            fn_803B9B8C(lbl_8051C1A0);
            *(s32*)(p + 0x80) = 0;
            p[0x112] = p[0x110];
            p[0x110] = 0x11;
            break;
        case 7:
            *(s32*)(p + 0x80) = 0x57;
            p[0x112] = p[0x110];
            p[0x110] = 7;
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        default:
            *(s32*)(p + 0x80) = 0;
            break;
        }
    }
}

extern "C" void fn_803832BC(char* a, s32 b, int c, int d, int e);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);
extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" f32 lbl_80543498;
extern "C" void fn_803CE370(char* p) {
    u32 r;
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        *(s32*)(p + 0x80) = 0;
        r = 0x117;
        if (lbl_8053AAF8[0x7f] != 0) {
            r = 0x116;
        }
        *(s32*)(p + 0x84) = r;
        void* tb = ((J2DTextBoxVt*)*(void**)(p + 8))->v15(r, 0x54, 0x66743031);
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(tb), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        f32* bounds = getBounds__7J2DPaneFv(*(void**)(*(char**)(p + 0x20) + 4));
        f32 w = *bounds;
        f32 h = *(f32*)(*(char**)(p + 0x20) + 8);
        if (w - h < lbl_80543498) {
            *(s16*)(*(char**)(p + 0x20) + 0x20) = 0;
            *(s16*)(*(char**)(p + 0x20) + 0x26) = 0;
            p[0x117] = 1;
        }
        p[0x112] = p[0x110];
        p[0x110] = 1;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern u32 lbl_8053ADB0;
extern "C" s32 fn_803CE4B0(void) {
    if (lbl_8053ADB0 != 0) {
        return *(s32*)(lbl_8053ADB0 + 0x1a8);
    }
    return 3;
}

extern "C" u8* fn_803CFFBC(u8* p, s16 flags) {
    void** q;
    s32 i;

    if (p != 0) {
        *(void**)p = lbl_804AFF60;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
        releaseSlot(*(void**)(p + 4));
        releaseSlot(*(void**)(p + 8));
        releaseSlot(*(void**)(p + 0x10));
        *(void**)(p + 0x10) = 0;
        releaseSlot(*(void**)(p + 0x14));
        *(void**)(p + 0x14) = 0;
        releaseSlot(*(void**)(p + 0x18));
        *(void**)(p + 0x18) = 0;
        releaseSlot(*(void**)(p + 0x1c));
        *(void**)(p + 0x1c) = 0;
        releaseSlot(*(void**)(p + 0x20));
        *(void**)(p + 0x20) = 0;

        q = (void**)p;
        i = 0;
        do {
            releaseSlot(q[9]);
            q[9] = 0;
            i++;
            q++;
        } while (i < 4);

        releaseSlot(*(void**)(p + 0x34));
        *(void**)(p + 0x34) = 0;

        q = (void**)p;
        i = 0;
        do {
            releaseSlot(q[0xe]);
            q[0xe] = 0;
            releaseSlot(q[0x11]);
            i++;
            q[0x11] = 0;
            q++;
        } while (i < 3);

        releaseSlot(*(void**)(p + 0x50));
        *(void**)(p + 0x50) = 0;
        releaseSlot(*(void**)(p + 0x54));
        *(void**)(p + 0x54) = 0;

        {
            void* obj = *(void**)(lbl_80529DEC + 0x30);
            (*(DtorVt**)obj)->v3(obj);
        }
        lbl_8053ADB0 = 0;
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

