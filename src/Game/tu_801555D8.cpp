#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"

class ActorResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern void* lbl_804A00C8[];
extern f32 lbl_8053D378;
extern f32 lbl_8053D39C;
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" s32 fn_801F6874(u32 x);
extern "C" u16 fn_8022461C(void* p, s32 b);
extern "C" u8 fn_802DE9A0(void);
extern "C" const f32 sincosTable___5JMath[];
extern f32 lbl_8053D388;
extern f32 lbl_8053D3D8;
extern f32 lbl_8053D37C, lbl_8053D380, lbl_8053D38C, lbl_8053D390, lbl_8053D394, lbl_8053D3C0;
extern f32 lbl_8053D3A4, lbl_8053D3C4, lbl_8053D3F4, lbl_8053D3FC, lbl_8053D410, lbl_8053D414;
extern f32 lbl_8053D418, lbl_8053D41C;
extern void* lbl_8053AAF8;
extern s32 lbl_8053AB50;
extern u32 lbl_8049FDC8[];
extern s32 lbl_8049FFD8[];
extern char lbl_80529DEC[];
extern "C" s32 fn_80157C68(char* self) {
    if (*(s32*)(self + 0x230) == 0xd) {
        return 1;
    }
    if (*(f32*)(self + 0x14) > lbl_8053D3D8) {
        return 0;
    }
    *(f32*)(self + 0x2b8) = *(f32*)(self + 0xc);
    *(f32*)(self + 0x2bc) = *(f32*)(self + 0x10);
    *(f32*)(self + 0x2c0) = *(f32*)(self + 0x14);
    *(f32*)(self + 0x2b8) = (f32)((s32)*(f32*)(self + 0x2b8) & 0xFFF8);
    *(f32*)(self + 0x2bc) = (f32)((s32)*(f32*)(self + 0x2bc) & 0xFFF8);
    s32 angle = (s16)fn_801F6874(*(u32*)(self + 0x98));
    char* sc = (char*)sincosTable___5JMath + (((u32)angle >> 2) & 0x3ff8);
    *(f32*)(self + 0x2b8) = lbl_8053D388 * *(f32*)sc + *(f32*)(self + 0x2b8);
    angle = (s16)fn_801F6874(*(u32*)(self + 0x98));
    sc = (char*)sincosTable___5JMath + (((u32)angle >> 2) & 0x3ff8);
    *(f32*)(self + 0x2bc) = lbl_8053D388 * *(f32*)(sc + 4) + *(f32*)(self + 0x2bc);
    s32 k = (u16)fn_8022461C(self + 0x2b8, *(s32*)(self + 4));
    if ((u32)(k - 2) <= 1 || k == 0xe) {
        if (k == 0xe && fn_802DE9A0() == 1) {
            *(u8*)(self + 0x2a8) = 1;
        }
        *(s32*)(self + 0xd8) = 0;
        *(s32*)(self + 0xdc) = 0;
        *(f32*)(self + 0x3c) = 0.0f;
        *(f32*)(self + 0x40) = 0.0f;
        *(f32*)(self + 0x44) = 0.0f;
        *(f32*)(self + 0x2ac) = 0.0f;
        *(f32*)(self + 0x2b0) = 0.0f;
        *(f32*)(self + 0x2b4) = 0.0f;
        *(s32*)(self + 0x254) = 10000;
        *(s32*)(self + 0x230) = 0xc;
        *(s32*)(self + 0x108) = 200;
        return 1;
    }
    return 0;
}

extern "C" void fn_80157E20(char* self) {
    s32 idx = *(s32*)(self + 0x284);
    if (idx >= 0) {
        void* p = fn_801F666C(fn_801F856C(), idx);
        if (p != NULL) {
            Vec v;
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 5.0f;
            *(Vec*)((char*)p + 0x3c) = v;
        }
        *(s32*)(self + 0x284) = -1;
    }
    if (*(s32*)(self + 0x108) <= 0) {
        s32 idx2 = *(s32*)(self + 0x280);
        if (idx2 >= 0) {
            void* p = fn_801F666C(fn_801F856C(), idx2);
            if (p != NULL) {
                *(s32*)((char*)p + 0x290) -= 1;
            }
        }
    }
}

