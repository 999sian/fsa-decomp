// ANHO_80102278: .text 0x80102278-0x8010307C (actor ANHO)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80102278_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C970[];

extern "C" void* fn_80102278(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C970;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F02BC(void* this_, const char* name, s32 idx, s32, s32, s32, s32, f32, f32);
extern "C" void fn_8043CB24(void* mgr, s32 t, s32 a, s32 b, s32 c, s32 d, f32, f32, f32);
extern char lbl_80463BB8[];
extern void* lbl_8053AED0;
extern const f32 lbl_8053C1A8;
extern const f32 lbl_8053C1AC;
extern const f32 lbl_8053C1B0;
extern const f32 lbl_8053C1B4;

extern "C" void fn_801022D8(char* p) {
    fn_801F02BC(p, lbl_80463BB8, 0x311 + ((u8*)p)[0x235] * 2 + *(s32*)(p + 0x238), 0, 0, 0, 0, lbl_8053C1A8, lbl_8053C1A8);
    if (*(s32*)(p + 0x230) == 4 || *(s32*)(p + 0x230) == 5 || *(s32*)(p + 0x230) == 6) {
        fn_8043CB24(lbl_8053AED0, *(s32*)(p + 0x240) / 60, 0xff, 0, 2, 1, lbl_8053C1AC, lbl_8053C1B0, lbl_8053C1B4);
    }
}

struct AnhoRandom {
    u32 seed;
    u32 get() {
        seed = seed * 0x19660d + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - lbl_8053C1A8;
    }
};
struct AnhoGame { u8 pad[0xb4]; AnhoRandom rnd; };
class AnhoVBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual bool isFlag();
};
extern AnhoGame* lbl_8053AAF8;
extern "C" u8 fn_80138A30(AnhoGame* game);
extern const f32 lbl_8053C1C4;
extern const f32 lbl_8053C1C8;
extern const f32 lbl_8053C1CC;

extern "C" void fn_80102D34(char* p) {
    *(f32*)(p + 0x60) = lbl_8053C1C4;
    *(f32*)(p + 0x64) = lbl_8053C1C4;
    *(f32*)(p + 0x68) = lbl_8053C1C8;
    *(f32*)(p + 0x6c) = lbl_8053C1C8;
    p[0x235] = 1;
    *(s32*)(p + 0x238) = 0;
    p[0x234] = 0;
    *(s32*)(p + 0x23c) = -1;
    p[0x236] = fn_80138A30(lbl_8053AAF8);
    *(s32*)(p + 0x24c) = (s32)(lbl_8053C1CC * lbl_8053AAF8->rnd.get_ufloat_1()) + 0x10;
    if (*(s32*)(p + 0x24c) == 0x14) {
        *(s32*)(p + 0x24c) = 0x13;
    }
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x280) = 0;
    if (((AnhoVBase*)p)->isFlag()) {
        *(s32*)(p + 0x230) = 7;
        *(s32*)(p + 0x244) = 0;
    } else {
        *(s32*)(p + 0x230) = 0;
        *(s32*)(p + 0x244) = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
