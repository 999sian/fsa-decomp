// WRTC_800F7FCC: .text 0x800F7FCC-0x800FD438 (actor WRTC/BWRT)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

extern f32 lbl_8053BFA0;
extern f32 lbl_8053BFA4;
extern f32 lbl_8053BFA8;
extern f32 lbl_8053BFB8;
extern "C" u8 fn_8023F264(s32 idx);
extern "C" u32 fn_8022EA0C(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" f32* fn_8023E724(s32 idx);
extern "C" const f32 sincosTable___5JMath[];
extern f32 lbl_8053BFF4;
extern f32 lbl_8053BFF8;
extern f32 lbl_8053BFFC;
extern f32 lbl_8053C00C;
extern f32 lbl_8053C074;
extern f32 lbl_8053C0A8;
extern "C" s32 fn_801EEC98(void* a, void* h, s16* p5, s32* p6, f32* p7, s32* p8, s32 p9, s32 p10);
extern "C" s32 fn_801F68E0(void* p);
extern "C" void fn_80238548(s32 idx, s32 a, f32* pos, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 x);
extern "C" void fn_801F0E34(void* p, u32 a, s32 b);
extern f32 lbl_8053C080;
extern f32 lbl_8053C050;
extern f32 lbl_8053BFF0;
extern f32 lbl_8053BFC0;
extern f32 lbl_8053BFC4;
extern f32 lbl_8053BFC8;
extern "C" void fn_800FA1A4(void* this_);
extern "C" u8 fn_801F2618(void* this_, void* out, s32 flag);
extern "C" void fn_800FB6E0(void* p, s32 x);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 a, f32 x, f32 y);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern f32 lbl_8053C02C;
extern f32 lbl_8053C030;
extern f32 lbl_8053C034;
extern f32 lbl_8053BFAC;
extern "C" void* lbl_8053AAF8;
extern "C" s16 lbl_80463800[];
extern "C" s16 lbl_804638C0[];
extern "C" s32 fn_80138A30(void* game);
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
extern "C" const f32 lbl_8049C634[];
extern f32 lbl_8053C014;
extern f32 lbl_8053C01C;
extern f32 lbl_8053C020;
extern f32 lbl_8053BFC8;
extern f32 lbl_8053C048;
extern f32 lbl_8053C078;
extern f32 lbl_8053C098;
extern f32 lbl_8053C09C;
extern f32 lbl_8053C0A0;
extern f32 lbl_8053C0A4;
extern const f32 lbl_8049C5FC[][2];
extern "C" void* fn_801F1184(void* this_);
extern "C" u8 fn_801F305C(void* this_);
extern "C" s32 fn_801F3D94(void* this_, s32 a);

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

