#include <math.h>
#include "Game/Actor.h"

struct SinCosEntry {
    f32 first;
    f32 second;
};
extern SinCosEntry sincosTable___5JMath[];
extern f32 lbl_80540AD8;


extern "C" char lbl_804A886C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_802D6A9C(void);
extern "C" void fn_802D9FBC(void);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void*, u32, s32);
extern "C" f64 fabs(f64 x);
extern "C" void* fn_8023E724(s32 id);
extern "C" s32 fn_8023DE58(s32 id);
extern "C" s32 fn_80237774(s32 id);
extern "C" u8 fn_8023F264(s32 id);
extern "C" u8 fn_80236B50(s32 id);
extern "C" u8 fn_801F2B7C(char* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801F71A4(void* v, f32 x, f32 y, f32 z);
extern void* lbl_8053AAF8;
extern s32 lbl_804A8858[];
extern f32 __float_epsilon;
extern f32 lbl_80540AB8;
extern f32 lbl_80540ABC;
extern f32 lbl_80540AC0;
extern f32 lbl_80540AC4;
extern f32 lbl_80540AC8;
extern f32 lbl_80540AD0;
extern f32 lbl_80540AD4;
extern const f32 lbl_80540ACC;
extern const f32 lbl_80540ADC;
extern const f32 lbl_80540AE0;
extern const f32 lbl_80540AE4;
extern const f32 lbl_80540AE8;
extern const f32 lbl_80540AEC;
extern void* lbl_8053AED0;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F6058(void*, s32);
extern "C" void fn_8043D67C(void*, s32, s32, s32);
extern "C" void fn_8015F8FC(void* p, s32 room, void* pos, s32 flag);
extern "C" void* Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, s32 a, s32 b, s32 c);
extern void* lbl_8053AB10;
struct ActorSlot9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void slot9();
};

