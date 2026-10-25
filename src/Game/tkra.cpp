// TU 0x802eb21c-0x802ec1d4 (actor TKRA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tkra_dtor_802EB21C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA178[];

extern "C" void* fn_802EB21C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA178;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// fn_802EB27C - TKRA: releases every linked actor that is in state 3;
// returns whether any was found.
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 fn_801597B8(void* a);
extern "C" void fn_801597C0(void* a);
#include "JSystem/JGeometry/Vec.h"
struct TkraG;
extern "C" TkraG* fn_802D6A9C(void);
extern "C" bool fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, JGeometry::TVec3f*, u32, s32, s32);
extern "C" u8 fn_802308E0(s32);
extern "C" u8 fn_8023077C(void);
extern "C" void fn_8037AE30(void*);
extern "C" s32 fn_80138A30(void*);
extern "C" s32 fn_801F6058(void*, s32);
extern "C" s32 fn_801CD664(s32);
extern "C" void fn_80230FD0(s32, s32);
extern "C" void fn_802A3948(void*, void*, s32, s32, s32);
extern "C" s32 fn_802D4C10(TkraG*, s32, u16);
extern "C" void fn_802D7D00(TkraG*, s32, s32, s32);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern u8* lbl_8053AAF8;
extern void* lbl_8053AD70;
extern void* lbl_8053AC98;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern const f32 lbl_805413B0;
extern const f32 lbl_805413B4;
extern const f32 lbl_805413B8;
extern const f32 lbl_805413BC;
extern "C" void* fn_801F856C();
static inline void tkraSpawnItem(s32 player, JGeometry::TVec3f* pos, u32 hi, s32 kind) {
    u32 param = kind + hi;
    s32 room = fn_8023DE58(player);
    Actor_CreateByID(fn_801F856C(), 'IMUP', room, pos, param, -1, -1);
}
struct TkraObj {
    u8 pad[0x24c];
    s32 ids[4];
};
extern "C" u8 fn_802EB27C(TkraObj* p) {
    u8 found = 0;
    for (s32 i = 0; i < 4; i++) {
        s32 v = p->ids[i];
        if (v >= 0) {
            void* a = fn_801F666C(fn_801F856C(), v);
            v = (s32)a;
            if (v != 0 && fn_801597B8((void*)v) == 3) {
                fn_801597C0((void*)v);
                found = 1;
            }
        }
    }
    return found;
}