extern "C" void fn_800F802C(void* this_) {
    u8* self = (u8*)this_;
    if (self[0xc] != 0) {
        f32 scale;
        s32 limit;
        switch (self[0xd]) {
        case 0:
            scale = lbl_8053BFA0;
            limit = 0x28;
            break;
        case 1:
            scale = lbl_8053BFA4;
            limit = 0x28;
            break;
        case 2:
            scale = lbl_8053BFA8;
            limit = 0x14;
            break;
        default:
            scale = lbl_8053BFA0;
            limit = 0x28;
            break;
        }
        *(f32*)(self + 0x10) = (f32)*(u16*)(self + 0x14) * scale;
        *(u16*)(self + 0x14) += 1;
        if (*(u16*)(self + 0x14) > limit) {
            self[0xc] = 0;
        }
        for (s32 i = 0; i < 4; i++) {
            if (fn_8023F264(i) && (s32)fn_8022EA0C(i) == i && !(self[0x16] & (1 << i)) && fn_8023DE58(i) == 0) {
                JGeometry::TVec2<f32> d;
                d.x = fn_8023E724(i)[0] - *(f32*)self;
                d.y = fn_8023E724(i)[1] - *(f32*)(self + 4);
                if (d.length() < *(f32*)(self + 0x10)) {
                    d.x = *(f32*)self;
                    d.y = *(f32*)(self + 4);
                    fn_80238548(i, 0, (f32*)&d, 0xb);
                    self[0x16] |= (1 << i);
                }
            }
        }
    }
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

extern "C" void fn_800F8BAC(void* this_) {
    extern f32 lbl_8053BFD0, lbl_8053BFD4, lbl_8053BFF8, lbl_8053BFFC, lbl_8053C000, lbl_8053C004, lbl_8053C008;
    u8* self = (u8*)this_;
    u8* owner = *(u8**)(self + 0x240);
    u8 idx = self[0x247];
    f32 k, t, sn, cs, fx, fy, fz, scl;
    s32 n;
    u16 ang;
    if (*(s16*)(owner + 0x284 + ((u32)idx << 1)) != 0) {
        n = owner[0x2ac] >> 1;
        if (idx == 0) {
            ang = *(u16*)(owner + 0x2b2);
            t = (f32)((n + 1) * 20);
            k = lbl_8053BFF8 + t;
        } else {
            ang = *(u16*)(owner + 0x2b4);
            t = (f32)((n + 1) * -20);
            k = t - lbl_8053BFF8;
        }
        sn = JMath::sincosTable_.mTable[(s16)ang >> 5].first;
        cs = JMath::sincosTable_.mTable[(s16)ang >> 5].second;
        fx = k * sn + *(f32*)(owner + 0xc);
        fy = k * cs + *(f32*)(owner + 0x10);
        fz = lbl_8053BFFC + *(f32*)(owner + 0x14);
        self[0x249] = 1;
        n = owner[0x2ac] >> 1;
        scl = lbl_8053C000 - lbl_8053C004 * (f32)(n + 1);
        *(f32*)(self + 0x3c) = *(f32*)(self + 0xc);
        *(f32*)(self + 0x40) = *(f32*)(self + 0x10);
        *(f32*)(self + 0x44) = *(f32*)(self + 0x14);
        *(f32*)(self + 0xc) = lbl_8053BFD0 * (f32)(s32)(lbl_8053BFD4 * (fx - *(f32*)(self + 0xc))) * scl + *(f32*)(self + 0xc);
        *(f32*)(self + 0x10) = lbl_8053BFD0 * (f32)(s32)(lbl_8053BFD4 * (fy - *(f32*)(self + 0x10))) * scl + *(f32*)(self + 0x10);
        *(f32*)(self + 0x14) = lbl_8053BFD0 * (f32)(s32)(lbl_8053BFD4 * (fz - *(f32*)(self + 0x14))) * scl + *(f32*)(self + 0x14);
        *(f32*)(self + 0x3c) = (*(f32*)(self + 0x3c) - *(f32*)(self + 0xc)) * lbl_8053C008;
        *(f32*)(self + 0x40) = (*(f32*)(self + 0x40) - *(f32*)(self + 0x10)) * lbl_8053C008;
        *(f32*)(self + 0x44) = (*(f32*)(self + 0x44) - *(f32*)(self + 0x14)) * lbl_8053C008;
    }
}

extern "C" void fn_800F9170(void* this_) {
    s32 idx = 1;
    *(u8*)((char*)this_ + 0x249) = idx;
    void* owner = *(void**)((char*)this_ + 0x240);
    u32 m = *(u8*)((char*)owner + 0x2ac);
    u32 k;
    if (m < 8) {
        idx = 0;
        k = 0x2000;
    } else if (m < 0x10) {
        k = 0x2000;
    } else if (m < 0x15) {
        idx = 2;
        k = 0x3332;
    } else if (m < 0x18) {
        idx = 3;
        k = 0x5554;
    } else if (m < 0x1a) {
        idx = 4;
        k = 0x8000;
    } else {
        idx = 5;
        k = 0x2000;
    }
    u16 ang = *(u16*)((char*)owner + 0x2ae) + m * k + (idx << 12);
    f32 t = lbl_8049C634[idx];
    f32 scale = *(f32*)((char*)owner + 0x2a8);
    f32 sn = sincosTable___5JMath[(ang >> 5) * 2];
    f32 cs = sincosTable___5JMath[(ang >> 5) * 2 + 1];
    f32 x = scale * (t * sn) + *(f32*)((char*)owner + 0xc);
    f32 y = scale * (t * cs) + *(f32*)((char*)owner + 0x10);
    f32 z = lbl_8053BFFC + *(f32*)((char*)owner + 0x14) + (f32)(s32)(idx * 13);
    JGeometry::TVec3<f32> pos = JGeometry::TVec3<f32>(x, y, z);
    *(u8*)((char*)owner + 0x2ac) += 1;
    s32 id = *(s32*)((char*)this_ + 0xa0);
    if (id != -1) {
        void* target = fn_801F666C(fn_801F856C(), id);
        if (target != 0 && *(u32*)((char*)target + 0x1a0) == 0x424F4D45) {
            *(u16*)((char*)this_ + 0x244) = 0x4000;
            *(u16*)((char*)this_ + 0x24e) = 0;
            return;
        }
    }
    if (fn_801F3D94(this_, 1) != 0) {
        return;
    }
    if (fn_801F305C(this_) == 0) {
        *(u32*)((char*)this_ + 0xb0) = 0x80002;
        *(u16*)((char*)this_ + 0x24e) += 1;
        owner = *(void**)((char*)this_ + 0x240);
        JGeometry::TVec3<f32> d = *(JGeometry::TVec3<f32>*)((char*)owner + 0xc);
        d -= *(JGeometry::TVec3<f32>*)((char*)this_ + 0xc);
        if (d.length() < lbl_8053C01C && *(u16*)((char*)this_ + 0x24e) > 0x50) {
            *(s32*)((char*)this_ + 0x234) = 1;
            d.normalize();
            d.scale(lbl_8053BFC8);
            d.z = lbl_8053BFAC;
            if (*(f32*)((char*)this_ + 0x14) < lbl_8053BFFC || *(u16*)((char*)this_ + 0x24e) < 0x50) {
                d.x = lbl_8053BFAC;
                d.y = lbl_8053BFAC;
                d.z = lbl_8053BFAC;
            }
            *(JGeometry::TVec3<f32>*)((char*)this_ + 0x3c) = d;
            *(JGeometry::TVec3<f32>*)((char*)this_ + 0xc) += *(JGeometry::TVec3<f32>*)((char*)this_ + 0x3c);
            *(u16*)((char*)this_ + 0x244) += 0x480;
            *(f32*)((char*)this_ + 0x14) = lbl_8053C020 * __fabsf(sincosTable___5JMath[((*(u16*)((char*)this_ + 0x244)) >> 5) * 2]);
            if (*(f32*)((char*)this_ + 0x14) > lbl_8053BFFC) {
                return;
            }
        }
    } else {
        return;
    }
    fn_801F0E34(this_, 0x50083, 0);
}

extern "C" void fn_800F9C20(void* this_) {
    char* p = (char*)this_;
    f32 a = lbl_8053C02C;
    f32 b = lbl_8053C030;
    f32 c = lbl_8053C034;
    f32 d = lbl_8053BFA8;
    *(f32*)(p + 0x70) = a;
    *(f32*)(p + 0x74) = b;
    *(f32*)(p + 0x78) = c;
    *(f32*)(p + 0x7c) = d;
    *(s32*)(p + 0x108) = 4;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x246) = 0;
    *(u16*)(p + 0x244) = 0;
    *(u8*)(p + 0x249) = 0;
    *(u8*)(p + 0x247) = (*(u32*)(p + 0x90) >> 16) & 0xff;
    *(u8*)(p + 0x248) = *(u32*)(p + 0x90) >> 24;
    if (*(u8*)(p + 0x248) == 2) {
        *(f32*)(p + 0x80) = a;
        *(f32*)(p + 0x84) = b;
        *(f32*)(p + 0x88) = c;
        *(f32*)(p + 0x8c) = d;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = b;
        *(f32*)(p + 0x68) = c;
        *(f32*)(p + 0x6c) = d;
        *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + (f32)lbl_804638C0[*(u8*)(p + 0x247) * 2];
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + (f32)lbl_804638C0[*(u8*)(p + 0x247) * 2 + 1];
        *(u32*)(p + 0xb0) = 0x40004;
    } else {
        if (*(u8*)(p + 0x247) < 0x30) {
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + (f32)lbl_80463800[*(u8*)(p + 0x247) * 2];
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + (f32)lbl_80463800[*(u8*)(p + 0x247) * 2 + 1];
        } else {
            s16 x = lbl_80463800[0];
            s16 y = lbl_80463800[1];
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + (f32)x;
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + (f32)y;
        }
        *(f32*)(p + 0x14) = d;
        *(u16*)(p + 0x24c) = 0;
        for (s32 i = 0; i < *(u8*)(p + 0x247); i++) {
            s32 step = 10;
            if (*(u8*)(p + 0x247) < 0x1e) {
                step = 0x28 - *(u8*)(p + 0x247);
            }
            *(u16*)(p + 0x24c) = *(u16*)(p + 0x24c) + step;
        }
        s32 cnt = fn_80138A30(lbl_8053AAF8);
        if ((f32)cnt == lbl_8053BFCC) {
            *(s32*)(p + 0x23c) = -1;
            *(u16*)(p + 0x94) = 0;
        } else {
            u32* rng = (u32*)((char*)lbl_8053AAF8 + 0xb4);
            *rng = *rng * 0x19660d + 0x3c6ef35f;
            u32 bits = (*rng >> 9) | 0x3f800000;
            *(s32*)(p + 0x23c) = (s32)((f32)cnt * (*(f32*)&bits - 1.0f));
            *(u16*)(p + 0x94) = *(s32*)(p + 0x23c) + 1;
            *rng = *rng * 0x19660d + 0x3c6ef35f;
            bits = (*rng >> 9) | 0x3f800000;
            if ((s32)(lbl_8053BFA0 * (*(f32*)&bits - 1.0f)) < 1) {
                *(s32*)(p + 0x23c) = -1;
                *(u16*)(p + 0x94) = 0;
            }
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
                fn_801F0E34(p, 0x40026, 0);
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
            fn_801F0E34(p, 0x40027, 0);
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
        WrtcVec v(0.0f, 0.0f, 0.0f);
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
struct ActorVT11 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual bool v11(f32 a, f32 b, f32 c);
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

extern "C" s32 fn_800FAB50(void* this_, s32 a, void* b) {
    struct H {
        static inline s32 check(u32 r, void* p) {
            s32 kind = ((u16 (*)(void*, u32))fn_8022461C)(p, r);
            if (kind == 3 || kind == 14 || kind == 2) {
                return 0;
            }
            return fn_802265DC(p, (void*)r, 0);
        }
    };
    return H::check(a, b);
}

extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_800FCCCC(void* this_);
extern "C" void fn_800FC984(void* this_);
extern "C" void fn_800FC4A8(void* this_);
extern "C" void fn_800FC128(void* this_);
extern "C" void fn_800FBD90(void* this_);
extern "C" void fn_800FBA14(char* this_);
extern "C" void fn_800FB32C(void* this_);
extern "C" void fn_800FB070(u8* this_);
extern "C" void fn_801F6884(void* mgr);
extern "C" void fn_80458FF0(void* p, u32 a, s32 b, s32 c);
extern "C" void fn_8030C210(void* cam, void* pos);
extern "C" void fn_800FABC0(char* this_) {
    ((JGeometry::TBox2<f32>*)(this_ + 0x70))->set(-21.0f, -35.0f + *(f32*)(this_ + 0x14), 22.0f, -2.0f + *(f32*)(this_ + 0x14));
    if (((ActorVT11*)this_)->v11(0.0f, -20.0f, 50.0f)) {
        return;
    }
    if (!(*(u32*)(this_ + 0x238) & 1)) {
        if (*(u32*)(this_ + 0x238) & 0x10) {
            fn_801F2B7C(this_, 4, -1, 6);
        } else {
            fn_801F2B7C(this_, 1, -1, 6);
        }
    }
    switch (*(u32*)(this_ + 0x230)) {
    case 0:
        fn_800FCCCC(this_);
        break;
    case 1:
        *(u16*)(this_ + 0x2b0) = 0;
        *(u16*)(this_ + 0x2ae) += *(u16*)(this_ + 0x2b0);
        *(f32*)(this_ + 0x2a8) = 1.0f;
        *(u16*)(this_ + 0x260) += 0x200;
        *(f32*)(this_ + 0x14) = 5.0f * sincosTable___5JMath[(((u32)*(u16*)(this_ + 0x260) & 0xffff) >> 5) * 2] + *(f32*)(this_ + 0x25c);
        switch (*(u8*)(this_ + 0x254)) {
        case 0: {
            char* cam = *(char**)(lbl_8053AB10 + 0x30);
            if (*(u8*)(cam + 0x284) == 0) {
                *(u8*)(cam + 0x284) = 1;
                *(f32*)(cam + 0x28c) = 0.05f;
            }
            char* cam2 = *(char**)(lbl_8053AB10 + 0x24);
            f32 x;
            f32 y;
            y = *(f32*)(this_ + 0x10) - 20.0f;
            x = *(f32*)(this_ + 0xc);
            if (*(u8*)(cam2 + 0x7f5) == 0) {
                *(u8*)(cam2 + 0x7f4) = 1;
                *(s32*)(cam2 + 0x7f8) = 4;
                *(f32*)(cam2 + 0x7fc) = x;
                *(f32*)(cam2 + 0x800) = y;
                *(f32*)(cam2 + 0x804) = 0.0f;
                *(u8*)(cam2 + 0x7f6) = 0;
            }
            if (*(u8*)(this_ + 0x2ac) >= 0x18) {
                fn_801F6884(fn_801F856C());
                fn_80458FF0(lbl_8053AF80, 0x1000004, 0, 0);
                *(s32*)(this_ + 0x234) = 0;
                *(u8*)(this_ + 0x254) += 1;
            }
            break;
        }
        case 1:
            *(s32*)(this_ + 0x234) += 1;
            if (*(s32*)(this_ + 0x234) > 100) {
                *(s32*)(this_ + 0x27c) = 1;
                *(s32*)(this_ + 0x230) = 2;
                u32* rng = (u32*)((char*)lbl_8053AAF8 + 0xb4);
                *rng = *rng * 0x19660d + 0x3c6ef35f;
                u32 bits = (*rng >> 9) | 0x3f800000;
                *(s32*)(this_ + 0x234) = (s32)(100.0f * (*(f32*)&bits - 1.0f)) + 200;
            }
            break;
        }
        break;
    case 2:
        fn_800FC984(this_);
        break;
    case 3:
        fn_800FC4A8(this_);
        break;
    case 4:
        fn_800FC128(this_);
        break;
    case 5:
        fn_800FBD90(this_);
        break;
    case 6:
        fn_800FBA14(this_);
        break;
    case 7:
        fn_800FB32C(this_);
        break;
    case 8:
        fn_801F3D94(this_, 1);
        if (*(u32*)(this_ + 0x268) != 0) {
            *(u32*)(this_ + 0x268) += 0x2000;
            if (*(u32*)(this_ + 0x268) > 0x20000) {
                *(u32*)(this_ + 0x268) = 0;
            }
        }
        if (*(s32*)(this_ + 0x234) == 0x3c) {
            *(s32*)(this_ + 0x27c) = 0;
        }
        if (*(s32*)(this_ + 0x234) == 100) {
            *(s32*)(this_ + 0x27c) = 2;
            fn_801F0E34(this_, 0x4002a, 0);
        }
        if (*(s32*)(this_ + 0x234) > 0x96) {
            *(f32*)(this_ + 0x14) = 0.0f;
            *(u32*)(this_ + 0x238) |= 1;
            *(u32*)(this_ + 0x238) |= 4;
            *(s32*)(this_ + 0xb0) = 4;
            *(f32*)(this_ + 0x3c) = 0.0f;
            *(f32*)(this_ + 0x40) = 0.0f;
            *(f32*)(this_ + 0x44) = 10.0f;
            *(s32*)(this_ + 0x230) = 6;
            *(s32*)(this_ + 0x268) = 1;
            *(s32*)(this_ + 0x264) = 0;
            if (!(*(u32*)(this_ + 0x238) & 8)) {
                f32 r = (f32)*(s32*)(this_ + 0x108) / 480.0f;
                if (r < 0.4f) {
                    *(u8*)(this_ + 0x257) = 3;
                } else {
                    *(u8*)(this_ + 0x257) = 2;
                }
            }
            fn_801F0E34(this_, 0x4002b, 0);
        } else {
            *(f32*)(this_ + 0x44) -= 0.2f;
            *(f32*)(this_ + 0x14) += *(f32*)(this_ + 0x44);
            if (*(f32*)(this_ + 0x14) <= 0.0f) {
                *(f32*)(this_ + 0x14) = 0.0f;
                *(f32*)(this_ + 0x44) = 0.0f;
            }
            *(s32*)(this_ + 0x234) += 1;
        }
        break;
    case 9:
        fn_800FB070((u8*)this_);
        break;
    }
    *(s32*)(this_ + 0x258) += 1;
    *(u8*)(this_ + 0x2ac) = 0;
    fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
    char* c = *(char**)(lbl_8053AB10 + 0x24);
    if (*(u8*)(c + 0x179) == 0) {
        *(u8*)(c + 0x178) = 1;
    }
    fn_800F802C(this_ + 0x290);
    fn_800FA6B0(this_);
}

extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F2FAC(void* this_);
extern "C" void fn_8013CC50(s32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_800FB070(u8* this_) {
    *(f32*)(this_ + 0x44) -= 0.3f;
    *(JGeometry::TVec3<f32>*)(this_ + 0xc) += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);
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
    f32 a = -26.0f * v;
    f32 b = -50.0f * v;
    f32 c = 26.0f * v;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = b;
    *(f32*)(this_ + 0x68) = c;
    *(f32*)(this_ + 0x6c) = 0.0f;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = b;
    *(f32*)(this_ + 0x88) = c;
    *(f32*)(this_ + 0x8c) = 0.0f;
    if ((u32)*(s32*)(this_ + 0x268) != 0) {
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
            if (r < 0.4f) {
                *(u8*)(this_ + 0x257) = 3;
            } else {
                *(u8*)(this_ + 0x257) = 2;
            }
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
            ((ActorVT*)this_)->slot9();
        }
    }
}

extern "C" void fn_800FB32C(void* this_) {
    u8* p = (u8*)this_;
    JGeometry::TVec3f* pos = (JGeometry::TVec3f*)(p + 0xc);
    JGeometry::TVec3f* vel = (JGeometry::TVec3f*)(p + 0x3c);

    fn_800FA1A4(this_);
    if (p[0x256] != 0) {
        p[0x256] = p[0x256] - 1;
    }
    if (p[0x278] == 3 || p[0x278] == 6) {
        *(s32*)(p + 0xb0) = 0x10;
    } else {
        *(s32*)(p + 0xb0) = 4;
    }
    if (fn_801F3D94(this_, 1) == 1) {
        return;
    }
    if (*(u32*)(p + 0x268) != 0) {
        *(u32*)(p + 0x268) += 0x800;
        if (*(u32*)(p + 0x268) < 0x8000) {
            return;
        }
        if (*(u32*)(p + 0x268) > 0x10000) {
            *(u32*)(p + 0x268) = 0;
        }
    }

    vel->z = vel->z - lbl_8053C080;
    pos->add(*vel);

    if (pos->z > lbl_8053BFAC) {
        if (p[0x257] == 0) {
            fn_800FB6E0(this_, 0);
            fn_801F0E34(this_, 0x4002C, 0);
            JGeometry::TVec3f tmp = *pos;
            *(JGeometry::TVec3f*)(p + 0x290) = tmp;
            *(u8*)(p + 0x29c) = 1;
            *(f32*)(p + 0x2a0) = lbl_8053BFAC;
            *(s16*)(p + 0x2a4) = 0;
            p[0x2a6] = 0;
            p[0x29d] = 0;

            f32 scale;
            switch (p[0x29d]) {
            case 0:
                scale = lbl_8053BFC0;
                break;
            case 1:
                scale = lbl_8053BFC4;
                break;
            case 2:
                scale = lbl_8053BFC8;
                break;
            default:
                scale = lbl_8053BFC0;
                break;
            }
            if (*(s32*)(p + 4) < 8) {
                fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), p + 0x290, 2, 0, scale, lbl_8053BFCC);
            }
            fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 4), 0, lbl_8053BFF4, lbl_8053BFAC);
            fn_80134DE4(lbl_8053AAF8, 2, 0);
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e6, 0, 0, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e7, 0, 0, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e8, 0, 0, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e9, 0, 0, 0, 0, 1);
        } else {
            if (p[0x257] == 4) {
                fn_800FB6E0(this_, 1);
            } else {
                fn_800FB6E0(this_, 0);
            }
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4ed, 0, 0, 0, 0, 1);
        }
        pos->z = lbl_8053BFAC;
    }

    JGeometry::TVec3f n;
    if (fn_801F2618(this_, &n, 0)) {
        f32 dot = vel->x * n.x + vel->y * n.y + vel->z * n.z;
        f32 k = lbl_8053BFF0 * dot;
        vel->x = vel->x - k * n.x;
        vel->y = vel->y - k * n.y;
        vel->z = vel->z - k * n.z;
        *(s16*)(p + 0x262) = (s16)(lbl_8053C050 * JMath::atanTable_.atan2_(vel->x, vel->y));
    }
    if (vel->z > lbl_8053BFAC) {
        *(u32*)(p + 0x238) |= 1;
    } else {
        *(u32*)(p + 0x238) &= ~1;
    }
}

