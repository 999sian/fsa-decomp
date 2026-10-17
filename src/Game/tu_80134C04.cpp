// tu_80134C04: .text 0x80134C04-0x80139BE8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JKernel/JKRHeap.h"
void* operator new(unsigned long size, JKRHeap* heap, int align);

extern "C" void fn_80139BE8(void* p);
extern "C" void* fn_8013A538(void* p, void* heap);
extern "C" void fn_8013A1A4(void* p);
extern "C" void* fn_8037A8D4(void* p);
extern "C" void* fn_803A59E0(void* p);
extern "C" void* fn_803DFF40(void* p);
extern "C" void* fn_803D0264(void* p);
extern "C" void* fn_803A8884(void* p);
extern "C" void* fn_8039027C(void* p);
extern "C" void fn_8013BE04(void*);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_80139958(void);
struct TuVtable7 {
    virtual void v0(s32 flags);
    virtual void v1();
    virtual void v2(s32 flags);
};

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

extern "C" void fn_80135020(char* this_, s32 which) {
    switch (which) {
    case 7:
        if (*(void**)(this_ + 4) == 0) {
            void* p = operator new(0x38, *(JKRHeap**)(this_ + 0x98), 0);
            if (p != 0) {
                p = fn_8013A538(p, *(void**)(this_ + 0x98));
            }
            *(void**)(this_ + 4) = p;
            fn_8013BE04(lbl_8053AB10);
            if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
                s32 b = *(s32*)(lbl_80529DEC + 0x11c);
                s32 a = *(s32*)(lbl_80529DEC + 0x118);
                char* drive = (char*)fn_802D6A9C();
                *(s32*)(drive + 4) = a;
                *(s32*)(drive + 8) = b;
            } else {
                s32 b = *(s32*)(lbl_80529DEC + 0x12c);
                s32 a = *(s32*)(lbl_80529DEC + 0x128);
                char* drive = (char*)fn_802D6A9C();
                *(s32*)(drive + 4) = a;
                *(s32*)(drive + 8) = b;
            }
            fn_8013A1A4(*(void**)(this_ + 4));
        }
        break;
    case 12:
        if (*(void**)(this_ + 0x1c) == 0) {
            u8 group = (*(JKRHeap**)(this_ + 0x98))->changeGroupID(1);
            void* p = operator new(0x20, *(JKRHeap**)(this_ + 0x98), 0);
            if (p != 0) {
                p = fn_8037A8D4(p);
            }
            *(void**)(this_ + 0x1c) = p;
            (*(JKRHeap**)(this_ + 0x98))->changeGroupID(group);
            fn_80139958();
        }
        break;
    case 1:
        if (*(void**)(this_ + 0x20) == 0) {
            u8 group = (*(JKRHeap**)(this_ + 0x98))->changeGroupID(1);
            void* p = operator new(0x158, *(JKRHeap**)(this_ + 0x98), 0);
            if (p != 0) {
                p = fn_803A59E0(p);
            }
            *(void**)(this_ + 0x20) = p;
            (*(JKRHeap**)(this_ + 0x98))->changeGroupID(group);
            this_[0x87] = 0;
        }
        break;
    case 2:
    case 5:
        if (*(void**)(this_ + 0x28) == 0) {
            u8 group = (*(JKRHeap**)(this_ + 0x98))->changeGroupID(1);
            void* p = operator new(0x120, *(JKRHeap**)(this_ + 0x98), 0);
            if (p != 0) {
                p = fn_803DFF40(p);
            }
            *(void**)(this_ + 0x28) = p;
            (*(JKRHeap**)(this_ + 0x98))->changeGroupID(group);
        }
        break;
    case 3:
        if (*(void**)(this_ + 0x24) == 0) {
            u8 group = (*(JKRHeap**)(this_ + 0x98))->changeGroupID(1);
            void* p = operator new(0x1ac, *(JKRHeap**)(this_ + 0x98), 0);
            if (p != 0) {
                p = fn_803D0264(p);
            }
            *(void**)(this_ + 0x24) = p;
            (*(JKRHeap**)(this_ + 0x98))->changeGroupID(group);
        }
        break;
    case 4:
        if (*(void**)(this_ + 0x2c) == 0) {
            u8 group = (*(JKRHeap**)(this_ + 0x98))->changeGroupID(1);
            void* p = operator new(0x10, *(JKRHeap**)(this_ + 0x98), 0);
            if (p != 0) {
                p = fn_803A8884(p);
            }
            *(void**)(this_ + 0x2c) = p;
            (*(JKRHeap**)(this_ + 0x98))->changeGroupID(group);
        }
        break;
    case 6:
        if (*(void**)(this_ + 0x30) == 0) {
            u8 group = (*(JKRHeap**)(this_ + 0x98))->changeGroupID(1);
            void* p = operator new(0x10, *(JKRHeap**)(this_ + 0x98), 0);
            if (p != 0) {
                p = fn_8039027C(p);
            }
            *(void**)(this_ + 0x30) = p;
            (*(JKRHeap**)(this_ + 0x98))->changeGroupID(group);
        }
        break;
    }
}

