

#include "types.h"
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" u32 lbl_804ADB60[];


extern "C" f32 lbl_80542B80;
extern "C" f32 lbl_80542B84;
extern "C" const s32 lbl_804745A8[];
extern "C" const s32 lbl_80474BC4[];
#include "JSystem/JGeometry/Vec.h"
extern "C" s8 lbl_8053AD50;
extern "C" s8 lbl_8053AD51;
extern "C" JGeometry::TVec3<f32> lbl_8050C0B8[3];
extern "C" JGeometry::TVec3<f32> lbl_8050C0DC[3];
extern "C" const s32 lbl_80474A5C[];
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

struct Anim80363880 {
    char pad[0x268];
    s32 frame;
    s32 animation;
    s8* durations;
    s8* frames;
};

struct ActorList80362634 {
    u32 pad[2];
    char* actors[0x400];
    s32 count;
    char* getActor(const s32& index) { return actors[index]; }
    s32 getCount() const { return count; }
};

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" const char lbl_80474BFC[];
extern "C" const f32 lbl_80542B10;

extern "C" void* fn_8013C824(void);
extern "C" void* fn_801F856C(void);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" const s32 lbl_80474B58[];
extern "C" const s32 lbl_80474B68[];
extern "C" f32 lbl_80542B28;
extern "C" f32 lbl_80542B50;
extern "C" f32 lbl_80542B58;
extern "C" f32 lbl_80542BBC;
extern "C" f32 lbl_80542BC0;
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, void* prm);
extern "C" void* lbl_8053AB10;
extern "C" const char lbl_80474C10[];
extern "C" const s32 lbl_80474B88[];
extern "C" const s32 lbl_80474BA0[];
extern "C" const s32 lbl_80474320[];
extern "C" f32 lbl_80542B5C;
extern "C" f32 lbl_80542B60;
extern "C" f32 lbl_80542B64;
extern "C" f32 lbl_80542B68;
extern "C" f32 lbl_80542B6C;
extern "C" f32 lbl_80542B70;
extern "C" void* fn_8013CC50(u32 id, void* pos, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119958(void);
extern "C" s32 fn_8030AAF4(s32);
extern "C" u32 fn_80309D6C(void*, s32, u32);
extern void* lbl_8053AD30;
extern void* lbl_8053AAF8;
extern "C" void fn_8013670C(void*, s32);
extern "C" const u16 lbl_80542AF0[4];
extern "C" f32 lbl_80542AF8;
extern "C" f32 lbl_80542AFC;
extern "C" f32 lbl_80542B00;
extern "C" f32 lbl_80542B04;
extern "C" f32 lbl_80542B08;

static inline void fn_80362C44_deleteEmitter(void*& emitter) {
    if (emitter != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, emitter);
        emitter = NULL;
    }
}

static u32 fn_80362C44_findPlayer() {
    for (s32 i = 0; i < 4; i++) {
        u32 found = fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100);
        if (found != 0) {
            return found;
        }
    }
    return 0;
}

struct Unk80365AB8;
typedef void (Unk80365AB8::*Unk80365AB8Func)();
extern Unk80365AB8Func lbl_804ADDE8[];
extern Unk80365AB8Func lbl_804ADC38[];
extern "C" f32 lbl_80542BD4;
extern "C" f32 lbl_80542B0C;
extern "C" f32 lbl_80542BC4;
extern "C" f32 lbl_80542B8C;
extern "C" f32 lbl_80542BC8;
extern "C" f32 lbl_80542B54;
extern "C" const f32 lbl_80542B20;
extern "C" f32 lbl_80542B24;
extern "C" f32 lbl_80542B28;
extern "C" f32 lbl_80542B2C;
extern "C" f32 lbl_80542B30;
extern "C" f32 lbl_80542B34;
extern "C" f32 lbl_80542B38;
extern "C" f32 lbl_80542B3C;
extern "C" f32 lbl_80542B40;
extern "C" f32 lbl_80542B44;
extern "C" f32 lbl_80542B48;
extern "C" const f32 lbl_80542B4C;
extern "C" f32 lbl_80542BB4;
extern "C" f32 lbl_80542BB8;
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801CD664(s32 n);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);



static bool fn_80364340_isBadPos(Vec* p, Vec& v1) {
    if (p->x < lbl_80542B20 || p->x > lbl_80542B24) {
        return true;
    }
    if (p->y < lbl_80542B28 || p->y > lbl_80542B2C) {
        return true;
    }
    if (p->x + p->y < lbl_80542B30) {
        return true;
    }
    if (p->x > lbl_80542B34 && p->y < lbl_80542B38) {
        return true;
    }
    v1.x = lbl_80542B3C;
    v1.y = lbl_80542B38;
    v1.z = lbl_80542B0C;
    if (PSVECDistance(p, &v1) < lbl_80542B40) {
        return true;
    }
    v1.x = lbl_80542B44;
    v1.y = lbl_80542B48;
    v1.z = lbl_80542B0C;
    if (PSVECDistance(p, &v1) < lbl_80542B40) {
        return true;
    }
    return false;
}


extern "C" const s32 lbl_80474A98[];
extern "C" const s32 lbl_80474AD8[];
extern "C" const s32 lbl_80474858[];
extern "C" u8 lbl_80542AD8[8];
extern "C" u8 lbl_80542AC8[4];
extern "C" f32 lbl_80542B88;
extern "C" f32 lbl_80542B90;

static void fn_80363880_reset(char* self) {
    *(s32*)(self + 0x24c) = -1;
    f32 zero = 0.0f;
    *(f32*)(self + 0x44) = zero;
    *(f32*)(self + 0x40) = zero;
    *(f32*)(self + 0x3c) = zero;
    *(s32*)(self + 0x264) = 1;
    *(s32*)(self + 0x268) = 0;
    *(s32*)(self + 0x248) = 0x20;
}

static s32 fn_80363880_quadrant(u16 a) {
    if (a >= 0x2000 && a < 0x6000) {
        return 0;
    }
    if (a >= 0x6000 && a < 0xa000) {
        return 2;
    }
    if (a >= 0xa000 && a < 0xe000) {
        return 1;
    }
    return 3;
}

static void fn_80363880_aim(char* self, f32 dy, f32 dx, const f32 speed) {
    f32 angle = JMath::atanTable_.atan2_(dy, dx);
    f32 value = speed;
    *(s16*)(self + 0x240) = (s16)(s32)(angle * lbl_80542B50);
    *(f32*)(self + 0x3c) = value * JMath::sincosTable_.mTable[(u16)*(s16*)(self + 0x240) >> 5].second;
    *(f32*)(self + 0x40) = value * JMath::sincosTable_.mTable[(u16)*(s16*)(self + 0x240) >> 5].first;
}

static void fn_80363880_setQuadrant(char* self) {
    f32 ang = JMath::atanTable_.atan2_(*(f32*)(self + 0x40), *(f32*)(self + 0x3c));
    u16 a = (u16)(s32)(ang * lbl_80542B50);
    if (a >= 0x2000 && a < 0x6000) *(s32*)(self + 0x23c) = 0;
    else if (a >= 0x6000 && a < 0xa000) *(s32*)(self + 0x23c) = 2;
    else if (a >= 0xa000 && a < 0xe000) *(s32*)(self + 0x23c) = 1;
    else *(s32*)(self + 0x23c) = 3;
    *(s32*)(self + 0x26c) = lbl_80474858[*(s32*)(self + 0x23c)];
}

extern "C" void fn_80362634(char* self) {
    if (*(void**)(self + 0x300) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(self + 0x300));
        *(void**)(self + 0x300) = NULL;
    }
}

