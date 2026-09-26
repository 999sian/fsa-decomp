// POPO (Poppo?) actor. TU 80172170-80172894.
// Functions: dtor, draw (slot 6), update (slot 3, not yet decompiled), init (slot 1).
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);
extern void* lbl_804A0868[];

struct PopoGame { u8 pad[0xb4]; JMARandFast rnd; };
extern PopoGame* lbl_8053AAF8;

// POPO destructor
extern "C" void* fn_80172170(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0868;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// POPO draw (vtable slot 6)
extern "C" void fn_801721D0(char* this_) {
    fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x24c) + 0x99, 1.0f, 1.0f, 0, 0);
}

extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, void* out, s32 a);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);

// Direct sin/cos table reads (the retail code does not use the JMath inline
// member functions here; calling them changes the function emission order).
static inline f32 popoSin(s16 v) { return JMath::sincosTable_.mTable[(u16)v >> 5].first; }
static inline f32 popoCos(s16 v) { return JMath::sincosTable_.mTable[(u16)v >> 5].second; }
// POPO update (vtable slot 3)
extern "C" void fn_80172210(char* this_) {
    if (*(u32*)(this_ + 0x90) == 1) {
        if (*(f32*)(this_ + 0x14) > 0.0f) {
            *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 1.0f;
            if (*(f32*)(this_ + 0x44) < -10.0f) {
                *(f32*)(this_ + 0x44) = -10.0f;
            }
            ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
            return;
        }
        *(f32*)(this_ + 0x14) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        *(u32*)(this_ + 0xb0) = 0x11101;
        *(u32*)(this_ + 0x90) = 0;
    }
    if (fn_801F3D94(this_, 1) != 0 || fn_801F305C(this_)) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x250), 0.3f, 1.0f);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x254), 0.3f, 1.0f);
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    fn_801F2B7C(this_, -100, -1, 1);
    fn_801F2618(this_, 0, 0);
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if (*(s32*)(this_ + 0x238) == 0) {
        PopoGame* g = lbl_8053AAF8;
        *(s32*)(this_ + 0x238) = (s32)(10.0f * g->rnd.get_ufloat_1()) + 10;
        *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) + 1;
        *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) & 1;
        if (*(s32*)(this_ + 0x240) == 0) {
            PopoGame* g1 = lbl_8053AAF8;
            *(f32*)(this_ + 0x250) = 0.5f * popoSin((s16)(s32)(65536.0f * g1->rnd.get_ufloat_1()));
            PopoGame* g2 = lbl_8053AAF8;
            *(f32*)(this_ + 0x254) = 0.5f * popoCos((s16)(s32)(65536.0f * g2->rnd.get_ufloat_1()));
        } else {
            *(f32*)(this_ + 0x250) = 0.0f;
            *(f32*)(this_ + 0x254) = 0.0f;
            *(f32*)(this_ + 0x258) = 0.0f;
        }
        }
        break;
    }
    if (*(s32*)(this_ + 0x234) == 0) {
        *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) + 1;
        *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) & 3;
        *(s32*)(this_ + 0x234) = 8;
    }
    for (int i = 0; i < 3; i++) {
        if (*(s32*)(this_ + i * 4 + 0x234) > 0) {
            (*(s32*)(this_ + i * 4 + 0x234))--;
        }
    }
}

// POPO init (vtable slot 1)
extern "C" void fn_80172530(char* this_) {
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 0xff;
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x250) = 0.0f;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0x11101;
    PopoGame* g = lbl_8053AAF8;
    *(s32*)(this_ + 0x240) = (s32)(1.99f * g->rnd.get_ufloat_1());
    PopoGame* g2 = lbl_8053AAF8;
    *(s32*)(this_ + 0x238) = (s32)(10.0f * g2->rnd.get_ufloat_1()) + 10;
    if (*(u32*)(this_ + 0x90) == 1) {
        *(u32*)(this_ + 0xb0) = 0;
    }
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
