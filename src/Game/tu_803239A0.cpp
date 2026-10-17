#include "Game/ItemBase.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804AB3A8[];
struct FsaParam {
    s32 w0;
    s32 w1;
    s32 w2;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    s32 w3;
    u8 b11;
    u8 b12;
    u8 b13;
    s32 w4;
    s32 w5;
    s32 w6;
};

extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80541B70;
extern "C" char lbl_8047184C[];
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_802F86CC(void*, void*, void*, f32, f32, s32, void*);
extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, s32 id, void* ext);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" void* fn_802D6A9C(void);
extern "C" s32 lbl_80541B68;
extern "C" s32 lbl_80541B6C;
extern "C" void fn_803239A0(char* this_) {
    u8 tbl[16];
    FsaParam p;
    u8 i;
    p.w0 = -1;
    p.w1 = -1;
    for (i = 0; i < 0x10; i += 8) {
        tbl[i] = i;
        tbl[(u8)(i + 1)] = i + 1;
        tbl[(u8)(i + 2)] = i + 2;
        tbl[(u8)(i + 3)] = i + 3;
        tbl[(u8)(i + 4)] = i + 4;
        tbl[(u8)(i + 5)] = i + 5;
        tbl[(u8)(i + 6)] = i + 6;
        tbl[(u8)(i + 7)] = i + 7;
    }
    p.w2 = 0;
    p.b0 = 0;
    p.b1 = 0;
    p.b2 = 0;
    p.b3 = 1;
    p.b4 = 1;
    p.b5 = 0;
    p.b6 = 1;
    p.w3 = 3;
    p.b7 = 1;
    p.w4 = -1;
    p.w5 = 0;
    p.w6 = 2;
    if (*(s16*)(this_ + 0x94) == 1 && *(s32*)(this_ + 4) < 8) {
        void* obj = *(void**)((char*)lbl_8053AAF8 + 0xa4);
        void* res = (void*)(*(void*(**)(void*, u32, char*))(*(void***)obj)[6])(obj, 0x534F4220, lbl_8047184C);
        fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), this_ + 0xc, res, lbl_80541B70, lbl_80541B70, 0xe7, tbl);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, 0xe7, 0, 2, -1, 0, 0, 0);
}

extern "C" void* fn_80324570(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB3A8;
        fn_801EE434(*(void**)(this_ + 0x26c));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" f32 lbl_80541B74;
extern "C" f32 lbl_80541B78;
extern "C" f32 lbl_80541B7C;
extern "C" f32 lbl_80541B80;
extern "C" f32 lbl_80541B84;
extern "C" f32 lbl_80541B90;
extern "C" f32 lbl_80541BB0;
extern "C" f32 lbl_80541BB4;
extern "C" f32 lbl_80541BB8;
extern "C" f32 lbl_80541BBC;
extern "C" f32 lbl_80541BC0;
extern "C" f32 lbl_80541BC4;
extern "C" void fn_80324AC4(char* this_) {
    u32 bits;
    f32 frac;
    s32 room;
    f32 b;
    f32 a;
    f32 fb = lbl_80541B90;
    f32 fa = lbl_80541BB0;
    *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 7;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 8) & 3;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 3;
    *(u8*)(this_ + 0x268) = 0;
    *(u8*)(this_ + 0x269) = 0;
    *(void**)(this_ + 0x26c) = 0;
    *(f32*)(this_ + 0x80) = fa;
    *(f32*)(this_ + 0x84) = fa;
    *(f32*)(this_ + 0x88) = fb;
    *(f32*)(this_ + 0x8c) = fb;
    *(u32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0x250) = 0;
    *(u32*)(this_ + 0x254) = 0;
    *(u32*)(this_ + 0x238) = 0;
    *(u32*)(this_ + 0x23c) = 0;
    *(u32*)(this_ + 0x240) = 0;
    *(u32*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x248) = 0;
    switch (*(u32*)(this_ + 0x98)) {
    case 0:
        b = lbl_80541B78;
        a = lbl_80541B74;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = b;
        break;
    case 1:
        b = lbl_80541B78;
        a = lbl_80541B7C;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = b;
        break;
    case 2:
        b = lbl_80541B74;
        a = lbl_80541B78;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = a;
        break;
    case 3:
        b = lbl_80541B7C;
        a = lbl_80541B78;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = a;
        break;
    case 4:
        b = lbl_80541B80;
        a = lbl_80541B80;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = lbl_80541B78;
        break;
    case 5:
        b = lbl_80541B80;
        a = lbl_80541B84;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = lbl_80541B78;
        break;
    case 6:
        b = lbl_80541B84;
        a = lbl_80541B80;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = lbl_80541B78;
        break;
    case 7:
        b = lbl_80541B84;
        a = lbl_80541B84;
        *(f32*)(this_ + 0x3c) = a;
        *(f32*)(this_ + 0x40) = b;
        *(f32*)(this_ + 0x44) = lbl_80541B78;
        break;
    }
    *(f32*)(this_ + 0x234) = lbl_80541BB4;
    *(u32*)(this_ + 0x240) = 500;
    *(f32*)(this_ + 0x274) = lbl_80541B78;
    room = *(s32*)(this_ + 4);
    *(u8*)(this_ + 0x278) = *((u8*)fn_802D6A9C() + room + 0x131df);
    if (*(u16*)(this_ + 0x94) == 1) {
        room = *(s32*)(this_ + 4);
        if (*((u8*)fn_802D6A9C() + room + 0x131df) == 0) {
            *(u32*)((char*)lbl_8053AAF8 + 0xb4) = *(u32*)((char*)lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits = (*(u32*)((char*)lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
            frac = *(f32*)&bits - lbl_80541B70;
            *(f32*)(this_ + 0x44) = lbl_80541BB8 + lbl_80541BBC * frac;
        } else {
            *(u32*)((char*)lbl_8053AAF8 + 0xb4) = *(u32*)((char*)lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits = (*(u32*)((char*)lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
            frac = *(f32*)&bits - lbl_80541B70;
            *(f32*)(this_ + 0x270) = lbl_80541BB8 + lbl_80541BBC * frac;
            *(u32*)((char*)lbl_8053AAF8 + 0xb4) = *(u32*)((char*)lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits = (*(u32*)((char*)lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
            frac = *(f32*)&bits - lbl_80541B70;
            *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x40) - (lbl_80541BC0 + lbl_80541BC4 * frac);
        }
    } else if (*(u16*)(this_ + 0x94) == 0 && *(void**)(this_ + 0x26c) == 0) {
        *(void**)(this_ + 0x26c) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_80541B70, 0x35d, 0, 1, 0, 0, 1);
    }
    *(u32*)(this_ + 0x25c) = 0;
    *(u32*)(this_ + 0x260) = 0;
    *(u32*)(this_ + 0x264) = 0;
    *(u32*)(this_ + 0x108) = 10000;
    *(u32*)(this_ + 0x230) = 0;
    *(u8*)(this_ + 0x26a) = 0;
}