#pragma opt_propagation off
extern "C" void fn_80362680(char* self) {
    const char* names = (const char*)lbl_80474320;
    struct {
        u8 unk_0x0[16];
        s32 unk_0x10;
        s32 unk_0x14;
        void* unk_0x18;
        u8 unk_0x1c;
        u8 unk_0x1d;
        u8 unk_0x1e;
        u8 unk_0x1f;
        u8 unk_0x20;
        u8 unk_0x21[5];
        u8 unk_0x26;
        s32 unk_0x28;
        u8 unk_0x2c;
        u8 unk_0x2d[2];
        s32 unk_0x30;
        s32 unk_0x34;
        s32 unk_0x38;
    } p;
    f32 vecs[12];
    s32 i;

    p.unk_0x10 = -1;
    p.unk_0x14 = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        p.unk_0x0[(u8)i] = (u8)i;
        p.unk_0x0[(u8)(i + 1)] = (u8)(i + 1);
        p.unk_0x0[(u8)(i + 2)] = (u8)(i + 2);
        p.unk_0x0[(u8)(i + 3)] = (u8)(i + 3);
        p.unk_0x0[(u8)(i + 4)] = (u8)(i + 4);
        p.unk_0x0[(u8)(i + 5)] = (u8)(i + 5);
        p.unk_0x0[(u8)(i + 6)] = (u8)(i + 6);
        p.unk_0x0[(u8)(i + 7)] = (u8)(i + 7);
    }
    p.unk_0x10 = -1;
    p.unk_0x14 = 0;
    p.unk_0x18 = NULL;
    p.unk_0x1c = 0;
    p.unk_0x1d = 0;
    p.unk_0x1e = 0;
    p.unk_0x1f = 1;
    p.unk_0x20 = 1;
    p.unk_0x21[0] = 0;
    p.unk_0x21[1] = 0;
    p.unk_0x21[2] = 0;
    p.unk_0x21[3] = 0;
    p.unk_0x21[4] = 0;
    p.unk_0x26 = 1;
    p.unk_0x28 = 3;
    p.unk_0x2c = 1;
    p.unk_0x2d[0] = 0;
    p.unk_0x2d[1] = 0;
    p.unk_0x30 = -1;
    p.unk_0x34 = 0;
    p.unk_0x38 = 2;
    p.unk_0x1f = 0;

    if (*(s32*)(self + 0x234) == 0x10 || *(s32*)(self + 0x234) == 8) {
        p.unk_0x1d = 1;
    }
    if (*(s32*)(self + 0x234) == 4) {
        if (*(s32*)(self + 0x238) == 0x1d || *(s32*)(self + 0x238) == 0x1e) {
            p.unk_0x26 = 0;
        }
        if (*(s32*)(self + 0x238) >= 0x26 && *(s32*)(self + 0x238) <= 0x29) {
            *((u8*)&p.unk_0x10 + 3) = 0x66;
        }
    }
    if (*(u8*)(self + 0x278) == 1) {
        f32 b;
        f32 c;
        f32 a;
        a = lbl_80542B0C;
        b = lbl_80542B10;
        c = lbl_80542B5C;
        vecs[3] = a; vecs[7] = a; vecs[11] = a;
        vecs[0] = c; vecs[1] = a; vecs[2] = a;
        vecs[4] = a; vecs[5] = b; vecs[6] = a;
        vecs[8] = a; vecs[9] = a; vecs[10] = b;
        p.unk_0x18 = vecs;
    }
    if (*(s32*)(self + 0x258) == 0) {
        fn_801F06F0(self, names + 0x8b4, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), (s32)&p, 7, lbl_80542B10, lbl_80542B10);
    } else if (*(s32*)(self + 0x258) == 1) {
        fn_801F06F0(self, names + 0x8c8, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), (s32)&p, 7, lbl_80542B10, lbl_80542B10);
    } else if (*(s32*)(self + 0x258) == 2) {
        fn_801F06F0(self, names + 0x8dc, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), (s32)&p, 7, lbl_80542B10, lbl_80542B10);
    }
}
#pragma opt_propagation reset
extern "C" f32 lbl_80474BB8[];
extern "C" const char lbl_80474BD4[];
extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);
#pragma opt_propagation off
extern "C" void fn_803628D4(char* self) {
 JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(self + 0xc);
 Mtx mtxB;
 DrawRec p;
 Mtx mtxA;
 if ((*(s32*)(self + 0x268) & 7) >= 5) {
  f32 one;
  f32 zero;
  one = lbl_80542B10;
  zero = lbl_80542B0C;
  mtxA[0][3] = zero; mtxA[1][3] = zero; mtxA[2][3] = zero;
  mtxA[0][0] = one; mtxA[0][1] = zero; mtxA[0][2] = zero;
  mtxA[1][0] = zero; mtxA[1][1] = one; mtxA[1][2] = zero;
  mtxA[2][0] = zero; mtxA[2][1] = zero; mtxA[2][2] = lbl_80542B5C;
  p.w18 = mtxA;
  *(f32*)(self + 0x10) -= lbl_80474BB8[(*(s32*)(self + 0x268) & 7) - 5];
 }
 fn_801F06F0(self,lbl_80474BD4,*(s32*)(self+0x26c)+*(s32*)(self+0x264),(s32)&p,-1,lbl_80542B10,lbl_80542B10);
 *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
 mtxB[0][0] = lbl_80542B10; mtxB[0][1] = lbl_80542B0C; mtxB[0][2] = lbl_80542B0C;
 mtxB[1][0] = lbl_80542B0C; mtxB[1][1] = lbl_80542B10; mtxB[1][2] = lbl_80542B0C;
 mtxB[2][0] = lbl_80542B0C; mtxB[2][1] = lbl_80542B0C; mtxB[2][2] = lbl_80542B10;
 p.w18 = mtxB;
 s32 id = *(s32*)(self+0x26c)+*(s32*)(self+0x264);
 if (*(void**)(self+0x138)==0)
 fn_801EF830(*(s32*)(self+4),(f32*)(self+0xc),(u8*)&p,7,(u8*)lbl_80474BD4,id,0);
}
#pragma opt_propagation reset
extern "C" void fn_80362B14(char* self) {
    void* tex = fn_804032E8(0x54494d47, lbl_80474C10);
    if (*(s32*)(self + 4) < 8) {
        fn_802F745C(*(void**)((char*)lbl_8053AB10 + 0x20), self + 0xc, tex, NULL);
    }
}

extern "C" void fn_80362B74(char* self) {
    Vec saved;
    s32 i;
    fn_801F06F0(self, lbl_80474BFC, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), 0, 7, 1.0f, 1.0f);
    JGeometry::setTVec3f((f32*)(self + 0xc), (f32*)&saved);
    for (i = 0; i < 3; i++) {
        JGeometry::setTVec3f((f32*)(self + 0x27c + i * 0xc), (f32*)(self + 0xc));
        fn_801F06F0(self, lbl_80474BFC, *(s32*)(self + 0x2e8 + i * 4) + *(s32*)(self + 0x264), 0, 7, 1.0f, 1.0f);
    }
    JGeometry::setTVec3f((f32*)&saved, (f32*)(self + 0xc));
}

extern "C" void fn_80362C44(char* self) {
    int i;
    u16* ids;
    char* p;
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(self + 0xc);
    BOOL handled = FALSE;
    switch (*(u32*)(self + 0x238)) {
    case 0:
        if (*(s32*)(self + 0x248) == 0) {
            *(s32*)(self + 0x26c) = 0x9b;
            *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
            *(f32*)(self + 0x3c) = 0.6f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x2f8) = 0.0f;
            (*(s32*)(self + 0x238))++;
        }
        break;
    case 1:
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
            (*(s32*)(self + 0x264))++;
            *(s32*)(self + 0x264) &= 7;
        }
        *(f32*)(self + 0x2f8) += *(f32*)(self + 0x3c);
        if (*(f32*)(self + 0x2f8) >= 160.0f) {
            (*(s32*)(self + 0x238))++;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x40) = -0.6f;
            *(f32*)(self + 0x44) = 0.0f;
            *(s32*)(self + 0x26c) = 0xb3;
            *(f32*)(self + 0x2f8) = 0.0f;
        }
        break;
    case 2:
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
            (*(s32*)(self + 0x264))++;
            *(s32*)(self + 0x264) &= 7;
        }
        *(f32*)(self + 0x2f8) += JMAAbs(*(f32*)(self + 0x40));
        if (*(f32*)(self + 0x2f8) >= 160.0f) {
            (*(s32*)(self + 0x238))++;
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(s32*)(self + 0x264) = 0;
            *(s32*)(self + 0x248) = 0x3c;
        }
        break;
    case 3:
        if (*(s32*)(self + 0x248) == 0) {
            *(s32*)(self + 0x248) = 0x5c;
            *(u8*)(*(char**)(self + 0x2fc) + 0x294) = 1;
            (*(s32*)(self + 0x238))++;
        }
        break;
    case 4:
        if (*(s32*)(self + 0x248) != 0) {
            if (*(s32*)(self + 0x248) >= 0x3c) {
                pos.y -= (f32)(0x20 - (*(s32*)(self + 0x248) - 0x3c));
            } else {
                pos.y -= 32.0f;
            }
            if (*(s32*)(self + 0x248) == 1) {
                *(f32*)(self + 0x3c) = 0.0f;
                *(f32*)(self + 0x40) = -0.4f;
                *(f32*)(self + 0x44) = 0.0f;
                *(s32*)(self + 0x26c) = 0xb3;
                *(f32*)(self + 0x2f8) = 0.0f;
            }
            break;
        }
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
            (*(s32*)(self + 0x264))++;
            *(s32*)(self + 0x264) &= 7;
        }
        handled = TRUE;
        *(f32*)(self + 0x2f8) += JMAAbs(*(f32*)(self + 0x40));
        if (*(f32*)(self + 0x2f8) >= 80.0f) {
            JGeometry::TVec3<f32> v;
            *(s32*)(self + 0x248) = 0x12c;
            *(f32*)(self + 0x250) = *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x2c) + 0xc);
            *(f32*)(self + 0x254) = *(f32*)(self + 0x250) / *(s32*)(self + 0x248);
            f32 y = 384.0f * (s32)(*(f32*)(self + 0x10) / 384.0f) + 192.0f;
            f32 x = 512.0f * (s32)(*(f32*)(self + 0xc) * 0.001953125f) + 256.0f;
            v.z = 0.0f;
            v.y = y;
            v.x = x;
            p = self;
            ids = (u16*)lbl_80542AF0;
            for (i = 0; i < 4; i++) {
                fn_8013CC50(0, &v, 1.0f, *ids, 0, 0, 0, 0, 1);
                fn_80362C44_deleteEmitter(*(void**)(p + 0x30c));
                p += 4;
                ids++;
            }
            v.z = 0.0f;
            v.y = 0.0f;
            v.x = 0.0f;
            fn_8013CC50(0, &v, 1.0f, 0x55a, 0, 0, 0, 0, 1);
            fn_8013CC50(0, &v, 1.0f, 0x55b, 0, 0, 0, 0, 1);
            fn_8013CC50(0, &v, 1.0f, 0x55c, 0, 0, 0, 0, 1);
            fn_8013CC50(0, &v, 1.0f, 0x55d, 0, 0, 0, 0, 1);
            fn_8013CC50(0, &v, 1.0f, 0x55e, 0, 0, 0, 0, 1);
            *(void**)(self + 0x304) = fn_8013CC50(0, &v, 1.0f, 0x558, 0, 0, 0, 0, 1);
            *(void**)(self + 0x308) = fn_8013CC50(0, &v, 1.0f, 0x559, 0, 0, 0, 0, 1);
            (*(s32*)(self + 0x238))++;
        }
        break;
    case 5:
        handled = TRUE;
        if (*(f32*)(self + 0x250) > 0.0f) {
            *(f32*)(self + 0x250) -= *(f32*)(self + 0x254);
            if (*(f32*)(self + 0x250) <= 0.0f) {
                *(f32*)(self + 0x250) = 0.0f;
                *(f32*)(self + 0x254) = 0.0f;
            }
        }
        *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x2c) + 0xc) = (s32)*(f32*)(self + 0x250);
        if (*(s32*)(self + 0x248) == 0) {
            fn_80119DD0();
            fn_80119958();
            *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x2c) + 0xc) = 0;
            (*(s32*)(self + 0x238))++;
            *(s32*)(self + 0x244) = 0;
            *(s32*)(self + 0x248) = 0x1f4;
        }
        break;
    case 6:
        (*(s32*)(self + 0x244))++;
        *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x2c) + 0xc) = 0;
        if (*(s32*)(self + 0x248) == 0) {
            handled = TRUE;
            if (fn_80362C44_findPlayer() != 0) {
                (*(s32*)(self + 0x238))++;
            }
        }
        break;
    case 7:
        *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x2c) + 0xc) = 0;
        handled = TRUE;
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(self + 0x304));
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(self + 0x308));
        fn_8013670C(lbl_8053AAF8, 1);
        (*(s32*)(self + 0x238))++;
        break;
    default:
        *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x2c) + 0xc) = 0;
        handled = TRUE;
        break;
    }
    if (!handled) {
        *(JGeometry::TVec3<f32>*)(*(char**)(self + 0x2fc) + 0xc) = pos;
    }
}

