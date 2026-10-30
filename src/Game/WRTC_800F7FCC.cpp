// WRTC_800F7FCC: .text 0x800F7FCC-0x800FD438 (actor WRTC/BWRT)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/ItemBase.h"
extern "C" void* fn_804032E8(u32 fourcc, u32 id);
extern "C" void fn_801EFD34(void*, void*, f32, f32, f32, void*, s32);
extern const f32 lbl_8053C038;
extern const f32 lbl_8053C03C;
extern const f32 lbl_8053C040;
extern const u32 lbl_8049C5D0[];
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

extern const f32 lbl_8053BFA0;
extern const f32 lbl_8053BFA4;
extern f32 lbl_8053BFA8;
extern f32 lbl_8053BFB8;
extern "C" u8 fn_8023F264(s32 idx);
extern "C" u32 fn_8022EA0C(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" f32* fn_8023E724(s32 idx);
extern "C" const f32 sincosTable___5JMath[];
extern const f32 lbl_8053BFF4;
extern f32 lbl_8053BFF8;
extern const f32 lbl_8053BFFC;
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
extern const f32 lbl_8053BFF0;
extern f32 lbl_8053BFC0;
extern const f32 lbl_8053BFC4;
extern "C" s32 fn_801F285C(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern f32 lbl_8053BFC8;
extern "C" void fn_800FA1A4(void* this_);
extern "C" u8 fn_801F2618(void* this_, void* out, s32 flag);
extern "C" void fn_800FB6E0(void* p, s32 x);
extern f32 lbl_8053C084;
extern const f32 lbl_8053C088;
extern const f32 lbl_8053C08C;
extern const f32 lbl_8053BFE8;
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 a, f32 x, f32 y);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern f32 lbl_8053C02C;
extern f32 lbl_8053C030;
extern f32 lbl_8053C034;
extern const f32 lbl_8053BFAC;
extern "C" void* lbl_8053AAF8;
extern "C" s16 lbl_80463800[];
extern "C" s16 lbl_804638C0[];
extern "C" s32 fn_80138A30(void* game);
extern "C" void fn_800FA6B0(void* p);
extern "C" void fn_80458F9C(void* p, s32 x);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern void* lbl_8053AF80;
extern const f32 lbl_8053BFCC;
extern const f32 lbl_8053C054;
extern const f32 lbl_8053C058;
extern const f32 lbl_8053C05C;
extern "C" const f32 lbl_8049C634[];
extern f32 lbl_8053C014;
extern f32 lbl_8053C01C;
extern f32 lbl_8053C020;
extern f32 lbl_8053BFC8;
extern f32 lbl_8053C048;
extern f32 lbl_8053BFB0;
extern f32 lbl_8053C044;
extern f32 lbl_8053C04C;
extern f32 lbl_8053C078;
extern f32 lbl_8053C098;
extern f32 lbl_8053C09C;
extern f32 lbl_8053C0A0;
extern f32 lbl_8053C0A4;
extern const f32 lbl_8049C5FC[][2];
extern "C" void* fn_801F1184(void* this_);
extern "C" u8 fn_801F305C(void* this_);
extern "C" s32 fn_801F3D94(void* this_, s32 a);

static inline f32 WRTC_sinShort(s16 v) {
    return JMath::sincosTable_.mTable[(u32)(u16)v >> 5].first;
}
static inline f32 WRTC_cosShort(s16 v) {
    return JMath::sincosTable_.mTable[(u32)(u16)v >> 5].second;
}

static inline void WRTC_scaleMtx(f32 m[3][4], f32 x, f32 y, f32 z) {
    m[0][0] = x;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = y;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = z;
}

static inline f32 WRTC_random() {
    f32 one;
    f32 result;
    one = lbl_8053BFCC;
    u32* rng = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *rng = *rng * 0x19660d + 0x3c6ef35f;
    union { u32 u; f32 f; } value;
    value.u = (*rng >> 9) | 0x3f800000;
    result = value.f - one;
    return result;
}

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
    void fn_80239914(void* box, u32 room, u32 handle);
    u8 fn_801F2740(void* this_, s32 a);
    void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
    s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
    struct WrtcOwner {
        u8 pad0[0xc];
        f32 x, y, z;
        u8 pad18[0x284 - 0x18];
        s16 m284[2];
        u8 pad288[0x2ac - 0x288];
        u8 m2ac;
        u8 pad2ad[0x2b2 - 0x2ad];
        u16 m2b2;
        u16 m2b4;
    };
    struct WrtcSub {
        u8 pad0[4];
        u32 mRoomId;
        u8 pad8[4];
        JGeometry::TVec3<f32> mPos;
        u8 pad18[0x3c - 0x18];
        JGeometry::TVec3<f32> mVel;
        u8 pad48[0x198 - 0x48];
        u32 mRoomHandle;
        u8 pad19c[0x240 - 0x19c];
        WrtcOwner* mOwner;
        u8 pad244[3];
        s8 mIdx;
        u8 pad248;
        bool m249;
        u8 m24a;
    };
    struct H {
        static inline JGeometry::TVec3<f32> calcPos(WrtcOwner* owner, u8 idx) {
            register s16 ang;
            register f32 k;
            if (idx == 0) {
                k = 20.0f + (f32)(((owner->m2ac >> 1) + 1) * 20);
                ang = owner->m2b2;
            } else {
                k = (f32)(((owner->m2ac >> 1) + 1) * -20) - 20.0f;
                ang = owner->m2b4;
            }
            JGeometry::TVec3<f32> res;
            res.x = k * WRTC_sinShort(ang) + owner->x;
            res.y = k * WRTC_cosShort(ang) + owner->y;
            res.z = 10.0f + owner->z;
            return res;
        }
        static inline f32 quantize(f32 v) {
            return 0.0001f * (f32)(s32)(10000.0f * v);
        }
        static inline void lerpVec(f32* p1, const f32* p2, f32 scl) {
            f32 dx = quantize(p2[0] - p1[0]);
            p1[0] += dx * scl;
            f32 dy = quantize(p2[1] - p1[1]);
            p1[1] += dy * scl;
            f32 dz = quantize(p2[2] - p1[2]);
            p1[2] += dz * scl;
        }
        static inline f32 dot(WrtcSub* self, const JGeometry::TVec3<f32>& b) {
            f32 d = self->mVel.x * b.x + self->mVel.y * b.y;
            return d + self->mVel.z * b.z;
        }
    };
    WrtcSub* self = (WrtcSub*)this_;
    WrtcOwner* owner = self->mOwner;
    if (owner->m284[(u8)self->mIdx] != 0) {
        JGeometry::TVec3<f32> targetPos;
        targetPos.set(H::calcPos(owner, self->mIdx));
        f32 scl = 0.36f - 0.032f * (f32)((owner->m2ac >> 1) + 1);
        self->m249 = true;
        self->mVel.set(self->mPos);
        H::lerpVec((f32*)&self->mPos, (const f32*)&targetPos, scl);
        self->mVel.sub(self->mPos);
        self->mVel.scale(-0.5f);
    } else {
        self->mVel.z -= 0.2f;
        self->mPos.add(self->mVel);
        if (self->mPos.z <= 0.0f) {
            self->mPos.z = 0.0f;
            self->mVel.z = 0.0f;
            self->mVel.x *= 0.99f;
            self->mVel.y *= 0.99f;
        }
        JGeometry::TVec3<f32> n;
        if (fn_801F2618(this_, &n, 0)) {
            f32 k = 2.0f * H::dot(self, n);
            self->mVel.x -= k * n.x;
            self->mVel.y -= k * n.y;
            self->mVel.z -= k * n.z;
            if (self->m24a == 0) {
                fn_801F0E34(this_, 0x4002d, 0);
                self->m24a = 1;
            }
        }
    }
    if (self->m24a != 0) {
        self->m24a++;
        if (self->m24a >= 30) {
            self->m24a = 0;
        }
    }
    if (__fabsf(self->mVel.x) < 1.0f && __fabsf(self->mVel.y) < 1.0f) {
        JGeometry::TBox2<f32> box(self->mPos.x - 10.0f, self->mPos.y - 10.0f, self->mPos.x + 10.0f, self->mPos.y + 10.0f);
        fn_80239914(&box, self->mRoomId, self->mRoomHandle);
        if (fn_801F2740(this_, -1)) {
            self->mVel.x = 0.0f;
            self->mVel.y = 0.0f;
        }
    } else {
        fn_801F2B7C(this_, 2, -1, 1);
    }
    if (__fabsf(self->mVel.x) < 1.0f && __fabsf(self->mVel.y) < 1.0f) {
        s32 hit = fn_801F285C(this_, 0, 0, 1, -1);
        if (hit >= 0) {
            JGeometry::TVec3<f32> dir(0.0f, 0.0f, 0.0f);
            dir.x = fn_8023E724(hit)[0] - self->mPos.x;
            dir.y = fn_8023E724(hit)[1] - self->mPos.y;
            dir.normalize();
            dir.scale(-1.0f);
            self->mVel.x = 1.5f * dir.x;
            self->mVel.y = 1.5f * dir.y;
            JGeometry::TVec2<f32> p2(self->mPos.x, self->mPos.y);
            fn_80238548(hit, 0, (f32*)&p2, 0x10);
        }
    }
}

