// TU 0x802f032c-0x802f184c (actor SWDL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// ---- Swdl_EmptyHook.cpp ----
// Swdl_EmptyHook - SWDL: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Swdl_EmptyHook(void) {}

extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" void fn_8030C210(void* p, void* pos);
extern "C" s32 fn_80236228(s32 i);
extern "C" s32 fn_8023077C(void);
extern "C" void fn_80230498(s32 i, void* vec, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" void* fn_8013CC50(void* obj, void* vec, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_80134D14(void* p, s32 mode);
extern "C" u8 fn_801B7550(void);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void fn_8043D67C(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_80230F44(s32 a, s32 b);
extern "C" void fn_80236ED8(s32 a, s32 b);
extern "C" void fn_8045873C(void* p, s32 a);
extern "C" void fn_80128C58(s32 a);
extern "C" u8* lbl_8053AAF8;
extern "C" char* lbl_8053AB10;
extern "C" char* lbl_8053AEC8;
extern "C" void* lbl_8053AF80;
extern "C" void* lbl_8053AED0;
#pragma pool_data on
const u8 lbl_8046F628[] = {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2,0,0,0,1,0,0,0,1,0,0,0,2,0,0,0,2,0,0,0,100};
const s32 Swdl_frames[] = {0,1,2,3,4,5,6,7,8,9,10,1,3,5};
const s32 Swdl_rooms[] = {0,4,0,0,8,4,0,2,3,6,0,1,9,1,0,2,4,6,0,0,0,0,0,5,2,0,0,1,9,0,6,3};
const s32 Swdl_layers[] = {2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,7,0,0,0,1,0,1,0,0,0,3,3,0,1,3};
#pragma pool_data reset
extern "C" char lbl_80529DEC[];
extern "C" char lbl_8050EC80[];
extern "C" f32 lbl_80541438;
extern "C" f32 lbl_8054143C;
extern "C" char* fn_802D6A9C();
extern "C" void fn_802D9FF4(void*, s32, s32);
extern "C" void fn_802D6AAC(void*, s32);
extern "C" u8 fn_802DE7CC();
extern "C" u8 fn_80230534(s32);
extern "C" u8 fn_80388EEC(s32);
extern "C" void fn_8038BD08(s32, s32, s32, void*, s32);
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern "C" void fn_801EE434(void*);
extern "C" void fn_80230FD0(s32,s32);
extern "C" s32 fn_80237810(s32);
extern "C" void fn_80236554(s32,s32,s32);
extern "C" void* fn_80119DD0();
extern "C" void fn_80119468(void*,s32,s32);
extern "C" void fn_80136798(void*,s32,s32);
struct SwdlControlBase { u32 _0, _4; };
struct SwdlControl : SwdlControlBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void command(u32*);
};
static inline u32 Swdl_isPlayer(s32 i) {
    return (lbl_8053AAF8[0x82] & (u8)(1<<i)) != 0;
}
static inline s32 Swdl_isCleared() {
    s32 room=*(s32*)(lbl_80529DEC+0x118);
    s32 layer=*(s32*)(lbl_80529DEC+0x11c);
    if(room<0 || room>7) return 0;
    if(layer<0 || layer>3) return 0;
    return (*(u32*)(lbl_8050EC80 + 0x28 + 200**(s32*)(lbl_8050EC80+0x10)) & (1 << (room*4+layer))) != 0;
}

extern "C" void fn_802F0330(u8* p) {
    JGeometry::TVec3<f32> pos;
    s32 i;
    u8* q;
    if (*(s32*)(p+0x244)>=1) {
        for(i=0;i<4;++i) {
            pos=*fn_8023E724(i);
            fn_8030C210(*(void**)(lbl_8053AB10+0x24), &pos);
        }
    }
    switch(*(s32*)(p+0x244)) {
    case 0: {
        int total=0;
        for(i=0;i<4;++i) if(Swdl_isPlayer(i)==1) total+=fn_80236228(i);
        if(total<2000) break;
        if((u8)fn_8023077C()!=1) break;
        for(i=0;i<4;++i) {
            pos=*fn_8023E724(i);
            fn_80230498(i, &pos, 46, 255, 2, -128, 1);
        }
        *(s32*)(p+0x24c)=0;
        *(s32*)(p+0x250)=1;
        fn_80134D14(lbl_8053AAF8,2);
        *(s32*)(p+0x258)=fn_801B7550();
        *(s32*)(p+0x254)=*(s32*)(p+0x258)/30;
        if(*(s32*)(p+0x254)==0) *(s32*)(p+0x254)=1;
        *(s32*)(p+0x25c)=*(s32*)(p+0x258);
        *(s32*)(p+0x244)=1;
        u32 command=0x50076;
        ((SwdlControl*)*(void**)(p+0x230))->command(&command);
        fn_8045873C(lbl_8053AF80,1);
        if(lbl_8053AAF8[0x7e]==0 && (lbl_8053AAF8[0x83]&3U)==2 && fn_8023DE58(0)>=8) {
            *(s32*)(p+0x264)=1; *(s32*)(p+0x268)=1;
            *(s32*)(p+0x26c)=1; *(s32*)(p+0x270)=1;
        }
        break;
    }
    case 1:
        *(s32*)(p+0x25c)-=*(s32*)(p+0x254);
        if(*(s32*)(p+0x25c)<=0) {
            *(s32*)(p+0x25c)=0;
            if(*(s32*)(p+0x24c)==8) *(s32*)(p+0x244)=2;
        }
        lbl_8053AEC8[0x5c]=255-*(s32*)(p+0x25c);
        --*(s32*)(p+0x250);
        if(*(s32*)(p+0x250)==0) {
            ++*(s32*)(p+0x24c);
            *(s32*)(p+0x250)=((s32*)lbl_8046F628)[*(s32*)(p+0x24c)];
            for(i=0;i<4;++i) {
                pos=*fn_8023E724(i);
                if(*(s32*)(p+0x24c)<6) { fn_80230498(i, &pos, *(s32*)(p+0x24c)+0x2e, 255, 2, -128, 1); }
                else if(*(s32*)(p+0x24c)==8) {
                    fn_80230498(i, &pos, 953, 255, 2, -128, 1);
                    fn_8013CC50(*(void**)(p+4), &pos, lbl_80541438, 631, 2,3,0,0,1);
                    fn_8013CC50(*(void**)(p+4), &pos, lbl_80541438, 632, 2,3,0,0,1);
                    fn_8013CC50(*(void**)(p+4), &pos, lbl_80541438, 633, 2,3,0,0,1);
                    fn_8013CC50(*(void**)(p+4), &pos, lbl_80541438, 634, 2,3,0,0,1);
                    fn_8013CC50(*(void**)(p+4), &pos, lbl_80541438, 635, 2,3,0,0,1);
                    fn_8013CC50(*(void**)(p+4), &pos, lbl_80541438, 636, 2,3,0,0,1);
                    fn_8013CC50(*(void**)(p+4), &pos, lbl_80541438, 637, 2,3,0,0,1);
                } else { fn_80230498(i, &pos, *(s32*)(p+0x24c)+0x3ba, 255, 2, -128, 1); }
            }
        }
        break;
    case 2:
        --*(s32*)(p+0x250);
        if(*(s32*)(p+0x250)==0) { *(s32*)(p+0x244)=3; *(s32*)(p+0x250)=100; }
        break;
    case 3:
        --*(s32*)(p+0x250);
        if(*(s32*)(p+0x250)==0) { *(s32*)(p+0x250)=4; *(s32*)(p+0x244)=4; }
        for (i=0, q=p; i<4; ++i,q+=4) {
                pos=*fn_8023E724(i);
                if (fn_8023DE58(i)>=8) {
                    if (*(s32*)(p+0x250) & *(s32*)(q+0x264)) { fn_80230498(i, &pos, 954, 255, 2, -128, 1); }
                    else { fn_80230498(i, &pos, 955, 255, 2, -128, 1); }
                } else { fn_80230498(i, &pos, 954, 255, 2, -128, 1); }
            }
        break;
    case 4:
        --*(s32*)(p+0x250);
        if(*(s32*)(p+0x250)==0) { *(s32*)(p+0x250)=100; *(s32*)(p+0x244)=5; }
        for (i=0, q=p; i<4; ++i,q+=4) {
                pos=*fn_8023E724(i);
                if (fn_8023DE58(i)>=8) {
                    if (*(s32*)(p+0x250) & *(s32*)(q+0x264)) { fn_80230498(i, &pos, 956, 255, 2, -128, 1); }
                    else { fn_80230498(i, &pos, 957, 255, 2, -128, 1); }
                } else { fn_80230498(i, &pos, 956, 255, 2, -128, 1); }
            }
        break;
    case 5:
        --*(s32*)(p+0x250);
        if(*(s32*)(p+0x250)==0) { *(s32*)(p+0x244)=6; *(s32*)(p+0x250)=60; }
        for (i=0, q=p; i<4; ++i,q+=4) {
                pos=*fn_8023E724(i);
                if (fn_8023DE58(i)>=8) {
                    if (*(s32*)(p+0x250) & *(s32*)(q+0x264)) { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
                    else { fn_80230498(i, &pos, 959, 255, 2, -128, 1); }
                } else { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
            }
        if(*(s32*)(p+0x250)==90) {
            fn_8043D67C(lbl_8053AED0,0x23f,0,0);
            fn_80230F44(0,0x100002d);
            for(i=0,q=p;i<4;++i,q+=4) {
                if(Swdl_isPlayer(i)==1) fn_80236ED8(i,2);
                pos=*fn_8023E724(i);
                *(void**)(q+0x234)=fn_8013CC50(*(void**)(p+4),&pos,lbl_80541438,0x26a,1,3,0,0,1);
            }
        }
        break;
    case 6:
        --*(s32*)(p+0x250);
        if(*(s32*)(p+0x250)==0) {
            *(s32*)(p+0x244)=7;
            *(s32*)(p+0x24c)=0;
            *(s32*)(p+0x250)=2;
            *(s16*)(p+0x260)=0;
            for(i=0;i<4;++i) { pos=*fn_8023E724(i); fn_80230498(i, &pos, 219, 255, 2, -128, 1); }
        } else {
            for (i=0, q=p; i<4; ++i,q+=4) {
                pos=*fn_8023E724(i);
                if (fn_8023DE58(i)>=8) {
                    if (*(s32*)(p+0x250) & *(s32*)(q+0x264)) { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
                    else { fn_80230498(i, &pos, 959, 255, 2, -128, 1); }
                } else { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
            }
        }
        break;
    case 7:
        --*(s32*)(p+0x250);
        if(*(s32*)(p+0x250)==0) {
            *(s16*)(p+0x260)+=0x1000;
            for(i=0,q=p;i<4;++i,q+=4) {
                JGeometry::TVec3<f32> point=*fn_8023E724(i);
                if(*(s32*)(p+0x24c)<11) {
                    if(*(void**)(q+0x234)) {
                        JGeometry::TVec3<f32> ring=*fn_8023E724(i);
                        ring.x=lbl_8054143C*JMACosShort(*(s16*)(p+0x260))+ring.x;
                        ring.y=lbl_8054143C*JMASinShort(*(s16*)(p+0x260))+ring.y;
                        fn_8013CB44(*(void**)(q+0x234),&ring,1,3,1);
                    }
                    fn_80230498(i, &point, Swdl_frames[*(s32*)(p+0x24c)]+0xdb, 255, 2, -128, 1);
                } else {
                    if(fn_8023DE58(i)>=8) {
                        if(*(s32*)(p+0x250)&*(s32*)(q+0x264)) { fn_80230498(i, &point, Swdl_frames[*(s32*)(p+0x24c)]+0x3b9, 255, 2, -128, 1); }
                        else { fn_80230498(i, &point, Swdl_frames[*(s32*)(p+0x24c)]+0x3ba, 255, 2, -128, 1); }
                    } else { fn_80230498(i, &point, Swdl_frames[*(s32*)(p+0x24c)]+0x3b9, 255, 2, -128, 1); }
                    if(*(s32*)(p+0x24c)==11) {
                        if(*(void**)(q+0x234)) { fn_801EE434(*(void**)(q+0x234)); *(void**)(q+0x234)=0; }
                        fn_80230FD0(i,0x10001);
                        if(lbl_8053AAF8[0x82]&(u8)(1<<i)) fn_80236554(i,fn_80237810(i),0);
                    }
                }
            }
            ++*(s32*)(p+0x24c);
            *(s32*)(p+0x250)=2;
            if(*(s32*)(p+0x24c)>=14) {
                if(*(u8*)(fn_802D6A9C()+0x131f9)) { *(s32*)(p+0x244)=10; *(s32*)(p+0x250)=1; }
                else { *(s32*)(p+0x244)=8; *(s32*)(p+0x250)=1; }
            }
        }
        break;
    case 8:
        if(*(s32*)(p+0x250)==0) {
            *(s32*)(p+0x25c)+=*(s32*)(p+0x254);
            if(*(s32*)(p+0x25c)>=*(s32*)(p+0x258)) {
                *(s32*)(p+0x25c)=*(s32*)(p+0x258);
                if(fn_802DE7CC() && !Swdl_isCleared()) {
                    s32 eventRoom=*(s32*)(p+4);
                    JGeometry::TVec3<f32> point=*(JGeometry::TVec3<f32>*)(p+0xc);
                    fn_8038BD08(0,0x265,eventRoom,&point,0x21);
                    *(s32*)(p+0x244)=15;
                } else *(s32*)(p+0x244)=9;
                fn_80134D14(lbl_8053AAF8,0);
            }
            lbl_8053AEC8[0x5c]=255-*(s32*)(p+0x25c);
        } else --*(s32*)(p+0x250);
        for(i=0;i<4;++i) { pos=*fn_8023E724(i); fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
        break;
    case 9:
        if(fn_80230534(0)) {
            *(u8*)(p+0x11c)=0;
            fn_8045873C(lbl_8053AF80,0);
        }
        for (i=0, q=p; i<4; ++i,q+=4) {
                pos=*fn_8023E724(i);
                if (fn_8023DE58(i)>=8) {
                    if (*(s32*)(p+0x250) & *(s32*)(q+0x264)) { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
                    else { fn_80230498(i, &pos, 959, 255, 2, -128, 1); }
                } else { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
            }
        break;
    case 10:
        if(*(s32*)(p+0x250)==0) {
            *(s32*)(p+0x25c)+=*(s32*)(p+0x254);
            if(*(s32*)(p+0x25c)>=*(s32*)(p+0x258)) {
                *(s32*)(p+0x25c)=*(s32*)(p+0x258);
                if(fn_802DE7CC() && !Swdl_isCleared()) {
                    s32 eventRoom=*(s32*)(p+4);
                    JGeometry::TVec3<f32> point=*(JGeometry::TVec3<f32>*)(p+0xc);
                    fn_8038BD08(0,0x265,eventRoom,&point,0x21);
                    *(s32*)(p+0x244)=16;
                } else *(s32*)(p+0x244)=11;
                fn_80134D14(lbl_8053AAF8,0);
            }
            lbl_8053AEC8[0x5c]=255-*(s32*)(p+0x25c);
        } else --*(s32*)(p+0x250);
        for (i=0, q=p; i<4; ++i,q+=4) {
                pos=*fn_8023E724(i);
                if (fn_8023DE58(i)>=8) {
                    if (*(s32*)(p+0x250) & *(s32*)(q+0x264)) { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
                    else { fn_80230498(i, &pos, 959, 255, 2, -128, 1); }
                } else { fn_80230498(i, &pos, 958, 255, 2, -128, 1); }
            }
        break;
    case 11:
        *(s32*)(p+0x244)=12;
        *(u8*)(*(char**)(lbl_8053AB10+0x20)+0x216)=1;
        break;
    case 12:
        *(u8*)(*(char**)(lbl_8053AB10+0x20)+0x216)=1;
        if(*(u8*)(*(char**)(lbl_8053AB10+0x20)+0x214)!=1) {
            fn_80119468(fn_80119DD0(),0,1);
            *(s32*)(p+0x250)=5; *(s32*)(p+0x244)=13;
        }
        break;
    case 13: {
        *(u8*)(*(char**)(lbl_8053AB10+0x20)+0x216)=1;
        fn_80134D14(lbl_8053AAF8,0);
        s32 layer=*(s32*)(fn_802D6A9C()+8);
        s32 room=*(s32*)(fn_802D6A9C()+4);
        s32 value=*(s32*)((u8*)Swdl_layers+room*16+layer*4);
        s32 layer2=*(s32*)(fn_802D6A9C()+8);
        char* map=fn_802D6A9C();
        char* mgr=fn_802D6A9C();
        fn_802D9FF4(mgr,*(s32*)((u8*)Swdl_rooms+*(s32*)(map+4)*16+layer2*4),value);
        fn_80136798(lbl_8053AAF8,13,0);
        fn_802D6AAC(fn_802D6A9C(),3);
        fn_8045873C(lbl_8053AF80,0);
        *(s32*)(p+0x244)=14;
        break;
    }
    case 14:
        *(u8*)(*(char**)(lbl_8053AB10+0x20)+0x216)=1;
        break;
    case 15:
        if(fn_80388EEC(0)) *(s32*)(p+0x244)=9;
        break;
    case 16:
        if(fn_80388EEC(0)) *(s32*)(p+0x244)=11;
        break;
    }
    if(*(s32*)(p+0x244)>=1 && *(s32*)(p+0x244)<=10) {
        fn_80128C58((u8)*(s32*)(p+0x25c));
        *(u8*)(*(char**)(lbl_8053AB10+0x2c)+0xe)=*(s32*)(p+0x25c);
    }
}

}

// ---- Swdl_dtor_802F14B4.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA590[];

struct NonPolyBase {
    void* pad0;
    void* pad1;
};

struct NotifyTarget : NonPolyBase {
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
    virtual void Notify(int arg);
};

static inline void NotifySub(void* obj, int arg) {
    if (obj) {
        ((NotifyTarget*)obj)->Notify(arg);
    }
}

extern "C" void* fn_802F14B4(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA590;
        for (int i = 0; i < 4; i++) {
            void* h = *(void**)((char*)this_ + 0x234 + i * 4);
            if (h) {
                fn_801EE434(h);
            }
        }
        void* sub = *(void**)((char*)this_ + 0x230);
        if (sub) {
            NotifySub(sub, 1);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Swdl_SetParams_802F1574.cpp ----
// fn_802F1574 - SWDL: setParams. Reads the ambient effect group byte and
// mirrors it into this->0x258/0x25c, branches on fn_80237060(0)'s result
// to clear either the "active" flag (0x11c) or a counter (0x244), sets a
// run of paired int/int field defaults (0x234/0x238/0x23c/0x240 = 0,
// 0x264/0x268/0x26c/0x270 = 2), then allocates and placement-constructs
// an owned sub-object at this->0x230 - the same owned-sub-object
// composition pattern (same size 0x5c, same (0,0,8) constructor args) as
// WAVE/SDSM, see Wave_SetParams_802E73B4.cpp for the operator new/delete
// unlock this pattern needed.




class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

extern "C" u8 Glwp_GetAmbientEffectGroupByte(void);
extern "C" s32 fn_80237060(s32 arg);

extern "C" void Swdl_SetParams(void* this_) {
    char* p = (char*)this_;
    u8 byte = Glwp_GetAmbientEffectGroupByte();
    *(s32*)(p + 0x258) = byte;
    *(s32*)(p + 0x25c) = *(s32*)(p + 0x258);
    s32 r = fn_80237060(0);
    if (r == 2) {
        *(u8*)(p + 0x11c) = 0;
    } else {
        *(s32*)(p + 0x244) = 0;
    }
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x264) = 2;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x268) = 2;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x26c) = 2;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x270) = 2;
    *(WaveController**)(p + 0x230) = new WaveController(0, 0, 8);
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
