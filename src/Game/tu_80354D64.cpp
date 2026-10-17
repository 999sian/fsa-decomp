#include "Game/Actor.h"


extern "C" char __vt__4MRTA[];
extern "C" void fn_801EE434(...);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_8013CC50(u32, void*, u16, s32, f32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(void*, u32, u32);
extern "C" void detach__5ActorFv(void*);
extern "C" u16 fn_8022461C(f32* pos);
extern "C" s32 v17__5ActorFiPf(void* this_, s32 room, f32* pos);
extern "C" s32 fn_801F132C(void* this_, s32 a, s32 b, void* state);
extern "C" s32 fn_8035533C(void* this_, s32 param2, f32* param3) {
    u8* p = (u8*)this_;
    if (*(s32*)(p + 0x230) == 0) {
        s32 kind = fn_8022461C(param3);
        if (kind == 0x27 || kind == 3) {
            return 0;
        }
        if (kind == 4 || kind == 0x28 || kind == 0x2c) {
            if (((s32)param3[1] & 0xf) >= 8) {
                return 0;
            }
        } else if (kind == 5 || kind == 0x29 || kind == 0x2d) {
            if (((s32)param3[1] & 0xf) < 8) {
                return 0;
            }
        } else if (kind == 6 || kind == 0x2a || kind == 0x2e) {
            if (((s32)param3[0] & 0xf) >= 8) {
                return 0;
            }
        } else if (kind == 7 || kind == 0x2b || kind == 0x2f) {
            if (((s32)param3[0] & 0xf) < 8) {
                return 0;
            }
        }
        return v17__5ActorFiPf(this_, param2, param3);
    }
    return fn_801F132C(this_, param2, (s32)param3, p + 0x2b8);
}

extern "C" void fn_803554B8(void* this_)
{
    u8* p = (u8*)this_;
    u16 id0;
    u16 id1;
    u16 id2;

    switch (*(s32*)(p + 0x2c0)) {
    case 0:
        switch (*(s32*)(p + 0x2c4)) {
        case 0:
            id0 = 0xa1;
            id1 = 0xa2;
            id2 = 0xa3;
            break;
        case 1:
            id0 = 0x9b;
            id1 = 0x9c;
            id2 = 0x9d;
            break;
        }
        break;
    case 1:
        switch (*(s32*)(p + 0x2c4)) {
        case 0:
            id0 = 0xa4;
            id1 = 0xa5;
            id2 = 0xa6;
            break;
        case 1:
            id0 = 0x9e;
            id1 = 0x9f;
            id2 = 0xa0;
            break;
        }
        break;
    }
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, id0, 1, 1.0f, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, id1, 1, 1.0f, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, id2, 1, 1.0f, 0, 0, 0, 1);
    fn_801F0E34(this_, 0x30003, 0);
    detach__5ActorFv(this_);
}

