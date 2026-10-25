#include "Game/Actor.h"

extern "C" {
void* fn_802D6A9C();
void fn_802F9974(void* mgr, s32 room, u32 key, s32 n);
}

static inline s32 clampTileCoordinate(s32 v) {
    s32 r = v;
    if (v < 0) r = 0;
    else if (v >= 0x200) r = 0x1ff;
    return r;
}

struct Box4 {
    f32 a, b, c, d;
};

extern "C" f32 lbl_805408C8;
extern "C" f32 lbl_805408DC;
extern "C" f32 lbl_805408F4;
extern "C" f32 lbl_805408FC;
extern "C" f32 lbl_80540900;
extern "C" f32 lbl_80540904;
extern "C" f32 lbl_80540908;
extern "C" f32 lbl_8054090C;
extern "C" f32 lbl_80540948;
extern "C" f32 lbl_8054094C;
extern "C" f32 lbl_80540950;
extern "C" f32 lbl_80540954;
extern "C" f32 lbl_80540958;
extern "C" f32 lbl_8054095C;
extern "C" s32 lbl_8046C8CC[];
extern "C" s32 lbl_8046C8B0[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;


extern "C" char lbl_804A83A0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802ACEA4(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A83A0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802F745C(void* mgr, void* src, s32 room, void* out);
extern "C" void fn_802F6CF4(void* mgr, void* src, s32 room, void* out);
extern "C" void* fn_802D6A9C();
extern "C" f32 lbl_805408D0;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_805408CC;
extern "C" f32 lbl_805408D8;
extern "C" void fn_802ACF04(Actor* a) {
    u8 tbl[0x10];
    f32 vec[3];
    s32 i;
    s32 kind = *(s32*)((u8*)a + 0x234);
    f32 angle = *(f32*)((u8*)a + 0x248);
    s32 room;

    for (i = 0; i < 0x10; i++) {
        tbl[i] = (u8)i;
    }
    room = a->field_04;
    if (room < 8) {
    }
}

void fn_80239914(s32 room, void* obj);
void* fn_8023E724(s32 idx);
s32 fn_8022F478(s32 idx);
s32 fn_80234F68(s32 idx);
void* fn_801F2718(Actor* a, u32 fourcc);
void fn_8023A89C(void* box, s32 room, void* out);
s32 fn_8023A97C(s32 idx, void* box, s32 room, void* out);
s32 fn_802D800C(void* mgr, s32 idx);
s16 fn_802F9908(void* mgr, s32 room, u32 key);
void fn_8013CC50(s32 room, void* vec, s32 id, s32 f6, s32 f7, s32 f8, s32 f9, s32 f10);
void fn_801F0E34(Actor* a, u32 id, s32 n);
extern "C" f32 lbl_805408EC;
extern "C" f32 lbl_805408F8;
extern "C" void fn_802ADC18(Actor* a) {
    u8* p = (u8*)a;
    Vec pos = a->field_0C;

    switch (*(s32*)(p + 0x234)) {
    case 2:
        a->field_0C.x += lbl_805408EC;
        a->field_0C.y += lbl_805408F4;
        break;
    case 3:
        a->field_0C.x += lbl_805408DC;
        a->field_0C.y += lbl_805408F4;
        break;
    case 4:
    case 5:
        *(f32*)(p + 0x80) = lbl_805408F8;
        *(f32*)(p + 0x84) = lbl_805408F8;
        *(f32*)(p + 0x88) = lbl_805408EC;
        *(f32*)(p + 0x8c) = lbl_805408EC;
        a->field_0C.x += lbl_805408EC;
        a->field_0C.y += lbl_805408EC;
        break;
    default:
        a->field_0C.x += lbl_805408DC;
        a->field_0C.y += lbl_805408DC;
        break;
    }
}

extern "C" void fn_802AEE10(Actor* a) {
    u8* p = (u8*)a;
    s32* ta;
    s32* tb;
    s32 i;
    f32 zero = 0.0f;
    *(s32*)(p + 0x234) = a->field_90 & 0x7f;
    *(s32*)(p + 0x238) = (a->field_90 >> 7) & 0x1f;
    *(s32*)(p + 0x240) = (a->field_90 >> 12) & 0xfff;
    *(s32*)(p + 0x23c) = (a->field_90 >> 24) & 3;
    *(f32*)(p + 0x248) = zero;

    switch (*(s32*)(p + 0x234)) {
    case 6:
    default:
        if (*(s32*)(p + 0x23c) == 1) {
            f32 hi = -20.0f;
            f32 lo = 20.0f;
            a->field_60 = hi;
            a->field_64 = hi;
            a->field_68 = lo;
            a->field_6C = lo;
        } else {
            f32 hi = -32.0f;
            f32 lo = 32.0f;
            a->field_60 = hi;
            a->field_64 = hi;
            a->field_68 = lo;
            a->field_6C = lo;
        }
        break;
    case 2:
        a->field_60 = -40.0f;
        a->field_64 = -32.0f;
        a->field_68 = 40.0f;
        a->field_6C = 32.0f;
        break;
    case 3:
        a->field_60 = -24.0f;
        a->field_64 = -32.0f;
        a->field_68 = 24.0f;
        a->field_6C = 32.0f;
        break;
    case 4:
    case 5:
        a->field_60 = -16.0f;
        a->field_64 = -50.0f;
        a->field_68 = 24.0f;
        a->field_6C = 50.0f;
        *(f32*)(p + 0x248) = -0.06f;
        break;
    }

    *(s32*)(p + 0x244) = 0x14;
    if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
        *(s16*)(p + 0x252) = 12;
    } else {
        *(s16*)(p + 0x252) = 13;
    }

    if (*(s32*)(p + 0x234) >= 2) {
        f32 px = a->field_0C.x;
        s32 room = a->field_04;
        u8* mgr = (u8*)fn_802D6A9C();
        Box4 box = *(Box4*)(room < 8 ? mgr + 0xcc : mgr + 0xdc);
        ta = lbl_8046C8CC;
        tb = lbl_8046C8B0;
        f32 py;
        f32 ry0 = box.b;
        f32 one = 16.0f;
        for (i = 0; i < tb[*(s32*)(p + 0x234)]; i++) {
            s32 xi = (s32)(px - box.a);
            py = a->field_0C.y;
            for (s32 j = 0; j < ta[*(s32*)(p + 0x234)]; j++) {
                s32 x;
                s32 yi = (s32)(py - ry0);
                x = xi;
                if(x < 0) x = 0;
                else if(x >= 0x200) x = 0x1ff;
                if(yi < 0) yi = 0;
                else if(yi >= 0x200) yi = 0x1ff;
                s32 y = yi;
                u32 key = ((y << 1) & 0x200) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf);
                fn_802F9974(*(void**)((u8*)lbl_8053AB10 + 0x20), a->field_04, key, 6);
                py += one;
            }
            px += one;
        }
    }
    *(s32*)(p + 0x230) = 0;
}

