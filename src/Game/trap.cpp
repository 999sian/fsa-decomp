// TRAP actor. TU 801643C4-8016545C.
// Functions: dtor, move check (TODO), draw (slot 6, TODO), update (slot 3, TODO), init (slot 1).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "std/math.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A04D8[];

struct TrapRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
class TrapResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
struct TrapGame { u8 pad[0xa4]; TrapResMgr* res; u8 padA8[0xb4 - 0xa8]; TrapRandom rnd; };
extern TrapGame* lbl_8053AAF8;

// TRAP destructor
extern "C" void* fn_801643C4(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A04D8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, u32 id, const void* ext);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u8* fn_802D6A9C(void);
extern const char lbl_804662A8[];

// TRAP move check: can the trap move onto pos?
extern "C" u8 fn_80164424(char* this_, s32 room, void* pos) {
    u32 id = *(u32*)(this_ + 0x198);
    u8* mgr = fn_8020D58C();
    if (fn_8020D6AC(mgr + 4 + mgr[1] * 0x784, room, pos, id, lbl_804662A8) == 1) {
        return 1;
    }
    if (*(s32*)(this_ + 0x24C) == 0) {
        s32 kind = fn_8022461C(pos, room);
        if (kind != 0 && kind != 4 && kind != 5 && kind != 6 && kind != 7 && kind != 2 && kind != 3 && kind != 0x50 && kind != 0xE && kind != 0xC && kind != 0x27 && kind != 0x28 && kind != 0x29 && kind != 0x2A && kind != 0x2B && kind != 0x2C && kind != 0x2D && kind != 0x2E && kind != 0x2F && kind != 0x20 && kind != 0xD && kind != 0x39 && kind != 0x3A && kind != 0x3B && kind != 0x4C && kind != 0x4D && kind != 0x4E && kind != 0x4F && kind != 0x24) {
            if ((u32)(kind - 0x10) <= 2 || kind == 0x13) {
                *(s32*)(this_ + 0x24C) = 0x78;
                return 0;
            }
            if (kind == 0x25) {
                return fn_802D6A9C()[0x171] == 0;
            }
            if (kind == 0x26) {
                return fn_802D6A9C()[0x171] == 1;
            }
            if (kind != 0x22 || fn_802D6A9C()[0x170] == 1) {
                return 1;
            }
        }
    } else {
        *(s32*)(this_ + 0x24C) = *(s32*)(this_ + 0x24C) - 1;
    }
    return 0;
}

extern u8* lbl_8053AB10;
extern const char lbl_804662BC[];
extern const char lbl_804662D0[];
extern "C" void fn_802F86CC(void* p, void* pos, void* res, s32 id, DrawRec* rec, f32 a, f32 b);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);

// TRAP draw (vtable slot 6)
extern "C" void fn_80164640(char* this_) {
    DrawRec rec;
    s32 flag = 0;
    if (*(s32*)(this_ + 0x254) != 0) {
        flag = 1;
    }
    if (*(s32*)(this_ + 0x258) == 0) {
        if (*(s32*)(this_ + 4) < 8) {
            void* res = lbl_8053AAF8->res->vf18('SOB ', lbl_804662BC);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xC, res, 0x154, &rec, 1.0f, 1.0f);
        }
        fn_801F02BC(this_, lbl_804662BC, 0x154, &rec, 0, flag, 0, 1.0f, 1.0f);
    } else {
        fn_801F02BC(this_, lbl_804662D0, *(s32*)(this_ + 0x260) + 0x17A, &rec, 0, flag, 0, 1.0f, 1.0f);
    }
}

