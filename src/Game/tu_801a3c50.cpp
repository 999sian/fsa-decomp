// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A3C50-801A6690 (unknown). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "std/math.h"
#include "JSystem/JMath/JMath.h"
extern "C" s32 fn_8023AE34(void*, s32, void*);
extern "C" s32 fn_8023B2B0(s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, void*, s32, s32, s32);
extern "C" s32 fn_801F6874(s32);
extern "C" void fn_801F714C(u16*, u16, s32, s32);
extern "C" f32 fn_801EE4F0();

extern "C" u8* fn_802D6A9C(void);
extern "C" void* fn_8023E724(s32);
extern "C" void fn_801F37AC(void*, s32, void*, s32, s32, s32);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void* fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);

extern "C" s32 fn_8023AD54(void* box, s32 room, void* out);
extern "C" s32 fn_8023B358(s32 id);
extern "C" s32 fn_8023B5B4(s32 id);
extern "C" void fn_80235B68(s32 id, s32 h);
extern "C" void fn_801F3780(void* a, s32 v);
extern "C" s32 ClassifyBamAngleToQuadrant(u16 angle);
extern const f32 lbl_8053E5E4;
extern const f32 lbl_8053E5E8;

class SayaActor {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
};

extern "C" void fn_801F4694(void* this_);
extern s32 lbl_8053A100;
extern s8 lbl_8053ABC8;
extern f32 lbl_8053E5D0;
extern f32 lbl_8053E5D4;
extern f32 lbl_8053E5D8;
extern u8 lbl_804C6640[0x30];

struct SayaCfg {
    u8 tbl[16];
    s32 w10;
    s32 w14;
    void* p18;
    u8 b1c[11];
    s32 w28;
    u8 b2c[3];
    s32 w30;
    s32 w34;
    s32 w38;
};

static inline void Saya_setTarget(u8* this_, s32 id) {
    *(s32*)(this_ + 0x108) = 0;
    *(s32*)(this_ + 0x10C) = id;
    JGeometry::TVec3<f32> v(1.4f, 0.4f, 0.4f);
    *(s32*)(this_ + 0xA0) = id;
    *(JGeometry::TVec3<f32>*)(this_ + 0x48) = v;
    *(s32*)(this_ + 0xD8) = 0;
    *(s32*)(this_ + 0xDC) = 0;
    *(s32*)(this_ + 0xA4) = 0;
    fn_801F4694(this_);
    if (*(s32*)(this_ + 4) >= 8) {
        *(s32*)(this_ + 0xA8) = 0x1E;
    } else {
        *(s32*)(this_ + 0xA8) = 0x23;
    }
    lbl_8053A100 = id;
    ((SayaActor*)this_)->v44();
}

extern "C" void fn_801A3C50(u8* this_, s32 id) {
    Saya_setTarget(this_, id);
}

extern "C" void PSMTXScale(f32 (*m)[4], f32 x, f32 y, f32 z);
extern "C" void PSMTXTrans(f32 (*m)[4], f32 x, f32 y, f32 z);
extern "C" void fn_801A3CFC(u8* this_) {
    struct Cfg {
        u8 tbl[16];
        u8 m10, m11, m12, m13, m14, m15, m16, m17;
        void* p18;
        u8 b1c0, b1c1, b1c2, b1c3, b1c4, b1c5, b1c6, b1c7, b1c8, b1c9, b1c10;
        s32 w28;
        u8 b2c0, b2c1, b2c2;
        s32 w30;
        s32 w34;
        s32 w38;
    };
    Cfg cfg;
    u8 i;

    *(s32*)&cfg.m10 = -1;
    *(s32*)&cfg.m14 = -1;
    for (i = 0; i < 16; i++) {
        cfg.tbl[i] = i;
    }
    *(s32*)&cfg.m10 = -1;
    *(s32*)&cfg.m14 = 0;
    cfg.p18 = 0;
    cfg.b1c0 = 0;
    cfg.b1c1 = 0;
    cfg.b1c2 = 0;
    cfg.b1c3 = 1;
    cfg.b1c4 = 1;
    cfg.b1c5 = 0;
    cfg.b1c6 = 0;
    cfg.b1c7 = 0;
    cfg.b1c8 = 0;
    cfg.b1c9 = 0;
    cfg.b1c10 = 1;
    cfg.w28 = 3;
    cfg.b2c0 = 1;
    cfg.b2c1 = 0;
    cfg.b2c2 = 0;
    cfg.w30 = -1;
    cfg.w34 = 0;
    cfg.w38 = 2;

    if (lbl_8053ABC8 == 0) {
        lbl_8053ABC8 = 1;
    }
    *(Cfg*)(this_ + 0x120) = cfg;
    if (*(s32*)(this_ + 0xA0) >= 0 && lbl_8053E5D0 != *(f32*)(this_ + 0x48)) {
        cfg.w30 = 8;
        PSMTXScale((f32(*)[4])lbl_804C6640, *(f32*)(this_ + 0x48), *(f32*)(this_ + 0x4C), *(f32*)(this_ + 0x4C));
        *(f32*)(lbl_804C6640 + 0xC) = lbl_8053E5D4;
        *(f32*)(lbl_804C6640 + 0x1C) = lbl_8053E5D4;
        *(f32*)(lbl_804C6640 + 0x2C) = lbl_8053E5D4;
        cfg.p18 = lbl_804C6640;
        *(Cfg*)(this_ + 0x120) = cfg;
    } else {
        if (*(s32*)(this_ + 0xA4) != 0) {
            PSMTXTrans((f32(*)[4])lbl_804C6640, 0.0f, 0.0f, 0.0f);
            if (*(s32*)(this_ + 0xA4) < 100) {
                if ((*(s32*)(this_ + 0xA4) & 2) == 0) {
                    *(f32*)(lbl_804C6640 + 0xC) = lbl_8053E5D0;
                    *(f32*)(lbl_804C6640 + 0x1C) = lbl_8053E5D4;
                    *(f32*)(lbl_804C6640 + 0x2C) = lbl_8053E5D4;
                } else {
                    *(f32*)(lbl_804C6640 + 0xC) = lbl_8053E5D8;
                    *(f32*)(lbl_804C6640 + 0x1C) = lbl_8053E5D4;
                    *(f32*)(lbl_804C6640 + 0x2C) = lbl_8053E5D4;
                }
            }
            cfg.p18 = lbl_804C6640;
            *(Cfg*)(this_ + 0x120) = cfg;
        }
    }
}

