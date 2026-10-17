#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/JUTVideo.h"

extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80118454(void*);
extern "C" void fn_801184F0(void*, s32);
extern "C" void fn_80458FF0(void*, s32, s32, s32);
extern "C" void fn_80458F9C(void*, s32);
extern "C" void fn_8022FE80(s32, void*, void*, s32, s32);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void*, s32, s32);
extern "C" void fn_802DA8DC(void*);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void*, s32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void detach__5ActorFv(void*);
extern "C" void Actor_CreateByID(void*, s32, s32, void*, s32, s32, s32);
extern "C" void fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void* sManager__8JUTVideo;
extern "C" void* lbl_8053AF80;
extern "C" f32 lbl_8053CAE0;
extern "C" f32 lbl_8053CAE4;
extern "C" f32 lbl_8053CAE8;
extern "C" f32 lbl_8053CAEC;

extern "C" void* fn_8011921C(void);
extern "C" void fn_80128728(void* p, s32 x);
extern "C" const s32 lbl_80464FC0[];

extern "C" char lbl_8049E500[];
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void* fn_801286C0(void* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049E500;
        *(s32*)((u8*)p + 0x23c) = 0;
        __dt__13Base_8010E074Fv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80128728(void* p, s32 x) {
    struct Box4 {
        f32 a, b, c, d;
    };
    u8* this_ = (u8*)p;

    switch (x) {
    case 0: {
        u8* obj = (u8*)fn_80119DD0();
        fn_80119998(obj, 0xb4, 0, 0, 0, 0, 0, 0);
        obj = (u8*)fn_80119DD0();
        obj[1] = 1;
        break;
    }
    case 1: {
        fn_80458FF0(lbl_8053AF80, 0x100002c, 0, 0);
        fn_80118454(fn_8011921C());
        u8* obj = (u8*)fn_80119DD0();
        obj[1] = 0;
        break;
    }
    case 3: {
        u8* obj = (u8*)fn_80119DD0();
        fn_80119998(obj, 0xb4, 0, 1, 0, 0, 0, 0);
        obj = (u8*)fn_80119DD0();
        obj[1] = 0;
        break;
    }
    case 4: {
        f32 pos[3];
        fn_80458F9C(lbl_8053AF80, 0x3c);
        u8* obj = (u8*)fn_80119DD0();
        obj[1] = 0;
        Box4 box = *(Box4*)((char*)fn_802D6A9C() + 0xcc);
        pos[0] = lbl_8053CAE0 * (box.a - box.c) + box.c;
        pos[1] = lbl_8053CAE0 * (box.b - box.d) + box.d;
        pos[2] = lbl_8053CAE4;
        fn_8013CC50(*(s32*)(this_ + 4), pos, lbl_8053CAE8, 0x33c, 1, 2, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 4), pos, lbl_8053CAE8, 0x33d, 1, 2, 0, 0, 1);
        break;
    }
    case 5: {
        JGeometry::TVec3<f32> pos((f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f, (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f - lbl_8053CAEC, lbl_8053CAE4);
        fn_8022FE80(0, *(void**)(this_ + 4), *(void**)(this_ + 0x198), 1, 0);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, 0x231, *(u32*)(this_ + 4), &copy, 0x62)) {
            fn_80118454(fn_8011921C());
        }
        break;
    }
    case 6:
        fn_80458FF0(lbl_8053AF80, 0x100001d, 0, 0);
        Actor_CreateByID(fn_801F856C(), 0x53455632, *(s32*)(this_ + 4), this_ + 0xc, 0x2000, -1, -1);
        break;
    case 7: {
        JGeometry::TVec3<f32> pos((f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f, (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f - lbl_8053CAEC, lbl_8053CAE4);
        fn_8022FE80(0, *(void**)(this_ + 4), *(void**)(this_ + 0x198), 1, 0);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, 0x23c, *(u32*)(this_ + 4), &copy, 0x62)) {
            fn_80118454(fn_8011921C());
        }
        break;
    }
    case 8:
        fn_80119998(fn_80119DD0(), 0x10e, 0, 2, 0, 0, 0x3c, 0);
        fn_80458F9C(lbl_8053AF80, 0x96);
        break;
    case 9: {
        s32 id = fn_801F7A08(fn_801F856C(), 0x53455632);
        if (id >= 0) {
            void* a = fn_801F666C(fn_801F856C(), id);
            if (a != 0) {
                detach__5ActorFv(a);
            }
        }
        break;
    }
    case 10:
        fn_801184F0(fn_8011921C(), 0);
        fn_802D9FF4(fn_802D6A9C(), 2, 4);
        fn_802DA8DC(fn_802D6A9C());
    case 2:
        break;
    }
    *(s32*)(this_ + 0x230) = x;
}

extern "C" u8 fn_80128B18(char* p) {
    return *(s32*)(p + 0x230) == 10;
}

extern "C" s32 fn_80128B2C(char* p) {
    return *(s32*)(p + 0x230);
}

extern "C" void fn_80128B34(void* p) {
    if (*(s32*)((u8*)fn_8011921C() + 4) == 0xc) {
        s32 v = *(s32*)((u8*)fn_8011921C() + 8);
        if (v == lbl_80464FC0[1]) {
            fn_80128728(p, 1);
        } else if (v == lbl_80464FC0[4]) {
            fn_80128728(p, 4);
        } else if (v == lbl_80464FC0[5]) {
            fn_80128728(p, 5);
        } else if (v == lbl_80464FC0[6]) {
            fn_80128728(p, 6);
        } else if (v == lbl_80464FC0[7]) {
            fn_80128728(p, 7);
        } else if (v == lbl_80464FC0[8]) {
            fn_80128728(p, 8);
        } else if (v == lbl_80464FC0[9]) {
            fn_80128728(p, 9);
        } else if (v == lbl_80464FC0[10]) {
            fn_80128728(p, 10);
        }
    }
}

extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AF38;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_80539F38;
extern "C" void fn_8010DF58(void* p);
extern "C" void fn_8010DF98(void);
extern "C" void fn_8044C028(u8* this_, f32 val);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 x);
extern "C" void fn_80128728(void* p, s32 x);
extern "C" void fn_80128C58(s32 val) {
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x2c) + 0xc) = val;
}

#pragma dont_inline on
extern "C" void fn_80128C68(char* p) {
    fn_80128C58((s32)*(f32*)(p + 0x234));
    s32 v = *(s32*)(p + 0x230);
    if (v >= 1 && v <= 3) {
        fn_8044C028((u8*)lbl_8053AF38, *(f32*)(p + 0x238));
    }
    fn_8010DF58(p);
}

extern "C" void fn_8010DF78(void* p);
extern "C" s32 fn_801CD950(void* p, f32 a, f32 b);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_801183BC(void* p);
extern "C" void fn_8022FE80(s32 a, void* b, void* c, s32 d, s32 e);
extern "C" s32 fn_803865B8(s32 a);
extern "C" void fn_80388EEC(s32 a);
extern "C" void fn_80458F9C(void* p, s32 x);
extern "C" void fn_801186B0(void* p, s32 x);
extern "C" void* lbl_8053AF80;
extern "C" const f32 lbl_8053CAF8;
extern "C" const f32 lbl_8053CAFC;
extern "C" const f32 lbl_8053CB00;
extern "C" const f32 lbl_8053CB04;
extern "C" const f32 lbl_8053CB08;
extern "C" const f32 lbl_8053CB0C;
extern "C" const f32 lbl_8053CB10;
extern "C" const f32 lbl_8053CB14;
extern "C" const f32 lbl_8053CB18;
extern "C" void fn_80128CCC(char* p) {
    fn_8010DF78(p);
    f32 f0 = lbl_8053CAF8;
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x24) + 0x179) = 1;
    f32 f1 = *(f32*)(p + 0x10);
    u8* obj = *(u8**)((u8*)lbl_8053AB10 + 0x24);
    f32 f3 = f0 + f1;
    f32 f4 = *(f32*)(p + 0xc);
    f32 f2 = f1 - f0;
    if (obj[0x840] == 0) {
        obj[0x840] = 1;
        f32 f5 = lbl_8053CAE8;
        *(f32*)(obj + 0x844) = f4;
        f32 f6 = lbl_8053CAFC;
        *(f32*)(obj + 0x848) = f2;
        *(f32*)(obj + 0x84c) = f4;
        *(f32*)(obj + 0x850) = f3;
        *(f32*)(obj + 0x854) = f5;
        *(f32*)(obj + 0x1d4) = f6;
        *(f32*)(obj + 0x1d8) = f6;
    }
    s32 v = *(s32*)(p + 0x230);
    if (v <= 9) {
        u8* obj2 = *(u8**)((u8*)lbl_8053AB10 + 0x30);
        if (obj2[0x284] == 0) {
            u8 one = 1;
            f32 f5 = lbl_8053CB00;
            obj2[0x284] = one;
            *(f32*)(obj2 + 0x28c) = f5;
        }
    }
    v = *(s32*)(p + 0x230);
    if (v >= 1 && v <= 3) {
        fn_8044C028((u8*)lbl_8053AF38, *(f32*)(p + 0x238));
    }
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (*(u8*)fn_8011921C() == 0) {
            fn_80458F9C(lbl_8053AF80, 0x3c);
            fn_801186B0(fn_8011921C(), 0xc);
        }
        break;
    case 1:
        fn_801CD950(p + 0x238, lbl_8053CB04, lbl_8053CB08);
        if (*(u8*)fn_80119DD0() == 0) {
            fn_80128728(p, 2);
        }
        break;
    case 2:
        if (fn_801CD950(p + 0x238, lbl_8053CB0C, lbl_8053CB08) == 0) {
            fn_80128728(p, 3);
        }
        break;
    case 3:
        fn_801CD950(p + 0x238, lbl_8053CB10, lbl_8053CB08);
        if (*(s32*)((u8*)fn_80119DD0() + 4) >= 0xb3) {
            fn_801183BC(fn_8011921C());
            u8* p2 = (u8*)fn_80119DD0();
            p2[1] = 1;
        }
        break;
    case 5:
        fn_8022FE80(0, *(void**)(p + 4), *(void**)(p + 0x198), 1, 0);
        if ((u8)fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_801183BC(fn_8011921C());
        }
        break;
    case 6:
        fn_801CD950(p + 0x234, lbl_8053CB14, lbl_8053CB18);
        break;
    case 7:
        fn_8022FE80(0, *(void**)(p + 4), *(void**)(p + 0x198), 1, 0);
        if ((u8)fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_801183BC(fn_8011921C());
        }
        break;
    case 4:
    case 8:
    case 9:
    case 10:
        break;
    }
}

#pragma dont_inline reset
extern "C" void fn_80128F10(char* p) {
    fn_8010DF98();
    void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
    s32 (*fn)(void*, s32, void*) = (s32 (*)(void*, s32, void*))(*(void***)obj)[6];
    *(s32*)(p + 0x23c) = fn(obj, 0x3f3f3f3f, lbl_80539F38);
    fn_802D7440(fn_802D6A9C(), 0);
    fn_80128728(p, 0);
}

