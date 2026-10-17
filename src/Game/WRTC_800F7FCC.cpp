// WRTC_800F7FCC: .text 0x800F7FCC-0x800FD438 (actor WRTC/BWRT)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern f32 lbl_8053BFA0;
extern f32 lbl_8053BFA4;
extern f32 lbl_8053BFA8;
extern f32 lbl_8053BFB8;
extern "C" u8 fn_8023F264(s32 idx);
extern "C" u32 fn_8022EA0C(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" f32* fn_8023E724(s32 idx);
extern "C" void fn_80238548(s32 idx, s32 a, f32* pos, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 x);
extern "C" void fn_801F0E34(void* p, u32 a, s32 b);
extern "C" void fn_800FA6B0(void* p);
extern "C" void fn_80458F9C(void* p, s32 x);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern void* lbl_8053AF80;
extern f32 lbl_8053BFAC;
extern f32 lbl_8053BFCC;
extern f32 lbl_8053C054;
extern f32 lbl_8053C058;
extern f32 lbl_8053C05C;

// ---- from Game/fn_800F7FCC_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C678[];

extern "C" void* fn_800F7FCC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C678;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_800F89FC.cpp

extern "C" void fn_801F0E34(void* target, u32 effectId, s32 flag);
struct WrtcVec { f32 x, y, z; WrtcVec() {} WrtcVec(f32 a, f32 b, f32 c) { x = a; y = b; z = c; } };
struct WrtcVT24 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); };

extern "C" void fn_800F89FC(void* this_) {
    *(s32*)((char*)this_ + 0x234) = 2;
    fn_801F0E34(this_, 0x50084, 0);
}

// ---- from Game/RupeeContainerUpdate_800F8A30.cpp

// fn_800F8A30: the "rupee container" class's main per-frame update
// dispatcher. On the first call (this->0x230==0), looks up an owner
// registry entry via SpatialRegistry_GetBase + fn_801F666C (ID = low
// 16 bits of this->0x90) and caches the pointer in this->0x240.
// If this->0x248==1, dispatches on the phase field this->0x234:
// phase 1 -> fn_800F953C; phase 2 -> fn_800F9170; phase 0 -> waits
// for the cached owner's own phase field (+0x230) to reach 1, via a
// 2-stage counter/threshold wait (this->0x238 against this->0x24c,
// gated by the this->0x246 stage flag) before setting its own phase
// to 1, stashing this->0xb0=0x80004, and playing effect 0x40029.
// If this->0x248!=1, instead calls fn_800F8BAC. Regardless of mode,
// afterward checks the cached owner's +0x2ad byte flag (1 in the
// phase-dispatch path, 2 in the fn_800F8BAC path) and conditionally
// invokes own vtable slot 9 (byte offset 0x24). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
extern "C" void* SpatialRegistry_GetBase(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" void fn_800F953C(void* this_);
extern "C" void fn_800F9170(void* this_);
extern "C" void fn_800F8BAC(void* this_);
// fn_801F0E34 declared above

struct ActorVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void slot9();
};

