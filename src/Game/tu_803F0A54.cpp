#include "types.h"

extern "C" void* lbl_8053AD30;
extern "C" void* fn_80309C4C(void* a, s32 b, s32 c);
extern "C" void* fn_80309A9C(void* a, s32 b, s32 c);
extern "C" void fn_80403680(void* p);
extern "C" u8 lbl_80529DEC[];

extern "C" void fn_8043670C(void* p, s32 a);
extern "C" void fn_80431A9C(void* p, s32 a, u8 b, s32 c);
extern void* lbl_8053AEC0;
extern void* lbl_8053AF80;
extern "C" void fn_80436668(void* p);
extern "C" s32 fn_804366B8(void* p);
extern "C" void fn_80458880(void* p, s32 a, s32 b);
extern "C" u8* lbl_8053AAF8;
extern const f32 lbl_8054372C;
extern const f32 lbl_80543768;
extern const f32 lbl_80543770;
extern const f32 lbl_80543774;
extern const f32 lbl_80543778;
extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern const f32 lbl_80543730;
extern const f32 lbl_80543784;
extern const f32 lbl_80543788;
extern const f32 lbl_8054378C;
extern const f32 lbl_8054377C;
extern const f32 lbl_80543790;
extern const f32 lbl_805437AC;
extern "C" void fn_80440EE8(void* p);
extern void* lbl_8053AED8;
struct T803FC46C;
typedef void (T803FC46C::*PMF803FC46C)();
extern PMF803FC46C lbl_804B0BDC[];

extern "C" void fn_803F1C18(u8* p) {
    fn_8043670C(*(void**)(p + 0x58), 1);
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xc;
}

extern "C" void fn_803F1C5C(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xb;
}

extern "C" void fn_803F2580(u8* p) {
    s32 j = 0;
    s32 i;
    s32 k;
    u8* b;

    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1d0) = 5;
    if (*(s32*)(p + 0x1a8) == 0) {
        i = 0;
        for (k = 0; k < 4; k++) {
            if (i < *(s32*)(p + 0x1ac) + 2) {
                lbl_8053AAF8[0x82] |= (u8)(1 << i);
                b = lbl_8053AAF8;
                b[0x83] &= ~(u8)(3 << j);
                b[0x83] |= (u8)(1 << j);
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
            }
            j += 2;
            i++;
        }
    }
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 9;
}

extern "C" void fn_803F2660(u8* p) {
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 8;
}

