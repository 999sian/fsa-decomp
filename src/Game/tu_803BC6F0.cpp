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
        void (*fn)(void*, s32) = (*(DtorVt**)obj)->v2;
        fn(obj, 1);
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
extern "C" f32 lbl_80543458;
extern "C" f32 lbl_80543498;
extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" u32 fn_803B9940(void* a, s32 b);
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
extern "C" void fn_80402E08(void* state, f32 x, f32 y);
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

extern "C" void fn_803C1054(u8* p) {
    u32* pair;
    s32 i;

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
    f64 d;
    void* r;

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
                *(u32*)&d = 0x43300000;
                *((u32*)&d + 1) = (u32)(t * t) ^ 0x80000000;
                v = (f32)(d - lbl_80543468) * lbl_805434A4 / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else if (t < 10) {
                *(u32*)&d = 0x43300000;
                *((u32*)&d + 1) = (u32)((10 - t) * (10 - t)) ^ 0x80000000;
                v = (f32)(d - lbl_80543468) * lbl_805434A4 / lbl_805434A8;
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
        fn_80402E08(*(void**)(p + 0x34), *(f32*)(*(u8**)(p + p[0x114] * 4 + 0x24) + 8) - *(f32*)(*(u8**)(p + 0x24) + 8), v);
        fn_8040245C(*(void**)(p + 0x34), 0x3c, 0, (*(u8**)(p + 0x34))[0x28], 1);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)*(void**)(p + 8))[15])(*(void**)(p + 8), 0x50610000, 0x50616363, 0x75723031);
        fn_804023D0(*(void**)(p + 0x34), r, (*(u8**)(p + 0x34))[0x28]);
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
        {
            void* obj = *(void**)(p + 0x8);
            void* r = ((void* (*)(void*, u32, u32, u32))((void**)*(void**)obj)[15])(obj, 0x50610000, 0x50616363, 0x75723031);
            fn_804023D0(*(void**)(p + 0x34), r, *(u8*)(*(u8**)(p + 0x34) + 0x28));
        }
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
                    *(s32*)(p + 0x80) = 0;
                    b = (u8*)lbl_8050EC80;
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
        char* pane = *(char**)(p + 0x20);
        if (*bounds - *(f32*)(pane + 8) < lbl_80543498) {
            *(s16*)(pane + 0x20) = 0;
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
            ((DtorVt*)obj)->v3(obj);
        }
        lbl_8053ADB0 = 0;
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