// from src/Game/Saya_ForceState1_801A46FC.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
struct SayaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
    f32 get_sfloat_1() {
        return 1.0f - 2.0f * get_ufloat_1();
    }
};
struct SayaGame { u8 pad[0xb4]; SayaRandom rnd; };
extern SayaGame* lbl_8053AAF8;
extern const f32 lbl_8053E5E0;
#pragma dont_inline reset
extern "C" s32 fn_801A41D8(void* this_, void* a4, void* a5) {
    u8* other;
    s32 id;
    s32 kind;
    s32 result;
    u8* self = (u8*)this_;
    id = fn_8023AD54(a4, *(s32*)(self+4), a5);
    if (id < 0) return 0;
    s32 room = *(s32*)(self+4);
    u8 (*mgr)[0x10000] = (u8 (*)[0x10000])fn_802D6A9C();
    if (mgr[1][room+0x31df] == 0 && *(f32*)(self+0x14)>32.0f) return 0;
    s32 handle = fn_8023B358(id);
    other = (u8*)fn_801F666C(fn_801F856C(), handle);
    if (!other || *(s32*)(other+0x108)==0) return 0;
    s32 mode = 0;
    if (*(u16*)(other+0x94)) kind = (*(u32*)(self+0xb0)>>16)&0xff;
    else { mode = 1; kind = *(u32*)(self+0xb0)&0xff; }
    if (kind==0) return 0;
    result = 0;
    if (id>=0) lbl_8053A100=id;
    ((SayaActor*)self)->v44();
    if (mode==0) {
        if (kind==6) {
            f32 x = *(f32*)(self+0xc)-*(f32*)(other+0xc);
            f32 y = *(f32*)(self+0x10)-*(f32*)(other+0x10);
            s32 dir;
            bool diff=false;
            kind=4;
            f32 angle=JMath::atanTable_.atan2_(-x,-y);
            dir=*(s32*)(self+0x98);
            if ((dir^1)!=ClassifyBamAngleToQuadrant((u16)(s32)(angle*lbl_8053E5E0))) diff=true;
            if (!diff) kind=1;
            if (*(s32*)(self+0xa4)) kind=1;
        }
        switch (kind) {
        default: case 0: case 4: case 6:
            for (s32 i=0;i<4;i++) {
                s32 h=fn_8023B358(i);
                if (h>=0) {
                    u8* a=(u8*)fn_801F666C(fn_801F856C(),h);
                    if (a) *(s32*)(a+0x108)=0;
                }
            }
        case 2: case 5: result=0xff; break;
        case 1:
            if (*(f32*)(self+0x14)==lbl_8053E5D4) {
                f32 base = 4.0f;
                f32 one = 1.0f;
                f32 scale = 2.0f;
                f32 random = lbl_8053AAF8->rnd.get_ufloat_1();
                f32 z=base+(one-scale*random);
                *(JGeometry::TVec3<f32>*)(self+0x3c)=JGeometry::TVec3<f32>(*(f32*)(self+0x3c),*(f32*)(self+0x40),z);
                *(JGeometry::TVec3<f32>*)(self+0xc)=JGeometry::TVec3<f32>(*(f32*)(self+0xc),*(f32*)(self+0x10),*(f32*)(self+0x14)+*(f32*)(self+0x44));
            }
            *(s32*)(self+0xd8)=0;
            *(s32*)(self+0xdc)=0;
            *(s32*)(other+0x108)=0;
            fn_801F3780(self,0x12c);
            fn_801F0E34(self,0x30021,0);
            result=0x32; break;
        case 7:
            *(u8*)(other+0x11c)=0;
            *(s32*)(self+0x108)=0;
            result=0xff; break;
        case 3:
            *(u8*)(other+0x11c)=0;
            *(s32*)(self+0x10c)=id;
            fn_801F4694(self);
            ((SayaActor*)self)->v24();
            break;
        }
    } else {
        if (kind==9) {
            kind=4;
            f32 x=*(f32*)(self+0xc)-((f32*)fn_8023E724(id))[0];
            f32 y=*(f32*)(self+0x10)-((f32*)fn_8023E724(id))[1];
            f32 angle=JMath::atanTable_.atan2_(-x,-y);
            mode=*(s32*)(self+0x98);
            if (mode!=ClassifyBamAngleToQuadrant((u16)(s32)(angle*lbl_8053E5E0))) kind=5;
        }
        switch(kind) {
        case 8:
            *(s32*)(self+0x108)=0; result=0xff; break;
        case 1: case 2: case 5: {
            mode=*(s32*)(self+0x108);
            s32 health=mode-fn_8023B5B4(id);
            *(u8*)(other+0x11c)=0;
            if (health<=0) {
                *(s32*)(self+0x108)=0;
                fn_80235B68(id,*(s32*)(self+0x198));
                *(s32*)(self+0x10c)=id;
                result=0x14;
            } else { *(s32*)(self+0x108)=health; result=0xa; }
            break;
        }
        case 4: case 6: case 11: case 16: case 17: case 18:
            for (s32 i=0;i<4;i++) {
                s32 h=fn_8023B358(i);
                if (h>=0) {
                    u8* a=(u8*)fn_801F666C(fn_801F856C(),h);
                    other=a;
                    if (a) *(s32*)(a+0x108)=0;
                }
            }
            result=0xff; break;
        case 0: case 3: case 9: case 10: case 12: case 13: case 14: case 15: break;
        default:
            fn_8013CC50(*(s32*)(other+4),other+0xc,0x24a,0,1,0,0,1,1.0f);
            fn_8013CC50(*(s32*)(other+4),other+0xc,0x24b,0,1,0,0,1,1.0f);
            *(u8*)(other+0x11c)=0;
            *(u8*)(self+0x11c)=0;
            result=0xff; break;
        }
        if (result && (kind==1 || kind==2 || kind==5)) {
            JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(self+0xc));
            JMathInlineVEC::PSVECSubtract(&pos,(Vec*)(other+0x3c),&pos);
            fn_801F37AC(self,0,&pos,3,0,-1);
        }
    }
    return result;
}
#pragma dont_inline reset