extern "C" void fn_8036335C(void) {
}

extern "C" void fn_80363360(char* self) {
    if (*(s32*)(self + 0x248) == 0) {
        s32 r = fn_801CD664(3);
        if (r == 0) {
            f32 zero = lbl_80542B0C;
            *(f32*)(self + 0x44) = zero;
            *(f32*)(self + 0x40) = zero;
            *(f32*)(self + 0x3c) = zero;
            *(s32*)(self + 0x264) = 0;
            *(s32*)(self + 0x268) = 0;
            *(s32*)(self + 0x248) = 0x20;
        } else {
            if (JMathInlineVEC::PSVECSquareMag((Vec*)(self + 0x3c)) <= lbl_80542B6C * *(f32*)__float_epsilon) {
                *(s16*)(self + 0x240) = fn_801CD664(0x10000);
            } else if (r == 1) {
                *(s16*)(self + 0x240) += 0x1000;
            } else {
                *(s16*)(self + 0x240) -= 0x1000;
            }
            f32 speed = 0.3f;
            *(f32*)(self + 0x3c) = speed * JMath::sincosTable_.mTable[(u16)*(s16*)(self + 0x240) >> 5].second;
            *(f32*)(self + 0x40) = speed * JMath::sincosTable_.mTable[(u16)*(s16*)(self + 0x240) >> 5].first;
            *(s32*)(self + 0x248) = 0x40;
        }
    }
    if (PSVECDistance((Vec*)(self + 0xc), (Vec*)(self + 0x27c)) >= lbl_80542B84) {
        *(s32*)(self + 0x248) = 0x80;
        f32 a = JMath::atanTable_.atan2_(*(f32*)(self + 0x280) - *(f32*)(self + 0x10), *(f32*)(self + 0x27c) - *(f32*)(self + 0xc));
        f32 speed = 0.3f;
        a *= lbl_80542B50;
        *(s16*)(self + 0x240) = (s32)a;
        *(f32*)(self + 0x3c) = speed * JMath::sincosTable_.mTable[(u16)*(s16*)(self + 0x240) >> 5].second;
        *(f32*)(self + 0x40) = speed * JMath::sincosTable_.mTable[(u16)*(s16*)(self + 0x240) >> 5].first;
    }
    if (!(JMathInlineVEC::PSVECSquareMag((Vec*)(self + 0x3c)) <= lbl_80542B6C * *(f32*)__float_epsilon)) {
        f32 a = JMath::atanTable_.atan2_(*(f32*)(self + 0x40), *(f32*)(self + 0x3c));
        a *= lbl_80542B50;
        u16 angle = (s32)a;
        if (angle >= 0x2000 && angle < 0x6000) *(s32*)(self + 0x23c) = 0;
        else if (angle >= 0x6000 && angle < 0xa000) *(s32*)(self + 0x23c) = 2;
        else if (angle >= 0xa000 && angle < 0xe000) *(s32*)(self + 0x23c) = 1;
        else *(s32*)(self + 0x23c) = 3;
        *(s32*)(self + 0x26c) = lbl_804745A8[*(s32*)(self + 0x23c)];
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
            *(s32*)(self + 0x268) += 1;
            if (*(s32*)(self + 0x268) >= 4) *(s32*)(self + 0x268) = 0;
            *(s32*)(self + 0x264) = lbl_80474BC4[*(s32*)(self + 0x268)];
        }
        JMathInlineVEC::PSVECAdd((Vec*)(self + 0xc), (Vec*)(self + 0x3c), (Vec*)(self + 0xc));
    }
}

extern "C" const f32 lbl_8050C088[];
extern "C" const s32 lbl_804745B8[];
extern "C" f32 lbl_80542B6C;
extern "C" int __float_epsilon[];
extern "C" void fn_80363664(char* self) {
    if (*(s32*)(self + 0x248) == 0) {
        if (!(JMathInlineVEC::PSVECSquareMag((Vec*)(self + 0x3c)) <= lbl_80542B6C * *(f32*)__float_epsilon)) {
            s32 prev = *(s32*)(self + 0x26c);
            do {
                const f32* v;
                char* p = self;
                *(s32*)(self + 0x23c) = fn_801CD664(4);
                v = &lbl_8050C088[*(s32*)(self + 0x23c) * 3];
                *(f32*)(p + 0x3c) = v[0];
                *(f32*)(p + 0x40) = v[1];
                *(f32*)(p + 0x44) = v[2];
                *(s32*)(self + 0x248) = fn_801CD664(0x14) + 0x1e;
                *(s32*)(self + 0x26c) = lbl_804745B8[*(s32*)(self + 0x23c) + 0x14];
            } while (*(s32*)(self + 0x26c) == prev);
        } else {
            f32 zero = lbl_80542B0C;
            *(f32*)(self + 0x44) = zero;
            *(f32*)(self + 0x40) = zero;
            *(f32*)(self + 0x3c) = zero;
            *(s32*)(self + 0x248) = fn_801CD664(0xa) + 0xf;
            *(s32*)(self + 0x264) = 0;
        }
    }
    if (JMathInlineVEC::PSVECSquareMag((Vec*)(self + 0x3c)) <= lbl_80542B6C * *(f32*)__float_epsilon) {
        return;
    }
    if (fn_801F2618(self, 0, 0)) {
        f32 zero = lbl_80542B0C;
        *(f32*)(self + 0x44) = zero;
        *(f32*)(self + 0x40) = zero;
        *(f32*)(self + 0x3c) = zero;
        *(s32*)(self + 0x248) = fn_801CD664(0xa) + 0xf;
        *(s32*)(self + 0x264) = 0;
        return;
    }
    JMathInlineVEC::PSVECAdd((Vec*)(self + 0xc), (Vec*)(self + 0x3c), (Vec*)(self + 0xc));
    if (*(s32*)(self + 0x25c) != 0) {
        return;
    }
    *(s32*)(self + 0x268) += 1;
    if (*(s8*)(*(s8**)(self + 0x270) + *(s32*)(self + 0x268)) < 0) {
        *(s32*)(self + 0x268) = 0;
    }
    *(s32*)(self + 0x25c) = *(s8*)(*(s8**)(self + 0x270) + *(s32*)(self + 0x268));
    *(s32*)(self + 0x264) = *(s8*)(*(s8**)(self + 0x274) + *(s32*)(self + 0x268));
}

