// TU 0x802e4c74-0x802e5c44 (actor BLZ2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- VtableForward_802E4D20.cpp ----
extern "C" void fn_801F35AC(void* this_);

// fn_802E4D20 - BLZ2: virtual-call wrapper (slot 21, byte offset 0x54)
// + fn_801F35AC. See [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this calls through a real `virtual` member rather than a
// manual cast.
struct ActorSlot21 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void slot21();
};

extern "C" void fn_802E4D20(void* this_) {
    ((ActorSlot21*)this_)->slot21();
    fn_801F35AC(this_);
}

// ---- Blz2_dtor_802E5724.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9D28[];

extern "C" void* fn_802E5724(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9D28;
        for (int i = 0; i < 0x10; i++) {
            void* h0 = *(void**)((char*)this_ + 0x230 + i * 4);
            if (h0) {
                fn_801EE434(h0);
            }
            void* h1 = *(void**)((char*)this_ + 0x270 + i * 4);
            if (h1) {
                fn_801EE434(h1);
            }
            void* h2 = *(void**)((char*)this_ + 0x2b0 + i * 4);
            if (h2) {
                fn_801EE434(h2);
            }
        }
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
