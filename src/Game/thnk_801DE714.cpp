// Game TU 801DE714-801E2540 (THNK). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "math.h"
extern "C" void fn_801DF9D8(void*, void*);
extern "C" void fn_801E002C(void*, void*);
extern "C" void fn_801E1AB4(void*, u8);
extern "C" void fn_801E2D88(void*);
extern "C" s32 fn_802375B0(s32);
extern "C" s32 fn_801CCFE4(s32);
extern "C" s32 fn_80138A30(void*);
extern void* lbl_8053AAF8;
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802308E0(s32);
extern "C" u8 fn_8038AD24(s32,s32,s32,s32,void*,s32);
extern "C" void fn_8023061C(s32,s32);
extern "C" u8 fn_801D0DD4(void*);
extern "C" s32 fn_801D05F8(void*,void*,f32);
extern "C" s32 fn_801D0020(void*,void*,s32,s32);
extern "C" void fn_801CD950(void*,f32,f32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" s32 fn_80236228(s32);
extern "C" u8 fn_8038470C(s32,s32);
extern "C" u8 fn_80384C58(s32,s32);
extern "C" void fn_80237524(s32,s32);
extern "C" void fn_8023619C(s32,s32);
extern f32 lbl_8053F498, lbl_8053F49C, lbl_8053F4A0, lbl_8053F4B0;


extern "C" void fn_801CE694(void* this_);
extern "C" u8 fn_801CD2F8(s32 owner);
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801CE2BC(void);
extern "C" void fn_8021835C(void* this_);
extern "C" s32 fn_801CCF7C(void);
extern "C" void* fn_801F856C();
extern "C" void fn_801E1594(void* this_, s32 state);
extern "C" void fn_8021FDB8(void* this_);
extern "C" const f32 lbl_8053F488;
extern "C" const f32 lbl_8053F4AC;
extern "C" s32 fn_801F750C(void* mgr, void* a, s32 b);
extern "C" s32 fn_801F7464(void* mgr, void* a, s32 b);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801CD664(s32 n);
extern "C" u8 fn_801CD2F8(s32 owner);
extern "C" void* fn_8023E724(s32 idx);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
static inline u8 thnk_isIdleSub(void* this_) {
    u8 r = 0;
    switch (*(s32*)((char*)this_ + 0x278)) {
    case 0: case 1: case 2:
    case 0xd: case 0xe: case 0xf: case 0x10:
        r = 1;
    }
    return r;
}

static inline u8 thnkShouldReset(void* this_) {
    char* p = (char*)this_;
    s32 state = *(s32*)(p + 0x248);
    u8 hit = 0;
    switch (state) {
    case 0: case 7:
    case 0xf: case 0x10: case 0x11: case 0x12:
        break;
    default:
        if (!(*(u32*)(p + 0x230) & 0x4000) && *(u16*)(p + 0x2cc) == 0 && thnk_isIdleSub(this_)) {
            if (*(u32*)(p + 0x230) & 0x20000) {
                if (*(u32*)(p + 0x230) & 0x100000) hit = 1;
            } else if (*(s32*)(p + 0x2bc) < 0) hit = 1;
        }
    }
    return hit;
}

extern "C" void fn_801E1300(void* this_);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" u8 fn_801CD290(s32 owner);
extern "C" s32 fn_801CD354(s32 owner);
extern "C" u8 fn_801E3250(s32 owner, s32 flag);
extern "C" u8 fn_801D21F0(void* p);
extern "C" void fn_8022FE80(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_801E2F40(void* this_);
extern "C" void fn_801E2EE4(void* this_);
extern "C" void fn_801F7AB8(void* base, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
static inline char* thnkFieldAt(const s32 room) {
    char* rec = (char*)fn_802D6A9C();
    if (room < 8) return rec + 0xcc;
    return rec + 0xdc;
}
extern f32 lbl_8053F4A4;
extern f32 lbl_8053F480;
extern void* lbl_804A51E4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern u8 lbl_8050EC80[];
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801D0F40(void* this_);
extern "C" void fn_801E1E08(void* this_);
extern "C" void fn_801D22A0(void* p, s32 a, s32 b);
extern "C" void* fn_8023E724(s32 idx);
extern "C" void fn_8020D2AC(void* this_);
extern "C" u8 fn_80218538(void* this_);
extern "C" void fn_801F0E34(void* this_, u32 a, s32 b);
extern "C" void fn_8020D16C(void* this_);
extern "C" void fn_8020CFC4(void* this_);
extern "C" s32 fn_801CD664(s32 kind);
extern f32 lbl_8053F4A8;
static inline u8 thnkIsLeft(f32 x, s32 room) {
    u8 result = 0;
    char* field = thnkFieldAt(room);
    if (x < lbl_8053F4A8 * (*(f32*)field + *(f32*)(field + 8))) result = 1;
    return result;
}
extern "C" void fn_801E1594(void* this_, s32 state);
extern f32 lbl_8053F4BC;
extern f32 lbl_8053F490;
extern f32 lbl_8053F4C0;
extern f32 lbl_8053F4C4;

extern "C" void fn_801DE714(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 0xa) {
        fn_801CE694(this_);
    }
}

extern "C" void fn_801DE740(void* this_) {
    u8 flag = 0;
    s32 state = *(s32*)((char*)this_ + 0x248);
    switch (state) {
    case 0xb:
    case 0xc:
        flag = 1;
        break;
    }
    if (flag == 0) {
        return;
    }
    if (fn_801CD2F8(*(s32*)((char*)this_ + 0x4)) != 0) {
        return;
    }
    {
        void* registry = fn_80212AC0();
        fn_80212AF0(registry, (char*)this_ + 0xc);
    }
}

extern f32 lbl_8053F484;
extern f32 lbl_8053F48C;
extern f32 lbl_8053F494;
extern f32 lbl_8053EFBC;
extern "C" void fn_801D01A0(void* this_, void* pos, void* out, f32 speed = 0.0f);
extern "C" void fn_801D00B4(void* this_, s32 idx, void* out, f32 speed = 0.0f);
extern "C" void fn_801DE7AC(void* this_) {
    f32 v[2];
    s32 flag = fn_801CCF7C();
    f32 zero = lbl_8053F480;
    *(f32*)((char*)this_ + 0x3c) = zero;
    *(f32*)((char*)this_ + 0x40) = zero;
    if (*(s32*)((char*)this_ + 0x248) != 0xa) {
        *(f32*)((char*)this_ + 0x44) = zero;
    }
    if (*(s32*)((char*)this_ + 0x248) != 0) {
        if (lbl_8053F480 != *(f32*)((char*)this_ + 0x254) && (flag & 0xff) == 0) {
            v[0] = lbl_8053F480;
            v[1] = lbl_8053F480;
            if (*(u32*)((char*)this_ + 0x230) & 0x4000) {
                fn_801D01A0(this_, (char*)this_ + 0x2c4, v, *(f32*)((char*)this_ + 0x254));
            } else if (*(u32*)((char*)this_ + 0x230) & 0x20000) {
                if (*(s32*)((char*)this_ + 0x2a8) >= 0) {
                    fn_801D00B4(this_, *(s32*)((char*)this_ + 0x2a8), v, *(f32*)((char*)this_ + 0x254));
                }
            } else {
                void* found = 0;
                s32 idx = *(s32*)((char*)this_ + 0x2ac);
                if (idx >= 0) {
                    found = fn_801F666C(fn_801F856C(), idx);
                }
                if (found == 0) {
                    idx = *(s32*)((char*)this_ + 0x2b0);
                    if (idx >= 0) {
                        found = fn_801F666C(fn_801F856C(), idx);
                    }
                }
                if (found == 0) {
                    idx = *(s32*)((char*)this_ + 0x2b4);
                    if (idx >= 0) {
                        found = fn_801F666C(fn_801F856C(), idx);
                    }
                }
                if (found != 0) {
                    fn_801D01A0(this_, (char*)found + 0xc, v, *(f32*)((char*)this_ + 0x254));
                }
            }
            *(f32*)((char*)this_ + 0x3c) = v[0];
            *(f32*)((char*)this_ + 0x40) = v[1];
        }
        switch (*(s32*)((char*)this_ + 0x248)) {
        case 2:
            if ((flag & 0xff) == 0) {
                *(f32*)((char*)this_ + 0x44) = lbl_8053F484;
            }
            break;
        case 4:
            if ((flag & 0xff) == 0) {
                if (*(u32*)((char*)this_ + 0x230) & 0x80000) {
                    *(f32*)((char*)this_ + 0x44) = lbl_8053F488;
                } else {
                    *(f32*)((char*)this_ + 0x44) = *(s32*)((char*)this_ + 0x2bc) >= 0 ? lbl_8053F48C : lbl_8053F490;
                }
            }
            break;
        case 10: {
            f32 cur = *(f32*)((char*)this_ + 0x44) + lbl_8053F494;
            f32 lim = -lbl_8053EFBC;
            *(f32*)((char*)this_ + 0x44) = cur;
            if (*(f32*)((char*)this_ + 0x44) < lim) {
                *(f32*)((char*)this_ + 0x44) = lim;
            }
            break;
        }
        case 18:
            if ((flag & 0xff) == 0) {
                *(f32*)((char*)this_ + 0x44) = lbl_8053F494;
            }
            break;
        }
    }
}

extern "C" void fn_801DE9C0(void* this_) {
    fn_801CE2BC();
    fn_8021835C(this_);
}

extern "C" void fn_801DE9F4(void* this_) {
    char* p = (char*)this_;
    if (*(u16*)(p + 0x2ce) != 0) {
        *(u16*)(p + 0x2ce) = *(u16*)(p + 0x2ce) - 1;
    }
    if (*(u16*)(p + 0x2ce) == 0) {
        if (*(s32*)(p + 0x248) == 7) {
            switch (*(s32*)(p + 0x278)) {
            case 0xf:
            case 0x10:
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 2, 0);
                return;
            }
        }
        fn_801CE4BC(this_);
    }
}

extern "C" void fn_801E0CF4(char* this_);
#pragma opt_propagation off
#pragma opt_common_subs off
static inline u8 thnkPlayerActive(s32 player) {
    s32 active = 0;
    if (fn_802375B0(player) == 0 && (u8)fn_801CCFE4(player)) active = 1;
    return active;
}
static inline u8 thnkPlayerValid(s32 player) {
    s32 valid = 0;
    if (thnkPlayerActive(player) && player < fn_80138A30(lbl_8053AAF8)) valid = 1;
    return valid;
}
#pragma opt_common_subs reset
#pragma opt_common_subs reset
extern "C" void fn_801DEA70(void* this_) {
    char* const p = (char*)this_;
    u32 active;
    s32 room;
    u8 valid;
    s32 player;
    s32 state;
    void* found;
    if (*(u16*)(p+0x2cc)==0) fn_801E0CF4(p);
    const s32 pause=fn_801CCF7C();
    s32 idx=*(s32*)(p+0x2ac); found=0;
    if(idx>=0)found=fn_801F666C(fn_801F856C(),idx);
    if(!found){idx=*(s32*)(p+0x2b0);if(idx>=0)found=fn_801F666C(fn_801F856C(),idx);}
    if(!found){idx=*(s32*)(p+0x2b4);if(idx>=0)found=fn_801F666C(fn_801F856C(),idx);}
    state=*(s32*)(p+0x248);
    switch(state) {
    case 0:
        if((u8)pause)break;
        if(*(u16*)(p+0x2cc)) {--*(u16*)(p+0x2cc);break;}
        if(*(s32*)(p+0x2a8)>=0){*(u32*)(p+0x230)|=0x120000;fn_801E1594(this_,1);break;}
        if(*(u32*)(p+0x230)&0x40000)break;
        idx=*(s32*)(p+0x2ac);
        if(idx<0 || !fn_801F666C(fn_801F856C(),idx)) {
            idx=*(s32*)(p+0x2b0);
            if(idx<0 || !fn_801F666C(fn_801F856C(),idx))break;
        }
        if(!fn_801E3250(*(s32*)(p+4),0))fn_801E1594(this_,1);
        break;
    case 1:
        if(*(u32*)(p+0x230)&0x20000) {
            if(*(u32*)(p+0x230)&0x4000)break;
            player=*(s32*)(p+0x2a8);
            if(player<0)break;
            valid=0;
            active=0;
            if(fn_802375B0(player)==0 && (u8)fn_801CCFE4(player))active=1;
            if((u8)(active & 0xff) && player<fn_80138A30(lbl_8053AAF8))valid=1;
            if(!valid)break;
            room=*(s32*)(p+4);
            s32 playerRoom=fn_8023DE58(*(s32*)(p+0x2a8));
            if(playerRoom!=room)break;
            if(!(fabs(((f32*)fn_8023E724(*(s32*)(p+0x2a8)))[0]-*(f32*)(p+0xc))<lbl_8053F498))break;
            if(!(fabs(((f32*)fn_8023E724(*(s32*)(p+0x2a8)))[1]-*(f32*)(p+0x10))<lbl_8053F498))break;
            fn_8022FE80(*(s32*)(p+0x2a8),*(s32*)(p+4),*(s32*)(p+0x198),0,0);
            if(*(s32*)(p+0x2a8)!=fn_8022FD8C(*(s32*)(p+0x198)))break;
            if(!fn_802308E0(*(s32*)(p+0x2a8)))break;
            f32 v[3];v[0]=lbl_8053F480;v[1]=lbl_8053F480;v[2]=lbl_8053F480;
            if(fn_8038AD24(*(s32*)(p+0x2a8),0xf0,*(s32*)(p+0x198),*(s32*)(p+4),v,4))fn_801E1594(this_,15);
            else fn_8023061C(*(s32*)(p+0x2a8),0);
        } else {
            if(*(s32*)(p+0x2bc)>=0 || (*(u32*)(p+0x230)&0x4000) || !found)break;
            f32 dx=*(f32*)((char*)found+0xc)-*(f32*)(p+0xc);
            f32 dy=*(f32*)((char*)found+0x10)-*(f32*)(p+0x10);
            f32 xx=dx*dx;
            f32 yy=dy*dy;
            if(xx+yy<=lbl_8053F49C)fn_801E1594(this_,2);
        }
        break;
    case 2: {
        f32 height=lbl_8053F498;
        if(*(u32*)(p+0x230)&0x20000)height=lbl_8053F4A0;
        else {
            s32 i=*(s32*)(p+0x2ac);
            if(i>=0 && fn_801F666C(fn_801F856C(),i))height=lbl_8053F4A0;
            else {i=*(s32*)(p+0x2b0);if(i>=0 && fn_801F666C(fn_801F856C(),i))height=lbl_8053F4A0;}
        }
        if(*(f32*)(p+0x14)<=height){*(f32*)(p+0x14)=height;fn_801E1594(this_,3);}
        break;
    }
    case 3:fn_801E002C(this_,found);break;
    case 4: {
        f32 z=*(f32*)(p+0x14);
        const f32 limit=30.0f;
        if(z>=limit){*(f32*)(p+0x14)=limit;fn_801E1594(this_,1);}break;
    }
    case 5:
        if(*(s32*)(p+0x24c)>1 && fn_801D21F0(p+0x270)) {
            *(s32*)(p+0x98)=fn_801CD354(*(s32*)(p+0x98));
            f32 limit=lbl_8053F4A4;
            if(*(f32*)(p+0x14)>=limit){*(f32*)(p+0x14)=limit;fn_801E1594(this_,1);}
            else fn_801E1594(this_,4);
        }break;
    case 6:
        if(*(s32*)(p+0x24c)>1 && fn_801D21F0(p+0x270)){
            *(s32*)(p+0x98)=fn_801CD354(*(s32*)(p+0x98));
            if(*(s32*)(p+0x2d0)>=0){fn_801E1594(this_,*(s32*)(p+0x2d0));*(s32*)(p+0x2d0)=-1;}
            else fn_801E1594(this_,1);
        }break;
    case 7:fn_801DF9D8(this_,found);break;
    case 8:if(*(s32*)(p+0x24c)>1 && fn_801D21F0(p+0x270))fn_801E1594(this_,9);break;
    case 9:if(*(s32*)(p+0x24c)>1 && fn_801D21F0(p+0x270))fn_801E1594(this_,10);break;
    case 10:
        if(*(s32*)(p+0x24c)>1 && fn_801D21F0(p+0x270) && fn_801D0DD4(this_)){
            if(fn_801E2F40(this_))fn_801E1594(this_,14);else fn_801E1594(this_,11);
        }break;
    case 11:if(*(s32*)(p+0x24c)>1 && fn_801D21F0(p+0x270))fn_801E1594(this_,12);break;
    case 12:
        if((u8)pause || !fn_801D21F0(p+0x270))break;
        if(*(s32*)(p+0x24c)>=*(s32*)(p+0x250)){fn_801E1594(this_,13);break;}
        {s32 i=fn_801D05F8(this_,p+0xc,lbl_8053F480);if(i>=0){
            s32 dir=fn_801D0020(this_,p+0xc,i,0);
            if(dir!=*(s32*)(p+0x98)){*(s32*)(p+0x98)=dir;fn_801D22DC(p+0x270,*(s32*)(p+0x98)+8,0,0);}
        }}break;
    case 13:
        if(*(s32*)(p+0x24c)>1 && fn_801D21F0(p+0x270)){
        *(u32*)(p + 0x230) |= 0x4000;
        *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
        {
            s32 room;
            u8 flag;
            f32 lower;
            f32 upper;
            f32 pos;
            room = *(s32*)(p + 4);
            char* rec = (char*)fn_802D6A9C();
            char* field = (room < 8) ? rec + 0xcc : rec + 0xdc;
            flag = 0;
            upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
            pos = *(f32*)(p + 0xc);
            lower = *(f32*)field - lbl_8053F4A4;
            flag=thnkIsLeft(pos,*(s32*)(p+4));
            if (flag && lower < *(f32*)(p + 0xc)) {
                *(f32*)(p + 0x2c4) = upper;
            } else {
                *(f32*)(p + 0x2c4) = lower;
            }
            switch (*(s32*)(p + 0x248)) {
            case 0xd:
                if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                    *(s32*)(p + 0x98) = 0;
                } else {
                    *(s32*)(p + 0x98) = 1;
                }
                if (*(f32*)(p + 0x14) >= 30.0f) {
                    *(f32*)(p + 0x14) = 30.0f;
                    fn_801E1594(this_, 1);
                } else {
                    fn_801E1594(this_, 4);
                }
                break;
            case 7: {
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                fn_801E1594(this_, 5);
                break;
            }
            default: {
                f32 cur = *(f32*)(p + 0x2c4);
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 5);
                } else {
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                }
                break;
            }
            }
        }
        }break;
    case 14:
        if(lbl_8053F480!=*(f32*)(p+0x54)){
            fn_801CD950(p+0x54,lbl_8053F480,lbl_8053F4B0);
            *(f32*)(p+0x58)=*(f32*)(p+0x54);*(f32*)(p+0x5c)=*(f32*)(p+0x54);
        }else fn_801E1594(this_,0);
        break;
    case 15:
        if(!fn_803865B8(*(s32*)(p+0x2a8)))break;
        if(fn_8037EFB4(*(s32*)(p+0x2a8))==0) {
            if(fn_80236228(*(s32*)(p+0x2a8))<20){if(fn_8038470C(*(s32*)(p+0x2a8),0xf1))fn_801E1594(this_,17);}
            else {if(fn_80384C58(*(s32*)(p+0x2a8),*(s32*)(p+0x198)))fn_801E1594(this_,18);}
        }else {if(fn_8038470C(*(s32*)(p+0x2a8),0xf2))fn_801E1594(this_,16);}
        break;
    case 16:
        if(fn_803865B8(*(s32*)(p+0x2a8)) && fn_80384C58(*(s32*)(p+0x2a8),*(s32*)(p+0x198))){
            fn_8023061C(*(s32*)(p+0x2a8),0);
        *(u32*)(p + 0x230) |= 0x4000;
        *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
        {
            s32 room;
            u8 flag;
            f32 pos;
            f32 lower;
            f32 upper;
            room = *(s32*)(p + 4);
            char* rec = (char*)fn_802D6A9C();
            char* field = (room < 8) ? rec + 0xcc : rec + 0xdc;
            flag = 0;
            upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
            pos = *(f32*)(p + 0xc);
            lower = *(f32*)field - lbl_8053F4A4;
            flag=thnkIsLeft(pos,*(s32*)(p+4));
            if (flag && lower < *(f32*)(p + 0xc)) {
                *(f32*)(p + 0x2c4) = upper;
            } else {
                *(f32*)(p + 0x2c4) = lower;
            }
            switch (*(s32*)(p + 0x248)) {
            case 0xd:
                if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                    *(s32*)(p + 0x98) = 0;
                } else {
                    *(s32*)(p + 0x98) = 1;
                }
                if (*(f32*)(p + 0x14) >= 30.0f) {
                    *(f32*)(p + 0x14) = 30.0f;
                    fn_801E1594(this_, 1);
                } else {
                    fn_801E1594(this_, 4);
                }
                break;
            case 7: {
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                fn_801E1594(this_, 5);
                break;
            }
            default: {
                f32 cur = *(f32*)(p + 0x2c4);
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 5);
                } else {
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                }
                break;
            }
            }
        }
        }break;
    case 17:
        if(fn_803865B8(*(s32*)(p+0x2a8)) && fn_80384C58(*(s32*)(p+0x2a8),*(s32*)(p+0x198)))fn_801E1594(this_,18);
        break;
    case 18:{
        f32 height=lbl_8053F498;
        if(*(u32*)(p+0x230)&0x20000)height=lbl_8053F4A0;
        else {
            s32 i=*(s32*)(p+0x2ac);
            if(i>=0 && fn_801F666C(fn_801F856C(),i))height=lbl_8053F4A0;
            else {i=*(s32*)(p+0x2b0);if(i>=0 && fn_801F666C(fn_801F856C(),i))height=lbl_8053F4A0;}
        }
        if(*(f32*)(p+0x14)<=height) {
            *(f32*)(p+0x14)=height;
            fn_80237524(*(s32*)(p+0x2a8),0x180);
            fn_8023619C(*(s32*)(p+0x2a8),-20);
            fn_8023061C(*(s32*)(p+0x2a8),0);
            *(u32*)(p+0x230)&=~0x100000;
            *(u32*)(p+0x230)|=0x80000;
            fn_801E1AB4(this_,1);
            fn_801F0E34(this_,0x5001b,0);
        *(u32*)(p + 0x230) |= 0x4000;
        *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
        {
            s32 room;
            u8 flag;
            f32 pos;
            f32 lower;
            f32 upper;
            room = *(s32*)(p + 4);
            char* rec = (char*)fn_802D6A9C();
            char* field = (room < 8) ? rec + 0xcc : rec + 0xdc;
            flag = 0;
            upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
            pos = *(f32*)(p + 0xc);
            lower = *(f32*)field - lbl_8053F4A4;
            flag=thnkIsLeft(pos,*(s32*)(p+4));
            if (flag && lower < *(f32*)(p + 0xc)) {
                *(f32*)(p + 0x2c4) = upper;
            } else {
                *(f32*)(p + 0x2c4) = lower;
            }
            switch (*(s32*)(p + 0x248)) {
            case 0xd:
                if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                    *(s32*)(p + 0x98) = 0;
                } else {
                    *(s32*)(p + 0x98) = 1;
                }
                if (*(f32*)(p + 0x14) >= 30.0f) {
                    *(f32*)(p + 0x14) = 30.0f;
                    fn_801E1594(this_, 1);
                } else {
                    fn_801E1594(this_, 4);
                }
                break;
            case 7: {
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                fn_801E1594(this_, 5);
                break;
            }
            default: {
                f32 cur = *(f32*)(p + 0x2c4);
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 5);
                } else {
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                }
                break;
            }
            }
        }
        }break;
    }
    }
    fn_801E2D88(this_);
}
#pragma opt_propagation reset
extern "C" void fn_801DF9D8(void* this_, void* obj) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x24c) < *(s32*)(p + 0x250)) {
        return;
    }
    if (*(u32*)(p + 0x230) & 0x20000) {
        *(s32*)(p + 0x2a8) = -1;
        if (!(*(u32*)(p + 0x230) & 0x2000)) {
            *(s32*)(p + 0x2a8) = -1;
        }
        if (*(s32*)(p + 0x2a8) >= 0) {
            *(u32*)(p + 0x230) |= 0x2000;
            {
                f32 v = ((f32*)fn_8023E724(*(s32*)(p + 0x2a8)))[0];
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (v < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < v) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 6);
                } else {
                    fn_801E1594(this_, 1);
                }
            }
        } else {
            *(u32*)(p + 0x230) |= 0x4000;
            *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
            {
                f32 lower;
                f32 upper;
                f32 pos;
                char* field=thnkFieldAt(*(s32*)(p+4));
                upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
                s32 room2;
                u8 flag = 0;
                pos = *(f32*)(p + 0xc);
                lower = *(f32*)field - lbl_8053F4A4;
                room2 = *(s32*)(p + 4);
                char* rec = (char*)fn_802D6A9C();
                field = (room2 < 8) ? rec + 0xcc : rec + 0xdc;
                if (pos < lbl_8053F4A8 * (*(f32*)field + *(f32*)(field + 0x8))) {
                    flag = 1;
                }
                if (flag && lower < *(f32*)(p + 0xc)) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                switch (*(s32*)(p + 0x248)) {
                case 0xd:
                    if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                        *(s32*)(p + 0x98) = 0;
                    } else {
                        *(s32*)(p + 0x98) = 1;
                    }
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                    break;
                case 7: {
                    u8 hit = 0;
                    switch (*(s32*)(p + 0x98)) {
                    case 0:
                        if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                            hit = 1;
                        }
                        break;
                    case 1:
                        if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                            hit = 1;
                        }
                        break;
                    }
                    if (hit) {
                        *(f32*)(p + 0x2c4) = upper;
                    } else {
                        *(f32*)(p + 0x2c4) = lower;
                    }
                    fn_801E1594(this_, 5);
                    break;
                }
                default: {
                    f32 cur = *(f32*)(p + 0x2c4);
                    u8 hit = 0;
                    switch (*(s32*)(p + 0x98)) {
                    case 0:
                        if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                            hit = 1;
                        }
                        break;
                    case 1:
                        if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                            hit = 1;
                        }
                        break;
                    }
                    if (hit) {
                        fn_801E1594(this_, 5);
                    } else {
                        if (*(f32*)(p + 0x14) >= 30.0f) {
                            *(f32*)(p + 0x14) = 30.0f;
                            fn_801E1594(this_, 1);
                        } else {
                            fn_801E1594(this_, 4);
                        }
                    }
                    break;
                }
                }
            }
        }
    } else if (!(*(u32*)(p + 0x230) & 0x2000) && obj != 0) {
        {
            u8 hit = 0;
            *(volatile u32*)(p + 0x230) |= 0x2000;
            f32 v = *(f32*)((char*)obj + 0xc);
            switch (*(s32*)(p + 0x98)) {
            case 0:
                if (v < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                    hit = 1;
                }
                break;
            case 1:
                if (lbl_8053F4AC + *(f32*)(p + 0xc) < v) {
                    hit = 1;
                }
                break;
            }
            if (hit) {
                fn_801E1594(this_, 6);
            } else {
                fn_801E1594(this_, 1);
            }
        }
    } else {
        *(u32*)(p + 0x230) |= 0x4000;
        *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
        {
            u8 flag;
            s32 room;
            f32 pos;
            f32 lower;
            f32 upper;
            room = *(s32*)(p + 4);
            char* rec = (char*)fn_802D6A9C();
            char* field = (room < 8) ? rec + 0xcc : rec + 0xdc;
            flag = 0;
            upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
            pos = *(f32*)(p + 0xc);
            lower = *(f32*)field - lbl_8053F4A4;
            flag=thnkIsLeft(pos,*(s32*)(p+4));
            if (flag && lower < *(f32*)(p + 0xc)) {
                *(f32*)(p + 0x2c4) = upper;
            } else {
                *(f32*)(p + 0x2c4) = lower;
            }
            switch (*(s32*)(p + 0x248)) {
            case 0xd:
                if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                    *(s32*)(p + 0x98) = 0;
                } else {
                    *(s32*)(p + 0x98) = 1;
                }
                if (*(f32*)(p + 0x14) >= 30.0f) {
                    *(f32*)(p + 0x14) = 30.0f;
                    fn_801E1594(this_, 1);
                } else {
                    fn_801E1594(this_, 4);
                }
                break;
            case 7: {
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                fn_801E1594(this_, 5);
                break;
            }
            default: {
                f32 cur = *(f32*)(p + 0x2c4);
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 5);
                } else {
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                }
                break;
            }
            }
        }
    }
}

