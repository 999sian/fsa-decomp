#include "JSystem/JGeometry/Vec.h"

class Actor;

extern const f32 lbl_80541F3C;
extern const f32 lbl_80541F40;
extern const f32 lbl_80541F44;
extern const f32 lbl_80541F48;
extern const f32 lbl_80541F4C;
extern char* lbl_8053AB10;
extern u8* lbl_8053AAF8;
extern char lbl_80471A90[];
extern char lbl_80471AA0[];

struct Tu80333958ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};


extern "C" char lbl_804AB968[];
extern "C" void fn_801F2B7C(void* this_, u32 a, u32 b, u32 c);
extern "C" void fn_801F0E34(void* this_, u32 a, u32 b);
extern "C" double __fabs(double x);
extern const f32 lbl_80541F50;
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80333958(Actor* p, s16 n)
{
  if (p) {
    *(void**)p = lbl_804AB968;
    __dt__5ActorFv(p, 0);
    if (n > 0) operator delete(p);
  }
  return p;
}

extern const f32 lbl_80541F38;
extern "C" u16 fn_8022461C(Vec* pos, s32 room);
extern "C" BOOL fn_803339B8(void* this_, s32 room, JGeometry::TVec3f* pos) {
    JGeometry::TVec3f v(*pos);
    switch (*(s32*)((char*)this_ + 0x240)) {
    case 0:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.y -= lbl_80541F38;
        } else {
            v.y -= lbl_80541F38;
        }
        break;
    case 1:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.y += lbl_80541F38;
        } else {
            v.y += lbl_80541F38;
        }
        break;
    case 2:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.x -= lbl_80541F38;
        } else {
            v.x -= lbl_80541F38;
        }
        break;
    case 3:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.x += lbl_80541F38;
        } else {
            v.x += lbl_80541F38;
        }
        break;
    }
    s32 kind = (u16)fn_8022461C(&v, room);
    switch (*(s32*)((char*)this_ + 0x240)) {
    case 0:
        if (kind == 0x41) {
            return 1;
        }
        break;
    case 1:
        if (kind == 0x40) {
            return 1;
        }
        break;
    case 2:
        if (kind == 0x43) {
            return 1;
        }
        break;
    case 3:
        if (kind == 0x42) {
            return 1;
        }
        break;
    }
    return 0;
}

extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, void* rec);
extern "C" s32 fn_80307AC8(u32 caller, s32 room, void* pos, s32 id, s32 on, s32 b, s32 target);
extern "C" void fn_80333B64(void* this_) {
    char* p = (char*)this_;
    u8 rec[0x3c];

    *(s32*)(rec + 0x10) = -1;
    *(s32*)(rec + 0x14) = -1;
    for (u32 i = 0; (u8)i < 0x10; i += 8) {
        rec[(u8)(i + 0)] = (u8)(i + 0);
        rec[(u8)(i + 1)] = (u8)(i + 1);
        rec[(u8)(i + 2)] = (u8)(i + 2);
        rec[(u8)(i + 3)] = (u8)(i + 3);
        rec[(u8)(i + 4)] = (u8)(i + 4);
        rec[(u8)(i + 5)] = (u8)(i + 5);
        rec[(u8)(i + 6)] = (u8)(i + 6);
        rec[(u8)(i + 7)] = (u8)(i + 7);
    }
    rec[0x1d] = 0;
    *(s32*)(rec + 0x10) = -1;
    *(s32*)(rec + 0x14) = 0;
    *(s32*)(rec + 0x18) = 0;
    rec[0x1c] = 0;
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
    *(s8*)(rec + 0x1d) = -1;

    if (*(s32*)(p + 0x23c) == 0) {
        Vec pos;
        s32 iVar1;
        void* res;

        pos.y = lbl_80541F3C + *(f32*)(p + 0x10);
        pos.x = *(f32*)(p + 0xc);
        pos.z = lbl_80541F40;
        if (*(s32*)(p + 4) < 8) {
            res = ((Tu80333958ResMgr*)*(u8**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_80471A90);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, res, 0, lbl_80541F44, lbl_80541F44, rec);
        }
        iVar1 = *(s32*)(p + 0x238) + 0x25;
        if (*(s32*)(p + 4) < 8) {
            res = ((Tu80333958ResMgr*)*(u8**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_80471AA0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, res, iVar1, lbl_80541F44, lbl_80541F44, 0);
        }
        fn_80307AC8(*(u32*)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x238) + 0x25, 0, 0, -1);
    } else {
        Vec pos;
        s32 iVar1;
        void* res;

        pos.y = lbl_80541F48 + *(f32*)(p + 0x10);
        pos.x = *(f32*)(p + 0xc);
        pos.z = lbl_80541F40;
        if (*(s32*)(p + 4) < 8) {
            res = ((Tu80333958ResMgr*)*(u8**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_80471A90);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, res, 3, lbl_80541F4C, lbl_80541F44, rec);
        }
        iVar1 = *(s32*)(p + 0x238) + 0x27;
        if (*(s32*)(p + 4) < 8) {
            res = ((Tu80333958ResMgr*)*(u8**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_80471AA0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, res, iVar1, lbl_80541F44, lbl_80541F44, 0);
        }
        fn_80307AC8(*(u32*)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x238) + 0x27, 0, 0, -1);
    }
}

