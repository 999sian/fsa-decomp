// TU 0x8032ab80-0x8032df94 (actor RUPY).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_8032AB80_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AB6D8[];
extern const f32 lbl_80541D88;
extern const f32 lbl_80541D90;
extern const f32 lbl_80541D98;
extern const f32 lbl_80541D9C;
extern const f32 lbl_80541DA0;
extern const f32 lbl_80541DA4;
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 flag);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void* lbl_8053AAF8;
extern const f32 lbl_80541DA8;
extern const f32 lbl_80541DAC;
extern const f32 lbl_80541DB0;
extern const f32 lbl_80541DB4;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801F0D20(void* this_, s32 a);
extern "C" u8 fn_802DEBA0(void);
extern const f32 lbl_80541D8C;
extern const f32 lbl_80541D94;
extern void* lbl_8053AED0;
extern const u32 lbl_804719D8[];
extern "C" u8 fn_8023B0F4(s32 idx, void* box, u32 room, s32 a, f32 f);
extern "C" u8 fn_80230188(s32 idx);
extern "C" u8 fn_80234ECC(s32 idx);
extern "C" u8 fn_8023EA28(s32 idx);
extern "C" u8 fn_80236B50(s32 idx);
extern "C" u8 fn_8023B9CC(s32 d, void* rect, u32 room, void* out8, u32 e);
extern "C" u8 fn_8023B848(s32 d, void* rect, u32 room, void* out8);
extern "C" u8 fn_80234C5C(s32 idx);
extern "C" u8 fn_8022B7C4(s32 idx);
extern "C" u8 fn_8022F514(s32 idx);
extern "C" s32 fn_8022F3DC(s32 idx);
extern "C" u8 fn_802D7F40(void* rec, u32 sw);
extern "C" void fn_802D7F84(void* rec, u32 sw, s32 on);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 arg, s32 flag);
extern "C" void fn_8043D874(void* mgr, s32 idx, u32 id, s32 flag);
extern "C" void fn_80230FD0(s32 idx, s32 id);
extern "C" void fn_802362C4(s32 idx, u32 id);
extern "C" u8 fn_8023ED8C(s32 idx);
extern "C" u8 fn_8023EBB8(s32 idx);
extern "C" u8 fn_80233DA4(s32 idx);
extern "C" u8 fn_802308E0(s32 idx);
extern "C" void* fn_8023E724(s32 idx);
extern "C" u8 fn_80233E40(s32 idx);
extern "C" void fn_80230498(s32 idx, void* vec, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void detach__5ActorFv(void* this_);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 room, void* pos, u32 param, s32 a, s32 b);
extern "C" void* fn_801F856C(void);
struct RupyVec3 {
    f32 x, y, z;
};

// Fast LCG at lbl_8053AAF8+0xB4; returns a value in [0,1).
static inline f32 rupyRand01() {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = *s * 0x19660du + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - lbl_80541D90;
}

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

