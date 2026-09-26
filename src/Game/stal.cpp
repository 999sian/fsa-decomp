// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80175684-801769D8 (STAL). Remaining functions are not yet decompiled.
#include "types.h"

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
extern "C" void fn_801756E4(char* this_) {
    s32 flag = 0;
    StalVec* pos = (StalVec*)(this_ + 0xc);
    StalVec save;
    save.x = pos->x;
    save.y = pos->y;
    save.z = pos->z;
    s32 t = *(s32*)(this_ + 0x248);
    if (t > 30 && t < 130) {
        if (!(t & 2)) {
            *(f32*)(this_ + 0xc) += 2.0f;
        } else {
            *(f32*)(this_ + 0xc) -= 2.0f;
        }
    }
    if (*(s32*)(this_ + 0x264) != 0) {
        flag = 1;
    }
    fn_801F02BC(this_, "enemy_both2_sob.bin", *(s32*)(this_ + 0x258) + 0x158, 1.0f, 1.0f, 0, 7, flag, 0);
    pos->x = save.x;
    pos->y = save.y;
    pos->z = save.z;
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
