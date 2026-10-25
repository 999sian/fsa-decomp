// TU 0x803172dc-0x80317eb8 (actor FTGL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

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
#include "Game/AnimEffectRec.h"
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
extern "C" void __dt__5ActorFv(void* this_, int how);

// fn_803172DC - FTGL: draw().
extern "C" void fn_803172DC(char* p) {
    s32 st = *(s32*)(p + 0x230);
    if (st == 12 || st == 11) {
        return;
    }
    fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x23c) + 0xc0, 0, 2, -1, 0, 0, 0);
    fn_801F06F0(p, lbl_80471620, *(s32*)(p + 0x23c) + 0xc0, 0, 7, lbl_805418C4, lbl_805418C4);
}

extern "C" void fn_80239914(f32* box, s32 room, s32 h);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_8023EFEC(s32 i);
extern "C" void fn_80230C6C(s32 i);
extern "C" void fn_80458FF0(void* a, s32 b, s32 c, s32 d);
extern "C" void* lbl_8053AF80;
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F68E0(void* p);
extern "C" u8 fn_80233E40(s32 i);
extern "C" u8 fn_8023EA28(s32 i);
extern "C" u8 fn_80236B50(s32 i);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" void fn_80230498(s32 i, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230BF4(s32 a, s32 b);
extern "C" void* lbl_8053AAF8;
extern "C" s32 fn_80138A30(void* game);
extern "C" s32 fn_8022EA0C(s32 a);
extern "C" void fn_801F0E34(char* p, s32 a, s32 b);
extern "C" void fn_8022FE80(s32 a, s32 room, s32 h, s32 b, s32 c);
extern "C" s32 fn_8022FD8C(s32 h);
extern "C" u8 fn_8038AD24(s32 a, s32 id, s32 h, s32 room, JGeometry::TVec3<f32> pos, s32 c);
extern "C" u8 fn_803865B8(s32 a);
extern "C" u8 fn_8038470C(s32 a, s32 id);
extern "C" u8 fn_80388CAC(s32 a, s32 h);
extern "C" void fn_801F6884(void* p);
extern "C" u8 fn_8022B978(s32 room, f32* box, s32 c);
extern "C" void fn_8030C210(void* a, void* pos);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_801F35AC(char* p);
extern "C" u8* lbl_8053AB10;
extern "C" s16* lbl_804AADC8[];
extern const f32 lbl_805418C0;
extern const f32 lbl_805418C8;
extern const f32 lbl_805418CC;
extern const f32 lbl_805418D0;
extern const f32 lbl_805418D4;
extern const f32 lbl_805418D8;
extern const f32 lbl_805418DC;
extern const f32 lbl_805418E0;
static inline void ftglFacePlayers(char* p) {
    for (s32 i = 0; i < 4; i++) {
        s32 room = *(s32*)(p + 0x4);
        s32 r = fn_8023DE58(i);
        if (r == room && !fn_80233E40(i) && !fn_8023EA28(i) && !fn_80236B50(i)) {
            s32 side = fn_8023E724(i)->x > *(f32*)(p + 0xc) ? 1 : 0;
            fn_80230498(i, fn_8023E724(i), side + 0x3c, 0xff, -0x80, -0x80, 1);
            fn_80230BF4(i, side);
        }
    }
}

static inline s32 ftglNearestPlayer(char* p) {
    s32 n = fn_80138A30(lbl_8053AAF8);
    s32 best = 0;
    f32 bestD = lbl_805418C0;
    for (s32 j = 0; j < n; j++) {
        s32 id = fn_8022EA0C(j);
        s32 room = *(s32*)(p + 0x4);
        s32 r = fn_8023DE58(id);
        if (r == room) {
            f32 d = PSVECSquareDistance((Vec*)(p + 0xc), fn_8023E724(id));
            if (d < bestD) {
                bestD = d;
                best = id;
            }
        }
    }
    return best;
}

