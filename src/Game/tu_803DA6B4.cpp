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
