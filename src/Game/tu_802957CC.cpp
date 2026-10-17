#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" char __vt__4HOUS[];
extern "C" void fn_801EE434(s32);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_8022F514(s32 a);
extern "C" s32 fn_8023DE58(s32 x);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_802317F0(s32 i, s32 a, void* b, void* c, s32 d);
extern "C" void* fn_802D6A9C();
extern "C" void* fn_802D9C4C();
extern "C" void fn_802D79E8(void* mgr, s32 mode, f32 a, f32 b, s32 c);
extern "C" void fn_802A20F0(void* mgr, void* v, s32 a, s32 room, s32 c, s32 d);
extern "C" void fn_802A1050(void* mgr, void* v);
extern "C" void fn_8030C210(void* obj, void* v);
extern "C" void fn_802C59B0(void* obj);
extern "C" void fn_802D8050(void* mgr, s32 kind, s32 a, s32 b);
extern "C" void* lbl_8053AC98;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_8046C238[];
extern "C" s32 fn_8013CC50(s32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_801F0E34(void* a, s32 code, s32 z);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_80295C40(void* p) {
    s32 i;
    s32 n;
    char* pc;
    char* q;
    void* obj;
    s32 k;

    for (i = 0; i < 4; i++) {
        if (fn_8023F264(i) != 0 && fn_8022F514(i) == 0) {
            n = (*(u32*)((char*)p + 0x90) >> 7) & 0x1f;
            n = (n + 7) & ~-(n == 0);
            if (n == fn_8023DE58(i)) {
                n = *(s32*)((char*)p + 4);
                if (fn_802317F0(i, n, fn_8023E724(i), (char*)p + 0xc, 0x1f) != 0) {
                    *((char*)p + (i + 0x2bc)) = 1;
                } else {
                    *((char*)p + (i + 0x2bc)) = fn_802317F0(i, n, fn_8023E724(i), (char*)p + 0xc, 0x21);
                }
            }
        }
    }

    fn_802D6A9C();
    pc = (char*)fn_802D9C4C();
    fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x82, 1, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x83, 1, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x84, 1, 0, 0, 0, 1);
    if (*pc == 'r' || *pc == 's') {
        fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x80, 1, 0, 0, 0, 1);
    } else {
        fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x81, 1, 0, 0, 0, 1);
    }
    fn_801F0E34(p, 0x30092, 0);

    q = (char*)p;
    for (k = 0; k < 2; k++) {
        obj = *(void**)(q + 0x2fc);
        if (obj != 0) {
            *(u32*)((char*)obj + 0xf4) |= 1;
            *(s32*)((char*)obj + 0x24) = 1;
            *(void**)(q + 0x2fc) = 0;
        }
        obj = *(void**)(q + 0x300);
        if (obj != 0) {
            *(u32*)((char*)obj + 0xf4) |= 1;
            *(s32*)((char*)obj + 0x24) = 1;
            *(void**)(q + 0x300) = 0;
        }
        q += 8;
    }

    q = (char*)p;
    for (i = 0; i < *(s32*)((char*)p + 0x2a4); i++) {
        obj = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x27c));
        if (obj != 0) {
            *(u8*)((char*)obj + 0x11c) = 0;
        }
        q += 4;
    }

    *(u8*)((char*)p + 0x2bb) = 1;
}

