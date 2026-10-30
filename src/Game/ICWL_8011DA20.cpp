#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JKernel/JKRArchive.h"
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, DrawRec* rec, f32 sx, f32 sy);
extern "C" void fn_801F02BC(void* a, const char* name, s32 id, DrawRec* rec, s32 p5, s32 p6, s32 p7, f32 f6, f32 f7);
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern char lbl_80464C30[];
extern char lbl_80464C44[];
extern const f32 lbl_8053C8C4;
extern const f32 lbl_8053C8C8;
extern const f32 lbl_8053C8CC;
extern const f32 lbl_8053C8D0;

extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049DE18[];
extern const f32 lbl_8053C8BC;
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CC34[];
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_80539F28[8];
extern const f32 lbl_8053C8B8;
extern const f32 lbl_8053C8C0;
extern const f32 lbl_8053C8DC;
extern const f32 lbl_8053C8E0;
extern const f32 lbl_8053C8E4;
extern const f32 lbl_8053C8E8;
extern const f32 lbl_8053C8EC;
extern const f32 lbl_8053C8F0;
extern const f32 lbl_8053C8D4;
extern const f32 lbl_8053C8D8;
extern const f32 lbl_8053C8BC;
extern u32 lbl_80464C0C[];
extern u32 lbl_80464BE8[];
extern "C" void v03__5ActorFv(void* this_);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_80239914(void* box, u32 a, u32 b);
extern "C" s32 fn_8023AA18(void* box, s32 room, void* vec = 0);
extern "C" s32 fn_8023AB94(void* box, s32 room, void* vec);
extern "C" s32 fn_8023AC74(void* box, s32 room, void* vec);
extern "C" s32 fn_8023AD54(void* box, s32 room, void* vec);
extern "C" s32 fn_8023AE34(void* box, s32 room, void* vec);
extern "C" void fn_802379E4(s32 idx, void* vec);
extern "C" s32 fn_801F285C(void* this_, void* a, void* b, u32 c, s32 d);
extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" void fn_801F0D20(void* this_, s32 p);
extern "C" s32 fn_801F2718(void* this_, u32 code);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 name, u32 room, void* pos, u32 arg, s32 a, s32 b);
extern "C" void fn_801CC820(s32 idx, s32 a);
extern "C" void fn_801CC538(s32 idx, void* a, void* b, s32 c);
extern "C" void fn_801CC640(s32 idx, s32 a, s32 b);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_8020D58C(void);
extern "C" void fn_8020D7D0(void* entry, u32 handle);
extern "C" s32 fn_801CD950(void* value, f32 target, f32 step);
extern "C" s32 fn_8013CC50(u32 room, void* pos, f32 scale, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void fn_801D1C18(void* p);
extern "C" void v06__5ActorFv(void* this_);
struct ICWLVec2 {
    ICWLVec2() {}
    ICWLVec2(f32 x_, f32 y_) : x(x_), y(y_) {}
    f32 x, y;
};

struct ICWLResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* vf18(u32 type, const char* name);
};

struct ICWLPos {
    f32 x, y, z;
};

struct ICWLBox {
    f32 x0, y0, x1, y1;
    void offset(f32 x, f32 y) {
        x0 += x;
        y0 += y;
        x1 += x;
        y1 += y;
    }
};

static inline void icwlScaleMatrix(f32* __restrict m, const JGeometry::TVec3<f32>& v) {
    f32 zero = 0.0f;
    m[3] = zero; m[7] = zero; m[11] = zero;
    f32 y = v.y;
    f32 x = v.x;
    m[0] = x;
    m[1] = zero; m[2] = zero; m[4] = zero;
    m[5] = y;
    m[6] = zero; m[8] = zero; m[9] = zero;
    m[10] = v.z;
}
static inline void icwlDrawSprite(void* pos, const char* name, s32 id, DrawRec* rec) {
    void* res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x534f4220, name);
    fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, res, id, rec, lbl_8053C8BC, lbl_8053C8BC);
}