extern "C" Actor* fn_802B7C78(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A886C;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_802B7CD8(void* this_) {
    fn_802D6A9C();
    fn_802D9FBC();
    ((ActorSlot9*)this_)->slot9();
}

extern "C" void fn_802B7D1C(char* this_, s32 idx, s32 mode) {
    Vec tgt;
    s32 dxi;
    f32 len2;
    s32 r28;
    s32 r29;

    {
        f32* src = (f32*)fn_8023E724(*(s32*)(this_ + 0x298));
        *(f64*)&tgt = *(f64*)src;
        tgt.z = src[2];
    }
    dxi = (s32)fabs(*(f32*)(this_ + 0xc) - tgt.x);
    if (dxi < 40) {
        *(s32*)(this_ + 0x250) = 1;
        goto norm;
    }
    if (*(f32*)(this_ + 0xc) < tgt.x) {
        *(s32*)(this_ + 0x250) = 2;
        goto norm;
    }
    *(s32*)(this_ + 0x250) = 4;
    fn_801F0E34(this_, 0x40040, 0);
    if (fn_8023DE58(*(s32*)(this_ + 0x298)) != *(s32*)(this_ + 4)) {
        *(s32*)(this_ + 0x244) = 0xb4;
        *(s32*)(this_ + 0x230) = 3;
        *(s32*)(this_ + 0x250) = 0;
        *(f64*)(this_ + 0x234) = *(f64*)(this_ + 0xc);
        *(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0x14);
        return;
    }
    {
        f32* src = (f32*)fn_8023E724(*(s32*)(this_ + 0x298));
        *(f32*)(this_ + 0x284) = src[0] - *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x288) = src[1] - *(f32*)(this_ + 0x10);
    }
    len2 = *(f32*)(this_ + 0x284) * *(f32*)(this_ + 0x284) + *(f32*)(this_ + 0x288) * *(f32*)(this_ + 0x288);
    if (len2 <= lbl_80540AB8 * __float_epsilon) {
        goto tail;
    }
    if (len2 <= lbl_80540ABC) {
        goto after_norm;
    }
    goto tail;

norm:
    len2 = *(f32*)(this_ + 0x284) * *(f32*)(this_ + 0x284) + *(f32*)(this_ + 0x288) * *(f32*)(this_ + 0x288);
    {
        f32 r = __frsqrte(len2);
        f32 inv = lbl_80540AC0 * r * (lbl_80540AC4 - len2 * (r * r));
        *(f32*)(this_ + 0x284) *= inv;
        *(f32*)(this_ + 0x288) *= inv;
    }
    {
        s32 off = idx << 2;
        *(f32*)(this_ + 0x254) = *(f32*)(this_ + 0x284) * *(f32*)(this_ + 0x268 + off);
        *(f32*)(this_ + 0x258) = *(f32*)(this_ + 0x288) * *(f32*)(this_ + 0x268 + off);
        fn_801F71A4(this_ + 0x3c, *(f32*)(this_ + 0x254), lbl_80540AC8, *(f32*)(this_ + 0x260 + off));
        fn_801F71A4(this_ + 0x40, *(f32*)(this_ + 0x258), lbl_80540AC8, *(f32*)(this_ + 0x260 + off));
        fn_801F71A4(this_ + 0x260 + off, lbl_80540ABC, lbl_80540AD0, lbl_80540AD0);
    }
after_norm:
    *(f32*)(this_ + 0xc) += *(f32*)(this_ + 0x3c);
    *(f32*)(this_ + 0x10) += *(f32*)(this_ + 0x40);
    *(f32*)(this_ + 0x14) += *(f32*)(this_ + 0x44);
    r29 = 0x12;
tail:
    r28 = *(s32*)(this_ + 0x114);
    if (((u8*)lbl_8053AAF8)[0x7f] == 0) {
        s32 n = fn_80237774(*(s32*)(this_ + 0x298));
        r28 = (n > 1) ? n - 1 : 0;
        r29 = 4;
    }
    if (fn_8023F264(*(s32*)(this_ + 0x298)) == 1 && fn_80236B50(*(s32*)(this_ + 0x298)) == 0) {
        if (fn_801F2B7C(this_, r28, -1, r29)) {
            fn_801F0E34(this_, 0x40041, 0);
            *(s32*)(this_ + 0x244) = 0x8c;
            *(f64*)(this_ + 0x234) = *(f64*)(this_ + 0xc);
            *(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0x14);
            if (*(s32*)(this_ + 0x298) == lbl_804A8858[r28 >> 1]) {
                *(s32*)(this_ + 0x230) = mode;
                *(s32*)(this_ + 0x250) = 0;
                *(s32*)(this_ + 0x280) = 100;
                if (((u8*)lbl_8053AAF8)[0x7e] == 0) {
                    *(u8*)(this_ + 0x11c) = 0;
                    fn_801F0E34(this_, 0x40041, 0);
                }
            } else {
                *(s32*)(this_ + 0x244) = 0xb4;
                *(s32*)(this_ + 0x230) = mode;
                *(s32*)(this_ + 0x250) = 0;
            }
        }
    } else {
        *(s32*)(this_ + 0x244) = 0xb4;
        *(s32*)(this_ + 0x230) = mode;
        *(s32*)(this_ + 0x250) = 0;
        *(f64*)(this_ + 0x234) = *(f64*)(this_ + 0xc);
        *(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0x14);
    }
}

