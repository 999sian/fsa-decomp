#include "Game/Actor.h"


struct JMathSinCos {
    f32 sin;
    f32 cos;
};
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" void* lbl_8053AAF8;
struct ActorRoomModes;
extern "C" ActorRoomModes* fn_802D6A9C(void);
extern "C" char lbl_804AB098[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8031A210(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB098;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

struct ActorRoomModes {
    u8 pad_0x0[0x131df];
    u8 mode[16];
};

inline u8 actorRoomMode(u32 room) {
    ActorRoomModes* g = fn_802D6A9C();
    return g->mode[room];
}

inline f32 actorRandomUnit() {
    union { u32 bits; f32 value; } out;
    u32* seed = (u32*)((char*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    out.bits = (*seed >> 9) | 0x3f800000;
    return out.value - 1.0f;
}

extern "C" void fn_8031B994(Actor* p) {
    char* g1;
    u32 rawSeed;
    u32 b1;
    for (s32 i=0; i<1; i++) {
    *(u16*)((char*)p + 0x94) = (*(u32*)((char*)p + 0x90) >> 16) & 0xff;
    *(s32*)((char*)p + 0x270) = *(u32*)((char*)p + 0x90) & 7;
    *(s32*)((char*)p + 0x274) = (*(u32*)((char*)p + 0x90) >> 12) & 1;
    *(u8*)((char*)p + 0x284) = (*(u32*)((char*)p + 0x90) >> 14) & 1;
    *(u8*)((char*)p + 0x286) = (*(u32*)((char*)p + 0x90) >> 10) & 1;
    *(u8*)((char*)p + 0x282) = (*(u32*)((char*)p + 0x90) >> 25) & 1;
    *(u8*)((char*)p + 0x283) = (*(u32*)((char*)p + 0x90) >> 26) & 1;
    *(s32*)((char*)p + 0x25c) = 0;
    *(s32*)((char*)p + 0x260) = 0;
    *(s32*)((char*)p + 0x264) = 0;
    *(s32*)((char*)p + 0x268) = 0;
    *(s32*)((char*)p + 0x24c) = 0;
    *(s32*)((char*)p + 0x250) = 0;
    *(s32*)((char*)p + 0x254) = 0;
    *(s32*)((char*)p + 0x258) = 0;
    *(u16*)((char*)p + 0x288) = 0;
    *(s32*)((char*)p + 0x108) = 10000;
    *(s32*)((char*)p + 0x26c) = -1;
    *(s32*)((char*)p + 0x98) = 0;
    *(f32*)((char*)p + 0x298) = *(f32*)((char*)p + 0xc);
    *(f32*)((char*)p + 0x29c) = *(f32*)((char*)p + 0x10);
    *(f32*)((char*)p + 0x2a0) = *(f32*)((char*)p + 0x14);
    *(f32*)((char*)p + 0x2ac) = 0.0f;
    *(f32*)((char*)p + 0x2a8) = 0.0f;
    *(f32*)((char*)p + 0x2a4) = 0.0f;
    *(s32*)((char*)p + 0x268) = 100;
    *(s32*)((char*)p + 0x278) = 0;
    *(f32*)((char*)p + 0x23c) = 1.0f;
    *(f32*)((char*)p + 0x240) = 0.0f;
    *(f32*)((char*)p + 0x244) = 0.0f;
    *(f32*)((char*)p + 0x248) = 0.0f;
    *(u8*)((char*)p + 0x280) = 0;
    *(u8*)((char*)p + 0x281) = (*(u32*)((char*)p + 0x90) >> 24) & 1;
    *(u8*)((char*)p + 0x285) = (*(u32*)((char*)p + 0x90) >> 8) & 1;
    *(f32*)((char*)p + 0x238) = 30.0f;
    *(f32*)((char*)p + 0x2b8) = 0.0f;
    *(f32*)((char*)p + 0x2b4) = 0.0f;
    *(f32*)((char*)p + 0x2b0) = 0.0f;
    {
        g1 = (char*)lbl_8053AAF8;
        u32 s = *(u32*)(g1 + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g1 + 0xb4) = s;
    }
    }
    rawSeed = *(u32*)(g1 + 0xb4);
    b1 = (rawSeed >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x27c) = (s32)(65536.0f * (*(f32*)&b1 - 1.0f));
    *(s32*)((char*)p + 0x230) = 0;
    *(s32*)((char*)p + 0x234) = *(s32*)((char*)p + 0x230);
    {
        char* g = (char*)lbl_8053AAF8;
        u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g + 0xb4) = s;
        u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        *(s32*)((char*)p + 0x264) = (s32)(65535.0f * (*(f32*)&b - 1.0f));
    }
    *(f32*)((char*)p + 0x14) = 24.0f;
    if (*(s32*)((char*)p + 0x274) != 0) {
        *(f32*)((char*)p + 0x14) = 8.0f;
        *(s32*)((char*)p + 0xb0) = 0x20000;
    }
    {
        u32 room = *(u32*)((char*)p + 4);
        if (actorRoomMode(room) != 0) {
            *(f32*)((char*)p + 0x10) = *(f32*)((char*)p + 0x10) - *(f32*)((char*)p + 0x14);
            *(f32*)((char*)p + 0x14) = 0.0f;
            *(s32*)((char*)p + 0xb0) = 0x20000;
        }
    }
    switch (*(u16*)((char*)p + 0x94)) {
    case 0:
        *(u8*)((char*)p + 0x17c) = 0;
        *(s32*)((char*)p + 0x174) = 50;
        break;
    case 1:
    case 6:
        *(s32*)((char*)p + 0x98) = 2;
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 2:
    case 7:
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 3:
        *(s32*)((char*)p + 0x268) = -100;
        /* fallthrough */
    case 4:
        *(f32*)((char*)p + 0xc) = *(f32*)((char*)p + 0x238) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x264) >> 5].sin + *(f32*)((char*)p + 0x298);
        *(f32*)((char*)p + 0x10) = *(f32*)((char*)p + 0x238) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x264) >> 5].cos + *(f32*)((char*)p + 0x29c);
        break;
    case 5:
        *(s32*)((char*)p + 0x180) = 60;
        break;
    case 8:
        *(s32*)((char*)p + 0x230) = 3;
        *(f32*)((char*)p + 0x14) = 0.0f;
        break;
    }
    *(f32*)((char*)p + 0x28c) = 0.0f;
    *(f32*)((char*)p + 0x290) = 0.0f;
    *(f32*)((char*)p + 0x294) = 0.0f;
    *(f32*)((char*)p + 0x3c) = 0.0f;
    *(f32*)((char*)p + 0x40) = 0.0f;
    *(f32*)((char*)p + 0x44) = 0.0f;
    *(f32*)((char*)p + 0x80) = -7.0f;
    *(f32*)((char*)p + 0x84) = -4.0f;
    *(f32*)((char*)p + 0x88) = 7.0f;
    *(f32*)((char*)p + 0x8c) = 4.0f;
    if (*(u16*)((char*)p + 0x94) == 5 || *(s32*)((char*)p + 0x274) != 0) {
        *(f32*)((char*)p + 0x60) = -7.0f;
        *(f32*)((char*)p + 0x64) = -23.0f;
        *(f32*)((char*)p + 0x68) = 7.0f;
        *(f32*)((char*)p + 0x6c) = 7.0f;
    } else {
        *(f32*)((char*)p + 0x60) = -8.0f;
        *(f32*)((char*)p + 0x64) = -32.0f;
        *(f32*)((char*)p + 0x68) = 8.0f;
        *(f32*)((char*)p + 0x6c) = 16.0f;
    }
    if (*((u8*)lbl_8053AAF8 + 0x7f) == 0) {
        p->detach();
    } else if (*(u8*)((char*)p + 0x283) == 1 && *((u8*)lbl_8053AAF8 + 0x7e) == 0) {
        p->detach();
    } else if (*(u8*)((char*)p + 0x285) == 1) {
        *(s32*)((char*)p + 0x234) = *(s32*)((char*)p + 0x230);
        *(s32*)((char*)p + 0x230) = 1;
    }
}

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
extern "C" void fn_8031BE2C(void)
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