#pragma opt_strength_reduction off
extern "C" void fn_80363880(char* p) {
    int count;
    char* item;
    int i;
    int state = *(int*)(p + 0x24c);
    if (state >= 0) {
        item = (char*)((void**)((char*)fn_801F856C() + 8))[state];
        if (item != NULL) {
            JGeometry::TVec3<f32> tgt(*(JGeometry::TVec3<f32>*)(item + 0xc));
            if (PSVECDistance((Vec*)(p + 0xc), &tgt) >= lbl_80542B4C) {
                fn_80363880_reset(p);
            } else {
                tgt.z = 0.0f;
                if (PSVECDistance((Vec*)(p + 0xc), &tgt) >= lbl_80542B88) {
                    fn_80363880_aim(p, tgt.y - *(f32*)(p + 0x10), tgt.x - *(f32*)(p + 0xc), 0.5f);
                }
                fn_80363880_setQuadrant(p);
            }
        } else {
            fn_80363880_reset(p);
        }
    } else {
        count = *(int*)((char*)fn_801F856C() + 0x1008);
        for (i = 0; i < count; i++) {
            item = ((ActorList80362634*)fn_801F856C())->actors[i];
            if (item == NULL || *(int*)(item + 0x1a0) != 0x454f574c || *(u8*)(item + 0x11c) != 1 || *(int*)(item + 0x278) != 0) continue;
            if (!(PSVECDistance((Vec*)(p + 0xc), (Vec*)(item + 0xc)) < lbl_80542B4C)) break;
            *(int*)(p + 0x24c) = i;
            JGeometry::TVec3<f32> tgt(*(JGeometry::TVec3<f32>*)(item + 0xc));
            fn_80363880_aim(p, *(f32*)(item + 0x10) - *(f32*)(p + 0x10), *(f32*)(item + 0xc) - *(f32*)(p + 0xc), 0.8f);
            fn_80363880_setQuadrant(p);
            *(u8**)(p + 0x270) = lbl_80542AD8;
            *(u8**)(p + 0x274) = lbl_80542AC8;
            *(int*)(p + 0x25c) = *(s8*)*(u8**)(p + 0x270);
            *(int*)(p + 0x264) = *(s8*)*(u8**)(p + 0x274);
            *(int*)(p + 0x258) = 0;
            break;
        }
        if (*(int*)(p + 0x24c) < 0) {
            if (*(int*)(p + 0x248) == 0) {
                int r = fn_801CD664(3);
                if (r == 0) {
                    fn_80363880_reset(p);
                } else {
                    if (((JGeometry::TVec3<f32>*)(p + 0x3c))->isZero()) {
                        *(s16*)(p + 0x240) = fn_801CD664(0x10000);
                    } else if (r == 1) {
                        *(s16*)(p + 0x240) += 0x1000;
                    } else {
                        *(s16*)(p + 0x240) -= 0x1000;
                    }
                    *(f32*)(p + 0x3c) = 0.5f * JMath::sincosTable_.mTable[(u16)*(s16*)(p + 0x240) >> 5].second;
                    *(f32*)(p + 0x40) = 0.5f * JMath::sincosTable_.mTable[(u16)*(s16*)(p + 0x240) >> 5].first;
                    *(int*)(p + 0x248) = 0x40;
                }
            }
            if (PSVECDistance((Vec*)(p + 0xc), (Vec*)(p + 0x27c)) >= lbl_80542B90) {
                *(int*)(p + 0x248) = 0x80;
                fn_80363880_aim(p, *(f32*)(p + 0x280) - *(f32*)(p + 0x10), *(f32*)(p + 0x27c) - *(f32*)(p + 0xc), 0.5f);
            }
        }
    }
    if (!(((JGeometry::TVec3<f32>*)(p + 0x3c))->isZero())) {
        fn_80363880_setQuadrant(p);
        ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
        if (*(int*)(p + 0x25c) == 0) {
            ++*(int*)(p + 0x268);
            if (((Anim80363880*)p)->durations[((Anim80363880*)p)->frame] < 0) *(int*)(p + 0x268) = 0;
            *(int*)(p + 0x25c) = ((Anim80363880*)p)->durations[((Anim80363880*)p)->frame];
            *(int*)(p + 0x264) = ((Anim80363880*)p)->frames[((Anim80363880*)p)->frame];
        }
    }
}
#pragma opt_strength_reduction reset
extern "C" void fn_80363F7C(char* self) {
    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x268) = *(s32*)(self + 0x268) + 1;
        if (*(s32*)(self + 0x268) >= 6) {
            *(s32*)(self + 0x268) = 0;
        }
        *(s32*)(self + 0x25c) = lbl_80474B88[*(s32*)(self + 0x268)];
        *(s32*)(self + 0x264) = lbl_80474BA0[*(s32*)(self + 0x268)];
    }
    ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
}

extern "C" u32 fn_802F9908(void* obj, u32 room, u32 flags);
extern "C" const s32 lbl_80474598[];
extern "C" const f32 lbl_8050C028[];
extern "C" f32 lbl_80542B94;
extern "C" f32 lbl_80542B98;
extern "C" f32 lbl_80542B9C;
extern "C" f32 lbl_80542BA0;
extern "C" f32 lbl_80542BA4;
extern "C" f32 lbl_80542BA8;
extern "C" f32 lbl_80542BAC;
extern "C" f32 lbl_80542BB0;
extern "C" f32 __fres(f32);
#pragma opt_propagation off
extern "C" void fn_80363FFC(char* self) {
    int nextAng;
    Vec v;
    int rx;
    int ry;

    if (0.0f == *(f32*)(self + 0x3c)) {
        rx = (s32)*(f32*)(self + 0xc);
        if (*(f32*)(self + 0x40) < 0.0f) {
            ry = (s32)(*(f32*)(self + 0x10) - lbl_80542B94);
        } else {
            ry = (s32)(lbl_80542B94 + *(f32*)(self + 0x10));
        }
    } else {
        ry = (s32)*(f32*)(self + 0x10);
        if (*(f32*)(self + 0x3c) < 0.0f) {
            rx = (s32)(*(f32*)(self + 0xc) - lbl_80542B94);
        } else {
            rx = (s32)(lbl_80542B94 + *(f32*)(self + 0xc));
        }
    }

    if (0.0f == *(volatile f32*)(self + 0x44) && 0.0f == *(f32*)(self + 0x14)) {
        *(u16*)(self + 0x27a) = fn_802F9908(*(void**)((char*)lbl_8053AB10 + 0x20), *(u32*)(self + 4), ((((u32)ry & 0x100) << 1) | ((u32)rx & 0x100) | ((u32)ry & 0xf0) | ((u32)rx >> 4 & 0xf))) & 0x3ff;
        if (*(u16*)(self + 0x27a) == 0x1a8) {
            *(s32*)(self + 0x264) = 0;
            *(f32*)(self + 0x44) = 3.0f;
        }
    } else {
        if (*(f32*)(self + 0x14) > 0.0f) {
            *(f32*)(self + 0x44) = *(f32*)(self + 0x44) - lbl_80542B9C;
        } else {
            *(f32*)(self + 0x14) = 0.0f;
            *(f32*)(self + 0x44) = 0.0f;
        }
        *(s32*)(self + 0x264) = 0;
        *(s32*)(self + 0x25c) = 1;
    }

    v.x = lbl_80542BA0;
    v.y = lbl_80542BA4;
    v.z = 0.0f;
    if (*(f32*)(self + 0xc) >= lbl_80542BA0) {
        if (*(f32*)(self + 0x10) < lbl_80542BA4) {
            f32 dist;
            f32 radians = JMath::atanTable_.atan2_(*(f32*)(self + 0x10) - lbl_80542BA4, *(f32*)(self + 0xc) - lbl_80542BA0);
            radians *= lbl_80542B50;
            s32 ang = (s32)radians;
            dist = PSVECDistance((Vec*)(self + 0xc), &v);
            f32 inv = __fres(lbl_80542BA8 * dist);
            nextAng = ang + (s32)(lbl_80542BAC * (inv * lbl_80542BB0));
            *(f32*)(self + 0xc) = dist * JMath::sincosTable_.mTable[(u16)nextAng >> 5].second + v.x;
            *(f32*)(self + 0x10) = dist * JMath::sincosTable_.mTable[(u16)nextAng >> 5].first + v.y;
            if ((u16)nextAng >= 0xe000) {
                *(s32*)(self + 0x23c) = 0;
                if (*(s32*)(self + 0x238) == 0) {
                    *(s32*)(self + 0x26c) = 0x32f;
                } else {
                    *(s32*)(self + 0x26c) = 0x33b;
                }
                *(s32*)(self + 0x26c) += lbl_80474598[*(s32*)(self + 0x23c)];
            }
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
        } else {
            *(volatile f32*)(self + 0x3c) = lbl_8050C028[0];
            *(volatile f32*)(self + 0x40) = ((volatile f32*)lbl_8050C028)[1];
            *(volatile f32*)(self + 0x44) = ((volatile f32*)lbl_8050C028)[2];
        }
    }
    JMathInlineVEC::PSVECAdd((Vec*)(self + 0xc), (Vec*)(self + 0x3c), (Vec*)(self + 0xc));

    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x268) += 1;
        if ((s8)(*(u8**)(self + 0x270))[*(s32*)(self + 0x268)] < 0) {
            *(s32*)(self + 0x268) = 0;
        }
        *(s32*)(self + 0x25c) = (s8)(*(u8**)(self + 0x270))[*(s32*)(self + 0x268)];
            *(s32*)(self + 0x264) = (s8)(*(u8**)(self + 0x274))[*(s32*)(self + 0x268)];
    }
}
#pragma opt_propagation reset
extern "C" void fn_80364340(char* self) {
    if (*(s32*)(self + 0x248) == 0) {
        JGeometry::TVec3<f32> offs;
        JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(self + 0xc);
        JGeometry::TVec3<f32> spawn;
        Vec check;
        JGeometry::TVec3<f32> temp;
        offs.x = (f32)fn_801CD664(0x17c) - lbl_80542BB4;
        offs.y = (f32)fn_801CD664(0x17c) - lbl_80542BB8;
        offs.z = lbl_80542B0C;
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(offs);
        if (fn_80364340_isBadPos((Vec*)(self + 0xc), check)) {
            *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
            return;
        }
        *(s32*)(self + 0x248) = fn_801CD664(0x32) + 0x3c;
        offs.z = lbl_80542B4C;
        *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
        u32 type = fn_801CD664(8) | 0x250000;
        temp = *(JGeometry::TVec3<f32>*)(self + 0xc);
        temp.add(offs);
        spawn = temp;
        Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(self + 4), (f32*)&spawn, type, -1, -1);
    }
}

