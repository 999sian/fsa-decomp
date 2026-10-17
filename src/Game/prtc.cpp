// TU 0x802e0ab4-0x802e1b40 (actor PRTC).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

static inline void* PrtcSpawn(char* p, s32 id, s32 a) {
    f32 pos[3];
    pos[0] = *(f32*)(p + 0xc) + *(f32*)(p + 0x244);
    pos[1] = *(f32*)(p + 0x10) + *(f32*)(p + 0x248);
    pos[2] = 0.0f;
    return fn_8013CC50(*(s32*)(p + 4), pos, id, a, 0, 0, 0, 1, 1.0f);
}

static inline void PrtcNotify(char* p) {
    s32 phase = *(s32*)(p + 0x250);
    if (phase == 6 || phase == 8) {
        s32 code = 0x30074;
        void* obj = *(void**)(p + 0x230);
        ((void (*)(void*, s32*))(*(void***)((char*)obj + 8))[5])(obj, &code);
    }
}

extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

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
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
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
    virtual void v5(void* arg);
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
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
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