extern "C" void fn_80356268(void* this_) {
    u8* p = (u8*)this_;
    *(s32*)(p + 0x2c0) = *(u32*)(p + 0x90) & 1;
    *(s32*)(p + 0x2c4) = (*(u32*)(p + 0x90) >> 4) & 1;
    *(s32*)(p + 0x2c8) = (*(u32*)(p + 0x90) >> 8) & 1;
    *(s32*)(p + 0x1a4) = 2;
    switch (*(s32*)(p + 0x2c8)) {
    case 0:
        switch (*(s32*)(p + 0x2c0)) {
        case 0:
            switch (*(s32*)(p + 0x2c4)) {
            case 0:
                *(f32*)(p + 0x60) = -46.0f;
                *(f32*)(p + 0x64) = -7.0f;
                *(f32*)(p + 0x68) = 46.0f;
                *(f32*)(p + 0x6c) = 7.0f;
                *(f32*)(p + 0x80) = -47.0f;
                *(f32*)(p + 0x84) = -7.0f;
                *(f32*)(p + 0x88) = 47.0f;
                *(f32*)(p + 0x8c) = 7.0f;
                break;
            case 1:
                *(f32*)(p + 0x60) = -46.0f;
                *(f32*)(p + 0x64) = -14.0f;
                *(f32*)(p + 0x68) = 46.0f;
                *(f32*)(p + 0x6c) = 14.0f;
                *(f32*)(p + 0x80) = -47.0f;
                *(f32*)(p + 0x84) = -15.0f;
                *(f32*)(p + 0x88) = 47.0f;
                *(f32*)(p + 0x8c) = 15.0f;
                break;
            }
            break;
        case 1:
            switch (*(s32*)(p + 0x2c4)) {
            case 0:
                *(f32*)(p + 0x60) = -7.0f;
                *(f32*)(p + 0x64) = -46.0f;
                *(f32*)(p + 0x68) = 7.0f;
                *(f32*)(p + 0x6c) = 46.0f;
                *(f32*)(p + 0x80) = -7.0f;
                *(f32*)(p + 0x84) = -47.0f;
                *(f32*)(p + 0x88) = 7.0f;
                *(f32*)(p + 0x8c) = 47.0f;
                break;
            case 1:
                *(f32*)(p + 0x60) = -14.0f;
                *(f32*)(p + 0x64) = -46.0f;
                *(f32*)(p + 0x68) = 14.0f;
                *(f32*)(p + 0x6c) = 46.0f;
                *(f32*)(p + 0x80) = -15.0f;
                *(f32*)(p + 0x84) = -47.0f;
                *(f32*)(p + 0x88) = 15.0f;
                *(f32*)(p + 0x8c) = 47.0f;
                break;
            }
            break;
        }
        break;
    case 1:
        *(f32*)(p + 0x60) = -15.0f;
        *(f32*)(p + 0x64) = -23.0f;
        *(f32*)(p + 0x68) = 15.0f;
        *(f32*)(p + 0x6c) = 7.0f;
        *(f32*)(p + 0x80) = -15.0f;
        *(f32*)(p + 0x84) = -23.0f;
        *(f32*)(p + 0x88) = 15.0f;
        *(f32*)(p + 0x8c) = 7.0f;
        *(f32*)(p + 0x70) = -15.0f;
        *(f32*)(p + 0x74) = -23.0f;
        *(f32*)(p + 0x78) = 15.0f;
        *(f32*)(p + 0x7c) = 7.0f;
        break;
    }
    *(s32*)(p + 0x234) = -1;
    *(u8*)(p + 0x264) = 0;
    *(u8*)(p + 0x268) = 1;
    *(f32*)(p + 0x274) = 0.0f;
    *(f32*)(p + 0x270) = 0.0f;
    *(f32*)(p + 0x26c) = 0.0f;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x238) = -1;
    *(u8*)(p + 0x265) = 0;
    *(u8*)(p + 0x27c) = 1;
    *(f32*)(p + 0x288) = 0.0f;
    *(f32*)(p + 0x284) = 0.0f;
    *(f32*)(p + 0x280) = 0.0f;
    *(s32*)(p + 0x28c) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(u8*)(p + 0x266) = 0;
    *(u8*)(p + 0x290) = 1;
    *(f32*)(p + 0x29c) = 0.0f;
    *(f32*)(p + 0x298) = 0.0f;
    *(f32*)(p + 0x294) = 0.0f;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x240) = -1;
    *(u8*)(p + 0x267) = 0;
    *(u8*)(p + 0x2a4) = 1;
    *(f32*)(p + 0x2b0) = 0.0f;
    *(f32*)(p + 0x2ac) = 0.0f;
    *(f32*)(p + 0x2a8) = 0.0f;
    *(s32*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x25c) = -1;
    *(s32*)(p + 0x260) = -1;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0xb8) = 2;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2d0) = -1;
    *(f32*)(p + 0x2dc) = 0.0f;
    *(f32*)(p + 0x2d8) = 0.0f;
    *(f32*)(p + 0x2d4) = 0.0f;
    *(u8*)(p + 0x2cc) = 0;
    *(s32*)(p + 0x2e0) = 0;
}

extern "C" Actor* fn_80356514(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = __vt__4MRTA;
        void* v0 = *(void**)((char*)p + 0x2e0);
        if (v0 != 0) {
            fn_801EE434(v0);
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
