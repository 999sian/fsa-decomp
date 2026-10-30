// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8015C828-8015DE10 (KETH). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"

// from src/Game/fn_8015C828_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A02B8[];

extern "C" void* fn_8015C828(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A02B8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_8015C888.cpp
extern "C" s32 fn_802265DC(void* targetPos, void* arg1, s32 zero);

// fn_8015C888 - KETH's ("Keese") override of the base Actor vtable's
// slot 19 ("can I move this way" query, per
// project_fsa_actor_system_discovery.md and
// project_fsa_zlda_actor_progress.md, where it's called via a genuine
// virtual dispatch in update()). A thin forwarder: fn_802265DC(targetPos,
// arg1, 0) - not itself decompiled, but the fixed 0 second argument (vs
// whatever the base default passes) is consistent with Keese's erratic
// flight ignoring the normal terrain/ground movement constraint most
// grounded actors check.
extern "C" s32 fn_8015C888(void* this_, void* arg1, void* targetPos) {
    return fn_802265DC(targetPos, arg1, 0);
}

struct KethRandom {
    u32 seed;
    u32 get() {
        seed = seed * 0x19660d + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct KethGame { u8 pad[0xb4]; KethRandom rnd; };
extern KethGame* lbl_8053AAF8;

static inline f32 kethRandFrom(void* __restrict game, int multiplier = 0x19660d) {
    unsigned int* base = (unsigned int*)game;
    union { f32 f; u32 s; } out;
    base[45] = base[45] * multiplier + 0x3c6ef35f;
    out.s = (base[45] >> 9) | 0x3f800000;
    return out.f - 1.0f;
}

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801F06F0(void* actor, const char* res, u32 id, DrawRec* rec, s32 a, f32 sx, f32 sy);
extern "C" void fn_801F02BC(void* actor, const char* res, u32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 sx, f32 sy);
extern "C" void fn_803075AC(void* a, s32 room, void* pos, s32 id, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern const char lbl_804660F8[];

struct KethVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 isVisible();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual u8 canMove(s32 room, void* pos);
};

static inline f32 ksin(f32 x) { return sin(x); }
static inline f32 kcos(f32 x) { return cos(x); }
static inline void kethRotMtx(f32 m[3][4], f32 ax, f32 ay, f32 az, f32 s) {
    f32 cx;
    f32 sx = ksin(ax);
    f32 sy = ksin(ay);
    f32 sz = ksin(az);
    cx = kcos(ax);
    f32 cy = kcos(ay);
    f32 cz = kcos(az);
    f32 cc = cx * cz;
    f32 ss = sx * sy;
    f32 cs = cx * sz;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (ss * cz - cs);
    m[1][1] = s * (ss * sz + cc);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cc * sy + sx * sz);
    m[1][2] = s * (cs * sy - sx * cz);
    m[2][2] = s * (cx * cy);
}

// KETH draw (vtable slot 6)
extern "C" void fn_8015C8B0(char* this_) {
    if ((*(u32*)(this_ + 0x90) >> 27) && !((KethVT*)this_)->isVisible()) return;
    DrawRec rec;
    f32 mtx[3][4];
    f32 zero = 0.0f;
    mtx[0][3] = zero; mtx[1][3] = zero; mtx[2][3] = zero;
    if (*(s32*)(this_ + 0x264) == 1) return;
    rec.w30 = *(s32*)(this_ + 0x150);
    kethRotMtx(mtx, zero, (f32)*(u16*)(this_ + 0x25c) / -10430.228f, zero, 1.0f);
    rec.w18 = mtx;
    s32 big = 0;
    if (*(s32*)(this_ + 0x260) != 0) big = 1;
    if (*(s32*)(this_ + 4) == 8 && *(s32*)(this_ + 0x260) != 0) {
        kethRotMtx(mtx, zero, (f32)*(u16*)(this_ + 0x25c) / -10430.228f, zero, 2.0f);
        rec.w18 = mtx;
        fn_801F06F0(this_, lbl_804660F8, *(s32*)(this_ + 0x258) + 0x155, &rec, -1, 1.0f, 1.0f);
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, 0x176, 0, 2, -1, 0, 0, 0);
    } else {
        fn_801F02BC(this_, lbl_804660F8, *(s32*)(this_ + 0x258) + 0x155, &rec, -1, big, 0, 1.0f, 1.0f);
    }
}

extern "C" u16 fn_80226998(void* pos, s32 room);
extern "C" char* fn_802D6A9C();
extern "C" u8 fn_802DCD0C();
extern "C" s32 fn_801F3D94(void*, s32);
extern "C" u8 fn_801F2FAC(void*);
extern "C" void* fn_801F856C();
extern "C" void* Actor_CreateByID(void*, u32, s32, void*, s32, s32, s32);
extern "C" u16 fn_8022461C(void*, s32);
extern "C" s32 fn_801F2718(void*, u32);
extern "C" char* fn_801F666C(void*, s32);
extern "C" u8 fn_801F2DB4(void*, u32, u32, s32);
extern "C" void fn_801EEC98(void*, void*, u16*, s32*, f32*, s32*, s32, s32);
extern "C" void fn_801F71A4(f32*, f32, f32, f32);
extern "C" void fn_801F2B7C(void*, s32, s32, s32);
extern "C" void fn_801F714C(u16*, u16, s32, s32);
extern "C" f32* fn_8023E724(s32);
extern "C" void fn_801F0E34(void*, u32, s32);
extern "C" double fabs(double);
extern f32 sincosTable___5JMath[];
extern "C" void fn_8015CCF8(char* this_) {
    s32 room;
    u8 changed;
    if (*(u32*)(this_ + 0x90) >> 27) {
        if (!((KethVT*)this_)->isVisible()) return;
        *(u32*)(this_ + 0xb0) = 0x31201;
    }
    if (*(s32*)(this_ + 0x264) == 1) {
        if (*(u16*)(this_ + 0x26a) == 0xffff) {
            fn_802D6A9C();
            if (!fn_802DCD0C()) {
                JGeometry::TVec2<f32> pos;
                s32 room = *(s32*)(this_ + 4);
                pos.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
                *(u16*)(this_ + 0x26a) = fn_80226998(&pos, room);
            }
            return;
        }
        JGeometry::TVec2<f32> pos;
        s32 room = *(s32*)(this_ + 4);
                pos.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
        if (*(u16*)(this_ + 0x26a) == fn_80226998(&pos, room)) return;
        *(s32*)(this_ + 0x264) = 0;
    }
    if (fn_801F3D94(this_, 1)) return;
    if (fn_801F2FAC(this_)) {
        if (*(u8*)(this_ + 0x25e) == 1 && kethRandFrom(lbl_8053AAF8) < 0.5f)
            Actor_CreateByID(fn_801F856C(), 'HART', *(s32*)(this_ + 4), this_ + 0xc, 0, -1, -1);
        return;
    }
    if ((int)fn_8022461C(this_ + 0xc, *(s32*)(this_ + 4)) == 0x3b) {
        ((KethVT*)this_)->v7();
        return;
    }
    room = fn_801F2718(this_, 'BMTY');
    if (room >= 0) {
        char* other = fn_801F666C(fn_801F856C(), room);
        if (other && *(u32*)(other + 0x1a0) == 'BMTY' && (u8)(*(s32*)(other + 0x230) == 3) == 1)
            room = -1;
    }
    if (room < 0 && fn_801F2DB4(this_, 'NULL', 'NULL', 0)) {
        if (*(u8*)(this_ + 0x25e) == 1 && kethRandFrom(lbl_8053AAF8) < 0.5f)
            Actor_CreateByID(fn_801F856C(), 'HART', *(s32*)(this_ + 4), this_ + 0xc, 0, -1, -1);
        return;
    }
    f32 distance;
    s32 index;
    s32 player;
    u16 angle;
    angle = 0;
    distance = 0.0f;
    index = 0;
    player = -1;
    fn_801EEC98(this_, *(void**)(this_ + 0x198), &angle, &index, &distance, &player, 0, 0);
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x274), 0.3f, 1.0f);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x278), 0.3f, 1.0f);
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    fn_801F2B7C(this_, -100, -1, 1);
    switch (*(s32*)(this_ + 0x230)) {
    case 0: {
        changed = 0;
        if (*(s32*)(this_ + 0x264) == 3) {
            if (*(s32*)(this_ + 0x24c) == 0)
                *(f32*)(this_ + 0x274) = 1.2f * sincosTable___5JMath[((u16)*(s32*)(this_ + 0x250) >> 5) * 2];
            else
                *(f32*)(this_ + 0x278) = 1.2f * sincosTable___5JMath[((u16)*(s32*)(this_ + 0x250) >> 5) * 2 + 1];
            *(s32*)(this_ + 0x250) += *(s32*)(this_ + 0x254);
            if (*(s32*)(this_ + 0x234) <= 0) {
                ++*(s32*)(this_ + 0x258);
                if (*(s32*)(this_ + 0x258) > 2) *(s32*)(this_ + 0x258) = 0;
                *(s32*)(this_ + 0x234) = 6;
            }
        }
        room = *(s32*)(this_ + 4);
        if (((u8*)(fn_802D6A9C() + 0x131df))[room] == 0 && *(u8*)(this_ + 0x25e) == 0) {
            if (*(s32*)(this_ + 0x238) == 0 && index >= 0 && distance < 60.0f) {
                *(u16*)(this_ + 0x268) = angle + 0x8000;
                changed = 1;
                *(s32*)(this_ + 0x238) = (s32)(50.0f * kethRandFrom(lbl_8053AAF8)) + 50;
                *(s32*)(this_ + 0x230) = 1;
            }
        } else {
            fn_801F714C((u16*)(this_ + 0x25c), 0x8000, 1, 0x3000);
            if (*(s32*)(this_ + 0x238) == 0 && index >= 0 &&
                (f32)fabs(*(f32*)(this_ + 0xc) - fn_8023E724(player)[0]) < 64.0f &&
                *(f32*)(this_ + 0x10) < fn_8023E724(player)[1] &&
                (f32)fabs(*(f32*)(this_ + 0x10) - fn_8023E724(player)[1]) < 128.0f) {
                changed = 1;
                *(s32*)(this_ + 0x238) = (s32)(10.0f * kethRandFrom(lbl_8053AAF8)) + 10;
                if (*(f32*)(this_ + 0xc) > fn_8023E724(player)[0]) {
                    *(s32*)(this_ + 0x244) = (s32)(4096.0f * kethRandFrom(lbl_8053AAF8)) + 0x1000;
                    *(u16*)(this_ + 0x25c) = 0x8000;
                } else {
                    *(s32*)(this_ + 0x244) = 0xf000 - (s32)(4096.0f * kethRandFrom(lbl_8053AAF8));
                    *(u16*)(this_ + 0x25c) = 0x8001;
                }
                *(f32*)(this_ + 0x26c) = fn_8023E724(player)[1] - 32.0f;
                *(s32*)(this_ + 0x23c) = (s32)(50.0f * kethRandFrom(lbl_8053AAF8)) + 50;
                *(s32*)(this_ + 0x230) = 2;
            }
        }
        if (changed == 1) {
            fn_801F0E34(this_, 0x4000f, 0);
            fn_801F0E34(this_, 0x400a9, 0);
        }
        break;
    }
    case 1:
        *(f32*)(this_ + 0x274) = 0.7f * sincosTable___5JMath[(((u32)*(u16*)(this_ + 0x268) >> 5) & 0x7ff)*2];
        *(f32*)(this_ + 0x278) = 0.7f * sincosTable___5JMath[(((u32)*(u16*)(this_ + 0x268) >> 5) & 0x7ff)*2+1];
        if (index != -1) fn_801F714C((u16*)(this_ + 0x268), angle, 1, 0x300);
        if (*(s32*)(this_ + 0x234) <= 0) {
            ++*(s32*)(this_ + 0x258);
            if (*(s32*)(this_ + 0x258) > 2) *(s32*)(this_ + 0x258) = 0;
            *(s32*)(this_ + 0x234) = 6;
            if (*(s32*)(this_ + 0x238) == 0 && *(s32*)(this_ + 0x258) == 2 &&
                !((KethVT*)this_)->canMove(*(s32*)(this_ + 4), this_ + 0xc)) {
                *(s32*)(this_ + 0x238) = (s32)(20.0f * kethRandFrom(lbl_8053AAF8)) + 20;
                *(f32*)(this_ + 0x274) = 0.0f;
                *(f32*)(this_ + 0x278) = 0.0f;
                *(f32*)(this_ + 0x27c) = 0.0f;
                *(s32*)(this_ + 0x230) = 0;
            }
        }
        break;
    case 2:
        if (*(s32*)(this_ + 0x238) == 0) {
            u16 target = *(s32*)(this_ + 0x244);
            if (*(s32*)(this_ + 0x248) == 0 && *(f32*)(this_ + 0x10) > *(f32*)(this_ + 0x26c))
                *(s32*)(this_ + 0x248) = 1;
            if (*(s32*)(this_ + 0x248)) {
                fn_801F714C((u16*)(this_ + 0x25c), target, 1, 0x200);
                *(f32*)(this_ + 0x274) = sincosTable___5JMath[((u16)(*(u16*)(this_ + 0x25c)-0x8000) >> 5)*2];
                *(f32*)(this_ + 0x278) = sincosTable___5JMath[((u16)(*(u16*)(this_ + 0x25c)-0x8000) >> 5)*2+1];
            } else {
                *(f32*)(this_ + 0x274) = 1.5f * sincosTable___5JMath[((u16)(*(u16*)(this_ + 0x25c)-0x8000) >> 5)*2];
                *(f32*)(this_ + 0x278) = 1.5f * sincosTable___5JMath[((u16)(*(u16*)(this_ + 0x25c)-0x8000) >> 5)*2+1];
            }
        }
        if (*(s32*)(this_ + 0x238) == 0 && *(s32*)(this_ + 0x234) <= 0) {
            ++*(s32*)(this_ + 0x258);
            if (*(s32*)(this_ + 0x258) > 2) *(s32*)(this_ + 0x258) = 0;
            *(s32*)(this_ + 0x234) = 6;
        }
        if (*(s32*)(this_ + 0x23c) == 0 && ((KethVT*)this_)->canMove(*(s32*)(this_ + 4), this_ + 0xc) == 1) {
            *(s32*)(this_ + 0x238) = (s32)(20.0f * kethRandFrom(lbl_8053AAF8)) + 20;
            *(f32*)(this_ + 0x274) = 0.0f;
            *(f32*)(this_ + 0x278) = 0.0f;
            *(f32*)(this_ + 0x27c) = 0.0f;
            *(s32*)(this_ + 0x258) = 2;
            *(s32*)(this_ + 0x248) = 0;
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    case 3: {
        fn_801F71A4((f32*)(this_ + 0x26c), *(f32*)(this_ + 0x270), 0.3f, 0.5f);
        u32 a = (u16)(*(u16*)(this_ + 0x268) + *(s32*)(this_ + 0x244));
        const f32* table = sincosTable___5JMath;
        f32 sx = *(f32*)(this_ + 0x26c) * table[(a>>5)*2];
        f32 cy = *(f32*)(this_ + 0x26c) * table[(a>>5)*2+1];
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x280) + sx;
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x284) + cy;
        *(s32*)(this_ + 0x244) += 0x200;
        if (*(s32*)(this_ + 0x234) <= 0) {
            ++*(s32*)(this_ + 0x258);
            if (*(s32*)(this_ + 0x258) > 2) *(s32*)(this_ + 0x258) = 0;
            *(s32*)(this_ + 0x234) = 6;
        }
        break;
    }
    }
    if (*(s32*)(this_ + 0x234) > 0) --*(s32*)(this_ + 0x234);
    if (*(s32*)(this_ + 0x238) > 0) --*(s32*)(this_ + 0x238);
    if (*(s32*)(this_ + 0x23c) > 0) --*(s32*)(this_ + 0x23c);
}

