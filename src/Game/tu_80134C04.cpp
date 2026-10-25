// tu_80134C04: .text 0x80134C04-0x80139BE8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/J3D/J3DSys.h"
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
extern u32 lbl_804652F0[];
extern void* lbl_8053AD80;
extern u8 lbl_8050EC80[];
extern "C" void fn_80158B3C(void*);
extern "C" void fn_80390088(void*);
extern "C" void fn_80458F04(void*, u32);
extern "C" void fn_80458FF0(void*, u32, s32, u8);
struct TuOwnedObject {
    virtual ~TuOwnedObject();
};

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
extern void* lbl_8053ACA8;

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
            if (*(TuVtable7**)(this_ + 0x1c) != 0) {
                (*(TuVtable7**)(this_ + 0x1c))->v0(1);
            }
            *(void**)(this_ + 0x1c) = 0;
        }
        break;
    case 1:
        if (*(TuVtable7**)(this_ + 0x20) != 0) {
            if (*(TuVtable7**)(this_ + 0x20) != 0) {
                (*(TuVtable7**)(this_ + 0x20))->v0(1);
            }
            *(void**)(this_ + 0x20) = 0;
        }
        break;
    case 2:
    case 5:
        if (*(TuVtable7**)(this_ + 0x28) != 0) {
            if (*(TuVtable7**)(this_ + 0x28) != 0) {
                (*(TuVtable7**)(this_ + 0x28))->v0(1);
            }
            *(void**)(this_ + 0x28) = 0;
        }
        break;
    case 3:
        if (*(TuVtable7**)(this_ + 0x24) != 0) {
            if (*(TuVtable7**)(this_ + 0x24) != 0) {
                (*(TuVtable7**)(this_ + 0x24))->v0(1);
            }
            *(void**)(this_ + 0x24) = 0;
        }
        break;
    case 4:
        if (*(TuVtable7**)(this_ + 0x2c) != 0) {
            if (*(TuVtable7**)(this_ + 0x2c) != 0) {
                (*(TuVtable7**)(this_ + 0x2c))->v0(1);
            }
            *(void**)(this_ + 0x2c) = 0;
        }
        break;
    case 6:
        if (*(TuVtable7**)(this_ + 0x30) != 0) {
            if (*(TuVtable7**)(this_ + 0x30) != 0) {
                (*(TuVtable7**)(this_ + 0x30))->v0(1);
            }
            *(void**)(this_ + 0x30) = 0;
        }
        break;
    }
}

extern "C" void OSReport(const char* fmt, ...);
extern "C" void* fn_80401E10(const char* name, s32 a, void* heap);
extern f32 lbl_8053CD50;

static inline void tu80134_heapReport(char* this_, const char* fmt) {
    f32 t = (s32)(*(JKRHeap**)(this_ + 0x98))->getTotalFreeSize();
    f32 total = t * lbl_8053CD50;
    f32 f = (s32)(*(JKRHeap**)(this_ + 0x98))->getFreeSize();
    OSReport(fmt, f * lbl_8053CD50, total);
}

static inline void* tu80134_load(const char* name) {
    return fn_80401E10(name, 0, *(void**)(lbl_80529DEC + 8));
}

