#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" char lbl_804A8C80[];
extern "C" void __dt__5ActorFv(void*, int);
void operator delete(void*);
extern "C" f32 lbl_80540C40;
extern "C" f32 lbl_80540C38;
extern "C" f32 lbl_80540C44;
extern "C" char lbl_8046D54C[];
extern "C" u8* lbl_8053AB10;
extern "C" void fn_801F06F0(void* a, const char* name, s32 id, void* rec, s32 p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80158B5C(void*, s32, void*, void*, f32);
extern "C" u8* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(u8* a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_8022461C(s32 a, s32 b);
extern "C" s32 fn_80226850(s32 a, s32 b);
extern "C" u8* fn_802D6A9C(void);

extern "C" f32 lbl_80540C48;
extern "C" f32 lbl_80540C4C;
extern "C" f32 lbl_80540C50;
extern "C" f32 lbl_80540C54;
extern "C" f32 lbl_80540C64;
extern "C" f32 lbl_80540C6C;
extern "C" u8* lbl_8053AAF8;
extern "C" s32 fn_801CD664(s32 a);
extern "C" u8 fn_801F2618(char* a, void* b, s32 c);

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

struct Vec2f {
    f32 x;
    f32 y;
};

struct Rec {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0c;
    u32 w10;
    u32 w14;
    u32 w18;
    u8 b1c;
    u8 b1d;
    u8 b1e;
    u8 b1f;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    u8 b24;
    u8 b25;
    u8 b26;
    u32 w28;
    u8 b2c;
    u8 b2d;
    u8 b2e;
    u32 w30;
    u32 w34;
    u32 w38;
};

struct Col4 {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    Col4() {}
    Col4(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
};
extern "C" void* fn_802BFB7C(void* p, s16 flags) {
    if (p != 0) {
        *(char**)p = lbl_804A8C80;
        __dt__5ActorFv(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" s32 fn_802BFBDC(char* p, s32 a, s32 b) {
    u8* base;
    u8* mgr;
    s32 handle;
    s32 type;
    s32 kind;

    if (*(s32*)(p + 0x258) == 0) {
        handle = *(s32*)(p + 0x198);
        base = fn_8020D58C();
        if (fn_8020D6AC(base + base[1] * 0x784 + 4, a, b, handle, 0)) {
            return 1;
        }
        type = (u16)fn_8022461C(b, a);
        kind = (u16)fn_80226850(b, a);
        if (kind == 0x230 || kind == 0x231) {
            return 0;
        }
        if ((u32)(kind - 0x19e) <= 1 || (u32)(kind - 0x350) <= 1 || (u32)(kind - 0x342) <= 1 || (u32)(kind - 0x345) <= 1 || (u32)(kind - 0x355) <= 1 || (u32)(kind - 0x2ee) <= 1 || (u32)(kind - 0x2fe) <= 1 || (u32)(kind - 0x338) <= 1 || (u32)(kind - 0x32a) <= 1 || (u32)(kind - 0x32d) <= 1 || (u32)(kind - 0x33d) <= 1 || (u32)(kind - 0x2ce) <= 1 || (u32)(kind - 0x2de) <= 1 || (u32)(kind - 0x3b0) <= 1 || (u32)(kind - 0x3a2) <= 1 || (u32)(kind - 0x3a5) <= 1 || kind == 0x3b6 || (u32)(kind - 0x398) <= 1 || (u32)(kind - 0x38a) <= 1 || kind == 0x39d || (u32)(kind - 0x38d) <= 1 || kind == 0x39e) {
            return 1;
        }
        if (type != 0 && type != 4 && type != 5 && type != 6 && type != 7 && type != 2 && type != 3 && type != 0x50 && type != 0xe && type != 0xc && type != 0x2c && type != 0x2d && type != 0x2e && type != 0x2f && type != 0x20 && type != 0xd && type != 0x39 && type != 0x3a && type != 0x3b && type != 0x4c && type != 0x4d && type != 0x4e && type != 0x4f && type != 0x24) {
            if ((u32)(type - 0x10) <= 2 || type == 0x13) {
                *(s32*)(p + 0x258) = 0x78;
                return 0;
            }
            if ((u16)fn_80226850(b, a) == 0x3a || (u16)fn_80226850(b, a) == 0x3d) {
                return 0;
            }
            if (type == 0x25) {
                mgr = fn_802D6A9C();
                return mgr[0x171] == 0;
            }
            if (type == 0x26) {
                mgr = fn_802D6A9C();
                return mgr[0x171] == 1;
            }
            if (type != 0x22 || fn_802D6A9C()[0x170] == 1) {
                return 1;
            }
        }
    } else {
        *(s32*)(p + 0x258) = *(s32*)(p + 0x258) - 1;
    }
    return 0;
}

extern "C" u32 fn_8022F514(s32 a);
extern "C" s32 fn_8022F3DC(s32 a);
extern "C" BOOL fn_802308E0(s32 a);
extern "C" BOOL fn_8023077C(s32 a);
extern "C" void fn_8037AE30(void* a);
extern "C" void* fn_8023E724(s32 a);
extern "C" s32 fn_8023DE58(s32 a);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* a, u32 id, void* rec, void* d, s32 e, s32 f, s32 g);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D6F38(void* a, void* b, void* c, s32 d, s32 e);
extern "C" BOOL fn_802BFF30(u8* this_, s32 room) {
    s32 v26 = room;
    s32 v22 = room;
    s32 v3;
    s32 i;
    u32 base;

    v22 = room;
    if (fn_8022F514(room)) {
        v26 = fn_8022F3DC(room);
    }
    return 1;
}

extern "C" void fn_802C0278(char* p) {
    Rec rec;
    Col4 tmp;
    Col4 col;
    s32 iVar1;
    u8* buf;
    u32 i;

    if (*(s32*)(p + 0x230) == 1) {
        return;
    }
    iVar1 = *(s32*)(p + 4);
    if (iVar1 == 0) {
        buf = (u8*)&rec;
        rec.w10 = -1;
        rec.w14 = -1;
        for (i = 0; (u8)i < 0x10; i += 8) {
            buf[(u8)i] = i;
            buf[(u8)(i + 1)] = i + 1;
            buf[(u8)(i + 2)] = i + 2;
            buf[(u8)(i + 3)] = i + 3;
            buf[(u8)(i + 4)] = i + 4;
            buf[(u8)(i + 5)] = i + 5;
            buf[(u8)(i + 6)] = i + 6;
            buf[(u8)(i + 7)] = i + 7;
        }
        rec.w18 = 0;
        rec.w10 = -1;
        rec.w14 = 0;
        rec.b1c = 0;
        rec.b1d = 0;
        rec.b1e = 0;
        rec.b1f = 1;
        rec.b20 = 1;
        rec.b21 = 0;
        rec.b22 = 0;
        rec.b23 = 0;
        rec.b24 = 0;
        rec.b25 = 0;
        rec.b26 = 1;
        rec.w28 = 3;
        rec.b2c = 1;
        rec.b2d = 0;
        rec.b2e = 0;
        rec.w30 = -1;
        rec.w34 = 0;
        rec.w38 = 2;
        buf[0x13] = (u8)*(s32*)(p + 0x24c);
        if (*(f32*)(p + 0x14) != lbl_80540C40) {
            fn_801F06F0(p, lbl_8046D54C, *(s32*)(p + 0x238) + 0x40, &rec, 0, lbl_80540C38, lbl_80540C38);
        } else if (*(s32*)(p + 0x23c) == 2) {
            fn_801F06F0(p, lbl_8046D54C, *(s32*)(p + 0x238) + 0x20c, &rec, 0, lbl_80540C38, lbl_80540C38);
        } else {
            fn_801F06F0(p, lbl_8046D54C, *(s32*)(p + 0x238) + 0x182, &rec, 0, lbl_80540C38, lbl_80540C38);
        }
    } else if ((*(s32*)(p + 0x248) == 0 || (*(s32*)(p + 0x248) & 3) == 0) &&
               (*(s32*)(p + 0x254) >= 0x78 || (*(s32*)(p + 0x254) != 0 && (*(s32*)(p + 0x254) & 3) == 0))) {
        if (*(f32*)(p + 0x14) != lbl_80540C40) {
            fn_803075AC(*(void**)(p + 0x198), iVar1, p + 0xc, *(s32*)(p + 0x238) + 0x40, 0, 2, -1, 0, 0, 0);
        } else if (*(s32*)(p + 0x23c) == 2) {
            fn_803075AC(*(void**)(p + 0x198), iVar1, p + 0xc, *(s32*)(p + 0x238) + 0x20c, 0, 2, -1, 0, 0, 0);
        } else {
            fn_803075AC(*(void**)(p + 0x198), iVar1, p + 0xc, *(s32*)(p + 0x238) + 0x182, 0, 2, -1, 0, 0, 0);
        }
    }
    tmp = Col4(0, 0, 0, 0x80);
    col = tmp;
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), *(s32*)(p + 4), p + 0xc, &col, lbl_80540C44);
}

extern "C" u8 fn_801F2740(void* a, s32 b);
extern "C" s32 fn_80230CFC(s32 a);
extern "C" void fn_802C0570(char* p) {
    Vec2f xy;
    f32 z;
    s32 mode;
    s32 ix;
    s32 iy;
    u8 flag;
    u8 bit;
    s32 i;

    *(f32*)(p + 0x60) = lbl_80540C48;
    *(f32*)(p + 0x64) = lbl_80540C48;
    *(f32*)(p + 0x68) = lbl_80540C4C;
    *(f32*)(p + 0x6c) = lbl_80540C4C;
    xy = *(Vec2f*)(p + 0xc);
    z = *(f32*)(p + 0x14);
    flag = fn_801F2740(p, -1);
    if (flag) {
        bit = 1;
        for (i = 0; i < 4; i++, bit <<= 1) {
            if (flag & bit) {
                Vec3f vec = *(Vec3f*)fn_8023E724(i);
                ix = (s32)__fabsf(((Vec3f*)(p + 0xc))->x - vec.x);
                iy = (s32)__fabsf(((Vec3f*)(p + 0xc))->y - vec.y);
                mode = fn_80230CFC(i);
                if (ix >= 0 && ix <= 15) {
                    if (mode == 1) {
                        if (((Vec3f*)(p + 0xc))->x > vec.x) {
                            ((Vec3f*)(p + 0xc))->x = ((Vec3f*)(p + 0xc))->x + (f32)((15 - ix) >> 1);
                        } else {
                            ((Vec3f*)(p + 0xc))->x = ((Vec3f*)(p + 0xc))->x - (f32)((15 - ix) >> 1);
                        }
                    }
                }
                if (iy >= 0 && iy <= 15) {
                    if (mode == 2) {
                        if (((Vec3f*)(p + 0xc))->y > vec.y) {
                            ((Vec3f*)(p + 0xc))->y = ((Vec3f*)(p + 0xc))->y + (f32)((15 - iy) >> 1);
                        } else {
                            ((Vec3f*)(p + 0xc))->y = ((Vec3f*)(p + 0xc))->y - (f32)((15 - iy) >> 1);
                        }
                    }
                }
            }
        }
    }
    if (flag) {
        if (fn_801F2618(p, 0, 0) == 1) {
            *(Vec2f*)(p + 0xc) = xy;
            *(f32*)(p + 0x14) = z;
            *(f32*)(p + 0x60) = lbl_80540C50;
            *(f32*)(p + 0x64) = lbl_80540C50;
            *(f32*)(p + 0x68) = lbl_80540C54;
            *(f32*)(p + 0x6c) = lbl_80540C54;
        }
    }
}

extern "C" void fn_802C0EE0(char* p) {
    f32 z = lbl_80540C40;
    *(f32*)(p + 0x44) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x3c) = z;
    *(s32*)(p + 0x248) = 0;
    if (*(s32*)(p + 0x254) < 0xb4) {
        *(s32*)(p + 0x254) = 0xb4;
    }
    *(s32*)(p + 0x24c) = 0xff;
    *(s32*)(p + 0x250) = 1;
}

extern "C" void fn_802C0F20(char* p) {
    s32 t;
    s32 room;
    s32 n;
    s32 a;
    s32 b;
    u8* mgr;
    u32 a18;
    u32 packed;
    f32 c50;
    f32 c54;
    f32 c48;
    f32 c4c;
    Vec3f v;
    Vec3f d;
    Vec2f pos;

    *(s32*)(p + 0x238) = *(s32*)(p + 0x90) & 0x7f;
    t = *(s32*)(p + 0x238);
    if (t == 0xb || t == 0x16) {
        *(s32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
        *(s32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 7) & 0x1f;
        *(s32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
        *(s32*)(p + 0x244) = (*(u32*)(p + 0x90) >> 17) & 0x1f;
    } else {
        *(s32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
        *(s32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 7) & 0x1f;
        *(s32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
        *(s32*)(p + 0x244) = (*(u32*)(p + 0x90) >> 17) & 0x1f;
        if (*(s32*)(p + 0x244) >= 4) {
            *(s32*)(p + 0x244) = -1;
        }
    }
    *(s32*)(p + 0xb0) = 0x20000;
    *(u32*)(p + 0x264) = *(u32*)(p + 0x90);
    *(f32*)(p + 0x268) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x26c) = *(f32*)(p + 0x10);
    mgr = fn_802D6A9C();
    a18 = *(u32*)(mgr + 0x18);
    mgr = fn_802D6A9C();
    *(u32*)(p + 0x270) = (*(u32*)(p + 4) & 0xff) | ((a18 & 0xff) << 8) | ((*(u32*)(mgr + 0x14) & 0xff) << 16) | (*(u32*)(p + 0x244) << 24);
    c50 = lbl_80540C50;
    c54 = lbl_80540C54;
    c48 = lbl_80540C48;
    c4c = lbl_80540C4C;
    *(f32*)(p + 0x60) = c50;
    *(f32*)(p + 0x64) = c50;
    *(f32*)(p + 0x68) = c54;
    *(f32*)(p + 0x6c) = c54;
    *(f32*)(p + 0x80) = c48;
    *(f32*)(p + 0x84) = c48;
    *(f32*)(p + 0x88) = c4c;
    *(f32*)(p + 0x8c) = c4c;
    t = *(s32*)(p + 0x234);
    if (t == 0 || t == 2 || t == 3) {
        *(s32*)(p + 0x230) = 0;
        if (*(s32*)(p + 0x234) == 2) {
            *(s32*)(p + 0x234) = 0;
        }
        if (*(s32*)(p + 0x234) == 3) {
            room = *(s32*)(p + 4);
            if (fn_802D6A9C()[room + 0x131df] != 0) {
                n = fn_801CD664(2) + 1;
                v.x = lbl_80540C40;
                v.y = -(f32)n;
                v.z = lbl_80540C40;
            } else {
                n = fn_801CD664(3) + 1;
                v.x = lbl_80540C40;
                v.y = lbl_80540C40;
                v.z = (f32)n;
            }
        } else {
            room = *(s32*)(p + 4);
            if (fn_802D6A9C()[room + 0x131df] != 0) {
                n = fn_801CD664(3) + 1;
                a = fn_801CD664(5) - 2;
                v.x = lbl_80540C6C * (f32)a;
                v.y = lbl_80540C40;
                v.z = (f32)n;
            } else {
                n = fn_801CD664(3) + 2;
                a = fn_801CD664(5) - 2;
                b = fn_801CD664(5) - 2;
                v.x = lbl_80540C6C * (f32)b;
                v.y = lbl_80540C6C * (f32)a;
                v.z = (f32)n;
            }
        }
        *(Vec3f*)(p + 0x3c) = v;
        if (fn_801F2618(p, &d, 0)) {
            if (d.x != lbl_80540C40) {
                *(f32*)(p + 0x3c) = *(f32*)(p + 0x3c) * lbl_80540C64;
            }
            if (d.y != lbl_80540C40) {
                *(f32*)(p + 0x40) = *(f32*)(p + 0x40) * lbl_80540C64;
            }
        }
        if (*(s32*)(p + 0x234) == 0) {
            mgr = fn_802D6A9C();
            a18 = *(u32*)(mgr + 0x18);
            mgr = fn_802D6A9C();
            pos.x = *(f32*)(p + 0xc);
            pos.y = *(f32*)(p + 0x10);
            packed = (*(u32*)(p + 4) & 0xff) | ((a18 & 0xff) << 8) | ((*(u32*)(mgr + 0x14) & 0xff) << 16) | (*(u32*)(p + 0x244) << 24);
            fn_802D6F38(fn_802D6A9C(), (void*)*(u32*)(p + 0x90), &pos, packed, 1);
            *(s32*)(p + 0x248) = 0x96;
            return;
        }
        *(s32*)(p + 0x230) = 0;
        *(s32*)(p + 0x248) = 0;
    }
    *(s32*)(p + 0x24c) = 0xff;
    *(s32*)(p + 0x250) = 1;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x254) = 0xb4;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) == 0) {
        if (*(s32*)(p + 0x234) == 0) {
            *(s32*)(p + 0x254) = 0xb4;
        } else {
            *(s32*)(p + 0x254) = 0x258;
        }
    }
    room = *(s32*)(p + 4);
    if (fn_802D6A9C()[room + 0x131df] == 1) {
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
        *(f32*)(p + 0x14) = lbl_80540C40;
        *(f32*)(p + 0x40) = *(f32*)(p + 0x40) - *(f32*)(p + 0x44);
        *(f32*)(p + 0x44) = lbl_80540C40;
    }
}

