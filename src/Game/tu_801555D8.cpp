#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

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

extern "C" void fn_801583D4(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_801583E4(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

void __sinit_tu_801555D8_cpp(void) {
}

