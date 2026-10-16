#include "types.h"
#include "Game/ItemBase.h"

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

