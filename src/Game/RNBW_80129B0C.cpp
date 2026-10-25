// RNBW_80129B0C: .text 0x80129B0C-0x8012A5EC (actor RNBW)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#define Vec SDKVec
#include "JSystem/JGeometry/Vec.h"
#undef Vec
#include "Game/Actor.h"

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* manager, s32 kind);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern u16 lbl_80465098[];
extern u16 lbl_804650A4[];
extern f32 lbl_8053CB48;
extern f32 lbl_8053CB4C;
extern f32 lbl_8053CB50;
extern f32 lbl_8053CB54;
extern f32 lbl_8053CB58;

// ---- from Game/Rnbw_ctor_8012A364.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E610[];

extern "C" void* fn_8012A364(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E610;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = -1;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(s32*)((char*)this_ + 0x240) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    return this_;
}

extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void fn_801EE434(void* handle);
struct RnbwActor {
    u8 pad[0x23c];
    void* mHandles[5];
    void release(int i) { fn_801EE434(mHandles[i]); mHandles[i] = 0; }
};

inline void releaseHandle(void*& h) { fn_801EE434(h); h = 0; }

extern "C" void fn_80129B0C(void* this_) {
    Actor* actor = (Actor*)this_;
    actor->Actor::v03();
    s32 state = *(s32*)((char*)this_ + 0x238);
    switch (state) {
    case 0:
        if ((u8)actor->v11()) {
            *(s32*)((char*)this_ + 0x238) = 1;
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39f, 0, -1, 0, 0, 1);
                s32 i = 0;
                void** hp = (void**)this_;
                u16* idp = lbl_80465098;
                do {
                    if (hp[0x8f] == 0) {
                        hp[0x8f] = fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, *idp, 0, -1, 0, 0, 1);
                    }
                    i++;
                    idp++;
                    hp++;
                } while (i < 5);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x3a0, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39b, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39c, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39d, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39e, 0, -1, 0, 0, 1);
            } else {
                u16* idp = lbl_804650A4;
                void** hp = (void**)this_;
                s32 i = 0;
                do {
                    if (hp[0x8f] == 0) {
                        hp[0x8f] = fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, *idp, 0, -1, 0, 0, 1);
                    }
                    i++;
                    idp++;
                    hp++;
                } while (i < 5);
            }
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_801F0E34(this_, 0x5004d, 0);
                *(s32*)((char*)this_ + 0x234) = 0;
            }
        }
        break;
    case 1:
        break;
    }
}

extern "C" void fn_8012A008(void* this_) {
    Actor* actor = (Actor*)this_;
    actor->Actor::v01();
    *(s32*)((char*)this_ + 0x230) = (*(u32*)((char*)this_ + 0x90) >> 22) & 0x1f;
    if ((u8)actor->v11()) {
        *(s32*)((char*)this_ + 0x238) = 1;
        switch (*(s32*)((char*)this_ + 0x238)) {
        case 1:
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39f, 0, -1, 0, 0, 1);
                s32 i = 0;
                void** hp = (void**)this_;
                u16* idp = lbl_80465098;
                do {
                    if (hp[0x8f] == 0) {
                        hp[0x8f] = fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, *idp, 0, -1, 0, 0, 1);
                    }
                    i++;
                    idp++;
                    hp++;
                } while (i < 5);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x3a0, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39b, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39c, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39d, 0, -1, 0, 0, 1);
                fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, 0x39e, 0, -1, 0, 0, 1);
            } else {
                u16* idp = lbl_804650A4;
                void** hp = (void**)this_;
                s32 i = 0;
                do {
                    if (hp[0x8f] == 0) {
                        hp[0x8f] = fn_8013CC50(actor->field_04, &actor->field_0C, lbl_8053CB48, *idp, 0, -1, 0, 0, 1);
                    }
                    i++;
                    idp++;
                    hp++;
                } while (i < 5);
            }
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_801F0E34(this_, 0x5004d, 0);
                *(s32*)((char*)this_ + 0x234) = 0;
            }
            break;
        case 0:
        default:
            break;
        }
    }
    *(f32*)((char*)this_ + 0x60) = lbl_8053CB4C;
    *(f32*)((char*)this_ + 0x64) = lbl_8053CB50;
    *(f32*)((char*)this_ + 0x68) = lbl_8053CB54;
    *(f32*)((char*)this_ + 0x6c) = lbl_8053CB58;
    *(f32*)((char*)this_ + 0x70) = *(f32*)((char*)this_ + 0x60);
    *(f32*)((char*)this_ + 0x74) = *(f32*)((char*)this_ + 0x64);
    *(f32*)((char*)this_ + 0x78) = *(f32*)((char*)this_ + 0x68);
    *(f32*)((char*)this_ + 0x7c) = *(f32*)((char*)this_ + 0x6c);
    *(f32*)((char*)this_ + 0x80) = *(f32*)((char*)this_ + 0x60);
    *(f32*)((char*)this_ + 0x84) = *(f32*)((char*)this_ + 0x64);
    *(f32*)((char*)this_ + 0x88) = *(f32*)((char*)this_ + 0x68);
    *(f32*)((char*)this_ + 0x8c) = *(f32*)((char*)this_ + 0x6c);
}

extern "C" void* fn_8012A2E0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E610;
        void* zero = 0;
        s32 i = 0;
        void** handles = (void**)this_;
        for (; i < 5; i++) {
            fn_801EE434(handles[0x8f + i]);
            handles[0x8f + i] = zero;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