extern "C" s32 fn_801F3D94(void* p, s32 x);
extern "C" void fn_800FB6E0(void* p, s32 x);
extern f32 lbl_8053BFE0;
extern f32 lbl_8053C008;
extern f32 lbl_8053C018;
extern "C" void fn_800FBA14(char* this_) {
    u8* p = (u8*)this_;
    JGeometry::TVec3f* pos = (JGeometry::TVec3f*)(p + 0xc);
    JGeometry::TVec3f* vel = (JGeometry::TVec3f*)(p + 0x3c);
    u16 ang;
    f32 f;
    s32 n2;
    s32 n1;

    if (fn_801F3D94(this_, 1) == 1) {
        f32 z = lbl_8053BFAC;
        vel->set(z, z, lbl_8053BFFC);
        return;
    }
    if (*(u32*)(p + 0x268) != 0) {
        *(u32*)(p + 0x268) += 0x800;
        if (*(u32*)(p + 0x268) < 0x8000) {
            return;
        }
        if (*(u32*)(p + 0x268) > 0x10000) {
            *(u32*)(p + 0x268) = 0;
        }
    }
    ang = 0;
    f = lbl_8053BFAC;
    n2 = 0;
    n1 = 0;
    fn_801EEC98(this_, *(void**)(p + 0x198), (s16*)&ang, &n2, &f, &n1, 0, 0);
    if (vel->z > lbl_8053C008) {
        if (n1 >= 0) {
            pos->x += *(f32*)((u8*)sincosTable___5JMath + ((ang >> 2) & 0x3ff8));
            pos->y += *(f32*)((u8*)sincosTable___5JMath + ((ang >> 2) & 0x3ff8) + 4);
        }
    } else {
        *(u32*)(p + 0x238) &= ~1;
        *(u32*)(p + 0x238) |= 0x10;
    }

    f32 zero = lbl_8053BFAC;
    vel->z = vel->z - lbl_8053BFE0;
    pos->add(*vel);

    if (pos->z <= zero) {
        if (*(u32*)(p + 0x238) & 8) {
            p[0x257] = 0;
            fn_800FB6E0(this_, 0);
        } else {
            u8 k = p[0x257];
            vel->set((f32)k, lbl_8053C018 * (f32)k, zero);
            pos->z = zero;
            *(s32*)(p + 0x230) = 5;
            *(s32*)(p + 0x234) = 0x19;
        }
        JGeometry::TVec3f tmp = *pos;
        s32 room = *(s32*)(p + 4);
        ((JGeometry::TVec3f*)(p + 0x290))->set(tmp.x, tmp.y, tmp.z);
        *(u8*)(p + 0x29c) = 1;
        *(f32*)(p + 0x2a0) = lbl_8053BFAC;
        *(s16*)(p + 0x2a4) = 0;
        p[0x2a6] = 0;
        p[0x29d] = 1;

        f32 scale;
        switch (p[0x29d]) {
        case 0:
            scale = lbl_8053BFC0;
            break;
        case 1:
            scale = lbl_8053BFC4;
            break;
        case 2:
            scale = lbl_8053BFC8;
            break;
        default:
            scale = lbl_8053BFC0;
            break;
        }
        if (room < 8) {
            fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), p + 0x290, 2, 0, scale, lbl_8053BFCC);
        }
        fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 4), 0, lbl_8053BFA8, lbl_8053BFAC);
        fn_801F0E34(this_, 0x4002C, 0);
        fn_80134DE4(lbl_8053AAF8, 2, 0);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e6, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e7, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e8, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_8053BFCC, 0x4e9, 0, 0, 0, 0, 1);
    }
}