extern "C" void fn_80333E8C(void* this_) {
    char* p = (char*)this_;
    u8 r;
    fn_801F2B7C(this_, -0x64, -1, 1);
    r = ((u8 (*)(void*))((*(u32**)this_)[0x34 / 4]))(this_);
    if (r != 0) {
        return;
    }
    ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
    r = ((u8 (*)(void*, u32))((*(u32**)this_)[0x4c / 4]))(this_, *(u32*)(p + 4));
    if (r != 0 || *(s32*)(p + 0x244) > 0x258) {
        *(u8*)(p + 0x11c) = 0;
    }
    *(s32*)(p + 0x234) -= (s32)(lbl_80541F50 + ((f32)__fabs(*(f32*)(p + 0x40)) + (f32)__fabs(*(f32*)(p + 0x3c))));
    if (*(s32*)(p + 0x234) <= 15) {
        *(s32*)(p + 0x238) = 1;
        if (*(s32*)(p + 0x234) <= 0) {
            *(s32*)(p + 0x234) = 0x1e;
            *(s32*)(p + 0x238) = 0;
            fn_801F0E34(this_, 0x30010, 0);
        }
    }
    *(s32*)(p + 0x244) += 1;
}

extern const f32 lbl_80541F40;
extern const f32 lbl_80541F54;
extern const f32 lbl_80541F58;
extern const f32 lbl_80541F5C;
extern const f32 lbl_80541F60;
extern const f32 lbl_80541F64;
extern const f32 lbl_80541F68;
extern "C" void fn_801F0E34(void* this_, u32 a, u32 b);
extern "C" void fn_80333FC4(void* this_) {
    char* p = (char*)this_;
    s32 mode = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(s32*)(p + 0x240) = mode;
    *(s32*)(p + 0x108) = 0x80;
    if ((*(u32*)(p + 0x90) & 0xf) != 0) {
        *(s32*)(p + 0x23c) = 1;
        *(f32*)(p + 0x60) = lbl_80541F54;
        *(f32*)(p + 0x64) = lbl_80541F54;
        *(f32*)(p + 0x68) = lbl_80541F58;
        *(f32*)(p + 0x6c) = lbl_80541F58;
    } else {
        *(s32*)(p + 0x23c) = 0;
        *(f32*)(p + 0x60) = lbl_80541F5C;
        *(f32*)(p + 0x64) = lbl_80541F5C;
        *(f32*)(p + 0x68) = lbl_80541F60;
        *(f32*)(p + 0x6c) = lbl_80541F60;
    }
    switch (*(s32*)(p + 0x240)) {
    case 0:
        *(f32*)(p + 0x3c) = lbl_80541F40;
        *(f32*)(p + 0x40) = lbl_80541F64;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 1:
        *(f32*)(p + 0x3c) = lbl_80541F40;
        *(f32*)(p + 0x40) = lbl_80541F68;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 2:
        *(f32*)(p + 0x3c) = lbl_80541F64;
        *(f32*)(p + 0x40) = lbl_80541F40;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 3:
        *(f32*)(p + 0x3c) = lbl_80541F68;
        *(f32*)(p + 0x40) = lbl_80541F40;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    }
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x234) = 0x1e;
    *(s32*)(p + 0x244) = 0;
    fn_801F0E34(this_, 0x30019, 0);
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
extern "C" void fn_803340F4(void)
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

