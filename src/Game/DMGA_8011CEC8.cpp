#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern "C" void* fn_8011921C(void);
extern "C" void* fn_8011871C(void* a, s32 b, s32 c);
extern "C" void fn_8030C7C4(void* mgr, f32* pos, f32 f);
extern u8* lbl_8053AB10;
extern f32 lbl_8053C860;
extern f32 lbl_8053C864;
extern f32 lbl_8053C868;
extern f32 lbl_8053C86C;
extern f32 lbl_8053C870;
extern f32 lbl_8053C874;
extern f32 lbl_8053C878;
extern f32 lbl_8053C87C;
extern f32 lbl_8053C880;
extern f32 lbl_8053C884;
extern f64 lbl_8053C888;
extern int __float_epsilon[];
extern s32 lbl_80464BBC[];
extern void* lbl_8053AF80;
extern f32 lbl_8053C8A0;
struct Actor {
    void detach();
};
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801186B0(void* a, s32 b);
extern "C" void fn_80230BF4(s32 a, s32 b);
extern "C" void* fn_8023E724(s32 a);
extern "C" void fn_80230498(s32 a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern "C" void fn_80458FF0(void* a, s32 b, s32 c, s32 d);
extern "C" void fn_8013CC50(void* a, void* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_801F0E34(void* a, s32 b, s32 c);
extern "C" void fn_802DCD1C(void* a, void* b);
extern "C" void fn_802D9CB0(void);
extern "C" void fn_80118384(void);
#include "JSystem/JGeometry/Vec.h"


extern char lbl_8049DD68[];
extern char lbl_8049CC34[];
extern "C" void __dt__13Base_8010E074Fv(void* p, s32 n);
extern "C" char* fn_8011CEC8(char* p, s16 n) {
    if (p != 0) {
        *(char**)p = lbl_8049DD68;
        if (p + 0x274 != 0 && p + 0x298 != 0) {
            *(char**)(p + 0x298) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8011CF48(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x234)) {
    case 0: {
        f32 v[2];
        if (*(f32*)(p + 0x244) - (*(f32*)(p + 0x28) - lbl_8053C864) >= lbl_8053C868) {
            fn_801CD950((f32*)(p + 0x23c), lbl_8053C86C, lbl_8053C870);
        } else {
            fn_801CD950((f32*)(p + 0x23c), lbl_8053C874, lbl_8053C878);
        }
        fn_801CD950((f32*)(p + 0x244), *(f32*)(p + 0x28) - lbl_8053C864, *(f32*)(p + 0x23c));
        v[1] = *(f32*)(p + 0x244);
        v[0] = *(f32*)(p + 0x240);
        v[1] = *(f32*)(p + 0x244);
        fn_8030C7C4(*(void**)(lbl_8053AB10 + 0x24), v, *(f32*)(p + 0x258));
        break;
    }
    case 1: {
        f32 v[2];
        v[0] = *(f32*)(p + 0x240);
        v[1] = *(f32*)(p + 0x244);
        fn_8030C7C4(*(void**)(lbl_8053AB10 + 0x24), v, *(f32*)(p + 0x258));
        break;
    }
    case 2: {
        f32 v[2];
        if (*(s32*)((u8*)fn_8011921C() + 0x8) >= *(s32*)((u8*)lbl_80464BBC + 0x18) + 0x14) {
            s32 d = *(s32*)((u8*)lbl_80464BBC + 0x1c) - 0x4b - *(s32*)((u8*)fn_8011921C() + 0x8);
            f32 t = (f32)d;
            if (t < *(f32*)__float_epsilon) {
                *(f32*)(p + 0x244) = *(f32*)(p + 0x28);
            } else {
                *(f32*)(p + 0x244) = lbl_8053C87C / t * (*(f32*)(p + 0x28) - *(f32*)(p + 0x244)) + *(f32*)(p + 0x244);
            }
        }
        v[1] = *(f32*)(p + 0x244);
        v[0] = *(f32*)(p + 0x240);
        v[1] = *(f32*)(p + 0x244);
        fn_8030C7C4(*(void**)(lbl_8053AB10 + 0x24), v, *(f32*)(p + 0x258));
        break;
    }
    case 3: {
        f32 v[2];
        v[1] = *(f32*)(p + 0x244);
        v[0] = *(f32*)(p + 0x240);
        v[1] = *(f32*)(p + 0x244);
        fn_8030C7C4(*(void**)(lbl_8053AB10 + 0x24), v, *(f32*)(p + 0x258));
        break;
    }
    case 4: {
        f32 v[2];
        f32 z[3];
        f32* q;
        u8* ret = (u8*)fn_8011921C();
        u8* r = (u8*)fn_8011871C(ret, *(s32*)(ret + 0x10), 0x444d5357);
        if (r == *(u8**)((u8*)fn_8011921C() + 0x14)) {
            z[0] = lbl_8053C860;
            z[1] = lbl_8053C860;
            z[2] = lbl_8053C860;
            q = z;
        } else {
            q = (f32*)(*(u8**)r + 0xc);
        }
        fn_801CD950((f32*)(p + 0x244), lbl_8053C880 + q[1], lbl_8053C884);
        v[0] = *(f32*)(p + 0x240);
        v[1] = *(f32*)(p + 0x244);
        fn_8030C7C4(*(void**)(lbl_8053AB10 + 0x24), v, *(f32*)(p + 0x258));
        break;
    }
    default:
        break;
    }
}

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_8011D1B8(void* this_, s32 state) {
    void* object = this_;
    char* p;
    s32 mode;
    s32 i;
    p = (char*)object;
    mode = state;
    switch (mode) {
    case 0:
    case 5:
    case 8:
        break;
    case 1: {
        fn_801186B0(fn_8011921C(), 0x11);
        for (i = 0; i < 4; i++) {
            fn_80230BF4(i, 3);
            fn_80230498(i, fn_8023E724(i), 0x3f, 0, -0x80, -0x80, 1);
        }
        {
            u8* ret = (u8*)fn_8011921C();
            ret[2] = 1;
        }
        fn_80458FF0(lbl_8053AF80, 0x100001B, 0, 0);
        break;
    }
    case 2: {
        s32 pair[2];
        f32 f = lbl_8053C860;
        *(f32*)(p + 0x23C) = f;
        *(f32*)(p + 0x238) = f;
        p[0x230] = 0;
        pair[0] = 0;
        pair[1] = -1;
        fn_802DCD1C(fn_802D6A9C(), pair);
        break;
    }
    case 3:
        *(f32*)(p + 0x238) = lbl_8053C860;
        p[0x230] = 1;
        break;
    case 4:
        *(f32*)(p + 0x238) = lbl_8053C8A0;
        break;
    case 6: {
        s32 j;
        for (j = 0; j < 4; j++) {
            f32 z[3];
            f32* q;
            u8* ret = (u8*)fn_8011921C();
            u8* r = (u8*)fn_8011871C(ret, *(s32*)(ret + 0x10), 0x444d4c4b);
            if (r == *(u8**)((u8*)fn_8011921C() + 0x14)) {
                z[0] = lbl_8053C860;
                z[1] = lbl_8053C860;
                z[2] = lbl_8053C860;
                q = z;
            } else {
                q = (f32*)(*(u8**)r + 0x24);
            }
            fn_80230498(j, q, 0x3f, 0, -0x80, -0x80, 1);
        }
        {
            JGeometry::TVec3<f32> v;
            f32 a[3];
            f32* q;
            u8* ret = (u8*)fn_8011921C();
            u8* r = (u8*)fn_8011871C(ret, *(s32*)(ret + 0x10), 0x444d4c4b);
            if (r == *(u8**)((u8*)fn_8011921C() + 0x14)) {
                a[0] = lbl_8053C860;
                a[1] = lbl_8053C860;
                a[2] = lbl_8053C860;
                q = a;
            } else {
                q = (f32*)(*(u8**)r + 0x24);
            }
            v = *(JGeometry::TVec3<f32>*)q;
            fn_8013CC50(*(void**)(p + 0x4), &v, lbl_8053C87C, 0x33f, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 0x4), &v, lbl_8053C87C, 0x340, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 0x4), &v, lbl_8053C87C, 0x341, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(p + 0x4), &v, lbl_8053C87C, 0x342, 0, 0, 0, 0, 1);
        }
        fn_801F0E34(p, 0x30079, 0);
        break;
    }
    case 7: {
        for (i = 0; i < 4; i++) {
            fn_80230BF4(i, 3);
            fn_80230498(i, fn_8023E724(i), 0x3f, 0xff, -0x80, -0x80, 1);
        }
        break;
    }
    case 9:
        fn_802D6A9C();
        fn_802D9CB0();
        fn_8011921C();
        fn_80118384();
        ((Actor*)p)->detach();
        break;
    }
    *(s32*)(p + 0x234) = state;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" u8 fn_8011D4B4(int param_1) {
    return *(int*)(param_1 + 0x234) == 9;
}

extern "C" u32 fn_8011D4B4(int param_1) {
    return (u32)(__cntlzw(9 - *(int*)(param_1 + 0x234)) >> 5);
}

extern "C" s32 fn_8011D4C8(char* p) {
    return *(s32*)(p + 0x234);
}

extern s32 lbl_80464BBC[];
extern "C" void* fn_8011921C(void);
extern f32 lbl_8053C864;
extern f32 lbl_8053C868;
extern f32 lbl_8053C86C;
extern f32 lbl_8053C870;
extern f32 lbl_8053C874;
extern f32 lbl_8053C878;
extern f32 lbl_8053C87C;
extern f32 lbl_8053C880;
extern f32 lbl_8053C884;
extern f64 lbl_8053C888;
extern f32 lbl_8053C860;
extern int __float_epsilon[];

extern "C" void fn_8011D4D0(void* param_1) {
    if (*(s32*)((char*)fn_8011921C() + 4) == 0x11) {
        s32 v = *(s32*)((char*)fn_8011921C() + 8);
        if (v == lbl_80464BBC[2]) {
            fn_8011D1B8(param_1, 2);
        } else if (v == lbl_80464BBC[3]) {
            fn_8011D1B8(param_1, 3);
        } else if (v == lbl_80464BBC[4]) {
            fn_8011D1B8(param_1, 4);
        } else if (v == lbl_80464BBC[5]) {
            fn_8011D1B8(param_1, 5);
        } else if (v == lbl_80464BBC[6]) {
            fn_8011D1B8(param_1, 6);
        } else if (v == lbl_80464BBC[7]) {
            fn_8011D1B8(param_1, 7);
        } else if (v == lbl_80464BBC[8]) {
            fn_8011D1B8(param_1, 8);
        } else if (v == lbl_80464BBC[9]) {
            fn_8011D1B8(param_1, 9);
        }
    }
}

extern "C" void fn_8010DF58(void);
extern "C" void fn_8010DF98(void);
extern "C" void fn_801D2608(void* p, void* a, s32 b);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, u32 a);
extern "C" void fn_8011D5F4(void) {
    fn_8010DF58();
}

