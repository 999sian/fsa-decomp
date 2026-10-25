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
extern "C" void fn_802EB90C(char* this_) {
    char* p = this_;
    s32 i;
    JGeometry::TBox2f box;
    f32 y = *(f32*)(p + 0x10);
    f32 x = *(f32*)(p + 0xc);
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
        for (i=0; i<4; i++) {
            JGeometry::TVec3f v(*fn_8023E724(i));
            JGeometry::TVec3f pos(v);
            pos.x=1.0f+v.x;
            pos.y=v.y-12.0f;
            pos.z=v.z;
            if ((u8)fn_8022F514(i)==1) {
                if (i == *(s32*)(p + 0x244)) { u32 param = 0x80000000 + (*(u32*)(p + 0x244) << 26) + ((i << 24) + *(u32*)(p + 0x234));
                    s32 room = fn_8023DE58(i);
                    ((TkraObj*)p)->ids[i] = Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1); }
            } else {
                if (i == *(s32*)(p + 0x244)) { u32 param = 0x80000000 + (*(u32*)(p + 0x244) << 26) + ((i << 24) + *(u32*)(p + 0x234));
                    s32 room = fn_8023DE58(i);
                    ((TkraObj*)p)->ids[i] = Actor_CreateByID(fn_801F856C(), 'IMUP', room, &pos, param, -1, -1); }
            }
        }
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
