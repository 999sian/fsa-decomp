// WPCN_80130FAC: .text 0x80130FAC-0x80131D98 (actor WPCN)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80131A70_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049EAE0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80131A70(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049EAE0;
        if (p + 0x230 != 0) {
            if (p + 0x254 != 0) {
                *(void**)(p + 0x254) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- ctor

extern "C" void __ct__5ActorFv(void*);
extern "C" void fn_801D267C(void*);
extern const f32 lbl_8053CCA0;

extern "C" char* fn_80131AF0(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049EAE0;
    fn_801D267C(p + 0x230);
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = -1;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 0;
    *(f32*)(p + 0x27c) = lbl_8053CCA0;
    *(f32*)(p + 0x280) = lbl_8053CCA0;
    *(f32*)(p + 0x284) = lbl_8053CCA0;
    *(f32*)(p + 0x288) = lbl_8053CCA0;
    *(f32*)(p + 0x28c) = lbl_8053CCA0;
    *(f32*)(p + 0x290) = lbl_8053CCA0;
    *(f32*)(p + 0x294) = lbl_8053CCA0;
    *(f32*)(p + 0x298) = lbl_8053CCA0;
    return p;
}

extern "C" void fn_801D2608(void*, const char*, int);
extern "C" void fn_801D22DC(void*, int, int, int);
extern "C" void fn_801D1F14(void*, f32);
extern const f32 lbl_8053CCE8;
extern const f32 lbl_8053CCD8;
extern const f32 lbl_8053CCEC;
extern char lbl_80539F48[8];

extern "C" void fn_80131984(char* p) {
    *(s32*)(p + 0x274) = (*(u32*)(p + 0x90) >> 8) & 0xFF;
    *(s32*)(p + 0x270) = (*(u32*)(p + 0x90) >> 16) & 0xFF;
    *(f32*)(p + 0x60) = lbl_8053CCE8;
    *(f32*)(p + 0x64) = lbl_8053CCE8;
    *(f32*)(p + 0x68) = lbl_8053CCD8;
    *(f32*)(p + 0x6c) = lbl_8053CCEC;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = lbl_8053CCA0;
    *(f32*)(p + 0x84) = lbl_8053CCA0;
    *(f32*)(p + 0x88) = lbl_8053CCA0;
    *(f32*)(p + 0x8c) = lbl_8053CCA0;
    *(s32*)(p + 0x108) = 0;
    *(s32*)(p + 0xb0) = 0x50303;
    fn_801D2608(p + 0x230, lbl_80539F48, 1);
    fn_801D22DC(p + 0x230, 0, 2, 0);
    fn_801D1F14(p + 0x230, lbl_8053CCA0);
    *(f32*)(p + 0x284) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x288) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x28c) = *(f32*)(p + 0x14);
}

