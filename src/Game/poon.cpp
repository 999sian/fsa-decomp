// Poon actor ("Poon" actor id, mixed case in the table). TU 80167938-801688AC.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), init (slot 1).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A06C0[];

// Poon destructor
extern "C" void* fn_80167938(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A06C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


struct PoonDrawParam {
    PoonDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};

struct PoonResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* get(u32 type, const char* name);
};

extern "C" double sin(double);
extern "C" double cos(double);
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern const char lbl_80466338[];
extern "C" void fn_802F86CC(void* map, void* pos, void* res, s32 id, PoonDrawParam* prm, f32 a, f32 b);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);

extern "C" void fn_80167998(char* this_) {
    if (*(s32*)(this_ + 0x230) == 2) {
        PoonDrawParam prm;
        f32 mtx[3][4];
        prm.reset();
        mtx[0][3] = 0.0f;
        mtx[1][3] = 0.0f;
        mtx[2][3] = 0.0f;
        prm.mMtx = mtx;
        f32 rx = 0.0f;
        f32 ry = *(f32*)(this_ + 0x258);
        f32 rz = 0.0f;
        f32 scale = *(f32*)(this_ + 0x254);
        f32 sx = sin(rx);
        f32 sy = sin(ry);
        f32 sz = sin(rz);
        f32 cx = cos(rx);
        f32 cy = cos(ry);
        f32 cz = cos(rz);
        mtx[0][0] = scale * (cy * cz);
        mtx[1][0] = scale * (cy * sz);
        mtx[2][0] = scale * -sy;
        mtx[0][1] = scale * (sx * sy * cz - cx * sz);
        mtx[1][1] = scale * (sx * sy * sz + cx * cz);
        mtx[2][1] = scale * (sx * cy);
        mtx[0][2] = scale * (cx * cz * sy + sx * sz);
        mtx[1][2] = scale * (cx * sz * sy - sx * cz);
        mtx[2][2] = scale * (cx * cy);
        prm.mMtx = mtx;
        s32 id = *(s32*)(this_ + 0x250) + 0x92;
        if (*(s32*)(this_ + 0x4) < 8) {
            void* res = (*(PoonResMgr**)(lbl_8053AAF8 + 0xa4))->get('SOB ', lbl_80466338);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, &prm, 1.0f, 1.0f);
        }
    } else {
        fn_801F06F0(this_, lbl_80466338, *(s32*)(this_ + 0x250) + 0x92, 0, 0, 1.0f, 1.0f);
    }
}

struct PoonVec { f32 x, y, z; };

// Poon init (vtable slot 1)
extern "C" void fn_801685C8(char* this_) {
    *(f32*)(this_ + 0x60) = -6.0f;
    *(f32*)(this_ + 0x64) = -6.0f;
    *(f32*)(this_ + 0x68) = 6.0f;
    *(f32*)(this_ + 0x6c) = 6.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x278) = 0.2f;
    *(f32*)(this_ + 0x27c) = 0.2f;
    *(f32*)(this_ + 0x280) = 0.2f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(u8*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x254) = 1.0f;
    ((PoonVec*)(this_ + 0x260))->x = ((PoonVec*)(this_ + 0xc))->x;
    ((PoonVec*)(this_ + 0x260))->y = ((PoonVec*)(this_ + 0xc))->y;
    ((PoonVec*)(this_ + 0x260))->z = ((PoonVec*)(this_ + 0xc))->z;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0xb8) = 1;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
