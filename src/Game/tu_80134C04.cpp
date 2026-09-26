// tu_80134C04: .text 0x80134C04-0x80139BE8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/oscluster_80134dc0.cpp

extern "C" {

// fn_80134DC0(this) - a byte-flag toggle: this->0x86 = !this->0x86.
void fn_80134DC0(void* thisPtr)
{
    char* t = (char*)thisPtr;
    if (*(u8*)(t + 0x86) == 0) {
        *(u8*)(t + 0x86) = 1;
    } else {
        *(u8*)(t + 0x86) = 0;
    }
}

} // extern "C"

// ---- from Game/DiscErrorStateSetter_80134DE4.cpp

extern "C" void* fn_8008E328(s32 p1);
extern "C" void fn_8008E1FC(void* p1, void* p2, s32 p3, s32 p4);

extern u8 lbl_80529DEC[];
extern u8 lbl_8049ED88[];

// fn_80134DE4(this, code, param) - a "set disc-error/status code" method.
// No-op if the boot-config struct's byte (lbl_80529DEC->0x246, the SAME
// struct main() itself reads/writes) is 0. Otherwise re-fetches the DVD
// drive status object (fn_8008E328) and dispatches on `code`: 1-4 set a
// fixed retry-wait timer; 5-9 display a disc-error message string via
// fn_8008E1FC (each code picks a different message-table entry) then set
// a follow-up code; 10 uses `param` (or a default); anything else stores
// `code` verbatim.
extern "C" void fn_80134DE4(void* this_, s32 code, s32 param) {
    char* t = (char*)this_;
    u8* msgTable = lbl_8049ED88;
    if (*(u8*)(lbl_80529DEC + 0x246) == 0) {
        return;
    }

    char* drive = (char*)fn_8008E328(0);
    *(s32*)(t + 0x10c) = 0;

    if (code == 1) {
        *(s32*)(t + 0x108) = 0x1e;
    } else if (code == 2) {
        *(s32*)(t + 0x108) = 0x3c;
    } else if (code == 3) {
        *(s32*)(t + 0x108) = 0x5a;
    } else if (code == 4) {
        *(s32*)(t + 0x108) = 0x78;
    } else if (code == 5) {
        fn_8008E1FC(drive + 0x68, msgTable + 0xd0, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x41a;
    } else if (code == 6) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x158, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 7) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x168, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 8) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x178, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 9) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x188, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 10) {
        s32 val10 = param;
        if (param == 0) {
            val10 = 0x78;
        }
        *(s32*)(t + 0x108) = val10;
    } else {
        *(s32*)(t + 0x108) = code;
    }
}

// ---- from Game/oscluster_80134fbc.cpp

extern "C" {

// fn_80134FBC(this, val) - trivial setter, this->0x96 = val.
// fn_80134FC4(this, val) - setter with a side effect: this->0x94 = val;
// if the new value isn't 1, also sets this->0x95 = 1 (a "changed away
// from mode 1" latch).
void fn_80134FBC(void* thisPtr, u8 val)
{
    *(u8*)((char*)thisPtr + 0x96) = val;
}

void fn_80134FC4(void* thisPtr, u8 val)
{
    char* t = (char*)thisPtr;
    *(u8*)(t + 0x94) = val;
    if (*(u8*)(t + 0x94) != 1) {
        *(u8*)(t + 0x95) = 1;
    }
}

} // extern "C"


// ---- small accessors ----
extern char* lbl_8053AB10;
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern "C" void fn_80458658(void*, s32);
extern "C" void fn_80021840(void);
extern "C" void fn_802AC8AC(void*, s32);
extern void* lbl_8053ACA0;

extern "C" void fn_80134CC0(void* this_, s32 v) { *(s32*)((char*)this_ + 0x108) = v; }

extern "C" BOOL fn_80134CC8(char* this_) {
    bool ok;
    if (*(s32*)(this_ + 0x4c) == 0xb) {
        ok = TRUE;
    } else {
        ok = *(u8*)(this_ + 0x88) == 2;
    }
    if (ok) {
        return *(u8*)(*(char**)(lbl_8053AB10 + 0x2c) + 0xc) == 0;
    }
    return FALSE;
}

extern "C" void fn_80134D14(void*, u8 v) { *(u8*)(lbl_8053AAF8 + 0x88) = v; }

extern "C" void fn_80134FE0(u8* this_, u8 v) {
    this_[0x94] = v;
    if (this_[0x94] == 1) {
        fn_80458658(lbl_8053AF80, this_[0x94]);
    } else {
        this_[0x95] = 1;
    }
}

