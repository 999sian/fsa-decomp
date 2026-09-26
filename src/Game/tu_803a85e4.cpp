// TU 0x803a85e4-0x803a8dfc.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// fn_803A8884 (ctor) is ~97.4%: this/string-base callee-saved regs swapped.
#include "types.h"

// ---- from src/Game/fn_803A8600.cpp ----
extern void* lbl_8053AAF8[2];
extern void* lbl_8053AD98;
extern "C" void* fn_803A85E4(void) {
    if (lbl_8053AD98 != 0) {
        return *(void**)((char*)lbl_8053AD98 + 0xc);
    }
    return (void*)4;
}


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

extern "C" void fn_803EDA2C(void* subObj);
extern "C" void fn_803FC46C(void* subObj);

extern "C" void fn_803A8664(void* this_) {
    if (*(u8*)((char*)lbl_8053AAF8[0] + 0x7f) != 0) {
        fn_803EDA2C(*(void**)((char*)this_ + 0x4));
    } else {
        fn_803FC46C(*(void**)((char*)this_ + 0x8));
    }
}

extern u8 lbl_80529DEC[];
extern "C" void fn_803EDBF0(void* subObj, s32 mode);
extern "C" void fn_803FC5E4(void* subObj, s32 mode);

extern "C" void fn_803A86A4(void* this_) {
    *(s32*)((char*)this_ + 0xc) = 4;
    u8 st = lbl_80529DEC[0x237];
    if (st == 3 || st == 4) {
        if (*(u8*)((char*)lbl_8053AAF8[0] + 0x7f) != 0) {
            if (*(u8*)((char*)lbl_8053AAF8[0] + 0x7e) == 0) {
                fn_803EDBF0(*(void**)((char*)this_ + 0x4), 2);
            } else {
                fn_803EDBF0(*(void**)((char*)this_ + 0x4), 1);
            }
            st = lbl_80529DEC[0x237];
            if (st == 3) {
                lbl_80529DEC[0x237] = 9;
            } else if (st == 4) {
                lbl_80529DEC[0x237] = 7;
            } else {
                lbl_80529DEC[0x237] = 0;
            }
        } else {
            fn_803FC5E4(*(void**)((char*)this_ + 0x8), 1);
            lbl_80529DEC[0x237] = 0;
        }
    } else {
        if (*(u8*)((char*)lbl_8053AAF8[0] + 0x7f) != 0) {
            fn_803EDBF0(*(void**)((char*)this_ + 0x4), 0);
        } else {
            fn_803FC5E4(*(void**)((char*)this_ + 0x8), 0);
        }
        lbl_80529DEC[0x237] = 0;
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
        lbl_8053AD98 = NULL;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct T85ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
extern char* lbl_8053AB10;
extern char* lbl_8053AF80;
extern "C" void fn_802FF798(void* mgr);
extern "C" void fn_802F9714(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_802F93F4(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_803EE254(void* obj);
extern "C" void fn_803FCBC4(void* obj);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern "C" void fn_80458408(void* obj, u32 id, s32 a);
extern "C" u8 fn_804580DC(void* obj, s32 a);
extern "C" void fn_80458090(void* obj);

#define T85_RES (*(T85ResMgr**)((char*)lbl_8053AAF8[0] + 0xa4))

extern "C" void* fn_803A8884(void* this_) {
    *(void**)this_ = lbl_804AF878;
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
    *(s32*)((char*)this_ + 0xc) = 4;
    if (lbl_80529DEC[0x242] == 0) {
        lbl_80529DEC[0x242] = 1;
        fn_802FF798(*(void**)(lbl_8053AB10 + 0x20));
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), T85_RES->get('SCH ', "gb_ch_obj_base_sch.szs"), 0, 0, 0, 0);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), T85_RES->get('SCH ', "gb_ch_obj_tr_schE.szs"), 0, 0, 0x7000, 0);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), T85_RES->get('SCL ', "cu_cl_obj_base_scl.szs"), 0, 0, 0, 0, 0);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), T85_RES->get('SCH ', "player_sch.szs"), 0, 2, 0x4000, 0);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), T85_RES->get('SCL ', "cu_cl_obj_base_scl.szs"), 0, 2, 0, 0, 0);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), T85_RES->get('SCH ', "gals_sch.szs"), 0, 3, 0, 0);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), T85_RES->get('SCL ', "cu_cl_obj_base_scl.szs"), 0, 3, 0, 0, 0);
    }
    *(u8*)(*(char**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    void* o = __nw__FUl(0x364);
    if (o != NULL) {
        fn_803EE254(o);
    }
    *(void**)((char*)this_ + 0x4) = o;
    o = __nw__FUl(0x354);
    if (o != NULL) {
        fn_803FCBC4(o);
    }
    *(void**)((char*)this_ + 0x8) = o;
    if (*(u32*)(lbl_8053AF80 + 0x58) != 0x100001a) {
        fn_80458FF0(lbl_8053AF80, 0x100001a, 0, 0);
        fn_80458408(lbl_8053AF80, 0x100001a, 1);
        lbl_80529DEC[0x248] = 1;
    } else if (lbl_80529DEC[0x248] != 1) {
        fn_80458408(lbl_8053AF80, 0x100001a, 1);
        lbl_80529DEC[0x248] = 1;
    }
    if (!fn_804580DC(*(void**)(lbl_80529DEC + 0xc), 3)) {
        fn_80458090(lbl_8053AF80);
    }
    lbl_8053AD98 = this_;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
