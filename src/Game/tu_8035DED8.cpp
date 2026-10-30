#include "Game/Actor.h"
#include "Game/ItemBase.h"


struct Unk8035DA78;
typedef void (Unk8035DA78::*Unk8035DA78Func)();
extern Unk8035DA78Func lbl_804AD6A8[];
struct Unk8035E60CTable { Unk8035DA78Func f[6]; };
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, int id);
extern "C" void fn_8035C1C4(void* self, int a, int b);
extern "C" char lbl_804AD6F0[];
extern "C" char lbl_804A5958[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8 fn_8035C15C(void* self, int a);
extern const f32 lbl_80542988;
extern float lbl_8054298C;
extern "C" Actor* fn_8035DED8(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AD6F0;
        if (p != 0) {
            *(void**)p = lbl_804A5958;
            __dt__5ActorFv(p, 0);
        }
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8035DF48(Actor* a) {
    char* p = (char*)a;
    if (*(f32*)(p + 0x10) < lbl_80542988) {
        if (fn_8035C15C(p, 6) == 1) {
            fn_8035C1C4(p, 6, 0x9b);
        }
        *(f32*)(p + 0x10) += lbl_8054298C;
    } else {
        char* found = (char*)fn_801F666C(fn_801F856C(), *(int*)(p + 0x23c));
        if (found != 0) {
            *(int*)(found + 0x230) = 7;
            *(int*)(found + 0x234) = 0;
        }
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" void fn_8035DFE4(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x234) == 0) {
        if (*(int*)(p + 0x238) == 0) {
            char* found = (char*)fn_801F666C(fn_801F856C(), *(int*)(p + 0x23c));
            if (found != 0) {
                *(int*)(found + 0x234) = 1;
            }
        } else {
            fn_8035C1C4(p, 6, 0x9b);
            *(int*)(p + 0x230) += 1;
        }
    } else if (*(int*)(p + 0x234) < 0xf0) {
        *(int*)(p + 0x248) = 0x18;
    }
}

extern f32 lbl_80542990;
extern f32 lbl_80542994;
extern f32 lbl_80542998;
extern f32 lbl_8054299C;
extern "C" void fn_8035E070(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x234) != 0) {
        if (*(int*)(p + 0x234) == 1 && *(int*)(p + 0x238) == 0) {
            fn_8035C1C4(p, 5, 0x9b);
        }
    } else {
        if (*(int*)(p + 0x238) == 0) {
            if (fn_8035C15C(p, 5) == 1) {
                fn_8035C1C4(p, 5, 0x9b);
            }
            if (*(f32*)(p + 0xc) >= lbl_80542990) {
                *(f32*)(p + 0xc) -= lbl_80542994;
            } else {
                *(f32*)(p + 0xc) = lbl_80542990;
                fn_8035C1C4(p, 6, 0x9b);
                *(int*)(p + 0x238) += 1;
                *(int*)(p + 0x234) = 0x10;
            }
        } else if (*(int*)(p + 0x238) == 1) {
            if (fn_8035C15C(p, 6) == 1) {
                fn_8035C1C4(p, 6, 0x9b);
            }
            if (*(f32*)(p + 0x10) < lbl_80542998) {
                *(f32*)(p + 0x10) += lbl_80542994;
            } else {
                *(f32*)(p + 0x10) = lbl_80542998;
                fn_8035C1C4(p, 4, 0x9b);
                *(int*)(p + 0x238) += 1;
                *(int*)(p + 0x234) = 0x10;
            }
        } else {
            if (fn_8035C15C(p, 4) == 1) {
                fn_8035C1C4(p, 4, 0x9b);
            }
            if (*(f32*)(p + 0xc) < lbl_8054299C) {
                *(f32*)(p + 0xc) += lbl_80542994;
            } else {
                *(f32*)(p + 0x10) = lbl_80542998;
                fn_8035C1C4(p, 4, 0x9b);
                *(int*)(p + 0x238) = 0;
                *(int*)(p + 0x230) += 1;
                *(int*)(p + 0x234) = 0x16f;
            }
        }
    }
}

