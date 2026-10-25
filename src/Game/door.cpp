// TU 0x802c5950-0x802c8500 (actor DOOR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Box.h"

// ---- fn_802C5950_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A8D88[];

extern "C" void* fn_802C5950(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8D88;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// fn_802C59B0 - DOOR: add a 2D offset to this->0x258.
extern "C" void fn_802C59B0(char* p, const f32* d) {
    *(f32*)(p + 0x258) += d[0];
    *(f32*)(p + 0x25c) += d[1];
}

// ---- oscluster_802c59d4.cpp ----
extern "C" {

// fn_802C59D4(this) - DOOR's real draw(). A pure no-op override (just
// `blr`) - DOOR renders nothing itself, confirming its visual
// representation is static level geometry rather than an actor-drawn
// model. See [[project_fsa_door_key0_full_depth]].
void fn_802C59D4(void)
{
}

} // extern "C"

// ---- Actor_SetVec3_0x0.cpp ----
// Actor_SetVec3_0x0 - trivial 3-float vector setter (this->0x0/0x4/0x8 = x,y,z).
extern "C" void Actor_SetVec3_0x0(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

// ---- fn_802C7CC8: DOOR init (vtable slot 1) ----
extern "C" s32 fn_80226BC4(JGeometry::TVec2<f32>* pos, s32 room);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D49A8(void* cfg, s32 room, u16 tile);
extern "C" u8 fn_802D4ADC(void* cfg, s32 room, u16 tile);
extern const f32 lbl_80540D00;
extern const f32 lbl_80540D14;
extern const f32 lbl_80540D30;
extern const f32 lbl_80540D34;
extern const f32 lbl_80540D40;
extern const f32 lbl_80540D44;
extern const f32 lbl_80540D48;
extern const f32 lbl_80540D4C;
extern const f32 lbl_80540D50;
extern const f32 lbl_80540D54;

struct DoorVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void open();
};

static inline void doorShift(char* p, f32 dx, f32 dy) {
    *(f32*)(p + 0xc) += dx;
    *(f32*)(p + 0x10) += dy;
}

static inline void doorShiftDir(char* p, f32 d) {
    switch (*(s32*)(p + 0x238)) {
    case 0:
        doorShift(p, d, lbl_80540D34);
        break;
    case 1:
        doorShift(p, d, lbl_80540D30);
        break;
    case 2:
        doorShift(p, lbl_80540D30, d);
        break;
    case 3:
        doorShift(p, lbl_80540D34, d);
        break;
    }
}

extern "C" void fn_802C7CC8(char* p) {
    *(JGeometry::TVec3<f32>*)(p + 0x258) = *(JGeometry::TVec3<f32>*)(p + 0xc);
    *(s32*)(p + 0x234) = *(u32*)(p + 0x90) & 0x7f;
    *(s32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 7) & 0x1f;
    *(s32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
    *(s32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 17) & 1;
    *(s32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 18) & 1;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x248) = -1;
    if (*(s32*)(p + 0x234) == 0) {
        *(s32*)(p + 0x230) = 0;
    } else {
        *(s32*)(p + 0x230) = 1;
    }
    ((JGeometry::TBox2<f32>*)(p + 0x60))->set(lbl_80540D40, lbl_80540D40, lbl_80540D14, lbl_80540D14);
    switch (*(s32*)(p + 0x234)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
        switch (*(s32*)(p + 0x23c)) {
        case 0:
            switch (*(s32*)(p + 0x238)) {
            case 0:
                doorShift(p, lbl_80540D30, lbl_80540D34);
                break;
            case 1:
                doorShift(p, lbl_80540D30, lbl_80540D30);
                break;
            case 2:
                doorShift(p, lbl_80540D30, lbl_80540D30);
                break;
            case 3:
                doorShift(p, lbl_80540D34, lbl_80540D30);
                break;
            }
            break;
        case 1:
            switch (*(s32*)(p + 0x238)) {
            case 0:
                doorShift(p, lbl_80540D44, lbl_80540D34);
                break;
            case 1:
                doorShift(p, lbl_80540D44, lbl_80540D30);
                break;
            case 2:
                doorShift(p, lbl_80540D30, lbl_80540D44);
                break;
            case 3:
                doorShift(p, lbl_80540D34, lbl_80540D44);
                break;
            }
            break;
        case 2:
            switch (*(s32*)(p + 0x238)) {
            case 0:
                doorShift(p, lbl_80540D48, lbl_80540D34);
                break;
            case 1:
                doorShift(p, lbl_80540D48, lbl_80540D30);
                break;
            case 2:
                doorShift(p, lbl_80540D30, lbl_80540D48);
                break;
            case 3:
                doorShift(p, lbl_80540D34, lbl_80540D48);
                break;
            }
            break;
        }
        break;
    case 5:
        ((JGeometry::TBox2<f32>*)(p + 0x60))->set(lbl_80540D4C, lbl_80540D4C, lbl_80540D50, lbl_80540D50);
        doorShift(p, lbl_80540D14, lbl_80540D14);
        *(s32*)(p + 0x230) = 2;
        break;
    case 6:
        ((JGeometry::TBox2<f32>*)(p + 0x60))->set(lbl_80540D54, lbl_80540D54, lbl_80540D30, lbl_80540D30);
        doorShift(p, lbl_80540D00, lbl_80540D00);
        *(s32*)(p + 0x230) = 2;
        break;
    case 7:
        ((JGeometry::TBox2<f32>*)(p + 0x60))->set(lbl_80540D4C, lbl_80540D4C, lbl_80540D50, lbl_80540D50);
        doorShift(p, lbl_80540D00, lbl_80540D14);
        *(s32*)(p + 0x230) = 2;
        break;
    }
    JGeometry::TVec2<f32>* org = (JGeometry::TVec2<f32>*)(p + 0x264);
    org->set(((JGeometry::TVec2<f32>*)(p + 0xc))->x, ((JGeometry::TVec2<f32>*)(p + 0xc))->y);
    JGeometry::TBox2<f32>* box = (JGeometry::TBox2<f32>*)(p + 0x26c);
    box->set(*(JGeometry::TBox2<f32>*)(p + 0x60));
    box->addPos(*org);
    if (*(s32*)(p + 0x23c) == 0 || (*(s32*)(p + 0x23c) == 2 && *(s32*)(p + 0x234) == 0)) {
        JGeometry::TVec2<f32> pos(*(f32*)(p + 0x258), *(f32*)(p + 0x25c));
        *(s32*)(p + 0x244) = fn_80226BC4(&pos, *(s32*)(p + 0x4));
    } else if (*(s32*)(p + 0x238) < 2) {
        JGeometry::TVec2<f32> pos(lbl_80540D00 + *(f32*)(p + 0x258), *(f32*)(p + 0x25c));
        *(s32*)(p + 0x244) = fn_80226BC4(&pos, *(s32*)(p + 0x4));
    } else {
        JGeometry::TVec2<f32> pos(*(f32*)(p + 0x258), lbl_80540D00 + *(f32*)(p + 0x25c));
        *(s32*)(p + 0x244) = fn_80226BC4(&pos, *(s32*)(p + 0x4));
    }
    s32 type = *(s32*)(p + 0x234);
    if ((type >= 1 && type <= 4) || type == 8) {
        s32 room = *(s32*)(p + 0x4);
        if (room < 8) {
            if (fn_802D49A8(fn_802D6A9C(), room, *(s32*)(p + 0x244)) == 1) {
                *(s32*)(p + 0x230) = 3;
                ((DoorVT*)p)->open();
                *(s32*)(p + 0x230) = 5;
            }
        } else {
            if (fn_802D4ADC(fn_802D6A9C(), room, *(s32*)(p + 0x244)) == 1) {
                *(s32*)(p + 0x230) = 3;
                ((DoorVT*)p)->open();
                *(s32*)(p + 0x230) = 5;
            }
        }
    } else if (type >= 5) {
        if (fn_802D4ADC(fn_802D6A9C(), *(s32*)(p + 0x4), *(s32*)(p + 0x244)) == 1) {
            *(s32*)(p + 0x230) = 5;
        }
    } else {
        ((DoorVT*)p)->open();
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