extern "C" void fn_801352F4(char* this_, s32 which) {
    switch (which) {
    case 7:
        if (*(void**)(this_ + 4) != 0) {
            fn_80139BE8(*(void**)(this_ + 4));
            if (*(TuVtable7**)(this_ + 4) != 0) {
                (*(TuVtable7**)(this_ + 4))->v0(1);
            }
            *(void**)(this_ + 4) = 0;
        }
        break;
    case 12:
        if (*(TuVtable7**)(this_ + 0x1c) != 0) {
            (*(TuVtable7**)(this_ + 0x1c))->v0(1);
            *(void**)(this_ + 0x1c) = 0;
        }
        break;
    case 1:
        if (*(TuVtable7**)(this_ + 0x20) != 0) {
            (*(TuVtable7**)(this_ + 0x20))->v0(1);
            *(void**)(this_ + 0x20) = 0;
        }
        break;
    case 2:
    case 5:
        if (*(TuVtable7**)(this_ + 0x28) != 0) {
            (*(TuVtable7**)(this_ + 0x28))->v0(1);
            *(void**)(this_ + 0x28) = 0;
        }
        break;
    case 3:
        if (*(TuVtable7**)(this_ + 0x24) != 0) {
            (*(TuVtable7**)(this_ + 0x24))->v0(1);
            *(void**)(this_ + 0x24) = 0;
        }
        break;
    case 4:
        if (*(TuVtable7**)(this_ + 0x2c) != 0) {
            (*(TuVtable7**)(this_ + 0x2c))->v0(1);
            *(void**)(this_ + 0x2c) = 0;
        }
        break;
    case 6:
        if (*(TuVtable7**)(this_ + 0x30) != 0) {
            (*(TuVtable7**)(this_ + 0x30))->v0(1);
            *(void**)(this_ + 0x30) = 0;
        }
        break;
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

extern "C" void fn_8008C308(s32);
extern "C" void fn_8008B8B4(void*, u32*, s32);
extern char* lbl_8053A900;
extern u16 lbl_804655FC[];
extern void* lbl_8053AD70;
extern "C" void fn_8037ADA4(void*);
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void fn_804593D4(void*);
extern "C" void fn_8008DF30(s16, s32);
extern "C" void fn_8008E2B8(void*, s16);
extern "C" u8 fn_8037F1E4(s32);

extern "C" void fn_80134C04(void) {
    s32 i = 0;
    fn_8008C308(0xc8);
    struct Pad { u8 p[0x84]; s32 a, b; };
    Pad* pad = (Pad*)lbl_8053A900;
    pad->a = -1;
    pad->b = -1;
    while (lbl_804655FC[i] != 0) {
        u32 key;
        fn_8008C308(0x64);
        fn_8008B8B4(lbl_8053A900, &key, 0);
        if (key != 0) {
            if (key == lbl_804655FC[i]) {
                i++;
            } else {
                i = 0;
            }
        }
    }
    pad = (Pad*)lbl_8053A900;
    pad->a = 0;
    pad->b = -1;
}

extern "C" void fn_80134D20(char* this_, u8 flag) {
    *(s32*)(this_ + 0x4c) = 9;
    fn_8037ADA4(lbl_8053AD70);
    *((u8*)lbl_8053AD70 + 0xc) = 1;
    fn_80458880(*(void**)(this_ + 0xa0), 1, -1);
    if (flag) {
        fn_804593D4(*(void**)(this_ + 0xa0));
    }
    char* drive = (char*)fn_8008E328(0);
    *(s32*)(this_ + 0x10c) = 0;
    *(s32*)(this_ + 0x108) = 0;
    fn_8008DF30(*(s16*)(drive + 0x7c), 0);
    fn_8008E2B8(drive + 0x68, *(s16*)(drive + 0x7c));
}

extern "C" void fn_80136500(u8* this_) {
    char* g = lbl_8053AAF8;
    u8 paused = *(u8*)(g + 0x94);
    if (*(u8*)(g + 0x96) != 0) {
        paused = 1;
    }
    if (*(u8*)(g + 0x7e) == 0 && fn_8037F1E4(0)) {
        paused = 1;
    }
    if (this_[0xfe] == 1 && !paused) {
        this_[0xfc]++;
        if (this_[0xfc] >= 0x3c) {
            this_[0xfc] = 0;
            (*(s32*)(this_ + 0xf8))++;
        }
    }
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void*);
extern "C" u8 fn_802DEBF8(void*);
extern "C" void* fn_80309C4C(void*, s32, s32);
extern "C" u8 fn_8037AD34(void*);
extern "C" u8 fn_8037ACC4(void*);
extern "C" u8 fn_8037ADD8(void*);

extern "C" void fn_80136364(char* this_) {
    if (*(u8*)(this_ + 0xfe) != 1) return;
    if (fn_802DCD0C(fn_802D6A9C())) return;
    if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) return;
    if (fn_80309C4C(lbl_8053AD30, 0x1000, -1) == 0) return;
    if (fn_8037AD34(lbl_8053AD70)) return;
    if (fn_8037ACC4(lbl_8053AD70)) return;
    if (*(u8*)(lbl_8053AAF8 + 0x85) == 1) {
        if (*(s32*)(this_ + 0x54) == 7) {
            fn_801365E8(this_, *(s32*)(this_ + 0x74), *(s32*)(this_ + 0x78), 0);
        } else {
            fn_80136798(this_, *(s32*)(this_ + 0x54), 0);
        }
    } else if (!fn_802DEBF8(lbl_8053AAF8) && fn_8037ADD8(lbl_8053AD70)) {
        fn_80134D20(this_, 1);
    }
}

extern u32 lbl_804652F0[];
extern "C" void fn_80458F04(void*, u32);
extern "C" void fn_80458FF0(void*, u32, s32, u8);

extern "C" void fn_80138B7C(char* this_) {
    s32 cnt = *(s32*)((char*)fn_802D6A9C() + 0x1328c);
    s32 st = *(s32*)((char*)fn_802D6A9C() + 0x34);
    if (st == 0x11) return;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
        if (st == 0x14 || st == 0x1e) {
            fn_80458F04(*(void**)(this_ + 0xa0), lbl_804652F0[st]);
        } else {
            fn_80458FF0(*(void**)(this_ + 0xa0), lbl_804652F0[st], 0, cnt);
            char* m = (char*)fn_802D6A9C();
            *(s32*)(m + 0x1328c) = cnt + 1;
        }
    } else if (st != 0x19) {
        if (*(u8*)(this_ + 0x86) == 0) {
            fn_80458FF0(*(void**)(this_ + 0xa0), 0x1000004, 0, 0);
        } else {
            fn_80458FF0(*(void**)(this_ + 0xa0), 0x100000d, 0, 0);
        }
    } else {
        fn_80458FF0(*(void**)(this_ + 0xa0), 0x1000019, 0, 0);
    }
}

