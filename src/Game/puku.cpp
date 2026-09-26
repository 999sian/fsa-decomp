// PUKU actor. TU 8017B140-8017C01C.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), tile check, init (slot 1).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "std/math.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" u16 fn_8022461C(void* pos);
extern void* lbl_804A11B8[];

struct PukuRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct PukuGame { u8 pad[0xb4]; PukuRandom rnd; };
extern PukuGame* lbl_8053AAF8;

// PUKU destructor
extern "C" void* fn_8017B140(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A11B8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct PukuResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
struct PukuGameRes { u8 pad[0xa4]; PukuResMgr* res; };
extern "C" void fn_802F86CC(void* layer, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* rec);
extern "C" void fn_803075AC(void* a, s32 room, void* pos, s32 id, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern u8* lbl_8053AB10;
extern const char lbl_804668A8[];

// PUKU draw (vtable slot 6)
extern "C" void fn_8017B1A0(char* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    s32 scaled = 0;
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    if (*(s32*)(this_ + 0x258) == 1) {
        scaled = 1;
        mtx[0][0] = 2.0f;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = 2.0f;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = 2.0f;
        rec.w18 = mtx;
    }
    s32 id = *(s32*)(this_ + 0x250) + 0x143;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = ((PukuGameRes*)lbl_8053AAF8)->res->get('SOB ', lbl_804668A8);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, 1.0f, 1.0f, &rec);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                *(s32*)(this_ + 0x250) + 0x143, scaled != 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_801F71A4(f32* p, f32 target, f32 a, f32 b);
extern "C" u8 fn_801F2618(void* this_, JGeometry::TVec3<f32>* out, s32 b);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, s32 c);
extern "C" u8 fn_801F6758(JGeometry::TVec3<f32>* pos, u32 room, f32 r);
extern "C" void fn_801EEC98(void* this_, void* room, s16* a, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);

struct Puku {
    u8 pad0[4];
    u32 room;
    u8 pad8[0xc - 0x8];
    JGeometry::TVec3<f32> pos;
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3<f32> vel;
    u8 pad48[0x98 - 0x48];
    s32 dir;
    u8 pad9c[0x114 - 0x9c];
    u32 x114;
    u8 pad118[0x198 - 0x118];
    void* x198;
    u8 pad19c[0x230 - 0x19c];
    s32 state;
    s32 timers[4];
    s32 anim;
    u8 pad248[0x250 - 0x248];
    s32 frame;
    u8 pad254[0x258 - 0x254];
    s32 big;
    s16 phase;
    u8 pad25e[2];
    f32 range;
    JGeometry::TVec3<f32> target;
    JGeometry::TVec3<f32> home;
};

static inline void pukuStop(Puku* p) {
    p->target.x = p->target.y = p->target.z = 0.0f;
    p->vel.x = p->vel.y = p->vel.z = 0.0f;
}

// PUKU update (vtable slot 3)
extern "C" void fn_8017B3B4(Puku* p) {
    f32 dist = 0.0f;
    s32 player = -1;
    s32 dir;
    u8 far = 0;
    fn_801F71A4(&p->vel.x, p->target.x, 0.1f, 0.1f);
    fn_801F71A4(&p->vel.y, p->target.y, 0.1f, 0.1f);
    p->pos += p->vel;
    JGeometry::TVec3<f32> push;
    push.x = push.y = push.z = 0.0f;
    u8 blocked = fn_801F2618(p, &push, 0);
    if (p->big == 1 && push.y) {
        blocked = 0;
    }
    if (fn_801F2B7C(p, p->x114, -1, 1) && p->big == 1 && p->state == 3) {
        far = 1;
    }
    switch (p->state) {
    case 0:
        if (p->big == 1) {
            switch (p->dir) {
            case 0:
                p->target.x = 0.9f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            case 1:
                p->target.x = -0.9f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            }
        } else {
            switch (p->dir) {
            case 0:
                p->target.x = 0.4f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            case 1:
                p->target.x = -0.4f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            }
        }
        p->state = 1;
    case 1:
        p->target.y = 0.3f * JMASinShort(p->phase);
        if ((f32)__fabs(p->home.x - p->pos.x) > 96.0f + 16.0f * lbl_8053AAF8->rnd.get_ufloat_1()) {
            far = 1;
        }
        p->phase += 300;
        if (p->timers[1] == 0 || blocked) {
            if (blocked || fn_801F6758(&p->pos, p->room, 16.0f) || far == 1) {
                s32 old = p->dir;
                p->dir = 0;
                if (p->home.x < p->pos.x) {
                    p->dir = 1;
                }
                if (old != p->dir) {
                    pukuStop(p);
                }
                p->timers[1] = 20;
                p->state = 0;
            }
        }
        if (p->timers[2] == 0) {
            fn_801EEC98(p, p->x198, 0, &dir, &dist, &player, 0, 0);
            if (player >= 0 && p->dir == dir) {
                if (p->big == 0) {
                    if (dist < 96.0f && (f32)__fabs(fn_8023E724(player)->y - p->pos.y) < 32.0f) {
                        p->state = 2;
                    }
                } else {
                    if (dist < 128.0f && (f32)__fabs(fn_8023E724(player)->y - p->pos.y) < 32.0f) {
                        p->state = 2;
                    }
                }
            }
        }
        break;
    case 2:
        pukuStop(p);
        if (p->big == 1) {
            switch (p->dir) {
            case 0:
                p->target.x = 1.7f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            case 1:
                p->target.x = -1.7f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            }
        } else {
            switch (p->dir) {
            case 0:
                p->target.x = 0.9f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            case 1:
                p->target.x = -0.9f;
                p->target.y = 0.0f;
                p->target.z = 0.0f;
                break;
            }
        }
        p->timers[2] = 0;
        p->timers[1] = 350;
        p->state = 3;
    case 3: {
        p->target.y = 0.2f * JMASinShort(p->phase);
        f32 r = 16.0f;
        p->phase += 300;
        if (p->big == 1) {
            r = -24.0f;
            blocked = far;
        }
        if (blocked || fn_801F6758(&p->pos, p->room, r) || p->timers[1] == 0) {
            p->dir ^= 1;
            pukuStop(p);
            p->timers[2] = 160;
            p->timers[1] = 20;
            p->state = 0;
        }
        break;
    }
    case 4:
        switch (p->dir) {
        case 0:
            p->target.x = 0.4f;
            p->target.y = 0.0f;
            p->target.z = 0.0f;
            break;
        case 1:
            p->target.x = -0.4f;
            p->target.y = 0.0f;
            p->target.z = 0.0f;
            break;
        case 2:
            p->target.x = 0.0f;
            p->target.y = 0.4f;
            p->target.z = 0.0f;
            break;
        case 3:
            p->target.x = 0.0f;
            p->target.y = -0.4f;
            p->target.z = 0.0f;
            break;
        }
        p->timers[1] = 10;
        p->state = 5;
        break;
    case 5: {
        f32 dx = p->home.x - p->pos.x;
        f32 dy = p->home.y - p->pos.y;
        if (p->timers[1] == 0) {
            if (blocked || std::sqrtf(dx * dx + dy * dy) > p->range) {
                p->dir ^= 1;
                pukuStop(p);
                p->state = 4;
            }
        }
        break;
    }
    }
    if (p->timers[0] == 0) {
        p->timers[0] = 8;
        if (p->state == 3) {
            p->timers[0] = 4;
        }
        p->anim++;
        p->anim &= 1;
        p->frame = ((p->dir & 1) << 1) + p->anim;
    }
    if (p->timers[0] > 0) {
        p->timers[0]--;
    }
    if (p->timers[1] > 0) {
        p->timers[1]--;
    }
    if (p->timers[2] > 0) {
        p->timers[2]--;
    }
    if (p->timers[3] > 0) {
        p->timers[3]--;
    }
}

// PUKU: can it move onto the tile at pos? (tile types 0x3b, 0, 2, 3 block)
extern "C" BOOL fn_8017BBA8(void* this_, void* arg1, void* pos) {
    s32 t = (u16)fn_8022461C(pos);
    BOOL ret;
    if (t != 0x3b && t != 0 && t != 2 && t != 3) {
        ret = TRUE;
    } else {
        ret = FALSE;
    }
    return ret;
}

// PUKU init (vtable slot 1)
static inline f32 puku_zero() { return 0.0f; }
extern "C" void fn_8017BBFC(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(u32*)(this_ + 0x258) = *(u32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s16*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x260) = 8.0f * (f32)((*(u32*)(this_ + 0x90) >> 8) & 0xff);
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x270) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x98) = (s32)(1.99f * lbl_8053AAF8->rnd.get_ufloat_1());
    if (*(s32*)(this_ + 0x258) == 1) {
        PukuGame* g = lbl_8053AAF8;
        *(s32*)(this_ + 0x254) = (s32)(1.99f * g->rnd.get_ufloat_1());
        *(s32*)(this_ + 0x114) = 4;
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 16.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        *(f32*)(this_ + 0x80) = -16.0f;
        *(f32*)(this_ + 0x84) = -10.0f;
        *(f32*)(this_ + 0x88) = 16.0f;
        *(f32*)(this_ + 0x8c) = 10.0f;
    }
    *(s32*)(this_ + 0x230) = 0;
    if ((*(u32*)(this_ + 0x90) >> 4) & 0xff) {
        if (*(f32*)(this_ + 0x260) == puku_zero()) {
            *(f32*)(this_ + 0x260) = 16.0f;
        }
        *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
        *(s32*)(this_ + 0x98) = *(s32*)(this_ + 0x98) - 1;
        *(u32*)(this_ + 0x98) = *(u32*)(this_ + 0x98) & 3;
        *(s32*)(this_ + 0x230) = 4;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
