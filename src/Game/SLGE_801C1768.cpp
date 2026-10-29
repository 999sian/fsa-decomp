#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

extern "C" char lbl_804A4310[];
extern "C" char lbl_804A4808[];
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void* p);
extern "C" void fn_8021FAB8(u8* p, s32 n);
extern "C" void __dt__5ActorFv(u8* this_, s32 flags);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_802F745C(void* a, void* b, void* c, void* d);
extern "C" u32 lbl_8053AB10;

extern "C" s32 fn_801CD664(s32 n);
extern "C" u32 fn_801C5660(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_801C26D8(void);
extern "C" u16 lbl_80469424[];
extern "C" u16 lbl_8053EDB8;
extern "C" f32 lbl_8053EDD0;
extern "C" void* fn_801C0D70(void);
extern "C" void* fn_804032E8(u32 name, void* str);
extern "C" u16 lbl_8053EDB0[3];
extern "C" u16 lbl_80469418[];
extern "C" char lbl_80469430[];
extern "C" char* lbl_8053AC20;
extern "C" char lbl_8053AC24;
extern "C" void fn_8021C2B4(void* p);
extern "C" u8 fn_8021F4B0(void* p);
extern "C" f32 lbl_8053EDC4;
extern "C" f32 lbl_8053EDC8;
extern "C" f32 lbl_8053EDCC;
extern "C" f32 lbl_8053EDD4;
extern "C" f64 lbl_8053EDD8;
extern "C" f64 lbl_8053EDE0;
extern "C" void fn_8021F914(void* p, s32 n);
extern "C" void fn_8021F924(void* p);
extern "C" void fn_8021F9AC(void* p, f32* v);
extern "C" void* fn_8013C824(void);
extern "C" s32 fn_801F7884(void* mgr, u32 name, u32 room);
extern "C" void fn_8010F9F0(void);
extern "C" void fn_8022ADCC(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" f32 lbl_8053EDC0;
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" void fn_801C1768(u8* this_) {
    s32 i;
    for (i = 0; i < 5; i++) {
        ((void**)this_)[0xb0 + i] = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_80469424[i], 0, 0, 0, 0, 1, lbl_8053EDC0);
    }
    for (i = 0; i < 4; i++) {
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, (&lbl_8053EDB8)[i], 0, 0, 0, 0, 1, lbl_8053EDC0);
    }
    fn_801EE434(*(void**)(this_ + 0x2b0));
    *(void**)(this_ + 0x2b0) = 0;
    fn_801F0E34(this_, 0x50049, 0);
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = 4;
}

#pragma scheduling on
extern "C" void fn_801C186C(const u8* p) {
s32 diff;
u32 mgr;
u32 lo;
s32 i;
diff=p[0x2a9];
lo=p[0x2a8];
diff-=lo;
for(i=0;i<4;i++) {
 s32 n=fn_801CD664(diff+1);
 n=(s32)(lo+n);
 mgr=fn_801C5660(8,0,n,0,0);
 s32 id=Actor_CreateByID(fn_801F856C(),0x534c4b32,*(u32*)(p+4),(f32*)(p+0xc),mgr,-1,-1);
 if(id>=0 && fn_801F666C(fn_801F856C(),id)) fn_801C26D8();
}
}
#pragma scheduling reset
extern "C" void fn_801C1918(u8* this_) {
    if (*(s32*)(this_ + 0x248) != 0xb) {
        DrawRec rec;
        *(s8*)&rec.b1d = -2;
        void* res = *(void**)(this_ + 0x2d4);
        if (*(s32*)(this_ + 4) < 8) {
            fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, &rec);
        }
    }
}