extern "C" s32 fn_801F732C(void* mgr, void* a, f32 f, void* p5, void* p6, s32 c);
extern f32 lbl_8053F4B4, lbl_8053F4B8, lbl_8053F498, lbl_8053F4A0;
extern "C" void fn_8020CF7C(void*);
extern "C" void fn_801E1AB4(void*, u8);


#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void fn_801E002C(void* this_, void* obj) {
    s32 period;
    s32 timer;
    u8 flag;
    s32 idx;
    void* found;
    char* p=(char*)this_;
    if(obj && *(s32*)(p+0x2ac)>=0) {
        period=*(s32*)(p+0x27c);
        timer=*(s32*)(p+0x24c);
        if(timer>=period*2) {
            if(!(*(u32*)(p+0x230)&0x20000) && fn_80218538(this_)) fn_801F0E34(this_,0x40070,0);
            if(!(*(volatile u32*)(p+0x230)&0x2000)) {
                *(s32*)(p+0x2b8)=*(s32*)(p+0x2ac);
                *(s32*)(p+0x2ac)=fn_801F750C(fn_801F856C(),*(void**)(p+4),*(s32*)(p+0x2b8));
                if(*(s32*)(p+0x2ac)>=0) {
                    *(s32*)(p+0x2b0)=-1;
                    *(s32*)(p+0x2b4)=-1;
                } else {
                    *(s32*)(p+0x2b0)=fn_801F7464(fn_801F856C(),*(void**)(p+4),-1);
                    if(*(s32*)(p+0x2b0)>=0) *(s32*)(p+0x2b4)=-1;
                    else *(s32*)(p+0x2b4)=fn_801F732C(fn_801F856C(),*(void**)(p+4),lbl_8053F4B4,p+0xc,p+0xc,*(s32*)(p+0x2b8));
                }
                found = 0;
idx=*(s32*)(p+0x2ac);
if(idx>=0) found=fn_801F666C(fn_801F856C(),idx);
if(!found) {
 idx=*(s32*)(p+0x2b0);
 if(idx>=0) found=fn_801F666C(fn_801F856C(),idx);
}
if(!found) {
 idx=*(s32*)(p+0x2b4);
 if(idx>=0) found=fn_801F666C(fn_801F856C(),idx);
}
                if(found) {
                    *(u32*)(p+0x230)|=0x2000;
                    f32 v=*(f32*)((char*)found+0xc);
                    u8 hit=0;
                    switch(*(s32*)(p+0x98)) {
                    case 0: if(v<*(f32*)(p+0xc)-lbl_8053F4AC)hit=1;break;
                    case 1: if(lbl_8053F4AC+*(f32*)(p+0xc)<v)hit=1;break;
                    }
                    if(hit)fn_801E1594(this_,6);else fn_801E1594(this_,1);
                } else {
                                *(u32*)(p + 0x230) |= 0x4000;
            *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
            {
                f32 lower;
                f32 upper;
                f32 pos;
                char* field=thnkFieldAt(*(s32*)(p+4));
                upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
                s32 room2;
                u8 flag = 0;
                pos = *(f32*)(p + 0xc);
                lower = *(f32*)field - lbl_8053F4A4;
                room2 = *(s32*)(p + 4);
                char* rec = (char*)fn_802D6A9C();
                field = (room2 < 8) ? rec + 0xcc : rec + 0xdc;
                if (pos < lbl_8053F4A8 * (*(f32*)field + *(f32*)(field + 0x8))) {
                    flag = 1;
                }
                if (flag && lower < *(f32*)(p + 0xc)) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                switch (*(s32*)(p + 0x248)) {
                case 0xd:
                    if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                        *(s32*)(p + 0x98) = 0;
                    } else {
                        *(s32*)(p + 0x98) = 1;
                    }
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                    break;
                case 7: {
                    u8 hit = 0;
                    switch (*(s32*)(p + 0x98)) {
                    case 0:
                        if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                            hit = 1;
                        }
                        break;
                    case 1:
                        if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                            hit = 1;
                        }
                        break;
                    }
                    if (hit) {
                        *(f32*)(p + 0x2c4) = upper;
                    } else {
                        *(f32*)(p + 0x2c4) = lower;
                    }
                    fn_801E1594(this_, 5);
                    break;
                }
                default: {
                    f32 cur = *(f32*)(p + 0x2c4);
                    u8 hit = 0;
                    switch (*(s32*)(p + 0x98)) {
                    case 0:
                        if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                            hit = 1;
                        }
                        break;
                    case 1:
                        if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                            hit = 1;
                        }
                        break;
                    }
                    if (hit) {
                        fn_801E1594(this_, 5);
                    } else {
                        if (*(f32*)(p + 0x14) >= 30.0f) {
                            *(f32*)(p + 0x14) = 30.0f;
                            fn_801E1594(this_, 1);
                        } else {
                            fn_801E1594(this_, 4);
                        }
                    }
                    break;
                }
                }
            }
                }
            } else {
                        *(u32*)(p + 0x230) |= 0x4000;
        *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
        {
            u8 flag;
            s32 room;
            f32 pos;
            f32 lower;
            f32 upper;
            room = *(s32*)(p + 4);
            char* rec = (char*)fn_802D6A9C();
            char* field = (room < 8) ? rec + 0xcc : rec + 0xdc;
            flag = 0;
            upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
            pos = *(f32*)(p + 0xc);
            lower = *(f32*)field - lbl_8053F4A4;
            flag=thnkIsLeft(pos,*(s32*)(p+4));
            if (flag && lower < *(f32*)(p + 0xc)) {
                *(f32*)(p + 0x2c4) = upper;
            } else {
                *(f32*)(p + 0x2c4) = lower;
            }
            switch (*(s32*)(p + 0x248)) {
            case 0xd:
                if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                    *(s32*)(p + 0x98) = 0;
                } else {
                    *(s32*)(p + 0x98) = 1;
                }
                if (*(f32*)(p + 0x14) >= 30.0f) {
                    *(f32*)(p + 0x14) = 30.0f;
                    fn_801E1594(this_, 1);
                } else {
                    fn_801E1594(this_, 4);
                }
                break;
            case 7: {
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                fn_801E1594(this_, 5);
                break;
            }
            default: {
                f32 cur = *(f32*)(p + 0x2c4);
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 5);
                } else {
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                }
                break;
            }
            }
        }
            }
        } else {
            timer-=13;
            if(timer>=0 && timer%period==0)fn_8020CF7C(this_);
        }
    } else {
        flag=0;
        found = (void*)flag;
idx=*(s32*)(p+0x2ac);
if(idx>=0) found=fn_801F666C(fn_801F856C(),idx);
if(!found) {
 idx=*(s32*)(p+0x2b0);
 if(idx>=0) found=fn_801F666C(fn_801F856C(),idx);
}
if(!found) {
 idx=*(s32*)(p+0x2b4);
 if(idx>=0) found=fn_801F666C(fn_801F856C(),idx);
}
        if(*(s32*)(p+0x248)==3 && found && *(s32*)(p+0x2ac)==-1 &&
           __fabsf(*(f32*)((char*)found+0xc)-*(f32*)(p+0xc))<lbl_8053F4B8 &&
           __fabsf(*(f32*)((char*)found+0x10)-*(f32*)(p+0x10))<lbl_8053F4B8) {
            f32 height=lbl_8053F498;
            if(*(u32*)(p+0x230)&0x20000)height=lbl_8053F4A0;
            else {
                idx=*(s32*)(p+0x2ac);
                if(idx>=0 && fn_801F666C(fn_801F856C(),idx))height=lbl_8053F4A0;
                else {
                    idx=*(s32*)(p+0x2b0);
                    if(idx>=0 && fn_801F666C(fn_801F856C(),idx))height=lbl_8053F4A0;
                }
            }
            if(__fabsf(height-*(f32*)(p+0x14))<lbl_8053F488)flag=1;
        }
        if(flag) {
            if((fn_801CCF7C()&0xff)==0)fn_801F0E34(this_,0x50019,0);
            fn_801E1AB4(this_,0);
                    *(u32*)(p + 0x230) |= 0x4000;
        *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
        {
            
            s32 room;
            f32 pos;
            f32 lower;
            f32 upper;
            room = *(s32*)(p + 4);
            char* rec = (char*)fn_802D6A9C();
            char* field = (room < 8) ? rec + 0xcc : rec + 0xdc;
            flag = 0;
            upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
            pos = *(f32*)(p + 0xc);
            lower = *(f32*)field - lbl_8053F4A4;
            idx=*(s32*)(p+4);
              rec=(char*)fn_802D6A9C();
              field=(idx<8)?rec+0xcc:rec+0xdc;
              if(pos < lbl_8053F4A8 * (*(f32*)field + *(f32*)(field+8))) flag=1;
            if (flag && lower < *(f32*)(p + 0xc)) {
                *(f32*)(p + 0x2c4) = upper;
            } else {
                *(f32*)(p + 0x2c4) = lower;
            }
            switch (*(s32*)(p + 0x248)) {
            case 0xd:
                if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                    *(s32*)(p + 0x98) = 0;
                } else {
                    *(s32*)(p + 0x98) = 1;
                }
                if (*(f32*)(p + 0x14) >= 30.0f) {
                    *(f32*)(p + 0x14) = 30.0f;
                    fn_801E1594(this_, 1);
                } else {
                    fn_801E1594(this_, 4);
                }
                break;
            case 7: {
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                fn_801E1594(this_, 5);
                break;
            }
            default: {
                f32 cur = *(f32*)(p + 0x2c4);
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 5);
                } else {
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                }
                break;
            }
            }
        }
        } else if(*(s32*)(p+0x24c)>=180) {
                    *(u32*)(p + 0x230) |= 0x4000;
        *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
        {
            
            s32 room;
            f32 pos;
            f32 lower;
            f32 upper;
            room = *(s32*)(p + 4);
            char* rec = (char*)fn_802D6A9C();
            char* field = (room < 8) ? rec + 0xcc : rec + 0xdc;
            flag = 0;
            upper = lbl_8053F4A4 + *(f32*)(field + 0x8);
            pos = *(f32*)(p + 0xc);
            lower = *(f32*)field - lbl_8053F4A4;
            idx=*(s32*)(p+4);
              rec=(char*)fn_802D6A9C();
              field=(idx<8)?rec+0xcc:rec+0xdc;
              if(pos < lbl_8053F4A8 * (*(f32*)field + *(f32*)(field+8))) flag=1;
            if (flag && lower < *(f32*)(p + 0xc)) {
                *(f32*)(p + 0x2c4) = upper;
            } else {
                *(f32*)(p + 0x2c4) = lower;
            }
            switch (*(s32*)(p + 0x248)) {
            case 0xd:
                if (*(f32*)(p + 0xc) < *(f32*)(p + 0x2c4)) {
                    *(s32*)(p + 0x98) = 0;
                } else {
                    *(s32*)(p + 0x98) = 1;
                }
                if (*(f32*)(p + 0x14) >= 30.0f) {
                    *(f32*)(p + 0x14) = 30.0f;
                    fn_801E1594(this_, 1);
                } else {
                    fn_801E1594(this_, 4);
                }
                break;
            case 7: {
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (upper < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < upper) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    *(f32*)(p + 0x2c4) = upper;
                } else {
                    *(f32*)(p + 0x2c4) = lower;
                }
                fn_801E1594(this_, 5);
                break;
            }
            default: {
                f32 cur = *(f32*)(p + 0x2c4);
                u8 hit = 0;
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    if (cur < *(f32*)(p + 0xc) - lbl_8053F4AC) {
                        hit = 1;
                    }
                    break;
                case 1:
                    if (lbl_8053F4AC + *(f32*)(p + 0xc) < cur) {
                        hit = 1;
                    }
                    break;
                }
                if (hit) {
                    fn_801E1594(this_, 5);
                } else {
                    if (*(f32*)(p + 0x14) >= 30.0f) {
                        *(f32*)(p + 0x14) = 30.0f;
                        fn_801E1594(this_, 1);
                    } else {
                        fn_801E1594(this_, 4);
                    }
                }
                break;
            }
            }
        }
        }
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
static inline s32 thnkCollectRooms(s32* rooms) {
    s32 count=0;
    s32 room;
    for(s32 i=count;i<4;++i) {
        room=fn_8023DE58(i);
        if(fn_801CD2F8(room) && room!=8 && !fn_801E3250(room,0)) {
            if(fn_801F750C(fn_801F856C(),(void*)room,-1)>=0 ||
               fn_801F7464(fn_801F856C(),(void*)room,-1)>=0) {
                *rooms++=room;
                ++count;
            }
        }
    }
    return count;
}
static inline void thnkStoreTurn(char* p, f32 x, u8& hit) {
    hit=0;
    switch(*(s32*)(p+0x98)) {
    case 0:
        if(x<*(f32*)(p+0xc)-lbl_8053F4AC) hit=1;
        break;
    case 1:
        if(lbl_8053F4AC+*(f32*)(p+0xc)<x) hit=1;
        break;
    }
}
static inline u8 thnkResetCached(char* p, s32 state, u32 flags, u32 active) {
    u8 hit=0;
    switch(state) {
    case 0: case 7: case 0xf: case 0x10: case 0x11: case 0x12: break;
    default:
        if(!(flags&0x4000) && *(u16*)(p+0x2cc)==0 && thnk_isIdleSub(p)) {
            if(active) {
                if(flags&0x100000) hit=1;
            } else if(*(s32*)(p+0x2bc)<0) hit=1;
        }
    }
    return hit;
}
extern "C" void fn_801E0CF4(char* this_) {
    s32 id;
    s32 i;
    char* p = this_;
    s32 n;
    s32 found[4];
    s32* piVar;
    s32 st;
    s32 st98;
    s32 st278;
    u32 flags;
    u8 b2;
    u8 b3;
    s32 idx;
    char* obj;
    f32* pf;

    if (*(s32*)(p + 0x248) == 0) {
        *(s32*)(p + 0x2a8) = -1;
        if (*(s32*)(p + 0x2a8) >= 0) {
            *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0x2a8));
        } else {
            n=thnkCollectRooms(found);
            if (n == 0) {
                *(s32*)(p + 4) = 0;
            } else {
                *(s32*)(p + 4) = found[fn_801CD664(n)];
            }
        }
    } else {
        if ((*(u32*)(p + 0x230) & 0x4000) != 0 &&
            __fabsf(*(f32*)(p + 0x2c4) - *(f32*)(p + 0xc)) < lbl_8053F488 &&
            __fabsf(*(f32*)(p + 0x2c8) - *(f32*)(p + 0x10)) < lbl_8053F488) {
            fn_801E1594(p, 0);
            return;
        }
        if (fn_801CD2F8(*(s32*)(p + 4)) && fn_801CD290(*(s32*)(p + 4)) == 0) {
            fn_801E1594(p, 0);
            return;
        }
        if ((*(volatile u32*)(p + 0x230) & 0x10000) != 0) {
            *(u32*)(p + 0x230) &= 0xfffeffff;
            st = *(s32*)(p + 0x248);
            switch (st) {
            case 5: case 6: {
                *(s32*)(p + 0x98) = fn_801CD354(*(s32*)(p + 0x98));
                *(s32*)(p + 0x2d0) = -1;
            } }
            fn_801E1594(p, 8);
        } else {
            st278 = *(s32*)(p + 0x278);
            switch(st278) {case 0xd: case 0xe:
            if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 2, 0);
            } }
        }

        flags=*(u32*)(p+0x230);
        u32 active=flags&0x20000;
        if (active) {
            st=*(s32*)(p+0x248);
            switch(st) {
            case 1: case 6:
                if(*(s32*)(p+0x2a8)>=0 && *(s32*)(p+0x2a8)!=-1) {
                    if(thnkResetCached(p,st,flags,active)) {
                        *(s32*)(p+0x2a8)=-1;
                        fn_801E1594(p,7);
                    }
                }
                break;
            case 0xf: case 0x10: case 0x11:
                fn_8022FE80(*(s32*)(p+0x2a8),*(s32*)(p+4),*(s32*)(p+0x198),0,0);
                break;
            }
        }

        fn_8021FDB8(p);
        b3=0;
        switch(*(s32*)(p+0x248)) {
        case 0: case 5: case 6: case 7:
        case 0xf: case 0x10: case 0x11: case 0x12:
            goto after_B;
        }
        st278=*(s32*)(p+0x278);
        b2=thnk_isIdleSub(p);
        if(!b2) goto after_B;
        u8 isTwo=0;
        switch(st278) { case 2: isTwo=1; }
        if(!isTwo) {
            flags = *(u32*)(p + 0x230);
            if ((flags & 0x4000) != 0) {
                thnkStoreTurn(p,*(f32*)(p+0x2c4),b3);
            } else if ((flags & 0x20000) != 0) {
                if (*(s32*)(p + 0x2a8) >= 0 && *(s32*)(p + 0x2a8) == -1) {
                    pf = (f32*)fn_8023E724(*(s32*)(p + 0x2a8));
                    thnkStoreTurn(p,*pf,b3);
                }
            } else {
                idx = *(s32*)(p + 0x2ac);
                obj = 0;
                if (idx >= 0) {
                    obj = (char*)fn_801F666C(fn_801F856C(), idx);
                }
                if (obj == 0) {
                    idx=*(s32*)(p+0x2b0);
                    if(idx>=0) obj=(char*)fn_801F666C(fn_801F856C(),idx);
                }
                if (obj == 0) {
                    idx=*(s32*)(p+0x2b4);
                    if(idx>=0) obj=(char*)fn_801F666C(fn_801F856C(),idx);
                }
                if (obj != 0) {
                    thnkStoreTurn(p,*(f32*)(obj+0xc),b3);
                }
            }
            if (b3) {
                *(s32*)(p + 0x2d0) = *(s32*)(p + 0x248);
                fn_801E1594(p, 6);
            }
        }
