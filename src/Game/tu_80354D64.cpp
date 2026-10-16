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