#pragma opt_lifetimes off
extern "C" void fn_803645B4(char* self) {
    s32 secondIdx;
    JGeometry::TVec3<f32> v;
    if (*(s32*)(self + 0x248) != 0 && *(s32*)(self + 0x238) == 0) {
        return;
    }
    if (*(s32*)(self + 0x238) == 0) {
        {
        s32 idx = *(s32*)(self + 0x24c);
        if (idx >= 0) {
            ActorList80362634* __restrict list = (ActorList80362634*)fn_801F856C();
            char* obj = list->actors[idx];
            if (obj != NULL) {
                *(u8*)(obj + 0x11c) = 0;
            }
        }
        }
        s32 count = *(s32*)((char*)fn_801F856C() + 0x1008);
        s32 off;
        s32 i;
        i = 0;
        off = 0;
        for (; i < count; off += 4, i++) {
            char* p = *(char**)((char*)fn_801F856C() + off + 8);
            if (p != NULL && *(u32*)(p + 0x1a0) == 0x52555059) {
                v = *(JGeometry::TVec3<f32>*)(p + 0xc);
                v.y += lbl_80542BBC;
                if (lbl_80542B0C == v.z) {
                    if (PSVECDistance((Vec*)(self + 0xc), (Vec*)&v) < lbl_80542B58 &&
                        PSVECDistance((Vec*)(self + 0xc), &v) > lbl_80542BC0) {
                        *(s32*)(self + 0x238) = 1;
                        *(f32*)(self + 0x3c) = (v.x - *(f32*)(self + 0xc)) / 40.0f;
                        *(f32*)(self + 0x40) = (v.y - *(f32*)(self + 0x10)) / 40.0f;
                        *(s32*)(self + 0x24c) = i;
                        *(s32*)(self + 0x264) = 0;
                        *(s32*)(self + 0x268) = 0;
                        *(s32*)(self + 0x25c) = 3;
                        f32 angle = JMath::atanTable_.atan2_(*(f32*)(self + 0x40), *(f32*)(self + 0x3c));
                        angle *= lbl_80542B50;
                        u16 ang = (s32)angle;
                        if (ang >= 0x2000 && ang < 0x6000) {
                            *(s32*)(self + 0x23c) = 0;
                        } else if (ang >= 0x6000 && ang < 0xa000) {
                            *(s32*)(self + 0x23c) = 2;
                        } else if (ang >= 0xa000 && ang < 0xe000) {
                            *(s32*)(self + 0x23c) = 1;
                        } else {
                            *(s32*)(self + 0x23c) = 3;
                        }
                        *(s32*)(self + 0x26c) = lbl_80474B58[*(s32*)(self + 0x23c)];
                        *(s32*)(self + 0x248) = 0x3c;
                        return;
                    }
                }
            }
        }
    } else {
        JMathInlineVEC::PSVECAdd((Vec*)(self + 0xc), (Vec*)(self + 0x3c), (Vec*)(self + 0xc));
        fn_801F2618(self, 0, 0);
        secondIdx = *(s32*)(self + 0x24c);
        ActorList80362634* __restrict list = (ActorList80362634*)fn_801F856C();
        char* obj = list->actors[secondIdx];
        if (obj == NULL) {
            *(s32*)(self + 0x24c) = -1;
            *(s32*)(self + 0x238) = 0;
            *(s32*)(self + 0x264) = 0;
            *(s32*)(self + 0x268) = 0;
            return;
        }
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x264) = *(s32*)(self + 0x264) + 1;
            if (*(s32*)(self + 0x264) >= 8) {
                *(s32*)(self + 0x264) = 0;
            }
            *(s32*)(self + 0x25c) = lbl_80474B68[*(s32*)(self + 0x264)];
        }
        v = *(JGeometry::TVec3<f32>*)(obj + 0xc);
        v.y += lbl_80542BBC;
        if (PSVECDistance((Vec*)(self + 0xc), &v) < lbl_80542BBC) {
            *(s32*)(self + 0x238) = 0;
            *(s32*)(self + 0x248) = 0x1e;
            *(s32*)(self + 0x264) = 0;
            return;
        }
        if (*(s32*)(self + 0x248) == 0) {
            *(s32*)(self + 0x238) = 0;
            *(s32*)(self + 0x248) = 0xa;
            *(s32*)(self + 0x264) = 0;
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_80364900(char* self) {
    if (*(s32*)(self + 0x238) == 0) {
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
        if (*(s32*)(self + 0x25c) != 0) {
            return;
        }
        *(s32*)(self + 0x268) += 1;
        if (*(s32*)(self + 0x268) >= 0x10) {
            *(s32*)(self + 0x238) = 1;
            *(s32*)(self + 0x264) = 0;
            *(s32*)(self + 0x268) = 0;
            *(s32*)(self + 0x26c) = 0x2b1;
            *(f32*)(self + 0x44) = 5.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            return;
        }
        *(s32*)(self + 0x25c) = lbl_80474A98[*(s32*)(self + 0x268)];
        if (*(f32*)(self + 0x3c) < 0.0f) {
            *(s32*)(self + 0x264) = lbl_80474AD8[*(s32*)(self + 0x268) + 16];
        } else {
            *(s32*)(self + 0x264) = lbl_80474AD8[*(s32*)(self + 0x268)];
        }
        return;
    }
    *(f32*)(self + 0x44) -= 0.5f;
    ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
    if (*(f32*)(self + 0x14) < 0.0f) {
        *(s32*)(self + 0x238) = 0;
        *(f32*)(self + 0x14) = 0.0f;
        *(f32*)(self + 0x44) = 0.0f;
        *(s32*)(self + 0x26c) = 0x38e;
        *(s32*)(self + 0x25c) = 4;
        if (*(s32*)(self + 0x23c) == 3) {
            *(s32*)(self + 0x23c) = 2;
            *(f32*)(self + 0x3c) = -0.8f;
            *(s32*)(self + 0x264) = 5;
            *(s32*)(self + 0x25c) = 4;
        } else {
            *(s32*)(self + 0x23c) = 3;
            *(f32*)(self + 0x3c) = 0.8f;
            *(s32*)(self + 0x26c) = 0x38e;
            *(s32*)(self + 0x264) = 0;
        }
    }
}

#pragma opt_propagation off
extern "C" void fn_80364A88(char* self) {
    char* tbl = (char*)lbl_80474320;
    if (*(s32*)(self + 0x248) == 0) {
        f32 mag = PSVECMag((Vec*)(self + 0x3c));
        JMathInlineVEC::PSVECAdd((Vec*)(self + 0xc), (Vec*)(self + 0x3c), (Vec*)(self + 0xc));
        *(f32*)(self + 0x2f8) += mag;
        if (*(f32**)(self + 0x2f4) != 0) {
            if (*(f32*)(self + 0x2f8) >= **(f32**)(self + 0x2f4)) {
                f32 zero = lbl_80542B0C;
                *(f32*)(self + 0x2f8) = zero;
                *(s32*)(self + 0x2f4) += 4;
                *(s32*)(self + 0x23c) += 1;
                if (*(s32*)(self + 0x23c) == 1) {
                    const s32* __restrict base = (const s32*)(tbl + 0x228);
                    *(f32*)(self + 0x3c) = zero;
                    *(f32*)(self + 0x40) = -1.0f * mag;
                    *(f32*)(self + 0x44) = zero;
                    *(s32*)(self + 0x26c) = base[*(s32*)(self + 0x238) * 4 + 1];
                } else if (*(s32*)(self + 0x23c) == 2) {
                    const s32* __restrict base = (const s32*)(tbl + 0x228);
                    *(f32*)(self + 0x3c) = mag;
                    *(f32*)(self + 0x40) = zero;
                    *(f32*)(self + 0x44) = zero;
                    *(s32*)(self + 0x26c) = base[*(s32*)(self + 0x238) * 4 + 3];
                } else if (*(s32*)(self + 0x23c) == 3) {
                    const s32* __restrict base = (const s32*)(tbl + 0x228);
                    *(f32*)(self + 0x3c) = zero;
                    *(f32*)(self + 0x40) = mag;
                    *(f32*)(self + 0x44) = zero;
                    *(s32*)(self + 0x26c) = base[*(s32*)(self + 0x238) * 4];
                } else if (*(s32*)(self + 0x23c) == 4) {
                    const s32* __restrict base = (const s32*)(tbl + 0x228);
                    *(f32*)(self + 0x3c) = mag;
                    *(f32*)(self + 0x40) = zero;
                    *(f32*)(self + 0x44) = zero;
                    *(s32*)(self + 0x26c) = base[*(s32*)(self + 0x238) * 4 + 3];
                } else {
                    const s32* __restrict base = (const s32*)(tbl + 0x228);
                    *(s32*)(self + 0x26c) = base[*(s32*)(self + 0x238) + 16];
                    *(s32*)(self + 0x260) = 0xf;
                    *(s32*)(self + 0x25c) = 0xf;
                    if (*(s32*)(self + 0x238) == 1) {
                        *(s32*)(self + 0x264) = 1;
                    } else {
                        *(s32*)(self + 0x264) = 0;
                    }
                    f32 stop = lbl_80542B0C;
                    *(f32*)(self + 0x44) = stop;
                    *(f32*)(self + 0x40) = stop;
                    *(f32*)(self + 0x3c) = stop;
                    *(s32*)(self + 0x2f4) = 0;
                }
            }
            if (*(s32*)(self + 0x25c) != 0) {
                return;
            }
            *(s32*)(self + 0x268) += 1;
            if (*(s32*)(self + 0x268) >= 4) {
                *(s32*)(self + 0x268) = 0;
            }
            if (*(s32*)(self + 0x238) == 1) {
                const s32* __restrict frames = (const s32*)(tbl + 0x758);
                *(s32*)(self + 0x25c) = frames[*(s32*)(self + 0x268)];
            } else {
                const s32* __restrict frames = (const s32*)(tbl + 0x768);
                *(s32*)(self + 0x25c) = frames[*(s32*)(self + 0x268)];
            }
            const s32* __restrict frames = (const s32*)(tbl + 0x748);
            *(s32*)(self + 0x264) = frames[*(s32*)(self + 0x268)];
        } else {
            if (*(s32*)(self + 0x238) != 1 && *(s32*)(self + 0x25c) == 0) {
                *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
                *(s32*)(self + 0x264) ^= 1;
            }
        }
    }
}
#pragma opt_propagation reset
extern "C" void* fn_801F856C(void);
extern "C" f32 lbl_80542B50;
extern "C" f32 lbl_80542B58;
extern "C" const s32 lbl_80474320[];
extern "C" const s32 lbl_80474450[];
#pragma opt_propagation off
extern "C" void fn_80364D0C(char* self) {
    s32 idx = *(s32*)(self + 0x24c);
    if (idx < 0) {
        s32 count = *(s32*)((char*)fn_801F856C() + 0x1008);
        s32 off = 0;
        s32 i = 0;
        for (; i < count; off += 4, i++) {
            char* p = *(char**)((char*)fn_801F856C() + off + 8);
            if (p != NULL && *(u32*)(p + 0x1a0) == 0x454f574c) {
                *(s32*)(self + 0x24c) = i;
                break;
            }
        }
    } else {
        s32 old = *(s32*)(self + 0x23c);
        char* p = ((char**)((char*)fn_801F856C() + 8))[idx];
        if (p == NULL) {
            *(s32*)(self + 0x24c) = -1;
        } else {
            if (PSVECDistance((Vec*)(self + 0xc), (Vec*)(p + 0xc)) >= lbl_80542B58) {
                *(s32*)(self + 0x23c) = 0;
            } else {
                f32 angle = JMath::atanTable_.atan2_(*(f32*)(p + 0x10) - *(f32*)(self + 0x10),
                                                     *(f32*)(p + 0xc) - *(f32*)(self + 0xc));
                *(s16*)(self + 0x240) = (s16)(angle * lbl_80542B50);
                u16 u = *(s16*)(self + 0x240);
                if (u >= 0x2000 && u < 0x6000) {
                    *(s32*)(self + 0x23c) = 0;
                } else if (u >= 0x6000 && u < 0xa000) {
                    *(s32*)(self + 0x23c) = 2;
                } else if (u >= 0xa000 && u < 0xe000) {
                    *(s32*)(self + 0x23c) = 1;
                } else {
                    *(s32*)(self + 0x23c) = 3;
                }
            }
        }
        if (*(s32*)(self + 0x23c) != old) {
            *(s32*)(self + 0x26c) = lbl_80474320[*(s32*)(self + 0x23c) + *(s32*)(self + 0x238) * 4];
            *(s32*)(self + 0x25c) = *(s32*)((char*)lbl_80474450 + *(s32*)(self + 0x238) * 8);
        }
    }
    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
        *(u32*)(self + 0x264) ^= 1;
    }
}
#pragma opt_propagation reset
extern "C" void fn_80364F00(char* this_) {
    if (*(s32*)(this_ + 0x25c) != 0) {
        return;
    }
    *(s32*)(this_ + 0x268) += 1;
    if (*(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268)) < 0) {
        *(s32*)(this_ + 0x268) = 0;
    }
    *(s32*)(this_ + 0x25c) = *(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268));
    *(s32*)(this_ + 0x264) = *(char*)(*(char**)(this_ + 0x274) + *(s32*)(this_ + 0x268));
}