struct WpcnDrawKey {
    s32 a, b;
    WpcnDrawKey() { a = -1; b = -1; }
};
struct WpcnDrawParam {
    u8 map[16];      // 0x00
    WpcnDrawKey key; // 0x10
    void* c;         // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    WpcnDrawParam() {
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
extern const char lbl_8046513C[];
extern const f32 lbl_8053CCC0;
extern const f32 lbl_8053CCA8;
extern "C" void fn_801F02BC(void* this_, const char* name, void* id, WpcnDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);

extern "C" void fn_8013123C(char* p) {
    WpcnDrawParam param;
    f32 m[3][4];
    param.color = 1;
    f32 one = lbl_8053CCC0;
    f32 zero = lbl_8053CCA0;
    m[0][3] = zero;
    m[1][3] = zero;
    m[2][3] = zero;
    m[0][0] = one;
    m[0][1] = zero;
    m[0][2] = zero;
    m[1][0] = zero;
    m[1][1] = one;
    m[1][2] = zero;
    m[2][0] = zero;
    m[2][1] = zero;
    m[2][2] = one;
    param.c = m;
    fn_801F02BC(p, lbl_8046513C, *(char**)(p + 0x240) + 0x14c, &param, 0x407, 1, 0, lbl_8053CCA8, lbl_8053CCA8);
}

#include "JSystem/JGeometry/Vec.h"
typedef JGeometry::TVec3<f32> WpcnVec;
extern const f32 lbl_8053CCDC;
extern const f32 lbl_8053CCB4;
extern const f32 lbl_8053CCE0;
extern const f32 lbl_8053CCCC;
extern char* lbl_8053AAF8;
extern void* lbl_8053AD70;
extern char* lbl_8053AB10;
extern "C" void fn_80230FD0(s32 player, u32 id);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern "C" void fn_8037AE00(void* p);
extern "C" void fn_8037AE30(void* p);
extern "C" WpcnVec* fn_8023E32C(s32 i);
extern "C" WpcnVec* fn_8023E724(s32 i);
extern "C" u8 fn_80230360(s32 i);
extern "C" void fn_80230498(s32 i, const WpcnVec& pos, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" u16 fn_8023CBC0(s32 i);
extern "C" void fn_802F601C(void* mgr, WpcnVec* pos, s32 a, s32 b, f32 c, f32 d);
extern "C" s32 fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230534(s32 i);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* mgr, s32 a, s32 b);
extern "C" void fn_80136798(void* game, s32 a, s32 b);
extern "C" void fn_8023077C(void);

static inline bool wpcnAllActive() {
    for (s32 i = 0; i < 4; i++) {
        if (!fn_80230360(i)) {
            return false;
        }
    }
    return true;
}

extern "C" void fn_80130FAC(char* p, s32 state) {
    s32 i;
    *(s32*)(p + 0x268) = state;
    switch (*(s32*)(p + 0x268)) {
    case 1:
        fn_80230FD0(*(s32*)(p + 0x26c), 0x20035);
        break;
    case 2:
        *(f32*)(p + 0x27c) = lbl_8053CCDC;
        fn_80230FD0(0, 0x20036);
        fn_80134DE4(lbl_8053AAF8, 1, 0);
        fn_8037AE00(lbl_8053AD70);
        break;
    case 3:
        *(WpcnVec*)(p + 0x290) = *fn_8023E32C(0);
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                if (!fn_80230360(j)) {
                    goto skip;
                }
            }
            *(s32*)(p + 0x278) = 0;
        skip:
            for (j = 0; j < 4; j++) {
                fn_80230498(j, *(WpcnVec*)(p + 0x290), 0xb0, 0, -0x80, -0x80, 1);
            }
        }
        break;
    case 4:
        for (i = 0; i < 4; i++) {
            s32 id = fn_8023CBC0(i);
            fn_80230498(i, *fn_8023E724(i), id, 0xff, -0x80, -0x80, 1);
        }
        for (i = 0; i < 4; i++) {
            fn_80230FD0(i, 0x10003);
        }
        *(f32*)(p + 0x27c) = lbl_8053CCB4;
        fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), (WpcnVec*)(p + 0x290), 1, 0, lbl_8053CCA8, lbl_8053CCE0);
        fn_8013CC50(0, p + 0x290, lbl_8053CCA8, 0x17d, 1, 0, 0, 0, 1);
        break;
    case 6:
        fn_80230534(0);
        fn_802D9FF4(fn_802D6A9C(), *(s32*)(p + 0x270), *(s32*)(p + 0x274));
        fn_80136798(lbl_8053AAF8, 0xd, 0);
        fn_8037AE30(lbl_8053AD70);
        break;
    case 7:
        fn_8023077C();
        *(s32*)(p + 0x278) = 0;
        for (i = 0; i < 4; i++) {
            WpcnVec pos(*fn_8023E724(i));
            pos.z = lbl_8053CCCC;
            fn_80230498(i, pos, 0xb0, 0xff, -0x80, -0x80, 1);
        }
        *(f32*)(p + 0x27c) = lbl_8053CCA0;
        break;
    case 8:
        fn_80230534(0);
        *(u8*)(p + 0x11c) = 0;
        break;
    }
}

#include "JSystem/JGeometry/Box.h"
typedef JGeometry::TBox2<f32> WpcnBox;
extern const f32 lbl_8053CCA4;
extern const f32 lbl_8053CCAC;
extern const f32 lbl_8053CCB0;
extern const f32 lbl_8053CCB8;
extern const f32 lbl_8053CCBC;
extern const f32 lbl_8053CCC4;
extern const f32 lbl_8053CCC8;
extern const f32 lbl_8053CCD0;
extern const f32 lbl_8053CCD4;
extern const f32 lbl_8053CCE4;
extern "C" u8 fn_8023B0F4(s32 i, WpcnBox* box, s32 room, s32 a, f32 r);
extern "C" u8 fn_80230188(s32 i);
extern "C" void fn_802308E0(s32 i);
extern "C" s32 fn_801CD950(f32* v, f32 target, f32 step);
extern "C" char* fn_80119DD0(void);
extern "C" void fn_801D1C18(void* p);

static inline bool wpcnAllReady() {
    for (s32 i = 0; i < 4; i++) {
        if (!fn_80230188(i)) {
            return false;
        }
    }
    return true;
}

static inline bool wpcnBounce(char* p) {
    static s32 sCount = 0;
    static f32 sT = lbl_8053CCA0;
    sT += lbl_8053CCA4;
    if (sT >= lbl_8053CCA8) {
        sT = lbl_8053CCA8;
    }
    sCount++;
    f32 dy;
    if (sT <= lbl_8053CCB8) {
        dy = lbl_8053CCAC * (lbl_8053CCB0 - sT);
    } else {
        dy = lbl_8053CCB4 * (lbl_8053CCB8 - sT);
    }
    WpcnVec d(lbl_8053CCA0, dy, lbl_8053CCA0);
    ((WpcnVec*)(p + 0xc))->add(d);
    if (*(f32*)(p + 0x10) < *(f32*)(p + 0x288)) {
        *(f32*)(p + 0x10) = *(f32*)(p + 0x288);
    }
    if (sT >= lbl_8053CCA8 && sCount >= 30) {
        sCount = 0;
        sT = lbl_8053CCA0;
        return true;
    }
    return false;
}

