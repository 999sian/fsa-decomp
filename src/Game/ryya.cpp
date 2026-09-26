// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A6690-801A8194 (RYYA). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/Saya_ForceStateRange_801A68A4.cpp
extern "C" void fn_801A68DC(void* this_);

// SAYA cluster, part 14/18 (56B). Vtable-slot wrapper directly invoking
// fn_801A68DC (the actor's other big body, landed alongside) when the
// state field is 0 or 1.
extern "C" void fn_801A68A4(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x260);
    switch (state) {
    case 0:
    case 1:
        fn_801A68DC(this_);
        break;
    }
}

// from src/Game/Saya_AdvanceCycleCounter_801A7C48.cpp
// SAYA cluster, part 17/18. Private cycle-counter helper called from
// fn_801A68DC - advances a wraparound counter (this->0x240) and, on
// specific values, records a state snapshot (this->0x250/0x254/0x234).
//
// A 6-way switch on this->0x250, where case 0 and case 5 share one
// block (the switch-shared-tail idiom, see project_fsa_phase4_kickoff.md).
// The shared block ends with a genuinely redundant re-check
// (`if (this->0x250 != 5) return; if (this->0x250 == 4) return;` -
// the second check can never be true given the first, since nothing
// modifies this->0x250 in between) that retail's own compiled output
// has too - kept honestly as-written rather than simplified away,
// since simplifying it would change the logic even though it happens
// to be unreachable in this specific call context; most likely a
// remnant of a shared helper checked against multiple possible
// "settled" states from other call sites. All `this->0x240` reads are
// written as separate fresh dereferences (never cached across
// statements) matching retail's own repeated-reload style, per this
// project's established this-relative-repeated-read rule. Landed
// clean on the first attempt.
extern "C" void fn_801A7C48(void* thisObj) {
	char* p = (char*)thisObj;
	if (*(s32*)(p + 0x234) != 0) return;
	s32 state = *(s32*)(p + 0x250);
	switch (state) {
	case 0:
	case 5:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 2;
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 7;
		if (*(s32*)(p + 0x240) < 4) return;
		if (*(s32*)(p + 0x250) != 5) return;
		if (*(s32*)(p + 0x250) == 4) return;
		*(s32*)(p + 0x250) = 4;
		*(s32*)(p + 0x234) = 0;
		*(s32*)(p + 0x240) = 0;
		return;
	case 1:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 0xc;
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 3;
		return;
	case 2:
		*(s32*)(p + 0x254) = 0xd - *(s32*)(p + 0x240);
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 3;
		if (*(s32*)(p + 0x240) != 0) return;
		*(s32*)(p + 0x250) = 0;
		return;
	case 3:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 0xa;
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 3;
		if (*(s32*)(p + 0x240) != 0) return;
		*(s32*)(p + 0x250) = 1;
		return;
	case 4:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240);
		*(s32*)(p + 0x234) = 0xf;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 1;
		return;
	}
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_8022B1C8(void);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_80458508(void* snd, s32 a);
extern void* lbl_804A2E30[];
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;

// RYYA destructor
extern "C" void* fn_801A7B98(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2E30;
        s32 kind = *(s32*)(this_ + 0x260);
        if (kind == 0 || kind == 1) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 4 || state == 5) {
                fn_8022B1C8();
                if (*(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
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

struct RyyaDrawParam {
    RyyaDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};
extern "C" void fn_801F06F0(void* this_, const char* table, s32 id, RyyaDrawParam* prm, f32 f1, f32 f2, s32 mode);
extern const char lbl_80468500[];
extern const f32 lbl_8053E628;
extern const f32 lbl_8053E62C;
extern const f32 lbl_8053E630;
struct RyyaTimer {
    u8 pad[0x10];
    u8 m10;
    u8 m11;
    u8 m12;
    u8 m13;
};
extern RyyaTimer* lbl_8053AF20;

inline void ryyaSetTime(s32 a, f32 b) {
    lbl_8053AF20->m11 = a;
    lbl_8053AF20->m12 = b;
    lbl_8053AF20->m13 |= 2;
}

inline void ryyaSetTime2(s32 t) {
    lbl_8053AF20->m11 = t / 60;
    lbl_8053AF20->m12 = lbl_8053E62C * (t % 60) / lbl_8053E630;
    lbl_8053AF20->m13 |= 2;
}

extern "C" void fn_801A6690(char* p) {
    switch (*(s32*)(p + 0x260)) {
    case 0:
    case 1: {
        RyyaDrawParam prm;
        prm.reset();
        if (*(s32*)(p + 0x250) != 1) {
            fn_801F06F0(p, lbl_80468500, *(s32*)(p + 0x254) + 0x303, &prm, lbl_8053E628, lbl_8053E628, -1);
        }
        if (*(s32*)(p + 0x258) >= 0) {
            lbl_8053AF20->m10 = *(s32*)(p + 0x25c);
            lbl_8053AF20->m13 |= 1;
            s32 t = *(s32*)(p + 0x258);
            lbl_8053AF20->m11 = t / 60;
            lbl_8053AF20->m12 = (s32)(lbl_8053E62C * (t - (t / 60) * 60) / lbl_8053E630);
            lbl_8053AF20->m13 |= 2;
        }
        break;
    }
    }
}

extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_8053E654;
extern const f32 lbl_8053E660;
extern const f32 lbl_8053E664;
extern const f32 lbl_8053E688;
extern const f32 lbl_8053E68C;

struct RyyaVT {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual u8 v11();
};

static inline void ryyaSetCycle(char* p, s32 st) {
    if (*(s32*)(p + 0x250) != st) {
        *(s32*)(p + 0x250) = st;
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x240) = 0;
    }
}

extern "C" void fn_801A7DD4(char* p) {
    *(f32*)(p + 0x60) = lbl_8053E660;
    *(f32*)(p + 0x64) = lbl_8053E660;
    *(f32*)(p + 0x68) = lbl_8053E664;
    *(f32*)(p + 0x6c) = lbl_8053E664;
    *(f32*)(p + 0x70) = lbl_8053E688;
    *(f32*)(p + 0x74) = lbl_8053E688;
    *(f32*)(p + 0x78) = lbl_8053E68C;
    *(f32*)(p + 0x7c) = lbl_8053E68C;
    *(f32*)(p + 0x80) = lbl_8053E660;
    *(f32*)(p + 0x84) = lbl_8053E660;
    *(f32*)(p + 0x88) = lbl_8053E664;
    *(f32*)(p + 0x8c) = lbl_8053E664;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x254) = 2;
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x26c) = -1;
    *(s32*)(p + 0x270) = -1;
    *(f32*)(p + 0x44) = lbl_8053E654;
    *(f32*)(p + 0x40) = lbl_8053E654;
    *(f32*)(p + 0x3c) = lbl_8053E654;
    *(s32*)(p + 0x264) = -1;
    *(s32*)(p + 0x268) = -1;
    *(s32*)(p + 0x250) = 0;
    ryyaSetCycle(p, 0);
    *(s32*)(p + 0x260) = *(u32*)(p + 0x90) & 0xf;
    if (((RyyaVT*)p)->v11()) {
        detach__5ActorFv(p);
        return;
    }
    switch (*(s32*)(p + 0x260)) {
    case 1:
        ryyaSetCycle(p, 1);
        *(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 0xc;
    case 0:
        if (((RyyaVT*)p)->v11()) {
            *(s32*)(p + 0x230) = 10;
        } else {
            *(s32*)(p + 0x230) = 0;
        }
        break;
    case 2:
        *(s32*)(p + 0x230) = 0xd;
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