extern "C" void fn_802B8078(char* this_) {
    *(s32*)(this_ + 0x29c) = fn_8023DE58(*(s32*)(this_ + 0x298));
    if (*(s32*)(this_ + 0x29c) < 8) {
        if (*(s32*)(this_ + 4) >= 8) {
            *(Vec*)(this_ + 0xc) = *(Vec*)(this_ + 0x28c);
            *(s32*)(this_ + 4) = *(s32*)(this_ + 0x29c);
            Vec v = *(Vec*)(this_ + 0xc);
            v.y += lbl_80540AB8;
            v.z += lbl_80540AD4;
            fn_8013CC50(*(s32*)(this_ + 4), &v, 0x17d, 1, 0, 0, 0, 1, lbl_80540ACC);
            fn_8015F8FC(*(void**)((char*)lbl_8053AB10 + 0x30), *(s32*)(this_ + 4), this_ + 0xc, 3);
            *(s32*)(this_ + 0x244) = 0x32;
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x230) = 4;
        } else {
            *(s32*)(this_ + 0x230) = 2;
            *(s32*)(this_ + 0x244) = 300;
        }
    } else {
        if (*(s32*)(this_ + 4) >= 8) {
            if (*(s32*)(this_ + 0x29c) == *(s32*)(this_ + 4)) {
                *(s32*)(this_ + 0x230) = 7;
                *(s32*)(this_ + 0x244) = 300;
            } else {
                *(Vec*)(this_ + 0xc) = *(Vec*)(this_ + 0x28c);
                *(s32*)(this_ + 4) = *(s32*)(this_ + 0x29c);
                Vec v = *(Vec*)(this_ + 0xc);
                v.y += lbl_80540AB8;
                v.z += lbl_80540AD4;
                fn_8013CC50(*(s32*)(this_ + 4), &v, 0x17d, 1, 0, 0, 0, 1, lbl_80540ACC);
                fn_8015F8FC(*(void**)((char*)lbl_8053AB10 + 0x30), *(s32*)(this_ + 4), this_ + 0xc, 3);
                *(s32*)(this_ + 0x244) = 0x32;
                *(s32*)(this_ + 0x24c) = 0;
                *(s32*)(this_ + 0x230) = 4;
            }
        } else {
            Vec v = *(Vec*)(this_ + 0xc);
            v.y += lbl_80540AB8;
            v.z += lbl_80540AD4;
            fn_8013CC50(*(s32*)(this_ + 4), &v, 0x17d, 1, 0, 0, 0, 1, lbl_80540ACC);
            fn_8015F8FC(*(void**)((char*)lbl_8053AB10 + 0x30), *(s32*)(this_ + 4), this_ + 0xc, 3);
            *(Vec*)(this_ + 0x28c) = *(Vec*)(this_ + 0xc);
            Vec* src = (Vec*)fn_8023E724(*(s32*)(this_ + 0x298));
            *(Vec*)(this_ + 0xc) = *src;
            *(s32*)(this_ + 0x244) = 0xb4;
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x230) = 5;
            *(s32*)(this_ + 4) = *(s32*)(this_ + 0x29c);
            Vec t;
            t.x = *(f32*)(this_ + 0xc) - lbl_80540AD4;
            t.y = *(f32*)(this_ + 0x10) - lbl_80540AD4;
            t.z = *(f32*)(this_ + 0x14);
            Actor_CreateByID(fn_801F856C(), 0x4B4D5249, *(s32*)(this_ + 4), &t, 0x81, -1, -1);
            t.x = *(f32*)(this_ + 0xc) + lbl_80540AD4;
            t.y = *(f32*)(this_ + 0x10) - lbl_80540AD4;
            t.z = *(f32*)(this_ + 0x14);
            Actor_CreateByID(fn_801F856C(), 0x4B4D5249, *(s32*)(this_ + 4), &t, 0x81, -1, -1);
            t.x = *(f32*)(this_ + 0xc) - lbl_80540AD4;
            t.y = *(f32*)(this_ + 0x10) + lbl_80540AD4;
            t.z = *(f32*)(this_ + 0x14);
            Actor_CreateByID(fn_801F856C(), 0x4B4D5249, *(s32*)(this_ + 4), &t, 0x81, -1, -1);
            t.x = *(f32*)(this_ + 0xc) + lbl_80540AD4;
            t.y = *(f32*)(this_ + 0x10) + lbl_80540AD4;
            t.z = *(f32*)(this_ + 0x14);
            Actor_CreateByID(fn_801F856C(), 0x4B4D5249, *(s32*)(this_ + 4), &t, 0x81, -1, -1);
        }
    }
}

extern "C" void fn_802B8420(char* this_) {
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x173, 1, 0, 0, 0, 1, 1.0f);
    *(u8*)(this_ + 0x11c) = 0;
    fn_801F0E34(this_, 0x40041, 0);
}

