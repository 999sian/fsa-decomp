// TU 0x8032ab80-0x8032df94 (actor RUPY).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_8032AB80_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AB6D8[];
extern const f32 lbl_80541D90;
extern const f32 lbl_80541D98;
extern const f32 lbl_80541D9C;
extern const f32 lbl_80541DA0;
extern const f32 lbl_80541DA4;
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 flag);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);

extern "C" void* fn_8032AB80(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB6D8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// RUPY: small helpers.
extern const f32 lbl_80541D88;
extern "C" void fn_8032D534(char* p) {
    *(f32*)(p + 0x44) = lbl_80541D88;
    *(f32*)(p + 0x40) = lbl_80541D88;
    *(f32*)(p + 0x3c) = lbl_80541D88;
    if (*(s32*)(p + 0x24c) < 800) {
        *(s32*)(p + 0x24c) = 800;
    }
    *(s32*)(p + 0x230) = 1;
}

extern const u32 lbl_804719D8[];
extern "C" u32 fn_8032D564(void* p, s32 i) { return lbl_804719D8[i]; }

// NONMATCHING (93.1%): the constant extent copy is scheduled before the
// register saves here, after them in retail.
// fn_8032D578 - RUPY: can the rupee land at pos? Checks the collision map
// first, then the tile type.
struct RupyPt { f32 x, y; };
extern const RupyPt lbl_80541D80;
extern const u32 lbl_80541D84;
extern "C" u8* fn_8020D58C();
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, u32 id, RupyPt* ext);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" bool fn_802265DC(void* pos, s32 room, s32 a);
extern "C" u8 fn_8032D578(char* p, s32 room, void* pos) {
    RupyPt ext;
    *(u32*)&ext = *(u32*)&lbl_80541D80;
    ((u32*)&ext)[1] = *(u32*)&lbl_80541D84;
    u32 id = *(u32*)(p + 0x198);
    u8* mgr = fn_8020D58C();
    if (fn_8020D6AC(mgr + 4 + mgr[1] * 0x784, room, pos, id, &ext) == 1) {
        return 1;
    }
    bool ok;
    s32 t = fn_8022461C(pos, room);
    if (t == 0x3b || t == 0x23) {
        ok = 0;
    } else {
        ok = fn_802265DC(pos, room, 0);
    }
    if (!ok) {
        *(u8*)(p + 0x283) = 0;
    }
    return ok;
}

// ---- FlagClear_8032D660.cpp ----
// fn_8032D660(this) - RUPY's (Rupee) vtable slot override. Gated on
// this->0x94 (a halfword) being exactly 0x19 or 0x1a - likely a
// rupee-color/value subtype range. When in that range, makes a
// virtual call through its own vtable slot 13 (byte offset 0x34,
// shared with many other actors); if that call returns true, clears
// this->0x280 (a byte flag - plausibly "is still collectible/active",
// given RUPY's role as a pickup). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot13 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 slot13();
};

extern "C" void fn_8032D660(void* this_) {
    u16 subtype = *(u16*)((char*)this_ + 0x94);
    if (subtype == 0x19 || subtype == 0x1a) {
        if (((ActorSlot13*)this_)->slot13() != 0) {
            *(u8*)((char*)this_ + 0x280) = 0;
        }
    }
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
