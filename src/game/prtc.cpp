// TU 0x802e0ab4-0x802e1b40 (actor PRTC).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Prtc_EmptyHook.cpp ----
// PRTC (vtable lbl_804A9AC8, ctor fn_80201E80) cluster, part 1/4. No
// separate leading static-init this time - PRTC's cluster begins
// immediately after URAC's tail static-init. Prtc_EmptyHook - empty
// override (bare blr), no extab.
extern "C" {

void Prtc_EmptyHook(void) {}

}

// ---- Prtc_dtor_802E1064.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9AC8[];

struct NonPolyBase {
    void* pad0;
    void* pad1;
};

struct NotifyTarget : NonPolyBase {
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
    virtual void Notify(int arg);
};

static inline void NotifySub(void* obj, int arg) {
    if (obj) {
        ((NotifyTarget*)obj)->Notify(arg);
    }
}

extern "C" void* Prtc_dtor(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9AC8;
        void* h0 = *(void**)((char*)this_ + 0x234);
        if (h0) {
            fn_801EE434(h0);
        }
        void* h1 = *(void**)((char*)this_ + 0x238);
        if (h1) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)((char*)this_ + 0x23c);
        if (h2) {
            fn_801EE434(h2);
        }
        void* sub = *(void**)((char*)this_ + 0x230);
        if (sub) {
            NotifySub(sub, 1);
        }
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
