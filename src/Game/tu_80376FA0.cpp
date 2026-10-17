#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AE7D8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80376FA0(Actor* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE7D8;
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802F745C(void* a, void* b, void* c, void* d);
extern "C" u32 fn_804032E8(u32 tag, const char* name);
extern "C" char lbl_80475188[];
extern "C" char lbl_80475198[];
extern "C" u32 lbl_8053AB10;
extern "C" void fn_80377000(u8* this_) {
    DrawRec rec;
    rec.b1c = 0;
    *(s8*)&rec.b1d = -1;
    s32 kind = *(s32*)(this_ + 0x244);
    switch (kind) {
    case 0:
        {
            u32 res = fn_804032E8(0x54494D47, lbl_80475188);
            if (*(s32*)(this_ + 4) < 8) {
                fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, (void*)res, &rec);
            }
        }
        break;
    case 1: {
        u32 res = fn_804032E8(0x54494D47, lbl_80475198);
        if (*(s32*)(this_ + 4) < 8) {
            fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, (void*)res, &rec);
        }
    } break;
    }
}

extern "C" int fn_8028D4DC(f32* this_, s32 a, void* c);
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_80475178[];
extern "C" void fn_80377A38(u8* this_) {
    *(s32*)(this_ + 0x244) = 0;
    this_[0x264] = 0;
    *(u32*)(this_ + 0x258) = (u8)((u8)*(u32*)(this_ + 0x90) + 1);
    this_[0x265] = (*(u32*)(this_ + 0x90) >> 16) & 1;
    if (this_[0x265] == 0) {
        if ((u8)fn_8028D4DC((f32*)(this_ + 0xc), 3, *(void**)(this_ + 0x16c))) {
            *(s32*)(this_ + 0x244) = 1;
            Vec pos;
            f32 x = ((Vec*)(this_ + 0xc))->x;
            f32 y = ((Vec*)(this_ + 0xc))->y;
            f32 z = ((Vec*)(this_ + 0xc))->z;
            x -= 24.0f;
            for (s32 i = 0; i < 4; i++) {
                pos.x = x;
                pos.y = y;
                pos.z = z;
                for (s32 j = 0; j < 4; j++) {
                    pos.y = y + lbl_80475178[j];
                    fn_802A3948(lbl_8053AC98, &pos, 0, *(u32*)(this_ + 4), 0);
                }
                x += 16.0f;
            }
            this_[0x264] = 1;
            return;
        }
    }
    ((Vec*)(this_ + 0x3c))->x = 0.0f;
    ((Vec*)(this_ + 0x3c))->y = 0.0f;
    ((Vec*)(this_ + 0x3c))->z = 0.0f;
    *(f64*)(this_ + 0x248) = *(f64*)(this_ + 0xc);
    *(f32*)(this_ + 0x250) = ((Vec*)(this_ + 0xc))->z;
    *(f32*)(this_ + 0x60) = -31.5f;
    *(f32*)(this_ + 0x64) = -31.5f;
    *(f32*)(this_ + 0x68) = 31.5f;
    *(f32*)(this_ + 0x6c) = 31.5f;
    *(f32*)(this_ + 0x80) = -31.5f;
    *(f32*)(this_ + 0x84) = -31.5f;
    *(f32*)(this_ + 0x88) = 31.5f;
    *(f32*)(this_ + 0x8c) = 31.5f;
    *(s32*)(this_ + 0x1a4) = 4;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
}
