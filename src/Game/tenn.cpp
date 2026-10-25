// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A0710-801A35AC (TENN). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern const char lbl_804684E8[];
extern const f32 lbl_8053E4F0;
extern const f32 lbl_8053E4F4;
extern const f32 lbl_8053E4F8;
extern const f32 lbl_8053E4FC;
extern const f32 lbl_8053E504;
extern const f32 lbl_8053E53C;
extern const f32 lbl_8053E554;
extern const f32 lbl_8053E594;
extern const f32 lbl_8053E598;
extern const f32 lbl_8053E59C;
extern const f32 lbl_8053E5A0;
extern const f32 lbl_8053E5A4;
extern const f32 lbl_8053E5A8;
extern const f32 lbl_8053E5AC;
extern s32 lbl_804A2B90[];
extern s32 lbl_8053ABC0;
extern u8 lbl_8053ABC4;
extern u8 lbl_8053ABC5;
extern f32 lbl_8053A0F8;
extern const f32 lbl_8053E500;
extern const f32 lbl_8053E538;
extern const f32 lbl_8053E540;
extern const f32 lbl_8053E55C;
extern const f32 lbl_8053E518;
extern const f32 lbl_8053E51C;
extern const f32 lbl_8053E544;
extern const f32 lbl_8053E548;
extern const f32 lbl_8053E54C;
extern const f32 lbl_8053E550;
extern const f32 lbl_8053E558;
extern char* lbl_8053AAF8;
extern void* lbl_8053AB10;

// from src/Game/fn_801A0710.cpp
extern "C" void fn_801A0910(void* this_);
extern "C" void fn_801A0754(void* this_);

// TENN (vtable lbl_804A2BF4, ctor fn_80201294) cluster, part 1/9.
// draw() dispatcher - calls 2 sub-pieces (fn_801A0754/fn_801A0910).
extern "C" void fn_801A0710(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x274);
    if (state == 0) {
        goto call0910;
    }
    if (state < 0) {
        goto skip;
    }
    if (state >= 3) {
        goto skip;
    }
    goto call0754;
call0910:
    fn_801A0910(this_);
    goto skip;
call0754:
    fn_801A0754(this_);
skip:
    return;
}

extern "C" void fn_801A0754(void* this_) {
    DrawRec rec;
    f32 m[3][4];

    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;

    if (*(s32*)((char*)this_ + 0x274) == 2) {
        m[0][0] = 2.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 2.0f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 2.0f;
        rec.w18 = m;
        rec.w30 = 0x11;
        ((u8*)&rec)[0x13] = (u8)(s32)*(f32*)((char*)this_ + 0x340);
        fn_801F06F0(this_, lbl_804684E8, *(s32*)((char*)this_ + 0x264) + 0x2ba, &rec, 0, 1.0f, 1.0f);
    }
}

// from src/Game/Tenn_update_801A0B8C.cpp
extern "C" void fn_801A17B8(void* this_);
extern "C" void fn_801A0F90(void* this_);
extern "C" void fn_801A0BE4(void* this_);

// TENN cluster, part 4/9 (88B). update() dispatcher - routes to 3
// private state handlers (fn_801A0BE4/fn_801A0F90/fn_801A17B8, landed
// alongside).
extern "C" void fn_801A0B8C(void* this_) {
    switch (*(s32*)((char*)this_ + 0x274)) {
        case 0: fn_801A17B8(this_); break;
        case 1: fn_801A0F90(this_); break;
        case 2: fn_801A0BE4(this_); break;
    }
}

extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_801F71A4(f32*, f32, f32, f32);
extern "C" u8 fn_801F2740(void*, s32);
extern "C" void fn_8022F3DC(void);
extern "C" u8 fn_801F2B7C(void*, s32, s32, s32);
extern "C" s32 fn_801F285C(void*, f32*, u32*, u32, s32);
extern "C" u16 fn_8023CBC0(s32);
extern "C" u8 fn_802353AC(s32);
extern "C" s32 fn_80138A30(void*);
extern "C" void fn_8023B6CC(s32);
extern "C" void fn_80230FD0(s32, s32);
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_80230188(s32);
extern "C" void fn_801EEC98(void*, s32, s16*, s32, s32, s32, s32, s32);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_8023E724(s32);
extern "C" s32 fn_801F2718(void*, u32);
extern "C" void fn_8030C210(void*);
extern "C" void fn_801A0F90(void* this_) {
    char* p = (char*)this_;
    s32 r31 = 0;
    s16 ang;
    f32 scale;
    s32 cnt;
    s32 idx;

    *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + *(f32*)(p + 0x3c);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + *(f32*)(p + 0x40);
    *(f32*)(p + 0x14) = *(f32*)(p + 0x14) + *(f32*)(p + 0x44);
    fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24));

    switch (*(s32*)(p + 0x230)) {
    case 0x10: {
        s32 r29 = fn_801F2718(this_, 0x54454e4e);
        if (*(f32*)(p + 0x14) > lbl_8053E4F0) {
            fn_801F0E34(this_, 0x3004c, 0);
            *(f32*)(p + 0x14) = lbl_8053E4F0;
            *(f32*)(p + 0x44) = lbl_8053E51C;
        } else {
            *(f32*)(p + 0x44) = *(f32*)(p + 0x44) - lbl_8053E548;
        }
        if (lbl_8053ABC4 == 1 && r29 >= 0) {
            char* obj = (char*)fn_801F666C(fn_801F856C(), r29);
            if (obj != 0) {
                *(s32*)(obj + 0x258) = 1;
                *(s32*)(p + 0x230) = 0xe;
            }
        }
        return;
    }
    case 0x11:
        fn_801F71A4((f32*)(p + 0x340), lbl_8053E4F0, lbl_8053E544, lbl_8053E518);
        return;
    case 0xe:
        *(s32*)(p + 0x230) = 0xf;
        break;
    case 0xf:
        break;
    default:
        return;
    }

    if (*(f32*)(p + 0x3c) == lbl_8053E4F0 && *(f32*)(p + 0x40) == lbl_8053E4F0) {
        if (*(f32*)(p + 0x14) > lbl_8053E4F0) {
            fn_801F0E34(this_, 0x3004c, 0);
            *(f32*)(p + 0x14) = lbl_8053E4F0;
            *(f32*)(p + 0x44) = lbl_8053E518;
        } else {
            *(f32*)(p + 0x44) = *(f32*)(p + 0x44) - lbl_8053E544;
        }
        return;
    }
    if (*(f32*)(p + 0x14) > lbl_8053E4F0) {
        fn_801F0E34(this_, 0x3004c, 0);
        *(f32*)(p + 0x14) = lbl_8053E4F0;
        *(f32*)(p + 0x44) = lbl_8053E51C;
    } else {
        *(f32*)(p + 0x44) = *(f32*)(p + 0x44) - lbl_8053E548;
    }
    fn_801F71A4((f32*)(p + 0x14), lbl_8053E500, lbl_8053E548, lbl_8053E4F8);
    if (*(s32*)(p + 0x23c) != 0) return;

    *(f32*)(p + 0x60) = lbl_8053E54C;
    *(f32*)(p + 0x64) = lbl_8053E54C;
    *(f32*)(p + 0x68) = lbl_8053E550;
    *(f32*)(p + 0x6c) = lbl_8053E550;
    {
        u8 r = fn_801F2740(this_, -1);
        if (r != 0) {
            s32 v = r;
            idx = 0;
            while (v > 0) {
                v >>= 1;
                idx++;
            }
            idx--;
            if (idx < 0) idx = 0;
            if (*(s32*)(p + 0x264) != idx) {
                fn_8022F3DC();
                if (*(s32*)(p + 0x264) != idx) goto l_a8c;
            }
            if (fn_801F2B7C(this_, 0, -1, 1)) {
                fn_801F0E34(this_, 0x3004d, 0);
                r31 = 1;
                lbl_8053ABC5 = 1;
                return;
            }
        }
    }