extern "C" s32 fn_8032B0A4(void* this_) {
    u8* p = (u8*)this_;
    u16 subtype = *(u16*)(p + 0x94);
    s32 sVar;
    u32 id1;
    u32 id2;

    if (subtype == 0x23 || subtype == 0x24) {
        return 0;
    }
    if (*(f32*)(p + 0x14) > lbl_80541D98) {
        return 0;
    }
    sVar = (u16)fn_8022461C(p + 0xc, *(s32*)(p + 0x4));
    if (sVar == 3) {
        *(s32*)(p + 0x24c) = 0x3ff;
        *(f32*)(p + 0x44) = lbl_80541D88;
        *(f32*)(p + 0x40) = lbl_80541D88;
        *(f32*)(p + 0x3c) = lbl_80541D88;
        *(s32*)(p + 0x230) = 5;
        return 1;
    }
    if (sVar == 0xe) {
        *(s32*)(p + 0x24c) = 0x3ff;
        *(f32*)(p + 0x44) = lbl_80541D88;
        *(f32*)(p + 0x40) = lbl_80541D88;
        *(f32*)(p + 0x3c) = lbl_80541D88;
        *(f32*)(p + 0x238) = lbl_80541D88;
        if (*(s32*)(p + 0x230) != 5) {
            *(s32*)(p + 0x230) = 5;
            if (fn_802DE9A0() == 1) {
                id1 = 0x2a9;
                id2 = 0x2aa;
                fn_801F0E34(this_, 0x50040, 0);
            } else {
                if (fn_802DEB58() == 1) {
                    id1 = 0x45e;
                    id2 = 0x45f;
                    fn_801F0E34(this_, 0x5003f, 0);
                } else {
                    return 1;
                }
            }
            if (*(s32*)(p + 0x268) < 4) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D9C, id1, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D9C, id2, 0, 0, 0, 0, 1);
            } else if (*(s32*)(p + 0x268) < 8) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D90, id1, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D90, id2, 0, 0, 0, 0, 1);
            } else {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541DA0, id1, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541DA0, id2, 0, 0, 0, 0, 1);
            }
        }
        return 1;
    }
    if (sVar == 0xd) {
        *(f32*)(p + 0x44) = lbl_80541D88;
        *(f32*)(p + 0x40) = lbl_80541D88;
        *(f32*)(p + 0x3c) = lbl_80541D88;
        *(f32*)(p + 0x44) = lbl_80541DA4;
        *(f32*)(p + 0x238) = lbl_80541D90;
        if (*(s32*)(p + 0x230) != 6) {
            *(s32*)(p + 0x24c) = 0x1e;
            if (*(s32*)(p + 0x268) < 4) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D9C, 0x3d0, 0, 1, 0, 0, 1);
            } else if (*(s32*)(p + 0x268) < 8) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D90, 0x3d0, 0, 1, 0, 0, 1);
            } else {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541DA0, 0x3d0, 0, 1, 0, 0, 1);
            }
            fn_801F0E34(this_, 0x30022, 0);
        }
        *(s32*)(p + 0x230) = 6;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_8032B3F8(void* this_) {
    u8* p = (u8*)this_;
    u32 room = *(u32*)(p + 4);
    u8* mgr = (u8*)fn_802D6A9C();
    if (mgr[room + 0x131df] == 0) {
        if (*(f32*)(p + 0x14) > lbl_80541D88 || *(f32*)(p + 0x44) > lbl_80541D88) {
            *(f32*)(p + 0x44) = *(f32*)(p + 0x44) - lbl_80541DA8;
        } else if (*(f32*)(p + 0x14) <= lbl_80541D88) {
            *(f32*)(p + 0x14) = lbl_80541D88;
            if (p[0x280] == 1) {
                fn_801F0D20(this_, 0x42);
                p[0x280] = 0;
            }
            if ((u8)fn_8032B0A4(this_) != 0) {
                return 0;
            }
            if (*(s32*)(p + 0x260) == 0) {
                if (fn_802DEBA0() == 0) {
                    fn_801F0E34(this_, 0x3000a, 0);
                }
                *(s32*)(p + 0x260) = 1;
                if (p[0x27f] == 0) {
                    *(f32*)(p + 0x44) = lbl_80541DA0 + (lbl_80541D90 - lbl_80541DA0 * rupyRand01());
                    *(f32*)(p + 0x3c) = lbl_80541DAC - rupyRand01();
                    *(f32*)(p + 0x40) = lbl_80541DAC - rupyRand01();
                } else {
                    *(f32*)(p + 0x44) = lbl_80541DA0;
                    p[0x27f] = 0;
                }
            } else {
                *(f32*)(p + 0x44) = lbl_80541D88;
                *(f32*)(p + 0x40) = lbl_80541D88;
                *(f32*)(p + 0x3c) = lbl_80541D88;
                if (p[0x27d] != 0) {
                    *(s32*)(p + 0x230) = 9;
                } else {
                    *(s32*)(p + 0x230) = 1;
                }
            }
        }
    } else {
        if (lbl_80541D88 != *(f32*)(p + 0x44)) {
            *(f32*)(p + 0x40) = *(f32*)(p + 0x40) - *(f32*)(p + 0x44);
            *(f32*)(p + 0x44) = lbl_80541D88;
        }
        if (*(f32*)(p + 0x14) > lbl_80541D88) {
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
            *(f32*)(p + 0x14) = lbl_80541D88;
        }
        *(f32*)(p + 0x40) = *(f32*)(p + 0x40) + lbl_80541DA8;
        if (p[0x27e] == 1 && *(f32*)(p + 0x40) > lbl_80541D88) {
            if (lbl_80541D88 != *(f32*)(p + 0x284)) {
                *(f32*)(p + 0x3c) = *(f32*)(p + 0x3c) - *(f32*)(p + 0x3c);
            }
            if (lbl_80541D88 != *(f32*)(p + 0x288)) {
                if (p[0x280] == 1) {
                    fn_801F0D20(this_, 0x42);
                    p[0x280] = 0;
                }
                if (*(s32*)(p + 0x260) == 0) {
                    if (fn_802DEBA0() == 0) {
                        fn_801F0E34(this_, 0x3000a, 0);
                    }
                    *(s32*)(p + 0x260) = 1;
                    *(f32*)(p + 0x44) = lbl_80541D88;
                    *(f32*)(p + 0x3c) = lbl_80541DAC - rupyRand01();
                    *(f32*)(p + 0x40) = lbl_80541DB0 + (lbl_80541D90 - lbl_80541DA0 * rupyRand01());
                } else {
                    *(f32*)(p + 0x3c) = lbl_80541D88;
                    *(f32*)(p + 0x44) = lbl_80541D88;
                    *(f32*)(p + 0x40) = lbl_80541DB4;
                    if (p[0x27d] != 0) {
                        *(s32*)(p + 0x230) = 9;
                    } else {
                        *(s32*)(p + 0x230) = 1;
                    }
                }
            }
        }
    }
    return 1;
}

