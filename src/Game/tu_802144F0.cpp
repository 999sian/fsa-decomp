// TU 0x802144f0-0x802153a8.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry.h"

// ---- fn_80214900.cpp ----
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void* fn_801F856C(void);
extern "C" u8 fn_801CD2F8(void* p);
extern "C" f32 fn_802F5E9C(void*, const f32*);
extern "C" void fn_8013CB44(void* a, JGeometry::TVec3f* b, s32 c, s32 d, s32 e);
extern const f32 lbl_8053FBBC;
extern const f32 lbl_8053FBC0;
extern char* lbl_8053AB10;
extern "C" void* fn_8013C824();
extern "C" void fn_800EC240(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);
extern const f32 lbl_8053FBD0;
extern "C" u8* fn_8013CC50(f32 scale, u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 event, s32 arg);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* em);

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

extern "C" void fn_80214994(void* this_)
{
	char* p = (char*)this_;
	JGeometry::TVec3f v;
	char* q = *(char**)(p + 0x34);

	v = *(JGeometry::TVec3f*)(q + 0xc);
	v.y += lbl_8053FBBC;
	if (fn_801CD2F8(*(void**)(q + 0x4))) {
		s32 id = *(s32*)(p + 0x30);
		if (id >= 0) {
			char* found = (char*)fn_801F666C(fn_801F856C(), id);
			if (found != 0) {
				*(JGeometry::TVec3f*)(found + 0xc) = v;
			}
		}
	} else {
		if (*(void**)(p + 0x18) != 0) {
			s32 a = 0;
			s32 b = 1;
			if (v.z > lbl_8053FBC0) {
				a = b;
				b = 0;
			}
			s32 lim = (a << 10) + (b << 7);
			f32 x = v.x;
			f32 y = v.y + lim;
			f32 z = v.z + lim;
			f32 w = fn_802F5E9C(*(void**)(lbl_8053AB10 + 0x20), &v.x);
			*(f32*)(p + 0x20) = x;
			*(f32*)(p + 0x24) = y;
			*(f32*)(p + 0x28) = z + (w - v.z);
			fn_8013CB44(*(void**)(p + 0x18), &v, 0, 1, 1);
		}
	}
}

extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* em);
extern "C" void fn_80214CE4(u8* this_) {
    if (*(u8**)(this_ + 0) != 0) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(*(u8**)(this_ + 0x34) + 0xc));
        pos.y += -24.0f;
        s32 lo = 1;
        s32 hi = 0;
        if (pos.z > 0.0f) {
            hi = lo;
            lo = 0;
        }
        f32 off = (hi << 10) + (lo << 7);
        f32 x = pos.x;
        f32 y = pos.y + off;
        f32 z = pos.z + off;
        f32 d = fn_802F5E9C(*(void**)(lbl_8053AB10 + 0x20), &pos.x) - pos.z;
        *(f32*)(this_ + 0x8) = x;
        *(f32*)(this_ + 0xc) = y;
        z += d;
        *(f32*)(this_ + 0x10) = z;
        fn_8013CB44(*(void**)(this_ + 0), &pos, 0, 1, 1);
        bool del = false;
        if (*(u32*)(*(u8**)(this_ + 0) + 0xf4) & 0x8) {
            if (*(s32*)(*(u8**)(this_ + 0) + 0xd0) + *(s32*)(*(u8**)(this_ + 0) + 0xdc) == 0) {
                del = true;
            }
        }
        if (del && *(u8**)(this_ + 0) != 0) {
            void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(this_ + 0));
            *(u8**)(this_ + 0) = 0;
        }
    }
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
extern "C" u8* fn_8013CC50(f32 scale, u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" f32 fn_802F5E9C(void*, const f32*);
extern char* lbl_8053AB10;
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

void fn_80214578(u8* this_) {
    u8* o = *(u8**)(this_ + 0x34);
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(o + 0xc));
    switch (*(s32*)(o + 0x98)) {
    case 0:
        pos.x -= 24.0f;
        break;
    case 1:
        pos.x += 24.0f;
        break;
    case 2:
        pos.x += 2.0f;
        pos.y -= 26.0f;
        break;
    case 3:
        pos.x -= 4.0f;
        pos.y += 18.0f;
        break;
    }
    fn_8013CC50(lbl_8053FBA4, *(u32*)(*(u8**)(this_ + 0x34) + 4), &pos, 0xcb, 0, 1, 0, 0, 1);
    fn_8013CC50(lbl_8053FBA4, *(u32*)(*(u8**)(this_ + 0x34) + 4), &pos, 0xcc, 0, 1, 0, 0, 1);
}

