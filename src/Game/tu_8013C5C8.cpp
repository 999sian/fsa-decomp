// tu_8013C5C8: .text 0x8013C5C8-0x8013F9A8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern void* lbl_8053AAF8;
extern "C" void* fn_8023E724(u32 id);
extern "C" void* fn_8023DE58(u32 id);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void*, u32, void*, void*, u32, s32, s32);

// ---- from Game/dtor_8013C5C8.cpp

extern "C" void fn_800EB208(void* this_, s32 flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F140[];

extern "C" void* dtor_8013C5C8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F140;
        fn_800EB208(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8013C628(u8* this_, u8* actor) {
    if ((*(u32*)(actor + 0xf4) & 1) == 0) {
        u8* g = (u8*)lbl_8053AAF8;
        u8 hit = 0;
        if (g[0x7f] != 0) {
            if (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb) {
                hit = 1;
            }
        } else {
            if (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb || *(s32*)(g + 0x4c) == 0xc) {
                hit = 1;
            }
        }
        if (hit && *(s32*)(g + 0x4c) != 0xc && g[0x94] == 0) {
            *(s32*)(this_ + 0xc) += 1;
            s32 state = *(s32*)(this_ + 0x8);
            if (state == 1) {
                if (*(s32*)(this_ + 0xc) >= 8) {
                    *(s32*)(this_ + 0xc) = 0;
                    u32 id = *(u32*)(this_ + 0x4);
                    void* a = fn_8023E724(id);
                    void* b = fn_8023DE58(*(u32*)(this_ + 0x4));
                    void* m = fn_801F856C();
                    Actor_CreateByID(m, 0x50454646, b, a, id & 3, -1, id);
                }
            } else if (state >= 0 && state < 1) {
                if (*(s32*)(this_ + 0xc) >= 8) {
                    *(s32*)(this_ + 0xc) = 0;
                    u32 id = *(u32*)(this_ + 0x4);
                    void* a = fn_8023E724(id);
                    void* b = fn_8023DE58(*(u32*)(this_ + 0x4));
                    void* m = fn_801F856C();
                    Actor_CreateByID(m, 0x50454646, b, a, (id & 3) | 0x30, -1, id);
                }
            }
        }
    }
}

// ---- from Game/fn_8013C86C_dtor.cpp

extern "C" void fn_800EB208(void* this_, s32 flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F15C[];

extern "C" void* fn_8013C86C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F15C;
        fn_800EB208(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8013D5B0.cpp

// fn_8013D5B0(this) - the first method of the this->0x28 sub-object's own
// class (forward-referenced from fn_8013B4C0/fn_8013B71C/etc in the
// camera-cue-manager cluster; this class's own dtor is dtor_8013C5C8,
// already landed). Thin forwarder: fn_800EC188(this->0xc).
extern "C" s32 fn_800EC188(void* subObj);

extern "C" s32 fn_8013D5B0(void* this_) {
    return fn_800EC188(*(void**)((char*)this_ + 0xc));
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

extern u8* lbl_8053AB10;
extern "C" u8 fn_80134CC8(void*);
extern "C" void fn_8013B438(void*);
extern "C" void fn_8013B490(void*);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" void C_MTXLightOrtho(f32 (*m)[4], f32 t, f32 b, f32 l, f32 r, f32 sS, f32 sT, f32 tS, f32 tT);
extern "C" void draw__17JPAEmitterManagerFPC11JPADrawInfoUc(void*, const void*, u8);
extern "C" void capture__10JUTTextureFii9_GXTexFmtbUc(void*, s32, s32, u8, u8, u8);
extern "C" void GXSetAlphaUpdate(u8);
extern "C" u8* sManager__8JUTVideo;
extern "C" void fn_8013C958(void*);
extern "C" void calc__17JPAEmitterManagerFUc(void*, u8);
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void*);
extern void* lbl_8053AAF8;
extern "C" void clearResourceManager__17JPAEmitterManagerFUc(void*, u8);
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void __dt__18JPAEmitterCallBackFv(void*, s32);
extern "C" void PSMTXCopy(const void*, void*);
extern void* lbl_8049F178[];
extern void* lbl_8049F184[];

extern "C" void* fn_8013C824(void) {
    return *(void**)(lbl_8053AB10 + 0x28);
}

struct RGB3 { u8 r, g, b; };
inline void setRGB(u8* d, u8 r, u8 g, u8 b) { d[0xb8] = r; d[0xb9] = g; d[0xba] = b; }
extern "C" void fn_8013C830(u8* this_, s32 idx, u8* dst) {
    if (dst == 0) return;
    if (idx < 0) return;
    if (idx >= 4) return;
    setRGB(dst, this_[idx * 3 + 0x4110], this_[idx * 3 + 0x4111], this_[idx * 3 + 0x4112]);
}

extern "C" void fn_8013DC1C(void* this_) {
    calc__17JPAEmitterManagerFUc(*(void**)((char*)this_ + 0xc), 10);
}

extern "C" void fn_8013DC44(u8* this_) {
    bool bVar2 = false;
    u8 flag = 0;
    if (*((u8*)lbl_8053AAF8 + 0x7f) != 0) {
        s32 t = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
        if (t == 7 || t == 8 || t == 9 || t == 0x16 || t == 0xa || t == 0xb) flag = 1;
    } else {
        s32 t = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
        if (t == 7 || t == 8 || t == 9 || t == 0x16 || t == 0xa || t == 0xb || t == 0xc) flag = 1;
    }
    if (!flag || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xc) {
        bVar2 = true;
    } else if (fn_802DCD0C(fn_802D6A9C()) == 0) {
        bVar2 = true;
    }
    if (bVar2) {
        if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 0xb) {
            calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 0);
            calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 1);
            calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 2);
            calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 4);
            calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 5);
            calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 6);
        }
        calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 7);
        calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 8);
    }
    calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 3);
    calc__17JPAEmitterManagerFUc(*(void**)(this_ + 0xc), 9);
}

