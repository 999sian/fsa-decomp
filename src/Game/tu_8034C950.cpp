#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
typedef Vec RckSdkVec;
#define Vec ActorVec
#include "Game/Actor.h"

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];
    YasiDrawKey key;
    s32 c;
    u8 palette;
    s8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_804721B0[];
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" void fn_801F0E34(void* a, s32 b, s32 c);
extern "C" void fn_8013CC50(s32 room, void* pos, f32 f, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_802DEB58(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" s32 fn_8023CA88(s32 holder);
extern "C" void fn_801F06F0(Actor* a, const char* name, s32 id, YasiDrawParam* param, s32 p5, f32 f6, f32 f7);
extern "C" void fn_80307AC8(u32 x, u32 y, void* v, s32 p, s32 p6, u32 u, s32 minus1);
extern "C" void fn_803075AC(u32 x, u32 y, void* v, s32 p, s32 sign, s32 two, s32 minus1, u8 p7, u32 u, s32 zero);


extern "C" u32 fn_801F132C(Actor* a, s32 b, s32 c, s32* d);
extern "C" char __vt__4RCK2[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8034C950(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = __vt__4RCK2;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8034C9B0(Actor* a, s32 b, s32 c) {
    fn_801F132C(a, b, c, (s32*)((u8*)a + 0x378));
}

extern "C" void fn_8034C9D4(Actor* a) {
    u8* p = (u8*)a;
    s32 c = fn_8022461C(&a->field_0C, a->field_04);
    if (c == 0xd || c == 0x3b || c == 0x39) {
        *(f32*)(p + 0x14) = 0.0f;
        *(f32*)(p + 0x3c) = 0.0f;
        *(f32*)(p + 0x40) = 0.0f;
        *(f32*)(p + 0x44) = 0.0f;
        fn_801F0E34(a, 0x30047, 0);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f3, -1, 1, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f4, 0, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f5, 0, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f6, 0, 0, 0, 0, 1);
        *(u8*)(p + 0x11c) = 0;
    } else if (c == 0xe && fn_802DEB58() == 1) {
        *(f32*)(p + 0x14) = 0.0f;
        *(f32*)(p + 0x3c) = 0.0f;
        *(f32*)(p + 0x40) = 0.0f;
        *(f32*)(p + 0x44) = 0.0f;
        fn_801F0E34(a, 0x30047, 0);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4fb, -1, 1, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4fc, 0, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4fd, 0, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4fe, 0, 0, 0, 0, 1);
        *(u8*)(p + 0x11c) = 0;
    } else {
        if ((s32)a->field_04 >= 8) {
            Vec pos;
            *(JGeometry::TVec3<f32>*)&pos = *(JGeometry::TVec3<f32>*)&a->field_0C;
            pos.z = 0.0f;
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249u, a->field_04, (f32*)&pos, 0, -1, -1);
        } else {
            fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x8a, 1, 0, 0, 0, 1);
            fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x8b, 1, 0, 0, 0, 1);
        }
        fn_801F0E34(a, 0x30003, 0);
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);
extern "C" void fn_8034CC98(Actor* a) {
    Vec saved;
    YasiDrawParam param;
    s32 flag;

    param.color = -1;
    param.palette = 0;
    if (a->field_C4 == 1 && a->field_0C.z != 0.0f) {
        param.f20 = 0;
        param.color = fn_8023CB24(a->field_C8) + 1;
        param.palette = fn_8023CA88(a->field_C8);
    }
    JGeometry::setTVec3f(&a->field_0C.x, &saved.x);
    a->field_0C.y += 8.0f;
    flag = 7;
    if (*(s32*)((u8*)a + 0x230) == 0) {
        flag = -1;
        fn_80307AC8(a->field_198, a->field_04, &a->field_0C, 0xc, 0, 0, -1);
    } else {
        fn_803075AC(a->field_198, a->field_04, &a->field_0C, 0x2b, 0, 2, -1, 1, 0, 0);
    }
    fn_801F06F0(a, lbl_804721B0, 0x2b, &param, flag, 1.0f, 1.0f);
    JGeometry::setTVec3f(&saved.x, &a->field_0C.x);
}

