// TU 0x80427d2c-0x8042e964.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/Dtor_lbl804B15D0_80427F60.cpp ----
// fn_80427F60 - lbl_804B15D0: destructor. Reinstalls the base vtable,
// calls own virtual slot 0 (byte offset 0x8) on this->0x4/0x8/0xc if
// set, clearing each afterward, then conditionally forwards to
// __dl__FPv. See [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this calls through a real `virtual` member rather than a
// manual cast.
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B15D0[];

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_80427F60(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B15D0;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80428030_ctor.cpp ----
class SubObj_8042B12C {
public:
    SubObj_8042B12C();
private:
    unsigned char pad[0x13f8];
};

class SubObj_8042ADC0 {
public:
    SubObj_8042ADC0();
private:
    unsigned char pad[0x64380];
};

class SubObj_8042A7FC {
public:
    SubObj_8042A7FC();
private:
    unsigned char pad[0x64378];
};

extern void* lbl_804B15D0[];

extern "C" void* fn_80428030(void* this_) {
    char* p = (char*)this_;
    *(void**)p = lbl_804B15D0;
    SubObj_8042B12C* obj1 = new SubObj_8042B12C();
    *(SubObj_8042B12C**)(p + 0x4) = obj1;
    SubObj_8042ADC0* obj2 = new SubObj_8042ADC0();
    *(SubObj_8042ADC0**)(p + 0x8) = obj2;
    SubObj_8042A7FC* obj3 = new SubObj_8042A7FC();
    *(SubObj_8042A7FC**)(p + 0xc) = obj3;
    return this_;
}

// ---- from src/Game/fn_804281FC.cpp ----
// fn_804281FC + fn_8042828C + fn_80428294 - 3 helpers bundled.
// fn_804281FC(a,b,c,d): if fn_804286A0(a,b,c,d) succeeds, forwards a
// chained lookup (fn_8042828C(fn_80428294())) plus 4 offset-adjusted
// args to fn_804288A0, then calls fn_80428A88().
extern "C" u8 fn_804286A0(s32 a, s32 b, s32 c, s32 d);
extern "C" void* fn_80428294(void);
extern "C" s32 fn_8042828C(void* p);
extern "C" void fn_804288A0(s32 x, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_80428A88(void);

extern void* sManager__8JUTVideo;
extern s32 lbl_8053AEA4;
extern s32 lbl_8053AEA8;
extern s32 lbl_8052BEC0[];

extern "C" void fn_804281FC(s32 a, s32 b, s32 c, s32 d) {
    if (fn_804286A0(a, b, c, d)) {
        fn_804288A0(fn_8042828C(fn_80428294()), lbl_8053AEA4 + a, lbl_8053AEA8 + b, lbl_8052BEC0[0] + c, lbl_8052BEC0[1] + d);
        fn_80428A88();
    }
}

extern "C" s32 fn_8042828C(void* p) {
    return *(s32*)((char*)p + 0x4);
}

extern "C" void* fn_80428294(void) {
    return sManager__8JUTVideo;
}

// ---- from src/Game/fn_804283B0.cpp ----
extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, int flag);

// fn_804283B0(this) - helper: free__7JKRHeapFPvP7JKRHeap(this, 0).
extern "C" void fn_804283B0(void* this_) {
    free__7JKRHeapFPvP7JKRHeap(this_, 0);
}
