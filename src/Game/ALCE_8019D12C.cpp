#include "types.h"

extern f32 lbl_8053E440;
extern f32 lbl_8053E444;
extern f32 lbl_8053E448;
extern "C" void fn_80134DE4(void*, s32, s32);
extern "C" void fn_8022ADE4(void);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void* fn_8023E724(s32);
extern "C" void fn_802D79E8(void*, s32, s32, f32, f32);

extern u8 lbl_804C1E30[];
extern "C" void* fn_801F856C(void);
extern "C" void fn_801EE4F0(void*);
extern "C" void fn_8013CC50(u32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F4694(void*);
extern "C" void detach__5ActorFv(void*);
extern "C" void fn_801F8544(void*, u32, void*, void*, s32);
extern "C" void Actor_CreateByID(void*, u32, void*, void*, s32, s32, s32);

extern "C" void fn_801EE434(void*);
extern "C" void fn_8022ADCC(void);
extern "C" void fn_80134FC4(void*, s32);
extern "C" void fn_8037AE30(void*);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern char lbl_804A2AB0[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AD70;
extern u8 lbl_8053ABB0;
struct Quad {
    f32 v[4];
};
struct Words {
    u32 v[4];
};
struct VActor {
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(void);
    virtual void v06(void);
    virtual void v07(void);
    virtual void v08(void);
    virtual void v09(void);
    virtual void v10(void);
    virtual u8 v11(void);
};

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8019D958(char* p);
extern "C" void fn_8019D2AC(char* p);
extern "C" void fn_8019DC5C(char* p);
extern "C" void fn_801F0D20(char* p, s32 n);
extern void* lbl_8053AB10;
extern "C" void fn_8019D12C(char* this_) {
    s32 n = *(s32*)(this_ + 0x4);
    char* base = (char*)fn_802D6A9C();
    u32* src;
    if (n < 8) {
        src = (u32*)(base + 0xcc);
    } else {
        src = (u32*)(base + 0xdc);
    }
    u32 tmp[4];
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    tmp[3] = src[3];
    char* st = *(char**)((char*)lbl_8053AB10 + 0x24);
    if (*(u8*)(st + 0x7f5) == 0) {
        *(u8*)(st + 0x7f4) = 1;
        *(s32*)(st + 0x7f8) = 5;
        *(f32*)(st + 0x808) = *(f32*)&tmp[0];
        *(f32*)(st + 0x80c) = *(f32*)&tmp[1];
        *(f32*)(st + 0x810) = *(f32*)&tmp[2];
        *(f32*)(st + 0x814) = *(f32*)&tmp[3];
        *(u8*)(st + 0x7f6) = 0;
    }
    switch (*(s32*)(this_ + 0x238)) {
    case 0:
        if (*(s32*)(this_ + 0x230) == 0 && ((VActor*)this_)->v11()) {
            fn_801F0D20(this_, 0x42);
            fn_8019DC5C(this_);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    case 1:
        fn_8019D958(this_);
        break;
    case 2:
    case 3:
        fn_8019D2AC(this_);
        break;
    }
    if (*(s32*)(this_ + 0x23c) > 0) {
        *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) - 1;
    }
    if (*(s32*)(this_ + 0x240) > 0) {
        *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) - 1;
    }
    char* sub = this_ + 8;
    if (*(s32*)(this_ + 0x244) > 0) {
        *(s32*)(sub + 0x23c) = *(s32*)(this_ + 0x244) - 1;
    }
}

extern "C" void fn_8019D958(char* this_) {
    typedef void (*EffectFn)(s32, void*, f32, s32, s32, s32, s32, s32, s32);
    EffectFn effect = (EffectFn)fn_8013CC50;
    char* st = *(char**)((char*)lbl_8053AB10 + 0x24);
    f32 pos[3];
    pos[0] = -*(f32*)(st + 0x10);
    pos[1] = -*(f32*)(st + 0x20);
    pos[2] = lbl_8053E440;
    switch (*(s32*)(this_ + 0x230)) {
    case 1:
        fn_80134FC4(lbl_8053AAF8, 1);
        fn_8022ADE4();
        effect(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E444, 0x8e, 1, 7, 0, 0, 1);
        effect(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E444, 0x8f, 1, 7, 0, 0, 1);
        effect(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E444, 0x90, 1, 7, 0, 0, 1);
        effect(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E444, 0x421, 1, 7, 0, 0, 1);
        effect(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E444, 0x422, 1, 7, 0, 0, 1);
        effect(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E444, 0x423, 1, 7, 0, 0, 1);
        effect(*(s32*)(this_ + 4), pos, lbl_8053E444, 0x425, 1, 7, 0, 0, 1);
        fn_801F0E34(this_, 0x30001, 0);
        fn_80134DE4(lbl_8053AAF8, 3, 0);
        for (s32 i = 0; i < 4; i++) {
            if (fn_8023F264(i) && *(s32*)(this_ + 4) == fn_8023DE58(i)) {
                effect(*(s32*)(this_ + 4), fn_8023E724(i), lbl_8053E444, 0x424, 1, 4, 0, 0, 1);
            }
        }
        effect(*(s32*)(this_ + 4), pos, lbl_8053E444, 0x550, 1, 7, 0, 0, 1);
        *(s32*)(this_ + 0x230) = 2;
        break;
    case 2:
        fn_801F0E34(this_, 0x3005b, 0);
        ++*(s32*)(this_ + 0x24c);
        if (*(s32*)(this_ + 0x24c) == 0xbe) {
            fn_802D79E8(fn_802D6A9C(), *(s32*)(this_ + 4), 0, lbl_8053E448, lbl_8053E440);
            fn_801F0E34(this_, 0x3005c, 0);
            fn_8019DC5C(this_);
        } else {
            fn_801F0D20(this_, 0x4f);
            if (*(s32*)(this_ + 0x24c) >= 0x104) {
                *(u8*)(this_ + 0x11c) = 0;
                fn_80134FC4(lbl_8053AAF8, 0);
                fn_8022ADCC();
                fn_8037AE30(lbl_8053AD70);
                *(s32*)(this_ + 0x248) = 0;
                lbl_8053ABB0 = 0;
            }
        }
        break;
    }
}

extern "C" void fn_8019DC5C(char* this_) {
    s32 n;
    char* actor;
    s32 off;
    u32* pw;
    u8* pf;
    f32* pp;
    u8* flags;
    f32* pos;
    u32* words;
    s32 i;
    u8* base;
    s32 type;
    s32 id;

    base = lbl_804C1E30;
    n = *(s32*)((char*)fn_801F856C() + 0x1008);
    words = (u32*)(base + 0x3000);
    flags = base + 0x4000;
    pos = (f32*)base;
    pw = words;
    pf = flags;
    pp = pos;
    off = 0;
    for (i = 0; i < n; i++) {
        actor = *(char**)((char*)fn_801F856C() + off + 8);
        if (actor != 0 && *(s32*)(actor + 4) == *(s32*)(this_ + 4) && *(u8*)(actor + 0x1a8) == 1 && *(u8*)(actor + 0x196) == 0) {
            *pw = *(u32*)(actor + 0x16c);
            *pf = 1;
            pp[0] = *(f32*)(actor + 0xc);
            pp[1] = *(f32*)(actor + 0x10);
            pp[2] = *(f32*)(actor + 0x14);
            type = *(s32*)(this_ + 0x238);
            switch (type) {
            case 1:
                id = *(s32*)(actor + 4);
                fn_801EE4F0(actor);
                fn_8013CC50(id, actor + 0xc, lbl_8053E440, 0x35c, 1, 1, 0, 0, 1);
                *(u8*)(actor + 0x11c) = 0;
                break;
            case 0:
                id = *(s32*)(actor + 4);
                fn_801EE4F0(actor);
                fn_8013CC50(id, actor + 0xc, lbl_8053E440, 0x172, 1, 1, 0, 0, 1);
                id = *(s32*)(actor + 4);
                fn_801EE4F0(actor);
                fn_8013CC50(id, actor + 0xc, lbl_8053E440, 0x173, 1, 1, 0, 0, 1);
                fn_801F4694(actor);
                detach__5ActorFv(actor);
                break;
            case 2:
            case 3:
                *pw = 4;
                *(s32*)(this_ + 0x250) = *(s32*)(this_ + 0x250) + 1;
                *(s32*)(this_ + 0x254) = n;
                break;
            }
        }
        pw++;
        pf++;
        pp += 3;
        off += 4;
    }
    for (i = 0; i < n; i++) {
        if (*flags == 1) {
            type = *(s32*)(this_ + 0x238);
            if (type == 1) {
                Actor_CreateByID(fn_801F856C(), 0x5a41534c, *(void**)(this_ + 4), pos, 0, *words, -1);
            } else if (type < 1 && type >= 0) {
                fn_801F8544(fn_801F856C(), 0x52555059, *(void**)(this_ + 4), pos, 2);
            }
        }
        flags++;
        pos += 3;
        words++;
    }
}

extern "C" void* fn_8019DEB4(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2AB0;
        char* p = this_;
        int i = 0;
        do {
            fn_801EE434(*(void**)(p + 0x260));
            i++;
            p += 4;
        } while (i < 2);
        if (*(s32*)(this_ + 0x248) == 1) {
            fn_8022ADCC();
            *(s32*)(this_ + 0x248) = 0;
            fn_80134FC4(lbl_8053AAF8, 0);
            lbl_8053ABB0 = 0;
            fn_8037AE30(lbl_8053AD70);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern u8 lbl_804C1E30[];
extern f32 lbl_8053E440;
extern "C" void fn_8037AE00(void* p);
extern "C" void fn_8019DF7C(char* this_) {
    s32 i;
    f32 z = lbl_8053E440;
    u8* pb = lbl_804C1E30 + 0x4000;
    s32* pw = (s32*)(lbl_804C1E30 + 0x3000);
    f32* pf = (f32*)(lbl_804C1E30 + 0);

    for (i = 0; i < 0x80; i++) {
        pf[2] = z;
        pf[1] = z;
        pf[0] = z;
        pf[5] = z;
        pf[4] = z;
        pf[3] = z;
        pf[8] = z;
        pf[7] = z;
        pf[6] = z;
        pf[11] = z;
        pf[10] = z;
        pf[9] = z;
        pf[14] = z;
        pf[13] = z;
        pf[12] = z;
        pf[17] = z;
        pw[0] = -1;
        pb[0] = 0;
        pf[16] = z;
        pw[1] = -1;
        pb[1] = 0;
        pf[15] = z;
        pw[2] = -1;
        pb[2] = 0;
        pf[20] = z;
        pw[3] = -1;
        pb[3] = 0;
        pf[19] = z;
        pw[4] = -1;
        pb[4] = 0;
        pf[18] = z;
        pw[5] = -1;
        pb[5] = 0;
        pf[23] = z;
        pw[6] = -1;
        pb[6] = 0;
        pf[22] = z;
        pf[21] = z;
        pw[7] = -1;
        pb[7] = 0;
        pf += 24;
        pw += 8;
        pb += 8;
    }

    *(u32*)(this_ + 0x238) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;

    if (lbl_8053ABB0 == 1) {
        *(u8*)(this_ + 0x11c) = 0;
    } else {
        s32 st = *(s32*)(this_ + 0x238);
        if (st == 1) {
            fn_8037AE00(lbl_8053AD70);
            lbl_8053ABB0 = 1;
            *(s32*)(this_ + 0x248) = 1;
            *(s32*)(this_ + 0x230) = 1;
        } else if (st < 1) {
            if (st >= 0) {
                *(s32*)(this_ + 0x230) = 0;
            }
        } else if (st < 4) {
            fn_8037AE00(lbl_8053AD70);
            lbl_8053ABB0 = 1;
            *(s32*)(this_ + 0x248) = 1;
            *(s32*)(this_ + 0x230) = 3;
        }
    }
}

extern void __construct_array(void*, void*, void*, u32, u32);
extern void __register_global_object(void*, void*, void*);
extern void __ct__17JASGenericMemPoolFv(void*);
extern char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern void* memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern void* memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern void* memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern void* memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern void* memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern void* memPool___30JASPoolAllocObject_9JAIStream;
extern void __dt__22JASMemPool_9JAIStreamFv(void*);
extern char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern void* memPool___35JASPoolAllocObject_13JAISoundChild;
extern void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern void* memPool___27JASPoolAllocObject_6JAISeq;
extern void __dt__19JASMemPool_6JAISeqFv(void*);
extern char __init__memPool___26JASPoolAllocObject_5JAISe;
extern void* memPool___26JASPoolAllocObject_5JAISe;
extern void __dt__18JASMemPool_5JAISeFv(void*);
extern void __ct__Q29JGeometry8TVec3_f_Fv(void);
extern "C" void fn_8019E13C(void) {
    u8* base = lbl_804C1E30;
    __construct_array(base, (void*)__ct__Q29JGeometry8TVec3_f_Fv, NULL, 0xc, 0x400);
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x4400);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0x440c);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x4418);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x4424);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x4430);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x443c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x4448);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x4454);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x4460);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

