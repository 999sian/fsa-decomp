#include "types.h"
#include "JSystem/J2D/J2DPane.h"


extern "C" void fn_8044C028(u8* this_, f32 val) {
    this_[0x18] = 1;
    *(f32*)(this_ + 0x14) = val;
}

extern "C" void fn_8044C038(u8* this_) {
    if (this_[0x18] != 0) {
        f32 x = (*(J2DPane**)(this_ + 8))->search(0x54703031)->getBounds()->i.x;
        (*(J2DPane**)(this_ + 8))->search(0x54703031)->move(x, *(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x14));
        x = (*(J2DPane**)(this_ + 8))->search(0x54703032)->getBounds()->i.x;
        (*(J2DPane**)(this_ + 8))->search(0x54703032)->move(x, *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14));
    }
}

extern "C" void fn_8013B490(void* p);
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80543DC8;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* self, f32 x, f32 y, void* ctx);
extern "C" void fn_8044C14C(u8* this_) {
    if (this_[0x18] != 0) {
        fn_8013B490(lbl_8053AB10);
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(this_ + 4), lbl_80543DC8, lbl_80543DC8, *(void**)((u8*)lbl_8053AB10 + 0x10));
        *(u8*)(*(u8**)(this_ + 8) + 0x100) = 1;
        f32 f = lbl_80543DC8;
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(this_ + 8), f, f, *(void**)((u8*)lbl_8053AB10 + 0x10));
        this_[0x18] = 0;
    }
}

extern "C" void __dl__FPv(void* p);
extern "C" char lbl_804B1D20[];
extern "C" s32 lbl_8053AF38;

class RupyDeletable {
public:
    virtual ~RupyDeletable();
};
extern "C" void* fn_8044C1CC(void** this_, s16 param_2) {
    if (this_ != nullptr) {
        void** p = this_;
        s32 i = 0;
        *this_ = lbl_804B1D20;
        do {
            delete (RupyDeletable*)p[1];
            i++;
            p++;
            *p = nullptr;
        } while (i < 2);
        lbl_8053AF38 = 0;
        if (param_2 > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

