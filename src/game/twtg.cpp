// TU 0x80313c20-0x80316e34 (actor TWTG).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"
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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"
#include "game/AnimEffectRec.h"

// ---- Twtg_ctor_80316A60.cpp ----
// fn_80316A60 - "TWTG" real constructor. Identical shape to FTGL/JIJI -
// see Ftgl_ctor_80317C38.cpp for the full technique writeup. Base Actor
// ctor + own vtable install, allocates a 0x1c-byte resource handle and
// resets it via ResetResourceHandleRecord if allocation succeeded,
// storing the handle (or null) at +0x278.



struct Actor {
    Actor();
    ~Actor();
};

extern "C" void ResetResourceHandleRecord(void* h);

class ResourceHandle {
public:
    ResourceHandle() { ResetResourceHandleRecord(this); }
    ~ResourceHandle();
private:
    unsigned char pad[0x1c];
};

extern "C" void* lbl_804AAD60[];

class Twtg : public Actor {
public:
    Twtg();
    void update();
};

struct TwtgPt { f32 x, y; };
struct TwtgBox { TwtgPt min, max; };
extern "C" void fn_80239914(TwtgBox* box, u32 room, u32 id);
typedef void (Twtg::*TwtgStateFn)();
extern TwtgStateFn lbl_804AACDC[];

// fn_80316754 - TWTG: update(). Refreshes the collision box and runs the
// state handler from the member-function table lbl_804AACDC.
void Twtg::update() {
    char* p = (char*)this;
    TwtgBox box;
    box.min.x = *(f32*)(p + 0x60);
    box.min.y = *(f32*)(p + 0x64);
    box.max.x = *(f32*)(p + 0x68);
    box.max.y = *(f32*)(p + 0x6c);
    box.min.x += *(f32*)(p + 0xc);
    box.min.y += *(f32*)(p + 0x10);
    box.max.x += *(f32*)(p + 0xc);
    box.max.y += *(f32*)(p + 0x10);
    fn_80239914(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198));
    (this->*lbl_804AACDC[*(s32*)(p + 0x230)])();
}

// fn_803169E0 - TWTG: destructor.
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void* fn_803169E0(char* p, s16 how) {
    if (p != 0) {
        *(void**)p = lbl_804AAD60;
        AnimEffectRec* r = *(AnimEffectRec**)(p + 0x278);
        if (r != 0) {
            delete r;
            *(AnimEffectRec**)(p + 0x278) = 0;
        }
        dtor_801F593C(p, 0);
        if (how > 0) {
            operator delete(p);
        }
    }
    return p;
}

Twtg::Twtg() : Actor() {
    *(void**)this = lbl_804AAD60;
    ResourceHandle* h = new ResourceHandle();
    *(ResourceHandle**)((char*)this + 0x278) = h;
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