after_B:
        b3=0;
        switch(*(s32*)(p+0x248)) { case 0xb: case 0xc: b3=1; }
        if (b3) {
            if (fn_801E2F40(p)) {
                fn_801E1594(p, 0xe);
            } else {
                fn_801E2EE4(p);
            }
        }
    }

    if (*(s32*)(p + 0x2a8) == -1 && (*(u32*)(p + 0x230) & 0x20000) == 0) {
        fn_801E1300(p);
    }
}

extern "C" void fn_801E1594(void* this_, s32 state);
extern "C" s32 fn_801F750C(void* mgr, void* a, s32 b);
extern "C" s32 fn_801F7464(void* mgr, void* a, s32 b);
extern "C" s32 fn_801F732C(void* mgr, void* a, f32 f, void* p5, void* p6, s32 c);
extern "C" u8 fn_801CC910(void* obj);
extern "C" u8 fn_801CC960(void* obj);
extern "C" u8 fn_801CC9B0(void* obj);
extern f32 lbl_8053F4B4;
extern "C" void fn_801E1300(void* this_) {
    char* p = (char*)this_;
    u8 flag = 0;
    s32 idx;
    void* obj;

    idx = *(s32*)(p + 0x2ac);
    if (idx >= 0) {
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0 || fn_801CC910(obj) == 0) {
            flag = 1;
        }
    } else if ((idx = *(s32*)(p + 0x2b0)) >= 0) {
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0 || fn_801CC960(obj) == 0) {
            flag = 1;
        }
    } else if ((idx = *(s32*)(p + 0x2b4)) >= 0) {
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0 || fn_801CC9B0(obj) == 0) {
            flag = 1;
        }
    } else {
        *(s32*)(p + 0x2ac) = fn_801F750C(fn_801F856C(), *(void**)(p + 4), *(s32*)(p + 0x2b8));
        if (*(s32*)(p + 0x2ac) >= 0) {
            *(s32*)(p + 0x2b0) = -1;
            *(s32*)(p + 0x2b4) = -1;
        } else {
            *(s32*)(p + 0x2b0) = fn_801F7464(fn_801F856C(), *(void**)(p + 4), -1);
            if (*(s32*)(p + 0x2b0) >= 0) {
                *(s32*)(p + 0x2b4) = -1;
            } else {
                *(s32*)(p + 0x2b4) = fn_801F732C(fn_801F856C(), *(void**)(p + 4), lbl_8053F4B4, p + 0xc, p + 0xc, *(s32*)(p + 0x2b8));
            }
        }
    }
    if (flag == 0) {
        return;
    }
    *(s32*)(p + 0x2ac) = fn_801F750C(fn_801F856C(), *(void**)(p + 4), *(s32*)(p + 0x2b8));
    if (*(s32*)(p + 0x2ac) >= 0) {
        *(s32*)(p + 0x2b0) = -1;
        *(s32*)(p + 0x2b4) = -1;
    } else {
        *(s32*)(p + 0x2b0) = fn_801F7464(fn_801F856C(), *(void**)(p + 4), -1);
        if (*(s32*)(p + 0x2b0) >= 0) {
            *(s32*)(p + 0x2b4) = -1;
        } else {
            *(s32*)(p + 0x2b4) = fn_801F732C(fn_801F856C(), *(void**)(p + 4), lbl_8053F4B4, p + 0xc, p + 0xc, *(s32*)(p + 0x2b8));
        }
    }
    if (thnkShouldReset(this_)) fn_801E1594(this_, 7);
}

