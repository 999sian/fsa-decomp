// TU 0x802144f0-0x802153a8.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry.h"

// ---- fn_80214900.cpp ----
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void* fn_8013C824();
extern "C" void fn_800EC240(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);

extern "C" void fn_80214900(void* this_) {
    char* p = (char*)this_;
    s32 id = *(s32*)(p + 0x30);
    if (id >= 0) {
        void* base = SpatialRegistry_GetBase();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(u8*)((char*)found + 0x11c) = 0;
        }
        *(s32*)(p + 0x30) = -1;
    }
    if (*(u32*)(p + 0x18) != 0) {
        void* table = fn_8013C824();
        fn_800EC240(*(void**)((char*)table + 0xc), *(s32*)(p + 0x18));
        *(s32*)(p + 0x18) = 0;
    }
    fn_801CDC8C(*(void**)(p + 0x34), 0x4000E);
}

// ---- Slk2_InitVtablePairRecord.cpp ----
// Slk2_InitVtablePairRecord(this) - initializes a small record with TWO pointer-typed
// fields (+0x4, +0x1c) - each is installed with an interposed value
// (lbl_8049C178) that's IMMEDIATELY overwritten by a second, final value
// (lbl_804A64A8) - the same base-overridden-by-derived double-install
// pattern documented in project_fsa_multiple_inheritance_pattern.md,
// applied to two separate pointer slots within this one record rather
// than the record's own primary vtable. Also zeroes +0x0/+0x14/+0x18/
// +0x2c/+0x34 and sets +0x30=-1. Embedded by SLK2 at its own +0x4ec.
// Declared as functions (not data objects) so MWCC never treats these
// address-only references as small-data-relative - the actual symbols
// live in plain .data (vtables), not .sdata/.sbss, and a bare `extern
// void*` scalar declaration triggers MWCC's small-data-eligible
// heuristic regardless of the real section (same class of bug as the
// "large-bss-struct declared as bare scalar" case in
// project_fsa_phase4_kickoff.md's second batch).
extern "C" void lbl_8049C178();
extern "C" void lbl_804A64A8();

extern "C" {

void Slk2_InitVtablePairRecord(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x0) = 0;
	*(void**)(p + 0x4) = (void*)lbl_8049C178;
	*(void**)(p + 0x4) = (void*)lbl_804A64A8;
	*(u8*)(p + 0x14) = 0;
	*(u32*)(p + 0x18) = 0;
	*(void**)(p + 0x1c) = (void*)lbl_8049C178;
	*(void**)(p + 0x1c) = (void*)lbl_804A64A8;
	*(u8*)(p + 0x2c) = 0;
	*(s32*)(p + 0x30) = -1;
	*(u32*)(p + 0x34) = 0;
}

}

extern "C" void __dt__19JPAParticleCallBackFv(void* this_, s16 flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_8013CC50(f32 scale, u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
class JPABaseEmitter;
class JPAEmitterManager {
public:
    void forceDeleteEmitter(JPABaseEmitter*);
};
extern const f32 lbl_8053FBA0;
extern const f32 lbl_8053FBA4;

static inline void spawn(u8* o, s32 id, s32 f) {
    fn_8013CC50(lbl_8053FBA4, *(u32*)(o + 4), o + 0xc, id, 0, f, 0, 0, 1);
}

static inline void spawn2(u8* self, s32 id, s32 f) {
    u8* o = *(u8**)(self + 0x34);
    fn_8013CC50(lbl_8053FBA4, *(u32*)(o + 4), o + 0xc, id, 0, f, 0, 0, 1);
}

static inline void spawn3(void* pos, u32 owner, s32 id, s32 f) {
    fn_8013CC50(lbl_8053FBA4, owner, pos, id, 0, f, 0, 0, 1);
}

struct CbActor {
    u8 _0[4];
    u32 mId;
    u8 _8[4];
    f32 mPos[3];
};
static inline u32 cbOwner(u8* o) { return ((CbActor*)o)->mId; }
static inline u32& cbOwnerR(u8* o) { return ((CbActor*)o)->mId; }
static inline f32* cbPos(u8* o) { return ((CbActor*)o)->mPos; }
static inline f32* cbPosR(u8* o) { return &((CbActor*)o)->mPos[0]; }

static inline void killEmitter(JPABaseEmitter** pe) {
    if (*pe != 0) {
        JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
        mgr->forceDeleteEmitter(*pe);
        *pe = 0;
    }
}

static inline void releaseId(u8* p) {
    s32 id = *(s32*)(p + 0x30);
    if (id >= 0) {
        u8* a = (u8*)fn_801F666C(fn_801F856C(), id);
        if (a != 0) {
            a[0x11c] = 0;
        }
        *(s32*)(p + 0x30) = -1;
    }
}

static inline void cleanup(u8* p) {
    killEmitter((JPABaseEmitter**)(p + 0));
    releaseId(p);
    killEmitter((JPABaseEmitter**)(p + 0x18));
    fn_801CDC8C(*(void**)(p + 0x34), 0x4000e);
}

extern "C" {

void fn_802144F0(u8* this_) {
    fn_801F0E34(*(void**)(this_ + 0x34), 0x400c3, 0);
    u8* o = *(u8**)(this_ + 0x34);
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(o + 0xc));
    pos.y += lbl_8053FBA0;
    fn_8013CC50(lbl_8053FBA4, *(u32*)(o + 4), &pos, 0x3cf, 0, 0, 0, 0, 1);
}

void fn_802146A4(u8* this_) {
    u8* o = *(u8**)(this_ + 0x34);
    s32 f = 0;
    if (*(u32*)(o + 0x524) & 0x400) {
        f = 1;
    }
    fn_8013CC50(lbl_8053FBA4, cbOwner(o), cbPos(o), 0x416, 0, f - 1, 0, 0, 1);
    fn_8013CC50(lbl_8053FBA4, cbOwner(*(u8**)(this_ + 0x34)), cbPos(*(u8**)(this_ + 0x34)), 0x417, 0, f, 0, 0, 1);
}

void* dtor_80214F9C(u8* this_, s16 flag) {
    if (this_ != 0) {
        cleanup(this_);
        if (this_ + 0x1c != 0) {
            *(void**)(this_ + 0x1c) = (void*)lbl_804A64A8;
            __dt__19JPAParticleCallBackFv(this_ + 0x1c, 0);
        }
        if (this_ + 0x4 != 0) {
            *(void**)(this_ + 0x4) = (void*)lbl_804A64A8;
            __dt__19JPAParticleCallBackFv(this_ + 0x4, 0);
        }
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

void* dtor_802150FC(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = (void*)lbl_804A64A8;
        __dt__19JPAParticleCallBackFv(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

void fn_8021515C(u8* this_, void* emitter, u8* particle) {
    if (this_[0x10] == 0) {
        *(f32*)(particle + 0x18) = *(f32*)(this_ + 0x4);
        *(f32*)(particle + 0x1c) = *(f32*)(this_ + 0x8);
        *(f32*)(particle + 0x20) = *(f32*)(this_ + 0xc);
    }
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
