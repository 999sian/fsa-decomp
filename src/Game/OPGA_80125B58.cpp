#include "types.h"
#include "JSystem/JGeometry/Vec.h"
struct OPGA_Vec {
    f32 x, y, z;
};

extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
class Actor {
public:
    void v01();
    void v06();
};

extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void*, s32, s32, s32);

struct OpgaVT {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v12(u32 a, u32 b);
    virtual u8 v13();
    virtual void v14();
    virtual int v15();
};
void operator delete(void* p);
extern "C" void* __vt__4OPGA[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053CA70;
extern const f32 lbl_8053CA78;
extern const f32 lbl_8053CA7C;
extern const f32 lbl_8053CA90;
extern const f32 lbl_8053CA94;
extern void* lbl_8049E330[];
extern void* lbl_8049E340[];
extern u8 lbl_80464EE8[];
extern u8 lbl_80464EFC[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern const f32 lbl_8053CA80;
extern const f32 lbl_8053CA84;
extern const f32 lbl_8053CA88;
extern "C" void fn_801F02BC(void*, void*, s32, void*, s32, f32, f32, s32, s32);
extern "C" void fn_802F86CC(void*, void*, s32, void*, f32, f32, s32);
extern "C" void* fn_80125B58(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4OPGA;
        if (this_ + 0x27c != 0) {
            if (this_ + 0x2a0 != 0) {
                *(void**)(this_ + 0x2a0) = lbl_8049CC34;
            }
        }
        if (this_ + 0x244 != 0) {
            if (this_ + 0x268 != 0) {
                *(void**)(this_ + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80125BF4(u8* this_) {
    JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(this_ + 0xc));
    pos.y += lbl_8053CA78;
    fn_8013CC50(*(u32*)(this_ + 4), &pos, 0x33a, 0, 0, 0, 0, 1, lbl_8053CA7C);
}

extern "C" void fn_80125C58(u8* this_, u8 flag) {
    this_[0x231] = flag;
    if (this_[0x231] != 0) {
        switch (*(s32*)(this_ + 0x238)) {
        case 1:
            fn_801D22DC(this_ + 0x27c, 0, 0, 0);
            break;
        case 0:
        default:
            fn_801D22DC(this_ + 0x27c, 1, 0, 0);
            break;
        }
        fn_801D1F14(this_ + 0x27c, lbl_8053CA70);
    }
}

extern "C" void fn_80125CDC(u8* this_) {
    struct {
        u8 idx[16];
        s32 a;
        s32 b;
        s32 c;
        u8 d[11];
        s32 e;
        u8 f[3];
        s32 g;
        s32 h;
        s32 i;
    } local;
    u32 i;
    s32 iVar1;

    ((Actor*)this_)->v06();
    local.a = -1;
    local.b = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        local.idx[(u8)i] = i;
        local.idx[(u8)(i + 1)] = i + 1;
        local.idx[(u8)(i + 2)] = i + 2;
        local.idx[(u8)(i + 3)] = i + 3;
        local.idx[(u8)(i + 4)] = i + 4;
        local.idx[(u8)(i + 5)] = i + 5;
        local.idx[(u8)(i + 6)] = i + 6;
        local.idx[(u8)(i + 7)] = i + 7;
    }
    local.a = -1;
    local.b = 0;
    local.c = 0;
    local.d[0] = 0;
    local.d[1] = 0;
    local.d[2] = 0;
    local.d[3] = 1;
    local.d[4] = 1;
    local.d[5] = 0;
    local.d[6] = 0;
    local.d[7] = 0;
    local.d[8] = 0;
    local.d[9] = 0;
    local.d[10] = 1;
    local.e = 3;
    local.f[0] = 1;
    local.f[1] = 0;
    local.f[2] = 0;
    local.g = -1;
    local.h = 0;
    local.i = 2;

    switch (*(s32*)(this_ + 0x238)) {
    case 1:
        iVar1 = 0x2d2;
        break;
    case 0:
    default:
        iVar1 = 0x2e6;
        break;
    }
    fn_801F02BC(this_, lbl_80464EE8, iVar1 + *(s32*)(this_ + 0x254), local.idx, 0x407, lbl_8053CA7C, lbl_8053CA7C, 0, 0);

    if (this_[0x231] != 0) {
        JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(this_ + 0xc));
        pos.y += lbl_8053CA80;
        if (*(s32*)(this_ + 0x238) == 1) {
            pos.x += lbl_8053CA84;
        } else {
            pos.x += lbl_8053CA88;
        }
        u8* p = *(u8**)(this_ + 0x28c) + 0x2a3;
        if (*(s32*)(this_ + 4) < 8) {
            struct Snd {
                virtual void v02();
                virtual void v03();
                virtual void v04();
                virtual void v05();
                virtual s32 v06(u32 a, void* b);
            };
            Snd* snd = *(Snd**)((u8*)lbl_8053AAF8 + 0xa4);
            s32 r = snd->v06(0x534F4220, lbl_80464EFC);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos, r, p, lbl_8053CA7C, lbl_8053CA7C, 0);
        }
    }
}

extern const f32 lbl_8053CA74;
extern const f32 lbl_8053CA8C;
extern "C" void v03__5ActorFv(void* this_);
extern "C" s32 fn_8022FD8C(s32 handle);
extern "C" u8 fn_802300EC(void);
extern "C" void fn_8022FEB8(f32* box, s32 room, s32 handle, s32 a, s32 b);
extern "C" void fn_8022FF8C(s32 a, f32* box, s32 room, s32 handle, s32 b, s32 c);
extern "C" u8 fn_80388CAC(s32 a, s32 b);
extern "C" u8 fn_8038AD24(s32 a, u16 kind, s32 handle, s32 room, JGeometry::TVec3f* p, s32 e);
extern "C" void fn_80239914(f32* box, s32 room, s32 handle);
extern "C" void fn_8030C210(void* a, void* b);
extern "C" void fn_801D1C18(void* p);
inline s32 opgaSpawn(u8* this_, u16 kind) {
    JGeometry::TVec3f p;
    JGeometry::TVec3f pos;
    f32 b8[4];
    b8[0] = *(f32*)(this_ + 0x60);
    b8[1] = *(f32*)(this_ + 0x64);
    b8[2] = *(f32*)(this_ + 0x68);
    b8[3] = *(f32*)(this_ + 0x6c);
    b8[0] += ((OPGA_Vec*)(this_ + 0xc))->x;
    b8[1] += ((OPGA_Vec*)(this_ + 0xc))->y;
    b8[2] += ((OPGA_Vec*)(this_ + 0xc))->x;
    b8[3] += ((OPGA_Vec*)(this_ + 0xc))->y;
    fn_8022FEB8(b8, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    s32 player = fn_8022FD8C(*(s32*)(this_ + 0x198));
    if (player < 0) return -1;
    if (!fn_802300EC()) return -1;
    pos = *(JGeometry::TVec3f*)(this_ + 0xc);
    pos.y -= lbl_8053CA74;
    p = pos;
    if (fn_8038AD24(player, kind, *(s32*)(this_ + 0x198), *(s32*)(this_ + 4), &p, 0x28)) return player;
    return -1;
}

inline void opgaChangeState(u8* p, s32 state) {
    *(s32*)(p + 0x234) = state;
    switch (*(s32*)(p + 0x234)) {
    case 0: p[0x230] = 0; break;
    case 1:
        ((OpgaVT*)p)->v12(0xff, 1);
        p[0x230] = 1;
        p[0x11d] = 1;
        *(s32*)(p + 0x23c) = -1;
        break;
    case 2: {
        s32 n = *(s32*)(p + 0x240);
        if (n > 0) fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
    } break;
    }
}

extern "C" void fn_80125EFC(u8* this_) {
    f32 box[4];
    v03__5ActorFv(this_);
    box[0] = *(f32*)(this_ + 0x60);
    box[1] = *(f32*)(this_ + 0x64);
    box[2] = *(f32*)(this_ + 0x68);
    box[3] = *(f32*)(this_ + 0x6c);
    box[0] += ((OPGA_Vec*)(this_ + 0xc))->x;
    box[1] += ((OPGA_Vec*)(this_ + 0xc))->y;
    box[2] += ((OPGA_Vec*)(this_ + 0xc))->x;
    box[3] += ((OPGA_Vec*)(this_ + 0xc))->y;
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
        if (((OpgaVT*)this_)->v15() > 0 && ((OpgaVT*)this_)->v13()) {
            if (*(s32*)(this_ + 0x238) == 0) *(s32*)(this_ + 0x98) = 0;
            opgaChangeState(this_, 1);
        }
        break;
    case 1:
    {
        s32 r29;
        switch (*(s32*)(this_ + 0x238)) { case 1: r29=0x4c0; break; case 0: default: r29=0x4bf; break; }
        f32 b8[4];
        b8[0] = *(f32*)(this_ + 0x60);
        b8[1] = *(f32*)(this_ + 0x64);
        b8[2] = *(f32*)(this_ + 0x68);
        b8[3] = *(f32*)(this_ + 0x6c);
        b8[0] += ((OPGA_Vec*)(this_ + 0xc))->x;
        b8[1] += ((OPGA_Vec*)(this_ + 0xc))->y;
        b8[2] += ((OPGA_Vec*)(this_ + 0xc))->x;
        b8[3] += ((OPGA_Vec*)(this_ + 0xc))->y;
        fn_8022FEB8(b8, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        s32 r30 = fn_8022FD8C(*(s32*)(this_ + 0x198));
        if (r30 >= 0 && fn_802300EC()) {
            JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(this_ + 0xc));
            pos.y -= lbl_8053CA74;
            JGeometry::TVec3f p(pos);
            if (!fn_8038AD24(r30, (u16)r29, *(s32*)(this_ + 0x198), *(s32*)(this_ + 4), &p, 0x28)) {
                r30 = -1;
            }
        } else {
            r30 = -1;
        }
        if (r30 >= 0) {
            *(s32*)(this_ + 0x23c) = r30;
            opgaChangeState(this_, 2);
        }
    }
        break;
    case 2:
        fn_8022FF8C(*(s32*)(this_ + 0x23c), box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(this_ + 0x23c), *(s32*)(this_ + 0x198))) opgaChangeState(this_, 1);
        break;
    }
    if (*(s32*)(this_ + 0x234) != 0) {
        fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), this_ + 0xc);
    }
    if (*(u8*)(this_ + 0x230) != 0) {
        fn_80239914(box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
    }
    s32 v = *(s32*)(this_ + 0x98);
    if (v >= 0 && (*(s32*)(this_ + 0x98) = v) != *(s32*)(this_ + 0x24c)) {
        fn_801D22DC(this_ + 0x244, v, 2, 0);
        fn_801D1F14(this_ + 0x244, lbl_8053CA70);
    }
    *(f32*)(this_ + 0x274) = *(u8*)(this_ + 0x231) != 0 ? lbl_8053CA8C : lbl_8053CA7C;
    fn_801D1C18(this_ + 0x244);
    fn_801D1C18(this_ + 0x27c);
    fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), this_ + 0xc);
}

