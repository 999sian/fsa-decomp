#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AE7D8[];
extern "C" void fn_80239914(f32* box, u32 room, u32 handle);
extern "C" u8* fn_8020D58C(u32 handle);
extern "C" void fn_8020D7D0(u8* p, u32 handle);
extern "C" f32 PSVECDistance(const Vec* a, const Vec* b);
extern "C" f32 fn_8033D4AC(f32 cur, f32 target, f32 speed);
extern "C" void fn_801EE434(u32 p);
extern "C" u32 fn_8013CC50(u32 room, Vec* pos, f32 scale, u32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8013CB44(u32 h, Vec* pos, s32 a, s32 b, s32 c);
extern "C" void fn_801F0E34(u8* self, u32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7584(void* a, void* b, u8 c);
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_80475178[];
extern "C" f32 lbl_80475148[];
extern "C" void fn_801F0D20(u8* self, s32 a);
extern "C" s32 fn_80238BC4(u32 h);
extern "C" s32 fn_80239108(u32 h);
extern "C" void fn_80238E08(u32 h);
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

extern "C" void fn_803771AC(u8* this_) {
    f32 box[4];
    Vec tmp;
    Vec* pos = (Vec*)(this_ + 0xc);
    Vec* home = (Vec*)(this_ + 0x248);
    Vec* vel = (Vec*)(this_ + 0x3c);
    box[0] = *(f32*)(this_ + 0x60);
    box[1] = *(f32*)(this_ + 0x64);
    box[2] = *(f32*)(this_ + 0x68);
    box[3] = *(f32*)(this_ + 0x6c);
    box[0] += pos->x;
    box[2] += pos->x;
    box[1] += pos->y;
    box[3] += pos->y;
    switch (*(s32*)(this_ + 0x244)) {
    case 0: {
        box[0] -= 1.0f;
        box[1] -= 1.0f;
        box[2] += 1.0f;
        box[3] += 1.0f;
        fn_80239914(box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        box[0] -= -1.0f;
        box[1] -= -1.0f;
        box[2] += -1.0f;
        box[3] += -1.0f;
        {
            u8* p = fn_8020D58C(*(u32*)(this_ + 0x198));
            fn_8020D7D0(p + p[0] * 0x784 + 4, *(u32*)(this_ + 0x198));
        }
        if (this_[0x264] == 0) {
            Vec* target = (Vec*)(this_ + 0x24);
            f32 dist = PSVECDistance(pos, target);
            f32 speed;
            if (dist >= 12.0f) {
                if (dist >= 44.1f) {
                    speed = 15.9f;
                } else {
                    speed = 19.9f;
                }
            } else {
                speed = 11.9f;
            }
            f32 d2 = PSVECDistance(pos, home);
            if (d2 < speed) {
                if (pos->x <= target->x + 11.5f && pos->x >= target->x - 11.5f) {
                    pos->x = target->x;
                } else {
                    pos->x = fn_8033D4AC(pos->x, home->x, speed);
                }
                if (pos->y <= target->y + 11.5f && pos->y >= target->y - 11.5f) {
                    pos->y = target->y;
                } else {
                    pos->y = fn_8033D4AC(pos->y, home->y, speed);
                }
            }
            JGeometry::setTVec3f((f32*)pos, (f32*)home);
            vel->x = 0.0f;
            vel->y = 0.0f;
            vel->z = 0.0f;
            if (*(u32*)(this_ + 0x230) != 0) {
                fn_801EE434(*(u32*)(this_ + 0x230));
            }
            *(u32*)(this_ + 0x230) = 0;
            *(s32*)(this_ + 0x254) = 8;
            JGeometry::setTVec3f((f32*)pos, (f32*)(this_ + 0x18));
            if (PSVECDistance(pos, target) < 63.9) {
                ((Actor*)this_)->v10(0xff, 1);
                f32 x = pos->x - 24.0f;
                s32 i, j;
                for (i = 0; i < 4; i++) {
                    tmp.x = x;
                    tmp.y = pos->y;
                    tmp.z = pos->z;
                    f32* offset = lbl_80475178;
                    for (j = 0; j < 4; j++, offset++) {
                        tmp.y = pos->y + *offset;
                        fn_802A3948(lbl_8053AC98, &tmp, 0, *(u32*)(this_ + 4), 0);
                    }
                    x += 16.0f;
                }
                *(s32*)(this_ + 0x244) = 1;
                *(s32*)(this_ + 0x25c) = 50;
                *(s32*)(this_ + 0x260) = 0;
                if (*(u32*)(this_ + 0x230) == 0) {
                    *(u32*)(this_ + 0x230) = fn_8013CC50(*(u32*)(this_ + 4), pos, 1.0f, 0x542, 0, 0, 0, 0, 1);
                    fn_8013CB44(*(u32*)(this_ + 0x230), pos, -1, -1, 1);
                }
                if (*(u32*)(this_ + 0x234) == 0) {
                    *(u32*)(this_ + 0x234) = fn_8013CC50(*(u32*)(this_ + 4), pos, 1.0f, 0xb7, 0, 0, 0, 0, 1);
                    fn_8013CB44(*(u32*)(this_ + 0x234), pos, -1, -1, 1);
                }
                if (*(u32*)(this_ + 0x238) == 0) {
                    *(u32*)(this_ + 0x238) = fn_8013CC50(*(u32*)(this_ + 4), pos, 1.0f, 0xb8, 0, 0, 0, 0, 1);
                    fn_8013CB44(*(u32*)(this_ + 0x238), pos, 0, 0, 1);
                }
                if (*(u32*)(this_ + 0x23c) == 0) {
                    *(u32*)(this_ + 0x23c) = fn_8013CC50(*(u32*)(this_ + 4), pos, 1.0f, 0xb9, 0, 0, 0, 0, 1);
                    fn_8013CB44(*(u32*)(this_ + 0x23c), pos, 0, 0, 1);
                }
                if (*(u32*)(this_ + 0x240) == 0) {
                    *(u32*)(this_ + 0x240) = fn_8013CC50(*(u32*)(this_ + 4), pos, 1.0f, 0xba, 0, 0, 0, 0, 1);
                    fn_8013CB44(*(u32*)(this_ + 0x240), pos, 0, 0, 1);
                }
                fn_801F0E34(this_, 0x50065, 0);
                if (this_[0x265] == 0) {
                    fn_802D7584(fn_802D6A9C(), *(void**)(this_ + 0x16c), (u8)*(u32*)(this_ + 0x258));
                }
            }
        }
        break;
    }
    case 1: {
        pos->x += vel->x;
        pos->y += vel->y;
        pos->z += vel->z;
        break;
    }
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
            s32 j;
            s32 i;
            Vec pos;
            f32 x = ((Vec*)(this_ + 0xc))->x;
            f32 y = ((Vec*)(this_ + 0xc))->y;
            f32 z = ((Vec*)(this_ + 0xc))->z;
            x -= 24.0f;
            for (i = 0; i < 4; i++) {
                pos.x = x;
                pos.y = y;
                pos.z = z;
                f32* offset = lbl_80475178;
                for (j = 0; j < 4; j++, offset++) {
                    pos.y = y + *offset;
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
    JGeometry::setTVec3f((f32*)(this_ + 0xc), (f32*)(this_ + 0x248));
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