extern "C" void fn_800F9170(void* this_) {
    JGeometry::TVec3<f32> d, pos, tmp;
    int idx;
    *(u8*)((char*)this_ + 0x249) = idx = 1;
    void* owner = *(void**)((char*)this_ + 0x240);
    unsigned int m = *(u8*)((char*)owner + 0x2ac);
    int k;
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
    unsigned int ang = (u16)( *(u16*)((char*)owner + 0x2ae) + m * k + (idx << 12));
    f32 scale = *(f32*)((char*)owner + 0x2a8);
    f32 t = lbl_8049C634[idx];
    f32 x = t * sincosTable___5JMath[(ang >> 5) * 2];
    f32 y = t * sincosTable___5JMath[(ang >> 5) * 2 + 1];
    x = scale * x + *(f32*)((char*)owner + 0xc);
    y = scale * y + *(f32*)((char*)owner + 0x10);
    f32 z = (f32)(s32)(idx * 13) + (lbl_8053BFFC + *(f32*)((char*)owner + 0x14));
    *(u8*)((char*)owner + 0x2ac) += 1;
    tmp.set(x, y, z);
    pos = tmp;
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
        d = *(JGeometry::TVec3<f32>*)((char*)owner + 0xc);
        d -= *(JGeometry::TVec3<f32>*)((char*)this_ + 0xc);
        if (d.length() < lbl_8053C01C && *(u16*)((char*)this_ + 0x24e) > 0x50) {
            *(s32*)((char*)this_ + 0x234) = 1;
        }
        f32 inv;
        f32 scalar;
        f32 sq = d.squared();
        if (!(sq <= JGeometry::TUtilf::epsilon())) {
            inv = JGeometry::TUtilf::inv_sqrt(sq);
            d.scale(inv);
        }
            scalar = lbl_8053BFC8;
            d.scale(scalar);
            d.z = lbl_8053BFAC;
            if (*(f32*)((char*)this_ + 0x14) < lbl_8053BFFC || *(u16*)((char*)this_ + 0x24e) < 0x50) {
                d.x = d.y = d.z = 0.0f;
            }
            ((JGeometry::TVec3<f32>*)((char*)this_ + 0x3c))->set(d);
            *(JGeometry::TVec3<f32>*)((char*)this_ + 0xc) += *(JGeometry::TVec3<f32>*)((char*)this_ + 0x3c);
            *(u16*)((char*)this_ + 0x244) += 0x480;
            *(f32*)((char*)this_ + 0x14) = lbl_8053C020 * __fabsf(sincosTable___5JMath[((u32)*(u16*)((char*)this_ + 0x244) >> 5) * 2]);
            if (*(f32*)((char*)this_ + 0x14) <= lbl_8053BFE8) {
                fn_801F0E34(this_, 0x50083, 0);
            }
    } else {
        return;
    }
}