extern "C" void* getStringPtr__10J2DTextBoxCFv(void* p);
extern "C" void fn_803832BC(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void* fn_804031C4(s32 a, void* b);
extern "C" u8 lbl_80478A60[];
extern const f32 lbl_80543754;
extern const f32 lbl_8054375C;
extern const f32 lbl_80543760;
extern "C" void fn_803F267C(u8* p) {
    u8* base;
    void* s1;
    void* s2;
    void* s3;
    void* uVar1;
    void* piVar4;

    base = lbl_80478A60;
    s1 = getStringPtr__10J2DTextBoxCFv(((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x616e0000, 0x5468, 0x616e3031));
    s2 = getStringPtr__10J2DTextBoxCFv(((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x74610000, 0x5473, 0x74613031));
    s3 = getStringPtr__10J2DTextBoxCFv(((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x540000, 0x547275, 0x6c653031));
    fn_803832BC(s2, 0x11b, 0, 0, 0);
    fn_803832BC(s1, 0xac, 0, 0, 0);
    fn_803832BC(s3, 0xf7, 0, 0, 0);

    if (*(s32*)(p + 0x1ac) == 0) {
        uVar1 = fn_804031C4(0x54494d47, base + 0xf30);
        piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x6f700000, 0x506e, 0x6f703032);
        ((void (*)(void*, void*, s32))(*(void***)piVar4)[68])(piVar4, uVar1, 0);
        piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x6f700000, 0x506e, 0x6f703031);
        ((void (*)(void*, void*, s32))(*(void***)piVar4)[68])(piVar4, uVar1, 0);
    } else if (*(s32*)(p + 0x1ac) == 1) {
        uVar1 = fn_804031C4(0x54494d47, base + 0xf44);
        piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x6f700000, 0x506e, 0x6f703032);
        ((void (*)(void*, void*, s32))(*(void***)piVar4)[68])(piVar4, uVar1, 0);
        piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x6f700000, 0x506e, 0x6f703031);
        ((void (*)(void*, void*, s32))(*(void***)piVar4)[68])(piVar4, uVar1, 0);
    } else {
        uVar1 = fn_804031C4(0x54494d47, base + 0xf58);
        piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x6f700000, 0x506e, 0x6f703032);
        ((void (*)(void*, void*, s32))(*(void***)piVar4)[68])(piVar4, uVar1, 0);
        piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x6f700000, 0x506e, 0x6f703031);
        ((void (*)(void*, void*, s32))(*(void***)piVar4)[68])(piVar4, uVar1, 0);
    }

    *(f32*)(p + 0x164) = lbl_80543754;
    *(f32*)(p + 0x168) = lbl_80543754;
    *(f32*)(p + 0x184) = lbl_8054375C;
    *(f32*)(p + 0x188) = lbl_8054375C;
    *(f32*)(p + 0x18c) = lbl_8054375C;
    *(f32*)(p + 0x198) = lbl_80543760;

    piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x62620000, 0x506d6261, 0x62623037);
    ((void (*)(void*, f32, f32))(*(void***)piVar4)[4])(piVar4, *(f32*)(p + 0x15c), *(f32*)(p + 0x160) + *(f32*)(p + 0x164));
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x168));

    piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x00500000, 0x507374, 0x61623034);
    ((void (*)(void*, f32, f32))(*(void***)piVar4)[4])(piVar4, *(f32*)(p + 0x16c) + *(f32*)(p + 0x184), *(f32*)(p + 0x178));

    piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x00500000, 0x506861, 0x6e623034);
    ((void (*)(void*, f32, f32))(*(void***)piVar4)[4])(piVar4, *(f32*)(p + 0x170) + *(f32*)(p + 0x188), *(f32*)(p + 0x17c));

    piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x75620000, 0x5072, 0x75623034);
    ((void (*)(void*, f32, f32))(*(void***)piVar4)[4])(piVar4, *(f32*)(p + 0x174) + *(f32*)(p + 0x18c), *(f32*)(p + 0x180));

    piVar4 = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 0xc)))[15])(*(void**)(p + 0xc), 0x506c0000, 0x506c6962, 0x6b6b3033);
    ((void (*)(void*, f32, f32))(*(void***)piVar4)[4])(piVar4, *(f32*)(p + 0x190) + *(f32*)(p + 0x198), *(f32*)(p + 0x194));

    *(s32*)(p + 0x1d0) = 0;
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x210) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 7;
}

extern "C" void fn_803F2AEC(u8* p) {
    fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1ac) + 2), 0);
    *(u8*)(p + 0x25c) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 6;
}

extern "C" void fn_803F2B48(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 5;
}

extern "C" void fn_803F2B5C(u8* p) {
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 4;
}

extern "C" void fn_803F32E8(u8* p) {
    *(s32*)(p + 0x210) = 0;
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1d0) = 5;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 2;
}

extern "C" void fn_803F3310(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 1;
}

