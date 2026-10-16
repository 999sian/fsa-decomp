// CLOD_80105368: .text 0x80105368-0x80105DD4 (actor CLOD)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_802F745C(void* mgr, JGeometry::TVec3f* pos, s32 id, void* out);
extern char* lbl_8053AB10;
extern const f32 lbl_8053C23C;
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049CBE0[];
extern const f32 lbl_8053C228;
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void* anim, void* arg, s32 n);
extern "C" void fn_801D22DC(void* anim, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* anim, f32 scale);
extern u8 lbl_80539EC0[];
extern char* lbl_8053AAF8;
extern const char* lbl_8049CBB0[][4];
extern const f32 lbl_8053C250;
extern const f32 lbl_8053C254;
extern const f32 lbl_8053C258;
extern const f32 lbl_8053C25C;
extern const f32 lbl_8053C260;
extern const f32 lbl_8053C264;
extern const f32 lbl_8053C268;
extern const f32 lbl_8053C26C;
class CLOD_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern "C" void fn_80105654(char* p) {
    v06__5ActorFv(p);
    p[0x325] = -1;
    s32 idx = *(s32*)(p + 0x390);
    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
    if (*(s32*)(p + 0x36c) == 2) {
        pos.y -= lbl_8053C23C;
    }
    s32 id = ((s32*)(p + 0x2f8))[idx];
    if (*(s32*)(p + 0x4) < 8) {
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, id, p + 0x308);
    }
}

extern "C" void* fn_80105BEC(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049CBE0;
    *(s32*)(p + 0x318) = -1;
    *(s32*)(p + 0x31c) = -1;
    for (s32 i = 0; (u8)i < 0x10; i += 8) {
        p[(u8)(i + 0) + 0x308] = i + 0;
        p[(u8)(i + 1) + 0x308] = i + 1;
        p[(u8)(i + 2) + 0x308] = i + 2;
        p[(u8)(i + 3) + 0x308] = i + 3;
        p[(u8)(i + 4) + 0x308] = i + 4;
        p[(u8)(i + 5) + 0x308] = i + 5;
        p[(u8)(i + 6) + 0x308] = i + 6;
        p[(u8)(i + 7) + 0x308] = i + 7;
    }
    *(s32*)(p + 0x318) = -1;
    *(s32*)(p + 0x31c) = 0;
    *(s32*)(p + 0x320) = 0;
    p[0x324] = 0;
    p[0x325] = 0;
    p[0x326] = 0;
    p[0x327] = 1;
    p[0x328] = 1;
    p[0x329] = 0;
    p[0x32a] = 0;
    p[0x32b] = 0;
    p[0x32c] = 0;
    p[0x32d] = 0;
    p[0x32e] = 1;
    *(s32*)(p + 0x330) = 3;
    p[0x334] = 1;
    p[0x335] = 0;
    p[0x336] = 0;
    *(s32*)(p + 0x338) = -1;
    *(s32*)(p + 0x33c) = 0;
    *(s32*)(p + 0x340) = 2;
    *(f32*)(p + 0x344) = lbl_8053C228;
    *(f32*)(p + 0x348) = lbl_8053C228;
    *(f32*)(p + 0x34c) = lbl_8053C228;
    *(f32*)(p + 0x350) = lbl_8053C228;
    *(s32*)(p + 0x354) = 0;
    *(s32*)(p + 0x358) = 0;
    *(s32*)(p + 0x35c) = -1;
    *(s32*)(p + 0x360) = 0;
    *(s32*)(p + 0x364) = 0;
    *(s32*)(p + 0x368) = 0;
    *(s32*)(p + 0x36c) = 0;
    *(s32*)(p + 0x370) = 0;
    fn_801D267C(p + 0x374);
    *(s32*)(p + 0x2f8) = 0;
    *(s32*)(p + 0x2fc) = 0;
    *(s32*)(p + 0x300) = 0;
    *(s32*)(p + 0x304) = 0;
    return p;
}

// ---- from Game/fn_80105368_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CBE0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80105368(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CBE0;
        if (p + 0x374 != 0) {
            if (p + 0x398 != 0) {
                *(void**)(p + 0x398) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/dtor_80105D80.cpp

#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CC34[];

extern "C" void* __dt__7AnimSubFv(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        if (p + 0x24 != 0) {
            *(void**)(p + 0x24) = lbl_8049CC34;
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}