extern "C" void fn_80295EE8(void* this_) {
    extern void fn_8013CB44(void* a, s32 b, s32 c, s32 d, f32 e, f32 f, f32 g);
    extern void fn_8023DE58(s32 a);
    extern s32 fn_80235274(s32 a);
    extern void fn_8023E724(s32 a);
    extern void fn_80238548(s32 a, s32 b, s32 c, s32 d);

    char* self = (char*)this_;
    s32 i;
    s32 j;
    s32 n;

    if (*(s32*)(self + 0x2c4) > 0) {
        if (*(s32*)(self + 0x2c8) - *(s32*)(self + 0x2c4) < 0x3c) {
        }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_80298978(void* p) {
    s32 i;
    s32 j;
    s32 flag;
    s32 mode;
    u32 key;
    u8 ret;
    void* obj;
    JGeometry::TVec3f pos;
    JGeometry::TVec2f* center;
    JGeometry::TBox2f box;
    JGeometry::TVec3f* v;
    f32 lenSq;

    for (i = 0; i < *(s32*)((char*)p + 0x29c); i++) {
        obj = fn_801F666C(fn_801F856C(), *(s32*)((char*)p + 0x25c + i * 4));
        flag = 0;
        if (obj != 0) {
            v = (JGeometry::TVec3f*)((char*)p + 0x250);
            lenSq = v->z * v->z + v->x * v->x + v->y * v->y;
            if (lenSq > 32.0f * FLT_EPSILON) {
                flag = 1;
            } else {
                for (j = 0; j < 4; j++) {
                    pos = *(JGeometry::TVec3f*)((char*)obj + 0x238);
                    pos.x = pos.x + (8.0f * (f32)((j & 1) != 0) - 4.0f);
                    pos.y = pos.y + (8.0f * (f32)((j & 2) != 0) - 4.0f);
                    key = *(u32*)((char*)obj + 0x90) & 0x7f;
                    switch (key) {
                    case 3:
                        pos.y = pos.y - 16.0f;
                        break;
                    case 1:
                    case 2:
                        pos.y = pos.y + 16.0f;
                        break;
                    case 0x17:
                        pos.x = pos.x + 16.0f;
                        break;
                    case 0x18:
                        pos.x = pos.x - 16.0f;
                        break;
                    }
                    mode = (*(u32*)((char*)obj + 0x90) >> 5) & 7;
                    mode = mode ? mode + 7 : 0;
                    ret = (*(u8 (**)(void*, s32, void*))(*(char**)p + 0x4c))(p, mode, &pos);
                    if ((ret & 0xff) == 1) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1) {
                center = (JGeometry::TVec2f*)((char*)p + 0x2dc) + i;
                box.set(-10.0f, -10.0f, 10.0f, 10.0f);
                box.addPos(*center);
                mode = (*(u32*)((char*)p + 0x90) >> 7) & 0x1f;
                mode = mode ? mode + 7 : 0;
                fn_80239914(&box, mode, *(void**)((char*)p + 0x198));
            }
        }
    }
}

extern "C" void fn_802D79E8(void* mgr, s32 mode, f32 a, f32 b, s32 c);
extern "C" void fn_802A20F0(void* mgr, void* v, s32 a, s32 room, s32 c, s32 d);
extern "C" void fn_802A1050(void* mgr, void* v);
extern "C" void fn_8030C210(void* obj, void* v);
extern "C" void fn_802C59B0(void* obj);
extern "C" void fn_802D8050(void* mgr, s32 kind, s32 a, s32 b);
extern "C" void* lbl_8053AC98;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_8046C238[];
extern "C" void fn_80298FC4(void* p) {
    char* self = (char*)p;
    char* q;
    char* obj;
    s32 mode;
    s32 bits;
    s32 idx;
    s32 k;
    f32 lenSq;
    JGeometry::TVec3f tmp;
    JGeometry::TVec3f v;
    JGeometry::TVec3f d;
    JGeometry::TVec3f sum;
    JGeometry::TVec3f cur;

    if (*(f32*)(self + 0x250) < 0.0f) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, 1.0f, 0.0f, 1);

        if (*(f32*)(self + 0x250) < -0.32f) {
            *(f32*)(self + 0xc) -= 0.32f;
            *(f32*)(self + 0x250) += 0.32f;
        } else {
            *(f32*)(self + 0xc) += *(f32*)(self + 0x250);
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += 2.0f;
        tmp.y += *(f32*)(self + 0x64);
        tmp.y += 8.0f;
        tmp.z = 0.0f;
        for (k = 0; k < 6; k++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.y += 16.0f;
        }

        idx = 1;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx = 0;
        }
        sum = *(JGeometry::TVec3f*)(self + 0xc);
        d = ((JGeometry::TVec3f*)lbl_8046C238)[idx];
        sum += d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = *(f32*)(self + 0x250) * *(f32*)(self + 0x250)
              + *(f32*)(self + 0x254) * *(f32*)(self + 0x254)
              + *(f32*)(self + 0x258) * *(f32*)(self + 0x258);
        if (lenSq > 32.0f * FLT_EPSILON) {
            v.x = -16.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            q = self;
            for (k = 0; k < *(s32*)(self + 0x2a8); k++) {
                obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    cur = *(JGeometry::TVec3f*)(obj + 0xc);
                    *(JGeometry::TVec3f*)(obj + 0xc) = cur + v;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            }
        }
    }
}

extern "C" void fn_80299374(void* p) {
    char* self = (char*)p;
    char* q;
    char* obj;
    s32 mode;
    s32 bits;
    s32 idx;
    s32 k;
    f32 lenSq;
    JGeometry::TVec3f tmp;
    JGeometry::TVec3f v;
    JGeometry::TVec3f d;
    JGeometry::TVec3f sum;

    if (*(f32*)(self + 0x254) > 0.0f) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, 1.0f, 0.0f, 1);

        if (*(f32*)(self + 0x254) > 0.32f) {
            *(f32*)(self + 0x10) += 0.32f;
            *(f32*)(self + 0x254) -= 0.32f;
        } else {
            *(f32*)(self + 0x10) += *(f32*)(self + 0x254);
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += 8.0f;
        tmp.y += *(f32*)(self + 0x6c);
        tmp.y -= 2.0f;
        tmp.z = 0.0f;
        for (k = 0; k < 6; k++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.x += 16.0f;
        }

        sum = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 2;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx ^= 1;
        }
        d.x = lbl_8046C238[idx * 3];
        d.y = lbl_8046C238[idx * 3 + 1];
        d.z = lbl_8046C238[idx * 3 + 2];
        sum = sum + d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = *(f32*)(self + 0x250) * *(f32*)(self + 0x250)
              + *(f32*)(self + 0x254) * *(f32*)(self + 0x254)
              + *(f32*)(self + 0x258) * *(f32*)(self + 0x258);
        if (lenSq <= 32.0f * FLT_EPSILON) {
            v.x = 0.0f;
            v.y = 16.0f;
            v.z = 0.0f;
            q = self;
            for (k = 0; k < *(s32*)(self + 0x2a8); k++) {
                obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    *(JGeometry::TVec3f*)(obj + 0xc) = *(JGeometry::TVec3f*)(obj + 0xc) + v;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            } else {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            } else {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            }
        }
    }
}