extern "C" void fn_803F3324(u8* p) {
    void* obj;
    void* self;

    *(f32*)(p + 0x110) = lbl_80543770;
    self = *(void**)(p + 4);
    obj = ((void* (*)(void*, s32, s32, s32))(*(void***)self)[15])(self, 0x62620000, 0x506d6261, 0x62623037);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x108), *(f32*)(p + 0x10c) + *(f32*)(p + 0x110));
    *(f32*)(p + 0x114) = lbl_80543768;
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x114));

    *(f32*)(p + 0x130) = lbl_80543774;
    self = *(void**)(p + 4);
    obj = ((void* (*)(void*, s32, s32, s32))(*(void***)self)[15])(self, 0x70620000, 0x506e6f, 0x70623038);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x118) + *(f32*)(p + 0x130), *(f32*)(p + 0x124));
    *(f32*)(p + 0x134) = lbl_80543774;
    self = *(void**)(p + 4);
    obj = ((void* (*)(void*, s32, s32, s32))(*(void***)self)[15])(self, 0x70620000, 0x506e6f, 0x70623132);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x11c) + *(f32*)(p + 0x134), *(f32*)(p + 0x128));
    *(f32*)(p + 0x138) = lbl_80543774;
    self = *(void**)(p + 4);
    obj = ((void* (*)(void*, s32, s32, s32))(*(void***)self)[15])(self, 0x70620000, 0x506e6f, 0x70623136);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x120) + *(f32*)(p + 0x138), *(f32*)(p + 0x12c));
    *(f32*)(p + 0x144) = lbl_80543778;
    self = *(void**)(p + 4);
    obj = ((void* (*)(void*, s32, s32, s32))(*(void***)self)[15])(self, 0x74610000, 0x4e6461, 0x74613032);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x13c) + *(f32*)(p + 0x144), *(f32*)(p + 0x140));
    *(f32*)(p + 0x158) = lbl_80543778;
    self = *(void**)(p + 4);
    obj = ((void* (*)(void*, s32, s32, s32))(*(void***)self)[15])(self, 0x74610000, 0x4e6461, 0x74613035);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x148) + *(f32*)(p + 0x158), *(f32*)(p + 0x14c));
    self = *(void**)(p + 4);
    obj = ((void* (*)(void*, s32, s32, s32))(*(void***)self)[15])(self, 0x4e0000, 0x4e6461, 0x74613037);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x150) + *(f32*)(p + 0x158), *(f32*)(p + 0x154));

    *(s32*)(p + 0x210) = 0;
    *(s32*)(p + 0x1d0) = 0;
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0;
}

extern "C" void fn_803F358C(u8* p) {
    fn_80436668(*(void**)(p + 0x58));
}

