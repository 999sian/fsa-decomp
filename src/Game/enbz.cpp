// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A35AC-801A3C50 (ENBZ). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801A35AC_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A2CB0[];

extern "C" void* fn_801A35AC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2CB0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/stub_801a360c.cpp
// ENBZ cluster, part 2/4. fn_801A360C - empty override (bare blr), no
// extab. Likely a "do nothing" draw() or similar no-op virtual.
extern "C" {

void fn_801A360C(void) {}

}

// ENBZ: bomb spawner. Params (0x90): bits 0-7 = entry in lbl_804A2C80
// (0xFF = random), bits 8-11 = respawn flag, bits 12-15 = count (0 -> 3).
struct EnbzRandom {
    u32 seed;
    u32 get() {
        seed = 0x19660d * seed + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};

struct EnbzGame {
    u8 pad[0xb4];
    EnbzRandom rnd;
};

struct EnbzVec { f32 x, y, z; };

struct ENBZ {
    void* vtbl;
    u32 m_4;
    u8 pad8[0xc - 0x8];
    EnbzVec pos;
    u8 pad18[0x90 - 0x18];
    u32 params;
    u8 pad94[0x230 - 0x94];
    s32 state;
    u32 spawnId;
    u32 spawnArg;
    s32 respawn;
    s32 count;
    s32 handles[15];
    s32 timer0;
    s32 timer1;
    s32 timer2;
    s32 m_28c;
    s32 m_290;
    s32 m_294;
};

extern EnbzGame* lbl_8053AAF8;
extern u32 lbl_804A2C80[];

extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, u32 arg, EnbzVec* pos, u32 arg2, s32 a, s32 b);
extern "C" void* fn_801F666C(void* mgr, s32 handle);

extern "C" void fn_801A3610(ENBZ* this_) {
    switch (this_->state) {
    case 0:
        if (this_->timer0 != 0) {
            break;
        }
        {
            int i;
            for (i = 0; i < this_->count; i++) {
                if (this_->handles[i] == -1) {
                    u32 id = this_->spawnId;
                    u32 arg = this_->spawnArg;
                    if (this_->spawnId == 0) {
                        u32* e = &lbl_804A2C80[(int)(5.99f * lbl_8053AAF8->rnd.get_ufloat_1())];
                        id = e[0];
                        arg = e[1];
                    }
                    EnbzVec pos;
                    pos.x = this_->pos.x;
                    pos.y = this_->pos.y;
                    pos.z = this_->pos.z;
                    if (i & 1) {
                        pos.x = pos.x - 16.0f * i;
                    } else {
                        pos.x = pos.x + 16.0f * i;
                    }
                    pos.x += 8.0f - 16.0f * lbl_8053AAF8->rnd.get_ufloat_1();
                    EnbzGame* g = lbl_8053AAF8;
                    pos.y += 8.0f - 16.0f * g->rnd.get_ufloat_1();
                    this_->handles[i] = Actor_CreateByID(fn_801F856C(), id, this_->m_4, &pos, arg, -1, -1);
                    if (this_->handles[i] != 0) {
                        Actor_CreateByID(fn_801F856C(), 'HBMB', this_->m_4, &pos, 0xb, -1, -1);
                    }
                }
            }
            this_->state = 1;
        }
    case 1:
        if (this_->timer0 == 0) {
            int i;
            int dead;
            for (i = 0, dead = 0; i < this_->count; i++) {
                if (fn_801F666C(fn_801F856C(), this_->handles[i]) == 0) {
                    this_->handles[i] = -1;
                    if (this_->respawn == 0) {
                        this_->state = 0;
                        this_->timer0 = 1200;
                        goto end;
                    }
                    dead++;
                }
            }
            this_->timer0 = 8;
            if (dead == this_->count && this_->respawn == 1) {
                this_->timer0 = 1200;
                this_->state = 0;
            }
        }
        break;
    }
    if (this_->timer0 > 0) {
        this_->timer0--;
    }
    if (this_->timer1 > 0) {
        this_->timer1--;
    }
    if (this_->timer2 > 0) {
        this_->timer2--;
    }
end:;
}

static inline void enbzClear(s32* h) {
    for (int i = 0; i < 15; i++) {
        h[i] = -1;
    }
}

extern "C" void fn_801A3944(ENBZ* this_) {
    this_->m_28c = 0;
    this_->m_290 = 0;
    this_->m_294 = 0;
    this_->timer0 = 0;
    this_->timer1 = 0;
    this_->timer2 = 0;
    int idx = (this_->params & 0xff) * 2;
    this_->spawnId = 0;
    this_->spawnArg = 0;
    if ((this_->params & 0xff) != 0xff) {
        this_->spawnId = lbl_804A2C80[idx];
        this_->spawnArg = lbl_804A2C80[idx + 1];
    }
    if (((this_->params >> 8) & 0xf) == 0) {
        this_->respawn = 0;
    } else {
        this_->respawn = 1;
    }
    this_->count = (this_->params >> 12) & 0xf;
    if (this_->count == 0) {
        this_->count = 3;
    }
    enbzClear(this_->handles);
    this_->state = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
