// ANHO_80102278: .text 0x80102278-0x8010307C (actor ANHO)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/Actor.h"

// ---- from Game/fn_80102278_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C970[];

extern "C" void* fn_80102278(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C970;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F02BC(void* this_, const char* name, s32 idx, s32, s32, s32, s32, f32, f32);
extern "C" void fn_8043CB24(void* mgr, s32 t, s32 a, s32 b, s32 c, s32 d, f32, f32, f32);
extern char lbl_80463BB8[];
extern void* lbl_8053AED0;
extern const f32 lbl_8053C1A8;
extern const f32 lbl_8053C1AC;
extern const f32 lbl_8053C1B0;
extern const f32 lbl_8053C1B4;

extern "C" void fn_801022D8(char* p) {
    fn_801F02BC(p, lbl_80463BB8, 0x311 + ((u8*)p)[0x235] * 2 + *(s32*)(p + 0x238), 0, 0, 0, 0, lbl_8053C1A8, lbl_8053C1A8);
    if (*(s32*)(p + 0x230) == 4 || *(s32*)(p + 0x230) == 5 || *(s32*)(p + 0x230) == 6) {
        fn_8043CB24(lbl_8053AED0, *(s32*)(p + 0x240) / 60, 0xff, 0, 2, 1, lbl_8053C1AC, lbl_8053C1B0, lbl_8053C1B4);
    }
}

extern const f32 lbl_8053C1B8;
extern const f32 lbl_8053C1BC;
extern const f32 lbl_8053C1C0;
extern const u8 lbl_80539EB8[2];
extern char* lbl_8053AB10;
extern char* lbl_8053AF80;
extern "C" void fn_80239914(void*,int,int);
extern "C" void fn_8022FEB8(void*,int,int,int,int);
extern "C" int fn_8022FD8C(int);
extern "C" u8 fn_802300EC(int);
extern "C" u8 fn_8038AD24(int,int,int,int,const JGeometry::TVec3<f32>&,int);
extern "C" void fn_802308E0(int);
extern "C" void fn_801EE8F4(void*,void*,f32*,int);
extern "C" u8 fn_803865B8(int);
extern "C" int fn_8037EFB4(int);
extern "C" int fn_80236228(int);
extern "C" void fn_8038470C(int,int);
extern "C" int fn_802373EC(int);
extern "C" int fn_8023725C(int);
extern "C" void fn_802372F8(int,int,int);
extern "C" u8 fn_8022F514(int);
extern "C" void fn_8023619C(int,int);
extern "C" int fn_80236100(int);
extern "C" u8 fn_80388CAC(int,int);
extern "C" void fn_80230534(int);
extern "C" int fn_8023DE58(int);
extern "C" void fn_8022FE80(int,int,int,int,int);
extern "C" void fn_8022B148();
extern "C" void fn_801F0D20(void*,int);
extern "C" void fn_80458FF0(void*,int,int,int);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void*,int,int,int);
extern "C" void fn_80458508(void*,int);
extern "C" u8 fn_8023077C();
extern "C" void fn_8030C210(void*,void*);
extern "C" void fn_8022B130();
extern "C" u8 fn_80384C58(int,int);
extern const u8 lbl_80539EB8[2];
static inline u8 anhoStartMessage(const int player, const int message, const int handle, const int room, JGeometry::TVec3<f32>& copy, const JGeometry::TVec3<f32>& pos, int mode) {
    copy = pos;
    return fn_8038AD24(player, message, handle, room, copy, mode);
}

