// TU 0x80221b44-0x802223fc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

extern "C" {
void fn_801CDD58();
void fn_801CE120();
void fn_801CE4BC();
void fn_801CE4E4();
void fn_801CE594();
void fn_801CE694();
void fn_801CE914();
void fn_801CE918();
void fn_801CE920();
void fn_801CE928();
void fn_801CE98C();
void fn_801CEB78();
void fn_801CECEC();
void fn_801D0ECC();
void fn_80220F54();
void fn_80221114();
void fn_80221158();
void fn_80221160();
void fn_80221184();
void v02__5ActorFv();
void v04__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFv();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v15__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFv();
void v18__5ActorFv();
void* fn_80221B44(void* this_, s16 freeFlag);
void fn_80222124(void* this_);
void fn_80221BE4(void* this_);
void fn_80221C4C(void* this_);
void fn_80221C18(void* this_);
}
void* lbl_804A6AA8[] = {
    0,
    0,
    (void*)fn_80221B44,
    (void*)fn_80222124,
    (void*)v02__5ActorFv,
    (void*)fn_801CDD58,
    (void*)v04__5ActorFv,
    (void*)v05__5ActorFv,
    (void*)fn_80220F54,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFv,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)v15__5ActorFv,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFv,
    (void*)v18__5ActorFv,
    (void*)fn_801D0ECC,
    (void*)fn_801CECEC,
    (void*)fn_801CEB78,
    (void*)fn_80221158,
    (void*)fn_801CE98C,
    (void*)fn_801CE928,
    (void*)fn_80221184,
    (void*)fn_801CE920,
    (void*)fn_80221160,
    (void*)fn_801CE918,
    (void*)fn_801CE914,
    (void*)fn_801CE694,
    (void*)fn_801CE594,
    (void*)fn_80221BE4,
    (void*)fn_801CE4E4,
    (void*)fn_80221C4C,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_80221C18,
    (void*)fn_80221114,
};

// ---- fn_80221B44_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6AA8[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80221B44(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6AA8;
        if (this_ != 0) {
            *(void**)p = lbl_804A6A00;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_80221BE4.cpp ----
extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

// fn_80221BE4 - fn_80222190's own vtable-0x88 override (see
// extab_80221b44.s and project_fsa_growing_area_extension.md). If
// this->0x248 == 2 (a specific state), calls fn_80221250 (a
// not-further-decompiled "already settled" behavior); otherwise falls
// through to the generic 0x88 default fn_801CE4E8 (direction-vector
// update + growth-step chain).
extern "C" void fn_80221BE4(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}

// ---- fn_80222190_ctor.cpp ----

// ---- fn_80221C18 / fn_80221C4C / fn_80222124 ----
#include "JSystem/JGeometry.h"

extern "C" {
extern const f32 lbl_8053FE70;
extern void* lbl_8053AAF8;
void fn_80221210(void* this_);
void fn_800F802C(void* obj);
void fn_800F8210(void* obj, u32 id, JGeometry::TVec3<f32>* pos, s32 n);
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_802216E8(void* this_, s32 t);
void fn_8022149C(void* this_, s32 a);
void fn_802217C8(void* this_);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);
u8 fn_801D21F0(void* anim);
s32 fn_8013CC50(u32 id, void* pos, s32 kind, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
void* fn_802D6A9C(void);
void fn_802D79E8(void* mgr, u32 a, void* b, f32 x, f32 y);
void fn_80134DE4(void* game, s32 a, void* b);
u8 fn_802258D4(JGeometry::TVec3<f32>* pos, u32 id);
u8 fn_80225614(JGeometry::TVec3<f32>* pos, u32 id);

void fn_80221C18(void* this_) {
    fn_80221210(this_);
    fn_800F802C((char*)this_ + 0x2bc);
}

void fn_80221C4C(void* this_) {
    char* p = (char*)this_;
    JGeometry::TVec3<f32> tmp; JGeometry::TVec3<f32> pos; JGeometry::TVec3<f32> pos5;
    switch (*(u32*)(p + 0x248)) {
    case 0:
        fn_80221408(this_);
        break;
    case 1:
        fn_80221334(this_);
        break;
    case 2:
        fn_802212AC(this_);
        break;
    case 3:
        if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250)) {
            fn_801D22DC(p + 0x270, 0x18, 0, 0);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 5;
        }
        break;
    case 4:
        fn_802216E8(this_, 0x3c);
        if (*(f32*)(p + 0x14) <= 0.0f) {
            if (*(u32*)(p + 0x230) & 0x2000) {
                fn_801D22DC(p + 0x270, 0x18, 0, 0);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 5;
            } else {
                *(f32*)(p + 0x44) = lbl_8053FE70;
            }
        }
        break;
    case 5:
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            fn_801D22DC(p + 0x270, 0x19, 0, 0);
            pos5 = *(JGeometry::TVec3<f32>*)(p + 0xc);
            pos5.y -= 22.0f;
            fn_8013CC50(*(u32*)(p + 0x4), &pos5, 0xcb, 1.0f, 0, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), &pos5, 0xcc, 1.0f, 0, 1, 0, 0, 1);
            fn_801F0E34(this_, 0x400c4, 0);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 6;
        }
        break;
    case 6:
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            fn_801D22DC(p + 0x270, 0x1a, 0, 0);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 7;
        }
        break;
    case 7:
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            (*(s32*)(p + 0x2b8))++;
            if (*(s32*)(p + 0x2b8) >= 3) {
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 0, 0);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 8;
            } else {
                *(s32*)(p + 0x250) = 0x78;
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 0, 0);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 3;
            }
        } else if (*(s32*)(p + 0x24c) == 3) {
            pos.set(*(f32*)(p + 0xc), *(f32*)(p + 0x10), 0.0f);
            switch (*(s32*)(p + 0x98)) {
            case 0:
                pos.x += 12.0f;
                break;
            case 1:
                pos.x -= 12.0f;
                break;
            case 2:
                pos.y += 12.0f;
                break;
            case 3:
                pos.y -= 12.0f;
                break;
            }
            u32 id = *(u32*)(p + 0x4);
            tmp = pos;
            fn_800F8210(p + 0x2bc, id, &tmp, 2);
            fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x23b, 1.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x23c, 1.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x23d, 5.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x23e, 2.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x23f, 2.0f, 0, 0, 0, 0, 1);
            if (fn_802258D4(&pos, *(u32*)(p + 0x4)) || fn_80225614(&pos, *(u32*)(p + 0x4))) {
                fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x3d0, 2.0f, 0, 0, 0, 0, 1);
            } else {
                fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x3cf, 2.0f, 0, 0, 0, 0, 1);
            }
            fn_801F0E34(this_, 0x400e6, 0);
            fn_802D79E8(fn_802D6A9C(), *(u32*)(p + 0x4), 0, 4.0f, 0.0f);
            fn_80134DE4(lbl_8053AAF8, 1, 0);
        }
        break;
    case 8:
        if (*(s32*)(p + 0x24c) >= 0x3c) {
            fn_8022149C(this_, 1);
        }
        break;
    }
}

void fn_80222124(void* this_) {
    char* p = (char*)this_;
    fn_802217C8(this_);
    *(s32*)(p + 0x98) = 2;
    *(s32*)(p + 0x248) = 4;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_801D22DC(p + 0x270, 2, 0, 0);
}
}

extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6AA8[];

extern "C" void* fn_80222190(void* this_) {
    fn_802218C8(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A6AA8;
    *(s32*)(p + 0x2b8) = 0;
    *(char*)(p + 0x2c8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
