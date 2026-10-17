// MOZO actor. TU 80166BD0-80167938.
// Functions: draw (slot 6, TODO), update (slot 3, TODO), init (slot 1),
// child release, dtor.
#include "types.h"
#include "Game/ItemBase.h"

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, void* rec, f32 sx, f32 sy, s32 mode);
extern "C" void fn_802F86CC(void* map, void* pos, void* res, s32 idx, void* rec, f32 sx, f32 sy);
extern u8* lbl_8053AAF8;
extern const f32 lbl_8053D7F8;
extern char* lbl_8053AB10;

struct MozoResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};

static inline void mozoRotScale(f32 m[3][4], f32 rx, const f32* pry, f32 rz, const f32* ps) {
    m[0][3] = lbl_8053D7F8;
    m[1][3] = lbl_8053D7F8;
    m[2][3] = lbl_8053D7F8;
              f32 s = *ps;
    f32 ry = *pry;
    f32 sz, sy, sx;
    f32 cz, cy, cx;
    sx = sin(rx);
    sy = sin(ry);
    sz = sin(rz);
    cx = cos(rx);
    cy = cos(ry);
    cz = cos(rz);
    f32 cxcz = cx * cz;
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * cy);
}

// MOZO draw (vtable slot 6)
extern "C" void fn_80166BD0(u8* this_) {
    if (*(s32*)(this_ + 0x230) == 3) {
        DrawRec r;
        f32 m[3][4];
        mozoRotScale(m, lbl_8053D7F8, (f32*)(this_ + 0x25c), lbl_8053D7F8, (f32*)(this_ + 0x258));
        r.w18 = m;
        s32 idx = *(s32*)(this_ + 0x250) + 0x9d;
        if (*(s32*)(this_ + 4) < 8) {
            void* res = (*(MozoResMgr**)(lbl_8053AAF8 + 0xa4))->get('SOB ', "enemy_gc_sob.bin");
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, idx, &r, 1.0f, 1.0f);
        }
    } else {
        fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x250) + 0x9d, 0, 1.0f, 1.0f, 0);
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A0668[];

// MOZO init (vtable slot 1)
extern "C" void fn_801675E0(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
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
    *(s32*)(this_ + 0x108) = 4;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(f32*)(this_ + 0x258) = 1.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x254) = 255.0f;
    *(void**)(this_ + 0x26c) = 0;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x230) = 0;
}

struct MozoChild { u8 pad[0x24]; s32 dead; u8 pad2[0xf4 - 0x28]; u32 flags; };

// MOZO: release linked child actor
extern "C" void fn_8016767C(char* this_) {
    MozoChild* c = *(MozoChild**)(this_ + 0x26c);
    if (c != 0) {
        c->flags |= 1;
        c->dead = 1;
        *(MozoChild**)(this_ + 0x26c) = 0;
    }
}

// MOZO destructor
extern "C" void* fn_801676A8(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0668;
        fn_801EE434(*(void**)(this_ + 0x26c));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