extern "C" void fn_800FC128(void* this_) {
    u8 ready = 0;
    if (*(u8*)((char*)this_ + 0x2AC) == 0) {
        *(s32*)((char*)this_ + 0xB0) = 4;
        *(s32*)((char*)this_ + 0x27C) = 1;
        *(s32*)((char*)this_ + 0x234) = 0;
        *(s32*)((char*)this_ + 0x230) = 8;
        fn_801F0E34(this_, 0x40005, 0);
        *(u8*)((char*)this_ + 0x2AD) = 1;
        ready = 1;
    }
    if (ready) {
        WrtcVec v(0.0f, 0.0f, 0.0f);
        *(s16*)((char*)this_ + 0x284) = 0;
        *(s16*)((char*)this_ + 0x286) = 0;
        void* a = fn_801F666C(fn_801F856C(), *(s32*)((char*)this_ + 0x288));
        void* b = fn_801F666C(fn_801F856C(), *(s32*)((char*)this_ + 0x28C));
        *(WrtcVec*)((char*)a + 0x3C) = v;
        *(WrtcVec*)((char*)b + 0x3C) = v;
        return;
    }
    if (*(u8*)((char*)this_ + 0x256) != 0) {
        *(u8*)((char*)this_ + 0x256) = *(u8*)((char*)this_ + 0x256) - 1;
    }
    if (*(u8*)((char*)this_ + 0x278) == 3 || *(u8*)((char*)this_ + 0x278) == 6) {
        *(s32*)((char*)this_ + 0xB0) = 0x10;
    } else {
        *(s32*)((char*)this_ + 0xB0) = 4;
    }
    fn_801F3D94(this_, 1);
}