extern "C" u8 fn_802EB314(char* p) {
    u8 ret;
    u8 ok;
    u32 bits;
    int i;
    f32 dy;
    f32 dx;
    ret = 0;
    ok = 0;
    if (lbl_8053AAF8[0x7e] == 1) {
        if (fn_802308E0(*(s32*)(p + 0x240)) == 1) {
            ok = 1;
        }
    } else if (fn_8023077C() == 1) {
        fn_8037AE30(lbl_8053AD70);
        ok = 1;
    }
    if (ok == 1) {
        if (lbl_8053AAF8[0x7e] == 1) {
            s32 bit;
            s32 x = *(s32*)(lbl_80529DEC + 0x118);
            s32 y = *(s32*)(lbl_80529DEC + 0x11c);
            if (x < 0 || x > 7) {
                bit = 0;
            } else if (y < 0 || y > 3) {
                bit = 0;
            } else {
                u8* saves = lbl_8050EC80;
                u32 mask = 1u << (y + x * 4);
                s32 slot = *(s32*)(saves + 0x10);
                bit = mask & *(u32*)(saves + 0x28 + 0xc8 * slot);
                bit = bit != 0;
            }
            if (bit != 0) {
                s32 k = *(s32*)(p + 0x234);
                if (k <= 2 || k == 0x2f) {
                    s32 n = fn_80138A30(lbl_8053AAF8);
                    if (*(s32*)(p + 0x240) == fn_801F6058(fn_801F856C(), n - 1)) {
                        s32 chance = 20;
                        if (fn_80138A30(lbl_8053AAF8) == 3) {
                            chance = 30;
                        } else if (fn_80138A30(lbl_8053AAF8) == 4) {
                            chance = 50;
                        }
                        if (fn_801CD664(100) <= chance) {
                            *(s32*)(p + 0x234) = 0x20;
                        }
                    }
                }
            }
        }
        dx = lbl_805413B0;
        dy = lbl_805413B4;
        for (i = 0, bits = 0; i < 4; i++, bits += 0x1000000) {
            JGeometry::TVec3f v;
            JGeometry::TVec3f pos;
            v = *fn_8023E724(i);
            pos = v;
            pos.x = dx + v.x;
            pos.y = v.y - dy;
            pos.z = v.z;
            s32 k = *(s32*)(p + 0x234);
            if (k >= 0x30) {
                if (lbl_8053AAF8[0x7e] == 1) {
                    if ((u8)fn_8022F514(i) == 1) {
                        if (*(s32*)(p + 0x248) == fn_8022F3DC(i)) {
                            if (i == *(s32*)(p + 0x240)) {
                                s32 room;
                                u32 param = bits + (*(u32*)(p + 0x240) << 26);
                                param = *(s32*)(p + 0x234) + param;
                                room = fn_8023DE58(i);
                                Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1);
                            } else {
                                u32 param = bits + (*(u32*)(p + 0x240) << 26);
                                param += 0x10000000;
                                param = *(s32*)(p + 0x234) + param;
                                s32 room = fn_8023DE58(i);
                                Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1);
                            }
                        }
                    } else if (i == *(s32*)(p + 0x248)) {
                        if (i == *(s32*)(p + 0x240)) {
                            u32 param = bits + (*(u32*)(p + 0x240) << 26);
                            param = *(s32*)(p + 0x234) + param;
                            s32 room = fn_8023DE58(i);
                            Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1);
                        } else {
                            u32 param = bits + (*(u32*)(p + 0x240) << 26);
                            param += 0x10000000;
                            param = *(s32*)(p + 0x234) + param;
                            s32 room = fn_8023DE58(i);
                            Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1);
                        }
                    }
                } else {
                    s32 pl = *(s32*)(p + 0x240);
                    if (i == pl) {
                        s32 room = fn_8023DE58(i);
                        Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, k + (bits + ((u32)pl << 26)), -1, -1);
                    } else {
                        s32 room = fn_8023DE58(i);
                        u32 param = bits + ((u32)pl << 26);
                        param += 0x10000000;
                        Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, k + param, -1, -1);
                    }
                }
            } else {
                if ((u8)fn_8022F514(i) == 1 && *(s32*)(p + 0x248) == fn_8022F3DC(i)) {
                    if (i == *(s32*)(p + 0x240)) {
                        u32 param = bits + (*(u32*)(p + 0x240) << 26);
                        param += 0x800000;
                        param = *(s32*)(p + 0x234) + param;
                        s32 room = fn_8023DE58(i);
                        Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1);
                    }
                } else if (i == *(s32*)(p + 0x248) && i == *(s32*)(p + 0x240)) {
                    u32 param = bits + (*(u32*)(p + 0x240) << 26);
                    param += 0x800000;
                    param = *(s32*)(p + 0x234) + param;
                    s32 room = fn_8023DE58(i);
                    Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1);
                }
            }
        }
        if (*(s32*)(p + 0x238) == 0) {
            fn_80230FD0(*(s32*)(p + 0x240), 0x20013);
            fn_802A3948(lbl_8053AC98, p + 0x25c, 0, *(s32*)(p + 4), 0x10);
            s32 r = fn_802D4C10(fn_802D6A9C(), *(s32*)(p + 4), *(u32*)(p + 0x23c));
            if (r != -1) {
                fn_802D7D00(fn_802D6A9C(), *(s32*)(p + 4), r, 1);
            }
            JGeometry::TVec3f a(lbl_805413B8 + *(f32*)(p + 0x25c), lbl_805413B8 + *(f32*)(p + 0x260), lbl_805413BC);
            fn_8013CC50(*(s32*)(p + 4), &a, 0xd0, 0, 0, 0, 0, 1, lbl_805413B0);
            JGeometry::TVec3f b(lbl_805413B8 + *(f32*)(p + 0x25c), lbl_805413B8 + *(f32*)(p + 0x260), lbl_805413BC);
            fn_8013CC50(*(s32*)(p + 4), &b, 0xd1, 1, 0, 0, 0, 1, lbl_805413B0);
        }
        ret = 1;
    }
    return ret;
}

// ---- Tkra_EmptyHook.cpp ----
// Tkra_EmptyHook - TKRA: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Tkra_EmptyHook(void) {}

}

#include "JSystem/JGeometry/Vec.h"
struct TkraG { u8 pad[0x131df]; u8 arr[4]; };
extern "C" TkraG* fn_802D6A9C(void);
extern "C" u32 fn_80226BC4(f32* pos, s32 room);
extern "C" u8 fn_802D49A8(void* g, s32 room, u16 idx);
extern const f32 lbl_805413B0;
extern const f32 lbl_805413B4;
extern const f32 lbl_805413B8;
extern const f32 lbl_805413BC;
extern const f32 lbl_805413C0;
extern const f32 lbl_805413C8;
extern const f32 lbl_805413CC;
extern const f32 lbl_805413D0;
extern const f32 lbl_805413D4;
extern const f32 lbl_805413E8;