class J2DTextBox {
public:
    char* getStringPtr() const;
};
extern "C" char* strcpy(char*, const char*);
extern "C" void fn_8013BE04(void*);
extern "C" void fn_802ACB58(void*);
extern "C" void fn_80119DD0(void);
extern "C" void fn_80119D48(void);
extern "C" void fn_8011921C(void);
extern "C" void fn_801190E4(void);
extern "C" f32 fn_803832BC(char*, s32, s32, s32, s32);

struct BootCfgB { u8 pad[0x21a]; u8 m21A, m21B; u8 pad2[0x249 - 0x21c]; u8 m249; };

inline f32 randF_80138C9C() {
    u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    u32 bits = (*seed >> 9) | 0x3f800000;
    return *(f32*)&bits - 1.0f;
}

extern "C" void fn_80138C9C(char* this_) {
    *(u8*)(*(char**)(this_ + 0xa0) + 5) = 4;
    fn_8013BE04(lbl_8053AB10);
    fn_802ACB58(*(void**)(this_ + 0x10));
    fn_80119DD0();
    fn_80119D48();
    fn_8011921C();
    fn_801190E4();
    BootCfgB* cfg = (BootCfgB*)lbl_80529DEC;
    *(s32*)(this_ + 0x5c) = 0;
    this_[0x94] = 0;
    this_[0x96] = 0;
    *(s32*)(this_ + 0x10c) = 0;
    *(s32*)(this_ + 0x108) = 0;
    *(s32*)(this_ + 0x58) = 0;
    if (cfg->m21A != 0xa7) {
        cfg->m21A = 0xa7;
        *(s32*)(this_ + 0x4c) = 1;
    } else {
        if (cfg->m21B != 0xa5) {
            cfg->m249 = 1;
            fn_80136798(this_, 2, 0);
        } else {
            fn_80136798(this_, 1, 0);
        }
        cfg->m21B = 0;
    }
    *(s32*)(this_ + 0x60) = 0;
    *(s32*)(this_ + 0x64) = 0;
    *(s32*)(this_ + 0x68) = 0;
    *(s32*)(this_ + 0xb4) = 19750304;
    *(s32*)(this_ + 0x70) = 0;
    this_[0x80] = 0;
    this_[0x81] = 0;
    this_[0x7e] = 1;
    this_[0x7f] = 1;
    this_[0x82] = 0;
    this_[0x83] = 0;
    this_[0xff] = 0;
    *(f32*)(this_ + 0xf0) = 0.0f;
    this_[0x86] = (s32)(2.0f * randF_80138C9C()) & 1;
    *(f32*)(this_ + 0xf4) = fn_803832BC(this_ + 0xc8, 0x42, 0, 0, 0);
    strcpy((*(J2DTextBox**)(this_ + 0xc4))->getStringPtr(), this_ + 0xc8);
    strcpy((*(J2DTextBox**)(this_ + 0xc0))->getStringPtr(), this_ + 0xc8);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
