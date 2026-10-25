#include "types.h"
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];
    YasiDrawKey key;
    s32 c;
    u8 palette;
    u8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
struct Rgba802D {
    Rgba802D() {}
    Rgba802D(Rgba802D* p) { *this = *p; }
    Rgba802D(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};
struct YasiMgr {
    u8 flag(u32 i) { return mFlags[i]; }
    u8 pad[0x131df];
    u8 mFlags[1];
};
extern const char lbl_8046E100[];
extern "C" const f32 lbl_80540ECC;
extern "C" const f32 lbl_80540EE0;
extern "C" u32 lbl_8053AB10;
extern "C" int fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_8013CB44(s32, void*, s32, s32, s32);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" f32* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_8023BCD4(s32);
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" s32 fn_8023CA88(s32 holder);
extern "C" s32 fn_801F02BC(void* p, const char* name, s32 id, void* param, s32 a, s32 b, s32 c, f32 f1, f32 f2);
extern "C" s32 fn_802D6A9C(void);
extern "C" void fn_80158B5C(void* a, u32 b, void* c, Rgba802D d, f32 f);
struct Vec3f_802D { float x, y, z; };
struct VObj_802D {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
};

extern "C" void fn_802D14DC(VObj_802D* p) {
    p->m7();
}

extern "C" void fn_801F132C(void*, int, int, void*);
extern "C" void fn_802D1508(char* this_, int a, int b) {
    fn_801F132C(this_, a, b, this_ + 0x248);
}

extern "C" void fn_802D1DB4(char* p) {
    s32 flag = 7;
    YasiDrawParam param;
    ((u8*)&param.key.a)[3] = *(u8*)(p + 0x254);
    if (*(u8*)(p + 0xc4) != 0) {
        param.f20 = 0;
        flag = -1;
        param.color = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
        param.palette = fn_8023CA88(*(s32*)(p + 0xc8));
    }
    u32 n = *(u32*)(p + 4);
    if (((YasiMgr*)fn_802D6A9C())->flag(n) != 0) {
        fn_801F02BC(p, lbl_8046E100, 0x1bb + *(s32*)(p + 0x234) + *(s32*)(p + 0x238), &param, flag, 0, 1, lbl_80540ECC, lbl_80540ECC);
    } else {
        fn_801F02BC(p, lbl_8046E100, 0x21 + *(s32*)(p + 0x234) + *(s32*)(p + 0x238), &param, flag, 0, 1, lbl_80540ECC, lbl_80540ECC);
    }
    if (*(s32*)(p + 0x234) == 1) {
        u32 id = *(u32*)(p + 4);
        Rgba802D c(0, 0, 0, 0x80);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, p + 0xc, c, lbl_80540EE0);
    }
}