l_a8c:
    *(f32*)(p + 0x60) = lbl_8053E554;
    *(f32*)(p + 0x64) = lbl_8053E554;
    *(f32*)(p + 0x68) = lbl_8053E53C;
    *(f32*)(p + 0x6c) = lbl_8053E53C;
    *(s32*)(p + 0x278) = fn_801F285C(this_, 0, 0, 1, -1);
    if (*(s32*)(p + 0x278) < 0) return;
    if (*(s32*)(p + 0x264) != *(s32*)(p + 0x278)) {
        fn_8022F3DC();
        if (*(s32*)(p + 0x264) != *(s32*)(p + 0x278)) return;
    }
    {
        u16 c = fn_8023CBC0(*(s32*)(p + 0x278));
        if (c >= 0x43 && c < 0x6f) return;
    }
    scale = lbl_8053A0F8;
    if (fn_802353AC(*(s32*)(p + 0x264))) scale = scale * lbl_8053E558;
    *(s32*)(p + 0x264) += 1;
    cnt = fn_80138A30(lbl_8053AAF8);
    if (*(s32*)(p + 0x264) >= cnt) *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x248) += 1;
    fn_8023B6CC(*(s32*)(p + 0x278));
    fn_80230FD0(*(s32*)(p + 0x278), 0x2003f);
    cnt = fn_80138A30(lbl_8053AAF8);
    if (*(s32*)(p + 0x248) >= cnt) {
        *(s32*)(p + 0x248) = 0;
        *(s32*)(p + 0x264) = 4;
        return;
    }
    if (fn_8023F264(*(s32*)(p + 0x264))) {
        if (*(s32*)(p + 0x4) != fn_8023DE58(*(s32*)(p + 0x264))) return;
        if (fn_80230188(*(s32*)(p + 0x264))) return;
        fn_801EEC98(this_, *(s32*)(p + 0x198), &ang, 0, 0, 0, *(s32*)(p + 0x264), 2);
    }
    {
        char* game = lbl_8053AAF8;
        u32 seed = *(u32*)(game + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits;
        f32 rf;
        *(u32*)(game + 0xb4) = seed;
        bits = (seed >> 9) | 0x3f800000;
        rf = *(f32*)&bits - lbl_8053E4FC;
        if (rf >= lbl_8053E544) ang += 0x600;
        else ang -= 0x600;
    }
    *(f32*)(p + 0x3c) = JMath::sincosTable_.mTable[(u16)ang >> 5].first * scale;
    *(f32*)(p + 0x40) = JMath::sincosTable_.mTable[(u16)ang >> 5].second * scale;
    *(s32*)(p + 0x23c) = 0x1e;
    (void)r31;
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_8022AF2C(void);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_80458508(void* snd, s32 a);
extern char* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern void* lbl_8053AF80;

struct Handles_tenn { u8 pad[0x344]; void* h[4]; };
// TENN destructor
extern void* lbl_804A2BF4[];
extern "C" void* fn_801A2F90(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2BF4;
        if (*(s32*)(this_ + 0x274) == 0) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 5 || state == 6) {
                fn_8022AF2C();
                if (*(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            fn_801EE434(((Handles_tenn*)this_)->h[i]);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801A3068(char* this_) {
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x2c8) = 0;
    *(s32*)(this_ + 0x2cc) = 0;
    *(s32*)(this_ + 0x2d0) = 0;
    *(s32*)(this_ + 0x2d4) = 0;
    *(s32*)(this_ + 0x2d8) = 0;
    *(s32*)(this_ + 0x2dc) = 0;
    *(s32*)(this_ + 0x2e0) = 0;
    *(s32*)(this_ + 0x2e4) = 0;
    *(s32*)(this_ + 0x2e8) = 0;
    *(s32*)(this_ + 0x2ec) = 0;
    *(s32*)(this_ + 0x2f0) = 0;
    *(s32*)(this_ + 0x2f4) = 0;
    *(s32*)(this_ + 0x2f8) = 0;
    *(s32*)(this_ + 0x2fc) = 0;
    *(s32*)(this_ + 0x300) = 0;
    *(s32*)(this_ + 0x304) = 0;
    *(s32*)(this_ + 0x308) = 0;
    *(s32*)(this_ + 0x30c) = 0;
    *(s32*)(this_ + 0x310) = 0;
    *(s32*)(this_ + 0x314) = 0;
    *(s32*)(this_ + 0x28c) = 0;
    *(s32*)(this_ + 0x27c) = -1;
    *(s32*)(this_ + 0x29c) = 0;
    *(s32*)(this_ + 0x2ac) = 0;
    *(u8*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x344) = 0;
    *(s32*)(this_ + 0x290) = 0;
    *(s32*)(this_ + 0x280) = -1;
    *(s32*)(this_ + 0x2a0) = 0;
    *(s32*)(this_ + 0x2b0) = 0;
    *(u8*)(this_ + 0x2bd) = 0;
    *(s32*)(this_ + 0x348) = 0;
    *(s32*)(this_ + 0x294) = 0;
    *(s32*)(this_ + 0x284) = -1;
    *(s32*)(this_ + 0x2a4) = 0;
    *(s32*)(this_ + 0x2b4) = 0;
    *(u8*)(this_ + 0x2be) = 0;
    *(s32*)(this_ + 0x34c) = 0;
    *(s32*)(this_ + 0x298) = 0;
    *(s32*)(this_ + 0x288) = -1;
    *(s32*)(this_ + 0x2a8) = 0;
    *(s32*)(this_ + 0x2b8) = 0;
    *(u8*)(this_ + 0x2bf) = 0;
    *(s32*)(this_ + 0x350) = 0;
    *(s32*)(this_ + 0x31c) = 0;
    *(s32*)(this_ + 0x2c4) = -1;
    *(s32*)(this_ + 0x318) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(s32*)(this_ + 0x268) = 0;
    *(f32*)(this_ + 0x33c) = lbl_8053E4F0;
    *(f32*)(this_ + 0x324) = lbl_8053E4FC;
    *(f32*)(this_ + 0x328) = lbl_8053E4FC;
    *(f32*)(this_ + 0x32c) = lbl_8053E4FC;
    *(f32*)(this_ + 0x330) = lbl_8053E4FC;
    *(f32*)(this_ + 0x334) = lbl_8053E4FC;
    *(f32*)(this_ + 0x338) = lbl_8053E4FC;
    *(f32*)(this_ + 0x340) = lbl_8053E594;
    *(s32*)(this_ + 0x278) = -1;
    *(s32*)(this_ + 0x2c0) = 0;
    *(s32*)(this_ + 0x320) = -1;
    *(s32*)(this_ + 0x26c) = 0;
    *(u8*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x274) = *(s32*)(this_ + 0x90) & 0xf;

    switch (*(s32*)(this_ + 0x274)) {
    case 0:
        if (*(s32*)(this_ + 0x238) == 0) {
            *(s32*)(this_ + 0x264) = lbl_804A2B90[*(s32*)(this_ + 0x248) + *(s32*)(this_ + 0x98) * 4];
            if ((*(s32*)(this_ + 0x248) & 1) == 0) {
                *(s32*)(this_ + 0x238) = 12;
            } else {
                *(s32*)(this_ + 0x238) = 10;
            }
            *(s32*)(this_ + 0x248) = *(s32*)(this_ + 0x248) + 1;
            *(s32*)(this_ + 0x248) = *(s32*)(this_ + 0x248) & 3;
        }
        *(s32*)(this_ + 0xb0) = 0xa040004;
        *(f32*)(this_ + 0x60) = lbl_8053E598;
        *(f32*)(this_ + 0x64) = lbl_8053E59C;
        *(f32*)(this_ + 0x68) = lbl_8053E5A0;
        *(f32*)(this_ + 0x6c) = lbl_8053E5A4;
        *(f32*)(this_ + 0x70) = lbl_8053E5A8;
        *(f32*)(this_ + 0x74) = lbl_8053E554;
        *(f32*)(this_ + 0x78) = lbl_8053E5AC;
        *(f32*)(this_ + 0x7c) = lbl_8053E53C;
        *(s32*)(this_ + 0x98) = 2;
        lbl_8053ABC0 = 0;
        lbl_8053ABC5 = 0;
        lbl_8053ABC4 = 0;
        lbl_8053A0F8 = lbl_8053E4F8;
        u8 cVar4 = (*(u8 (**)(char*))(*(s32*)this_ + 0x34))(this_);
        if (cVar4 != 0) {
            *(s32*)(this_ + 0x230) = 0xb;
        } else {
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    case 1:
        *(s32*)(this_ + 0x108) = 10000;
        *(f32*)(this_ + 0x60) = lbl_8053E554;
        *(f32*)(this_ + 0x64) = lbl_8053E554;
        *(f32*)(this_ + 0x68) = lbl_8053E53C;
        *(f32*)(this_ + 0x6c) = lbl_8053E53C;
        *(f32*)(this_ + 0x80) = lbl_8053E504;
        *(f32*)(this_ + 0x84) = lbl_8053E504;
        *(f32*)(this_ + 0x88) = lbl_8053E4F8;
        *(f32*)(this_ + 0x8c) = lbl_8053E4F8;
        *(s32*)(this_ + 0x230) = 0xe;
        break;
    case 2:
        *(s32*)(this_ + 0x108) = 10000;
        *(f32*)(this_ + 0x60) = lbl_8053E554;
        *(f32*)(this_ + 0x64) = lbl_8053E554;
        *(f32*)(this_ + 0x68) = lbl_8053E53C;
        *(f32*)(this_ + 0x6c) = lbl_8053E53C;
        *(f32*)(this_ + 0x80) = lbl_8053E504;
        *(f32*)(this_ + 0x84) = lbl_8053E504;
        *(f32*)(this_ + 0x88) = lbl_8053E4F8;
        *(f32*)(this_ + 0x8c) = lbl_8053E4F8;
        *(s32*)(this_ + 0x230) = 0x12;
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
