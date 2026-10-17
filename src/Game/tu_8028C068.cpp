#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];
    YasiDrawKey key;
    s32 c;
    u8 palette;
    u8 color;
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
extern "C" const char lbl_8046C210[];
extern "C" const f32 lbl_80540500;
extern "C" void fn_801F06F0(void* p, const char* name, s32 id, void* param, s32 a, f32 f1, f32 f2);
extern "C" void fn_80307AC8(void* a, u32 b, void* pos, s32 id, s32 c, s32 d, s32 e);


extern "C" char lbl_804A7A10[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8028C068(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804A7A10;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern void* lbl_8053AC98;
extern "C" void fn_8029E928(void* sys, void* pos, u32 tag, s32 id);
extern "C" void fn_8028C0C8(u8* this_) {
    s32 x;

    x = (s32)*(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0xc) = (f32)((x + 4) / 8 * 8);
    x = (s32)*(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x10) = (f32)((x + 4) / 8 * 8);
    if ((*(u32*)(this_ + 0x90) & 3) == 0) {
        fn_8029E928(lbl_8053AC98, this_ + 0xc, *(u32*)(this_ + 0x4), 0x20);
    }
    *(u8*)(this_ + 0x11c) = 0;
}

extern "C" void fn_8028C190(u8* this_) {
    s32 idx = 0;
    YasiDrawParam param;
    s32 n = *(u32*)(this_ + 0x90) & 3;
    if (n != 0) {
        *(s8*)&param.color = -1;
        param.palette = 0;
        fn_801F06F0(this_, lbl_8046C210, n + 4, &param, 0, lbl_80540500, lbl_80540500);
        fn_80307AC8(*(void**)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, n + 4, 0, 0, -1);
    } else {
        s32 m = (*(u32*)(this_ + 0x90) >> 4) & 7;
        if (m != 0) {
            idx = m + 3;
        }
        fn_801F06F0(this_, lbl_8046C210, idx + 0x45, 0, 0, lbl_80540500, lbl_80540500);
        fn_80307AC8(*(void**)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, idx + 0x45, 0, 0, -1);
    }
}

extern "C" int fn_80238CB4(int idx);
extern "C" void* fn_8023E724(int idx);
extern "C" BOOL fn_8028C364(u8* this_, u8 mode) {
    s32 i;
    s32 n;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 v;

    if (mode <= 1) {
        f31 = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
        f29 = *(f32*)(this_ + 0xc);
        f30 = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
    } else {
        f31 = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
        f29 = *(f32*)(this_ + 0x10);
        f30 = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
    }

    i = 0;
    while (i < 4) {
        n = *(s32*)(this_ + 0x198);
        if (fn_80238CB4(i) == n) {
            if (mode <= 1) {
                v = *(f32*)((u8*)fn_8023E724(i) + 0x4);
                if (v < f30 && f31 < v) {
                    return FALSE;
                }
                if (mode == 0) {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x0);
                    if (v > f29) {
                        return FALSE;
                    }
                } else {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x0);
                    if (v < f29) {
                        return FALSE;
                    }
                }
            } else {
                v = *(f32*)((u8*)fn_8023E724(i) + 0x0);
                if (v < f30 && f31 < v) {
                    return FALSE;
                }
                if (mode == 2) {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x4);
                    if (v > f29) {
                        return FALSE;
                    }
                } else {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x4);
                    if (v < f29) {
                        return FALSE;
                    }
                }
            }
        }
        i++;
    }
    return TRUE;
}

extern "C" s16 fn_8022461C(float*);
extern "C" int fn_8028D470(Actor* this_, int a, float* b) {
    if ((s32)(u16)fn_8022461C(b) == 0xd) {
        return 0;
    }
    return this_->Actor::v17(a, b);
}

extern "C" char lbl_8046C150[];
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7544(void* a, void* b);
extern "C" int fn_8028D4DC(f32* this_, s32 a, void* c) {
    u8 r = fn_802D7544(fn_802D6A9C(), c);
    if (r == 0) {
        return 0;
    }
    f32* d = (f32*)(lbl_8046C150 + (u8)(r - 1) * 12);
    f32 x = (f32)(a + 1);
    this_[0] = this_[0] + 16.0f * (x * d[0]);
    this_[1] = this_[1] + 16.0f * (x * d[1]);
    this_[2] = this_[2] + 0.0f;
    return 1;
}

