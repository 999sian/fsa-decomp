// TU 0x803944c8-0x803a3484.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// String scratch buffers (snprintf/strcat targets).
static char lbl_8050E518[0x10];
static char lbl_8050E528[0x10];
static char lbl_8050E538[0x10];
static char lbl_8050E548[0x10];

// ---- from src/Game/fn_80396F94.cpp ----
extern "C" void update__Q28JMessage8TControlFv(void* subObj);
extern "C" void fn_80396884(void* this_);
extern "C" void fn_80395BE8(void* this_);

// fn_80396F94 - leading helper: calls update__Q28JMessage8TControlFv(this->0x8), then
// fn_80396884(this), then fn_80395BE8(this), then sets this->0x3b0=1
// (a "done" latch).
extern "C" void fn_80396F94(void* this_) {
    update__Q28JMessage8TControlFv(*(void**)((char*)this_ + 0x8));
    fn_80396884(this_);
    fn_80395BE8(this_);
    *(u8*)((char*)this_ + 0x3b0) = 1;
}

// ---- from src/Game/fn_80397328_dtor.cpp ----
extern "C" void __dt__Q28JMessage18TSequenceProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF774[];

extern "C" void* fn_80397328(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF774;
        __dt__Q28JMessage18TSequenceProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80397388_dtor.cpp ----
extern "C" void __dt__Q28JMessage10TReferenceFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6D4[];

extern "C" void* fn_80397388(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6D4;
        __dt__Q28JMessage10TReferenceFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_803986A0_dtor.cpp ----
extern "C" void __dt__Q28JMessage19TRenderingProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6E4[];

extern "C" void* fn_803986A0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6E4;
        __dt__Q28JMessage19TRenderingProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/ClearIndirectFlags_0x2c0_0x2c4.cpp ----
// component C: 3 tiny vtable-slot/helper functions bundled.
extern "C" {
void fn_8039FE54(void* thisPtr) {
	void* p1 = *(void**)((char*)thisPtr + 0x2c0);
	*(u8*)p1 = 0;
	void* p2 = *(void**)((char*)thisPtr + 0x2c4);
	*(u8*)p2 = 0;
}

void fn_8039FE6C(void) {}

int fn_8039FE70(void) { return 1; }
}

// ---- from src/Game/stub_8039a510.cpp ----
// fn_8039A510 - component B vtable slot: advances a byte counter
// (this->0x281), then uses the counter as a byte offset from `this` to
// write 2 fields (a copy of this->0x22c, then a zero) at that
// dynamically-offset location. Each use re-reads the counter from
// memory rather than caching it, matching retail's own reload pattern.
extern "C" void fn_8039A510(void* thisObj) {
	u8* base = (u8*)thisObj;
	base[0x281] = base[0x281] + 1;
	base[base[0x281] + 0x202] = base[0x22c];
	base[base[0x281] + 0x257] = 0;
}

// ---- small helpers near the end of the TU (0x803A2BC4-0x803A3258) ----
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7E5C(void* mgr, s32 a, s32 b);
extern "C" void fn_802D7EB0(void* mgr, s32 a, s32 b, s32 c);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_8043D874(void* p, s32 a, s32 b, s32 c);
extern void* lbl_8053AD78;
extern void* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern u8 lbl_8050EC80[];
extern u8 lbl_80529DEC[];

extern "C" {
void fn_803A2BC4(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(u8*)(*(char**)(p + 0x60) + 0x3af) = 0;
    char* q = *(char**)(p + 0x60);
    if (*(u8*)(q + 0x1aa) == 0) {
        *(u8*)(q + 0x3ae) = 8;
    } else {
        *(u8*)(q + 0x3ae) = 3;
    }
}

void fn_803A2BF8(void* thisPtr) { *(u8*)((char*)thisPtr + 0x5c) = 1; }

void fn_803A2C04(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x58) = 0;
    *(u8*)(p + 0x5d) = 0;
    char* q = *(char**)(p + 0x60);
    *(s32*)(q + 0x150) = 0;
    *(u8*)(q + 0x19e) = 0xff;
    *(s32*)(*(char**)(p + 0x60) + 0x15c) = 0;
    *(u8*)(*(char**)(p + 0x60) + 0x3af) = 1;
    q = *(char**)(p + 0x60);
    *(s32*)(q + 0x16c) = 0;
    *(u8*)(q + 0x1a0) = 0;
    *(u8*)(q + 0x1a1) = 0;
    *(s32*)(q + 0x168) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x148) = -1;
    *(u8*)(*(char**)(p + 0x60) + 0x1a9) = 0;
    *(s32*)(*(char**)(p + 0x60) + 0x174) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x13c) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x140) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x144) = -1;
    q = *(char**)(p + 0x60);
    if (*(u8*)(q + 0x1aa) == 0) {
        *(u8*)(q + 0x3ae) = 7;
    } else {
        *(u8*)(q + 0x3ae) = 2;
    }
}