extern "C" void fn_801E1594(void* this_, s32 state) {
    u8 flag;
    char* field;
    char* rec;
    void* obj;
    s32 idx;
    char* p = (char*)this_;
    switch (state) {
    case 0:
        fn_801E1E08(this_);
        break;
    case 1:
    case 2:
    case 4:
        if (*(s32*)(p + 0x248) == 0 && state == 1) {
            f32 y;
            f32 x;
            if (*(u32*)(p + 0x230) & 0x20000) {
                x = ((f32*)fn_8023E724(*(s32*)(p + 0x2a8)))[0];
                y = ((f32*)fn_8023E724(*(s32*)(p + 0x2a8)))[1];
            } else {
                obj = 0;
                idx = *(s32*)(p + 0x2ac);
                if (idx >= 0) {
                    obj = fn_801F666C(fn_801F856C(), idx);
                }
                if (obj == 0) {
                    idx = *(s32*)(p + 0x2b0);
                    if (idx >= 0) {
                        obj = fn_801F666C(fn_801F856C(), idx);
                    }
                }
                if (obj == 0) {
                    idx = *(s32*)(p + 0x2b4);
                    if (idx >= 0) {
                        obj = fn_801F666C(fn_801F856C(), idx);
                    }
                }
                x = *(f32*)((char*)obj + 0xc);
                y = *(f32*)((char*)obj + 0x10);
            }
            flag = thnkIsLeft(x, *(s32*)(p + 4));
            if (flag != 0) {
                field = thnkFieldAt(*(s32*)(p + 4));
                *(f32*)(p + 0xc) = 30.0f + *(f32*)(field + 0x8);
                *(s32*)(p + 0x98) = 1;
            } else {
                field = thnkFieldAt(*(s32*)(p + 4));
                *(f32*)(p + 0xc) = *(f32*)field - 30.0f;
                *(s32*)(p + 0x98) = 0;
            }
            *(f32*)(p + 0x10) = y;
            *(f32*)(p + 0x14) = 30.0f;
            f32 px = *(f32*)(p + 0xc);
            f32 py = *(f32*)(p + 0x10);
            *(f32*)(p + 0x2c4) = px;
            *(f32*)(p + 0x2c8) = py;
            *(s32*)(p + 0xb0) = 0x51303;
        }
        *(s32*)(p + 0x250) = -1;
            if (*(s32*)(p + 0x2bc) >= 0) {
                *(f32*)(p + 0x258) = lbl_8053F490;
            } else if (*(u32*)(p + 0x230) & 0x4000) {
                *(f32*)(p + 0x258) = lbl_8053F490;
            } else {
                *(f32*)(p + 0x258) = 0.6f;
            }
            if (*(s32*)(p + 0x248) == 0xd) {
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 0xd, 0, 0);
            } else {
                fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 2);
            }
        break;
    case 3:
            *(s32*)(p + 0x250) = -1;
            *(f32*)(p + 0x258) = 0.6f;
            if (*(s32*)(p + 0x2ac) >= 0) {
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 0xf, 2, 0);
            } else {
                fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 2);
            }
        break;
    case 5:
    case 6:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, 2, 0, 0);
        break;
    case 7:
        *(s32*)(p + 0x250) = fn_801CD664(1) + 0x5a;
        *(f32*)(p + 0x254) = 0.0f;
        *(f32*)(p + 0x258) = 0.0f;
        *(u16*)(p + 0x2ce) = 0x2d;
        fn_8020D2AC(this_);
        if (!(*(u32*)(p + 0x230) & 0x20000) && fn_80218538(this_)) {
            fn_801F0E34(this_, 0x40070, 0);
        }
        break;
    case 8:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 3, 0, 0);
        break;
    case 9:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, 5, 0, 0);
        break;
    case 10:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, 6, 0, 0);
        break;
    case 11:
        fn_8020D16C(this_);
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, 7, 0, 0);
        break;
    case 12:
        *(s32*)(p + 0x98) = 2;
        *(s32*)(p + 0x250) = fn_801CD664(0x259) + 0x12c;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 8, 0, 0);
        break;
    case 13:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, 0xc, 0, 0);
        break;
    case 14:
        fn_8020CFC4(this_);
        *(f32*)(p + 0x40) = 0.0f;
        *(f32*)(p + 0x3c) = 0.0f;
        *(f32*)(p + 0x60) = 1.0f;
        *(f32*)(p + 0x64) = 1.0f;
        *(f32*)(p + 0x68) = -1.0f;
        *(f32*)(p + 0x6c) = -1.0f;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(s32*)(p + 0xb0) = 0;
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x254) = 0.0f;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22DC(p + 0x270, 6, 0, 0);
        break;
    case 15:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x254) = 0.0f;
        *(f32*)(p + 0x258) = 0.0f;
        fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 2);
        break;
    case 16:
        fn_801F0E34(this_, 0x5001d, 0);
        break;
    case 17:
    case 18:
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}