// SAYA cluster, part 4/18 (88B). Vtable-slot wrapper that directly
// invokes state-handler fn_801A41D8 (an external "force-run this
// specific behavior" entry point, separate from the update() dispatch
// chain through fn_801A6160). Return value is passed through to callers
// that check it (e.g. extab_80145f60.s).
extern "C" s32 fn_801A46FC(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A41D8(target, a4, a5);
}

// from src/Game/Saya_ForceState2_801A4D1C.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A4754(u8* this_, void* a4, void* a5);
extern "C" s32 fn_8023AC74(void*, s32, void*);
extern "C" s32 fn_8023B22C(s32);
extern "C" u8 fn_801EAC20(void*, s32);
extern "C" s32 fn_8022F514(void*);
extern "C" s32 fn_8022F3DC(void*);
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
extern "C" s32 fn_801A4754(u8* this_, void* a4, void* a5) {
    u8* other;
    s32 kind;
    s32 id = (s32)a4;
    s32 result;
    s32 handle;
    s32 out = (s32)a5;
    kind = (*(u32*)(this_ + 0xB0) >> 16) & 0xFF;
    if (kind == 0) return 0;
    if (kind == 2 || kind == 7 || kind == 8) {
        u8* target;
        handle = *(s32*)(this_ + 0xA0);
        if (handle >= 0) {
            target = (u8*)fn_801F666C(fn_801F856C(), handle);
            if (target) {
                JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(target + 0xC));
                id = fn_8023AC74((void*)id, *(s32*)(this_ + 4), (void*)out);
                if (id >= 0) lbl_8053A100 = id;
                ((SayaActor*)this_)->v44();
                if (kind == 8 && *(s32*)(target + 4) != 0) {
                    *(s32*)(this_ + 0xB0) = *(s32*)(this_ + 0xB4);
                    *(s32*)(this_ + 0xA0) = -1;
                    return 0;
                }
                s32 flag = *(s32*)(this_ + 0x198);
                if (((u32)(flag == 0) & 0x10) != 0) {
                    pos.x += 3.5f - (s32)(flag & 7);
                    pos.y += 3.5f - (s32)(flag & 7);
                } else {
                    pos.x -= 3.5f - (s32)(flag & 7);
                    pos.y -= 3.5f - (s32)(flag & 7);
                }
                *(JGeometry::TVec3f*)(this_ + 0xC) = pos;
                *(s32*)(this_ + 4) = *(s32*)(target + 4);
                if (kind == 2) return 0x32;
                return 0xFF;
            }
            if (kind == 7 || kind == 2 || kind == 8) {
                *(s32*)(this_ + 0xB0) = *(s32*)(this_ + 0xB4);
            }
            *(s32*)(this_ + 0xA0) = -1;
            return 0;
        }
    }
    result = *(s32*)(this_ + 4);
    u8 (*mgr)[0x10000] = (u8 (*)[0x10000])fn_802D6A9C();
    if (mgr[1][result + 0x31df] == 0 && *(f32*)(this_ + 0x14) > 32.0f) return 0;
    id = fn_8023AC74((void*)id, *(s32*)(this_ + 4), (void*)out);
    if (id < 0) return 0;
    result = 0;
    other = (u8*)fn_8023B22C(id);
    other = (u8*)fn_801F666C(fn_801F856C(), (u32)other);
    if (!other) return 0;
    if (kind == 6) {
        f32 x = *(f32*)(this_ + 0xC) - *(f32*)(other + 0xC);
        f32 y = *(f32*)(this_ + 0x10) - *(f32*)(other + 0x10);
        out = 0;
        kind = 4;
        f32 angle = JMath::atanTable_.atan2_(-x, -y);
        handle = *(s32*)(this_ + 0x98);
        if ((handle ^ 1) != ClassifyBamAngleToQuadrant((u16)(s32)(angle * lbl_8053E5E0))) out = 1;
        if (other && *(s32*)(other + 0x254)) out = 1;
        if (!(u8)out) kind = 1;
        if (*(s32*)(this_ + 0xA4)) kind = 1;
    }
    if (id >= 0) lbl_8053A100 = id;
    ((SayaActor*)this_)->v44();
    switch (kind) {
    case 4:
        if (fn_801EAC20(this_ + 0x1DC, id)) fn_801F0E34(this_, 0x400D1, 0);
        if (other) *(s32*)(other + 0x254) = 1;
    case 1:
        *(s32*)(this_ + 0xD8) = 0;
        *(s32*)(this_ + 0xDC) = 0;
        result = 0xFF;
        if (kind != 1) break;
    case 5:
        if (*(f32*)(this_ + 0x14) == lbl_8053E5D4) {
            *(JGeometry::TVec3f*)(this_ + 0x3C) = JGeometry::TVec3f(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), lbl_8053E5E4 + (1.0f - lbl_8053E5E8 * lbl_8053AAF8->rnd.get_ufloat_1()));
            *(JGeometry::TVec3f*)(this_ + 0xC) = JGeometry::TVec3f(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14) + *(f32*)(this_ + 0x44));
        }
        fn_801F3780(this_, 0x12C);
        result = 0x32;
        fn_801F0E34(this_, 0x30021, 0);
        break;
    case 2:
        result = 0x32;
        *(s32*)(this_ + 0xA0) = fn_8023B22C(id);
        *(u32*)(this_ + 0xB4) = *(u32*)(this_ + 0xB0);
        *(u32*)(this_ + 0xB0) = 0x20000;
        ((SayaActor*)this_)->v40();
        break;
    case 7:
        result = 0xFF;
        if (*(u8*)(this_ + 0xC4)) break;
        *(s32*)(this_ + 0xA0) = fn_8023B22C(id);
        *(u32*)(this_ + 0xB4) = *(u32*)(this_ + 0xB0);
        *(u32*)(this_ + 0xB0) = 0x70000;
        ((SayaActor*)this_)->v40();
        break;
    case 8:
        if (other) {
            s32 player = *(u16*)(this_ + 0x94) - 1;
            s32 valid = 0;
            if ((u8)fn_8022F514((void*)id)) {
                if (player == fn_8022F3DC((void*)id)) valid = 1;
            } else {
                if (player == id) valid = 1;
            }
            if ((*(u16*)(this_ + 0x94) == 0 || valid == 1) && *(s32*)(other + 0x254) != 2) {
                *(s32*)(other + 0x254) = 2;
                *(s32*)(this_ + 0xA0) = fn_8023B22C(id);
                ((SayaActor*)this_)->v40();
                *(u32*)(this_ + 0xB4) = *(u32*)(this_ + 0xB0);
                *(u32*)(this_ + 0xB0) = 0x80000;
            }
        }
        result = 0xFF;
        break;
    case 3:
        *(s32*)(this_ + 0x10C) = id;
        fn_801F4694(this_);
        ((SayaActor*)this_)->v24();
        break;
    }
    return result;
}
#pragma dont_inline reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_lifetimes reset

