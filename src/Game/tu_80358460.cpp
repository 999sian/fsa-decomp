#include "types.h"
#include "JSystem/JGeometry/Vec.h"

struct Actor;


struct Unk8035A1D4;
typedef void (Unk8035A1D4::*Unk8035A1D4Func)();
extern Unk8035A1D4Func lbl_804AD30C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804AD348[];
extern "C" unsigned char sincosTable___5JMath[];
extern "C" const f32 lbl_8054286C;
extern "C" const f32 lbl_8054287C;
extern "C" const f32 lbl_80542880;
extern "C" const f32 lbl_80542884;
extern "C" const f32 lbl_8054288C;
extern "C" u8* lbl_8053AC98;
extern "C" const u16 lbl_80542868[];
struct Vec8035A860 {
    f32 x, y, z;
    Vec8035A860& operator-=(const Vec8035A860& o) {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }
};
extern "C" unsigned char sincosTable___5JMath[];
extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8035AE9C(u8* self, void* obj);
extern "C" void fn_801F317C(u8* self, f32* out);
extern "C" u8 fn_8023AAF8(s32 i, f32* box, s32 room, Vec8035A860* out);
extern "C" Actor* fn_80358460(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AD348;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_801F0D20(u8* self, s32 i);
extern "C" u8 fn_80235448(s32 i);
extern "C" void fn_803597EC(u8* self) {
    s32 i;
    s32 flags = 0;
    s16 ang;
    f32 cs;
    f32 box[4];
    Vec8035A860 v8;
    f32 d;
    f32 py;

    *(f32*)(self + 0x240) = lbl_8054286C;
    *(u8*)(self + 0x24e) = 0;
    if (*(s32*)(self + 0x254) != 0) {
        *(s32*)(self + 0x254) -= 1;
        if (*(s32*)(self + 0x254) == 0) {
            fn_801F0D20(self, 3);
        }
    }
    for (i = 0; i < 4; i++) {
        *(u8*)(self + 0x246 + i) = 0;
        *(u8*)(self + 0x24a + i) = 0;
        if (fn_8023F264(i)) {
            *(u8*)(self + 0x246 + i) = fn_8035AE9C(self, (void*)i);
            if (fn_80235448(i) && *(s8*)(self + 0x246 + i) != 0) {
                *(u8*)(self + 0x24e) |= 1 << i;
                fn_801F317C(self, box);
                ang = *(s16*)(self + 0x230);
                py = *(f32*)(self + 0x10);
                cs = __fabs(((f32*)(sincosTable___5JMath + ((ang >> 5) << 3)))[1]);
                box[1] = (box[1] - py) * cs + py;
                box[3] = (box[3] - py) * cs + py;
                if (fn_8023AAF8(i, box, *(s32*)(self + 0x4), &v8)) {
                    d = py - v8.y;
                    if (*(u8*)(self + 0x24e) != 0 && d == lbl_8054286C) {
                        d = lbl_8054287C;
                        if (*(u8*)(self + 0x24e) == 0 && __fabsf(d) <= lbl_80542880) {
                            *(f32*)(self + 0x240) += lbl_80542884 * lbl_8054286C;
                            *(s8*)(self + 0x24a + i) = d >= lbl_8054286C ? 1 : -1;
                        } else {
                            *(s8*)(self + 0x24a + i) = 0;
                        }
                    } else {
                        *(s8*)(self + 0x24a + i) = 0;
                    }
                }
            }
        }
        flags |= *(u8*)(self + 0x24e);
        flags |= *(s8*)(self + 0x24a + i) << i;
    }
}

extern "C" void fn_8035A1D4(Unk8035A1D4* self) {
    u32 v = *(u32*)((u8*)self + 0x90);
    (self->*lbl_804AD30C[(v >> 7) & 0x1f])();
}

extern "C" void fn_8035A210(u8* self) {
    f32 box[4];
    Vec8035A860 tmp;
    u8* p;
    s32 i;
    s32 r;

    p = self;
    *(f32*)(p + 0x240) = 0.0f;
    for (i = 0; i < 4; i++) {
        p[0x246 + i] = 0;
        p[0x24a + i] = 0;
        if (fn_8023F264(i)) {
            p[0x246 + i] = fn_8035AE9C(p, (void*)i);
            fn_801F317C(p, box);
            s16 rot = *(s16*)(p + 0x230);
            f32 py = *(f32*)(p + 0x10);
            f32 c = *(f32*)(sincosTable___5JMath + ((u16)rot >> 5) * 8 + 4);
            c = fabs(c);
            box[1] = (box[1] - py) * c + py;
            box[3] = (box[3] - py) * c + py;
            r = 0;
            if (fn_8023AAF8(i, box, *(s32*)(p + 4), &tmp)) {
                f32 dy = py - tmp.y;
                if (p[0x24e] != 0 && dy == 0.0f) {
                    r = 1;
                } else {
                    r = -1;
                }
                *(f32*)(p + 0x240) = *(f32*)(p + 0x240) + 1.0f;
            }
            p[0x24a + i] = r;
        } else {
            p[0x24a + i] = 0;
        }
    }
}

extern "C" Vec8035A860* fn_8023E724(void*);
extern "C" void fn_8022BE24(void*, Vec8035A860*);
extern "C" unsigned char sincosTable___5JMath[];
extern "C" void fn_8035A860(u8* self, void* obj, f32 speed) {
    Vec8035A860 pos = *fn_8023E724(obj);
    Vec8035A860 d;
    d.x = pos.x - *(f32*)(self + 0xc);
    d.y = pos.y - *(f32*)(self + 0x10);
    d.z = pos.z - *(f32*)(self + 0x14);
    d.z = 0.0f;
    bool inside = false;
    if (d.x >= *(f32*)(self + 0x60) + 10.0f && d.y >= *(f32*)(self + 0x64)
        && d.x < *(f32*)(self + 0x68) - 10.0f && d.y < *(f32*)(self + 0x6c)) {
        inside = true;
    }
    if (inside) {
        s16 ang = *(s16*)(self + 0x230);
        f32* tbl = (f32*)((char*)sincosTable___5JMath + ((ang >> 5) << 3));
        f32 s = 0.5f * __fabs(tbl[0]) * (__fabs(speed) / (*(f32*)(self + 0x6c) * __fabs(tbl[1])));
        if (s > 0.5f) s = 0.5f;
        f32 r;
        if (*(u8*)(self + 0x244) == 0) {
            if ((f32)*(s16*)(self + 0x230) * speed >= 0.0f) r = 1.0f - s;
            else r = 1.0f + s;
        } else {
            if ((f32)*(s16*)(self + 0x230) * speed >= 0.0f) r = 1.0f + s;
            else r = 1.0f - s;
        }
        Vec8035A860 sc;
        sc.x = r;
        sc.y = 1.0f;
        sc.z = r;
        fn_8022BE24(obj, &sc);
    }
}

extern "C" u8* lbl_8053AAF8;
extern "C" s32 fn_8022CAF8(s32);
extern "C" void fn_8035AA54(u8* self) {
    u8 bVar5 = 0;
    u8 bVar3 = 0;
    u8 bVar2 = 0;
    u8 bVar4;
    if (*(s8*)(self + 0x246) != 0) {
        if (*(s8*)(self + 0x247) != 0) {
            if (*(s8*)(self + 0x248) != 0) {
                if (*(s8*)(self + 0x249) != 0) {
                    bVar2 = 1;
                }
            }
        }
    }
    if (bVar2 && __fabsf(*(f32*)(self + 0x240)) < 33.0f) {
        bVar5 = 1;
    }
    bVar4 = bVar5;
    if (lbl_8053AAF8[0x7e] == 0) {
        bVar4 = bVar5 & (fn_8022CAF8(0) == 1);
    }
    if (*(f32*)(self + 0x240) != 0.0f) {
        if (bVar4 || *(s32*)(self + 0x250) > 0) {
            if (lbl_8053AAF8[0x7e] == 0) {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = -1500.0f;
                } else {
                    *(f32*)(self + 0x240) = 1500.0f;
                }
            } else {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = -10.0f;
                } else {
                    *(f32*)(self + 0x240) = 10.0f;
                }
            }
            bVar3 = 1;
        } else {
            if (lbl_8053AAF8[0x7e] == 0) {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = 1500.0f;
                } else {
                    *(f32*)(self + 0x240) = -1500.0f;
                }
            } else {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = 10.0f;
                } else {
                    *(f32*)(self + 0x240) = -10.0f;
                }
            }
        }
        *(s16*)(self + 0x23a) = (s16)*(f32*)(self + 0x240);
    } else {
        *(s16*)(self + 0x23a) = (s16)(-(0.01f * (f32)*(s16*)(self + 0x230) - -(0.1f * (f32)*(s16*)(self + 0x238))) / 15.0f);
    }
    *(s16*)(self + 0x238) += *(s16*)(self + 0x23a);
    if (bVar3) {
        *(f32*)(self + 0x240) = 0.0f;
    }
}

