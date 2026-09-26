// TU 0x803172dc-0x80317eb8 (actor FTGL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- FTGL functions before the ctor ----
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
extern const f32 lbl_805418C4;
extern const f32 lbl_805418E4;
extern const f32 lbl_805418E8;
extern const f32 lbl_805418EC;
extern const f32 lbl_805418F0;
extern const f32 lbl_805418F4;
extern const char lbl_80471620[];
extern "C" void* lbl_804AADD8[];
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" void dtor_801F593C(void* this_, int how);

// fn_803172DC - FTGL: draw().
extern "C" void fn_803172DC(char* p) {
    s32 st = *(s32*)(p + 0x230);
    if (st == 12 || st == 11) {
        return;
    }
    fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x23c) + 0xc0, 0, 2, -1, 0, 0, 0);
    fn_801F06F0(p, lbl_80471620, *(s32*)(p + 0x23c) + 0xc0, 0, 7, lbl_805418C4, lbl_805418C4);
}

// fn_80317B08 - FTGL: setParams().
extern "C" void fn_80317B08(char* p) {
    *(f32*)(p + 0x60) = lbl_805418E4;
    *(f32*)(p + 0x64) = lbl_805418E8;
    *(f32*)(p + 0x68) = lbl_805418EC;
    *(f32*)(p + 0x6c) = lbl_805418EC;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x238) = 50;
    *(s32*)(p + 0x234) = -1;
    *(s32*)(p + 0x23c) = 0x1d;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    s32 room = *(s32*)(p + 0x4);
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
    fn_80316E50(*(AnimEffectRec**)(p + 0x24c), room, pos);
    *(f32*)(p + 0x260) = lbl_805418F0;
    *(f32*)(p + 0x264) = lbl_805418F0;
    *(f32*)(p + 0x268) = lbl_805418F4;
    *(f32*)(p + 0x26c) = lbl_805418F4;
    *(u8*)(p + 0x270) = 0;
}

// fn_80317BB8 - FTGL: destructor.
extern "C" void* fn_80317BB8(char* p, s16 how) {
    if (p != 0) {
        *(void**)p = lbl_804AADD8;
        AnimEffectRec* r = *(AnimEffectRec**)(p + 0x24c);
        if (r != 0) {
            delete r;
            *(AnimEffectRec**)(p + 0x24c) = 0;
        }
        dtor_801F593C(p, 0);
        if (how > 0) {
            operator delete(p);
        }
    }
    return p;
}

// ---- Ftgl_ctor_80317C38.cpp ----
// fn_80317C38 - "FTGL" real constructor. Identical shape to JIJI/TWTG:
// base Actor ctor + own vtable install, then allocates a 0x1c-byte
// resource handle and resets it via ResetResourceHandleRecord if the
// allocation succeeded, storing the handle (or null) at +0x24c.
//
// This is the first "owned resource + base-class exception safety"
// pattern landed as real C++ - it needed genuine C++ inheritance (not a
// raw Actor_ctor(this) function call) to get MWCC to emit the real
// DESTROYBASE+DELETEPOINTER extab pair, plus aliasing Actor_ctor/
// dtor_801F593C to their mangled Actor::Actor()/Actor::~Actor() call
// targets via the LCF (see config/G4SE01/ldscript.tpl and
// reference_fsa_operator_new_delete_identified.md). The key remaining
// trick: calling ResetResourceHandleRecord from INSIDE ResourceHandle's
// own (trivial, MWCC-inlined) constructor reuses the compiler's own
// "did the allocation succeed" check instead of adding a second,
// redundant explicit null-check - that redundant check is what broke
// both the register allocation and the extab region shape in earlier
// attempts.



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

class Ftgl : public Actor {
public:
    Ftgl();
};

Ftgl::Ftgl() : Actor() {
    *(void**)this = lbl_804AADD8;
    ResourceHandle* h = new ResourceHandle();
    *(ResourceHandle**)((char*)this + 0x24c) = h;
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