extern "C" void* fn_801F856C(void);
extern "C" void detach__5ActorFv(void* this_);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" s32 fn_8032D564(void* obj, u32 arg);
extern "C" void fn_8021FDB8(void* this_);
extern "C" void fn_801E1AB4(void* this_, u8 flag) {
    u8* p = (u8*)this_;
    u8 bVar1 = 0;
    f32 pos[3];
    u32 uVar5;
    if (flag != 0) {
        pos[0] = *(f32*)(p + 0xc);
        pos[1] = *(f32*)(p + 0x10);
        pos[2] = *(f32*)(p + 0x14);
        uVar5 = 2;
        bVar1 = 1;
    } else {
        u8* obj = 0;
        s32 idx = *(s32*)(p + 0x2ac);
        if (idx >= 0 && (obj = (u8*)fn_801F666C(fn_801F856C(), idx)) != 0) {
        } else {
            idx = *(s32*)(p + 0x2b0);
            if (idx >= 0 && (obj = (u8*)fn_801F666C(fn_801F856C(), idx)) != 0) {
            } else {
                idx = *(s32*)(p + 0x2b4);
                if (idx >= 0) {
                    obj = (u8*)fn_801F666C(fn_801F856C(), idx);
                }
            }
        }
        pos[0] = *(f32*)(obj + 0xc);
        pos[1] = *(f32*)(obj + 0x10);
        pos[2] = *(f32*)(obj + 0x14);
        s32 state = *(s32*)(obj + 0x230);
        uVar5 = *(u32*)(obj + 0x90);
        if (state == 0 || (u32)(state - 0xf) <= 1 || (u32)(state - 1) <= 1 || state == 9 || state == 0xd) {
            detach__5ActorFv(obj);
        }
        if (*(u8*)(obj + 0x11c) == 0) {
            bVar1 = 1;
        }
    }
    if (bVar1) {
        *(u32*)(p + 0x230) &= 0xffff7fff;
        *(s32*)(p + 0x2bc) = Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(p + 4), pos, (uVar5 & 0xffff) | 0x10000, -1, -1);
        if (*(s32*)(p + 0x2bc) >= 0) {
            if (flag == 0 && *(s32*)(p + 0x2b0) >= 0) {
                *(u32*)(p + 0x230) |= 0x8000;
            }
            u8* obj = (u8*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x2bc));
            if (obj != 0) {
                obj[0x194] = 1;
                *(s32*)(p + 0x2c0) = fn_8032D564(obj, *(u32*)(obj + 0x90) & 0xff);
                if (flag != 0) {
                    fn_8021FDB8(this_);
                    f32 one = 1.0f;
                    f32 negOne = -1.0f;
                    *(f32*)(obj + 0x60) = one;
                    *(f32*)(obj + 0x64) = one;
                    *(f32*)(obj + 0x68) = negOne;
                    *(f32*)(obj + 0x6c) = negOne;
                    *(f32*)(obj + 0x70) = one;
                    *(f32*)(obj + 0x74) = one;
                    *(f32*)(obj + 0x78) = negOne;
                    *(f32*)(obj + 0x7c) = negOne;
                }
            }
        }
        *(s32*)(p + 0x2ac) = -1;
        *(s32*)(p + 0x2b0) = -1;
        *(s32*)(p + 0x2b4) = -1;
    }
}

