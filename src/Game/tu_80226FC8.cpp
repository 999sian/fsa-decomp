#include "types.h"
#include "sdk/stl/float.h"
#include "JSystem/JGeometry/Box.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
static inline void projectGateBox(JGeometry::TBox2f* box, u8* actor) {
    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(actor + 0xc);
    *box = *(JGeometry::TBox2f*)(actor + 0x60);
    box->addPos(pos.x, pos.y);
    box->i.y -= pos.z;
    pos.z *= 0.5f;
    box->f.y -= pos.z;
}

static inline bool gateVelocitySame(u8* actor) {
    f32 eps = 32.0f * FLT_EPSILON;
    bool equal = false, xy = false, x = false;
    f32 dx = *(f32*)(actor+0x3c) - *(f32*)(actor+0x364);
    if (-eps <= dx && dx <= eps) x = true;
    if (x) {
        bool y = false;
        f32 dy = *(f32*)(actor+0x40) - *(f32*)(actor+0x368);
        if (-eps <= dy && dy <= eps) y = true;
        if (y) xy = true;
    }
    if (xy) {
        bool z = false;
        f32 dz = *(f32*)(actor+0x44) - *(f32*)(actor+0x36c);
        if (-eps <= dz && dz <= eps) z = true;
        if (z) equal = true;
    }
    return equal;
}
struct GateBox {
    f32 x0, y0, x1, y1;
    void translate(f32 x, f32 y) { x0 += x; y0 += y; x1 += x; y1 += y; }
    void expand(f32 v) { f32 a=x0-v, b=y0-v, c=x1+v, d=y1+v; x0=a; y0=b; x1=c; y1=d; }
};
static inline int gateRoom(const u32 param) { u32 n=(param>>24)&7; int r=n+7; if (!n) r=n; return r; }
struct GateRoomFlags { u8 pad[0x131df]; u8 flags[1]; u8 flag(s32 room) { return flags[room]; } };