extern "C" void fn_800F8A30(void* this_) {
    if (*(s32*)((char*)this_ + 0x230) == 0) {
        void* base = SpatialRegistry_GetBase();
        u32 id = *(u32*)((char*)this_ + 0x90) & 0xFFFF;
        void* target = fn_801F666C(base, id);
        *(void**)((char*)this_ + 0x240) = target;
    }
    *(s32*)((char*)this_ + 0x230) = *(s32*)((char*)this_ + 0x230) + 1;

    if (*(u8*)((char*)this_ + 0x248) == 1) {
        switch (*(s32*)((char*)this_ + 0x234)) {
        case 0:
            switch ((s32)*(u8*)((char*)this_ + 0x246)) {
            case 0: {
                void* owner = *(void**)((char*)this_ + 0x240);
                if (*(s32*)((char*)owner + 0x230) == 1) {
                    *(s32*)((char*)this_ + 0x238) = 0;
                    *(u8*)((char*)this_ + 0x246) = *(u8*)((char*)this_ + 0x246) + 1;
                }
                break;
            }
            case 1: {
                *(s32*)((char*)this_ + 0x238) = *(s32*)((char*)this_ + 0x238) + 1;
                s32 counter = *(s32*)((char*)this_ + 0x238);
                s32 threshold = *(u16*)((char*)this_ + 0x24c);
                if (counter > threshold) {
                    *(s32*)((char*)this_ + 0x234) = 1;
                    *(u32*)((char*)this_ + 0xb0) = 0x80004;
                    fn_801F0E34(this_, 0x40029, 0);
                }
                break;
            }
            }
            break;
        case 1:
            fn_800F953C(this_);
            break;
        case 2:
            fn_800F9170(this_);
            break;
        }
        void* owner = *(void**)((char*)this_ + 0x240);
        if (*(u8*)((char*)owner + 0x2ad) == 1) {
            ((ActorVT*)this_)->slot9();
        }
    } else {
        fn_800F8BAC(this_);
        void* owner = *(void**)((char*)this_ + 0x240);
        if (*(u8*)((char*)owner + 0x2ad) == 2) {
            ((ActorVT*)this_)->slot9();
        }
    }
}

extern "C" u8 lbl_8049C61C[];
extern "C" u8 lbl_8049C628[];
extern "C" u8 lbl_80539E80[];
extern "C" u8 lbl_80539E88[];
extern "C" u8 lbl_80539E90[];
extern "C" u8 lbl_80539E94[];
extern "C" u8 lbl_80539E98[];
extern "C" u8 lbl_80539EA0[];
extern "C" void fn_801F0E34(void*, u32, s32);
extern "C" void fn_800FA6B0(void* p)
{
    u8* self = (u8*)p;

    if (*(s32*)(self + 0x280) != *(s32*)(self + 0x27c)) {
        *(s32*)(self + 0x280) = *(s32*)(self + 0x27c);
        self[0x27a] = 0;
        self[0x279] = 0;
    }
    switch (*(u32*)(self + 0x27c)) {
    case 0:
        self[0x278] = lbl_8049C61C[self[0x279]];
        if (self[0x278] == 0xff) {
            self[0x278] = 3;
            self[0x27a] = 0;
            break;
        }
        if (self[0x27a] != lbl_8049C628[self[0x279]]) {
            break;
        }
        self[0x27a] = 0;
        self[0x279]++;
        if (self[0x27a] != 0) {
            break;
        }
        if (self[0x279] != 0) {
            if (self[0x279] == 6) {
                fn_801F0E34(self, 0x40026, 0);
            }
            break;
        }
        /* fallthrough */
    case 1:
        self[0x278] = lbl_80539E80[self[0x279]];
        if (self[0x278] == 0xff) {
            self[0x278] = 0;
            self[0x27a] = 0;
        } else if (self[0x27a] == lbl_80539E88[self[0x279]]) {
            self[0x27a] = 0;
            self[0x279]++;
        }
        if (self[0x27a] == 0 && self[0x279] == 0) {
            fn_801F0E34(self, 0x40027, 0);
        }
        break;
    case 2:
        self[0x278] = lbl_80539E90[self[0x279]];
        if (self[0x278] == 0xff) {
            self[0x278] = 6;
            self[0x27a] = 0;
        } else if (self[0x27a] == lbl_80539E94[self[0x279]]) {
            self[0x27a] = 0;
            self[0x279]++;
        }
        break;
    case 3:
        self[0x278] = 0;
        break;
    case 4:
        self[0x278] = 7;
        break;
    case 5:
        self[0x278] = 8;
        break;
    case 6:
        self[0x278] = 9;
        break;
    case 7:
        self[0x278] = 0xa;
        break;
    case 8:
        self[0x278] = lbl_80539E98[self[0x279]];
        if (self[0x278] == 0xff) {
            self[0x278] = 3;
            self[0x27a] = 0;
        } else if (self[0x27a] == lbl_80539EA0[self[0x279]]) {
            self[0x27a] = 0;
            self[0x279]++;
            self[0x27a]++;
        }
        break;
    }
}