// SAYA cluster, part 6/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A4754 (same external-entry-point pattern as
// fn_801A46FC). Return value is passed through to callers that check it.
extern "C" s32 fn_801A4D1C(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A4754((u8*)target, a4, a5);
}

extern "C" s32 fn_8023AC74(void* a, s32 room, void* b);
extern "C" s32 fn_8023B22C(s32 id);
extern "C" u8 fn_801EAC20(void* list, s32 idx);
extern "C" s32 fn_8022F514(void* a);
extern "C" s32 fn_8022F3DC(void* a);
extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_8023AA18(void* a, s32 room, void* b);
extern "C" s32 fn_8023B520(void);
extern "C" void* fn_8023E724(s32 player);
extern "C" void fn_801F37AC(void* this_, s32 a, void* pos, s32 b, s32 c, s32 d);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);

extern "C" s32 fn_801A4D74(u8* this_, void* a4, void* a5) {
    s32 room; u8* mgr; s32 t; s32 kind; s32 id;
    kind = (*(u32*)(this_ + 0xB0) >> 8) & 0xF;
    if (kind == 0) {
        return 0;
    }
    room = *(s32*)(this_ + 4);
    mgr = fn_802D6A9C();
    if (mgr[room + 0x131DF] == 0 && *(f32*)(this_ + 0x14) > 32.0f) {
        return 0;
    }
    id = fn_8023AA18(a4, *(s32*)(this_ + 4), a5);
    if (id < 0) {
        return 0;
    }
    if (kind != 3) {
        if (*(s32*)(this_ + 0xD8) == 0) {
            t = *(s32*)(this_ + 0x108);
            s32 d = t - fn_8023B520();
            *(s32*)(this_ + 0x10C) = id;
            if (d <= 0) {
                d = 0;
                if (*(s32*)(this_ + 0xBC) != 3) {
                    Saya_setTarget(this_, id);
                    return 0x28;
                }
            }
            *(s32*)(this_ + 0x108) = d;
            fn_801F37AC(this_, 0, fn_8023E724(id), 0, 4, -1);
            if (*(s32*)(this_ + 0xBC) == 3) {
                *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
            }
            if (id >= 0) {
                lbl_8053A100 = id;
            }
            ((SayaActor*)this_)->v44();
        }
    } else {
        return 0xFF;
    }
    fn_801F0E34(this_, 0x4001E, 0);
    return 0x1E;
}

