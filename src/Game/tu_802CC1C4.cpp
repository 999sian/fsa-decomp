#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JKernel/JKRFileLoader.h"
#include "JSystem/JParticle/JPAEmitter.h"


struct GXColor_CC {
    unsigned char r, g, b, a;
    GXColor_CC(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) : r(r_), g(g_), b(b_), a(a_) {}
};

extern "C" char lbl_804A9020[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, int);
extern "C" char* lbl_8053AB10;
extern "C" void* lbl_8053AC98;
extern "C" void fn_802A3948(void* mgr, void* pos, int player, unsigned long room, int id);
extern "C" unsigned long fn_8013CC50(unsigned long id, void* pos, unsigned long seId, int a, int b, int c, int d, int e, float f);
extern "C" char* fn_802D6A9C(void);

struct Vec3CC {
    float x;
    float y;
    float z;
};
extern "C" void fn_80158B5C(void*, unsigned long, void*, GXColor_CC, float);
extern "C" void fn_802CC1C4(void* this_) {
    unsigned long id = *(unsigned long*)((char*)this_ + 0x4);
    GXColor_CC c(0, 0, 0, 0x80);
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, (char*)this_ + 0xc, c, 70.0f);
}

extern "C" unsigned long fn_8023BA68(float* box, unsigned long room, float* pos, int a);
extern "C" void fn_802A3884(void* mgr, void* pos, int player, unsigned long room, int id);
extern "C" unsigned char fn_801F2DB4(void* this_, unsigned long a, unsigned long b, int c);
extern "C" void fn_801F0E34(void* this_, unsigned long a, int b);
extern "C" void fn_802D790C(unsigned long a, int b);
extern "C" void fn_802FA160(void* a, unsigned long b, unsigned long c, int d, unsigned long e, int f);
extern "C" char* lbl_8053AAF8;
extern "C" char lbl_8046D908[];
extern "C" const f32 lbl_80540DD4;
static inline JGeometry::TVec2<f32> ccPosition(const Actor* actor) {
    return JGeometry::TVec2<f32>(8.0f + actor->field_0C.x, 8.0f + actor->field_0C.y);
}

static inline unsigned long ccEffect(char* p, unsigned long id) {
    JGeometry::TVec3<f32> pos(8.0f + *(f32*)(p + 0xc), 8.0f + *(f32*)(p + 0x10), *(f32*)(p + 0x14));
    return fn_8013CC50(*(unsigned long*)(p + 4), &pos, id, 1, 0, 0, 0, 1, 1.0f);
}
static inline void ccStop(JPABaseEmitter*& emitter) {
    if (emitter) {
        emitter->becomeInvalidEmitter();
        emitter = 0;
    }
}
extern "C" void fn_802CC21C(Actor* this_) {
    char* p = (char*)this_;
    const Actor* actor = (const Actor*)this_;
    JGeometry::TBox2<f32> box;
    const f32 y = 8.0f + actor->field_0C.y;
    const f32 x = 8.0f + actor->field_0C.x;
    JGeometry::TVec2<f32> pos(x, y);
    box.set(*(JGeometry::TBox2<f32>*)(p + 0x60));
    box.addPos(pos);
    int player = fn_8023BA68((f32*)&box, *(unsigned long*)(p + 4), (f32*)&pos, 1);
    *(unsigned long*)(p + 0xd8) = 0;
    switch (*(int*)(p + 0x240)) {
    case 0:
        if (player >= 0 || fn_801F2DB4(p, 0x48424d42, 0x4e554c4c, 0)) {
            fn_802A3948(lbl_8053AC98, p + 0xc, player, *(unsigned long*)(p + 4), 0xaf);
            {
    void* resource = (*(JKRFileLoader**)(lbl_8053AAF8 + 0xa4))->getResource(0x53434820, lbl_8046D908);
    fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), (unsigned long)resource, 704, 0, 0x5c0, 0x40);
}
            {
    void* resource = (*(JKRFileLoader**)(lbl_8053AAF8 + 0xa4))->getResource(0x53434820, lbl_8046D908);
    fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), (unsigned long)resource, 768, 0, 0x7c0, 0x40);
}
            *(int*)(p + 0x240) = 1;
            fn_801F0E34(p, 0x30051, 0);
            *(int*)(p + 0x244) = 60;
            fn_802D790C((unsigned long)fn_802D6A9C(), 0);
            ccEffect(p, 0x42a);
            *(unsigned long*)(p + 0x230) = ccEffect(p, 0x426);
            *(unsigned long*)(p + 0x234) = ccEffect(p, 0x427);
            ccStop(*(JPABaseEmitter**)(p + 0x238));
            ccStop(*(JPABaseEmitter**)(p + 0x23c));
        } else {
            if ((u8)fn_802D6A9C()[0x171] != 0) break;
            fn_802A3948(lbl_8053AC98, p + 0xc, player, *(unsigned long*)(p + 4), 0xaf);
            *(unsigned long*)(p + 0x230) = ccEffect(p, 0x426);
            *(unsigned long*)(p + 0x234) = ccEffect(p, 0x427);
            ccStop(*(JPABaseEmitter**)(p + 0x238));
            ccStop(*(JPABaseEmitter**)(p + 0x23c));
            *(int*)(p + 0x240) = 2;
        }
        break;
    case 1:
        if (*(int*)(p + 0x244) == 0) *(int*)(p + 0x240) = 2;
        else *(int*)(p + 0x244) -= 1;
        break;
    case 2:
        if (player >= 0 || fn_801F2DB4(p, 0x48424d42, 0x4e554c4c, 0)) {
            fn_802A3884(lbl_8053AC98, p + 0xc, player, *(unsigned long*)(p + 4), 0xae);
            {
    void* resource = (*(JKRFileLoader**)(lbl_8053AAF8 + 0xa4))->getResource(0x53434820, lbl_8046D908);
    fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), (unsigned long)resource, 576, 0, 0x5c0, 0x40);
}
            {
    void* resource = (*(JKRFileLoader**)(lbl_8053AAF8 + 0xa4))->getResource(0x53434820, lbl_8046D908);
    fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), (unsigned long)resource, 640, 0, 0x7c0, 0x40);
}
            *(int*)(p + 0x240) = 3;
            fn_801F0E34(p, 0x30051, 0);
            fn_802D790C((unsigned long)fn_802D6A9C(), 1);
            ccEffect(p, 0x42c);
            *(unsigned long*)(p + 0x238) = ccEffect(p, 0x42d);
            *(unsigned long*)(p + 0x23c) = ccEffect(p, 0x42e);
            ccStop(*(JPABaseEmitter**)(p + 0x230));
            ccStop(*(JPABaseEmitter**)(p + 0x234));
            *(int*)(p + 0x244) = 60;
        } else {
            if ((u8)fn_802D6A9C()[0x171] != 1) break;
            fn_802A3884(lbl_8053AC98, p + 0xc, player, *(unsigned long*)(p + 4), 0xae);
            *(unsigned long*)(p + 0x238) = ccEffect(p, 0x42d);
            *(unsigned long*)(p + 0x23c) = ccEffect(p, 0x42e);
            ccStop(*(JPABaseEmitter**)(p + 0x230));
            ccStop(*(JPABaseEmitter**)(p + 0x234));
            *(int*)(p + 0x240) = 0;
        }
        break;
    case 3:
        if (*(int*)(p + 0x244) == 0) *(int*)(p + 0x240) = 0;
        else *(int*)(p + 0x244) -= 1;
        break;
    default:
        *(u8*)(p + 0x11c) = 0;
        break;
    }
}

