#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"

struct ActorE62 { u8 pad0[4]; u32 f4; u8 fC[4]; };
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_8013CC50(s32 id, void* pos, f32 scale, u16 kind, s32 a, s32 b, void* c, void* d, u8 e);
extern "C" void fn_801CB71C(void* a, void* b, u32 c, u32 d);
extern "C" const f32 lbl_8053F5AC;
extern "C" u32 fn_801DA938(void* p);
extern "C" void* fn_804032E8(u32 id, u32 v);
extern "C" u8 fn_801DA904(void* p);
extern "C" void fn_801DAC6C();
extern "C" u8 fn_801DAD2C();
extern "C" void fn_801EFD34(void* a, void* p, u8* buf, s32 id, f32 x, f32 y, f32 z);
extern "C" const f32 lbl_8053F5A0;
extern "C" const f32 lbl_8053F5A4;
extern "C" const f32 lbl_8053F5A8;
extern "C" void fn_801E5FC8(u8* this_) {
    volatile struct {
        s32 a;
        u8 b[4];
        f32* m;
        u8 c[11];
        s32 d;
        u8 e[4];
        s32 f;
        s32 g;
        s32 h;
    } req;
    f32 mtx[12];
    u8 buf[16];
    void* p;
    u32 id = fn_801DA938(this_ + 0x2a8);
    p = fn_804032E8(0x49434542, id);
    if (p != 0) {
        req.a = -1;
        *(s32*)req.b = -1;
        for (u8 i = 0; i < 16; i += 8) {
            buf[(u8)i] = i;
            buf[(u8)(i + 1)] = (u8)(i + 1);
            buf[(u8)(i + 2)] = (u8)(i + 2);
            buf[(u8)(i + 3)] = (u8)(i + 3);
            buf[(u8)(i + 4)] = (u8)(i + 4);
            buf[(u8)(i + 5)] = (u8)(i + 5);
            buf[(u8)(i + 6)] = (u8)(i + 6);
            buf[(u8)(i + 7)] = (u8)(i + 7);
        }
        req.a = -1;
        *(s32*)req.b = 0;
        req.m = 0;
        req.c[0] = 0;
        req.c[1] = 0;
        req.c[2] = 0;
        req.c[3] = 1;
        req.c[4] = 1;
        req.c[5] = 0;
        req.c[6] = 0;
        req.c[7] = 0;
        req.c[8] = 0;
        req.c[9] = 0;
        req.c[10] = 1;
        req.d = 3;
        req.e[0] = 1;
        req.e[1] = 0;
        req.e[2] = 0;
        req.f = -1;
        req.g = 0;
        req.h = 2;
        if ((*(u32*)(this_ + 0x230) & 0x2000) != 0 && fn_801DA904(this_ + 0x2a8)) {
            mtx[0] = lbl_8053F5A4;
            mtx[1] = lbl_8053F5A0;
            mtx[2] = lbl_8053F5A0;
            mtx[3] = lbl_8053F5A0;
            mtx[4] = lbl_8053F5A0;
            mtx[5] = lbl_8053F5A8;
            mtx[6] = lbl_8053F5A0;
            mtx[7] = lbl_8053F5A0;
            mtx[8] = lbl_8053F5A0;
            mtx[9] = lbl_8053F5A0;
            mtx[10] = lbl_8053F5A8;
            mtx[11] = lbl_8053F5A0;
            req.m = (f32*)mtx;
        }
        fn_801DAC6C();
        u8 r = fn_801DAD2C();
        req.b[0] += r;
        req.b[1] += r;
        req.b[2] += r;
        fn_801EFD34(this_, p, buf, -1, lbl_8053F5A0, *(s32*)(this_ + 0x248) >= 8 ? lbl_8053F5AC : lbl_8053F5A0, lbl_8053F5A0);
    }
}

extern "C" void fn_801E61C4(char* this_) {
    f32 v[3];
    f32 y = lbl_8053F5AC + *(f32*)(this_ + 0x10);
    f32 z = *(f32*)(this_ + 0x14);
    v[0] = *(f32*)(this_ + 0xc);
    v[1] = y;
    v[2] = z;
    fn_801CB71C(this_ + 0x2c8, v, 0, 0);
    fn_801CB71C(this_ + 0x2cc, v, 0, 0);
}

extern "C" void fn_801E6234(char* this_) {
    f32 v[3];
    f32 k = lbl_8053F5AC;
    f32 w = *(f32*)(this_ + 0x10);
    f32 y = k + w;
    f32 z = *(f32*)(this_ + 0x14);
    f32 x = *(f32*)(this_ + 0xc);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    *(void**)(this_ + 0x2c8) = fn_8013CC50(*(u32*)(this_ + 4), v, 1.0f, 0x25c, 0, 0, 0, 0, 1);
    *(void**)(this_ + 0x2cc) = fn_8013CC50(*(u32*)(this_ + 4), v, 1.0f, 0x25d, 0, 0, 0, 0, 1);
}

extern "C" void fn_801E62D4(Actor* this_) {
    fn_8013CC50(this_->field_04, &this_->field_0C, 1.0f, 0x259, 0, 0, 0, 0, 1);
}
extern "C" void fn_801E631C(const Actor* this_) {
    fn_8013CC50(this_->field_04, (void*)&this_->field_0C, lbl_8053F5A8, 0x25a, 0, 0, 0, 0, 1);
    fn_8013CC50(this_->field_04, (void*)&this_->field_0C, lbl_8053F5A8, 0x25b, 0, 0, 0, 0, 1);
}

extern "C" void fn_801E6394(char* this_) {
    fn_801EE434(*(void**)(this_ + 0x2c0));
    fn_801EE434(*(void**)(this_ + 0x2c4));
    *(u32*)(this_ + 0x2c0) = 0;
    *(u32*)(this_ + 0x2c4) = 0;
}

extern "C" void fn_801E63D8(char* this_) {
    *(void**)(this_ + 0x2c0) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 1.0f, 0x25e, 0, 0, 0, 0, 1);
    *(void**)(this_ + 0x2c4) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 1.0f, 0x25f, 0, 0, 0, 0, 1);
}

void __sinit_tu_801E5FC8_cpp(void) {
}

