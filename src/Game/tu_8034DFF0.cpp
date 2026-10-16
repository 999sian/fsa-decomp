#include "Game/Actor.h"

struct YnswVirt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual u8 v11();
    virtual void v12(); virtual u8 v13();
};
extern const f32 lbl_805425CC;
extern const f32 lbl_805425D0;
extern const f32 lbl_805425D4;


extern "C" char __vt__4YNSW[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8034DFF0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4YNSW;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8034EAB4(char* this_) {
    *(f32*)(this_ + 0x80) = lbl_805425D0;
    *(f32*)(this_ + 0x84) = lbl_805425D0;
    *(f32*)(this_ + 0x88) = lbl_805425D4;
    *(f32*)(this_ + 0x8c) = lbl_805425D4;
    *(f32*)(this_ + 0x60) = lbl_805425D0;
    *(f32*)(this_ + 0x64) = lbl_805425D0;
    *(f32*)(this_ + 0x68) = lbl_805425D4;
    *(f32*)(this_ + 0x6c) = lbl_805425D4;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x238);
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(u8*)(this_ + 0x24c) = 0;
    *(u8*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x25c) = lbl_805425CC;
    *(f32*)(this_ + 0x258) = lbl_805425CC;
    *(f32*)(this_ + 0x254) = lbl_805425CC;
    *(u8*)(this_ + 0x24d) = 0;
    *(u8*)(this_ + 0x251) = 0;
    *(f32*)(this_ + 0x268) = lbl_805425CC;
    *(f32*)(this_ + 0x264) = lbl_805425CC;
    *(f32*)(this_ + 0x260) = lbl_805425CC;
    *(u8*)(this_ + 0x24e) = 0;
    *(u8*)(this_ + 0x252) = 0;
    *(f32*)(this_ + 0x274) = lbl_805425CC;
    *(f32*)(this_ + 0x270) = lbl_805425CC;
    *(f32*)(this_ + 0x26c) = lbl_805425CC;
    *(u8*)(this_ + 0x24f) = 0;
    *(u8*)(this_ + 0x253) = 0;
    *(f32*)(this_ + 0x280) = lbl_805425CC;
    *(f32*)(this_ + 0x27c) = lbl_805425CC;
    *(f32*)(this_ + 0x278) = lbl_805425CC;
    *(s32*)(this_ + 0x230) = 0;
    if (*(s32*)(this_ + 0x234) == 1 && (u8)((YnswVirt*)this_)->v13() == 1) {
        *(s32*)(this_ + 0x238) = 2;
        *(s32*)(this_ + 0x230) = 4;
    }
}