extern "C" bool fn_8022D75C(void*);
extern "C" bool fn_80230188(void*);
extern "C" s32 fn_8023DE58(void*);
extern "C" void fn_8022DF48(void*);
extern "C" void fn_8022E088(void*, s32, Vec8035A860*);
extern "C" s32 fn_8035AE9C(u8* self, void* obj) {
    Vec8035A860 d;
    Vec8035A860* pos;
    f32 dy;
    u8 flag;
    s32 i;
    if (fn_8022D75C(obj)) return 0;
    if (fn_80230188(obj)) return 0;
    s32 v = *(s32*)(self + 4);
    if (fn_8023DE58(obj) != v) return 0;
    if (fn_8023E724(obj)->z > 0.0f) {
        fn_8022DF48(obj);
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (*(s16*)(self + 0x230) >= 0x3c00 && *(s16*)(self + 0x230) <= 0x4400) return 0;
        if (*(s16*)(self + 0x230) <= -0x3c00 && *(s16*)(self + 0x230) >= -0x4400) return 0;
        fn_8022E088(obj, i, &d);
        d.x -= *(f32*)(self + 0xc);
        d.y -= *(f32*)(self + 0x10);
        d.z = 0.0f;
        f32 c = __fabsf(*(f32*)(sincosTable___5JMath + ((u16)*(s16*)(self + 0x230) >> 5) * 8 + 4));
        f32 f2 = *(f32*)(self + 0x64) * c;
        f32 f3 = *(f32*)(self + 0x6c) * c;
        if (!(d.x >= *(f32*)(self + 0x60)) && !(d.y >= f2) && !(d.x >= *(f32*)(self + 0x68)) && !(d.y >= f3)) {
            fn_8022DF48(obj);
            pos = fn_8023E724(obj);
            flag = *(u8*)(self + 0x24e);
            dy = *(f32*)(self + 0x10) - pos->y;
            if (flag == 0) {
                if (__fabsf(dy) > 8.0f) dy = 0.0f;
            } else if (dy == 0.0f) {
                dy = 0.1f;
            }
            *(f32*)(self + 0x240) += dy;
            fn_8035A860(self, obj, dy);
            if (dy >= 0.0f) return -1;
            return 1;
        }
    }
    return 0;
}

