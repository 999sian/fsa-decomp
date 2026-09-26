// FDWP_8012EA00: .text 0x8012EA00-0x8012F008 (actor FDWP, all-players warp trigger)
#include "types.h"

struct FdwpVec {
    f32 x;
    f32 y;
};

extern "C" void v01__5ActorFv(void* this_);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" u8 fn_8023F264(s32 player);
extern "C" u8 fn_8023EA28(s32 player);
extern "C" u8 fn_8023561C(s32 player);
extern "C" u8 fn_80230188(s32 player);
extern "C" FdwpVec* fn_8023E724(s32 player);
extern "C" void fn_8023077C(void);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void* mgr, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* rec, u32 a, u32 b);
extern "C" void fn_80136798(void* obj, int id, int arg);
void operator delete(void* p);
extern void* lbl_8049E8F8[];
extern u8* lbl_8053AAF8;

class FDWP_Actor {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30(s32, s32);
    virtual u8 vf34();
    virtual void vf38();
    virtual s32 vf3C();
};

#define S32(o) (*(s32*)(this_ + (o)))
#define F32(o) (*(f32*)(this_ + (o)))

extern "C" void* fn_8012EA00(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E8F8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8012EA60(u8* this_) {
    v03__5ActorFv(this_);
    switch (S32(0x230)) {
    case 0: {
        if (((FDWP_Actor*)this_)->vf3C() != 0 && !((FDWP_Actor*)this_)->vf34()) {
            break;
        }
        f32 x0 = F32(0x60);
        f32 y0 = F32(0x64);
        f32 x1 = F32(0x68);
        f32 y1 = F32(0x6C);
        x0 += F32(0xC);
        x1 += F32(0xC);
        y0 += F32(0x10);
        y1 += F32(0x10);
        BOOL all;
        for (s32 i = 0; i < 4; i++) {
            if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
                if (!fn_8023F264(i)) {
                    all = FALSE;
                    goto done;
                }
                if (fn_8023EA28(i)) {
                    all = FALSE;
                    goto done;
                }
                if (!fn_8023561C(i)) {
                    all = FALSE;
                    goto done;
                }
                if (fn_80230188(i)) {
                    all = FALSE;
                    goto done;
                }
                FdwpVec* v = fn_8023E724(i);
                f32 x = v->x;
                u8 in = FALSE;
                if (x >= x0 && v->y >= y0 && x < x1 && v->y < y1) {
                    in = TRUE;
                }
                if (!in) {
                    all = FALSE;
                    goto done;
                }
            }
        }
        all = TRUE;
    done:
        if ((u8)all) {
            S32(0x230) = 2;
            switch (S32(0x230)) {
            case 1:
                fn_8023077C();
                fn_80119998(fn_80119DD0(), 0x3C, 0, 1, 0, 1, 0x5A, 0);
                break;
            case 0:
                break;
            case 2:
                fn_802D9FF4(fn_802D6A9C(), S32(0x234), S32(0x238));
                fn_80136798(lbl_8053AAF8, 0xF, 0);
                break;
            }
        }
        break;
    }
    case 1:
        S32(0x23C)++;
        if (S32(0x23C) == 0x78) {
            S32(0x230) = 2;
            switch (S32(0x230)) {
            case 1:
                fn_8023077C();
                fn_80119998(fn_80119DD0(), 0x3C, 0, 1, 0, 1, 0x5A, 0);
                break;
            case 0:
                break;
            case 2:
                fn_802D9FF4(fn_802D6A9C(), S32(0x234), S32(0x238));
                fn_80136798(lbl_8053AAF8, 0xF, 0);
                break;
            }
        }
        break;
    case 2:
    default:
        break;
    }
}

extern "C" void fn_8012ED40(u8* this_) {
    v01__5ActorFv(this_);
    S32(0x234) = (*(u32*)(this_ + 0x90) >> 8) & 0xF;
    S32(0x238) = (*(u32*)(this_ + 0x90) >> 12) & 0xF;
    F32(0x60) = -32.0f;
    F32(0x64) = -16.0f;
    F32(0x68) = 32.0f;
    F32(0x6C) = 16.0f;
    F32(0x70) = F32(0x60);
    F32(0x74) = F32(0x64);
    F32(0x78) = F32(0x68);
    F32(0x7C) = F32(0x6C);
    F32(0x80) = F32(0x60);
    F32(0x84) = F32(0x64);
    F32(0x88) = F32(0x68);
    F32(0x8C) = F32(0x6C);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