extern "C" char lbl_8046CB70[];
extern "C" s32 lbl_8046CB60[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, void* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_802B848C(char* this_) {
    if (*(s32*)(this_ + 0x230) != 0) {
        u8 rec[0x3c];
        *(s32*)(rec + 0x10) = -1;
        *(s32*)(rec + 0x14) = -1;
        for (s32 i = 0; (u8)i < 0x10; i += 8) {
            rec[(u8)i] = i;
            rec[(u8)(i + 1)] = i + 1;
            rec[(u8)(i + 2)] = i + 2;
            rec[(u8)(i + 3)] = i + 3;
            rec[(u8)(i + 4)] = i + 4;
            rec[(u8)(i + 5)] = i + 5;
            rec[(u8)(i + 6)] = i + 6;
            rec[(u8)(i + 7)] = i + 7;
        }
        *(s32*)(rec + 0x10) = -1;
        rec[0x1c] = 0;
        rec[0x1d] = 0;
        *(s32*)(rec + 0x14) = 0;
        *(s32*)(rec + 0x18) = 0;
        rec[0x1e] = 0;
        rec[0x1f] = 1;
        rec[0x20] = 1;
        rec[0x21] = 0;
        rec[0x22] = 0;
        rec[0x23] = 0;
        rec[0x24] = 0;
        rec[0x25] = 0;
        rec[0x26] = 1;
        *(s32*)(rec + 0x28) = 3;
        rec[0x2c] = 1;
        rec[0x2d] = 0;
        rec[0x2e] = 0;
        *(s32*)(rec + 0x30) = -1;
        *(s32*)(rec + 0x34) = 0;
        *(s32*)(rec + 0x38) = 2;
        rec[0x1c] = 1;
        rec[0x1d] = 1;
        rec[0x13] = *(s32*)(this_ + 0x270);
        *(s32*)(rec + 0x30) = 8;
        fn_801F06F0(this_, lbl_8046CB70, lbl_8046CB60[*(s32*)(this_ + 0x24c)] + 0x466, rec, 7, lbl_80540ACC, lbl_80540ACC);
    }
}

extern "C" void fn_802B8078(char* this_);
extern "C" void fn_802B85EC(char* this_) {
    if (*(u8*)((char*)lbl_8053AAF8 + 0xfe) == 0) {
        ((ActorSlot9*)this_)->slot9();
        return;
    }
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x54e, 1, 0, 0, 0, 1, lbl_80540ACC);
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x172, 1, 0, 0, 0, 1, lbl_80540ACC);
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x59, 1, 0, 0, 0, 1, lbl_80540ACC);
        *(s32*)(this_ + 0x230) = 1;
        break;
    case 1:
        if (*(s32*)(this_ + 0x280) == 0) {
            if (--*(s32*)(this_ + 0x244) == 0) {
                if (*(u8*)((char*)lbl_8053AAF8 + 0x7e) == 1) {
                    if (*(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
                        for (;;) {
                            s32 s = *(s32*)(this_ + 0x298) = *(s32*)(this_ + 0x2a0 + *(s32*)(this_ + 0x27c) * 4);
                            bool bit = (*(u8*)((char*)lbl_8053AAF8 + 0x82) & (u8)(1 << s)) != 0;
                            if (bit && fn_8023F264(s) == 1) {
                                fn_802B8078(this_);
                                *(s32*)(this_ + 0x27c) += 1;
                                if (*(s32*)(this_ + 0x27c) >= 4) *(s32*)(this_ + 0x27c) = 0;
                                break;
                            }
                            *(s32*)(this_ + 0x27c) += 1;
                            if (*(s32*)(this_ + 0x27c) >= 4) {
                                *(s32*)(this_ + 0x244) = 0x78;
                                *(s32*)(this_ + 0x27c) = 0;
                            }
                        }
                    } else {
                        if (*(s32*)(this_ + 0x27c) >= 4) {
                            *(u8*)(this_ + 0x11c) = 0;
                            fn_801F0E34(this_, 0x40041, 0);
                            break;
                        }
                        do {
                            s32 s = *(s32*)(this_ + 0x298) = *(s32*)(this_ + 0x2a0 + *(s32*)(this_ + 0x27c) * 4);
                            bool bit = (*(u8*)((char*)lbl_8053AAF8 + 0x82) & (u8)(1 << s)) != 0;
                            if (bit && fn_8023F264(s) == 1 && fn_80237774(s) > 1) {
                                goto L156;
                            }
                            *(s32*)(this_ + 0x27c) += 1;
                        } while (*(s32*)(this_ + 0x27c) < 4);
                        *(u8*)(this_ + 0x11c) = 0;
                        fn_801F0E34(this_, 0x40041, 0);
                        break;
L156:
                        if (*(u8*)(this_ + 0x11c) != 0) {
                            fn_802B8078(this_);
                            *(s32*)(this_ + 0x27c) += 1;
                        }
                    }
                } else {
                    if (--*(s32*)(this_ + 0x298) < 0) *(s32*)(this_ + 0x298) = 3;
                    fn_802B8078(this_);
                    *(s32*)(this_ + 0x27c) += 1;
                }
            } else {
                s32 ang = *(s32*)(this_ + 0x274) + 0xc0;
                *(s32*)(this_ + 0x274) = ang;
                *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x234) + lbl_80540AD4 * sincosTable___5JMath[(u16)ang >> 5].first;
                *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x238) + lbl_80540AD4 * sincosTable___5JMath[(u16)ang >> 5].second;
            }
        } else {
            Vec* p = (Vec*)fn_8023E724(*(s32*)(this_ + 0x298));
            f32 dx = p->x - *(f32*)(this_ + 0xc);
            f32 dy = (p->y - lbl_80540AD8) - *(f32*)(this_ + 0x10);
            *(f32*)(this_ + 0x284) = dx;
            *(f32*)(this_ + 0x288) = dy;
            f32 len2 = dx * dx + dy * dy;
            if (len2 > lbl_80540AB8 * __float_epsilon && len2 <= lbl_80540ABC) {
                f32 r = __frsqrte(len2);
                f32 inv = lbl_80540AC0 * r * (lbl_80540AC4 - len2 * (r * r));
                *(f32*)(this_ + 0x284) = dx * inv;
                *(f32*)(this_ + 0x288) = dy * inv;
            }
            *(f32*)(this_ + 0x254) = *(f32*)(this_ + 0x284) * *(f32*)(this_ + 0x26c);
            *(f32*)(this_ + 0x258) = *(f32*)(this_ + 0x288) * *(f32*)(this_ + 0x26c);
            fn_801F71A4(this_ + 0x3c, *(f32*)(this_ + 0x254), lbl_80540AC8, *(f32*)(this_ + 0x264));
            fn_801F71A4(this_ + 0x40, *(f32*)(this_ + 0x258), lbl_80540AC8, *(f32*)(this_ + 0x264));
            fn_801F71A4(this_ + 0x264, lbl_80540ACC, lbl_80540AD0, lbl_80540AD0);
            if (--*(s32*)(this_ + 0x280) == 0) {
                *(s32*)(this_ + 0x274) = 0x8000;
            }
        }
        break;
    case 2:
        fn_802B7D1C(this_, 0, 1);
        break;
    case 3:
        {
            s32 ang = *(s32*)(this_ + 0x274) + 0xc0;
            *(s32*)(this_ + 0x274) = ang;
            *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x234) + lbl_80540AD4 * sincosTable___5JMath[(u16)ang >> 5].first;
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x238) + lbl_80540AD4 * sincosTable___5JMath[(u16)ang >> 5].second;
        }
        if (--*(s32*)(this_ + 0x244) == 0) {
            fn_802B8078(this_);
            fn_801F0E34(this_, 0x40041, 0);
        }
        break;
    case 4:
        if (--*(s32*)(this_ + 0x244) == 0) {
            *(s32*)(this_ + 0x230) = 2;
            *(s32*)(this_ + 0x244) = 0x12c;
            fn_801F0E34(this_, 0x4003f, 0);
        }
        break;
    case 5:
        if (--*(s32*)(this_ + 0x244) == 0) {
            *(s32*)(this_ + 0x230) = 7;
            *(s32*)(this_ + 0x244) = 0x12c;
            fn_801F0E34(this_, 0x4003f, 0);
        }
        break;
    case 6:
        fn_802B7D1C(this_, 1, 8);
        break;
    }
    if (*(s32*)(this_ + 0x270) < 0xff) *(s32*)(this_ + 0x270) += 1;
    if (*(s32*)(this_ + 0x250) == 0) {
        if (--*(s32*)(this_ + 0x248) == 0) {
            if (++*(s32*)(this_ + 0x24c) >= 4) *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 0x14;
        }
    } else {
        *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x250) - 1;
    }
}