#pragma opt_lifetimes off
extern "C" void fn_80102398(char* p) {
    int iB;
    int iC;
    int best;
    char* q;
    int* delta;
    char* scoreActor;
    int* deltaBase;
    int iA;
    JGeometry::TVec3<f32> pos(*(Vec*)(p + 0xC));
    pos.y -= lbl_8053C1B8;
    JGeometry::TVec3<f32> cam(*(Vec*)(p + 0xC));
    f32 box[4];
    JGeometry::TVec3<f32> temp0, temp1, temp2;
    JGeometry::TVec3<f32> dir;
    int diffs[4];
    JGeometry::TVec3<f32> dir2;
    f32 dist;
    f32 dist2;
    box[0] = *(f32*)(p + 0x60);
    box[1] = *(f32*)(p + 0x64);
    box[2] = *(f32*)(p + 0x68);
    box[3] = *(f32*)(p + 0x6C);
    box[0] += *(f32*)(p + 0xC);
    box[1] += *(f32*)(p + 0x10);
    box[2] += *(f32*)(p + 0xC);
    box[3] += *(f32*)(p + 0x10);
    fn_80239914(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198));
    ++((u8*)p)[0x234];
    if (((u8*)p)[0x234] == lbl_80539EB8[*(s32*)(p + 0x238)]) {
        ++*(s32*)(p + 0x238);
        if (*(s32*)(p + 0x238) == 2) *(s32*)(p + 0x238) = 0;
        ((u8*)p)[0x234] = 0;
    }
    switch (*(s32*)(p + 0x230)) {
    case 0:
        fn_8022FEB8(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198), 1, 0);
        *(s32*)(p + 0x23c) = fn_8022FD8C(*(s32*)(p + 0x198));
        if (*(s32*)(p + 0x23c) >= 0 && fn_802300EC(*(s32*)(p + 0x23c))) {
            s32 room0 = *(s32*)(p+4);
            s32 handle0 = *(s32*)(p+0x198);
            if (anhoStartMessage(*(s32*)(p + 0x23c), ((u8*)p)[0x236] == 1 ? 0x32E : 0x32E, handle0, room0, temp0, pos, 0)) {
                for (iA = 0; iA < 4; iA++) fn_802308E0(iA);
                *(s32*)(p + 0x230) = 1;
                *(s32*)(p + 0x244) = 0;
                fn_801EE8F4(p, &dir, &dist, *(s32*)(p + 0x23c) + 1);
                if (dist < lbl_8053C1BC) {
                    f32 radians = JMath::atanTable_.atan2_(-dir.x, -dir.y);
                    u32 angle = (u16)(radians * lbl_8053C1C0);
                    if (angle < 0x2000 || angle >= 0xE000) ((u8*)p)[0x235] = 3;
                    else if (angle >= 0x2000 && angle < 0x6000) ((u8*)p)[0x235] = 1;
                    else if (angle >= 0x6000 && angle <= 0xA000) ((u8*)p)[0x235] = 2;
                    else ((u8*)p)[0x235] = 0;
                }
            }
        }
        break;
    case 1:
        { char* c = *(char**)(lbl_8053AB10 + 0x24);
        if (((u8*)c)[0x7F5] == 0) {
            ((u8*)c)[0x7F4] = 1;
            *(s32*)(c + 0x7F8) = 4;
            *(f32*)(c + 0x7FC) = cam.x;
            *(f32*)(c + 0x800) = cam.y;
            *(f32*)(c + 0x804) = cam.z;
            ((u8*)c)[0x7F6] = 0;
        } }
        fn_8022FEB8(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x23c))) {
            switch (fn_8037EFB4(*(s32*)(p + 0x23c))) {
            case 0:
                if (((u8*)p)[0x236] == 1 && fn_80236228(*(s32*)(p + 0x23c)) < 0) {
                    fn_8038470C(*(s32*)(p + 0x23c), 0x333);
                    *(s32*)(p + 0x230) = 2; *(s32*)(p + 0x244) = 0;
                } else {
                    fn_8038470C(*(s32*)(p + 0x23c), ((u8*)p)[0x236] == 1 ? 0x32F : 0x32F);
                    *(s32*)(p + 0x230) = 3; *(s32*)(p + 0x244) = iB = 0;
                    q=p;
                    for (;iB<4;iB++,q+=4) {
                        *(s32*)(q+0x254) = fn_802373EC(iB);
                        *(s32*)(q+0x264) = fn_8023725C(iB);
                        fn_802372F8(iB,9,2);
                    }
                    iA=0;
                    q=p;
                    for (;iA<4;iA++,q+=4) {
                        if (!fn_8022F514(iA)) {
                            fn_8023619C(iA,-100);
                            *(s32*)(q+0x274) = fn_80236100(iA);
                        }
                    }
                }
                break;
            case 1:
                fn_8038470C(*(s32*)(p + 0x23c),0x330);
                *(s32*)(p + 0x230) = 2; *(s32*)(p + 0x244) = 0;
                break;
            }
        }
        break;
    case 2:
        { char* c = *(char**)(lbl_8053AB10 + 0x24);
        if (((u8*)c)[0x7F5] == 0) {
            ((u8*)c)[0x7F4] = 1;
            *(s32*)(c + 0x7F8) = 4;
            *(f32*)(c + 0x7FC) = cam.x;
            *(f32*)(c + 0x800) = cam.y;
            *(f32*)(c + 0x804) = cam.z;
            ((u8*)c)[0x7F6] = 0;
        } }
        fn_8022FEB8(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x23c), *(s32*)(p + 0x198))) {
            *(s32*)(p + 0x230) = 0; *(s32*)(p + 0x244) = 0; fn_80230534(0);
        }
        break;
    case 3:
        { char* c = *(char**)(lbl_8053AB10 + 0x24);
        if (((u8*)c)[0x7F5] == 0) {
            ((u8*)c)[0x7F4] = 1;
            *(s32*)(c + 0x7F8) = 4;
            *(f32*)(c + 0x7FC) = cam.x;
            *(f32*)(c + 0x800) = cam.y;
            *(f32*)(c + 0x804) = cam.z;
            ((u8*)c)[0x7F6] = 0;
        } }
        fn_8022FE80(*(s32*)(p + 0x23c), fn_8023DE58(0), *(s32*)(p + 0x198),0,0);
        if (fn_80388CAC(*(s32*)(p + 0x23c), *(s32*)(p + 0x198))) {
            *(s32*)(p + 0x230) = 4; *(s32*)(p + 0x244) = 0; *(s32*)(p + 0x240) = 3600;
            fn_80230534(0); fn_8022B148(); fn_801F0D20(p,0x3A);
            *(s32*)(p + 0x248) = *(s32*)(lbl_8053AF80+0x58);
            fn_80458FF0(lbl_8053AF80,0x1000007,1,0);
            fn_802D8050(fn_802D6A9C(),*(s32*)(p + 0x24c),1,255);
        }
        break;
    case 4:
        --*(s32*)(p + 0x240);
        if (*(s32*)(p + 0x240) / 60 <= 10 && *(s32*)(p + 0x240) % 60 == 59) fn_801F0D20(p,0x3F);
        fn_80458508(lbl_8053AF80,1);
        if (*(s32*)(p + 0x240) == 0) {
            ((u8*)p)[0x250] = fn_8023077C();
            *(s32*)(p + 0x230)=5; *(s32*)(p + 0x244)=0;
            fn_801F0D20(p,0x3B); ((u8*)p)[0x235]=2;
            fn_802D8050(fn_802D6A9C(),*(s32*)(p + 0x24c),0,255);
            fn_80458508(lbl_8053AF80,0);
        }
        break;
    case 5:
        fn_8030C210(*(void**)(lbl_8053AB10+0x24),p+0xC);
        ++*(s32*)(p + 0x244);
        if (((u8*)p)[0x250] == 0) ((u8*)p)[0x250] = fn_8023077C();
        if (*(s32*)(p + 0x244) > 50 && ((u8*)p)[0x250] == 1) {
            fn_8022FE80(0,fn_8023DE58(0),*(s32*)(p + 0x198),0,0);
            if (fn_8022FD8C(*(s32*)(p + 0x198)) == 0) {
                s32 handle1 = *(s32*)(p+0x198);
                s32 room1 = *(s32*)(p+4);
                fn_8038AD24(0,0x331,handle1,room1,(temp1 = pos, temp1),2);
                *(s32*)(p + 0x230)=6; *(s32*)(p + 0x244)=0; fn_8022B130();
            }
        }
        break;
    case 6:
        fn_8030C210(*(void**)(lbl_8053AB10+0x24),p+0xC);
        fn_8022FE80(0,fn_8023DE58(0),*(s32*)(p + 0x198),0,0);
        if (fn_803865B8(0) && fn_80384C58(0,*(s32*)(p + 0x198))) {
            ((Actor*)p)->v10(255,1);
            *(s32*)(p + 0x230)=7; *(s32*)(p + 0x244)=0; fn_80230534(0);
            deltaBase = diffs;
            scoreActor = p;
            delta = deltaBase;
            best=-10000;
            iC=0;
            int zero = iC;
            for (;iC<4;iC++,delta++,scoreActor+=4) {
                *delta=zero;
                if (!fn_8022F514(iC)) {
                    *delta=fn_80236100(iC)-*(s32*)(scoreActor+0x274);
                    if (*delta>best) best=*delta;
                }
            }
            scoreActor=p;
            for (iB=0;iB<4;iB++,deltaBase++,scoreActor+=4) {
                if (!fn_8022F514(iB) && best != *deltaBase)
                    fn_802372F8(iB, *(s32*)(scoreActor+0x254), *(s32*)(scoreActor+0x264));
            }
            fn_80458FF0(lbl_8053AF80,*(s32*)(p+0x248),1,0);
        }
        break;
    case 7:
        fn_8022FEB8(box, *(s32*)(p+4), *(s32*)(p+0x198), 1, 0);
        *(s32*)(p+0x23C)=fn_8022FD8C(*(s32*)(p+0x198));
        if (*(s32*)(p+0x23C)>=0) {
            s32 handle2=*(s32*)(p+0x198);
            s32 room2=*(s32*)(p+4);
            if (fn_8038AD24(*(s32*)(p+0x23C),0x332,handle2,room2,(temp2 = pos, temp2),0)) {
            *(s32*)(p+0x230)=8; *(s32*)(p+0x244)=0;
                fn_801EE8F4(p, &dir2, &dist2, *(s32*)(p + 0x23c) + 1);
                if (dist2 < lbl_8053C1BC) {
                    f32 radians = JMath::atanTable_.atan2_(-dir2.x, -dir2.y);
                    u32 angle = (u16)(radians * lbl_8053C1C0);
                    if (angle < 0x2000 || angle >= 0xE000) ((u8*)p)[0x235] = 3;
                    else if (angle >= 0x2000 && angle < 0x6000) ((u8*)p)[0x235] = 1;
                    else if (angle >= 0x6000 && angle <= 0xA000) ((u8*)p)[0x235] = 2;
                    else ((u8*)p)[0x235] = 0;
                }
        }
        }
        break;
    case 8:
        fn_8022FEB8(box, *(s32*)(p+4), *(s32*)(p+0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p+0x23C),*(s32*)(p+0x198))) {
            *(s32*)(p+0x230)=7; *(s32*)(p+0x244)=0;
        }
        break;
    }
}
#pragma opt_lifetimes reset
struct AnhoRandom {
    u32 seed;
    u32 get() {
        seed = seed * 0x19660d + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - lbl_8053C1A8;
    }
};
struct AnhoGame { u8 pad[0xb4]; AnhoRandom rnd; };
class AnhoVBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual bool isFlag();
};
extern AnhoGame* lbl_8053AAF8;
extern "C" u8 fn_80138A30(AnhoGame* game);
extern const f32 lbl_8053C1C4;
extern const f32 lbl_8053C1C8;
extern const f32 lbl_8053C1CC;

extern "C" void fn_80102D34(char* p) {
    *(f32*)(p + 0x60) = lbl_8053C1C4;
    *(f32*)(p + 0x64) = lbl_8053C1C4;
    *(f32*)(p + 0x68) = lbl_8053C1C8;
    *(f32*)(p + 0x6c) = lbl_8053C1C8;
    p[0x235] = 1;
    *(s32*)(p + 0x238) = 0;
    p[0x234] = 0;
    *(s32*)(p + 0x23c) = -1;
    p[0x236] = fn_80138A30(lbl_8053AAF8);
    *(s32*)(p + 0x24c) = (s32)(lbl_8053C1CC * lbl_8053AAF8->rnd.get_ufloat_1()) + 0x10;
    if (*(s32*)(p + 0x24c) == 0x14) {
        *(s32*)(p + 0x24c) = 0x13;
    }
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x280) = 0;
    if (((AnhoVBase*)p)->isFlag()) {
        *(s32*)(p + 0x230) = 7;
        *(s32*)(p + 0x244) = 0;
    } else {
        *(s32*)(p + 0x230) = 0;
        *(s32*)(p + 0x244) = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
