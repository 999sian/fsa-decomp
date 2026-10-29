#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
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
extern "C" char* fn_802D6A9C(void* this_);

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
extern "C" void fn_802CC21C(void* this_) {
    char* p = (char*)this_;
    float pos2[2];
    float box[4];
    Vec3CC pos;
    unsigned long uVar2;
    int iVar1;
    int iVar3;
    unsigned char cVar4;

    pos2[0] = 8.0f + *(float*)(p + 0xc);
    pos2[1] = 8.0f + *(float*)(p + 0x10);
    box[0] = *(float*)(p + 0x60) + pos2[0];
    box[1] = *(float*)(p + 0x64) + pos2[1];
    box[2] = *(float*)(p + 0x68) + pos2[0];
    box[3] = *(float*)(p + 0x6c) + pos2[1];
    iVar1 = fn_8023BA68(box, *(unsigned long*)(p + 4), pos2, 1);
    *(unsigned long*)(p + 0xd8) = 0;
    iVar3 = *(int*)(p + 0x240);
    if (iVar3 == 2) {
        if (iVar1 < 0 && (cVar4 = fn_801F2DB4(p, 0x48424d42, 0x4e554c4c, 0)) == 0) {
            if (*(unsigned char*)(fn_802D6A9C(p) + 0x171) != 1) {
                return;
            }
            fn_802A3884(lbl_8053AC98, p + 0xc, iVar1, *(unsigned long*)(p + 4), 0xae);
            pos.x = *(float*)(p + 0x14);
            pos.y = 8.0f + *(float*)(p + 0x10);
            pos.z = 8.0f + *(float*)(p + 0xc);
            *(unsigned long*)(p + 0x238) = fn_8013CC50(*(unsigned long*)(p + 4), &pos, 0x42d, 1, 0, 0, 0, 1, 1.0f);
            pos.y = 8.0f + *(float*)(p + 0x10);
            pos.z = *(float*)(p + 0x14);
            pos.x = 8.0f + *(float*)(p + 0xc);
            *(unsigned long*)(p + 0x23c) = fn_8013CC50(*(unsigned long*)(p + 4), &pos, 0x42e, 1, 0, 0, 0, 1, 1.0f);
            *(unsigned long*)(p + 0x240) = 0;
            return;
        }
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
    char* iVar2 = fn_802D6A9C(this_);
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

