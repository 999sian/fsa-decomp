#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "Game/Actor.h"

static inline f32 abRandom(char* game, u32 multiplier) {
    *(u32*)(game + 0xb4) = *(u32*)(game + 0xb4) * multiplier + 0x3c6ef35f;
    union { u32 u; f32 f; } value;
    value.u = (*(u32*)(game + 0xb4) >> 9) | 0x3f800000;
    return value.f - 1.0f;
}


extern "C" void __dt__5ActorFv(void*, s16);
extern char lbl_804A81C8[];
extern f32 lbl_805408B0;
extern f32 lbl_80540898;
struct TileSwitchActor : Actor {
    s32 state;
    s32 kind;
    s32 timer;
    s32 index;
    u16 tile;
};

struct Obj802AB9DC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual bool check();
};

extern "C" void* fn_802AB1D4(void* p, s16 d) {
    if (p != NULL) {
        *(char**)p = lbl_804A81C8;
        __dt__5ActorFv(p, 0);
        if (d > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802AB234(void) {}

extern "C" s32 fn_8023AF14(f32* rect, s32 room, s32 zero, f32 z = 0.0f);
extern "C" void* fn_802D6A9C(void);
extern "C" unsigned int fn_802F9908(void* mgr, int room, int word);
extern "C" void fn_802F9974(void* mgr, s32 room, s32 word, u16 val);
extern "C" u8 fn_80234F68(void);
extern "C" void fn_802A3884(void* a, f32* pos, s32 zero, s32 room, s32 id);
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F35AC(void* a);
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern char* lbl_8053AB10;
extern char* lbl_8053AAF8;
extern char* lbl_8053AC98;
extern f32 lbl_80540890;
extern f32 lbl_80540894;
extern f32 lbl_8054089C;
extern f32 lbl_805408A0;
extern f32 lbl_805408A4;
extern f32 lbl_805408A8;
extern f32 lbl_805408AC;
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_802AB238(TileSwitchActor* actor) {
    char* self = (char*)actor;
    JGeometry::TBox2<f32> rect;
    f32 c = 4.0f;
    JGeometry::TVec2<f32> offset(c + actor->field_0C.x, c + actor->field_0C.y);
    rect.set(*(JGeometry::TBox2<f32>*)(self + 0x60));
    rect.addPos(offset);
    int r = fn_8023AF14((f32*)&rect, actor->field_04, 0, lbl_80540894);
    switch (actor->state) {
    case 0: {
        s32 room = actor->field_04;
        char* mgr = (char*)fn_802D6A9C();
        f32* origin;
        if (room < 8) origin = (f32*)(mgr + 0xcc);
        else origin = (f32*)(mgr + 0xdc);
        s32 x = (s32)(actor->field_0C.x - origin[0]);
        s32 y = (s32)(actor->field_0C.y - origin[1]);
        if (x < 0) x = 0; else if (x >= 512) x = 511;
        if (y < 0) y = 0; else if (y >= 512) y = 511;
        actor->index = ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf);
        actor->tile = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), actor->field_04, actor->index) & 0x3ff;
        actor->state = 1;
        break;
    }
    case 1: {
        const unsigned int& current = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), actor->field_04, actor->index) & 0x3ff;
        if ((unsigned int)actor->tile == current) break;
        switch (actor->kind) {
        case 5:
            ((Actor*)self)->v10(0xff, 1);
        case 0:
        case 10:
            Actor_CreateByID(fn_801F856C(), 0x474f4c44, actor->field_04, self + 0xc, 0x30000, -1, -1);
            if (actor->kind == 10) self[0x11c] = 0;
            else fn_801F35AC(self);
            break;
        case 1:
            actor->timer = 100;
            actor->state = 2;
            break;
        case 2:
            actor->state = 2;
            break;
        case 3:
            ((Actor*)self)->v10(0xff, 1);
            self[0x11c] = 0;
            break;
        case 4:
        case 11:
            actor->timer = 300;
            actor->state = 2;
            break;
        case 6: {
            if (abRandom(lbl_8053AAF8, 0x19660d) < 0.2f) {
                bool spawned = false;
                if (abRandom(lbl_8053AAF8, 0x19660d) < 0.8f) {
                    s32 id = Actor_CreateByID(fn_801F856C(), 0x52555059, actor->field_04, self + 0xc, 0, -1, -1);
                    char* child = (char*)fn_801F666C(fn_801F856C(), id);
                    if (child) {
                        JGeometry::TVec3<f32> vel(0.0f, 0.0f, 3.0f);
                        *(JGeometry::TVec3<f32>*)(child + 0x3c) = vel;
                    }
                } else {
                    if (abRandom(lbl_8053AAF8, 0x19660d) < 0.5f) {
                        Actor_CreateByID(fn_801F856C(), 0x4d54424f, actor->field_04, self + 0xc, 0, -1, -1);
                        spawned = true;
                    }
                    if (!spawned) {
                        if (abRandom(lbl_8053AAF8, 0x19660d) < 0.2f)
                            Actor_CreateByID(fn_801F856C(), 0x46415259, actor->field_04, self + 0xc, 0, -1, -1);
                        else
                            Actor_CreateByID(fn_801F856C(), 0x48415254, actor->field_04, self + 0xc, 0, -1, -1);
                    }
                }
            }
            fn_801F35AC(self);
            break;
        }
        case 7:
            Actor_CreateByID(fn_801F856C(), 0x48415254, actor->field_04, self + 0xc, 0, -1, -1);
            self[0x11c] = 0;
            break;
        case 8:
            Actor_CreateByID(fn_801F856C(), 0x4d54424f, actor->field_04, self + 0xc, 0, -1, -1);
            fn_801F35AC(self);
            break;
        case 9:
            Actor_CreateByID(fn_801F856C(), 0x46415259, actor->field_04, self + 0xc, 0, -1, -1);
            fn_801F35AC(self);
            break;
        default:
            fn_801F35AC(self);
            break;
        }
        break;
    }
    case 2:
        switch (actor->kind) {
        case 1:
            actor->timer -= 1;
            if (actor->timer == 0) {
                void* manager = *(void**)(lbl_8053AB10 + 0x20);
                u32 tile = actor->tile;
                fn_802F9974(manager, actor->field_04, actor->index, tile);
                actor->state = 1;
            }
            break;
        case 2:
            if (r >= 0 && fn_80234F68() == 1) {
                actor->timer = 60;
                actor->state = 3;
            }
            break;
        case 4:
        case 11:
            actor->timer -= 1;
            if (actor->timer == 0) {
                if (r < 0) {
                    if (*(s32*)(self + 4) >= 8) {
                        JGeometry::TVec3<f32> pos(8.0f + actor->field_0C.x, 8.0f + actor->field_0C.y, 0.0f);
                        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, actor->field_04, &pos, 3, -1, -1);
                    } else {
                        JGeometry::TVec3<f32> pos(8.0f + actor->field_0C.x, 8.0f + actor->field_0C.y, 0.0f);
                        fn_8013CC50(actor->field_04, &pos, 1.0f, 0x503, 1, 0, 0, 0, 1);
                    }
                    if (actor->kind == 4)
                        fn_802A3884(lbl_8053AC98, (f32*)(self + 0xc), 0, actor->field_04, 0x4f);
                    else
                        fn_802A3884(lbl_8053AC98, (f32*)(self + 0xc), 0, actor->field_04, 0x4e);
                    actor->state = 1;
                } else actor->timer = 1;
            }
            break;
        default:
            fn_801F35AC(self);
            break;
        }
        break;
    case 3:
        switch (actor->kind) {
        case 2:
            actor->timer -= 1;
            if (actor->timer == 0) {
                void* manager = *(void**)(lbl_8053AB10 + 0x20);
                u32 tile = actor->tile;
                fn_802F9974(manager, actor->field_04, actor->index, tile);
                actor->state = 1;
            }
            break;
        default:
            fn_801F35AC(self);
            break;
        }
        break;
    case 4:
        switch (actor->kind) {
        case 5:
            ((Actor*)self)->v10(0xff, 1);
            break;
        case 3:
            ((Actor*)self)->v10(0xff, 1);
            break;
        default: break;
        }
        self[0x11c] = 0;
        break;
    }
}

extern "C" void fn_802AB9DC(Obj802AB9DC* obj) {
    char* self = (char*)obj;
    *(u32*)(self + 0x234) = *(u32*)(self + 0x90) & 0x1f;
    *(f32*)(self + 0x60) = -1.0f;
    *(f32*)(self + 0x64) = -1.0f;
    *(f32*)(self + 0x68) = 1.0f;
    *(f32*)(self + 0x6c) = 1.0f;
    *(u32*)(self + 0x230) = 0;
    if (obj->check()) {
        *(u32*)(self + 0x230) = 4;
    }
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/Actor.h"
