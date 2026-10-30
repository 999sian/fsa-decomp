#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Matrix.h"
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

static inline JGeometry::TVec3<f32> SHBL_neg(const JGeometry::TVec3<f32>& v) {
    JGeometry::TVec3<f32> r;
    r.negate(v);
    return r;
}

extern "C" void* fn_801F856C();
extern "C" s32 fn_801F8544(void* mgr, u32 tag, s32 room, void* pos, s32 n);
extern "C" void* fn_801F666C(void* mgr, s32 id);

static inline void SHBL_spawn(u8* this_, u32 tag, const s32& n) {
    s32 id = fn_801F8544(fn_801F856C(), tag, *(s32*)(this_ + 4), this_ + 0xc, n);
    if (id >= 0) {
        fn_801F666C(fn_801F856C(), id);
    }
}

static inline void SHBL_neg2(JGeometry::TVec3<f32>& out, const JGeometry::TVec3<f32>& v) {
    JGeometry::TVec3<f32> r;
    r.negate(v);
    out = r;
}
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049D020[];
extern void* lbl_8049CC34[];
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void* p, void* sym, s32 n);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p, f32 f);
extern "C" s32 fn_8010C294(u8* this_, s32 mode);
extern f32 lbl_8053C4A4;
extern f32 lbl_8053C4A0;

static inline void SHBL_setBox(u8* this_, f32 h, f32 w) {
    *(f32*)(this_ + 0x60) = w;
    *(f32*)(this_ + 0x64) = w;
    *(f32*)(this_ + 0x68) = h;
    *(f32*)(this_ + 0x6c) = h;
}
extern f32 lbl_8053C4BC;
extern f32 lbl_8053C4F0;
extern f32 lbl_8053C4F4;
extern f32 lbl_8053C490;
extern f32 lbl_8053C4D4;
extern void* lbl_80539EE8[2];
extern "C" void v06__5ActorFv(void* this_);
class SHBLResourceMgr {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void* get(u32 type, const void* name);
};
extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);
extern "C" void fn_802F86CC(void* a, void* b, void* c, u32 d, void* e, f32 f, f32 g);
extern f32 lbl_8053C4E0;
extern f32 lbl_8053C4D8;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern void* lbl_8053AAF8;
extern void* lbl_80464334[];
extern f32 lbl_8053C494;
extern f32 lbl_8053C4A8;
extern f32 lbl_8053C4DC;
extern s32 lbl_80464328[];
extern "C" void fn_801EEC98(void* this_, void* p, u16* a, s32* b, f32* c, s32* d, s32 e, s32 f);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D79E8(void*, s32, s32, f32, f32);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void fn_801F0D20(void* this_, s32 a);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void*, u32, s32, void*, s32, s32, s32);
extern "C" s32 fn_801F8544(void* mgr, u32 tag, s32 room, void* pos, s32 n);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void detach__5ActorFv(void* this_);
extern "C" s32 fn_8010C294(u8* this_, s32 mode) {
    switch (mode) {
    case 1:
        *(s32*)(this_ + 0x24c) = 0;
        *(s32*)(this_ + 0x254) = 5;
        break;
    case 2: {
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x24c) = 0;
        u16 a;
        f32 d;
        s32 c;
        s32 b;
        a = 0;
        b = 0;
        c = 0;
        d = 0.0f;
        fn_801EEC98(this_, *(void**)(this_ + 0x198), &a, &b, &d, &c, *(s32*)(this_ + 0x23c), 2);
        *(u16*)(this_ + 0x230) = a;
        break;
    }
    case 3:
        *(u8*)(this_ + 0x2ae) = 0;
        *(u8*)(this_ + 0x2af) = 0;
        *(u8*)(this_ + 0x2ad) = 0;
        break;
    case 4:
        *(f32*)(this_ + 0x264) = 1.5f;
        if (*(s32*)(this_ + 0x258) > 0 && *(s32*)(this_ + 0x25c) > 0) {
            u8 n = *(s32*)(this_ + 0x25c);
            if (n < *(u8*)(this_ + 0x2ae)) {
                *(u8*)(this_ + 0x2af) = n;
            }
        }
        break;
    case 5: {
        JGeometry::TVec3<f32> w;
        SHBL_neg2(w, *(JGeometry::TVec3<f32>*)(this_ + 0x3c));
        *(JGeometry::TVec3<f32>*)(this_ + 0x3c) = w;
        *(f32*)(this_ + 0x44) = 1.0f;
        fn_802D79E8(fn_802D6A9C(), *(s32*)(this_ + 4), 0, 4.0f, 0.0f);
        u8* e = *(u8**)(this_ + 0x374);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
        }
        break;
    }
    case 6:
        *(f32*)(this_ + 0x264) = 0.0f;
        *(s32*)(this_ + 0x244) = 0;
        break;
    case 7:
        *(s32*)(this_ + 0x248) = 0;
        break;
    case 8:
        *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0xc8);
        *(f32*)(this_ + 0x264) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 10:
        *(f32*)(this_ + 0x3c) *= -0.1f;
        *(f32*)(this_ + 0x40) *= -0.1f;
        *(f32*)(this_ + 0x44) = 0.0f;
        *(s32*)(this_ + 0xd8) = 0;
        fn_801D22DC(this_ + 0x274, 1, 0, 0);
        if (*(s32*)(this_ + 4) == 0) {
            *(void**)(this_ + 0x378) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x93, 0, -1, 0, 0, 1, *(f32*)(this_ + 0x260));
            *(void**)(this_ + 0x37c) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x94, 1, 0, 0, 0, 1, *(f32*)(this_ + 0x260));
        }
        break;
    case 12: {
        if (*(void* volatile*)(this_ + 0x100) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void* volatile*)(this_ + 0x100));
            *(void**)(this_ + 0x100) = 0;
        }
        if (*(void* volatile*)(this_ + 0x104) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void* volatile*)(this_ + 0x104));
            *(void**)(this_ + 0x104) = 0;
        }
        u8* e = *(u8**)(this_ + 0x374);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
        }
        JGeometry::TVec3<f32> p(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
        p.y -= 16.0f * *(f32*)(this_ + 0x260);
        fn_8013CC50(*(s32*)(this_ + 4), &p, 0x44a, 0, 1, 0, 0, 1, *(f32*)(this_ + 0x260));
        fn_8013CC50(*(s32*)(this_ + 4), &p, 0x44b, 0, 1, 0, 0, 1, *(f32*)(this_ + 0x260));
        fn_8013CC50(*(s32*)(this_ + 4), &p, 0x44c, 0, 1, 0, 0, 1, *(f32*)(this_ + 0x260));
        fn_801F0E34(this_, 0x50077, 0);
        *(f32*)(this_ + 0x270) = *(f32*)(this_ + 0x260);
        break;
    }
    case 13:
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x14) = 0.0f;
        switch (*(s32*)(this_ + 0x234)) {
        case 1:
            fn_801F0D20(this_, 3);
            Actor_CreateByID(fn_801F856C(), 0x4b455930, *(s32*)(this_ + 4), this_ + 0xc, 0x60000000, -1, -1);
            break;
        case 0:
        default: {
            s32 idx = 0;
            if (*(f32*)(this_ + 0x270) >= 2.0f) {
                idx = 2;
            } else if (*(f32*)(this_ + 0x270) >= 1.4f) {
                idx = 1;
            }
            if (*(s32*)(this_ + 0x258) >= 1) {
                idx = 1;
            }
            for (s32 i = 0; i < 1; i++) {
                s32 id = fn_801F8544(fn_801F856C(), 0x52555059, *(s32*)(this_ + 4), this_ + 0xc, lbl_80464328[idx]);
                if (id >= 0) {
                    fn_801F666C(fn_801F856C(), id);
                }
            }
            break;
        }
        }
        detach__5ActorFv(this_);
        break;
    }
    *(s32*)(this_ + 0x238) = mode;
    fn_801D1F14(this_ + 0x274, 0.0f);
    return 1;
}

