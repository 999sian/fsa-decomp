// IWAG_800F46C0: .text 0x800F46C0-0x800F4C70 (actor IWAG)
// NOTE: IWAG has no __sinit/.ctors of its own and shares pooled .sdata2
// literals (1.0f, 50.0f, 0.0f, 10.0f, 4330 double) with OIWA_800F4C70, so
// IWAG+OIWA are most likely one TU (IWAG first). Must be merged before either
// can be Matching. fn_800F4724: only an r4/r5 swap in case 4 remains.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/fn_800F46C0_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C46C[];

extern "C" void* fn_800F46C0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C46C;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_800F4720: empty draw
extern "C" void fn_800F4720(void) {
}

struct IWAG_Random {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct IWAG_Game { u8 pad[0xb4]; IWAG_Random rnd; };
extern IWAG_Game* lbl_8053AAF8;

// ---- fn_800F4724: spawner update (periodically creates OIWA rocks)
class IWAG_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual u8 vf34();
};

extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" u8* fn_801F666C(void* mgr, s32 id);

extern "C" void fn_800F4724(u8* this_) {
    JGeometry::TVec3f pos;
    if (*(s32*)(this_ + 0x234) == 0) {
        switch (*(u8*)(this_ + 0x230)) {
        case 0:
            if ((*(u32*)(this_ + 0x90) & 0xF8000000) && !((IWAG_Actor*)this_)->vf34()) {
                return;
            }
            Actor_CreateByID(fn_801F856C(), 'OIWA', *(s32*)(this_ + 4), this_ + 0xC, 0, -1, -1);
            *(s32*)(this_ + 0x234) = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 150;
            break;
        case 1: {
            if ((*(u32*)(this_ + 0x90) & 0xF8000000) && !((IWAG_Actor*)this_)->vf34()) {
                return;
            }
            pos = *(JGeometry::TVec3f*)(this_ + 0xC);
            pos.z += 200.0f;
            s32 id = Actor_CreateByID(fn_801F856C(), 'OIWA', *(s32*)(this_ + 4), &pos, 1, -1, -1);
            u8* rock = fn_801F666C(fn_801F856C(), id);
            *(JGeometry::TVec3f*)(rock + 0x3C) = JGeometry::TVec3f(0.0f, -0.01f, 0.0f);
            *(s32*)(this_ + 0x234) = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 150;
            break;
        }
        case 2:
            Actor_CreateByID(fn_801F856C(), 'OIWA', *(s32*)(this_ + 4), this_ + 0xC, 3, -1, -1);
            *(u8*)(this_ + 0x11C) = 0;
            return;
        case 3:
            Actor_CreateByID(fn_801F856C(), 'OIWA', *(s32*)(this_ + 4), this_ + 0xC, (*(u32*)(this_ + 0x90) & ~0xFF) + 4, -1, -1);
            *(s32*)(this_ + 0x234) = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 150;
            break;
        case 4: {
            if ((*(u32*)(this_ + 0x90) & 0xF8000000) && !((IWAG_Actor*)this_)->vf34()) {
                return;
            }
            pos.x = *(f32*)(this_ + 0xC);
            pos.y = *(f32*)(this_ + 0x10);
            pos.z = *(f32*)(this_ + 0x14);
            pos.z += 200.0f;
            pos.x += 0x28 - (s32)(20.0f * lbl_8053AAF8->rnd.get());
            IWAG_Game* g = lbl_8053AAF8;
            pos.y += 0x14 - (s32)(10.0f * g->rnd.get());
            Actor_CreateByID(fn_801F856C(), 'OIWA', *(s32*)(this_ + 4), &pos, 5, -1, -1);
            *(s32*)(this_ + 0x234) = (s32)(150.0f * lbl_8053AAF8->rnd.get()) + 0x50;
            break;
        }
        }
    }
    *(s32*)(this_ + 0x234) -= 1;
}

// ---- fn_800F4B90: init (random start delay)

extern "C" void fn_800F4B90(u8* this_) {
    *(u8*)(this_ + 0x230) = *(u32*)(this_ + 0x90);
    if (*(u8*)(this_ + 0x230) == 2) {
        *(s32*)(this_ + 0x234) = 0;
    } else if (*(u8*)(this_ + 0x230) == 4) {
        *(s32*)(this_ + 0x234) = 100.0f * lbl_8053AAF8->rnd.get();
    } else {
        *(s32*)(this_ + 0x234) = 30.0f * lbl_8053AAF8->rnd.get();
    }
}