#include "JSystem/JGeometry/Box.h"
#include "Game/ItemBase.h"
extern "C" s32 fn_8023AF14(void*, s32, s32, f32);
extern "C" u16 fn_802F9908(void*, s32, u32);
extern "C" s32 fn_80230CFC(s32);
extern "C" void fn_8022FEB8(void*, s32, s32, s32, s32);
extern "C" bool fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" bool fn_8023EFEC(s32);
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8030AAF4(s32);
extern "C" u32 fn_80309D6C(void*, s32, u32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, JGeometry::TVec3f*, u32, s32, s32);
extern char* lbl_8053AB10;
extern void* lbl_8053AD30;

struct TKRA {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual u8 open();
};

inline u8 tkraRoomMode(char* p) {
    s32 room = *(s32*)(p + 4);
    TkraG* g = fn_802D6A9C();
    return g->arr[(u32)room];
}

struct TkraV2 { f32 x, y; };
inline s32 tkraCreateItem(s32 player, JGeometry::TVec3f* pos, u32 param) {
    s32 room = fn_8023DE58(player);
    return Actor_CreateByID(fn_801F856C(), 'IMUP', room, pos, param, -1, -1);
}

inline void tkraCreateItems(char* p) {
    int i;
    char* out;
    u32 bits;
    JGeometry::TVec3f pos;
    JGeometry::TVec3f v;
        f32 dx = lbl_805413B0;
        out = p;
        f32 dy = lbl_805413B4;
        for (i=0, bits=0UL; i<4; i++, bits+=0x1000000, out+=4) {
            v = *fn_8023E724(i);
            pos = v;
            pos.x=dx+v.x;
            pos.y=v.y-dy;
            pos.z=v.z;
            if ((u8)fn_8022F514(i)==1) {
                if (i == *(s32*)(p + 0x244)) { s32 room; u32 param = (bits + *(u32*)(p + 0x234));
                    param = (s32)(0x80000000 + (*(u32*)(p + 0x244) << 26)) + (s32)param;
                    room = fn_8023DE58(i);
                    *(s32*)(out + 0x24c) = Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1); }
            } else {
                if (i == *(s32*)(p + 0x244)) { u32 param = (bits + *(u32*)(p + 0x234));
                    param = (s32)(0x80000000 + (*(u32*)(p + 0x244) << 26)) + (s32)param;
                    s32 room = fn_8023DE58(i);
                    *(s32*)(out + 0x24c) = Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1); }
            }
        }

}