extern "C" s32 fn_801F285C(char* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" u8 fn_80237948(s32 r, f32* p);
extern "C" void fn_8013CC50(void* snd, void* pos, f32 vol, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void fn_801F0E34(char* this_, s32 anim, s32 flag);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern "C" void fn_801F2B7C(char* this_, s32 a, s32 b, s32 c);
extern "C" u8 fn_801F2618(char* this_, s32 a, s32 b);
extern "C" void fn_801EEC98(char* this_, void* a, s32 b, void* c, s32 d, void* e, s32 f, s32 g);
extern f32 lbl_8053D77C;
extern f32 lbl_8053D778;
extern f32 lbl_8053D780;
struct TrapRoomRect { f32 x, y, x1, y1; };

struct TrapActor : Actor {
    s32 state;
    s32 timers[3];
    s32 a240, a244, a248, a24C, a250, a254, a258, a25C, anim;
    u8 aim;
    u8 pad265[3];
    JGeometry::TVec3<f32> target;
    JGeometry::TVec3<f32> home;
};

static inline void trapGetCenter(const JGeometry::TBox2f* box, JGeometry::TVec2<f32>* point) {
    point->x = lbl_8053D77C * (box->i.x - box->f.x) + box->f.x;
    point->y = lbl_8053D77C * (box->i.y - box->f.y) + box->f.y;
}

static inline void trapSetTarget(TrapActor* p) {
    switch ((s32)p->field_98) {
    case 0: p->target.set(3.0f, 0.0f, 0.0f); break;
    case 1: p->target.set(-3.0f, 0.0f, 0.0f); break;
    case 2: p->target.set(0.0f, 3.0f, 0.0f); break;
    case 3: p->target.set(0.0f, -3.0f, 0.0f); break;
    }
}
static inline void trapStop(TrapActor* p) {
    p->target.set(0.0f, 0.0f, 0.0f);
    p->field_3C.x = 0.0f;
    p->field_3C.y = 0.0f;
    p->field_3C.z = 0.0f;
}
extern "C" s32 fn_8023DE58(s32);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32);
extern const JGeometry::TVec2<f32> lbl_80466288[];
extern "C" void fn_80164834(char* this_) {
    s32 i;
    TrapActor* p = (TrapActor*)this_;
    JGeometry::TVec3<f32> vel(p->field_3C);
    JGeometry::TVec3<f32> oldPos(p->field_0C);
    p->field_108 = 1000;
    i = 0;
    for (; i < 4; ++i) {
        s32 hit = fn_801F285C(this_, 0, 0, 0, i);
        if (hit < 0) break;
        JGeometry::TVec3<f32> pos(p->field_0C);
        JGeometry::TVec2<f32> point;
        JGeometry::TBox2f box;
        box.set(*(JGeometry::TBox2f*)&p->field_60);
        box.addPos(pos.x, pos.y);
        point.set(lbl_8053D77C * (box.i.x - box.f.x) + box.f.x,
                  lbl_8053D77C * (box.i.y - box.f.y) + box.f.y);
        if (fn_80237948(hit, &point.x)) {
            fn_8013CC50((void*)p->field_04, &p->field_0C, 1.0f, 0x117, 0, 1, 0, 0, 1);
            fn_8013CC50((void*)p->field_04, &p->field_0C, 1.0f, 0x118, 0, 1, 0, 0, 1);
            fn_801F0E34(this_, 0x400d1, 0);
        }
        const volatile f32* saved = &vel.x;
        f32 vx = saved[0];
        f32 vy = saved[1];
        p->field_3C.x = vx;
        f32 vz = saved[2];
        p->field_3C.y = vy;
        p->field_3C.z = vz;
    }
    fn_801F71A4(&p->field_3C.x, p->target.x, 0.3f, 1.0f);
    fn_801F71A4(&p->field_3C.y, p->target.y, 0.3f, 1.0f);
    (*(JGeometry::TVec3<f32>*)&p->field_0C) += *(JGeometry::TVec3<f32>*)&p->field_3C;
    fn_801F2B7C(this_, -100, -1, 1);
    if (p->a258 != 0 && p->timers[1] == 0) {
        p->anim++;
        p->anim &= 3;
        p->timers[1] = 10;
    }
    u8 blocked = fn_801F2618(this_, 0, 0);
    s32 player = -1;
    s32 dir;
    fn_801EEC98(this_, (void*)p->field_198, 0, &dir, 0, &player, 0, 0);
    s32 state = p->state;
    if (state != 2 && state != 3 && state != 0 &&
        (p->field_9C >= 0 || (state == 1 && blocked))) {
        JGeometry::TVec3<f32> pos(p->field_0C);
        pos.x += lbl_80466288[p->field_98].x;
        pos.y += lbl_80466288[p->field_98].y;
        if (p->timers[2] == 0) {
            fn_8013CC50((void*)p->field_04, &pos, 1.0f, 0x4a1, 0, 1, 0, 0, 1);
            fn_801F0E34(this_, 0x30014, 0);
            p->timers[2] = 4;
        }
        trapStop(p);
        p->state = 2;
        return;
    }
    switch (state) {
    case 0:
        if (p->timers[0] == 0 && player >= 0) {
            f32 dx, dy;
            if (fn_8023DE58(player) < 8 && (s32)p->field_04 == 8) {
                s32 room = fn_8023DE58(player);
                u8* mgr = fn_802D6A9C();
                TrapRoomRect box = *(TrapRoomRect*)(room < 8 ? mgr + 0xcc : mgr + 0xdc);
                dx = (f32)fabs(p->field_0C.x - (fn_8023E724(player)->x - box.x));
                dy = (f32)fabs(p->field_0C.y - (fn_8023E724(player)->y - box.y));
            } else {
                dx = (f32)fabs(p->field_0C.x - fn_8023E724(player)->x);
                dy = (f32)fabs(p->field_0C.y - fn_8023E724(player)->y);
            }
            if (p->aim == 1) {
                if (((dir & 2) == 0 && dy < 22.0f) || ((dir & 2) != 0 && dx < 22.0f))
                    p->field_98 = dir;
            }
            s32 d = p->field_98;
            if (((d & 2) == 0 && dy < 22.0f) || ((d & 2) != 0 && dx < 22.0f)) {
                trapSetTarget(p);
                fn_801F0E34(this_, 0x30013, 0);
                p->state = 1;
            }
        }
        break;
    case 2:
        if (!blocked) {
            fn_801F71A4(&p->field_0C.x, p->home.x, 0.3f, 0.5f);
            fn_801F71A4(&p->field_0C.y, p->home.y, 0.3f, 0.5f);
            f32 dy = p->field_0C.y - p->home.y;
            f32 dx = p->field_0C.x - p->home.x;
            if (std::sqrtf(dx*dx + dy*dy) < 1.0f || blocked) {
                p->timers[0] = 10;
                if (blocked) p->home.set(*(JGeometry::TVec3<f32>*)&p->field_0C);
                p->field_0C.x = p->home.x;
                p->field_0C.y = p->home.y;
                p->field_0C.z = p->home.z;
                p->state = 0;
            }
        }
        break;
    case 3:
        if (p->field_9C >= 0 || blocked) {
            JGeometry::TVec3<f32> pos(p->field_0C);
            pos.x += lbl_80466288[p->field_98].x;
            pos.y += lbl_80466288[p->field_98].y;
            if (p->timers[2] == 0) {
                fn_8013CC50((void*)p->field_04, &pos, 1.0f, 0x4a1, 0, 1, 0, 0, 1);
                fn_801F0E34(this_, 0x30014, 0);
                p->timers[2] = 4;
            }
            p->field_98 ^= 1;
            p->field_3C.x = 0.0f;
            p->field_3C.y = 0.0f;
            p->field_3C.z = 0.0f;
        }
        trapSetTarget(p);
        break;
    }
    if (p->timers[0] > 0) --p->timers[0];
    if (p->timers[1] > 0) --p->timers[1];
    if (p->timers[2] > 0) --p->timers[2];
}

// TRAP init (vtable slot 1)
extern "C" void fn_801650AC(char* this_) {
    *(f32*)(this_ + 0x60) = -6.0f;
    *(f32*)(this_ + 0x64) = -6.0f;
    *(f32*)(this_ + 0x68) = 6.0f;
    *(f32*)(this_ + 0x6c) = 6.0f;
    *(f32*)(this_ + 0x80) = -3.0f;
    *(f32*)(this_ + 0x84) = -3.0f;
    *(f32*)(this_ + 0x88) = 3.0f;
    *(f32*)(this_ + 0x8c) = 3.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(u32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    if (*(s32*)(this_ + 0x254) != 0) {
        *(f32*)(this_ + 0x60) = -12.0f;
        *(f32*)(this_ + 0x64) = -12.0f;
        *(f32*)(this_ + 0x68) = 12.0f;
        *(f32*)(this_ + 0x6c) = 12.0f;
    }
    *(u32*)(this_ + 0x98) = *(u32*)(this_ + 0x90) & 3;
    *(u32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    *(s32*)(this_ + 0x260) = 0;
    if (*(s32*)(this_ + 0x258) != 0) {
        *(s32*)(this_ + 0x260) = (s32)(3.0f * lbl_8053AAF8->rnd.get_ufloat_1());
    }
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x27c) = *(f32*)(this_ + 0x14);
    *(u8*)(this_ + 0x264) = 0;
    if (*(u32*)(this_ + 0x90) & 4) {
        *(u8*)(this_ + 0x264) = 1;
    }
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0x230) = 0;
    if (*(s32*)(this_ + 0x25c) != 0) {
        *(s32*)(this_ + 0x230) = 3;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
