// tu_8013C5C8: .text 0x8013C5C8-0x8013F9A8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern void* lbl_8053AAF8;
extern "C" void* fn_8023E724(u32 id);
extern "C" void* fn_8023DE58(u32 id);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void*, u32, void*, void*, u32, s32, s32);
extern "C" u8 fn_80134CC8(void*);
extern "C" void fn_8013B438(void*);
extern "C" void fn_8013B490(void*);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" void PSMTXCopy(const void*, void*);
extern "C" void C_MTXLightOrtho(f32 (*m)[4], f32 t, f32 b, f32 l, f32 r, f32 sS, f32 sT, f32 tS, f32 tT);
extern "C" void draw__17JPAEmitterManagerFPC11JPADrawInfoUc(void*, const void*, u8);
extern "C" void capture__10JUTTextureFii9_GXTexFmtbUc(void*, s32, s32, u8, u8, u8);
extern "C" void GXSetAlphaUpdate(u8);
extern "C" u8* sManager__8JUTVideo;
extern u8* lbl_8053AB10;

namespace JGeometry {
template <typename T> struct TVec3;
}
struct JPABaseEmitter;
struct JPAEmitterCallBack;
struct JPAParticleCallBack;
class JPAEmitterManager {
public:
    JPABaseEmitter* createSimpleEmitterID(const JGeometry::TVec3<f32>&, u16, u8, u8, JPAEmitterCallBack*, JPAParticleCallBack*);
};
class JPAResourceManager {
public:
    u32 getResUserWork(u16) const;
};
void JPASetRMtxSTVecfromMtx(const f32 (*)[4], f32 (*)[4], JGeometry::TVec3<f32>*, JGeometry::TVec3<f32>*);

struct EffSlot {
    u16 id;
    u16 used;
    f32 pos[3];
};

struct EffSlotTable {
    u8 pad[0x10];
    EffSlot slots[0x400];
};

static inline void tu13_setVec(f32* v, f32 x, f32 y, f32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline bool tu13_inPlay(u8* g) {
    if (g[0x7f] != 0) {
        u8 hit = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb);
        return hit;
    } else {
        u8 hit = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb || *(s32*)(g + 0x4c) == 0xc);
        return hit;
    }
}

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
            hit = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb);
        } else {
            hit = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb || *(s32*)(g + 0x4c) == 0xc);
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
            } else if (state == 0) {
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

extern "C" void __sinit_tu_8013C5C8_cpp_8013D6E4(u8* this_) {
    if (fn_80134CC8(lbl_8053AAF8)) {
        return;
    }
    struct SinitPOD_ {
        f32 cam[3][4];
        f32 prj[3][4];
    };
    SinitPOD_ src;
    src = *(SinitPOD_*)(*(u8**)(lbl_8053AB10 + 0x24) + 0xe4);
    f32 info[2][3][4];
    PSMTXIdentity(info[0]);
    PSMTXIdentity(info[1]);
    fn_8013B438(lbl_8053AB10);
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &src, 0);
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &src, 3);
    capture__10JUTTextureFii9_GXTexFmtbUc(*(void**)(lbl_8053AB10 + 0x34), 0, 0, **(u8**)(*(u8**)(lbl_8053AB10 + 0x34) + 0x20), 0, 0);
    fn_8013B490(lbl_8053AB10);
    f32 info2[2][3][4];
    PSMTXIdentity(info2[0]);
    PSMTXIdentity(info2[1]);
    PSMTXCopy(*(u8**)(lbl_8053AB10 + 0x10) + 0x80, info[0]);
    s32 w = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4);
    s32 h = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6);
    C_MTXLightOrtho(info[1], 0.0f, (f32)h, 0.0f, (f32)w, 0.5f, 0.5f, 0.5f, 0.5f);
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), info, 5);
    fn_8013B438(lbl_8053AB10);
    GXSetAlphaUpdate(0);
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &src, 1);
}

extern "C" u8 fn_80134CC8(void*);
extern "C" void fn_8013B438(void*);
extern "C" void fn_8013B490(void*);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" void C_MTXLightOrtho(f32 (*m)[4], f32 t, f32 b, f32 l, f32 r, f32 sS, f32 sT, f32 tS, f32 tT);
extern "C" void draw__17JPAEmitterManagerFPC11JPADrawInfoUc(void*, const void*, u8);
extern "C" void capture__10JUTTextureFii9_GXTexFmtbUc(void*, s32, s32, u8, u8, u8);
extern "C" void GXSetAlphaUpdate(u8);
extern "C" u8* sManager__8JUTVideo;

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