extern "C" void fn_802EB90C(char* this_) {
    char* p = this_;
    JGeometry::TBox2f box;
    f32 x, y;
    y = *(f32*)(p + 0x10);
    x = *(f32*)(p + 0xc);
    if (tkraRoomMode(p)) { *(f32*)(p + 0x60)=-10.0f; *(f32*)(p + 0x64)=2.0f; *(f32*)(p + 0x68)=10.0f; *(f32*)(p + 0x6c)=5.0f; }
    else { *(f32*)(p + 0x60)=-6.0f; *(f32*)(p + 0x64)=0.0f; *(f32*)(p + 0x68)=6.0f; *(f32*)(p + 0x6c)=5.0f; }
    box.set(*(JGeometry::TBox2f*)(p + 0x60));
    box.addPos(x,y);
    *(s32*)(p + 0x240)=fn_8023AF14(&box,*(s32*)(p + 4),0,0.0f);
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if ((u16)fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(s32*)(p + 4), *(u32*)(p + 0x23c)) == 0x30) *(s32*)(p + 0x230)=1;
        break;
    case 1: {
        u8 allowed = 0;
        if (*(s32*)(p + 0x240) < 0) break;
        if (tkraRoomMode(p)) {
            if (fn_80230CFC(*(s32*)(p + 0x240)) == 3 || fn_80230CFC(*(s32*)(p + 0x240)) == 0 || fn_80230CFC(*(s32*)(p + 0x240)) == 1) allowed=1;
        } else if (fn_80230CFC(*(s32*)(p + 0x240)) == 3) allowed=1;
        if (allowed == 1) {
            *(f32*)(p + 0x60)=-20.0f; *(f32*)(p + 0x64)=-18.0f; *(f32*)(p + 0x68)=20.0f; *(f32*)(p + 0x6c)=18.0f;
            box.set(*(JGeometry::TBox2f*)(p + 0x60));
            box.addPos(x,y);
            fn_8022FEB8(&box,*(s32*)(p + 4),*(s32*)(p + 0x198),1,1);
        }
        *(s32*)(p + 0x248)=*(s32*)(p + 0x240);
        if (fn_8022F514(*(s32*)(p + 0x240))) *(s32*)(p + 0x248)=fn_8022F3DC(*(s32*)(p + 0x240));
        if (allowed == 1 && !fn_8023EFEC(*(s32*)(p + 0x240)) && *(s32*)(p + 0x240)==fn_8022EA0C(*(s32*)(p + 0x240)) &&
            fn_80309D6C(lbl_8053AD30,fn_8030AAF4(*(s32*)(p + 0x248)),0x100) != 0 &&
            ((TKRA*)p)->open()) p[0x11c]=0;
        break;
    }
    case 2:
        *(s32*)(p + 0x240)=*(s32*)(p + 0x244);
        *(s32*)(p + 0x248)=*(s32*)(p + 0x240);
        if (fn_8022F514(*(s32*)(p + 0x240))) *(s32*)(p + 0x248)=fn_8022F3DC(*(s32*)(p + 0x240));
        tkraCreateItems(p);
        if (*(s32*)(p + 0x238)!=1) p[0x11c]=0;
        else *(s32*)(p + 0x230)=4;
        break;
    case 3:
        *(s32*)(p + 0x240)=*(s32*)(p + 0x244);
        *(s32*)(p + 0x248)=*(s32*)(p + 0x240);
        if (fn_8022F514(*(s32*)(p + 0x240))) *(s32*)(p + 0x248)=fn_8022F3DC(*(s32*)(p + 0x240));
        if (((TKRA*)p)->open()) p[0x11c]=0;
        break;
    case 4: break;
    }
}

extern "C" void fn_802EBDCC(char* this_) {
    *(s32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xff;
    *(s32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    if (*(s32*)(this_ + 0x244) >= 4) {
        *(s32*)(this_ + 0x244) = -1;
    }
    s32 k = *(s32*)(this_ + 0x234);
    if ((k >= 0x1a && k < 0x20) || (k >= 0x26 && k < 0x2a) || (k >= 0x3b && k < 0x40) || k >= 0x4b ||
        (k == 0x2e && *(s32*)(this_ + 0x4) >= 8)) {
        *(s32*)(this_ + 0x234) = 0;
    }
    *(JGeometry::TVec3<f32>*)(this_ + 0x25c) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    *(f32*)(this_ + 0xc) += lbl_805413B8;
    *(f32*)(this_ + 0x10) += lbl_805413B4;
    s32 room = *(s32*)(this_ + 0x4);
    TkraG* g = fn_802D6A9C();
    if (g->arr[room] != 0) {
        *(f32*)(this_ + 0x60) = lbl_805413C0;
        *(f32*)(this_ + 0x64) = lbl_805413E8;
        *(f32*)(this_ + 0x68) = lbl_805413C8;
        *(f32*)(this_ + 0x6c) = lbl_805413CC;
    } else {
        *(f32*)(this_ + 0x60) = lbl_805413D0;
        *(f32*)(this_ + 0x64) = lbl_805413BC;
        *(f32*)(this_ + 0x68) = lbl_805413D4;
        *(f32*)(this_ + 0x6c) = lbl_805413CC;
    }
    JGeometry::TVec2<f32> p(*(f32*)(this_ + 0x25c), *(f32*)(this_ + 0x260));
    *(u32*)(this_ + 0x23c) = fn_80226BC4((f32*)&p, *(s32*)(this_ + 0x4));
    if (fn_802D49A8(fn_802D6A9C(), *(s32*)(this_ + 0x4), *(u32*)(this_ + 0x23c)) == 1) {
        this_[0x11c] = 0;
    }
    if (*(s32*)(this_ + 0x238) == 0) {
        *(s32*)(this_ + 0x230) = 0;
    } else if (*(s32*)(this_ + 0x238) == 2) {
        *(s32*)(this_ + 0x230) = 3;
    } else {
        *(s32*)(this_ + 0x230) = 2;
    }
    *(s32*)(this_ + 0x248) = -1;
    *(s32*)(this_ + 0x24c) = -1;
    *(s32*)(this_ + 0x250) = -1;
    *(s32*)(this_ + 0x254) = -1;
    *(s32*)(this_ + 0x258) = -1;
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
