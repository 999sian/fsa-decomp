#include "Game/esd/types.h"
#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_802A3884(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern "C" void fn_8023061C(s32 p, s32 a);
extern "C" char lbl_804AAAE8[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern void* lbl_8053AC98;
extern "C" void* fn_80310DE8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AAAE8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80310E48(void* this_) {
    fn_802A3948(lbl_8053AC98, (u8*)this_ + 0xc, 0, *(u32*)((u8*)this_ + 4), 0x10);
    *(s32*)((u8*)this_ + 0x234) = -1;
    *(s32*)((u8*)this_ + 0x230) = 0;
}

extern "C" void fn_80310E98(u8* this_) {
    if (*(s32*)(this_ + 0x230) == 1) {
        fn_802A3948(lbl_8053AC98, this_ + 0xc, 0, *(u32*)(this_ + 4), 0x10);
        fn_801F0E34(this_, 0x30076, 0);
        *(f32*)(this_ + 0x248) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x24c) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x250) = *(f32*)(this_ + 0x14);
        *(u8*)(this_ + 0x254) = 0;
        *(s32*)(this_ + 0x240) = 0x5a;
        *(s32*)(this_ + 0x230) = 2;
    } else if (*(s32*)(this_ + 0x230) == 3) {
        fn_8023061C(*(s32*)(this_ + 0x234), 0);
        *(s32*)(this_ + 0x234) = -1;
        *(s32*)(this_ + 0x230) = 0;
    }
}

extern "C" void fn_80310F50(void* this_, s32 p2, s32 p3, s32 p4) {
    fn_802A3884(lbl_8053AC98, (u8*)this_ + 0xc, 0, *(u32*)((u8*)this_ + 4), 0x30);
    *(s32*)((u8*)this_ + 0x234) = p2;
    *(s32*)((u8*)this_ + 0x238) = p3;
    *(s32*)((u8*)this_ + 0x23c) = p4;
    *(s32*)((u8*)this_ + 0x230) = 1;
}

extern "C" f32 lbl_805417AC;
extern "C" f32 lbl_805417A4;
extern "C" f32 lbl_805417B0;
extern "C" f32 lbl_805417A0;
extern "C" f32 lbl_805417B4;
extern "C" void fn_80311504(u8* this_) {
    JGeometry::TVec3f* pos = (JGeometry::TVec3f*)(this_ + 0xc);
    f32 a = lbl_805417AC;
    f32 nx = pos->x + a;
    f32 b = lbl_805417A4;
    f32 c = lbl_805417B0;
    f32 d = lbl_805417A0;
    f32 z = lbl_805417B4;
    pos->x = nx;
    pos->y = pos->y + b;
    ((JGeometry::TVec3f*)(this_ + 0x60))->set(c, d, z);
    *(f32*)(this_ + 0x6c) = z;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = -1;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = -1;
    *(s32*)(this_ + 0x240) = 0;
    *(JGeometry::TVec3f*)(this_ + 0x248) = *pos;
    *(u8*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x244) = 0;
}

