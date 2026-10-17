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

