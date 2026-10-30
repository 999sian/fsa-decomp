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
        if(F(p,0x264)<0.2f) U(P(p,0x374),0xf4)|=1;
        else U(P(p,0x374),0xf4)&=~1;
    }
}
static inline f32 SHBL_getSize(u8* p) { return F(p,0x260); }
static inline f32 SHBL_cosAt(const f32* table, s16 angle) {
    return table[((u16)angle>>5)*2];
}
static inline bool SHBL_ground(u8* p) {
    if(F(p,0x14)<=0.0f) {
        F(p,0x14)=0.0f;
        F(p,0x44)=0.0f;
        return true;
    }
    return false;
}

#pragma opt_common_subs off
extern "C" void fn_8010CA44(u8* p) {
    JGeometry::TBox2<f32> box;
    JGeometry::TVec2<f32> hit;
    JGeometry::TVec3<f32> probe2;
    JGeometry::TVec3<f32> probe7;
    JGeometry::TVec3<f32> probe9;
    v03__5ActorFv(p);
    F(p,0x26c)=1.0f;
    box.set(*(JGeometry::TBox2<f32>*)(p+0x60));
    box.addPos(*(JGeometry::TVec2<f32>*)(p+0xc));
    if(I(p,0x238)!=12 && I(p,0x238)!=13) {
        if(fn_8023AB94((f32*)&box,I(p,4),(u8*)&hit)>=0) fn_8010C294(p,12);
    }
    switch(U(p,0x238)) {
    case 0: {
        fn_801F2DB4(p,0x4e554c4c,0x4e554c4c,0);
        F(p,0x26c)=0.0f;
        u16 angle;
        s32 b;
        s32 player;
        f32 distance;
        fn_801EEC98(p,P(p,0x198),&angle,&b,&distance,&player,0,0);
        if(player>=0 && distance<lbl_8053C4C4) {I(p,0x23c)=player;fn_8010C294(p,1);}
        break;
    }
    case 1:
        F(p,0x26c)=lbl_8053C4E4;
        I(p,0x24c)++;
        if(I(p,0x24c)>=50) fn_8010C294(p,2);
        break;
    case 2: {
        s32 target=I(p,0x23c);
        if(target>=0) {
            u16 angle;
            f32 distance;
            s32 player;
            s32 b;
            angle=0;b=0;player=0;distance=0.0f;
            fn_801EEC98(p,P(p,0x198),&angle,&b,&distance,&player,target,2);
            const f32* cosine=&JMath::sincosTable_.mTable[0].second;
            s16 diff=S(p,0x230)-angle;
            s16 step;
            if(cosine[((u16)diff>>5)*2]>=0.0f)
                step=100+(s32)JGeometry::TUtilf::abs(lbl_8053C4C0*JMath::sincosTable_.sinShort(diff));
            else step=700;
            fn_801CD930(&S(p,0x230),(s16)angle,step);
            if(distance>=lbl_8053C4C4) fn_801CD950(&F(p,0x264),lbl_8053C4B8,lbl_8053C4C8);
            else fn_801CD950(&F(p,0x264),lbl_8053C4CC,lbl_8053C4D0);
            f32 speed=F(p,0x264);
            f32 sine=JMath::sincosTable_.sinShort(S(p,0x230));
            sine=speed*sine;
            F(p,0x3c)=sine;
            f32 cosSpeed=F(p,0x264);
            f32 cosineValue=SHBL_cosAt(cosine,S(p,0x230));
            cosineValue=cosSpeed*cosineValue;
            F(p,0x40)=cosineValue;
            F(p,0x44)=0.0f;
            V(p,0xc)+=V(p,0x3c);
            F(p,0x26c)=V(p,0x3c).length()/lbl_8053C4B8;
            if(F(p,0x26c)>=1.0f) F(p,0x26c)=1.0f;
            SHBL_updateTrail(p);
            fn_801F0E34(p,0x3007b,0);
        }
        F(p,0x260)+=(lbl_8053C4B4*F(p,0x264))/lbl_8053C4B8;
        if(F(p,0x260)>=2.0f) F(p,0x260)=2.0f;
        f32 half=8.0f*F(p,0x260);
        f32 minimum=-half;
        F(p,0x60)=minimum;F(p,0x64)=minimum;F(p,0x68)=half;F(p,0x6c)=half;
        F(p,0x70)=F(p,0x60);F(p,0x74)=F(p,0x64);F(p,0x78)=F(p,0x68);F(p,0x7c)=F(p,0x6c);
        F(p,0x80)=F(p,0x60);F(p,0x84)=F(p,0x64);F(p,0x88)=F(p,0x68);F(p,0x8c)=F(p,0x6c);
        fn_801F2DB4(p,0x4e554c4c,0x4e554c4c,0);
        if(fn_801F2B7C(p,-100,-1,1)) fn_8010C294(p,7);
        {
            if(fn_801F2618(p,&probe2,0)) fn_8010C294(p,5);
        }
        break;
    }
    case 3: {
        JGeometry::TVec3<f32> pos(V(p,0xc));
        fn_800FE3EC(p+0x2ac,I(p,0x258),&pos,I(p,4));
        fn_8010C294(p,4);
        break;
    }
    case 4:
        if(I(p,0x258)>0) {
            JGeometry::TVec3<f32> pos;
            JGeometry::TVec3<f32> velocity;
            s32 room;
            s16 angle;
            angle=0;
            velocity.set(0.0f,0.0f,0.0f);
            room=I(p,4);
            pos=V(p,0xc);
            fn_800FDEA0(p+0x2ac,&pos,&velocity,&room,&angle,0x200,lbl_8053C494);
            F(p,0x3c)=velocity.x;F(p,0x40)=velocity.y;F(p,0x44)=velocity.z;
            V(p,0xc)+=V(p,0x3c);
            SHBL_updateTrail(p);
            fn_801F0E34(p,0x3007b,0);
        }
        fn_801F2DB4(p,0x4e554c4c,0x4e554c4c,0);
        fn_801F2B7C(p,-100,-1,1);
        break;
    case 5:
        fn_801CD950(&F(p,0x44),lbl_8053C4AC,lbl_8053C4B0);
        V(p,0xc)+=V(p,0x3c);
        if(SHBL_ground(p)) fn_8010C294(p,6);
        break;
    case 6:
        F(p,0x26c)=0.0f;
        fn_801F2DB4(p,0x4e554c4c,0x4e554c4c,0);
        fn_80239914(&box,I(p,4),I(p,0x198));
        I(p,0x244)++;
        if(I(p,0x244)>=180) fn_8010C294(p,0);
        break;
    case 7: {
        I(p,0x248)++;
        if(I(p,0x248)>60) {fn_801F2B7C(p,-100,-1,1);I(p,0x248)=60;}
        if(fn_801F2618(p,&probe7,0)) {fn_8010C294(p,5);break;}
        if(fn_801CD950(&F(p,0x264),lbl_8053C4E8,lbl_8053C4EC)==0) fn_8010C294(p,2);
        f32 speed=F(p,0x264);
        f32 sine=JMath::sincosTable_.sinShort(S(p,0x230));
        sine=speed*sine;
        F(p,0x3c)=sine;
        f32 cosSpeed=F(p,0x264);
        f32 cosineValue=JMath::sincosTable_.cosShort(S(p,0x230));
        cosineValue=cosSpeed*cosineValue;
        F(p,0x40)=cosineValue;
        F(p,0x44)=0.0f;
        V(p,0xc)+=V(p,0x3c);
        {

    if(I(p,4)==0) {
        if(P(p,0x374)==0)
            P(p,0x374)=(u8*)fn_8013CC50(I(p,4),p+0xc,0x3d3,0,0,0,0,1,lbl_8053C494);
        JGeometry::TVec3<f32> pos(V(p,0xc));
        pos.y=lbl_8053C498*F(p,0x260)+F(p,0x10);
        fn_8013CB44(P(p,0x374),&pos,0,0,1);
        B(P(p,0x374),0xbb)=0x80;
        if(F(p,0x264)<0.2f) U(P(p,0x374),0xf4)|=1;
        else U(P(p,0x374),0xf4)&=~1;
    }

        }
        break;
    }
    case 8:
        F(p,0x26c)=0.0f;
        if(B(p,0xc4)) {
            JGeometry::TVec3<f32>* pos=fn_8023E7B0(I(p,0xc8));
            F(p,0xc)=pos->x;F(p,0x10)=pos->y;F(p,0x14)=pos->z;
            I(p,4)=fn_8023DE58(I(p,0xc8));
        } else fn_8010C294(p,9);
        break;
    case 9: {
        if(fn_801F2B7C(p,I(p,0x114),I(p,0x23c),1) || fn_801F2B20(p,0) || fn_801F2618(p,&probe9,0)) {
            fn_8010C294(p,10);break;
        }
        fn_801CD950(&F(p,0x44),lbl_8053C4AC,lbl_8053C4B0);
        V(p,0xc)+=V(p,0x3c);
        if(SHBL_ground(p)) fn_8010C294(p,10);
        break;
    }
    case 10:
        fn_80239914(&box,I(p,4),I(p,0x198));
        if(fn_801D21F0(p+0x274)) {
            fn_801CD950(&F(p,0x44),lbl_8053C4AC,lbl_8053C4B0);
            V(p,0xc)+=V(p,0x3c);
            if(SHBL_ground(p)) fn_8010C294(p,11);
        }
        break;
    case 11:
        fn_80239914(&box,I(p,4),I(p,0x198));
        break;
    case 12:
        B(p,0x11d)=0;
        fn_80239914(&box,I(p,4),I(p,0x198));
        I(p,0x250)++;
        if(I(p,0x250)>=90) fn_8010C294(p,13);
        break;
    case 13:break;
    }
    f32 scale=F(p,0x260);
    F(p,0x54)=scale;F(p,0x58)=scale;F(p,0x5c)=scale;
    F(p,0x2a4)=F(p,0x26c);
    fn_801D1C18(p+0x274);
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