extern "C" void fn_803F59A0(u8* p) {
    if (fn_804366B8(*(void**)(p + 0x58))) {
        if (p[0x25e] == 0) {
            *(s32*)(p + 0x1cc) = 7;
            p[0x25e] = 1;
        }
        *(s32*)(p + 0x1a8) = 0;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" u8 fn_80402940(void* p, s32 a, f32 x, f32 y, s32 b);
extern "C" void fn_803F715C(u8* p) {
    s32 t;
    u8* q;
    u8 a;
    u8 b;
    u8 c;
    s32 i;

    a = 0;
    b = 0;
    c = 0;
    *(s16*)(p + 0x24c) = *(s16*)(p + 0x24c) + 1;
    if (*(s16*)(p + 0x24c) > 0) {
        a = fn_80402940(*(void**)(p + 0x60), 0x16, -200.0f, 0.0f, 0);
    }
    if (*(s16*)(p + 0x24c) > 0x10) {
        b = fn_80402940(*(void**)(p + 0x74), 0x18, -200.0f, 0.0f, 0);
    }
    q = p;
    i = 0;
    t = 4;
    for (; i < 4; i++, q += 4) {
        if (i <= *(s32*)(p + 0x1ac) + 1 && *(s16*)(p + 0x24c) > t) {
            c = fn_80402940(*(void**)(q + 0x64), 0x12, 150.0f, 0.0f, 0);
        }
        t += 5;
    }
    if (a != 0 && b != 0 && c != 0) {
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 0xb;
    }
}

extern "C" void fn_803F8050(u8* p) {
    s32 i;
    s32 j;
    s32 t = *(s16*)(p + 0x240);

    if (t != 0) {
        *(s16*)(p + 0x240) = t + 1;
        if (*(s16*)(p + 0x240) > 10) {
            *(s16*)(p + 0x240) = 0;
        }
    }
    *(s32*)(p + 0x210) = *(s32*)(p + 0x210) + 1;
    if (*(s32*)(p + 0x210) >= 0x1e) {
        *(s32*)(p + 0x210) = 0;
    }
    if (*(s32*)(p + 0x1c0) != *(s32*)(p + 0x1ac) + 2) {
        *(u8*)(p + 0x25c) = 0xff;
        (((T803FC46C*)p)->*lbl_804B0BDC[3])();
    } else {
        u8* q = lbl_80529DEC;
        if (fn_80309C4C(lbl_8053AD30, 0x1100, q[0x23d] + 2) != 0) {
            if (*(s32*)(p + 0x1a8) < 3) {
                *(s32*)(p + 0x1cc) = 0xd;
                *(s16*)(p + 0x240) = 0;
                *(s32*)(p + 0x1d0) = 5;
                if (*(s32*)(p + 0x1a8) == 0) {
                    s32 k;
                    u8* b;
                    i = 0;
                    j = i;
                    for (k = 0; k < 4; k++) {
                        if (i < *(s32*)(p + 0x1ac) + 2) {
                            lbl_8053AAF8[0x82] |= (u8)(1 << i);
                            b = lbl_8053AAF8;
                            b[0x83] &= ~(u8)(3 << j);
                            b[0x83] |= (u8)(1 << j);
                        } else {
                            lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                            lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
                        }
                        j += 2;
                        i++;
                    }
                }
                *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
                *(s32*)(p + 0x1c4) = 9;
            }
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else if (fn_80309C4C(lbl_8053AD30, 0x200, q[0x23d] + 2) != 0) {
            *(s32*)(p + 0x1cc) = 0;
            (((T803FC46C*)p)->*lbl_804B0BDC[9])();
            fn_80458880(lbl_8053AF80, 0xc, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 4, q[0x23d] + 2) != 0) {
            *(s32*)(p + 0x1a8) = *(s32*)(p + 0x1a8) + 1;
            if (*(s32*)(p + 0x1a8) >= 3) {
                *(s32*)(p + 0x1a8) = 0;
            }
            *(s16*)(p + 0x240) = 1;
            *(s32*)(p + 0x1d0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 8, q[0x23d] + 2) != 0) {
            *(s32*)(p + 0x1a8) = *(s32*)(p + 0x1a8) - 1;
            if (*(s32*)(p + 0x1a8) < 0) {
                *(s32*)(p + 0x1a8) = 2;
            }
            *(s16*)(p + 0x240) = 1;
            *(s32*)(p + 0x1d0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    }
    *(s32*)(p + 0x1d0) = *(s32*)(p + 0x1d0) + 1;
    if (*(s32*)(p + 0x1d0) >= 0x3c) {
        *(s32*)(p + 0x1d0) = 0;
    }
}

extern "C" s32 fn_804317AC(void* p);
extern "C" s32 fn_80431740(void* p);
extern "C" void fn_8013CC50(s32 a, f32* v, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" u8* sManager__8JUTVideo;
extern "C" u8 lbl_80479238[];
extern const f32 lbl_80543720;
extern const f32 lbl_80543728;
extern const f32 lbl_80543730;
extern const f32 lbl_805437A4;
extern const f32 lbl_805437C8;
extern const f32 lbl_805437CC;
extern const f32 lbl_805437A0;
extern "C" void fn_803F8FBC(u8* p) {
    s32 i;
    s32* ent;
    u8* q;
    f32 span;
    void* r;
    void** vt;
    u32 t1;
    u32 t2;
    f32 v1[3];
    f32 v2[3];

    switch (p[0x25c]) {
    case 0:
        if (fn_804317AC(lbl_8053AEC0)) {
            p[0x25c] = 1;
        }
        break;
    case 2:
        if (fn_80431740(lbl_8053AEC0)) {
            p[0x25c] = 0;
            *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
            *(s32*)(p + 0x1c4) = 5;
        }
        break;
    case 3:
        if (fn_80431740(lbl_8053AEC0)) {
            p[0x25c] = 0;
            *(s32*)(p + 0x350) = 2;
        }
        break;
    default:
        if (*(s32*)(p + 0x1c0) == *(s32*)(p + 0x1ac) + 2) {
            p[0x25c] = 2;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23d] + 2)) {
                p[0x25c] = 2;
                fn_80458880(lbl_8053AF80, 0xb, -1);
            } else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23d] + 2)) {
                p[0x25c] = 2;
                fn_80458880(lbl_8053AF80, 0xc, -1);
            }
        }
        break;
    }

    *(s16*)(p + 0x248) += 1;
    if (*(s16*)(p + 0x248) >= 100) {
        *(s16*)(p + 0x248) = 0;
    }
    *(s16*)(p + 0x24a) += 1;
    if (*(s16*)(p + 0x24a) >= 100) {
        *(s16*)(p + 0x24a) = 0;
    }

    ent = (s32*)lbl_80479238;
    q = p;
    for (i = 0; i < 4; i++, q += 4, ent += 2) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) {
            *(s32*)(q + 0x210) += 1;
            if (*(s32*)(q + 0x210) >= 0x82) {
                *(s32*)(q + 0x210) = 0x64;
            }
            if (*(s32*)(q + 0x210) == 0xb) {
                ((u8*)*(void**)(q + 0x78))[0x44] = 0;
                ((u8*)*(void**)(q + 0x78))[0x45] = 0;
                t1 = 0x10001;
                vt = *(void***)((u8*)*(void**)(q + 0x78) + 8);
                ((void (*)(void*, u32*))vt[5])(*(void**)(q + 0x78), &t1);
            } else if (*(s32*)(q + 0x210) == 0x24) {
                vt = *(void***)*(void**)(p + 8);
                r = ((void* (*)(void*, u8*, s32, s32))vt[15])(*(void**)(p + 8), lbl_8053AAF8, ent[0], ent[1]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                vt = *(void***)*(void**)(p + 8);
                r = ((void* (*)(void*, u8*, s32, s32))vt[15])(*(void**)(p + 8), lbl_8053AAF8, ent[0], ent[1]);
                *(f32*)(p + 0x88) = (lbl_805437A0 * (span * lbl_80543720 + *(f32*)((u8*)r + 0x30))) /
                                    ((f32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4) - 4503599627370496.0f);
                vt = *(void***)*(void**)(p + 8);
                r = ((void* (*)(void*))vt[15])(*(void**)(p + 8));
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                vt = *(void***)*(void**)(p + 8);
                r = ((void* (*)(void*, u8*, s32, s32))vt[15])(*(void**)(p + 8), lbl_8053AAF8, ent[0], ent[1]);
                *(f32*)(p + 0x8c) = (lbl_805437A4 * (lbl_80543728 + span * lbl_80543720 + *(f32*)((u8*)r + 0x34))) /
                                    ((f32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6) - 4503599627370496.0f);
                *(f32*)(p + 0x90) = lbl_8054372C;
                ((u8*)*(void**)(q + 0x78))[0x44] = 0;
                ((u8*)*(void**)(q + 0x78))[0x45] = 0;
                t2 = 0x2000E;
                vt = *(void***)((u8*)*(void**)(q + 0x78) + 8);
                ((void (*)(void*, u32*))vt[5])(*(void**)(q + 0x78), &t2);
                v1[0] = lbl_805437CC + *(f32*)(p + 0x88);
                v1[1] = *(f32*)(p + 0x8c) - lbl_805437C8;
                v1[2] = *(f32*)(p + 0x90);
                fn_8013CC50(0, v1, 0xcb, 1, 0, 0, 0, 1, lbl_80543730);
                v2[0] = lbl_805437CC + *(f32*)(p + 0x88);
                v2[1] = *(f32*)(p + 0x8c) - lbl_805437C8;
                v2[2] = *(f32*)(p + 0x90);
                fn_8013CC50(0, v2, 0xcc, 1, 0, 0, 0, 1, lbl_80543730);
            }
            *(s32*)(q + 0x210) = 0;
        }
    }
}

