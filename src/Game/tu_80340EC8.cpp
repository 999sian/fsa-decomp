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
extern "C" f32 lbl_805422B8;
extern "C" f32 lbl_805422BC;
extern "C" f32 lbl_805422C4;
extern "C" char lbl_80471EC8[];
extern "C" f32 lbl_805422C0;
extern "C" void fn_80340EC8(u8* p) {
    struct Rec {
        u8 idx[16];
        s32 a;
        s32 b;
        f32 (*mtx)[4];
        u8 c[12];
        s32 d;
        u8 e[4];
        s32 f;
        s32 g;
        s32 h;
    };
    Rec rec;
    f32 m[3][4];
    u8 i;
    if (*(s32*)(p + 0x230) == 8 || *(s32*)(p + 0x230) == 0xb) {
        rec.a = -1;
        rec.b = -1;
        for (i = 0; i < 16; i += 8) {
            rec.idx[(u8)i] = i;
            rec.idx[(u8)(i + 1)] = i + 1;
            rec.idx[(u8)(i + 2)] = i + 2;
            rec.idx[(u8)(i + 3)] = i + 3;
            rec.idx[(u8)(i + 4)] = i + 4;
            rec.idx[(u8)(i + 5)] = i + 5;
            rec.idx[(u8)(i + 6)] = i + 6;
            rec.idx[(u8)(i + 7)] = i + 7;
        }
        rec.a = -1;
        rec.b = 0;
        rec.mtx = 0;
        rec.c[0] = 0;
        rec.c[1] = 0;
        rec.c[2] = 0;
        rec.c[3] = 1;
        rec.c[4] = 1;
        rec.c[5] = 0;
        rec.c[6] = 0;
        rec.c[7] = 0;
        rec.c[8] = 0;
        rec.c[9] = 0;
        rec.c[10] = 1;
        rec.d = 3;
        rec.e[0] = 1;
        rec.e[1] = 0;
        rec.e[2] = 0;
        rec.f = -1;
        rec.g = 0;
        rec.h = 2;
        PSMTXIdentity(m);
        rec.e[2] = 0x40;
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
        rec.mtx = m;
        fn_801F06F0(p, lbl_80471EC8, *(s32*)(p + 0x23c), (f32(*)[4])&rec, 7, lbl_805422C4, lbl_805422C4);
    } else if (*(s32*)(p + 0x230) > 3 && *(s32*)(p + 0x230) < 8) {
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
    char* base = lbl_8050A0F8;
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

