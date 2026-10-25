// TU 0x803a60e4-0x803a85e4.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JFramework/JFWDisplay.h"
#include "JSystem/J2D/J2DScreen.h"

extern void* lbl_8053AAF8;
extern "C" void fn_80402E08(void* a, f32 b, f32 c);

// ---- from src/Game/Dtor_lbl804AF860_803A7708.cpp ----
// fn_803A7708 - actor@lbl_804AF860's destructor. Calls getTotalFreeSize__7JKRHeapFv on
// a manager sub-object (lbl_80529DEC->0x8), then releases 8 embedded
// sub-objects (this->0x4/0x8, a 6-element array at this->0xc-0x20,
// then this->0x24/0x28/0x2c/0x30) via own vtable slot 0 (byte offset
// 0x8), clearing each afterward. Zeroes the global lbl_8053AD90, then
// conditionally forwards to __dl__FPv. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why the
// releases go through a real `virtual` member rather than a manual
// cast.
extern "C" void getTotalFreeSize__7JKRHeapFv(void* p);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF860[];
extern u8 lbl_80529DEC[];
extern char* lbl_8053AD90;

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_803A7708(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF860;
        void* mgr = *(void**)((u8*)lbl_80529DEC + 0x8);
        getTotalFreeSize__7JKRHeapFv(mgr);
        void* p;
        p = *(void**)((char*)this_ + 0x4);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        *(void**)((char*)this_ + 0x4) = 0;
        p = *(void**)((char*)this_ + 0x8);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        *(void**)((char*)this_ + 0x8) = 0;
        for (s32 i = 0; i < 6; i++) {
            void* q = *(void**)((char*)this_ + 0xc + 4 * i);
            if (q != 0) { ((Slot0*)q)->slot0(1); }
            *(void**)((char*)this_ + 0xc + 4 * i) = 0;
        }
        p = *(void**)((char*)this_ + 0x24);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        *(void**)((char*)this_ + 0x24) = 0;
        p = *(void**)((char*)this_ + 0x28);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        *(void**)((char*)this_ + 0x28) = 0;
        p = *(void**)((char*)this_ + 0x2c);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        *(void**)((char*)this_ + 0x2c) = 0;
        p = *(void**)((char*)this_ + 0x30);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        *(void**)((char*)this_ + 0x30) = 0;
        lbl_8053AD90 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_803A65EC() {
    if (lbl_8053AD90 != 0) {
        return *(s32*)(lbl_8053AD90 + 0x80);
    }
    return 5;
}

extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void fn_803832BC(char* a, s32 b, int c, int d, int e);
extern void* lbl_8053AAF8;
static inline f32 tuRandFloat() {
    u8* g = (u8*)lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    return *(f32*)&bits - 1.0f;
}
extern "C" void fn_8013B490(void* obj);
extern "C" void fn_80440EE8(void* obj);
struct Game8053AB10 { u8 pad[0x10]; J2DGrafContext* graf; };
extern Game8053AB10* lbl_8053AB10;
extern void* lbl_8053AED8;

extern "C" void fn_803A71F0(char* p) {
    JFWDisplay::getManager()->setClearColor(JUtility::TColor(0, 0, 0, 0));
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(p + 0x4))->draw(0.0f, 0.0f, lbl_8053AB10->graf);
    fn_80440EE8(lbl_8053AED8);
}

extern "C" void fn_803A7280(char* p) {
    *(u32*)(p + 0x64) = 0;
    *(u16*)(p + 0x68) = 0;
    *(u8*)(p + 0x76) = 0;
    fn_80402E08(*(void**)(p + 0x8), 0.0f, -448.0f);
    *(u16*)(*(char**)(p + 0x8) + 0x22) = 0;
    for (s32 i = 0; i < 6; i++) {
        fn_80402E08(*(void**)(p + 0xc + i * 4), 0.0f, -448.0f);
        *(u16*)(*(char**)(p + 0xc + i * 4) + 0x22) = 0;
    }
    for (s32 i = 0; i < 2; i++) {
        fn_80402E08(*(void**)(p + 0x24 + i * 4), 0.0f, -448.0f);
        *(u16*)(*(char**)(p + 0x24 + i * 4) + 0x22) = 0;
    }
    fn_80402E08(*(void**)(p + 0x2c), 0.0f, -448.0f);
    *(u16*)(*(char**)(p + 0x2c) + 0x22) = 0;
    fn_80402E08(*(void**)(p + 0x30), 0.0f, -448.0f);
    *(u16*)(*(char**)(p + 0x30) + 0x22) = 0;
    fn_80402E08(*(void**)(p + 0x34), 0.0f, -448.0f);
    *(u16*)(*(char**)(p + 0x34) + 0x22) = 0;

    *(u8*)(p + 0x77) = lbl_80529DEC[0x245];
    *(u8*)(p + 0x78) = lbl_80529DEC[0x246];
    if (*(u8*)(p + 0x77) == 1) {
        fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(p + 0x4))->search(0x54736f3032ULL))->getStringPtr(), 0x98, 0, 0, 0);
    } else {
        fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(p + 0x4))->search(0x54736f3032ULL))->getStringPtr(), 0x99, 0, 0, 0);
    }
    if (*(u8*)(p + 0x78) == 1) {
        fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(p + 0x4))->search(0x5473693032ULL))->getStringPtr(), 0x38, 0, 0, 0);
    } else {
        fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(p + 0x4))->search(0x5473693032ULL))->getStringPtr(), 0x39, 0, 0, 0);
    }

    f32 h = (*(J2DScreen**)(p + 0x4))->search(0x5061723031ULL)->getHeight();
    J2DPane* w = (*(J2DScreen**)(p + 0x4))->search(0x5061723031ULL);
    (*(J2DScreen**)(p + 0x4))->search(0x5061723031ULL)->rotate(0.5f * w->getWidth(), 0.5f * h, J2DROTATE_Z, *(s16*)(p + 0x70) + *(s16*)(p + 0x74));
    h = (*(J2DScreen**)(p + 0x4))->search(0x5061723032ULL)->getHeight();
    w = (*(J2DScreen**)(p + 0x4))->search(0x5061723032ULL);
    (*(J2DScreen**)(p + 0x4))->search(0x5061723032ULL)->rotate(0.5f * w->getWidth(), 0.5f * h, J2DROTATE_Z, *(s16*)(p + 0x72) + *(s16*)(p + 0x74));

    *(s16*)(p + 0x6a) = (s32)(11.0f * tuRandFloat()) + 10;
    *(s16*)(p + 0x6c) = (s32)(11.0f * tuRandFloat()) + 10;
    *(s16*)(p + 0x6e) = 0;
    *(u8*)(p + 0x79) = 0;
    *(u8*)(p + 0x7a) = 10;
    *(u8*)(p + 0x7b) = 0xff;
    *(u8*)(p + 0x7c) = 0xc0;
    *(s32*)(p + 0x80) = 5;
}

extern void* lbl_804AF86C[];

extern "C" void* fn_803A8378(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF86C;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
