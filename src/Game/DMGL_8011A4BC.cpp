#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_8010DF58();
extern "C" void fn_8010DF98();
extern "C" void fn_801D2608(void* p, u32 a, u32 b);
extern "C" void fn_801D22DC(void* p, u32 a, u32 b, u32 c);
extern "C" void fn_801D1F14(void* p);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7440(void* p, u32 a);
extern "C" void __dt__13Base_8010E074Fv(void* p, int how);
extern "C" void fn_801EE434(void* p);
extern void operator delete(void* p);
extern f32 lbl_8053C7D0;

extern void* lbl_8049DB30[];
extern void* lbl_8049CC34[];

extern f32 lbl_8053C7D0;
extern "C" u32 fn_8011AAB0(void* param_1) {
    u32 val = *(u32*)((u8*)param_1 + 0x234);
    return ((3U - val) | (val - 3U)) >> 31;
}

extern "C" s32 fn_8011AAC8(char* p) {
    return *(s32*)(p + 0x234);
}

extern "C" void* fn_8011921C();
extern "C" void fn_801184F0(void* p, s32 a);
extern "C" void fn_802D9FF4(void* p, s32 a, s32 b);
extern "C" void fn_802DA8DC();
extern "C" void* fn_8013CC50(void* p, void* q, f32 f, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern f32 lbl_8053C7B8;
extern "C" void fn_8011AAD0(void* self)
{
    u8* p = (u8*)self;
    s32 state = *(s32*)(p + 0x234);
    switch (state) {
    case 3:
        if (*(s32*)((u8*)fn_8011921C() + 8) >= 0x78) {
            fn_801184F0(fn_8011921C(), 0);
            fn_802D9FF4(fn_802D6A9C(), *(s32*)(p + 0x238), *(s32*)(p + 0x23c));
            fn_802D6A9C();
            fn_802DA8DC();
            *(s32*)(p + 0x234) = 4;
        }
        break;
    case 4:
        break;
    case 0:
        if (*(s32*)((u8*)fn_8011921C() + 8) >= 0x47e) {
            fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4d7, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4d8, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4d9, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4da, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4db, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4dc, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4dd, 0, 0, 0, 0, 1);
            if (*(void**)(p + 0x24c) == 0) {
                *(void**)(p + 0x24c) = fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4de, 0, 0, 0, 0, 1);
            }
            if (*(void**)(p + 0x250) == 0) {
                *(void**)(p + 0x250) = fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x4df, 0, 0, 0, 0, 1);
            }
            *(s32*)(p + 0x240) = 0xb4;
            *(s32*)(p + 0x234) = 1;
        }
        break;
    case 1:
        if (*(s32*)((u8*)fn_8011921C() + 8) >= 0x794) {
            *(s32*)(p + 0x240) = 0x78;
            *(s32*)(p + 0x234) = 2;
        }
        break;
    case 2:
        break;
    }
}

extern "C" void fn_8011AD30() {
    fn_8010DF58();
}