extern "C" f32* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_8023BCD4(s32);
extern "C" u8 fn_801F2618(void*, s32, s32);
extern "C" u8 fn_801F2B7C(void*, s32, s32, s32);
extern "C" u8 fn_801F2B20(void*, s32);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void fn_8013CB44(s32, void*, s32, s32, s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7818(void*, u32, s32, void*, s32);
extern "C" u32 fn_80226850(void*, s32);
extern "C" void fn_802A381C(void*, void*, s32, s32);
extern "C" void fn_8030C210(void*, void*);
extern "C" u8* lbl_8053AAF8;
extern "C" u32 lbl_8053AC98;
extern "C" const f32 lbl_80540F00;
extern "C" s32 fn_801F7818(void*, u32, s32, void*, s32);
extern "C" void* fn_801F856C(void);
extern "C" u32 lbl_8053ADF8;
extern "C" void fn_802D1FEC(void* this_) {
    char* p = (char*)this_;
    u8 buf[0x400 * 4];

    *(u8*)(p + 0x254) = 0xff;
    if (*(u8*)(p + 0xc4) != 0) {
        f32* v = fn_8023E7B0(*(s32*)(p + 0xc8));
        *(f32*)(p + 0xc) = v[0];
        *(f32*)(p + 0x10) = v[1];
        *(f32*)(p + 0x14) = v[2];
        *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0xc8));
        *(u8*)(p + 0x254) = fn_8023BCD4(*(s32*)(p + 0xc8));
        if (*(s32*)(p + 0x234) == 1) {
            *(s32*)(p + 0x250) -= 1;
            if (*(s32*)(p + 0x250) == 0) {
                *(s32*)(p + 0x250) = 4;
                *(s32*)(p + 0x23c) += 1;
                if (*(s32*)(p + 0x23c) >= 3) {
                    *(s32*)(p + 0x23c) = 0;
                }
            }
            if (*(s32*)(p + 4) >= 8) {
                *(s32*)(p + 0x238) = *(s32*)(p + 0x23c) + 2;
            } else {
                *(s32*)(p + 0x238) = 2;
            }
        }
    } else {
        s32 mode = *(s32*)(p + 0x114);
        if (lbl_8053AAF8[0x7f] != 0) {
            mode = 0;
        }
        s32 id = *(s32*)(p + 4);
        if (*(u8*)((char*)fn_802D6A9C() + 0x10000 + id + 0x31df) == 0) {
            *(f32*)(p + 0x44) += 1.0f;
            *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
            *(f32*)(p + 0x14) += *(f32*)(p + 0x44);
            if (fn_801F2618(p, 0, 0)) {
                if (*(f32*)(p + 0x14) < 0.0f) {
                    if ((u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) == 0x90) {
                        fn_802A381C((void*)lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x91);
                    } else if ((u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) == 0x91 ||
                               (u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) == 0x22e) {
                        fn_802A381C((void*)lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x92);
                    }
                }
                if (*(s32*)(p + 0x234) == 2) {
                    void* mgr = fn_801F856C();
                    s32 n = fn_801F7818(mgr, 0x424c5a32, *(s32*)(p + 4), buf, -1);
                    void** e = (void**)buf;
                    for (s32 i = 0; i < n; i++, e++) {
                        char* r5 = (char*)*e;
                        if (r5 == 0) continue;
                        f32 dy = *(f32*)(r5 + 0x10) - *(f32*)(p + 0x10);
                        f32 dx = *(f32*)(r5 + 0xc) - *(f32*)(p + 0xc);
                        f32 d = std::sqrtf(dx * dx + dy * dy);
                        if (d < lbl_80540F00) {
                            *(s16*)(r5 + 0x94) = 2;
                        }
                    }
                }
                ((VObj_802D*)p)->m9();
                return;
            }
            if (!fn_801F2B7C(p, mode, *(s32*)(p + 0xc8), 1)) {
                if (fn_801F2B20(p, 0)) {
                    ((VObj_802D*)p)->m9();
                }
                return;
            }
        }
        if (*(s32*)(p + 0x24c) == 0) {
            *(f32*)(p + 0x10) -= *(f32*)(p + 0x14);
            *(f32*)(p + 0x14) = 0.0f;
            *(f32*)(p + 0x44) = 0.0f;
            *(s32*)(p + 0x24c) = 1;
        }
        *(f32*)(p + 0x40) += 1.0f;
        *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
        if (!fn_801F2B7C(p, mode, *(s32*)(p + 0xc8), 1)) {
            if (!fn_801F2B20(p, 0)) {
                return;
            }
        }
        ((VObj_802D*)p)->m9();
        return;
    }
    if (*(s32*)(p + 0x234) == 1) {
        f32 x = *(f32*)(p + 0xc);
        f32 y = *(f32*)(p + 0x18);
        if (x == y && *(f32*)(p + 0x10) == *(f32*)(p + 0x1c)) {
            if (*(s32*)(p + 0x244) != 0) {
                if (*(s32*)(p + 0x230) != 0) {
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(
                        *(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x230));
                    *(s32*)(p + 0x230) = 0;
                }
                *(s32*)(p + 0x230) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x1a8, 0, 0, 0, 0, 1);
                *(s32*)(p + 0x244) = 0;
            }
        }
    }
    if (*(s32*)(p + 0x230) != 0) {
        fn_8013CB44(*(s32*)(p + 0x230), p + 0xc, 0, 1, 1);
        *(u8*)(*(s32*)(p + 0x230) + 0xbb) = *(u8*)(p + 0x254);
    }
    lbl_8053ADF8 = 0;
}

extern "C" char lbl_804A9428[];
extern "C" Vec3f_802D lbl_804C0EA0;
extern "C" unsigned int lbl_8053AB68;
extern "C" unsigned int fn_8022461C(void*, unsigned int);
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, int);
void operator delete(void*);
extern "C" void* fn_802D26F8(void* this_, short freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)this_ = lbl_804A9428;
        if ((unsigned short)fn_8022461C(p + 0xc, *(unsigned int*)(p + 4)) != 0xd) {
            lbl_804C0EA0.x = *(float*)(p + 0xc);
            lbl_804C0EA0.y = *(float*)(p + 0x10);
            lbl_804C0EA0.z = *(float*)(p + 0x14);
            lbl_8053AB68 = *(unsigned int*)(p + 4);
        }
        void* h = *(void**)(p + 0x230);
        if (h != 0) {
            fn_801EE434(h);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" int fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_802D27A8(void* this_) {
    char* p = (char*)this_;

    *(u32*)(p + 0x240) = *(u32*)(p + 0x90) & 0x7f;
    *(u32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 7) & 0x1f;
    *(u32*)(p + 0x238) = 0;
    *(u32*)(p + 0x23c) = 0;
    *(f32*)(p + 0x60) = -8.0f;
    *(f32*)(p + 0x64) = -8.0f;
    *(f32*)(p + 0x68) = 8.0f;
    *(f32*)(p + 0x6c) = 8.0f;
    *(f32*)(p + 0x80) = -4.0f;
    *(f32*)(p + 0x84) = -4.0f;
    *(f32*)(p + 0x88) = 4.0f;
    *(f32*)(p + 0x8c) = 4.0f;
    *(u8*)(p + 0x254) = 0xff;
    *(s16*)(p + 0x94) = 0;
    *(u32*)(p + 0x248) = 0;
    *(u32*)(p + 0x24c) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x244) = 0;
    if (*(s32*)(p + 0x234) == 1) {
        *(s32*)(p + 0x230) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x1a8, 0, 0, 0, 0, 1);
    }
    *(s32*)(p + 0x250) = 4;
}

extern "C" void fn_802D2880(void) {
}