extern "C" void* fn_8013F378(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F178;
        clearResourceManager__17JPAEmitterManagerFUc(*(void**)((char*)this_ + 0xc), 0);
        destroy__7JKRHeapFv(*(void**)((char*)this_ + 0x4));
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* create__12JKRSolidHeapFUlP7JKRHeapb(u32, void*, s32);
extern "C" void* __nw__FUlP7JKRHeapi(u32, void*, s32);
extern "C" void* __ct__18JPAResourceManagerFPCvP7JKRHeap(void*, const void*, void*);
extern "C" void* __ct__17JPAEmitterManagerFUlUlP7JKRHeapUcUc(void*, u32, u32, void*, u8, u8);
extern "C" void entryResourceManager__17JPAEmitterManagerFP18JPAResourceManagerUc(void*, void*, u8);
extern "C" void* swapTexture__18JPAResourceManagerFPC7ResTIMGPCc(void*, const void*, const char*);
extern "C" s32 adjustSize__12JKRSolidHeapFv(void*);
extern "C" void __construct_array(void*, void*, void*, u32, u32);
extern "C" void OSReport(const char*, ...);
extern char lbl_80465980[];
extern "C" void fn_8013F584(void);
extern "C" void* fn_8013F3E4(u8* this_, void* heap) {
    char* base = lbl_80465980;
    *(void**)this_ = lbl_8049F178;
    __construct_array(this_ + 0x10, (void*)fn_8013F584, 0, 0x10, 0x400);
    *(void**)(this_ + 0x4) = create__12JKRSolidHeapFUlP7JKRHeapb(-1, heap, 0);
    void* res = __nw__FUlP7JKRHeapi(0x14, *(void**)(this_ + 0x4), 0);
    if (res != 0) {
        void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        void* tex = (*(void* (**)(void*, u32, const char*))(**(u8***)((u8*)lbl_8053AAF8 + 0xa4) + 0x18))(obj, 0x3f3f3f3f, base + 0xb8);
        res = __ct__18JPAResourceManagerFPCvP7JKRHeap(res, tex, *(void**)(this_ + 0x4));
    }
    *(void**)(this_ + 0x8) = res;
    OSReport(base + 0xc8);
    void* em = __nw__FUlP7JKRHeapi(0x30, *(void**)(this_ + 0x4), 0);
    if (em != 0) {
        em = __ct__17JPAEmitterManagerFUlUlP7JKRHeapUcUc(em, 0x1c00, 0x200, *(void**)(this_ + 0x4), 0xb, 8);
    }
    *(void**)(this_ + 0xc) = em;
    entryResourceManager__17JPAEmitterManagerFP18JPAResourceManagerUc(*(void**)(this_ + 0xc), *(void**)(this_ + 0x8), 0);
    swapTexture__18JPAResourceManagerFPC7ResTIMGPCc(*(void**)(this_ + 0x8), *(void**)(*(u8**)(lbl_8053AB10 + 0x34) + 0x20), base + 0xe8);
    adjustSize__12JKRSolidHeapFv(*(void**)(this_ + 0x4));
    this_[0x4110] = 200;
    this_[0x4111] = 250;
    this_[0x4112] = 172;
    this_[0x4113] = 250;
    this_[0x4114] = 174;
    this_[0x4115] = 172;
    this_[0x4116] = 180;
    this_[0x4117] = 210;
    this_[0x4118] = 230;
    this_[0x4119] = 240;
    this_[0x411a] = 180;
    this_[0x411b] = 240;
    return this_;
}

extern "C" void fn_8013F584(void) {}

extern "C" void fn_8013F588(void) {
    fn_8013C958(*(void**)(lbl_8053AB10 + 0x28));
}

extern "C" void PSMTXScale(f32 (*m)[4], f32 x, f32 y, f32 z);
extern "C" void PSMTXTrans(f32 (*m)[4], f32 x, f32 y, f32 z);
extern "C" void PSMTXConcat(const f32 (*a)[4], const f32 (*b)[4], f32 (*ab)[4]);
extern "C" void fn_8013F5B0(void* this_, u8* p) {
    f32 a[3][4];
    f32 s[3][4];
    u8* obj = (u8*)*(void**)((u8*)*(void**)((u8*)*(void**)(lbl_8053AB10 + 0x28) + 0xc) + 0x20);
    PSMTXCopy(obj + 0x184, a);
    PSMTXScale(s, 1.0f, 1.0f, 1.0f);
    PSMTXConcat(a, s, a);
    PSMTXTrans(s, 0.0f, *(f32*)(p + 0xa8), *(f32*)(p + 0xac));
    PSMTXConcat(a, s, a);
    PSMTXCopy(a, obj + 0x184);
}

extern "C" void fn_8013F6BC(void) {
    PSMTXCopy((u8*)*(void**)(lbl_8053AB10 + 0x24) + 0xe4, (u8*)*(void**)((u8*)*(void**)((u8*)*(void**)(lbl_8053AB10 + 0x28) + 0xc) + 0x20) + 0x184);
}

extern "C" void* fn_8013F6F8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F184;
        __dt__18JPAEmitterCallBackFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" char lbl_804BEC38[];
extern "C" char __vt__18JPAEmitterCallBack[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
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
extern "C" void* lbl_8053AB18;
extern "C" void* lbl_8049F184[];
extern "C" void fn_8013F758(void) {
    lbl_8053AB18 = __vt__18JPAEmitterCallBack;
    lbl_8053AB18 = lbl_8049F184;
    __register_global_object(&lbl_8053AB18, (void*)fn_8013F6F8, lbl_804BEC38);
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, lbl_804BEC38 + 0x18);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, lbl_804BEC38 + 0x24);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, lbl_804BEC38 + 0x30);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, lbl_804BEC38 + 0x3c);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, lbl_804BEC38 + 0x48);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, lbl_804BEC38 + 0x54);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, lbl_804BEC38 + 0x60);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, lbl_804BEC38 + 0x6c);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, lbl_804BEC38 + 0x78);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

