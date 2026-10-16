#include "Game/Actor.h"


extern void* lbl_804AE948[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_80379870(void* this_, s16 freeFlag) {
    if (this_ != NULL) {
        *(void**)this_ = lbl_804AE948;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 fn_803798D0(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_80239914(f32* rect, s32 a, void* b);
extern f32 lbl_80475340[];
extern "C" void fn_80379A90(Actor* this_) {
    u8* self = (u8*)this_;
    Vec* pos = &this_->field_0C;
    f32 rect[4];
    u8 ok;
    if (*(s32*)(self + 0x234) == 0 || (u8)this_->v11()) {
        switch (*(s32*)(self + 0x230)) {
        case 0:
            if (!fn_803798D0(this_)) {
                return;
            }
            break;
        case 1: {
            Vec saved = *pos;
            ok = 0;
            if (fn_801F2618(this_, 0, 0)) {
                ok = 1;
            }
            *pos = saved;
            if (!ok) {
                return;
            }
            break;
        }
        }
        {
            f32* t = (f32*)((u8*)lbl_80475340 + ((((this_->field_90 & 3) + *(s32*)(self + 0x230) * 4) * 16) & 0xff0));
            rect[0] = t[0];
            rect[1] = t[1];
            rect[2] = t[2];
            rect[3] = t[3];
            rect[0] += pos->x;
            rect[2] += pos->x;
            rect[1] += pos->y;
            rect[3] += pos->y;
            fn_80239914(rect, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        }
    }
}
struct Quad {
    f32 v[4];
};
extern "C" const Quad lbl_804752C0[4];
extern "C" const Quad lbl_80475300[4];