extern "C" void fn_80299720(void* p) {
    char* self = (char*)p;
    char* q;
    char* obj;
    s32 mode;
    s32 bits;
    s32 idx;
    s32 k;
    f32 lenSq;
    JGeometry::TVec3f tmp;
    JGeometry::TVec3f v;
    JGeometry::TVec3f d;
    JGeometry::TVec3f sum;

    if (*(f32*)(self + 0x254) < 0.0f) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, 1.0f, 0.0f, 1);

        if (*(f32*)(self + 0x254) < -0.32f) {
            *(f32*)(self + 0x10) -= 0.32f;
            *(f32*)(self + 0x254) += 0.32f;
        } else {
            *(f32*)(self + 0x10) += *(f32*)(self + 0x254);
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += 8.0f;
        tmp.y += *(f32*)(self + 0x64);
        tmp.y += 2.0f;
        tmp.z = 0.0f;
        for (k = 0; k < 6; k++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.x += 16.0f;
        }

        sum = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 3;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx = 2;
        }
        d = ((JGeometry::TVec3f*)lbl_8046C238)[idx];
        sum += d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = *(f32*)(self + 0x250) * *(f32*)(self + 0x250)
              + *(f32*)(self + 0x254) * *(f32*)(self + 0x254)
              + *(f32*)(self + 0x258) * *(f32*)(self + 0x258);
        if (lenSq > 32.0f * FLT_EPSILON) {
            v.x = 0.0f;
            v.y = -16.0f;
            v.z = 0.0f;
            q = self;
            for (k = 0; k < *(s32*)(self + 0x2a8); k++) {
                obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    *(JGeometry::TVec3f*)(obj + 0xc) += v;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            }
        }
    }
}

