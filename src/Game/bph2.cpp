// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8018A8D8-8018EB94 (BPH2). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JMath/JMath.h"

// from src/Game/Bph2_SetVec2.cpp
// BPH2 cluster, part 5 (final piece). fn_8018E964 - trivial 2-float
// setter, no extab entry (leaf).
extern "C" {

void fn_8018E964(void* thisPtr, f32 a, f32 b) { *(f32*)((char*)thisPtr + 0x0) = a; *(f32*)((char*)thisPtr + 0x4) = b; }

}

// Small (inline-style) accessors.
extern void* lbl_8053AAF8;
extern "C" void* fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8018E30C(char* this_, s32 state);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 p);
extern "C" void fn_802D8050(void* mgr, void* a, void* b, void* c);
extern "C" bool fn_802D800C(void* mgr, void* a);

extern "C" void fn_8018E890(void) {}
extern "C" void fn_8018E894(char* this_, s32 v) { *(s32*)(this_ + 0x234) = v; }
extern "C" void* fn_8018E89C(void) { return fn_80138A30(lbl_8053AAF8); }
extern "C" void fn_8018E8C0(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
extern "C" void fn_8018E8DC(void* a, void* b, void* c) { fn_802D8050(fn_802D6A9C(), a, b, c); }
extern "C" void fn_8018E930(void* a) { fn_802D800C(fn_802D6A9C(), a); }

struct ActorVt_bph2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setShadow(s32 type, f32 x, f32 y);
};
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);

