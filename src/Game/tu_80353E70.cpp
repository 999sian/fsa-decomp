#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JMath/JMath.h"

struct Actor;
extern "C" void detach__5ActorFv(Actor* a);
extern void* lbl_8053AAF8;
extern void* lbl_8053AD70;
extern void* lbl_8053AB10;
extern f32 lbl_80542730;
extern f32 lbl_80542740;
extern f32 lbl_80542744;
extern f32 lbl_80542748;
extern f32 lbl_8054274C;
extern f32 lbl_80542754;
extern f32 lbl_80542758;
extern f32 lbl_8054275C;
extern "C" void fn_80134FC4(void* p, s32 b);
extern "C" void fn_80134FBC(void* p, s32 b);
extern "C" void fn_8037AE00(void* p);
extern "C" void fn_8037AE30(void* p);
extern "C" void fn_801F0E34(void* a, u32 b, s32 c);
extern "C" void fn_801F714C(void* p, u16 a, s32 b, s32 c);
extern "C" void fn_801F71A4(void* p, f32 a, f32 b, f32 c);
extern "C" void fn_801EB418(void* a, void* b);
extern "C" void fn_80238548(s32 i, s32 b, void* p, s32 d);
extern "C" void fn_8013A884(u32* p);


extern "C" char __vt__4TUGF[];
extern "C" void dtor_801EB8CC(void*, s32);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80353E70(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = __vt__4TUGF;
        dtor_801EB8CC((char*)param_1 + 0x230, -1);
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern s32 lbl_80472288[];
extern const char lbl_80472298[];
extern f32 lbl_80542750;
extern "C" void fn_801EBA14(void* p);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801EB710(void* a, s32 b, void* c);
extern "C" void fn_8018330C(s32* p);
extern const f32 lbl_80542734;
extern const f32 lbl_80542738;
extern const f32 lbl_8054273C;
extern const f32 lbl_80542768;
extern const f32 lbl_8054276C;
extern const f32 lbl_80542770;
extern const f32 lbl_80542774;
extern const f32 lbl_80542778;
extern const f32 lbl_8054277C;
extern const f32 lbl_80542780;
extern "C" void fn_80353EE0(void* this_) {
    DrawRec rec;
    rec.b2d = 1;
    rec.b1c = 1;
    rec.b1d = 1;
    rec.w30 = 8;
    fn_801F06F0(this_, lbl_80472298, lbl_80472288[*(s32*)((char*)this_ + 0x2c8)] + 0x466, &rec, 7, lbl_80542750, lbl_80542750);
}

static inline bool tugfNear(f32 x, f32 y) {
    return x*x + y*y <= lbl_8054273C;
}

extern "C" void fn_80354030(char* this_) {
    if (*(s32*)(this_ + 0x2b8) != 0) {
        char* p = *(char**)((char*)lbl_8053AB10 + 0x30);
        if (*(u8*)(p + 0x284) == 0) {
            *(u8*)(p + 0x284) = 1;
            *(f32*)(p + 0x28c) = 1.0f;
        }
        p = *(char**)((char*)lbl_8053AB10 + 0x24);
        if (*(u8*)(p + 0x7f4) == 0) {
            *(u8*)(p + 0x7f5) = 1;
        }
    }

    switch (*(s32*)(this_ + 0x2b8)) {
    case 0:
        fn_80134FC4(lbl_8053AAF8, 1);
        fn_8037AE00(lbl_8053AD70);
        fn_80134FBC(lbl_8053AAF8, 1);
        *(s32*)(this_ + 0x2c0) = 0x3c;
        *(s32*)(this_ + 0x2b8) = 1;
        break;
    case 1:
        JMathInlineVEC::PSVECAdd((Vec*)(this_ + 0xc), (Vec*)(this_ + 0x3c), (Vec*)(this_ + 0xc));
        if (*(s32*)(this_ + 0x2c0) <= 0) {
            fn_801F0E34(this_, 0x4003f, 0);
            *(f32*)(this_ + 0x288) = lbl_80542758;
            *(f32*)(this_ + 0x3c) = *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x44) = lbl_8054273C;
            *(s32*)(this_ + 0x2c0) = 0;
            *(s32*)(this_ + 0x2b8) = 2;
            f32 scale = lbl_8054275C;
            *(f32*)(this_ + 0x2d8) = scale * (f32)(*(u32*)(this_ + 0x2d4) >> 24);
            *(f32*)(this_ + 0x2dc) = scale * (f32)((*(u32*)(this_ + 0x2d4) >> 16) & 0xff);
            *(f32*)(this_ + 0x2e0) = scale * (f32)((*(u32*)(this_ + 0x2d4) >> 8) & 0xff);
        } else {
            *(f32*)(this_ + 0x2d8) = *(f32*)(this_ + 0x2d8) + *(f32*)(this_ + 0x2e8);
            *(f32*)(this_ + 0x2dc) = *(f32*)(this_ + 0x2dc) + *(f32*)(this_ + 0x2ec);
            *(f32*)(this_ + 0x2e0) = *(f32*)(this_ + 0x2e0) + *(f32*)(this_ + 0x2f0);
        }
        *(s32*)(this_ + 0x2c0) = *(s32*)(this_ + 0x2c0) - 1;
        break;
    case 2:
        if (*(s32*)(this_ + 0x2c0) <= 0) {
            *(s32*)(this_ + 0x2c0) = 300;
            *(s32*)(this_ + 0x2b8) = 3;
        } else {
            *(s32*)(this_ + 0x2c0) = *(s32*)(this_ + 0x2c0) - 1;
        }
        *(s32*)(this_ + 0x2bc) = *(s32*)(this_ + 0x2bc) - 1;
        if (*(s32*)(this_ + 0x2bc) < 0) {
            *(s32*)(this_ + 0x2bc) = 10;
            *(s32*)(this_ + 0x2c8) = *(s32*)(this_ + 0x2c8) + 1;
            *(u32*)(this_ + 0x2c8) = *(u32*)(this_ + 0x2c8) & 3;
        }
        break;
    case 3:
        if (*(s32*)(this_ + 0x2c4) <= 0 || (*(s32*)(this_ + 0x2c0) <= 0 && *(f32*)(this_ + 0xc) >= *(f32*)(this_ + 0x290) && *(f32*)(this_ + 0x10) >= *(f32*)(this_ + 0x294))) {
            if (*(s32*)(this_ + 0x2c0) <= 0) {
                *(f32*)(this_ + 0x290) = *(f32*)(this_ + 0x2a8) - lbl_80542730;
                *(f32*)(this_ + 0x294) = (*(f32*)(this_ + 0x2ac) + *(f32*)(this_ + 0x2b4)) * lbl_80542738 + lbl_80542734;
            } else {
                f32 x = *(f32*)(this_ + 0x290) - *(f32*)(this_ + 0xc);
                f32 y = *(f32*)(this_ + 0x294) - *(f32*)(this_ + 0x10);
                (x*x + y*y <= lbl_8054273C);
            }
            f32 ang = JMath::atanTable_.atan2_(*(f32*)(this_ + 0x290) - *(f32*)(this_ + 0xc), *(f32*)(this_ + 0x294) - *(f32*)(this_ + 0x10));
            *(s16*)(this_ + 0x2d0) = (s16)(s32)(ang * lbl_80542740);
            *(s32*)(this_ + 0x2c4) = 6;
        }
        fn_801F714C(this_ + 0x2cc, *(u16*)(this_ + 0x2d0), 0x14, 0x1000);
        *(f32*)(this_ + 0x2a0) = lbl_80542744 * JMath::sincosTable_.mTable[(u32)*(u16*)(this_ + 0x2cc) >> 5].first;
        *(f32*)(this_ + 0x2a4) = lbl_80542744 * JMath::sincosTable_.mTable[(u32)*(u16*)(this_ + 0x2cc) >> 5].second;
        fn_801F71A4(this_ + 0x3c, *(f32*)(this_ + 0x2a0), lbl_80542748, lbl_8054274C);
        fn_801F71A4(this_ + 0x40, *(f32*)(this_ + 0x2a4), lbl_80542748, lbl_8054274C);
        *(s32*)(this_ + 0x2c4) = *(s32*)(this_ + 0x2c4) - 1;
        JMathInlineVEC::PSVECAdd((Vec*)(this_ + 0xc), (Vec*)(this_ + 0x3c), (Vec*)(this_ + 0xc));
        fn_801EB418(this_ + 0x230, this_ + 0xc);
        if (*(s32*)(this_ + 0x2c0) <= 0) {
            if (*(f32*)(this_ + 0x2a8) - lbl_80542730 > *(f32*)(this_ + 0xc)) {
                *(s32*)(this_ + 0x2b8) = 4;
            }
        } else {
            if (*(s32*)(this_ + 0x2c0) <= 0x28 && *(u8*)(this_ + 0x2f8) == 1) {
                fn_801F0E34(this_, 0x40041, 0);
                *(u8*)(this_ + 0x2f8) = 0;
                *(s32*)(this_ + 0x2c0) = *(s32*)(this_ + 0x2c0) - 1;
                fn_801F0E34(this_, 0x40051, 0);
            }
        }
        *(s32*)(this_ + 0x2bc) = *(s32*)(this_ + 0x2bc) - 1;
        if (*(s32*)(this_ + 0x2bc) < 0) {
            *(s32*)(this_ + 0x2bc) = 10;
            *(s32*)(this_ + 0x2c8) = *(s32*)(this_ + 0x2c8) + 1;
            *(u32*)(this_ + 0x2c8) = *(u32*)(this_ + 0x2c8) & 3;
        }
        break;
    case 4:
        fn_80134FC4(lbl_8053AAF8, 0);
        fn_8037AE30(lbl_8053AD70);
        for (s32 i = 0; i < 4; i++) {
            fn_80238548(i, 0x28, this_ + 0xc, 0x12);
        }
        *(u8*)(this_ + 0x28c) = 1;
        *(f32*)(this_ + 0x288) = lbl_8054273C;
        fn_80134FBC(lbl_8053AAF8, 0);
        detach__5ActorFv((Actor*)this_);
        break;
    }

    u32 color = ((s32)*(f32*)(this_ + 0x2d8) << 24) | ((s32)*(f32*)(this_ + 0x2dc) << 16) | ((s32)*(f32*)(this_ + 0x2e0) << 8) | (s32)*(f32*)(this_ + 0x2e4);
    fn_8013A884(&color);
}

