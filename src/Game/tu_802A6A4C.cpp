#include "Game/Actor.h"


extern "C" char lbl_804A7F38[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802A6A4C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A7F38;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* lbl_8053AC98;
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_802A6AAC(Actor* p, s32 player) {
    switch (*(u16*)((u8*)p + 0x258)) {
    case 0x41:
    case 0x12:
    case 0x68:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x13);
        break;
    case 0x50:
    case 0x43:
    case 0x6a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x51);
        break;
    case 0x14:
    case 0x52:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x15);
        break;
    case 0x15a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x360);
        break;
    }
}

extern "C" void fn_802A6BC0(void) {}

extern f32 lbl_80540804;
extern f32 lbl_80540808;
extern f32 lbl_8054080C;
extern f32 lbl_80540810;
extern "C" void fn_802A7978(Actor* p) {
    u8* base = (u8*)p;
    f32 k;
    f32 c;
    f32 d;
    s32 v;

    *(u32*)(base + 0x238) = ((*(u32*)(base + 0x90) >> 0x16) & 0x1f) + 1;
    *(u32*)(base + 0x23c) = ((*(u32*)(base + 0x90) >> 0x11) & 0x1f) + 1;
    *(u32*)(base + 0x240) = *(u32*)(base + 0x90) & 0x3e0;
    *(u32*)(base + 0x234) = *(u32*)(base + 0x90) & 0x1f;
    *(s32*)(base + 0x264) = (*(u32*)(base + 0x90) >> 0xc) & 0x1f;
    if (*(s32*)(base + 0x264) == 0) {
        *(s32*)(base + 0x264) = -1;
    }
    *(u32*)(base + 0x25c) = *(u32*)(base + 0x90) >> 0x1b;
    if (*(s32*)(base + 0x234) == 8 && *(s32*)(base + 0x240) == 0) {
        *(s32*)(base + 0x240) = 0x3c;
    }
    v = *(s32*)(base + 0x240);
    k = lbl_80540804;
    *(s32*)(base + 0x24c) = v;
    *(f32*)(base + 0xc) = *(f32*)(base + 0xc) + k;
    *(f32*)(base + 0x10) = *(f32*)(base + 0x10) + k;
    if (*(s32*)(base + 0x234) == 2 || *(s32*)(base + 0x234) == 3) {
        d = lbl_8054080C;
        c = lbl_80540808;
        *(f32*)(base + 0x60) = c;
        *(f32*)(base + 0x64) = c;
        *(f32*)(base + 0x68) = d;
        *(f32*)(base + 0x6c) = d;
    } else if (*(s32*)(base + 0x234) == 7) {
        f32 a = lbl_80540810 * (f32)*(s32*)(base + 0x238);
        f32 b = lbl_80540810 * (f32)*(s32*)(base + 0x23c);
        *(f32*)(base + 0x60) = -a;
        *(f32*)(base + 0x64) = -b;
        *(f32*)(base + 0x68) = a;
        *(f32*)(base + 0x6c) = b;
    } else {
        d = lbl_8054080C;
        c = lbl_80540808;
        *(f32*)(base + 0x60) = c;
        *(f32*)(base + 0x64) = c;
        *(f32*)(base + 0x68) = d;
        *(f32*)(base + 0x6c) = d;
    }
    *(s32*)(base + 0x248) = 0;
    if (*(s32*)(base + 0x234) == 4 || *(s32*)(base + 0x234) == 7) {
        *(s32*)(base + 0x230) = 2;
    } else {
        *(s32*)(base + 0x230) = 1;
    }
    *(s32*)(base + 0x250) = -1;
    *(s32*)(base + 0x260) = -1;
}

extern "C" char lbl_804D0C68[];
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
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_802A7B18(void)
{
    static u32 c0[3];
    static u32 c1[3];
    static u32 c2[3];
    static u32 c3[3];
    static u32 c4[3];
    static u32 c5[3];
    static u32 c6[3];
    static u32 c7[3];
    static u32 c8[3];
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

