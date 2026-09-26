// Game TU 801B6C50-801B7784 (GEWP). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" u8 fn_801B7550(void);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 idx);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119468(void* p, u32 a, u32 b);
extern "C" void fn_8023EE28(s32 idx);
extern u8 lbl_8053AC00;
extern const f32 lbl_8053EAE0;
extern const f32 lbl_8053EAE4;
extern const f32 lbl_8053EAE8;
extern const f32 lbl_8053EAEC;

extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A39DC[];
extern "C" {
}
extern void* lbl_8053AB10[2];

extern "C" void fn_801B6C50(void) {}

struct GewpReqTarget {
    u8 pad[0x10];
    f32 x10;
    u8 pad14[0x20 - 0x14];
    f32 x20;
    u8 pad24[0x7f4 - 0x24];
    u8 busy;
    u8 lock;
    u8 flag;
    u8 pad7f7;
    s32 id;
    bool request(s32 v) {
        bool ok = false;
        if (lock == 0) {
            ok = true;
            busy = 1;
            id = v;
            flag = 0;
        }
        return ok;
    }
};
struct GewpX20 { u8 pad[0x216]; u8 b216; };
struct GewpRoot {
    u8 pad[0x20];
    GewpX20* x20;
    GewpReqTarget* target;
    void request(s32 v) { target->request(v); }
};

class JPABaseEmitter;
class JPAEmitterManager {
public:
    void forceDeleteEmitter(JPABaseEmitter* e);
};
struct GewpEffMgr { u8 pad[0xc]; JPAEmitterManager* mgr; };

extern "C" void fn_80128C58(s32 a);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F68E0(void* reg);
extern "C" void* fn_801F6884(void* reg);
extern "C" JPABaseEmitter* fn_8013CC50(u32 room, JGeometry::TVec3<f32>* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" s32 fn_8022EA0C(s32 p);
extern "C" void fn_801F71A4(f32* p, f32 target, f32 a, f32 b);
extern "C" void fn_8022FE80(s32 a, u32 room, void* b, s32 c, s32 d);
extern "C" u8 fn_8038AD24(s32 a, u32 b, void* c, u32 d, JGeometry::TVec3<f32> pos, s32 flags);
extern "C" u8 fn_803865B8(s32 p);
extern "C" GewpEffMgr* fn_8013C824(void);
extern "C" s32 fn_8037EFB4(s32 p);
extern "C" void fn_80237524(s32 a, s32 b);
extern "C" void fn_80384C58(s32 a, void* b);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* p, s32 a, s32 b);
extern "C" void fn_802D6AAC(void* p, s32 a);
extern "C" void fn_802372F8(s32 i, s32 a, s32 b);
extern "C" void fn_80136798(void* obj, s32 id, s32 arg);
extern u8 lbl_8053AAA0;
extern u8 lbl_8053AB98;
extern u8 lbl_8053ABE8;
extern void* lbl_8053AAF8;
extern s32 lbl_804A39A0[];

struct Gewp {
    u8 pad0[4];
    u32 room;
    u8 pad8[0xc - 0x8];
    JGeometry::TVec3<f32> pos;
    u8 pad18[0x11c - 0x18];
    u8 b11c;
    u8 pad11d[0x198 - 0x11d];
    void* x198;
    u8 pad19c[0x230 - 0x19c];
    s32 state;
    s32 timers[3];
    u8 pad240[0x244 - 0x240];
    s32 x244;
    u8 pad248[0x24c - 0x248];
    s32 x24c;
    s32 x250;
    s32 x254;
    s32 x258;
    f32 x25c;
    f32 x260;
    JGeometry::TVec3<f32> ppos[4];
    JPABaseEmitter* eff[4];
};

#define GEWP_ROOT ((GewpRoot*)lbl_8053AB10[0])

