#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "Game/HitRect.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AE7D8[];
extern "C" void fn_80239914(f32* box, u32 room, u32 handle);
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D7D0(u8* p, u32 handle);
extern "C" f32 PSVECDistance(const Vec* a, const Vec* b);
extern "C" f32 fn_8033D4AC(f32 cur, f32 target, f32 speed);
extern "C" void fn_801EE434(u32 p);
extern "C" u32 fn_8013CC50(u32 room, Vec* pos, u32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_8013CB44(u32 h, Vec* pos, s32 a, s32 b, s32 c);
extern "C" void fn_801F0E34(u8* self, u32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7584(void* a, void* b, u8 c);
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_80475178[];
extern "C" Vec lbl_80475148[4];
extern "C" void fn_801F0D20(u8* self, s32 a);
extern "C" void fn_8022E088(s32 i, s32 j, Vec* out);
extern "C" void fn_8022DF48(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
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

static inline void movingBlockBreakTiles(u8* self, s32& i, s32& j, f32 x, const f32 y, const f32 z) {
    Vec point;
    x -= 24.0f;
    const f32* offsets = lbl_80475178;
    for (i = 0; i < 4; i++) {
        point.x = x;
        point.y = y;
        point.z = z;
        const f32* offset = offsets;
        for (j = 0; j < 4; j++, offset++) {
            point.y = y + *offset;
            fn_802A3948(lbl_8053AC98, &point, 0, *(u32*)(self + 4), 0);
        }
        x += 16.0f;
    }
}

static inline bool movingBlockContainsPlayer(u8* self, s32 player) {
    s32 room = *(s32*)(self + 4);
    if (fn_8023DE58(player) != room) return false;
    f32 maxY, minX, minY, maxX;
    minX = *(f32*)(self + 0x60);
    maxX = *(f32*)(self + 0x68);
    minY = *(f32*)(self + 0x64);
    minX += *(f32*)(self + 0xc);
    maxX += *(f32*)(self + 0xc);
    maxY = *(f32*)(self + 0x6c);
    minY += *(f32*)(self + 0x10);
    maxY += *(f32*)(self + 0x10);
    for (s32 j = 0; j < 8; j++) {
        Vec point;
        fn_8022E088(player, j, &point);
        point.z = 0.0f;
        f32 x = point.x;
        bool inside = false;
        if (x >= minX) {
            f32 y = point.y;
            if (y >= minY && x < maxX && y < maxY) inside = true;
        }
        if (inside) return true;
    }
    return false;
}

static inline bool movingBlockContainsPlayerCached(u8* self, s32 player, s32& j) {
    j = *(s32*)(self + 4);
    if (fn_8023DE58(player) != j) return false;
    f32 maxY, minX, minY, maxX;
    minX = *(f32*)(self + 0x60);
    maxX = *(f32*)(self + 0x68);
    minY = *(f32*)(self + 0x64);
    minX += *(f32*)(self + 0xc);
    maxX += *(f32*)(self + 0xc);
    maxY = *(f32*)(self + 0x6c);
    minY += *(f32*)(self + 0x10);
    maxY += *(f32*)(self + 0x10);
    for (j = 0; j < 8; j++) {
        Vec point;
        fn_8022E088(player, j, &point);
        point.z = 0.0f;
        f32 x = point.x;
        bool inside = false;
        if (x >= minX) {
            f32 y = point.y;
            if (y >= minY && x < maxX && y < maxY) inside = true;
        }
        if (inside) return true;
    }
    return false;
}

static inline bool movingBlockContainsPlayerRef(u8* self, s32 player, s32& j, f32& maxY, f32& minX, f32& minY, f32& maxX) {
    j = *(s32*)(self + 4);
    if (fn_8023DE58(player) != j) return false;
    minX = *(f32*)(self + 0x60);
    maxX = *(f32*)(self + 0x68);
    minY = *(f32*)(self + 0x64);
    minX += *(f32*)(self + 0xc);
    maxX += *(f32*)(self + 0xc);
    maxY = *(f32*)(self + 0x6c);
    minY += *(f32*)(self + 0x10);
    maxY += *(f32*)(self + 0x10);
    for (j = 0; j < 8; j++) {
        Vec point;
        fn_8022E088(player, j, &point);
        point.z = 0.0f;
        f32 x = point.x;
        bool inside = false;
        if (x >= minX) {
            f32 y = point.y;
            if (y >= minY && x < maxX && y < maxY) inside = true;
        }
        if (inside) return true;
    }
    return false;
}
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
extern "C" void fn_803771AC(u8* this_) {
    JGeometry::TBox2<f32> box;
    Vec tmp;
    f32 x, y, z;
    s32 j, i;
    box.set(*(JGeometry::TBox2<f32>*)(this_ + 0x60));
    box.addPos(*(JGeometry::TVec2<f32>*)(this_ + 0xc));
    switch (*(s32*)(this_ + 0x244)) {
    case 0: {
        box.i.x -= 1.0f;
        box.i.y -= 1.0f;
        box.f.x += 1.0f;
        box.f.y += 1.0f;
        fn_80239914((f32*)&box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        box.i.x -= -1.0f;
        box.i.y -= -1.0f;
        box.f.x += -1.0f;
        box.f.y += -1.0f;
        {
            i = *(s32*)(this_ + 0x198);
            HitRectMgr* manager = (HitRectMgr*)fn_8020D58C();
            fn_8020D7D0((u8*)&manager->lists[manager->cur], i);
        }
        if (this_[0x264] == 0) {
            f32 dist = PSVECDistance(((Vec*)(this_ + 0xc)), ((Vec*)(this_ + 0x24)));
            f32 speed;
            if (dist < 12.0f) speed = 11.9f;
            else if (dist >= 44.1f) speed = 15.9f;
            else speed = 19.9f;
            f32 d2 = PSVECDistance(((Vec*)(this_ + 0xc)), ((Vec*)(this_ + 0x248)));
            if (d2 >= speed) {
                if (((Vec*)(this_ + 0xc))->x <= ((Vec*)(this_ + 0x24))->x + 11.5f && ((Vec*)(this_ + 0xc))->x >= ((Vec*)(this_ + 0x24))->x - 11.5f) {
                    ((Vec*)(this_ + 0xc))->x = ((Vec*)(this_ + 0x24))->x;
                } else {
                    ((Vec*)(this_ + 0xc))->x = fn_8033D4AC(((Vec*)(this_ + 0xc))->x, ((Vec*)(this_ + 0x248))->x, speed);
                }
                if (((Vec*)(this_ + 0xc))->y <= ((Vec*)(this_ + 0x24))->y + 11.5f && ((Vec*)(this_ + 0xc))->y >= ((Vec*)(this_ + 0x24))->y - 11.5f) {
                    ((Vec*)(this_ + 0xc))->y = ((Vec*)(this_ + 0x24))->y;
                } else {
                    ((Vec*)(this_ + 0xc))->y = fn_8033D4AC(((Vec*)(this_ + 0xc))->y, ((Vec*)(this_ + 0x248))->y, speed);
                }
            JGeometry::setTVec3f((f32*)((Vec*)(this_ + 0xc)), (f32*)((Vec*)(this_ + 0x248)));
            ((Vec*)(this_ + 0x3c))->x = 0.0f;
            ((Vec*)(this_ + 0x3c))->y = 0.0f;
            ((Vec*)(this_ + 0x3c))->z = 0.0f;
            if (*(u32*)(this_ + 0x230) != 0) {
                fn_801EE434(*(u32*)(this_ + 0x230));
                *(u32*)(this_ + 0x230) = 0;
            }
            *(s32*)(this_ + 0x254) = 8;
            JGeometry::setTVec3f((f32*)((Vec*)(this_ + 0xc)), (f32*)(this_ + 0x18));
            if (PSVECDistance(((Vec*)(this_ + 0xc)), ((Vec*)(this_ + 0x24))) >= 63.9) {
                ((Actor*)this_)->v10(0xff, 1);
                x = ((Vec*)(this_ + 0xc))->x;
                y = ((Vec*)(this_ + 0xc))->y;
                z = ((Vec*)(this_ + 0xc))->z;
                x -= 24.0f;
                for (i = 0; i < 4; i++) {
                    tmp.x = x;
                    tmp.y = y;
                    tmp.z = z;
                    const f32* offset = lbl_80475178;
                    for (j = 0; j < 4; j++, offset++) {
                        tmp.y = y + *offset;
                        fn_802A3948(lbl_8053AC98, &tmp, 0, *(u32*)(this_ + 4), 0);
                    }
                    x += 16.0f;
                }
                *(s32*)(this_ + 0x244) = 1;
                *(s32*)(this_ + 0x25c) = 50;
                *(s32*)(this_ + 0x260) = 0;
                if (*(u32*)(this_ + 0x230) == 0) {
                    *(u32*)(this_ + 0x230) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0x542, 0, 0, 0, 0, 1, 1.0f);
                    fn_8013CB44(*(u32*)(this_ + 0x230), ((Vec*)(this_ + 0xc)), -1, -1, 1);
                }
                if (*(u32*)(this_ + 0x234) == 0) {
                    *(u32*)(this_ + 0x234) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0xb7, 0, 0, 0, 0, 1, 1.0f);
                    fn_8013CB44(*(u32*)(this_ + 0x234), ((Vec*)(this_ + 0xc)), -1, -1, 1);
                }
                if (*(u32*)(this_ + 0x238) == 0) {
                    *(u32*)(this_ + 0x238) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0xb8, 0, 0, 0, 0, 1, 1.0f);
                    fn_8013CB44(*(u32*)(this_ + 0x238), ((Vec*)(this_ + 0xc)), 0, 0, 1);
                }
                if (*(u32*)(this_ + 0x23c) == 0) {
                    *(u32*)(this_ + 0x23c) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0xb9, 0, 0, 0, 0, 1, 1.0f);
                    fn_8013CB44(*(u32*)(this_ + 0x23c), ((Vec*)(this_ + 0xc)), 0, 0, 1);
                }
                if (*(u32*)(this_ + 0x240) == 0) {
                    *(u32*)(this_ + 0x240) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0xba, 0, 0, 0, 0, 1, 1.0f);
                    fn_8013CB44(*(u32*)(this_ + 0x240), ((Vec*)(this_ + 0xc)), 0, 0, 1);
                }
                fn_801F0E34(this_, 0x50065, 0);
                if (this_[0x265] == 0) {
                    fn_802D7584(fn_802D6A9C(), *(void**)(this_ + 0x16c), (u8)*(u32*)(this_ + 0x258));
                }
            }
            } else {
        JMathInlineVEC::PSVECAdd(((Vec*)(this_ + 0xc)), ((Vec*)(this_ + 0x3c)), ((Vec*)(this_ + 0xc)));
        if (*(s32*)(this_ + 0x254) > 0) {
            (*(s32*)(this_ + 0x254))--;
            break;
        }
        if (*(s32*)(this_ + 0x254) != 0) {
            break;
        }
        if (JMathInlineVEC::PSVECSquareMag(((Vec*)(this_ + 0x3c))) <= 32.0f * FLT_EPSILON) {
            if (fn_80239108(*(u32*)(this_ + 0x198)) < 4) {
                break;
            }
            if (!(PSVECDistance(((Vec*)(this_ + 0xc)), (Vec*)(this_ + 0x24)) < 63.9f)) {
                break;
            }
            if (*(s32*)(this_ + 0x260) < 10) {
                (*(s32*)(this_ + 0x260))++;
                break;
            }
            {
                u32 h = *(u32*)(this_ + 0x198);
                s32 idx = fn_80238BC4(h);
                s32 r4 = *(s32*)(this_ + 0x258);
                if (r4 == 0) {
                    *(s32*)(this_ + 0x258) = idx + 1;
                } else if (idx + 1 != r4) {
                    break;
                }
                if (idx < 0 || idx >= 4) {
                    break;
                }
                fn_80238E08(*(u32*)(this_ + 0x198));
                ((Vec*)(this_ + 0x3c))->x = lbl_80475148[idx].x;
                ((Vec*)(this_ + 0x3c))->y = lbl_80475148[idx].y;
                ((Vec*)(this_ + 0x3c))->z = lbl_80475148[idx].z;
                ((Vec*)(this_ + 0x248))->x = ((Vec*)(this_ + 0xc))->x;
                ((Vec*)(this_ + 0x248))->y = ((Vec*)(this_ + 0xc))->y;
                ((Vec*)(this_ + 0x248))->z = ((Vec*)(this_ + 0xc))->z;
                fn_801F0E34(this_, 0x30004, 0);
                JMathInlineVEC::PSVECAdd(((Vec*)(this_ + 0xc)), ((Vec*)(this_ + 0x3c)), ((Vec*)(this_ + 0xc)));
                if (idx == 0) {
                    *(u32*)(this_ + 0x230) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0x31a, 1, 1, 0, 0, 1, 1.0f);
                } else if (idx == 1) {
                    *(u32*)(this_ + 0x230) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0x31b, 1, 1, 0, 0, 1, 1.0f);
                } else if (idx == 2) {
                    *(u32*)(this_ + 0x230) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0x31c, 1, 1, 0, 0, 1, 1.0f);
                } else {
                    *(u32*)(this_ + 0x230) = fn_8013CC50(*(u32*)(this_ + 4), ((Vec*)(this_ + 0xc)), 0x319, 1, 1, 0, 0, 1, 1.0f);
                }
            }
        } else if (*(u32*)(this_ + 0x230) != 0) {
            fn_8013CB44(*(u32*)(this_ + 0x230), ((Vec*)(this_ + 0xc)), 0, 0, 1);
        }
            }
        }
        break;
    }
    case 1: {
        if (*(s32*)(this_ + 0x25c) != 0) {
            --*(s32*)(this_ + 0x25c);
            if (*(s32*)(this_ + 0x25c) == 0) fn_801F0D20(this_, 3);
        }
        for (s32 player = 0; player < 4; player++) {
            if (movingBlockContainsPlayerCached(this_, player, i)) fn_8022DF48(player);
        }
        break;
    }
    }
}

extern "C" int fn_8028D4DC(f32* this_, s32 a, void* c);
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_80475178[];
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
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
#include "JSystem/JAudio/JASFakeMatchFSA.h"
