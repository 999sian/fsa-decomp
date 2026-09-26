// SHTM_80108A6C: .text 0x80108A6C-0x80109534 (actor SHTM)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80108A6C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CDC0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80108A6C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CDC0;
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

// ---- fn_80108AEC: draw
extern "C" void v06__5ActorFv(void* this_);
struct SHTM_DrawKey {
    s32 a, b;
    SHTM_DrawKey() { a = -1; b = -1; }
};
struct SHTM_DrawParam {
    u8 map[16];      // 0x00
    SHTM_DrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    SHTM_DrawParam() {
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
extern const char lbl_8046404C[];
extern const f32 lbl_8053C368;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, SHTM_DrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);

extern "C" void fn_80108AEC(u8* this_) {
    v06__5ActorFv(this_);
    SHTM_DrawParam param;
    fn_801F02BC(this_, lbl_8046404C, *(s32*)(this_ + 0x240) + 0x17B, &param, 7, 0, 0, lbl_8053C368, lbl_8053C368);
}

// ---- fn_801091EC: init
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern void* lbl_8049CDA0[];
extern const f32 lbl_8053C36C;
extern const f32 lbl_8053C370;
extern const f32 lbl_8053C374;
extern const f32 lbl_8053C378;

extern "C" void fn_801091EC(u8* this_) {
    v01__5ActorFv(this_);
    *(f32*)(this_ + 0x60) = lbl_8053C36C;
    *(f32*)(this_ + 0x64) = lbl_8053C36C;
    *(f32*)(this_ + 0x68) = lbl_8053C370;
    *(f32*)(this_ + 0x6C) = lbl_8053C370;
    *(f32*)(this_ + 0x80) = lbl_8053C36C;
    *(f32*)(this_ + 0x84) = lbl_8053C36C;
    *(f32*)(this_ + 0x88) = lbl_8053C370;
    *(f32*)(this_ + 0x8C) = lbl_8053C370;
    *(s32*)(this_ + 0x108) = 0;
    *(s32*)(this_ + 0x268) = *(u32*)(this_ + 0x90) & 0xFF;
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0xC);
    *(f32*)(this_ + 0x27C) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x280) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x27C) -= lbl_8053C374;
    fn_801D2608(this_ + 0x230, lbl_8049CDA0, 8);
    fn_801D22DC(this_ + 0x230, *(s32*)(this_ + 0x268), 2, 0);
    fn_801D1F14(this_ + 0x230, lbl_8053C378);
}

// ---- from Game/fn_801092B0_ctor.cpp

struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);
extern void* lbl_8049CDC0[];

class fn_801092B0_actor : public Actor {
public:
    fn_801092B0_actor();
};

fn_801092B0_actor::fn_801092B0_actor() : Actor() {
    *(void**)this = lbl_8049CDC0;
    char* p = (char*)this;
    fn_801D267C(p + 0x230);
    *(s32*)(p + 0x268) = 8;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = -1;
    *(s32*)(p + 0x274) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