void fn_803A2CB0(void* thisPtr, u8 kind, s32 mode) {
    s32* w = (s32*)((char*)thisPtr + 0x50);
    switch (kind) {
    case 1: if (mode == 1) *w += 10; else *w += 11; break;
    case 2: if (mode == 1) *w += 6; else *w += 7; break;
    case 3: if (mode == 1) *w += 6; else *w += 8; break;
    case 4: if (mode == 1) *w += 5; else *w += 6; break;
    case 5: if (mode == 1) *w += 7; else *w += 8; break;
    case 6: if (mode == 1) *w += 6; else *w += 8; break;
    case 7: if (mode == 1) *w += 5; else *w += 6; break;
    case 8: if (mode == 1) *w += 7; else *w += 8; break;
    case 9: if (mode == 1) *w += 12; else *w += 14; break;
    }
    *w += 1;
}

void fn_803A2E48(void* thisPtr, s32 n) {
    s32* w = (s32*)((char*)thisPtr + 0x50);
    u8 started = 0;
    if (n < 0) {
        *w += 1;
        n *= -1;
    }
    s32 r = n % 10000;
    if (n / 10000 != 0) {
        *w += 1;
        started = 1;
    }
    s32 d = r / 1000;
    r = r % 1000;
    if (d != 0 || started) {
        *w += 1;
        started = 1;
    }
    d = r / 100;
    r = r % 100;
    if (d != 0 || started) {
        *w += 1;
        started = 1;
    }
    d = r / 10;
    if (d != 0 || started) {
        *w += 1;
    }
    *w += 1;
}

void fn_803A2F74(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x58) = 0;
    *(u8*)(p + 0x5d) = 0;
    (*(s32*)(*(char**)(p + 0x60) + 0x15c))++;
    char* q = *(char**)(p + 0x60);
    *(s32*)(q + 0x150) = 0;
    *(u8*)(q + 0x19e) = 0xff;
    *(s32*)(*(char**)(p + 0x60) + 0x148) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x13c) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x140) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x144) = -1;
    *(u8*)(*(char**)(p + 0x60) + 0x3ae) = 2;
}

s32 fn_803A2FE0(void) { return *(s32*)((char*)lbl_8053AD78 + 0x10c); }
void fn_803A2FEC(void) { *(s32*)((char*)lbl_8053AD78 + 0x44) = 0; }
void fn_803A2FFC(void) { *(u8*)((char*)lbl_8053AD78 + 0xe9) = 0; }
u8 fn_803A300C(void) { return *(u8*)((char*)lbl_8053AD78 + 0xe9); }
u16 fn_803A3018(void) { return *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x36); }
u16 fn_803A3034(void) { return *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x34); }
s32 fn_803A3050(void* p) { return *(s32*)((char*)p + 0x17c); }
s32 fn_803A3058(void* p) { return *(s32*)((char*)p + 0x178); }
s16 fn_803A3060(void* p) { return *(s16*)((char*)p + 0x192); }
s16 fn_803A3068(void* p) { return *(s16*)((char*)p + 0x190); }
void fn_803A3070(void* p, s32 v) { *(s32*)((char*)p + 0x174) = v; }
void fn_803A3078(void* p) { *(u8*)((char*)p + 0x3b1) = 0; }
void fn_803A3084(void* p, s32 i, s32 v) { ((s32*)((char*)p + 0x180))[i] = v; }
s32 fn_803A3094(void* p) { return *(s32*)((char*)p + 0x14c); }
s32 fn_803A309C(void* p) { return *(s32*)((char*)p + 0x3bc); }
void fn_803A30A4(void* p, u8 a, s32 b) {
    *(s32*)((char*)p + 0x150) = b;
    *(u8*)((char*)p + 0x19e) = a;
}
void fn_803A30B0(void* p) { *(u8*)((char*)p + 0x1a9) = 1; }
s32 fn_803A30BC(void* p) { return *(s32*)((char*)p + 0x160); }
void fn_803A30C4(void* p) { *(u8*)((char*)p + 0x1a0) = 3; }
void fn_803A30D0(void* p) { *(u8*)((char*)p + 0x1a1) = 1; }
void fn_803A30DC(void* p, s32 v) { *(s32*)((char*)p + 0x148) = v; }
void fn_803A30E4(void* p) { *(u8*)((char*)p + 0x1a1) = 0; }
void fn_803A30F0(void* p) { *(u8*)((char*)p + 0x1a0) = 2; }
void fn_803A30FC(void* p, s32 i, s32 v) { ((s32*)((char*)p + 0x13c))[i] = v; }
s32 fn_803A310C(void* p) { return *(s32*)((char*)p + 0x16c); }
void fn_803A3114(void* p) {
    if (*(u8*)((char*)p + 0x1a0) == 0) {
        (*(s32*)((char*)p + 0x168))++;
    }
    (*(s32*)((char*)p + 0x16c))++;
}
u8 fn_803A313C(void* p) { return *(u8*)((char*)p + 0x1aa); }
void fn_803A3144(void) { fn_80138B7C(lbl_8053AAF8); }
void fn_803A3168(s32 a, s32 b) { fn_802D7E5C(fn_802D6A9C(), a, b); }
void fn_803A31AC(s32 a, s32 b, s32 c) { fn_802D7EB0(fn_802D6A9C(), a, b, c); }
s32 fn_803A3200(void) { return *(s32*)(lbl_80529DEC + 0x11c); }
s32 fn_803A3210(void) { return *(s32*)(lbl_80529DEC + 0x118); }
s32 fn_803A3220(void* p) { return *(s32*)((char*)p + 0x280); }
void fn_803A3228(s32 a, s32 b, s32 c) { fn_8043D874(lbl_8053AED0, a, b, c); }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
