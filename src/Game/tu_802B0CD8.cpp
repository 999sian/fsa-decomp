#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A8520[];
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 idx);
extern "C" void* fn_8013CC50(u32 a, void* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_801F0E34(void* this_, u32 a, s32 b);
extern "C" void* fn_802B114C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8520;
        char* p = (char*)this_;
        void* h1 = *(void**)(p + 0x230);
        if (h1 != 0) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)(p + 0x234);
        if (h2 != 0) {
            fn_801EE434(h2);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 idx);
extern "C" void* fn_8013CC50(u32 a, void* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_802B11D0(void* this_) {
    char* p = (char*)this_;
    *(u32*)(p + 0x23c) = *(u32*)(p + 0x90) & 0x7f;
    *(u32*)(p + 0x244) = *(u32*)(p + 0x90) >> 27;
    *(u32*)(p + 0x24c) = 0;
    *(f32*)(p + 0x250) = 0.0f;
    if (*(s32*)(p + 0x23c) == 0 || *(s32*)(p + 0x23c) == 2) {
        *(f32*)(p + 0x254) = 70.0f;
    } else {
        *(f32*)(p + 0x254) = 20.0f;
    }
    *(u16*)(p + 0x94) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = 0;
    s32 idx = *(s32*)(p + 0x244);
    if (idx == 0 || fn_802D800C(fn_802D6A9C(), idx)) {
        *(u8*)(p + 0x248) = 1;
        s32 state = *(s32*)(p + 0x23c);
        if (state == 0 || state == 2 || state == 4) {
            *(u32*)(p + 0x230) = (u32)fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0xbd, 0, 0, 0, 0, 1);
            if (*(s32*)(p + 0x23c) != 4) {
                *(u32*)(p + 0x234) = (u32)fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x54a, 0, 0, 0, 0, 1);
            }
        }
        *(u32*)(p + 0xb0) = 0xc;
        *(u32*)(p + 0x238) = 1;
        *(u32*)(p + 0x24c) = 1;
    } else {
        *(u32*)(p + 0xb0) = 0xd;
        *(u32*)(p + 0x238) = 0;
        *(u8*)(p + 0x248) = 0;
    }
}

