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
extern const f32 lbl_805425C0;
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern char lbl_80472210[];
extern "C" void fn_802F86CC(u32, char*, u32, s32, f32, f32, void*);
extern "C" void fn_80307AC8(s32, s32, char*, s32, s32, s32, s32);

struct SlotVirt6 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual u32 v06(u32 a, char* b);
};
struct Init48 {
    u8 idx[0x10];
    s32 w18;
    s32 w1c;
    s32 w20;
    s8 b24[0xb];
    s32 w30;
    u8 b34[3];
    s32 w38;
    s32 w3c;
    s32 w40;
};


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

extern "C" void fn_8034E2F0(char* this_) {
    Init48 s;
    u8 i;
    s.w18 = -1;
    s.w1c = -1;
    for (i = 0; i < 0x10; i += 8) {
        s.idx[i] = i;
        s.idx[(u8)(i + 1)] = i + 1;
        s.idx[(u8)(i + 2)] = i + 2;
        s.idx[(u8)(i + 3)] = i + 3;
        s.idx[(u8)(i + 4)] = i + 4;
        s.idx[(u8)(i + 5)] = i + 5;
        s.idx[(u8)(i + 6)] = i + 6;
        s.idx[(u8)(i + 7)] = i + 7;
    }
    s.w18 = -1;
    s.w1c = 0;
    s.w20 = 0;
    s.b24[0] = 0;
    s.b24[1] = 0;
    s.b24[2] = 0;
    s.b24[3] = 1;
    s.b24[4] = 1;
    s.b24[5] = 0;
    s.b24[6] = 0;
    s.b24[7] = 0;
    s.b24[8] = 0;
    s.b24[9] = 0;
    s.b24[10] = 1;
    s.w30 = 3;
    s.b34[0] = 1;
    s.b34[1] = 0;
    s.b34[2] = 0;
    s.w38 = -1;
    s.w3c = 0;
    s.w40 = 2;
    s.b24[1] = -3;
    s.b24[0] = 0;
    s32 iVar1 = *(s32*)(this_ + 0x238);
    if (*(s32*)(this_ + 0x4) < 8) {
        u32 uVar2 = ((SlotVirt6*)*(char**)(lbl_8053AAF8 + 0xa4))->v06(0x534f4220, lbl_80472210);
        fn_802F86CC(*(u32*)(lbl_8053AB10 + 0x20), this_ + 0xc, uVar2, iVar1 + 0xd, lbl_805425C0, lbl_805425C0, &s);
    }
    fn_80307AC8(*(s32*)(this_ + 0x198), *(s32*)(this_ + 0x4), this_ + 0xc, *(s32*)(this_ + 0x238) + 0xd, 0, 0, -1);
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
    if (*(s32*)(this_ + 0x234) == 1 && (u8)((YnswVirt*)this_)->v11() == 1) {
        *(s32*)(this_ + 0x238) = 2;
        *(s32*)(this_ + 0x230) = 4;
    }
}