extern "C" void deleteAllParticle__14JPABaseEmitterFv(void*);

struct PtclMgr_ { u8 pad[0x4010]; void* emitters[0x19]; u16 ids[0x4c]; s32 count; };
inline bool isKeep(u16 id) { return id == 0x349 || id == 0x34a || id == 0x34b; }
extern "C" void fn_8013C8CC(PtclMgr_* this_) {
    for (int i = 0; i < this_->count; i++) {
        if (this_->ids[i] == 0x349 || this_->ids[i] == 0x34a || this_->ids[i] == 0x34b) deleteAllParticle__14JPABaseEmitterFv(this_->emitters[i]);
    }
}

struct Vec3_ { f32 x, y, z; };inline f32 addPI(f32 a) { return a + 3.1415927f; }static const f32 kPI = 3.1415927f;
extern "C" void fn_8010F668(f32 (*m)[4], Vec3_* axis, f32 rad);
extern "C" void JPASetRMtxfromMtx__FPA4_CfPA4_f(f32 (*src)[4], void* dst);

extern "C" u8 fn_8013CAA4(u8* this_, f32 angle) {
    int ret = 0;
    if (this_ != 0) {
    f32 m[3][4];
    Vec3_ axis;
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 1.0f;
    fn_8010F668(m, &axis, kPI + angle);
    m[0][0] *= -1.0f;
    m[0][1] *= -1.0f;
    m[0][2] *= -1.0f;
    JPASetRMtxfromMtx__FPA4_CfPA4_f(m, this_ + 0x68);
    ret = 1;
    }
    return ret;
}

extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" void C_MTXLightOrtho(f32 (*m)[4], f32 t, f32 b, f32 l, f32 r, f32 sS, f32 sT, f32 tS, f32 tT);
extern "C" void draw__17JPAEmitterManagerFPC11JPADrawInfoUc(void*, const void*, u8);
extern "C" u8 fn_80134CC8(void*);
extern "C" void fn_8013B490(void*);
extern void* lbl_8053AAF8;
struct RenderMode_ { u32 tvMode; u16 fbWidth; u16 efbHeight; };
class JUTVideo {
public:
    static JUTVideo* sManager;
    u32 _0;
    RenderMode_* mRenderMode;
    s32 getFbWidth() const { return mRenderMode->fbWidth; }
    s32 getEfbHeight() const { return mRenderMode->efbHeight; }
};
struct DrawInfo_ {
    DrawInfo_() {
        PSMTXIdentity(mCamMtx);
        PSMTXIdentity(mPrjMtx);
    }
    void setOrtho(f32 t, f32 b, f32 l, f32 r) { C_MTXLightOrtho(mPrjMtx, t, b, l, r, 0.5f, 0.5f, 0.5f, 0.5f); }
    f32 mCamMtx[3][4];
    f32 mPrjMtx[3][4];
};

extern "C" void fn_8013DB2C(u8* this_) {
    if (fn_80134CC8(lbl_8053AAF8)) {
        return;
    }
    DrawInfo_ info;
    fn_8013B490(lbl_8053AB10);
    DrawInfo_ info2;
    PSMTXCopy((u8*)*(void**)(lbl_8053AB10 + 0x10) + 0x80, info.mCamMtx);
    info.setOrtho(0.0f, JUTVideo::sManager->getEfbHeight(), 0.0f, JUTVideo::sManager->getFbWidth());
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &info, 4);
}

struct MtxS_ { f32 m[3][4]; };
struct DrawInfoPOD_ { MtxS_ cam; MtxS_ prj; };
extern "C" void fn_8013B438(void*);

extern "C" void fn_8013D908(u8* this_) {
    DrawInfoPOD_ info;
    DrawInfoPOD_* src = (DrawInfoPOD_*)((u8*)*(void**)(lbl_8053AB10 + 0x24) + 0xe4);
    info.cam = src->cam;
    info.prj = src->prj;
    fn_8013B438(lbl_8053AB10);
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &info, 7);
}

extern "C" void fn_8013DA10(u8* this_) {
    DrawInfoPOD_ info;
    DrawInfoPOD_* src;
    if (fn_80134CC8(lbl_8053AAF8) == 0) {
        src = (DrawInfoPOD_*)((u8*)*(void**)(lbl_8053AB10 + 0x24) + 0xe4);
        info.cam = src->cam;
        info.prj = src->prj;
        fn_8013B438(lbl_8053AB10);
        GXSetAlphaUpdate(0);
        draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &info, 9);
    }
}

extern "C" f32 fn_802F5E9C(void*, const f32*);

extern "C" u8 fn_8013CB44(u8* this_, f32* pos, s32 a, s32 b, u8 flag) {
    s32 ret = 0;
    if (this_ != 0) {
        if (flag) {
            flag = pos[2] > 0.0f;
        }
        if (flag && a < 1) {
            a++;
            b--;
        }
        f32 off = (a << 10) + (b << 7);
        f32 x = pos[0];
        f32 y = pos[1] + off;
        f32 z = pos[2] + off;
        f32 g = fn_802F5E9C(*(void**)(lbl_8053AB10 + 0x20), pos);
        f32 d = g - pos[2];
        *(f32*)(this_ + 0xa4) = x;
        *(f32*)(this_ + 0xa8) = y;
        z += d;
        *(f32*)(this_ + 0xac) = z;
        ret = 1;
    }
    return ret;
}