// GEWP update (vtable slot 3)
extern "C" void fn_801B6C54(Gewp* p) {
    if (p->x24c == 0 && p->state != 0) {
        fn_80128C58((s32)p->x260);
    }
    switch (p->state) {
    case 0:
        if (p->timers[2] != 0) {
            lbl_8053AC00 = 0;
            break;
        }
        if (lbl_8053AC00 == 0) {
            break;
        }
        p->x25c = fn_801B7550();
        p->x260 = p->x25c;
        if (fn_801F68E0(fn_801F856C()) == 0) {
            break;
        }
        {
            GewpReqTarget* t = GEWP_ROOT->target;
            f32 x = -t->x10;
            f32 y = -t->x20;
            p->pos.x = x;
            p->pos.y = y;
            p->pos.z = 0.0f;
        }
        for (s32 i = 0; i < 4; i++) {
            fn_8013CC50(p->room, fn_8023E724(i), 0x3ae, 1, 1, 0, 0, 1, 1.0f);
            p->eff[i] = fn_8013CC50(p->room, fn_8023E724(i), 0x3ac, 1, 1, 0, 0, 1, 1.0f);
        }
        p->timers[1] = 120;
        p->state = 1;
    case 1:
        GEWP_ROOT->request(fn_8022EA0C(0));
        fn_801F71A4(&p->x260, 136.0f, 0.5f, 5.0f);
        if (p->timers[1] == 0) {
            JGeometry::TVec3<f32> v;
            v.x = v.y = v.z = 0.0f;
            v.y = -10.0f;
            fn_8022FE80(fn_8022EA0C(0), p->room, p->x198, 0, 0);
            u32 player = p->room;
            void* room = p->x198;
            if (fn_8038AD24(fn_8022EA0C(0), 0x240, room, player, v, 0x4102)) {
                p->state = 2;
            }
        }
        break;
    case 2:
        GEWP_ROOT->request(fn_8022EA0C(0));
        fn_8022FE80(fn_8022EA0C(0), p->room, p->x198, 0, 0);
        if (fn_803865B8(fn_8022EA0C(0))) {
            for (s32 i = 0; i < 4; i++) {
                if (p->eff[i] != 0) {
                    GewpEffMgr* m = fn_8013C824();
                    m->mgr->forceDeleteEmitter(p->eff[i]);
                    p->eff[i] = 0;
                }
            }
            switch (fn_8037EFB4(0)) {
            case 0:
                p->x244 = 0;
                fn_80237524(0, 0x180);
                lbl_8053AAA0 = 1;
                lbl_8053AB98 = 1;
                lbl_8053ABE8 = 1;
                for (s32 i = 0; i < 4; i++) {
                    JGeometry::TVec3<f32>* src = fn_8023E724(i);
                    p->ppos[i].x = src->x;
                    p->ppos[i].y = src->y;
                    p->ppos[i].z = src->z;
                }
                p->timers[0] = 8;
                p->x244 = 0x3f;
                for (s32 i = 0; i < 4; i++) {
                    fn_8013CC50(p->room, fn_8023E724(i), 0x489, 0, 0, 0, 0, 1, 1.0f);
                    fn_8013CC50(p->room, fn_8023E724(i), 0x551, 0, 0, 0, 0, 1, 1.0f);
                }
                p->timers[1] = 240;
                p->state = 4;
                break;
            case 1:
                for (s32 i = 0; i < 4; i++) {
                    fn_8013CC50(p->room, fn_8023E724(i), 0x48a, 1, 1, 0, 0, 1, 1.0f);
                }
                p->timers[1] = 100;
                p->state = 3;
                break;
            }
            fn_80384C58(fn_8022EA0C(0), p->x198);
        }
        break;
    case 3:
        GEWP_ROOT->request(fn_8022EA0C(0));
        if (p->timers[1] == 0) {
            fn_801F71A4(&p->x260, p->x25c, 0.5f, 5.0f);
            if ((f32)__fabs(p->x260 - p->x25c) < 1.0f) {
                p->x260 = p->x25c;
                fn_801F6884(fn_801F856C());
                lbl_8053AC00 = 0;
                p->timers[2] = 40;
                p->state = 0;
            }
        }
        break;
    case 4:
        GEWP_ROOT->request(fn_8022EA0C(0));
        fn_801F0E34(p, 0x3008e, 0);
        if (p->timers[1] == 0) {
            fn_802D9FF4(fn_802D6A9C(), p->x250, p->x254);
            fn_80119468(fn_80119DD0(), 0, 1);
            fn_802D6AAC(fn_802D6A9C(), 2);
            for (s32 i = 0; i < 4; i++) {
                fn_802372F8(i, lbl_804A39A0[p->x258], 1);
            }
            p->timers[0] = 5;
            p->state = 5;
            GEWP_ROOT->x20->b216 = 1;
        }
        break;
    case 5:
        GEWP_ROOT->request(fn_8022EA0C(0));
        if (p->timers[0] == 0) {
            fn_80136798(lbl_8053AAF8, 0xd, 0);
            p->b11c = 0;
        }
        GEWP_ROOT->x20->b216 = 1;
        break;
    case 6:
        GEWP_ROOT->x20->b216 = 1;
        p->state = 7;
        break;
    case 7:
        GEWP_ROOT->x20->b216 = 1;
        p->state = 8;
        fn_801F6884(fn_801F856C());
        p->b11c = 0;
        break;
    case 8:
        break;
    }
    for (s32 i = 0; i < 3; i++) {
        if (p->timers[i] > 0) {
            p->timers[i]--;
        }
    }
}