// KETH init (vtable slot 1)
extern "C" void fn_8015D844(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = 0.0f;
    *(f32*)(this_ + 0x84) = 0.0f;
    *(f32*)(this_ + 0x88) = 0.0f;
    *(f32*)(this_ + 0x8c) = 0.0f;
    *(u32*)(this_ + 0x260) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    if (*(s32*)(this_ + 0x260) != 0) {
        *(f32*)(this_ + 0x60) = -12.0f;
        *(f32*)(this_ + 0x64) = -12.0f;
        *(f32*)(this_ + 0x68) = 12.0f;
        *(f32*)(this_ + 0x6c) = 12.0f;
        *(s32*)(this_ + 0xc0) = 2;
    }
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(u16*)(this_ + 0x25c) = 0;
    *(u8*)(this_ + 0x25e) = 0;
    if (*(u32*)(this_ + 0x90) & 0x100) {
        *(u8*)(this_ + 0x25e) = 1;
        *(u16*)(this_ + 0x25c) = 0x8000;
    }
    *(u32*)(this_ + 0x264) = *(u32*)(this_ + 0x90) & 0xf;
    if (*(s32*)(this_ + 0x264) == 3) {
        *(s32*)(this_ + 0x24c) = (s32)(1.99f * kethRandFrom(lbl_8053AAF8));
        if (kethRandFrom(lbl_8053AAF8) < 0.5f) {
            *(s32*)(this_ + 0x254) = -((s32)(512.0f * kethRandFrom(lbl_8053AAF8)) + 0x200);
        } else {
            *(s32*)(this_ + 0x254) = (s32)(512.0f * kethRandFrom(lbl_8053AAF8)) + 0x200;
        }
    }
    if (*(s32*)(this_ + 0x264) == 2) {
        *(f32*)(this_ + 0xc) += (f32)((s32)(9.0f * kethRandFrom(lbl_8053AAF8)) - 4);
        *(f32*)(this_ + 0x10) += (f32)((s32)(9.0f * kethRandFrom(lbl_8053AAF8)) - 4);
        *(JGeometry::TVec3<f32>*)(this_ + 0x24) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    }
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0x31201;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(f32*)(this_ + 0x27c) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(s32*)(this_ + 0x258) = 2;
    *(u16*)(this_ + 0x268) = 0;
    *(u16*)(this_ + 0x26a) = 0xffff;
    *(f32*)(this_ + 0x14) = 1.0f;
    if (*(u32*)(this_ + 0x90) >> 27) {
        *(u32*)(this_ + 0xb0) = 0;
    }
    if (*(s32*)(this_ + 0x264) == 4) {
        *(f32*)(this_ + 0x14) = 0.0f;
        *(s32*)(this_ + 0x230) = 3;
    } else {
        *(s32*)(this_ + 0x230) = 0;
    }
    *(f32*)(this_ + 0x280) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x14);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
