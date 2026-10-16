#include "types.h"
#include "JSystem/J2D/J2DScreen.h"

struct Tu803DA6B4Sub {
    virtual void v00(s32 how);
};

struct Tu803DA6B4Pane {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void move(f32 x, f32 y);
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void setAlpha(s32 alpha);
};

struct Tu803DA6B4Owner {
    void* vtbl;
    Tu803DA6B4Sub* mpSub;
    J2DPane* mpPane0;
    J2DPane* mpPane1;
    f32 mX;
    f32 mY;
    f32 mZ;
    s16 m1C;
    u8 mAlpha0;
    u8 mAlpha1;
    u8 m20;
    u8 m21;
};

extern "C" char lbl_804B04F8[];
extern "C" void* lbl_8053ADC8;
extern "C" char lbl_804774B4[];
extern "C" char lbl_80529DEC[];
extern "C" f32 lbl_805435B0;

extern "C" void fn_8013B490(void* p);
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_804774A0[];
extern "C" f32 lbl_805435B4;
extern "C" f32 lbl_805435B8;
extern "C" f32 lbl_805435BC;
extern "C" f32 lbl_805435C0;
extern "C" void fn_803DA6B4(Tu803DA6B4Owner* this_) {
    this_->mZ = lbl_805435B0;
    if (this_->m20 != 0) {
        this_->m1C++;
        if (this_->m1C < 0x1b) {
            s32 d;
            if (this_->m1C < 13) {
                d = 13 - this_->m1C;
            } else {
                d = this_->m1C - 13;
            }
            this_->mZ = lbl_805435B4 + lbl_805435B8 * (f32)(d * d) / lbl_805435BC;
        } else {
            this_->mZ = lbl_805435C0;
            if (this_->m1C >= 0x2e) {
                this_->m1C = 0;
            }
        }
        if (this_->m21 != 1) {
            this_->mpPane1->move(this_->mX, this_->mY + lbl_804774A0[this_->m21]);
            this_->mpPane0->setAlpha((s32)((f32)this_->mAlpha0 * this_->mZ));
            this_->mpPane1->setAlpha((s32)((f32)this_->mAlpha1 * this_->mZ));
            fn_8013B490(lbl_8053AB10);
            ((J2DScreen*)this_->mpSub)->draw(lbl_805435B0, lbl_805435B0, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
        }
        this_->m20 = 0;
    } else {
        if (this_->m1C != 0) {
            this_->m1C = 0;
        }
    }
}

extern "C" Tu803DA6B4Owner* fn_803DA878(Tu803DA6B4Owner* this_, s16 del) {
    if (this_ != 0) {
        this_->vtbl = lbl_804B04F8;
        if (this_->mpSub != 0) {
            this_->mpSub->v00(1);
        }
        this_->mpSub = 0;
        lbl_8053ADC8 = 0;
        if (del > 0) {
            delete this_;
        }
    }
    return this_;
}

extern "C" Tu803DA6B4Owner* fn_803DA8FC(Tu803DA6B4Owner* this_) {
    this_->vtbl = lbl_804B04F8;
    lbl_8053ADC8 = this_;
    J2DScreen* screen = new J2DScreen();
    if (screen == 0) {
        return this_;
    }
    this_->mpSub = (Tu803DA6B4Sub*)screen;
    ((J2DScreen*)this_->mpSub)->setPriority(lbl_804774B4, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x20));
    this_->mpPane0 = ((J2DScreen*)this_->mpSub)->search(0x7072737374727431ULL);
    this_->mpPane1 = ((J2DScreen*)this_->mpSub)->search(0x7072737374727432ULL);
    this_->mX = this_->mpPane1->getBounds()->i.x;
    this_->mY = this_->mpPane1->getBounds()->i.y;
    this_->mAlpha0 = this_->mpPane0->mAlpha;
    this_->mAlpha1 = this_->mpPane1->mAlpha;
    this_->m1C = 0;
    this_->m20 = 0;
    this_->mZ = 0.0f;
    this_->m21 = 0;
    return this_;
}