extern const f32 lbl_8053BFD0;
extern const f32 lbl_8053BFD4;
extern f32 lbl_8053C028;
extern const f32 lbl_8053C024;
extern const f32 lbl_8053C004;
extern const f32 lbl_8053C000;
extern "C" s16 lbl_8049C3B8[];
static inline void WRTC_moveTowards(u8* self,const JGeometry::TVec3f& out,f32 k) {
    if(fn_801F3D94(self,1)==0){
        s32 idx=fn_801F285C(self,0,0,1,-1);
        if(idx>=0){
            JGeometry::TVec2f pos(*(f32*)(self+0xc),*(f32*)(self+0x10));
            fn_80238548(idx,0,(f32*)&pos,0x10);
        }
        *(f32*)(self+0xc)=k*((f32)(s32)(10000.0f*(out.x-*(f32*)(self+0xc)))*0.0001f)+*(f32*)(self+0xc);
        *(f32*)(self+0x10)=k*((f32)(s32)(10000.0f*(out.y-*(f32*)(self+0x10)))*0.0001f)+*(f32*)(self+0x10);
        *(f32*)(self+0x14)=k*((f32)(s32)(10000.0f*(out.z-*(f32*)(self+0x14)))*0.0001f)+*(f32*)(self+0x14);
        fn_801F2B7C(self,2,-1,1);
    }
}

static inline JGeometry::TVec3f WRTC_circlePosition(u8* p) {
    u32 n=p[0x2ac];
    s32 kind,step;
    if(n<8){kind=0;step=0x2000;}
    else if(n<16){kind=1;step=0x2000;}
    else if(n<21){kind=2;step=0x3332;}
    else if(n<24){kind=3;step=0x5554;}
    else if(n<26){kind=4;step=0x8000;}
    else {kind=5;step=0x2000;}
    u16 angle=*(u16*)(p+0x2ae)+n*step+kind*0x1000;
    f32 radius=lbl_8049C634[kind];
    f32 sn=WRTC_sinShort(angle);
    f32 cs=WRTC_cosShort(angle);
    f32 x=*(f32*)(p+0x2a8)*(radius*sn)+*(f32*)(p+0xc);
    f32 y=*(f32*)(p+0x2a8)*(radius*cs)+*(f32*)(p+0x10);
    f32 z=(f32)(kind*13)+(lbl_8053BFFC+*(f32*)(p+0x14));
    JGeometry::TVec3f result(x,y,z);
    p[0x2ac]++;
    return result;
}

static inline JGeometry::TVec3f WRTC_linePosition(u8* p,s32 n) {
    s16 angle;
    register f32 radius;
    if(n&1){radius=20.0f+(f32)(((n>>1)+1)*20);angle=(s16)*(u16*)(p+0x2b2);}
    else {radius=(f32)(((n>>1)+1)*-20)-20.0f;angle=(s16)*(u16*)(p+0x2b4);}
    s32 index=(u16)angle;
    index >>= 5;
    f32 sn=JMath::sincosTable_.mTable[index].first;
    f32 cs=JMath::sincosTable_.mTable[index].second;
    f32 x=sn*radius+*(f32*)(p+0xc);
    f32 y=cs*radius+*(f32*)(p+0x10);
    f32 z=lbl_8053BFFC+*(f32*)(p+0x14);
    p[0x2ac]++;
    JGeometry::TVec3f result(x,y,z);
    return result;
}

#pragma opt_lifetimes off
extern "C" void fn_800F953C(void* this_) {
    u8* self=(u8*)this_;
    Vec out;
    f32 k;
    *(s32*)(self+0xb0)=0x80004;
    self[0x1a8]=1;
    u8* p=*(u8**)(self+0x240);
    int state=*(s32*)(p+0x230);
    if(state==3){
        const JGeometry::TVec3f& v=WRTC_circlePosition(p);
        out=v;
        k=lbl_8053BFC0;
        *(u8*)(self+0x249)=1;
    }else if(state==4){
        s32 n=p[0x2ac];
        const JGeometry::TVec3f& v=WRTC_linePosition(p,n);
        out=v;
        int half=(n>>1)+1;
        k=(0.001f*(f32)lbl_8049C3B8[8]+0.36f)-(0.001f*(f32)lbl_8049C3B8[9]+0.032f)*(f32)half;
        *(u8*)(self+0x249)=1;
    }else if(state==1){
        const JGeometry::TVec3f& v=WRTC_circlePosition(p);
        out=v;
        k=lbl_8053C028;
        *(u8*)(self+0x249)=1;
    }else{
        const JGeometry::TVec3f& v=WRTC_circlePosition(p);
        out=v;
        k=lbl_8053C00C;
        *(u8*)(self+0x249)=0;
    }
    WRTC_moveTowards(self,*(const JGeometry::TVec3f*)&out,k);
}
#pragma opt_lifetimes reset
extern "C" void fn_800F9C20(void* this_) {
    char* rng;
    unsigned int multiplier;
    s32 y;
    s32 x;
    const s16* table;
    char* p = (char*)this_;
    ((JGeometry::TBox2<f32>*)(p+0x70))->set(-13.0f,-14.0f,13.0f,8.0f);
    *(s32*)(p + 0x108) = 4;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x246) = 0;
    *(u16*)(p + 0x244) = 0;
    *(u8*)(p + 0x249) = 0;
    *(u8*)(p + 0x247) = (*(u32*)(p + 0x90) >> 16) & 0xff;
    *(u8*)(p + 0x248) = *(u32*)(p + 0x90) >> 24;
    if (*(u8*)(p + 0x248) == 2) {
        ((JGeometry::TBox2<f32>*)(p+0x80))->set(-13.0f,-14.0f,13.0f,8.0f);
        ((JGeometry::TBox2<f32>*)(p+0x60))->set(-13.0f,-14.0f,13.0f,8.0f);
        *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + (f32)lbl_804638C0[*(u8*)(p + 0x247) * 2];
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + (f32)lbl_804638C0[*(u8*)(p + 0x247) * 2 + 1];
        *(u32*)(p + 0xb0) = 0x40004;
    } else {
        if (*(u8*)(p + 0x247) < 0x30) {
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + (f32)lbl_80463800[*(u8*)(p + 0x247) * 2];
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + (f32)lbl_80463800[*(u8*)(p + 0x247) * 2 + 1];
        } else {
            table=lbl_80463800;
            x=table[0];
            y=table[1];
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + (f32)x;
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + (f32)y;
        }
        *(f32*)(p + 0x14) = lbl_8053BFAC;
        *(u16*)(p + 0x24c) = 0;
        s32 step;
        int i;
        for (i = 0; i < *(u8*)(p + 0x247); i++) {
            step = 10;
            if (*(u8*)(p + 0x247) < 0x1e) {
                step = 0x28 - *(u8*)(p + 0x247);
            }
            *(u16*)(p + 0x24c) = *(u16*)(p + 0x24c) + step;
        }
        f32 cnt = fn_80138A30(lbl_8053AAF8);
        if (lbl_8053BFCC == cnt) {
            *(s32*)(p + 0x23c) = -1;
            *(u16*)(p + 0x94) = 0;
        } else {
            multiplier=0x19660d;
            union {u32 u; f32 f;} first;
            f32 one=lbl_8053BFCC;
            rng=(char*)lbl_8053AAF8;
            *(u32*)(rng+0xb4)=*(u32*)(rng+0xb4)*multiplier+0x3c6ef35f;
            first.u=(*(u32*)(rng+0xb4)>>9)|0x3f800000;
            *(s32*)(p + 0x23c) = (s32)(cnt * (first.f-one));
            *(u16*)(p + 0x94) = *(s32*)(p + 0x23c) + 1;
            union {u32 u; f32 f;} second;
            rng=(char*)lbl_8053AAF8;
            *(u32*)(rng+0xb4)=*(u32*)(rng+0xb4)*multiplier+0x3c6ef35f;
            second.u=(*(u32*)(rng+0xb4)>>9)|0x3f800000;
            if ((s32)(lbl_8053BFA0 * (second.f-one)) < 1) {
                *(s32*)(p + 0x23c) = -1;
                *(u16*)(p + 0x94) = 0;
            }
        }
    }
}