extern "C" bool fn_801E1D7C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x248);
	return v < 0xd && v >= 0xb;
}

extern "C" bool fn_801E1D9C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x278);
	bool result = false;
	if (v == 2) { result = true; }
	return result;
}

extern "C" u8 fn_801E1CF8(void* this_) {
    char* p = (char*)this_;
    u8 r = 0;
    switch (*(s32*)(p + 0x248)) {
    case 0:
    case 0xf: case 0x10: case 0x11: case 0x12:
        break;
    default:
        if (!(*(u32*)(p + 0x230) & 0x80000) && *(u16*)(p + 0x2cc) == 0 && thnk_isIdleSub(this_)) {
            r = 1;
        }
    }
    return r;
}

extern "C" u8 fn_801E1DB4(void* this_) {
    return thnk_isIdleSub(this_);
}

extern "C" s32 fn_801CD664(s32 kind);

extern "C" s32 fn_801E1DE8(void* this_) {
    return fn_801CCF7C();
}

extern "C" void fn_801E1E08(void* this_) {
    extern u8 lbl_8050EC80[];
    extern f32 lbl_8053F4A4;
    extern f32 lbl_8053F4C0;
    extern f32 lbl_8053F4C4;
    extern f32 lbl_8053F4C8;
    extern f32 lbl_8053F480;
    char* p = (char*)this_;
    if (*(s32*)(p + 0x2bc) >= 0) {
        if ((*(volatile u32*)(p + 0x230) & 0x80000) == 0) {
            *(u32*)(p + 0x230) |= 0x40000;
        }
        if (*(s32*)(p + 0x2bc) >= 0) {
            s32 n = *(s32*)(p + 0x2c0);
            if (n > 0) {
                if ((*(u32*)(p + 0x230) & 0x80000) == 0) {
                    char* base = (char*)lbl_8050EC80;
                    char* e = base + *(s32*)(base + 0x10) * 200;
                    *(s32*)(e + 0x2c) += n;
                    e = base + *(s32*)(base + 0x10) * 200;
                    if (*(s32*)(e + 0x2c) < 0) {
                        *(s32*)(e + 0x2c) = 0;
                    }
                }
                *(s32*)(p + 0x2c0) = 0;
            }
            void* tmp = fn_801F856C();
            void* obj = fn_801F666C(tmp, *(s32*)(p + 0x2bc));
            if (obj != 0) {
                *(u8*)((char*)obj + 0x11c) = 0;
            }
            *(s32*)(p + 0x2bc) = -1;
        }
    }
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x98) = 0;
    s32 kind = *(volatile s32*)(p + 0x4);
    char* record = (char*)fn_802D6A9C();
    char* field = (kind < 8) ? (record + 0xcc) : (record + 0xdc);
    *(f32*)(p + 0xc) = *(f32*)field - lbl_8053F4A4;
    kind = *(s32*)(p + 0x4);
    record = (char*)fn_802D6A9C();
    field = (kind < 8) ? (record + 0xcc) : (record + 0xdc);
    f32 zero = lbl_8053F4A4;
    f32 sum = lbl_8053F4C8 + *(f32*)(field + 4);
    f32 one = lbl_8053F4C0;
    f32 negOne = lbl_8053F4C4;
    *(f32*)(p + 0x10) = sum;
    *(f32*)(p + 0x14) = zero;
    *(f32*)(p + 0x54) = one;
    *(f32*)(p + 0x58) = one;
    *(f32*)(p + 0x5c) = one;
    *(f32*)(p + 0x60) = one;
    *(f32*)(p + 0x64) = one;
    *(f32*)(p + 0x68) = negOne;
    *(f32*)(p + 0x6c) = negOne;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(s32*)(p + 0xb0) = 0;
    *(u32*)(p + 0x230) &= 0xff841fff;
    *(s32*)(p + 0x2a8) = -1;
    *(s32*)(p + 0x2ac) = -1;
    *(s32*)(p + 0x2b0) = -1;
    *(s32*)(p + 0x2b4) = -1;
    *(s32*)(p + 0x2bc) = -1;
    *(s32*)(p + 0x2c0) = 0;
    *(s16*)(p + 0x2cc) = fn_801CD664(0x79) + 0xb4;
    f32 zero2 = lbl_8053F480;
    *(s16*)(p + 0x2ce) = 0;
    *(s32*)(p + 0x2d0) = -1;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = zero2;
    *(f32*)(p + 0x258) = zero2;
}

