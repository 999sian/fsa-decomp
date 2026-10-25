// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80175684-801769D8 (STAL). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_801F3D94(void* a, s32 b);
extern "C" u8 fn_801F2618(void* a, f32* out, u32 c);
extern "C" void fn_801F0E34(void* a, s32 id, s32 z);
extern "C" u32 fn_801F305C(void* a);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern "C" void fn_801EEC98(void* unused, s32 idx, u16* angOut, s32* quadOut, f32* distOut, s32* idxOut, s32 sel, s32 mode);
extern "C" u8 fn_801F2B7C(void* a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8023F264(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022C3AC(s32 i);

// from src/Game/fn_80175684_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A0CD8[];

extern "C" void* fn_80175684(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0CD8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F02BC(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b, s32 c, s32 d);

struct StalVec { f32 x, y, z; };
// STAL draw (vtable slot 6); shakes horizontally while reassembling.
extern const f32 lbl_8053DB50;
extern "C" void fn_801756E4(char* this_) {
    s32 flag = 0;
    f32 x = *(f32*)(this_ + 0xc);
    f32 y = *(f32*)(this_ + 0x10);
    f32 z = *(f32*)(this_ + 0x14);
    s32 t = *(s32*)(this_ + 0x248);
    if (t > 30 && t < 130) {
        if (!(t & 2)) {
            *(f32*)(this_ + 0xc) = *(volatile f32*)(this_ + 0xc) + lbl_8053DB50;
        } else {
            *(f32*)(this_ + 0xc) = *(volatile f32*)(this_ + 0xc) - lbl_8053DB50;
        }
    }
    if (*(s32*)(this_ + 0x264) != 0) flag = 1;
    fn_801F02BC(this_, "enemy_both2_sob.bin", *(s32*)(this_ + 0x258) + 0x158, 1.0f, 1.0f, 0, 7, flag, 0);
    *(f32*)(this_ + 0xc) = x;
    *(f32*)(this_ + 0x10) = y;
    *(f32*)(this_ + 0x14) = z;
}

extern "C" void fn_801757D4(char* this_) {
    f32 dist = 0.0f;
    s32 idxOut = -1;
    u16 ang;
    s32 quad;
    f32 probe[4];
    u8 hit;
    s32 i;

    if (*(u32*)(this_ + 0x90) == 4 || (*(u32*)(this_ + 0x90) == 5 && *(s32*)(this_ + 0x108) == 1000)) {
        if (*(f32*)(this_ + 0x14) > 0.0f) {
            if (*(f32*)(this_ + 0x44) == 0.0f) {
                return;
            }
            *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 1.0f;
            if (*(f32*)(this_ + 0x44) < -10.0f) {
                *(f32*)(this_ + 0x44) = -10.0f;
            }
            *(JGeometry::TVec3<f32>*)(this_ + 0xc) += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);
            return;
        }
        *(f32*)(this_ + 0x14) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        if (*(u32*)(this_ + 0x90) == 4) {
            *(u32*)(this_ + 0x90) = 0;
        } else {
            *(s32*)(this_ + 0x108) = 10000;
        }
    }
    if (*(u32*)(this_ + 0x90) == 5 && *(s32*)(this_ + 0x108) != 1000) {
        *(s32*)(this_ + 0x108) = 10000;
    }
    if (*(u32*)(this_ + 0x90) == 5 && *(u16*)(this_ + 0x94) != 0 && *(s32*)(this_ + 0x230) != 8) {
        *(s32*)(this_ + 0x230) = 7;
    }
    if (fn_801F3D94(this_, 1) != 0) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (*(s32*)(this_ + 0x240) == 0 && *(s32*)(this_ + 0x230) != 6 && *(s32*)(this_ + 0x230) != 8) {
        if (*(u32*)(this_ + 0xb0) == 0) {
            *(u32*)(this_ + 0xb0) = 0x42205;
        }
        if ((*(u32*)(this_ + 0x90) == 0 || *(s32*)(this_ + 0x230) != 4) && *(f32*)(this_ + 0x14) == 0.0f && fn_801F305C(this_) != 0) {
            if (*(u32*)(this_ + 0x90) == 5) {
                *(s32*)(this_ + 0x25c) -= 10000 - *(s32*)(this_ + 0x108);
                if (*(s32*)(this_ + 0x25c) < 1) {
                    *(f32*)(this_ + 0x274) = 0.0f;
                    *(f32*)(this_ + 0x270) = 0.0f;
                    *(f32*)(this_ + 0x26c) = 0.0f;
                    *(s32*)(this_ + 0x230) = 5;
                }
                if (*(s32*)(this_ + 0x25c) > 0) {
                    fn_801F0E34(this_, 0x4009d, 0);
                } else {
                    fn_801F0E34(this_, 0x4009e, 0);
                }
            }
            fn_801F2618(this_, 0, 0);
            return;
        }
    }
    {
        u32 room = *(u32*)(this_ + 4);
        if (fn_802D6A9C()[0x131df + room] != 0) {
            *(f32*)(this_ + 0x270) = 3.0f;
        }
        fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x26c), 0.3f, 1.0f);
        fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x270), 0.3f, 1.0f);
        *(JGeometry::TVec3<f32>*)(this_ + 0xc) += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);
    }
    if (*(s32*)(this_ + 0x240) == 0 && *(s32*)(this_ + 0x230) != 4 && *(s32*)(this_ + 0x230) != 8) {
        fn_801F2B7C(this_, -100, -1, 1);
        hit = fn_801F2618(this_, probe, 0);
        fn_801EEC98(this_, *(s32*)(this_ + 0x198), &ang, &quad, &dist, &idxOut, 0, 0);
        if (*(u32*)(this_ + 0x90) == 1 || (*(u32*)(this_ + 0x90) == 2 && *(s32*)(this_ + 0x230) == 1 && dist < 50.0f)) {
            for (i = 0; i < 4; i++) {
                if (fn_8023F264(i) != 0 && *(u32*)(this_ + 4) == fn_8023DE58(i) && fn_80230188(i) == 0 && fn_8023DE58(i) != 8 && fn_8022C3AC(i) != 0) {
                    *(s32*)(this_ + 0x230) = 3;
                    break;
                }
            }
        }
    }
    fn_801F2618(this_, 0, 0);
}