extern "C" f32 lbl_80542BCC;
extern "C" f32 lbl_80542BD0;
extern "C" f32 lbl_80542B0C;
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_80364F60(char* this_) {
  if (*(s32*)(this_ + 0x238) != 5) {
    s32 prev = *(s32*)(this_ + 0x264);
    if (*(s32*)(this_ + 0x25c) == 0) {
      *(s32*)(this_ + 0x268) += 1;
      if (*(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268)) < 0) {
        *(s32*)(this_ + 0x268) = 0;
      }
      *(s32*)(this_ + 0x25c) = *(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268));
      *(s32*)(this_ + 0x264) = *(char*)(*(char**)(this_ + 0x274) + *(s32*)(this_ + 0x268));
    }
    s32 cur = *(s32*)(this_ + 0x264);
    if (prev != cur && *(s32*)(this_ + 0x238) >= 4 && *(s32*)(this_ + 0x238) <= 7 && cur == 0) {
      *(s32*)(this_ + 0x25c) += fn_801CD664(5) * 6;
    }
    if (*(s32*)(this_ + 0x238) == 0x1d || *(s32*)(this_ + 0x238) == 0x1e) {
      if (*(s32*)(this_ + 0x268) == 2) {
        if (*(s32*)(this_ + 0x25c) == 0xc) {
          *(f32*)(this_ + 0x44) = lbl_80542BCC;
        } else {
          *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - lbl_80542BD0;
        }
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x14) + *(f32*)(this_ + 0x44);
      } else {
        f32 zero = lbl_80542B0C;
        *(f32*)(this_ + 0x14) = zero;
        *(f32*)(this_ + 0x44) = zero;
      }
    }
  }
}

extern "C" void* fn_8013CC50(u32 id, void* pos, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" void fn_8036509C(char* self) {
    if (*(s32*)(self + 0x248) != 0) {
        if (*(s32*)(self + 0x248) <= 0xe) {
            if (*(s32*)(self + 0x248) == 0xe) {
                char* p = *(char**)(self + 0x300);
                if (p != NULL) {
                    *(u32*)(p + 0xf4) |= 1;
                    *(s32*)(p + 0x24) = 1;
                    *(void**)(self + 0x300) = NULL;
                }
                *(s32*)(self + 0x258) = 0;
                *(s32*)(self + 0x264) = 0xb;
                fn_8013CC50(*(u32*)(self + 4), self + 0xc, 1.0f, 0x15b, 0, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(self + 4), self + 0xc, 1.0f, 0x15c, -1, 0, 0, 0, 1);
            } else if (*(s32*)(self + 0x248) == 0xa) {
                *(s32*)(self + 0x264) = 0xa;
            } else if (*(s32*)(self + 0x248) == 8) {
                *(s32*)(self + 0x264) = 9;
            } else if (*(s32*)(self + 0x248) == 6) {
                *(s32*)(self + 0x264) = 8;
            } else if (*(s32*)(self + 0x248) == 4) {
                *(s32*)(self + 0x264) = 2;
            } else if (*(s32*)(self + 0x248) == 2) {
                *(s32*)(self + 0x264) = 1;
            }
        }
        if (*(s32*)(self + 0x248) == 1) {
            *(s32*)(self + 0x25c) = fn_801CD664(9);
            *(s32*)(self + 0x264) = 0;
        }
    } else {
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x25c) = 8;
            *(s32*)(self + 0x264) = *(s32*)(self + 0x264) + 1;
            if (*(s32*)(self + 0x264) >= 4) {
                *(s32*)(self + 0x264) = 0;
            }
        }
    }
}

extern "C" void fn_80365220(char* this_) {
    if (*(s32*)(this_ + 0x248) == 0) {
        *(s32*)(this_ + 0x248) = 0x40;
        *(s32*)(this_ + 0x238) += 1;
    }
    if (!(*(u32*)(this_ + 0x238) & 1)) {
        *(f32*)(this_ + 0x10) += lbl_80542BD4;
    } else {
        *(f32*)(this_ + 0x10) -= lbl_80542BD4;
    }
}