extern int __float_epsilon[];
extern "C" void fn_8011DA20(u8* this_) {
    v06__5ActorFv(this_);
    DrawRec a;
    DrawRec b;
    f32 m[12];
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec3<f32>& v = *(JGeometry::TVec3<f32>*)(this_ + 0x54);
    if (!(v.squared() <= lbl_8053C8C4 * (*(f32*)__float_epsilon))) {
        icwlScaleMatrix(m, v);
        a.w18 = m;
    }
    if ((*(s32*)(this_ + 0x230) == 0 && v.x >= lbl_8053C8C8) || (*(s32*)(this_ + 0x230) == 1 && v.x >= lbl_8053C8CC)) {
            JGeometry::TVec3<f32>* drawPos = (JGeometry::TVec3<f32>*)(this_ + 0xc);
            pos = *drawPos;
            switch (*(s32*)(this_ + 0x23c)) {
            case 0: case 7: break;
            case 1:
                if (*(s32*)(this_ + 0x4) < 8) {
                    icwlDrawSprite(drawPos, lbl_80464C30, 0xe9, 0);
                }
                break;
            case 2:
                if (*(s32*)(this_ + 0x4) < 8) {
                    icwlDrawSprite(drawPos, lbl_80464C44, 0x11, 0);
                }
                break;
            case 3:
                b.ids[2] = 4;
                if (*(s32*)(this_ + 0x4) < 8) {
                    icwlDrawSprite(drawPos, lbl_80464C44, 0x200, &b);
                }
                break;
            case 4:
                b.b1d = -1;
                pos.y += lbl_8053C8D0;
                if (*(s32*)(this_ + 0x4) < 8) {
                    icwlDrawSprite(&pos, lbl_80464C30, 0x14c, &b);
                }
                break;
            case 5:
                if (*(s32*)(this_ + 0x4) < 8) {
                    icwlDrawSprite(&pos, lbl_80464C44, 0x5e, &b);
                }
                break;
            case 6:
                if (*(s32*)(this_ + 0x4) < 8) {
                    icwlDrawSprite(&pos, lbl_80464C44, 0x31, &b);
                }
                break;
            case 8:
                if (*(s32*)(this_ + 0x4) < 8) {
                    icwlDrawSprite(&pos, lbl_80464C44, 0x2c, &b);
                }
                break;
            }
        }
    fn_801F02BC(this_, lbl_80464C44, *(s32*)(this_ + 0x254) + 0x1ca, &a, 7, 0, 0, lbl_8053C8BC, lbl_8053C8BC);
    if (*(s32*)(this_ + 0x230) == 0) {
        a.b1c = 1;
    }
    fn_801F02BC(this_, lbl_80464C44, *(s32*)(this_ + 0x254) + 0x1cb, &a, 7, 0, 0, lbl_8053C8BC, lbl_8053C8BC);
}

static inline void icwlGetBox(u8* this_, ICWLBox* box) {
    *box = *(ICWLBox*)(this_ + 0x60);
    box->x0 += *(f32*)(this_ + 0xc);
    box->y0 += *(f32*)(this_ + 0x10);
    box->x1 += *(f32*)(this_ + 0xc);
    box->y1 += *(f32*)(this_ + 0x10);
}

static inline void icwlGetBox2(u8* this_, ICWLBox* box, f32 x, f32 y) {
    *box = *(ICWLBox*)(this_ + 0x70);
    box->x0 += x;
    box->y0 += y;
    box->x1 += x;
    box->y1 += y;
}

static inline void icwlKillEmitter(void** emitter) {
    if (*(u32*)emitter != 0) {
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *emitter);
        *emitter = 0;
    }
}

static inline void icwlRelease(u32 handle) {
    u8* base = (u8*)fn_8020D58C();
    fn_8020D7D0(base + 4 + base[0] * 0x784, handle);
}

