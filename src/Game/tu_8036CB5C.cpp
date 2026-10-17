#include "Game/Actor.h"

extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);
extern "C" f64 __ps_add(f64 a, f64 b);

/* paired-single Vec add, same code as JMathInlineVEC::PSVECAdd */
static inline void PSVECAdd(const Vec* a, const Vec* b, Vec* d) {
    f64 axy = __psq_l((void*)a, 0, 0, 0);
    f64 bxy = __psq_l((void*)b, 0, 0, 0);
    f64 az = __psq_l((void*)a, 8, 1, 0);
    f64 bz = __psq_l((void*)b, 8, 1, 0);
    __psq_st(__ps_add(axy, bxy), (void*)d, 0, 0, 0);
    __psq_st(__ps_add(az, bz), (void*)d, 8, 1, 0);
}


extern "C" char lbl_804AE230[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_80542CE4;
extern "C" f32 lbl_80542CD8;
extern "C" f32 lbl_80542CDC;
extern "C" f32 lbl_80542CE0;
extern "C" f32 lbl_80542CE8;
extern "C" f32 lbl_80542CEC;
extern "C" f32 lbl_80542CF0;
extern "C" f32 lbl_80542CF4;
extern "C" f32 lbl_80542CF8;
extern "C" f32 lbl_80542CFC;
extern "C" f32 lbl_80542D00;
extern "C" void fn_8036CBBC(Actor*);
extern "C" s32 fn_80239470(void*, u32, void*);
extern "C" void fn_80239914(void*, u32, void*);
extern "C" void* fn_8023E724(s32);
extern "C" void fn_8023DFF4(s32, void*);
extern "C" u8 fn_8023077C(Actor*);
extern "C" void fn_801F0E34(Actor*, s32, s32);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" const char lbl_80474EAC[];
extern "C" void fn_802F86CC(void*, void*, void*, s32, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);

class SobResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern "C" Actor* fn_8036CB5C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AE230;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8036CE58(Actor* this_) {
    u8* p = (u8*)this_;
    s32 id = *(s32*)(p + 0x24c) + 0x147;
    if (*(s32*)(p + 4) < 8) {
        SobResMgr* mgr = *(SobResMgr**)(lbl_8053AAF8 + 0xa4);
        void* res = mgr->vf18('SOB ', lbl_80474EAC);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0x24, res, id, 0, lbl_80542CE4, lbl_80542CE4);
    }
    fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0x24, *(s32*)(p + 0x24c) + 0x147, 0, 1, -1, 0, 0, 0);
}

extern "C" void fn_8036CF1C(Actor* this_) {
    u8* p = (u8*)this_;
    f32 box[4];
    f32 dx;
    s32 hit;

    box[0] = *(f32*)(p + 0x60) + *(f32*)(p + 0xc);
    box[1] = *(f32*)(p + 0x64) + *(f32*)(p + 0x10);
    box[2] = *(f32*)(p + 0x68) + *(f32*)(p + 0xc);
    box[3] = *(f32*)(p + 0x6c) + *(f32*)(p + 0x10);
    *(f32*)(p + 0x3c) = lbl_80542CD8;
    *(f32*)(p + 0x40) = lbl_80542CD8;
    *(f32*)(p + 0x44) = lbl_80542CD8;

    if (*(s32*)(p + 0x258) > 0) {
        *(s32*)(p + 0x258) -= 1;
        fn_8036CBBC(this_);
        hit = fn_80239470(box, *(u32*)(p + 4), *(void**)(p + 0x198));
        if (hit >= 0) {
            fn_80239914(box, *(u32*)(p + 4), *(void**)(p + 0x198));
            dx = *(f32*)(p + 0xc) - *(f32*)fn_8023E724(hit);
        }
    }

    if (*(u8*)(p + 0x250) != 0) {
        *(f32*)(p + 0x254) = lbl_80542CE0;
        *(f32*)(p + 0x10) = *(f32*)(p + 0x28) + *(f32*)(p + 0x254);
    }
}

extern "C" f32 lbl_80542CD8;
extern "C" f32 lbl_80542CE0;
extern "C" f32 lbl_80542CF4;
extern "C" f32 lbl_80542D04;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 Actor_CreateByID(void* reg, s32 type, s32 parent, Vec* pos, u32 flags, s32 a, s32 b);
extern "C" void fn_8036D3D8(Actor* this_) {
    u8* p = (u8*)this_;
    s32 i;

    if (((*(u32*)(p + 0x90) >> 4) & 3) == 0) {
        for (i = 0; i < 3; i++) {
            Vec base = *(Vec*)(p + 0xC);
            Vec off = {lbl_80542CF4 * (f32)(i + 1), lbl_80542CD8, lbl_80542CD8};
            Vec pos = {base.x + off.x, base.y + off.y, base.z + off.z};
            u32 flags = (*(u32*)(p + 0x90) & 0xF800000F) | ((i + 1) << 4);

            *(s32*)(p + 0x234 + i * 4) = -1;
            *(s32*)(p + 0x234 + i * 4) = Actor_CreateByID(fn_801F856C(), 0x50535732, *(s32*)(p + 4), &pos, flags, -1, -1);
            if (*(s32*)(p + 0x234 + i * 4) >= 0) {
                *(s32*)((u8*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x234 + i * 4)) + 0x230) = *(s32*)(p + 0x198);
            } else {
                this_->detach();
            }
        }
    }

    *(f32*)(p + 0x60) = lbl_80542D04;
    *(f32*)(p + 0x64) = lbl_80542D04;
    *(f32*)(p + 0x68) = lbl_80542CE0;
    *(f32*)(p + 0x6c) = lbl_80542CE0;
    *(f32*)(p + 0x80) = lbl_80542CD8;
    *(f32*)(p + 0x84) = lbl_80542CD8;
    *(f32*)(p + 0x88) = lbl_80542CD8;
    *(f32*)(p + 0x8c) = lbl_80542CD8;
    *(s32*)(p + 0x108) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(u8*)(p + 0x250) = this_->v11();
    if (*(u8*)(p + 0x250) != 0) {
        *(f32*)(p + 0x254) = lbl_80542CE0;
        *(f32*)(p + 0x10) = *(f32*)(p + 0x28) + *(f32*)(p + 0x254);
    } else {
        *(f32*)(p + 0x254) = lbl_80542CD8;
        *(f32*)(p + 0x3c) = lbl_80542CD8;
        *(f32*)(p + 0x40) = lbl_80542CD8;
        *(f32*)(p + 0x44) = lbl_80542CD8;
        *(s32*)(p + 0x258) = 0;
        *(s32*)(p + 0x25c) = -1;
        *(s32*)(p + 0x260) = 0;
    }
}