static inline bool wrtcStartIdle(void* this_) {
    u8* p = (u8*)this_;
    if (p[0x2AC] == 0) {
        *(s32*)(p + 0xB0) = 4;
        *(s32*)(p + 0x27C) = 1;
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x230) = 8;
        fn_801F0E34(this_, 0x40005, 0);
        p[0x2AD] = 1;
        return true;
    }
    return false;
}

static inline bool wrtcStepFlash(void* this_) {
    u8* p = (u8*)this_;
    if (*(u32*)(p + 0x268) != 0) {
        *(u32*)(p + 0x268) += 0x2000;
        if (*(u32*)(p + 0x268) > 0x20000) {
            *(u32*)(p + 0x268) = 0;
        }
        return true;
    }
    return false;
}

extern "C" void fn_800FC4A8(void* this_) {
    u8* p = (u8*)this_;
    bool ready;
    if (p[0x2AC] == 0) {
        *(s32*)(p + 0xB0) = 4;
        *(s32*)(p + 0x27C) = 1;
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x230) = 8;
        fn_801F0E34(this_, 0x40005, 0);
        p[0x2AD] = 1;
        ready = 1;
    } else {
        ready = 0;
    }
    if (ready) {
        return;
    }
    if (p[0x256] != 0) {
        p[0x256]--;
    }
    if (p[0x278] == 3 || p[0x278] == 6) {
        *(s32*)(p + 0xB0) = 0x10;
    } else {
        *(s32*)(p + 0xB0) = 4;
    }
    bool timeout;
    if (*(u32*)(p + 0x268) != 0) {
        *(u32*)(p + 0x268) += 0x2000;
        if (*(u32*)(p + 0x268) > 0x20000) {
            *(u32*)(p + 0x268) = 0;
        }
        timeout = 1;
    } else {
        timeout = 0;
    }
    if (timeout == 1) {
        fn_801F3D94(this_, 1);
        return;
    }
    if (*(s32*)(p + 0x234) > 0x12C) {
        *(u16*)(p + 0x2B0) += 4;
        if (*(u16*)(p + 0x2B0) > 0x400) {
            *(u16*)(p + 0x2B0) = 0x400;
        }
        *(f32*)(p + 0x2A8) = *(f32*)(p + 0x2A8) + 0.01f;
        if (*(f32*)(p + 0x2A8) > 2.0f) {
            *(f32*)(p + 0x2A8) = 2.0f;
        }
    } else if (*(s32*)(p + 0x234) < 0x64) {
        *(u16*)(p + 0x2B0) -= 0x10;
        if (*(u16*)(p + 0x2B0) < 0x40) {
            *(u16*)(p + 0x2B0) = 0x40;
        }
        *(f32*)(p + 0x2A8) = *(f32*)(p + 0x2A8) - 0.03f;
        if (*(f32*)(p + 0x2A8) < 1.0f) {
            *(f32*)(p + 0x2A8) = 1.0f;
        }
    }
    *(u16*)(p + 0x2AE) += *(u16*)(p + 0x2B0);
    f32 v = (f32)(*(u16*)(p + 0x2B0) - 0x40) / 960.0f;
    *(f32*)((u8*)fn_801F1184(this_) + 0x48) = v;
    fn_801F0E34(this_, 0x4002F, 0);
    *(s32*)(p + 0x234) -= 1;
    if (*(s32*)(p + 0x234) <= 0) {
        *(s32*)(p + 0x230) = 2;
        u32* rng = (u32*)((char*)lbl_8053AAF8 + 0xB4);
        *rng = *rng * 0x19660D + 0x3C6EF35F;
        u32 bits = (*rng >> 9) | 0x3F800000;
        *(s32*)(p + 0x234) = (s32)(200.0f + (f32)(s32)(100.0f * (*(f32*)&bits - 1.0f)));
    }
    *(u16*)(p + 0x260) = *(u16*)(p + 0x260) + 0x200;
    *(f32*)(p + 0x14) = 5.0f * *(f32*)((u8*)sincosTable___5JMath + ((*(u16*)(p + 0x260) >> 2) & 0x3ff8)) + *(f32*)(p + 0x25C);
    if (*(s32*)(p + 0x234) == 0x15E) {
        u32* rng = (u32*)((char*)lbl_8053AAF8 + 0xB4);
        *rng = *rng * 0x19660D + 0x3C6EF35F;
        u32 bits = (*rng >> 9) | 0x3F800000;
        *(s32*)(p + 0x264) = (s32)(3.0f * (*(f32*)&bits - 1.0f));
        switch (*(s32*)(p + 0x264)) {
        case 0:
            *(s32*)(p + 0x27C) = 5;
            break;
        case 1:
            *(s32*)(p + 0x27C) = 6;
            break;
        case 2:
            *(s32*)(p + 0x27C) = 4;
            break;
        case 3:
            *(s32*)(p + 0x27C) = 5;
            break;
        }
    }
    if (*(s32*)(p + 0x234) > 0xC8 && *(s32*)(p + 0x234) <= 0x12C) {
        *(f32*)(p + 0x23C) = *(f32*)(p + 0x23C) + lbl_8049C5FC[*(s32*)(p + 0x264)][0];
        *(f32*)(p + 0x240) = *(f32*)(p + 0x240) + lbl_8049C5FC[*(s32*)(p + 0x264)][1];
    } else {
        if (*(s32*)(p + 0x234) > 0x64 && *(s32*)(p + 0x234) <= 0xC8) {
            *(f32*)(p + 0x23C) = *(f32*)(p + 0x23C) - lbl_8049C5FC[*(s32*)(p + 0x264)][0];
            *(f32*)(p + 0x240) = *(f32*)(p + 0x240) - lbl_8049C5FC[*(s32*)(p + 0x264)][1];
        }
        *(u16*)(p + 0x262) += 0xB0;
    }
    *(f32*)(p + 0xC) = 100.0f * *(f32*)((u8*)sincosTable___5JMath + ((*(u16*)(p + 0x262) >> 2) & 0x3ff8)) + *(f32*)(p + 0x23C);
    *(f32*)(p + 0x10) = 50.0f * *(f32*)((u8*)sincosTable___5JMath + ((*(u16*)(p + 0x262) >> 2) & 0x3ff8) + 4) + *(f32*)(p + 0x240) - 50.0f;
    fn_801F3D94(this_, 1);
    if (*(s32*)(p + 0x234) == 0x244) {
        *(s32*)(p + 0x27C) = 0;
    } else if (*(s32*)(p + 0x234) == 0x32) {
        *(s32*)(p + 0x27C) = 1;
    }
}

