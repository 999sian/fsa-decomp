// Game TU 801DC264-801DCC98 (BOIT). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry.h"
extern "C" bool fn_801CD2F8(s32 id);
extern "C" void fn_80307AC8(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c);
extern "C" void fn_801F02BC(void* actor, void* res, u32 id, void* rec, s32 p5, u32 p6, u32 p7, f32 a, f32 b);
extern "C" void fn_801F2DB4(void* actor, u32 a, u32 b, u32 c);
extern "C" void fn_801D22A0(void* obj, u32 a, u32 b);
extern u8 lbl_80469AE4[];
extern const f32 lbl_8053F340;
extern const f32 lbl_8053F344;
extern const f32 lbl_8053F35C;

extern "C" {
}
extern f32 lbl_8053EFB8;
extern "C" void fn_801CE2BC(void* this_);
struct ActorSlot37 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void slot37();
};
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_801DAC6C(void);
extern void* lbl_804A4F90[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, s32 id, s32 a, f32 x, f32 y);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern void* lbl_8053AAF8;
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_801DAD88(void* mgr);
extern "C" void fn_801DAF3C(void* mgr, void* p);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D2608(void* ctrl, void* seqs, s32 num);
extern "C" void fn_801D22DC(void* ctrl, s32 seq, s32 mode, bool keep);
extern "C" void fn_801D1D60(void* ctrl);
extern void* lbl_8053A150[2];
extern const f32 lbl_8053F360;
extern const f32 lbl_8053F364;
extern const f32 lbl_8053F368;
extern const f32 lbl_8053F36C;
extern const f32 lbl_8053F370;

extern "C" void fn_801DC7D0(u8* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
        break;
    case 1:
        fn_802D79E8(fn_802D6A9C(), *(s32*)(this_ + 0x4), 0, lbl_8053F360, lbl_8053F364);
        fn_80134DE4(lbl_8053AAF8, 1, 0);
        if (*(s32*)(this_ + 0x24c) >= 60) {
            fn_801F0E34(this_, 0x40055, 0);
            *(u16*)((u8*)fn_801DAC6C() + 0x84) &= ~1;
            fn_801DAD88(fn_801DAC6C());
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 2;
        }
        break;
    case 2:
        if (*(s32*)(this_ + 0x24c) >= 120) {
            detach__5ActorFv(this_);
        }
        break;
    }
}

extern "C" void fn_801DC89C(u8* this_) {
    fn_801D0ED0(this_);
    *(f32*)(this_ + 0x60) = lbl_8053F368;
    *(f32*)(this_ + 0x64) = lbl_8053F36C;
    *(f32*)(this_ + 0x68) = lbl_8053F370;
    *(f32*)(this_ + 0x6c) = lbl_8053F370;
    *(f32*)(this_ + 0x80) = lbl_8053F340;
    *(f32*)(this_ + 0x84) = lbl_8053F340;
    *(f32*)(this_ + 0x88) = lbl_8053F35C;
    *(f32*)(this_ + 0x8c) = lbl_8053F35C;
    *(u32*)(this_ + 0xb0) = 0x40004;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x2a0;
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x114) = 2;
    this_[0x196] = 1;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = -1;
    *(f32*)(this_ + 0x254) = lbl_8053F344;
    *(f32*)(this_ + 0x258) = lbl_8053F344;
    fn_801D2608(this_ + 0x270, lbl_8053A150, 2);
    fn_801D22DC(this_ + 0x270, 0, 2, false);
    fn_801D1D60(this_ + 0x270);
    fn_801DAF3C(fn_801DAC6C(), *(void**)(this_ + 0x198));
}


extern "C" u8 fn_801DC264(void* thisPtr)
{
    char* t = (char*)thisPtr;
    s32 total;
    u8 result = 0;
    if (*(s32*)(t + 0x278) == 1) {
        total = *(s32*)(t + 0xdc);
        s32 elapsed = *(s32*)(t + 0xd8);
        s32 remain = total - 25;
        if (elapsed > remain || total < 25) {
            if (total < 25) {
                result = (u8)(elapsed * 255 / total);
            } else {
                result = (u8)((elapsed - remain) * 255 / 25);
            }
        }
    }
    return result;
}

extern "C" void fn_801DC758(void* thisPtr)
{
    f32 zero = lbl_8053F344;
    *(f32*)((char*)thisPtr + 0x3c) = zero;
    *(f32*)((char*)thisPtr + 0x44) = zero;
    if (*(s32*)((char*)thisPtr + 0x248) == 2) {
        f32 kick = __fabsf(lbl_8053EFB8);
        f32 vy = *(f32*)((char*)thisPtr + 0x40);
        *(f32*)((char*)thisPtr + 0x40) = vy + kick;
    } else {
        *(f32*)((char*)thisPtr + 0x40) = zero;
    }
}

extern "C" void fn_801DC2D4(u8* this_) {
    if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
        fn_80307AC8(*(void**)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, *(s32*)(this_ + 0x280) + 0xe3, 0, 0, -1);
    } else {
        fn_801F02BC(this_, lbl_80469AE4, *(s32*)(this_ + 0x280) + 0xe3, 0, -1, 0, 0, lbl_8053F340, lbl_8053F340);
    }
}

