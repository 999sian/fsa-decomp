#include "types.h"


extern "C" char lbl_804A8C80[];
extern "C" void __dt__5ActorFv(void*, int);
void operator delete(void*);
extern "C" f32 lbl_80540C40;
extern "C" f32 lbl_80540C38;
extern "C" f32 lbl_80540C44;
extern "C" char lbl_8046D54C[];
extern "C" u8* lbl_8053AB10;
extern "C" void fn_801F06F0(void* a, const char* name, s32 id, void* rec, s32 p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80158B5C(void*, s32, void*, void*, f32);
extern "C" u8* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(u8* a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_8022461C(s32 a, s32 b);
extern "C" s32 fn_80226850(s32 a, s32 b);
extern "C" u8* fn_802D6A9C(void);

struct Rec {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0c;
    u32 w10;
    u32 w14;
    u32 w18;
    u8 b1c;
    u8 b1d;
    u8 b1e;
    u8 b1f;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    u8 b24;
    u8 b25;
    u8 b26;
    u32 w28;
    u8 b2c;
    u8 b2d;
    u8 b2e;
    u32 w30;
    u32 w34;
    u32 w38;
};

struct Col4 {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    Col4() {}
    Col4(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
};
extern "C" void* fn_802BFB7C(void* p, s16 flags) {
    if (p != 0) {
        *(char**)p = lbl_804A8C80;
        __dt__5ActorFv(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" u32 fn_8022F514(s32 a);
extern "C" s32 fn_8022F3DC(s32 a);
extern "C" BOOL fn_802308E0(s32 a);
extern "C" BOOL fn_8023077C(s32 a);
extern "C" void fn_8037AE30(void* a);
extern "C" void* fn_8023E724(s32 a);
extern "C" s32 fn_8023DE58(s32 a);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* a, u32 id, void* rec, void* d, s32 e, s32 f, s32 g);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D6F38(void* a, void* b, void* c, s32 d);
extern "C" BOOL fn_802BFF30(u8* this_, s32 room) {
    s32 v26 = room;
    s32 v22 = room;
    s32 v3;
    s32 i;
    u32 base;

    v22 = room;
    if (fn_8022F514(room)) {
        v26 = fn_8022F3DC(room);
    }
    return 1;
}

extern "C" void fn_802C0278(char* p) {
    Col4 col;
    Col4 tmp;
    Rec rec;
    s32 iVar1;
    u8* buf;
    u32 i;

    if (*(s32*)(p + 0x230) == 1) {
        return;
    }
    iVar1 = *(s32*)(p + 4);
    if (iVar1 == 0) {
        buf = (u8*)&rec;
        rec.w10 = -1;
        rec.w14 = -1;
        for (i = 0; (u8)i < 0x10; i += 8) {
            buf[(u8)i] = i;
            buf[(u8)(i + 1)] = i + 1;
            buf[(u8)(i + 2)] = i + 2;
            buf[(u8)(i + 3)] = i + 3;
            buf[(u8)(i + 4)] = i + 4;
            buf[(u8)(i + 5)] = i + 5;
            buf[(u8)(i + 6)] = i + 6;
            buf[(u8)(i + 7)] = i + 7;
        }
        rec.w18 = 0;
        rec.w10 = -1;
        rec.w14 = 0;
        rec.b1c = 0;
        rec.b1d = 0;
        rec.b1e = 0;
        rec.b1f = 1;
        rec.b20 = 1;
        rec.b21 = 0;
        rec.b22 = 0;
        rec.b23 = 0;
        rec.b24 = 0;
        rec.b25 = 0;
        rec.b26 = 1;
        rec.w28 = 3;
        rec.b2c = 1;
        rec.b2d = 0;
        rec.b2e = 0;
        rec.w30 = -1;
        rec.w34 = 0;
        rec.w38 = 2;
        buf[0x13] = (u8)*(s32*)(p + 0x24c);
        if (*(f32*)(p + 0x14) != lbl_80540C40) {
            fn_801F06F0(p, lbl_8046D54C, *(s32*)(p + 0x238) + 0x40, &rec, 0, lbl_80540C38, lbl_80540C38);
        } else if (*(s32*)(p + 0x23c) == 2) {
            fn_801F06F0(p, lbl_8046D54C, *(s32*)(p + 0x238) + 0x20c, &rec, 0, lbl_80540C38, lbl_80540C38);
        } else {
            fn_801F06F0(p, lbl_8046D54C, *(s32*)(p + 0x238) + 0x182, &rec, 0, lbl_80540C38, lbl_80540C38);
        }
    } else if ((*(s32*)(p + 0x248) == 0 || (*(s32*)(p + 0x248) & 3) == 0) &&
               (*(s32*)(p + 0x254) >= 0x78 || (*(s32*)(p + 0x254) != 0 && (*(s32*)(p + 0x254) & 3) == 0))) {
        if (*(f32*)(p + 0x14) != lbl_80540C40) {
            fn_803075AC(*(void**)(p + 0x198), iVar1, p + 0xc, *(s32*)(p + 0x238) + 0x40, 0, 2, -1, 0, 0, 0);
        } else if (*(s32*)(p + 0x23c) == 2) {
            fn_803075AC(*(void**)(p + 0x198), iVar1, p + 0xc, *(s32*)(p + 0x238) + 0x20c, 0, 2, -1, 0, 0, 0);
        } else {
            fn_803075AC(*(void**)(p + 0x198), iVar1, p + 0xc, *(s32*)(p + 0x238) + 0x182, 0, 2, -1, 0, 0, 0);
        }
    }
    tmp = Col4(0, 0, 0, 0x80);
    col = tmp;
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), *(s32*)(p + 4), p + 0xc, &col, lbl_80540C44);
}

extern "C" void fn_802C0EE0(char* p) {
    f32 z = lbl_80540C40;
    *(f32*)(p + 0x44) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x3c) = z;
    *(s32*)(p + 0x248) = 0;
    if (*(s32*)(p + 0x254) < 0xb4) {
        *(s32*)(p + 0x254) = 0xb4;
    }
    *(s32*)(p + 0x24c) = 0xff;
    *(s32*)(p + 0x250) = 1;
}

