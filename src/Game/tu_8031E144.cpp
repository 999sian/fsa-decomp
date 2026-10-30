#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Box.h"


#include "JSystem/JGeometry/Box.h"

extern "C" char lbl_804AB1F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" const f32 lbl_80541A20;
extern "C" const f32 lbl_80541A24;
extern "C" const f32 lbl_80541A38;
extern "C" f32 lbl_80541A3C;
extern "C" f32 lbl_80541A40;
extern "C" f32 lbl_80541A44;
extern "C" f32 lbl_80541A48;
extern "C" f32 lbl_80541A4C;
extern "C" f32 lbl_80541A50;
extern "C" void* lbl_8053AAF8;
extern "C" s32 fn_8013CC50(void* p, void* q, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_801F0E34(Actor* p, s32 a, s32 b);
extern "C" s32 fn_8022461C(s32 a);
extern "C" char lbl_80471718[];
extern "C" char lbl_8047172C[];
extern "C" char* lbl_8053AB10;
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void PSMTXIdentity(f32 m[3][4]);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801EF830(s32 idx, void* pos, DrawRec* rec, u32 mask, const char* name, s32 id, s32 p7);
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* prm);
extern "C" void fn_803075AC(void* a, s32 room, void* pos, s32 id, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10);
struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* getResource(u32 fourccType, const char* fileName);
};