extern f32 lbl_8054257C;
extern f32 lbl_80542580;
extern f32 lbl_80542570;
extern "C" void fn_80239914(f32* out, s32 room, s32 id);
extern "C" void fn_8020D8C0(void* a, f32* box, s32 room, s32 id);
extern "C" void* fn_8020D58C();
extern "C" u8 fn_8023F264(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" s32 fn_80230CFC(s32 i);
extern "C" s32 fn_8022C004(s32 i);
extern "C" u8 fn_8023E8F0(s32 i);
extern "C" u8 fn_8023188C(s32 i);
extern "C" u8 fn_802319B4(s32 i, s32 j);
extern "C" u8 fn_80234D94(s32 i);
struct RockPlayerState {
    u8 field_00;
    u8 pad01[3];
    JGeometry::TVec3<f32> position;
    s32 mode;
};
struct RockStoredActor {
    u32 id;
    JGeometry::TVec3<f32> position;
    u32 param;
    s32 slot;
};
struct Rck2State : Actor {
    s32 state;
    s32 directions[4];
    s32 counts[4];
    s32 players[2];
    u8 active[4];
    RockStoredActor stored[8];
    RockPlayerState playerStates[4];
    s32 field_370;
    s32 storedCount;
    s32 field_378;
    s32 timer;
    u8 field_380, field_381, field_382, field_383, field_384, field_385;
    u8 pad386[2];
    s32 direction;
};
extern const f32 lbl_80472190[4][2];
extern "C" s32 fn_8022CAF8(s32);
extern "C" u8 fn_8022F9E4(s32, s32, s32, s32);
extern "C" u8 fn_8022E438(s32,s32);
extern "C" u8 fn_8022F478(s32);
extern "C" s32 fn_802373EC(s32);
extern "C" u8 fn_8022C310(s32);
extern "C" void fn_80230C6C(s32);
extern "C" void fn_8023DFF4(s32,const JGeometry::TVec3<f32>*);
extern "C" JGeometry::TVec3<f32>* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_8020D7D0(void*,s32);
extern "C" void fn_801F3604(Actor*);
extern "C" u8 fn_801F2618(Actor*,s32,s32);
extern "C" u16 fn_80226850(void*,s32);
extern "C" void* lbl_8053AC98;
extern "C" void fn_802A381C(void*,void*,s32,s32);
extern "C" u8 fn_801F2740(Actor*,s32);
extern "C" void fn_80238548(s32,s32,void*,s32);
extern "C" u8 fn_801F2B20(Actor*,s32);
extern "C" void fn_801F0D20(Actor*,s32);

#pragma fp_contract on
extern "C" void fn_8034CEB0(Actor* a) {
    s32 count;
    Rck2State* p = static_cast<Rck2State*>(a);
    JGeometry::TBox2<f32> box;
    JGeometry::TBox2<f32> bounds(lbl_8054257C,lbl_8054257C,lbl_80542580,lbl_80542580);
    box.set(*(JGeometry::TBox2<f32>*)((u8*)a+0x80));
    box.addPos(*(JGeometry::TVec2<f32>*)&a->field_0C);
    bounds.addPos(*(JGeometry::TVec2<f32>*)&a->field_0C);
    switch(p->state) {
    case 0: {
        fn_80239914((f32*)&box,a->field_04,a->field_198);
        s32 handle=a->field_198;
        s32 room=a->field_04;
        u8* mgr=(u8*)fn_8020D58C();
        fn_8020D8C0(mgr+mgr[0]*0x784+4,(f32*)&box,room,handle);
        p->directions[0]=-1;p->directions[1]=-1;p->directions[2]=-1;p->directions[3]=-1;
        p->counts[0]=0;p->counts[1]=0;p->counts[2]=0;p->counts[3]=0;
        p->direction=-1;
        for(s32 i=0;i<4;i++) {
            if(fn_8023F264(i)) {
                JGeometry::TVec3<f32>* pos=(JGeometry::TVec3<f32>*)fn_8023E724(i);
                f32 x=pos->x;
                f32 y=pos->y;
                s32 dir=fn_80230CFC(i);
                x+=lbl_80472190[dir][0]; y+=lbl_80472190[dir][1];
                p->active[i]=fn_8022C004(i);
                if(p->active[i]==1 && fn_8023E8F0(i)==1 && fn_8023188C(i)==1
                    && fn_802319B4(i,0x11)==1 && !fn_80234D94(i)
                    && (u8)(x>=bounds.i.x && y>=bounds.i.y && x<bounds.f.x && y<bounds.f.y)==1) {
                        p->directions[i]=dir;
                        p->counts[p->directions[i]]++;
                } else p->active[i]=0;
                if(p->active[i]==1 && p->direction==-1 && p->counts[p->directions[i]]>=2)
                    p->direction=p->directions[i];
            }
        }
        if(p->direction==-1) break;
        count=0;
        if(p->counts[p->direction]>=2) {
            f32 distance[4];
            for(s32 i=0;i<4;i++) {
                if(p->directions[i]==p->direction) {
                    if(fn_8023E8F0(i)==1)
                        distance[i]=PSVECDistance((RckSdkVec*)&a->field_0C,(RckSdkVec*)fn_8023E724(i));
                    else {
                        p->directions[i]=-1; distance[i]=0.0f;
                        p->counts[p->direction]--;
                    }
                } else {p->directions[i]=-1;distance[i]=0.0f;}
            }
            for(s32 j=0;j<p->counts[p->direction]-2;j++) {
                f32 farthest=0.0f;
                s32 index;
                for(s32 i=0;i<4;i++) {
                    if(farthest<distance[i]) {farthest=distance[i];index=i;}
                }
                if(farthest>0.0f) {
                    p->directions[index]=-1;distance[index]=0.0f;
                    p->counts[p->direction]--;
                }
            }
        }
        if(p->counts[p->direction]>=2) {
            u8* chosen=(u8*)p;
            for(s32 i=0;i<4;i++) {
                p->playerStates[i].position=*(JGeometry::TVec3<f32>*)fn_8023E724(i);
                p->playerStates[i].mode=fn_8022CAF8(i);
                if(p->directions[i]==p->direction && count<2) {
                    if(fn_8022F9E4(i,a->field_198,1,0)) {
                        *(s32*)(chosen+0x254)=i;chosen+=4; count++;
                        if(count>=2) {
                            if(a->v13()>0) a->v10(0xff,1);
                            p->state=1;
                            if(p->field_385==1) fn_801F3604(a);
                            a->field_B8=0;
                            p->timer=3;
                        }
                    }
                } else p->directions[i]=-1;
            }
        }
        if(p->state==1) {
            for(s32 i=0;i<4;i++) {
                if(fn_8022E438(p->players[0],i)==1 || fn_8022E438(p->players[1],i)==1)
                    p->playerStates[i].field_00=0;
            }
        }
        break;
    }
    case 1:
        if(a->field_C4) {
            JGeometry::TVec3<f32> positions[2];
            JGeometry::TVec3<f32>* out=positions;
            for(s32 i=0;i<4;i++) {
                if(p->directions[i]==p->direction && p->playerStates[i].field_00==0) {
                    if(p->playerStates[i].mode!=fn_8022CAF8(i)
                        || (fn_8022CAF8(i)==4 && fn_8022F478(i)==1)) {
                        fn_80230C6C(i);return;
                    }
                    if(fn_802373EC(i)==7 && fn_8022C310(i)==1) {
                        fn_80230C6C(i);return;
                    }
                }
                JGeometry::TVec3<f32> current(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                JGeometry::TVec3<f32> previous(p->playerStates[i].position);
                if(p->playerStates[i].field_00==0) {
                    f32 dx=current.x-previous.x;
                    f32 dy=current.y-previous.y;
                    f32 xx=dx*dx;
                    f32 yy=dy*dy;
                    if(JGeometry::TUtil<f32>::sqrt(xx+yy)>2.0f)
                        fn_8023DFF4(i, &(previous-current));
                }
                if(p->directions[i]==p->direction) *out++=*fn_8023E7B0(i);
            }
            positions[0]+=positions[1];
            positions[0].scale(0.5f);
            if(positions[0].z>0.0f) {
                a->field_0C.x=positions[0].x;a->field_0C.y=positions[0].y;a->field_0C.z=positions[0].z;
                a->field_04=fn_8023DE58(a->field_C8);
            }
            if(a->field_0C.z<=0.0f) {
                s32 handle=a->field_198;
                u8* mgr=(u8*)fn_8020D58C();
                fn_8020D7D0(mgr+mgr[0]*0x784+4,handle);
            } else if(p->field_382==0) {
                fn_801F0E34(a,0x3008c,0);p->field_382=1;
            }
        } else {
            a->field_3C.z+=-0.15f;
            *(JGeometry::TVec3<f32>*)&a->field_0C+=*(JGeometry::TVec3<f32>*)&a->field_3C;
            if(a->field_0C.z<0.0f || fn_801F2618(a,0,0)) {
                if(a->field_0C.z<0.0f) {
                    if(fn_80226850(&a->field_0C,a->field_04)==0x90)
                        fn_802A381C(lbl_8053AC98,&a->field_0C,a->field_04,0x91);
                    else if(fn_80226850(&a->field_0C,a->field_04)==0x91)
                        fn_802A381C(lbl_8053AC98,&a->field_0C,a->field_04,0x92);
                }
                p->state=2;p->timer=0;
            } else {
                s32 hits=fn_801F2740(a,-1);
                u8 pushed=0;
                if(hits>0) {
                    for(s32 i=0;i<4;i++) {
                        if(p->directions[i]!=p->direction && (hits&(1<<i))>0
                            && !fn_8022E438(p->players[0],i) && !fn_8022E438(p->players[1],i)) {
                            fn_80238548(i,0,&a->field_0C,5);pushed=1;
                        }
                    }
                }
                if(pushed==1 || fn_801F2B20(a,0)) {p->state=2;p->timer=0;}
            }
        }
        break;
    case 2: a->v07();break;
    }
    if((p->state==1 && a->field_0C.z>0.0f) || p->state==2) {
        p->timer--;
        if(p->timer<=0 && p->field_384==1 && p->field_370==1) {
            for(s32 i=0;i<p->storedCount;i++) {
                Actor_CreateByID(fn_801F856C(),p->stored[i].id,a->field_04,(f32*)&p->stored[i].position,
                    p->stored[i].param,p->stored[i].slot,-1);
            }
            p->field_384=0;
        }
        if(p->field_380==1) {
            if(p->field_381!=1) fn_801F0D20(a,3);
            p->field_380=0;
        }
    }
}
extern "C" void* fn_801F856C(void);
extern "C" u16 fn_80226850(void* p, s32 q);
extern "C" void fn_8034D99C(Actor* a) {
    u8* p = (u8*)a;
    s32 attr = fn_80226850(&a->field_0C, a->field_04);
    if ((u32)(attr - 0x64) <= 3 || (u32)(attr - 0x2c2) <= 1 || attr == 0x2d2 || attr == 0x2d3) {
        *(u8*)(p + 0x380) = 1;
        *(u8*)(p + 0x385) = 1;
    }
    if (*(s32*)(p + 0x370) == 1) {
        f32 minX = *(f32*)(p + 0x80);
        f32 minY = *(f32*)(p + 0x84);
        f32 maxX = *(f32*)(p + 0x88);
        f32 maxY = *(f32*)(p + 0x8c);
        minX += a->field_0C.x;
        maxX += a->field_0C.x;
        minY += a->field_0C.y;
        maxY += a->field_0C.y;
        s32 count = *(s32*)((u8*)fn_801F856C() + 0x1008);
        s32 j;
        s32 i = 0;
        j = 0;
        for (; i < count; j += 4, i++) {
            Actor* e = *(Actor**)((u8*)fn_801F856C() + j + 8);
            if (e != 0 && a->field_198 != e->field_198 && e->field_11C == 1 && (s32)a->field_04 == (s32)e->field_04) {
                u8 ok = (e->field_24.x >= minX && e->field_24.y >= minY && e->field_24.x < maxX && e->field_24.y < maxY);
                if (ok == 1) {
                    if (*(s32*)(p + 0x374) >= 8) {
                        return;
                    }
                    if (e->field_1A8 == 1) {
                        *(u8*)(p + 0x380) = 1;
                        *(u8*)(p + 0x381) = 1;
                    } else if (e->field_1A0 == 0x4654474c) {
                        *(u8*)(p + 0x380) = 1;
                    }
                    *(u8*)(p + 0x384) = 1;
                    *(u32*)(p + *(s32*)(p + 0x374) * 0x18 + 0x260) = e->field_1A0;
                    *(JGeometry::TVec3<f32>*)(p + *(s32*)(p + 0x374) * 0x18 + 0x264) = *(JGeometry::TVec3<f32>*)&e->field_24;
                    *(u32*)(p + *(s32*)(p + 0x374) * 0x18 + 0x270) = e->field_90;
                    *(s32*)(p + *(s32*)(p + 0x374) * 0x18 + 0x274) = e->field_16C;
                    e->field_11C = 0;
                    (*(s32*)(p + 0x374))++;
                }
            }
        }
    }
}

extern "C" void fn_8034DBF4(Actor* a) {
    u8* p = (u8*)a;
    a->field_60 = -14.0f;
    a->field_64 = -14.0f;
    a->field_68 = 14.0f;
    a->field_6C = 14.0f;
    a->field_1A4 = 2;
    a->field_7C.y = -16.0f;
    a->field_7C.z = -16.0f;
    a->field_88 = 16.0f;
    a->field_8C = 16.0f;
    *(s32*)(p + 0x234) = -1;
    *(u8*)(p + 0x25c) = 0;
    *(u8*)(p + 0x320) = 1;
    *(f32*)(p + 0x32c) = 0.0f;
    *(f32*)(p + 0x328) = 0.0f;
    *(f32*)(p + 0x324) = 0.0f;
    *(s32*)(p + 0x330) = 0;
    *(s32*)(p + 0x238) = -1;
    *(u8*)(p + 0x25d) = 0;
    *(u8*)(p + 0x334) = 1;
    *(f32*)(p + 0x340) = 0.0f;
    *(f32*)(p + 0x33c) = 0.0f;
    *(f32*)(p + 0x338) = 0.0f;
    *(s32*)(p + 0x344) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(u8*)(p + 0x25e) = 0;
    *(u8*)(p + 0x348) = 1;
    *(f32*)(p + 0x354) = 0.0f;
    *(f32*)(p + 0x350) = 0.0f;
    *(f32*)(p + 0x34c) = 0.0f;
    *(s32*)(p + 0x358) = 0;
    *(s32*)(p + 0x240) = -1;
    *(u8*)(p + 0x25f) = 0;
    *(u8*)(p + 0x35c) = 1;
    *(f32*)(p + 0x368) = 0.0f;
    *(f32*)(p + 0x364) = 0.0f;
    *(f32*)(p + 0x360) = 0.0f;
    *(s32*)(p + 0x36c) = 0;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x260) = 0;
    *(f32*)(p + 0x26c) = 0.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x264) = 0.0f;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x274) = -1;
    *(s32*)(p + 0x278) = 0;
    *(f32*)(p + 0x284) = 0.0f;
    *(f32*)(p + 0x280) = 0.0f;
    *(f32*)(p + 0x27c) = 0.0f;
    *(s32*)(p + 0x288) = 0;
    *(s32*)(p + 0x28c) = -1;
    *(s32*)(p + 0x290) = 0;
    *(f32*)(p + 0x29c) = 0.0f;
    *(f32*)(p + 0x298) = 0.0f;
    *(f32*)(p + 0x294) = 0.0f;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x2a4) = -1;
    *(s32*)(p + 0x2a8) = 0;
    *(f32*)(p + 0x2b4) = 0.0f;
    *(f32*)(p + 0x2b0) = 0.0f;
    *(f32*)(p + 0x2ac) = 0.0f;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = -1;
    *(s32*)(p + 0x2c0) = 0;
    *(f32*)(p + 0x2cc) = 0.0f;
    *(f32*)(p + 0x2c8) = 0.0f;
    *(f32*)(p + 0x2c4) = 0.0f;
    *(s32*)(p + 0x2d0) = 0;
    *(s32*)(p + 0x2d4) = -1;
    *(s32*)(p + 0x2d8) = 0;
    *(f32*)(p + 0x2e4) = 0.0f;
    *(f32*)(p + 0x2e0) = 0.0f;
    *(f32*)(p + 0x2dc) = 0.0f;
    *(s32*)(p + 0x2e8) = 0;
    *(s32*)(p + 0x2ec) = -1;
    *(s32*)(p + 0x2f0) = 0;
    *(f32*)(p + 0x2fc) = 0.0f;
    *(f32*)(p + 0x2f8) = 0.0f;
    *(f32*)(p + 0x2f4) = 0.0f;
    *(s32*)(p + 0x300) = 0;
    *(s32*)(p + 0x304) = -1;
    *(s32*)(p + 0x308) = 0;
    *(f32*)(p + 0x314) = 0.0f;
    *(f32*)(p + 0x310) = 0.0f;
    *(f32*)(p + 0x30c) = 0.0f;
    *(s32*)(p + 0x318) = 0;
    *(s32*)(p + 0x31c) = -1;
    a->field_B8 = 2;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x378) = 0;
    *(s32*)(p + 0x37c) = 0;
    *(s32*)(p + 0x388) = -1;
    *(s32*)(p + 0x374) = 0;
    *(s32*)(p + 0x370) = 1;
    *(u8*)(p + 0x380) = (a->field_90 >> 4) & 1;
    *(u8*)(p + 0x383) = (a->field_90 >> 5) & 1;
    *(u8*)(p + 0x381) = 0;
    *(u8*)(p + 0x384) = 0;
    *(u8*)(p + 0x385) = 0;
    *(u8*)(p + 0x382) = 0;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