extern "C" void fn_801E2004(void* this_) {
    char* p = (char*)this_;
    void* base = fn_801F856C();
    fn_801F7AB8(base, *(s32*)(p + 0x1a0), *(s32*)(p + 0x198));
    s32 kind = *(s32*)(p + 0x4);
    char* record = (char*)fn_802D6A9C();
    char* field = (kind < 8) ? (record + 0xcc) : (record + 0xdc);
    *(f32*)(p + 0xc) = *(f32*)field - lbl_8053F4A4;
    f32 v1 = *(f32*)(p + 0x10);
    f32 v0 = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2c4) = v0;
    *(f32*)(p + 0x2c8) = v1;
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 kind);
extern "C" void fn_801D2608(void* p, void* data, s32 n);
extern f32 lbl_8053F4C0;
extern f32 lbl_8053F4C4;
extern char lbl_804A51A0[];
extern "C" void fn_801E2080(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(this_);
    ((JGeometry::TBox2f*)(p + 0x80))->set(1.0f, 1.0f, -1.0f, -1.0f);
    ((JGeometry::TBox2f*)(p + 0x60))->set(1.0f, 1.0f, -1.0f, -1.0f);
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(s32*)(p + 0xb0) = 0;
    *(s32*)(p + 0x98) = 0;
    *(u32*)(p + 0x230) |= 0x300;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(u8*)(p + 0x194) = 1;
    *(s32*)(p + 0x4) = 0;
    *(s16*)(p + 0x2cc) = fn_801CD664(0x3d) + 0x3c;
    *(s32*)(p + 0x248) = 0;
    f32 zero = 0.0f;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = zero;
    *(f32*)(p + 0x258) = zero;
    fn_801D2608(p + 0x270, lbl_804A51A0, 0x11);
    fn_801D22DC(p + 0x270, 0, 2, 0);
}