extern "C" void forceDeleteAllEmitter__17JPAEmitterManagerFv(void*);
extern "C" void* swapTexture__18JPAResourceManagerFPC7ResTIMGPCc(void*, const void*, const char*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" char __vt__18JPAEmitterCallBack[];
extern "C" char lbl_804BEC38[];
extern "C" s8 lbl_8053AB1C;
extern "C" void* lbl_8053AB20;
extern "C" char lbl_804BEC44[];
extern f32 lbl_8053CE00;

// Texture swap table: TIMG resource name, then the particle texture it replaces.
struct EffTexSwap {
    const char* res;
    const char* name;
};

struct EffEmitterSet {
    u8 pad0[0xc];
    JPAEmitterManager* mgr;
    EffSlot slots[0x400];
    JPABaseEmitter* emitters[0x19];
    u16 ids[0x1a];
    s32 flags[0x19];
    s32 count;
};

// Shared effect callback: a function-local static object (vtable lbl_8049F15C,
// dtor fn_8013C86C) registered for destruction on first use.
static inline JPAEmitterCallBack* tu13_effCallBack() {
    if (!lbl_8053AB1C) {
        lbl_8053AB20 = __vt__18JPAEmitterCallBack;
        lbl_8053AB20 = lbl_8049F15C;
        __register_global_object(&lbl_8053AB20, (void*)fn_8013C86C, lbl_804BEC44);
        lbl_8053AB1C = 1;
    }
    return (JPAEmitterCallBack*)&lbl_8053AB20;
}

static inline void tu13_addEmitter(EffEmitterSet* set, u16 id, u8 group, s32 flag) {
    JPAEmitterCallBack* cb = tu13_effCallBack();
    JPABaseEmitter*& em = set->emitters[set->count];
    f32 pos[3];
    pos[0] = lbl_8053CE00;
    pos[1] = lbl_8053CE00;
    pos[2] = lbl_8053CE00;
    em = set->mgr->createSimpleEmitterID(*(JGeometry::TVec3<f32>*)pos, id, group, 0, cb, 0);
    *(s32*)((u8*)em + 0x24) = 0;
    *(u32*)((u8*)em + 0xf4) |= 1;
    set->ids[set->count] = id;
    set->flags[set->count] = flag;
    set->count++;
}

extern "C" void fn_8013DC1C(void* this_) {
    calc__17JPAEmitterManagerFUc(*(void**)((char*)this_ + 0xc), 10);
}

extern "C" void fn_8013DC44(u8* this_) {
    bool bVar2 = false;
    u8 flag = 0;
    u8* g = (u8*)lbl_8053AAF8;
    if (g[0x7f] != 0) {
        if (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb) flag = 1;
    } else {
        if (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb || *(s32*)(g + 0x4c) == 0xc) flag = 1;
    }
    if (!flag || *(s32*)(g + 0x4c) == 0xc) {
        bVar2 = true;
    } else if (fn_802DCD0C(fn_802D6A9C()) == 0) {
        bVar2 = true;
    }
    if (bVar2) {
        if (*(s32*)(g + 0x4c) != 0xb) {
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

extern "C" const char* lbl_8049F118[];
extern "C" u8 lbl_80529DEC[];
extern "C" void fn_8013DDEC(u8* this_) {
    struct ResMgr {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void* getRes(u32 type, const char* name);
    };
    EffEmitterSet* set = (EffEmitterSet*)this_;
    ResMgr* res;
    s32 i;
    forceDeleteAllEmitter__17JPAEmitterManagerFv(set->mgr);
    set->count = 0;
    tu13_addEmitter(set, 0x347, 0, 0);
    tu13_addEmitter(set, 0x346, 0, 0);
    tu13_addEmitter(set, 0x345, 0, 0);
    tu13_addEmitter(set, 0x357, 0, 0);
    tu13_addEmitter(set, 0x358, 0, 0);
    tu13_addEmitter(set, 0x348, 0, 0);
    tu13_addEmitter(set, 0x35c, 0, 0);
    tu13_addEmitter(set, 0x54d, 1, 0);
    tu13_addEmitter(set, 0x349, 0, 0);
    tu13_addEmitter(set, 0x34a, 0, 0);
    tu13_addEmitter(set, 0x34b, 0, 0);
    tu13_addEmitter(set, 0x34c, 0, 1);
    tu13_addEmitter(set, 0x34d, 0, 1);
    tu13_addEmitter(set, 0x354, 0, 0);
    tu13_addEmitter(set, 0x355, 0, 0);
    tu13_addEmitter(set, 0x356, 0, 0);
    tu13_addEmitter(set, 0x351, 0, 0);
    tu13_addEmitter(set, 0x352, 0, 0);
    tu13_addEmitter(set, 0x353, 0, 0);
    tu13_addEmitter(set, 0x34e, 0, 0);
    tu13_addEmitter(set, 0x34f, 0, 0);
    tu13_addEmitter(set, 0x350, 0, 0);
    tu13_addEmitter(set, 0x359, 0, 0);
    tu13_addEmitter(set, 0x35a, 0, 0);
    tu13_addEmitter(set, 0x35b, 0, 0);
    res = *(ResMgr**)(lbl_80529DEC + 0x10);
    if (res != 0) {
        for (i = 0; i < 5; i++) {
            void* tex = res->getRes(0x54494d47, ((EffTexSwap*)lbl_8049F118)[i].res);
            if (tex != 0) {
                swapTexture__18JPAResourceManagerFPC7ResTIMGPCc(*(void**)(this_ + 8), tex, ((EffTexSwap*)lbl_8049F118)[i].name);
            }
        }
    }
    for (u32 j = 0; j < 0x400; j++) {
        set->slots[j].used = 0;
    }
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
        void* tex = ((void* (*)(void*, u32, const char*))((*(void***)obj)[6]))(obj, 0x3f3f3f3f, base + 0xb8);
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
    u8* p = lbl_8053AB10;
    u8* src = (u8*)*(void**)(p + 0x28);
    src = (u8*)*(void**)(src + 0xc);
    src = (u8*)*(void**)(src + 0x20) + 0x184;
    PSMTXCopy((u8*)*(void**)(p + 0x24) + 0xe4, src);
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
    char* base = lbl_804BEC38;
    lbl_8053AB18 = __vt__18JPAEmitterCallBack;
    lbl_8053AB18 = lbl_8049F184;
    __register_global_object(&lbl_8053AB18, (void*)fn_8013F6F8, lbl_804BEC38 + 0);
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x18);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0x24);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x30);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x3c);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x48);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x54);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x60);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x6c);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x78);
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
    fn_8010F668(m, &axis, angle + kPI);
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

