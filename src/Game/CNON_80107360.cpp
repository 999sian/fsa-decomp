// CNON_80107360: .text 0x80107360-0x80108414 (actor CNON)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CCF0[];
extern void* lbl_8049CC34[];


extern "C" void* __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void*);
extern "C" void fn_8013CC50(s32 id, JGeometry::TVec3f* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern "C" void fn_80230FD0(s32 h, s32 id);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern void* lbl_8053AAF8;
extern u8 lbl_80539ED0[8];
extern const f32 lbl_8053C2C0;
extern const f32 lbl_8053C2D4;
extern const f32 lbl_8053C2F8;
extern const f64 lbl_8053C300;
extern const f32 lbl_8053C308;
extern const f32 lbl_8053C30C;
extern const f32 lbl_8053C310;
extern const f32 lbl_8053C314;

class CNON {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual u8 v34();
    virtual void v38();
    virtual int v3C();
    s32 m04;
    u8 pad08[4];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x60 - 0x18];
    f32 m60[4];      // 0x60
    f32 m70[4];      // 0x70
    f32 m80[4];      // 0x80
    u32 m90;         // 0x90
    u8 pad94[0xb0 - 0x94];
    s32 mB0;         // 0xb0
    u8 padB4[0x108 - 0xb4];
    s32 m108;        // 0x108
    u8 pad10C[0x198 - 0x10c];
    void* m198;      // 0x198
    u8 pad19C[0x230 - 0x19c];
    u8 m230[0x38];
    u8 m268;
    u8 m269;
    u8 m26A;
    u8 pad26B;
    s32 m26C;
    s32 mState; // 0x270
    s32 m274;
    s32 m278;
    s32 m27C;
    f32 m280;
    f32 m284;
    f32 m288;
    f32 m28C;
    f32 m290;

    s32 m240() { return *(s32*)(m230 + 0x10); }

    void setState(s32 st) {
        m278 = m274;
        m274 = st;
        switch (m274) {
        case 1:
            break;
        case 2:
            fn_80230FD0(m26C, 0x20035);
            break;
        case 3:
            break;
        }
        m284 = lbl_8053C2C0;
    }
};

extern "C" int fn_80107360(CNON* this_) {
    if (this_->m274 != 2) {
        return 0;
    }
    this_->mPos.y = this_->m28C;
    JGeometry::TVec3f pos = this_->mPos;
    pos.y -= lbl_8053C308;
    if (this_->m04 == 0) {
        fn_8013CC50(this_->m04, &pos, 0x5a, 0, 1, 0, 0, 1, lbl_8053C2D4);
    }
    fn_80230FD0(this_->m26C, 0x20036);
    fn_80134DE4(lbl_8053AAF8, 1, 0);
    this_->setState(3);
    return 1;
}


class CNON_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, DrawRec*);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern const char lbl_80463FEC[];
extern u8* lbl_8053AB10;

extern "C" void fn_80107458(CNON* this_) {
    if (this_->v3C() != 0) {
        if (this_->m274 == 0 || this_->m274 == 1) {
            if (!this_->v34()) {
                return;
            }
        }
    }
    DrawRec rec;
    rec.b1d = 1;
    s32 id = this_->m240() + 0x14c;
    JGeometry::TVec3f* pos = &this_->mPos;
    if (this_->m04 < 8) {
        void* res = (*(CNON_ResMgr**)((u8*)lbl_8053AAF8 + 0xA4))->vf18('SOB ', lbl_80463FEC);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053C2D4, lbl_8053C2D4, &rec);
    }
    fn_803075AC(this_->m198, this_->m04, &this_->mPos, this_->m240() + 0x14c, 0, 1, -1, 0, 0, 0);
}

extern "C" void fn_80107F38(CNON* this_) {
    if ((this_->m90 & 0xf) == 1) {
        this_->m274 = 1;
    }
    this_->m27C = (this_->m90 >> 4) & 0xf;
    this_->m280 = (u32)((this_->m90 >> 8) & 0x1f);
    if (((this_->m90 >> 16) & 1) == 1) {
        this_->m26A = 1;
    } else {
        this_->m26A = 0;
    }
    this_->m60[0] = lbl_8053C30C;
    this_->m60[1] = lbl_8053C30C;
    this_->m60[2] = lbl_8053C2F8;
    this_->m60[3] = lbl_8053C310;
    this_->m70[0] = this_->m60[0];
    this_->m70[1] = this_->m60[1];
    this_->m70[2] = this_->m60[2];
    this_->m70[3] = this_->m60[3];
    this_->m80[0] = lbl_8053C2C0;
    this_->m80[1] = lbl_8053C2C0;
    this_->m80[2] = lbl_8053C2C0;
    this_->m80[3] = lbl_8053C2C0;
    this_->m108 = 0;
    this_->mB0 = 0x50303;
    fn_801D2608(this_->m230, lbl_80539ED0, 1);
    fn_801D22DC(this_->m230, 0, 2, 0);
    fn_801D1F14(this_->m230, lbl_8053C2C0);
    this_->m288 = this_->mPos.x;
    this_->m28C = this_->mPos.y;
    this_->m290 = this_->mPos.z;
    if (this_->v3C() != 0 && this_->v34()) {
        this_->m269 = 1;
    }
}

extern "C" f32 fn_801080B8(CNON* this_) {
    if (this_->m04 == 0) {
        return lbl_8053C2F8;
    }
    if (this_->m26A != 0) {
        return lbl_8053C2F8;
    }
    return lbl_8053C314;
}

extern "C" void* fn_801080E8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CCF0;
        if (p + 0x230 != 0) {
            if (p + 0x254 != 0) {
                *(void**)(p + 0x254) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80108168(CNON* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_8049CCF0;
    fn_801D267C(this_->m230);
    this_->m268 = 1;
    this_->m269 = 0;
    this_->m26A = 0;
    this_->m26C = -1;
    this_->mState = 0;
    this_->m274 = 0;
    this_->m278 = 0;
    this_->m27C = 0;
    this_->m280 = lbl_8053C2C0;
    this_->m284 = lbl_8053C2C0;
    this_->m288 = lbl_8053C2C0;
    this_->m28C = lbl_8053C2C0;
    this_->m290 = lbl_8053C2C0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