extern "C" void fn_801F37AC(void*, s32, void*, s32, s32, s32);
extern f32 lbl_8053BFAC;
extern f32 lbl_8053BFF4;
extern f32 lbl_8053C054;
extern f32 lbl_8053C058;
extern f32 lbl_8053C05C;
extern "C" void fn_800FA944(char* this_) {
    u32 st = *(u32*)(this_ + 0xb0);
    if (st == 4 || st == 0x12) {
        return;
    }
    if (*(u8*)(this_ + 0x256) != 0) {
        return;
    }
    if (*(s32*)(this_ + 0xd8) == 0) {
        this_[0x255]++;
        this_[0x256] = 0x32;
        if (*(u32*)(this_ + 0x268) == 0) {
            *(u32*)(this_ + 0x268) = 1;
        }
        fn_801F37AC(this_, 0, this_ + 0xc, 3, 0, -1);
        fn_801F0E34(this_, 0x40005, 0);
        WrtcVec v;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        *(WrtcVec*)(this_ + 0x3c) = v;
        if (*(u8*)(this_ + 0x2ad) != 0) {
            if (*(s32*)(this_ + 0x230) != 9) {
                *(s32*)(this_ + 0x230) = 9;
                *(u32*)(this_ + 0x238) |= 1;
                *(u32*)(this_ + 0x238) &= ~4;
                *(f32*)(this_ + 0x3c) = 0.0f;
                *(f32*)(this_ + 0x40) = 0.0f;
                *(f32*)(this_ + 0x44) = 5.0f;
                *(u32*)(this_ + 0x268) = 0;
                *(u32*)(this_ + 0x264) = 0;
                f32 s = *(f32*)(this_ + 0x26c);
                *(f32*)(this_ + 0x60) = -26.0f * s;
                *(f32*)(this_ + 0x64) = -50.0f * s;
                *(f32*)(this_ + 0x68) = 26.0f * s;
                *(f32*)(this_ + 0x6c) = 0.0f;
                fn_801F0E34(this_, 0x40005, 0);
                if (*(s32*)(this_ + 0x108) <= 10) {
                    ((WrtcVT24*)this_)->v7();
                }
            }
        }
    } else if (*(u8*)(this_ + 0x255) == 3) {
        this_[0x2ad] = 1;
    }
}

// ---- from Game/fn_800FD1B4_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C718[];

extern "C" void* fn_800FD1B4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C718;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct ActorVT10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(s32 a, f32 x, f32 y);
};
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern "C" u16 fn_8022461C(void*);
extern "C" s32 fn_802265DC(void*, void*, s32);
extern "C" void fn_802F601C(void*, void*, s32, s32, f32, f32);
extern char* lbl_8053AB10;

extern "C" void fn_800FAAE0(char* this_) {
    fn_802D7440(fn_802D6A9C(), 0);
    fn_801F0E34(this_, 0x40006, 0);
    this_[0x2ad] = 2;
    ((ActorVT10*)this_)->v8(0, 0.0f, 1.0f);
}

extern "C" s32 fn_800FAB50(void* this_, void* a, void* b) {
    s32 t = fn_8022461C(b);
    if (t == 3 || t == 0xe || t == 2) {
        return 0;
    }
    return fn_802265DC(b, a, 0);
}

extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F2FAC(void* this_);
extern "C" void fn_8013CC50(s32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_800FB070(u8* this_) {
    *(f32*)(this_ + 0x44) -= 0.3f;
    *(f32*)(this_ + 0xc) += *(f32*)(this_ + 0x3c);
    *(f32*)(this_ + 0x10) += *(f32*)(this_ + 0x40);
    *(f32*)(this_ + 0x14) += *(f32*)(this_ + 0x44);
    if (*(f32*)(this_ + 0x14) <= 0.0f) {
        *(f32*)(this_ + 0x14) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
    }
    if (*(u8*)(this_ + 0x256) != 0) {
        *(u8*)(this_ + 0x256) -= 1;
    }
    if (*(u8*)(this_ + 0x278) == 3 || *(u8*)(this_ + 0x278) == 6) {
        *(s32*)(this_ + 0xb0) = 0x10;
    } else {
        *(s32*)(this_ + 0xb0) = 4;
    }
    f32 v = *(f32*)(this_ + 0x26c);
    *(f32*)(this_ + 0x60) = -26.0f * v;
    *(f32*)(this_ + 0x64) = -50.0f * v;
    *(f32*)(this_ + 0x68) = 26.0f * v;
    *(f32*)(this_ + 0x6c) = 0.0f;
    *(f32*)(this_ + 0x80) = -26.0f * v;
    *(f32*)(this_ + 0x84) = -50.0f * v;
    *(f32*)(this_ + 0x88) = 26.0f * v;
    *(f32*)(this_ + 0x8c) = 0.0f;
    if (*(s32*)(this_ + 0x268) != 0) {
        *(s32*)(this_ + 0x268) += 0x2000;
        if ((u32)*(s32*)(this_ + 0x268) > 0x10000) {
            *(s32*)(this_ + 0x268) = 0;
        }
    }
    *(s32*)(this_ + 0x264) += 1;
    if (fn_801F3D94(this_, 1) == 1) {
        return;
    }
    if (*(s32*)(this_ + 0x264) >= 0x118) {
        *(s32*)(this_ + 0x264) = 0;
        *(s32*)(this_ + 0x238) |= 1;
        *(s32*)(this_ + 0x238) |= 4;
        *(s32*)(this_ + 0xb0) = 4;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 10.0f;
        *(s32*)(this_ + 0x230) = 6;
        *(s32*)(this_ + 0x268) = 1;
        *(s32*)(this_ + 0x264) = 0;
        if (!(*(s32*)(this_ + 0x238) & 8)) {
            f32 r = (f32)*(s32*)(this_ + 0x108) / 480.0f;
            *(u8*)(this_ + 0x257) = r < 0.4f ? 3 : 2;
        }
        fn_801F0E34(this_, 0x4002b, 0);
        return;
    }
    if (fn_801F2FAC(this_) != 0) {
        *(s32*)(this_ + 0xd8) = 0x14;
        *(s32*)(this_ + 0xdc) = 0x14;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        *(s32*)(this_ + 0x268) = 1;
        fn_801F0E34(this_, 0x40005, 0);
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 1.0f, 0x4eb, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 1.0f, 0x4ec, 0, 0, 0, 0, 1);
        if (*(s32*)(this_ + 0x108) <= 10) {
            ((void (*)(void*))((void**)*(void**)this_)[9])(this_);
        }
    }
}