// from src/Game/Saya_ForceState3_801A4F5C.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A4D74(u8* this_, void* a4, void* a5);

// SAYA cluster, part 8/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A4D74 (same external-entry-point pattern). Return
// value is passed through to callers that check it.
#pragma dont_inline on
extern "C" s32 fn_801A4F5C(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A4D74((u8*)target, a4, a5);
}
#pragma dont_inline reset

extern "C" u8 fn_8023F264(s32 player);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" u8 fn_8023A51C(s32 player);
extern "C" s32 fn_8023725C(s32 player);
extern "C" f32* fn_8023A478(s32 player);
extern "C" void fn_801F3780(void* this_, s32 a);

extern "C" s32 fn_801A4FB4(u8* this_) {
    s32 room;
    s32 i;
    f32 vz;
    s32 mode = (*(u32*)(this_ + 0xB0) >> 12) & 0xF;
    if (mode == 0) {
        return 0;
    }
    if (*(u8*)(this_ + 0xD4) == 0) {
        f32 range = 0.0f;
        for (i = 0; i < 4; i++) {
            if (!fn_8023F264(i)) {
                continue;
            }
            room = *(s32*)(this_ + 4);
            if (room == fn_8023DE58(i) && fn_8023A51C(i) && *(f32*)(this_ + 0x14) == lbl_8053E5D4) {
                if (fn_8023725C(i) == 1) {
                    range = 50.0f;
                } else if (fn_8023725C(i) == 2) {
                    range = 777.0f;
                }
                if (range > 0.0f) {
                    f32 dx = fn_8023A478(i)[0] - *(f32*)(this_ + 0xC);
                    f32 dy = fn_8023A478(i)[1] - *(f32*)(this_ + 0x10);
                    f32 d = std::sqrtf(dx * dx + dy * dy);
                    if (d < range || range == 777.0f) {
                        *(u8*)(this_ + 0xD4) = 1;
                        if (i >= 0) {
                            lbl_8053A100 = i;
                        }
                        ((SayaActor*)this_)->v44();
                    }
                }
            }
        }
    }
    vz = 0.0f;
    if (*(u8*)(this_ + 0xD4) == 1) {
        switch (mode) {
        case 1:
            vz = 5.0f + lbl_8053AAF8->rnd.get_sfloat_1();
            break;
        case 2:
            vz = 2.0f + lbl_8053AAF8->rnd.get_sfloat_1();
            break;
        case 3:
            if (*(s32*)(this_ + 0x108) - 10 <= 0) {
                *(s32*)(this_ + 0x108) = 0;
            }
            *(u8*)(this_ + 0xD4) = 0;
            break;
        }
        *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), vz);
        *(u8*)(this_ + 0xD4) = 2;
    }
    if (*(u8*)(this_ + 0xD4) == 2) {
        *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14) + *(f32*)(this_ + 0x44));
        *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), *(f32*)(this_ + 0x44) - 0.5f);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), 0.0f);
            *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), 0.0f);
            *(u8*)(this_ + 0xD4) = 0;
            if ((s32)((*(u32*)(this_ + 0xB0) >> 16) & 0xFF) == 1) {
                fn_801F3780(this_, 0x12C);
            }
        }
    }
    return *(u8*)(this_ + 0xD4);
}

