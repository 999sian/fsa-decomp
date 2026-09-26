// TU 0x802ecad4-0x802ed140 (actor SDSM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Sdsm_EmptyHook.cpp ----
// Sdsm_EmptyHook - SDSM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Sdsm_EmptyHook(void) {}

}

// ---- Sdsm_dtor_802ECD0C.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA280[];

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

extern "C" void* fn_802ECD0C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA280;
        void* handle = *(void**)((char*)this_ + 0x234);
        if (handle) {
            fn_801EE434(handle);
        }
        void* sub = *(void**)((char*)this_ + 0x230);
        if (sub) {
            NotifySub(sub, 1);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
