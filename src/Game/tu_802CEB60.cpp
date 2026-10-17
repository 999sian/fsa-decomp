#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

typedef JGeometry::TVec3<f32> YasiVec;
extern "C" f32 lbl_80540E48;
extern "C" f32 lbl_80540E58;
extern "C" f32 lbl_80540E5C;
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" u16 fn_8022461C(YasiVec* pos, u32 room);
extern "C" u8 fn_802DE9A0();
extern "C" u8 fn_802DEB58();
extern "C" void fn_802CEC10(char* p);
BOOL fn_802CF598(char* p);
void* fn_801F856C();
void fn_801F0E34(void* a, u32 code, u32 z);
s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void fn_801F132C(void* a, void* b, void* c, void* d);
extern "C" char lbl_804A92D0[];

struct Vt802CEBC0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" void* fn_802CEB60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A92D0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802CEBC0(Vt802CEBC0* p) {
    p->m7();
}

extern "C" void fn_802CEBEC(void* this_, void* b, void* c) {
    fn_801F132C(this_, b, c, (char*)this_ + 0x23c);
}

extern "C" void fn_802CF130(char* p) {
    if (*(s32*)(p + 0x4) >= 8) {
        YasiVec pos(*(YasiVec*)(p + 0xc));
        pos.z = lbl_80540E48;
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(p + 0x4), &pos, 4, -1, -1);
        if (*(s32*)(p + 0x238) == 0) {
            fn_801F0E34(p, 0x30006, 0);
        } else if (*(s32*)(p + 0x238) == 1) {
            fn_801F0E34(p, 0x5002f, 0);
        }
    } else if (*(s32*)(p + 0x238) == 0) {
        if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xd || fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0x39) {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x3d0, 0, 1, 0, 0, 1);
            fn_801F0E34(p, 0x30022, 0);
        } else if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xe) {
            if (fn_802DE9A0()) {
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x2a9, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x2aa, 0, 0, 0, 0, 1);
                fn_801F0E34(p, 0x5005f, 0);
            } else if (fn_802DEB58()) {
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x45e, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x45f, 0, 0, 0, 0, 1);
                fn_801F0E34(p, 0x5003f, 0);
            }
        } else {
            fn_802CF598(p);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E5C, 0x357, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x30006, 0);
            *(s32*)(p + 0x234) = 2;
            fn_802CEC10(p);
        }
    } else if (*(s32*)(p + 0x238) == 1) {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E5C, 0x358, 0, 0, 0, 0, 1);
        fn_801F0E34(p, 0x5002f, 0);
        fn_802CEC10(p);
    }
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_801F02BC(void* a, u8* p2, s32 p3, DrawRec* p4, s32 p5, s32 p6, u8 p7, f32 f6, f32 f7);
extern "C" s32 fn_8023CB24(s32 a);
extern "C" s32 fn_8023CA88(s32 a);
extern "C" u8 lbl_8046DFB8[];
extern "C" f32 lbl_80540E58;
extern "C" void fn_802CF408(char* p) {
    if (*(s32*)(p + 0x238) != 2) {
        s32 n = 7;
        DrawRec rec;
        ((u8*)&rec.w10)[3] = *(u8*)(p + 0x244);
        if (*(u8*)(p + 0xc4) != 0) {
            rec.b20 = 0;
            n = -1;
            rec.b1d = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
            rec.b1c = fn_8023CA88(*(s32*)(p + 0xc8));
        }
        fn_801F02BC(p, lbl_8046DFB8, 0x27, &rec, n, 0, 1, lbl_80540E58, lbl_80540E58);
    }
}

void* fn_802D6A9C();
void* fn_801F856C();
void* fn_801F666C(void* mgr, s32 idx);
s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
void fn_801F0E34(void* a, u32 code, u32 z);
s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern f32 lbl_80540E58;
BOOL fn_802CF598(char* p) {
    f32 x0 = *(f32*)(p + 0x60) + *(f32*)(p + 0xc);
    f32 y0 = *(f32*)(p + 0x64) + *(f32*)(p + 0x10);
    f32 x1 = *(f32*)(p + 0x68) + *(f32*)(p + 0xc);
    f32 y1 = *(f32*)(p + 0x6c) + *(f32*)(p + 0x10);
    s32 room = *(s32*)(p + 0x4);
    f32* o;
    s32 prev = -1;
    s32 id;
    char* obj;
    f32 ox0;
    f32 oy0;
    f32 ox1;
    f32 oy1;

    fn_802D6A9C();
    if (room < 8) {
        o = (f32*)(p + 0xcc);
    } else {
        o = (f32*)(p + 0xdc);
    }
    x0 -= o[0];
    y0 -= o[1];
    x1 -= o[0];
    y1 -= o[1];
    for (;;) {
        id = fn_801F78F4(fn_801F856C(), 0x424c5a32, prev);
        prev = id;
        if (id < 0) {
            return 0;
        }
        if (id == *(s32*)(p + 0x198)) {
            continue;
        }
        obj = (char*)fn_801F666C(fn_801F856C(), id);
        if (obj == NULL) {
            continue;
        }
        fn_802D6A9C();
        room = *(s32*)(obj + 0x4);
        if (room < 8) {
            o = (f32*)(obj + 0xcc);
        } else {
            o = (f32*)(obj + 0xdc);
        }
        ox0 = *(f32*)(obj + 0x60) + *(f32*)(obj + 0xc) - o[0];
        oy0 = *(f32*)(obj + 0x64) + *(f32*)(obj + 0x10) - o[1];
        ox1 = *(f32*)(obj + 0x68) + *(f32*)(obj + 0xc) - o[0];
        oy1 = *(f32*)(obj + 0x6c) + *(f32*)(obj + 0x10) - o[1];
        if (ox0 > x0) {
            ox0 = x0;
        }
        if (oy0 > y0) {
            oy0 = y0;
        }
        if (ox1 < x1) {
            ox1 = x1;
        }
        if (oy1 < y1) {
            oy1 = y1;
        }
        if (ox1 < ox0 && oy1 < oy0) {
            fn_801F0E34(p, 0x3002f, 0);
            fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540E58, 0x1a2, 1, 0, 0, 0, 1);
            return 1;
        }
    }
}

extern "C" s32 fn_8013CC50(s32 a, char* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_802CFABC(char* p) {
    *(s32*)(p + 0x230) = *(s32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x234) = (*(s32*)(p + 0x90) >> 0x10) & 0xf;
    *(s32*)(p + 0x238) = (*(s32*)(p + 0x90) >> 0x14) & 0xf;
    *(u8*)(p + 0x244) = 0xff;
    *(f32*)(p + 0x60) = -4.0f;
    *(f32*)(p + 0x64) = -4.0f;
    *(f32*)(p + 0x68) = 4.0f;
    *(f32*)(p + 0x6c) = 4.0f;
    *(f32*)(p + 0x80) = -4.0f;
    *(f32*)(p + 0x84) = -4.0f;
    *(f32*)(p + 0x88) = 4.0f;
    *(f32*)(p + 0x8c) = 4.0f;
    *(s32*)(p + 0x23c) = 0;
    *(u8*)(p + 0x245) = 0;
    if (*(s32*)(p + 0x238) == 2) {
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x3d1, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x3d2, 0, 0, 0, 0, 1);
        *(s32*)(p + 0x240) = 0x1e;
    }
}



