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

struct WRTCEff { f32 x, y, z; u8 m0C, m0D; u8 pad[2]; f32 m10; u16 m14; u8 m16; };

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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
