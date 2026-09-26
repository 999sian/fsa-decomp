// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801769D8-80179150 (WIZR). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80178D24.cpp
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);

extern "C" void fn_80178D24(void* this_) {
    char* p = (char*)this_;
    u16 kind = *(u16*)(p + 0x94);
    if (kind == 0 || (u16)(kind - 4) <= 1 || (u16)(kind - 1) <= 1 || kind == 3) {
        s32 id = *(s32*)(p + 0x268);
        if (id >= 0) {
            void* base = fn_801F856C();
            void* found = fn_801F666C(base, id);
            if (found != 0) {
                *(s32*)(p + 0x268) = -1;
                *(s32*)((char*)found + 0x108) = 0;
            }
        }
    }
    *(s32*)(p + 0x238) = 0;
    *(char*)(p + 0x2e4) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x230) = 8;
}

// from src/Game/fn_80178DD0_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* table, s32 index);
extern void* lbl_804A0EDC[];

extern "C" void* fn_80178DD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0EDC;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x300));
        fn_801EE434(*(void**)(p + 0x304));
        fn_801EE434(*(void**)(p + 0x308));
        u16 state = *(u16*)(p + 0x94);
        if (state == 0 || (u16)(state - 4) <= 1 || (u16)(state - 1) <= 1 || state == 3) {
            s32 idx = *(s32*)(p + 0x268);
            if (idx >= 0) {
                void* table = fn_801F856C();
                void* found = fn_801F666C(table, idx);
                if (found != 0) {
                    *(s32*)(p + 0x268) = -1;
                    *(s32*)((char*)found + 0x108) = 0;
                }
            }
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