#pragma opt_propagation off
extern "C" void fn_800F9F54(u8* this_) {
    f32 xs;
    f32 zero;
    f32 zs;
    f32 scale;
    f32 x;
    u8* self = this_;
    f32 sin = sincosTable___5JMath[((u16)*(u32*)(self + 0x268) >> 5) * 2];
    x = lbl_8053BFC4 * sin;
    f32 z = lbl_8053C038 * sin;
    DrawRec r;
    f32 m[3][4];
    zero = 0.0f;
    m[0][3] = zero;
    m[1][3] = zero;
    m[2][3] = zero;
    scale = *(f32*)(self + 0x26c);
    zs = scale + z;
    xs = scale + x;
    WRTC_scaleMtx(m, xs, scale, zs);
    r.w18 = m;
    ((u8*)&r.w14)[0] = (u8)(s32)(lbl_8053C03C * *(f32*)(self + 0x274));
    ((u8*)&r.w14)[1] = (u8)(s32)(lbl_8053C03C * *(f32*)(self + 0x274));
    ((u8*)&r.w14)[2] = (u8)(s32)(lbl_8053C03C * *(f32*)(self + 0x274));
    ((u8*)&r.w10)[3] = (u8)(s32)(lbl_8053C03C * *(f32*)(self + 0x270));
    if (*(u32*)(self + 0x238) & 2) r.w30 = 13;
    else if (*(u32*)(self + 0x238) & 4) r.w30 = 17;
    void* res = fn_804032E8(0x57415254, lbl_8049C5D0[self[0x278]]);
    fn_801EFD34(self, res, 0.0f, lbl_8053C040 * (*(f32*)(self + 0x26c) + z), 0.0f, &r, 5);
}
#pragma opt_propagation reset
extern "C" void fn_800FA1A4(void* this_) {
    char* self = (char*)this_;
    if (*(u32*)(self + 0x238) & 8) {
        char* pa = (char*)fn_801F666C(fn_801F856C(), *(s32*)(self + 0x288));
        char* pb = (char*)fn_801F666C(fn_801F856C(), *(s32*)(self + 0x28c));
        JGeometry::TVec3<f32> posA(*(Vec*)(pa + 0xc));
        JGeometry::TVec3<f32> posB(*(Vec*)(pb + 0xc));
        JGeometry::TVec3<f32> d(posA);
        d -= posB;
        if (d.length() < lbl_8053BFF8) {
            JGeometry::TVec3<f32> velA(*(Vec*)(pa + 0x3c));
            JGeometry::TVec3<f32> velB(*(Vec*)(pb + 0x3c));
            *(JGeometry::TVec3<f32>*)(pa + 0x3c) = velB;
            *(JGeometry::TVec3<f32>*)(pb + 0x3c) = velA;
            JGeometry::TVec3<f32> offset;
            JGeometry::TVec3<f32> mid(posA);
            mid.add(posB);
            mid.scale(0.5f);
            d.normalize();
            offset.set(d.x, d.y, d.z);
            offset.scale(10.0f);
            offset += mid;
            *(JGeometry::TVec3<f32>*)(pa + 0xc) = offset;
            offset.set(d.x, d.y, d.z);
            offset.scale(-10.0f);
            offset += mid;
            *(JGeometry::TVec3<f32>*)(pb + 0xc) = offset;
        }
        if (*(u8*)(self + 0x2ac) == 0) {
            d.set(*(f32*)(self + 0xc), *(f32*)(self + 0x10) - lbl_8053BFF8, *(f32*)(self + 0x14));
            d -= posA;
            if (d.length() < lbl_8053C048) {
                d.normalize();
                d.scale(-5.0f);
                *(JGeometry::TVec3<f32>*)(pa + 0x3c) = d;
            }
            d.set(*(f32*)(self + 0xc), *(f32*)(self + 0x10) - lbl_8053BFF8, *(f32*)(self + 0x14));
            d -= posB;
            if (d.length() < lbl_8053C048) {
                d.normalize();
                d.scale(-5.0f);
                *(JGeometry::TVec3<f32>*)(pb + 0x3c) = d;
            }
        }
    }
}

