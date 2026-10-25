#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804A6E20[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8022979C(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A6E20;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" u8 fn_8022F514(u32 idx);
extern "C" f32* fn_8023E724(u32 idx);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" char lbl_8046ADF0[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, struct SobDrawParam* prm);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" f32 lbl_8053FFD8;
extern "C" f32 lbl_8053FFE0;
extern "C" f32 lbl_8053FFE8;
extern "C" f32 lbl_8053FFEC;
extern "C" f32 lbl_8053FFF0;
extern "C" f32 lbl_8053FFF4;
extern "C" f32 lbl_8053FFF8;
extern "C" void fn_8022A83C(u8* p) {
    s32 mode = (*(u32*)(p + 0x90) >> 2) & 0x3f;
    f32* src;
    if (mode != 5) {
        if (mode == 1) {
            if (fn_8022F514(*(u32*)(p + 0x90) & 3)) {
                *(u8*)(p + 0x11c) = 0;
                return;
            }
        } else if (mode != 6 && mode != 7 && mode != 8 && mode != 9 && *(s32*)(p + 0x4) < 8) {
            *(u8*)(p + 0x11c) = 0;
            return;
        }
    }
    mode = (*(u32*)(p + 0x90) >> 2) & 0x3f;
    if (mode == 3) {
        u8* rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(f32*)(p + 0xc) += (f32)(s32)(lbl_8053FFEC * (*(f32*)&bits - lbl_8053FFD8)) - lbl_8053FFE0;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(f32*)(p + 0x10) += (f32)(s32)(lbl_8053FFEC * (*(f32*)&bits - lbl_8053FFD8)) - lbl_8053FFF8;
    } else if (mode == 4) {
        *(f32*)(p + 0x14) += lbl_8053FFE8;
    } else if (mode == 0xe) {
        *(f32*)(p + 0xc) -= lbl_8053FFEC;
        *(f32*)(p + 0x14) += lbl_8053FFE8;
    }
    *(u32*)(p + 0x108) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = 0;
    mode = (*(u32*)(p + 0x90) >> 2) & 0x3f;
    if (mode <= 0xe) {
        switch (mode) {
        case 0:
            *(s32*)(p + 0x234) = 0x85;
            break;
        case 1:
            *(s32*)(p + 0x234) = 0x7d;
            break;
        case 2:
            *(s32*)(p + 0x234) = 0x2ab;
            break;
        case 3:
            *(s32*)(p + 0x234) = 0x1aa;
            break;
        case 4:
        case 14:
            *(s32*)(p + 0x234) = 0x1c3;
            break;
        case 6:
        case 8:
            src = fn_8023E724(mode & 3);
            *(f32*)(p + 0xc) = src[0];
            *(f32*)(p + 0x10) = src[1];
            *(f32*)(p + 0x14) = src[2];
            *(f32*)(p + 0xc) += lbl_8053FFF0;
            *(f32*)(p + 0x14) += lbl_8053FFF4;
            *(s32*)(p + 0x234) = 0x2a3;
            break;
        case 7:
        case 9:
            src = fn_8023E724(mode & 3);
            *(f32*)(p + 0xc) = src[0];
            *(f32*)(p + 0x10) = src[1];
            *(f32*)(p + 0x14) = src[2];
            *(f32*)(p + 0xc) -= lbl_8053FFF0;
            *(f32*)(p + 0x14) += lbl_8053FFF4;
            *(s32*)(p + 0x234) = 0x2a3;
            break;
        case 10:
            *(s32*)(p + 0x234) = 0x2f5;
            break;
        case 11:
            *(s32*)(p + 0x234) = 0x306;
            break;
        case 12:
            *(s32*)(p + 0x234) = 0x30c;
            break;
        case 13:
            *(s32*)(p + 0x234) = 0x300;
            break;
        }
    }
    *(u8*)(p + 0x11f) = 1;
}