extern "C" void* fn_801E2180(void* this_, s16 freeFlag) {
    extern u8 lbl_8050EC80[];
    char* p = (char*)this_;
    if (this_ != 0) {
        *(void**)p = lbl_804A51E4;
        if (*(s32*)(p + 0x2bc) >= 0) {
            s32 n = *(s32*)(p + 0x2c0);
            if (n > 0) {
                if ((*(u32*)(p + 0x230) & 0x80000) == 0) {
                    char* e = (char*)lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200;
                    *(s32*)(e + 0x2c) += n;
                    e = (char*)lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200;
                    if (*(s32*)(e + 0x2c) < 0) {
                        *(s32*)(e + 0x2c) = 0;
                    }
                }
                *(s32*)(p + 0x2c0) = 0;
            }
            void* tmp = fn_801F856C();
            void* obj = fn_801F666C(tmp, *(s32*)(p + 0x2bc));
            if (obj != 0) {
                *(u8*)((char*)obj + 0x11c) = 0;
            }
            *(s32*)(p + 0x2bc) = -1;
        }
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

extern "C" void* fn_801E22A4(void* this_) {
    char* p = (char*)this_;
    fn_801D0F40(this_);
    *(void**)p = lbl_804A51E4;
    *(s32*)(p + 0x2a8) = -1;
    *(s32*)(p + 0x2ac) = -1;
    *(s32*)(p + 0x2b0) = -1;
    *(s32*)(p + 0x2b4) = -1;
    *(s32*)(p + 0x2b8) = -1;
    *(s32*)(p + 0x2bc) = -1;
    *(s32*)(p + 0x2c0) = 0;
    *(f32*)(p + 0x2c4) = 0.0f;
    *(f32*)(p + 0x2c8) = 0.0f;
    *(u16*)(p + 0x2cc) = 0;
    *(u16*)(p + 0x2ce) = 0;
    *(s32*)(p + 0x2d0) = -1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
