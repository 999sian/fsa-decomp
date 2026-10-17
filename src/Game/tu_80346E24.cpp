#include "Game/Actor.h"

extern "C" void fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" f32 lbl_80542438;
extern "C" f32 lbl_8054243C;
extern "C" f32 lbl_80542440;
extern "C" f32 lbl_80542444;
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" f32 lbl_80542448;
extern "C" f32 lbl_8054244C;
extern "C" f32 lbl_80542450;
extern "C" f32 lbl_80542454;
extern "C" f32 lbl_80542458;


extern "C" char lbl_804AC6B0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80346E24(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC6B0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" s32 fn_8022461C(s32);
extern "C" void fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(Actor*, s32, s32);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" s32 v17__5ActorFiPf(Actor*, s32, f32*);
extern "C" f32 lbl_80542438;
extern "C" f32 lbl_8054243C;
extern "C" f32 lbl_8054245C;
extern "C" s32 fn_803477DC(Actor* this_, s32 a, s32 b) {
    u8* p = (u8*)this_;
    s32 type = (u16)fn_8022461C(b);
    if ((u32)(type - 0x4c) <= 2 || type == 0x4f) {
        return 0;
    } else if (type == 3) {
        if (*(f32*)(p + 0x14) <= lbl_80542438) {
            *(f32*)(p + 0x234) = (f32)(((s32)*(f32*)(p + 0xc)) & 0xfff0) + lbl_8054245C;
            *(f32*)(p + 0x238) = (f32)(((s32)*(f32*)(p + 0x10)) & 0xfff0) + lbl_8054245C;
            *(u32*)(p + 0x24c) = 0x400;
            *(s32*)(p + 0x230) = 3;
            *(f32*)(p + 0x3c) = lbl_80542438;
            *(f32*)(p + 0x40) = lbl_80542438;
            *(f32*)(p + 0x44) = lbl_80542438;
        }
        return 0;
    } else if (type == 0xd || type == 0x3a) {
        if (*(f32*)(p + 0x14) <= lbl_80542438) {
            fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x3d0, 0, 1, 0, 0, 1);
            fn_801F0E34(this_, 0x30022, 0);
            *(u8*)(p + 0x11c) = 0;
        }
        return 0;
    } else if (type == 0xe) {
        if (*(f32*)(p + 0x14) <= lbl_80542438) {
            if (fn_802DE9A0()) {
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x2a9, -1, 1, 0, 0, 1);
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x2aa, -1, 0, 0, 0, 1);
                fn_801F0E34(this_, 0x5005f, 0);
                *(u8*)(p + 0x11c) = 0;
            } else if (fn_802DEB58()) {
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x45e, -1, 1, 0, 0, 1);
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x45f, 0, 0, 0, 0, 1);
                fn_801F0E34(this_, 0x5003f, 0);
            } else {
                *(f32*)(p + 0x234) = (f32)(((s32)*(f32*)(p + 0xc)) & 0xfff0) + lbl_8054245C;
                *(f32*)(p + 0x238) = (f32)(((s32)*(f32*)(p + 0x10)) & 0xfff0) + lbl_8054245C;
                *(u32*)(p + 0x24c) = 0x400;
                *(s32*)(p + 0x230) = 3;
                *(f32*)(p + 0x3c) = lbl_80542438;
                *(f32*)(p + 0x40) = lbl_80542438;
                *(f32*)(p + 0x44) = lbl_80542438;
            }
        }
        return 0;
    } else if (type == 0x39) {
        return 0;
    }
    return v17__5ActorFiPf(this_, a, (f32*)b);
}

extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" Vec lbl_80472010[];
extern "C" void fn_80347B20(Actor* this_) {
    u8* p = (u8*)this_;
    *(f32*)(p + 0x60) = -4.0f;
    *(f32*)(p + 0x64) = -4.0f;
    *(f32*)(p + 0x68) = 4.0f;
    *(f32*)(p + 0x6c) = 4.0f;
    *(f32*)(p + 0x80) = -4.0f;
    *(f32*)(p + 0x84) = -4.0f;
    *(f32*)(p + 0x88) = 4.0f;
    *(f32*)(p + 0x8c) = 4.0f;
    *(u32*)(p + 0x108) = 8;
    *(u16*)(p + 0x264) = 0;
    *(f32*)(p + 0x26c) = 1.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x23c) = 0.0f;
    *(f32*)(p + 0x238) = 0.0f;
    *(f32*)(p + 0x234) = 0.0f;
    *(u8*)(p + 0x270) = (this_->field_90 >> 8) & 1;
    *(u32*)(p + 0x24c) = 0x400;
    if (((this_->field_90 >> 4) & 1) == 1) {
        *(u32*)(p + 0x230) = 1;
        *(u16*)(p + 0x264) = fn_80226850(p + 0xc, *(u32*)(p + 0x4));
        *(u32*)(p + 0xb0) = 0;
    } else {
        *(u32*)(p + 0x230) = 0;
        *(u32*)(p + 0xb0) = 0x20000;
    }
    *(s32*)(p + 0x254) = (this_->field_90 >> 27) & 3;
    if (*(s32*)(p + 0x254) != 0) {
        Vec* v;
        *(s32*)(p + 0x258) = (this_->field_90 >> 22) & 3;
        v = &lbl_80472010[*(s32*)(p + 0x258) | ((*(s32*)(p + 0x254) - 1) << 2)];
        *(f32*)(p + 0x3c) = v->x;
        *(f32*)(p + 0x40) = v->y;
        *(f32*)(p + 0x44) = v->z;
    }
    *(s32*)(p + 0x250) = -1;
    *(u8*)(p + 0x271) = this_->field_90 & 1;
    *(u32*)(p + 0x25c) = 0;
}

