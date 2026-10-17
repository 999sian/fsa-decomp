#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AC4D0[];
extern "C" void* lbl_8053AAF8;
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
s32 fn_802D6A9C(void);
u8 fn_802D800C(s32, s32);
extern f32 lbl_805422E0;
extern f32 lbl_805422C4;
extern "C" s32 fn_802D6A9C(void);
extern "C" u8 fn_802D800C(s32, s32);
extern "C" s32 fn_802D6A9C();
extern "C" void PSMTXIdentity(f32 m[3][4]);
extern "C" void fn_801F06F0(u8* p, void* a, s32 b, void* c, s32 d, f32 e, f32 f);
extern "C" const f32 lbl_805422B8;
extern "C" const f32 lbl_805422BC;
extern "C" char lbl_80471EC8[];
extern "C" const f32 lbl_805422C0;
extern "C" void fn_80340EC8(u8* p) {
    if (*(s32*)(p + 0x230) == 8 || *(s32*)(p + 0x230) == 0xb) {
        DrawRec rec;
        f32 m[3][4];
        PSMTXIdentity(m);
        rec.b2e = 0x40;
        if (*(s32*)(p + 0x230) == 8) {
            f32 f3 = *(f32*)(p + 0x250);
            m[0][0] = f3;
            m[0][1] = lbl_805422C0;
            m[0][2] = lbl_805422C0;
            m[1][0] = lbl_805422C0;
            m[1][1] = lbl_805422B8 - lbl_805422BC * f3;
            m[1][2] = lbl_805422C0;
            m[2][0] = lbl_805422C0;
            m[2][1] = lbl_805422C0;
            m[2][2] = m[1][1];
        } else {
            f32 f3 = *(f32*)(p + 0x250);
            m[0][0] = f3;
            m[0][1] = lbl_805422C0;
            m[0][2] = lbl_805422C0;
            m[1][0] = lbl_805422C0;
            m[1][1] = lbl_805422BC - f3;
            m[1][2] = lbl_805422C0;
            m[2][0] = lbl_805422C0;
            m[2][1] = lbl_805422C0;
            m[2][2] = m[1][1];
        }
        rec.w18 = m;
        fn_801F06F0(p, lbl_80471EC8, *(s32*)(p + 0x23c), &rec, 7, lbl_805422C4, lbl_805422C4);
    } else if (*(s32*)(p + 0x230) >= 4 && *(s32*)(p + 0x230) <= 7) {
        fn_801F06F0(p, lbl_80471EC8, *(s32*)(p + 0x23c), 0, 7, lbl_805422C4, lbl_805422C4);
    }
}

extern "C" void fn_803418B8(Actor* p) {
    *(s32*)((u8*)p + 0x240) = (*(u32*)((u8*)p + 0x90) >> 12) & 0xff;
    *(s32*)((u8*)p + 0x23c) = 0;
    *(s32*)((u8*)p + 0x244) = -1;
    if (*(s32*)((u8*)p + 0x240) == 0) {
        *(u8*)((u8*)p + 0x254) = 1;
    } else {
        *(u8*)((u8*)p + 0x254) = 0;
        *(s32*)((u8*)p + 0x240) = *(s32*)((u8*)p + 0x240) - 1;
    }
    *(s32*)((u8*)p + 0x248) = (*(u32*)((u8*)p + 0x90) >> 22) & 0x1f;
    if ((*(u32*)((u8*)p + 0x90) >> 27) != 0) {
        *(s32*)((u8*)p + 0x230) = 0;
        *(s32*)((u8*)p + 0x238) = 0;
        *(s32*)((u8*)p + 0x234) = 0;
    } else {
        *(s32*)((u8*)p + 0x230) = 1;
        *(s32*)((u8*)p + 0x238) = 0;
        *(u32*)((u8*)p + 0x234) = *(u32*)((u8*)p + 0x90) & 0x7f;
    }
    if (((u8*)lbl_8053AAF8)[0x7f] == 0) {
        s32 idx = *(s32*)((u8*)p + 0x4);
        u8* base = (u8*)fn_802D6A9C();
        if ((base + idx + 0x10000)[0x31df] == 1) {
            *(f32*)((u8*)p + 0x10) = *(f32*)((u8*)p + 0x10) + lbl_805422E0;
            *(f64*)((u8*)p + 0x24) = *(f64*)((u8*)p + 0xc);
            *(f32*)((u8*)p + 0x2c) = *(f32*)((u8*)p + 0x14);
            *(f32*)((u8*)p + 0x250) = lbl_805422C4;
        }
    }
    if (fn_802D800C(fn_802D6A9C(), *(s32*)((u8*)p + 0x248)) == 0 && ((u8*)lbl_8053AAF8)[0x7f] == 1) {
        *(u8*)((u8*)p + 0x255) = 1;
    } else {
        *(u8*)((u8*)p + 0x255) = 0;
    }
}

extern "C" Actor* fn_80341A00(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AC4D0;
        if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
            s32 kind = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
            if (kind != 9 && kind != 0xb) {
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" char lbl_8050A0F8[];
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
extern "C" void fn_80341A8C(void) {
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