extern "C" void fn_800FCF80(u8* this_) {
    f32 fVar1 = lbl_8053BFCC;
    *(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0xc);
    f32 fVar2 = lbl_8053BFAC;
    *(f32*)(this_ + 0x240) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x244) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x248) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x24c) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x250) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 500;
    *(u8*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(u8*)(this_ + 0x255) = 0;
    *(u8*)(this_ + 0x256) = 0;
    *(u8*)(this_ + 0x2ad) = 0;
    *(s32*)(this_ + 0x268) = 0;
    *(s16*)(this_ + 0x262) = 0;
    *(f32*)(this_ + 0x270) = fVar1;
    *(f32*)(this_ + 0x274) = fVar2;
    *(f32*)(this_ + 0x26c) = fVar1;
    *(s16*)(this_ + 0x260) = 0;
    *(f32*)(this_ + 0x25c) = fVar2;
    *(s32*)(this_ + 0x238) = 0;
    *(u8*)(this_ + 0x257) = 0;
    *(s16*)(this_ + 0x284) = 0;
    *(s16*)(this_ + 0x286) = 0;
    *(s32*)(this_ + 0x98) = 2;
    fn_802D7440(fn_802D6A9C(), 0);
    *(u8*)(this_ + 0x196) = 1;
    if (*(u32*)(this_ + 0x90) == 1) {
        *(u32*)(this_ + 0x238) |= 8;
    }
    if (*(u32*)(this_ + 0x238) & 8) {
        *(s32*)(this_ + 0x108) = 0xf0;
    } else {
        *(s32*)(this_ + 0x108) = 0x1e0;
    }
    *(s32*)(this_ + 0xbc) = 3;
    f32 k1 = lbl_8053C054;
    f32 k2 = *(f32*)(this_ + 0x26c);
    f32 a = k1 * k2;
    f32 b = lbl_8053C058 * k2;
    f32 c = lbl_8053C05C * k2;
    f32 d = lbl_8053BFAC;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = b;
    *(f32*)(this_ + 0x68) = c;
    *(f32*)(this_ + 0x6c) = d;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = b;
    *(f32*)(this_ + 0x88) = c;
    *(f32*)(this_ + 0x8c) = d;
    *(s32*)(this_ + 0x27c) = 0;
    fn_801F0E34(this_, 0x40026, 0);
    *(s32*)(this_ + 0x280) = 9;
    fn_800FA6B0(this_);
    fn_80458F9C(lbl_8053AF80, 0x3c);
    s32 n = 0;
    s32 off = 0;
    u32 base = *(u32*)(this_ + 0x198) & 0xffff;
    do {
        void* mgr = fn_801F856C();
        Actor_CreateByID(mgr, 0x57525443, *(u32*)(this_ + 4), (f32*)(this_ + 0xc), base + off + 0x1000000, -1, -1);
        n++;
        off += 0x10000;
        *(u8*)(this_ + 0x2ac) += 1;
    } while (n < 0x18);
    if (*(u32*)(this_ + 0x238) & 8) {
        s32* slot = (s32*)this_;
        s32 cnt = 0;
        off = 0;
        do {
            void* mgr = fn_801F856C();
            s32 id = Actor_CreateByID(mgr, 0x57525443, *(u32*)(this_ + 4), (f32*)(this_ + 0xc), base + off + 0x2000000, -1, -1);
            cnt++;
            slot[0x288 / 4] = id;
            off += 0x10000;
            slot++;
        } while (cnt < 2);
    }
}

struct WRTCEff { f32 x, y, z; u8 m0C, m0D; u8 pad[2]; f32 m10; u16 m14; u8 m16; };

static inline f32 WRTC_quantize(f32 v) {
    return 0.0001f * (f32)(s32)(10000.0f * v);
}

