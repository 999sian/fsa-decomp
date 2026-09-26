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


// ---- small leaf accessors and manager forwarders (0x8042E1E4-) ----
extern void* lbl_8053AE7C;
extern void* lbl_8053AE80;
extern void* lbl_8053AE84;
extern "C" void fn_80428524(void*, u32);
extern "C" void fn_8042E204(u32 a) { fn_80428524(lbl_8053AE7C, a); }
extern "C" void fn_8042852C(void*);
extern "C" void fn_8042E22C() { fn_8042852C(lbl_8053AE7C); }
extern "C" void fn_804285F4(void*, u32);
extern "C" void fn_8042E250(u32 a) { fn_804285F4(lbl_8053AE7C, a); }
extern "C" void fn_8042855C(void*);
extern "C" void fn_8042E278() { fn_8042855C(lbl_8053AE7C); }
extern "C" void fn_8042858C(void*, u32);
extern "C" void fn_8042E29C(u32 a) { fn_8042858C(lbl_8053AE7C, a); }
extern "C" void fn_8042ACCC(void*, u32);
extern "C" void fn_8042E2C4(u32 a) { fn_8042ACCC(lbl_8053AE80, a); }
extern "C" void fn_8042AD10(void*, u32);
extern "C" void fn_8042E2EC(u32 a) { fn_8042AD10(lbl_8053AE80, a); }
extern "C" void fn_8042A708(void*, u32);
extern "C" void fn_8042E314(u32 a) { fn_8042A708(lbl_8053AE84, a); }
extern "C" void fn_8042A74C(void*, u32);
extern "C" void fn_8042E33C(u32 a) { fn_8042A74C(lbl_8053AE84, a); }
extern "C" void fn_8042A3E4(void*);
extern "C" void fn_8042E364() { fn_8042A3E4(lbl_8053AE84); }
extern "C" void fn_8042A818(void*);
extern "C" void fn_8042E388() { fn_8042A818(lbl_8053AE80); }
extern "C" void fn_8042AF60(void*);
extern "C" void fn_8042E3AC() { fn_8042AF60(lbl_8053AE7C); }
extern "C" void fn_8042AFA4(void*);
extern "C" void fn_8042E3D0() { fn_8042AFA4(lbl_8053AE7C); }
extern "C" void fn_8042A428(void*);
extern "C" void fn_8042E3F4() { fn_8042A428(lbl_8053AE84); }
extern "C" void fn_8042A85C(void*);
extern "C" void fn_8042E418() { fn_8042A85C(lbl_8053AE80); }
extern "C" void fn_8042ADDC(void*, u32);
extern "C" void fn_8042E43C(u32 a) { fn_8042ADDC(lbl_8053AE7C, a); }
extern "C" void fn_8042B02C(void*, u32);
extern "C" void fn_8042E4C4(u32 a) { fn_8042B02C(lbl_8053AE7C, a); }
extern "C" void fn_8042A5E0(void*, u32);
extern "C" void fn_8042E4EC(u32 a) { fn_8042A5E0(lbl_8053AE84, a); }
extern "C" void fn_8042A534(void*, u32);
extern "C" void fn_8042E514(u32 a) { fn_8042A534(lbl_8053AE84, a); }
extern "C" void fn_8042A608(void*, u32);
extern "C" void fn_8042E53C(u32 a) { fn_8042A608(lbl_8053AE84, a); }
extern "C" void fn_8042AFD4(void*, u32);
extern "C" void fn_8042E564(u32 a) { fn_8042AFD4(lbl_8053AE7C, a); }
extern "C" void fn_8042B0AC(void*);
extern "C" void fn_8042E58C() { fn_8042B0AC(lbl_8053AE7C); }
extern "C" void fn_8042A6DC(void*, u32);
extern "C" void fn_8042E5B0(u32 a) { fn_8042A6DC(lbl_8053AE84, a); }
extern "C" void fn_8042A778(void*);
extern "C" void fn_8042E5D8() { fn_8042A778(lbl_8053AE84); }
extern "C" void fn_8042AAA8(void*, u32);
extern "C" void fn_8042E5FC(u32 a) { fn_8042AAA8(lbl_8053AE80, a); }
extern "C" void fn_8042A970(void*, u32);
extern "C" void fn_8042E624(u32 a) { fn_8042A970(lbl_8053AE80, a); }
extern "C" void fn_8042AB70(void*, u32);
extern "C" void fn_8042E64C(u32 a) { fn_8042AB70(lbl_8053AE80, a); }
extern "C" void fn_8042AFFC(void*);
extern "C" void fn_8042E674() { fn_8042AFFC(lbl_8053AE7C); }
extern "C" void fn_8042ACA0(void*, u32);
extern "C" void fn_8042E698(u32 a) { fn_8042ACA0(lbl_8053AE80, a); }
extern "C" void fn_8042AD3C(void*);
extern "C" void fn_8042E6C0() { fn_8042AD3C(lbl_8053AE80); }
extern "C" void fn_8042AE74(void*, u32);
extern "C" void fn_8042E6E4(u32 a) { fn_8042AE74(lbl_8053AE7C, a); }
extern "C" void fn_8042B084(void*, u32);
extern "C" void fn_8042E70C(u32 a) { fn_8042B084(lbl_8053AE7C, a); }
extern "C" void fn_8042B054(void*);
extern "C" void fn_8042E734() { fn_8042B054(lbl_8053AE7C); }

struct Obj8042E1E4 { u8 pad[0x1c]; u16 m1C; u8 pad2[2]; u32 m20; };
extern "C" void fn_8042E1E4(Obj8042E1E4* o, u16 v) { o->m1C = v; o->m20 = 0; }
extern void* sManager__10JFWDisplay;
extern "C" void* fn_8042E1F4() { return sManager__10JFWDisplay; }
extern "C" u16 fn_8042E1FC(Obj8042E1E4* o) { return o->m1C; }
extern "C" void fn_80428524(void* o, u32 v) { *(u32*)((char*)o + 4) = v; }
extern "C" void fn_80429DE0() {}
extern "C" void* fn_8042E780(void* o) { return *(void**)((char*)o + 8); }

#include "JSystem/JAudio/JASFakeMatchFSA.h"
