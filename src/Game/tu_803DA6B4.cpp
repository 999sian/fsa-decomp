#include "types.h"
#include "JSystem/J2D/J2DScreen.h"

struct Tu803DA6B4Sub {
    virtual void v00(s32 how);
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
    J2DScreen* screen;
    if ((screen = new J2DScreen()) != 0) {
        this_->mpSub = (Tu803DA6B4Sub*)screen;
        ((J2DScreen*)this_->mpSub)->setPriority(lbl_804774B4, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x20));
        this_->mpPane0 = ((J2DScreen*)this_->mpSub)->search(0x7072737374727431ULL);
        this_->mpPane1 = ((J2DScreen*)this_->mpSub)->search(0x7072737374727432ULL);
        this_->mX = this_->mpPane1->getBounds()->i.x;
        this_->mY = this_->mpPane1->getBounds()->i.y;
        this_->mZ = 0.0f;
        this_->mAlpha0 = this_->mpPane0->mAlpha;
        this_->mAlpha1 = this_->mpPane1->mAlpha;
        this_->m1C = 0;
        this_->m20 = 0;
        this_->m21 = 0;
    }
    return this_;
}

