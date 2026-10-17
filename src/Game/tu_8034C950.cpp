#include "Game/SinitPoolChain.h"
#include "Game/Actor.h"

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];
    YasiDrawKey key;
    s32 c;
    u8 palette;
    s8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_804721B0[];
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" s32 fn_8023CA88(s32 holder);
extern "C" void fn_801F06F0(Actor* a, const char* name, s32 id, YasiDrawParam* param, s32 p5, f32 f6, f32 f7);
extern "C" void fn_80307AC8(u32 x, u32 y, void* v, s32 p, s32 p6, u32 u, s32 minus1);
extern "C" void fn_803075AC(u32 x, u32 y, void* v, s32 p, s32 sign, s32 two, s32 minus1, u8 p7, u32 u, s32 zero);


extern "C" u32 fn_801F132C(Actor* a, s32 b, s32 c, s32* d);
extern "C" char __vt__4RCK2[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8034C950(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = __vt__4RCK2;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8034C9B0(Actor* a, s32 b, s32 c) {
    fn_801F132C(a, b, c, (s32*)((u8*)a + 0x378));
}

extern "C" void fn_8034CC98(Actor* a) {
    Vec saved;
    YasiDrawParam param;
    s32 flag;

    param.color = -1;
    param.palette = 0;
    if (a->field_C4 == 1 && a->field_0C.z != 0.0f) {
        param.f20 = 0;
        param.color = fn_8023CB24(a->field_C8) + 1;
        param.palette = fn_8023CA88(a->field_C8);
    }
    *(f64*)&saved = *(f64*)&a->field_0C;
    saved.z = a->field_0C.z;
    a->field_0C.y += 8.0f;
    flag = 7;
    if (*(s32*)((u8*)a + 0x230) == 0) {
        flag = -1;
        fn_80307AC8(a->field_198, a->field_04, 0, 0xc, 0, 0, -1);
    } else {
        fn_803075AC(a->field_198, a->field_04, 0, 0x2b, 0, 2, -1, 1, 0, 0);
    }
    fn_801F06F0(a, lbl_804721B0, 0x2b, &param, flag, 1.0f, 1.0f);
    *(f64*)&a->field_0C = *(f64*)&saved;
    a->field_0C.z = saved.z;
}

extern "C" void fn_8034DBF4(Actor* a) {
    u8* p = (u8*)a;
    a->field_60 = -14.0f;
    a->field_64 = -14.0f;
    a->field_68 = 14.0f;
    a->field_6C = 14.0f;
    a->field_1A4 = 2;
    a->field_7C.y = -16.0f;
    a->field_7C.z = -16.0f;
    a->field_88 = 16.0f;
    a->field_8C = 16.0f;
    *(s32*)(p + 0x234) = -1;
    *(u8*)(p + 0x25c) = 0;
    *(u8*)(p + 0x320) = 1;
    *(f32*)(p + 0x32c) = 0.0f;
    *(f32*)(p + 0x328) = 0.0f;
    *(f32*)(p + 0x324) = 0.0f;
    *(s32*)(p + 0x330) = 0;
    *(s32*)(p + 0x238) = -1;
    *(u8*)(p + 0x25d) = 0;
    *(u8*)(p + 0x334) = 1;
    *(f32*)(p + 0x340) = 0.0f;
    *(f32*)(p + 0x33c) = 0.0f;
    *(f32*)(p + 0x338) = 0.0f;
    *(s32*)(p + 0x344) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(u8*)(p + 0x25e) = 0;
    *(u8*)(p + 0x348) = 1;
    *(f32*)(p + 0x354) = 0.0f;
    *(f32*)(p + 0x350) = 0.0f;
    *(f32*)(p + 0x34c) = 0.0f;
    *(s32*)(p + 0x358) = 0;
    *(s32*)(p + 0x240) = -1;
    *(u8*)(p + 0x25f) = 0;
    *(u8*)(p + 0x35c) = 1;
    *(f32*)(p + 0x368) = 0.0f;
    *(f32*)(p + 0x364) = 0.0f;
    *(f32*)(p + 0x360) = 0.0f;
    *(s32*)(p + 0x36c) = 0;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x260) = 0;
    *(f32*)(p + 0x26c) = 0.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x264) = 0.0f;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x274) = -1;
    *(s32*)(p + 0x278) = 0;
    *(f32*)(p + 0x284) = 0.0f;
    *(f32*)(p + 0x280) = 0.0f;
    *(f32*)(p + 0x27c) = 0.0f;
    *(s32*)(p + 0x288) = 0;
    *(s32*)(p + 0x28c) = -1;
    *(s32*)(p + 0x290) = 0;
    *(f32*)(p + 0x29c) = 0.0f;
    *(f32*)(p + 0x298) = 0.0f;
    *(f32*)(p + 0x294) = 0.0f;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x2a4) = -1;
    *(s32*)(p + 0x2a8) = 0;
    *(f32*)(p + 0x2b4) = 0.0f;
    *(f32*)(p + 0x2b0) = 0.0f;
    *(f32*)(p + 0x2ac) = 0.0f;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = -1;
    *(s32*)(p + 0x2c0) = 0;
    *(f32*)(p + 0x2cc) = 0.0f;
    *(f32*)(p + 0x2c8) = 0.0f;
    *(f32*)(p + 0x2c4) = 0.0f;
    *(s32*)(p + 0x2d0) = 0;
    *(s32*)(p + 0x2d4) = -1;
    *(s32*)(p + 0x2d8) = 0;
    *(f32*)(p + 0x2e4) = 0.0f;
    *(f32*)(p + 0x2e0) = 0.0f;
    *(f32*)(p + 0x2dc) = 0.0f;
    *(s32*)(p + 0x2e8) = 0;
    *(s32*)(p + 0x2ec) = -1;
    *(s32*)(p + 0x2f0) = 0;
    *(f32*)(p + 0x2fc) = 0.0f;
    *(f32*)(p + 0x2f8) = 0.0f;
    *(f32*)(p + 0x2f4) = 0.0f;
    *(s32*)(p + 0x300) = 0;
    *(s32*)(p + 0x304) = -1;
    *(s32*)(p + 0x308) = 0;
    *(f32*)(p + 0x314) = 0.0f;
    *(f32*)(p + 0x310) = 0.0f;
    *(f32*)(p + 0x30c) = 0.0f;
    *(s32*)(p + 0x318) = 0;
    *(s32*)(p + 0x31c) = -1;
    a->field_B8 = 2;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x378) = 0;
    *(s32*)(p + 0x37c) = 0;
    *(s32*)(p + 0x388) = -1;
    *(s32*)(p + 0x374) = 0;
    *(s32*)(p + 0x370) = 1;
    *(u8*)(p + 0x380) = (a->field_90 >> 4) & 1;
    *(u8*)(p + 0x383) = (a->field_90 >> 5) & 1;
    *(u8*)(p + 0x381) = 0;
    *(u8*)(p + 0x384) = 0;
    *(u8*)(p + 0x385) = 0;
    *(u8*)(p + 0x382) = 0;
}

