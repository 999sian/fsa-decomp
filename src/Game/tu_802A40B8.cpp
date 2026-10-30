#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801F06F0(void* this_, const void* name, s32 a, s32 b, s32 c, f32 f, f32 g);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern void* lbl_804A7E58[];
extern const char lbl_8046C640[];
extern const f32 lbl_805407A0;
extern const f32 lbl_805407A4;
extern const f32 lbl_805407B4;
extern const f32 lbl_805407B8;
extern const f32 lbl_805407A8;
extern const f32 lbl_805407AC;
extern const f32 lbl_805407B0;
extern "C" s32 fn_8023AF14(f32* pos, s32 a, s32 b);
extern "C" u8 fn_80388EEC(void* p);
extern "C" void fn_80230224(s32 a, s32 b);
extern "C" u8 fn_8023ED8C(void);
extern "C" u8 fn_8023EBB8(s32 a);
extern "C" void* fn_8023E724(s32 a);
extern "C" u8 fn_802308E0(s32 a);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, s32 id, s32 a, void* pos, s32 b, s32 c, s32 d);
extern "C" void fn_8030C210(void* a, void* b);
extern void* lbl_8053AB10;

struct TBoxCopy {
    f32 ix, iy, fx, fy;
};
extern "C" void* fn_802A40B8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7E58;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_802A4118(u8* this_) {
    fn_801F06F0(this_, lbl_8046C640, 0x31, 0, 1, lbl_805407A0, lbl_805407A0);
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 0x4), this_ + 0xc, 0x31, 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_802A4190(u8* this_) {
    f32 pos[3];
    TBoxCopy vec;
    JGeometry::TVec3f tmp;
    s32 state = *(s32*)(this_ + 0x230);
    f32 px = *(f32*)(this_ + 0xc);
    f32 py = *(f32*)(this_ + 0x10);

    switch (state) {
    case 0:
        if (lbl_805407A4 != *(f32*)(this_ + 0x14) || lbl_805407A4 != *(f32*)(this_ + 0x44)) {
            *(JGeometry::TVec3f*)(this_ + 0xc) += *(JGeometry::TVec3f*)(this_ + 0x3c);
            *(f32*)(this_ + 0x44) -= lbl_805407A8;
            if (!(*(f32*)(this_ + 0x14) <= lbl_805407A4)) {
                *(f32*)(this_ + 0x14) = lbl_805407A4;
                *(f32*)(this_ + 0x44) = lbl_805407A4;
                *(f32*)(this_ + 0x40) = lbl_805407A4;
                *(f32*)(this_ + 0x3c) = lbl_805407A4;
            }
        }

        vec = *(TBoxCopy*)(this_ + 0x60);
        vec.ix = vec.ix + px;
        vec.iy = vec.iy + py;
        vec.fx = vec.fx + px;
        vec.fy = vec.fy + py;
        *(s32*)(this_ + 0x238) = fn_8023AF14((f32*)&vec, *(s32*)(this_ + 4), 1);

        if (*(s32*)(this_ + 0x238) >= 0 && !fn_8023ED8C() && !fn_8023EBB8(*(s32*)(this_ + 0x238)) && *(f32*)(this_ + 0x14) <= lbl_805407A4) {
            tmp = *(JGeometry::TVec3f*)fn_8023E724(*(s32*)(this_ + 0x238));
            *(f32*)(this_ + 0xc) = lbl_805407AC + tmp.x;
            *(f32*)(this_ + 0x10) = tmp.y - lbl_805407B0;
            if (fn_802308E0(*(s32*)(this_ + 0x238)) == 1) {
                void* mgr = fn_801F856C();
                Actor_CreateByID(mgr, 0x494d5550, *(s32*)(this_ + 4), this_ + 0xc, ((*(s32*)(this_ + 0x238) << 24) + 0x800000 + (*(s32*)(this_ + 0x238) << 26)) + 0x14, -1, -1);
                this_[0x11c] = 0;
            }
        }
        break;
    case 1:
        if (*(s32*)(this_ + 0x234) == 0 && fn_80388EEC(*(void**)(this_ + 0x238))) {
            fn_80230224(*(s32*)(this_ + 0x238), 0);
            fn_80230224(*(s32*)(this_ + 0x90) & 0xf, 0);
            this_[0x11c] = 0;
        } else if (*(s32*)(this_ + 0x234) != 0) {
            *(s32*)(this_ + 0x234) -= 1;
        }
        break;
    }

    if (*(s32*)(this_ + 4) < 8) {
        pos[0] = *(f32*)(this_ + 0xc);
        pos[1] = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
        pos[2] = lbl_805407A4;
        fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), pos);
    }
}

extern "C" void fn_802A4404(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_805407B4;
    *(f32*)(this_ + 0x64) = lbl_805407B4;
    *(f32*)(this_ + 0x68) = lbl_805407B8;
    *(f32*)(this_ + 0x6c) = lbl_805407B8;
    *(f32*)(this_ + 0x44) = lbl_805407A4;
    *(s32*)(this_ + 0x230) = 0;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
