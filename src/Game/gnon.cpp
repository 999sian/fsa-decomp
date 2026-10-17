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

extern "C" void __dt__5ActorFv(void* this_, int flag);
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
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8013CC50(u32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void* fn_8023E724(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" void fn_8022CA6C(s32 a, s32 b, s32 c);
extern "C" u8 fn_802317F0(s32 a, u32 b, void* c, void* d, s32 e);
extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022DCD8(s32 i);
extern "C" s32 fn_80237774(s32 i);
extern "C" s32 fn_80236228(s32 i);
extern f32 lbl_8053E284;
extern f32 lbl_8053E360;
extern f32 lbl_8053E298;
extern u32 lbl_804C1BC0[];
extern u8 lbl_804C1BD0[];

static inline void gnonReleaseHandle(u8** handle) {
    u8* h = *handle;
    if (h != 0) {
        *(u32*)(h + 0xf4) |= 1;
        *(s32*)(h + 0x24) = 1;
        *handle = 0;
    }
}
struct GnonTimers { u8 pad[0x234]; s32 t[10]; };

extern "C" void fn_80192BD8(char* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0x2c:
        *(s32*)(this_ + 0x234) = 0x32;
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x359, 0, 0, 0, 0, 1, 1.0f);
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x35a, 0, 0, 0, 0, 1, 1.0f);
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x35b, 0, 0, 0, 0, 1, 1.0f);
        *(s32*)(this_ + 0x230) = 0x2d;
    case 0x2d:
        if (*(s32*)(this_ + 0x234) == 0) {
            this_[0x11c] = 0;
        }
        break;
    }
    fn_801F2B7C(this_, -100, -1, 1);
    for (int i = 0; i < 10; i++) {
        if (((GnonTimers*)this_)->t[i] > 0) {
            ((GnonTimers*)this_)->t[i]--;
        }
    }
}

extern "C" void fn_80196020(char* this_, s32 idx) {
    if (idx < 0) {
        return;
    }
    if (*(s32*)(this_ + 0x268) < 0) {
        gnonReleaseHandle((u8**)(this_ + 0x328));
        gnonReleaseHandle((u8**)(this_ + 0x32c));
        gnonReleaseHandle((u8**)(this_ + 0x330));
        gnonReleaseHandle((u8**)(this_ + 0x334));
        gnonReleaseHandle((u8**)(this_ + 0x338));
        *(s32*)(this_ + 0x328) = fn_8013CC50(*(u32*)(this_ + 4), fn_8023E724(idx), 0x2a6, 0, 0, 0, 0, 1, lbl_8053E298);
        *(s32*)(this_ + 0x32c) = fn_8013CC50(*(u32*)(this_ + 4), fn_8023E724(idx), 0x2a7, 0, 0, 0, 0, 1, lbl_8053E298);
    }
    if (fn_8022F3DC(idx) >= 0) {
        idx = fn_8022F3DC(idx);
    }
    fn_8022CA6C(idx, 5, 0);
    if (fn_802317F0(idx, lbl_804C1BC0[idx], fn_8023E724(idx), lbl_804C1BD0 + idx * 12, 6)) {
        *(f32*)(this_ + 0x2a8) = lbl_8053E298;
        *(s32*)(this_ + 0x234) = 100;
        *(s32*)(this_ + 0x230) = 0x22;
    } else {
        *(s32*)(this_ + 0x230) = 0x21;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