extern "C" void* fn_801B7324(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A39DC;
        char* p = (char*)this_;
        int i = 0;
        do {
            void* h = *(void**)(p + 0x294);
            fn_801EE434(h);
            i++;
            p += 4;
        } while (i < 4);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801B73B8(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053EAE0;
    *(f32*)(this_ + 0x64) = lbl_8053EAE0;
    *(f32*)(this_ + 0x68) = lbl_8053EAE4;
    *(f32*)(this_ + 0x6c) = lbl_8053EAE4;
    *(f32*)(this_ + 0x25c) = fn_801B7550();
    *(f32*)(this_ + 0x260) = *(f32*)(this_ + 0x25c);
    *(f32*)(this_ + 0x60) = lbl_8053EAE8;
    *(f32*)(this_ + 0x64) = lbl_8053EAE8;
    *(f32*)(this_ + 0x68) = lbl_8053EAEC;
    *(f32*)(this_ + 0x6c) = lbl_8053EAEC;
    *(f32*)(this_ + 0x80) = lbl_8053EAE8;
    *(f32*)(this_ + 0x84) = lbl_8053EAE8;
    *(f32*)(this_ + 0x88) = lbl_8053EAEC;
    *(f32*)(this_ + 0x8c) = lbl_8053EAEC;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    s32 i;
    for (s32 i = 0; i < 4; i++) {
        f32* p = (f32*)fn_8023E724(i);
        f32* d = (f32*)(this_ + i * 0xc + 0x264);
        d[0] = p[0];
        d[1] = p[1];
        d[2] = p[2];
    }
    *(s32*)(this_ + 0x250) = *(u32*)(this_ + 0x90) & 0xf;
    *(s32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(s32*)(this_ + 0x24c) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    if (*(s32*)(this_ + 0x258) > 10) {
        *(s32*)(this_ + 0x258) = 0;
    }
    lbl_8053AC00 = 0;
    *(s32*)(this_ + 0x294) = 0;
    *(s32*)(this_ + 0x298) = 0;
    *(s32*)(this_ + 0x29c) = 0;
    *(s32*)(this_ + 0x2a0) = 0;
    if (*(s32*)(this_ + 0x24c) == 0) {
        *(s32*)(this_ + 0x230) = 0;
    } else {
        fn_80119468(fn_80119DD0(), 0, 0);
        for (s32 i = 0; i < 4; i++) {
            fn_8023EE28(i);
        }
        *(s32*)(this_ + 0x230) = 6;
    }
}

extern "C" u8 fn_801B7550(void) {
	void* p1 = lbl_8053AB10[0];
	void* p2 = *(void**)((char*)p1 + 0x2c);
	return *(u8*)((char*)p2 + 0xc);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
