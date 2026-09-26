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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
