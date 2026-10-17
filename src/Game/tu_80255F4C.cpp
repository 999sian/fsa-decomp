#include "Game/Actor.h"

struct ShapeArg {
    u8 idx[16];
    s32 unk10;
    s32 unk14;
    f32* mtx;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    s32 unk28;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    s32 unk30;
    s32 unk34;
    s32 unk38;
};

extern "C" u8 sincosTable___5JMath[];
extern "C" f32 lbl_805400A0;
extern "C" f32 lbl_805400A4;
extern "C" u32 lbl_804A6F48[];
extern "C" char* lbl_8053AAF8;
extern "C" char* lbl_8053AB10;
extern "C" void* fn_802F745C(void* a, void* b, void* c, void* d);

namespace JMath {
template <int N, typename T>
struct TAtanTable {
    T atan2(T y, T x) const;
};
extern const TAtanTable<1024, f32> atanTable_;
}


extern "C" char lbl_804A6F6C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80255F4C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A6F6C;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80255FAC(Actor* param_1) {
    char* p = (char*)param_1;
    ShapeArg arg;
    f32 mtx[3][4];
    u8* tbl = sincosTable___5JMath;
    f32 s0, c0, sa, ca, k;
    s32 i;
    u32 off;

    for (i = 0; (u8)i < 16; i += 8) {
        arg.idx[(u8)i] = i;
        arg.idx[(u8)(i + 1)] = i + 1;
        arg.idx[(u8)(i + 2)] = i + 2;
        arg.idx[(u8)(i + 3)] = i + 3;
        arg.idx[(u8)(i + 4)] = i + 4;
        arg.idx[(u8)(i + 5)] = i + 5;
        arg.idx[(u8)(i + 6)] = i + 6;
        arg.idx[(u8)(i + 7)] = i + 7;
    }
    arg.unk10 = -1;
    arg.unk14 = 0;
    arg.mtx = 0;
    arg.unk1c = 0;
    arg.unk1d = 0;
    arg.unk1e = 0;
    arg.unk1f = 1;
    arg.unk20 = 1;
    arg.unk21 = 0;
    arg.unk22 = 0;
    arg.unk23 = 0;
    arg.unk24 = 0;
    arg.unk25 = 0;
    arg.unk26 = 1;
    arg.unk28 = 3;
    arg.unk2c = 1;
    arg.unk2d = 0;
    arg.unk2e = 0;
    arg.unk30 = -1;
    arg.unk34 = 0;
    arg.unk38 = 2;

    s0 = *(f32*)(tbl + 0);
    c0 = *(f32*)(tbl + 4);
    k = lbl_805400A4;
    mtx[0][3] = lbl_805400A0;
    mtx[1][3] = lbl_805400A0;
    mtx[2][3] = lbl_805400A0;
    off = ((u32)*(s16*)(p + 0x238) >> 2) & 0x3ff8;
    sa = *(f32*)(tbl + off);
    ca = *(f32*)(tbl + off + 4);
    arg.mtx = &mtx[0][0];

    mtx[0][0] = k * (ca * c0);
    mtx[0][1] = k * ((s0 * sa) * c0 - c0 * s0);
    mtx[0][2] = k * ((c0 * c0) * sa + s0 * s0);
    mtx[1][0] = k * (ca * s0);
    mtx[1][1] = k * ((s0 * sa) * s0 + c0 * c0);
    mtx[1][2] = k * ((c0 * s0) * sa - c0 * s0);
    mtx[2][0] = k * -sa;
    mtx[2][1] = k * (ca * s0);
    mtx[2][2] = k * (ca * c0);

    arg.unk1d = -2;
    arg.unk21 = 1;

    if (*(s32*)(p + 0x4) < 8) {
        char* mgr = *(char**)(lbl_8053AAF8 + 0xa4);
        void* tex = (*(void* (**)(void*, u32, u32))(*(u32*)mgr + 0x18))(mgr, 0x54494d47, lbl_804A6F48[*(u32*)(p + 0x90) & 0x7f]);
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, tex, &arg);
    }
}