extern "C" void* fn_802CCA10(void* this_, short freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A9020;
        if (*(void**)(p + 0x230) != 0) {
            fn_801EE434(*(void**)(p + 0x230));
        }
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        if (*(void**)(p + 0x238) != 0) {
            fn_801EE434(*(void**)(p + 0x238));
        }
        if (*(void**)(p + 0x23c) != 0) {
            fn_801EE434(*(void**)(p + 0x23c));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" const f32 lbl_80540DDC;
extern "C" const f32 lbl_80540DD4;
extern "C" const f32 lbl_80540DD8;
extern "C" void fn_802CCAB4(void* this_) {
    char* p = (char*)this_;
    *(unsigned long*)(p + 0x230) = 0;
    *(unsigned long*)(p + 0x234) = 0;
    *(unsigned long*)(p + 0x238) = 0;
    *(unsigned long*)(p + 0x23c) = 0;
    *(float*)(p + 0x60) = lbl_80540DDC;
    *(float*)(p + 0x64) = lbl_80540DDC;
    *(float*)(p + 0x68) = lbl_80540DD4;
    *(float*)(p + 0x6c) = lbl_80540DD4;
    char* iVar2 = fn_802D6A9C();
    if (*(unsigned char*)(iVar2 + 0x171) == 0) {
        Vec3CC a;
        Vec3CC b;
        fn_802A3948(lbl_8053AC98, p + 0xc, 0, *(unsigned long*)(p + 4), 0xaf);
        *(unsigned long*)(p + 0x240) = 2;
        float ax = *(float*)(p + 0xc);
        float ay = *(float*)(p + 0x10);
        float az = *(float*)(p + 0x14);
        a.x = lbl_80540DD4 + ax;
        a.y = lbl_80540DD4 + ay;
        a.z = az;
        *(unsigned long*)(p + 0x230) = fn_8013CC50(*(unsigned long*)(p + 4), &a, 0x426, 1, 0, 0, 0, 1, lbl_80540DD8);
        float bx = *(float*)(p + 0xc);
        float by = *(float*)(p + 0x10);
        float bz = *(float*)(p + 0x14);
        b.x = lbl_80540DD4 + bx;
        b.y = lbl_80540DD4 + by;
        b.z = bz;
        *(unsigned long*)(p + 0x234) = fn_8013CC50(*(unsigned long*)(p + 4), &b, 0x427, 1, 0, 0, 0, 1, lbl_80540DD8);
    } else {
        Vec3CC c;
        Vec3CC d;
        *(unsigned long*)(p + 0x240) = 0;
        float cx = *(float*)(p + 0xc);
        float cy = *(float*)(p + 0x10);
        float cz = *(float*)(p + 0x14);
        c.x = lbl_80540DD4 + cx;
        c.y = lbl_80540DD4 + cy;
        c.z = cz;
        *(unsigned long*)(p + 0x238) = fn_8013CC50(*(unsigned long*)(p + 4), &c, 0x42d, 1, 0, 0, 0, 1, lbl_80540DD8);
        float dx = *(float*)(p + 0xc);
        float dy = *(float*)(p + 0x10);
        float dz = *(float*)(p + 0x14);
        d.x = lbl_80540DD4 + dx;
        d.y = lbl_80540DD4 + dy;
        d.z = dz;
        *(unsigned long*)(p + 0x23c) = fn_8013CC50(*(unsigned long*)(p + 4), &d, 0x42e, 1, 0, 0, 0, 1, lbl_80540DD8);
    }
    *(unsigned long*)(p + 0x244) = 0xf;
}

void __sinit_tu_802CC1C4_cpp(void) {}

