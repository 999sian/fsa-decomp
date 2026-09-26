// TU 0x80427d2c-0x8042e964.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include <dolphin/os.h>
#include <dolphin/vi.h>
#include <string.h>


struct Obj8042E1E4 { u8 pad[0x1c]; u16 m1C; u8 pad2[2]; u32 m20; };




extern "C" s32 fn_80427D2C(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_80427D60();
extern "C" s32 fn_80427D94();
extern "C" s32 fn_80427DB4(void* a, s32 b);
extern "C" s32 fn_80427DD4(s32, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_80427E08();
extern "C" s32 fn_80427E28();
extern "C" s32 fn_80427E58(void* this_, s32 idx);
extern "C" void* fn_80427F34(s32 i);
extern "C" void* fn_80427F60(void* this_, s16 flag);
extern "C" void* fn_80428030(void* this_);
extern "C" void fn_804280C0(f32 v);
extern "C" s32 fn_80428134();
extern "C" void fn_804281FC(s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8042828C(void* p);
extern "C" void* fn_80428294(void);
extern "C" s32 fn_8042829C();
extern "C" void fn_804283B0(void* this_);
extern "C" void fn_804283D4();
extern "C" u8 fn_8042840C();
extern "C" u8 fn_80428448();
extern "C" void fn_80428524(void* o, u32 v);
extern "C" u8 fn_8042852C(void* p);
extern "C" void fn_8042855C(void* p);
extern "C" u8 fn_8042858C(void* p, u32 prio);
extern "C" void* fn_804285F4(void*, u32);
extern "C" u8 fn_80428630();
extern "C" bool fn_804286A0(s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_804287DC();
extern "C" u32 fn_804287EC();
extern "C" s32 fn_80428810(void* dst);
extern "C" s32 fn_80428858(void* dst);
extern "C" void fn_80429DE0();
extern "C" void fn_8042E1E4(Obj8042E1E4* o, u16 v);
extern "C" void* fn_8042E1F4();
extern "C" u16 fn_8042E1FC(Obj8042E1E4* o);
extern "C" void fn_8042E204(u32 a);
extern "C" u8 fn_8042E22C();
extern "C" void fn_8042E250(u32 a);
extern "C" void fn_8042E278();
extern "C" u8 fn_8042E29C(u32 a);
extern "C" void fn_8042E2C4(u32 a);
extern "C" void fn_8042E2EC(u32 a);
extern "C" void fn_8042E314(u32 a);
extern "C" void fn_8042E33C(u32 a);
extern "C" void fn_8042E364();
extern "C" void fn_8042E388();
extern "C" void fn_8042E3AC();
extern "C" void fn_8042E3D0();
extern "C" void fn_8042E3F4();
extern "C" void fn_8042E418();
extern "C" void fn_8042E43C(u32 a);
extern "C" void fn_8042E4C4(u32 a);
extern "C" void fn_8042E4EC(u32 a);
extern "C" void fn_8042E514(u32 a);
extern "C" void fn_8042E53C(u32 a);
extern "C" void fn_8042E564(u32 a);
extern "C" void fn_8042E58C();
extern "C" void fn_8042E5B0(u32 a);
extern "C" void fn_8042E5D8();
extern "C" void fn_8042E5FC(u32 a);
extern "C" void fn_8042E624(u32 a);
extern "C" void fn_8042E64C(u32 a);
extern "C" void fn_8042E674();
extern "C" void fn_8042E698(u32 a);
extern "C" void fn_8042E6C0();
extern "C" void fn_8042E6E4(u32 a);
extern "C" void fn_8042E70C(u32 a);
extern "C" void fn_8042E734();
extern "C" void* fn_8042E780(void* o);
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


// ---- from src/Game/fn_804281FC.cpp ----
// fn_804281FC + fn_8042828C + fn_80428294 - 3 helpers bundled.
// fn_804281FC(a,b,c,d): if fn_804286A0(a,b,c,d) succeeds, forwards a
// chained lookup (fn_8042828C(fn_80428294())) plus 4 offset-adjusted
// args to fn_804288A0, then calls fn_80428A88().
extern "C" void fn_804288A0(s32 x, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_80428A88(void);

extern void* sManager__8JUTVideo;
extern s32 lbl_8053AEA4;
extern s32 lbl_8053AEA8;
extern u32 lbl_8052BEC0[];




// ---- from src/Game/fn_804283B0.cpp ----
extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, int flag);



// ---- small leaf accessors and manager forwarders (0x8042E1E4-) ----
extern void* lbl_8053AE7C;
extern void* lbl_8053AE80;
extern void* lbl_8053AE84;
extern "C" void fn_8042ACCC(void*, u32);
extern "C" void fn_8042AD10(void*, u32);
extern "C" void fn_8042A708(void*, u32);
extern "C" void fn_8042A74C(void*, u32);
extern "C" void fn_8042A3E4(void*);
extern "C" void fn_8042A818(void*);
extern "C" void fn_8042AF60(void*);
extern "C" void fn_8042AFA4(void*);
extern "C" void fn_8042A428(void*);
extern "C" void fn_8042A85C(void*);
extern "C" void fn_8042ADDC(void*, u32);
extern "C" void fn_8042B02C(void*, u32);
extern "C" void fn_8042A5E0(void*, u32);
extern "C" void fn_8042A534(void*, u32);
extern "C" void fn_8042A608(void*, u32);
extern "C" void fn_8042AFD4(void*, u32);
extern "C" void fn_8042B0AC(void*);
extern "C" void fn_8042A6DC(void*, u32);
extern "C" void fn_8042A778(void*);
extern "C" void fn_8042AAA8(void*, u32);
extern "C" void fn_8042A970(void*, u32);
extern "C" void fn_8042AB70(void*, u32);
extern "C" void fn_8042AFFC(void*);
extern "C" void fn_8042ACA0(void*, u32);
extern "C" void fn_8042AD3C(void*);
extern "C" void fn_8042AE74(void*, u32);
extern "C" void fn_8042B084(void*, u32);
extern "C" void fn_8042B054(void*);

extern void* sManager__10JFWDisplay;


// ---- THP movie player core (0x80427D2C-) ----
struct THPPlayerState {
    u8 pad0[0x50];
    u32 m50;
    u8 pad54[0x80 - 0x54];
    u8 videoInfo[0xc];
    u8 audioInfo[0x10];
    u8 pad9C[0xa0 - 0x9c];
    u8 open;
    u8 state;
    u8 internalState;
    u8 padA3[0xc0 - 0xa3];
    u32 initReadFrame;
    u8 padC4[0xf0 - 0xc4];
    u32 mF0;
    u32 mF4;
    struct { u8 pad[0xc]; u32 frameNumber; }* dispTextureSet;
    u32 mFC;
};
extern THPPlayerState lbl_8052AAD0;
extern u8 lbl_8053AEBD;
extern u8 lbl_8053AEBC;
extern u16 lbl_8053AEBE;
extern s32 lbl_8053AEB8;
extern void* lbl_8053AEB4;
extern void* lbl_8053AEAC;
extern void* lbl_8053AE90;
extern void* lbl_804B15C0[];
extern "C" void fn_80428978();
extern "C" void fn_80429400();
extern "C" void fn_80429748();
extern "C" u8 fn_80429454(void*, s32);
extern "C" s32 fn_80428C6C();
extern "C" void fn_80428A28();
extern "C" void fn_80428CBC();


















































struct RenderModeHolder { u8 pad[4]; u16 fbWidth; u16 efbHeight; };
extern u32 lbl_8052BECC[];
extern u32 lbl_8053AEB0;
extern "C" void fn_804291F0(void*);
extern "C" u8 fn_80428AC8(s32, s32);
extern "C" void fn_804286B4(s32, s32);
extern "C" void fn_80429784(s32);
extern "C" void* fn_8042E758();
extern "C" void* alloc__7JKRHeapFUli(void*, u32, int);
























































































































































































extern "C" s32 fn_80427D2C(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (lbl_8053AEBD) {
        return 0;
    }
    return fn_80427DD4(a, b, c, d, e);
}

extern "C" s32 fn_80427D60() {
    if (lbl_8053AEBD) {
        return 0;
    }
    return fn_80427E08();
}

extern "C" s32 fn_80427D94() { return fn_80427E28(); }

extern "C" s32 fn_80427DB4(void* a, s32 b) { return fn_80427E58(a, b); }

extern "C" s32 fn_80427DD4(s32, s32 a, s32 b, s32 c, s32 d) {
    fn_804281FC(a, b, c, d);
    return 1;
}

extern "C" s32 fn_80427E08() { return fn_8042829C(); }

extern "C" s32 fn_80427E28() {
    fn_8042E1E4((Obj8042E1E4*)fn_8042E1F4(), lbl_8053AEBE);
    fn_804283D4();
    return 1;
}

extern "C" s32 fn_80427E58(void* this_, s32 idx) {
    lbl_8053AEBE = fn_8042E1FC((Obj8042E1E4*)fn_8042E1F4());
    fn_8042E1E4((Obj8042E1E4*)fn_8042E1F4(), 1);
    lbl_8053AEBD = 0;
    *(void**)((char*)this_ + 0x10) = (void*)fn_80428134;
    *(void**)((char*)this_ + 0x14) = (void*)fn_804280C0;
    *(void**)((char*)this_ + 0x18) = (void*)fn_804287EC;
    void* p = fn_80427F34(idx);
    if (p) {
        lbl_8053AEB4 = p;
        if (!fn_8042840C()) {
            lbl_8053AEBD = 1;
            return 0;
        }
        return 1;
    }
    lbl_8053AEB4 = fn_80427F34(0);
    if (!fn_8042840C()) {
        lbl_8053AEBD = 1;
        return 0;
    }
    return 1;
}

extern "C" void* fn_80427F34(s32 i) {
    if (i >= 0 && i < 4) {
        return lbl_804B15C0[i];
    }
    return 0;
}

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

extern "C" void fn_804280C0(f32 v) {
    if (!lbl_8053AEBD) {
        s32 vol;
        if (v >= 1.0f) {
            vol = 0x7f;
        } else if (v <= 0.0f) {
            vol = 0;
        } else {
            vol = v / 127.0f;
        }
        fn_804286B4(vol, 0);
    }
}

extern "C" s32 fn_80428134() {
    if (lbl_8053AEBD || fn_804287DC() == 5) {
        return 0;
    }
    u32 frame;
    if (lbl_8052AAD0.open && lbl_8052AAD0.dispTextureSet) {
        frame = (lbl_8052AAD0.dispTextureSet->frameNumber + lbl_8052AAD0.initReadFrame) % lbl_8052AAD0.m50;
    } else {
        return -1;
    }
    u32 n = fn_804287EC();
    if (n == 0) {
        return 0;
    }
    if (n <= 1) {
        return 0;
    }
    n--;
    return frame >= n ? 0 : n - frame;
}

extern "C" void fn_804281FC(s32 a, s32 b, s32 c, s32 d) {
    if (fn_804286A0(a, b, c, d)) {
        fn_804288A0(fn_8042828C(fn_80428294()), lbl_8053AEA4 + a, lbl_8053AEA8 + b, lbl_8052BEC0[0] + c, lbl_8052BEC0[1] + d);
        fn_80428A88();
    }
}

#pragma dont_inline on
extern "C" s32 fn_8042828C(void* p) {
    return *(s32*)((char*)p + 0x4);
}
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_80428294(void) {
    return sManager__8JUTVideo;
}
#pragma dont_inline off

extern "C" s32 fn_8042829C() {
    if (lbl_8053AEB8 == 0) {
        if (fn_8042E22C()) {
            fn_8042E204(0);
            if (lbl_8053AEBC) {
                return 0;
            }
            if (!fn_80428448()) {
                return 0;
            }
            lbl_8053AEB8 = 1;
        }
    } else if (lbl_8053AEB8 == 1) {
        switch (fn_80428C6C()) {
        case 0:
            return 0;
        case 1:
            lbl_8052AAD0.internalState = 0;
            lbl_8052AAD0.state = 1;
            lbl_8052AAD0.dispTextureSet = 0;
            lbl_8052AAD0.mFC = 0;
            lbl_8052AAD0.mF0 = 0;
            lbl_8052AAD0.mF4 = 0;
            lbl_8053AE90 = (void*)VISetPostRetraceCallback((VIRetraceCallback)fn_80428CBC);
            fn_80428A28();
            lbl_8053AEB8 = 2;
            break;
        }
    } else if (fn_804287DC() == 5) {
        fn_80428978();
        fn_80429400();
        if (lbl_8053AEAC) {
            fn_804283B0(lbl_8053AEAC);
        }
        return 0;
    }
    return 1;
}

// fn_804283B0(this) - helper: free__7JKRHeapFPvP7JKRHeap(this, 0).
extern "C" void fn_804283B0(void* this_) {
    free__7JKRHeapFPvP7JKRHeap(this_, 0);
}

#pragma dont_inline on
extern "C" void fn_804283D4() {
    fn_80428978();
    fn_80429400();
    fn_80429748();
    if (lbl_8053AEAC) {
        fn_804283B0(lbl_8053AEAC);
    }
}
#pragma dont_inline off

extern "C" u8 fn_8042840C() {
    lbl_8053AEB8 = 0;
    lbl_8053AEBC = 0;
    return fn_80428630() != 0;
}

extern "C" u8 fn_80428448() {
    fn_80428858(lbl_8052BEC0);
    fn_80428810(lbl_8052BECC);
    lbl_8053AEA4 = (((RenderModeHolder*)fn_8042828C(fn_80428294()))->fbWidth - lbl_8052BEC0[0]) >> 1;
    lbl_8053AEA8 = (((RenderModeHolder*)fn_8042828C(fn_80428294()))->efbHeight - lbl_8052BEC0[1]) >> 1;
    fn_804291F0(lbl_8053AEAC);
    u32 r;
    if (lbl_8052BECC[3] != 1) {
        r = OSGetTick() % lbl_8052BECC[3];
    } else {
        r = 0;
    }
    lbl_8053AEB0 = r;
    if (!fn_80428AC8(0, 0)) {
        return 0;
    }
    return 1;
}

extern "C" void fn_80428524(void* o, u32 v) { *(u32*)((char*)o + 4) = v; }

extern "C" u8 fn_8042852C(void* p) {
    return OSIsThreadTerminated((OSThread*)((char*)p + 0xe0)) != 0;
}

extern "C" void fn_8042855C(void* p) {
    if (*(s32*)((char*)p + 4)) {
        OSResumeThread((OSThread*)((char*)p + 0xe0));
    }
}

extern "C" u8 fn_8042858C(void* p, u32 prio) {
    if (!OSCreateThread((OSThread*)((char*)p + 0xe0), (void*(*)(void*))fn_8042E250, 0, (char*)p + 0x13f8, 0x1000, prio, 1)) {
        return 0;
    }
    *(s32*)((char*)p + 4) = 1;
    return 1;
}

extern "C" void* fn_804285F4(void*, u32) {
    if (!fn_80429454(lbl_8053AEB4, 0)) {
        lbl_8053AEBC = 1;
    }
    return 0;
}

extern "C" u8 fn_80428630() {
    fn_80429784(0);
    lbl_8053AEAC = alloc__7JKRHeapFUli(fn_8042E758(), 0x1c0000, 0x20);
    if (!lbl_8053AEAC) {
        return 0;
    }
    if (!fn_8042E29C(OSGetThreadPriority(OSGetCurrentThread()) + 1)) {
        return 0;
    }
    fn_8042E278();
    return 1;
}

extern "C" bool fn_804286A0(s32 a, s32 b, s32 c, s32 d) {
    return lbl_8053AEB8 == 2;
}

extern "C" s32 fn_804287DC() { return lbl_8052AAD0.state; }

extern "C" u32 fn_804287EC() {
    if (lbl_8052AAD0.open) {
        return lbl_8052AAD0.m50;
    }
    return 0;
}

extern "C" s32 fn_80428810(void* dst) {
    if (lbl_8052AAD0.open) {
        memcpy(dst, lbl_8052AAD0.audioInfo, 0x10);
        return 1;
    }
    return 0;
}

extern "C" s32 fn_80428858(void* dst) {
    if (lbl_8052AAD0.open) {
        memcpy(dst, lbl_8052AAD0.videoInfo, 0xc);
        return 1;
    }
    return 0;
}

extern "C" void fn_80429DE0() {}

#pragma dont_inline on
extern "C" void fn_8042E1E4(Obj8042E1E4* o, u16 v) { o->m1C = v; o->m20 = 0; }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_8042E1F4() { return sManager__10JFWDisplay; }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u16 fn_8042E1FC(Obj8042E1E4* o) { return o->m1C; }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E204(u32 a) { fn_80428524(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u8 fn_8042E22C() { return fn_8042852C(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E250(u32 a) { fn_804285F4(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E278() { fn_8042855C(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u8 fn_8042E29C(u32 a) { return fn_8042858C(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E2C4(u32 a) { fn_8042ACCC(lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E2EC(u32 a) { fn_8042AD10(lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E314(u32 a) { fn_8042A708(lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E33C(u32 a) { fn_8042A74C(lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E364() { fn_8042A3E4(lbl_8053AE84); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E388() { fn_8042A818(lbl_8053AE80); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E3AC() { fn_8042AF60(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E3D0() { fn_8042AFA4(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E3F4() { fn_8042A428(lbl_8053AE84); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E418() { fn_8042A85C(lbl_8053AE80); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E43C(u32 a) { fn_8042ADDC(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E4C4(u32 a) { fn_8042B02C(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E4EC(u32 a) { fn_8042A5E0(lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E514(u32 a) { fn_8042A534(lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E53C(u32 a) { fn_8042A608(lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E564(u32 a) { fn_8042AFD4(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E58C() { fn_8042B0AC(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E5B0(u32 a) { fn_8042A6DC(lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E5D8() { fn_8042A778(lbl_8053AE84); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E5FC(u32 a) { fn_8042AAA8(lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E624(u32 a) { fn_8042A970(lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E64C(u32 a) { fn_8042AB70(lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E674() { fn_8042AFFC(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E698(u32 a) { fn_8042ACA0(lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E6C0() { fn_8042AD3C(lbl_8053AE80); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E6E4(u32 a) { fn_8042AE74(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E70C(u32 a) { fn_8042B084(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E734() { fn_8042B054(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_8042E780(void* o) { return *(void**)((char*)o + 8); }
#pragma dont_inline off

#include "JSystem/JAudio/JASFakeMatchFSA.h"
