// TU 0x802e2990-0x802e40a8 (actor GNL2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gol2_SetField_0x2f4.cpp ----
// GOL2 (vtable lbl_804A9C20, ctor fn_80201898) cluster, part 1/5 (8B,
// no extab - leaf). Trivial single-byte setter (this->0x2f4).
extern "C" {

void Gol2_SetField_0x2f4(void* thisPtr, u8 val) { *(u8*)((char*)thisPtr + 0x2f4) = val; }

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
extern "C" {
void fn_801EE434(void* h);
void __dt__5ActorFv(void* this_, int flag);
void __dl__FPv(void* p);
void fn_80457E54(void* p, s32 a);
}
extern void* __vt__4GNL2[];
extern void* lbl_8053AF80;

extern "C" void* fn_802E3A48(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4GNL2;
        char* p = this_;
        for (s32 i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x2c8) != 0) {
                fn_801EE434(*(void**)(p + 0x2c8));
            }
            if (*(void**)(p + 0x2d8) != 0) {
                fn_801EE434(*(void**)(p + 0x2d8));
            }
        }
        if (*(void**)(this_ + 0x2e8) != 0) {
            fn_801EE434(*(void**)(this_ + 0x2e8));
        }
        if (*(void**)(this_ + 0x2ec) != 0) {
            fn_801EE434(*(void**)(this_ + 0x2ec));
        }
        if (*(s32*)(this_ + 0x238) != 5) {
            fn_80457E54(lbl_8053AF80, 0);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
class Gnl2ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char lbl_8046F090[];
extern const char lbl_8046F0A4[];
extern "C" void fn_801F06F0(void* actor, const char* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, DrawRec* prm);

extern "C" void fn_802E2998(u8* this_) {
    if (*(s32*)(this_ + 0x230) <= 3) {
        f32 x = *(f32*)(this_ + 0xc);
        f32 y = *(f32*)(this_ + 0x10);
        f32 z = *(f32*)(this_ + 0x14);
        for (s32 i = 0; i < 4; i++) {
            *(JGeometry::TVec3<f32>*)(this_ + 0xc) = *(JGeometry::TVec3<f32>*)(this_ + 0x258 + i * 0xc);
            if (*(s32*)(this_ + 0x288 + i * 4) == 1) {
                fn_801F06F0(this_, lbl_8046F090, 0x25a, 0, 7, 1.0f, 1.0f);
            } else {
                fn_801F06F0(this_, lbl_8046F090, 0x25b, 0, 7, 1.0f, 1.0f);
            }
        }
        *(f32*)(this_ + 0xc) = x;
        *(f32*)(this_ + 0x10) = y;
        *(f32*)(this_ + 0x14) = z;
    }
    if (*(s32*)(this_ + 0x238) == 5) {
        DrawRec rec;
        *(s8*)&rec.b1d = -2;
        void* tex = (*(Gnl2ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18('TIMG', lbl_8046F0A4);
        JGeometry::TVec3<f32> pos(80.0f + *(f32*)(this_ + 0xc), 48.0f + *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
        if (*(s32*)(this_ + 4) < 8) {
            fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, tex, &rec);
        }
    }
}

#include "JSystem/JGeometry/Box.h"
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, s32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" s32 fn_8023B8E4(JGeometry::TBox2<f32>* box, s32 room, JGeometry::TVec2<f32>* pos, s32 n);
extern "C" s32 fn_80237060(void);
extern "C" void fn_801F0E34(void* p, s32 a, s32 b);
extern "C" void fn_80134DE4(u8* game, s32 a, s32 b);
extern "C" void fn_80238548(s32 player, s32 a, JGeometry::TVec2<f32>* pos, s32 n);
extern "C" u8 fn_801F2B7C(u8* p, s32 type, s32 a, s32 b);
extern "C" void fn_80239914(JGeometry::TBox2<f32>* box, s32 room, s32 id);
extern "C" u8 fn_802DE7CC(void);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D75BC(void* mgr, s32 id);
extern "C" void fn_801F34DC(u8* p);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_801F0D20(void* p, s32 a);
extern "C" void fn_8030C210(void* view, JGeometry::TVec3<f32>* pos);
extern u8 lbl_8053AC00;
extern void* lbl_8053AED0;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern const f32 lbl_805411C8;
extern const f32 lbl_805411D4;
extern const f32 lbl_805411D8;
extern const f32 lbl_805411DC;
extern const f32 lbl_805411E0;
extern const f32 lbl_805411E4;
extern const f32 lbl_805411E8;
extern const f32 lbl_805411EC;
extern const f32 lbl_805411F0;
struct Gnl2Layout;
extern const Gnl2Layout lbl_8046EA10;

class Gnl2Self {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30(s32 a, s32 b);
};

static inline BOOL gnl2StageFlag(s32 a, s32 b) {
    if (a < 0 || a > 7) return FALSE;
    if (b < 0 || b > 3) return FALSE;
    return ((1 << (b + a * 4)) & *(u32*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x28)) != 0;
}

extern "C" void fn_802E2C28(u8* this_) {
    const u8* t = (const u8*)&lbl_8046EA10;
    s32 i;
    s32 done;
    JGeometry::TBox2<f32> box;
    JGeometry::TVec2<f32> v;
    JGeometry::TBox2<f32>* r60 = (JGeometry::TBox2<f32>*)(this_ + 0x60);
    JGeometry::TBox2<f32>* r80 = (JGeometry::TBox2<f32>*)(this_ + 0x80);
    if (*(s32*)(this_ + 0x230) < 1) {
        *(s32*)(this_ + 0x248) = *(s32*)(this_ + 0x248) + 1;
    }
    *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24c);
    *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x250);
    *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x254);
    f32 x = *(f32*)(this_ + 0xc);
    f32 y = *(f32*)(this_ + 0x10);
    f32 z = *(f32*)(this_ + 0x14);
    switch (*(s32*)(this_ + 0x230)) {
    case 3:
    case 5:
        break;
    case 2:
        (*(s32*)(this_ + 0x2c4))--;
        if (*(s32*)(this_ + 0x2c4) == 0) {
            lbl_8053AC00 = 1;
            *(s32*)(this_ + 0x230) = 0;
        }
    case 0: {
        done = 0;
        if (*(s32*)(this_ + 0x288) == 4) done = 1;
        if (*(s32*)(this_ + 0x28c) == 4) done++;
        if (*(s32*)(this_ + 0x290) == 4) done++;
        if (*(s32*)(this_ + 0x294) == 4) done++;
        for (i = 0; i < 4; i++) {
            *(JGeometry::TVec3<f32>*)(this_ + 0xc) = *(JGeometry::TVec3<f32>*)(this_ + 0x258 + i * 0xc);
            r60->set(lbl_805411D4, lbl_805411D4, lbl_805411D8, lbl_805411D8);
            box.set(*r60);
            v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
            box.addPos(v);
            s32 player = fn_8023B8E4(&box, *(s32*)(this_ + 4), &v, 1);
            s32 st = *(s32*)(this_ + 0x288 + i * 4);
            if (st == 1) {
                if (player >= 0 && fn_80237060() == 2) {
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x113, 1, 1, 0, 0, 1, lbl_805411C8);
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x114, 1, 1, 0, 0, 1, lbl_805411C8);
                    *(s32*)(this_ + 0x288 + i * 4) = 2;
                    *(s32*)(this_ + 0x298 + i * 4) = 20;
                    *(s32*)(this_ + 0x2a8 + i * 4) = 0;
                    this_[0x2c0 + i] = 0xff;
                    fn_801F0E34(this_, 0x3003a, 0);
                    fn_80134DE4(lbl_8053AAF8, 1, 0);
                    if (done >= 3) {
                        *(s32*)(this_ + 0x288 + i * 4) = 3;
                        this_[0x2c0 + i] = 0;
                        (*(u8**)(this_ + 0x2c8 + i * 4))[0xbb] = this_[0x2c0 + i];
                    }
                } else if (player >= 0) {
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x7b, 0, 0, 0, 0, 1, lbl_805411C8);
                    JGeometry::TVec2<f32> at(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                    fn_80238548(player, 0, &at, 10);
                    fn_801F0E34(this_, 0x3008b, 0);
                    *(s32*)(this_ + 0x230) = 2;
                    *(s32*)(this_ + 0x2c4) = 0x2d;
                }
            } else if (st == 2) {
                this_[0x2c0 + i] -= 12;
                (*(s32*)(this_ + 0x298 + i * 4))--;
                if (*(s32*)(this_ + 0x298 + i * 4) == 0) {
                    this_[0x2c0 + i] = 0;
                    *(s32*)(this_ + 0x288 + i * 4) = 3;
                }
                (*(u8**)(this_ + 0x2c8 + i * 4))[0xbb] = this_[0x2c0 + i];
            } else if (st == 3) {
                if (*(void**)(this_ + 0x2c8 + i * 4) != 0) {
                    fn_801EE434(*(void**)(this_ + 0x2c8 + i * 4));
                    *(void**)(this_ + 0x2c8 + i * 4) = 0;
                }
                *(s32*)(this_ + 0x288 + i * 4) = 4;
                if (done >= 3) {
                    *(s32*)(this_ + 0x298 + i * 4) = 1;
                }
            } else if (st == 4) {
                if (*(s32*)(this_ + 0x2a8 + i * 4) != 0) {
                    (*(s32*)(this_ + 0x2a8 + i * 4))--;
                }
                if (*(s32*)(this_ + 0x2a8 + i * 4) == 0 && player >= 0) {
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x113, 1, 1, 0, 0, 1, lbl_805411C8);
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x114, 1, 1, 0, 0, 1, lbl_805411C8);
                    *(s32*)(this_ + 0x2a8 + i * 4) = 20;
                }
            }
            r80->set(lbl_805411D4, lbl_805411D4, lbl_805411D8, lbl_805411D8);
            box = *r80;
            v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
            box.addPos(v);
            fn_80239914(&box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
            if (*(u16*)(this_ + 0x2b8 + i * 2) == 0) {
                continue;
            }
            switch (*(s32*)(this_ + 0x238)) {
            case 0:
            default: {
                r60->set(((const JGeometry::TBox2<f32>(*)[4])(t + 0x1b0))[*(s32*)(this_ + 0x238)][i]);
                box.set(*r60);
                v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                box.addPos(v);
                if (!fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 0x1a)) {
                    r80->set(((const JGeometry::TBox2<f32>(*)[4])(t + 0x2b0))[*(s32*)(this_ + 0x238)][i]);
                    box.set(*r80);
                    v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                    box.addPos(v);
                    fn_80239914(&box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
                }
                break;
            }
            case 1: {
                for (s32 j = 0; j < 3; j++) {
                    r60->set(((const JGeometry::TBox2<f32>(*)[3])(t + 0x3b0))[i][j]);
                    box.set(*r60);
                    v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                    box.addPos(v);
                    if (!fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 0x1a)) {
                        r80->set(((const JGeometry::TBox2<f32>(*)[3])(t + 0x470))[i][j]);
                        box.set(*r80);
                        v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                        box.addPos(v);
                        fn_80239914(&box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
                    }
                }
                break;
            }
            case 4:
                if (i >= 3) {
                    break;
                }
                if (i != 1) {
                    for (s32 j = 0; j < 3; j++) {
                        r60->set(((const JGeometry::TBox2<f32>(*)[3])(t + 0x530))[i][j]);
                        box.set(*r60);
                        v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                        box.addPos(v);
                        if (!fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 4)) {
                            r80->set(((const JGeometry::TBox2<f32>(*)[3])(t + 0x5c0))[i][j]);
                            box.set(*r80);
                            v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                            box.addPos(v);
                            fn_80239914(&box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
                        }
                    }
                } else {
                    r60->set(lbl_805411DC, lbl_805411E0, lbl_805411E4, lbl_805411E8);
                    box.set(*r60);
                    v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                    box.addPos(v);
                    if (!fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 4)) {
                        r80->set(lbl_805411DC, lbl_805411EC, lbl_805411E4, lbl_805411F0);
                        box.set(*r80);
                        v.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                        box.addPos(v);
                        fn_80239914(&box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
                    }
                }
                break;
            case 5:
                break;
            }
        }
        s32 waiting = 0;
        if (*(s32*)(this_ + 0x288) != 4) waiting = 1;
        if (*(s32*)(this_ + 0x28c) != 4) waiting = 1;
        if (*(s32*)(this_ + 0x290) != 4) waiting = 1;
        if (*(s32*)(this_ + 0x294) != 4) waiting = 1;
        if (waiting != 0) {
            break;
        }
        {
            JGeometry::TVec3<f32>& cur = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
            for (s32 k = 0; k < 4; k++) {
                cur = *(JGeometry::TVec3<f32>*)(this_ + 0x258 + k * 0xc);
                fn_8013CC50(*(u32*)(this_ + 4), &cur, 0x7b, 0, 0, 0, 0, 1, lbl_805411C8);
                fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x7c, 0, 0, 0, 0, 1, lbl_805411C8);
                fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x7d, 0, 0, 0, 0, 1, lbl_805411C8);
                u8* emt = *(u8**)(this_ + 0x2d8 + k * 4);
                if (emt != 0) {
                    *(u32*)(emt + 0xf4) |= 1;
                    *(s32*)(emt + 0x24) = 1;
                    *(u8**)(this_ + 0x2d8 + k * 4) = 0;
                }
            }
        }
        if (*(s32*)(this_ + 0x238) == 5) {
            ((Gnl2Self*)this_)->vf30(0xff, 1);
        } else if (*(s32*)(this_ + 0x244) != 0) {
            ((Gnl2Self*)this_)->vf30(0xff, 1);
        }
        if (fn_802DE7CC()) {
            if (!gnl2StageFlag(*(s32*)(lbl_80529DEC + 0x118), *(s32*)(lbl_80529DEC + 0x11c))) {
                fn_8043D67C(lbl_8053AED0, 0x341, 0, 0);
            }
        }
        fn_801F0E34(this_, 0x30039, 0);
        *(s32*)(this_ + 0x230) = 1;
        *(s32*)(this_ + 0x234) = 20;
        break;
    }
    case 1:
        (*(s32*)(this_ + 0x234))--;
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x230) = 4;
            *(s32*)(this_ + 0x234) = 100;
        }
        break;
    case 4:
        (*(s32*)(this_ + 0x234))--;
        if (*(s32*)(this_ + 0x234) == 0) {
            if (*(s32*)(this_ + 0x238) != 5) {
                *(f32*)(this_ + 0xc) = x;
                *(f32*)(this_ + 0x10) = y;
                *(f32*)(this_ + 0x14) = z;
                s32 bonus = 0;
                if (*(s32*)(this_ + 0x248) < 600) {
                    if (lbl_8053AAF8[0x7e] == 1) {
                        bonus = 2;
                    } else {
                        bonus = 1;
                    }
                }
                if (!fn_802D75BC(fn_802D6A9C(), *(s32*)(this_ + 0x16c))) {
                    fn_801F34DC(this_);
                } else {
                    bonus = 0;
                }
                if (*(s32*)((u8*)fn_802D6A9C() + 4) != 7 || *(s32*)((u8*)fn_802D6A9C() + 8) != 3) {
                    Actor_CreateByID(fn_801F856C(), 0x474f414c, *(u32*)(this_ + 4), this_ + 0xc,
                                     (((*(s32*)(this_ + 0x238) + 1) << 12) + 2) + (bonus << 17), -1, -1);
                }
                this_[0x11c] = 0;
            } else {
                *(s32*)(this_ + 0x230) = 5;
            }
        } else if (*(s32*)(this_ + 0x234) == 0x3c) {
            fn_801F0D20(this_, 3);
        }
        break;
    }
    if (*(s32*)(this_ + 0x230) < 4) {
        fn_801F0E34(this_, 0x30038, 0);
    }
    *(f32*)(this_ + 0xc) = x;
    *(f32*)(this_ + 0x10) = y;
    *(f32*)(this_ + 0x14) = z;
    {
        const f32* offs = ((const f32(*)[2])(t + 0x650))[*(s32*)(this_ + 0x238)];
        JGeometry::TVec3<f32> at(*(f32*)(this_ + 0xc) + offs[0], *(f32*)(this_ + 0x10) + offs[1], *(f32*)(this_ + 0x14));
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &at);
    }
    if (*(u8**)(this_ + 0x2e8) != 0) {
        (*(u8**)(this_ + 0x2e8))[0xbb] = this_[0x2f4];
    }
    if (*(u8**)(this_ + 0x2ec) != 0) {
        (*(u8**)(this_ + 0x2ec))[0xbb] = this_[0x2f4];
    }
}

