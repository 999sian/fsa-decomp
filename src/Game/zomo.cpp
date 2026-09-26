// TU 0x802ec73c-0x802ecad4 (actor ZOMO).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Zomo_dtor_802EC73C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA228[];

extern "C" void* fn_802EC73C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA228;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Zomo_EmptyHook.cpp ----
// Zomo_EmptyHook - ZOMO: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Zomo_EmptyHook(void) {}

}

// fn_802EC7A0 - ZOMO: update(). Uses an inline "request" helper on the
// object at global->0x24 (sets +0x7f5 when +0x7f4 is clear).
struct ZomoTarget {
    u8 pad[0x7f4];
    u8 busy;
    u8 request;
    inline bool tryRequest() {
        bool ok = false;
        if (busy == 0) {
            ok = true;
            request = 1;
        }
        return ok;
    }
};
struct ZomoVT {
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
    virtual u8 check();
};
extern char* lbl_8053AB10;
#define ZOMO_TARGET (*(ZomoTarget**)(lbl_8053AB10 + 0x24))

extern "C" void fn_802EC7A0(void* this_) {
    switch (*(s32*)((char*)this_ + 0x230)) {
    case 0:
        if (((ZomoVT*)this_)->check()) {
            ZOMO_TARGET->tryRequest();
            if (ZOMO_TARGET->tryRequest() == true) {
                *(s32*)((char*)this_ + 0x230) = 1;
                *(s32*)((char*)this_ + 0x238) = *(s32*)((char*)this_ + 0x234);
            }
        }
        break;
    case 1:
        ZOMO_TARGET->tryRequest();
        *(s32*)((char*)this_ + 0x238) = *(s32*)((char*)this_ + 0x238) - 1;
        if (*(s32*)((char*)this_ + 0x238) == 0) {
            *(u8*)((char*)this_ + 0x11c) = 0;
        }
        break;
    }
}

// ---- Zomo_SetParams.cpp ----
#include "Game/esd/Actor.h"

// ZOMO: setParams.
extern "C" {
void Zomo_SetParams(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 v = ((Actor*)thisPtr)->spawnParam;
	*(u32*)(p + 0x234) = v & 0xFFF;
	*(s32*)(p + 0x238) = 0;
	*(s32*)(p + 0x230) = 0;
}
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