extern "C" void fn_803FB6F4(u8* p) {
    s32 j;
    s32 i;
    u8* cfg;
    u8* flags;

    if ((s32)*(s16*)(p + 0x240) != 0) {
        *(s16*)(p + 0x240) = *(s16*)(p + 0x240) + 1;
        if (*(s16*)(p + 0x240) > 10) {
            *(s16*)(p + 0x240) = 0;
        }
    }
    *(s32*)(p + 0x210) = *(s32*)(p + 0x210) + 1;
    if (*(s32*)(p + 0x210) >= 0x1e) {
        *(s32*)(p + 0x210) = 0;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        j = 0;
        *(s32*)(p + 0x1a8) = 0;
        lbl_8053AAF8[0x7e] = 1;
        if (*(s32*)(p + 0x1c0) == *(s32*)(p + 0x1ac) + 2) {
            for (i = 0; i < 4; j += 2, i++) {
                if (i < *(s32*)(p + 0x1ac) + 2) {
                    lbl_8053AAF8[0x82] |= (u8)(1 << i);
                    flags = lbl_8053AAF8;
                    flags[0x83] &= ~(u8)(3 << j);
                    flags[0x83] |= (u8)(1 << j);
                } else {
                    lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                    flags = lbl_8053AAF8;
                    flags[0x83] &= ~(u8)(3 << j);
                }
            }
            *(s32*)(p + 0x1cc) = 0xd;
        }
        *(s32*)(p + 0x210) = 0;
        *(s16*)(p + 0x240) = 0;
        *(s32*)(p + 0x1d0) = 5;
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 2;
        cfg = lbl_80529DEC;
        if (*(s32*)(p + 0x1ac) != cfg[0x23d]) {
            *(s32*)(cfg + 0x140) = 0;
            *(s32*)(cfg + 0x144) = 0;
            *(s32*)(cfg + 0x148) = 0;
            *(s32*)(cfg + 0x14c) = 0;
            *(s32*)(cfg + 0x64) = -1;
            fn_80403680(cfg);
        }
        cfg[0x23d] = *(s32*)(p + 0x1ac);
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(p + 0x350) = 2;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        *(s32*)(p + 0x1ac) = *(s32*)(p + 0x1ac) + 1;
        if (*(s32*)(p + 0x1ac) >= 3) {
            *(s32*)(p + 0x1ac) = 0;
        }
        *(s16*)(p + 0x240) = 1;
        *(s32*)(p + 0x1d0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        *(s32*)(p + 0x1ac) = *(s32*)(p + 0x1ac) - 1;
        if (*(s32*)(p + 0x1ac) < 0) {
            *(s32*)(p + 0x1ac) = 2;
        }
        *(s16*)(p + 0x240) = 1;
        *(s32*)(p + 0x1d0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    }
    *(s32*)(p + 0x1d0) = *(s32*)(p + 0x1d0) + 1;
    if (*(s32*)(p + 0x1d0) >= 0x3c) {
        *(s32*)(p + 0x1d0) = 0;
    }
}

extern "C" void fn_80456154(void* p);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* a, s32 b);
extern "C" void* lbl_8053AD30;
struct T803FC304;
typedef void (T803FC304::*PMF803FC304)();
extern PMF803FC304 lbl_804B0D14[];
extern "C" void fn_803FC304(u8* p) {
    s32 i;

    *(s32*)(p + 0x1c0) = 0;
    for (i = 0; i < 4; i++) {
        if (i <= *(s32*)(p + 0x1ac) + 1) {
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
                lbl_8053AAF8[0x82] |= (u8)(1 << (i + 4));
                *(s32*)(p + 0x1c0) += 1;
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
            }
        } else {
            lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
        }
    }
    if (p[0x25e] == 0 || *(s32*)(p + 0x1c4) == 4) {
        if (*(s32*)(p + 0x1c4) != 0xd) {
            (((T803FC304*)p)->*lbl_804B0D14[*(s32*)(p + 0x1c4)])();
        } else {
            (((T803FC304*)p)->*lbl_804B0D14[*(s32*)(p + 0x1c8)])();
        }
        for (i = 0; i < 4; i++, p += 4) {
            fn_80456154(*(void**)(p + 0x78));
        }
    }
}