extern f32 lbl_8053CE00;
extern f32 lbl_8053CE20;
extern "C" u8 fn_802DEABC(void);
extern "C" u8 fn_802DEB58(void);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8* fn_8013CC50(s32 mode, f32* pos, f32 scale, u16 effect, s32 dy, s32 dz, JPAEmitterCallBack* cb, JPAParticleCallBack* pcb, u8 snap) {
    u8* em = 0;
    if (scale > lbl_8053CE00) {
        if (mode == 0) {
            u8 group;
            f32 v[3];
            JPAEmitterCallBack* callback = cb;
            if (snap) {
                snap = pos[2] > lbl_8053CE00;
            }
            if (snap && dy < 1) {
                dy++;
                dz--;
            }
            f32 x = pos[0];
            f32 off = (f32)((dy << 10) + (dz << 7));
            tu13_setVec(v, x, pos[1] + off, pos[2] + off);
            f32 h = fn_802F5E9C(*(void**)(lbl_8053AB10 + 0x20), pos);
            v[2] = v[2] + (h - pos[2]);
            switch (effect) {
            case 0x558: case 0x559: case 0x55a: case 0x55b: case 0x55c: case 0x55d: case 0x55e:
            case 0x48e: case 0x48f: case 0x490: case 0x491: case 0x492: case 0x493: case 0x494: case 0x495:
            case 0x569: case 0x56a: case 0x56b: case 0x56c: case 0x56d: case 0x56e: case 0x56f: case 0x570: case 0x571:
                group = 2;
                break;
            case 0x127: case 0x128: case 0x129: case 0x12a: case 0x12b:
            case 0x188: case 0x189: case 0x18a: case 0x18b: case 0x18c: case 0x18d:
            case 0x2a8:
            case 0x4e0: case 0x4e1:
                group = 3;
                break;
            case 0x241:
            case 0x3dd:
            case 0x4cf: case 0x4d0: case 0x4d1:
                group = 4;
                break;
            case 0x543: case 0x544:
            case 0x54b:
                group = 5;
                break;
            case 0x26a:
            case 0x277: case 0x278: case 0x279: case 0x27a: case 0x27b: case 0x27c: case 0x27d:
            case 0x3a7: case 0x3a8: case 0x3a9: case 0x3aa: case 0x3ab: case 0x3ac: case 0x3ad:
            case 0x3ae: case 0x3af: case 0x3b0: case 0x3b1: case 0x3b2: case 0x3b3:
                group = 7;
                break;
            case 0x566: case 0x567: case 0x568:
                group = 8;
                break;
            case 0x385:
                group = 9;
                break;
            case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf:
            case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7:
            case 0xe8: case 0xe9:
            case 0x1dc: case 0x1dd: case 0x1de: case 0x1df: case 0x1e0: case 0x1e1: case 0x1e2: case 0x1e3:
            case 0x1e4: case 0x1e5: case 0x1e6: case 0x1e7: case 0x1e8: case 0x1e9: case 0x1ea: case 0x1eb:
            case 0x1ec: case 0x1ed: case 0x1ee: case 0x1ef: case 0x1f0: case 0x1f1: case 0x1f2: case 0x1f3:
            case 0x1f4: case 0x1f5: case 0x1f6: case 0x1f7: case 0x1f8: case 0x1f9: case 0x1fa: case 0x1fb:
            case 0x1fc:
            case 0x3ec: case 0x3ed: case 0x3ee: case 0x3ef: case 0x3f0: case 0x3f1: case 0x3f2: case 0x3f3:
                group = 10;
                break;
            case 0x345: case 0x346: case 0x347: case 0x348: case 0x349: case 0x34a: case 0x34b: case 0x34c:
            case 0x34d: case 0x34e: case 0x34f: case 0x350: case 0x351: case 0x352: case 0x353: case 0x354:
            case 0x355: case 0x356: case 0x357: case 0x358: case 0x359: case 0x35a: case 0x35b: case 0x35c:
            case 0x54d:
                group = 0xff;
                break;
            default:
                group = 0;
                break;
            }
            u8* g = (u8*)lbl_8053AAF8;
            if (tu13_inPlay(g) && *(s32*)(g + 0x4c) != 0xc) {
                if (fn_802D6A9C()[0x131f1] != 0) {
                    switch (effect) {
                    case 0x3cf: effect = 0x454; break;
                    case 0x3d3: effect = 0x455; break;
                    case 0x116: effect = 0x44e; break;
                    case 0x115: effect = 0x44d; break;
                    }
                } else if (fn_802D6A9C()[0x131f2] != 0) {
                    switch (effect) {
                    case 0x3d3: effect = 0x3a4; break;
                    case 0x3cf: effect = 0x3a3; break;
                    case 0x24e: effect = 0x24c; break;
                    case 0x24f: effect = 0x24d; break;
                    }
                } else if (fn_802DEABC()) {
                    switch (effect) {
                    case 0x3d3: effect = 0xd6; break;
                    case 0x3cf: effect = 0xd5; break;
                    }
                } else if (fn_802DEB58()) {
                    switch (effect) {
                    case 0x2a9: effect = 0x45e; break;
                    case 0x2aa: effect = 0x45f; break;
                    case 0x4f3: case 0x4f7: effect = 0x4fb; break;
                    case 0x4f4: case 0x4f8: effect = 0x4fc; break;
                    case 0x4f5: case 0x4f9: effect = 0x4fd; break;
                    case 0x4f6: case 0x4fa: effect = 0x4fe; break;
                    case 0x15b: case 0x15c: case 0x3d0: return 0;
                    }
                }
                if (!fn_802DE9A0()) {
                    switch (effect) {
                    case 0x2a9: return 0;
                    case 0x2aa: return 0;
                    case 0x4f7: return 0;
                    case 0x4f8: return 0;
                    case 0x4f9: return 0;
                    case 0x4fa: return 0;
                    }
                }
            }
            if (group == 0xff) {
                EffSlotTable* tbl = *(EffSlotTable**)(lbl_8053AB10 + 0x28);
                for (s32 i = 0; i < 0x400; i++) {
                    EffSlot& s = tbl->slots[i];
                    if (s.used == 0) {
                        s.pos[0] = v[0];
                        s.pos[1] = v[1];
                        s.pos[2] = v[2];
                        s.id = effect;
                        s.used = 1;
                        break;
                    }
                }
            } else {
                if ((*(JPAResourceManager**)(*(u8**)(lbl_8053AB10 + 0x28) + 0x8))->getResUserWork(effect) & 1) {
                    callback = (JPAEmitterCallBack*)&lbl_8053AB18;
                }
                if (((*(JPAResourceManager**)(*(u8**)(lbl_8053AB10 + 0x28) + 0x8))->getResUserWork(effect) & 2) && group != 5) {
                    group = 1;
                }
                em = (u8*)(*(JPAEmitterManager**)(*(u8**)(lbl_8053AB10 + 0x28) + 0xc))->createSimpleEmitterID(
                    *(JGeometry::TVec3<f32>*)v, effect, group, 0, callback, pcb);
            }
            if (em != 0) {
                f32 k = lbl_8053CE20 * scale;
                if (group != 2 && group != 4 && group != 5 && group != 8 && group != 10) {
                    f32 m[3][4];
                    m[0][0] = scale;
                    m[0][1] = lbl_8053CE00;
                    m[0][2] = lbl_8053CE00;
                    m[0][3] = v[0];
                    m[1][0] = lbl_8053CE00;
                    m[1][1] = lbl_8053CE00;
                    m[1][2] = k;
                    m[1][3] = v[1];
                    m[2][0] = lbl_8053CE00;
                    m[2][1] = k;
                    m[2][2] = lbl_8053CE00;
                    m[2][3] = v[2];
                    JPASetRMtxSTVecfromMtx(m, (f32 (*)[4])(em + 0x68), (JGeometry::TVec3<f32>*)(em + 0x98), (JGeometry::TVec3<f32>*)(em + 0xa4));
                    f32 sy = *(f32*)(em + 0x9c);
                    f32 sx = *(f32*)(em + 0x98);
                    *(f32*)(em + 0xb0) = sx;
                    *(f32*)(em + 0xb4) = sy;
                    *(f32*)(em + 0xb0) = scale;
                    *(f32*)(em + 0xb4) = scale;
                } else {
                    *(f32*)(em + 0x98) = scale;
                    *(f32*)(em + 0x9c) = scale;
                    *(f32*)(em + 0xa0) = scale;
                    *(f32*)(em + 0xb0) = scale;
                    *(f32*)(em + 0xb4) = scale;
                }
            }
        } else {
            switch (effect) {
            case 0x172:
                Actor_CreateByID(fn_801F856C(), 0x4b4d5249, (void*)mode, pos, 0, -1, -1);
                break;
            case 0x33a: case 0x33b:
                Actor_CreateByID(fn_801F856C(), 0x4b4d5249, (void*)mode, pos, 2, -1, -1);
                break;
            case 0x19d:
            case 0x24a:
                Actor_CreateByID(fn_801F856C(), 0x444d4745, (void*)mode, pos, 0, -1, -1);
                break;
            case 0x174: case 0x175: case 0x176: case 0x177: case 0x178: case 0x179:
            case 0x17c:
            case 0x473:
                Actor_CreateByID(fn_801F856C(), 0x444d4745, (void*)mode, pos, 1, -1, -1);
                break;
            case 0xff:
                Actor_CreateByID(fn_801F856C(), 0x444d4745, (void*)mode, pos, 0x80, -1, -1);
                break;
            case 0x116:
            case 0x24e: case 0x24f: case 0x250: case 0x251:
            case 0x3d3: case 0x3d4:
                em = (u8*)(*(JPAEmitterManager**)(*(u8**)(lbl_8053AB10 + 0x28) + 0xc))->createSimpleEmitterID(
                    *(JGeometry::TVec3<f32>*)pos, effect, 6, 0, cb, pcb);
                break;
            case 0x15b:
            case 0x3d0:
                Actor_CreateByID(fn_801F856C(), 0x50454646, (void*)mode, pos, 0x2c, -1, 0);
                break;
            case 0x3cf:
                Actor_CreateByID(fn_801F856C(), 0x50454646, (void*)mode, pos, 0x34, -1, 0);
                break;
            }
        }
    }
    return em;
}