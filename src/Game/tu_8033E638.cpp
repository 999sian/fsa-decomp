#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/ItemBase.h"
#include "math.h"

extern "C" const float lbl_80542210;
extern "C" const float lbl_8054221C;
extern "C" const float lbl_80542224;
extern "C" const float lbl_8054222C;
extern "C" const f64 lbl_80542238;


extern "C" const float lbl_80542228;
extern "C" f32 PSVECDistance(const Vec* a, const Vec* b);
extern "C" char lbl_804AC330[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8033E638(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AC330;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void PSMTXIdentity(f32 (*)[4]);
extern "C" const f32 lbl_80542214, lbl_80542218, lbl_80542220;
extern "C" const char lbl_80471E98[];
extern "C" void fn_801F06F0(Actor*,const char*,s32,DrawRec*,s32,f32,f32);
extern "C" void fn_8033E698(Actor* self) {
 u8* p=(u8*)self;
 if (*(f32*)(p+0x240) <= lbl_80542210) return;
 DrawRec rec;
 f32 m[3][4];
 PSMTXIdentity(m);
 if (*(s32*)(p+0x244)==0) {
 f32 sasb; f32 cc; f32 casc,a0,a1,a2,a3,a4,a5,a6,a7,a8; f32 cacc;
 f32 sa,sb,sc,ca,cb,scale;
 f32 angle = lbl_80542214 * (lbl_80542218 * (lbl_8054221C - *(f32*)(p+0x240)));
 scale = lbl_80542220 * *(f32*)(p+0x240);
 sa=sin(lbl_80542210); sb=sin(angle); sc=sin(lbl_80542210);
 ca=cos(lbl_80542210); cb=cos(angle); cc=cos(lbl_80542210);
 cacc=ca*cc; sasb=sa*sb; casc=ca*sc;
 a0=cb*cc; a1=cb*sc; a2=-sb; a3=sasb*cc-casc; a4=sasb*sc+cacc;
 a5=sa*cb; a6=cacc*sb+sa*sc; a7=casc*sb-sa*cc; a8=ca*cb;
 m[0][0]=scale*a0; m[1][0]=scale*a1; m[2][0]=scale*a2;
 m[0][1]=scale*a3; m[1][1]=scale*a4; m[2][1]=scale*a5;
 m[0][2]=scale*a6; m[1][2]=scale*a7; m[2][2]=scale*a8;
}
 else {
 f32 sasb; f32 cc; f32 casc,a0,a1,a2,a3,a4,a5,a6,a7,a8; f32 cacc;
 f32 sa,sb,sc,scale,ca,cb;
 cb = lbl_80542214 * (lbl_80542218 * (lbl_8054221C - *(f32*)(p+0x240)));
 scale = *(f32*)(p+0x240);
 sa=sin(lbl_80542210); sb=sin(cb); sc=sin(lbl_80542210);
 ca=cos(lbl_80542210); cb=cos(cb); cc=cos(lbl_80542210);
 cacc=ca*cc; sasb=sa*sb; casc=ca*sc;
 a0=cb*cc; a1=cb*sc; a2=-sb; a3=sasb*cc-casc; a4=sasb*sc+cacc;
 a5=sa*cb; a6=cacc*sb+sa*sc; a7=casc*sb-sa*cc; a8=ca*cb;
 m[0][0]=scale*a0; m[1][0]=scale*a1; m[2][0]=scale*a2;
 m[0][1]=scale*a3; m[1][1]=scale*a4; m[2][1]=scale*a5;
 m[0][2]=scale*a6; m[1][2]=scale*a7; m[2][2]=scale*a8;
}
 rec.w18=m; rec.b20=0; rec.b21=1;
 ((volatile DrawRec*)&rec)->b1c=0; rec.b1d=-3;
 fn_801F06F0(self,lbl_80471E98,*(s32*)(p+0x244)+0x172,&rec,-1,lbl_8054221C,lbl_8054221C);
}

extern "C" void fn_8023DEDC(int, const JGeometry::TVec3<f32>*);
extern "C" void fn_8022CB94(int);
extern "C" void fn_8022DF48(int);
extern "C" void* fn_8023E724(int);
extern "C" void fn_8022E088(int, int, JGeometry::TVec2<f32>*);
extern "C" int fn_8023DE58(int);
extern "C" const f32 lbl_80542230, lbl_80542234;
struct FsaVirtBase {
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
    virtual u8 v11();
    virtual void v12();
    virtual s32 v15();
};
static inline void movePlatformPlayer(int player, const JGeometry::TVec3<f32>& delta) {
    fn_8023DEDC(player, &delta);
}

static inline u8 platformContains(const f32* bounds, const JGeometry::TVec3<f32>& point) {
    f32 minX, maxY, minY, maxX;
    BOOL inside;
    minX = bounds[0];
    minY = bounds[1];
    maxX = bounds[2];
    maxY = bounds[3];
    inside = FALSE;
    if (point.x >= minX && point.y >= minY && point.x < maxX && point.y < maxY) inside = 1;
    return inside;
}

static inline u8 platformHasPlayer(u8* p, int player, int room) {
    int actualRoom = fn_8023DE58(player);
    if (actualRoom != room) return 0;
    for (int j = 0; j < 8; ++j) {
        JGeometry::TVec3<f32> point;
        fn_8022E088(player, j, (JGeometry::TVec2<f32>*)&point);
        point -= *(JGeometry::TVec3<f32>*)(p + 0xc);
        point.z = 0.0f;
        f32 angleF = JMath::atanTable_.atan2_(point.y, point.x);
        angleF *= lbl_80542230;
        s32 angle = (s32)angleF;
        f32 xx = point.x * point.x;
        f32 yy = point.y * point.y;
        f32 length = JGeometry::TUtilf::sqrt(xx + yy);
        point.set(length * JMath::sincosTable_.cosShort(angle), length * JMath::sincosTable_.sinShort(angle), 0.0f);
        if (platformContains((f32*)(p + 0x60), point)) {
            fn_8022DF48(player);
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_8033EA54(u8* p) {
    u8 hit;
    s32 room;
    int player;
    if (*(s32*)(p + 0x230) == 1) {
        ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
    }
    if (((FsaVirtBase*)p)->v15() > 0 && !((FsaVirtBase*)p)->v11()) {
        *(s32*)(p + 0x230) = 2;
    }
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        s32 speed = *(s32*)(p + 0x248);
        if (speed == 0 || *(s32*)(p + 0x24c) > 0) break;
        switch (*(s32*)(p + 0x254)) {
        case 0:
            *(f32*)(p + 0x3c) = lbl_80542224 * (f32)speed;
            *(f32*)(p + 0x40) = lbl_80542210;
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        case 1:
            *(f32*)(p + 0x3c) = lbl_80542224 * -(f32)speed;
            *(f32*)(p + 0x40) = lbl_80542210;
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        case 2:
            *(f32*)(p + 0x3c) = lbl_80542210;
            *(f32*)(p + 0x40) = lbl_80542224 * (f32)speed;
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        case 3:
            *(f32*)(p + 0x3c) = lbl_80542210;
            *(f32*)(p + 0x40) = lbl_80542224 * -(f32)speed;
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        }
        *(s32*)(p + 0x24c) = 1;
        *(s32*)(p + 0x230) = 1;
        break;
    }
    case 1: {
        if (*(s32*)(p + 0x254) == *(s32*)(p + 0x250)) {
            const JGeometry::TVec3<f32>& target = *(JGeometry::TVec3<f32>*)(p + 0x24) + *(JGeometry::TVec3<f32>*)(p + 0x234);
            if (PSVECDistance((Vec*)(p + 0xc), &target) >= lbl_80542228 * (f32)*(s32*)(p + 0x258)) goto stop;
        }
        if (*(s32*)(p + 0x254) != *(s32*)(p + 0x250)) {
            const JGeometry::TVec3<f32>& target = *(JGeometry::TVec3<f32>*)(p + 0x24) + *(JGeometry::TVec3<f32>*)(p + 0x234);
            if (PSVECDistance((Vec*)(p + 0xc), &target) <= lbl_80542210) {
stop:
                *(f32*)(p + 0x44) = lbl_80542210;
                *(f32*)(p + 0x40) = lbl_80542210;
                *(f32*)(p + 0x3c) = lbl_80542210;
                *(s32*)(p + 0x254) ^= 1;
                *(s32*)(p + 0x24c) = 60;
                *(s32*)(p + 0x230) = 0;
            }
        }
        if (*(s32*)(p + 0x24c) == 0) *(s32*)(p + 0x24c) = 16;
        break;
    }
    case 2:
        if (((FsaVirtBase*)p)->v11() == 1) {
            if (*(f32*)(p + 0x240) < lbl_8054221C) {
                *(f32*)(p + 0x240) += lbl_8054222C;
                if (*(f32*)(p + 0x240) >= lbl_8054221C) {
                    *(f32*)(p + 0x240) = lbl_8054221C;
                    *(s32*)(p + 0x230) = 0;
                }
            }
        } else {
            if (*(f32*)(p + 0x240) > lbl_80542210) {
                *(f32*)(p + 0x240) -= lbl_8054222C;
                if (*(f32*)(p + 0x240) <= lbl_80542210) *(f32*)(p + 0x240) = lbl_80542210;
            }
        }
        return;
    }
    if (p[0x262] != 0) {
        *(f32*)(p + 0x10) -= *(f32*)(p + 0x238);
        *(u16*)(p + 0x25c) += 0x800;
        *(f32*)(p + 0x238) = JMath::sincosTable_.sinShort(*(u16*)(p + 0x25c));
        *(f32*)(p + 0x10) += *(f32*)(p + 0x238);
        if (*(u16*)(p + 0x25c) == 0) {
            *(f32*)(p + 0x238) = lbl_80542210;
            p[0x262] = 0;
        }
    }
    for (player = 0; player < 4; ++player) {
        room = *(s32*)(p + 4);
        hit = platformHasPlayer(p, player, room);
        if (hit && ((JGeometry::TVec3<f32>*)fn_8023E724(player))->z <= lbl_80542210) {
            movePlatformPlayer(player, *(JGeometry::TVec3<f32>*)(p + 0xc) - *(JGeometry::TVec3<f32>*)(p + 0x18));
            for (int j = 0; j < 3; ++j) fn_8022CB94(player);
        }
        if (((JGeometry::TVec3<f32>*)fn_8023E724(player))->z > lbl_80542210) hit = 0;
        if (hit != p[0x25e + player]) p[0x262] = 1;
        p[0x25e + player] = hit;
    }
    if (*(s32*)(p + 0x24c) > 0) --*(s32*)(p + 0x24c);
}

extern "C" const float lbl_80542210;
extern "C" const float lbl_8054221C;
extern "C" const float lbl_80542240;
extern "C" const float lbl_80542244;
extern "C" const float lbl_80542248;
extern "C" const float lbl_8054224C;
extern "C" const float lbl_80542250;
extern "C" const float lbl_80542254;
extern "C" const float lbl_80542224;
extern "C" const float lbl_80542228;
extern "C" const float lbl_8054222C;
extern "C" const float lbl_80542230;
extern "C" const float lbl_80542234;
extern "C" const f64 lbl_80542238;
extern "C" void PSVECAdd(const Vec* a, const Vec* b, Vec* c);
extern "C" void fn_8023DEDC(int, const JGeometry::TVec3<f32>*);
extern "C" void fn_8022CB94(int);
extern "C" void fn_8022DF48(int);
extern "C" void* fn_8023E724(int);
extern "C" void fn_8022E088(int, int, JGeometry::TVec2<f32>*);
extern "C" int fn_8023DE58(int);


extern "C" void fn_8033F0E8(u8* this_) {
    *(u8*)(this_ + 0x25e) = 0;
    *(u8*)(this_ + 0x25f) = 0;
    *(u8*)(this_ + 0x260) = 0;
    *(u8*)(this_ + 0x261) = 0;
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x254) = *(u32*)(this_ + 0x250);
    *(u32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 12) & 0xff;
    *(u32*)(this_ + 0x24c) = 0;
    *(u16*)(this_ + 0x25c) = 0;
    *(u8*)(this_ + 0x262) = 0;
    *(f32*)(this_ + 0x23c) = lbl_80542210;
    *(f32*)(this_ + 0x238) = lbl_80542210;
    *(f32*)(this_ + 0x234) = lbl_80542210;
    *(f32*)(this_ + 0x240) = lbl_8054221C;
    *(s32*)(this_ + 0x230) = 0;

    if (((FsaVirtBase*)this_)->v15() > 0) {
        *(s32*)(this_ + 0x230) = 2;
        *(f32*)(this_ + 0x240) = lbl_80542210;
    }

    switch (*(s32*)(this_ + 0x244)) {
    case 0:
        *(f32*)(this_ + 0x60) = lbl_80542240;
        *(f32*)(this_ + 0x64) = lbl_80542240;
        *(f32*)(this_ + 0x68) = lbl_80542244;
        *(f32*)(this_ + 0x6c) = lbl_80542244;
        break;
    case 1:
        *(f32*)(this_ + 0x60) = lbl_80542248;
        *(f32*)(this_ + 0x64) = lbl_80542248;
        *(f32*)(this_ + 0x68) = lbl_8054224C;
        *(f32*)(this_ + 0x6c) = lbl_8054224C;
        break;
    case 2:
        *(f32*)(this_ + 0x60) = lbl_80542250;
        *(f32*)(this_ + 0x64) = lbl_80542250;
        *(f32*)(this_ + 0x68) = lbl_80542254;
        *(f32*)(this_ + 0x6c) = lbl_80542254;
        break;
    }
}

extern "C" void fn_8033F224(void) {
}