extern "C" void fn_80135494(char* this_, s32 cmd) {
    u8 bVar2 = 0;
    if ((cmd != 2 || *(s32*)(this_ + 0x4c) == 2 || *(s32*)(this_ + 0x4c) == 5) &&
        (cmd != 5 || *(s32*)(this_ + 0x4c) == 2 || *(s32*)(this_ + 0x4c) == 5) &&
        ((u32)(cmd - 3) > 1 && cmd != 6) && (cmd != 7 || *(s32*)(this_ + 4) != 0)) {
        if (cmd == 0xc && lbl_80529DEC[0x24d] == 1 && *(s16*)(this_ + 0x7c) < 0x78) {
            *(s16*)(this_ + 0x7c) = *(s16*)(this_ + 0x7c) + 1;
            return;
        }
    } else {
        char* obj = *(char**)(this_ + 0xac);
        if (*(u8*)(obj + 4) != 1) {
            return;
        }
        if (*(char**)(this_ + 0xb0) != 0 && *(u8*)(*(char**)(this_ + 0xb0) + 4) != 1) {
            return;
        }
        switch (cmd) {
        case 2:
        case 5:
            if (*(s32*)(this_ + 0x4c) != 2 && *(s32*)(this_ + 0x4c) != 5) {
                *(s32*)(lbl_80529DEC + 0x2c) = *(s32*)(obj + 0x14);
                fn_80135020(this_, 2);
            }
            break;
        case 3:
            *(s32*)(lbl_80529DEC + 0x30) = *(s32*)(obj + 0x14);
            fn_80135020(this_, 3);
            break;
        case 4:
            *(s32*)(lbl_80529DEC + 0x28) = *(s32*)(obj + 0x14);
            fn_80135020(this_, 4);
            break;
        case 7:
            *(s32*)(lbl_80529DEC + 0x10) = *(s32*)(obj + 0x14);
            *(s32*)(lbl_80529DEC + 0x4c) = *(s32*)(*(char**)(this_ + 0xb0) + 0x14);
            fn_80135020(this_, 7);
            break;
        case 6:
            *(s32*)(lbl_80529DEC + 0x34) = *(s32*)(obj + 0x14);
            fn_80135020(this_, 6);
            fn_80390088(lbl_8053AD80);
            break;
        }
        obj = *(char**)(this_ + 0xac);
        if (obj != 0) {
            ((void (*)(void*, s32))(*(void***)(obj + 8))[2])(obj, 1);
        }
        obj = *(char**)(this_ + 0xb0);
        if (obj != 0) {
            ((void (*)(void*, s32))(*(void***)(obj + 8))[2])(obj, 1);
        }
        bVar2 = 1;
    }
    if (!bVar2 && (*(s32*)(this_ + 0x50) == 1 || *(s32*)(this_ + 0x50) == 5 ||
                   *(s32*)(this_ + 0x50) == 2 || *(s32*)(this_ + 0x50) == 0xc)) {
        *(s32*)(this_ + 0x60) = 0;
    }
    *(s32*)(this_ + 0x4c) = *(s32*)(this_ + 0x50);
    if (*(s32*)(this_ + 0x4c) == 1 || *(s32*)(this_ + 0x4c) == 6) {
        fn_80158B3C(*(void**)(lbl_8053AB10 + 0x2c));
    }
    *(s32*)(this_ + 0x64) = 0;
    if (*(u8*)(this_ + 0xfd) == 0) {
        if (*(s32*)(this_ + 0x50) == 0x11) {
            *(s32*)(this_ + 0x58) = 3;
        } else {
            *(s32*)(this_ + 0x58) = 2;
        }
    } else {
        *(u8*)(this_ + 0xfd) = 0;
    }
    if (*(s32*)(this_ + 0x4c) == 7) {
        if (bVar2) {
            {
                char* g = lbl_8053AAF8;
                g[0xfe] = 1;
                g[0xfc] = 0;
                *(s32*)(g + 0xf8) = 0;
            }
            if (*(s32*)((char*)fn_802D6A9C() + 0x3c) != 0) {
                *(s32*)(this_ + 0x60) = 0;
            } else {
                *(s32*)(this_ + 0x60) = 4;
                if (*(s32*)((char*)fn_802D6A9C() + 4) != 0 || *(s32*)((char*)fn_802D6A9C() + 8) != 0 ||
                    (*(s32*)((char*)fn_802D6A9C() + 4) == 0 && *(s32*)((char*)fn_802D6A9C() + 8) == 0 &&
                     (*(s32*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x28) & 1) != 0)) {
                    u32 uVar1 = *(u32*)((char*)fn_802D6A9C() + 0x1328c);
                    s32 st = *(s32*)((char*)fn_802D6A9C() + 0x34);
                    if (st != 0x11) {
                        if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
                            if (st == 0x14 || st == 0x1e) {
                                fn_80458F04(*(void**)(this_ + 0xa0), lbl_804652F0[st]);
                            } else {
                                fn_80458FF0(*(void**)(this_ + 0xa0), lbl_804652F0[st], 0, uVar1 & 0xff);
                                *(u32*)((char*)fn_802D6A9C() + 0x1328c) = uVar1 + 1;
                            }
                        } else if (st == 0x19) {
                            fn_80458FF0(*(void**)(this_ + 0xa0), 0x1000019, 0, 0);
                        } else if (*(u8*)(this_ + 0x86) == 0) {
                            fn_80458FF0(*(void**)(this_ + 0xa0), 0x1000004, 0, 0);
                        } else {
                            fn_80458FF0(*(void**)(this_ + 0xa0), 0x100000d, 0, 0);
                        }
                    }
                }
            }
        } else if (*(s32*)(this_ + 0x50) == 0xe) {
            *(s32*)(this_ + 0x60) = 4;
            u32 uVar1 = *(u32*)((char*)fn_802D6A9C() + 0x1328c);
            s32 st = *(s32*)((char*)fn_802D6A9C() + 0x34);
            if (st != 0x11) {
                if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
                    if (st == 0x14 || st == 0x1e) {
                        fn_80458F04(*(void**)(this_ + 0xa0), lbl_804652F0[st]);
                    } else {
                        fn_80458FF0(*(void**)(this_ + 0xa0), lbl_804652F0[st], 0, uVar1 & 0xff);
                        *(u32*)((char*)fn_802D6A9C() + 0x1328c) = uVar1 + 1;
                    }
                } else if (st == 0x19) {
                    fn_80458FF0(*(void**)(this_ + 0xa0), 0x1000019, 0, 0);
                } else if (*(u8*)(this_ + 0x86) == 0) {
                    fn_80458FF0(*(void**)(this_ + 0xa0), 0x1000004, 0, 0);
                } else {
                    fn_80458FF0(*(void**)(this_ + 0xa0), 0x100000d, 0, 0);
                }
            }
        }
    }
}

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteAllEmitter__17JPAEmitterManagerFv(void* mgr);
extern "C" char* strcpy(char* d, const char* s);
extern "C" char* strcat(char* d, const char* s);
extern "C" void fn_80135A04(char* this_, u32 which) {
    char* base = (char*)lbl_804652F0;
    if (*(u8*)(this_ + 0x84) != 0) {
        fn_801352F4(this_, *(s32*)(this_ + 0x4c));
        *(u8*)(this_ + 0x84) = 0;
    }
    switch (which) {
    case 7:
        if (*(void**)(this_ + 4) == 0) {
            fn_801352F4(this_, 1);
            fn_801352F4(this_, 2);
            fn_801352F4(this_, 3);
            fn_801352F4(this_, 4);
            fn_801352F4(this_, 6);
            fn_801352F4(this_, 0xc);
            tu80134_heapReport(this_, base + 0x324);
            if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
                char buf[0x20];
                if (((s32 (*)(void))fn_80021840)() == 2) {
                    strcpy(buf, base + 0x350);
                } else if (((s32 (*)(void))fn_80021840)() == 0 || ((s32 (*)(void))fn_80021840)() == 1) {
                    strcpy(buf, base + 0x360);
                }
                strcat(buf, ((char**)(lbl_8049ED88 + *(s32*)(lbl_80529DEC + 0x118) * 16))[*(s32*)(lbl_80529DEC + 0x11c)]);
                *(void**)(this_ + 0xac) = tu80134_load(buf);
            } else if (((s32 (*)(void))fn_80021840)() == 2) {
                *(void**)(this_ + 0xac) = tu80134_load(base + 0x374);
            } else if (((s32 (*)(void))fn_80021840)() == 0 || ((s32 (*)(void))fn_80021840)() == 1) {
                *(void**)(this_ + 0xac) = tu80134_load(base + 0x390);
            }
            if (((s32 (*)(void))fn_80021840)() == 2) {
                *(void**)(this_ + 0xb0) = tu80134_load(base + 0x3b0);
            } else if (((s32 (*)(void))fn_80021840)() == 0 || ((s32 (*)(void))fn_80021840)() == 1) {
                *(void**)(this_ + 0xb0) = tu80134_load(base + 0x3c8);
            }
        }
        break;
    case 12:
        forceDeleteAllEmitter__17JPAEmitterManagerFv(*(void**)((char*)fn_8013C824() + 0xc));
        fn_801352F4(this_, 1);
        fn_801352F4(this_, 2);
        fn_801352F4(this_, 3);
        fn_801352F4(this_, 4);
        fn_801352F4(this_, 6);
        fn_801352F4(this_, 7);
        tu80134_heapReport(this_, base + 0x3e4);
        fn_80135020(this_, 0xc);
        break;
    case 1:
        fn_801352F4(this_, 7);
        fn_801352F4(this_, 2);
        fn_801352F4(this_, 3);
        fn_801352F4(this_, 4);
        fn_801352F4(this_, 6);
        fn_801352F4(this_, 0xc);
        tu80134_heapReport(this_, base + 0x414);
        fn_80135020(this_, 1);
        break;
    case 2:
    case 5:
        if (*(s32*)(this_ + 0x4c) == 2 || *(s32*)(this_ + 0x4c) == 5) {
            break;
        }
        fn_801352F4(this_, 7);
        fn_801352F4(this_, 1);
        fn_801352F4(this_, 3);
        fn_801352F4(this_, 4);
        fn_801352F4(this_, 6);
        fn_801352F4(this_, 0xc);
        tu80134_heapReport(this_, base + 0x440);
        if (((s32 (*)(void))fn_80021840)() == 2) {
            *(void**)(this_ + 0xac) = tu80134_load(base + 0x474);
        } else if (((s32 (*)(void))fn_80021840)() == 0 || ((s32 (*)(void))fn_80021840)() == 1) {
            *(void**)(this_ + 0xac) = tu80134_load(base + 0x48c);
        }
        *(void**)(this_ + 0xb0) = 0;
        break;
    case 3:
        fn_801352F4(this_, 7);
        fn_801352F4(this_, 1);
        fn_801352F4(this_, 2);
        fn_801352F4(this_, 4);
        fn_801352F4(this_, 6);
        fn_801352F4(this_, 0xc);
        tu80134_heapReport(this_, base + 0x4a8);
        if (((s32 (*)(void))fn_80021840)() == 2) {
            *(void**)(this_ + 0xac) = tu80134_load(base + 0x4dc);
        } else if (((s32 (*)(void))fn_80021840)() == 0 || ((s32 (*)(void))fn_80021840)() == 1) {
            *(void**)(this_ + 0xac) = tu80134_load(base + 0x4f0);
        }
        *(void**)(this_ + 0xb0) = 0;
        break;
    case 4:
        fn_801352F4(this_, 7);
        fn_801352F4(this_, 1);
        fn_801352F4(this_, 2);
        fn_801352F4(this_, 3);
        fn_801352F4(this_, 6);
        fn_801352F4(this_, 0xc);
        tu80134_heapReport(this_, base + 0x508);
        if (((s32 (*)(void))fn_80021840)() == 2) {
            *(void**)(this_ + 0xac) = tu80134_load(base + 0x534);
        } else if (((s32 (*)(void))fn_80021840)() == 0 || ((s32 (*)(void))fn_80021840)() == 1) {
            *(void**)(this_ + 0xac) = tu80134_load(base + 0x548);
        }
        *(void**)(this_ + 0xb0) = 0;
        break;
    case 6:
        fn_801352F4(this_, 7);
        fn_801352F4(this_, 1);
        fn_801352F4(this_, 2);
        fn_801352F4(this_, 3);
        fn_801352F4(this_, 4);
        fn_801352F4(this_, 0xc);
        tu80134_heapReport(this_, base + 0x560);
        if (((s32 (*)(void))fn_80021840)() == 2) {
            if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
                *(void**)(this_ + 0xac) = tu80134_load(base + 0x590);
            } else {
                *(void**)(this_ + 0xac) = tu80134_load(base + 0x5a4);
            }
        } else if (((s32 (*)(void))fn_80021840)() == 0 || ((s32 (*)(void))fn_80021840)() == 1) {
            if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
                *(void**)(this_ + 0xac) = tu80134_load(base + 0x5b8);
            } else {
                *(void**)(this_ + 0xac) = tu80134_load(base + 0x5d0);
            }
        }
        *(void**)(this_ + 0xb0) = 0;
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

