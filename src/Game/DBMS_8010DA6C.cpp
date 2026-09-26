// DBMS_8010DA6C: .text 0x8010DA6C-0x8010DF44 (actor DBMS)
// Function bodies partly adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern "C" void v06__5ActorFv(void* this_);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void*);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, s32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
void operator delete(void* p);

extern void* lbl_8049D0E8[];
extern void* lbl_8049CC34[];
extern const char lbl_80464348[];
extern u8 lbl_80539EF0[8];
extern const f32 lbl_8053C500;
extern const f32 lbl_8053C504;
extern const f32 lbl_8053C508;
extern const f32 lbl_8053C50C;

class DBMS_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;

struct DBMS_Box {
    f32 x0, y0, x1, y1;
};

extern "C" void* fn_8010DA6C(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049D0E8;
        if (this_ + 0x230 != 0) {
            if (this_ + 0x254 != 0) {
                *(void**)(this_ + 0x254) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8010DAEC(u8* this_) {
    v06__5ActorFv(this_);
    s32 id = *(s32*)(this_ + 0x240) + 0x386;
    void* pos = this_ + 0xC;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(DBMS_ResMgr**)(lbl_8053AAF8 + 0xA4))->vf18('SOB ', lbl_80464348);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053C500, lbl_8053C500, 0);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xC,
                *(s32*)(this_ + 0x240) + 0x386, 0, 1, -1, 0, 0, 0);
}

extern "C" void fn_8010DBC0(u8* this_) {
    v03__5ActorFv(this_);
    DBMS_Box b;
    b.x0 = *(f32*)(this_ + 0x60);
    b.y0 = *(f32*)(this_ + 0x64);
    b.x1 = *(f32*)(this_ + 0x68);
    b.y1 = *(f32*)(this_ + 0x6C);
    b.x0 += *(f32*)(this_ + 0xC);
    b.y0 += *(f32*)(this_ + 0x10);
    b.x1 += *(f32*)(this_ + 0xC);
    b.y1 += *(f32*)(this_ + 0x10);
    fn_80239914(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198));
    fn_801D1C18(this_ + 0x230);
}

extern "C" void fn_8010DC4C(u8* this_) {
    v01__5ActorFv(this_);
    *(f32*)(this_ + 0x60) = lbl_8053C504;
    *(f32*)(this_ + 0x64) = lbl_8053C504;
    *(f32*)(this_ + 0x68) = lbl_8053C508;
    *(f32*)(this_ + 0x6C) = lbl_8053C508;
    *(f32*)(this_ + 0x80) = lbl_8053C50C;
    *(f32*)(this_ + 0x84) = lbl_8053C50C;
    *(f32*)(this_ + 0x88) = lbl_8053C50C;
    *(f32*)(this_ + 0x8C) = lbl_8053C50C;
    *(s32*)(this_ + 0x108) = 0;
    fn_801D2608(this_ + 0x230, lbl_80539EF0, 1);
    fn_801D22DC(this_ + 0x230, 0, 2, 0);
    fn_801D1F14(this_ + 0x230, lbl_8053C50C);
}

struct Actor {
    Actor();
    ~Actor();
};

class Dbms : public Actor {
public:
    Dbms();
};

Dbms::Dbms() : Actor() {
    *(void**)this = lbl_8049D0E8;
    fn_801D267C((char*)this + 0x230);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