extern "C" int fn_801DC364(u8* this_) {
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053F344 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053F344) {
        fn_801F2DB4(this_, *(u32*)(this_ + 0x1a0), 'NULL', 0);
    }
    return 0;
}


extern const f32 lbl_8053F340;
struct BoitRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053F340;
    }
};
struct BoitGame { u8 pad[0xb4]; BoitRandom rnd; };

struct BoitRupy {
    u8 pad[0x3c];
    JGeometry::TVec3<f32> mVel;
};

extern "C" s32 fn_801F285C(void* this_, s32 a, s32* out, s32 b, s32 player);
extern "C" void fn_8023B6CC(s32 player);
extern "C" void* fn_8023E724(s32 player);
extern "C" bool fn_801F37AC(void* this_, s32 a, void* pos, s32 b, s32 v, s32 player);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* mgr, u32 kind, s32 room, void* pos, s32 n);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_801DADD0(void* mgr);
extern const f32 lbl_8053F348;
extern const f32 lbl_8053F34C;
extern const f32 lbl_8053F350;
extern const f32 lbl_8053F354;
extern const f32 lbl_8053F358;

extern "C" bool fn_801DC3C4(u8* this_) {
    bool result = false;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053F344
        && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053F344)
    {
        for (s32 i = 0; i < 4; i++) {
            s32 v;
            if (fn_801F285C(this_, 0, &v, 1, i) == i) {
                fn_8023B6CC(i);
                if (fn_801F37AC(this_, 0, fn_8023E724(i), 0, v, i)) {
                    result = true;
                    this_[0x2a8]++;
                    s32 room = *(s32*)(this_ + 0x4);
                    u8 flag = *(u8*)((u8*)fn_802D6A9C() + 0x131df + room);
                    s32 id = fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(this_ + 0x4), this_ + 0xc, 2);
                    if (id >= 0) {
                        BoitRupy* rupy = (BoitRupy*)fn_801F666C(fn_801F856C(), id);
                        if (rupy != NULL) {
                            JGeometry::TVec3<f32> v2;
                            JGeometry::TVec3<f32> v1;
                            if (flag) {
                                v1.set(lbl_8053F348 * (lbl_8053F34C * ((BoitGame*)lbl_8053AAF8)->rnd.get_ufloat_1() - lbl_8053F340),
                                       lbl_8053F350 - lbl_8053F34C * ((BoitGame*)lbl_8053AAF8)->rnd.get_ufloat_1(),
                                       lbl_8053F344);
                                rupy->mVel = v1;
                            } else {
                                v2.set(lbl_8053F354 * (lbl_8053F34C * ((BoitGame*)lbl_8053AAF8)->rnd.get_ufloat_1() - lbl_8053F340),
                                       lbl_8053F354 * (lbl_8053F34C * ((BoitGame*)lbl_8053AAF8)->rnd.get_ufloat_1() - lbl_8053F340),
                                       lbl_8053F358 * ((BoitGame*)lbl_8053AAF8)->rnd.get_ufloat_1() + lbl_8053F358);
                                rupy->mVel = v2;
                            }
                        }
                    }
                }
            }
        }
        if (result) {
            *(s32*)(this_ + 0xf8) = 0;
            *(f32*)(this_ + 0x3c) = lbl_8053F344;
            *(f32*)(this_ + 0x40) = lbl_8053F344;
            *(f32*)(this_ + 0x44) = lbl_8053F344;
            *(f32*)(this_ + 0x14) = lbl_8053F344;
            fn_801D22DC(this_ + 0x270, 1, 0, false);
            fn_801F0E34(this_, 0x40054, 0);
            fn_801DADD0(fn_801DAC6C());
        }
    }
    return result;
}

extern "C" void fn_801DC6B4(u8* this_) {
    fn_801D22A0(this_ + 0x270, 0, 2);
    if (this_[0x2a8] >= 10) {
        *(f32*)(this_ + 0x60) = lbl_8053F340;
        *(f32*)(this_ + 0x64) = lbl_8053F340;
        *(f32*)(this_ + 0x68) = lbl_8053F35C;
        *(f32*)(this_ + 0x6c) = lbl_8053F35C;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(u32*)(this_ + 0xb0) = 0;
        *(u16*)((u8*)fn_801DAC6C() + 0x84) |= 1;
        *(s32*)(this_ + 0x24c) = 0;
        *(s32*)(this_ + 0x248) = 1;
    }
}

extern "C" void fn_801DC790(void* this_) {
    u32 flags = *(u32*)((char*)this_ + 0x230);
    if ((flags & 7) == 0) {
        fn_801CE2BC(this_);
    } else {
        ((ActorSlot37*)this_)->slot37();
    }
}

extern "C" void* fn_801DC990(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4F90;
        void* singleton = fn_801DAC6C();
        *(s32*)((char*)singleton + 0x4) = -1;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801DCA30(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4F90;
    *(u8*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
