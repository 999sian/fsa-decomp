// TU 0x80414f6c-0x80418b64.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_8041769C_dtor.cpp ----
// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this is a real `virtual` member rather than a manual cast dispatch.
struct DtorSlot2 {
    virtual void destroy(s32 freeFlag);
};

extern "C" void fn_8042EB14(void* a);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B1378[];
extern void* lbl_8053AEC4;
extern s32 lbl_8053AE00;
extern u64 lbl_8048CD50[];
extern f32 lbl_805439C8;
extern f32 lbl_805439CC;
extern f32 lbl_805439D4;
extern f32 lbl_805439DC;

// Child object at this+0x24. slot 9 takes an s32; slot 15 takes a u64 (EABI puts it in r5:r6)
// and returns the child it creates.
struct T80416BD0_Child {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(s32 v);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual T80416BD0_Child* slot15(u64 name);
};

extern "C" void fn_8042EB24(void* a);
extern "C" void fn_80402E08(void* p, f32 x, f32 y);

struct T80414F6C_Obj {
    u8 pad0[0xe0];
    void* fe0;
};

class TU80414F6C {
public:
    void fn_80414F78();
    void fn_80415028();
    void fn_80416038();
    void fn_804170B0();

    u8 pad0[0x109];
    u8 f109;
    u8 f10a;
};

typedef void (TU80414F6C::*TU80414F6C_StateFn)();
static TU80414F6C_StateFn lbl_804B1354[3] = {
    &TU80414F6C::fn_80416038,
    &TU80414F6C::fn_80415028,
    &TU80414F6C::fn_80414F78,
};

extern "C" {
BOOL fn_8042EC7C(void*);
BOOL fn_8042EBEC(void*);
void* fn_80309C4C(void*, s32, s32);
extern void* lbl_8053AD30;

void* fn_80414F6C() {
    return ((T80414F6C_Obj*)lbl_8053AE00)->fe0;
}
}

void TU80414F6C::fn_80414F78() {
    switch (f10a) {
    case 0:
        if (fn_8042EC7C(lbl_8053AEC4)) {
            f10a = 1;
        }
        break;
    case 1:
        if (fn_80309C4C(lbl_8053AD30, 0x1300, -1)) {
            f10a = 2;
        }
        break;
    case 2:
        if (fn_8042EBEC(lbl_8053AEC4)) {
            f10a = 0;
            f109 = 1;
        }
        break;
    }
}

void TU80414F6C::fn_804170B0() {
    (((TU80414F6C*)lbl_8053AE00)->*lbl_804B1354[f109])();
}

// actor@lbl_804B1378: destructor (0x1E0). Resets the vtable pointer, then
// tears down a large family of owned sub-object slots via real virtual
// dispatch (vtable slot 2, freeFlag=1): 1 single slot (0x24), a 3-element
// array (0x28-0x30), 2 more single slots (0x34/0x38), TWO parallel
// 10-element arrays walked together (0x3c-0x64 and 0x6c-0x94), 1 more
// single slot (0x9c), and a 15-element array (0xa4-0xe0). Always clears
// the global lbl_8053AE00, then conditionally chains to the shared base
// dtor `__dl__FPv` when `how > 0`.
extern "C" void* fn_8041769C(void* this_, s16 how) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1378;
        fn_8042EB14(lbl_8053AEC4);

        char* p = (char*)this_;
        DtorSlot2* single1 = *(DtorSlot2**)(p + 0x24);
        if (single1 != 0) {
            single1->destroy(1);
        }
        *(void**)(p + 0x24) = 0;

        for (s32 i = 0; i < 3; i++) {
            char* slot = p + 0x28 + i * 4;
            DtorSlot2* obj = *(DtorSlot2**)slot;
            if (obj != 0) {
                obj->destroy(1);
            }
            *(void**)slot = 0;
        }

        DtorSlot2* single2 = *(DtorSlot2**)(p + 0x34);
        if (single2 != 0) {
            single2->destroy(1);
        }
        *(void**)(p + 0x34) = 0;

        DtorSlot2* single3 = *(DtorSlot2**)(p + 0x38);
        if (single3 != 0) {
            single3->destroy(1);
        }
        *(void**)(p + 0x38) = 0;

        for (s32 i = 0; i < 0xa; i++) {
            char* slotA = p + 0x3c + i * 4;
            DtorSlot2* objA = *(DtorSlot2**)slotA;
            if (objA != 0) {
                objA->destroy(1);
            }
            *(void**)slotA = 0;

            char* slotB = p + 0x6c + i * 4;
            DtorSlot2* objB = *(DtorSlot2**)slotB;
            if (objB != 0) {
                objB->destroy(1);
            }
            *(void**)slotB = 0;
        }

        DtorSlot2* single4 = *(DtorSlot2**)(p + 0x9c);
        if (single4 != 0) {
            single4->destroy(1);
        }
        *(void**)(p + 0x9c) = 0;

        for (s32 i = 0; i < 0xf; i++) {
            char* slot = p + 0xa4 + i * 4;
            DtorSlot2* obj = *(DtorSlot2**)slot;
            if (obj != 0) {
                obj->destroy(1);
            }
            *(void**)slot = 0;
        }

        lbl_8053AE00 = 0;
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
