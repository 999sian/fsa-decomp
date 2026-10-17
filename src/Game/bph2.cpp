// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8018A8D8-8018EB94 (BPH2). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/Bph2_SetVec2.cpp
// BPH2 cluster, part 5 (final piece). fn_8018E964 - trivial 2-float
// setter, no extab entry (leaf).
extern "C" {

void fn_8018E964(void* thisPtr, f32 a, f32 b) { *(f32*)((char*)thisPtr + 0x0) = a; *(f32*)((char*)thisPtr + 0x4) = b; }

}

// Small (inline-style) accessors.
extern void* lbl_8053AAF8;
extern "C" void* fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* mgr, void* a, void* b, void* c);
extern "C" void fn_802D800C(void* mgr, void* a);

extern "C" void fn_8018E890(void) {}
extern "C" void fn_8018E894(char* this_, s32 v) { *(s32*)(this_ + 0x234) = v; }
extern "C" void* fn_8018E89C(void) { return fn_80138A30(lbl_8053AAF8); }
extern "C" void fn_8018E8C0(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
extern "C" void fn_8018E8DC(void* a, void* b, void* c) { fn_802D8050(fn_802D6A9C(), a, b, c); }
extern "C" void fn_8018E930(void* a) { fn_802D800C(fn_802D6A9C(), a); }

struct ActorVt_bph2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setShadow(s32 type, f32 x, f32 y);
};
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);

extern "C" void fn_8018A8D8(ActorVt_bph2* this_) {
    fn_801F0E34(this_, 0x40015, 0);
    this_->setShadow(2, 0.0f, 16.0f);
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern "C" void fn_8022ADCC(void);
extern void* lbl_804A1E50[];
extern "C" s32 fn_8023F264(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" s32 fn_8022F478(s32 idx);
extern "C" s32 fn_80230188(s32 idx);
extern "C" void fn_8023061C(s32 idx, s32 p);
extern f32 lbl_8053E0F8;
extern f32 lbl_8053E130;
extern f32 lbl_8053E140;
extern f32 lbl_8053E1B4;

// BPH2 destructor
extern "C" void* fn_8018D9D4(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1E50;
        fn_801EE434(*(void**)(this_ + 0x328));
        fn_801EE434(*(void**)(this_ + 0x32c));
        fn_801EE434(*(void**)(this_ + 0x330));
        if (*(s32*)(this_ + 0x26c) == 0) {
            fn_802D7440(fn_802D6A9C(), 1);
            fn_8022ADCC();
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

static u8 lbl_804C18B8[0xC];

#include "JSystem/JAudio/JASFakeMatchFSA.h"
