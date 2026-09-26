// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A8194-801A908C (HBB2). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"

// from src/Game/fn_801A8194_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A2EC0[];

extern "C" void* fn_801A8194(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2EC0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct Hbb2Vec { f32 x, y, z; };
struct Hbb2 { u8 pad0[0xc]; Hbb2Vec pos; u8 pad18[0x27c - 0x18]; Hbb2Vec prev; Hbb2Vec prev2; Hbb2Vec trail[40]; };

// HBB2 init (vtable slot 1)
extern "C" void fn_801A8CB8(char* this_) {
    *(f32*)(this_ + 0x60) = -10.0f;
    *(f32*)(this_ + 0x64) = -10.0f;
    *(f32*)(this_ + 0x68) = 10.0f;
    *(f32*)(this_ + 0x6c) = 10.0f;
    *(f32*)(this_ + 0x80) = 0.0f;
    *(f32*)(this_ + 0x84) = 0.0f;
    *(f32*)(this_ + 0x88) = 0.0f;
    *(f32*)(this_ + 0x8c) = 0.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x270) = 72.0f;
    *(u8*)(this_ + 0x11e) = 1;
    *(f32*)(this_ + 0x26c) = 1.2f;
    *(f32*)(this_ + 0x274) = 255.0f;
    Hbb2* h = (Hbb2*)this_;
    h->prev.x = h->pos.x;
    h->prev.y = h->pos.y;
    h->prev.z = h->pos.z;
    h->prev2.x = h->pos.x;
    h->prev2.y = h->pos.y;
    h->prev2.z = h->pos.z;
    for (int i = 0; i < 40; i++) {
        h->trail[i].x = h->pos.x;
        h->trail[i].y = h->pos.y;
        h->trail[i].z = h->pos.z;
    }
    *(s16*)(this_ + 0x268) = 0;
    *(s32*)(this_ + 0x190) = 0;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(s32*)(this_ + 0x264) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x230) = 0;
}

extern "C" void fn_801F02BC(void* actor, const char* file, s32 idx, f32 sx, f32 sy, DrawRec* rec, s32 a, s32 b, s32 c);

struct Hbb2Mtx {
    Hbb2Mtx() {
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
    }
    void setScale(f32 s) {
        m[0][0] = s;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = s;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = s;
    }
    f32 m[3][4];
};

struct Hbb2VT {
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
    virtual u8 check();
};

// HBB2 draw: body plus a fading trail of 39 afterimages.
extern "C" void fn_801A81F4(char* this_) {
    DrawRec rec;
    Hbb2Mtx mtx;
    if (*(s32*)(this_ + 0x258) == 0 && (*(u32*)(this_ + 0x90) >> 27) != 0) {
        if (!((Hbb2VT*)this_)->check()) {
            return;
        }
    }
    rec.ids[4] = 3;
    rec.b1d = 2;
    mtx.setScale(*(f32*)(this_ + 0x26c));
    rec.w18 = &mtx;
    fn_801F02BC(this_, "enemy_both2_sob.bin", *(s32*)(this_ + 0x260) + 0x155, 1.0f, 1.0f, &rec, 7, 0, 0);
    f32 sx, sy, sz;
    f32 scale = *(f32*)(this_ + 0x26c);
    f32 alpha = *(f32*)(this_ + 0x274);
    s32 frame = *(s32*)(this_ + 0x260);
    Hbb2* h = (Hbb2*)this_;
    rec.ids[4] = 5;
    rec.b1d = 1;
    sx = h->pos.x;
    sy = h->pos.y;
    sz = h->pos.z;
    for (s32 i = 1; i < 40; i++) {
        if (h->trail[i].z) {
            scale *= 0.95f;
            if (scale < 0.5f) {
                scale = 0.5f;
            }
            alpha -= 2.0f;
            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
            ((u8*)&rec.w10)[3] = (s32)alpha;
            mtx.setScale(scale);
            rec.w18 = &mtx;
            if (--frame < 0) {
                frame = 2;
            }
            h->pos.x = h->trail[i].x;
            h->pos.y = h->trail[i].y;
            h->pos.z = h->trail[i].z;
            fn_801F02BC(this_, "enemy_both2_sob.bin", frame + 0x155, 1.0f, 1.0f, &rec, 7, 0, 0);
        }
    }
    h->pos.x = sx;
    h->pos.y = sy;
    h->pos.z = sz;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