extern "C" void fn_8013B490(void*);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern void* lbl_8053AB10;
extern const f32 lbl_8054372C;
extern const f32 lbl_8054374C;
extern const f32 lbl_80543750;
struct T803FC46C;
typedef void (T803FC46C::*PMF803FC46C)();
extern PMF803FC46C lbl_804B0E4C[];
extern PMF803FC46C lbl_804B0BDC[];
extern "C" void fn_803FC46C(u8* p) {
    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0x14), lbl_8054372C, lbl_8054372C, ((void**)lbl_8053AB10)[4]);
    if (*(s32*)(p + 0x1c4) != 0xd) {
        (((T803FC46C*)p)->*lbl_804B0E4C[*(s32*)(p + 0x1c4)])();
    } else {
        (((T803FC46C*)p)->*lbl_804B0E4C[*(s32*)(p + 0x1c8)])();
    }
    u8 state = p[0x25e];
    if (state != 0) {
        switch (state) {
        case 1:
            if (p[0x25d] >= 0xf5) {
                p[0x25d] = 0xff;
                p[0x25e] = 2;
                (((T803FC46C*)p)->*lbl_804B0BDC[*(s32*)(p + 0x1cc)])();
            } else {
                p[0x25d] += 10;
            }
            break;
        case 2:
            if (p[0x25d] <= 10) {
                p[0x25d] = 0;
                p[0x25e] = 0;
            } else {
                p[0x25d] -= 10;
            }
            break;
        }
        fn_8013B490(lbl_8053AB10);
        ((void(*)(void*, s32))(*(void***)(*(void**)(p + 0x5c)))[9])(*(void**)(p + 0x5c), p[0x25d]);
        ((void(*)(void*, s32, f32, s32, s32, f32, f32, f32))(*(void***)(*(void**)(p + 0x5c)))[59])(*(void**)(p + 0x5c), 0, lbl_8054372C, 0, 0, lbl_8054372C, lbl_8054374C, lbl_80543750);
    }
}