extern "C" const s32 lbl_80474BC4[];
extern "C" f32 lbl_80542BD8;
extern "C" void fn_80365274(char* this_) {
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    s32 state = *(s32*)(this_ + 0x238);
    switch (state) {
    case 0:
    case 2:
        if (*(s32*)(this_ + 0x25c) == 0) {
            *(s32*)(this_ + 0x25c) = *(s32*)(this_ + 0x260);
            *(s32*)(this_ + 0x268) += 1;
            if (*(s32*)(this_ + 0x268) >= 4) {
                *(s32*)(this_ + 0x268) = 0;
            }
            *(s32*)(this_ + 0x264) = lbl_80474BC4[*(s32*)(this_ + 0x268)];
        }
        if (*(s32*)(this_ + 0x248) == 0) {
            *(s32*)(this_ + 0x248) = 0xc6;
            f32 zero = lbl_80542B0C;
            *(f32*)(this_ + 0x44) = zero;
            *(f32*)(this_ + 0x40) = zero;
            *(f32*)(this_ + 0x3c) = zero;
            *(s32*)(this_ + 0x26c) = 0x3ac;
            *(s32*)(this_ + 0x264) = 0;
            if (*(s32*)(this_ + 0x238) == 2) {
                *(u8*)(this_ + 0x11c) = 0;
            } else {
                *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) + 1;
            }
        }
        break;
    case 1: {
        s32 timer = *(s32*)(this_ + 0x248);
        if (timer == 0x8a) {
            *(s32*)(this_ + 0x26c) = 0x3a4;
        } else if (timer == 0x72) {
            *(s32*)(this_ + 0x26c) = 0x3a8;
        } else if (timer == 0x5a) {
            *(s32*)(this_ + 0x26c) = 0x3a4;
        } else if (timer == 0) {
            f32 x = lbl_80542B0C;
            f32 y = lbl_80542BD8;
            *(s32*)(this_ + 0x238) = state + 1;
            *(s32*)(this_ + 0x26c) = 0x3b1;
            *(s32*)(this_ + 0x264) = 0;
            JGeometry::TVec3<f32> v(x, y, x);
            *(JGeometry::TVec3<f32>*)(this_ + 0x3c) = v;
            *(s32*)(this_ + 0x248) = 0x64;
        }
        break;
    }
    }
}

extern "C" void fn_803653EC(char* self) {
    s32 timer;
    if (*(s32*)(self + 0x238) < 0) {
        if (*(s32*)(self + 0x248) >= 0x80) {
            if (*(s32*)(self + 0x25c) == 0) {
                *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
                *(s32*)(self + 0x268) += 1;
                if (*(s32*)(self + 0x268) >= 4) {
                    *(s32*)(self + 0x268) = 0;
                }
                *(s32*)(self + 0x264) = lbl_80474BC4[*(s32*)(self + 0x268)];
            }
            JMathInlineVEC::PSVECAdd((Vec*)(self + 0xc), (Vec*)(self + 0x3c), (Vec*)(self + 0xc));
            JMathInlineVEC::PSVECAdd((Vec*)(self + 0x27c), (Vec*)(self + 0x3c), (Vec*)(self + 0x27c));
            JMathInlineVEC::PSVECAdd((Vec*)(self + 0x288), (Vec*)(self + 0x3c), (Vec*)(self + 0x288));
            JMathInlineVEC::PSVECAdd((Vec*)(self + 0x294), (Vec*)(self + 0x3c), (Vec*)(self + 0x294));
            timer = *(s32*)(self + 0x248);
            if (timer == 0x80) {
                *(f32*)(self + 0x44) = 0.0f;
                *(f32*)(self + 0x40) = 0.0f;
                *(f32*)(self + 0x3c) = 0.0f;
                *(s32*)(self + 0x26c) = 0x388;
                *(s32*)(self + 0x264) = 0;
            }
            return;
        } else if (*(s32*)(self + 0x248) == 0) {
            *(s32*)(self + 0x238) = 0;
        } else {
            return;
        }
    }

    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
        *(s32*)(self + 0x268) += 1;
        if (*(s32*)(self + 0x268) >= 4) {
            *(s32*)(self + 0x268) = 0;
        }
        *(s32*)(self + 0x264) = lbl_80474BC4[*(s32*)(self + 0x268)];
    }
    if (*(s32*)(self + 0x248) == 0) {
        *(s32*)(self + 0x248) = 0x80;
        switch (*(s32*)(self + 0x238) & 3) {
        case 0: {
            *(s32*)(self + 0x26c) = 913;
            if (!lbl_8053AD50) {
                lbl_8050C0B8[0] = JGeometry::TVec3<f32>(-16.0f,16.0f,0.0f);
                lbl_8050C0B8[1] = JGeometry::TVec3<f32>(16.0f,16.0f,0.0f);
                lbl_8050C0B8[2] = JGeometry::TVec3<f32>(0.0f,32.0f,0.0f);
                lbl_8053AD50 = 1;
            }
            for (s32 i = 0; i < 3; i++) {
                *(JGeometry::TVec3<f32>*)(self + 0x2a0 + i * 12) = *(JGeometry::TVec3<f32>*)(self + 12) + lbl_8050C0B8[i];
                *(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 12) = JGeometry::TVec3<f32>(
                    (*(f32*)(self + 0x2a0 + i * 12) - *(f32*)(self + 0x27c + i * 12)) / 10.0f,
                    (*(f32*)(self + 0x2a4 + i * 12) - *(f32*)(self + 0x280 + i * 12)) / 10.0f, 0.0f);
                *(s32*)(self + 0x2e8 + i * 4) = lbl_80474A5C[i];
            }
            break;
        }
        case 1: {
            *(s32*)(self + 0x26c) = 904;
            for (s32 i = 0; i < 3; i++) {
                *(JGeometry::TVec3<f32>*)(self + 0x2a0 + i * 12) = *(JGeometry::TVec3<f32>*)(self + 12) + JGeometry::TVec3<f32>(16.0f * i + 16.0f, 0.0f, 0.0f);
                *(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 12) = JGeometry::TVec3<f32>(
                    (*(f32*)(self + 0x2a0 + i * 12) - *(f32*)(self + 0x27c + i * 12)) / 10.0f,
                    (*(f32*)(self + 0x2a4 + i * 12) - *(f32*)(self + 0x280 + i * 12)) / 10.0f, 0.0f);
                *(s32*)(self + 0x2e8 + i * 4) = 904;
            }
            break;
        }
        case 2: {
            *(s32*)(self + 0x26c) = 910;
            for (s32 i = 0; i < 3; i++) {
                *(JGeometry::TVec3<f32>*)(self + 0x2a0 + i * 12) = *(JGeometry::TVec3<f32>*)(self + 12) + JGeometry::TVec3<f32>(0.0f, 16.0f * i + 16.0f, 0.0f);
                *(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 12) = JGeometry::TVec3<f32>(
                    (*(f32*)(self + 0x2a0 + i * 12) - *(f32*)(self + 0x27c + i * 12)) / 10.0f,
                    (*(f32*)(self + 0x2a4 + i * 12) - *(f32*)(self + 0x280 + i * 12)) / 10.0f, 0.0f);
                *(s32*)(self + 0x2e8 + i * 4) = 910;
            }
            break;
        }
        case 3: {
            *(s32*)(self + 0x26c) = 913;
            if (!lbl_8053AD51) {
                lbl_8050C0DC[0] = JGeometry::TVec3<f32>(16.0f,0.0f,0.0f);
                lbl_8050C0DC[1] = JGeometry::TVec3<f32>(0.0f,16.0f,0.0f);
                lbl_8050C0DC[2] = JGeometry::TVec3<f32>(16.0f,16.0f,0.0f);
                lbl_8053AD51 = 1;
            }
            for (s32 i = 0; i < 3; i++) {
                *(JGeometry::TVec3<f32>*)(self + 0x2a0 + i * 12) = *(JGeometry::TVec3<f32>*)(self + 12) + lbl_8050C0DC[i];
                *(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 12) = JGeometry::TVec3<f32>(
                    (*(f32*)(self + 0x2a0 + i * 12) - *(f32*)(self + 0x27c + i * 12)) / 10.0f,
                    (*(f32*)(self + 0x2a4 + i * 12) - *(f32*)(self + 0x280 + i * 12)) / 10.0f, 0.0f);
                *(s32*)(self + 0x2e8 + i * 4) = 913;
            }
            break;
        }
        }
        ++*(s32*)(self + 0x238);
    } else {
        *(JGeometry::TVec3<f32>*)(self + 636) += *(JGeometry::TVec3<f32>*)(self + 708);
        *(JGeometry::TVec3<f32>*)(self + 648) += *(JGeometry::TVec3<f32>*)(self + 720);
        *(JGeometry::TVec3<f32>*)(self + 660) += *(JGeometry::TVec3<f32>*)(self + 732);
        if (*(s32*)(self + 0x248) == 0x76) {
            *(JGeometry::TVec3<f32>*)(self + 636) = *(JGeometry::TVec3<f32>*)(self + 672);
            *(f32*)(self + 716) = 0.0f;
            *(f32*)(self + 712) = 0.0f;
            *(f32*)(self + 708) = 0.0f;
            *(JGeometry::TVec3<f32>*)(self + 648) = *(JGeometry::TVec3<f32>*)(self + 684);
            *(f32*)(self + 728) = 0.0f;
            *(f32*)(self + 724) = 0.0f;
            *(f32*)(self + 720) = 0.0f;
            *(JGeometry::TVec3<f32>*)(self + 660) = *(JGeometry::TVec3<f32>*)(self + 696);
            *(f32*)(self + 740) = 0.0f;
            *(f32*)(self + 736) = 0.0f;
            *(f32*)(self + 732) = 0.0f;
        }
    }
}