extern "C" u8 lbl_8049C61C[];
extern "C" u8 lbl_8049C628[];
extern "C" u8 lbl_80539E80[8];
extern "C" u8 lbl_80539E88[8];
extern "C" u8 lbl_80539E90[4];
extern "C" u8 lbl_80539E94[4];
extern "C" u8 lbl_80539E98[8];
extern "C" u8 lbl_80539EA0[8];
extern "C" void fn_801F0E34(void*, u32, s32);
#pragma opt_propagation off
extern "C" void fn_800FA6B0(void* p)
{
    u8* self = (u8*)p;

    s32 previous = *(s32*)(self + 0x280);
    if (previous != *(s32*)(self + 0x27c)) {
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
        } else if (self[0x27a] == lbl_8049C628[self[0x279]]) {
            self[0x27a] = 0;
            self[0x279]++;
        }
        if (self[0x27a] == 0 && (self[0x279] == 0 || self[0x279] == 6)) {
            fn_801F0E34(self, 0x40026, 0);
        }
        break;
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
        }
        break;
    }
    self[0x27a]++;
}
#pragma opt_propagation reset
extern "C" void fn_801F37AC(void*, s32, void*, s32, s32, s32);
extern "C" void fn_800FA944(char* this_) {
    u32 st = *(u32*)(this_ + 0xb0);
    if (st != 4 && st != 0x12) {
        if (*(u8*)(this_ + 0x256) != 0) {
        } else {
            if (*(s32*)(this_ + 0xd8) == 0) {
                this_[0x255]++;
                this_[0x256] = 0x32;
                if (*(u32*)(this_ + 0x268) == 0) {
                    *(u32*)(this_ + 0x268) = 1;
                }
                fn_801F37AC(this_, 0, this_ + 0xc, 3, 0, -1);
                fn_801F0E34(this_, 0x40005, 0);
                WrtcVec v(lbl_8053BFAC, lbl_8053BFAC, lbl_8053BFAC);
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

static inline f32 WRTC_velocityDot(WrtcVec* v, const JGeometry::TVec3<f32>& n) {
    f32 d = v->x * n.x + v->y * n.y;
    return d + v->z * n.z;
}

extern "C" void fn_800FB32C(void* this_) {
    u8* p = (u8*)this_;
    JGeometry::TVec3f* pos = (JGeometry::TVec3f*)(p + 0xc);
    JGeometry::TVec3f* vel = (JGeometry::TVec3f*)(p + 0x3c);
    JGeometry::TVec3f n;

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
    pos->add(*(JGeometry::TVec3f*)vel);

    if (pos->z <= lbl_8053BFAC) {
        if (p[0x257] == 0) {
            fn_800FB6E0(this_, 0);
            fn_801F0E34(this_, 0x4002C, 0);
            JGeometry::TVec3f tmp;
            tmp = *pos;
            s32 room = *(s32*)(p + 4);
            *(f32*)(p + 0x290) = tmp.x;
            *(f32*)(p + 0x294) = tmp.y;
            *(f32*)(p + 0x298) = tmp.z;
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
            if (room < 8) {
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

    if (fn_801F2618(this_, &n, 0)) {
        WrtcVec* reflected = (WrtcVec*)(p + 0x3c);
        f32 dot = WRTC_velocityDot(reflected, n);
        f32 k = lbl_8053BFF0 * dot;
        reflected->x -= k * n.x;
        reflected->y -= k * n.y;
        reflected->z -= k * n.z;
        f32 angle = JMath::atanTable_.atan2_(reflected->x, reflected->y);
        angle *= lbl_8053C050;
        *(s16*)(p + 0x262) = (s16)angle;
    }
    if (vel->z > lbl_8053BFAC) {
        *(u32*)(p + (s32)0x238) |= 1;
    } else {
        *(u32*)(p + 0x238) &= ~1;
    }
}

#pragma opt_propagation off
extern "C" void fn_800FB6E0(void* this_, s32 mode) {
    u8* p = (u8*)this_;
    u16 angle = 0;
    f32 distance = lbl_8053BFAC;
    s32 unused = 0;
    s32 index = 0;
    fn_801EEC98(this_, *(void**)(p + 0x198), (s16*)&angle, &unused, &distance, &index, 0, 0);
    if (index != -1 && distance < lbl_8053C048) {
        *(u16*)(p + 0x262) = angle;
    } else {
        if ((*(u32*)(p + 0x238) & 8) == 0) {
            distance = lbl_8053BFD4;
        } else {
            u8* first = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(p + 0x288));
            u8* second = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(p + 0x28c));
            JGeometry::TVec3f b;
            JGeometry::TVec3f a;
            a = *(JGeometry::TVec3f*)(p + 0xc);
            b = *(JGeometry::TVec3f*)(p + 0xc);
            a -= *(JGeometry::TVec3f*)(first + 0xc);
            b -= *(JGeometry::TVec3f*)(second + 0xc);
            f32 len = a.length();
            if (len < b.length()) {
                f32 radians = JMath::atanTable_.atan2_(-a.x, -a.y);
                radians *= lbl_8053C050;
                angle = (s32)radians;
            } else {
                f32 radians = JMath::atanTable_.atan2_(-b.x, -b.y);
                radians *= lbl_8053C050;
                angle = (s32)radians;
            }
        }
        if (distance < lbl_8053C084) {
            *(u16*)(p + 0x262) = angle;
        } else {
            f32 one;
            f32 random;
            f32 k;
            u32* rng = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
            one = lbl_8053BFCC;
            k = lbl_8053C088;
            *rng = *rng * 0x19660d + 0x3c6ef35f;
            union { u32 u; f32 f; } value;
            value.u = (*rng >> 9) | 0x3f800000;
            random = value.f;
            one = random - one;
            *(u16*)(p + 0x262) += (s16)(0x2000 - (s32)(k * one));
        }
    }
    *(f32*)(p + 0x3c) = lbl_8053BFE8 * sincosTable___5JMath[((*(u16*)(p + 0x262) >> 5) & 0x7ff) * 2];
    *(f32*)(p + 0x40) = lbl_8053BFE8 * sincosTable___5JMath[((*(u16*)(p + 0x262) >> 5) & 0x7ff) * 2 + 1];
    if (mode == 1) {
        *(f32*)(p + 0x44) = lbl_8053BFA8;
        p[0x257] = 0;
        fn_801F0E34(this_, 0x4002b, 0);
    } else {
        *(f32*)(p + 0x44) = lbl_8053BFF4;
        p[0x257]++;
        fn_801F0E34(this_, 0x400ca, 0);
    }
    *(u32*)(p + 0x238) |= 4;
    *(u32*)(p + 0x238) &= ~0x10;
    f32 scale = 1.4f * *(f32*)(p + 0x26c);
    f32 a = -26.0f * scale;
    f32 b = -50.0f * scale;
    f32 c = 26.0f * scale;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = b;
    *(f32*)(p + 0x68) = c;
    *(f32*)(p + 0x6c) = 0.0f;
    *(s32*)(p + 0x230) = 7;
    *(s32*)(p + 0x268) = 1;
    *(s32*)(p + 0x264) = 0;
}
#pragma opt_propagation reset
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

extern const f32 lbl_8053C07C;
extern "C" void fn_800FBD90(void* this_) {
    char* p = (char*)this_;
    if (*(u8*)(p + 0x256) != 0) --*(u8*)(p + 0x256);
    if (*(u8*)(p + 0x278) == 3 || *(u8*)(p + 0x278) == 6) {
        *(s32*)(p + 0xb0) = 0x10;
    } else {
        *(s32*)(p + 0xb0) = 4;
    }
    fn_800FA1A4(p);
    --*(s32*)(p + 0x234);
    if (*(s32*)(p + 0x234) >= 0) {
        f32 scale = lbl_8053C08C * *(f32*)(p + 0x26c);
        *(f32*)(p + 0x60) = lbl_8053C054 * scale;
        *(f32*)(p + 0x64) = lbl_8053C058 * scale;
        *(f32*)(p + 0x68) = lbl_8053C05C * scale;
        *(f32*)(p + 0x6c) = lbl_8053BFAC;
        return;
    }
    *(u32*)(p + 0x238) &= ~0x10;
    f32 scale = *(f32*)(p + 0x26c);
    f32 a = lbl_8053C054 * scale;
    f32 b = lbl_8053C058 * scale;
    f32 c = lbl_8053C05C * scale;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = b;
    *(f32*)(p + 0x68) = c;
    *(f32*)(p + 0x6c) = lbl_8053BFAC;
    *(f32*)(p + 0x80) = a;
    *(f32*)(p + 0x84) = b;
    *(f32*)(p + 0x88) = c;
    *(f32*)(p + 0x8c) = lbl_8053BFAC;
    if (fn_801F2FAC(p)) {
        *(s32*)(p + 0xd8) = 10;
        *(s32*)(p + 0xdc) = 10;
        *(s32*)(p + 0x230) = 9;
        *(u32*)(p + 0x238) |= 1;
        *(u32*)(p + 0x238) &= ~4;
        *(f32*)(p + 0x3c) = lbl_8053BFAC;
        *(f32*)(p + 0x40) = lbl_8053BFAC;
        *(f32*)(p + 0x44) = lbl_8053BFF4;
        *(s32*)(p + 0x268) = 0;
        *(s32*)(p + 0x264) = 0;
        f32 scale = *(f32*)(p + 0x26c);
        *(f32*)(p + 0x60) = lbl_8053C054 * scale;
        *(f32*)(p + 0x64) = lbl_8053C058 * scale;
        *(f32*)(p + 0x68) = lbl_8053C05C * scale;
        *(f32*)(p + 0x6c) = lbl_8053BFAC;
        fn_801F0E34(p, 0x40005, 0);
        if (*(s32*)(p + 0x108) <= 10) ((ActorVT*)p)->slot9();
        return;
    }
    fn_801F3D94(p, 1);
    if (*(s32*)(p + 0x264) != 0) {
        if (*(u32*)(p + 0x268) != 0) {
            *(u32*)(p + 0x268) += 0x2000;
            if (*(u32*)(p + 0x268) > 0x10000) *(u32*)(p + 0x268) = 0;
        }
        ++*(s32*)(p + 0x264);
        if (*(s32*)(p + 0x264) == 0x118) {
            *(s32*)(p + 0x264) = 0;
            *(u32*)(p + 0x238) |= 1;
            *(u32*)(p + 0x238) |= 4;
            *(s32*)(p + 0xb0) = 4;
            *(f32*)(p + 0x3c) = lbl_8053BFAC;
            *(f32*)(p + 0x40) = lbl_8053BFAC;
            *(f32*)(p + 0x44) = 10.0f;
            *(s32*)(p + 0x230) = 6;
            *(s32*)(p + 0x268) = 1;
            *(s32*)(p + 0x264) = 0;
            if (!(*(u32*)(p + 0x238) & 8)) {
                f32 r = (f32)*(s32*)(p + 0x108) / lbl_8053C07C;
                if (r < lbl_8053BFC4) *(u8*)(p + 0x257) = 3;
                else *(u8*)(p + 0x257) = 2;
            }
            fn_801F0E34(p, 0x4002b, 0);
        }
    } else {
        *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
        fn_801F0E34(p, 0x4002e, 0);
        JGeometry::TVec3<f32> n;
        if (fn_801F2618(p, &n, 0)) {
            WrtcVec* vel = (WrtcVec*)(p + 0x3c);
            f32 dot = WRTC_velocityDot(vel, n);
            f32 k = lbl_8053BFF0 * dot;
            vel->x -= k * n.x;
            vel->y -= k * n.y;
            vel->z -= k * n.z;
            fn_801F0E34(p, 0x4002d, 0);
        }
    }
}

extern "C" void fn_800FC128(void* this_) {
    char* a;
    char* self=(char*)this_;
    u8 ready;
    if (*(u8*)(self+0x2ac)==0) {
        *(s32*)(self+0xb0)=4;
        *(s32*)(self+0x27c)=1;
        *(s32*)(self+0x234)=0;
        *(s32*)(self+0x230)=8;
        fn_801F0E34(this_,0x40005,0);
        *(u8*)(self+0x2ad)=ready=1;
    } else ready=0;
    if (ready) {
        *(s16*)(self+0x284)=0;
        *(s16*)(self+0x286)=0;
        JGeometry::TVec3<f32> zero(0.0f,0.0f,0.0f);
        a=(char*)fn_801F666C(fn_801F856C(),*(u32*)(self+0x288));
        char* b=(char*)fn_801F666C(fn_801F856C(),*(u32*)(self+0x28c));
        *(JGeometry::TVec3<f32>*)(a+0x3c)=zero;
        *(JGeometry::TVec3<f32>*)(b+0x3c)=zero;
        return;
    }
    if (*(u8*)(self+0x256)!=0) --*(u8*)(self+0x256);
    if (*(u8*)(self+0x278)==3 || *(u8*)(self+0x278)==6) *(s32*)(self+0xb0)=16;
    else *(s32*)(self+0xb0)=4;
    u8 flash;
    if (*(u32*)(self+0x268)!=0) {
        *(u32*)(self+0x268)+=0x2000;
        if (*(u32*)(self+0x268)>0x20000) *(u32*)(self+0x268)=0;
        flash=1;
    } else flash=0;
    if (flash==1) {
        fn_801F3D94(this_,1);
        return;
    }
    if (*(s32*)(self+0x234)>=100) {
        *(u16*)(self+0x2b2)+=0x400;
        *(u16*)(self+0x2b4)-=0x400;
    }
    if (*(s32*)(self+0x234)==20) *(s32*)(self+0x27c)=0;
    if (*(u16*)(self+0x2b2)==0x4000 || *(u16*)(self+0x2b2)==0xc000) fn_801F0E34(this_,0x400cb,0);
    if (*(s16*)(self+0x284)>0) --*(s16*)(self+0x284);
    if (*(s16*)(self+0x286)>0) --*(s16*)(self+0x286);
    if (*(s16*)(self+0x284)<50 && *(u16*)(self+0x2b2)>0x3000 && *(u16*)(self+0x2b2)<0x5000) *(s16*)(self+0x284)=0;
    if (*(s16*)(self+0x286)<50 && *(u16*)(self+0x2b4)>0x3000 && *(u16*)(self+0x2b4)<0x5000) *(s16*)(self+0x286)=0;
    ++*(s32*)(self+0x234);
    if (*(s16*)(self+0x284)==0 && *(s16*)(self+0x286)==0) {
        *(s32*)(self+0x27c)=1;
        *(s32*)(self+0x230)=2;
        *(s32*)(self+0x234)=(s32)(300.0f+(f32)(s32)(100.0f*WRTC_random()));
    }
    *(u16*)(self+0x260)+=0x200;
    *(f32*)(self+0x14)=5.0f*sincosTable___5JMath[(((u32)*(u16*)(self+0x260)>>5)&0x7ff)*2]+*(f32*)(self+0x25c);
    *(u16*)(self+0x262)+=0xb0;
    *(f32*)(self+0xc)=100.0f*sincosTable___5JMath[(((u32)*(u16*)(self+0x262)>>5)&0x7ff)*2]+*(f32*)(self+0x23c);
    *(f32*)(self+0x10)=50.0f*sincosTable___5JMath[(((u32)*(u16*)(self+0x262)>>5)&0x7ff)*2+1]+*(f32*)(self+0x240)-50.0f;
    fn_801F3D94(this_,1);
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
    if (wrtcStartIdle(this_)) {
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
    if (wrtcStepFlash(this_) == 1) {
        fn_801F3D94(this_, 1);
        return;
    }
    if (*(s32*)(p + 0x234) > 0x12C) {
        *(u16*)(p + 0x2B0) += 4;
        if (*(u16*)(p + 0x2B0) > 0x400) {
            *(u16*)(p + 0x2B0) = 0x400;
        }
        *(f32*)(p + 0x2A8) += 0.01f;
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
    if (*(s32*)(p + 0x234) <= 0x12C && *(s32*)(p + 0x234) > 0xC8) {
        *(f32*)(p + 0x23C) = *(f32*)(p + 0x23C) + lbl_8049C5FC[*(s32*)(p + 0x264)][0];
        *(f32*)(p + 0x240) = *(f32*)(p + 0x240) + lbl_8049C5FC[*(s32*)(p + 0x264)][1];
    } else if (*(s32*)(p + 0x234) <= 0xC8 && *(s32*)(p + 0x234) > 0x64) {
        *(f32*)(p + 0x23C) = *(f32*)(p + 0x23C) - lbl_8049C5FC[*(s32*)(p + 0x264)][0];
        *(f32*)(p + 0x240) = *(f32*)(p + 0x240) - lbl_8049C5FC[*(s32*)(p + 0x264)][1];
        *(u16*)(p + 0x262) += 0xB0;
    } else {
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
#pragma opt_propagation off
extern "C" void fn_800FC984(void* this_) {
    u8* self=(u8*)this_;
    u8 bVar1=wrtcStartIdle(this_);
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
        u8 bVar2=wrtcStepFlash(this_);
        if (bVar2 == 1) {
            fn_801F3D94(this_, 1);
        } else {
            *(u16*)(self + 0x2b0) = 0x40;
            *(u16*)(self + 0x2ae) += *(u16*)(self + 0x2b0);
            *(f32*)(self + 0x2a8) = lbl_8053BFCC;
            void* iv = fn_801F1184(this_);
            *(f32*)((u8*)iv + 0x48) = lbl_8053BFAC;
            fn_801F0E34(this_, 0x4002f, 0);
            *(s32*)(self + 0x234) -= 1;
            if (*(s32*)(self + 0x234) <= 0) {
                if (((*(u32*)(self + 0x238) & 8) != 0) && self[0x2ac] <= 0xc) {
                    *(s32*)(self + 0x230) = 4;
                    *(s32*)(self + 0x234) = 0;
                    f32 one=lbl_8053BFCC;
                    f32 scale=lbl_8053C078;
                    f32 base=400.0f;
                    char* game=(char*)lbl_8053AAF8;
                    *(u32*)(game+0xb4)=*(u32*)(game+0xb4)*0x19660d+0x3c6ef35f;
                    union {u32 u; f32 f;} a;
                    a.u=(*(u32*)(game+0xb4)>>9)|0x3f800000;
                    s32 x=(s32)(scale*(a.f-one));
                    f32 fx=x;
                    *(s16*)(self+0x284)=(s32)(base+fx);
                    game=(char*)lbl_8053AAF8;
                    *(u32*)(game+0xb4)=*(u32*)(game+0xb4)*0x19660d+0x3c6ef35f;
                    union {u32 u; f32 f;} b;
                    b.u=(*(u32*)(game+0xb4)>>9)|0x3f800000;
                    s32 y=(s32)(scale*(b.f-one));
                    f32 fy=y;
                    *(s16*)(self+0x286)=(s32)(base+fy);
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
            *(f32*)(self + 0x14) = 5.0f * sincosTable___5JMath[((((u32)*(u16*)(self + 0x260) >> 5)&0x7ff)) * 2] + *(f32*)(self + 0x25c);
            *(u16*)(self + 0x262) += 0xb0;
            *(f32*)(self + 0xc) = 100.0f * sincosTable___5JMath[((((u32)*(u16*)(self + 0x262) >> 5)&0x7ff)) * 2] + *(f32*)(self + 0x23c);
            *(f32*)(self + 0x10) = 50.0f * sincosTable___5JMath[((((u32)*(u16*)(self + 0x262) >> 5)&0x7ff)) * 2 + 1] + *(f32*)(self + 0x240) - 50.0f;
            fn_801F3D94(this_, 1);
        }
    }
}
#pragma opt_propagation reset
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
            *(f32*)(mgr + 0x28c) = 0.05f;
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
            *(f32*)(mgr + 0x28c) = 0.05f;
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
        if (*(f32*)(p + 0x25c) >= 10.0f) {
            *(f32*)(p + 0x25c) = 10.0f;
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

#pragma opt_propagation off
extern "C" void fn_800FCF80(u8* this_) {
    f32 fVar2;
    f32 fVar1;
    f32 copy;
    f32 c;
    f32 d;
    f32 k2;
    f32 a;
    f32 b;
    copy = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x23c) = copy;
    copy = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x240) = copy;
    copy = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x244) = copy;
    copy = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x248) = copy;
    copy = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x24c) = copy;
    copy = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x250) = copy;
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
    *(f32*)(this_ + 0x270) = lbl_8053BFCC;
    *(f32*)(this_ + 0x274) = lbl_8053BFAC;
    *(f32*)(this_ + 0x26c) = lbl_8053BFCC;
    *(s16*)(this_ + 0x260) = 0;
    *(f32*)(this_ + 0x25c) = lbl_8053BFAC;
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
    c = lbl_8053C054;
    k2 = *(f32*)(this_ + 0x26c);
    a = c * k2;
    b = lbl_8053C058 * k2;
    c = lbl_8053C05C * k2;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = b;
    *(f32*)(this_ + 0x68) = c;
    *(f32*)(this_ + 0x6c) = lbl_8053BFAC;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = b;
    *(f32*)(this_ + 0x88) = c;
    *(f32*)(this_ + 0x8c) = lbl_8053BFAC;
    *(s32*)(this_ + 0x27c) = 0;
    fn_801F0E34(this_, 0x40026, 0);
    *(s32*)(this_ + 0x280) = 9;
    fn_800FA6B0(this_);
    fn_80458F9C(lbl_8053AF80, 0x3c);
    s32 off;
    s32 n;
    n = 0;
    off = 0;
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
#pragma opt_propagation reset
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

extern "C" s32 fn_801F8544(void*, u32, u32, f32*, u32);
extern "C" void v07__5ActorFv(void*);
extern const f32 lbl_8053BFEC;
#pragma opt_propagation off
extern "C" void fn_800F87E4(void* this_) {
    u8* self = (u8*)this_;
    s32 id;
    if (self[0x247] == 0x14) id = 4;
    else {
        f32 one;
        f32 random;
        f32 scale;
        u32* rng = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
        one = lbl_8053BFCC;
        scale = lbl_8053BFEC;
        *rng = *rng * 0x19660d + 0x3c6ef35f;
        union { u32 u; f32 f; } value;
        value.u = (*rng >> 9) | 0x3f800000;
        random = value.f;
        one = random - one;
        id = (u32)(scale * one) + 1;
    }
    id = fn_801F8544(fn_801F856C(), 0x52555059, *(u32*)(self + 4), (f32*)(self + 0xc), id);
    union { u32 u; f32 f; } last;
    if (id >= 0) {
        u8* actor = (u8*)fn_801F666C(fn_801F856C(), id);
        f32 z;
        f32 base;
        f32 amplitude;
        f32 one;
        union { u32 u; f32 f; } rz, ry, rx;
        JGeometry::TVec3<f32> vel;
        u32* rngZ;
        u32* rngY;
        u32* rngX;
        one = lbl_8053BFCC;
        amplitude = lbl_8053BFA4;
        base = lbl_8053BFF0;
        z = lbl_8053BFA0;
        rngZ = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
        *rngZ = *rngZ * 0x19660d + 0x3c6ef35f;
        rz.u = (*rngZ >> 9) | 0x3f800000;
        rngY = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
        *rngY = *rngY * 0x19660d + 0x3c6ef35f;
        ry.u = (*rngY >> 9) | 0x3f800000;
        rngX = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
        *rngX = *rngX * 0x19660d + 0x3c6ef35f;
        rx.u = (*rngX >> 9) | 0x3f800000;
        vel.set(base - amplitude * (rx.f - one),
                base - amplitude * (ry.f - one),
                z + z * (rz.f - one));
        *(JGeometry::TVec3<f32>*)(actor + 0x3c) = vel;
    }
    f32 one;
    f32 random;
    f32 scale;
    u32* rng = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    one = lbl_8053BFCC;
    scale = lbl_8053BFF4;
    *rng = *rng * 0x19660d + 0x3c6ef35f;
    last.u = (*rng >> 9) | 0x3f800000;
    random = last.f;
    one = random - one;
    if ((s32)(scale * one) == 3)
        Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(self + 4), (f32*)(self + 0xc), 0, -1, -1);
    *(s32*)(self + 0x18c) = 0;
    v07__5ActorFv(self);
}
#pragma opt_propagation reset

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/Inline.h"

