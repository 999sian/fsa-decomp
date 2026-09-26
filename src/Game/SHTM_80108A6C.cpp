// SHTM_80108A6C: .text 0x80108A6C-0x80109534 (actor SHTM)
// NOTE: all code matches. Not linkable as Matching yet: fn_80108C34 has three
// switch jump tables in .data (0x8049CE14-0x8049CE70) that sit after the SHTM
// vtable (0x8049CDC0); needs a .data split, i.e. SHTM as a real Actor subclass
// emitting its own vtable (see Game/actors/BOTS.cpp).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/fn_80108A6C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CDC0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80108A6C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CDC0;
        if (p + 0x230 != 0) {
            if (p + 0x254 != 0) {
                *(void**)(p + 0x254) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_80108AEC: draw
extern "C" void v06__5ActorFv(void* this_);
struct SHTM_DrawKey {
    s32 a, b;
    SHTM_DrawKey() { a = -1; b = -1; }
};
struct SHTM_DrawParam {
    u8 map[16];      // 0x00
    SHTM_DrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    SHTM_DrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_8046404C[];
extern const f32 lbl_8053C368;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, SHTM_DrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);

extern "C" void fn_80108AEC(u8* this_) {
    v06__5ActorFv(this_);
    SHTM_DrawParam param;
    fn_801F02BC(this_, lbl_8046404C, *(s32*)(this_ + 0x240) + 0x17B, &param, 7, 0, 0, lbl_8053C368, lbl_8053C368);
}

// ---- fn_80108C34: shop counter update (buy item for a player)
extern "C" void v03__5ActorFv(void* this_);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_8022FEB8(void*, s32, void*, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_802300EC(void);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" s32 fn_8030AAF4(s32);
extern "C" u32 fn_80309D6C(void*, s32, u32);
extern void* lbl_8053AD30;
extern "C" u8 fn_8038AD24(s32, u32, void*, s32, JGeometry::TVec3f, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" void fn_8038470C(s32, u32);
extern "C" s32 fn_80237774(s32);
extern "C" s32 fn_80236228(s32);
extern "C" u8 fn_80388CAC(s32, void*);
extern "C" void fn_802308E0(s32);
extern "C" void fn_802362C4(s32, s32);
extern "C" void fn_8023764C(s32, s32);
extern "C" void fn_80235FE8(s32);
extern "C" void fn_802372F8(s32, s32, s32);
extern "C" void* fn_8023E724(s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" u8 fn_80230188(s32);
extern "C" void fn_8023061C(s32, s32);
extern "C" void detach__5ActorFv(void* this_);
extern const u16 lbl_80464028[8];
extern const u32 lbl_8046403C[4];

struct SHTM_Box {
    f32 x0, y0, x1, y1;
};

extern "C" void fn_80108C34(u8* this_) {
    v03__5ActorFv(this_);
    SHTM_Box b;
    b.x0 = *(f32*)(this_ + 0x60);
    b.y0 = *(f32*)(this_ + 0x64);
    b.x1 = *(f32*)(this_ + 0x68);
    b.y1 = *(f32*)(this_ + 0x6C);
    b.x0 += *(f32*)(this_ + 0xC);
    b.y0 += *(f32*)(this_ + 0x10);
    b.x1 += *(f32*)(this_ + 0xC);
    b.y1 += *(f32*)(this_ + 0x10);
    switch (*(s32*)(this_ + 0x26C)) {
    case 0: {
        fn_80239914(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198));
        fn_8022FEB8(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 0, 0);
        s32 pad;
        s32 slot = fn_8022FD8C(*(void**)(this_ + 0x198));
        if (slot >= 0 && fn_802300EC()) {
            pad = slot;
            if (fn_8022F514(slot)) {
                pad = fn_8022F3DC(slot);
            }
            if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(pad), 0x120)) {
                void* room = *(void**)(this_ + 0x198);
                s32 player = *(s32*)(this_ + 4);
                if (fn_8038AD24(slot, lbl_8046403C[0], room, player, *(JGeometry::TVec3f*)(this_ + 0x278), 0x28)) {
                    *(s32*)(this_ + 0x270) = slot;
                    *(s32*)(this_ + 0x26C) = 1;
                }
            }
        }
        break;
    }
    case 1:
        fn_8022FEB8(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(this_ + 0x270))) {
            switch (fn_8037EFB4(*(s32*)(this_ + 0x270))) {
            case 0: {
                u8 ok;
                s32 p = *(s32*)(this_ + 0x270);
                switch (*(s32*)(this_ + 0x268)) {
                case 2:
                    if (fn_80237774(p) > lbl_80464028[*(s32*)(this_ + 0x268)]) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                    break;
                case 0:
                case 1:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    if (fn_80236228(p) >= lbl_80464028[*(s32*)(this_ + 0x268)]) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                    break;
                default:
                    ok = 0;
                    break;
                }
                if (ok) {
                    fn_80388CAC(*(s32*)(this_ + 0x270), *(void**)(this_ + 0x198));
                    fn_802308E0(*(s32*)(this_ + 0x270));
                    *(s32*)(this_ + 0x26C) = 2;
                } else {
                    fn_8038470C(*(s32*)(this_ + 0x270), lbl_8046403C[2]);
                    *(s32*)(this_ + 0x26C) = 5;
                }
                break;
            }
            case 1:
            default:
                fn_8038470C(*(s32*)(this_ + 0x270), lbl_8046403C[3]);
                *(s32*)(this_ + 0x26C) = 4;
                break;
            }
        }
        break;
    case 2: {
        s32 p = *(s32*)(this_ + 0x270);
        if (p >= 0) {
            *(u8*)(this_ + 0x11D) = 0;
            switch (*(s32*)(this_ + 0x268)) {
            case 0:
                fn_802362C4(p, -lbl_80464028[0]);
                break;
            case 1:
                fn_802362C4(p, -lbl_80464028[1]);
                break;
            case 2:
                fn_8023764C(p, fn_80237774(p) - lbl_80464028[2]);
                break;
            case 3:
                fn_802362C4(p, -lbl_80464028[3]);
                break;
            case 4:
                fn_802362C4(p, -lbl_80464028[4]);
                fn_80235FE8(p);
                fn_802372F8(p, 9, 1);
                break;
            case 5:
                fn_802362C4(p, -lbl_80464028[5]);
                fn_80235FE8(p);
                fn_802372F8(p, 4, 1);
                break;
            case 6:
                fn_802362C4(p, -lbl_80464028[6]);
                fn_80235FE8(p);
                fn_802372F8(p, 3, 1);
                break;
            case 7:
                fn_802362C4(p, -lbl_80464028[7]);
                fn_80235FE8(p);
                fn_802372F8(p, 6, 1);
                break;
            }
        }
        u32 param = 0;
        *(s32*)(this_ + 0x26C) = 3;
        switch (*(s32*)(this_ + 0x268)) {
        case 2:
            param |= 0x4;
            break;
        case 0:
            param |= 0x40020;
            break;
        case 1:
            param |= 0x50000;
            break;
        case 3:
            param |= 0x40014;
            break;
        case 4:
            param |= 0x10008;
            break;
        case 5:
            param |= 0x10003;
            break;
        case 6:
            param |= 0x10002;
            break;
        case 7:
            param |= 0x10005;
            break;
        }
        s32 who = *(s32*)(this_ + 0x270);
        param |= who << 24;
        param |= who << 26;
        Actor_CreateByID(fn_801F856C(), 0x494D5550, *(s32*)(this_ + 4), fn_8023E724(who), param, -1, -1);
        break;
    }
    case 3:
        if (!fn_80230188(*(s32*)(this_ + 0x270))) {
            fn_8023061C(*(s32*)(this_ + 0x270), 0);
            *(s32*)(this_ + 0x26C) = 6;
        }
        break;
    case 4:
        fn_8022FEB8(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(this_ + 0x270), *(void**)(this_ + 0x198))) {
            *(s32*)(this_ + 0x26C) = 0;
            *(s32*)(this_ + 0x270) = -1;
        }
        break;
    case 5:
        fn_8022FEB8(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(this_ + 0x270), *(void**)(this_ + 0x198))) {
            *(s32*)(this_ + 0x26C) = 0;
            *(s32*)(this_ + 0x270) = -1;
        }
        break;
    case 6:
        *(s32*)(this_ + 0x270) = -1;
        detach__5ActorFv(this_);
        break;
    }
    fn_801D1C18(this_ + 0x230);
}