extern "C" void* fn_80157ED0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A00C8;
        char* p = (char*)this_;
        s32 idx = *(s32*)(p + 0x280);
        if (idx >= 0) {
            void* found = fn_801F666C(fn_801F856C(), idx);
            if (found != 0) {
                *(s32*)((char*)found + 0x290) -= 1;
            }
        }
        idx = *(s32*)(p + 0x284);
        if (idx >= 0) {
            void* found = fn_801F666C(fn_801F856C(), idx);
            if (found != 0) {
                Vec v;
                v.x = lbl_8053D378;
                v.y = lbl_8053D378;
                v.z = lbl_8053D39C;
                *(Vec*)((char*)found + 0x3c) = v;
            }
            *(s32*)(p + 0x284) = -1;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80157FB0(char* self) {
    char* rng;
    u32 seed;
    u32 bits;
    s32 i;
    f32 frand;
    *(f32*)(self + 0x60) = lbl_8053D390;
    *(f32*)(self + 0x64) = lbl_8053D388;
    *(f32*)(self + 0x68) = lbl_8053D394;
    *(f32*)(self + 0x6c) = lbl_8053D38C;
    *(f32*)(self + 0x84) = *(f32*)(self + 0x80) = lbl_8053D410;
    *(f32*)(self + 0x8c) = *(f32*)(self + 0x88) = lbl_8053D380;
    *(f32*)(self + 0x74) = *(f32*)(self + 0x70) = lbl_8053D414;
    *(f32*)(self + 0x7c) = *(f32*)(self + 0x78) = lbl_8053D3C0;
    *(u16*)(self + 0x94) = (u16)((*(u32*)(self + 0x90) >> 16) & 0xff);
    *(s32*)(self + 0x280) = *(u32*)(self + 0x90) >> 24;
    *(s32*)(self + 0x28c) = 0;
    if (*(s32*)(self + 0x280) == 0) {
        *(s32*)(self + 0x280) = -1;
    }
    *(s32*)(self + 0x25c) = 0;
    *(s32*)(self + 0x260) = 0;
    *(s32*)(self + 0x264) = 0;
    *(s32*)(self + 0x268) = 0;
    *(s32*)(self + 0x26c) = 0;
    *(s32*)(self + 0x270) = 0;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x250) = 0;
    *(s32*)(self + 0x254) = 0;
    *(s32*)(self + 0x258) = 0;
    *(u32*)(self + 0x90) &= 0xff;
    *(u32*)(self + 0x108) = lbl_8049FDC8[*(u32*)(self + 0x90) * 2];
    *(s32*)(self + 0x274) = 0;
    *(s32*)(self + 0x278) = 0;
    *(f32*)(self + 0x298) = lbl_8053D37C;
    *(f32*)(self + 0x2b4) = lbl_8053D378;
    *(f32*)(self + 0x2b0) = lbl_8053D378;
    *(f32*)(self + 0x2ac) = lbl_8053D378;
    *(f32*)(self + 0x44) = lbl_8053D378;
    *(f32*)(self + 0x40) = lbl_8053D378;
    *(f32*)(self + 0x3c) = lbl_8053D378;
    rng = (char*)lbl_8053AAF8;
    *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
    frand = *(f32*)&(bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000);
    *(u32*)(self + 0x98) = (s32)(lbl_8053D418 * (frand - lbl_8053D37C)) & 3;
    *(u8*)(self + 0x2a8) = 0;
    *(s32*)(self + 0x238) = 8;
    *(s32*)(self + 0x284) = -1;
    *(s32*)(self + 0x27c) = lbl_8053AB50;
    lbl_8053AB50++;
    *(u16*)(self + 0x2aa) = 0xffff;
    *(u32*)(self + 0xb0) = 0x12205;
    if (*(u16*)(self + 0x94) == 2 || *(s32*)(self + 0x90) == 3) {
        *(u32*)(self + 0xb0) = 0x4000000;
    }
    *(s32*)(self + 0x290) = 0;
    if (*(s32*)(self + 0x90) == 2 && *(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        *(s32*)(self + 0x108) = 1;
        for (i = 0; i < 6; i++) {
            if ((s32)(lbl_8053D3F4 * *(f32*)(self + 0xc)) == lbl_8049FFD8[i * 2] &&
                (s32)(lbl_8053D3F4 * *(f32*)(self + 0x10)) == lbl_8049FFD8[i * 2 + 1]) {
                *(s32*)(self + 0x290) = i;
                break;
            }
        }
    }
    *(f32*)(self + 0x2a4) = lbl_8053D41C;
    if (*(u16*)(self + 0x94) == 1) {
        *(f32*)(self + 0x2a4) = lbl_8053D3FC;
    }
    rng = (char*)lbl_8053AAF8;
    *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
    frand = *(f32*)&(bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000);
    *(f32*)(self + 0x294) = lbl_8053D3C4 * *(f32*)(self + 0x2a4) + lbl_8053D3A4 * (frand - lbl_8053D37C);
    *(u16*)(self + 0x234) = 0;
    switch (*(s32*)(self + 0x90)) {
    case 2:
        *(s32*)(self + 0xbc) = 4;
        *(s32*)(self + 0xb8) = 1;
        *(s32*)(self + 0x230) = 0xf;
        break;
    case 3:
        *(f32*)(self + 0x298) = lbl_8053D378;
        *(s32*)(self + 0x278) = 1;
        *(s32*)(self + 0x230) = 8;
        break;
    default:
        *(s32*)(self + 0xbc) = 2;
        *(s32*)(self + 0xb8) = 1;
        *(s32*)(self + 0x230) = 0;
        break;
    }
    *(f32*)(self + 0x29c) = lbl_8053D378;
    *(f32*)(self + 0x2a0) = lbl_8053D37C;
    *(s32*)(self + 0x288) = 0;
    if (*(s32*)(self + 0x280) >= 0) {
        *(s32*)(self + 0x230) = 0xe;
    }
}

extern "C" void fn_801583D4(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_801583E4(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

void __sinit_tu_801555D8_cpp(void) {
}