extern "C" void fn_803A44D8(void*);
extern "C" void fn_8013B4F8(void*);
extern "C" void fn_803DF624(void*);
extern "C" void fn_803CEED4(void*);
extern "C" void fn_8013BB64(void*);
extern "C" void fn_8013BB18(void*);
extern "C" void fn_803A8664(void*);
extern "C" void fn_8013B71C(void*);
extern "C" void fn_8013B618(void*);
extern "C" void fn_803A71F0(void*);
extern "C" void fn_8039013C(void*);
extern "C" void fn_80390108(void*);
extern void* lbl_8053AD88;
extern void* lbl_8053ADD0;
extern void* lbl_8053ADB0;
extern void* lbl_8053AD98;
extern void* lbl_8053AD90;
extern "C" void fn_80136828(void* this_) {
    char* t = (char*)this_;
    j3dSys.drawInit();
    switch (*(s32*)(t + 0x4c)) {
    case 0:
        if (lbl_8053AD88 != 0) {
            fn_803A44D8(lbl_8053AD88);
        }
        fn_8013B4F8(lbl_8053AB10);
        break;
    case 1:
        fn_803DF624(lbl_8053ADD0);
        break;
    case 2:
        fn_803CEED4(lbl_8053ADB0);
        break;
    case 3:
        fn_8013BB64(lbl_8053AB10);
        fn_8013BB18(lbl_8053AB10);
        fn_803A8664(lbl_8053AD98);
        fn_8013B71C(lbl_8053AB10);
        fn_8013B618(lbl_8053AB10);
        break;
    case 4:
        fn_803A71F0(lbl_8053AD90);
        break;
    case 5:
        fn_8013BB64(lbl_8053AB10);
        fn_8013BB18(lbl_8053AB10);
        fn_8039013C(lbl_8053AD80);
        fn_8013B71C(lbl_8053AB10);
        fn_8013B618(lbl_8053AB10);
        fn_80390108(lbl_8053AD80);
        break;
    }
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

struct ResFONT;
class J2DTextBox {
public:
    J2DTextBox(u64 tag, const JGeometry::TBox2f& box, const ResFONT* font, const char* str, s16 len, s32 hb, s32 vb);
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

extern "C" u8 lbl_8049EF20[];
extern "C" void __dl__FPv(void* p);
extern "C" void fn_8007A298(void* p);
extern "C" void fn_803007A0(void);
extern "C" void releaseSound__14JAISoundHandleFv(void* p);
extern "C" void destroy__7JKRHeapFv(void* p);
extern "C" void* fn_80138E78(u8* p, s16 how) {
    void* sound;
    void* tmp;

    if (p != 0) {
        *(void**)p = lbl_8049EF20;
        tmp = fn_8008E328(0);
        *(s32*)(p + 0x10c) = 0;
        *(s32*)(p + 0x108) = 0;
        fn_8008DF30(*(s16*)((u8*)tmp + 0x7c), 0);
        fn_8008E2B8((u8*)tmp + 0x68, *(s16*)((u8*)tmp + 0x7c));
        if (*(void**)(p + 0x104) != 0) {
            __dl__FPv(*(void**)(p + 0x104));
        }
        if (*(void**)(p + 0x4) != 0) {
            delete *(TuOwnedObject**)(p + 0x4);
            *(void**)(p + 0x4) = 0;
        }
        delete *(TuOwnedObject**)(p + 0x18);
        *(void**)(p + 0x18) = 0;

        delete (TuOwnedObject*)lbl_8053AB10;
        delete *(TuOwnedObject**)(p + 0x8);

        delete *(TuOwnedObject**)(p + 0xc);

        delete *(TuOwnedObject**)(p + 0x10);

        if (*(void**)(p + 0x20) != 0) {
            delete *(TuOwnedObject**)(p + 0x20);
            *(void**)(p + 0x20) = 0;
        }
        if (*(void**)(p + 0x28) != 0) {
            delete *(TuOwnedObject**)(p + 0x28);
            *(void**)(p + 0x28) = 0;
        }
        if (*(void**)(p + 0x24) != 0) {
            delete *(TuOwnedObject**)(p + 0x24);
            *(void**)(p + 0x28) = 0;
        }
        if (*(void**)(p + 0x2c) != 0) {
            delete *(TuOwnedObject**)(p + 0x2c);
            *(void**)(p + 0x2c) = 0;
        }
        if (*(void**)(p + 0x30) != 0) {
            delete *(TuOwnedObject**)(p + 0x30);
            *(void**)(p + 0x30) = 0;
        }
        if (*(void**)(p + 0x1c) != 0) {
            delete *(TuOwnedObject**)(p + 0x1c);
            *(void**)(p + 0x1c) = 0;
        }
        fn_8007A298(*(void**)(lbl_80529DEC + 0x24));
        fn_8007A298(*(void**)(lbl_80529DEC + 0x38));
        fn_8007A298(*(void**)(lbl_80529DEC + 0x40));
        fn_8007A298(*(void**)(lbl_80529DEC + 0x44));
        delete *(TuOwnedObject**)(p + 0x34);
        *(void**)(p + 0x34) = 0;

        delete *(TuOwnedObject**)(p + 0x38);
        *(void**)(p + 0x38) = 0;

        delete *(TuOwnedObject**)(p + 0x3c);
        *(void**)(p + 0x3c) = 0;

        delete *(TuOwnedObject**)(p + 0x40);
        *(void**)(p + 0x40) = 0;

        (*(TuVtable7**)(p + 0xa4))->v1();
        (*(TuVtable7**)(p + 0xa8))->v1();
        (*(TuVtable7**)(lbl_80529DEC + 0x20))->v1();
        fn_803007A0();
        sound = *(void**)(p + 0xa0);
        if (sound != 0) {
            if ((u32)sound + 0x84 != 0) {
                releaseSound__14JAISoundHandleFv((u8*)sound + 0x84);
            }
            if ((u32)sound + 0x80 != 0) {
                releaseSound__14JAISoundHandleFv((u8*)sound + 0x80);
            }
            __dl__FPv(sound);
        }
        destroy__7JKRHeapFv(*(void**)(p + 0x9c));
        delete *(TuOwnedObject**)(p + 0xb8);
        *(void**)(p + 0xb8) = 0;

        delete *(TuOwnedObject**)(p + 0xbc);
        *(void**)(p + 0xbc) = 0;

        delete *(TuOwnedObject**)(p + 0xc0);
        *(void**)(p + 0xc0) = 0;

        delete *(TuOwnedObject**)(p + 0xc4);
        *(void**)(p + 0xc4) = 0;

        destroy__7JKRHeapFv(*(void**)(p + 0x98));
        if (how > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern u8 lbl_8049EF20[];
extern u8* sManager__8JUTVideo;
extern f32 lbl_8053CD80;
extern f32 lbl_8053CD84;
extern f32 lbl_8053CD8C;
extern f32 lbl_8053CD90;
extern f32 lbl_8053CDB8;
extern f32 lbl_8053CDBC;
extern "C" void* __ct__6MsgMgrFv(void*);
extern "C" void* __ct__10J2DPictureFPC7ResTIMG(void*, const void*);
extern "C" void* fn_8013BFEC(void*, void*);
extern "C" void* fn_802ACBE8(void*);
extern "C" void* fn_803DA8FC(void*);
extern "C" void* fn_8044243C(void*);
extern "C" void* fn_80440FDC(void*);
extern "C" void* fn_80431D84(void*);
extern "C" void* fn_804030C4(u32, void*);
extern "C" void fn_8008C494(void*);
extern "C" void fn_8008C484(void*);
extern "C" void __ct__Q25JMath13TRandom_fast_FUl(void*, u32);
extern "C" void* fn_80139300(char* this_) {
    u8* base = (u8*)lbl_804652F0;
    *(void**)this_ = lbl_8049EF20;
    __ct__Q25JMath13TRandom_fast_FUl(this_ + 0xb4, 0);
    lbl_8053AAF8 = this_;
    *(s32*)(this_ + 0x9c) = *(s32*)(lbl_80529DEC + 4);
    *(s32*)(this_ + 0x98) = *(s32*)(lbl_80529DEC + 8);
    *(s32*)(this_ + 0xa0) = *(s32*)(lbl_80529DEC + 0xc);
    *(s32*)(this_ + 0xa4) = *(s32*)(lbl_80529DEC + 0x14);
    *(s32*)(this_ + 0xa8) = *(s32*)(lbl_80529DEC + 0x1c);
    JKRHeap* heap = *(JKRHeap**)(this_ + 0x98);
    heap->becomeCurrentHeap();

    void* p = operator new(0x158, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = __ct__6MsgMgrFv(p);
    }
    *(void**)(this_ + 0x18) = p;

    p = operator new(0x3c, *(JKRHeap**)(this_ + 0x98), 0);
    void* q = 0;
    if (p != 0) {
        q = fn_8013BFEC(p, *(JKRHeap**)(this_ + 0x98));
    }
    lbl_8053AB10 = (char*)q;

    *(s32*)(this_ + 8) = *(s32*)(lbl_80529DEC + 0x5c);
    *(s32*)(this_ + 0xc) = *(s32*)(lbl_80529DEC + 0x60);

    p = operator new(0x1c, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = fn_802ACBE8(p);
    }
    *(void**)(this_ + 0x10) = p;

    p = operator new(0x24, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = fn_803DA8FC(p);
    }
    *(void**)(this_ + 0x34) = p;

    p = operator new(0x28, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = fn_8044243C(p);
    }
    *(void**)(this_ + 0x38) = p;

    p = operator new(0x14, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = fn_80440FDC(p);
    }
    *(void**)(this_ + 0x3c) = p;

    p = operator new(0xf0, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = fn_80431D84(p);
    }
    *(void**)(this_ + 0x40) = p;

    *(s32*)(this_ + 0xac) = 0;
    *(s32*)(this_ + 0xb0) = 0;
    *(s32*)(this_ + 4) = 0;
    *(s32*)(this_ + 0x1c) = 0;
    *(s32*)(this_ + 0x28) = 0;
    *(s32*)(this_ + 0x24) = 0;
    *(s32*)(this_ + 0x2c) = 0;
    *(s32*)(this_ + 0x30) = 0;
    *(u8*)(this_ + 0xfd) = 0;
    *(u8*)(this_ + 0x84) = 0;
    *(s32*)(this_ + 0x54) = 0;
    *(u8*)(this_ + 0x85) = 0;
    *(s32*)(this_ + 0x74) = 0;
    *(s32*)(this_ + 0x78) = 0;
    *(u8*)(this_ + 0x86) = 0;
    *(u8*)(this_ + 0x88) = 0;
    *(u8*)(this_ + 0x94) = 0;
    *(u8*)(this_ + 0x95) = 0;
    *(u8*)(this_ + 0x96) = 0;
    *(s32*)(this_ + 0x10c) = 0;
    *(s32*)(this_ + 0x108) = 0;
    *(s16*)(this_ + 0x7c) = 0;

    u8 group = (*(JKRHeap**)(this_ + 0x98))->changeGroupID(1);
    p = operator new(0x158, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = fn_803A59E0(p);
    }
    *(void**)(this_ + 0x20) = p;
    (*(JKRHeap**)(this_ + 0x98))->changeGroupID(group);
    *(u8*)(this_ + 0x87) = 0;

    void* tex = fn_804030C4(0x54494d47, base + 0x5e8);
    p = operator new(0x168, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = __ct__10J2DPictureFPC7ResTIMG(p, tex);
    }
    *(void**)(this_ + 0xb8) = p;

    u8 c1[4];
    u8 c2[4];
    c1[0] = 0xff;
    c1[1] = 0xd2;
    c1[2] = 0;
    c1[3] = 0xff;
    c2[0] = 0;
    c2[1] = 0;
    c2[2] = 0;
    c2[3] = 0;
    u32 t1 = *(u32*)c1;
    u32 t2 = *(u32*)c2;
    void* obj = *(void**)(this_ + 0xb8);
    (*(void (**)(void*, void*, void*))((*(char**)obj) + 0x130))(obj, &t2, &t1);

    obj = *(void**)(lbl_8053AAF8 + 0xa4);
    tex = (*(void* (**)(void*, u32, s32))((*(char**)obj) + 0x18))(obj, 0x54494d47, 0);
    p = operator new(0x168, *(JKRHeap**)(this_ + 0x98), 0);
    if (p != 0) {
        p = __ct__10J2DPictureFPC7ResTIMG(p, tex);
    }
    *(void**)(this_ + 0xbc) = p;

    if (((s32 (*)(void))fn_80021840)() == 2) {
        u16 w = *(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
        JGeometry::TBox2f boxA(lbl_8053CD90, lbl_8053CDB8, lbl_8053CD8C + (f32)w, lbl_8053CD80);
        p = new (*(JKRHeap**)(this_ + 0x98), 0) J2DTextBox(0x0000005445585431ULL, boxA, (ResFONT*)(base + 0x5f8), (char*)(this_ + 0xc8), 0x28, 0, 0);
        *(void**)(this_ + 0xc0) = p;
        JGeometry::TBox2f boxB(lbl_8053CD84, lbl_8053CDBC, lbl_8053CD8C + (f32)w, lbl_8053CD80);
        p = new (*(JKRHeap**)(this_ + 0x98), 0) J2DTextBox(0x0000005445585432ULL, boxB, (ResFONT*)(base + 0x5f8), (char*)(this_ + 0xc8), 0x28, 0, 0);
        *(void**)(this_ + 0xc4) = p;
    } else {
        u16 w = *(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
        JGeometry::TBox2f boxC(lbl_8053CD90, lbl_8053CDB8, lbl_8053CD8C + (f32)w, lbl_8053CD80);
        p = new (*(JKRHeap**)(this_ + 0x98), 0) J2DTextBox(0x0000005445585431ULL, boxC, (ResFONT*)(base + 0x60c), (char*)(this_ + 0xc8), 0x28, 0, 0);
        *(void**)(this_ + 0xc0) = p;
        JGeometry::TBox2f boxD(lbl_8053CD84, lbl_8053CDBC, lbl_8053CD8C + (f32)w, lbl_8053CD80);
        p = new (*(JKRHeap**)(this_ + 0x98), 0) J2DTextBox(0x0000005445585432ULL, boxD, (ResFONT*)(base + 0x60c), (char*)(this_ + 0xc8), 0x28, 0, 0);
        *(void**)(this_ + 0xc4) = p;
    }

    u32 colA[4];
    colA[0] = 0xffff50ff;
    colA[1] = 0xffff50ff;
    colA[2] = 0x50502800;
    colA[3] = 0x50502800;
    obj = *(void**)(this_ + 0xc0);
    (*(void (**)(void*, void*, void*))((*(char**)obj) + 0xac))(obj, &colA[3], &colA[1]);

    fn_8008C494(base + 0x620);
    fn_8008C484((void*)fn_80134C04);
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