#pragma opt_common_subs off
#pragma dont_inline reset
extern "C" s32 fn_801A5400(void* this_, void* a4, void* a5) {
 int kind;
 int id=(int)a4;
 int result;
 u8* other;
 u8* self=(u8*)this_;
 if((*(u32*)(self+0xb0)&255)==0) return 0;
 result=0;
 id=fn_8023AE34((void*)id,*(s32*)(self+4),a5);
 s32 room=*(s32*)(self+4);
 u8 (*mgr)[0x10000]=(u8 (*)[0x10000])fn_802D6A9C();
 if(mgr[1][room+0x31df]==0&&*(f32*)(self+0x14)>32.0f) return 0;
 if(*(s32*)(self+0xa0)<0) {
  if(id<0) return 0;
  kind=*(u32*)(self+0xb0)&255;
  if(kind!=3) {
   *(s32*)(self+0xa0)=fn_8023B2B0(id);
   other=(u8*)fn_801F666C(fn_801F856C(),*(u32*)(self+0xa0));
  } else {s32 h=fn_8023B2B0(id);other=(u8*)fn_801F666C(fn_801F856C(),h);}
  if(!other) {*(s32*)(self+0xa0)=-1;return 0;}
  if(*(s32*)(other+0x108)==0) {*(s32*)(self+0xa0)=-1;return 0;}
  *(s32*)(self+0x10c)=id;
  if(kind==9) {
   kind=4;
   f32 x=*(f32*)(self+0xc)-((f32*)fn_8023E724(id))[0];
   f32 y=*(f32*)(self+0x10)-((f32*)fn_8023E724(id))[1];
   f32 angle=JMath::atanTable_.atan2_(-x,-y);
   s32 dir=*(s32*)(self+0x98);
   if(dir!=ClassifyBamAngleToQuadrant((u16)(s32)(angle*lbl_8053E5E0))) kind=5;
   if(*(s32*)(self+0xa4)) kind=5;
  }
  if(kind==16) {
   f32 x=*(f32*)(self+0xc)-((f32*)fn_8023E724(id))[0];
   f32 y=*(f32*)(self+0x10)-((f32*)fn_8023E724(id))[1];
   f32 angle=JMath::atanTable_.atan2_(-x,-y);
   s32 dir=*(s32*)(self+0x98);
   if(dir!=ClassifyBamAngleToQuadrant((u16)(s32)(angle*lbl_8053E5E0))) kind=4;
  }
  u16 status=*(u16*)(other+0x94);
  if(status!=0&&status!=4) {
   if(kind==1||kind==8) kind=2;
   if(kind==10||kind==17) {*(s32*)(self+0xa0)=-1;return 0;}
  }
  if(kind==11&&*(s32*)(self+0xac)>=3) kind=4;
  switch(kind) {
  case 1:
   ++*(s32*)(other+0x270);*(s32*)(self+0xd8)=0;*(s32*)(self+0xdc)=0;*(s32*)(self+0x10c)=id;
  case 8:
   if(self[0xc4]) {*(s32*)(self+0xa0)=-1;result=255;break;}
   if(kind==8&&(*(f32*)(self+0x14)!=lbl_8053E5D4||*(f32*)(self+0x44)!=lbl_8053E5D4)) {*(s32*)(self+0xa0)=-1;result=255;break;}
   *(JGeometry::TVec3f*)(self+0x24)=JGeometry::TVec3f(*(f32*)(self+0xc)-*(f32*)(other+0xc),*(f32*)(self+0x10)-*(f32*)(other+0x10),*(f32*)(self+0x14)-*(f32*)(other+0x14));
   if(kind==8) break;
  case 0: case 9: default:
   if((*(u32*)(other+0x98)&2)==0) *(JGeometry::TVec3f*)(self+0x48)=JGeometry::TVec3f(0.5f,1.4f,0.0f);
   else *(JGeometry::TVec3f*)(self+0x48)=JGeometry::TVec3f(1.4f,0.5f,0.0f);
   break;
  case 16:
   {s32 hp=*(s32*)(self+0x108); *(s32*)(self+0x108)=hp-fn_8023B5B4(id);}
   if(*(s32*)(self+0x108)<1000) {
    switch(*(s32*)(other+0x98)) {case 0:{s32 r=*(s32*)(other+4);f32 scale=((f32(*)(void*))fn_801EE4F0)(self);fn_8013CC50(r,self+0xc,375,1,1,0,0,1,scale);break;}case 1:{s32 r=*(s32*)(other+4);f32 scale=((f32(*)(void*))fn_801EE4F0)(self);fn_8013CC50(r,self+0xc,374,1,1,0,0,1,scale);break;}case 2:{s32 r=*(s32*)(other+4);f32 scale=((f32(*)(void*))fn_801EE4F0)(self);fn_8013CC50(r,self+0xc,373,1,1,0,0,1,scale);break;}case 3:{s32 r=*(s32*)(other+4);f32 scale=((f32(*)(void*))fn_801EE4F0)(self);fn_8013CC50(r,self+0xc,376,1,1,0,0,1,scale);break;}}
   }
  case 2:
   if(self[0xc4]) {result=255;break;}
   if(kind!=16) {
    s32 hp=*(s32*)(self+0x108);s32 remaining=hp-fn_8023B5B4(id);
    if(remaining<=0) {*(s32*)(self+0x108)=0;result=20;other[0x11c]=0;break;}
    *(s32*)(self+0x108)=remaining;
   }
  case 5:
  case 11: case 15: case 18:
   if(kind==11) ++*(s32*)(self+0xac);
   other[0x11c]=0;
   if(kind==5||kind==16||kind==11||kind==18||kind==15) {
    s32 h=Actor_CreateByID(fn_801F856C(),0x4f4b544d,*(s32*)(other+4),other+0xc,1,-1,-1);
    if(h>=0) {
     u8* spawned=(u8*)fn_801F666C(fn_801F856C(),h);
     if(spawned&&*(s32*)(spawned+0x230)!=4) {
      s32 heading=fn_801F6874(*(s32*)(self+0x98));
      f32 x=0.8f*(*(f32*)(self+0xc)-*(f32*)(spawned+0xc));
      f32 y=0.8f*(*(f32*)(self+0x10)-*(f32*)(spawned+0x10));
      f32 magnitude=x*x+y*y; *(f32*)(spawned+0x254)=std::sqrtf(magnitude);
      u16 angle=(s32)(JMath::atanTable_.atan2_(-x,-y)*lbl_8053E5E0);
      u16 goal=fn_801F6874(*(s32*)(other+0x98))+0x8000;
      while(ClassifyBamAngleToQuadrant(angle)!=ClassifyBamAngleToQuadrant(goal)) fn_801F714C(&angle,goal,1,0x1000);
      s32 delta=heading-angle;
      if(kind==15) *(s32*)(spawned+0x230)=5;
      else if(kind==16||kind==18) *(s32*)(spawned+0x230)=6;
      else *(s32*)(spawned+0x230)=4;
      *(s32*)(spawned+0x258)=*(s32*)(self+0x198);
      *(s16*)(spawned+0x25c)=delta;
     }
    }
   }
   *(s32*)(self+0xa0)=-1;result=10;*(s32*)(self+0xd8)=0;*(s32*)(self+0xdc)=0;
   if(kind==15) result=255;
   break;
  case 10:result=255;break;
  case 17:result=10;break;
  case 6:
   fn_8013CC50(*(s32*)(other+4),other+0xc,0x117,0,1,0,0,1,1.0f);
   fn_8013CC50(*(s32*)(other+4),other+0xc,0x118,0,1,0,0,1,1.0f);
   *(s32*)(self+0x230)=1;
  case 4:
   for(s32 i=0;i<4;i++) {
    s32 h=fn_8023B2B0(i);
    if(h>=0) {other=(u8*)fn_801F666C(fn_801F856C(),h);if(other) *(s32*)(other+0x108)=0;}
   }
   *(s32*)(self+0xa0)=-1;
  case 3:result=255;break;
  case 7:
   self[0x11c]=0;
  case 14:
   *(s32*)(self+0xa0)=-1;
   fn_8013CC50(*(s32*)(other+4),other+0xc,0x24a,0,1,0,0,1,1.0f);
   fn_8013CC50(*(s32*)(other+4),other+0xc,0x24b,0,1,0,0,1,1.0f);
   other[0x11c]=0;result=255;break;
  case 12:
   if(status==1) *(u16*)(other+0x94)=2;
   if(*(u16*)(other+0x94)==0) *(u16*)(other+0x94)=4;
   *(s32*)(self+0xa0)=-1;result=255;break;
  case 13:
   if(status==2||status==4) *(u16*)(self+0x94)=1;
   *(s32*)(self+0xa0)=-1;result=255;break;
  }
  if(id>=0) lbl_8053A100=id;
  if(kind!=4&&kind!=8) ((SayaActor*)self)->v44();
  if(result) {
   if(kind==1||kind==2||kind==5||kind==16) {
    JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(self+0xc));
    JMathInlineVEC::PSVECSubtract(&pos,(Vec*)(other+0x3c),&pos);
    fn_801F37AC(self,0,&pos,0,3,-1);
    if(*(s32*)(self+0xbc)==3||kind==5) *(JGeometry::TVec3f*)(self+0x3c)=JGeometry::TVec3f(0.0f,0.0f,0.0f);
   }
   return result;
  }
 }
 s32 handle=*(s32*)(self+0xa0);
 if(handle>=0) {
  u8* target=(u8*)fn_801F666C(fn_801F856C(),handle);
  if(target) {
   if(*(u32*)(target+0x1a0)==0x41525257) {
    result=10;
    switch(*(u32*)(self+0xb0)&255) {
    case 10:case 17: {
     JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(target+0xc));
     if(id>=0) lbl_8053A100=id;
     s32 flag=*(s32*)(self+0x198);
     if(((u32)(flag==0)&16)!=0) {pos.x+=3.5f-(s32)(flag&7);pos.y+=3.5f-(s32)(flag&7);}
     else {pos.x-=3.5f-(s32)(flag&7);pos.y-=3.5f-(s32)(flag&7);}
     *(JGeometry::TVec3f*)(self+0xc)=pos;
     *(s32*)(self+4)=*(s32*)(target+4);
     ((SayaActor*)self)->v44();break;
    }
    case 8:
     if(self[0xc4]||*(f32*)(self+0x14)!=lbl_8053E5D4||*(f32*)(self+0x44)!=lbl_8053E5D4) {*(s32*)(self+0xa0)=-1;result=255;break;}
     if(*(s32*)(target+0x26c)==1) {*(s32*)(self+0xa0)=-1;*(s32*)(self+0x108)=0;*(s32*)(self+0xb0)=0;}
     {*(JGeometry::TVec3f*)(self+0xc)=*(JGeometry::TVec3f*)(target+0xc)+*(JGeometry::TVec3f*)(self+0x24);}
     *(s32*)(self+4)=*(s32*)(target+4);
     ((SayaActor*)self)->v44();
     if(*(s32*)(target+0x26c)==2) {((SayaActor*)self)->v24();result=20;}break;
    case 1:
     {*(JGeometry::TVec3f*)(self+0xc)=*(JGeometry::TVec3f*)(target+0xc)+*(JGeometry::TVec3f*)(self+0x24);}
     *(s32*)(self+4)=*(s32*)(target+4);
     if(*(s32*)(target+0x26c)==2) {((SayaActor*)self)->v24();result=20;}break;
    default:break;
    }
   }
  } else {
   switch(*(u32*)(self+0xb0)&255) {
   case 8:*(s32*)(self+0x108)=0;*(s32*)(self+0xb0)=0;
   case 10:case 17:break;
   default:((SayaActor*)self)->v24();break;
   }
   *(s32*)(self+0xa0)=-1;result=20;
  }
 }
 return result;
}
#pragma dont_inline reset
#pragma opt_common_subs reset