extern "C" void fn_8010DF78(void* this_);
extern "C" void fn_8011CF48(void* this_);
extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern "C" void fn_801D1C18(void* anim);
extern "C" s32 fn_801365A8(void);
extern "C" void fn_8030C5F0(void* a, f32* v, s32 b, s32 c, f32* out);
extern "C" void fn_8043A208(void* p, s32 n, f32 x, f32 y, f32 scale, f32 height);
extern "C" void* fn_8011871C(void* a, s32 b, s32 c);
extern "C" void fn_8030C7C4(void* mgr, f32* pos, f32 f);
extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern u8* lbl_8053AB10;
extern s32 lbl_80464BBC[];
extern f32 lbl_8053C864;
extern f32 lbl_8053C868;
extern f32 lbl_8053C86C;
extern f32 lbl_8053C870;
extern f32 lbl_8053C874;
extern f32 lbl_8053C878;
extern f32 lbl_8053C87C;
extern f32 lbl_8053C880;
extern f32 lbl_8053C884;
extern f64 lbl_8053C888;
extern int __float_epsilon[];
extern char lbl_8053AA9C;
extern s32 lbl_8053AA98;
extern f32 lbl_8053C860;
extern f32 lbl_8053C890;
extern f32 lbl_8053C894;
extern f32 lbl_8053C898;
extern f32 lbl_8053C89C;
extern f32 lbl_8053C8A0;
extern f32 lbl_8053C8A4;
extern f32 lbl_8053C8A8;
extern u8* lbl_8053AB10;
extern void* lbl_8053AED0;
extern "C" void fn_8011D614(int param_1) {
    fn_8010DF78((void*)param_1);
    fn_8011CF48((void*)param_1);
    if (lbl_8053AA9C == 0) {
        lbl_8053AA98 = 0;
        lbl_8053AA9C = 1;
    }
    switch (*(s32*)(param_1 + 0x234)) {
    case 0:
        fn_8011D1B8((void*)param_1, 1);
        break;
    case 3:
        fn_801CD950((f32*)(param_1 + 0x238), lbl_8053C8A0, lbl_8053C8A4);
        break;
    case 4:
        break;
    case 5:
        fn_801CD950((f32*)(param_1 + 0x238), lbl_8053C860, lbl_8053C8A8);
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
    if (*(u8*)(param_1 + 0x230) != 0) {
        f32 v[3];
        f32 out[3];
        u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
        v[0] = -*(f32*)(obj + 0x10);
        v[1] = -*(f32*)(obj + 0x20);
        v[2] = lbl_8053C860;
        fn_8030C5F0(obj, v, 0, 0, out);
        f32 f3;
        switch (fn_801365A8()) {
        case 2: f3 = lbl_8053C890; break;
        default: f3 = lbl_8053C894; break;
        }
        out[0] = -(f3 * lbl_8053C898 - out[0]);
        out[1] = out[1] - lbl_8053C89C;
        fn_8043A208(lbl_8053AED0, (s32)*(f32*)(param_1 + 0x238), out[0], out[1], f3, lbl_8053C880);
    }
    fn_801D1C18((void*)(param_1 + 0x274));
}

extern char lbl_80539F20;
extern "C" void fn_8011D77C(int param_1) {
    fn_8010DF98();
    fn_801D2608((void*)(param_1 + 0x274), &lbl_80539F20, 1);
    fn_801D22DC((void*)(param_1 + 0x274), 0, 2, 0);
    ((void (*)(void*, f32))fn_801D1F14)((void*)(param_1 + 0x274), 0.0f);
    *(JGeometry::TVec3f*)(param_1 + 0x240) = *(JGeometry::TVec3f*)(param_1 + 0xc);
    *(f32*)(param_1 + 0x258) = 284.0f;
    fn_802D7440(fn_802D6A9C(), 0);
}