extern "C" void fn_802B8C44(u8* this_) {
    f32 f1 = lbl_80540ADC;
    f32 f0 = lbl_80540AE0;
    f32 f3 = lbl_80540ACC;
    f32 f2 = lbl_80540AE4;
    *(f32*)(this_ + 0x60) = f1;
    *(f32*)(this_ + 0x64) = f1;
    f1 = lbl_80540AE8;
    *(f32*)(this_ + 0x68) = f0;
    *(f32*)(this_ + 0x6c) = f0;
    f0 = lbl_80540AEC;
    *(s32*)(this_ + 0x244) = 0xb4;
    *(s32*)(this_ + 0x248) = 0x14;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x260) = f3;
    *(f32*)(this_ + 0x268) = f2;
    *(f32*)(this_ + 0x264) = f1;
    *(f32*)(this_ + 0x26c) = f0;
    *(f64*)(this_ + 0x234) = *(f64*)(this_ + 0xc);
    *(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x274) = 0;
    *(s32*)(this_ + 0x298) = 4;
    *(s32*)(this_ + 0x280) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(void**)(this_ + 0x2a0 + i * 4) = fn_801F6058(fn_801F856C(), i);
    }
    *(s32*)(this_ + 0x27c) = 0;
    this_[0x196] = 1;
    *(s32*)(this_ + 0x230) = 0;
    fn_801F0E34(this_, 0x4003f, 0);
    fn_8043D67C(lbl_8053AED0, 0x197, 0, 0);
}

