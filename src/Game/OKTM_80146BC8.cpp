#include "types.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, s32 a, void* b, s32 d, s32 e);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" u16 fn_80226850(void* a, s32 b);
extern "C" void* fn_802D6A9C(void);

extern "C" char lbl_8049F5D8[];
extern "C" void __dt__5ActorFv(Actor*, s32);

struct Tmp16 {
    f32 x;
    f32 y;
    s32 a;
    s32 b;
};

class ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern "C" Actor* fn_80146BC8(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049F5D8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801EF574(const char* name, s32 id, Vec* pos, DrawRec* rec);
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* rec);
extern const char lbl_80465BD8[];
extern const char lbl_80465BEC[];
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern "C" void fn_80146C28(char* this_) {
    DrawRec rec;
    Vec pos;
    Tmp16 cpy;

    *(u8*)((u8*)&rec + 0x13) = *(s32*)(this_ + 0x248);
    switch (*(s32*)(this_ + 0x90)) {
    case 0:
        if (*(s32*)(this_ + 0x4) == 8) {
            void* mgr = fn_802D6A9C();
            Tmp16* cp = &cpy;
            *cp = *(Tmp16*)((u8*)mgr + 0xcc);
            Vec* p = (Vec*)(this_ + 0xc);
            pos.x = p->x + *(f32*)&cp->a;
            pos.y = p->y + *(f32*)&cp->b;
            pos.z = p->z;
            fn_801EF574(lbl_80465BD8, 0x25, &pos, &rec);
            fn_801F02BC(this_, lbl_80465BEC, 0x317, &rec, 1, 0, 0, 1.0f, 1.0f);
        } else {
            fn_801F02BC(this_, lbl_80465BD8, 0x25, &rec, 1, 0, 0, 1.0f, 1.0f);
        }
        break;
    case 4:
        rec.w30 = 0x11;
        fn_801F06F0(this_, lbl_80465BD8, *(s32*)(this_ + 0x24c) + 0xe5, &rec, -1, 1.0f, 1.0f);
        break;
    case 1:
    case 5: {
        s32 id = *(s32*)(this_ + 0x24c) + 0x4c;
        if (*(s32*)(this_ + 0x4) < 8) {
            void* res = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18('SOB ', lbl_80465BEC);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, 1.0f, 1.0f, &rec);
        }
        break;
    }
    case 2:
        fn_801F02BC(this_, lbl_80465BEC, *(s32*)(this_ + 0x24c) + 0x170, &rec, 7, 0, 0, 1.0f, 1.0f);
        break;
    case 3:
        fn_801F02BC(this_, lbl_80465BEC, 0x1ba, 0, 0, 0, 0, 1.0f, 1.0f);
        break;
    }
}

extern "C" u32 fn_80147620(Actor* a, s32 b, void* c) {
    s32 region = a->field_198;
    void* base = fn_8020D58C();
    u8 idx = static_cast<u8*>(base)[1];
    if (fn_8020D6AC(static_cast<u8*>(base) + idx * 0x784 + 4, b, c, region, 0) != 0) {
        return 1;
    }
    s32 kind = fn_8022461C(c, b);
    s32 sub = fn_80226850(c, b);
    if (sub == 0x230 || sub == 0x231) {
        return 0;
    }
    if (kind != 0x0 && kind != 0x4 && kind != 0x5 && kind != 0x6 && kind != 0x7 && kind != 0x2 && kind != 0x3 &&
        kind != 0x50 && kind != 0xe && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 &&
        kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f &&
        kind != 0x20 && kind != 0xd && kind != 0x39 && kind != 0x3a && kind != 0x3b && kind != 0x4c &&
        kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24) {
        if (sub == 0x3a || sub == 0x3d) {
            return 0;
        }
        if (kind == 0x25) {
            return static_cast<u8*>(fn_802D6A9C())[0x171] == 0;
        }
        if (kind == 0x26) {
            return static_cast<u8*>(fn_802D6A9C())[0x171] == 1;
        }
        if (kind != 0x22 || static_cast<u8*>(fn_802D6A9C())[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_80147834(char* this_) {
    *(f32*)(this_ + 0x60) = -2.0f;
    *(f32*)(this_ + 0x64) = -2.0f;
    *(f32*)(this_ + 0x68) = 2.0f;
    *(f32*)(this_ + 0x6c) = 2.0f;
    *(f32*)(this_ + 0x80) = -2.0f;
    *(f32*)(this_ + 0x84) = -2.0f;
    *(f32*)(this_ + 0x88) = 2.0f;
    *(f32*)(this_ + 0x8c) = 2.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x234) = 300;
    *(s32*)(this_ + 0x98) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0x248) = 0xff;
    if (*(s32*)(this_ + 0x90) == 3) {
        *(f32*)(this_ + 0x60) = -6.0f;
        *(f32*)(this_ + 0x64) = -6.0f;
        *(f32*)(this_ + 0x68) = 6.0f;
        *(f32*)(this_ + 0x6c) = 6.0f;
        *(f32*)(this_ + 0x80) = -6.0f;
        *(f32*)(this_ + 0x84) = -6.0f;
        *(f32*)(this_ + 0x88) = 6.0f;
        *(f32*)(this_ + 0x8c) = 6.0f;
    }
    switch (*(s32*)(this_ + 0x90)) {
    case 5:
        *(s32*)(this_ + 0x234) = 10000;
        *(s32*)(this_ + 0x23c) = 300;
    case 1:
        *(s32*)(this_ + 0xb0) = 6;
        break;
    case 2:
        *(s32*)(this_ + 0x238) = 3;
        *(f32*)(this_ + 0x14) = 8.0f;
        *(s32*)(this_ + 0xb0) = 7;
        break;
    }
    *(s32*)(this_ + 0x230) = 0;
}