extern "C" void fn_804310CC(void* a);
extern "C" void fn_803F267C(u8* p);
extern "C" void fn_803FC5E4(u8* p, u8 flag) {
    s32 i;
    void* obj;
    void* sub;

    fn_804310CC(lbl_8053AEC0);
    if (flag) {
        *(s32*)(p + 0x1c4) = 7;
        fn_803F267C(p);
    } else {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0))) {
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(1))) {
                *(s32*)(p + 0x1ac) = 0;
                i = 2;
                do {
                    if (!fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
                        break;
                    }
                    i++;
                    *(s32*)(p + 0x1ac) += 1;
                } while (i < 4);
            }
        }
        *(s32*)(p + 0x1c4) = 0;

        *(f32*)(p + 0x110) = lbl_80543770;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x62620000, 0x506d6261, 0x62623037);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x108), *(f32*)(p + 0x10c) + *(f32*)(p + 0x110));

        *(f32*)(p + 0x114) = lbl_80543768;
        fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x114));

        *(f32*)(p + 0x130) = lbl_80543774;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x00506e6f, 0x70623038);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x118) + *(f32*)(p + 0x130), *(f32*)(p + 0x124));

        *(f32*)(p + 0x134) = lbl_80543774;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x00506e6f, 0x70623132);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x11c) + *(f32*)(p + 0x134), *(f32*)(p + 0x128));

        *(f32*)(p + 0x138) = lbl_80543774;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x00506e6f, 0x70623136);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x120) + *(f32*)(p + 0x138), *(f32*)(p + 0x12c));

        *(f32*)(p + 0x144) = lbl_80543778;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x74610000, 0x004e6461, 0x74613032);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x13c) + *(f32*)(p + 0x144), *(f32*)(p + 0x140));

        *(f32*)(p + 0x158) = lbl_80543778;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x74610000, 0x004e6461, 0x74613035);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x148) + *(f32*)(p + 0x158), *(f32*)(p + 0x14c));

        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x004e0000, 0x004e6461, 0x74613037);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x150) + *(f32*)(p + 0x158), *(f32*)(p + 0x154));

        *(s32*)(p + 0x210) = 0;
        *(s32*)(p + 0x1d0) = 0;
        *(s16*)(p + 0x240) = 0;
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 0;
    }
    *(s32*)(p + 0x350) = 4;
}

