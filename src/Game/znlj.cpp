// TU 0x802205e0-0x80220f54 (actor ZNLJ).
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
void fn_80221210();
void v02__5ActorFv();
void v04__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFUlUl();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v15__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFiPf();
void v18__5ActorFiPf();
void* fn_802205E0(void* this_, s16 freeFlag);
void fn_80220BD0(void* this_);
void fn_80220680(void* this_);
void fn_802206FC(void* this_);
}
void* lbl_804A68D0[] = {
    0,
    0,
    (void*)fn_802205E0,
    (void*)fn_80220BD0,
    (void*)v02__5ActorFv,
    (void*)fn_801CDD58,
    (void*)v04__5ActorFv,
    (void*)v05__5ActorFv,
    (void*)fn_80220F54,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFUlUl,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)v15__5ActorFv,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFiPf,
    (void*)v18__5ActorFiPf,
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
    (void*)fn_80220680,
    (void*)fn_801CE4E4,
    (void*)fn_802206FC,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_80221210,
    (void*)fn_80221114,
};

// ---- fn_802205E0_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A68D0[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_802205E0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A68D0;
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


// ---- ZNLJ update / state change / init / ctor ----
#include "JSystem/JMath/JMath.h"

struct ZnljVt {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
};

struct ZnljRect { f32 x0, y0, x1, y1; };
struct ZnljGame { u8 pad[0x7e]; u8 mFlag7E; };

extern "C" {
extern f32 lbl_8053EFB8;
extern const f32 lbl_8053FE70;
extern ZnljGame* lbl_8053AAF8;
void fn_80221250(void* this_);
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_8022149C(void* this_, s32 a);
void fn_802217C8(void* this_);
void* fn_802218C8(void* this_);
void fn_80221670(void* this_);
s32 fn_801D05F8(void* this_, void* pos, f32 r);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
void fn_801F3604(void* this_);
void detach__5ActorFv(void* this_);
s32 fn_801CD664(s32 range);
s32 ClassifyBamAngleToQuadrant(u16 angle);
void fn_8022089C(void* this_, s32 state);

void fn_80220680(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x248)) {
    case 2:
        fn_80221250(this_);
        break;
    case 4:
    case 6:
        *(f32*)(p + 0x44) += lbl_8053EFB8;
        break;
    default:
        *(f32*)(p + 0x3c) = 0.0f;
        *(f32*)(p + 0x40) = 0.0f;
        ((ZnljVt*)this_)->s31();
        break;
    }
}

void fn_802206FC(void* this_) {
    char* p = (char*)this_;
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
        if (*(u32*)(p + 0x230) & 0x4000) {
            if (*(f32*)(p + 0x14) <= 0.0f) {
                fn_8022089C(this_, 4);
            }
        } else if (fn_801D05F8(this_, p + 0xc, 48.0f) >= 0) {
            *(u32*)(p + 0x230) |= 0x4000;
            ZnljRect* r = (ZnljRect*)(p + 0x60);
            r->x0 = 1.0f;
            r->y0 = 1.0f;
            r->x1 = -1.0f;
            r->y1 = -1.0f;
            *(ZnljRect*)(p + 0x70) = *r;
            if (*(f32*)(p + 0x14) <= 0.0f) {
                fn_8022089C(this_, 4);
            }
        } else if (*(f32*)(p + 0x14) <= 0.0f) {
            *(f32*)(p + 0x44) = lbl_8053FE70;
        }
        break;
    case 4:
        if (*(f32*)(p + 0x14) <= 0.0f) {
            (*(s32*)(p + 0x2bc))++;
            fn_8022089C(this_, 5);
        }
        break;
    case 5:
        if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250)) {
            if (*(s32*)(p + 0x2bc) >= *(s32*)(p + 0x2c0)) {
                fn_8022149C(this_, 1);
            } else {
                fn_8022089C(this_, 3);
            }
        }
        break;
    case 6:
        if (*(s32*)(p + 0x24c) >= 0x78) {
            detach__5ActorFv(this_);
        }
        break;
    }
}

