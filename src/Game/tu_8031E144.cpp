#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AB1F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" f32 lbl_80541A20;
extern "C" f32 lbl_80541A24;
extern "C" f32 lbl_80541A38;
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
  char* base = lbl_805084F8;
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

