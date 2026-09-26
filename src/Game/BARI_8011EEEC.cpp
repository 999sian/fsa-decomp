// BARI_8011EEEC: .text 0x8011EEEC-0x8011FFB8 (actor BARI)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/Bari_ctor_8011FD28.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049DEE8[];

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);

struct BariEmitter {
    u8 pad[0xa4];
    JGeometry::TVec3<f32> mGlobalTrs;
    void setGlobalTranslation(const JGeometry::TVec3<f32>& v) { mGlobalTrs.set(v); }
    u8 padb0[0xf4 - 0xb0];
    u32 mFlags;
    void setStatus(u32 f) { mFlags |= f; }
    void clearStatus(u32 f) { mFlags &= ~f; }
};

static inline void stopEmitter(BariEmitter* e) {
    if (e != 0) {
        e->setStatus(1);
        *(s32*)((char*)e + 0x24) = 1;
    }
}

extern "C" BariEmitter* fn_8013CC50(u32 id, void* pos, s32 type, s32 p4, s32 p5, u32 p6, u32 p7, u32 p8, f32 f);
extern "C" void fn_8013CAA4(BariEmitter* e, f32 angle);

struct Bari {
    void* vtbl;
    u32 m4;
    u8 pad8[0x4];
    JGeometry::TVec3<f32> mPos; // 0xc
    u8 pad18[0x234 - 0x18];
    s32 m234;
    s32 m238;
    s32 m23c;
    u8 m240;
    u8 m241;
    u8 pad242[2];
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

extern "C" void fn_8011EEEC(Bari* p);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void* cfg, s32 id, s32 a, s32 b);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 a);
extern "C" void fn_801F0D20(void* this_, s32 a);
extern "C" void detach__5ActorFv(void* this_);

extern "C" void fn_8011F5C0(Bari* p, s32 state) {
    *(s32*)((char*)p + 0x230) = state;
    switch (state) {
    case 0:
        *(u32*)((char*)p + 0xb0) = 0xa040304;
        if (p->m240) {
            p->mEmitters[0]->clearStatus(4);
            p->mEmitters[1]->clearStatus(4);
            p->mEmitters[2]->clearStatus(4);
            p->m250->clearStatus(4);
            p->m254->clearStatus(4);
            s32 id = p->m238;
            if (id > 0) {
                fn_802D8050(fn_802D6A9C(), id, 0, 0xff);
            }
        }
        break;
    case 1:
        fn_8011EEEC(p);
        p->mEmitters[0]->setStatus(4);
        p->mEmitters[1]->setStatus(4);
        p->mEmitters[2]->setStatus(4);
        p->m250->setStatus(4);
        p->m254->setStatus(4);
        p->m23c = 0;
        break;
    case 2: {
        fn_801F0E34(p, 0x50011, 0);
        *(u32*)((char*)p + 0xb0) = 0;
        s32 id = p->m238;
        if (id > 0) {
            fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
        }
        break;
    }
    case 3:
        if (!p->m241) {
            fn_801F0E34(p, 0x50011, 0);
        }
        p->m23c = 0;
        fn_8011EEEC(p);
        for (s32 i = 0; i < 3; i++) {
            stopEmitter(p->mEmitters[i]);
        }
        stopEmitter(p->m250);
        stopEmitter(p->m254);
        break;
    case 4: {
        s32 id = p->m238;
        if (id > 0) {
            fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
        }
        if (!p->m241) {
            fn_801F0D20(p, 3);
        }
        detach__5ActorFv(p);
        break;
    }
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

extern "C" void v03__5ActorFv(void* this_);
extern "C" u8 fn_801F2DB4(void* this_, u32 a, u32 b, s32 c);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_80239914(void* box, u32 a, u32 b);
extern "C" void fn_80230FD0(s32 player, s32 id);

static inline bool isEnded(BariEmitter* e) {
    bool ret = false;
    if ((e->mFlags & 8) && *(s32*)((char*)e + 0xd0) + *(s32*)((char*)e + 0xdc) == 0) {
        ret = true;
    }
    return ret;
}

extern "C" void fn_8011F850(Bari* p) {
    v03__5ActorFv(p);
    f32 box[4];
    box[0] = *(f32*)((char*)p + 0x80);
    box[1] = *(f32*)((char*)p + 0x84);
    box[2] = *(f32*)((char*)p + 0x88);
    box[3] = *(f32*)((char*)p + 0x8c);
    box[0] += p->mPos.x;
    box[1] += p->mPos.y;
    box[2] += p->mPos.x;
    box[3] += p->mPos.y;
    switch (*(s32*)((char*)p + 0x230)) {
    case 0: {
        fn_801F0E34(p, 0x50010, 0);
        if (((BariVt*)p)->v11()) {
            if (p->m240) {
                fn_8011F5C0(p, 1);
            } else {
                fn_8011F5C0(p, 3);
            }
            break;
        }
        if (fn_801F2DB4(p, 'NULL', 'NULL', 0)) {
            *(u32*)((char*)p + 0xd8) = 0;
        }
        u8 hit = fn_801F2B7C(p, *(s32*)((char*)p + 0x114), -1, 10);
        if (!hit) {
            fn_80239914(box, p->m4, *(u32*)((char*)p + 0x198));
        } else {
            for (s32 i = 0; i < 4; i++) {
                if (hit & (1 << i)) {
                    fn_80230FD0(i, 0x20042);
                }
            }
        }
        break;
    }
    case 1:
        if (!p->m241) {
            fn_8011F5C0(p, 2);
        } else {
            p->m23c++;
            if (p->m23c >= 55) {
            p->m23c = 0;
            fn_8011F5C0(p, 2);
            }
        }
        break;
    case 2:
        if (!((BariVt*)p)->v11()) {
            fn_8011F5C0(p, 0);
        }
        break;
    case 3:
        if (p->m241) {
            p->m23c++;
            if (p->m23c == 55) {
                fn_801F0E34(p, 0x50011, 0);
                fn_8011F5C0(p, 4);
            }
        } else if (isEnded(p->mEmitters[0])) {
            fn_8011F5C0(p, 4);
        }
        break;
    case 4:
        break;
    }
}

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
        fn_8011F5C0((Bari*)p, 1);
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