struct StalRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct StalGame { u8 pad[0xb4]; StalRandom rnd; };
extern StalGame* lbl_8053AAF8;
struct StalMgr { u8 flag(u32 i) { return mFlags[i]; } u8 pad[0x131df]; u8 mFlags[1]; };
extern "C" u8* fn_802D6A9C(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7818(void* mgr, u32 id, u32 owner, void** out, s32 max);

extern "C" void fn_80176538(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x70) = -4.0f;
    *(f32*)(this_ + 0x74) = -4.0f;
    *(f32*)(this_ + 0x78) = 4.0f;
    *(f32*)(this_ + 0x7c) = 4.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = 0.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(u32*)(this_ + 0x264) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    if (*(s32*)(this_ + 0x264) != 0) {
        *(f32*)(this_ + 0x60) = -12.0f;
        *(f32*)(this_ + 0x64) = -12.0f;
        *(f32*)(this_ + 0x68) = 12.0f;
        *(f32*)(this_ + 0x6c) = 12.0f;
    }
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 0xf;
    *(u16*)(this_ + 0x94) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s16*)(this_ + 0x268) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(f32*)(this_ + 0x278) = 1.0f;
    *(f32*)(this_ + 0x27c) = 1.0f;
    *(f32*)(this_ + 0x280) = 1.0f;
    *(u32*)(this_ + 0xb0) = 0x42205;
    *(s32*)(this_ + 0x98) = (s32)(3.99f * lbl_8053AAF8->rnd.get_ufloat_1());
    u32 room = *(u32*)(this_ + 4);
    if (((StalMgr*)fn_802D6A9C())->flag(room) != 0) {
        *(s32*)(this_ + 0x98) = *(s32*)(this_ + 0x98) & 1;
    }
    *(s32*)(this_ + 0x250) = *(s32*)(this_ + 0x98);
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(s32*)(this_ + 0x260) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x25c) = *(s32*)(this_ + 0x260);
    switch (*(s32*)(this_ + 0x90)) {
    case 3:
        *(s32*)(this_ + 0x240) = 30;
        *(u32*)(this_ + 0xb0) = 0;
        *(u32*)(this_ + 0x90) = 0;
        break;
    case 5: {
        *(s32*)(this_ + 0x260) = 4;
        *(s32*)(this_ + 0x25c) = 4;
        *(s32*)(this_ + 0x190) = 0;
        *(s32*)(this_ + 0x108) = 1000;
        void* list[0x400];
        s32 n = fn_801F7818(fn_801F856C(), 'WIZR', *(u32*)(this_ + 4), list, -1);
        for (s32 i = 0; i < n; i++) {
            char* w = (char*)list[i];
            if (w != 0 && w != 0 && *(u32*)(w + 0x90) == 1) {
                *(u32*)(this_ + 0x230) = 0;
                return;
            }
        }
        *(u32*)(this_ + 0x230) = 7;
        break;
    }
    case 4:
        *(u32*)(this_ + 0xb0) = 0;
        break;
    }
    *(u32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