extern "C" void fn_801EE434(void* p);
extern "C" void __dt__5ActorFv(void* p, int how);
extern void operator delete(void* p);
extern void* lbl_804A6DC8[];
typedef struct FsaVec3 {
    f32 x;
    f32 y;
    f32 z;
} FsaVec3;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern f32 lbl_8046AC58[];
extern void* lbl_8046ACB8[];
extern const f32 lbl_8053FF74;
extern const f32 lbl_8053FF84;
extern const f32 lbl_8053FF88;
extern void* lbl_8053AC98;
extern const f32 lbl_8053FF60;
extern const f32 lbl_8053FF64;
extern const f32 lbl_8053FF68;
extern const f32 lbl_8053FF6C;
extern const f32 lbl_8053FF70;
extern const f32 lbl_8053FF78;
extern const f32 lbl_8053FF94;
extern const f32 lbl_8053FF98;
extern const f32 lbl_8053FF9C;
extern const f32 lbl_8053FFA0;
extern const f32 lbl_8053FFA4;
extern const f32 lbl_8053FFA8;
extern const f32 lbl_8053FFAC;
extern const f32 lbl_8053FFB0;
extern const f32 lbl_8053FFB4;
extern const f32 lbl_8053FFB8;
extern const f32 lbl_8053FFBC;
extern const f32 lbl_8053FFC0;
extern const f32 lbl_8053FFC4;
extern "C" s32 Actor_CreateByID(void* mgr, u32 type, s32 room, void* pos, u32 param, s32 a, s32 b);
extern "C" u8 fn_8023EFEC(s32 idx);
extern "C" u32 fn_8023EEB4(s32 idx);
extern "C" s32 fn_8023EF50(s32 idx);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_802A3948(void* mgr, f32* pos, s32 idx, u32 room, s32 n);
static inline void gateEffect(const JGeometry::TVec3f& pos, s32 idx, u32 room) {
    fn_802A3948(lbl_8053AC98, (f32*)&pos, idx, room, 0xc);
}
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
s32 fn_801CD664(s32 arg);
void fn_802F6CF4(void* obj, f32* pos, void* res, u8* blk);
void fn_802F6CF4(void* obj, FsaVec3* pos, void* res, u8* blk);
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_801F856C(void);
#pragma opt_common_subs off
extern "C" void fn_80226FC8(void* this_, s32 idx) {
    u8* actor = (u8*)this_;
    if (*(actor + 0x255) != 1) {
        u8* p = actor + idx * 4;
        void* a = *(void**)(p + 0x27c);
        if (a == 0) {
            if (fn_8023EFEC(idx) && fn_8023EEB4(idx) == 0x59415349) {
                s32 id = fn_8023EF50(idx);
                void* mgr = fn_801F856C();
                *(void**)(p + 0x27c) = fn_801F666C(mgr, id);
            }
        } else if (*((u8*)a + 0x11c) == 0) {
            *(void**)(p + 0x27c) = 0;
        } else {
            JGeometry::TVec3f* vel = (JGeometry::TVec3f*)((u8*)a + 0x3c);
            JGeometry::TVec3f* apos = (JGeometry::TVec3f*)((u8*)a + 0xc);

            
            if (!(vel->squared() <= lbl_8053FF60 * FLT_EPSILON) && *(volatile f32*)((u8*)a + 0x14) < lbl_8053FF64) {
                JGeometry::TVec3f d;
                d = *apos - *(JGeometry::TVec3f*)(actor + 0xc);
                bool hit = false;
                if (d.x >= lbl_8053FF68 && d.y >= lbl_8053FF68 && d.x < lbl_8053FF6C && d.y < lbl_8053FF6C) {
                    hit = 1;
                }
                if (hit) {
                    void* target = *(void**)(p + 0x27c);
                    ((Actor*)target)->v16();
                    *(void**)(p + 0x27c) = 0;
                    gateEffect(JGeometry::TVec3f(*(f32*)(actor + 0xc) - lbl_8053FF70, *(f32*)(actor + 0x10) - lbl_8053FF70, lbl_8053FF74), idx, *(u32*)(actor + 4));
                    gateEffect(JGeometry::TVec3f(lbl_8053FF70 + *(f32*)(actor + 0xc), *(f32*)(actor + 0x10) - lbl_8053FF70, lbl_8053FF74), idx, *(u32*)(actor + 4));
                    gateEffect(JGeometry::TVec3f(*(f32*)(actor + 0xc) - lbl_8053FF70, lbl_8053FF70 + *(f32*)(actor + 0x10), lbl_8053FF74), idx, *(u32*)(actor + 4));
                    gateEffect(JGeometry::TVec3f(lbl_8053FF70 + *(f32*)(actor + 0xc), lbl_8053FF70 + *(f32*)(actor + 0x10), lbl_8053FF74), idx, *(u32*)(actor + 4));
                    if (*(actor + 0x255) == 0) {
                        fn_8013CC50(*(u32*)(actor + 4), actor + 0xc, lbl_8053FF78, 0x3e3, 0, -2, 0, 0, 1);
                        *(actor + 0x255) = 1;
                    }
                }
            }
        }
    }
}
#pragma opt_common_subs reset
extern "C" s32 fn_80227290(void* __restrict this_, f32 eps, const u32* __restrict types, s32 handle) {
    u8 flag;
    s32 count;
    s32 offset;
    s32 found;
    s32 i;
    s32 room = *(s32*)((u8*)this_ + 4);
    found = -1;
    flag = ((GateRoomFlags*)fn_802D6A9C())->flag(room);
    count = *(s32*)((u8*)fn_801F856C() + 0x1008);
    for (i = 0, offset = 0; i < count; i++, offset += 4) {
        u8* a = *(u8**)((u8*)fn_801F856C() + offset + 8);
        if (a == 0 || a[0x11c] == 0 || *(s32*)(a + 4) != *(s32*)((u8*)this_ + 4) || handle == *(s32*)(a + 0x198)) continue;
        if (flag == 0 && __fabs(*(f32*)((u8*)this_ + 0x14) - *(f32*)(a + 0x14)) > eps) continue;
        for (const u32* __restrict t = types; *t != 0x4e554c4c; t++) {
            if (*t == *(u32*)(a + 0x1a0)) {
                GateBox box = *(GateBox*)((u8*)this_ + 0x60);
                JGeometry::TVec3f pos = *(JGeometry::TVec3f*)((u8*)this_ + 0xc);
                JGeometry::TVec3f otherPos = *(JGeometry::TVec3f*)(a + 0xc);
                GateBox other = *(GateBox*)(a + 0x60);
                box.translate(pos.x, pos.y);
                other.translate(otherPos.x, otherPos.y);
                box.y0 -= pos.z;
                pos.z *= 0.5f;
                box.y1 -= pos.z;
                other.y0 -= otherPos.z;
                otherPos.z *= 0.5f;
                other.y1 -= otherPos.z;
                f32 x0 = ((JGeometry::TBox2f*)&box)->i.x;
                f32 y0 = ((JGeometry::TBox2f*)&box)->i.y;
                f32 x1 = ((JGeometry::TBox2f*)&box)->f.x;
                f32 y1 = ((JGeometry::TBox2f*)&box)->f.y;
                if (x0 <= ((JGeometry::TBox2f*)&other)->i.x) x0 = ((JGeometry::TBox2f*)&other)->i.x;
                if (y0 <= ((JGeometry::TBox2f*)&other)->i.y) y0 = ((JGeometry::TBox2f*)&other)->i.y;
                if (x1 >= ((JGeometry::TBox2f*)&other)->f.x) x1 = ((JGeometry::TBox2f*)&other)->f.x;
                if (y1 >= ((JGeometry::TBox2f*)&other)->f.y) y1 = ((JGeometry::TBox2f*)&other)->f.y;
                u8 hit = 0;
                if (x1 >= x0 && y1 >= y0) hit = 1;
                if (hit) { found = *(s32*)(a + 0x198); break; }
            }
        }
        if (found >= 0) break;
    }
    return found;
}
#pragma opt_propagation reset
extern "C" u8 fn_8023B0F4(s32, f32*, u32, s32, f32);
extern "C" u8 fn_8022C8EC(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);
extern "C" u8 fn_8023513C(s32);
extern "C" u8 fn_802317F0(s32,s32,void*,void*,u32);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8022F3DC(s32);
#pragma opt_propagation off
extern "C" void fn_80227530(u8* p, f32* out) {
    s32 i;
    for (i = 0; i < 4; i++) {
        fn_80226FC8(p, i);
        u8* global;
        f32 y1,x1,y0,x0,x,y;
        x0=*(f32*)(p+0x60); global=(u8*)lbl_8053AAF8; out[0]=x0;
        y0=*(f32*)(p+0x64); out[1]=y0;
        x1=*(f32*)(p+0x68); out[2]=x1;
        y1=*(f32*)(p+0x6c); out[3]=y1;
        y=*(f32*)(p+0x10); x=*(f32*)(p+0xc);
        y0+=y; x0+=x; x1+=x; y1+=y;
        *(volatile f32*)(out+1)=y0; out[0]=x0; out[2]=x1; out[3]=y1;
        if (global[0x7e] && !fn_8022C8EC(i)) {
            s32 room=(*(u32*)(p+0x90)>>24)&7;
            s32 id=room+7; if (!room) id=room;
            s32 current=fn_8023DE58(i);
            if (current!=id) continue;
        }
        if (fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF70)) {
            if (p[i+0x234]==1) continue;
            p[i+0x234]=1;
            if (fn_802373EC(i)==1 && fn_8023725C(i)>=2 && fn_8023513C(i)) continue;
            if (fn_8022F514(i) && fn_8022CAF8(i)!=4) {
                s32 player=fn_8022F3DC(i);
                if (fn_802373EC(player)==1 && fn_8023725C(player)>=2 && fn_8023513C(player)) continue;
            }
            int mapRoom;
            int rawRoom;
            u32 param=*(u32*)(p+0x90);
            rawRoom=(param>>24)&7;
            u32 kind=param&0x7f;
            mapRoom=rawRoom+7; if (!rawRoom) mapRoom=rawRoom;
            if (fn_802317F0(i,mapRoom,p+0xc,p+0x238,kind) && p[0x254]==1) {
                gateEffect(JGeometry::TVec3f(*(f32*)(p+0xc)-8.0f,*(f32*)(p+0x10)-8.0f,lbl_8053FF74),i,*(u32*)(p+4));
                gateEffect(JGeometry::TVec3f(8.0f+*(f32*)(p+0xc),*(f32*)(p+0x10)-8.0f,lbl_8053FF74),i,*(u32*)(p+4));
                gateEffect(JGeometry::TVec3f(*(f32*)(p+0xc)-8.0f,8.0f+*(f32*)(p+0x10),lbl_8053FF74),i,*(u32*)(p+4));
                gateEffect(JGeometry::TVec3f(8.0f+*(f32*)(p+0xc),8.0f+*(f32*)(p+0x10),lbl_8053FF74),i,*(u32*)(p+4));
                if (p[0x255]==0) {
                    fn_8013CC50(*(u32*)(p+4),p+0xc,lbl_8053FF78,0x3e3,0,-2,0,0,1);
                    p[0x255]=1;
                }
            }
        } else {
            f32 d,c,b,y1;
            f32 a,x1,y0,x0,v;
            x0=out[0]; v=lbl_8053FF78; y0=out[1]; x1=out[2];
            a=x0-v; y1=out[3]; b=y0-v; c=x1+v; d=y1+v;
            *(volatile f32*)out=a; out[1]=b; out[2]=c; out[3]=d;
            if (!fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF74)) p[i+0x234]=0;
        }
    }
}
#pragma opt_propagation reset
extern "C" u8 fn_8022D75C(s32);
extern "C" u8 fn_8022D534(s32);
extern "C" u8 fn_8022F514(s32);
extern "C" u8 fn_8023B0F4(s32, f32*, u32, s32, f32);
extern "C" void fn_802381B8(s32);
extern "C" u8 fn_80234E30(s32);
extern "C" u8 fn_8022C8EC(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u32 fn_8022C5EC(s32,s32);
extern "C" u32 fn_8022C46C(s32,s32);
extern "C" u8 fn_8022DBA0(s32);
extern "C" u8 fn_8022F478(s32);
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);
extern "C" u8 fn_8023513C(s32);
extern "C" u8 fn_802317F0(s32,s32,void*,void*,u32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8023E724(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" u8 fn_8022BC38(s32,s32,s32);
extern "C" void fn_802348C4(s32,s32,s32);
#pragma opt_propagation off
extern "C" void fn_802278A8(void* this_, f32* out) {
    s32 b, c, d, e;
    u8* p = (u8*)this_;
    for (s32 i = 0; i < 4; i++) {
        f32 y1,x1,y0,x0,x,y;
        x0=*(f32*)(p+0x60); out[0]=x0;
        y0=*(f32*)(p+0x64); out[1]=y0;
        x1=*(f32*)(p+0x68); out[2]=x1;
        y1=*(f32*)(p+0x6c); out[3]=y1;
        y=*(f32*)(p+0x10); x=*(f32*)(p+0xc);
        y0+=y; x0+=x; x1+=x; y1+=y;
        *(volatile f32*)(out+1)=y0; out[0]=x0; out[2]=x1; out[3]=y1;
        if (!fn_8022D75C(i) && fn_8022D534(i)) { p[i+0x234]=1; continue; }
        if ((*(s32*)(p+0x90)&0x7f)==0x10) return;
        if (fn_8022F514(i)) {
            s32 type=*(s32*)(p+0x90)&0x7f;
            if ((type==0 || (u32)(type-1)<=2 || type==0x17 || type==0x18) &&
                fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF70)) fn_802381B8(i);
        }
        if ((*(s32*)(p+0x90)&0x7f)==0x13 && !fn_80234E30(i)) continue;
        if (*((u8*)lbl_8053AAF8+0x7e) && !fn_8022C8EC(i)) {
            s32 room=(*(s32*)(p+0x90)>>24)&7;
            s32 id=room+7; if (!room) id=room;
            s32 current=fn_8023DE58(i);
            if (current!=id) continue;
        }
        if (fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF70)) {
            s32 mapRoom;
            if (((*(s32*)(p+0x90)&0x7f)==0x15 || (*(s32*)(p+0x90)&0x7f)==0x23) &&
                (mapRoom=*(s32*)(p+4), ((GateRoomFlags*)fn_802D6A9C())->flag(mapRoom))) {
                if (!fn_8022C5EC(i,8) && !fn_8022C5EC(i,4) && !fn_8022C46C(i,8) && !fn_8022C46C(i,4)) continue;
                if (fn_8022DBA0(i)) continue;
            } else {
                if (p[i+0x234]==1) continue;
                if (fn_8022D75C(i)) { p[i+0x234]=1; continue; }
            }
            if (fn_8022F478(i) && (*(s32*)(p+0x90)&0x7f)!=4) continue;
            if (((*(s32*)(p+0x90)&0x7f)==4 || (*(s32*)(p+0x90)&0x7f)==0x20 || (*(s32*)(p+0x90)&0x7f)==0x24) &&
                fn_802373EC(i)==1 && fn_8023725C(i)>=2 && fn_8023513C(i)) continue;
            int targetRoom;
            int rawRoom;
            u32 param=*(u32*)(p+0x90);
            rawRoom=(param>>24)&7;
            u32 kind=param&0x7f;
            targetRoom=rawRoom+7; if (!rawRoom) targetRoom=rawRoom;
            if (fn_802317F0(i,targetRoom,p+0xc,p+0x238,kind) &&
                (*(s32*)(p+0x90)&0x7f)==4 && fn_8022F514(i)) {
                s32 a=fn_8023DE58(i);
                if (((GateRoomFlags*)fn_802D6A9C())->flag(a) || fn_8022CAF8(i)==4 || fn_8022CAF8(i)==5) continue;
                if (fn_8022BC38(fn_8022F3DC(i),fn_8023DE58(i),fn_8023E724(i))) {
                    fn_802381B8(fn_8022F3DC(i));
                    fn_802348C4(fn_8022F3DC(i),fn_8023DE58(i),fn_8023E724(i));
                }
            }
        } else {
            f32 d,c,b,y1;
            f32 a,x1,y0,x0,v;
            x0=out[0]; v=lbl_8053FF78; y0=out[1]; x1=out[2];
            a=x0-v; y1=out[3]; b=y0-v; c=x1+v; d=y1+v;
            *(volatile f32*)out=a; out[1]=b; out[2]=c; out[3]=d;
            if (!fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF74)) p[i+0x234]=0;
        }
    }
}
#pragma opt_propagation reset
extern "C" void fn_80227CE8(void* this_) {
    f32 d[3];
    f32 save[3];
    u8 blk[0x3c];
    u8 i;

    if ((*(s32*)((u8*)this_ + 0x90) & 0x7f) == 0x20 && *((u8*)this_ + 0x255) == 0) {
        *(s32*)(blk + 0x10) = -1;
        *(s32*)(blk + 0x14) = -1;
        for (i = 0; i < 0x10; i += 8) {
            blk[(u8)(i)] = i;
            blk[(u8)(i + 1)] = i + 1;
            blk[(u8)(i + 2)] = i + 2;
            blk[(u8)(i + 3)] = i + 3;
            blk[(u8)(i + 4)] = i + 4;
            blk[(u8)(i + 5)] = i + 5;
            blk[(u8)(i + 6)] = i + 6;
            blk[(u8)(i + 7)] = i + 7;
        }
        *(s32*)(blk + 0x10) = -1;
        *(s32*)(blk + 0x14) = 0;
        *(s32*)(blk + 0x18) = 0;
        blk[0x1c] = 0;
        blk[0x1d] = 0;
        blk[0x1e] = 0;
        blk[0x1f] = 1;
        blk[0x20] = 1;
        blk[0x21] = 0;
        blk[0x22] = 0;
        blk[0x23] = 0;
        blk[0x24] = 0;
        blk[0x25] = 0;
        blk[0x26] = 1;
        *(s32*)(blk + 0x28) = 3;
        blk[0x2c] = 1;
        blk[0x2d] = 0;
        blk[0x2e] = 0;
        *(s32*)(blk + 0x30) = -1;
        *(s32*)(blk + 0x34) = 0;
        *(s32*)(blk + 0x38) = 2;

        save[0] = *(f32*)((u8*)this_ + 0xc);
        save[1] = *(f32*)((u8*)this_ + 0x10);
        save[2] = *(f32*)((u8*)this_ + 0x14);
        d[0] = lbl_8053FF84;
        d[1] = lbl_8053FF84;
        d[2] = lbl_8053FF74;
        *(f32*)((u8*)this_ + 0xc) += d[0];
        *(f32*)((u8*)this_ + 0x10) += d[1];
        *(f32*)((u8*)this_ + 0x14) += d[2];

        if (*((u8*)this_ + 0x256) == 1 && *(s32*)((u8*)this_ + 0x278) >= 0) {
            *(f32*)((u8*)this_ + 0xc) += lbl_8046AC58[*(s32*)((u8*)this_ + 0x278)];
            *(s32*)((u8*)this_ + 0x278) += 1;
            if (*(s32*)((u8*)this_ + 0x278) >= 0x18) {
                *(s32*)((u8*)this_ + 0x278) = fn_801CD664(10) - 0x69;
            }
        }

        blk[0x24] = 1;
        blk[0x1d] = -2;
        blk[0x13] = 0xa0;
        blk[0x2c] = 0;

        if (*(s32*)((u8*)this_ + 0x4) < 8) {
            void* mgr = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
            void* res = ((void* (*)(void*, u32, void*))(*(void***)mgr)[6])(mgr, 0x534d5020, lbl_8046ACB8);
            fn_802F6CF4(((void**)lbl_8053AB10)[8], (f32*)((u8*)this_ + 0xc), res, blk);
        }

        *(f32*)((u8*)this_ + 0xc) = save[0];
        *(f32*)((u8*)this_ + 0x10) = save[1];
        *(f32*)((u8*)this_ + 0x14) = save[2];
    } else {
        *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) + lbl_8053FF88;
        *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) - lbl_8053FF88;
    }
}

