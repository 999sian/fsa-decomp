// TU 0x803d6434-0x803d7098 (actor BFIN).
// The dtor and init bodies were adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0380[];

struct BfinReqTarget {
    u8 pad[0x7f4];
    u8 busy;
    u8 lock;
    u8 flag;
    u8 pad7f7;
    s32 id;
    bool request(s32 v) {
        if (lock != 0) {
            return false;
        }
        busy = 1;
        id = v;
        flag = 0;
        return true;
    }
};
struct BfinRoot {
    u8 pad[0x24];
    BfinReqTarget* target;
    BfinReqTarget* getTarget() { return target; }
    void request(s32 v) {
        getTarget()->request(v);
    }
};
extern BfinRoot* lbl_8053AB10;

struct BfinRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct BfinGame {
    u8 pad[0x82];
    u8 players;
    u8 pad83[0xb4 - 0x83];
    BfinRandom rnd;
};
extern BfinGame* lbl_8053AAF8;

struct BfinShared {
    u8 pad[0x64];
    s32 winner;
    u8 pad68[0x140 - 0x68];
    s32 wins[0x1a];
    s32 x1a8;
    u8 pad1ac[0x240 - 0x1ac];
    u8 x240;
    u8 pad241[2];
    u8 mask;
};
extern "C" BfinShared lbl_80529DEC;

struct BfinFlags {
    u8 pad[0xdc];
    u8 flags;
    u8 padDD[0x256 - 0xdd];
    u8 x256;
};
extern BfinFlags* lbl_8053AED0;
struct BfinE4 { u8 pad[0xe4]; u8 xe4; };
extern BfinE4* lbl_8053AD78;
struct BfinADC8 { u8 pad[0x20]; u8 a; u8 b; };
extern BfinADC8* lbl_8053ADC8;
extern void* lbl_8053AF80;
extern void* lbl_8053AD30;

extern "C" u32 fn_80309C4C(void* pad, s32 mask, s32 a);
extern "C" void fn_801367E0(void* game, s32 a);
extern "C" void fn_801365C8(void* game, s32 a);
extern "C" void fn_80458880(void* obj, s32 id, s32 a);
extern "C" void fn_80458FF0(void* obj, s32 id, s32 a, s32 b);
extern "C" void fn_80458F9C(void* obj, s32 a);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" void fn_80230498(s32 i, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230FD0(s32 i, s32 a);
extern "C" void* fn_8013CC50(u32 room, JGeometry::TVec3<f32>* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" u8 fn_80236B50(s32 i);
extern "C" u8 fn_802300EC(s32 i);
extern "C" void fn_80230AD4(s32 i);
extern "C" u8 fn_80239F10(void* p);
struct BfinReg { u8 pad[8]; u8* list[0x400]; s32 count; };
extern "C" BfinReg* fn_801F856C();
extern "C" void fn_802B3A48(void* p);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7440(void* p, s32 a);

class Bfin {
public:
    void state0();
    void state1();
    void state2();
    void state3();
    void state4();
    void state5();
    void state6();

    u8 pad0[0x4];
    u32 room;
    u8 pad8[0x11c - 0x8];
    u8 x11c;
    u8 pad11d[0x230 - 0x11d];
    s32 state;
    s32 player;
    s32 step;
    s32 timer;
    u8 x240;
    u8 active[4];
};

typedef void (Bfin::*BfinStateFn)();
static BfinStateFn lbl_804B032C[] = {
    &Bfin::state0, &Bfin::state1, &Bfin::state2, &Bfin::state3,
    &Bfin::state4, &Bfin::state5, &Bfin::state6,
};

extern "C" void* fn_803D6434(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B0380;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

void Bfin::state6() {
    s32 pl = player;
    if (pl != -1) {
        lbl_8053AB10->request(pl);
    } else {
        lbl_8053AB10->request(-1);
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1100, -1)) {
        fn_801367E0(lbl_8053AAF8, 10);
        if (player != -1) {
            lbl_80529DEC.wins[player]++;
            lbl_80529DEC.mask = 0;
            lbl_80529DEC.winner = player;
            lbl_80529DEC.mask = 1 << player;
        } else {
            s32 r = (s32)(3.0f * lbl_8053AAF8->rnd.get_ufloat_1());
            if (r >= 3) {
                r = 2;
            }
            lbl_80529DEC.winner = r;
        }
        lbl_8053AD78->xe4 = 0;
        fn_80458880(lbl_8053AF80, 0xb, -1);
        x11c = 0;
    }
}

void Bfin::state5() {
    s32 pl = player;
    if (pl != -1) {
        lbl_8053AB10->request(pl);
    } else {
        lbl_8053AB10->request(-1);
    }
    if (timer > 0) {
        timer--;
        if (timer == 0) {
            state = 6;
        }
    }
}

void Bfin::state4() {
    timer--;
    lbl_8053AB10->request(-1);
    if (timer <= 0) {
        x240 = 4;
        timer = 0x82;
        state = 5;
        fn_80458880(lbl_8053AF80, 0x2d, -1);
    }
}

void Bfin::state3() {
    timer--;
    lbl_8053AB10->request(player);
    if (timer <= 0) {
        step++;
        timer = 2;
        for (s32 i = 0; i < 4; i++) {
            if (active[i]) {
                if (i == player || player == fn_8022F3DC(i)) {
                    fn_80230498(i, fn_8023E724(i), step + 0xdb, 0xff, -0x80, -0x80, 1);
                    if (step == 1) {
                        fn_80230FD0(player, 0x10001);
                    } else if (step == 0xd) {
                        JGeometry::TVec3<f32> v = *fn_8023E724(i);
                        JGeometry::TVec3<f32> a;
                        a.x = 7.0f + v.x;
                        a.y = v.y - 27.0f;
                        a.z = v.z;
                        fn_8013CC50(room, &a, 0xcb, 1, 0, 0, 0, 1, 1.0f);
                        JGeometry::TVec3<f32> b;
                        b.x = 7.0f + v.x;
                        b.y = v.y - 27.0f;
                        b.z = v.z;
                        fn_8013CC50(room, &b, 0xcc, 1, 0, 0, 0, 1, 1.0f);
                        fn_80230FD0(player, 0x2000e);
                    }
                }
            }
        }
        if (step == 0xd) {
            timer = 0x82;
            state = 5;
            switch (player) {
            case 0: x240 = 0; break;
            case 1: x240 = 1; break;
            case 2: x240 = 2; break;
            case 3: x240 = 3; break;
            }
            fn_80458880(lbl_8053AF80, 0x2a, -1);
            fn_80458FF0(lbl_8053AF80, 0x1000027, 1, 0);
        }
    }
}

void Bfin::state2() {
    timer--;
    lbl_8053AB10->request(-1);
    if (timer <= 0) {
        if (player == -1) {
            state = 4;
            fn_80458F9C(lbl_8053AF80, 0x3c);
            fn_801365C8(lbl_8053AAF8, 0);
            timer = 1;
        } else {
            for (s32 i = 0; i < 4; i++) {
                if (active[i]) {
                    if (i == player || player == fn_8022F3DC(i)) {
                        fn_80230498(i, fn_8023E724(i), 0x3e, 0xff, -0x80, -0x80, 1);
                    }
                }
            }
            state = 3;
            fn_80458F9C(lbl_8053AF80, 0x3c);
            fn_801365C8(lbl_8053AAF8, 0);
            timer = 1;
        }
    }
}

void Bfin::state1() {
    s32 total = 0;
    s32 ready = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        active[i] = 0;
        if (!fn_80236B50(i)) {
            total++;
            if (fn_802300EC(i) == 1) {
                active[i] = 1;
                ready++;
            }
        }
    }
    if (ready == total) {
        for (s32 k = 0; k < 4; k++) {
            if (active[k]) {
                fn_80230AD4(k);
            }
        }
        lbl_8053AB10->request(-1);
        lbl_8053AED0->flags |= 0x10;
        state = 2;
    }
}