extern "C" void fn_8018A8D8(ActorVt_bph2* this_) {
    fn_801F0E34(this_, 0x40015, 0);
    this_->setShadow(2, 0.0f, 16.0f);
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern "C" void fn_8022ADCC(void);
extern void* lbl_804A1E50[];
extern "C" bool fn_8023F264(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" bool fn_8022F478(s32 idx);
extern "C" bool fn_80230188(s32 idx);
extern "C" void fn_8023061C(s32 idx, s32 p);
extern "C" f32* fn_8023E724(s32 idx);
extern "C" void fn_8023DFF4(s32 idx, f32* pos);
extern "C" bool fn_80236BEC(s32 idx);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7818(void* mgr, u32 name, u32 id, void* list, s32 max);
extern const f32 lbl_8053E0EC;
extern const f32 lbl_8053E0CC;
extern const f32 lbl_8053E100;
extern const f32 lbl_8053E11C;
extern const f32 lbl_8053E110;
extern const f32 lbl_8053E1B0;
extern const f32 lbl_8053E1B8;
extern const f32 lbl_8053E1BC;
extern const f32 lbl_8053E1C0;
extern f32 lbl_8053E0F8;
extern f32 lbl_8053E130;
extern f32 lbl_8053E140;
extern f32 lbl_8053E1B4;
extern const f32 lbl_8053E104;
extern const f32 lbl_8053E0E4;
extern const f32 lbl_8053E0C8;
extern const f32 lbl_8053E0D0;
extern const f32 lbl_8053E0E0;
extern const f32 lbl_8053E124;
extern const f32 lbl_8053E168;
extern const f32 lbl_8053E16C;
extern const f32 lbl_8053E170;
extern const f32 lbl_8053E18C;
extern s32 lbl_80539FC8;
extern s32 lbl_80539FCC;
extern s32 lbl_80539FD0;
extern void* lbl_8053AF80;
extern "C" void fn_80458F9C(void* a, s32 b);
extern u8 lbl_804C18B8[0xC];
extern const f32 lbl_8053E190;
extern const f32 lbl_8053E1C4;
extern const f32 lbl_8053E128;
extern s32 lbl_804A1B70[];
extern "C" void* fn_8013CC50(s32 room, f32* pos, f32 scale, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e);

// BPH2 destructor
extern "C" void* fn_8018D9D4(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1E50;
        fn_801EE434(*(void**)(this_ + 0x328));
        fn_801EE434(*(void**)(this_ + 0x32c));
        fn_801EE434(*(void**)(this_ + 0x330));
        if (*(s32*)(this_ + 0x26c) == 0) {
            fn_802D7440(fn_802D6A9C(), 1);
            fn_8022ADCC();
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8018DA6C(char* this_) {
    s32 v;
    s32 i;
    void* p;

    if (*(u8*)(this_ + 0x27b) == 1) {
        return 0;
    }
    if (fn_802D800C(fn_802D6A9C(), (void*)((*(u32*)(this_ + 0x90) >> 12) & 0x1f)) &&
        fn_802D800C(fn_802D6A9C(), (void*)((*(u32*)(this_ + 0x90) >> 17) & 0x1f)) &&
        fn_802D800C(fn_802D6A9C(), (void*)((*(u32*)(this_ + 0x90) >> 22) & 0x1f)) &&
        fn_802D800C(fn_802D6A9C(), (void*)(*(u32*)(this_ + 0x90) >> 27))) {
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i) && (v = *(s32*)(this_ + 0x4), v == fn_8023DE58(i)) && !fn_8022F478(i) &&
                fn_80230188(i) && *(u8*)(this_ + 0x29c) == 1) {
                fn_8023061C(i, 0);
                *(u8*)(this_ + 0x29c) = 0;
            }
        }
        if (lbl_8053E0F8 != *(f32*)(this_ + 0x284)) {
            *(f32*)(this_ + 0x284) = lbl_8053E0F8;
            *(s32*)(this_ + 0x244) = 0x12c;
            fn_801F0E34(this_, 0x4001f, 0);
        }
        if (*(f32*)(this_ + 0x280) > lbl_8053E1B4) {
            *(s32*)(this_ + 0x27c) = -1;
            p = *(void**)(this_ + 0x328);
            if (p != 0) {
                *(u32*)((char*)p + 0xf4) |= 1;
                *(s32*)((char*)p + 0x24) = 1;
                *(void**)(this_ + 0x328) = 0;
            }
            p = *(void**)(this_ + 0x32c);
            if (p != 0) {
                *(u32*)((char*)p + 0xf4) |= 1;
                *(s32*)((char*)p + 0x24) = 1;
                *(void**)(this_ + 0x32c) = 0;
            }
            p = *(void**)(this_ + 0x330);
            if (p != 0) {
                *(u32*)((char*)p + 0xf4) |= 1;
                *(s32*)((char*)p + 0x24) = 1;
                *(void**)(this_ + 0x330) = 0;
            }
            *(f32*)(this_ + 0x294) = lbl_8053E130;
            *(s32*)(this_ + 0x230) = 6;
            return 1;
        }
    } else {
        *(f32*)(this_ + 0x284) = lbl_8053E140;
    }
    return 0;
}

extern "C" void fn_8018DFCC(char* this_) {
    f32 x = *(f32*)(this_ + 0xc);
    f32 y = *(f32*)(this_ + 0x10);
    f32 z = *(f32*)(this_ + 0x14);
    void* obj;

    x -= lbl_8053E190;
    if (*(s32*)(this_ + 0x26c) == 1) {
        return;
    }
    if (*(s32*)(this_ + 0x268) == 4 || *(s32*)(this_ + 0x268) == 6 || *(s32*)(this_ + 0x268) == 0xb) {
        fn_801F0E34(this_, 0x40049, 0);
    }
    if (*(s32*)(this_ + 0x268) == 2) {
        fn_801F0E34(this_, 0x4004b, 0);
    }
    if (*(s32*)(this_ + 0x234) == 0) {
        switch (*(s32*)(this_ + 0x268)) {
        case 0:
            *(s32*)(this_ + 0x264) += 1;
            if (*(s32*)(this_ + 0x264) > 5) {
                *(s32*)(this_ + 0x264) = 0;
            }
            break;
        case 3:
        case 5:
        case 11:
            *(s32*)(this_ + 0x264) += 1;
            if (*(s32*)(this_ + 0x264) > 7) {
                if (*(s32*)(this_ + 0x268) == 3) {
                    fn_8018E30C(this_, 4);
                } else if (*(s32*)(this_ + 0x268) == 5) {
                    fn_8018E30C(this_, 6);
                } else {
                    *(s32*)(this_ + 0x264) = 7;
                    *(u8*)(this_ + 0x27a) = 1;
                    break;
                }
            } else {
                break;
            }
            /* fallthrough */
        case 4:
        case 6:
            y = y + lbl_8053E128;
            obj = *(void**)(this_ + 0x328);
            if (obj != 0) {
                *(f32*)((char*)obj + 0xa4) = x;
                *(f32*)((char*)obj + 0xa8) = y;
                *(f32*)((char*)obj + 0xac) = z;
            }
            obj = *(void**)(this_ + 0x32c);
            if (obj != 0) {
                *(f32*)((char*)obj + 0xa4) = x;
                *(f32*)((char*)obj + 0xa8) = y;
                *(f32*)((char*)obj + 0xac) = z;
            }
            *(s32*)(this_ + 0x264) += 1;
            *(s32*)(this_ + 0x264) &= 3;
            break;
        case 1:
        case 10:
            *(s32*)(this_ + 0x264) += 1;
            if (*(s32*)(this_ + 0x264) > 7) {
                if (*(s32*)(this_ + 0x268) == 1) {
                    fn_8018E30C(this_, 2);
                } else {
                    *(s32*)(this_ + 0x264) = 7;
                    *(u8*)(this_ + 0x27a) = 1;
                    break;
                }
            } else {
                break;
            }
            /* fallthrough */
        case 2:
            y = y + lbl_8053E1C4;
            obj = *(void**)(this_ + 0x328);
            if (obj != 0) {
                *(f32*)((char*)obj + 0xa4) = x;
                *(f32*)((char*)obj + 0xa8) = y;
                *(f32*)((char*)obj + 0xac) = z;
            }
            obj = *(void**)(this_ + 0x32c);
            if (obj != 0) {
                *(f32*)((char*)obj + 0xa4) = x;
                *(f32*)((char*)obj + 0xa8) = y;
                *(f32*)((char*)obj + 0xac) = z;
            }
            *(s32*)(this_ + 0x264) += 1;
            *(s32*)(this_ + 0x264) &= 3;
            break;
        case 7:
        case 9:
            *(s32*)(this_ + 0x264) += 1;
            if (*(s32*)(this_ + 0x264) > 0x15) {
                if (*(s32*)(this_ + 0x268) == 7) {
                    fn_8018E30C(this_, 8);
                } else {
                    *(s32*)(this_ + 0x264) = 0x15;
                    *(u8*)(this_ + 0x27a) = 1;
                    break;
                }
            } else {
                break;
            }
            /* fallthrough */
        case 8:
            *(s32*)(this_ + 0x264) += 1;
            if (*(s32*)(this_ + 0x264) > 5) {
                *(s32*)(this_ + 0x264) = 0;
            }
            break;
        case 12:
            *(s32*)(this_ + 0x264) += 1;
            if (*(s32*)(this_ + 0x264) > 0xb) {
                fn_8018E30C(this_, 0xd);
                *(u8*)(this_ + 0x27a) = 1;
            }
            break;
        case 13:
            *(s32*)(this_ + 0x264) += 1;
            *(s32*)(this_ + 0x264) &= 3;
            break;
        }
        *(s32*)(this_ + 0x234) = lbl_804A1B70[*(s32*)(this_ + 0x270) + *(s32*)(this_ + 0x264)];
    }
}

extern "C" void fn_8018E30C(char* this_, s32 state) {
    f32 pos[3];
    void* p;

    pos[0] = *(f32*)(this_ + 0xc);
    pos[1] = *(f32*)(this_ + 0x10);
    pos[2] = *(f32*)(this_ + 0x14);
    pos[0] = pos[0] - lbl_8053E190;
    if (*(s32*)(this_ + 0x26c) != 1 && state >= 0 && *(s32*)(this_ + 0x268) != state) {
        *(s32*)(this_ + 0x268) = state;
        *(u8*)(this_ + 0x27a) = 0;
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x264) = 0;
        switch (*(s32*)(this_ + 0x268)) {
        case 0:
            *(s32*)(this_ + 0x270) = 0;
            break;
        case 1:
        case 10:
            fn_801F0E34(this_, 0x4004C, 0);
            *(s32*)(this_ + 0x270) = 6;
            break;
        case 2:
            p = *(void**)(this_ + 0x328);
            if (p != 0) {
                *(u32*)((char*)p + 0xf4) |= 1;
                *(s32*)((char*)p + 0x24) = 1;
            }
            p = *(void**)(this_ + 0x32c);
            if (p != 0) {
                *(u32*)((char*)p + 0xf4) |= 1;
                *(s32*)((char*)p + 0x24) = 1;
            }
            pos[1] = pos[1] + lbl_8053E1C4;
            *(void**)(this_ + 0x328) = fn_8013CC50(*(s32*)(this_ + 0x4), pos, lbl_8053E0D0, 0x54, 1, 2, 0, 0, 1);
            *(void**)(this_ + 0x32c) = fn_8013CC50(*(s32*)(this_ + 0x4), pos, lbl_8053E0D0, 0x55, 1, 2, 0, 0, 1);
            *(s32*)(this_ + 0x270) = 0xe;
            break;
        case 3:
        case 5:
        case 11:
            *(s32*)(this_ + 0x270) = 0x12;
            break;
        case 4:
        case 6:
            p = *(void**)(this_ + 0x328);
            if (p != 0) {
                *(u32*)((char*)p + 0xf4) |= 1;
                *(s32*)((char*)p + 0x24) = 1;
            }
            p = *(void**)(this_ + 0x32c);
            if (p != 0) {
                *(u32*)((char*)p + 0xf4) |= 1;
                *(s32*)((char*)p + 0x24) = 1;
            }
            pos[1] = pos[1] + lbl_8053E128;
            if (*(s32*)(this_ + 0x268) == 4) {
                *(void**)(this_ + 0x328) = fn_8013CC50(*(s32*)(this_ + 0x4), pos, lbl_8053E0D0, 0x52, 1, 2, 0, 0, 1);
                *(void**)(this_ + 0x32c) = 0;
            } else {
                *(void**)(this_ + 0x328) = fn_8013CC50(*(s32*)(this_ + 0x4), pos, lbl_8053E0D0, 0x50, 1, 2, 0, 0, 1);
                *(void**)(this_ + 0x32c) = fn_8013CC50(*(s32*)(this_ + 0x4), pos, lbl_8053E0D0, 0x51, 1, 2, 0, 0, 1);
            }
            *(s32*)(this_ + 0x270) = 0x1a;
            break;
        case 7:
        case 9:
            *(s32*)(this_ + 0x270) = 0x1e;
            break;
        case 8:
            *(s32*)(this_ + 0x270) = 0x34;
            break;
        case 12:
            *(s32*)(this_ + 0x270) = 0x3b;
            break;
        case 13:
            *(s32*)(this_ + 0x270) = 0x47;
            break;
        }
        *(s32*)(this_ + 0x234) = lbl_804A1B70[*(s32*)(this_ + 0x270) + *(s32*)(this_ + 0x264)];
    }
}