extern "C" u8 lbl_804B0F10[];
extern "C" void* fn_803FC904(u8* param_1, s16 param_2) {
    s32 i;
    u8* p;

    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B0F10;
        if (*(void**)(param_1 + 0x8) != 0) {
            void* o = *(void**)(param_1 + 0x8);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0x8) = 0;
        if (*(void**)(param_1 + 0x4) != 0) {
            void* o = *(void**)(param_1 + 0x4);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0x4) = 0;
        if (*(void**)(param_1 + 0xc) != 0) {
            void* o = *(void**)(param_1 + 0xc);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0xc) = 0;
        if (*(void**)(param_1 + 0x10) != 0) {
            void* o = *(void**)(param_1 + 0x10);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0x10) = 0;
        if (*(void**)(param_1 + 0x14) != 0) {
            void* o = *(void**)(param_1 + 0x14);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0x14) = 0;

        p = param_1;
        for (i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x18) != 0) {
                void* o = *(void**)(p + 0x18);
                ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
            }
            *(void**)(p + 0x18) = 0;
            if (*(void**)(p + 0x38) != 0) {
                void* o = *(void**)(p + 0x38);
                ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
            }
            *(void**)(p + 0x38) = 0;
            if (*(void**)(p + 0x28) != 0) {
                void* o = *(void**)(p + 0x28);
                ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
            }
            *(void**)(p + 0x28) = 0;
            if (*(void**)(p + 0x48) != 0) {
                void* o = *(void**)(p + 0x48);
                ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
            }
            *(void**)(p + 0x48) = 0;
        }

        if (*(void**)(param_1 + 0x60) != 0) {
            void* o = *(void**)(param_1 + 0x60);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0x60) = 0;

        p = param_1;
        for (i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x64) != 0) {
                void* o = *(void**)(p + 0x64);
                ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
            }
            *(void**)(p + 0x64) = 0;
        }

        if (*(void**)(param_1 + 0x58) != 0) {
            void* o = *(void**)(param_1 + 0x58);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0x58) = 0;
        if (*(void**)(param_1 + 0x5c) != 0) {
            void* o = *(void**)(param_1 + 0x5c);
            ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
        }
        *(void**)(param_1 + 0x5c) = 0;

        p = param_1;
        for (i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x78) != 0) {
                void* o = *(void**)(p + 0x78);
                ((void (*)(void*, s32))((*(void***)((u8*)o + 8))[12]))(o, 1);
            }
            *(void**)(p + 0x78) = 0;
        }

        if (param_2 > 0) {
            delete param_1;
        }
    }
    return param_1;
}

