#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"

struct PopoGame {
    u8 pad[0xb4];
    JMARandFast rnd;
};
extern PopoGame* lbl_8053AAF8;

extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern const char lbl_80465B68[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_8049F3B0[];
extern "C" void* fn_80143874(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F3B0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801438D4(u8* this_) {
    fn_801F06F0(this_, lbl_80465B68, *(s32*)(this_ + 0x240) + 0x1a, 0, 0, 1.0f, 1.0f);
}

extern "C" s32 fn_801F3D94(void*, s32);
extern "C" u8 fn_801F305C(void*);
extern "C" u8 fn_801F2618(void*, void*, u8);
extern "C" u8 fn_801F2B7C(void*, s32, s32, s32);
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8022DCD8(s32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" u8 fn_801F23BC(void*, s32, void*, void*, void*, f32*, f32*, s32);
extern "C" void fn_80143914(u8* p) {
    if (fn_801F3D94(p, 1) != 0 || fn_801F305C(p)) {
        fn_801F2618(p, 0, 0);
        *(s32*)(p + 0x23c) = 0;
        if (*(s32*)(p + 0x230) != 0) {
            *(s32*)(p + 0x238) = 10;
            *(s32*)(p + 0x230) = 0;
        }
        return;
    }
    u8* timers = p;
    for (int i = 0; i < 3; i++) {
        if (*(s32*)(timers + 0x234) > 0) --*(s32*)(timers + 0x234);
        timers += 4;
    }
    if (*(s32*)(p + 0x23c) != 0) return;
    *(JGeometry::TVec3f*)(p + 0xc) += *(JGeometry::TVec3f*)(p + 0x3c);
    fn_801F2B7C(p, -100, -1, 1);
    u8 hit = fn_801F2618(p, 0, 0);
    switch (*(s32*)(p + 0x230)) {
    case 0:
        *(s32*)(p + 0x234) = 2;
        ((JGeometry::TVec3f*)(p + 0x3c))->scale(0.0f);
        if (*(s32*)(p + 0x238) == 0) {
            ++*(s32*)(p + 0x98);
            *(s32*)(p + 0x98) &= 1;
            switch (*(s32*)(p + 0x98)) {
            case 0: *(f32*)(p + 0x3c) = 1.0f; break;
            case 1: *(f32*)(p + 0x3c) = -1.0f; break;
            }
            PopoGame* game = lbl_8053AAF8;
            *(s32*)(p + 0x238) = 20 + (s32)(100.0f * game->rnd.get_ufloat_1());
            *(s32*)(p + 0x230) = 1;
        }
        break;
    case 1:
        if (hit || *(s32*)(p + 0x238) == 0) {
            PopoGame* game = lbl_8053AAF8;
            *(s32*)(p + 0x238) = 20 + (s32)(50.0f * game->rnd.get_ufloat_1());
            *(s32*)(p + 0x230) = 0;
        }
        s32 room;
        for (s32 i = 0; i < 4; i++) {
            if (!fn_8023F264(i)) continue;
            room = *(s32*)(p + 4);
            if (room != fn_8023DE58(i)) continue;
            if (fn_80230188(i)) continue;
            if (fn_8022DCD8(i)) continue;
            if (!((f32)__fabs(fn_8023E724(i)->x - *(f32*)(p + 0xc)) < 200.0f)) continue;
            if (!((f32)__fabs(fn_8023E724(i)->y - *(f32*)(p + 0x10)) < 40.0f)) continue;
            f32 out1[3], out2[3];
            if (!fn_801F23BC(p, *(s32*)(p + 4), p + 0xc, fn_8023E724(i), p + 0x80, out1, out2, 0)) {
                *(s32*)(p + 0x234) = 0;
                *(f32*)(p + 0x3c) = 2.0f;
                if (fn_8023E724(i)->x < *(f32*)(p + 0xc)) *(f32*)(p + 0x3c) = -2.0f;
                PopoGame* game = lbl_8053AAF8;
                *(s32*)(p + 0x238) = 50 + (s32)(100.0f * game->rnd.get_ufloat_1());
                *(s32*)(p + 0x230) = 2;
                break;
            }
        }
        break;
    case 2:
        if (hit || *(s32*)(p + 0x238) == 0) {
            PopoGame* game = lbl_8053AAF8;
            *(s32*)(p + 0x238) = (s32)(50.0f * game->rnd.get_ufloat_1());
            *(s32*)(p + 0x230) = 0;
        }
        break;
    }
    if (*(s32*)(p + 0x234) <= 0) {
        *(s32*)(p + 0x234) = 8;
        if (*(s32*)(p + 0x230) == 2) *(s32*)(p + 0x234) = 2;
        ++*(s32*)(p + 0x240);
        *(s32*)(p + 0x240) &= 1;
    }
}

extern "C" void fn_80143DD8(u8* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x98) = 0;
    PopoGame* g = lbl_8053AAF8;
    s32 r = (s32)(2.0f * g->rnd.get_ufloat_1());
    switch (r) {
    case 0:
        *(f32*)(this_ + 0x3c) = 1.0f;
        break;
    case 1:
        *(f32*)(this_ + 0x3c) = -1.0f;
        *(s32*)(this_ + 0x98) = 1;
        break;
    }
    *(s32*)(this_ + 0x234) = 0;
    PopoGame* g2 = lbl_8053AAF8;
    *(s32*)(this_ + 0x238) = (s32)(50.0f * g2->rnd.get_ufloat_1());
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x230) = 0;
}

void __sinit_PEAC_80143874_cpp(void) {
}

