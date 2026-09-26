// ICCL_8010B284: .text 0x8010B284-0x8010C294 (actor ICCL)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8010BF7C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CFC8[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8010BF7C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CFC8;
        fn_801EE434(*(void**)(p + 0x27c));
        *(s32*)(p + 0x27c) = 0;
        if (p + 0x244 != 0) {
            if (p + 0x268 != 0) {
                *(void**)(p + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}


#include "JSystem/JGeometry/Vec.h"
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern "C" void fn_801D2608(void* obj, void* tbl, s32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* obj, f32 f);
extern "C" void fn_8010B40C(void* this_, s32 state);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" void fn_801CD150(JGeometry::TVec3<f32>* in, JGeometry::TVec3<f32>* out);
extern "C" u16 fn_80226850(JGeometry::TVec3<f32>* pos, s32 room);
extern const f32 lbl_8053C45C;
extern const f32 lbl_8053C460;
extern const f32 lbl_8053C470;
extern const f32 lbl_8053C478;
extern const f32 lbl_8053C47C;
extern const f32 lbl_8053C488;
extern u8 lbl_80539EE0[8];

struct IcclVT {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual s32 v13();
};

extern "C" void* fn_8010C00C(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049CFC8;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(f32*)(p + 0x240) = lbl_8053C478;
    fn_801D267C(p + 0x244);
    *(s32*)(p + 0x27c) = 0;
    return p;
}

extern "C" void fn_8010BEB8(char* p) {
    v01__5ActorFv(p);
    *(f32*)(p + 0x60) = lbl_8053C488;
    *(f32*)(p + 0x64) = lbl_8053C488;
    *(f32*)(p + 0x68) = lbl_8053C47C;
    *(f32*)(p + 0x6c) = lbl_8053C47C;
    *(f32*)(p + 0x70) = lbl_8053C488;
    *(f32*)(p + 0x74) = lbl_8053C488;
    *(f32*)(p + 0x78) = lbl_8053C47C;
    *(f32*)(p + 0x7c) = lbl_8053C47C;
    *(f32*)(p + 0x80) = lbl_8053C488;
    *(f32*)(p + 0x84) = lbl_8053C488;
    *(f32*)(p + 0x88) = lbl_8053C47C;
    *(f32*)(p + 0x8c) = lbl_8053C47C;
    fn_801D2608(p + 0x244, lbl_80539EE0, 2);
    fn_801D22DC(p + 0x244, 0, 2, 0);
    fn_801D1F14(p + 0x244, lbl_8053C470);
    if (((IcclVT*)p)->v13() > 0) {
        *(u8*)(p + 0x11d) = 0;
        fn_8010B40C(p, 5);
    }
}

extern "C" bool fn_8010B284(char* p) {
    JGeometry::TVec3<f32> pl;
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
    for (s32 i = 0; i < 4; i++) {
        pl = *fn_8023E724(i);
        if (*(s32*)(p + 4) == 8 && fn_8023DE58(i) == 0) {
            fn_801CD150(&pl, &pl);
        }
        if (!(*(f32*)(p + 0x10) > pl.y) && !(*(f32*)(p + 0xc) - lbl_8053C45C > pl.x) &&
            !(pl.x > *(f32*)(p + 0xc) + lbl_8053C45C)) {
            s32 j;
            bool hit = false;
            for (j = 1; j <= 0x18; j++) {
                pos.y = lbl_8053C460 * j + *(f32*)(p + 0x10);
                if (pos.y >= pl.y) {
                    break;
                }
                u16 attr = fn_80226850(&pos, *(s32*)(p + 4));
                if (attr >= 999 || (attr >= 0x250 && attr <= 0x26f)) {
                    hit = true;
                    break;
                }
            }
            return !hit;
        }
    }
    return false;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