extern "C" void fn_8031E144(Actor* p) {
    char* c = (char*)p;
    DrawRec rec;
    f32 ss;
    f32 cz;
    f32 cs;
    f32 a0;
    f32 a1;
    f32 a2;
    f32 a3;
    f32 a4;
    f32 a5;
    f32 a6;
    f32 a7;
    f32 a8;
    f32 cc;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cx;
    f32 cy;
    f32 ay;
    f32 s;
    f32 ss2;
    f32 cz2;
    f32 cs2;
    f32 a02;
    f32 a12;
    f32 a22;
    f32 a32;
    f32 a42;
    f32 a52;
    f32 a62;
    f32 a72;
    f32 a82;
    f32 cc2;
    f32 sx2;
    f32 s2;
    f32 sz2;
    f32 cx2;
    f32 cy2;
    f32 ay2;
    f32 sy2;
    const char* name = lbl_80471718;
    s32 id = 0x89;
    if (*(s32*)(c + 0x248) == 1) {
        name = lbl_8047172C;
        id = *(s32*)(c + 0x250) + 0x471;
    }
    rec.b2d = 1;
    rec.b1d = -1;
    s32 state = *(s32*)(c + 0x230);
    if (state == 2 || state == 3) {
        f32 mtx[3][4];
            s = *(f32*)(c + 0x238) * *(f32*)(c + 0x240);
        PSMTXIdentity(mtx);
        ay = *(f32*)(c + 0x23c);
        sx = sin(lbl_80541A20);
        sy = sin(ay);
        sz = sin(lbl_80541A20);
        cx = cos(lbl_80541A20);
        cy = cos(ay);
        cz = cos(lbl_80541A20);
        rec.w18 = mtx;
    cc = cx * cz;
    ss = sx * sy;
    cs = cx * sz;
    a0 = cy * cz;
    a1 = cy * sz;
    a2 = -sy;
    a3 = ss * cz - cs;
    a4 = ss * sz + cc;
    a5 = sx * cy;
    a6 = cc * sy + sx * sz;
    a7 = cs * sy - sx * cz;
    a8 = cx * cy;
    mtx[0][0] = s * a0;
    mtx[1][0] = s * a1;
    mtx[2][0] = s * a2;
    mtx[0][1] = s * a3;
    mtx[1][1] = s * a4;
    mtx[2][1] = s * a5;
    mtx[0][2] = s * a6;
    mtx[1][2] = s * a7;
    mtx[2][2] = s * a8;
        if (*(s32*)(c + 4) < 8) {
            void* obj = *(void**)((char*)lbl_8053AAF8 + 0xa4);
            void* res = ((FsaResourceManager*)obj)->getResource(0x534F4220, name);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), c + 0xc, res, id, lbl_80541A24, lbl_80541A24, &rec);
        }
        return;
    }
    rec.b1d = 0;
    f32 mtx2[3][4];
    PSMTXIdentity(mtx2);
    ay2 = *(f32*)(c + 0x23c);
    s2 = *(f32*)(c + 0x240);
    sx2 = sin(lbl_80541A20);
    sy2 = sin(ay2);
    sz2 = sin(lbl_80541A20);
    cx2 = cos(lbl_80541A20);
    cy2 = cos(ay2);
    cz2 = cos(lbl_80541A20);
    rec.w18 = mtx2;
    cc2 = cx2 * cz2;
    ss2 = sx2 * sy2;
    cs2 = cx2 * sz2;
    a02 = cy2 * cz2;
    a12 = cy2 * sz2;
    a22 = -sy2;
    a32 = ss2 * cz2 - cs2;
    a42 = ss2 * sz2 + cc2;
    a52 = sx2 * cy2;
    a62 = cc2 * sy2 + sx2 * sz2;
    a72 = cs2 * sy2 - sx2 * cz2;
    a82 = cx2 * cy2;
    mtx2[0][0] = s2 * a02;
    mtx2[1][0] = s2 * a12;
    mtx2[2][0] = s2 * a22;
    mtx2[0][1] = s2 * a32;
    mtx2[1][1] = s2 * a42;
    mtx2[2][1] = s2 * a52;
    mtx2[0][2] = s2 * a62;
    mtx2[1][2] = s2 * a72;
    mtx2[2][2] = s2 * a82;
    if (*(f32*)(c + 0x14) != lbl_80541A20) {
        rec.b1c = 1;
    }
    s32 mode = *(s32*)(c + 0x258);
    if (mode == 4 || mode == 5) {
        fn_801F06F0(p, name, id, &rec, -1, lbl_80541A24, lbl_80541A24);
        JGeometry::TVec3<f32> save = *(JGeometry::TVec3<f32>*)(c + 0xc);
        *(f32*)(c + 0x10) = *(f32*)(c + 0x10) - lbl_80541A24;
        if (*(u32*)(c + 0x138) == 0) {
            fn_801EF830(*(s32*)(c + 4), c + 0xc, &rec, 7, name, id, 0);
        }
        *(JGeometry::TVec3<f32>*)(c + 0xc) = save;
    } else {
        fn_801F06F0(p, name, id, &rec, 7, lbl_80541A24, lbl_80541A24);
    }
    fn_803075AC(*(void**)(c + 0x198), *(s32*)(c + 4), c + 0xc, id, 0, 2, -1, 0, 0, 0);
}