static inline bool icwlHitPlayer(u8* this_) {
    s32 idx = fn_801F285C(this_, 0, 0, 1, -1);
    if (idx >= 0) {
        fn_801F0E34(this_, 0x400D1, 0);
        ICWLVec2 v(((f32*)(this_ + 0xc))[0], ((f32*)(this_ + 0xc))[1]);
        fn_802379E4(idx, &v);
        return true;
    }
    return false;
}

static inline bool icwlHitObject(u8* this_) {
    ICWLVec2 v;
    ICWLBox box;
    f32 out[3];
    s32 idx;
    v.x = lbl_8053C8B8;
    v.y = lbl_8053C8B8;
    icwlGetBox2(this_, &box, *(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14));
    if (fn_8023AA18(&box, *(s32*)(this_ + 0x4), &v) >= 0) {
        return true;
    }
    idx = fn_8023AE34(&box, *(s32*)(this_ + 0x4), &v);
    if (idx >= 0) {
        fn_801CC820(idx, 0);
        return true;
    }
    idx = fn_8023AC74(&box, *(s32*)(this_ + 0x4), &v);
    if (idx >= 0) {
        fn_801CC538(idx, &v, out, 0);
        return true;
    }
    idx = fn_8023AD54(&box, *(s32*)(this_ + 0x4), &v);
    if (idx >= 0) {
        fn_801CC640(idx, 0, 0);
        return true;
    }
    return false;
}

static inline bool icwlHitFire(u8* this_) {
    ICWLBox box;
    ICWLVec2 v;
    icwlGetBox(this_, &box);
    v.y = v.x = lbl_8053C8B8;
    if (fn_8023AB94(&box, *(s32*)(this_ + 0x4), &v) >= 0 || fn_801F2718(this_, 0x46495245) >= 0) {
        return true;
    }
    return false;
}

extern "C" void fn_8011E030(u8* this_) {
    ICWLBox box;
    u32 name;
    u32 arg;

    v03__5ActorFv(this_);
    icwlGetBox(this_, &box);

    switch (*(s32*)(this_ + 0x234)) {
    case 0:
        fn_80239914(&box, *(s32*)(this_ + 0x4), *(u32*)(this_ + 0x198));
        if (icwlHitPlayer(this_)) {
            break;
        }
        if (icwlHitObject(this_)) {
            break;
        }
        if (icwlHitFire(this_)) {
            icwlKillEmitter((void**)(this_ + 0x100));
            icwlKillEmitter((void**)(this_ + 0x104));
            s32 room = *(s32*)(this_ + 0x4);
            if (room == 0) {
                f32 scale = lbl_8053C8BC;
                if (*(s32*)(this_ + 0x230) == 1) {
                    scale = lbl_8053C8C0;
                }
                *(void**)(this_ + 0x27C) = (void*)fn_8013CC50(room, this_ + 0xc, scale, 0x28D, 1, 0, 0, 0, 1);
                fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, scale, 0x28E, 1, 0, 0, 0, 1);
            }
            fn_801F0E34(this_, 0x30061, 0);
            *(s32*)(this_ + 0x234) = 1;
        } else {
            u32 handle = *(u32*)(this_ + 0x198);
            u8* base = (u8*)fn_8020D58C();
            fn_8020D7D0(base + 4 + base[0] * 0x784, handle);
        }
        break;
    case 1:
        if (fn_801CD950(this_ + 0x240, lbl_8053C8D4, lbl_8053C8D8) == 0) {
            u8* emitter = *(u8**)(this_ + 0x27C);
            if (emitter != 0) {
                *(u32*)(emitter + 0xF4) |= 1;
                *(s32*)(emitter + 0x24) = 1;
            }
            switch (*(s32*)(this_ + 0x238)) {
            case 0:
                break;
            case 1:
                fn_801F0D20(this_, 3);
                break;
            case 2:
                fn_801F0D20(this_, 0x42);
                break;
            case 3:
                fn_801F0D20(this_, 6);
                break;
            }
            if (*(s32*)(this_ + 0x23C) != 0) {
                arg = lbl_80464C0C[*(s32*)(this_ + 0x23C)];
                name = lbl_80464BE8[*(s32*)(this_ + 0x23C)];
                Actor_CreateByID(fn_801F856C(), name, *(s32*)(this_ + 0x4), this_ + 0xc, arg, -1, -1);
            }
            detach__5ActorFv(this_);
            *(s32*)(this_ + 0x234) = 2;
        }
        break;
    case 2:
        break;
    }
    f32 s = *(f32*)(this_ + 0x240);
    *(f32*)(this_ + 0x54) = s;
    *(f32*)(this_ + 0x58) = s;
    *(f32*)(this_ + 0x5C) = s;
    fn_801D1C18(this_ + 0x244);
}

