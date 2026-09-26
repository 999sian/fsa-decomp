// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80192038-80197070 (GNON). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/GlobalMgr_GetByte_0x24f.cpp
// fn_80196DF0 - reads a byte at lbl_80529DEC->0x24f.
// fn_80196E00 - sets bit 0x10 in a byte at
// (*lbl_8053AED0)->0xdc. Retest of the batch-2
// "small-data-array" bug using the real 0x354-byte size from
// symbols.txt (the earlier attempt used an inexact 0x300 placeholder).
extern "C" {

extern u8 lbl_80529DEC[0x354];
extern void* lbl_8053AED0;

u8 fn_80196DF0(void) {
	return lbl_80529DEC[0x24f];
}

void fn_80196E00(void) {
	u8* p = (u8*)lbl_8053AED0;
	p[0xdc] |= 0x10;
}

}


// Small (inline-style) accessors.
extern void* lbl_8053AAF8;
extern "C" void fn_80134DE4(void* game, void* a, void* b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, void* a, void* b, f32 x, f32 y);

struct GnonVec { f32 x, y, z; };
extern "C" void fn_80196CF4(char* this_, const GnonVec* v) {
    *(GnonVec*)(this_ + 0x98) = *v;
    *(f32*)(this_ + 0xb0) = v->x;
    *(f32*)(this_ + 0xb4) = v->y;
}
extern "C" void fn_80196D18(char* this_, f32 x, f32 y) { *(f32*)(this_ + 0xb0) = x; *(f32*)(this_ + 0xb4) = y; }
extern "C" void fn_80196D24(f32* v, f32 x, f32 y) { v[0] = x; v[1] = y; }
extern "C" void fn_80196D30(void* a, void* b) { fn_80134DE4(lbl_8053AAF8, a, b); }
extern "C" void fn_80196D60(f32* v, f32 x, f32 y, f32 z) { v[0] = x; v[1] = y; v[2] = z; }
extern "C" void fn_80196D70(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
extern "C" void fn_80196D8C(void* a, void* b, f32 x, f32 y) { fn_802D79E8(fn_802D6A9C(), a, b, x, y); }

struct ActorVt_gnon {
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

extern "C" void fn_80192038(ActorVt_gnon* this_) {
    fn_801F0E34(this_, 0x40006, 0);
    this_->setShadow(2, 0.0f, 0.0f);
}

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);

struct Handles_gnon { u8 pad[0x328]; void* h[5]; };
// GNON destructor
extern void* lbl_804A25F0[];
extern "C" void* fn_80196834(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A25F0;
        for (int i = 0; i < 5; i++) {
            fn_801EE434(((Handles_gnon*)this_)->h[i]);
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