extern "C" void fn_8012639C(u8* this_) {
    ((Actor*)this_)->v01();
    *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x240) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(f32*)(this_ + 0x60) = lbl_8053CA90;
    *(f32*)(this_ + 0x64) = lbl_8053CA90;
    *(f32*)(this_ + 0x68) = lbl_8053CA94;
    *(f32*)(this_ + 0x6c) = lbl_8053CA94;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x84) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x88) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x8c) = *(f32*)(this_ + 0x6c);
    *(s32*)(this_ + 0x98) = 2;
    fn_801D2608(this_ + 0x244, lbl_8049E330, 4);
    fn_801D22DC(this_ + 0x244, 2, 2, 0);
    fn_801D1F14(this_ + 0x244, lbl_8053CA70);
    fn_801D2608(this_ + 0x27c, lbl_8049E340, 4);
    fn_801D22DC(this_ + 0x27c, 0, 0, 0);
    fn_801D1F14(this_ + 0x27c, lbl_8053CA70);
    *(u8*)(this_ + 0x11d) = 0;
    if (((OpgaVT*)this_)->v15() == 0 || ((OpgaVT*)this_)->v13()) {
        *(s32*)(this_ + 0x234) = 1;
        switch (*(s32*)(this_ + 0x234)) {
        case 0:
            *(u8*)(this_ + 0x230) = 0;
            break;
        case 1:
            ((OpgaVT*)this_)->v12(0xff, 1);
            *(u8*)(this_ + 0x230) = 1;
            *(u8*)(this_ + 0x11d) = 1;
            *(s32*)(this_ + 0x23c) = -1;
            break;
        case 2: {
            s32 n = *(s32*)(this_ + 0x240);
            if (n > 0) {
                fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
            }
        } break;
        }
    }
}

void __sinit_OPGA_80125B58_cpp(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