extern "C" void fn_8029B2EC(void* p) {
    *(f32*)((char*)p + 0x60) = -48.0f;
    *(f32*)((char*)p + 0x64) = -48.0f;
    *(f32*)((char*)p + 0x68) = 48.0f;
    *(f32*)((char*)p + 0x6c) = 48.0f;
    *(f32*)((char*)p + 0x80) = -48.0f;
    *(f32*)((char*)p + 0x84) = -48.0f;
    *(f32*)((char*)p + 0x88) = 48.0f;
    *(f32*)((char*)p + 0x8c) = 48.0f;
    *(s32*)((char*)p + 0xb8) = 1;
    *(s32*)((char*)p + 0xbc) = 3;
    *(s32*)((char*)p + 0x1a4) = 4;
    *(s32*)((char*)p + 0x108) = 10000;
    *(f32*)((char*)p + 0x250) = 0.0f;
    *(f32*)((char*)p + 0x254) = 0.0f;
    *(f32*)((char*)p + 0x258) = 0.0f;
    *(s32*)((char*)p + 0x2ac) = 0;
    *(u8*)((char*)p + 0x24c) = 0;
    *(s32*)((char*)p + 0x248) = 0;
    *(f32*)((char*)p + 0x54) = 1.0f;
    *(f32*)((char*)p + 0x58) = 1.0f;
    *(f32*)((char*)p + 0x5c) = 1.0f;
    *(s32*)((char*)p + 0x230) = 0;
    *(s32*)((char*)p + 0x244) = *(u32*)((char*)p + 0x90) & 3;
    *(u8*)((char*)p + 0x2b9) = (*(u32*)((char*)p + 0x90) >> 2) & 1;
    *(u8*)((char*)p + 0x2b5) = 0;
    *(u8*)((char*)p + 0x2b8) = 0;
    *(s32*)((char*)p + 0x2b0) = (*(u32*)((char*)p + 0x90) >> 3) & 3;
    *(u8*)((char*)p + 0x2b4) = 1;
    *(u8*)((char*)p + 0x2b6) = 1;
    *(u8*)((char*)p + 0x2b7) = 1;
    if (*(s32*)((char*)p + 0x244) == 0) {
        *(u8*)((char*)p + 0x2b6) = 0;
    } else if (*(s32*)((char*)p + 0x244) == 1) {
        *(u8*)((char*)p + 0x2b6) = 0;
        *(u8*)((char*)p + 0x2b7) = 0;
    }
    *(s32*)((char*)p + 0x25c) = -1;
    *(s32*)((char*)p + 0x26c) = -1;
    *(s32*)((char*)p + 0x260) = -1;
    *(s32*)((char*)p + 0x270) = -1;
    *(s32*)((char*)p + 0x264) = -1;
    *(s32*)((char*)p + 0x274) = -1;
    *(s32*)((char*)p + 0x268) = -1;
    *(s32*)((char*)p + 0x278) = -1;
    *(s32*)((char*)p + 0x27c) = -1;
    *(s32*)((char*)p + 0x280) = -1;
    *(s32*)((char*)p + 0x284) = -1;
    *(s32*)((char*)p + 0x288) = -1;
    *(s32*)((char*)p + 0x28c) = -1;
    *(s32*)((char*)p + 0x290) = -1;
    *(s32*)((char*)p + 0x294) = -1;
    *(s32*)((char*)p + 0x298) = -1;
    *(s32*)((char*)p + 0x29c) = 0;
    *(s32*)((char*)p + 0x2a0) = 0;
    *(s32*)((char*)p + 0x2a4) = 0;
    *(s32*)((char*)p + 0x2a8) = 0;
    *(s32*)((char*)p + 0x2cc) = 0;
    *(u8*)((char*)p + 0x2c0) = 0;
    *(u8*)((char*)p + 0x2ba) = 0;
    *(u8*)((char*)p + 0x2bb) = 0;
    *(u8*)((char*)p + 0x2bc) = 0;
    *(u8*)((char*)p + 0x2bd) = 0;
    *(u8*)((char*)p + 0x2be) = 0;
    *(u8*)((char*)p + 0x2bf) = 0;
    *(s32*)((char*)p + 0x2c4) = 0;
    *(s32*)((char*)p + 0x234) = 0;
    *(s32*)((char*)p + 0x2fc) = 0;
    *(s32*)((char*)p + 0x300) = 0;
    *(s32*)((char*)p + 0x304) = 0;
    *(s32*)((char*)p + 0x308) = 0;
    *(s32*)((char*)p + 0x310) = 0;
    *(s32*)((char*)p + 0x314) = 0;
    *(s32*)((char*)p + 0x318) = 0;
    *(s32*)((char*)p + 0x31c) = 0;
    *(s32*)((char*)p + 0x30c) = 0;
    *(f32*)((char*)p + 0x238) = *(f32*)((char*)p + 0xc);
    *(f32*)((char*)p + 0x23c) = *(f32*)((char*)p + 0x10);
    *(f32*)((char*)p + 0x240) = *(f32*)((char*)p + 0x14);
}

extern "C" void* fn_8029B484(void* p, s16 flag) {
    char* row;
    char* col;
    s32 i;
    s32 j;

    if (p != 0) {
        row = (char*)p;
        *(char**)p = __vt__4HOUS;
        for (i = 0; i < 2; i++) {
            for (j = 0, col = row; j < 2; j++) {
                fn_801EE434(*(s32*)(col + 0x2fc));
                col += 4;
            }
            row += 8;
        }
        for (j = 0, col = (char*)p; j < 4; j++, col += 4) {
            fn_801EE434(*(s32*)(col + 0x310));
        }
        __dt__5ActorFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
