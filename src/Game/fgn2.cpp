// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80187144-8018A8D8 (FGN2). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/stub_8018a6a0.cpp
extern void* lbl_8053AF80[2];

// fn_8018A6A0(this, a, b) - trivial 2-float pair setter.
extern "C" void fn_8018A6A0(void* thisObj, f32 a, f32 b) {
	char* p = (char*)thisObj;
	*(f32*)(p + 0x0) = a;
	*(f32*)(p + 0x4) = b;
}

// fn_8018A6AC() - returns the global sound-bank pointer.
extern "C" void* fn_8018A6AC(void) {
	return lbl_8053AF80[0];
}

// Small (inline-style) accessors.
extern char* lbl_8053AAF8;
extern "C" void* fn_8013C824(void* a);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F6884(void* mgr);
extern "C" void* fn_801F68E0(void* mgr);

extern "C" void fn_8018A588(char* p, s32 v) { *(s32*)(p + 0x108) = v; }
extern "C" u16 fn_8018A590(char* p) { return *(u16*)(p + 0x94); }
extern "C" void fn_8018A598(char* p, u8 v) { *(u8*)(p + 0x11c) = v; }
extern "C" void fn_8018A5A0(char* p, s32 v) { *(s32*)(p + 0x98) = v; }
extern "C" void fn_8018A5A8(char* p, u16 v) { *(u16*)(p + 0x94) = v; }
extern "C" u8 fn_8018A5B0(char* p) { return *(u8*)(p + 0x11c); }
extern "C" void fn_8018A5B8(f32* v, f32 x, f32 y, f32 z) { v[0] = x; v[1] = y; v[2] = z; }
extern "C" void fn_8018A5C8(char* p, u8 v) { *(u8*)(p + 0xbb) = v; }
extern "C" void fn_8018A5D0(char* p) { *(u32*)(p + 0xf4) &= ~4; }
extern "C" void fn_8018A5E0(char* p) { *(u32*)(p + 0xf4) |= 4; }
extern "C" void* fn_8018A5F0(void* a) { return *(void**)((char*)fn_8013C824(a) + 0xc); }
extern "C" BOOL fn_8018A614(s32 bit) { return (*(u8*)(lbl_8053AAF8 + 0x82) & (u8)(1 << bit)) != 0; }
extern "C" void* fn_8018A63C(void) { return fn_801F6884(fn_801F856C()); }
extern "C" void* fn_8018A660(void) { return fn_801F68E0(fn_801F856C()); }
extern "C" void fn_8018A684(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

struct ActorVt_fgn2 {
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

extern "C" void fn_80187144(ActorVt_fgn2* this_) {
    fn_801F0E34(this_, 0x40047, 0);
    this_->setShadow(*(s8*)((char*)this_ + 0x2ee), 8.0f, -16.0f);
}

extern "C" s32 fn_8022EA0C(s32 idx);
extern "C" u8 fn_8023F264(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" u8 fn_80230188(s32 idx);
extern "C" u8 fn_80236B50(s32 idx);
extern "C" u8 fn_8022DCD8(s32 idx);
extern s32 lbl_8053AB78;
extern const f32 lbl_8053DFF4;
extern const f32 lbl_8053E050;
extern "C" u16 fn_80189DEC(char* this_) {
    s32 cur = fn_8022EA0C(*(u16*)(this_ + 0x94));
    s32 cand;
    s32 i;
    f32 f;
    u32 bits;
    char* rng;
    if (cur < 0) {
        cur = 0;
    }
    if (fn_8023F264(cur) != 0) {
        s32 h = *(s32*)(this_ + 0x4);
        if (h == fn_8023DE58(cur) && fn_80230188(cur) == 0 && fn_80236B50(cur) == 0 && lbl_8053AB78 != 1) {
            *(s16*)(this_ + 0x94) = cur;
            return *(u16*)(this_ + 0x94);
        }
    }
    rng = lbl_8053AAF8;
    *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
    bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
    f = *(f32*)&bits;
    cand = (s32)(lbl_8053E050 * (f - lbl_8053DFF4));
    for (i = 0; i < 4; i++) {
        if (cand != cur && fn_8023F264(cand) != 0) {
            s32 h = *(s32*)(this_ + 0x4);
            if (h == fn_8023DE58(cand) && fn_8022EA0C(cand) == cand && fn_80230188(cand) == 0 && fn_80236B50(cand) == 0 && fn_8022DCD8(cand) == 0) {
                *(s16*)(this_ + 0x94) = cand;
                if (lbl_8053AB78 == 1) {
                    *(s32*)(this_ + 0x27c) = *(u16*)(this_ + 0x94);
                }
                return *(u16*)(this_ + 0x94);
            }
        }
        cand = (cand + 1) & 3;
    }
    *(s16*)(this_ + 0x94) = cur;
    return *(u16*)(this_ + 0x94);
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern "C" void fn_8022ADCC(void);
extern "C" char* fn_801F666C(void* mgr, s32 handle);
extern void* lbl_804A1A98[];
struct Handles_fgn2 { u8 pad[0x2f4]; void* a[4]; void* b[4]; void* c; };

// FGN2 destructor
extern "C" void* fn_80189F74(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1A98;
        s32 h;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(((Handles_fgn2*)this_)->a[i]);
            fn_801EE434(((Handles_fgn2*)this_)->b[i]);
        }
        fn_801EE434(((Handles_fgn2*)this_)->c);
        if (*(u32*)(this_ + 0x90) == 0) {
            fn_802D7440(fn_802D6A9C(), 1);
            fn_8022ADCC();
        }
        if (*(u32*)(this_ + 0x90) == 10) {
            h = *(s32*)(this_ + 0x274);
            if (h >= 0) {
                char* c = fn_801F666C(fn_801F856C(), h);
                if (c != 0) {
                    *(f32*)(c + 0x28c) = 3.0f;
                    *(s32*)(this_ + 0x274) = -1;
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

static u8 lbl_804C17A8[0x10];

#include "JSystem/JAudio/JASFakeMatchFSA.h"