extern "C" void fn_801313BC(char* p) {
    switch (*(s32*)(p + 0x268)) {
    case 0: {
        WpcnBox box = *(WpcnBox*)(p + 0x60);
        box.addPos(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - *(f32*)(p + 0x14));
        s32 i;
        for (i = 0; i < 4; i++) {
            if ((*(u8*)(lbl_8053AAF8 + 0x82) & (u8)(1 << i)) &&
                fn_8023B0F4(i, &box, *(s32*)(p + 0x4), 0, lbl_8053CCD4) && !fn_80230188(i) &&
                *(s32*)(p + 0x26c) < 0) {
                goto found;
            }
        }
        i = -1;
    found:
        if (i >= 0) {
            *(s32*)(p + 0x26c) = i;
            fn_80130FAC(p, 1);
        }
        if (wpcnAllReady()) {
            fn_80130FAC(p, 2);
        }
        break;
    }
    case 1:
        fn_802308E0(*(s32*)(p + 0x26c));
        bool up;
        *(f32*)(p + 0x280) += lbl_8053CCBC;
        {
            WpcnVec d(lbl_8053CCA0, lbl_8053CCC0 * (lbl_8053CCB0 - *(f32*)(p + 0x280)), lbl_8053CCA0);
            ((WpcnVec*)(p + 0xc))->add(d);
        }
        if (*(f32*)(p + 0x10) < *(f32*)(p + 0x288)) {
            *(f32*)(p + 0x10) = *(f32*)(p + 0x288);
        }
        if (*(f32*)(p + 0x280) >= lbl_8053CCA8) {
            *(f32*)(p + 0x280) = lbl_8053CCA8;
            up = true;
        } else {
            up = false;
        }
        if (up) {
            *(s32*)(p + 0x26c) = -1;
            fn_80130FAC(p, 0);
        }
        break;
    case 2:
        fn_801CD950((f32*)(p + 0x27c), lbl_8053CCC4, lbl_8053CCC8);
        for (s32 i = 0; i < 4; i++) {
            WpcnVec pos(*fn_8023E724(i));
            pos.y -= *(f32*)(p + 0x27c);
            fn_80230498(i, pos, 0xb0, 0xff, -0x80, -0x80, 1);
        }
        if (wpcnBounce(p)) {
            fn_80130FAC(p, 3);
        }
        break;
    case 3:
        (*(s32*)(p + 0x278))++;
        if (*(s32*)(p + 0x278) >= 60) {
            fn_80130FAC(p, 4);
        }
        break;
    case 4:
        fn_801CD950((f32*)(p + 0x27c), lbl_8053CCC4, lbl_8053CCD0);
        for (s32 i = 0; i < 4; i++) {
            WpcnVec pos(*fn_8023E724(i));
            fn_801CD950(&pos.z, lbl_8053CCD4, *(f32*)(p + 0x27c));
            fn_80230498(i, pos, 0xb0, 0xff, -0x80, -0x80, 1);
        }
        if (fn_8023E724(0)->z >= lbl_8053CCCC) {
            fn_80130FAC(p, 6);
        }
        break;
    case 5:
        fn_801CD950((f32*)(p + 0x27c), lbl_8053CCC4, lbl_8053CCD0);
        for (s32 i = 0; i < 4; i++) {
            WpcnVec pos(*fn_8023E724(i));
            fn_801CD950(&pos.z, lbl_8053CCD4, *(f32*)(p + 0x27c));
            fn_80230498(i, pos, 0xb0, 0xff, -0x80, -0x80, 1);
        }
        if (*(f32*)(fn_80119DD0() + 0x14) >= lbl_8053CCE4) {
            fn_80130FAC(p, 6);
        }
        break;
    case 6:
        fn_80130FAC(p, 7);
        break;
    case 7: {
        fn_801CD950((f32*)(p + 0x27c), lbl_8053CCC4, lbl_8053CCC8);
        u8 done = 0;
        for (s32 i = 0; i < 4; i++) {
            WpcnVec pos(*fn_8023E724(i));
            if (fn_801CD950(&pos.z, lbl_8053CCA0, *(f32*)(p + 0x27c)) == 0) {
                done = 1;
            }
            fn_80230498(i, pos, 0xb0, 0xff, -0x80, -0x80, 1);
        }
        if (done) {
            fn_80130FAC(p, 8);
        }
        break;
    }
    case 8:
        break;
    }
    fn_801D1C18(p + 0x230);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
