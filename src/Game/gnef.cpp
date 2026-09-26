// TU 0x802ed538-0x802eec50 (actor GNEF).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gnef_CueHelpers_802ED7D8.cpp ----
// Gnef_SetCueFlag - GNEF: cue-flag setter. Sets flag byte this->0x275=0xff
// and increments counter this->0x24c.
//
// Gnef_QueryCueState - GNEF: cue-state query. If this->0x24c < 0xb (11),
// returns 0. Otherwise checks/sets a latch byte at this->0x274 based
// on the incoming float param vs this->0x270 or a fixed threshold
// constant, returning the latch value.
extern "C" {

extern f32 lbl_80541400;

void Gnef_SetCueFlag(void* thisObj) {
	*(u8*)((char*)thisObj + 0x275) = 0xff;
	*(u32*)((char*)thisObj + 0x24c) += 1;
}

u8 Gnef_QueryCueState(void* thisObj, f32 value) {
	if (*(s32*)((char*)thisObj + 0x24c) < 0xb) {
		return 0;
	}
	if (*(u8*)((char*)thisObj + 0x274) != 0) {
		*(f32*)((char*)thisObj + 0x270) = value;
	} else {
		if (lbl_80541400 == value) {
			*(u8*)((char*)thisObj + 0x274) = 1;
		}
	}
	return *(u8*)((char*)thisObj + 0x274);
}

}

// fn_802ED7F0 - GNEF: latch a target value once the state reaches 11.

extern "C" u8 fn_802ED7F0(char* p, f32 v) {
    if (*(s32*)(p + 0x24c) < 11) {
        return 0;
    }
    if (*(u8*)(p + 0x274) != 0) {
        *(f32*)(p + 0x270) = v;
    } else if (lbl_80541400 == v) {
        *(u8*)(p + 0x274) = 1;
    }
    return *(u8*)(p + 0x274);
}

// ---- Gnef_dtor_802EE630.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA350[];

extern "C" void* fn_802EE630(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA350;
        void* h0 = *(void**)((char*)this_ + 0x230);
        if (h0) {
            fn_801EE434(h0);
        }
        void* h1 = *(void**)((char*)this_ + 0x234);
        if (h1) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)((char*)this_ + 0x238);
        if (h2) {
            fn_801EE434(h2);
        }
        void* h3 = *(void**)((char*)this_ + 0x23c);
        if (h3) {
            fn_801EE434(h3);
        }
        void* h4 = *(void**)((char*)this_ + 0x240);
        if (h4) {
            fn_801EE434(h4);
        }
        void* h5 = *(void**)((char*)this_ + 0x244);
        if (h5) {
            fn_801EE434(h5);
        }
        void* h6 = *(void**)((char*)this_ + 0x248);
        if (h6) {
            fn_801EE434(h6);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_802ED834: draw
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
extern u8* lbl_8053AB10;
extern "C" void fn_802F745C(void*, void*, void*, DrawRec*);

extern "C" void fn_802ED834(u8* this_) {
    if (*(void**)(this_ + 0x2cc) != 0) {
        DrawRec rec;
        rec.b1c = 0;
        *(s8*)&rec.b1d = -3;
        rec.b24 = 1;
        rec.b23 = 1;
        rec.b21 = 1;
        s32 id = *(s32*)(this_ + 4);
        void* res = *(void**)(this_ + 0x2cc);
        if (id < 8) {
            fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, &rec);
        }
    }
}

// ---- fn_802EE704: link to WARP / SLR4 actors
class GnefActor {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual s32 v3C();
    u8 pad04[0x08];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x1a0 - 0x18];
    u32 mName; // 0x1a0
};
struct GnefActorMgr {
    u8 pad00[8];
    GnefActor* mActors[0x400]; // 0x08
    s32 mCount; // 0x1008
};
extern "C" GnefActorMgr* fn_801F856C(void);
extern f32 lbl_80541404;
extern "C" void fn_802EEA24(u8 v);

struct GnefObj {
    u8 pad00[0xc];
    f32 x, y;
    u8 pad14[0x25c - 0x14];
    s32 m25C;
    s32 m260[2];
};
extern "C" void fn_802EE704(GnefObj* this_) {
    s32 count = fn_801F856C()->mCount;
    for (s32 i = 0; i < count; i++) {
        GnefActor* a = fn_801F856C()->mActors[i];
        if (a != 0 && a->mName == 'WARP' && this_->m25C == a->v3C()) {
            JGeometry::TVec3f pos = a->mPos;
            pos.x = this_->x;
            pos.y = lbl_80541404 + this_->y;
            a->mPos = pos;
        }
    }
    s32 n = 0;
    for (s32 j = 0; j < count; j++) {
        GnefActor* a = fn_801F856C()->mActors[j];
        if (a != 0 && a->mName == 'SLR4') {
            this_->m260[n] = j;
            n++;
            fn_802EEA24(1);
            if (n >= 2) {
                break;
            }
        }
    }
}

// fn_802EEA24 - GNEF: set global flag byte.
extern u8 lbl_8053AB60;
extern "C" void fn_802EEA24(u8 v) { lbl_8053AB60 = v; }

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