extern "C" f32 fn_8022C76C(s32);
extern const f32 lbl_8053FF80,lbl_8053FF8C,lbl_8053FF90;
#pragma pool_data on
const u32 lbl_8046ABE8[] = {
    'ARRW','FIRE','HBMB','BOME','STON','GRAS','TUBO','YASI','HNRY','ESRY','PCDM','SWBM','SBAL','NULL'
};
const u32 gateCarryTypes[] = { 'HNRY','ESRY','NULL' };
const u32 gateHeavyTypes[] = { 'HBMB','BOME','STON','GRAS','TUBO','YASI','RUPY','HNRY','ESRY','SBAL','NULL' };
extern "C" u8 fn_8023A51C(s32);
extern "C" void* fn_8023A478(s32);
extern "C" u16 fn_802265FC(void*,u32);
extern "C" u16 fn_80226850(void*,s32);
extern "C" void* fn_801902C0();
extern "C" s32 fn_801F26CC(void*,const u32*);
extern "C" void fn_801F349C(void*,s32,void*);
struct GateWarpTarget {
    void warp(const u32 param, void* pos) { fn_801F349C(this, gateRoom(param), pos); }
};
#pragma peephole off
extern "C" void fn_80227F50(void* this_) {
    u8* p=(u8*)this_;
    s32 i;
    u8* cursor=(u8*)this_;
    JGeometry::TVec3f delta;
    JGeometry::TVec3f dest;
    GateBox boxA;
    GateBox boxB;
    JGeometry::TVec3f push0,push1,push2,push3;
    JGeometry::TVec3f nearPos;
    JGeometry::TVec3f e3,e2,e1,e0;
    JGeometry::TVec3f attackPos;
    GateBox playerBox;
    JGeometry::TVec2f xy;
    for(i=0;i<4;i++) {
        *(f32*)(cursor+0x258)=fn_8022C76C(i);
        *(f32*)(cursor+0x268)=*(f32*)(cursor+0x258);
        cursor+=4;
    }
    p[0x256]=0;
    for(i=0;i<4;i++) {
        nearPos=*(JGeometry::TVec3f*)fn_8023E724(i);
        if(__fabsf((*(f32*)(p+0xc))-nearPos.x)<lbl_8053FF60 && __fabsf((*(f32*)(p+0x10))-nearPos.y)<lbl_8053FF60) {
            p[0x256]=1; break;
        }
    }
    if(p[0x256]==1) {
        if((*(s32*)(p+0x278))<0) {
            if((*(s32*)(p+0x278))==-1) (*(s32*)(p+0x278))=0;
            else (*(s32*)(p+0x278))++;
        }
    } else (*(s32*)(p+0x278))=-1;
    if(((*(s32*)(p+0x90))&0x7f)==0x20) {
        for(i=0;i<4;i++) {
            if(fn_802373EC(i)==1 && fn_8023A51C(i)) {
                attackPos=*(JGeometry::TVec3f*)fn_8023A478(i);
                if(__fabsf((*(f32*)(p+0xc))-attackPos.x)<64.0f && __fabsf((*(f32*)(p+0x10))-attackPos.y)<64.0f) {
                    { u32 room=(*(u32*)(p+0x4)); e0.set((*(f32*)(p+0xc))-8.0f,(*(f32*)(p+0x10))-8.0f,0.0f); gateEffect(e0,i,room); }
{ u32 room=(*(u32*)(p+0x4)); e1.set(8.0f+(*(f32*)(p+0xc)),(*(f32*)(p+0x10))-8.0f,0.0f); gateEffect(e1,i,room); }
{ u32 room=(*(u32*)(p+0x4)); e2.set((*(f32*)(p+0xc))-8.0f,8.0f+(*(f32*)(p+0x10)),0.0f); gateEffect(e2,i,room); }
{ u32 room=(*(u32*)(p+0x4)); e3.set(8.0f+(*(f32*)(p+0xc)),8.0f+(*(f32*)(p+0x10)),0.0f); gateEffect(e3,i,room); }
                    if(p[0x255]==0) {
                        fn_8013CC50((*(u32*)(p+0x4)),p+0xc,lbl_8053FF78,0x3e3,0,-2,0,0,1);
                        p[0x255]=1;
                    }
                    break;
                }
            }
        }
    }
    if((*(u32*)(p+0x90))>>27) { if(!(u8)((Actor*)p)->v11()) return; }
    f32 x0=(*(f32*)(p+0x60)), y0=(*(f32*)(p+0x64)), x1=(*(f32*)(p+0x68)), y1=(*(f32*)(p+0x6c));
    xy.set((*(f32*)(p+0xc)),(*(f32*)(p+0x10)));
    u16 tile=fn_802265FC(&xy,(*(u32*)(p+0x4)));
    if(tile==1 || tile==0x21) return;
    if(p[0x255]==1) {
        u8* mgr=(u8*)fn_801902C0();
        if(*(s32*)(mgr+0x79c)<16) {
            u8* slot=mgr+0x61c+*(s32*)(mgr+0x79c)*24;
            *(f32*)(slot)=(*(f32*)(p+0xc)); *(f32*)(slot+4)=(*(f32*)(p+0x10)); *(f32*)(slot+8)=(*(f32*)(p+0x14));
            mgr[*(s32*)(mgr+0x79c)*24+0x628]=1;
            (*(s32*)(mgr+0x79c))++;
        }
    }
    x0+=xy.x; y0+=xy.y; x1+=xy.x; y1+=xy.y;
    if(((*(s32*)(p+0x90))&0x7f)==0x20) {
        boxA.x0=x0; boxA.y0=y0; boxA.x1=x1; boxA.y1=y1; fn_80227530(p,(f32*)&boxA);
    } else if(((*(s32*)(p+0x90))&0x7f)==0x24) {
        for(s32 j=0;j<4;j++) {
            if(*((u8*)lbl_8053AAF8+0x7e) && !fn_8022C8EC(j)) {
                if(fn_8023DE58(j)!=gateRoom((*(u32*)(p+0x90)))) continue;
            }
            playerBox.x0=x0; playerBox.y0=y0; playerBox.x1=x1; playerBox.y1=y1;
            if(((f32*)fn_8023E724(j))[1]>(*(f32*)(p+0x10))) {
                f32 dy=((f32*)fn_8023E724(j))[1]-(*(f32*)(p+0x10));
                playerBox.translate(0.0f,dy);
            }
            if(fn_8023B0F4(j,(f32*)&playerBox,(*(u32*)(p+0x4)),0,8.0f))
                {
                    int mapRoom,rawRoom;
                    u32 param=(*(u32*)(p+0x90));
                    rawRoom=(param>>24)&7;
                    u32 kind=param&0x7f;
                    mapRoom=rawRoom+7; if(!rawRoom) mapRoom=rawRoom;
                    fn_802317F0(j,mapRoom,p+0xc,p+0x238,kind);
                }
        }
    } else {
        boxB.x0=x0; boxB.y0=y0; boxB.x1=x1; boxB.y1=y1; fn_802278A8(p,(f32*)&boxB);
    }
    int rawRoom=((*(u32*)(p+0x90))>>24)&7;
    int mapRoom=rawRoom+7; if(!rawRoom) mapRoom=rawRoom;
    s32 t=(u16)fn_80226850(p+0x238,mapRoom);
    if(t==0x19c || t==0x19d) return;
    s32 id;
    s32 kind=(*(u32*)(p+0x90))&0x7f;
    if(kind==4 || kind==0x20 || kind==0x24) id=fn_801F26CC(p,gateHeavyTypes);
    else if(kind==6 || kind==11 || kind==20) id=fn_801F26CC(p,gateCarryTypes);
    else id=fn_80227290(p,lbl_8053FF60,lbl_8046ABE8,-1);
    if(id<0) return;
    u8* actor=(u8*)fn_801F666C(fn_801F856C(),id);
    if(!actor) return;
    kind=(*(u32*)(p+0x90))&0x7f;
    if((kind==0 || kind==3 || kind==0x15 || kind==0x23) && (*(f32*)(actor+0x40))>=0.0f) return;
    if((kind==1 || kind==2) && (*(f32*)(actor+0x40))<=0.0f) return;
    if(kind==0x17 && (*(f32*)(actor+0x3c))<=0.0f) return;
    if(kind==0x18) { if((*(f32*)(actor+0x3c))>=0.0f) goto done; }

    if((*(u32*)(actor+0x1a0))==0x424f4d45) {
        fn_8023DE58((*(u32*)(actor+0x90))&15);
        u8 same;
        if((*(s32*)(actor+0x230))==1 || gateVelocitySame(actor)) same=1; else same=0;
        if(same==1) return;
        kind=(*(u32*)(p+0x90))&0x7f;
        if(kind==4 || kind==0x20 || kind==0x24) {
            if((*(s32*)(actor+0x230))==1 || gateVelocitySame(actor)) same=1; else same=0;
            if(!same) return;
        }
    }
    if((*(u32*)(actor+0x1a0))==0x48424d42 || (*(u32*)(actor+0x1a0))==0x53544f4e || (*(u32*)(actor+0x1a0))==0x47524153 ||
       (*(u32*)(actor+0x1a0))==0x5455424f || (*(u32*)(actor+0x1a0))==0x59415349) {
        if(((JGeometry::TVec3f*)(actor+0x3c))->length()<=lbl_8053FF78) return;
        kind=(*(u32*)(p+0x90))&0x7f;
        if(kind==4 || (u32)(kind-7)<=2 || kind==0x12 || kind==0x20 || kind==0x24)
            if((*(f32*)(actor+0x14))>lbl_8053FF64) return;
    }
    if((*(u32*)(actor+0x1a0))==0x484e5259 || (*(u32*)(actor+0x1a0))==0x424f4d45 || (*(u32*)(actor+0x1a0))==0x5043444d ||
       (*(u32*)(actor+0x1a0))==0x5357424d || ((*(u32*)(actor+0x1a0))==0x46495245 && (((*(u32*)(actor+0x90))>>6)&7)!=1)) {
        kind=(*(u32*)(p+0x90))&0x7f;
        if((kind==4 || kind==0x20 || kind==0x24) && (*(f32*)(actor+0x14))>0.0f) return;
        delta=*(JGeometry::TVec3f*)(actor+0xc);
        dest=*(JGeometry::TVec3f*)(p+0x238);
        delta.x-=(*(f32*)(p+0xc)); delta.y-=(*(f32*)(p+0x10));
        dest.add(delta);
        fn_801F349C(actor,gateRoom((*(u32*)(p+0x90))),&dest);
    } else {
        if((*(u32*)(actor+0x1a0))==0x45535259) {
            kind=(*(u32*)(p+0x90))&0x7f;
            if(kind==0 || kind==3 || kind==0x15 || kind==0x23) {
                push0.set(0.0f,lbl_8053FF8C,0.0f);
                *(JGeometry::TVec3f*)(actor+0x3c)=push0;
            } else if(kind==1 || kind==2) {
                push1.set(0.0f,lbl_8053FF90,0.0f);
                *(JGeometry::TVec3f*)(actor+0x3c)=push1;
            } else if(kind==0x17) {
                push2.set(lbl_8053FF90,0.0f,0.0f);
                *(JGeometry::TVec3f*)(actor+0x3c)=push2;
            } else if(kind==0x18) {
                push3.set(lbl_8053FF8C,0.0f,0.0f);
                *(JGeometry::TVec3f*)(actor+0x3c)=push3;
            }
        }
        if((*(u32*)(actor+0x1a0))==0x46495245 && (((*(u32*)(actor+0x90))>>6)&3)==1) return;
        if(actor[0xc4]==0) fn_801F349C(actor,gateRoom((*(u32*)(p+0x90))),p+0x238);
    }
done:
    return;
}
#pragma peephole reset
extern "C" void* fn_80228AEC(void* this_, s16 freeFlag) {
    if (this_) {
        *(void**)this_ = lbl_804A6DC8;
        fn_801EE434(*(void**)((u8*)this_ + 0x24c));
        fn_801EE434(*(void**)((u8*)this_ + 0x250));
        __dt__5ActorFv(this_, 0);
        s32 f = freeFlag;
        if (f > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" s32 Actor_CreateByID(void* mgr, u32 type, s32 room, void* pos, u32 param, s32 a, s32 b);
extern const f32 lbl_8053FF94;
extern const f32 lbl_8053FF98;
extern const f32 lbl_8053FF9C;
extern const f32 lbl_8053FFA0;
extern const f32 lbl_8053FFA4;
extern const f32 lbl_8053FFA8;
extern const f32 lbl_8053FFAC;
extern const f32 lbl_8053FFB0;
extern const f32 lbl_8053FFB4;
extern const f32 lbl_8053FFB8;
extern "C" void fn_80228B60(void* this_) {
    u8* p = (u8*)this_;
    p[0x256] = 0;
    *(s32*)(p + 0x278) = 0;
    p[0x255] = 0;
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x280) = 0;
    *(s32*)(p + 0x284) = 0;
    *(s32*)(p + 0x288) = 0;
    if ((*(s32*)(p + 0x90) & 0x7f) == 0x20) {
        p[0x254] = 1;
    } else {
        p[0x254] = 0;
    }

    s32 dstRoom = gateRoom(*(s32*)(p + 0x90));
    u8* m1 = (u8*)fn_802D6A9C();
    f32* dstOff = (f32*)(dstRoom < 8 ? m1 + 0xcc : m1 + 0xdc);
    f32 dstX = dstOff[0];
    f32 dstY = dstOff[1];

    s32 srcRoom = *(s32*)(p + 4);
    u8* m2 = (u8*)fn_802D6A9C();
    f32* srcOff = (f32*)(srcRoom < 8 ? m2 + 0xcc : m2 + 0xdc);
    f32 srcX = srcOff[0];
    f32 srcY = srcOff[1];

    u32 param = *(u32*)(p + 0x90);
    s32 kind = (s32)(param & 0x7f);
    if ((kind == 6 || kind == 4 || kind == 0x20 || kind == 0x24) &&
        (((param >> 16) & 0x3f) * 8) == 0 && (((param >> 8) & 0x3f) * 8) == 0) {
        *(f32*)(p + 0x238) = dstX + (*(f32*)(p + 0xc) - srcX);
        *(f32*)(p + 0x23c) = dstY + (*(f32*)(p + 0x10) - srcY);
        *(f32*)(p + 0x240) = lbl_8053FF74;
    } else {
        f32 ox = (f32)(((param >> 16) & 0x3f) * 8);
        f32 oy = (f32)(((param >> 8) & 0x3f) * 8);
        *(f32*)(p + 0x238) = ox + dstX;
        *(f32*)(p + 0x23c) = oy + dstY;
        *(f32*)(p + 0x240) = lbl_8053FF74;
    }

    s32 room = *(s32*)(p + 4);
    s32 r = (room >= 8) ? room - 7 : 0;
    s32 prm = *(s32*)(p + 0x90);
    s32 tp = prm & 0x7f;
    s32 w;
    if (tp == 0x19) {
        s32 tx = (s32)(*(f32*)(p + 0xc) - srcX) / 8;
        s32 ty = (s32)(*(f32*)(p + 0x10) - srcY) / 8;
        w = ((r & 7) << 24) | (prm & ~0x07ffffff) | ((tx & 0xff) << 16) | ((ty & 0xff) << 8) | (((prm >> 7) & 1) << 7) | 1;
        s32 rm = gateRoom(prm);
        Actor_CreateByID(fn_801F856C(), 0x57415250, rm, p + 0x238, w, -1, -1);
        *(s32*)(p + 0x90) &= ~0xff;
    } else if (tp == 0x1a) {
        s32 tx = (s32)(*(f32*)(p + 0xc) - srcX) / 8;
        s32 ty = (s32)(*(f32*)(p + 0x10) - srcY) / 8;
        w = ((r & 7) << 24) | (prm & ~0x07ffffff) | ((tx & 0xff) << 16) | ((ty & 0xff) << 8) | (((prm >> 7) & 1) << 7) | 3;
        s32 rm = gateRoom(prm);
        Actor_CreateByID(fn_801F856C(), 0x57415250, rm, p + 0x238, w, -1, -1);
        *(s32*)(p + 0x90) = (*(s32*)(p + 0x90) & ~0xff) | 2;
    } else if (tp == 0x1b) {
        s32 tx = (s32)(*(f32*)(p + 0xc) - srcX) / 8;
        s32 ty = (s32)(*(f32*)(p + 0x10) - srcY) / 8;
        w = ((r & 7) << 24) | (prm & ~0x07ffffff) | ((tx & 0xff) << 16) | ((ty & 0xff) << 8) | (((prm >> 7) & 1) << 7) | 0x18;
        s32 rm = gateRoom(prm);
        Actor_CreateByID(fn_801F856C(), 0x57415250, rm, p + 0x238, w, -1, -1);
        *(s32*)(p + 0x90) = (*(s32*)(p + 0x90) & ~0xff) | 0x17;
    } else if (tp == 0x1c) {
        s32 tx = (s32)(*(f32*)(p + 0xc) - srcX) / 8;
        s32 ty = (s32)(*(f32*)(p + 0x10) - srcY) / 8;
        w = ((r & 7) << 24) | (prm & ~0x07ffffff) | ((tx & 0xff) << 16) | ((ty & 0xff) << 8) | (((prm >> 7) & 1) << 7) | 0x17;
        s32 rm = gateRoom(prm);
        Actor_CreateByID(fn_801F856C(), 0x57415250, rm, p + 0x238, w, -1, -1);
        *(s32*)(p + 0x90) = (*(s32*)(p + 0x90) & ~0xff) | 0x18;
    }

    if (((*(u32*)(p + 0x90) >> 7) & 1) == 0 && (*(s32*)(p + 0x90) & 0x7f) != 0x20) {
        *(f32*)(p + 0x238) += lbl_8053FF70;
        *(f32*)(p + 0x23c) += lbl_8053FF70;
    }

    if (((*(u32*)(p + 0x90) >> 7) & 1) == 0 &&
        (*(s32*)(p + 0x90) & 0x7f) != 0xb &&
        (*(s32*)(p + 0x90) & 0x7f) != 0x1e &&
        (*(s32*)(p + 0x90) & 0x7f) != 0x1f &&
        (*(s32*)(p + 0x90) & 0x7f) != 0x20) {
        *(f32*)(p + 0xc) += (f32)(s32)(lbl_8053FF70 - (f32)(((s32)*(f32*)(p + 0xc)) % 8));
        *(f32*)(p + 0x10) += (f32)(s32)(lbl_8053FF70 - (f32)(((s32)*(f32*)(p + 0x10)) % 8));
    }

    s32 t2 = *(s32*)(p + 0x90) & 0x7f;
    if (t2 == 6) {
        *(f32*)(p + 0x60) = lbl_8053FF94;
        *(f32*)(p + 0x64) = lbl_8053FF94;
        *(f32*)(p + 0x68) = lbl_8053FF98;
        *(f32*)(p + 0x6c) = lbl_8053FF98;
    } else if (t2 == 0xb) {
        *(f32*)(p + 0x60) = lbl_8053FF9C;
        *(f32*)(p + 0x64) = lbl_8053FF9C;
        *(f32*)(p + 0x68) = lbl_8053FF70;
        *(f32*)(p + 0x6c) = lbl_8053FF70;
    } else if (t2 == 0x20) {
        *(f32*)(p + 0x60) = lbl_8053FFA0;
        *(f32*)(p + 0x64) = lbl_8053FFA0;
        *(f32*)(p + 0x68) = lbl_8053FFA4;
        *(f32*)(p + 0x6c) = lbl_8053FFA4;
    } else if (t2 == 0) {
        *(f32*)(p + 0x60) = lbl_8053FFA8;
        *(f32*)(p + 0x64) = lbl_8053FF68;
        *(f32*)(p + 0x68) = lbl_8053FF64;
        *(f32*)(p + 0x6c) = lbl_8053FF64;
    } else if (t2 == 1) {
        *(f32*)(p + 0x60) = lbl_8053FFA8;
        *(f32*)(p + 0x64) = lbl_8053FFA8;
        *(f32*)(p + 0x68) = lbl_8053FF64;
        *(f32*)(p + 0x6c) = lbl_8053FF6C;
    } else if (t2 == 2) {
        *(f32*)(p + 0x60) = lbl_8053FFA8;
        *(f32*)(p + 0x64) = lbl_8053FFA8;
        *(f32*)(p + 0x68) = lbl_8053FF64;
        *(f32*)(p + 0x6c) = lbl_8053FF64;
    } else if (t2 == 3) {
        *(f32*)(p + 0x60) = lbl_8053FFA8;
        *(f32*)(p + 0x64) = lbl_8053FF68;
        *(f32*)(p + 0x68) = lbl_8053FF64;
        *(f32*)(p + 0x6c) = lbl_8053FF64;
    } else if (t2 == 0xf) {
        *(f32*)(p + 0x60) = lbl_8053FFAC;
        *(f32*)(p + 0x64) = lbl_8053FF9C;
        *(f32*)(p + 0x68) = lbl_8053FFB0;
        *(f32*)(p + 0x6c) = lbl_8053FF70;
    } else if (t2 == 0x13) {
        *(f32*)(p + 0x60) = lbl_8053FFB4;
        *(f32*)(p + 0x64) = lbl_8053FF9C;
        *(f32*)(p + 0x68) = lbl_8053FFB8;
        *(f32*)(p + 0x6c) = lbl_8053FF70;
    } else if (t2 == 0x16) {
        *(f32*)(p + 0x60) = lbl_8053FFAC;
        *(f32*)(p + 0x64) = lbl_8053FF9C;
        *(f32*)(p + 0x68) = lbl_8053FFB0;
        *(f32*)(p + 0x6c) = lbl_8053FF70;
    } else if (t2 == 0x15) {
        s32 r15 = *(s32*)(p + 4);
        u8* m15 = (u8*)fn_802D6A9C();
        if (m15[r15 + 0x131df]) {
            *(f32*)(p + 0x60) = lbl_8053FFA8;
            *(f32*)(p + 0x64) = lbl_8053FFA8;
            *(f32*)(p + 0x68) = lbl_8053FF64;
            *(f32*)(p + 0x6c) = lbl_8053FF64;
        } else if (*(s32*)(p + 4) >= 8) {
            *(f32*)(p + 0x60) = lbl_8053FFA8;
            *(f32*)(p + 0x64) = lbl_8053FFA8;
            *(f32*)(p + 0x68) = lbl_8053FF64;
            *(f32*)(p + 0x6c) = lbl_8053FF6C;
        } else {
            *(f32*)(p + 0x60) = lbl_8053FFA8;
            *(f32*)(p + 0x64) = lbl_8053FF68;
            *(f32*)(p + 0x68) = lbl_8053FF64;
            *(f32*)(p + 0x6c) = lbl_8053FF64;
        }
    } else if (t2 == 0x23) {
        s32 r23 = *(s32*)(p + 4);
        u8* m23 = (u8*)fn_802D6A9C();
        if (m23[r23 + 0x131df]) {
            *(f32*)(p + 0x60) = lbl_8053FFA8;
            *(f32*)(p + 0x64) = lbl_8053FFA8;
            *(f32*)(p + 0x68) = lbl_8053FF64;
            *(f32*)(p + 0x6c) = lbl_8053FF64;
        } else if (*(s32*)(p + 4) >= 8) {
            *(f32*)(p + 0x60) = lbl_8053FFA8;
            *(f32*)(p + 0x64) = lbl_8053FF68;
            *(f32*)(p + 0x68) = lbl_8053FF64;
            *(f32*)(p + 0x6c) = lbl_8053FF64;
        } else {
            *(f32*)(p + 0x60) = lbl_8053FFA8;
            *(f32*)(p + 0x64) = lbl_8053FFA8;
            *(f32*)(p + 0x68) = lbl_8053FF64;
            *(f32*)(p + 0x6c) = lbl_8053FF6C;
        }
    } else if (t2 == 0x17) {
        *(f32*)(p + 0x60) = lbl_8053FFA8;
        *(f32*)(p + 0x64) = lbl_8053FFA8;
        *(f32*)(p + 0x68) = lbl_8053FF64;
        *(f32*)(p + 0x6c) = lbl_8053FF64;
    } else if (t2 == 0x18) {
        *(f32*)(p + 0x60) = lbl_8053FFA8;
        *(f32*)(p + 0x64) = lbl_8053FFA8;
        *(f32*)(p + 0x68) = lbl_8053FF64;
        *(f32*)(p + 0x6c) = lbl_8053FF64;
    } else if (t2 == 4) {
        *(f32*)(p + 0x60) = lbl_8053FFBC;
        *(f32*)(p + 0x64) = lbl_8053FFBC;
        *(f32*)(p + 0x68) = lbl_8053FF78;
        *(f32*)(p + 0x6c) = lbl_8053FF78;
    } else if (t2 == 0x28) {
        *(f32*)(p + 0x60) = lbl_8053FFC0;
        *(f32*)(p + 0x64) = lbl_8053FFC0;
        *(f32*)(p + 0x68) = lbl_8053FFC4;
        *(f32*)(p + 0x6c) = lbl_8053FFC4;
    } else {
        *(f32*)(p + 0x60) = lbl_8053FFA8;
        *(f32*)(p + 0x64) = lbl_8053FFA8;
        *(f32*)(p + 0x68) = lbl_8053FF64;
        *(f32*)(p + 0x6c) = lbl_8053FF64;
    }

    if ((*(s32*)(p + 0x90) & 0x7f) == 0x28) {
        *(s32*)(p + 0x90) = (*(s32*)(p + 0x90) & ~0x7f) | 4;
    }

    *(s32*)(p + 0x108) = 0;
    *(s32*)(p + 0xb0) = 3;
    p[0x234] = 0;
    p[0x235] = 0;
    p[0x236] = 0;
    p[0x237] = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;

    if ((*(s32*)(p + 0x90) & 0x7f) == 0xe) {
        *(void**)(p + 0x24c) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053FF78, 0x553, 0, -1, 0, 0, 1);
        *(void**)(p + 0x250) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053FF78, 0x4ee, 0, 0, 0, 0, 1);
    }
    if ((*(s32*)(p + 0x90) & 0x7f) == 0x25) {
        *(void**)(p + 0x24c) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053FF78, 0x553, -1, -1, 0, 0, 1);
        *(void**)(p + 0x250) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053FF78, 0x4ee, 0, 0, 0, 0, 1);
    }

    *(s32*)(p + 0x244) = *(s32*)((u8*)fn_802D6A9C() + 0x14);
    *(s32*)(p + 0x248) = *(s32*)((u8*)fn_802D6A9C() + 0x18);
    *(f32*)(p + 0x258) = lbl_8053FF74;
    *(f32*)(p + 0x268) = lbl_8053FF74;
    *(f32*)(p + 0x25c) = lbl_8053FF74;
    *(f32*)(p + 0x26c) = lbl_8053FF74;
    *(f32*)(p + 0x260) = lbl_8053FF74;
    *(f32*)(p + 0x270) = lbl_8053FF74;
    *(f32*)(p + 0x264) = lbl_8053FF74;
    *(f32*)(p + 0x274) = lbl_8053FF74;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