extern "C" void fn_8018E5E4(char* this_) {
    f32 zero = lbl_8053E0C8;
    f32 one = lbl_8053E0E4;
    f32 neg = lbl_8053E104;
    *(f32*)(this_ + 0x80) = neg;
    *(f32*)(this_ + 0x84) = neg;
    *(f32*)(this_ + 0x88) = one;
    *(f32*)(this_ + 0x8c) = one;
    *(s32*)(this_ + 0x26c) = *(u32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x2e8) = 0;
    *(f32*)(this_ + 0x2f8) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2fc) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x300) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x2ec) = 0;
    *(f32*)(this_ + 0x304) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x308) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x30c) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x2f0) = 0;
    *(f32*)(this_ + 0x310) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x314) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x318) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x2f4) = 0;
    *(f32*)(this_ + 0x31c) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x320) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x324) = *(f32*)(this_ + 0x14);
    *(f32*)(lbl_804C18B8 + 8) = zero;
    *(f32*)(lbl_804C18B8 + 4) = zero;
    *(f32*)(lbl_804C18B8 + 0) = zero;
    lbl_80539FC8 = -1;
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(f32*)(this_ + 0x280) = zero;
    *(f32*)(this_ + 0x288) = zero;
    *(s32*)(this_ + 0x268) = 0;
    *(u8*)(this_ + 0x27b) = 0;
    *(u8*)(this_ + 0x29c) = 0;
    *(f32*)(this_ + 0x2b4) = zero;
    *(f32*)(this_ + 0x2b0) = zero;
    *(f32*)(this_ + 0x2ac) = zero;
    *(f32*)(this_ + 0x44) = zero;
    *(f32*)(this_ + 0x40) = zero;
    *(f32*)(this_ + 0x3c) = zero;
    *(f32*)(this_ + 0x2a0) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2a8) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x2c4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2c8) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2cc) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x2d0) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2d4) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2d8) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x2dc) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2e0) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2e4) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x254) = -1;
    *(u8*)(this_ + 0x196) = 1;
    *(f32*)(this_ + 0x294) = lbl_8053E0D0;
    *(f32*)(this_ + 0x298) = lbl_8053E0D0;
    *(f32*)(this_ + 0x2b8) = lbl_8053E0D0;
    *(f32*)(this_ + 0x2bc) = lbl_8053E0D0;
    *(f32*)(this_ + 0x2c0) = lbl_8053E18C;
    *(u8*)(this_ + 0x27a) = 0;
    *(f32*)(this_ + 0x28c) = zero;
    *(f32*)(this_ + 0x284) = lbl_8053E140;
    *(f32*)(this_ + 0x290) = zero;
    *(s32*)(this_ + 0x274) = 0x300;
    *(s32*)(this_ + 0x328) = 0;
    *(s32*)(this_ + 0x32c) = 0;
    *(s32*)(this_ + 0x330) = 0;
    *(s32*)(this_ + 0x27c) = -1;
    *(s16*)(this_ + 0x278) = 0;
    if (*(s32*)(this_ + 0x26c) == 0) {
        lbl_80539FCC = -1;
        lbl_80539FD0 = 9;
        *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0x2a4) + lbl_8053E0E0;
        fn_802D7440(fn_802D6A9C(), 0);
        *(f32*)(this_ + 0x60) = lbl_8053E168;
        *(f32*)(this_ + 0x64) = lbl_8053E16C;
        *(f32*)(this_ + 0x68) = lbl_8053E170;
        *(f32*)(this_ + 0x6c) = lbl_8053E124;
        fn_80458F9C(lbl_8053AF80, 0x3c);
        *(s32*)(this_ + 0x230) = 0;
    } else {
        *(f32*)(this_ + 0x60) = neg;
        *(f32*)(this_ + 0x64) = neg;
        *(f32*)(this_ + 0x68) = one;
        *(f32*)(this_ + 0x6c) = one;
        *(s32*)(this_ + 0xb0) = 0x5040004;
        lbl_80539FC8 = *(s32*)(this_ + 0x4);
        *(f32*)(lbl_804C18B8 + 0) = *(f32*)(this_ + 0x2a0);
        *(f32*)(lbl_804C18B8 + 4) = *(f32*)(this_ + 0x2a4);
        *(f32*)(lbl_804C18B8 + 8) = *(f32*)(this_ + 0x2a8);
        *(s32*)(this_ + 0x230) = 0x1a;
    }
}

static u8 lbl_804C18B8[0xC];

#include "JSystem/JAudio/JASFakeMatchFSA.h"
