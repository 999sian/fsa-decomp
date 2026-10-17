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

extern const f32 lbl_80541400;

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
extern const f32 lbl_80541404;
extern "C" void fn_802EEA24(u8 v);

struct GnefObj {
    u8 pad00[0xc];
    f32 x, y;
    u8 pad14[0x25c - 0x14];
    s32 m25C;
    s32 m260[2];
};
extern "C" void fn_802EE704(GnefObj* this_) {
    GnefActor* a;
    s32 count = fn_801F856C()->mCount;
    for (s32 i = 0; i < count; i++) {
        a = fn_801F856C()->mActors[i];
        if (a != 0 && a->mName == 'WARP' && this_->m25C == a->v3C()) {
            JGeometry::TVec3f pos = a->mPos;
            pos.x = this_->x;
            pos.y = lbl_80541404 + this_->y;
            a->mPos = pos;
        }
    }
    s32 n = 0;
    for (s32 j = 0; j < count; j++) {
        a = fn_801F856C()->mActors[j];
        if (a != 0 && a->mName == 'SLR4') {
            this_->m260[n++] = j;
            fn_802EEA24(1);
            if (n >= 2) {
                break;
            }
        }
    }
}

// ---- fn_802ED538: pull players toward the fan
#include "JSystem/JMath/JMath.h"
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_80236B50(s32);
extern "C" u8 fn_8023EA28(s32);
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8022D534(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" void fn_80230AD4(s32);
extern "C" void fn_8022CA6C(s32, s32, s32);
extern "C" u8 fn_8022D75C(s32);
extern "C" void fn_802303FC(s32, void*, s32);
extern "C" void fn_80230224(s32, s32);
extern const f32 lbl_80541408;
extern const f32 lbl_8054140C;
extern const f32 lbl_80541410;
extern const f32 lbl_80541414;
extern const f32 lbl_80541418;


static inline f32 gnefSqrt(f32 x) {
    if (x > lbl_80541400) {
        f32 y = __frsqrte(x);
        f32 t = y * x;
        return (lbl_80541408 - t * y) * t * lbl_8054140C;
    }
    return x;
}

struct GnefPull {
    u8 pad[0x27c];
    JGeometry::TVec3f pos; // 0x27c
    f32 dist;              // 0x288
    s16 angle;             // 0x28c
    u8 active;             // 0x28e
};

extern "C" u8 fn_802ED538(u8* this_) {
    u8 result = 1;
    GnefPull* pull = (GnefPull*)this_;
    for (s32 i = 0; i < 4; i++, pull = (GnefPull*)((u8*)pull + 0x14)) {
        if (fn_8023F264(i) && fn_8023DE58(i) == *(s32*)(this_ + 4) && !fn_80236B50(i)
            && !fn_8023EA28(i) && !fn_80230188(i) && !fn_8022D534(i) && !pull->active
            && fn_802300EC(i))
        {
            JGeometry::TVec3f* pp = fn_8023E724(i);
            f32 px = pp->x;
            f32 py = pp->y;
            if (lbl_80541400 == pp->z) {
                f32 dx = *(f32*)(this_ + 0xc) - px;
                f32 dy = (lbl_80541404 + *(f32*)(this_ + 0x10)) - py;
                pull->pos = *fn_8023E724(i);
                pull->dist = gnefSqrt(dx * dx + dy * dy);
                pull->angle = lbl_80541410 * JMAAtan2Radian(-dx, -dy);
                pull->active = 1;
                fn_80230AD4(i);
                fn_8022CA6C(i, 5, 0);
            }
        }
        if (pull->active && fn_80230188(i) && !fn_8022D75C(i)) {
            if (pull->dist > lbl_80541414) {
                pull->dist -= lbl_80541414;
            } else {
                pull->dist = lbl_80541400;
            }
            pull->pos.x = pull->dist * JMASinShort(pull->angle) + *(f32*)(this_ + 0xc);
            pull->pos.y = pull->dist * JMACosShort(pull->angle) + (lbl_80541404 + *(f32*)(this_ + 0x10));
            fn_802303FC(i, &pull->pos, 0xff);
            if (pull->dist < lbl_80541418) {
                fn_80230224(i, 0);
            }
        }
        if (fn_8023DE58(i) == *(s32*)(this_ + 4)) {
            result = 0;
        }
    }
    return result;
}

// ---- fn_802EE830: init
struct GnefSlot {
    f32 a, b, c, d;
    u16 e;
    u8 f;
};
extern void* lbl_804AA330[];
extern "C" void* fn_804032E8(u32 type, void* name);
extern "C" s32 fn_8013CC50(s32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);

class GnefSelf {
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
    virtual u8 v34();
    s32 m04;
    u8 pad08[4];
    f32 x, y, z; // 0x0c
    u8 pad18[0x90 - 0x18];
    u32 m90;
    u8 pad94[0x11c - 0x94];
    u8 m11C;
    u8 pad11D[2];
    u8 m11F;
    u8 pad120[0x230 - 0x120];
    s32 mHandles[7]; // 0x230
    s32 m24C;
    s32 m250;
    s32 m254;
    s32 m258;
    s32 m25C;
    s32 m260;
    s32 m264;
    f32 m268, m26C, m270;
    u8 m274;
    u8 m275;
    u8 m276;
    u8 m277;
    u8 m278;
    u8 m279;
    u8 pad27A[2];
    GnefSlot mSlots[4]; // 0x27c
    void* m2CC;
};

extern "C" void fn_802EE830(GnefSelf* this_) {
    this_->mHandles[0] = 0;
    this_->mHandles[1] = 0;
    this_->mHandles[2] = 0;
    this_->mHandles[3] = 0;
    this_->mHandles[4] = 0;
    this_->mHandles[5] = 0;
    this_->mHandles[6] = 0;
    this_->x = (s32)this_->x / 16 * 16 + 8;
    this_->m24C = 0;
    this_->m254 = (this_->m90 >> 17) & 3;
    this_->m250 = 0;
    this_->m258 = (this_->m90 >> 12) & 0x1f;
    this_->m25C = (this_->m90 >> 7) & 0x1f;
    this_->m276 = 0;
    this_->m277 = 0;
    this_->m278 = 0;
    this_->m268 = this_->x;
    this_->m26C = this_->y;
    this_->m270 = this_->z;
    this_->m26C -= lbl_80541404;
    this_->m260 = -1;
    this_->m264 = -1;
    this_->m275 = 0xff;
    this_->m279 = 0;
    if (this_->v34() == 1) {
        this_->m11C = 0;
        this_->m2CC = 0;
        this_->m24C = 0x10;
    } else {
        this_->m2CC = fn_804032E8('TIMG', lbl_804AA330[this_->m254]);
        this_->mHandles[0] = fn_8013CC50(this_->m04, &this_->x, 0x4e, 0, 0, 0, 0, 1, lbl_80541418);
    }
    for (int i = 0; i < 4; i++) {
        this_->mSlots[i].a = lbl_80541400;
        this_->mSlots[i].b = lbl_80541400;
        this_->mSlots[i].c = lbl_80541400;
        this_->mSlots[i].d = lbl_80541400;
        this_->mSlots[i].e = 0;
        this_->mSlots[i].f = 0;
    }
    this_->m11F = 1;
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
