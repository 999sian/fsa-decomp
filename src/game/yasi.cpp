// TU 0x802df458-0x802dfce8 (actor YASI).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802DF458_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern void* lbl_804A9968[];

extern "C" void* fn_802DF458(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9968;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- VtableForward_802DF4B8.cpp ----
// YASI cluster, part 2/7. Virtual-call wrapper: invokes this object's
// own vtable slot 9 (byte offset 0x24) with no extra arguments.
// See [[reference_fsa_virtual_dispatch_codegen_trick]] for why this
// calls through a real `virtual` member rather than a manual cast.
struct ActorSlot9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void slot9();
};

extern "C" void fn_802DF4B8(void* this_) {
    ((ActorSlot9*)this_)->slot9();
}

// ---- Yasi_CanBeActiveHere_802DF4E4.cpp ----
// YASI cluster, part 3/7. A thin wrapper around the shared
// "can this actor be active here" gate fn_801F132C (see extab_801f132c.s),
// passing this actor's own +0x230 state block as the gate's per-instance
// scratch pointer.
extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);

extern "C" s32 Yasi_CanBeActiveHere(void* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, (u32*)((char*)this_ + 0x230));
}

// fn_802DF508 - YASI: break(). Spawns debris / effects depending on the
// ground tile under the actor, plays a sound and deactivates.
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
typedef JGeometry::TVec3<f32> YasiVec;
extern const f32 lbl_80541168;
extern const f32 lbl_8054116C;
extern const f32 lbl_80541170;
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F9484(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" u16 fn_8022461C(YasiVec* pos, u32 room);
extern "C" void fn_8013CC50(u32 room, YasiVec* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" u8 fn_802DE9A0();
extern "C" u8 fn_802DEB58();

extern "C" void fn_802DF508(char* p) {
    if (*(s32*)(p + 0x4) >= 8) {
        YasiVec pos(*(YasiVec*)(p + 0xc));
        pos.z = lbl_80541168;
        fn_801F9484(fn_801F856C(), 0x4b4d5249, *(u32*)(p + 0x4), &pos, 0, -1, -1);
    }
    if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xd || fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0x39) {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_8054116C, 0x3d0, 0, 1, 0, 0, 1);
        fn_801F0E34(p, 0x30022, 0);
    } else if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xe) {
        if (fn_802DE9A0()) {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_8054116C, 0x2a9, -1, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_8054116C, 0x2aa, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5005f, 0);
        } else if (fn_802DEB58()) {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_8054116C, 0x45e, -1, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_8054116C, 0x45f, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5003f, 0);
        }
    } else {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_8054116C, 0x8c, 1, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_8054116C, 0x7a, 1, 0, 0, 0, 1);
        fn_801F0E34(p, 0x30003, 0);
    }
    *(u8*)(p + 0x11c) = 0;
}

// fn_802DF754 - YASI: draw(). Fills a model draw descriptor on the stack
// and hands it to fn_801F02BC; when held, the holder's palette is used.
struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];      // 0x00
    YasiDrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_8046E998[];
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" u8 fn_8023CA88(s32 holder);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, YasiDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);

extern "C" void fn_802DF754(char* p) {
    YasiDrawParam param;
    ((u8*)&param.key.a)[3] = *(u8*)(p + 0x234);
    if (*(u8*)(p + 0xc4) != 0) {
        param.f20 = 0;
        param.color = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
        param.palette = fn_8023CA88(*(s32*)(p + 0xc8));
    }
    fn_801F02BC(p, lbl_8046E998, 0x1ae, &param, 7, 0, 1, lbl_8054116C, lbl_8054116C);
}

// fn_802DF8C8 - YASI: carried / thrown update. While held it follows the
// holder; otherwise it falls (gravity on the z speed), and breaks when it
// lands or hits something.
struct YasiVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void breakUp();
};
extern char* lbl_8053AAF8;
extern void* lbl_8053AC98;
extern "C" YasiVec* fn_8023E7B0(s32 holder);
extern "C" s32 fn_8023DE58(s32 holder);
extern "C" u8 fn_8023BCD4(s32 holder);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u16 fn_80226850(YasiVec* pos, u32 room);
extern "C" void fn_802A381C(void* mgr, YasiVec* pos, u32 room, s32 id);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 holder, s32 b);
extern "C" u8 fn_801F2B20(void* this_, s32 a);

extern "C" void fn_802DF8C8(char* p) {
    *(u8*)(p + 0x234) = 0xff;
    if (*(u8*)(p + 0xc4) != 0) {
        YasiVec* h = fn_8023E7B0(*(s32*)(p + 0xc8));
        *(f32*)(p + 0xc) = h->x;
        *(f32*)(p + 0x10) = h->y;
        *(f32*)(p + 0x14) = h->z;
        *(s32*)(p + 0x4) = fn_8023DE58(*(s32*)(p + 0xc8));
        *(u8*)(p + 0x234) = fn_8023BCD4(*(s32*)(p + 0xc8));
        return;
    }
    *(f32*)(p + 0x44) += lbl_80541170;
    *(YasiVec*)(p + 0xc) += *(YasiVec*)(p + 0x3c);
    s32 hit = *(s32*)(p + 0x114);
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        hit = 0;
    }
    if (*(f32*)(p + 0x14) < lbl_80541168 || fn_801F2618(p, 0, 0)) {
        if (*(f32*)(p + 0x14) < lbl_80541168) {
            if (fn_80226850((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0x90) {
                fn_802A381C(lbl_8053AC98, (YasiVec*)(p + 0xc), *(u32*)(p + 0x4), 0x91);
            } else if (fn_80226850((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0x91) {
                fn_802A381C(lbl_8053AC98, (YasiVec*)(p + 0xc), *(u32*)(p + 0x4), 0x92);
            }
        }
        ((YasiVT*)p)->breakUp();
    } else if (fn_801F2B7C(p, hit, *(s32*)(p + 0xc8), 4) || fn_801F2B20(p, 0)) {
        ((YasiVT*)p)->breakUp();
    }
}

// fn_802DFA80 - YASI: setParams (draw/collision extents).
extern const f32 lbl_80541174;
extern const f32 lbl_80541178;
extern const f32 lbl_8054117C;
extern const f32 lbl_80541180;

extern "C" void fn_802DFA80(char* p) {
    *(f32*)(p + 0x60) = lbl_80541174;
    *(f32*)(p + 0x64) = lbl_80541174;
    *(f32*)(p + 0x68) = lbl_80541178;
    *(f32*)(p + 0x6c) = lbl_80541178;
    *(f32*)(p + 0x80) = lbl_8054117C;
    *(f32*)(p + 0x84) = lbl_8054117C;
    *(f32*)(p + 0x88) = lbl_80541180;
    *(f32*)(p + 0x8c) = lbl_80541180;
    *(s32*)(p + 0x230) = 0;
    *(u8*)(p + 0x234) = 0xff;
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