extern "C" void fn_8010DF78();
extern "C" void* fn_801902C0();
extern "C" void fn_8011888C(void* a, void* b);
extern "C" void fn_801186B0(void* a, s32 b);
extern "C" void* fn_80119DD0();
extern "C" void fn_80119998(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_8011A4BC(void* p);
extern "C" s32 fn_8023AF14(void* a, void* b, f32 c, s32 d);
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern f32 lbl_8053C7D4;
extern "C" void fn_8011AD50(void* param_1) {
    u8* p = (u8*)param_1;
    f32 v[4];
    void* obj;
    u8 ok;
    s32 idx;

    fn_8010DF78();
    *(u8*)((u8*)fn_801902C0() + 0x7a8) = 1;
    if (*(s32*)(p + 0x234) == 2) {
        if (((u8 (*)(void*))(*(void***)param_1)[0x34 / 4])(param_1) != 0) {
            if (*(void**)(p + 0x254) == 0) {
                *(void**)(p + 0x254) = fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x111, 0, 0, 0, 0, 1);
            }
            if (*(void**)(p + 0x258) == 0) {
                *(void**)(p + 0x258) = fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C7B8, 0x112, 0, 0, 0, 0, 1);
            }
        } else {
            obj = *(void**)(p + 0x254);
            if (obj != 0) {
                *(u32*)((u8*)obj + 0xf4) |= 1;
                *(s32*)((u8*)obj + 0x24) = 1;
                *(void**)(p + 0x254) = 0;
            }
            obj = *(void**)(p + 0x258);
            if (obj != 0) {
                *(u32*)((u8*)obj + 0xf4) |= 1;
                *(s32*)((u8*)obj + 0x24) = 1;
                *(void**)(p + 0x258) = 0;
            }
        }
        if (*(u8*)fn_8011921C() == 0) {
            v[0] = *(f32*)(p + 0x60);
            v[1] = *(f32*)(p + 0x64);
            v[2] = *(f32*)(p + 0x68);
            v[3] = *(f32*)(p + 0x6c);
            v[0] += *(f32*)(p + 0xc);
            v[2] += *(f32*)(p + 0xc);
            v[1] += *(f32*)(p + 0x10);
            v[3] += *(f32*)(p + 0x10);
            idx = fn_8023AF14(v, *(void**)(p + 4), lbl_8053C7D0, 0);
            if (idx < 0) {
                ok = 0;
            } else {
                ok = 1;
                if ((((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << idx)) == 0) {
                    ok = 0;
                }
            }
            if (ok) {
                fn_8011888C(fn_8011921C(), param_1);
                fn_801186B0(fn_8011921C(), 0xe);
                fn_80119998(fn_80119DD0(), 0xb4, 0, 2, 0, 1, 0x3c, 0);
                *(s32*)(p + 0x234) = 3;
            }
        }
    }
    obj = *(void**)((u8*)lbl_8053AB10 + 0x30);
    if (*(u8*)((u8*)obj + 0x284) == 0) {
        *(u8*)((u8*)obj + 0x284) = 1;
        *(f32*)((u8*)obj + 0x28c) = lbl_8053C7D4;
    }
    fn_801D1C18(p + 0x25c);
    fn_8011A4BC(param_1);
}

extern "C" void fn_8011AF9C(void* param_1) {
    fn_8010DF98();
    u32 val = *(u32*)((u8*)param_1 + 0x90);
    *(u32*)((u8*)param_1 + 0x238) = val & 0xf;
    *(u32*)((u8*)param_1 + 0x23c) = (val >> 4) & 0xf;
    fn_801D2608((u8*)param_1 + 0x25c, 0x80539F18, 1);
    fn_801D22DC((u8*)param_1 + 0x25c, 0, 2, 0);
    fn_801D1F14((u8*)param_1 + 0x25c);
    void* result = fn_802D6A9C();
    fn_802D7440(result, 0);
}

extern "C" void* fn_8011B01C(void* this_, s16 freeFlag) {
    if (this_) {
        *(void**)this_ = lbl_8049DB30;
        fn_801EE434(*(void**)((u8*)this_ + 0x24c));
        *(void**)((u8*)this_ + 0x24c) = 0;
        fn_801EE434(*(void**)((u8*)this_ + 0x250));
        *(void**)((u8*)this_ + 0x250) = 0;
        fn_801EE434(*(void**)((u8*)this_ + 0x254));
        *(void**)((u8*)this_ + 0x254) = 0;
        fn_801EE434(*(void**)((u8*)this_ + 0x258));
        *(void**)((u8*)this_ + 0x258) = 0;
        if ((void*)((u8*)this_ + 0x25c) != 0 && (void*)((u8*)this_ + 0x280) != 0) {
            *(void**)((u8*)this_ + (unsigned short)0x280) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8010E074(void* this_);
extern "C" void fn_801D267C(void* p);
extern "C" void* fn_8011B0DC(void* this_) {
    fn_8010E074(this_);
    *(void**)this_ = lbl_8049DB30;
    *((u8*)this_ + 0x230) = 1;
    *(s32*)((u8*)this_ + 0x234) = 0;
    *(s32*)((u8*)this_ + 0x238) = 0;
    *(s32*)((u8*)this_ + 0x23c) = 0;
    *(s32*)((u8*)this_ + 0x240) = 0;
    *((u8*)this_ + 0x244) = 0x9f;
    *((u8*)this_ + 0x245) = 0xaf;
    *((u8*)this_ + 0x246) = 0xff;
    *((u8*)this_ + 0x247) = 0;
    *((u8*)this_ + 0x248) = 0xff;
    *(s32*)((u8*)this_ + 0x24c) = 0;
    *(s32*)((u8*)this_ + 0x250) = 0;
    *(s32*)((u8*)this_ + 0x254) = 0;
    *(s32*)((u8*)this_ + 0x258) = 0;
    fn_801D267C((u8*)this_ + 0x25c);
    return this_;
}