// from src/Game/Saya_ForceState4_801A6108.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);


// SAYA cluster, part 11/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A5400 (same external-entry-point pattern). Return
// value is passed through to callers that check it.
extern "C" s32 fn_801A6108(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A5400(target, a4, a5);
}

static u8 lbl_804C6640[0x30];

extern "C" f32 fn_801EE4F0(void);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" u8 fn_802242F4(void* this_);
extern "C" u8 fn_801F305C(void* this_);
extern "C" void fn_801F2618(void* this_, s32 a, s32 b);

struct SayaOfs;
struct SayaBox {
    inline void add(const SayaOfs& o);
    f32 x0, y0, x1, y1;
};
struct SayaOfs {
    SayaOfs(f32 ax, f32 ay) { x = ax; y = ay; }
    f32 x, y;
};
inline void SayaBox::add(const SayaOfs& o) {
    x0 += o.x;
    y0 += o.y;
    x1 += o.x;
    y1 += o.y;
}

// SAYA update
extern "C" s32 fn_801A6160(u8* this_) {
    s32 cnt;
    s32 res = 0;
    SayaBox box;
    box.x0 = ((SayaBox*)(this_ + 0x70))->x0;
    box.y0 = ((SayaBox*)(this_ + 0x70))->y0;
    box.x1 = ((SayaBox*)(this_ + 0x70))->x1;
    box.y1 = ((SayaBox*)(this_ + 0x70))->y1;
    SayaOfs ofs(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14));
    cnt = *(s32*)(this_ + 0xA8);
    if (cnt != 0) {
        if (cnt == 0x1E) {
            f32 sc = fn_801EE4F0();
            if (sc < 1.0f) {
                sc = 1.0f;
            }
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xC, 0x17C, 0, 1, 0, 0, 1, sc);
        }
        if (cnt - 1 <= 0) {
            ((SayaActor*)this_)->v24();
        }
        *(s32*)(this_ + 0xA8) = cnt - 1;
        return 1;
    }
    if (*(s32*)(this_ + 0x108) > 0 && fn_802242F4(this_)) {
        return 1;
    }
    if (*(u32*)(this_ + 0xB0) == 0 || *(s32*)(this_ + 0x108) <= 0) {
        return 0;
    }
    lbl_8053A100 = -1;
    box.add(ofs);
    s32 r;
    if ((r = fn_801A5400(this_, &box, &ofs)) != 0) {
        res = 3;
    } else if ((r = fn_801A4D74(this_, &box, &ofs)) != 0) {
        res = 3;
    } else if ((r = fn_801A4754(this_, &box, &ofs)) != 0) {
        res = 1;
    } else if ((r = fn_801A41D8(this_, &box, &ofs)) == 0x32) {
        res = 1;
    }
    if (r == 0xFF) {
        return 0;
    }
    if (res <= 1 && fn_801A4FB4(this_)) {
        res = 2;
    }
    s32 a4 = *(s32*)(this_ + 0xA4);
    if (a4 != 0) {
        if (*(f32*)(this_ + 0x14) > 0.0f) {
            *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), 0.0f);
            *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14) - 1.0f);
        } else {
            *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), 0.0f);
        }
        *(s32*)(this_ + 0xA4) = a4 - 1;
        res = 1;
        if (fn_801F305C(this_)) {
            if (*(s32*)(this_ + 0xBC) == 3) {
                *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
            }
            res = 2;
            fn_801F2618(this_, 0, 0);
        }
    }
    if (res > 1) {
        *(s32*)(this_ + 0xA4) = 0;
    }
    return res;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
