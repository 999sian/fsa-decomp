#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_80138B7C();
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4SLR3[];
extern "C" char* lbl_8053AAF8;
extern "C" char* lbl_8053AF80;
extern "C" char lbl_80529DEC[];
extern "C" s32 fn_802DE814(s32);
extern "C" char* fn_802D6A9C();
extern "C" void fn_80458FF0(void*, u32, s32, s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, void*, s32, s32, s32);
extern "C" void fn_801719C0(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x108) > 0) {
        return;
    }
    s32 id = *(s32*)(p + 0x26c);
    if (id != 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(u8*)((char*)found + 0x11c) = 0;
            *(s32*)(p + 0x26c) = 0;
        }
    }
}

extern "C" void* fn_80171A28(char* self, s16 flag) {
    if (self != 0) {
        *(char**)self = __vt__4SLR3;
        if (*(u16*)(self + 0x94) != 5) {
            s32 st = *(s32*)(lbl_8053AAF8 + 0x4c);
            if (st != 9 && st != 0xb && *(s32*)(self + 0x108) != 0) {
                fn_80138B7C();
            }
            s32 id = *(s32*)(self + 0x26c);
            if (id != 0) {
                char* p = (char*)fn_801F666C(fn_801F856C(), id);
                if (p != 0) {
                    p[0x11c] = 0;
                }
            }
        }
        fn_801EE434(*(void**)(self + 0x28c));
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_80171AF8(char* self) {
    *(u16*)(self + 0x94) = *(u32*)(self + 0x90) & 0xff;
    *(u32*)(self + 0x270) = (*(u32*)(self + 0x90) >> 8) & 1;
    *(f32*)(self + 0x60) = -8.0f;
    *(f32*)(self + 0x64) = -8.0f;
    *(f32*)(self + 0x68) = 8.0f;
    *(f32*)(self + 0x6c) = 8.0f;
    *(f32*)(self + 0x80) = -8.0f;
    *(f32*)(self + 0x84) = -8.0f;
    *(f32*)(self + 0x88) = 8.0f;
    *(f32*)(self + 0x8c) = 8.0f;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x250) = 0;
    *(s32*)(self + 0x254) = 0;
    *(s32*)(self + 0x234) = 0;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(JGeometry::TVec3<f32>*)(self + 0x29c) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2a8) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2b4) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2c0) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2cc) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2d8) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2e4) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2f0) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2fc) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x308) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x314) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(f32*)(self + 0x298) = 0.0f;
    *(f32*)(self + 0x294) = 0.0f;
    *(f32*)(self + 0x290) = 0.0f;
    *(f32*)(self + 0x44) = 0.0f;
    *(f32*)(self + 0x40) = 0.0f;
    *(f32*)(self + 0x3c) = 0.0f;
    *(f32*)(self + 0x280) = 0.3f;
    *(f32*)(self + 0x278) = 0.0f;
    *(f32*)(self + 0x27c) = 1.5f;
    *(s32*)(self + 0xb0) = 0xa002204;
    *(s32*)(self + 0xbc) = 3;
    *(s32*)(self + 0x28c) = 0;
    *(s32*)(self + 0x264) = 0;
    if ((u8)fn_802DE814(0xa002204) == 1) {
        *(s32*)(self + 0x108) = 0x10;
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        *(s32*)(self + 0x108) = 0x18;
    }
    *(s32*)(self + 0x268) = *(s32*)(self + 0x108);
    *(s32*)(self + 0x258) = 0;
    *(f32*)(self + 0x284) = 0.0f;
    *(f32*)(self + 0x288) = 70.0f;
    *(s32*)(self + 0x118) = 0x10;
    ((JGeometry::TVec3<f32>*)(self + 0x32c))->set(*(JGeometry::TVec3<f32>*)(self + 0xc));
    if (*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        char* a = fn_802D6A9C();
        if (*(s32*)(a + 0x18) == 3) {
            char* b = fn_802D6A9C();
            if (*(s32*)(b + 0x14) == 1) {
                *(s32*)(self + 0x244) = 0x64;
            }
        }
    }
    *(s32*)(self + 0x260) = 0;
    *(s32*)(self + 0x25c) = 0;
    *(s32*)(self + 0x98) = 2;
    *(s32*)(self + 0x250) = 0x47e;
    char* random = lbl_8053AAF8;
    *(u32*)(random + 0xb4) = *(u32*)(random + 0xb4) * 0x19660d + 0x3c6ef35f;
    {
        u32 bits = (*(u32*)(random + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(self + 0x23c) = (s32)((*(f32*)&bits - 1.0f) * 100.0f) + 0x64;
    }
    *(u8*)(self + 0x274) = 8;
    *(s32*)(self + 0x26c) = 0;
    *(s32*)(self + 0x230) = 0;
    switch (*(u16*)(self + 0x94)) {
    case 0:
        *(s32*)(self + 0x250) = 0x190;
        break;
    case 3: {
        *(u8*)(self + 0x274) = 6;
        char* random = lbl_8053AAF8;
    *(u32*)(random + 0xb4) = *(u32*)(random + 0xb4) * 0x19660d + 0x3c6ef35f;
        {
            u32 bits = (*(u32*)(random + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(self + 0x23c) = (s32)((*(f32*)&bits - 1.0f) * 50.0f) + 0x32;
        }
        *(s32*)(self + 0x250) = 0x64;
        *(f32*)(self + 0x27c) = 1.0f;
        *(f32*)(self + 0x288) = 10.0f;
        *(s32*)(self + 0x230) = 2;
        break;
    }
    case 1:
        *(u8*)(self + 0x274) = 4;
        *(f32*)(self + 0x27c) = 1.0f;
        *(f32*)(self + 0x288) = 10.0f;
        *(s32*)(self + 0x230) = 1;
        break;
    case 2:
        *(u8*)(self + 0x274) = 2;
        break;
    case 4:
        *(s32*)(self + 0x23c) = 0x32;
        *(u8*)(self + 0x274) = 3;
        *(s32*)(self + 0x230) = 3;
        break;
    case 5:
        *(s32*)(self + 0x114) = 4;
        *(s32*)(self + 0x108) = 0x2710;
        *(u8*)(self + 0x1a8) = 0;
        break;
    }
    if ((*(u32*)(self + 0x90) >> 27) != 0) {
        *(s32*)(self + 0xb0) = 0;
    } else {
        if (*(u16*)(self + 0x94) != 5) {
            *(s32*)(self + 0x26c) = Actor_CreateByID(fn_801F856C(), 0x534c5233, *(s32*)(self + 0x4), self + 0xc, 5, -1, -1);
            if ((u8)lbl_8053AAF8[0x7f] == 1) {
                fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
            }
        }
    }
}