extern "C" BOOL fn_80136320(char* this_) {
    if (lbl_8053AAF8 != 0) {
        s32 m = *(s32*)(this_ + 0x4c);
        if (m == 0 || (u32)(m - 1) <= 5 || m == 9 || m == 0xc) {
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" void fn_801365A8(void) { fn_80021840(); }

extern "C" void fn_801365C8(char* this_, u8 v) {
    this_[0xfe] = v;
    if (v == 1) {
        this_[0xfc] = 0;
        *(s32*)(this_ + 0xf8) = 0;
    }
}

struct BootCfg_80529DEC { u8 pad[0x118]; s32 m118, m11C, m120, m124; u8 pad2[0x237 - 0x128]; u8 m237; u8 pad3[0x24b - 0x238]; u8 m24B; };
#define sBootCfg (*(BootCfg_80529DEC*)lbl_80529DEC)
extern "C" void fn_802AC980(void*);

extern "C" void fn_801365E8(char* this_, s32 a, s32 b, s32 c) {
    *(s32*)(this_ + 0x50) = 7;
    *(s32*)(this_ + 0x58) = 1;
    fn_802AC8AC(lbl_8053ACA0, c);
    sBootCfg.m118 = a;
    sBootCfg.m11C = b;
    this_[0x84] = 1;
}

extern "C" void fn_8013665C(char* this_, s32 a, s32 b) {
    *(s32*)(this_ + 0x50) = 7;
    *(s32*)(this_ + 0x58) = 1;
    fn_802AC8AC(lbl_8053ACA0, 0);
    sBootCfg.m118 = a;
    sBootCfg.m11C = b;
    this_[0x84] = 1;
    if (a == 10 && b == 2) {
        if (*(s32*)(this_ + 0x4c) == 9) {
            sBootCfg.m24B = 2;
        } else {
            sBootCfg.m24B = 1;
        }
        sBootCfg.m237 = 7;
    }
}

extern "C" void fn_8013670C(char* this_, s32 a) {
    *(s32*)(this_ + 0x60) = 0;
    *(s32*)(this_ + 0x64) = 0;
    if (sBootCfg.m118 == 10 && sBootCfg.m11C == 2) {
        sBootCfg.m118 = sBootCfg.m120;
        sBootCfg.m11C = sBootCfg.m124;
        sBootCfg.m237 = 7;
    }
    *(s32*)(this_ + 0x50) = a;
    *(s32*)(this_ + 0x58) = 1;
    fn_802AC8AC(lbl_8053ACA0, 0);
    this_[0x84] = 0;
}

extern "C" void fn_80136798(char* this_, s32 a, s32 b) {
    *(s32*)(this_ + 0x50) = a;
    *(s32*)(this_ + 0x58) = 1;
    fn_802AC8AC(lbl_8053ACA0, b);
    this_[0x84] = 0;
}

extern "C" void fn_801367E0(char* this_, s32 a) {
    if (a == 10) {
        fn_802AC980(lbl_8053ACA0);
    }
    *(s32*)(this_ + 0x4c) = a;
}

extern "C" void* fn_8030AAF4(s32);
extern "C" u8 fn_8030A308(void*, void*);
extern void* lbl_8053AD30;
extern void* lbl_8053AD68;
extern void* lbl_8053ACA8;
extern "C" void fn_8037A708(void*);
extern "C" void fn_802B1610(void*, s32, s32);

extern "C" s32 fn_80138A30(void) {
    s32 n = 0;
    for (int i = 0; i < 4; i++) {
        if (*(u8*)(lbl_8053AAF8 + 0x82) & (u8)(1 << i)) {
            n++;
        }
    }
    return n;
}

extern "C" BOOL fn_80138AB0(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7e) == 1) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) && fn_8030A308(lbl_8053AD30, fn_8030AAF4(1)) &&
            fn_8030A308(lbl_8053AD30, fn_8030AAF4(2)) && fn_8030A308(lbl_8053AD30, fn_8030AAF4(3))) {
            return TRUE;
        }
    } else if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0))) {
        return TRUE;
    }
    return FALSE;
}

extern "C" void fn_80139958(void) { fn_8037A708(lbl_8053AD68); }

extern "C" s32 fn_8013997C(s32 i) { return (*(u8*)(lbl_8053AAF8 + 0x83) >> (i * 2)) & 3; }

extern "C" void fn_80139994(s32 a, s32 b) { fn_802B1610(lbl_8053ACA8, a, b); }

#include "JSystem/JAudio/JASFakeMatchFSA.h"