extern "C" const f32 lbl_80541A28;
extern "C" const f32 lbl_80541A2C;
extern "C" const f32 lbl_80541A30;
extern "C" const f32 lbl_80541A34;
extern "C" char lbl_80471708[];
extern "C" void fn_80239914(void* box, s32 room, void* handle);
extern "C" void fn_8020D8C0(void* a, void* box, s32 room, void* handle);
extern "C" void* fn_8020D58C();
extern "C" s32 fn_8023AB94(void* box, s32 room, void* pos);
extern "C" s32 fn_801F26CC(Actor* a, const char* name);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" s32 fn_801F8544(void* mgr, u32 tag, u32 id, f32* pos, s32 n);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void* mgr, u32 kind, u32 a, u32 b);
extern "C" void fn_8031E640(Actor* p) {
    char* c = (char*)p;
    JGeometry::TVec2<f32> pos;
    JGeometry::TBox2<f32> box;
    box.set(*(JGeometry::TBox2<f32>*)(c + 0x60));
    pos.set(*(f32*)(c + 0xc), *(f32*)(c + 0x10));
    box.addPos(pos);
    switch (*(s32*)(c + 0x230)) {
    case 0: {
        fn_80239914(&box, *(s32*)(c + 4), *(void**)(c + 0x198));
        void* h = *(void**)(c + 0x198);
        s32 room = *(s32*)(c + 4);
        u8* base = (u8*)fn_8020D58C();
        fn_8020D8C0(base + base[0] * 0x784 + 4, &box, room, h);
        if (fn_8023AB94(&box, *(s32*)(c + 4), &pos) >= 0 || fn_801F26CC(p, lbl_80471708) >= 0) {
            if (*(s32*)(c + 0x248) == 0) {
                fn_801F0E34(p, 0x30005, 0);
                Actor_CreateByID(fn_801F856C(), 0x424c5a45, *(u32*)(c + 4), (f32*)(c + 0xc), 0, -1, -1);
            } else {
                fn_8013CC50(*(void**)(c + 4), c + 0xc, lbl_80541A28 * *(f32*)(c + 0x240), 0x28d, 0, 0, 0, 0, 1);
                fn_8013CC50(*(void**)(c + 4), c + 0xc, lbl_80541A28 * *(f32*)(c + 0x240), 0x28e, 0, 0, 0, 0, 1);
                fn_801F0E34(p, 0x30061, 0);
            }
            *(s32*)(c + 0x230) = 1;
            *(s32*)(c + 0x25c) = 0x28;
        }
        break;
    }
    case 1: {
        fn_80239914(&box, *(s32*)(c + 4), *(void**)(c + 0x198));
        *(s32*)(c + 0x25c) = *(s32*)(c + 0x25c) - 1;
        if (*(s32*)(c + 0x25c) <= 0) {
            s32 mode = *(s32*)(c + 0x258);
            s32 k;
            if (mode == 4 || mode == 5) {
                k = mode - 4;
            } else {
                k = mode + 4;
            }
            s32 idx = fn_801F8544(fn_801F856C(), 0x52555059, *(u32*)(c + 4), (f32*)(c + 0xc), k);
            s32 n = *(s32*)(c + 0x260);
            if (n > 0) {
                fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
            }
            if (idx >= 0) {
                Actor* q = (Actor*)fn_801F666C(fn_801F856C(), idx);
                if (q != 0) {
                    *(JGeometry::TVec3<f32>*)&q->field_3C = JGeometry::TVec3<f32>(lbl_80541A20, lbl_80541A20, lbl_80541A2C);
                }
            }
            fn_8013CC50(*(void**)(c + 4), c + 0xc, lbl_80541A30, 0x19d, 0, 0, 0, 0, 1);
            p->detach();
        }
        break;
    }
    case 3:
        if (*(s32*)(c + 0x230) == 3) {
            Actor* e = *(Actor**)(c + 0x268);
            if (e != 0) {
                *(u32*)((char*)e + 0xf4) |= 1;
                *(s32*)((char*)e + 0x24) = 1;
                *(s32*)(c + 0x268) = 0;
            }
        }
    case 2:
        *(f32*)(c + 0x23c) += lbl_80541A30;
        *(f32*)(c + 0x238) -= lbl_80541A34;
        if (*(f32*)(c + 0x238) < lbl_80541A30) {
            p->detach();
        }
        break;
    }
    if (*(s32*)(c + 0x248) == 1) {
        *(s32*)(c + 0x24c) = *(s32*)(c + 0x24c) - 1;
        if (*(s32*)(c + 0x24c) <= 0) {
            *(s32*)(c + 0x250) = *(s32*)(c + 0x250) + 1;
            *(s32*)(c + 0x250) = *(s32*)(c + 0x250) & 3;
            if (*(s32*)(c + 0x250) == 0) {
                u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
                *seed = *seed * 0x19660du + 0x3c6ef35fu;
                u32 bits = (*seed >> 9) | 0x3f800000u;
                *(s32*)(c + 0x24c) = (s32)(lbl_80541A38 * (*(f32*)&bits - lbl_80541A24)) + 0x3c;
            } else {
                *(s32*)(c + 0x24c) = 2;
            }
        }
    }
}

