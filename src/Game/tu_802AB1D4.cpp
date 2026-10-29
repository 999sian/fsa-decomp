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
extern "C" u16 fn_802F9908(void* mgr, s32 room, s32 word);
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
extern "C" void fn_802AB238(void* p) {
    char* self = (char*)p;
    f32 rect[4];
    s32 r;
    s32 state;
    f32 c = lbl_80540890;
    rect[0] = *(f32*)(self + 0x60) + (c + *(f32*)(self + 0xc));
    rect[1] = *(f32*)(self + 0x64) + (c + *(f32*)(self + 0x10));
    rect[2] = *(f32*)(self + 0x68) + (c + *(f32*)(self + 0xc));
    rect[3] = *(f32*)(self + 0x6c) + (c + *(f32*)(self + 0x10));
    r = fn_8023AF14(rect, *(s32*)(self + 0x4), 0);
    state = *(s32*)(self + 0x230);
    if (state == 2) {
        return;
    }
    if (state == 0) {
        return;
    }
    if (state == 1) {
        return;
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
