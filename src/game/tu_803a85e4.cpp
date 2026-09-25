// TU 0x803a85e4-0x803a8dfc.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_803A8600.cpp ----
extern void* lbl_8053AAF8[2];

extern "C" void fn_803ED83C(void* subObj);
extern "C" void fn_803FC304(void* subObj);

// fn_803A8600 - actor@lbl_804AF860: vtable-slot function. Calls
// fn_803FC304/fn_803ED83C (both inside the still-unexamined 156KB
// non-actor stretch found earlier in this gap - confirms actors here
// do call into that shared subsystem).
extern "C" void fn_803A8600(void* this_) {
    u8 flag = *(u8*)((char*)lbl_8053AAF8[0] + 0x7f);
    if (flag != 0) {
        void* obj = *(void**)((char*)this_ + 0x4);
        fn_803ED83C(obj);
        obj = *(void**)((char*)this_ + 0x4);
        *(s32*)((char*)this_ + 0xc) = *(s32*)((char*)obj + 0x360);
    } else {
        void* obj = *(void**)((char*)this_ + 0x8);
        fn_803FC304(obj);
        obj = *(void**)((char*)this_ + 0x8);
        *(s32*)((char*)this_ + 0xc) = *(s32*)((char*)obj + 0x350);
    }
}

// ---- from src/Game/SubobjDtor_lbl804AF860_803A87A8.cpp ----
// fn_803A87A8 - actor@lbl_804AF860 vt+0x20 slot: destructor of an
// embedded base-class sub-object. Reinstalls the sub-view vtable
// lbl_804AF878, calls getTotalFreeSize__7JKRHeapFv on a manager sub-object
// (lbl_80529DEC->0x8), calls own virtual slot 0 (byte offset 0x8) on
// this->0x4/0x8 if set (clearing each afterward), calls a real
// virtual slot 1 (byte offset 0xc) on another manager sub-object
// (lbl_80529DEC->0x28), zeroes the global lbl_8053AD98, then
// conditionally forwards to __dl__FPv. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why the calls
// go through real `virtual` members rather than manual casts.
extern "C" void getTotalFreeSize__7JKRHeapFv(void* p);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF878[];
extern u8 lbl_80529DEC[];
extern s32 lbl_8053AD98;

struct SlotA {
    virtual void slot0(s32 arg);
};

struct SlotB {
    virtual void v0();
    virtual void slot1();
};

extern "C" void* fn_803A87A8(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF878;
        void* obj = *(void**)((u8*)lbl_80529DEC + 0x8);
        getTotalFreeSize__7JKRHeapFv(obj);
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((SlotA*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((SlotA*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* obj2 = *(void**)((u8*)lbl_80529DEC + 0x28);
        ((SlotB*)obj2)->slot1();
        lbl_8053AD98 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