#pragma opt_propagation off
extern "C" void fn_8010C6E4(u8* this_) {
    v06__5ActorFv(this_);
    DrawRec rec;
    DrawRec shadow;
    JGeometry::TMtx34f matrix;
    JGeometry::TMtx34f shadowMatrix;
    f32 sx;
    f32 zero;
    if (!(((JGeometry::TVec3f*)(this_+0x54))->squared() <= JGeometry::TUtilf::epsilon())) {
        zero=lbl_8053C490;
        matrix.mMtx[0][3]=zero; matrix.mMtx[1][3]=zero; matrix.mMtx[2][3]=zero;
        f32 sy=*(f32*)(this_+0x58);
        sx=*(f32*)(this_+0x54);
        f32 sz=*(f32*)(this_+0x5c);
        matrix.mMtx[0][0]=sx; matrix.mMtx[0][1]=zero; matrix.mMtx[0][2]=zero;
        matrix.mMtx[1][0]=zero; matrix.mMtx[1][1]=sy; matrix.mMtx[1][2]=zero;
        matrix.mMtx[2][0]=zero; matrix.mMtx[2][1]=zero; matrix.mMtx[2][2]=sz;
        rec.w18=&matrix;
        f32 ty=lbl_8053C4D8* *(f32*)(this_+0x260);
        shadowMatrix.mMtx[0][3]=zero; shadowMatrix.mMtx[2][3]=zero; shadowMatrix.mMtx[1][3]=ty;
        shadowMatrix.mMtx[0][0]=sx; shadowMatrix.mMtx[0][1]=zero; shadowMatrix.mMtx[0][2]=zero;
        shadowMatrix.mMtx[1][0]=zero; shadowMatrix.mMtx[1][1]=sy; shadowMatrix.mMtx[1][2]=zero;
        shadowMatrix.mMtx[2][0]=zero; shadowMatrix.mMtx[2][1]=zero; shadowMatrix.mMtx[2][2]=sz;
        shadow.w18=&shadowMatrix;
    }
    ((u8*)&shadow.w10)[3]=0x80;
    fn_801EF830(*(s32*)(this_+4),(f32*)(this_+0xc),(u8*)&shadow,0x407,(u8*)lbl_80464334,*(s32*)(this_+0x284)+0x165,0);
    void* pos=this_+0xc;
    s32 frame=*(s32*)(this_+0x284)+0x165;
    if (*(s32*)(this_+4)<8) {
        SHBLResourceMgr* mgr=*(SHBLResourceMgr**)((u8*)lbl_8053AAF8+0xa4);
        void* res=mgr->get('SOB ',lbl_80464334);
        fn_802F86CC(*(void**)((u8*)lbl_8053AB10+0x20),pos,res,frame,&rec,lbl_8053C4D4,lbl_8053C4D4);
    }
}
#pragma opt_propagation reset
extern f32 lbl_8053C4C4;
extern f32 lbl_8053C4E4;
extern "C" void v03__5ActorFv(void* this_);
extern "C" s32 fn_8023AB94(f32* box, s32 room, u8* out);
extern "C" void fn_801F2DB4(void* this_, u32 a, s32 b, u32 c);
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Box.h"
#define I(p,o) (*(s32*)((u8*)(p)+(o)))
#define U(p,o) (*(u32*)((u8*)(p)+(o)))
#define S(p,o) (*(s16*)((u8*)(p)+(o)))
#define B(p,o) (*(u8*)((u8*)(p)+(o)))
#define F(p,o) (*(f32*)((u8*)(p)+(o)))
#define P(p,o) (*(u8**)((u8*)(p)+(o)))
#define V(p,o) (*(JGeometry::TVec3<f32>*)((u8*)(p)+(o)))
extern f32 lbl_8053C498,lbl_8053C49C,lbl_8053C4AC,lbl_8053C4B0,lbl_8053C4B4,lbl_8053C4B8;
extern f32 lbl_8053C4C0,lbl_8053C4C8,lbl_8053C4CC,lbl_8053C4D0,lbl_8053C4E8,lbl_8053C4EC;
extern "C" s32 fn_801CD930(s16*,s16,s16);
extern "C" s32 fn_801CD950(f32*,f32,f32);
extern "C" void fn_8013CB44(void*,void*,s32,s32,s32);
extern "C" u8 fn_801F2B7C(void*,s32,s32,s32);
extern "C" u8 fn_801F2618(void*,void*,s32);
extern "C" u8 fn_801F2B20(void*,s32);
extern "C" void fn_80239914(void*,s32,s32);
extern "C" void fn_800FE3EC(void*,s32,JGeometry::TVec3<f32>*,s32);
extern "C" void fn_800FDEA0(void*,void*,void*,s32*,s16*,s32,f32);
extern "C" JGeometry::TVec3<f32>* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_801D21F0(void*);
extern "C" void fn_801D1C18(void*);
#pragma auto_inline off
static inline void SHBL_updateTrail(u8* p) {
    if(I(p,4)==0) {
        if(P(p,0x374)==0)
            P(p,0x374)=(u8*)fn_8013CC50(I(p,4),p+0xc,0x3d3,0,0,0,0,1,lbl_8053C494);
        JGeometry::TVec3<f32> pos(V(p,0xc));
        pos.y=lbl_8053C498*F(p,0x260)+F(p,0x10);
        fn_8013CB44(P(p,0x374),&pos,0,0,1);
        B(P(p,0x374),0xbb)=0x80;
        if(F(p,0x264)<lbl_8053C49C) U(P(p,0x374),0xf4)|=1;
        else U(P(p,0x374),0xf4)&=~1;
    }
}
static inline bool SHBL_ground(u8* p) {
    if(F(p,0x14)<=lbl_8053C490) {
        F(p,0x14)=lbl_8053C490;
        F(p,0x44)=lbl_8053C490;
        return true;
    }
    return false;
}