void Bfin::state0() {
    if (fn_80239F10(this)) {
        for (s32 i = 0; i < 4; i++) {
            if ((lbl_8053AAF8->players & (u8)(1 << i)) && !fn_80236B50(i)) {
                player = i;
            }
        }
        if (player >= 0) {
            lbl_80529DEC.x1a8 = player;
        } else {
            lbl_80529DEC.x1a8 = 4;
        }
        s32 n = fn_801F856C()->count;
        for (s32 j = 0; j < n; j++) {
            u8* obj = fn_801F856C()->list[j];
            if (obj && *(u32*)(obj + 0x1a0) == 'SWEV') {
                fn_802B3A48(obj);
            }
        }
        fn_802D7440(fn_802D6A9C(), 0);
        lbl_80529DEC.x240 = 1;
        state = 1;
    }
}

extern "C" void fn_803D6D00(Bfin* self) {
    if (self->x240 != 0xff) {
        lbl_8053AED0->x256 = self->x240;
    }
    if (self->state == 6) {
        lbl_8053ADC8->a = 1;
        lbl_8053ADC8->b = 3;
    }
}

extern "C" void fn_803D6D3C(Bfin* self) {
    (self->*lbl_804B032C[self->state])();
}

extern "C" void fn_803D6D74(void* thisObj) {
	char* p = (char*)thisObj;
	*(s32*)(p + 0x230) = 0;
	*(s32*)(p + 0x234) = -1;
	*(s32*)(p + 0x23c) = 0x82;
	*(s32*)(p + 0x238) = 0;
	*(u8*)(p + 0x240) = 0xff;
	*(u8*)(p + 0x244) = 0;
	*(u8*)(p + 0x243) = 0;
	*(u8*)(p + 0x242) = 0;
	*(u8*)(p + 0x241) = 0;
	*(u8*)(p + 0x11f) = 1;
	*(s32*)((u8*)&lbl_80529DEC + 0x1a8) = -1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