void fn_8022089C(void* this_, s32 state) {
    char* p = (char*)this_;
    switch (state) {
    case 3: {
        ZnljRect* r = (ZnljRect*)(p + 0x60);
        r->x0 = -8.0f;
        r->y0 = -8.0f;
        r->x1 = 8.0f;
        r->y1 = 8.0f;
        ZnljRect* r2 = (ZnljRect*)(p + 0x80);
        r2->x0 = -8.0f;
        r2->y0 = -8.0f;
        r2->x1 = 8.0f;
        r2->y1 = 8.0f;
        break;
    }
    case 4: {
        *(u32*)(p + 0x230) &= ~0x4000;
        ZnljRect* r = (ZnljRect*)(p + 0x60);
        r->x0 = 1.0f;
        r->y0 = 1.0f;
        r->x1 = -1.0f;
        r->y1 = -1.0f;
        *(ZnljRect*)(p + 0x70) = *r;
        ZnljRect* r2 = (ZnljRect*)(p + 0x80);
        r2->x0 = 1.0f;
        r2->y0 = 1.0f;
        r2->x1 = -1.0f;
        r2->y1 = -1.0f;
        static f32 sJumpVel = 0.5f * (45.0f * -lbl_8053EFB8);
        *(f32*)(p + 0x44) = sJumpVel;
        switch (*(s32*)(p + 0x2b8)) {
        case 0:
        case 1:
            *(f32*)(p + 0x3c) = 2.8444445f;
            if (*(s32*)(p + 0x2b8) == 1) {
                *(f32*)(p + 0x3c) = -*(f32*)(p + 0x3c);
            }
            if (*(s32*)(p + 0x2bc) & 1) {
                *(f32*)(p + 0x3c) = -*(f32*)(p + 0x3c);
            }
            *(f32*)(p + 0x40) = 0.0f;
            break;
        case 2:
        case 3:
            *(f32*)(p + 0x40) = 2.8444445f;
            if (*(s32*)(p + 0x2b8) == 3) {
                *(f32*)(p + 0x40) = -*(f32*)(p + 0x40);
            }
            if (*(s32*)(p + 0x2bc) & 1) {
                *(f32*)(p + 0x40) = -*(f32*)(p + 0x40);
            }
            *(f32*)(p + 0x3c) = 0.0f;
            break;
        }
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    }
    case 5: {
        ZnljRect* r = (ZnljRect*)(p + 0x60);
        r->x0 = -8.0f;
        r->y0 = -8.0f;
        r->x1 = 8.0f;
        r->y1 = 8.0f;
        ZnljRect* r2 = (ZnljRect*)(p + 0x80);
        r2->x0 = -8.0f;
        r2->y0 = -8.0f;
        r2->x1 = 8.0f;
        r2->y1 = 8.0f;
        if (lbl_8053AAF8->mFlag7E) {
            *(s32*)(p + 0x250) = 6;
        } else {
            *(s32*)(p + 0x250) = 0xc;
        }
        break;
    }
    case 6: {
        fn_801F3604(this_);
        ZnljRect* r = (ZnljRect*)(p + 0x60);
        r->x0 = 1.0f;
        r->y0 = 1.0f;
        r->x1 = -1.0f;
        r->y1 = -1.0f;
        *(ZnljRect*)(p + 0x70) = *r;
        ZnljRect* r2 = (ZnljRect*)(p + 0x80);
        r2->x0 = 1.0f;
        r2->y0 = 1.0f;
        r2->x1 = -1.0f;
        r2->y1 = -1.0f;
        static f32 sLandVel = 0.5f * (120.0f * -lbl_8053EFB8);
        *(f32*)(p + 0x44) = sLandVel;
        fn_80221670(this_);
        *(f32*)(p + 0x3c) = (1.0f / 120.0f) * (*(f32*)(p + 0x2b0) - *(f32*)(p + 0xc));
        *(f32*)(p + 0x40) = (1.0f / 120.0f) * (*(f32*)(p + 0x2b4) - *(f32*)(p + 0x10));
        f32 ang = JMAAtan2Radian(*(f32*)(p + 0x3c), *(f32*)(p + 0x40));
        ang *= 10430.378f;
        *(s32*)(p + 0x98) = ClassifyBamAngleToQuadrant((u16)(s32)ang);
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 8, 0, 0);
        break;
    }
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}

void fn_80220BD0(void* this_) {
    char* p = (char*)this_;
    fn_802217C8(this_);
    *(u32*)(p + 0x2b8) = *(u32*)(p + 0x90) & 3;
    *(s32*)(p + 0x98) = 2;
    *(s32*)(p + 0x248) = 3;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_801D22DC(p + 0x270, 2, 0, 0);
}

}


// Intermediate actor base shared by ZNLJ/ZSLA/tu_80221B44/tu_80222CC4/tu_802233A4
// (vtable lbl_804A6A00, ctor fn_802218C8). Its destructor is emitted weak here.
extern "C" void* fn_802218C8(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

class Base_802218C8 {
public:
    Base_802218C8() { fn_802218C8(this); }
    ~Base_802218C8() {
        char* p = (char*)this;
        *(void**)p = lbl_804A6A00;
        if (this != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this, 0);
        }
    }
    u8 mBase[0x2b8];
};

class Znlj : public Base_802218C8 {
public:
    Znlj();
    s32 m2B8;
    s32 m2BC;
    s32 m2C0;
};

Znlj::Znlj() {
    *(void**)this = lbl_804A68D0;
    m2B8 = 0;
    m2BC = 0;
    m2C0 = fn_801CD664(1) + 3;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