extern "C" void fn_8010CA44(u8* this_) {
    f32 box[4];
    u8 buf[0x74];
    v03__5ActorFv(this_);
    *(f32*)(this_ + 0x26c) = lbl_8053C4D4;
    box[0] = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
    box[1] = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
    box[2] = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
    box[3] = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
    s32 st = *(s32*)(this_ + 0x238);
    if (st != 0xc && st != 0xd) {
        if (fn_8023AB94(box, *(s32*)(this_ + 4), buf) >= 0) {
            fn_8010C294(this_, 0xc);
        }
    }
    switch (*(u32*)(this_ + 0x238)) {
    case 0: {
        fn_801F2DB4(this_, 0x4e554c4c, 0, 0x4e554c4c);
        *(f32*)(this_ + 0x26c) = lbl_8053C490;
        u16 a;
        f32 c;
        s32 b;
        s32 d;
        fn_801EEC98(this_, *(void**)(this_ + 0x198), &a, &b, &c, &d, 0, 0);
        if (d >= 0 && c < lbl_8053C4C4) {
            *(s32*)(this_ + 0x23c) = d;
            fn_8010C294(this_, 1);
        }
        break;
    }
    case 1:
        *(f32*)(this_ + 0x26c) = lbl_8053C4E4;
        *(s32*)(this_ + 0x24c) += 1;
        if (*(s32*)(this_ + 0x24c) >= 0x32) {
            fn_8010C294(this_, 2);
        }
        break;
    default:
        break;
    }
}