extern "C" BOOL fn_8031EA3C(Actor* p, s32 param_2, s32 param_3) {
    s32 status = (u16)fn_8022461C(param_3);
    if (status == 0xc || status == 3 || status == 0xe) {
        p->field_3C.x = p->field_3C.y = p->field_3C.z = lbl_80541A20;
        *(s32*)((char*)p + 0x230) = 2;
        return FALSE;
    } else if (status == 0xd) {
        p->field_3C.x = p->field_3C.y = p->field_3C.z = lbl_80541A20;
        if (*(u32*)((char*)p + 0x268) == 0) {
            *(s32*)((char*)p + 0x268) = fn_8013CC50(*(void**)((char*)p + 4), (char*)p + 0xc, lbl_80541A24, 0x3d0, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x30022, 0);
        }
        *(s32*)((char*)p + 0x230) = 3;
        return FALSE;
    }
    return status != 0;
}

extern "C" void fn_8031EB28(Actor* p) {
    char* c = (char*)p;
    f32 one = lbl_80541A24;
    *(u32*)(c + 0x258) = p->field_90 & 0xf;
    *(u32*)(c + 0x248) = (p->field_90 >> 16) & 0xf;
    *(u32*)(c + 0x268) = 0;
    *(u32*)(c + 0x260) = (p->field_90 >> 22) & 0x1f;
    *(u32*)(c + 0xb0) = 0x2300;
    *(u32*)(c + 0x230) = 0;
    *(u16*)(c + 0x264) = 0;
    *(u32*)(c + 0x108) = 10000;
    *(u32*)(c + 0x244) = 0;
    *(s32*)(c + 0x254) = -1;
    *(u32*)(c + 0x98) = 0;
    *(f32*)(c + 0x238) = one;
    *(f32*)(c + 0x23c) = lbl_80541A20;
    *(u32*)(c + 0x25c) = 0;

    u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660du + 0x3c6ef35fu;
    u32 bits = (*seed >> 9) | 0x3f800000u;
    *(s32*)(c + 0x24c) = (s32)(lbl_80541A38 * (*(f32*)&bits - one)) + 0x3c;
    *(u32*)(c + 0x250) = 0;

    s32 mode = *(s32*)(c + 0x258);
    if (mode == 4 || mode == 5) {
        *(f32*)(c + 0x240) = lbl_80541A3C;
    } else {
        *(f32*)(c + 0x240) = one;
    }

    if ((u8)p->v11()) {
        p->detach();
    } else {
        f32 v = lbl_80541A44;
        *(f32*)(c + 0x234) = lbl_80541A40;
        p->field_3C.x = lbl_80541A20;
        p->field_3C.y = lbl_80541A20;
        p->field_3C.z = lbl_80541A20;
        *(f32*)(c + 0x80) = v;
        *(f32*)(c + 0x84) = v;
        f32 w = lbl_80541A48;
        *(f32*)(c + 0x88) = w;
        *(f32*)(c + 0x8c) = w;
        f32 x = lbl_80541A4C;
        *(f32*)(c + 0x60) = x;
        *(f32*)(c + 0x64) = x;
        f32 y = lbl_80541A50;
        *(f32*)(c + 0x68) = y;
        *(f32*)(c + 0x6c) = y;
        if (((u8*)lbl_8053AAF8)[0x7f] == 0) {
            p->detach();
        }
    }
}

extern "C" Actor* fn_8031ECBC(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB1F0;
        fn_801EE434(*(void**)((char*)p + 0x268));
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" char lbl_805084F8[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_8031ED28(void)
{
  char* base = &lbl_805084F8[0];
  if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
    __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
    __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
    __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
  }
  if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
    __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
    __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
    __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
  }
  if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
    __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
    __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
    __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
  }
  if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
    __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
    __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
    __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
  }
  if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
    __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
    __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
    __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
  }
  if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
    __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
    __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
    __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
  }
  if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
    __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
    __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
    __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
  }
  if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
    __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
    __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
    __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
  }
  if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
    __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
    __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
    __init__memPool___26JASPoolAllocObject_5JAISe = 1;
  }
}