extern "C" void fn_801C1A58(u8* this_) {
    int i;
    int lo;
    int hi;
    fn_8021C2B4(this_ + 0x2d8);
    *(s32*)(this_ + 0x24c) += 1;
    if (*(s32*)(this_ + 0x24c) < 0) {
        *(s32*)(this_ + 0x24c) = 0;
    }
    switch (*(u32*)(this_ + 0x248)) {
    case 0:
        if (*(u16*)fn_801C0D70() & 0x40) {
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 1;
        }
        break;
    case 1:
        if (*(s32*)(this_ + 0x24c) >= 0xb4) {
            *(u16*)(this_ + 0x2aa) = 0xb4 + fn_801CD664(0x3d);
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 2;
        }
        break;
    case 2:
        if (*(u16*)(this_ + 0x2aa) != 0) {
            *(u16*)(this_ + 0x2aa) -= 1;
            if (*(u16*)(this_ + 0x2aa) == 0) {
                for (i = 0; i < 4; i++) {
                    lo = *(u8*)(this_ + 0x2a8);
                    hi = *(u8*)(this_ + 0x2a9);
                    s32 n = fn_801CD664(hi-lo+1);
                    n += lo;
                    u32 r = fn_801C5660(8,0,n,0,0);
                    s32 id = Actor_CreateByID(fn_801F856C(), 0x534c4b32, *(u32*)(this_ + 4), (f32*)(this_ + 0xc), r, -1, -1);
                    if (id >= 0) {
                        if (fn_801F666C(fn_801F856C(), id) != 0) {
                            fn_801C26D8();
                        }
                    }
                }
            }
            break;
        }
        if (!(*(u16*)fn_801C0D70() & 0x40)) {
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 3;
        }
        break;
    case 3:
        if (*(s32*)(this_ + 0x24c) >= 0x3c) {
            for (i = 0; i < 3; i++) {
                if (*(void**)(this_ + 0x2b4 + i * 4)) {
                    void* mgr = *(void**)((u8*)fn_8013C824()+0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(this_ + 0x2b4 + i * 4));
                }
                *(void**)(this_ + 0x2b4 + i * 4) = 0;
            }
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 5;
        } else {
            f32 t = lbl_8053EDC4 * (f32)(0x3c - *(s32*)(this_ + 0x24c));
            if (*(u8**)(this_ + 0x2b8)) {
                u8* em=*(u8**)(this_+0x2b8);
                *(f32*)(em+0xb0)=t;
                *(f32*)(em+0xb4)=lbl_8053EDC0;
            }
            if (*(u8**)(this_ + 0x2bc)) {
                *(u8*)(*(u8**)(this_ + 0x2bc) + 0xbb) = (u8)(s32)(lbl_8053EDC8 * t);
            }
        }
        break;
    case 5:
        if (*(s32*)(this_+0x24c)==0xb4) fn_801F0E34(this_,0x5004b,0);
        if (*(u16*)fn_801C0D70() & 0x80) {
            ((Actor*)this_)->v10(0xff,1);
            for(i=0;i<3;i++) fn_8013CC50(*(u32*)(this_+4),this_+0xc,lbl_8053EDB0[i],0,0,0,0,1,lbl_8053EDC0);
            *(s32*)(this_+0x24c)=0;
            *(s32*)(this_+0x248)=6;
        }
        break;
    case 6:
        fn_801F0E34(this_,0x5004c,0);
        if (*(s32*)(this_+0x24c)>=0x78) {
            if(!lbl_8053AC24) {lbl_8053AC20=lbl_80469430;lbl_8053AC24=1;}
            *(void**)(this_+0x2d4)=fn_804032E8(0x54494d47,lbl_8053AC20);
            f32 vec[3];
            vec[1]=lbl_8053EDCC+*(f32*)(this_+0x10);
            vec[0]=*(f32*)(this_+0xc);
            vec[2]=lbl_8053EDD0;
            fn_8021F9AC(this_+0x3f8,vec);
            *(s32*)(this_+0x24c)=0; *(s32*)(this_+0x248)=7;
        }
        break;
    case 7:
        fn_801F0E34(this_,0x5004c,0);
        if(fn_8021F4B0(this_+0x3f8)) {
            for (i=0;i<5;i++) {
                if(*(void**)(this_+0x2c0+i*4)) {
                    void* mgr = *(void**)((u8*)fn_8013C824()+0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(this_+0x2c0+i*4));
                }
                *(void**)(this_+0x2c0+i*4)=0;
            }
            s32 id=fn_801F7884(fn_801F856C(),0x444d5a4c,*(u32*)(this_+4));
            if(id>=0 && fn_801F666C(fn_801F856C(),id)) fn_8010F9F0();
            *(u16*)fn_801C0D70() |= 0x1000;
            *(s32*)(this_+0x24c)=0; *(s32*)(this_+0x248)=8;
            break;
        }
        if(*(u16*)(this_+0x2ac)) {
            --*(u16*)(this_+0x2ac);
            if(!*(u16*)(this_+0x2ac)) {
                for (i=0;i<5;i++) {
                    if(*(void**)(this_+0x2c0+i*4)) {
                        void* mgr = *(void**)((u8*)fn_8013C824()+0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(this_+0x2c0+i*4));
                    }
                    *(void**)(this_+0x2c0+i*4)=0;
                }
            } else {
                f32 alpha=lbl_8053EDC8*(lbl_8053EDD4*(f32)(u32)*(u16*)(this_+0x2ac));
                if(*(u8**)(this_+0x2c0)) (*(u8**)(this_+0x2c0))[0xbb]=(u8)(s32)alpha;
                if(*(u8**)(this_+0x2c4)) (*(u8**)(this_+0x2c4))[0xbb]=(u8)(s32)alpha;
                if(*(u8**)(this_+0x2c8)) (*(u8**)(this_+0x2c8))[0xbb]=(u8)(s32)alpha;
                if(*(u8**)(this_+0x2cc)) (*(u8**)(this_+0x2cc))[0xbb]=(u8)(s32)alpha;
                if(*(u8**)(this_+0x2d0)) (*(u8**)(this_+0x2d0))[0xbb]=(u8)(s32)alpha;
            }
        } else if(*(s32*)(this_+0x24c)==0xf0) *(u16*)(this_+0x2ac)=0x78;
        break;
    case 8:
        fn_801F0E34(this_, 0x5004c, 0);
        if (!(*(u16*)fn_801C0D70() & 0x1000)) {
            fn_8021F914(this_ + 0x3f8, 5);
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 9;
        }
        break;
    case 9:
        if (*(s32*)(this_ + 0x24c) >= 0x5a) {
            fn_8021F924(this_ + 0x3f8);
            for (i = 0; i < 5; i++) {
                fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_80469418[i], 0, 0, 0, 0, 1, lbl_8053EDC0);
            }
            fn_801F0E34(this_, 0x5006f, 0);
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 10;
        } else {
            fn_8021F4B0(this_ + 0x3f8);
        }
        break;
    case 10:
        if (*(s32*)(this_ + 0x24c) >= 0xb4) {
            fn_8022ADCC();
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 11;
        }
        break;
    case 11:
        break;
    }
    if (*(u8**)(this_+0x2b4)) {
        u32 n=*(u32*)(*(u8**)(this_+0x2b4)+0x100);
        if(n>=0x14 && (n-0x14)%90==0) fn_801F0E34(this_,0x50048,0);
    }
    if (*(s32*)(this_ + 0x248) >= 4 && *(s32*)(this_ + 0x248) < 7) {
        fn_801F0E34(this_, 0x5004a, 0);
    }
    *(u32*)(this_ + 0x108) = *(u32*)(this_ + 0x244);
}