extern "C" void fn_8010D55C(u8* this_) {
    f32 t;
    v01__5ActorFv(this_);
    *(s32*)(this_ + 0x234) = *(s32*)(this_ + 0x90) & 0xf;
    switch ((*(s32*)(this_ + 0x90) >> 4) & 0xf) {
    case 1:
        *(f32*)(this_ + 0x260) = lbl_8053C4A4;
        t = *(f32*)(this_ + 0x260);
        *(f32*)(this_ + 0x54) = t;
        *(f32*)(this_ + 0x58) = t;
        *(f32*)(this_ + 0x5c) = t;
        break;
    }
    *(s32*)(this_ + 0x258) = (*(s32*)(this_ + 0x90) >> 8) & 0xff;
    *(s32*)(this_ + 0x25c) = (*(s32*)(this_ + 0x90) >> 16) & 0xff;
    if (*(s32*)(this_ + 0x258) > 0 && lbl_8053C4A4 == *(f32*)(this_ + 0x260)) {
        SHBL_setBox(this_, lbl_8053C4A0, lbl_8053C4F0);
    } else {
        SHBL_setBox(this_, lbl_8053C4BC, lbl_8053C4F4);
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x84) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x88) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x8c) = *(f32*)(this_ + 0x6c);
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0xb8) = 1;
    *(s32*)(this_ + 0xf8) = 2;
    *(s32*)(this_ + 0xbc) = 3;
    *(s32*)(this_ + 0x1a4) = 1;
    *(s32*)(this_ + 0x118) = 2;
    *(s32*)(this_ + 0x114) = 2;
    *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x98);
    *(s32*)(this_ + 0xb0) = 0xa040304;
    fn_801D2608(this_ + 0x274, lbl_80539EE8, 2);
    fn_801D22DC(this_ + 0x274, 0, 2, 0);
    fn_801D1F14(this_ + 0x274, lbl_8053C490);
    if (*(s32*)(this_ + 0x258) > 0) {
        fn_8010C294(this_, 3);
    }
}

extern "C" void* fn_8010D6F0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049D020;
        fn_801EE434(*(void**)(p + 0x374));
        *(s32*)(p + 0x374) = 0;
        fn_801EE434(*(void**)(p + 0x378));
        *(s32*)(p + 0x378) = 0;
        fn_801EE434(*(void**)(p + 0x37c));
        *(s32*)(p + 0x37c) = 0;
        if (p + 0x274 != 0) {
            if (p + 0x298 != 0) {
                *(void**)(p + 0x298) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern f32 lbl_8053C4D4;
extern f32 lbl_8053C490;
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* p);
extern "C" u8* fn_8010D7A0(u8* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_8049D020;
    f32 b;
    f32 a = lbl_8053C4D4;
    *(u16*)(this_ + 0x230) = 0;
    b = lbl_8053C490;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = -1;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x260) = a;
    *(f32*)(this_ + 0x264) = b;
    *(f32*)(this_ + 0x268) = b;
    *(f32*)(this_ + 0x26c) = a;
    *(f32*)(this_ + 0x270) = a;
    fn_801D267C(this_ + 0x274);
    *(s32*)(this_ + 0x374) = 0;
    *(s32*)(this_ + 0x378) = 0;
    *(s32*)(this_ + 0x37c) = 0;
    return this_;
}

