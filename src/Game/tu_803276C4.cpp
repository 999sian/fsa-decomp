#include "Game/Actor.h"
#include "Game/ItemBase.h"

class ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char* lbl_804AB518[];
extern const char lbl_804718D0[];
extern "C" void* fn_802D6A9C(void);
extern "C" void PSMTXIdentity(void* m);
extern "C" void fn_802F86CC(void* a, void* b, void* c, u32 d, void* e, f32 f, f32 g);
extern "C" void fn_802F745C(void* a, void* b, void* c, void* d);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);


extern "C" char __vt__4OSIN[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803276C4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4OSIN;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_80327724(u8* this_) {
    if (*(f32*)(this_ + 0x25c) != 0.0f) {
        if (*(s32*)((u8*)fn_802D6A9C() + 4) != 7 || *(s32*)((u8*)fn_802D6A9C() + 8) != 2) {
            DrawRec rec;
            f32 mtx[3][4];
            PSMTXIdentity(mtx);
            f32 s = (f32)(*(s32*)(this_ + 0x240) + 1) * *(f32*)(this_ + 0x25c);
            mtx[0][1] = 0.0f;
            mtx[0][2] = 0.0f;
            mtx[0][0] = s;
            mtx[1][0] = 0.0f;
            mtx[1][1] = s;
            mtx[1][2] = 0.0f;
            mtx[2][0] = 0.0f;
            mtx[2][1] = 0.0f;
            mtx[2][2] = s;
            rec.w18 = mtx;
            s32 id = *(s32*)(this_ + 0x234) + 0x141;
            if (*(s32*)(this_ + 4) < 8) {
                void* res = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18('SOB ', lbl_804718D0);
                fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, &rec, 1.0f, 1.0f);
            }
            fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x141,
                        *(s32*)(this_ + 0x240) != 0, 2, -1, 0, 0, 0);
        } else {
            void* res = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x54494d47, lbl_804AB518[*(s32*)(this_ + 0x250)]);
            if (*(s32*)(this_ + 4) < 8) {
                fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, 0);
            }
        }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" u8 fn_801F6758(f32* pos, s32 room, f32 r);
extern "C" void fn_803283FC(u8* this_) {
    s32 idx = -1;
    *(u16*)(this_ + 0x94) = *(u32*)(this_ + 0x90) & 0xf;
    *(s32*)(this_ + 0x240) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(s32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u8*)(this_ + 0x25a) = (*(u32*)(this_ + 0x90) >> 12) & 1;
    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 0x4f53494e, idx);
        if (idx < 0) {
            break;
        }
        if (idx == *(s32*)(this_ + 0x198)) {
            continue;
        }
        u8* p = (u8*)fn_801F666C(fn_801F856C(), idx);
        if (p == 0) {
            continue;
        }
        if (*(s32*)(p + 0x248) != *(s32*)(this_ + 0x248)) {
            continue;
        }
        if (fn_801F6758((f32*)(p + 0xc), *(s32*)(p + 0x4), 0.0f) != 0) {
            continue;
        }
        break;
    }
    *(u8*)(this_ + 0x11c) = 0;
    *(s32*)(this_ + 0x108) = 10000;
    *(f32*)(this_ + 0x10) -= 8.0f;
    *(f32*)(this_ + 0x260) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x264) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x268) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(f32*)(this_ + 0x25c) = 1.0f;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x24c) = 10;
    *(s32*)(this_ + 0x250) = 0;
    *(u8*)(this_ + 0x258) = 0;
    *(u8*)(this_ + 0x259) = 0;
    *(u8*)(this_ + 0x254) = 0;
    *(u8*)(this_ + 0x255) = 0;
    *(u8*)(this_ + 0x256) = 0;
    *(u8*)(this_ + 0x257) = 0;
    if (*(u8*)(this_ + 0x25a) == 1) {
        *(f32*)(this_ + 0x25c) = 0.0f;
        if (*(s32*)(this_ + 0x240) == 0) {
            *(f32*)(this_ + 0x80) = -15.0f;
            *(f32*)(this_ + 0x84) = -7.0f;
            *(f32*)(this_ + 0x88) = 15.0f;
            *(f32*)(this_ + 0x8c) = 7.0f;
            *(f32*)(this_ + 0x60) = -15.0f;
            *(f32*)(this_ + 0x64) = -7.0f;
            *(f32*)(this_ + 0x68) = 15.0f;
            *(f32*)(this_ + 0x6c) = 7.0f;
        } else if (*(s32*)(this_ + 0x240) == 1) {
            *(f32*)(this_ + 0x80) = -31.0f;
            *(f32*)(this_ + 0x84) = -15.0f;
            *(f32*)(this_ + 0x88) = 31.0f;
            *(f32*)(this_ + 0x8c) = 15.0f;
            *(f32*)(this_ + 0x60) = -31.0f;
            *(f32*)(this_ + 0x64) = -15.0f;
            *(f32*)(this_ + 0x68) = 31.0f;
            *(f32*)(this_ + 0x6c) = 15.0f;
        }
    }
}