extern f32 lbl_8053C094;
extern "C" void fn_800FC984(void* this_) {
    u8* self = (u8*)this_;
    u8 bVar1;
    if (self[0x2ac] == 0) {
        *(s32*)(self + 0xb0) = 4;
        *(s32*)(self + 0x27c) = 1;
        *(s32*)(self + 0x234) = 0;
        *(s32*)(self + 0x230) = 8;
        fn_801F0E34(this_, 0x40005, 0);
        bVar1 = 1;
        self[0x2ad] = bVar1;
    } else {
        bVar1 = 0;
    }
    if (bVar1 == 0) {
        if (self[0x256] != 0) {
            self[0x256]--;
        }
        if (self[0x278] == 3 || self[0x278] == 6) {
            *(s32*)(self + 0xb0) = 0x10;
        } else {
            *(s32*)(self + 0xb0) = 4;
        }
        fn_800FA1A4(this_);
        u8 bVar2;
        if (*(s32*)(self + 0x268) != 0) {
            *(s32*)(self + 0x268) += 0x2000;
            if (*(u32*)(self + 0x268) > 0x20000) {
                *(s32*)(self + 0x268) = 0;
            }
            bVar2 = 1;
        } else {
            bVar2 = 0;
        }
        if (bVar2) {
            fn_801F3D94(this_, 1);
        } else {
            *(u16*)(self + 0x2b0) = 0x40;
            *(f32*)(self + 0x2a8) = lbl_8053BFCC;
            *(u16*)(self + 0x2ae) += *(u16*)(self + 0x2b0);
            void* iv = fn_801F1184(this_);
            *(f32*)((u8*)iv + 0x48) = lbl_8053BFAC;
            fn_801F0E34(this_, 0x4002f, 0);
            *(s32*)(self + 0x234) -= 1;
            if (*(s32*)(self + 0x234) <= 0) {
                if (((*(u32*)(self + 0x238) & 8) != 0) && self[0x2ac] <= 0xc) {
                    *(s32*)(self + 0x230) = 4;
                    *(s32*)(self + 0x234) = 0;
                    f32 fOne = lbl_8053BFCC;
                    f32 fScale = lbl_8053C078;
                    f32 fBase = lbl_8053C094;
                    void* lcg = lbl_8053AAF8;
                    s32 seed = *(s32*)((u8*)lcg + 0xb4) * 0x19660d + 0x3c6ef35f;
                    *(s32*)((u8*)lcg + 0xb4) = seed;
                    u32 bits = ((u32)seed >> 9) | 0x3f800000;
                    f32 fr = *(f32*)&bits;
                    s32 v = (s32)(fScale * (fr - fOne));
                    *(s16*)(self + 0x284) = (s16)(s32)(fBase + (f32)v);
                    lcg = lbl_8053AAF8;
                    seed = *(s32*)((u8*)lcg + 0xb4) * 0x19660d + 0x3c6ef35f;
                    *(s32*)((u8*)lcg + 0xb4) = seed;
                    bits = ((u32)seed >> 9) | 0x3f800000;
                    fr = *(f32*)&bits;
                    v = (s32)(fScale * (fr - fOne));
                    *(s16*)(self + 0x286) = (s16)(s32)(fBase + (f32)v);
                    *(s16*)(self + 0x2b2) = 0x3000;
                    *(s16*)(self + 0x2b4) = 0x5000;
                } else {
                    *(s32*)(self + 0x230) = 3;
                    *(s32*)(self + 0x234) = 600;
                }
            }
            *(f32*)(self + 0x23c) = *(f32*)(self + 0x248);
            *(f32*)(self + 0x240) = *(f32*)(self + 0x24c);
            *(f32*)(self + 0x244) = *(f32*)(self + 0x250);
            *(u16*)(self + 0x260) += 0x200;
            *(f32*)(self + 0x14) = lbl_8053BFF4 * sincosTable___5JMath[((*(u16*)(self + 0x260) >> 5) & 0x1fff) * 2] + *(f32*)(self + 0x25c);
            *(u16*)(self + 0x262) += 0xb0;
            *(f32*)(self + 0xc) = lbl_8053C078 * sincosTable___5JMath[((*(u16*)(self + 0x262) >> 5) & 0x1fff) * 2] + *(f32*)(self + 0x23c);
            *(f32*)(self + 0x10) = lbl_8053C048 * sincosTable___5JMath[((*(u16*)(self + 0x262) >> 5) & 0x1fff) * 2 + 1] + *(f32*)(self + 0x240) - lbl_8053C048;
            fn_801F3D94(this_, 1);
        }
    }
}

