#include "Game/Actor.h"


extern "C" char lbl_804AE620[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80374788(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AE620;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" char lbl_80475120[];
extern "C" f32 lbl_80542ED8;
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, void* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80307AC8(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c);
extern "C" void fn_803747E8(Actor* this_) {
    char rec[0x3C];
    u8 i;

    *(s32*)(rec + 0x10) = -1;
    *(s32*)(rec + 0x14) = -1;
    for (i = 0; i < 0x10; i += 8) {
        rec[(u8)(i)] = i;
        rec[(u8)(i + 1)] = i + 1;
        rec[(u8)(i + 2)] = i + 2;
        rec[(u8)(i + 3)] = i + 3;
        rec[(u8)(i + 4)] = i + 4;
        rec[(u8)(i + 5)] = i + 5;
        rec[(u8)(i + 6)] = i + 6;
        rec[(u8)(i + 7)] = i + 7;
    }
    *(s32*)(rec + 0x10) = -1;
    *(s32*)(rec + 0x14) = 0;
    *(s32*)(rec + 0x18) = 0;
    rec[0x1c] = 0;
    rec[0x1d] = 0;
    rec[0x1e] = 0;
    rec[0x1f] = 1;
    rec[0x20] = 1;
    rec[0x21] = 0;
    rec[0x22] = 0;
    rec[0x23] = 0;
    rec[0x24] = 0;
    rec[0x25] = 0;
    rec[0x26] = 1;
    *(s32*)(rec + 0x28) = 3;
    rec[0x2c] = 1;
    rec[0x2d] = 0;
    rec[0x2e] = 0;
    *(s32*)(rec + 0x30) = -1;
    *(s32*)(rec + 0x34) = 0;
    *(s32*)(rec + 0x38) = 2;

    s32 idx = 0;
    if (*(s32*)((char*)this_ + 0x240) != 0) {
        idx = *(s32*)((char*)this_ + 0x240) + 3;
        rec[0x1d] = -1;
        fn_801F06F0(this_, lbl_80475120, idx + 0x45, rec, 0, lbl_80542ED8, lbl_80542ED8);
    }
    fn_80307AC8(*(void**)((char*)this_ + 0x198), this_->field_04, (char*)this_ + 0xc, idx + 0x45, 0, 0, -1);
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* a, u32 b, s32 c);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" u8 fn_8028D4DC(void* a, s32 b, s32 c);
extern "C" u8* lbl_8053AAF8;
extern "C" f32 lbl_80542EDC;
extern "C" f32 lbl_80542F10;
extern "C" f32 lbl_80542F14;
extern "C" f32 lbl_80542F18;
extern "C" void fn_803754E8(Actor* this_) {
    s32 mask;
    u8* p = (u8*)this_;
    s32 idx;
    s32 rnd;
    s32 mode;
    union {
        u32 i;
        f32 f;
    } bits;
    f32 fx;
    f32 fy;

    *(f32*)(p + 0x3c) = lbl_80542EDC;
    *(f32*)(p + 0x40) = lbl_80542EDC;
    *(f32*)(p + 0x44) = lbl_80542EDC;
    mode = (*(u32*)(p + 0x90) >> 2) & 7;
    if (mode == 5) {
        mask = 0;
        idx = -1;
        while (true) {
            idx = fn_801F78F4(fn_801F856C(), 0x42434B32, idx);
            if (idx < 0) {
                break;
            }
            if (idx == *(s32*)(p + 0x198)) {
                continue;
            }
            void* o = fn_801F666C(fn_801F856C(), idx);
            if (o != 0 && *(s32*)((u8*)o + 0x240) != 0) {
                mask |= 1 << *(s32*)((u8*)o + 0x240);
            }
        }
        do {
            u8* rng = lbl_8053AAF8;
            *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits.i = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
            rnd = (s32)(lbl_80542F10 * (bits.f - lbl_80542ED8) + lbl_80542ED8);
            *(s32*)(p + 0x240) = rnd;
        } while ((mask & 0x1e) != 0x1e && (mask & (1 << rnd)) != 0);
    } else {
        *(s32*)(p + 0x240) = mode;
    }
    fx = (f32)((s32)*(f32*)(p + 0xc) / 16 * 16 + 8);
    *(f32*)(p + 0x24) = fx;
    *(f32*)(p + 0xc) = fx;
    fy = (f32)((s32)*(f32*)(p + 0x10) / 16 * 16 + 8);
    *(f32*)(p + 0x28) = fy;
    *(f32*)(p + 0x10) = fy;
    *(Vec*)(p + 0x230) = *(Vec*)(p + 0xc);
    *(f32*)(p + 0x238) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x60) = lbl_80542F14;
    *(f32*)(p + 0x64) = lbl_80542F14;
    *(f32*)(p + 0x68) = lbl_80542F18;
    *(f32*)(p + 0x6c) = lbl_80542F18;
    *(f32*)(p + 0x80) = lbl_80542F14;
    *(f32*)(p + 0x84) = lbl_80542F14;
    *(f32*)(p + 0x88) = lbl_80542F18;
    *(f32*)(p + 0x8c) = lbl_80542F18;
    *(s32*)(p + 0x1a4) = 1;
    *(s32*)(p + 0xb8) = 2;
    *(s32*)(p + 0x244) = 0;
    *(u8*)(p + 0x248) = (*(u32*)(p + 0x90) >> 5) & 1;
    if (*(u8*)(p + 0x248) == 0 && fn_8028D4DC(p + 0xc, 0, *(s32*)(p + 0x16c)) != 0) {
        *(s32*)(p + 0x244) = 1;
        (*(void (**)(void*, s32, s32))(*(u32*)p + 0x30))(p, 0xff, 1);
    }
    *(s32*)(p + 0x240) = 0;
    if (((*(u32*)(p + 0x90) >> 8) & 0xf) != 0) {
        *(s32*)(p + 0x244) = 1;
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
extern "C" void fn_8037574C(void) {
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

