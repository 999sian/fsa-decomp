#include "Game/Actor.h"

struct Tu80343Random {
    u32 seed;
    f32 get_ufloat_1() {
        union {
            f32 f;
            u32 s;
        } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct Tu80343Game {
    u8 pad[0xb4];
    Tu80343Random rnd;
};
extern Tu80343Game* lbl_8053AAF8;


extern "C" char __vt__4BEEE[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* mgr, u32 kind, s32 room, void* pos, s32 n);
extern "C" void v07__5ActorFv(void* this_);
extern "C" Actor* fn_80343A70(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4BEEE;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80343AD0(char* this_) {
    u32 n;
    s32 t = *(s32*)(this_ + 0x274);
    if (t == 1) {
        n = 3;
    } else if (t == 2) {
        n = 1;
    }
    fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(this_ + 4), this_ + 0xc, n | 0x261e00);
    v07__5ActorFv(this_);
}