extern "C" void fn_8035E238(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x244) == 0) {
        *(int*)(p + 0x248) = 0;
    }
    if (*(int*)(p + 0x238) == 0) return;
    *(int*)(p + 0x230) = 3;
    *(int*)(p + 0x234) = 100;
    *(int*)(p + 0x238) = 0;
}

extern "C" void fn_8035E274(int param_1) {
    char* p = (char*)param_1;
    int iVar1 = *(int*)(p + 0x238);
    if (iVar1 == 0) {
        if (fn_8035C15C(p, 0) == 1) {
            fn_8035C1C4(p, 1, 0x21b);
            *(int*)(p + 0x240) = 0;
            *(int*)(p + 0x238) = 4;
        }
    } else if (iVar1 == 4) {
        if (fn_8035C15C(p, 1) == 1) {
            fn_8035C1C4(p, 1, 0x21b);
        }
    } else if (iVar1 == 1) {
        fn_8035C1C4(p, 3, 0x274);
        *(int*)(p + 0x240) = 1;
        *(int*)(p + 0x238) = 2;
    } else if (iVar1 == 2) {
        if (fn_8035C15C(p, 2) == 1) {
            fn_8035C1C4(p, 2, 0x274);
        }
    } else if (iVar1 == 3) {
        *(int*)(p + 0x248) = 3;
        *(int*)(p + 0x244) = 0x45;
        *(int*)(p + 0x24c) = 0;
        *(int*)(p + 0x230) = 2;
        *(int*)(p + 0x238) = 0;
    }
}

extern "C" void fn_8035E394(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x238) != 0) {
        *(int*)(p + 0x230) = 1;
        fn_8035C1C4(p, 0, 0x274);
        *(int*)(p + 0x238) = 0;
    }
}

extern "C" char lbl_804727F8[];
extern "C" char lbl_8047280C[];
extern f32 lbl_805429A0;
extern "C" void fn_801F06F0(void* this_, void* name, s32 id, DrawRec* rec, s32 n, f32 a, f32 b);
extern "C" void fn_8035E3E4(u8* p) {
    DrawRec rec;
    if (*(s32*)(p + 0x230) < 3 || (*(s32*)(p + 0x230) == 3 && *(s32*)(p + 0x238) == 0)) {
        *(s8*)&rec.b1d = -1;
    } else {
        rec.b1d = 0;
    }
    if (*(s32*)(p + 0x240) == 0) {
        fn_801F06F0(p, lbl_804727F8, *(s32*)(p + 0x250) + *(s32*)(p + 0x248), &rec, 7, lbl_805429A0, lbl_805429A0);
    } else {
        fn_801F06F0(p, lbl_8047280C, *(s32*)(p + 0x250) + *(s32*)(p + 0x248), &rec, 7, lbl_805429A0, lbl_805429A0);
    }
}

extern "C" void fn_8035E57C(Unk8035DA78* self) {
    char* p = (char*)self;
    if (*(int*)(p + 0x234) != 0) *(int*)(p + 0x234) -= 1;
    if (*(int*)(p + 0x244) != 0) *(int*)(p + 0x244) -= 1;
    (self->*lbl_804AD6A8[*(int*)(p + 0x230)])();
}

extern "C" void fn_8035E5DC(int param_1) {
    char* p = (char*)param_1;
    *(int*)(p + 0x230) = 0;
    *(int*)(p + 0x234) = 0;
    *(int*)(p + 0x238) = 0;
    *(int*)(p + 0x240) = 1;
    *(int*)(p + 0x244) = 0;
    *(int*)(p + 0x248) = 0;
    *(int*)(p + 0x24c) = 0;
    *(int*)(p + 0x250) = 0x274;
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
extern Unk8035E60CTable lbl_804AD660[];
extern "C" void fn_8035E60C(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    lbl_804AD660[1].f[0] = lbl_804AD660[0].f[0];
    for (int i = 1; i < 6; ++i) {
        lbl_804AD6A8[i] = lbl_804AD660[0].f[i];
    }
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