extern "C" void fn_80365AB8(Unk80365AB8* self) {
    (self->*lbl_804ADDE8[*(s32*)((u8*)self + 0x234)])();
}

extern "C" void fn_80365AF0(Unk80365AB8* self) {
    if (*(s8*)((u8*)self + 0x230) == 0) {
        if (*(s32*)((u8*)self + 0x248) != 0) {
            *(s32*)((u8*)self + 0x248) -= 1;
        }
        if (*(s32*)((u8*)self + 0x25c) != 0) {
            *(s32*)((u8*)self + 0x25c) -= 1;
        }
        (self->*lbl_804ADC38[*(s32*)((u8*)self + 0x234)])();
    }
}

extern "C" s8 lbl_80542AE0[];
extern "C" s8 lbl_80542A78[];
extern "C" s8 lbl_80542A7C[];
extern "C" u16 lbl_80542AE8[];
extern "C" const f32 lbl_8050C088[];
extern "C" f32 lbl_80542BE4;
extern "C" f32 lbl_80542BE8;
extern "C" f32 lbl_80542BEC;
extern "C" f32 lbl_80542BF0;
extern "C" f32 lbl_80542BF4;
extern "C" f32 lbl_80542BF8;
extern "C" f32 lbl_80542BFC;

extern "C" f32 lbl_80542BE0;
extern "C" void fn_80365B5C(char* self) {
    s32 kind = (s32)(*(u32*)(self + 0x90) & 0x1f);
    *(s32*)(self + 0x234) = kind;
    *(s32*)(self + 0x238) = (s32)((*(u32*)(self + 0x90) >> 20) & 0x7f);
    *(s32*)(self + 0x23c) = (s32)((*(u32*)(self + 0x90) >> 18) & 0x3);
    *(u8*)(self + 0x230) = (u8)((*(u32*)(self + 0x90) >> 12) & 0x3f);
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24c) = -1;
    *(s32*)(self + 0x25c) = 0;
    *(s32*)(self + 0x260) = 0;
    *(s32*)(self + 0x264) = 0;
    *(s32*)(self + 0x268) = 0;
    *(s32*)(self + 0x26c) = 0;
    *(s32*)(self + 0x270) = 0;
    *(s32*)(self + 0x274) = 0;
    *(u8*)(self + 0x278) = 0;
    *(s32*)(self + 0x300) = 0;
    *(s32*)(self + 0x304) = 0;
    *(s32*)(self + 0x308) = 0;
    *(s32*)(self + 0x30c) = 0;
    *(s32*)(self + 0x310) = 0;
    *(s32*)(self + 0x314) = 0;
    *(s32*)(self + 0x318) = 0;
}

extern "C" char lbl_804ADF28[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4EETC[];
extern "C" void* fn_80366D44(void* this_, short how) {
    if (this_) {
        *(void**)this_ = __vt__4EETC;
        if (*(s32*)((char*)this_ + 0x234) == 3) {
            if (*(void**)((char*)this_ + 0x300)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x300));
                *(void**)((char*)this_ + 0x300) = 0;
            }
        }
        if (*(s32*)((char*)this_ + 0x234) == 0x10) {
            if (*(void**)((char*)this_ + 0x304)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x304));
                *(void**)((char*)this_ + 0x304) = 0;
            }
            if (*(void**)((char*)this_ + 0x308)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x308));
                *(void**)((char*)this_ + 0x308) = 0;
            }
            char* p = (char*)this_;
            int i = 0;
            do {
                if (*(void**)(p + 0x30c)) {
                    void* base = fn_8013C824();
                    void* mgr = *(void**)((char*)base + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x30c));
                    *(void**)(p + 0x30c) = 0;
                }
                i++;
                p += 4;
            } while (i < 4);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" f32 lbl_80542C00;
extern "C" f32 lbl_80542C04;
#pragma opt_propagation off
extern "C" void fn_80366E60(void) {
    char* registrations = (char*)lbl_8050C028;
    const u32* b = lbl_804ADB60;
    u32* first = lbl_804ADB60 + 54;
    first[0] = b[0];
    first[1] = b[1];
    first[2] = b[2];
    first[3] = b[3];
    first[4] = b[4];
    first[5] = b[5];
    first[6] = b[6];
    first[7] = b[7];
    first[8] = b[8];
    first[9] = b[9];
    first[10] = b[10];
    first[11] = b[11];
    first[12] = b[12];
    first[13] = b[13];
    first[14] = b[14];
    first[15] = b[15];
    first[16] = b[16];
    first[17] = b[17];
    first[18] = b[18];
    first[19] = b[19];
    first[20] = b[20];
    first[21] = b[21];
    first[22] = b[22];
    first[23] = b[23];
    first[24] = b[24];
    first[25] = b[25];
    first[26] = b[26];
    first[27] = b[27];
    first[28] = b[28];
    first[29] = b[29];
    first[30] = b[30];
    first[31] = b[31];
    first[32] = b[32];
    first[33] = b[33];
    first[34] = b[34];
    first[35] = b[35];
    first[36] = b[36];
    first[37] = b[37];
    first[38] = b[38];
    first[39] = b[39];
    first[40] = b[40];
    first[41] = b[41];
    first[42] = b[42];
    first[43] = b[43];
    first[44] = b[44];
    first[45] = b[45];
    first[46] = b[46];
    first[47] = b[47];
    first[48] = b[48];
    first[49] = b[49];
    first[50] = b[50];
    first[51] = b[51];
    first[52] = b[52];
    first[53] = b[53];
    u32* second = lbl_804ADB60 + 162;
    second[0] = b[108];
    second[1] = b[109];
    second[2] = b[110];
    second[3] = b[111];
    second[4] = b[112];
    second[5] = b[113];
    second[6] = b[114];
    second[7] = b[115];
    second[8] = b[116];
    second[9] = b[117];
    second[10] = b[118];
    second[11] = b[119];
    second[12] = b[120];
    second[13] = b[121];
    second[14] = b[122];
    second[15] = b[123];
    second[16] = b[124];
    second[17] = b[125];
    second[18] = b[126];
    second[19] = b[127];
    second[20] = b[128];
    second[21] = b[129];
    second[22] = b[130];
    second[23] = b[131];
    second[24] = b[132];
    second[25] = b[133];
    second[26] = b[134];
    second[27] = b[135];
    second[28] = b[136];
    second[29] = b[137];
    second[30] = b[138];
    second[31] = b[139];
    second[32] = b[140];
    second[33] = b[141];
    second[34] = b[142];
    second[35] = b[143];
    second[36] = b[144];
    second[37] = b[145];
    second[38] = b[146];
    second[39] = b[147];
    second[40] = b[148];
    second[41] = b[149];
    second[42] = b[150];
    second[43] = b[151];
    second[44] = b[152];
    second[45] = b[153];
    second[46] = b[154];
    second[47] = b[155];
    second[48] = b[156];
    second[49] = b[157];
    second[50] = b[158];
    second[51] = b[159];
    second[52] = b[160];
    second[53] = b[161];
    ((JGeometry::TVec3<f32>*)registrations)[0] = JGeometry::TVec3<f32>(lbl_80542B0C, lbl_80542BB0, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[1] = JGeometry::TVec3<f32>(lbl_80542B0C, lbl_80542C00, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[2] = JGeometry::TVec3<f32>(lbl_80542C00, lbl_80542B0C, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[3] = JGeometry::TVec3<f32>(lbl_80542BB0, lbl_80542B0C, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[4] = JGeometry::TVec3<f32>(lbl_80542B0C, lbl_80542B80, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[5] = JGeometry::TVec3<f32>(lbl_80542B0C, lbl_80542C04, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[6] = JGeometry::TVec3<f32>(lbl_80542C04, lbl_80542B0C, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[7] = JGeometry::TVec3<f32>(lbl_80542B80, lbl_80542B0C, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[8] = JGeometry::TVec3<f32>(lbl_80542B0C, lbl_80542B10, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[9] = JGeometry::TVec3<f32>(lbl_80542B0C, lbl_80542B5C, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[10] = JGeometry::TVec3<f32>(lbl_80542B5C, lbl_80542B0C, lbl_80542B0C);
    ((JGeometry::TVec3<f32>*)registrations)[11] = JGeometry::TVec3<f32>(lbl_80542B10, lbl_80542B0C, lbl_80542B0C);
    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr,
                                 __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, registrations + 0xd8);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack,
                                 __dt__35JASMemPool_MultiThreaded_8JASTrackFv, registrations + 0xe4);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel,
                                 __dt__38JASMemPool_MultiThreaded_10JASChannelFv, registrations + 0xf0);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA,
                                 __dt__29JASMemPool_15JASPoolObj3_FSAFv, registrations + 0xfc);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA,
                                 __dt__29JASMemPool_15JASPoolObj4_FSAFv, registrations + 0x108);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream,
                                 __dt__22JASMemPool_9JAIStreamFv, registrations + 0x114);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild,
                                 __dt__27JASMemPool_13JAISoundChildFv, registrations + 0x120);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq,
                                 __dt__19JASMemPool_6JAISeqFv, registrations + 0x12c);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe,
                                 __dt__18JASMemPool_5JAISeFv, registrations + 0x138);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma opt_propagation reset
