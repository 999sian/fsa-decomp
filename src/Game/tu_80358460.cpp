#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

struct Actor;


struct Unk8035A1D4;
typedef void (Unk8035A1D4::*Unk8035A1D4Func)();
extern Unk8035A1D4Func lbl_804AD30C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804AD348[];
struct Vec8035A860 {
    f32 x, y, z;
    Vec8035A860& operator-=(const Vec8035A860& o) {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }
};
extern "C" Actor* fn_80358460(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AD348;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8035A1D4(Unk8035A1D4* self) {
    u32 v = *(u32*)((u8*)self + 0x90);
    (self->*lbl_804AD30C[(v >> 7) & 0x1f])();
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