// ---- fn_801091EC: init
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern void* lbl_8049CDA0[];
extern const f32 lbl_8053C36C;
extern const f32 lbl_8053C370;
extern const f32 lbl_8053C374;
extern const f32 lbl_8053C378;

extern "C" void fn_801091EC(u8* this_) {
    v01__5ActorFv(this_);
    *(f32*)(this_ + 0x60) = lbl_8053C36C;
    *(f32*)(this_ + 0x64) = lbl_8053C36C;
    *(f32*)(this_ + 0x68) = lbl_8053C370;
    *(f32*)(this_ + 0x6C) = lbl_8053C370;
    *(f32*)(this_ + 0x80) = lbl_8053C36C;
    *(f32*)(this_ + 0x84) = lbl_8053C36C;
    *(f32*)(this_ + 0x88) = lbl_8053C370;
    *(f32*)(this_ + 0x8C) = lbl_8053C370;
    *(s32*)(this_ + 0x108) = 0;
    *(s32*)(this_ + 0x268) = *(u32*)(this_ + 0x90) & 0xFF;
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0xC);
    *(f32*)(this_ + 0x27C) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x280) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x27C) -= lbl_8053C374;
    fn_801D2608(this_ + 0x230, lbl_8049CDA0, 8);
    fn_801D22DC(this_ + 0x230, *(s32*)(this_ + 0x268), 2, 0);
    fn_801D1F14(this_ + 0x230, lbl_8053C378);
}

// ---- from Game/fn_801092B0_ctor.cpp

struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);
extern void* lbl_8049CDC0[];

class fn_801092B0_actor : public Actor {
public:
    fn_801092B0_actor();
};

fn_801092B0_actor::fn_801092B0_actor() : Actor() {
    *(void**)this = lbl_8049CDC0;
    char* p = (char*)this;
    fn_801D267C(p + 0x230);
    *(s32*)(p + 0x268) = 8;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = -1;
    *(s32*)(p + 0x274) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
