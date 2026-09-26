// BARI_8011EEEC: .text 0x8011EEEC-0x8011FFB8 (actor BARI)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/Bari_ctor_8011FD28.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049DEE8[];

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_8011F5C0(void* this_, s32 state);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);

struct BariEmitter {
    u8 pad[0xa4];
    JGeometry::TVec3<f32> mGlobalTrs;
    void setGlobalTranslation(const JGeometry::TVec3<f32>& v) { mGlobalTrs.set(v); }
};

extern "C" BariEmitter* fn_8013CC50(u32 id, void* pos, s32 type, s32 p4, s32 p5, u32 p6, u32 p7, u32 p8, f32 f);
extern "C" void fn_8013CAA4(BariEmitter* e, f32 angle);

struct Bari {
    u8 pad0[0x4];
    u32 m4;
    u8 pad8[0x4];
    JGeometry::TVec3<f32> mPos; // 0xc
    u8 pad18[0x234 - 0x18];
    s32 m234;
    u8 pad238[0x244 - 0x238];
    BariEmitter* mEmitters[3]; // 0x244
    BariEmitter* m250;
    BariEmitter* m254;
};

extern "C" void fn_8011F314(Bari* p) {
    s32 i;
    for (i = 0; i < 3; i++) {
        p->mEmitters[i] = fn_8013CC50(p->m4, &p->mPos, 200, 0, 0, 0, 0, 1, 1.0f);
    }
    p->m250 = fn_8013CC50(p->m4, &p->mPos, 201, 0, 0, 0, 0, 1, 1.0f);
    p->m254 = fn_8013CC50(p->m4, &p->mPos, 201, 0, 0, 0, 0, 1, 1.0f);
    JGeometry::TVec3<f32> a(p->mPos);
    JGeometry::TVec3<f32> b(p->mPos);
    switch (p->m234) {
    case 1:
        for (i = 0; i < 3; i++) {
            a.x = p->mPos.x + 16.0f * (i - 1);
            p->mEmitters[i]->setGlobalTranslation(a);
            fn_8013CAA4(p->mEmitters[i], 1.5707964f);
        }
        b.y -= 32.0f;
        p->m250->setGlobalTranslation(b);
        fn_8013CAA4(p->m250, 1.5707964f);
        b.y += 64.0f;
        p->m254->setGlobalTranslation(b);
        fn_8013CAA4(p->m254, 1.5707964f);
        break;
    case 0:
    default:
        for (i = 0; i < 3; i++) {
            a.y = p->mPos.y + 16.0f * (i - 1);
            p->mEmitters[i]->setGlobalTranslation(a);
        }
        b.x -= 32.0f;
        p->m250->setGlobalTranslation(b);
        b.x += 64.0f;
        p->m254->setGlobalTranslation(b);
        break;
    }
}

struct BariVt {
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
    virtual u8 v11();
};

extern "C" void fn_8011FAF0(char* p) {
    v01__5ActorFv(p);
    if ((*(u32*)(p + 0x90) & 1) == 1) {
        *(u8*)(p + 0x240) = 1;
    }
    if (((*(u32*)(p + 0x90) >> 1) & 1) == 1) {
        *(u8*)(p + 0x241) = 1;
    }
    *(u32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    switch (*(s32*)(p + 0x234)) {
    case 1:
        *(f32*)(p + 0x60) = -16.0f;
        *(f32*)(p + 0x64) = -40.0f;
        *(f32*)(p + 0x68) = 16.0f;
        *(f32*)(p + 0x6c) = 40.0f;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x80) = -14.0f;
        *(f32*)(p + 0x84) = -40.0f;
        *(f32*)(p + 0x88) = 14.0f;
        *(f32*)(p + 0x8c) = 40.0f;
        break;
    case 0:
    default:
        *(f32*)(p + 0x60) = -40.0f;
        *(f32*)(p + 0x64) = -16.0f;
        *(f32*)(p + 0x68) = 40.0f;
        *(f32*)(p + 0x6c) = 16.0f;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x80) = -40.0f;
        *(f32*)(p + 0x84) = -14.0f;
        *(f32*)(p + 0x88) = 40.0f;
        *(f32*)(p + 0x8c) = 14.0f;
        break;
    }
    *(u32*)(p + 0x114) = 2;
    *(u32*)(p + 0x118) = 2;
    *(u32*)(p + 0xb8) = 1;
    *(u32*)(p + 0xbc) = 3;
    *(u32*)(p + 0xb0) = 0xa040304;
    fn_8011F314((Bari*)p);
    if (((BariVt*)p)->v11()) {
        fn_8011F5C0(p, 1);
    }
}

extern "C" void* fn_8011FC84(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_8049DEE8;
        for (s32 i = 0; i < 3; i++) {
            fn_801EE434(*(void**)(p + 0x244 + i * 4));
            *(void**)(p + 0x244 + i * 4) = 0;
        }
        fn_801EE434(*(void**)(p + 0x250));
        *(void**)(p + 0x250) = 0;
        fn_801EE434(*(void**)(p + 0x254));
        *(void**)(p + 0x254) = 0;
        __dt__5ActorFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_8011FD28(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049DEE8;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(u8*)((char*)this_ + 0x240) = 0;
    *(u8*)((char*)this_ + 0x241) = 0;
    *(s32*)((char*)this_ + 0x250) = 0;
    *(s32*)((char*)this_ + 0x254) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