extern "C" void fn_801D0ED0(u8* this_);
extern "C" void* fn_804032E8(u32 name, void* str);
extern "C" void* fn_801C0D70(void);
extern "C" u16 lbl_8053EDA8[3];
extern "C" f32 lbl_8053EDD0;
extern "C" f32 lbl_8053EDE8;
extern "C" char lbl_80469444[];
extern "C" char lbl_8053AC1C;
extern "C" char* lbl_8053AC18;
extern "C" void fn_801C2150(u8* this_) {
    struct ItemBaseVT {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v10();
        virtual bool v11();
    };
    f32 neg;
    f32 two;
    f32 zero;
    fn_801D0ED0(this_);
    zero = lbl_8053EDC0;
    two = lbl_8053EDE8;
    neg = lbl_8053EDD0;
    *(u8*)(this_ + 0x2a8) = *(u32*)(this_ + 0x90) >> 8;
    *(u8*)(this_ + 0x2a9) = *(u32*)(this_ + 0x90) >> 16;
    *(f32*)(this_ + 0x60) = zero;
    *(f32*)(this_ + 0x64) = zero;
    *(f32*)(this_ + 0x68) = two;
    *(f32*)(this_ + 0x6c) = two;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = zero;
    *(f32*)(this_ + 0x84) = zero;
    *(f32*)(this_ + 0x88) = two;
    *(f32*)(this_ + 0x8c) = two;
    *(s32*)(this_ + 0xb0) = 0;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x380;
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = -1;
    *(f32*)(this_ + 0x254) = neg;
    *(f32*)(this_ + 0x258) = neg;
    if (lbl_8053AC1C == 0) {
        lbl_8053AC18 = lbl_80469444;
        lbl_8053AC1C = 1;
    }
    *(void**)(this_ + 0x2d4) = fn_804032E8(0x54494d47, lbl_8053AC18);
    if (((ItemBaseVT*)this_)->v11()) {
        *(s32*)(this_ + 0x248) = 0xb;
    } else {
        *(void**)(this_ + 0x2b0) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x4f, 0, 0, 0, 0, 1, lbl_8053EDC0);
        for (s32 i = 0; i < 3; i++) {
            *(void**)(this_ + 0x2b4 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053EDA8[i], 0, 0, 0, 0, 1, lbl_8053EDC0);
        }
    }
    void* p = *(void**)(this_ + 0x198);
    *(void**)((u8*)fn_801C0D70() + 0x50) = p;
}

