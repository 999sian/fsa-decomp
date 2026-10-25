#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void fn_80230498(s32, const JGeometry::TVec3f&, s32, s32, s32, s32, s32);
extern "C" char lbl_804AE230[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_80542CE4;
extern "C" f32 lbl_80542CD8;
extern "C" f32 lbl_80542CDC;
extern "C" f32 lbl_80542CE0;
extern "C" f32 lbl_80542CE8;
extern "C" f32 lbl_80542CEC;
extern "C" f32 lbl_80542CF0;
extern "C" f32 lbl_80542CF4;
extern "C" f32 lbl_80542CF8;
extern "C" f32 lbl_80542CFC;
extern "C" f32 lbl_80542D00;
extern "C" void fn_8036CBBC(Actor*);
extern "C" s32 fn_80239470(void*, u32, void*);
extern "C" void fn_80239914(void*, u32, void*);
extern "C" void* fn_8023E724(s32);
extern "C" void fn_8023DFF4(s32, void*);
extern "C" u8 fn_8023077C(Actor*);
extern "C" void fn_801F0E34(Actor*, s32, s32);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" const char lbl_80474EAC[];
extern "C" void fn_802F86CC(void*, void*, void*, s32, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);

class SobResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern "C" Actor* fn_8036CB5C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AE230;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8036CE58(Actor* this_) {
    u8* p = (u8*)this_;
    s32 id = *(s32*)(p + 0x24c) + 0x147;
    if (*(s32*)(p + 4) < 8) {
        SobResMgr* mgr = *(SobResMgr**)(lbl_8053AAF8 + 0xa4);
        void* res = mgr->vf18('SOB ', lbl_80474EAC);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0x24, res, id, 0, lbl_80542CE4, lbl_80542CE4);
    }
    fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0x24, *(s32*)(p + 0x24c) + 0x147, 0, 1, -1, 0, 0, 0);
}

inline bool psw2Ready(Actor* p) {
    if ((p->field_90 >> 4) & 3) return false;
    for (s32 i=0; i<3; i++) {
        char* other = (char*)fn_801F666C(fn_801F856C(), *(s32*)((char*)p + 0x234 + i*4));
        if (*(f32*)(other + 0x254) < 8.0f) return false;
    }
    for (s32 i=0; i<3; i++) {
        char* other = (char*)fn_801F666C(fn_801F856C(), *(s32*)((char*)p + 0x234 + i*4));
        *(u8*)(other + 0x250) = 1;
    }
    return true;
}

extern "C" void fn_8036CF1C(Actor* this_) {
    u8* p = (u8*)this_;
    f32 box[4];
    f32 dx;
    s32 hit;

    box[0] = *(f32*)(p + 0x60) + *(f32*)(p + 0xc);
    box[1] = *(f32*)(p + 0x64) + *(f32*)(p + 0x10);
    box[2] = *(f32*)(p + 0x68) + *(f32*)(p + 0xc);
    box[3] = *(f32*)(p + 0x6c) + *(f32*)(p + 0x10);
    *(f32*)(p + 0x3c) = lbl_80542CD8;
    *(f32*)(p + 0x40) = lbl_80542CD8;
    *(f32*)(p + 0x44) = lbl_80542CD8;

    if (*(s32*)(p + 0x258) > 0) {
        *(s32*)(p + 0x258) -= 1;
        fn_8036CBBC(this_);
        hit = fn_80239470(box, *(u32*)(p + 4), *(void**)(p + 0x198));
        if (hit >= 0) {
            fn_80239914(box, *(u32*)(p + 4), *(void**)(p + 0x198));
            dx = *(f32*)(p + 0xc) - *(f32*)fn_8023E724(hit);
        }
    }

    if (*(u8*)(p + 0x250) != 0) {
        *(f32*)(p + 0x254) = lbl_80542CE0;
        *(f32*)(p + 0x10) = *(f32*)(p + 0x28) + *(f32*)(p + 0x254);
    }
}

extern "C" f32 lbl_80542CD8;
extern "C" f32 lbl_80542CE0;
extern "C" f32 lbl_80542CF4;
extern "C" f32 lbl_80542D04;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 Actor_CreateByID(void* reg, s32 type, s32 parent, Vec* pos, u32 flags, s32 a, s32 b);
extern "C" void fn_8036D3D8(Actor* this_) {
    u8* p = (u8*)this_;
    s32 i;

    if (((*(u32*)(p + 0x90) >> 4) & 3) == 0) {
        for (i = 0; i < 3; i++) {
            Vec base = *(Vec*)(p + 0xC);
            Vec off;
            Vec pos;
            u32 flags;

            off.x = lbl_80542CF4 * (f32)(i + 1);
            off.y = lbl_80542CD8;
            off.z = lbl_80542CD8;
            pos.x = base.x + off.x;
            pos.y = base.y + off.y;
            pos.z = base.z + off.z;
            flags = (*(u32*)(p + 0x90) & 0xF800000F) | ((i + 1) << 4);
            *(s32*)(p + 0x234 + i * 4) = -1;
            *(s32*)(p + 0x234 + i * 4) = Actor_CreateByID(fn_801F856C(), 0x50535732, *(s32*)(p + 4), &pos, flags, -1, -1);
            if (*(s32*)(p + 0x234 + i * 4) >= 0) {
                *(s32*)((u8*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x234 + i * 4)) + 0x230) = *(s32*)(p + 0x198);
            } else {
                this_->detach();
            }
        }
    }

    *(f32*)(p + 0x60) = lbl_80542D04;
    *(f32*)(p + 0x64) = lbl_80542D04;
    *(f32*)(p + 0x68) = lbl_80542CE0;
    *(f32*)(p + 0x6c) = lbl_80542CE0;
    *(f32*)(p + 0x80) = lbl_80542CD8;
    *(f32*)(p + 0x84) = lbl_80542CD8;
    *(f32*)(p + 0x88) = lbl_80542CD8;
    *(f32*)(p + 0x8c) = lbl_80542CD8;
    *(s32*)(p + 0x108) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(u8*)(p + 0x250) = this_->v11();
    if (*(u8*)(p + 0x250) != 0) {
        *(f32*)(p + 0x254) = lbl_80542CE0;
        *(f32*)(p + 0x10) = *(f32*)(p + 0x28) + *(f32*)(p + 0x254);
    } else {
        *(f32*)(p + 0x254) = lbl_80542CD8;
        *(f32*)(p + 0x3c) = lbl_80542CD8;
        *(f32*)(p + 0x40) = lbl_80542CD8;
        *(f32*)(p + 0x44) = lbl_80542CD8;
        *(s32*)(p + 0x258) = 0;
        *(s32*)(p + 0x25c) = -1;
        *(s32*)(p + 0x260) = 0;
    }
}

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_8036D5D4(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

