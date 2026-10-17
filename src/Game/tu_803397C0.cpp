#include "Game/Actor.h"


extern "C" char lbl_804AC100[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803397C0(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AC100;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(u8* p, s32 a, f32* b, s32 c, s32 d);
extern "C" u16 fn_8022461C(f32* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" BOOL fn_8033B7FC(Actor* self, s32 a, f32* b) {
    s32 region = self->field_198;
    u8* base = static_cast<u8*>(fn_8020D58C());
    if (fn_8020D6AC(base + base[1] * 0x784 + 4, a, b, region, 0) == 1) {
        return 1;
    }
    u16 code = fn_8022461C(b, a);
    if (code == 0 || code == 2 || code == 0x50) {
        return 0;
    }
    if (code == 0x22 && static_cast<u8*>(fn_802D6A9C())[0x170] == 0) {
        return 0;
    }
    if (code == 0x39) {
        return 0;
    }
    if (code == 0x25 && static_cast<u8*>(fn_802D6A9C())[0x171] == 0) {
        return 0;
    }
    if (code == 4) {
        if (((s32)b[1] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 5) {
        if (((s32)b[1] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 6) {
        if (((s32)b[0] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 7) {
        if (((s32)b[0] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 3 || code == 0xe || code == 0xd) {
        return 0;
    }
    return 1;
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_8033B9D8(u8* self) {
    s32 idx = -1;
    s32 best = 0;
    u8* obj;
    s32 v;

    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 0x464c594f, idx);
        if (idx < 0) {
            break;
        }
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0) {
            continue;
        }
        if (*(s32*)(obj + 0x230) == 0 || *(s32*)(obj + 0x230) == 4) {
            v = *(s32*)(obj + 0x248);
        } else {
            v = 0xfff;
        }
        if (v < *(s32*)(self + 0x26c)) {
            *(s32*)(self + 0x26c) = v;
        }
        if (best < v && v < *(s32*)(self + 0x244)) {
            best = v;
        }
    }
    if (*(s32*)(self + 0x26c) == *(s32*)(self + 0x244)) {
        *(u8*)(self + 0x278) = 1;
    }
    if (best != 0) {
        *(s32*)(self + 0x274) = *(s32*)(self + 0x244) - best;
    }
}

extern "C" void fn_802D9C4C(void);
extern "C" void fn_8033BAC8(u8* self) {
    *(u32*)(self + 0x244) = *(u32*)(self + 0x90) & 0x7ff;
    *(u32*)(self + 0x250) = (*(u32*)(self + 0x90) >> 11) & 0x1f;
    *(u32*)(self + 0x24c) = (*(u32*)(self + 0x90) >> 16) & 0xf;
    *(u32*)(self + 0x254) = (*(u32*)(self + 0x90) >> 20) & 0xf;
    *(u32*)(self + 0x264) = ((*(u32*)(self + 0x90) >> 24) & 7) * 5 + 0xf;
    *(u32*)(self + 0x108) = 0;
    *(f32*)(self + 0x284) = 0.0f;
    *(f32*)(self + 0x280) = 0.0f;
    *(f32*)(self + 0x27c) = 0.0f;
    *(f32*)(self + 0x44) = 0.0f;
    *(f32*)(self + 0x40) = 0.0f;
    *(f32*)(self + 0x3c) = 0.0f;
    *(u16*)(self + 0x234) = 0;
    *(u32*)(self + 0x260) = 0;
    *(u32*)(self + 0x288) = 0;
    *(u32*)(self + 0x238) = 0;
    *(u32*)(self + 0x23c) = 5;
    *(u16*)(self + 0x25a) = 0;
    *(u32*)(self + 0x240) = 0x8000;
    *(u8*)(self + 0x258) = 0;
    *(u32*)(self + 0x114) = 1;
    *(u32*)(self + 0x268) = 1;
    *(u32*)(self + 0x270) = *(u32*)(self + 0x244) * 0x3c + 0x3c;
    *(u32*)(self + 0x248) = *(u32*)(self + 0x244);
    *(u8*)(self + 0x278) = 0;
    *(u32*)(self + 0x26c) = 0xfff;
    *(u32*)(self + 0x274) = 0;
    if (*(s32*)(self + 0x250) == 0) {
        *(u32*)(self + 0x230) = 0;
    } else {
        *(u32*)(self + 0x230) = 4;
    }
    switch (*(u32*)(self + 0x24c)) {
    case 0:
    case 5:
        *(f32*)(self + 0xc) += 8.0f;
        *(f32*)(self + 0x10) += 8.0f;
        *(f32*)(self + 0x80) = 8.0f;
        *(f32*)(self + 0x84) = 8.0f;
        *(f32*)(self + 0x88) = 0.0f;
        *(f32*)(self + 0x8c) = 0.0f;
        *(f32*)(self + 0x60) = 8.0f;
        *(f32*)(self + 0x64) = 8.0f;
        *(f32*)(self + 0x68) = 0.0f;
        *(f32*)(self + 0x6c) = 0.0f;
        *(u16*)(self + 0x25c) = 0x1000;
        *(u32*)(self + 0x114) = 2;
        break;
    case 1:
        *(f32*)(self + 0x80) = -7.0f;
        *(f32*)(self + 0x84) = -7.0f;
        *(f32*)(self + 0x88) = 7.0f;
        *(f32*)(self + 0x8c) = 7.0f;
        *(f32*)(self + 0x60) = -7.0f;
        *(f32*)(self + 0x64) = -7.0f;
        *(f32*)(self + 0x68) = 7.0f;
        *(f32*)(self + 0x6c) = 7.0f;
        *(u16*)(self + 0x25c) = 0x1000;
        *(u32*)(self + 0x114) = 2;
        break;
    case 2:
        *(f32*)(self + 0x10) += 16.0f;
        *(f32*)(self + 0x80) = -30.0f;
        *(f32*)(self + 0x84) = -30.0f;
        *(f32*)(self + 0x88) = 30.0f;
        *(f32*)(self + 0x8c) = 30.0f;
        *(f32*)(self + 0x60) = -30.0f;
        *(f32*)(self + 0x64) = -30.0f;
        *(f32*)(self + 0x68) = 30.0f;
        *(f32*)(self + 0x6c) = 30.0f;
        *(u16*)(self + 0x25c) = 0x800;
        fn_802D6A9C();
        fn_802D9C4C();
        *(void**)(self + 0x288) = fn_802D6A9C();
        *(u32*)(self + 0x114) = 2;
        break;
    case 3:
        *(f32*)(self + 0x80) = -40.0f;
        *(f32*)(self + 0x84) = -40.0f;
        *(f32*)(self + 0x88) = 40.0f;
        *(f32*)(self + 0x8c) = 40.0f;
        *(f32*)(self + 0x60) = -40.0f;
        *(f32*)(self + 0x64) = -40.0f;
        *(f32*)(self + 0x68) = 40.0f;
        *(f32*)(self + 0x6c) = 40.0f;
        *(u16*)(self + 0x25c) = 0x400;
        fn_802D6A9C();
        fn_802D9C4C();
        *(void**)(self + 0x288) = fn_802D6A9C();
        *(u32*)(self + 0x114) = 4;
        *(u32*)(self + 0x268) = 2;
        break;
    case 4:
        *(f32*)(self + 0x80) = -7.0f;
        *(f32*)(self + 0x84) = -7.0f;
        *(f32*)(self + 0x88) = 7.0f;
        *(f32*)(self + 0x8c) = 7.0f;
        *(f32*)(self + 0x60) = -7.0f;
        *(f32*)(self + 0x64) = -7.0f;
        *(f32*)(self + 0x68) = 7.0f;
        *(f32*)(self + 0x6c) = 7.0f;
        *(u16*)(self + 0x25c) = 0x800;
        *(u32*)(self + 0x114) = 4;
        break;
    case 6:
        *(f32*)(self + 0x80) = -7.0f;
        *(f32*)(self + 0x84) = -7.0f;
        *(f32*)(self + 0x88) = 7.0f;
        *(f32*)(self + 0x8c) = 7.0f;
        *(f32*)(self + 0x60) = -14.0f;
        *(f32*)(self + 0x64) = -14.0f;
        *(f32*)(self + 0x68) = 14.0f;
        *(f32*)(self + 0x6c) = 14.0f;
        *(u16*)(self + 0x25c) = 0x800;
        *(u32*)(self + 0x114) = 4;
        break;
    case 7:
    case 8:
    case 9:
        *(f32*)(self + 0xc) += 8.0f;
        *(f32*)(self + 0x10) += 8.0f;
        *(f32*)(self + 0x80) = -7.0f;
        *(f32*)(self + 0x84) = -7.0f;
        *(f32*)(self + 0x88) = 7.0f;
        *(f32*)(self + 0x8c) = 7.0f;
        *(f32*)(self + 0x60) = -7.0f;
        *(f32*)(self + 0x64) = -7.0f;
        *(f32*)(self + 0x68) = 7.0f;
        *(f32*)(self + 0x6c) = 7.0f;
        *(u16*)(self + 0x25c) = 0x800;
        *(u32*)(self + 0x114) = 2;
        break;
    }
}

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
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_8033BE5C(void) {
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