static inline s32 WRTC_stepToward(f32* v, f32 target, f32 step) {
    *v = WRTC_quantize(*v);
    target = WRTC_quantize(target);
    if (*v > target) {
        *v -= step;
        if (*v <= target) {
            *v = target;
            return 1;
        }
    } else {
        *v += step;
        if (*v >= target) {
            *v = target;
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_800F8210(WRTCEff* e, s32 n, const f32* pos, u8 kind) {
    e->x = pos[0];
    e->y = pos[1];
    e->z = pos[2];
    e->m0C = 1;
    e->m10 = 0.0f;
    e->m14 = 0;
    e->m16 = 0;
    e->m0D = kind;
    f32 s;
    switch (e->m0D) {
    case 0: s = 1.0f; break;
    case 1: s = 2.0f; break;
    case 2: s = 3.0f; break;
    default: s = 1.0f; break;
    }
    if (n < 8) {
        fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), e, 2, 0, s, 4.0f);
    }
}

extern "C" s8 fn_800F82CC(f32* p1, const f32* p2, f32 step) {
    u8 n = WRTC_stepToward(&p1[0], p2[0], step);
    n += WRTC_stepToward(&p1[1], p2[1], step);
    n += WRTC_stepToward(&p1[2], p2[2], step);
    return n == 3;
}

extern "C" const f32 sincosTable___5JMath[];
extern "C" const u32 lbl_8049C648[];
extern "C" u8 lbl_80463A58[];
extern "C" void fn_801F02BC(void* a, void* p2, void* p3, void* p4, void* p5, s32 p6, u8 p7, f32 f6, f32 f7);
extern "C" void fn_801EFD34(void* a, void* res, f32 x, f32 y, f32 z, void* rec, s32 n);
extern "C" void* fn_804032E8(u32 fourcc, u32 id);
extern "C" void fn_800F8548(void* this_) {
    char* p = (char*)this_;
    f32 lo = 0.0f;
    f32 hi = lo;
    if (*(s32*)(p + 0x234) == 2) {
        f32 s = __fabsf(*(f32*)((u8*)sincosTable___5JMath + (((u32)(*(u16*)(p + 0x244) + 0x4000) >> 2) & 0x3ff8)));
        lo = 0.1f * s;
        hi = -0.1f * s;
    }
    u8 rec[0x3C];
    u8* idx = rec;
    *(s32*)(rec + 0x10) = -1;
    *(s32*)(rec + 0x14) = -1;
    for (u32 i = 0; (u8)i < 0x10; i += 8) {
        idx[(u8)i] = i;
        idx[(u8)(i + 1)] = i + 1;
        idx[(u8)(i + 2)] = i + 2;
        idx[(u8)(i + 3)] = i + 3;
        idx[(u8)(i + 4)] = i + 4;
        idx[(u8)(i + 5)] = i + 5;
        idx[(u8)(i + 6)] = i + 6;
        idx[(u8)(i + 7)] = i + 7;
    }
    *(s32*)(rec + 0x10) = -1;
    *(s32*)(rec + 0x14) = 0;
    *(s32*)(rec + 0x18) = 0;
    rec[0x1C] = 0;
    rec[0x1D] = 0;
    rec[0x1E] = 0;
    rec[0x1F] = 1;
    rec[0x20] = 1;
    rec[0x21] = 0;
    rec[0x22] = 0;
    rec[0x23] = 0;
    rec[0x24] = 0;
    rec[0x25] = 0;
    rec[0x26] = 1;
    *(s32*)(rec + 0x28) = 3;
    rec[0x2C] = 1;
    rec[0x2D] = 0;
    rec[0x2E] = 0;
    *(s32*)(rec + 0x30) = -1;
    *(s32*)(rec + 0x34) = 0;
    *(s32*)(rec + 0x38) = 2;
    f32 m[3][4];
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    if (*(u8*)(p + 0x248) == 2) {
        m[0][0] = 1.5f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.5f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.5f;
        *(u32*)(rec + 0x18) = (u32)m;
        fn_801F02BC(this_, lbl_80463A58, (void*)0x25, rec, 0, 0, 0, 1.0f, 1.0f);
    } else {
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[0][0] = 1.0f + lo;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f + hi;
        *(u32*)(rec + 0x18) = (u32)m;
        if (*(u8*)(p + 0x249) != 0) {
            *(s32*)(rec + 0x30) = 15;
        }
        void* res;
        if (*(s32*)(p + 0x234) == 2) {
            s32 n = *(s32*)(p + 0x23c);
            res = fn_804032E8(0x57415254, lbl_8049C648[(n + 1) * 2 + 1]);
        } else {
            s32 n = *(s32*)(p + 0x23c);
            res = fn_804032E8(0x57415254, lbl_8049C648[(n + 1) * 2]);
        }
        fn_801EFD34(this_, res, 0.0f, 0.0f, 0.0f, rec, 0);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