extern "C" s32 fn_8023A51C(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" void* fn_8023A478(s32 idx);
extern "C" s32 fn_8030C2A8(void* a, void* b);
extern "C" s32 fn_8023A240(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* table, s32 kind, s32 room, void* pos, s32 flags);
extern "C" void* fn_801F666C(void* table, s32 idx);
extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_80541DB8;
extern const f32 lbl_80541DBC;
extern void* lbl_8053AB10;
extern "C" void fn_8032BB90(char* this_) {
    s32 i = 0;
    do {
        if (fn_8023A51C(i) == 1 && *(s32*)(this_ + 0x4) == fn_8023DE58(i)) {
            f32* pos = (f32*)fn_8023A478(i);
            f32 dx = pos[0] - *(f32*)(this_ + 0xc);
            f32 dz = pos[1] - *(f32*)(this_ + 0x10);
            if (dx * dx + dz * dz <= lbl_80541DB8 && fn_8030C2A8(*(void**)((char*)lbl_8053AB10 + 0x24), this_ + 0xc) == 1) {
                *(f32*)(this_ + 0x14) = lbl_80541DBC;
                s32 kind;
                if (*(s32*)(this_ + 0x230) == 7 || *(s32*)(this_ + 0x248) != 0) {
                    s32 steps;
                    s32 room = *(s32*)(this_ + 0x4);
                    s32 mode;
                    if (*(s32*)(this_ + 0x248) == 0) {
                        *(u32*)(this_ + 0x268) |= 0x2000000;
                        u16 k = *(u16*)(this_ + 0x94);
                        if (k == 0x1d || k == 0x1e) {
                            steps = fn_8023A240();
                        } else if (k < 4 || k > 7) {
                            steps = k - 8;
                        } else {
                            steps = k - 4;
                        }
                    }
                    kind = 0;
                    (void)room;
                    (void)steps;
                }
                break;
            }
        }
        i++;
    } while (i < 4);
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