extern "C" void fn_8011E4FC(u8* this_) {
    v01__5ActorFv(this_);
    *(s32*)(this_ + 0x230) = *(s32*)(this_ + 0x90) & 0xF;
    *(s32*)(this_ + 0x238) = (*(s32*)(this_ + 0x90) >> 4) & 0xF;
    *(s32*)(this_ + 0x23C) = (*(s32*)(this_ + 0x90) >> 8) & 0xFF;
    switch (*(s32*)(this_ + 0x230)) {
    case 1: {
        f32 f0 = lbl_8053C8C0;
        f32 f1 = lbl_8053C8E4;
        f32 f2 = lbl_8053C8E0;
        f32 f3 = lbl_8053C8DC;
        *(f32*)(this_ + 0x240) = f0;
        f32 f4 = *(f32*)(this_ + 0x240);
        *(f32*)(this_ + 0x54) = f4;
        *(f32*)(this_ + 0x58) = f4;
        *(f32*)(this_ + 0x5C) = f4;
        *(f32*)(this_ + 0x60) = f3;
        *(f32*)(this_ + 0x64) = f3;
        *(f32*)(this_ + 0x68) = f2;
        *(f32*)(this_ + 0x6C) = f2;
        *(f32*)(this_ + 0x80) = f1;
        *(f32*)(this_ + 0x84) = f1;
        f0 = lbl_8053C8E8;
        *(f32*)(this_ + 0x88) = f0;
        *(f32*)(this_ + 0x8C) = f0;
        break;
    }
    case 0:
    default: {
        f32 f0 = lbl_8053C8EC;
        f32 f1 = lbl_8053C8DC;
        f32 f2 = lbl_8053C8F0;
        *(f32*)(this_ + 0x60) = f0;
        *(f32*)(this_ + 0x64) = f0;
        f0 = lbl_8053C8E0;
        *(f32*)(this_ + 0x68) = f2;
        *(f32*)(this_ + 0x6C) = f2;
        *(f32*)(this_ + 0x80) = f1;
        *(f32*)(this_ + 0x84) = f1;
        *(f32*)(this_ + 0x88) = f0;
        *(f32*)(this_ + 0x8C) = f0;
        break;
    }
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7C) = *(f32*)(this_ + 0x6C);
    *(s32*)(this_ + 0xB8) = 1;
    *(s32*)(this_ + 0xB0) = 0x06040304;
    *(s32*)(this_ + 0x118) = 0;
    *(s32*)(this_ + 0xBC) = 3;
    fn_801D2608(this_ + 0x244, lbl_80539F28, 1);
    fn_801D22DC(this_ + 0x244, 0, 2, 0);
    fn_801D1F14(this_ + 0x244, lbl_8053C8B8);
}

extern "C" void* fn_8011E650(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049DE18;
        fn_801EE434(*(void**)(p + 0x27c));
        *(s32*)(p + 0x27c) = 0;
        if (p + 0x244 != 0) {
            if (p + 0x268 != 0) {
                *(void**)(p + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8011E6E0(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049DE18;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(f32*)(p + 0x240) = lbl_8053C8BC;
    fn_801D267C(p + 0x244);
    *(s32*)(p + 0x27c) = 0;
    return p;
}

void __sinit_ICWL_8011DA20_cpp(void) {}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
