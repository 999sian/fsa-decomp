#include "Game/Actor.h"


extern "C" char __vt__4MRTA[];
extern "C" void fn_801EE434(...);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_8013CC50(u32, void*, u16, s32, f32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(void*, u32, u32);
extern "C" void detach__5ActorFv(void*);
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