extern "C" void fn_800FCCCC(void* this_) {
    u8* p = (u8*)this_;
    s16 a = 0;
    f32 c = 0.0f;
    s32 b = 0;
    s32 idx = 0;
    *(s32*)(p + 0x234) = *(s32*)(p + 0x234) + 1;
    switch (p[0x254]) {
    case 0:
        *(s32*)(p + 0x27c) = 3;
        *(f32*)(p + 0x25c) = 0.0f;
        fn_801EEC98(this_, *(void**)(p + 0x198), &a, &b, &c, &idx, 0, 0);
        if (idx >= 0) {
            f32* q = fn_8023E724(idx);
            if (q[1] - *(f32*)(p + 0x10) < lbl_8053C0A8) {
                p[0x254]++;
                *(s32*)(p + 0x234) = 0;
            }
        }
        break;
    case 1:
        if (fn_801F68E0(fn_801F856C()) == 1) {
            p[0x254]++;
            *(s32*)(p + 0x234) = 0;
        }
        break;
    case 2: {
        u8* mgr = *(u8**)((u8*)lbl_8053AB10 + 0x30);
        if (mgr[0x284] == 0) {
            mgr[0x284] = 1;
            *(f32*)(mgr + 0x28c) = lbl_8053C074;
        }
        u8* o = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        f32 x = *(f32*)(p + 0xc);
        f32 y = *(f32*)(p + 0x10) - lbl_8053BFF8;
        if (o[0x7f5] == 0) {
            o[0x7f4] = 1;
            *(s32*)(o + 0x7f8) = 4;
            *(f32*)(o + 0x7fc) = x;
            *(f32*)(o + 0x800) = y;
            *(f32*)(o + 0x804) = 0.0f;
            o[0x7f6] = 0;
        }
        if (*(s32*)(p + 0x234) > 0xc8) {
            *(s32*)(p + 0x27c) = 0;
        }
        if (*(s32*)(p + 0x234) > 0x15e) {
            p[0x254]++;
            *(s32*)(p + 0x234) = 0;
            fn_801F0E34(this_, 0x40028, 0);
        }
        break;
    }
    case 3: {
        u8* mgr = *(u8**)((u8*)lbl_8053AB10 + 0x30);
        if (mgr[0x284] == 0) {
            mgr[0x284] = 1;
            *(f32*)(mgr + 0x28c) = lbl_8053C074;
        }
        u8* o = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        f32 x = *(f32*)(p + 0xc);
        f32 y = *(f32*)(p + 0x10) - lbl_8053BFF8;
        if (o[0x7f5] == 0) {
            o[0x7f4] = 1;
            *(s32*)(o + 0x7f8) = 4;
            *(f32*)(o + 0x7fc) = x;
            *(f32*)(o + 0x800) = y;
            *(f32*)(o + 0x804) = 0.0f;
            o[0x7f6] = 0;
        }
        f32 v = *(f32*)(p + 0x25c) + lbl_8053C00C;
        *(f32*)(p + 0x25c) = v;
        if (*(f32*)(p + 0x25c) <= lbl_8053BFFC) {
            *(f32*)(p + 0x25c) = lbl_8053BFFC;
        }
        *(u16*)(p + 0x260) = *(u16*)(p + 0x260) + 0x200;
        *(f32*)(p + 0x14) = lbl_8053BFF4 * *(f32*)((u8*)sincosTable___5JMath + ((*(u16*)(p + 0x260) >> 2) & 0x3ff8)) + *(f32*)(p + 0x25c);
        if (*(s32*)(p + 0x234) > 0x96) {
            *(s32*)(p + 0x230) = 1;
            p[0x254] = 0;
            *(s32*)(p + 0x234) = 0x3e8;
        }
        break;
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