extern "C" u8 sincosTable___5JMath[];
extern "C" f32 lbl_805400AC;
extern "C" f32 lbl_805400B4;
extern "C" void fn_80256410(Actor* param_1)
{
    u8* p = (u8*)param_1;
    s32 w;
    f32 k;

    if (*(u32*)(p + 0x234) != 0) {
        *(u32*)(p + 0x234) = *(u32*)(p + 0x234) - 1;
        return;
    }
    w = *(s32*)(p + 0x90);
    if ((w & 0x7f) == 6 || (w & 0x7f) == 7) {
        if (*(u32*)(p + 0x230) < (((u32)w >> 12) & 0x3e0)) {
            *(u32*)(p + 0x230) = *(u32*)(p + 0x230) + 1;
        } else {
            *(u32*)(p + 0x234) = 0x3c;
            *(u32*)(p + 0x230) = 0;
            switch (*(s32*)(p + 0x98)) {
            case 0:
                *(s32*)(p + 0x98) = 1;
                break;
            case 1:
                *(s32*)(p + 0x98) = 0;
                break;
            case 2:
                *(s32*)(p + 0x98) = 3;
                break;
            case 3:
                *(s32*)(p + 0x98) = 2;
                break;
            }
        }
    }
    if ((*(s32*)(p + 0x90) & 0x7f) < 6) {
        *(s16*)(p + 0x238) = *(s16*)(p + 0x238) + 0x40;
    }
    if ((*(s32*)(p + 0x90) & 0x7f) == 6) {
        if (*(s32*)(p + 0x98) == 0) {
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + lbl_805400AC;
        } else {
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) - lbl_805400AC;
        }
    }
    if ((*(s32*)(p + 0x90) & 0x7f) == 7) {
        if (*(s32*)(p + 0x98) == 2) {
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_805400AC;
        } else {
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - lbl_805400AC;
        }
    }
    if ((*(s32*)(p + 0x90) & 0x7f) == 8) {
        k = lbl_805400B4;
        *(s16*)(p + 0x23a) = *(s16*)(p + 0x23a) + 0x40;
        *(f32*)(p + 0xc) = k * *(f32*)(sincosTable___5JMath + ((u32)*(s16*)(p + 0x23a) >> 2 & 0x3ff8) + 4) + *(f32*)(p + 0x24);
        *(f32*)(p + 0x10) = k * *(f32*)(sincosTable___5JMath + ((u32)*(s16*)(p + 0x23a) >> 2 & 0x3ff8)) + *(f32*)(p + 0x28);
    }
}

extern char* lbl_8053AAF8;
extern u32 lbl_804A6F48[];
extern f32 lbl_805400B4;
extern "C" void fn_80256888(Actor* param_1) {
    char* p = (char*)param_1;
    if (((*(u32*)(p + 0x90) >> 17) & 0x1f) == 0) {
        *(u32*)(p + 0x90) = *(u32*)(p + 0x90) | 0x20000;
    }
    char* mgr = *(char**)(lbl_8053AAF8 + 0xa4);
    *(void**)(p + 0x23c) = (*(void* (**)(void*, u32, u32))(*(u32*)mgr + 0x18))(mgr, 0x3f3f3f3f, lbl_804A6F48[*(u32*)(p + 0x90) & 0x7f]);
    u16 a = *(u16*)(*(char**)(p + 0x23c) + 0x2);
    u16 b = *(u16*)(*(char**)(p + 0x23c) + 0x4);
    *(f32*)(p + 0x60) = (f32)(-(s32)a / 2);
    *(f32*)(p + 0x64) = (f32)(-(s32)b / 2);
    *(f32*)(p + 0x68) = (f32)((u32)a >> 1);
    *(f32*)(p + 0x6c) = (f32)((u32)b >> 1);
    *(u32*)(p + 0x108) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u16*)(p + 0x238) = 0;
    *(u16*)(p + 0x23a) = 0;
    if ((*(u32*)(p + 0x90) & 0x7f) == 8) {
        s32 off = ((u32)*(s16*)(p + 0x23a) >> 2) & 0x3ff8;
        *(f32*)(p + 0xc) = lbl_805400B4 * *(f32*)((char*)sincosTable___5JMath + off + 4) + *(f32*)(p + 0x24);
        *(f32*)(p + 0x10) = lbl_805400B4 * *(f32*)((char*)sincosTable___5JMath + off) + *(f32*)(p + 0x28);
    }
    if ((*(u32*)(p + 0x90) & 0x7f) == 6 || (*(u32*)(p + 0x90) & 0x7f) == 7) {
        *(s32*)(p + 0x234) = 0x3c;
    } else {
        *(s32*)(p + 0x234) = 0;
    }
    if ((*(u32*)(p + 0x90) & 0x7f) == 7) {
        *(s32*)(p + 0x98) = 3;
    } else {
        *(s32*)(p + 0x98) = 0;
    }
}

extern "C" char lbl_804CF668[];
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
extern "C" void fn_80256A50(void)
{
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, lbl_804CF668 + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, lbl_804CF668 + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, lbl_804CF668 + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, lbl_804CF668 + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, lbl_804CF668 + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, lbl_804CF668 + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, lbl_804CF668 + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, lbl_804CF668 + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, lbl_804CF668 + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