struct Gnl2Layout {
    f32 x[6][4];
    f32 y[6][4];
    f32 dx[6][4];
    f32 dy[6][4];
    u16 eff[6][4];
};
extern const Gnl2Layout lbl_8046EA10;
extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 id);
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, s32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);

#pragma opt_lifetimes off
extern "C" void fn_802E3B2C(u8* this_) {
    const Gnl2Layout* t = &lbl_8046EA10;
    s32 off2;
    u8* half;
    u8* vec;
    s32 off4;
    u8* handle;
    s32 j;
    u8* self = this_;
    const u16* __restrict effs;
    *(u32*)(self + 0x238) = *(u32*)(self + 0x90) & 0x1f;
    *(u32*)(self + 0x240) = (*(u32*)(self + 0x90) >> 22) & 0x1f;
    *(u32*)(self + 0x244) = (*(u32*)(self + 0x90) >> 7) & 1;
    *(s32*)(self + 0x23c) = fn_80138A30(lbl_8053AAF8);
    for (s32 k = 0; k < 4; k++) {
        *(void**)(self + 0x2c8 + k * 4) = 0;
        *(void**)(self + 0x2d8 + k * 4) = 0;
    }
    *(void**)(self + 0x2e8) = 0;
    *(void**)(self + 0x2ec) = 0;
    *(u8*)(self + 0x2f4) = 0xff;
    if (!fn_802D800C(fn_802D6A9C(), *(s32*)(self + 0x240))) {
        const f32* __restrict xs = &t->x[0][0];
        const f32* __restrict ys = &t->y[0][0];
        u8* positions = self;
        u8* state = self;
        s32 i;
        s32 off;
        for (i = 0, off = 0; i < 4; i++, off += 4, positions += 0xc, state += 4) {
            *(f32*)(positions + 0x258) = *(f32*)(self + 0xc) + *(const f32*)((const u8*)xs + (*(s32*)(self + 0x238) << 4) + off);
            *(f32*)(positions + 0x25c) = *(f32*)(self + 0x10) + *(const f32*)((const u8*)ys + (*(s32*)(self + 0x238) << 4) + off);
            *(f32*)(positions + 0x260) = 0.0f;
            *(s32*)(state + 0x298) = 0;
            *(s32*)(state + 0x2a8) = 0;
            *(s32*)(state + 0x288) = 1;
            *(void**)(state + 0x2c8) = fn_8013CC50(*(u32*)(self + 4), positions + 0x258, 0x10a, 0, 0, 0, 0, 1, 1.0f);
        }
        if (*(s32*)(self + 0x238) != 5) {
            j = 0;
            half = self;
            off2 = j;
            vec = self;
            off4 = j;
            handle = self;
            effs = &t->eff[0][0];
            for (; j < 4; j++, half += 2, vec += 0xc, off4 += 4, handle += 4, off2 += 2) {
                *(u16*)(half + 0x2b8) = *(const u16*)((const u8*)effs + (*(s32*)(self + 0x238) << 3) + off2);
                u32 eff = *(const u16*)((const u8*)effs + (*(s32*)(self + 0x238) << 3) + off2);
                if (eff != 0) {
                    const f32* __restrict dy = &t->dy[0][0];
                    const f32* __restrict dx = &t->dx[0][0];
                    s32 idx = (*(s32*)(self + 0x238) << 4) + off4;
                    JGeometry::TVec3<f32> pos;
                    pos.set(*(f32*)(vec + 0x258) + *(const f32*)((const u8*)dx + idx), *(f32*)(vec + 0x25c) + *(const f32*)((const u8*)dy + idx), *(f32*)(vec + 0x260));
                    *(void**)(handle + 0x2d8) = fn_8013CC50(*(u32*)(self + 4), &pos, eff, 1, 1, 0, 0, 1, 1.0f);
                }
            }
        }
        *(s32*)(self + 0x230) = 0;
        *(s32*)(self + 0x234) = 0;
        ((JGeometry::TVec3<f32>*)(self + 0x24c))->set(*(JGeometry::TVec3<f32>*)(self + 0xc));
    } else {
        ((JGeometry::TVec3<f32>*)(self + 0x24c))->set(*(JGeometry::TVec3<f32>*)(self + 0xc));
        *(s32*)(self + 0x230) = 5;
    }
    if (*(s32*)(self + 0x238) == 5) {
        JGeometry::TVec3<f32> a(80.0f + *(f32*)(self + 0xc), 48.0f + *(f32*)(self + 0x10), *(f32*)(self + 0x14));
        *(void**)(self + 0x2e8) = fn_8013CC50(*(u32*)(self + 4), &a, 0xc6, 0, 0, 0, 0, 1, 1.0f);
        JGeometry::TVec3<f32> b(80.0f + *(f32*)(self + 0xc), 48.0f + *(f32*)(self + 0x10), *(f32*)(self + 0x14));
        *(void**)(self + 0x2ec) = fn_8013CC50(*(u32*)(self + 4), &b, 0xc7, 0, 0, 0, 0, 1, 1.0f);
    }
    *(s32*)(self + 0x248) = 0;
    if (*(s32*)(self + 0x238) != 5) {
        fn_80457E54(lbl_8053AF80, 1);
    }
}
#pragma opt_lifetimes reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
