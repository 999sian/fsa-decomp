// TU 0x803287F0-0x80328D6C.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804AB580[];
extern "C" void* fn_803287F0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB580;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

struct Vec2 {
    f32 x, y;
};
struct Box {
    void add(const Vec2& p) {
        x0 += p.x;
        y0 += p.y;
        x1 += p.x;
        y1 += p.y;
    }
    f32 x0, y0, x1, y1;
};
struct ActorV {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10(s32 a, s32 b);
    virtual u8 s11();
};

extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" void fn_8013CC50(u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_80239914(Box* box, u32 room, u32 id);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8023BB50(Box* box, u32 room, Vec2* pos, s32 a);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);
extern "C" void fn_802379E4(s32 player, void* pos);
extern "C" void fn_80239638(u32 id);

static const s32 lbl_804718E8[7] = {0, 1, 2, 3, 4, 3, 4};

extern "C" void fn_80328850(u8* this_) {
    fn_801F06F0(this_, "enemy_gc_sob.bin", lbl_804718E8[*(s32*)(this_ + 0x23c)] + 0x12f, 0, 0, 1.0f, 1.0f);
}

// NonMatching: float register allocation/scheduling of the two box offsets
// differs (retail adds a.y0 first); control flow and calls match.
extern "C" void fn_803288A0(u8* this_) {
    if ((*(u32*)(this_ + 0x90) & 1) == 1 && ((ActorV*)this_)->s11() == 1) {
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x503, 1, 0, 0, 0, 1, 1.0f);
        this_[0x11c] = 0;
        return;
    }
    Box a;
    a.x0 = ((Box*)(this_ + 0x70))->x0;
    a.y0 = ((Box*)(this_ + 0x70))->y0;
    a.x1 = ((Box*)(this_ + 0x70))->x1;
    a.y1 = ((Box*)(this_ + 0x70))->y1;
    Box b;
    b.x0 = -4.0f;
    b.y0 = -4.0f;
    b.x1 = 4.0f;
    b.y1 = 4.0f;
    Vec2 pos;
    f32 y = *(f32*)(this_ + 0x10);
    f32 x = *(f32*)(this_ + 0xc);
    pos.x = x;
    pos.y = y;
    a.add(pos);
    b.add(pos);
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
    case 1:
        fn_80239914(&b, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        s32 hit = fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 1);
        s32 player = fn_801F285C(this_, 0, 0, 1, -1);
        if (hit > 0 || player >= 0 || *(s32*)(this_ + 0x9c) >= 0 ||
            fn_8023BB50(&a, *(u32*)(this_ + 4), &pos, 1) >= 0) {
            if (*(s32*)(this_ + 0x230) == 0) {
                fn_801F0E34(this_, 0x50080, 0);
            }
            if (player >= 0) {
                fn_802379E4(player, this_ + 0xc);
            }
            *(s32*)(this_ + 0x230) = 1;
            *(s32*)(this_ + 0x23c) = 0;
        }
        break;
    }
    if (*(s32*)(this_ + 0x230) == 1) {
        fn_80239638(*(u32*)(this_ + 0x198));
        (*(s32*)(this_ + 0x23c))++;
        if (*(s32*)(this_ + 0x23c) >= 7) {
            *(s32*)(this_ + 0x23c) = 0;
            *(s32*)(this_ + 0x230) = 0;
        }
    }
}

extern "C" void fn_80328AC8(u8* this_) {
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x114) = 2;
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0xb0) = 0x1042304;
    *(f32*)(this_ + 0x80) = -5.0f;
    *(f32*)(this_ + 0x84) = -5.0f;
    *(f32*)(this_ + 0x88) = 5.0f;
    *(f32*)(this_ + 0x8c) = 5.0f;
    *(f32*)(this_ + 0x60) = -7.0f;
    *(f32*)(this_ + 0x64) = -7.0f;
    *(f32*)(this_ + 0x68) = 7.0f;
    *(f32*)(this_ + 0x6c) = 7.0f;
    *(f32*)(this_ + 0x70) = -9.0f;
    *(f32*)(this_ + 0x74) = -9.0f;
    *(f32*)(this_ + 0x78) = 9.0f;
    *(f32*)(this_ + 0x7c) = 9.0f;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_80508D64[0x94];