extern "C" void fn_80317378(char* p) {
    f32 box[4];
    box[0] = *(f32*)(p + 0x60);
    box[1] = *(f32*)(p + 0x64);
    box[2] = *(f32*)(p + 0x68);
    box[3] = *(f32*)(p + 0x6c);
    box[0] += *(f32*)(p + 0xc);
    box[1] += *(f32*)(p + 0x10);
    box[2] += *(f32*)(p + 0xc);
    box[3] += *(f32*)(p + 0x10);
    if (*(s32*)(p + 0x230) < 9) {
        fn_80239914(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198));
    }
    switch (*(s32*)(p + 0x230)) {
    case 0:
        *(s32*)(p + 0x238) -= 1;
        if (*(s32*)(p + 0x238) <= 0) {
            for (s32 i = 0; i < 4; i++) {
                s32 room = *(s32*)(p + 0x4);
                s32 r = fn_8023DE58(i);
                if (r == room && fn_8023EFEC(i)) {
                    fn_80230C6C(i);
                }
            }
            *(s32*)(p + 0x230) = 1;
        }
        if (*(u8*)(p + 0x270) == 0) {
            fn_80458FF0(lbl_8053AF80, 0x1000025, 0, 0);
            *(u8*)(p + 0x270) = 1;
        }
        break;
    case 1:
        if (fn_801F68E0(fn_801F856C()) != 0) {
            for (s32 i = 0; i < 4; i++) {
                s32 room = *(s32*)(p + 0x4);
                s32 r = fn_8023DE58(i);
                if (r == room && !fn_80233E40(i) && !fn_8023EA28(i) && !fn_80236B50(i)) {
                    s32 side = fn_8023E724(i)->x > *(f32*)(p + 0xc) ? 1 : 0;
                    fn_80230498(i, fn_8023E724(i), side + 0x3c, 0xff, -0x80, -0x80, 1);
                    fn_80230BF4(i, side);
                }
            }
            s32 n = fn_80138A30(lbl_8053AAF8);
            s32 j;
            s32 id;
            s32 best = 0;
            f32 bestD = lbl_805418C0;
            for (j = 0; j < n; j++) {
                id = fn_8022EA0C(j);
                s32 room = *(s32*)(p + 0x4);
                s32 r = fn_8023DE58(id);
                if (r == room) {
                    f32 d = PSVECSquareDistance((Vec*)(p + 0xc), fn_8023E724(id));
                    if (d < bestD) {
                        bestD = d;
                        best = id;
                    }
                }
            }
            *(s32*)(p + 0x234) = best;
            *(s32*)(p + 0x238) = 0x3c;
            *(s32*)(p + 0x230) = 2;
            fn_801F0E34(p, 0x50050, 0);
        }
        break;
    case 3:
        *(s32*)(p + 0x238) = 0x78;
        *(s32*)(p + 0x230) = 4;
        break;
    case 5:
        fn_8022FE80(*(s32*)(p + 0x234), *(s32*)(p + 0x4), *(s32*)(p + 0x198), 0, 0);
        {
            s32 r = fn_8022FD8C(*(s32*)(p + 0x198));
            if (r >= 0) {
                if (fn_8038AD24(r, 0x50d, *(s32*)(p + 0x198), *(s32*)(p + 0x4), *(JGeometry::TVec3<f32>*)(p + 0xc), 0x102)) {
                    *(s32*)(p + 0x230) = 6;
                    s32 room = *(s32*)(p + 0x4);
                    fn_80316E50(*(AnimEffectRec**)(p + 0x24c), room, JGeometry::TVec3<f32>(*(JGeometry::TVec3<f32>*)(p + 0xc)));
                }
            }
        }
        break;
    case 6:
        fn_8022FE80(*(s32*)(p + 0x234), *(s32*)(p + 0x4), *(s32*)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x234))) {
            *(s32*)(p + 0x230) = 7;
        }
        break;
    case 7:
        fn_8022FE80(*(s32*)(p + 0x234), *(s32*)(p + 0x4), *(s32*)(p + 0x198), 0, 0);
        if (fn_8038470C(*(s32*)(p + 0x234), 0x50e)) {
            *(s32*)(p + 0x230) = 8;
            s32 room = *(s32*)(p + 0x4);
            fn_80316E50(*(AnimEffectRec**)(p + 0x24c), room, JGeometry::TVec3<f32>(*(JGeometry::TVec3<f32>*)(p + 0xc)));
        }
        break;
    case 8:
        fn_8022FE80(*(s32*)(p + 0x234), *(s32*)(p + 0x4), *(s32*)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x234), *(s32*)(p + 0x198))) {
            *(s32*)(p + 0x230) = 9;
            *(s32*)(p + 0x234) = -1;
            *(s32*)(p + 0x240) = 1;
            *(s32*)(p + 0x244) = 0;
            *(s32*)(p + 0x248) = 0;
        }
        break;
    case 9:
        if (*(s32*)(p + 0x240) >= 2) {
            *(f32*)(p + 0x3c) = lbl_805418C8;
            *(f32*)(p + 0x44) = lbl_805418CC;
            *(s32*)(p + 0x230) = 10;
            fn_801F6884(fn_801F856C());
        }
    case 10:
        if (*(f32*)(p + 0x14) >= lbl_805418D0) {
            *(f32*)(p + 0x44) = lbl_805418D4;
        }
        ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
        box[0] = *(f32*)(p + 0x260);
        box[1] = *(f32*)(p + 0x264);
        box[2] = *(f32*)(p + 0x268);
        box[3] = *(f32*)(p + 0x26c);
        box[0] += *(f32*)(p + 0xc);
        box[1] += *(f32*)(p + 0x10);
        box[2] += *(f32*)(p + 0xc);
        box[3] += *(f32*)(p + 0x10);
        if (!fn_8022B978(*(s32*)(p + 0x4), box, 1)) {
            *(s32*)(p + 0x238) = 0x3c;
            *(s32*)(p + 0x230) = 11;
        }
        break;
    case 11:
        *(f32*)(p + 0xc) = lbl_805418D8;
        *(f32*)(p + 0x10) = lbl_805418DC;
        *(f32*)(p + 0x14) = lbl_805418D4;
        *(s32*)(p + 0x4) = 0;
        *(f32*)(p + 0x3c) = lbl_805418E0;
        *(f32*)(p + 0x44) = lbl_805418CC;
        *(s32*)(p + 0x230) = 12;
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
        fn_80138B7C(lbl_8053AAF8);
        break;
    case 12:
        *(s32*)(p + 0x238) -= 1;
        if (*(s32*)(p + 0x238) <= 0) {
            *(s32*)(p + 0x230) = 13;
            fn_801F0E34(p, 0x5001b, 0);
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
        break;
    case 13:
        if (*(f32*)(p + 0x14) >= lbl_805418D0) {
            *(f32*)(p + 0x44) = lbl_805418D4;
        }
        ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
        box[0] = *(f32*)(p + 0x260);
        box[1] = *(f32*)(p + 0x264);
        box[2] = *(f32*)(p + 0x268);
        box[3] = *(f32*)(p + 0x26c);
        box[0] += *(f32*)(p + 0xc);
        box[1] += *(f32*)(p + 0x10);
        box[2] += *(f32*)(p + 0xc);
        box[3] += *(f32*)(p + 0x10);
        if (!fn_8022B978(*(s32*)(p + 0x4), box, 1)) {
            fn_801F35AC(p);
        } else {
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
        }
        break;
    case 2:
    case 4:
        *(s32*)(p + 0x238) -= 1;
        if (*(s32*)(p + 0x238) <= 0) {
            *(s32*)(p + 0x230) += 1;
        }
        break;
    }
    if (*(s32*)(p + 0x230) == 8 && *(s32*)(p + 0x234) >= 0) {
        u32 code = fn_80316E74(*(AnimEffectRec**)(p + 0x24c), *(s32*)(p + 0x234));
        if (fn_80316E34(*(AnimEffectRec**)(p + 0x24c)) >= 0) {
            *(s32*)(p + 0x23c) = fn_80316E34(*(AnimEffectRec**)(p + 0x24c));
            if (code != 0xffffffff) {
                fn_801F0E34(p, code, 0);
            }
        } else {
            *(s32*)(p + 0x23c) = 0x14;
        }
    } else if (*(s32*)(p + 0x230) >= 3) {
        s16* anim = lbl_804AADC8[*(s32*)(p + 0x240)];
        *(s32*)(p + 0x23c) = anim[*(s32*)(p + 0x244) * 2];
        s32 dur = anim[*(s32*)(p + 0x244) * 2 + 1];
        if (dur > 0) {
            *(s32*)(p + 0x248) += 1;
            if (*(s32*)(p + 0x248) >= dur) {
                *(s32*)(p + 0x248) = 0;
                *(s32*)(p + 0x244) += 1;
                if (anim[*(s32*)(p + 0x244) * 2] < 0) {
                    *(s32*)(p + 0x244) = 0;
                    if (*(s32*)(p + 0x240) < 3) {
                        *(s32*)(p + 0x240) += 1;
                    }
                }
            }
        }
    }
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
        __dt__5ActorFv(p, 0);
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
// __dt__5ActorFv to their mangled Actor::Actor()/Actor::~Actor() call
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