extern "C" void* fn_801C231C(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A4310;
        fn_801EE434(*(void**)(this_ + 0x2b0));
        for (s32 i = 0; i < 3; i++) {
            fn_801EE434(*(void**)(this_ + 0x2b4 + i * 4));
        }
        for (s32 i = 0; i < 5; i++) {
            fn_801EE434(*(void**)(this_ + 0x2c0 + i * 4));
        }
        fn_8021FAB8(this_ + 0x3f8, -1);
        if (this_ != 0) {
            *(void**)this_ = lbl_804A4808;
            if (this_ + 0x270 != 0) {
                if (this_ + 0x294 != 0) {
                    *(void**)(this_ + 0x294) = lbl_8049CC34;
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

extern "C" void fn_801D0F40(u8* this_);
extern "C" u8* fn_8021C5B0(u8* this_);
extern "C" void fn_8021FB44(char* p);
extern "C" void __construct_array(void* p, void* ctor, void* dtor, int size, int n);
extern "C" char lbl_804A4310[];
extern "C" u8* fn_801C2414(u8* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4310;
    *(u8*)(this_ + 0x2a8) = 0;
    *(u8*)(this_ + 0x2a9) = 0;
    *(s16*)(this_ + 0x2aa) = 0;
    *(s16*)(this_ + 0x2ac) = 0;
    *(s32*)(this_ + 0x2b0) = 0;
    *(s32*)(this_ + 0x2d4) = 0;
    __construct_array(this_ + 0x2d8, (void*)fn_8021C5B0, 0, 0x48, 4);
    fn_8021FB44((char*)(this_ + 0x3f8));
    *(s32*)(this_ + 0x2b4) = 0;
    *(s32*)(this_ + 0x2b8) = 0;
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = 0;
    *(s32*)(this_ + 0x2c4) = 0;
    *(s32*)(this_ + 0x2c8) = 0;
    *(s32*)(this_ + 0x2cc) = 0;
    *(s32*)(this_ + 0x2d0) = 0;
    return this_;
}