void fn_802146A4(u8* this_) {
    u8* o = *(u8**)(this_ + 0x34);
    s32 f = 0;
    if (*(u32*)(o + 0x524) & 0x400) {
        f = 1;
    }
    fn_8013CC50(lbl_8053FBA4, *(u32*)(o + 4), o + 0xc, 0x416, 0, f - 1, 0, 0, 1);
    o = *(u8**)(this_ + 0x34);
    fn_8013CC50(lbl_8053FBA4, *(u32*)(o + 4), o + 0xc, 0x417, 0, f, 0, 0, 1);
}

extern "C" u8* fn_801C0D70(void* o);
extern "C" void fn_801CDCD0(u8* o, u32 owner, void* pos, s32 id);
extern const u16 lbl_8053FB90[];
extern const u16 lbl_8053FB98[];
extern const u16 lbl_8053FB90[3];
extern const u16 lbl_8053FB98[3];
extern "C" void fn_80214740(u8* this_, u32 owner, void* pos, u8 flag) {
    u8* o = *(u8**)(this_ + 0x34);
    bool f = (*(u32*)(o + 0x524) & 0x400) != 0;
    if (*(s32*)(fn_801C0D70(o) + 0x50) >= 0) {
        fn_8013CC50(lbl_8053FBA4, owner, pos, 0x1d6, 0, f, 0, 0, 1);
        fn_8013CC50(lbl_8053FBA4, owner, pos, 0x1d7, 0, f, 0, 0, 1);
        fn_8013CC50(lbl_8053FBA4, owner, pos, 0x1d8, 0, f, 0, 0, 1);
        fn_8013CC50(lbl_8053FBA4, owner, pos, 0x1d9, 0, f, 0, 0, 1);
        fn_801F0E34(o, 0x400d6, 0);
    } else {
        const u16* ids = lbl_8053FB90;
        if (flag) {
            ids = lbl_8053FB98;
        }
        fn_8013CC50(lbl_8053FBA4, owner, pos, ids[0], 0, f - 1, 0, 0, 1);
        fn_8013CC50(lbl_8053FBA4, owner, pos, ids[1], 0, f, 0, 0, 1);
        fn_8013CC50(lbl_8053FBA4, owner, pos, ids[2], 0, f, 0, 0, 1);
        s32 id = 0x40048;
        if (flag) {
            id = 0x4004e;
        }
        fn_801CDCD0(o, owner, pos, id);
    }
}

void fn_80214E50(u8* this_) {
    if (*(u8**)(this_ + 0) == 0) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(*(u8**)(this_ + 0x34) + 0xc));
        pos.y += -24.0f;
        s32 lo = 1;
        s32 hi = 0;
        if (pos.z > 0.0f) {
            hi = lo;
            lo = 0;
        }
        f32 off = (hi << 10) + (lo << 7);
        f32 x = pos.x;
        f32 y = pos.y + off;
        f32 z = pos.z + off;
        f32 d = fn_802F5E9C(*(void**)(lbl_8053AB10 + 0x20), &pos.x) - pos.z;
        *(f32*)(this_ + 0x8) = x;
        *(f32*)(this_ + 0xc) = y;
        z += d;
        *(f32*)(this_ + 0x10) = z;
        *(u8**)(this_ + 0) = fn_8013CC50(lbl_8053FBA4, *(u32*)(*(u8**)(this_ + 0x34) + 4), &pos, 0x33b, 0, 1, 0, (s32)(this_ + 4), 1);
        u8* e = *(u8**)(this_ + 0);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 0x40;
        }
    }
}

void* dtor_80214F9C(void* this_, s16 flag) {
    u8* p = (u8*)this_;
    if (p != 0) {
        cleanup(p);
        if (p + 0x1c != 0) {
            *(void**)(p + 0x1c) = (void*)lbl_804A64A8;
            __dt__19JPAParticleCallBackFv(p + 0x1c, 0);
        }
        if (p + 0x4 != 0) {
            *(void**)(p + 0x4) = (void*)lbl_804A64A8;
            __dt__19JPAParticleCallBackFv(p + 0x4, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
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