extern "C" void fn_803545A4(char* this_) {
    struct {
        s32 a;
        s32 b;
        f32 c[7];
        s16 d;
    } rec;
    s32 tmp;
    char* p;

    fn_801EBA14(&rec);
    p = (char*)fn_802D6A9C();
    {
        s32* src = (s32*)(p + 0xcc);
        s32* dst = (s32*)(this_ + 0x2a8);
        s32 x = src[0], y = src[1];
        dst[0] = x;
        dst[1] = y;
        x = src[2];
        y = src[3];
        dst[2] = x;
        dst[3] = y;
    }
    *(f32*)(this_ + 0xc) = lbl_80542768 + *(f32*)(this_ + 0x2b0);
    *(f32*)(this_ + 0x10) = (*(f32*)(this_ + 0x2ac) + *(f32*)(this_ + 0x2b4)) * lbl_80542738 + lbl_80542734;
    *(f32*)(this_ + 0x14) = lbl_8054276C;
    rec.a = 1;
    rec.b = 1;
    rec.c[0] = lbl_8054276C;
    rec.c[1] = lbl_80542770;
    rec.c[2] = lbl_80542774;
    *(s32*)(this_ + 0x23c) = 1;
    *(s32*)(this_ + 0x240) = rec.b;
    *(f32*)(this_ + 0x244) = rec.c[0];
    *(f32*)(this_ + 0x248) = rec.c[1];
    *(f32*)(this_ + 0x24c) = rec.c[2];
    *(f32*)(this_ + 0x250) = rec.c[3];
    *(f32*)(this_ + 0x254) = rec.c[4];
    *(f32*)(this_ + 0x258) = rec.c[5];
    *(f32*)(this_ + 0x25c) = rec.c[6];
    *(s16*)(this_ + 0x260) = rec.d;
    fn_801EB710(this_ + 0x230, 0, this_ + 0xc);
    *(s32*)(this_ + 0x2c8) = 0;
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = 0;
    *(f32*)(this_ + 0x2f4) = lbl_8054273C;
    *(f32*)(this_ + 0x290) = (*(f32*)(this_ + 0x2a8) - *(f32*)(this_ + 0x2b0)) * lbl_80542738 + *(f32*)(this_ + 0x2b0);
    *(f32*)(this_ + 0x294) = (*(f32*)(this_ + 0x2ac) - *(f32*)(this_ + 0x2b4)) * lbl_80542738 + *(f32*)(this_ + 0x2b4);
    *(f32*)(this_ + 0x294) = *(f32*)(this_ + 0x294) + lbl_80542734;
    *(f32*)(this_ + 0x2a4) = lbl_8054273C;
    *(f32*)(this_ + 0x2a0) = lbl_8054273C;
    *(f32*)(this_ + 0x298) = (*(f32*)(this_ + 0x2b0) - *(f32*)(this_ + 0x2a8)) - lbl_80542734;
    *(f32*)(this_ + 0x29c) = (*(f32*)(this_ + 0x2b4) - *(f32*)(this_ + 0x2ac)) - lbl_80542734;
    *(s32*)(this_ + 0x2c4) = 0;
    *(s16*)(this_ + 0x2ce) = 0;
    *(s16*)(this_ + 0x2cc) = 0;
    *(s16*)(this_ + 0x2d0) = 0;
    *(u8*)(this_ + 0x2f8) = 1;
    fn_8018330C(&tmp);
    *(s32*)(this_ + 0x2d4) = tmp;
    *(f32*)(this_ + 0x2d8) = (f32)(*(u32*)(this_ + 0x2d4) >> 24);
    *(f32*)(this_ + 0x2dc) = (f32)((*(u32*)(this_ + 0x2d4) >> 16) & 0xff);
    *(f32*)(this_ + 0x2e0) = (f32)((*(u32*)(this_ + 0x2d4) >> 8) & 0xff);
    *(f32*)(this_ + 0x2e4) = (f32)((*(u32*)(this_ + 0x2d4)) & 0xff);
    *(f32*)(this_ + 0x2e8) = -(lbl_80542778 * *(f32*)(this_ + 0x2d8)) / lbl_8054277C;
    *(f32*)(this_ + 0x2ec) = -(lbl_80542778 * *(f32*)(this_ + 0x2dc)) / lbl_8054277C;
    *(f32*)(this_ + 0x2f0) = -(lbl_80542778 * *(f32*)(this_ + 0x2e0)) / lbl_8054277C;
    *(f32*)(this_ + 0x3c) = lbl_80542780;
    *(s32*)(this_ + 0x2b8) = 0;
}



