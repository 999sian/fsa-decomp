#include "Game/Actor.h"
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];


struct UnkBlob44 { u32 w[0x11]; };
extern "C" UnkBlob44 lbl_80469FC8;



class EffResMgr {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual u32 load(u32 a, void* b);
};

union EffWord {
    u32 w;
    u8 b[4];
};

struct EffArgs {
    u8 order[0x10];
    EffWord f10;
    EffWord f14;
    void* ptr;
    u8 b1c, b1d, b1e, b1f, b20, b21, b22, b23, b24, b25, b26;
    u8 pad0;
    u32 w28;
    u8 b2c, b2d, b2e;
    u8 pad1;
    u32 x30, x34, x38;
};

struct Rec {
    /* 0x00 */ u32 w00;
    /* 0x04 */ u32 w04;
    /* 0x08 */ u32 w08;
    /* 0x0c */ u32 w0c;
    /* 0x10 */ u32 w10;
    /* 0x14 */ u32 w14;
    /* 0x18 */ u32 w18;
    /* 0x1c */ u8  b1c;
    /* 0x1d */ u8  b1d;
    /* 0x1e */ u8  b1e;
    /* 0x1f */ u8  b1f;
    /* 0x20 */ u8  b20;
    /* 0x21 */ u8  b21;
    /* 0x22 */ u8  b22;
    /* 0x23 */ u8  b23;
    /* 0x24 */ u8  b24;
    /* 0x25 */ u8  b25;
    /* 0x26 */ u8  b26;
    /* 0x28 */ u32 w28;
    /* 0x2c */ u8  b2c;
    /* 0x2d */ u8  b2d;
    /* 0x2e */ u8  b2e;
    /* 0x30 */ u32 w30;
    /* 0x34 */ u32 w34;
    /* 0x38 */ u32 w38;
};

extern "C" {
void* fn_802D6A9C();                        /* returns the area/actor manager */
void fn_802D766C(void* mgr, u8 a, u32 b);
void fn_802D7704(void* mgr, s32 a, u8 b, u32 c);
void fn_802D7E04(void* mgr, u32 kind);
void* fn_802D800C(void* mgr, u32 kind);
void fn_802D8050(void* mgr, u32 kind, u32 a, u32 b);
u8 fn_802265DC(f32* b, int a, int c);
void* fn_8020D58C();
u8 fn_8020D6AC(void* entry, int a, f32* b, s32 d, int e);
void fn_801CB71C(void* a, void* b, int c, int d);
extern void* lbl_8053AAF8;
void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* a, void* p);
void* fn_8013C824();
void* fn_801F856C();
void fn_801F8448(void* mgr, Actor* a);
extern "C" void __construct_array(void* node, void (*cb)(), int c, int d, int e);
void fn_8003B2CC();
void fn_801EAD68(void* sub);
void fn_801F7F58(void* mgr, Actor* a, u32 b, u32 c, f32 d);
int fn_8023DE58(u32 x);
void fn_801F84C4(void* mgr, Actor* a);
u32 fn_801F2DB4(Actor* a, u32 b, u32 c, void* buf);
s32 fn_801F82CC(void* mgr, Actor* a, u8 c, f32 f);
Actor* fn_801F666C(void* mgr, s32 idx);
void fn_801CB538(u32 id, void* p, u32 a, u32 b);
u8 fn_801EAC54(void* sub, s32 v);
s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern f32 lbl_8053F774;
void fn_801F0E34(Actor* a, u32 code, u32 z);
s32 fn_801F285C(Actor* a, f32* b, u32* c, u32 e, s32 d);
void* fn_8023E724(u32 i);
u32 fn_8023B6CC(u32 i);
u32 fn_801F37AC(Actor* a, u32 x, void* p, u32 d, u32 buf, u32 i);
void fn_801CD150(void* src, f32* dst);
u8 fn_801F23BC(Actor* a, u32 id, void* f0C, void* f18, void* p80, f32* out1, f32* out2, u32 c);
u8 fn_8022E438(u32 i, s32 b);
u8 fn_8022D75C(u32 i);
u8 fn_8023B190(u32 i, f32* rect, u32 id);
u8 fn_8022BB48(u32 id, void* f0C);
u8 fn_8022BC38(u32 i, u32 id, void* f0C);
u8 fn_8030381C(u32 i);
void fn_803037D4(u32 i, u32 v);
void fn_80458880(void* mgr, u32 p, int v);
extern void* lbl_8053AF80;
u8 fn_80239B64(u32 i, f32* rect, u32 id, u32 p3, u32 p4, u32 p5);
u8 fn_8023F264(u32 i);
void fn_802397B4(void* rect, u32 id, s32 v);
float PSVECMag(void* vec);
u8 fn_8023B9CC(s32 d, f32* rect, u32 id, f32* out8, u32 e);
s32 fn_8023B8E4(f32* rect, u32 id, f32* out8);
u8 fn_8023B848(s32 d, f32* rect, u32 id, f32* out8);
s32 fn_8023B768(f32* rect, u32 id, f32* out8);
u8 fn_80233DA4(s32 r);
extern u32 lbl_80469F38[];
extern "C" f32 lbl_8046A00C[];
extern "C" f32 lbl_8053F748;
extern "C" void fn_801F8108(void* a, u32 b, u32 c, f32 d);
extern "C" void fn_802D7618(void* mgr, s32 id);
u16 fn_8022461C(s32 a, s32 b);
u16 fn_80226850(s32 a, s32 b);
s32 fn_801F7A6C(void* a);
s32 fn_802DE814();
void fn_801F52A4(Actor* a);
void fn_801CB434(u32 a, void* b, u32 c);
s32 fn_801F7A08(void* a, u32 b);
s32 fn_801CCDA4();
s32 fn_8022F340(u32 a);
void fn_8013C830(void* a, s32 b, s32 c);
u32 fn_8022F514(u32 a);
s32 fn_8022F3DC(u32 a);
s32 fn_802357E0(u32 a);
void fn_802359A4(u32 a, s32 b);
void fn_801F6718(void* a, u32 b, u32 c, void* d, s32 e, u32 f);
void fn_80235B68(u32 a, u32 b);
extern u8 lbl_80529DEC[];                  /* +0x118/+0x11C: two table indices */
extern u8 lbl_8050EC80[];                  /* array of 0xC8-byte records, flags at +0x28 */
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern "C" void fn_801CD0D0(f32* a, f32* b);
extern "C" void fn_80238548(u32 i, s32 b, f32* p, void* d);
extern "C" f32 lbl_8053F740;
extern "C" f32 lbl_8053F74C;
extern void* lbl_8053AB10;
void fn_802F86CC(void* a, void* b, void* c, u32 d, void* e, f32 f, f32 g);
u8 fn_80230188(s32 i);
u8 fn_8022DCD8(s32 i);
u8 fn_8022F478(s32 i);
u8 fn_80236B50(s32 i);
u8 fn_8022D534(s32 i);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" s32 fn_801F6874(u32 x);
extern "C" u8 lbl_8052EBC0[];
extern "C" f32 lbl_8053F73C;
extern "C" f32 lbl_8053F7A4;
extern f32 lbl_8053F740; /* 0.0 */
extern f32 lbl_8053F744; /* 512.0 */
extern f32 lbl_8053F74C; /* 0.5 */
extern f32 lbl_8053F750; /* 3.0 */
extern f32 lbl_80539D44[]; /* FLT_EPSILON */
extern "C" void* Registry_GetSlotValueOrFallback(void* a, u32 b);
extern "C" u8 fn_802D7804(void* mgr, u32 id, u32 flags);
extern "C" s32 fn_802D7948(void* mgr);
extern "C" s32 fn_80456334(void* a, void* b, u32 c);
extern f32 lbl_80539D44[];
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" u32 lbl_8053F728;
extern "C" u32 lbl_8053F72C;
extern "C" u32 lbl_80543F40;
extern "C" u32 lbl_80543F44;
extern "C" u32 lbl_80543F48;
extern "C" u32 lbl_80543F4C;
extern "C" f32 lbl_80469D48[];
extern "C" u32 lbl_80469D78[];
extern "C" f32 lbl_8053F7B0;
extern "C" f32 lbl_8053F7DC;
extern "C" f32 lbl_8053F7E0;
extern "C" f32 lbl_8053F7E4;
extern "C" f64 lbl_8053F788;
extern "C" f64 lbl_8053F798;
extern "C" u8 fn_801F172C(Actor* a, u32 id, Vec* p, void* lim, void* out2, u32 c);
s32 fn_802265FC(void* a, s32 b);
u8 fn_802DEB58();
void fn_802F745C(void* a, void* b, void* c, void* d);
void PSMTXScale(void* a, f32 b, f32 c, f32 d);
void PSMTXConcat(void* a, void* b, void* c);
extern u16 lbl_8053F730[4];
extern u8 lbl_8053F738[4];
extern f32 lbl_8053F778;
extern f32 lbl_8053F77C;
extern f32 lbl_8053F780;
extern f32 lbl_8053F784;
extern f32 lbl_80469FA8[8];
extern u8 lbl_8046A020[];
extern u8 lbl_8046A034[];
void fn_801F06F0(Actor* a, void* p2, void* p3, const void* p4, void* p5, f32 f6, f32 f7);
void fn_803075AC(u32 x, u32 y, void* v, void* p, int sign, int two, int minus1, u8 p7, u32 u, int zero);
void fn_80307AC8(u32 x, u32 y, void* v, void* p, int p6, u32 u, int minus1);
extern f32 lbl_8053F7A0;
}

/*
 * Actor base TU (retail 0x801EE24C-0x801F6058).
 *
 * Names that are not recoverable from call sites are left as the placeholder
 * v01..v18 / detach used by include/Game/Actor.h; the mapping to a retail
 * address is fixed by that header and by config/G4SE01/symbols.txt.
 *
 * The unit is NonMatching: the last 0x224 bytes (0x801F5E34) are the shared
 * per-TU __sinit chain owned by the ActorSinit slice and are not emitted here.
 */

/* Cross-TU helpers, still unnamed in the decomp (fn_* = retail address).  The
 * exact target symbol is irrelevant to matching because the project's objdiff
 * mask uses functionRelocDiffs=none, but the argument shape must reproduce the
 * caller's register setup. */

/* --- empty (blr) virtuals ------------------------------------------------- */

void Actor::v01() {}
void Actor::v02() {}
void Actor::v03() {}
void Actor::v06() {}
void Actor::v14() {}
void Actor::v15() {}
void Actor::v16() {}

/* --- slot 13: returns the top 5 bits of the status word (field_90) --------- */
int Actor::v13() {
    return field_90 >> 27;
}

/* --- slot 5: publishes the pending position (field_0C) as the live one ------
 * Retail copies the Vec with a paired-single load/store (xy as a pair, z as a
 * scalar); plain C++ struct assignment scalarises to 3x lfs/stfs with this
 * compiler, so the copy is written with the same inline PS asm idiom the repo
 * already uses in JMathInlineVEC. */
void Actor::v05() {
    register Actor* t = this;
    register f32 z, xy;
    // clang-format off
    __asm {
        psq_l  xy, 0xc(t),  0, 0
        lfs    z,  0x14(t)
        psq_st xy, 0x18(t), 0, 0
        stfs   z,  0x20(t)
    }
    // clang-format on
}

/* --- slot 12: notify the manager of this actor's kind ---------------------- */
void Actor::v12() {
    u32 kind = v13();
    void* mgr = fn_802D6A9C();
    fn_802D7E04(mgr, kind);
}

/* --- slot 11: look the actor up in the manager by kind --------------------- */
u32 Actor::v11() {
    u32 result;
    if (v13() != 0) {
        result = reinterpret_cast<u32>(fn_802D800C(fn_802D6A9C(), v13()));
    } else {
        result = 0;
    }
    return result;
}

/* --- slot 10: register this actor's kind with the manager ------------------ */
void Actor::v10(u32 a, u32 b) {
    if (v13() != 0) {
        fn_802D8050(fn_802D6A9C(), v13(), b, a);
    }
}

/* --- detach (non-virtual, 0x801F3668): clear field_11C and drop from area --- */
void Actor::detach() {
    field_11C = 0;
    s32 id = field_16C;
    if (id != -1) {
        fn_802D7704(fn_802D6A9C(), id, field_1A8, field_04);
    } else {
        fn_802D766C(fn_802D6A9C(), field_1A8, field_04);
    }
}

/* --- slot 17: test point b against the actor's area/collision (0x801F15BC) -- */
int Actor::v17(int a, f32* b) {
    int result = 1;
    if (fn_802265DC(b, a, 0) == 0) {
        s32 region = field_198;
        void* base = fn_8020D58C();
        u8 idx = static_cast<u8*>(base)[1];
        if (fn_8020D6AC(static_cast<u8*>(base) + idx * 0x784 + 4, a, b, region, 0) == 0) {
            result = 0;
        }
    }
    return result;
}

/* --- slot 18: bounds check b against the manager's world rect (0x801F165C) -- */
int Actor::v18(int a, f32* b) {
    void* mgr = fn_802D6A9C();
    f32* rect = (a < 8) ? reinterpret_cast<f32*>(static_cast<u8*>(mgr) + 0xcc)
                        : reinterpret_cast<f32*>(static_cast<u8*>(mgr) + 0xdc);
    int result = 0;
    if ((u8)v17(a, b) != 0 || b[0] < rect[0] || b[1] < rect[1] || b[0] >= rect[2] || b[1] >= rect[3]) {
        result = 1;
    }
    return result;
}

/* --- 0x801EE434: release a collision object back to its pool (or reactivate
 * it if it is still on-screen).  Operates on the collision object, not the
 * actor; ~Actor inlines this for field_100 and field_104.  Name is a
 * placeholder. */
extern "C" void fn_801EE434(void* obj) {
    if (obj != 0) {
        u8* c = static_cast<u8*>(obj);
        void* mgr = fn_802D6A9C();
        u8* m = static_cast<u8*>(mgr);
        bool ok = false;
        f32 span = *reinterpret_cast<f32*>(c + 0xa8) - *reinterpret_cast<f32*>(c + 0xac);
        if (*reinterpret_cast<f32*>(c + 0xa4) >= *reinterpret_cast<f32*>(m + 0xcc)) {
            if (span >= *reinterpret_cast<f32*>(m + 0xd0)) {
                if (*reinterpret_cast<f32*>(c + 0xa4) < *reinterpret_cast<f32*>(m + 0xd4)) {
                    if (span < *reinterpret_cast<f32*>(m + 0xd8)) {
                        ok = true;
                    }
                }
            }
        }
        if (ok) {
            *reinterpret_cast<u32*>(c + 0xf4) = *reinterpret_cast<u32*>(c + 0xf4) & 0xffffffbf;
            *reinterpret_cast<u32*>(c + 0xf4) = *reinterpret_cast<u32*>(c + 0xf4) | 1;
            *reinterpret_cast<u32*>(c + 0x24) = 1;
        } else {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*reinterpret_cast<void**>(static_cast<u8*>(fn_8013C824()) + 0xc), obj);
        }
    }
}

/* --- ~Actor (0x801F593C): release the two collision objects, then detach the
 * actor's model from the scene graph.  MWCC synthesises the vtable store and
 * the deleting-destructor tail; the release of field_100/field_104 is the
 * fn_801EE434 helper inlined. */
Actor::~Actor() {
    fn_801EE434(field_100);
    fn_801EE434(field_104);
    fn_801F8448(fn_801F856C(), this);
}

/* --- Actor::Actor (0x801F5AE0): default-initialise every member.  MWCC emits
 * the vtable store; the rest is field initialisation in retail order.  Field
 * names are the placeholders from Actor.h. */
Actor::Actor() {
    field_04 = 0;
    field_08 = 0;
    field_0C.x = 0.0f; field_0C.y = 0.0f; field_0C.z = 0.0f;
    field_18.x = 0.0f; field_18.y = 0.0f; field_18.z = 0.0f;
    field_24.x = 0.0f; field_24.y = 0.0f; field_24.z = 0.0f;
    field_30.x = 0.0f; field_30.y = 0.0f; field_30.z = 0.0f;
    field_3C.x = 0.0f; field_3C.y = 0.0f; field_3C.z = 0.0f;
    field_48.x = 1.0f; field_48.y = 1.0f; field_48.z = 1.0f;
    field_54.x = 1.0f; field_54.y = 1.0f; field_54.z = 1.0f;
    field_60 = -8.0f;
    field_64 = -8.0f;
    field_68 = 8.0f;
    field_6C = 8.0f;
    field_70.x = 0.0f; field_70.y = 0.0f; field_70.z = 0.0f;
    field_7C.x = 0.0f; field_7C.y = 0.0f; field_7C.z = 0.0f;
    field_88 = 0.0f;
    field_8C = 0.0f;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9C = -1;
    field_A0 = -1;
    field_A4 = 0;
    field_A8 = 0;
    field_AC = 0;
    field_B0 = 0;
    field_B4 = 0;
    field_B8 = 0;
    field_BC = 1;
    field_C0 = 1;
    field_C4 = 0;
    field_C8 = -1;
    field_CC = 0;
    field_D0 = -1;
    field_D4 = 0;
    field_D5 = 0;
    field_D8 = 0;
    field_DC = 0x18;
    field_E0 = 0;
    field_E4 = 0;
    field_E8 = 0;
    field_EC.x = 0.0f; field_EC.y = 0.0f; field_EC.z = 0.0f;
    field_F8 = 0;
    field_FC = 0;
    field_100 = 0;
    field_104 = 0;
    field_108 = 4;
    field_10C = -1;
    field_110 = -1;
    field_114 = 0;
    field_118 = 0;
    field_11C = 1;
    field_11D = 1;
    field_11E = 0;
    field_11F = 0;
    field_130 = -1;
    field_134 = -1;
    for (u8 i = 0; i < 0x10; ++i) {
        field_120[i] = i;
    }
    field_130 = -1;
    field_134 = 0;
    field_138 = 0;
    field_13C = 0;
    field_13D = 0;
    field_13E = 0;
    field_13F = 1;
    field_140 = 1;
    field_141 = 0;
    field_142 = 0;
    field_143 = 0;
    field_144 = 0;
    field_145 = 0;
    field_146 = 1;
    field_148 = 3;
    field_14C = 1;
    field_14D = 0;
    field_14E = 0;
    field_150 = -1;
    field_154 = 0;
    field_158 = 2;
    field_15C = 0;
    field_160 = 0;
    field_164 = 0;
    field_165 = 0;
    field_168 = 0;
    field_16C = -1;
    field_174 = 0;
    field_178 = 0;
    field_17C = 0;
    field_17D = 0;
    field_180 = 0x14;
    field_184 = 40.0f;
    field_188 = -1;
    field_18C = 0;
    field_190 = 0;
    field_194 = 0;
    field_195 = 0;
    field_196 = 0;
    field_198 = -1;
    field_19C = 0;
    field_1A0 = 0x4E554C4C;
    field_1A4 = 0;
    field_1A8 = 0;
    __construct_array(&field_1AC[0], fn_8003B2CC, 0, 0xc, 4);
    fn_801EAD68(&field_1DC);
    field_1AC[0].x = 0.0f; field_1AC[0].y = 0.0f; field_1AC[0].z = 0.0f;
    field_1AC[1].x = 0.0f; field_1AC[1].y = 0.0f; field_1AC[1].z = 0.0f;
    field_1AC[2].x = 0.0f; field_1AC[2].y = 0.0f; field_1AC[2].z = 0.0f;
    field_1AC[3].x = 0.0f; field_1AC[3].y = 0.0f; field_1AC[3].z = 0.0f;
}

/* --- 0x801EE3C0: true for the handful of actor ids that get special-cased --- */
extern "C" int fn_801EE3C0(int id) {
    if ((u16)(id - 0x68) <= 3 || (u16)(id - 0x70) <= 1 || (u16)(id - 0xaa) <= 1 ||
        (u16)id == 0x159 || (u16)(id - 0x74) <= 1 || (u16)id == 0x146 ||
        (u16)id == 0xfa || (u16)id == 0x4e) {
        return 1;
    }
    return 0;
}

/* --- 0x801EE508: register the two collision objects with the collision mgr -- */
extern "C" void fn_801EE508(Actor* a) {
    fn_801CB71C(&a->field_100, &a->field_0C, 0, -1);
    fn_801CB71C(&a->field_104, &a->field_0C, 0, 1);
}

/* --- 0x801F1184: hand the actor's id (field_19C) to a global registry ------- */
extern "C" void fn_801F1184(const Actor* a) {
    u32 id = a->field_19C;
    void* node = *reinterpret_cast<void**>(static_cast<u8*>(lbl_8053AAF8) + 4);
    Registry_GetSlotValueOrFallback(*reinterpret_cast<void**>(static_cast<u8*>(node) + 8), id);
}

/* --- 0x801EE4F0: per-id float lookup table --------------------------------- */
extern "C" f32 fn_801EE4F0(Actor* a) {
    return lbl_8046A00C[a->field_C0];
}

/* --- 0x801F2718: forward the actor to the sound helper -------------------- */
extern "C" void fn_801F2718(const Actor* a, u32 b) {
    fn_801F8108((Actor*)a, b, a->field_198, lbl_8053F748);
}

/* --- 0x801F3780: reset the interaction state ------------------------------ */
extern "C" void fn_801F3780(Actor* a, u32 v) {
    a->field_A4 = v;
    a->field_D8 = 0;
    a->field_D5 = 0;
    a->field_E4 = 0;
    a->field_E8 = 0;
    if ((s32)a->field_108 > 0) {
        a->field_E0 = 0;
    }
}

/* --- 0x801F36D4: claim the interaction slot -------------------------------- */
extern "C" u8 fn_801F36D4(Actor* a, s32 v) {
    u32 claimed = 0;
    if (a->field_CC == 0 && a->field_C4 == 0) {
        a->field_CC = 1;
        a->field_D0 = v;
        claimed = 1;
    }
    return claimed;
}

/* --- 0x801F34DC: detach the actor's area slot ----------------------------- */
extern "C" void fn_801F34DC(Actor* a) {
    s32 id = a->field_16C;
    if (id != -1) {
        fn_802D7618(fn_802D6A9C(), id);
    }
}

/* --- 0x801F3708: consume the pending position (field_3C) ------------------ */
extern "C" u8 fn_801F3708(Actor* a, const f32* p) {
    u32 done = 0;
    if (a->field_C4 != 0) {
        a->field_C4 = 0;
        done = 1;
        a->field_3C = *(const Vec*)p;
    }
    return done;
}

/* --- 0x801F3744: open the interaction slot -------------------------------- */
extern "C" u8 fn_801F3744(Actor* a, s32 v) {
    u32 opened = 0;
    if (a->field_C4 == 0) {
        a->field_C4 = 1;
        a->field_C8 = v;
        a->field_CC = 0;
        a->field_D0 = -1;
        a->field_110 = v;
        opened = 1;
    }
    return opened;
}

/* --- 0x801F349C: publish a position into field_30 (paired-single copy) ---- */
extern "C" void fn_801F349C(Actor* a, u32 x, f32* p) {
    if (a->field_17C != 0) return;
    if ((s32)a->field_174 > 0) return;
    register Actor* t = a;
    register f32* s = p;
    register f32 z, xy;
    // clang-format off
    __asm {
        psq_l  xy, 0x0(s),  0, 0
        lfs    z,  0x8(s)
        psq_st xy, 0x30(t), 0, 0
        stfs   z,  0x38(t)
    }
    // clang-format on
    a->field_178 = x;
    a->field_17C = 1;
    a->field_174 = 0;
}

/* --- 0x801F3518: clear field_11C and detach the area slot ----------------- */
extern "C" void fn_801F3518(Actor* a) {
    a->field_11C = 0;
    s32 id = a->field_16C;
    if (id != -1) {
        fn_802D7618(fn_802D6A9C(), id);
    }
}

/* --- 0x801F317C: write four derived coordinates --------------------------- */
extern "C" void fn_801F317C(const Actor* a, f32* out) {
    f32 y = a->field_0C.y;
    f32 x = a->field_0C.x;
    f32 z = a->field_0C.z;
    out[0] = a->field_70.x + x;
    out[1] = a->field_70.y + y - z;
    out[2] = a->field_70.z + x;
    out[3] = a->field_7C.x + y - z;
}

/* --- 0x801F355C: release the actor's area slot (does not clear field_11C) --- */
extern "C" void fn_801F355C(Actor* a) {
    s32 id = a->field_16C;
    if (id != -1) {
        fn_802D7704(fn_802D6A9C(), id, 0, a->field_04);
    }
}

/* --- 0x801F35AC: clear field_11C, then release the area slot --------------- */
extern "C" void fn_801F35AC(Actor* a) {
    a->field_11C = 0;
    s32 id = a->field_16C;
    if (id != -1) {
        fn_802D7704(fn_802D6A9C(), id, 0, a->field_04);
    }
}

/* --- 0x801F329C: actor-kind match test ------------------------------------- */
extern "C" u32 fn_801F329C(Actor* a, u32 x) {
    u32 r = 0;
    if (fn_8023DE58(x) < 8) {
        if ((s32)a->field_04 == 8) {
            r = 1;
        }
    }
    return r;
}

/* --- 0x801F26CC: forward the actor to the model helper with field_198 ------ */
extern "C" void fn_801F26CC(Actor* a, u32 b) {
    fn_801F7F58(fn_801F856C(), a, b, a->field_198, lbl_8053F748);
}

/* --- 0x801F3128: midpoint of the two derived edge points ------------------- */
extern "C" void fn_801F3128(Actor* a, f32* out) {
    f32 a1 = a->field_64 + a->field_0C.y - a->field_0C.z;
    f32 b0 = a->field_68 + a->field_0C.x;
    f32 b1 = a->field_6C + a->field_0C.y - a->field_0C.z;
    f32 a0 = a->field_60 + a->field_0C.x;
    out[0] = 0.5f * (a0 - b0) + b0;
    out[1] = 0.5f * (a1 - b1) + b1;
}

/* --- 0x801F31C4: four derived coordinates (field_60 band) ------------------ */
extern "C" void fn_801F31C4(const Actor* a, f32* out) {
    f32 y = a->field_0C.y;
    f32 x = a->field_0C.x;
    f32 z = a->field_0C.z;
    out[0] = a->field_60 + x;
    out[1] = a->field_64 + y - z;
    out[2] = a->field_68 + x;
    out[3] = a->field_6C + y - z;
}

/* --- 0x801F2DB4: submit/refresh a record code against the actor ------------ */
extern "C" u32 fn_801F2DB4(Actor* a, u32 b, u32 c, void* buf) {
    u32 ok = 0;
    s32 i = fn_801F82CC(fn_801F856C(), a, a->field_195, lbl_8053F748);
    if (i >= 0 && i != a->field_198) {
        Actor* p = fn_801F666C(fn_801F856C(), i);
        u8 sel = 0;
        if ((b == 0x4E554C4C || b == p->field_1A0)
            && (c == 0x4E554C4C || c != p->field_1A0)) {
            sel = 1;
            if (buf != 0) {
                u32* q = (u32*)buf;
                while (*q != 0x4E554C4C) {
                    if (*q == p->field_1A0) {
                        sel = 0;
                        break;
                    }
                    q++;
                }
            }
        }
        if (sel != 0) {
            Vec v;
            {
                register f32* s1 = (f32*)&a->field_0C;
                register f32* s2 = (f32*)&p->field_3C;
                register f32* dst = (f32*)&v;
                /* The declaration order is load-bearing: MWCC picks the FPRs for
                 * these operands from the order below, and any other order moves
                 * one temp to f31 (forcing a prologue save) and breaks the match. */
                register f32 az, axy, bxy, bz, dxy, dz;
                // clang-format off
                __asm {
                    psq_l  axy, 0(s1),  0, 0
                    lfs    az,  8(s1)
                    stfs   az,  8(dst)
                    psq_st axy, 0(dst), 0, 0
                    psq_l  bz,  8(dst), 1, 0
                    psq_l  bxy, 0(s2),  0, 0
                    ps_sub dxy, axy, bxy
                    psq_st dxy, 0(dst), 0, 0
                    psq_l  dz,  8(s2),  1, 0
                    ps_sub dz,  bz,  dz
                    psq_st dz,  8(dst), 1, 0
                }
                // clang-format on
            }
            ok = fn_801F37AC(a, p->field_118, &v, 0, p->field_168, p->field_110);
        } else {
            if (c != 0x48424D42) {
                ok = 1;
                switch (p->field_1A0) {
                case 0x5357424D:
                    fn_801CB538(a->field_04, &p->field_0C, 0, 0);
                    break;
                case 0x46495245:
                    if (fn_801EAC54(&a->field_1DC, p->field_198) != 0) {
                        fn_801CB538(a->field_04, &p->field_0C, 0, 0);
                        fn_8013CC50(a->field_04, &p->field_0C, lbl_8053F774, 0x19D, 0, 0, 0, 0, 1);
                    }
                    break;
                }
            } else {
                ok = 0;
            }
        }
        if ((u8)ok != 0) {
            p->field_164 = 1;
        }
    }
    return (u8)ok;
}

/* --- 0x801F2B20: set field_168, notify the model mgr, consume field_164 ---- */
extern "C" u8 fn_801F2B20(Actor* a, u32 v) {
    u8 prev = a->field_164;
    a->field_168 = v;
    fn_801F84C4(fn_801F856C(), a);
    if (a->field_164 != 0) {
        a->field_164 = 0;
    }
    return prev;
}

/* --- 0x801EF510: build a default record (copied from a global) and submit --- */
extern "C" void fn_801EF510(Actor* a) {
    UnkBlob44 local = lbl_80469FC8;
    fn_801F2DB4(a, 0x4E554C4C, 0x4E554C4C, &local);
}

/* --- 0x801F3604: detach from the area manager (no field_11C clear) ---------- */
extern "C" void fn_801F3604(Actor* a) {
    s32 id = a->field_16C;
    if (id != -1) {
        fn_802D7704(fn_802D6A9C(), id, a->field_1A8, a->field_04);
    } else {
        fn_802D766C(fn_802D6A9C(), a->field_1A8, a->field_04);
    }
}

/* --- 0x801F4694: replay the recorded state + default code ------------------- */
extern "C" void fn_801F4694(const Actor* a) {
    if ((s32)a->field_190 > 0) {
        fn_801F0E34((Actor*)a, lbl_80469F38[a->field_190 - 1], 0);
    }
    if ((s32)a->field_E8 == 0) {
        fn_801F0E34((Actor*)a, 0x40002, 0);
    }
}

/* --- 0x801F320C: kind test against field_04 -------------------------------- */
extern "C" u32 fn_801F320C(const Actor* a, u32 x) {
    s32 id = a->field_04;
    u32 r = 0;
    s32 k = fn_8023DE58(x);
    if (k == id) {
        goto hit;
    }
    u8 ok = 0;
    if (fn_8023DE58(x) < 8) {
        if ((s32)a->field_04 == 8) {
            ok = 1;
        }
    }
    if (ok != 0) {
hit:
        r = 1;
    }
    return r;
}

/* --- 0x801F2FAC: run the 4-slot collision sweep, returning whether any hit -- */
extern "C" u8 fn_801F2FAC(Actor* a) {
    void* p;
    u32 acc = 0;
    u32 i;
    for (i = 0; (s32)i < 4; i++) {
        u32 buf[2];
        if ((s32)i == (s32)fn_801F285C(a, 0, buf, 1, i)) {
            acc = (acc | fn_801F37AC(a, fn_8023B6CC(i), fn_8023E724(i), 0, buf[0], i)) & 0xff;
        }
    }
    return acc;
}

/* --- 0x801F305C: same sweep, but emit the default record when nothing hit --- */
extern "C" u32 fn_801F305C(Actor* a) {
    u32 i;
    u32 acc = 0;
    for (i = acc; (s32)i < 4; i++) {
        u32 buf[2];
        if ((s32)i == (s32)fn_801F285C(a, 0, buf, 1, i)) {
            acc = (acc | fn_801F37AC(a, fn_8023B6CC(i), fn_8023E724(i), 0, buf[0], i)) & 0xff;
        }
    }
    if ((u8)acc == 0) {
        return fn_801F2DB4(a, 0x4E554C4C, 0x4E554C4C, 0);
    }
    return (u8)acc;
}

/* --- 0x801F32F4: fill the four field_1AC bounds from the collision slots ---- */
extern "C" void fn_801F32F4(Actor* a) {
    u8 ok = 0;
    Actor* p = a;
    u32 i;
    for (i = 0; (s32)i < 4; i++) {
        ok = 0;
        if (fn_8023DE58(i) < 8) {
            if ((s32)a->field_04 == 8) {
                ok = 1;
            }
        }
        if (ok != 0) {
            f32 v[3];
            fn_801CD150(fn_8023E724(i), v);
            p->field_1AC[0].x = v[0];
            p->field_1AC[0].y = v[1];
            p->field_1AC[0].z = v[2];
        } else {
            f32* q = (f32*)fn_8023E724(i);
            p->field_1AC[0].x = q[0];
            p->field_1AC[0].y = q[1];
            p->field_1AC[0].z = q[2];
        }
        p = (Actor*)((u8*)p + 0xc);
    }
}

/* --- 0x801F2618: recompute field_0C through the model helper ---------------- */
extern "C" u8 fn_801F2618(Actor* a, f32* out, u32 c) {
    u32 r = 0;
    if ((s32)a->field_174 <= 0) {
        f32 v1[3];
        f32 v0[3];
        if (fn_801F23BC(a, a->field_04, &a->field_0C, &a->field_18, (u8*)a + 0x80, v1, v0, c)) {
            a->field_0C.x = v1[0];
            a->field_0C.y = v1[1];
            a->field_0C.z = v1[2];
            if (out != 0) {
                out[0] = v0[0];
                out[1] = v0[1];
                out[2] = v0[2];
            }
            r = 1;
        }
    }
    return (u8)r;
}

/* --- 0x801F2740: per-slot overlap test, returns a 4-bit slot mask ----------- */
extern "C" u8 fn_801F2740(const Actor* a, s32 b) {
    f32 rect[4];
    rect[3] = a->field_6C + a->field_0C.y - a->field_0C.z;
    rect[1] = a->field_64 + a->field_0C.y - a->field_0C.z;
    rect[0] = a->field_60 + a->field_0C.x;
    rect[2] = a->field_68 + a->field_0C.x;
    u32 id;
    u32 acc = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (i == b) {
            continue;
        }
        id = a->field_04;
        u8* mgr = (u8*)fn_802D6A9C();
        if (mgr[id + 0x131df] == 0) {
            f32* p = (f32*)fn_8023E724(i);
            if (__fabs(p[2] - a->field_0C.z) > lbl_8053F748) {
                continue;
            }
        }
        if (fn_8022E438(i, b) != 0) {
            continue;
        }
        if (fn_8022D75C(i) != 0) {
            continue;
        }
        if (fn_8023B190(i, rect, a->field_04) == 0) {
            continue;
        }
        acc = (acc | (1 << i)) & 0xff;
    }
    return (u8)acc;
}

/* --- 0x801F0D20: toggle the four sound slots for the given action ----------- */
extern "C" void fn_801F0D20(Actor* a, u32 p) {
    if (p == 3 || p == 0x42) {
        if ((s32)a->field_04 >= 8) {
            if (fn_8022BB48(a->field_04, &a->field_0C) == 0) {
                return;
            }
        }
        u8 found = 0;
        for (s32 i = 0; i < 4; i++) {
            if ((((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) == 0) {
                continue;
            }
            if ((s32)a->field_04 < 8) {
                continue;
            }
            if (fn_8022BC38(i, a->field_04, &a->field_0C) == 0) {
                continue;
            }
            if (fn_8030381C(i) == 0) {
                continue;
            }
            if (p == 3) {
                fn_803037D4(i, 0xf);
            } else {
                fn_803037D4(i, 0xe);
            }
            found = 1;
        }
        if (found == 1) {
            return;
        }
    }
    fn_80458880(lbl_8053AF80, p, -1);
}

/* --- 0x801F2A10: does any slot overlap the actor's bounds rect? ------------- */
extern "C" u32 fn_801F2A10(Actor* a, s32 b, u32 p3, u32 p4, u32 p5) {
    f32 rect[4];
    rect[0] = a->field_60 + a->field_0C.x;
    rect[1] = a->field_64 + a->field_0C.y - a->field_0C.z;
    rect[2] = a->field_68 + a->field_0C.x;
    rect[3] = a->field_6C + a->field_0C.y - a->field_0C.z;
    for (u32 i = 0; i < 4; i++) {
        u32 id = a->field_04;
        if (((u8*)fn_802D6A9C())[id + 0x131df] == 0) {
            f32* p = (f32*)fn_8023E724(i);
            if (__fabs(a->field_0C.z - p[2]) > lbl_8053F748) {
                continue;
            }
        }
        if (fn_8022E438(i, b) != 0) {
            continue;
        }
        if (fn_80239B64(i, rect, a->field_04, p3, p4, p5) == 0) {
            continue;
        }
        return 1;
    }
    return 0;
}

/* --- v04 (0x801F5790): per-slot ground/overlap prologue --------------------- */
void Actor::v04() {
    if (field_0C.z <= 16.0f) {
        if (field_68 - field_60 > 0.0f) {
            if (field_6C - field_64 > 0.0f) {
                f32 y = field_0C.y;
                f32 x = field_0C.x;
                f32 rect[4];
                rect[2] = field_68 + x;
                rect[0] = field_60 + x;
                rect[1] = field_64 + y - field_0C.z;
                rect[3] = field_6C + y - field_0C.z;
                s32 id;
                s32 i;
                for (i = 0; i < 4; i++) {
                    if (fn_8023F264(i) == 0) {
                        continue;
                    }
                    id = field_04;
                    if (id != fn_8023DE58(i)) {
                        continue;
                    }
                    f32* p = (f32*)fn_8023E724(i);
                    f32 x1 = -12.0f + p[0];
                    f32 x2 = 12.0f + p[0];
                    f32 y2 = (12.0f + p[1]) - p[2];
                    f32 y1 = (-28.0f + p[1]) - p[2];
                    f32 r0 = rect[0];
                    f32 r1 = rect[1];
                    f32 r2 = rect[2];
                    f32 r3 = rect[3];
                    if (r0 < x1) r0 = x1;
                    if (r1 < y1) r1 = y1;
                    if (r2 > x2) r2 = x2;
                    if (r3 > y2) r3 = y2;
                    if (r2 >= r0 && r3 >= r1) {
                        fn_802397B4(rect, field_04, field_198);
                        return;
                    }
                }
            }
        }
    }
}

/* --- 0x801F33C4: tick the actor's move-to-target (field_30 - field_0C) ------ */
extern "C" void fn_801F33C4(Actor* a) {
    a->field_17D = 0;
    if ((s32)a->field_174 > 0) {
        a->field_174 = a->field_174 - 1;
        Vec tmp;
        Vec v;
        {
            register f32* s1 = (f32*)&a->field_30;
            register f32* s2 = (f32*)&a->field_0C;
            register f32* dst = (f32*)&v;
            register f32* dst2 = (f32*)&tmp;
            register f32 az, axy, dz, bz, dxy, bxy;
            // clang-format off
            __asm {
                lfs    az,  8(s1)
                psq_l  axy, 0(s1),  0, 0
                stfs   az,  8(dst)
                psq_l  bxy, 0(s2),  0, 0
                psq_l  bz,  8(dst), 1, 0
                psq_l  dz,  8(s2),  1, 0
                ps_sub dxy, axy, bxy
                psq_st axy, 0(dst), 0, 0
                ps_sub dz,  bz,  dz
                psq_st dxy, 0(dst), 0, 0
                psq_st dz,  8(dst), 1, 0
                lfs    az,  8(dst)
                psq_st dxy, 0(dst2), 0, 0
                stfs   az,  8(dst2)
            }
            // clang-format on
        }
        if (PSVECMag(&tmp) >= a->field_184) {
            a->field_174 = 0;
        }
    } else {
        if (a->field_17C != 0) {
            a->field_0C.x = a->field_30.x;
            a->field_0C.y = a->field_30.y;
            a->field_04 = a->field_178;
            a->field_17C = 0;
            a->field_17D = 1;
            a->field_174 = a->field_180;
        }
    }
}

/* --- 0x801F285C: pick the collision slot overlapping the actor's bounds ------
 * Retail evaluates the actor's four world-rect corners into FPRs and only
 * writes the frame at the end of the block: the loads are 0x6c,0x10,0x64,0x14,
 * 0x68,0xc,0x60 and the stores land as rect[3],rect[1],rect[0],rect[2].  Four
 * plain `rect[i] = a->field_x + ...;` statements compile to four compute/store
 * pairs instead (the 71 % body), so the corners are expressed as named
 * temporaries, declared in the order 0,3,2,1 - that reproduces retail's load
 * order, FPR assignment (f1/f2/f0/f4/f2/f5/f0) and store order exactly.
 *
 * The d test is written `if (d >= 0) { ... } else { ... }` because retail lays
 * the fn_8023B9CC branch out first and branches FORWARD (`blt`) to the
 * fn_8023B8E4 call; the same applies to fn_8023B848/fn_8023B768 below.
 *
 * The frame is 0x40 with no FPR save, stmw r27 .. r31: a, b, c and the result
 * stay in callee-saved GPRs across the four helper calls.
 *
 * Known residue (see the report): this compiler places the four parameter
 * copies and the `r = -1` init as one run right after `stmw` and issues the
 * rectangle loads afterwards, where retail interleaves them through the float
 * chain (mr r30,r3 lands after `lfs f4,0x14`; mr r31,r4 after `fsubs f1,f1,f4`
 * ...) and hoists the first two loads above the LR/GPR saves.  Everything else
 * - float order, store order, control flow, call order and the frame - is
 * exact. */

/* --- 0x801F285C: pick the collision slot overlapping the actor's bounds ------ */
extern "C" s32 fn_801F285C(Actor* a, f32* b, u32* c, u32 e, s32 d) {
    f32 rect[4];
    f32 out8[2];
    s32 r = -1;
    f32 ta = a->field_60 + a->field_0C.x;
    f32 tb = a->field_6C + a->field_0C.y - a->field_0C.z;
    f32 tc = a->field_68 + a->field_0C.x;
    f32 td = a->field_64 + a->field_0C.y - a->field_0C.z;
    rect[0] = ta;
    rect[1] = td;
    rect[2] = tc;
    rect[3] = tb;
    if (d >= 0) {
        if (fn_8023B9CC(d, rect, a->field_04, out8, e)) {
            r = d;
        }
    } else {
        r = fn_8023B8E4(rect, a->field_04, out8);
    }
    if (r == -1) {
        if (d >= 0) {
            if (fn_8023B848(d, rect, a->field_04, out8)) {
                r = d;
            }
        } else {
            r = fn_8023B768(rect, a->field_04, out8);
        }
        if (r != -1) {
            if (c != 0) {
                c[0] = 0;
            }
        }
    } else {
        if (c != 0) {
            if (fn_80233DA4(r)) {
                c[0] = 0;
            } else {
                c[0] = 1;
            }
        }
    }
    if (r != -1) {
        u32 id = a->field_04;
        if (((u8*)fn_802D6A9C())[id + 0x131df] == 0) {
            f32* p = (f32*)fn_8023E724(r);
            if (__fabs(a->field_0C.z - p[2]) > lbl_8053F748) {
                r = -1;
            }
        }
    }
    if (b != 0) {
        b[0] = out8[0];
        b[1] = out8[1];
    }
    return r;
}

/* ==== integrated from actor-wip ==== */

/* --- 0x801F132C: choose this actor's "collision object to spawn" flag -------
 * Not a virtual.  d is a countdown: while *d != 0 it is decremented and 0 is
 * returned.  Once it hits 0 the actor's area entry is probed for a free
 * collision slot; if one is found 1 is returned.  Otherwise the actor's kind
 * (fn_8022461C) and sub-kind (fn_80226850) decide: a list of kinds is
 * rejected outright, a few sub-kinds park the spawn for 0x78 frames, and
 * kinds 0x25/0x26/0x22 report a bit from the area manager. */

extern "C" u32 fn_801F132C(Actor* a, s32 b, s32 c, s32* d) {
    if (*d == 0) {
        s32 region = a->field_198;
        void* base = fn_8020D58C();
        u8 idx = static_cast<u8*>(base)[1];
        if (fn_8020D6AC(static_cast<u8*>(base) + idx * 0x784 + 4, b, reinterpret_cast<f32*>(c), region, 0) != 0) {
            return 1;
        }
        s32 kind = fn_8022461C(c, b);
        s32 sub = fn_80226850(c, b);
        if (sub == 0x230 || sub == 0x231) {
            return 0;
        }
        if (kind != 0x0 && kind != 0x4 && kind != 0x5 && kind != 0x6 && kind != 0x7 && kind != 0x2 && kind != 0x3 &&
            kind != 0x50 && kind != 0xe && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 &&
            kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f &&
            kind != 0x20 && kind != 0xd && kind != 0x39 && kind != 0x3a && kind != 0x3b && kind != 0x4c &&
            kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24) {
            if ((u32)(kind - 0x10) <= 3 || (sub >= 0x140 && sub <= 0x15f)) {
                if (sub != 0x146 && sub != 0x147 && sub != 0x148 && sub != 0x159 && sub != 0x15a && sub != 0x15b) {
                    *d = 0x78;
                    return 0;
                }
            }
            if (sub == 0x3a || sub == 0x3d) {
                return 0;
            }
            if (kind == 0x25) {
                return static_cast<u8*>(fn_802D6A9C())[0x171] == 0;
            }
            if (kind == 0x26) {
                return static_cast<u8*>(fn_802D6A9C())[0x171] == 1;
            }
            if (kind != 0x22 || static_cast<u8*>(fn_802D6A9C())[0x170] == 1) {
                return 1;
            }
        }
    } else {
        *d = *d - 1;
    }
    return 0;
}

/* ==== integrated from actor-wip ==== */

/* --- 0x801F4F28: slot 7 of the vtable, the per-frame actor update --------- */

/* 0x19660d/0x3c6ef35f is the fast LCG the retail code keeps at
 * lbl_8053AAF8+0xB4; the caller only ever wants the [0,1) mantissa field. */
static inline f32 v07Rand01() {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = *s * 0x19660du + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - 1.0f;
}

/* Bounds-check the two record indices, then test the packed flag word.  The
 * two out-of-range cases each assign the result separately (rather than a
 * single shared `ok = 0`) - that is what puts the two `li r0, 0` blocks in
 * front of the value computation. */
static inline s32 v07FlagTest() {
    s32 x = *(s32*)(lbl_80529DEC + 0x118);
    s32 y = *(s32*)(lbl_80529DEC + 0x11c);
    s32 ok;
    if (x < 0 || x > 7) {
        ok = 0;
    } else if (y < 0 || y > 3) {
        ok = 0;
    } else {
        u32 f = *(u32*)(lbl_8050EC80 + 0x28 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10));
        u32 b = (1u << (y + x * 4));
        ok = (b & f) != 0;
    }
    return ok;
}

/* Slot 7 is the base actor's per-frame update: gate on the global mode flags,
 * occasionally spawn a "CRTL" actor next to it, refresh the two particles at
 * field_C0's scale, advance the current particle record, then run the
 * field_BC-dependent common update and detach.  Note that `idx` has to be
 * declared before `handle`: MWCC hands callee-saved GPRs out in declaration
 * order, and retail has the index in r30 and the handle in r29. */
void Actor::v07() {
    if (((u8*)lbl_8053AAF8)[0x7e] != 0 && field_1A8 == 1 &&
        fn_801F7A6C(fn_801F856C()) == 1) {
        fn_801CB434(field_04, &field_0C, 0);
    } else if ((s32)field_18C != 0 && ((u8*)lbl_8053AAF8)[0x7e] != 0 &&
               ((u8*)lbl_8053AAF8)[0x7f] != 0 && (u8)fn_802DE814() == 0 &&
               v07FlagTest() != 0 && v07Rand01() < 0.2f && field_10C >= 0 &&
               field_10C < 4 && fn_8022F340(field_10C) == fn_801CCDA4() &&
               fn_801F7A08(fn_801F856C(), 0x4352544c) < 0) {
        Actor_CreateByID(fn_801F856C(), (u32)0x4352544c, field_04, (f32*)&field_0C, (u32)0, -1, -1);
    } else if ((s32)field_18C != 0) {
        fn_801F52A4(this);
    }

    s32 idx;
    s32 handle = fn_8013CC50(field_04, &field_0C, lbl_8046A00C[field_C0], 0x172, 1, 1, 0, 0, 1);
    fn_8013CC50(field_04, &field_0C, lbl_8046A00C[field_C0], 0x173, 1, 1, 0, 0, 1);
    idx = field_10C;
    if (idx >= 0 && idx < 4) {
        fn_8013C830(fn_8013C824(), idx, handle);
        if ((u8)fn_8022F514(field_10C) != 0) {
            field_10C = fn_8022F3DC(field_10C);
        }
        if ((s32)field_FC == 1) {
            fn_802359A4(field_10C, fn_802357E0(field_10C));
            s32 d = fn_802357E0(field_10C);
            fn_801F6718(fn_801F856C(), field_10C, field_04, &field_0C, d, 0);
        }
        fn_80235B68(field_10C, field_198);
    }
    if ((s32)field_BC == 3 || (s32)field_BC == 4) {
        fn_801F0E34(this, 0x400f0, 0);
    } else {
        fn_801F0E34(this, 0x40003, 0);
    }
    detach();
}

/* ==== integrated from actor-wip ==== */

/* --- slot 8 (0x801F4E0C) --------------------------------------------------
 * The frozen slot-8 placeholder in Actor.h is `void v08()`, but retail's body
 * reads a pointer (r4) and two floats (f1/f2); the literal mangled name keeps
 * the target symbol while allowing the real argument shape. */

extern "C" void v08__5ActorFv(Actor* a, void* p, f32 dx, f32 dy) {
    Vec v;
    register f32 xy, z;
    register Actor* t = a;
    register void* d = &v;
    a->field_D8 = 0;
    a->field_188 = 0x12c;
    // clang-format off
    __asm {
        psq_l  xy, 0xc(t),  0, 0
        lfs    z,  0x14(t)
        psq_st xy, 0x0(d),  0, 0
        stfs   z,  0x8(d)
    }
    // clang-format on
    v.x += dx;
    v.y += dy;
    fn_8013CC50(a->field_04, &v, lbl_8053F774, 0x6d, (u32)p, 0, 0, 0, 1);
    fn_8013CC50(a->field_04, &v, lbl_8053F774, 0x6a, (u32)p, 0, 0, 0, 1);
    fn_8013CC50(a->field_04, &v, lbl_8053F774, 0x6b, (u32)p, 0, 0, 0, 1);
    fn_8013CC50(a->field_04, &v, lbl_8053F774, 0x6c, (u32)p, 0, 0, 0, 1);
    fn_80134DE4(lbl_8053AAF8, 0x12c, 0);
}

/* --- 0x801F2B7C ----------------------------------------------------------
 * Build the actor's world rect from its position and half-extents, test every
 * collision slot against it, and drive the surviving slots' events.  Returns
 * the 4-bit mask of slots that passed.
 *
 * Three shapes are load-bearing for the match (all measured against retail):
 * the rect corners are materialised in dedicated float locals before being
 * stored into the array (a direct `rect[i] = expr` scalarises differently);
 * the manager lookup needs its own `mgr` local so the `a->field_04` load is
 * hoisted above the call; and the mask is copied into a u32 before the test
 * so the zero-extension web is separate from the u8 mask itself. */

extern "C" u8 fn_801F2B7C(Actor* a, s32 b, s32 c, void* d) {
    f32 tmp[3];
    f32 v[3];
    f32 rect[4];
    f32 out[2];
    s32 i, j;
    u8 mask = 0;
    f32 vA = a->field_60 + a->field_0C.x;
    f32 vD = a->field_6C + a->field_0C.y - a->field_0C.z;
    f32 vC = a->field_68 + a->field_0C.x;
    f32 vB = a->field_64 + a->field_0C.y - a->field_0C.z;
    rect[0] = vA;
    rect[1] = vB;
    rect[2] = vC;
    rect[3] = vD;
    for (i = 0; i < 4; i++) {
        if (i == c) continue;
        u32 id = a->field_04;
        u8* mgr = (u8*)fn_802D6A9C();
        if (mgr[id + 0x131df] == 0) {
            f32 pz = ((f32*)fn_8023E724(i))[2];
            if (__fabs(a->field_0C.z - pz) > lbl_8053F748) continue;
        }
        if (fn_8022E438(i, c)) continue;
        if (fn_8022D75C(i)) continue;
        if (fn_8023B190(i, rect, a->field_04) == 0) continue;
        mask = (u8)(mask | (1 << i));
    }
    u32 m = mask;
    if (m != 0) {
        f32 y1 = a->field_6C + a->field_0C.y - a->field_0C.z;
        f32 x0 = a->field_60 + a->field_0C.x;
        f32 y0 = a->field_64 + a->field_0C.y - a->field_0C.z;
        f32 x1 = a->field_68 + a->field_0C.x;
        f32 cx = lbl_8053F74C * (x0 - x1) + x1;
        f32 cz = lbl_8053F74C * (y0 - y1) + y1;
        for (j = 0; j < 4; j++) {
            if ((m & (1 << j)) == 0) continue;
            u8 hit = 0;
            if (fn_8023DE58(j) < 8 && (s32)a->field_04 == 8) hit = 1;
            if (hit) {
                v[0] = cx;
                v[1] = cz;
                v[2] = lbl_8053F740;
                fn_801CD0D0(v, tmp);
                out[0] = tmp[0];
                out[1] = tmp[1];
            } else {
                out[0] = cx;
                out[1] = cz;
            }
            if (b == -100) b = a->field_114;
            fn_80238548(j, b, out, d);
        }
    }
    return m;
}

/* --- 0x801EF574 is parked at 62.56 %: its single fn_802F86CC call site orders the
 * arguments float-first, while the three call sites in the fn_801EF830 block (87.35 %)
 * order them pointer-first. C++ allows one declaration, so the two cannot coexist until
 * the retail stream settles which order is real. The body lives on its own work branch.
 * ------------------------------------------------------------------------ */




/* --- 0x801EE8F4: ... ----------------------------------------------------- */

inline void atu5SetVec3f(register const f32* src, register f32* dst) {
    register f32 xy, z;
    // clang-format off
    __asm {
        psq_l  xy, 0(src), 0, 0
        lfs    z,  8(src)
        psq_st xy, 0(dst), 0, 0
        stfs   z,  8(dst)
    }
    // clang-format on
}

/* The manager keeps two 4-float tables: slots 0..7 live at +0xCC and slots
 * 8..15 at +0xDC.  Each call re-reads the manager, i.e. retail calls
 * fn_802D6A9C() once per element it touches. */
inline f32* warpRect(s32 idx) {
    u8* m = (u8*)fn_802D6A9C();
    return (f32*)(idx < 8 ? m + 0xcc : m + 0xdc);
}

/* --- 0x801EE24C: warp the actor onto the manager's "WARP" entry ------------
 * Walks the manager's WARP list for the first live entry whose kind matches
 * this actor, then offsets field_0C by that entry's side table.  Returns 0
 * when the list holds no such entry. */
extern "C" u32 fn_801EE24C(Actor* a) {
    u32 code = 0x57415250; /* 'WARP' */
    s32 i = -1;
    u32 st;
    for (;;) {
        i = fn_801F78F4(fn_801F856C(), code, i);
        if (i < 0) {
            goto fail;
        }
        u8* e = (u8*)fn_801F666C(fn_801F856C(), i);
        if (e == 0) {
            continue;
        }
        if ((s32)a->field_04 != *(s32*)(e + 4)) {
            continue;
        }
        st = *(u32*)(e + 0x90);
        if ((u8)st != 8) {
            continue;
        }
        break;
    }
    Vec pos;
    atu5SetVec3f((const f32*)((u8*)a + 0xc), (f32*)&pos);
    s32 slot = (st >> 24) & 7;
    if (slot != 0) {
        slot += 7;
    }
    pos.x = pos.x - warpRect((s32)a->field_04)[0];
    pos.y = pos.y - warpRect((s32)a->field_04)[1];
    pos.x = pos.x + warpRect(slot)[0];
    pos.y = pos.y + warpRect(slot)[1];
    pos.z = 200.0f;
    atu5SetVec3f((const f32*)&pos, (f32*)((u8*)a + 0xc));
    a->field_04 = slot;
    return 1;

fail:
    return 0;
}

s32 fn_801F6874(u32 x);
u8 lbl_8052EBC0[];
f32 lbl_8053F740;
f32 lbl_8053F7A4;

/* --- 0x801F11B4: teleport the actor onto its spawn point -------------------
 * Only runs while the actor's bounds are still degenerate (a spawn marker);
 * once v17 accepts the spot it re-seeds field_0C from field_18, nudges it by
 * field_98's entry in the manager's trig table and - if that spot is outside
 * the manager's rect - resets the actor onto field_24. */
extern "C" int fn_801F11B4(Actor* a) {
    int result = 0;
    if (a->field_88 - a->field_7C.y > 0.0f) {
        if (a->field_8C - a->field_7C.z > 0.0f) {
            if ((u8)a->v17((int)a->field_04, (f32*)&a->field_0C) != 0) {
                a->field_0C.x = a->field_18.x;
                a->field_0C.y = a->field_18.y;
                f32 c = 8.0f;
                s16 angle = fn_801F6874(a->field_98);
                u32 idx = (u16)(angle - 0x8000) >> 5;
                f32 dx = c * sincosTable___5JMath[idx].sin;
                f32 dy = c * sincosTable___5JMath[idx].cos;
                a->field_0C.x = a->field_0C.x + dx;
                a->field_0C.y = a->field_0C.y + dy;
                f32* rect = warpRect((s32)a->field_04);
                bool inside = a->field_0C.x >= rect[0] && a->field_0C.y >= rect[1] &&
                                a->field_0C.x < rect[2] && a->field_0C.y < rect[3];
                if (!inside) {
                    a->field_04 = a->field_08;
                    register Actor* t = a;
                    register f32 z, xy;
                    // clang-format off
                    __asm {
                        psq_l  xy, 0x24(t), 0, 0
                        lfs    z,  0x2c(t)
                        psq_st xy, 0xc(t),  0, 0
                        stfs   z,  0x14(t)
                    }
                    __asm {
                        psq_l  xy, 0x24(t), 0, 0
                        lfs    z,  0x2c(t)
                        psq_st xy, 0x18(t),  0, 0
                        stfs   z,  0x20(t)
                    }
                    // clang-format on
                }
                result = 1;
            }
        }
    }
    return result;
}

/* --- 0x801EE558: closest collision slot around the actor --------------------
 * Scans up to four entries of a->field_1AC (the per-actor collision slot
 * array) and keeps the one whose position is nearest to a reference point
 * built from a->field_0C with its y flattened by z.  Returns nothing; the
 * normalized direction goes to b (if non-null) and the distance to c (if
 * non-null).  JMathInlineVEC / JGeometry helpers are inlined verbatim: the
 * floating point register allocation depends on their declared register
 * order, so they are reproduced exactly rather than included. */

namespace {
inline void blkSubtract(register const Vec* vec1, register const Vec* vec2, register Vec* dst) {
    register f32 v1xy, v2xy, dxy, v1z, v2z, dz;
    // clang-format off
    __asm {
        psq_l     v1xy, 0(vec1), 0, 0
        psq_l     v2xy, 0(vec2), 0, 0
        ps_sub    dxy, v1xy, v2xy
        psq_st    dxy, 0(dst), 0, 0

        psq_l     v1z,   8(vec1), 1, 0
        psq_l     v2z,   8(vec2), 1, 0
        ps_sub    dz, v1z, v2z
        psq_st    dz,  8(dst), 1, 0
    }
    // clang-format on
}
inline void blkScale(register const Vec* src, register Vec* dst, register f32 scalar) {
    register f32 vxy, vz, rxy, rz;
    // clang-format off
    __asm {
        psq_l       vxy, 0(src), 0, 0
        psq_l       vz,  8(src), 1, 0
        ps_muls0    rxy, vxy, scalar
        psq_st      rxy, 0(dst), 0, 0
        ps_muls0    rz,  vz,  scalar
        psq_st      rz,  8(dst), 1, 0
    }
    // clang-format on
}
inline f32 blkSquareMag(register const Vec* src) {
    register f32 xy, z, ret;
    // clang-format off
    __asm {
        psq_l xy, 0(src), 0, 0
        ps_mul xy, xy, xy
        lfs z, 8(src)
        ps_madd ret, z, z, xy
        ps_sum0 ret, ret, xy, xy
    }
    // clang-format on
    return ret;
}
inline f32 blkInvSqrt(f32 x) {
    if (x <= lbl_8053F740) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = lbl_8053F74C * y * (lbl_8053F750 - (x * (y * y)));
    return y;
}
inline f32 blkSqrt(f32 x) {
    if (x <= lbl_8053F740) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = lbl_8053F74C * y * (lbl_8053F750 - (x * (y * y)));
    return x * y;
}
} // namespace

extern "C" void fn_801EE558(Actor* a, Vec* b, f32* c, s32 d) {
    bool first = true;
    s32 slot = 0;
    Actor* aa = a;
    Vec best;
    Vec p;
    Vec delta;
    f32 min;

    best.x = lbl_8053F740;
    best.y = lbl_8053F744;
    best.z = lbl_8053F740;
    min = blkSquareMag(&best);
    p = a->field_0C;
    p.y = p.y - p.z;

    for (; slot < 4; slot++) {
        if (d != 0) {
            slot = d - 1;
        }
        if (fn_8023F264(slot)) {
            s32 t = aa->field_04;
            bool ok = false;
            if (t != fn_8023DE58(slot)) {
                t = 0;
                if (fn_8023DE58(slot) < 8 && (s32)aa->field_04 == 8) {
                    t = 1;
                }
            }
            if ((u8)t) {
                ok = true;
            }
            if (ok) {
                if (!fn_8022F478(slot) && !fn_80236B50(slot) && !fn_8022D534(slot)) {
                    blkSubtract(&a->field_1AC[slot], &p, &delta);
                    if (first) {
                        min = blkSquareMag(&delta);
                        best = delta;
                        first = false;
                    } else {
                        f32 d2 = blkSquareMag(&delta);
                        if (d2 < min) {
                            min = d2;
                            best = delta;
                        }
                    }
                }
            }
        }
        if (d != 0) {
            break;
        }
    }

    if (b != 0) {
        f32 len = lbl_8053F740;
        best.z = len;
        if (c != 0) {
            f32 d2 = blkSquareMag(&best);
            if (d2 <= lbl_8053F748 * lbl_80539D44[0]) {
                b->x = b->y = b->z = len;
            } else {
                f32 inv = blkInvSqrt(d2);
                blkScale(&best, b, inv);
                len = inv * d2;
            }
            *c = len;
        } else {
            f32 d2 = blkSquareMag(&best);
            if (d2 <= lbl_8053F748 * lbl_80539D44[0]) {
                b->x = b->y = b->z = len;
            } else {
                f32 inv = blkInvSqrt(d2);
                blkScale(&best, b, inv);
            }
        }
    } else if (c != 0) {
        *c = blkSqrt(min);
    }
}

/* --- 0x801F0E34: publish/refresh the four slot-sound entries ---------------
 * Dispatch on `code` (0x30000-based slot ids) to re-arm one of the four
 * slot-sound entries, then resolve and publish the actor's slot state.  The
 * second half is written as a small helper that this compiler inlines: that
 * (not statement order) is what reproduces retail's callee-saved allocation
 * (z=r31, code=r30, a=r29, loop index / slot pointer = r28), and keeping
 * `mgr` in a local in the last branch reproduces retail's `cmpw r4, r0`
 * operand order.  Residue: retail defers the `stw r28` prologue save past the
 * body's first load, we emit it in the prologue group (99.06 %, 1 instr). */
namespace ATU3 {

/* Tail half: resolve one slot and publish it (retail has this inlined). */
static s32 slotTail(Actor* a, u32 code, u32 z) {
    u8* p = (u8*)Registry_GetSlotValueOrFallback(
        *reinterpret_cast<void**>(static_cast<u8*>(
            *reinterpret_cast<void**>(static_cast<u8*>(lbl_8053AAF8) + 4)) + 8),
        a->field_19C);
    p[0x44] = ((s32)a->field_04 >= 8);
    if (fn_802D7804(fn_802D6A9C(), a->field_04, 0x800) != 0) {
        p[0x45] = 0;
    } else if ((s32)a->field_04 < 8) {
        if (fn_802D7948(fn_802D6A9C()) == 1) {
            p[0x45] = 2;
        } else {
            p[0x45] = 0;
        }
    } else if ((s32)a->field_04 == 8) {
        p[0x45] = 3;
    } else {
        void* mgr = fn_802D6A9C();
        if ((s32)a->field_04 < *(s32*)(static_cast<u8*>(mgr) + 0x54)) {
            if (fn_802D7948(fn_802D6A9C()) == 1) {
                p[0x45] = 2;
            } else {
                p[0x45] = 1;
            }
        } else {
            p[0x45] = 2;
        }
    }
    u32 buf = code;
    return fn_80456334(p, &buf, z);
}

/* Dispatch half: guards, then the four slot-sound blocks. */
extern "C" s32 fn_801F0E34(Actor* a, u32 code, u32 z) {
    s32 i;
    if ((s32)a->field_04 >= 8) {
        if (fn_8022BB48(a->field_04, &a->field_0C) == 0) {
            return 0;
        }
    }
    if ((s32)a->field_04 >= 8) {
        if (((u8*)lbl_8053AAF8)[0x7e] != 0 || ((((u32)((u8*)lbl_8053AAF8)[0x83]) & 3) != 2)) {
            if (code - 0x30000 == 9) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022BC38(i, a->field_04, &a->field_0C) == 0) {
                        continue;
                    }
                    if (fn_8030381C(i) == 0) {
                        continue;
                    }
                    if ((((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) == 0) {
                        continue;
                    }
                    fn_803037D4(i, 8);
                }
                return 0;
            } else if (code - 0x30000 == 4) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022BC38(i, a->field_04, &a->field_0C) == 0) {
                        continue;
                    }
                    if (fn_8030381C(i) == 0) {
                        continue;
                    }
                    if ((((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) == 0) {
                        continue;
                    }
                    fn_803037D4(i, 0xb);
                }
                return 0;
            } else if (code - 0x30000 == 0x22) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022BC38(i, a->field_04, &a->field_0C) == 0) {
                        continue;
                    }
                    if (fn_8030381C(i) == 0) {
                        continue;
                    }
                    if ((((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) == 0) {
                        continue;
                    }
                    fn_803037D4(i, 7);
                }
                return 0;
            } else if (code - 0x30000 == 0x4b) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022BC38(i, a->field_04, &a->field_0C) == 0) {
                        continue;
                    }
                    if (fn_8030381C(i) == 0) {
                        continue;
                    }
                    if ((((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) == 0) {
                        continue;
                    }
                    fn_803037D4(i, 8);
                }
                return 0;
            }
        }
    }
    return slotTail(a, code, z);
}
}  // namespace ATU3

/* --- 0x801EE8F4: ... ----------------------------------------------------- */

static inline f32 ee8f4_invsqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return y;
}

static inline f32 ee8f4_sqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return x * y;
}

static inline void ee8f4_scale(Vec* src, Vec* dst, register f32 scalar) {
    register f32 vxy, vz, rxy, rz;
    register f32* sp = (f32*)src;
    register f32* dp = (f32*)dst;
    // clang-format off
    __asm {
        psq_l    vxy, 0(sp), 0, 0
        psq_l    vz,  8(sp), 1, 0
        ps_muls0 rxy, vxy, scalar
        psq_st   rxy, 0(dp), 0, 0
        ps_muls0 rz,  vz,  scalar
        psq_st   rz,  8(dp), 1, 0
    }
    // clang-format on
}

static inline f32 ee8f4_sqmag(Vec* v) {
    register f32 xy, z, t, s;
    register f32* p = (f32*)v;
    // clang-format off
    __asm {
        psq_l   xy, 0(p), 0, 0
        ps_mul  t, xy, xy
        lfs     z, 8(p)
        ps_madd s, z, z, t
        ps_sum0 s, s, t, t
    }
    // clang-format on
    return s;
}

static inline f32 ee8f4_sqmag2(Vec* v) {
    register f32 s, xy, z;
    register f32* p = (f32*)v;
    // clang-format off
    __asm {
        psq_l   xy, 0(p), 0, 0
        ps_mul  xy, xy, xy
        lfs     z, 8(p)
        ps_madd s, z, z, xy
        ps_sum0 s, s, xy, xy
    }
    // clang-format on
    return s;
}

static inline u8 ee8f4_eq(s32 a, s32 b) { return a == b; }
static inline u8 ee8f4_t(Actor* a, s32 i) {
    u8 t = 0;
    if (fn_8023DE58(i) < 8 && (s32)a->field_04 == 8) {
        t = 1;
    }
    return t;
}

extern "C" void fn_801EE8F4(Actor* a, Vec* outDir, f32* outLen, s32 n) {
    Vec best;
    Vec ref;
    ref.x = a->field_0C.x;
    ref.y = a->field_0C.y;
    ref.z = a->field_0C.z;
    best.x = 0.0f;
    best.y = 0.0f;
    best.z = 0.0f;
    ref.y = a->field_0C.y - a->field_0C.z;

    u8 first = 1;
    f32 bestLen;

    s32 i = 0;
    while (i < 4) {
        if (n != 0) {
            i = n - 1;
        }
        if (fn_8023F264(i)) {
s32 id = (s32)a->field_04; u8 same = 0; if (ee8f4_eq(fn_8023DE58(i), id) || ee8f4_t(a, i)) { same = 1; }
            if (same && !fn_80230188(i) && !fn_8022DCD8(i) && !fn_8022F478(i) &&
                !fn_80236B50(i) && !fn_8022D534(i)) {
                Vec d;
                {
                    register f32* p1 = (f32*)&ref;
                    register f32* p2 = (f32*)&a->field_1AC[i];
                    register f32* dst = (f32*)&d;
                    register f32 az, ez, axy, exy, dxy, dz;
                    // clang-format off
                    __asm {
                        psq_l  axy, 0(p1), 0, 0
                        psq_l  az,  8(p1), 1, 0
                        psq_l  exy, 0(p2), 0, 0
                        psq_l  ez,  8(p2), 1, 0
                        ps_sub dxy, exy, axy
                        ps_sub dz,  ez,  az
                        psq_st dxy, 0(dst), 0, 0
                        psq_st dz,  8(dst), 1, 0
                    }
                    // clang-format on
                }
                if (first) {
                    first = 0;
                    bestLen = ee8f4_sqmag(&d);
                    best = d;
                } else {
                    f32 l = ee8f4_sqmag(&d);
                    if (l < bestLen) {
                        bestLen = l;
                        best = d;
                    }
                }
            }
        }
        if (n != 0) {
            break;
        }
        i++;
    }

    if (outDir != 0) {
        best.z = 0.0f;
        if (outLen != 0) {
            f32 l2 = ee8f4_sqmag2(&best);
            f32 len;
            if (l2 <= lbl_8053F748 * lbl_80539D44[0]) {
                outDir->z = 0.0f;
                outDir->y = 0.0f;
                outDir->x = 0.0f;
                len = 0.0f;
            } else {
                f32 s = ee8f4_invsqrt(l2);
                ee8f4_scale(&best, outDir, s);
                len = s * l2;
            }
            *outLen = len;
        } else {
            f32 l2 = ee8f4_sqmag2(&best);
            if (l2 <= lbl_8053F748 * lbl_80539D44[0]) {
                outDir->z = 0.0f;
                outDir->y = 0.0f;
                outDir->x = 0.0f;
            } else {
                f32 s = ee8f4_invsqrt(l2);
                ee8f4_scale(&best, outDir, s);
            }
        }
    } else {
        if (outLen != 0) {
            *outLen = ee8f4_sqrt(bestLen);
        }
    }
}

/* --- 0x801F52A4 ----------------------------------------------------------
 * Slot-8 prize spawner: rolls the shared LCG twice, uses the configured table
 * entry for a->field_18C to pick a name/count, then spawns local[0+i] actors
 * (local[4+i] name) per row and scatters each one on a ring. */

extern "C" void fn_801F52A4(Actor* a) {
    u32 rnd1Bits;
    u32 rnd2Bits;
    Vec p1;
    Vec p2;
    u32 name[2];
    u32 param[2];
    u32 count[2];
    u32 i;
    u32 j;
    s32 id;
    s32 idx = a->field_18C;

    u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 1013904223;
    rnd1Bits = (*seed >> 9) | 0x3f800000;
    f32 roll = *(f32*)&rnd1Bits - lbl_8053F774;
    if (roll < lbl_80469D48[idx]) {
    } else {
        return;
    }
    *seed = *seed * 0x19660d + 1013904223;
    rnd2Bits = (*seed >> 9) | 0x3f800000;
    name[0] = lbl_8053F728;
    name[1] = lbl_8053F72C;
    param[0] = lbl_80543F40;
    param[1] = lbl_80543F44;
    count[0] = lbl_80543F48;
    count[1] = lbl_80543F4C;

    switch (lbl_80469D78[idx * 8 + (s32)(lbl_8053F7A4 * (*(f32*)&rnd2Bits - lbl_8053F774))]) {
    case 1:
        count[0] = 1;
        name[0] = 0x48415254;
        break;
    case 2:
        count[0] = 2;
        name[0] = 0x48415254;
        break;
    case 3:
        count[0] = 1;
        name[0] = 0x52555059;
        break;
    case 4:
        count[0] = 1;
        name[0] = 0x52555059;
        param[0] = 1;
        break;
    case 5:
        name[0] = 0x52555059;
        count[0] = 1;
        param[0] = 2;
        break;
    case 6:
        name[0] = 0x52555059;
        count[0] = 1;
        param[0] = 3;
        break;
    case 7:
        name[0] = 0x52555059;
        count[0] = 1;
        param[0] = 4;
        break;
    case 8:
        name[0] = 0x52555059;
        count[0] = 1;
        param[0] = 5;
        break;
    case 9:
        count[0] = 5;
        name[0] = 0x52555059;
        break;
    case 10:
        count[0] = 10;
        name[0] = 0x52555059;
        break;
    case 11:
        name[0] = 0x52555059;
        count[0] = 5;
        param[0] = 1;
        break;
    case 12:
        name[0] = 0x52555059;
        count[0] = 10;
        param[0] = 1;
        break;
    case 13:
        name[0] = 0x52555059;
        count[0] = 20;
        name[1] = 0x52555059;
        count[1] = 20;
        param[1] = 1;
        break;
    }
    f32 x = a->field_0C.x;
    f32 zero = lbl_8053F740;
    f32 scale = lbl_8053F7DC;
    f32 dy = a->field_0C.y - a->field_0C.z;
    for (i = 0; i < 2 && name[i] != 0x4e554c4c; i++) {
        u32 n = count[i];
        param[i] |= 0x26001e00;
        f32 spread = scale * (f32)i;
        for (j = 0; j < n; j++) {
            register f32 xy, z;
            register f32* src = (f32*)&p1;
            register f32* dst = (f32*)&p2;
            p1.x = x;
            p1.y = dy;
            p1.z = zero;
            id = Actor_CreateByID(fn_801F856C(), name[i], a->field_04, (f32*)&p1, param[i], -1, -1);
            if (id >= 0 && n > 1) {
                register void* child = fn_801F666C(fn_801F856C(), id);
                if (child != 0) {
                    // clang-format off
                    __asm {
                        psq_l  xy, 0(src), 0, 0
                        lfs    z,  8(src)
                        psq_st xy, 0(dst), 0, 0
                        stfs   z,  8(dst)
                    }
                    // clang-format on
                    f32 step = spread / (f32)n;
                    f32 astep = step;
                    if (astep < zero) {
                        astep = -astep;
                    }
                    p2.x += lbl_8053F7B0 *
                            lbl_8052EBC0[((s32)(lbl_8053F7E0 * astep) & 0x7ff) * 2 + 1];
                    f32 s;
                    if (step < zero) {
                        s = -lbl_8052EBC0[((s32)(lbl_8053F7E4 * step) & 0x7ff) * 2];
                    } else {
                        s = lbl_8052EBC0[((s32)(lbl_8053F7E0 * step) & 0x7ff) * 2];
                    }
                    p2.y += lbl_8053F7B0 * s;
                    register f32* out = (f32*)((u8*)child + 0xc);
                    z = p2.z;
                    // clang-format off
                    __asm {
                        psq_l  xy, 0(dst), 0, 0
                        psq_st xy, 0(out), 0, 0
                        stfs   z,  8(out)
                    }
                    // clang-format on
                }
            }
        }
    }
}

/* ==== atu7 fn_801F23BC (append block) ==== */
static inline void ATU7_setTVec3f(register const f32* src, register f32* dst) {
    register f32 xy, z;
    __asm {
        psq_l  xy, 0(src), 0, 0
        lfs    z,  8(src)
        psq_st xy, 0(dst), 0, 0
        stfs   z,  8(dst)
    }
}
extern "C" u8 fn_801F23BC(Actor* a, u32 id, void* f0C, void* f18, void* p80, f32* out1, f32* out2, u32 c) {
    u8 more = 1;
    u32 ret = 0;
    Vec pos;
    Vec delta;
    f32 w = ((f32*)p80)[2] - ((f32*)p80)[0];
    f32 h = ((f32*)p80)[3] - ((f32*)p80)[1];
    ATU7_setTVec3f((const f32*)f18, (f32*)&pos);
    if (w > 0.01f) {
        if (h > 0.01f) {
            register f32 z, xy;
            register f32 nr, r;
            if (w < h) h = w;
            r = h;
            if (r > 8.0f) r = 8.0f;
            r -= 0.01f;
            r *= 0.5f;
            nr = -r;
            {
                register f32* f = (f32*)f0C;
                __asm {
                    psq_l xy, 0x0(f), 0, 0
                    psq_l z,  0x8(f), 1, 0
                }
            }
            while (more != 0) {
                u8 okx = 0;
                u8 oky = 0;
                register f32 dz, az, dxy, axy;
                {
                    register f32* pd = (f32*)&pos;
                    register f32* dd = (f32*)&delta;
                    __asm {
                        psq_l  axy, 0x0(pd), 0, 0
                        psq_l  az,  0x8(pd), 1, 0
                        ps_sub dxy, xy, axy
                        ps_sub dz,  z,  az
                        psq_st dxy, 0x0(dd), 0, 0
                        psq_st dz,  0x8(dd), 1, 0
                    }
                }
                if (delta.x > r) {
                    delta.y = delta.y * (r / delta.x);
                    delta.x = r;
                } else if (delta.x < nr) {
                    delta.y = delta.y * (nr / delta.x);
                    delta.x = nr;
                } else {
                    okx = 1;
                }
                if (delta.y > r) {
                    delta.x = delta.x * (r / delta.y);
                    delta.y = r;
                } else if (delta.y < nr) {
                    delta.x = delta.x * (nr / delta.y);
                    delta.y = nr;
                } else {
                    oky = 1;
                }
                if (okx != 0 && oky != 0) {
                    pos = *(Vec*)f0C;
                    more = 0;
                } else {
                    register f32 dz, az, dxy, axy;
                    {
                        register f32* pd = (f32*)&pos;
                        register f32* dd = (f32*)&delta;
                        __asm {
                            psq_l  axy, 0x0(pd), 0, 0
                            psq_l  dxy, 0x0(dd), 0, 0
                            psq_l  az,  0x8(pd), 1, 0
                            psq_l  dz,  0x8(dd), 1, 0
                            ps_add dxy, axy, dxy
                            ps_add dz,  az,  dz
                            psq_st dxy, 0x0(pd), 0, 0
                            psq_st dz,  0x8(pd), 1, 0
                        }
                    }
                }
                u8 ok = fn_801F172C(a, id, &pos, p80, out2, c);
                if (ok != 0) {
                    if (out1 != 0) {
                        ret = 1;
                        more = 0;
                        out1[0] = pos.x;
                        out1[1] = pos.y;
                        out1[2] = pos.z;
                    }
                }
            }

        }
    }
    return (u8)ret;
}
/* --- 0x801EF830: spawn the actor's effect / model ---------------------------
 * Guards on the actor slot, picks the effect id from the collision kind, then
 * fills an effect-argument block and hands it to one of three spawners:
 * the "enemy_both2" model path, the kind-7 model+matrix path and the generic
 * "kage" path. */




extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7) {
    if ((s32)mask == -1) {
        return;
    }
    if (idx >= 8) {
        return;
    }
    u8* mgr = (u8*)fn_802D6A9C();
    if (mgr[idx + 0x131df] != 0) {
        return;
    }
    s32 kind;
    s32 uVar3 = mask & 0x3ff;
    kind = fn_802265FC(pos, 0);
    u8 ok = 1;
    s32 n = 3;
    if (fn_802DEB58() != 0) {
        n = 2;
    }
    for (s32 i = 0; i < n; i++) {
        if ((u16)kind == lbl_8053F730[i]) {
            ok = 0;
            break;
        }
    }
    if (ok == 0) {
        return;
    }
    u8 alpha = 0xdf;
    EffArgs args;
    f32 mtx[3][4];
    Vec v20;
    Vec v14;
    Vec v8;
    args.f10.w = -1;
    args.f14.w = -1;
    for (u8 i = 0; i < 0x10; i++) {
        args.order[i] = i;
    }
    args.f10.w = -1;
    args.f14.w = 0;
    args.ptr = 0;
    args.b1c = 0;
    args.b1d = 0;
    args.b1e = 0;
    args.b1f = 1;
    args.b20 = 1;
    args.b21 = 0;
    args.b22 = 0;
    args.b23 = 0;
    args.b24 = 0;
    args.b25 = 0;
    args.b26 = 1;
    args.w28 = 3;
    args.b2c = 1;
    args.b2d = 0;
    args.b2e = 0;
    args.x30 = -1;
    args.x34 = 0;
    args.x38 = 2;
    args.f10.b[3] = 0xdf;
    if (pos[2] > lbl_8053F740) {
        f32 t = (f32)args.f10.b[3] - lbl_8053F74C * pos[2];
        f32 m = lbl_8053F778;
        if (m >= t) {
            m = t;
        }
        args.f10.b[3] = (u8)(s32)m;
    }
    if (p3 != 0) {
        if ((mask & 0x400) != 0) {
            args.f10.b[3] = (u8)((args.f10.b[3] * p3[0x13]) / 0xff);
        }
        args.b1c = p3[0x1c];
        args.b1d = p3[0x1d];
    }
    args.b1d = args.b1d - 1;
    args.w28 = 1;
    args.b2e = args.f10.b[3] >> 1;
    if ((u16)kind == 0x39 && uVar3 == 0 && pos[2] == lbl_8053F740) {
        v14.x = pos[0];
        v14.y = lbl_8053F77C + pos[1];
        v14.z = pos[2];
        u32 sel = (*(u32*)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x34) >> 2) & 3;
        u32 id2 = lbl_8053F738[sel] + 0x18f;
        args.b1d = args.b1d + 1;
        if (idx < 8) {
            EffResMgr* m = (EffResMgr*)*(void**)((u8*)lbl_8053AAF8 + 0xa4);
            void* name = (void*)m->load(0x534f4220, lbl_8046A020);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &v14, name, id2, &args, lbl_8053F774, lbl_8053F774);
        }
    } else if (uVar3 == 7) {
        v20.x = pos[0];
        v20.y = pos[1];
        v20.z = lbl_8053F780;
        PSMTXScale(mtx, lbl_8053F784, lbl_8053F74C, lbl_8053F74C);
        if (p3 != 0) {
            u8* o = *(u8**)(p3 + 0x18);
            if (o != 0) {
                f32 x = *(f32*)(o + 0xc);
                f32 y = *(f32*)(o + 0x1c);
                f32 z = *(f32*)(o + 0x2c);
                PSMTXConcat(mtx, o, mtx);
                mtx[0][3] = x;
                mtx[1][3] = y;
                mtx[2][3] = z;
            }
        }
        args.f10.b[0] = 0;
        args.f10.b[1] = 0;
        args.f10.b[2] = 0;
        args.f14.b[0] = 0x28;
        args.f14.b[1] = 0x28;
        args.f14.b[2] = 0x28;
        args.f14.b[3] = 0;
        args.ptr = mtx;
        if (p5 != 0) {
            if (idx < 8) {
                EffResMgr* m = (EffResMgr*)*(void**)((u8*)lbl_8053AAF8 + 0xa4);
                void* name = (void*)m->load(0x534f4220, p5);
                fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &v20, name, p6, &args, lbl_8053F774, lbl_8053F774);
            }
        } else {
            if (idx < 8) {
                fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), &v20, p7, &args);
            }
        }
    } else {
        f32 f = lbl_80469FA8[uVar3];
        v8.x = pos[0];
        v8.y = pos[1];
        v8.z = lbl_8053F740;
        if (idx < 8) {
            EffResMgr* m = (EffResMgr*)*(void**)((u8*)lbl_8053AAF8 + 0xa4);
            void* name = (void*)m->load(0x534f4220, lbl_8046A034);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &v8, name, uVar3, &args, f, lbl_8053F774);
        }
    }
}


/* --- 0x801F02BC: build the actor's hit/query record and submit it ----------
 * The record handed to fn_801F06F0 is either the caller's (p4, byte 0x13 must
 * be set) or a fixed template; the actor's kind (field_04) decides whether the
 * record path runs (kind <= 8) or the collision-manager path (kind >= 8).  A
 * kind of exactly 8 runs both.  The record is 0x3C bytes: 7 words, 11 bytes,
 * one word, 3 bytes, 3 words. */


extern "C" void fn_801F02BC(Actor* a, u8* p2, void* p3, Rec* p4, void* p5, s32 p6, u8 p7, f32 f6, f32 f7) {
    Vec v98;
    Vec v14;

    if (p4 != 0 && ((u8*)p4)[0x13] == 0) {
        return;
    }
    if ((s32)a->field_04 <= 8) {
        if (p6 != 0) {
            if (p6 == 2) {
                PSMTXScale(&v98, lbl_8053F774, lbl_8053F774, lbl_8053F74C);
            } else {
                PSMTXScale(&v98, lbl_8053F7A0, lbl_8053F7A0, lbl_8053F7A0);
            }
            if (p4 != 0) {
                u8  t2e = p4->b2e;
                u8  t2c = p4->b2c;
                u32 t30 = p4->w30;
                u32 t34 = p4->w34;
                u32 t18 = p4->w18;
                u32 t00 = p4->w00;
                u32 t04 = p4->w04;
                u32 t08 = p4->w08;
                u32 t0c = p4->w0c;
                u32 t10 = p4->w10;
                u32 t14 = p4->w14;
                u8  t1c = p4->b1c;
                u8  t1d = p4->b1d;
                u8  t1e = p4->b1e;
                u8  t1f = p4->b1f;
                u8  t20 = p4->b20;
                u8  t21 = p4->b21;
                u8  t22 = p4->b22;
                u8  t23 = p4->b23;
                u8  t24 = p4->b24;
                u8  t25 = p4->b25;
                u8  t26 = p4->b26;
                u32 t28 = p4->w28;
                u8  t2d = p4->b2d;
                u32 t38 = p4->w38;
                Rec rec;
                rec.b2c = t2c;
                rec.b2e = t2e;
                rec.w30 = t30;
                rec.w00 = t00;
                rec.w04 = t04;
                rec.w08 = t08;
                rec.w0c = t0c;
                rec.w10 = t10;
                rec.w14 = t14;
                rec.w18 = t18;
                rec.b1c = t1c;
                rec.b1d = t1d;
                rec.b1e = t1e;
                rec.b1f = t1f;
                rec.b20 = t20;
                rec.b21 = t21;
                rec.b22 = t22;
                rec.b23 = t23;
                rec.b24 = t24;
                rec.b25 = t25;
                rec.b26 = t26;
                rec.w28 = t28;
                rec.b2d = t2d;
                rec.w34 = t34;
                rec.w38 = t38;
                if (rec.w18 != 0) {
                    PSMTXConcat(&v98, &v98, &v98);
                }
                rec.w18 = (u32)&v98;
                fn_801F06F0(a, p2, p3, &rec, p5, f6, f7);
            } else {
                Rec rec2;
                u8* buf = (u8*)&rec2;
                u32 i;
                rec2.w10 = -1;
                rec2.w14 = -1;
                for (i = 0; (u8)i < 0x10; i += 8) {
                    buf[(u8)i] = i;
                    buf[(u8)(i + 1)] = i + 1;
                    buf[(u8)(i + 2)] = i + 2;
                    buf[(u8)(i + 3)] = i + 3;
                    buf[(u8)(i + 4)] = i + 4;
                    buf[(u8)(i + 5)] = i + 5;
                    buf[(u8)(i + 6)] = i + 6;
                    buf[(u8)(i + 7)] = i + 7;
                }
                rec2.w18 = 0;
                rec2.w10 = -1;
                rec2.w14 = 0;
                rec2.b1c = 0;
                rec2.b1d = 0;
                rec2.b1e = 0;
                rec2.b1f = 1;
                rec2.b20 = 1;
                rec2.b21 = 0;
                rec2.b22 = 0;
                rec2.b23 = 0;
                rec2.b24 = 0;
                rec2.b25 = 0;
                rec2.b26 = 1;
                rec2.w28 = 3;
                rec2.b2c = 1;
                rec2.b2d = 0;
                rec2.b2e = 0;
                rec2.w30 = -1;
                rec2.w34 = 0;
                rec2.w38 = 2;
                rec2.w18 = (u32)&v98;
                fn_801F06F0(a, p2, p3, &rec2, p5, f6, f7);
            }
        } else {
            fn_801F06F0(a, p2, p3, p4, p5, f6, f7);
        }
    }
    if ((s32)a->field_04 >= 8) {
        u32 n = a->field_D8;
        u32 flag = 1;
        u32 mode = 0;
        register Vec* d = &v14;
        register Actor* s = a;
        register f32 z, xy;
        // clang-format off
        __asm {
            psq_l  xy, 0xc(s), 0, 0
            lfs    z,  0x14(s)
            psq_st xy, 0(d),   0, 0
            stfs   z,  8(d)
        }
        // clang-format on
        if ((s32)n > 0) {
            u32 m = a->field_DC;
            if ((s32)n > (s32)(m - 0x19) || (s32)m < 0x19) {
                if (n & 2) {
                    flag = 0;
                } else if (n & 4) {
                    v14.x = v14.x + lbl_8053F774;
                } else {
                    v14.x = v14.x - lbl_8053F774;
                }
            }
        } else if ((s32)a->field_E0 > 0) {
            mode = 1;
        }
        if ((u8)flag != 0) {
            if (p2[0xa] == 0x32) {
                fn_803075AC(a->field_198, a->field_04, &v14, p3, (p6 != 0), 2, -1, p7, mode, 0);
            } else {
                fn_80307AC8(a->field_198, a->field_04, &v14, p3, p6, (u8)mode, -1);
            }
        }
    }
}

/* v09__5ActorFv - 100% (objdiff, functionRelocDiffs=none). Body from the v09 handover run.
 * The three source properties that matter: the loop start value is its own variable
 * (retail's li r4,0 / li r4,2 / mr r30,r4), the rand seed is read through a struct, and
 * the Vec components are written through an inline setter so MWCC evaluates the three
 * rand calls right-to-left while still colouring the FPRs as retail does. */
extern "C" void fn_802F601C(void* handle, f32* pos, f32 a, f32 b, s32 c, s32 d);
extern "C" void fn_801F6884();
extern "C" s32 fn_801F8544(void* mgr, u32 tag, u32 id, f32* pos, s32 n);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void fn_80458F9C(void* a, u32 b);

struct V09Rng { u8 pad[0xB4]; u32 seed; };
inline void v09Set(Vec* v, f32 x, f32 y, f32 z) { v->x = x; v->y = y; v->z = z; }
inline f32 v09Rand01() {
    V09Rng* r = (V09Rng*)lbl_8053AAF8;
    r->seed = r->seed * 1664525u + 1013904223u;
    u32 bits = (r->seed >> 9) | 0x3F800000;
    return *(f32*)&bits - 1.0f;
}

extern "C" u32 v09__5ActorFv(Actor* a, f32 dx, f32 dy, f32 spread) {
    if (a->field_188 == -1) {
        return 0;
    }
    a->field_188 = a->field_188 - 1;
    if ((a->field_188 & 7) == 0) {
        Vec pos;
        atu5SetVec3f((const f32*)&a->field_0C, (f32*)&pos);
        f32 half = 0.5f * spread;
        pos.x = pos.x + (dx + (spread * v09Rand01() - half));
        pos.y = pos.y + (dy + (spread * v09Rand01() - half));
        fn_8013CC50(a->field_04, &pos, 1.0f, 0x68, 2, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, &pos, 1.0f, 0x69, 2, 0, 0, 0, 1);
    }
    if ((a->field_188 & 0x1F) == 0) {
        fn_801F0E34(a, 0x30001, 0);
    }
    if (a->field_188 == 0) {
        if ((s32)a->field_04 < 8) {
            fn_802F601C(*(void**)((u8*)lbl_8053AB10 + 0x20), (f32*)&a->field_0C, 1.0f, 1.0f, 2, 0);
        }
        fn_8013CC50(a->field_04, (f32*)&a->field_0C, 0.3f, 0x59, 0, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, (f32*)&a->field_0C, 0.375f, 0x5A, 1, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, (f32*)&a->field_0C, 0.375f, 0x5B, 1, 0, 0, 0, 1);
        fn_801F0E34(a, 0x30001, 0);
        fn_801F856C();
        fn_801F6884();
        Vec pos;
        atu5SetVec3f((const f32*)&a->field_0C, (f32*)&pos);
        Actor_CreateByID(fn_801F856C(), (u32)0x474F4C44, a->field_04, (f32*)&a->field_0C, (u32)0x50, -1, -1);
        s32 start = 0;
        if (a->field_1A0 == 0x42575254) {
            if (a->field_90 == 1) {
                start = 2;
            }
        }
        for (s32 i = start; i < 5; i++) {
            pos.x = a->field_0C.x;
            pos.y = a->field_0C.y;
            pos.z = a->field_0C.z;
            s32 n = (i < 1) ? 7 : 4;
            s32 slot = fn_801F8544(fn_801F856C(), 0x52555059, a->field_04, (f32*)&pos, n);
            if (slot >= 0) {
                u8* e = (u8*)fn_801F666C(fn_801F856C(), slot);
                if (a->field_1A0 == 0x4647414E) {
                    Vec v;
                    v09Set(&v, 2.0f - 4.0f * v09Rand01(), 0.5f - v09Rand01(), 3.0f * v09Rand01() + 3.0f);
                    atu5SetVec3f((const f32*)&v, (f32*)(e + 0x3c));
                } else if (a->field_1A0 == 0x424F4943) {
                    Vec v;
                    v09Set(&v, 2.0f - 4.0f * v09Rand01(), -5.0f, 0.0f);
                    atu5SetVec3f((const f32*)&v, (f32*)(e + 0x3c));
                } else {
                    Vec v;
                    v09Set(&v, 2.0f - 4.0f * v09Rand01(), 2.0f - 4.0f * v09Rand01(), 3.0f * v09Rand01() + 3.0f);
                    atu5SetVec3f((const f32*)&v, (f32*)(e + 0x3c));
                }
            }
        }
        a->field_11C = 0;
        s32 id = a->field_16C;
        if (id != -1) {
            fn_802D7704(fn_802D6A9C(), id, a->field_1A8, a->field_04);
        } else {
            fn_802D766C(fn_802D6A9C(), a->field_1A8, a->field_04);
        }
        if ((a->field_1A0 == 0x42575254 && a->field_90 == 1) || a->field_1A0 == 0x47524F4B) {
            fn_80138B7C(lbl_8053AAF8);
        } else {
            fn_80458F9C(lbl_8053AF80, 0x3C);
        }
    }
    return 1;
}

/* --- 0x801F5E34: the TU's compiler-generated `__sinit` ----------------------
 * 548 B / 137 instructions whose only job is to register nine weak
 * JASPoolAllocObject<T>::memPool_ objects via __register_global_object (each
 * preceded by a `Guard == 0` check, a base-pool construct and a guard store).
 * MWCC emits the whole function from the nine object *definitions* below, so
 * none of it is written by hand.  The types are placeholders (the real nine T
 * are the audio/JAI pool types, owned by the audio units - see
 * docs/game/sinit.md 5): a type's identity only names the pool/guard/dtor
 * symbols, never the emitted instructions.  ~JASMemPool is deliberately only
 * *declared*, so this TU references the shared weak deleting dtors exactly the
 * way retail does instead of emitting nine private 0x54-byte copies (which
 * would also add nine extab entries).  The base construct is the inline
 * JASMemPool<T>::JASMemPool() : JASGenericMemPool(), so MWCC folds it and each
 * entry calls JASGenericMemPool::JASGenericMemPool (0x80028974) directly.
 * Layout notes: the DestructorChain nodes are at +0x0C*i off r31, i.e. this TU
 * contributes no statics of its own before the nine (retail delta 0), and the
 * chain array is lbl_804CAAD8 in the split. */
struct JASGenericMemPool {
    /* 0x00 */ void* mRunner;
    /* 0x04 */ s32 mFreeMemCount;
    /* 0x08 */ s32 mTotalMemCount;
    /* 0x0C */ u32 mUsedMemCount;
    JASGenericMemPool();
    ~JASGenericMemPool();
};

template <typename T>
struct JASMemPool : public JASGenericMemPool {
    JASMemPool() : JASGenericMemPool() {}
    ~JASMemPool();
};

template <typename T>
struct JASPoolAllocObject {
    static JASMemPool<T> memPool_;
};

struct Atu2PoolObj1 { u8 x[80]; };
struct Atu2PoolObj2 { u8 x[592]; };
struct Atu2PoolObj3 { u8 x[268]; };
struct Atu2PoolObj4 { u8 x[64]; };
struct Atu2PoolObj5 { u8 x[100]; };
struct Atu2PoolObj6 { u8 x[712]; };
struct Atu2PoolObj7 { u8 x[948]; };
struct Atu2PoolObj8 { u8 x[832]; };
struct Atu2PoolObj9 { u8 x[16]; };

template <> JASMemPool<Atu2PoolObj1> JASPoolAllocObject<Atu2PoolObj1>::memPool_;
template <> JASMemPool<Atu2PoolObj2> JASPoolAllocObject<Atu2PoolObj2>::memPool_;
template <> JASMemPool<Atu2PoolObj3> JASPoolAllocObject<Atu2PoolObj3>::memPool_;
template <> JASMemPool<Atu2PoolObj4> JASPoolAllocObject<Atu2PoolObj4>::memPool_;
template <> JASMemPool<Atu2PoolObj5> JASPoolAllocObject<Atu2PoolObj5>::memPool_;
template <> JASMemPool<Atu2PoolObj6> JASPoolAllocObject<Atu2PoolObj6>::memPool_;
template <> JASMemPool<Atu2PoolObj7> JASPoolAllocObject<Atu2PoolObj7>::memPool_;
template <> JASMemPool<Atu2PoolObj8> JASPoolAllocObject<Atu2PoolObj8>::memPool_;
template <> JASMemPool<Atu2PoolObj9> JASPoolAllocObject<Atu2PoolObj9>::memPool_;


/* --- 0x801F06F0: build the per-actor draw/light request --------------------
 * The only caller (0x801F02BC) passes, as p4, a 0x3C-byte record describing
 * the pending attachment/light: either one of its own stack records or its
 * own p4 unchanged.  p2 is the actor-ish node drawn by the renderer, p3 is
 * forwarded straight through, f6/f7 are the two render factors.
 *
 * The record layout below was recovered from the paired loads/stores the two
 * whole-record copies expand into (4 words, 8 bytes, 1 word, 10 bytes, 1 byte,
 * 1 word, 3 bytes, 3 words).
 *
 * p4 is declared const so MWCC hoists the record loads above the destination
 * stores (retail schedules the copy that way).  The `s32 d8` local mirrors the
 * hoisted field_D8 load retail keeps live across the record's default init. */
struct UnkDrawRec {
    /* 0x00 */ u8  field_00[0x10];
    /* 0x10 */ u8  field_10;
    /* 0x11 */ u8  field_11;
    /* 0x12 */ u8  field_12;
    /* 0x13 */ u8  field_13;
    /* 0x14 */ u8  field_14;
    /* 0x15 */ u8  field_15;
    /* 0x16 */ u8  field_16;
    /* 0x17 */ u8  field_17;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ u8  field_1C;
    /* 0x1D */ u8  field_1D;
    /* 0x1E */ u8  field_1E;
    /* 0x1F */ u8  field_1F;
    /* 0x20 */ u8  field_20;
    /* 0x21 */ u8  field_21;
    /* 0x22 */ u8  field_22;
    /* 0x23 */ u8  field_23;
    /* 0x24 */ u8  field_24;
    /* 0x25 */ u8  field_25;
    /* 0x26 */ u8  field_26;
    /* 0x28 */ u32 field_28;
    /* 0x2C */ u8  field_2C;
    /* 0x2D */ u8  field_2D;
    /* 0x2E */ u8  field_2E;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ u32 field_34;
    /* 0x38 */ u32 field_38;
};

/* 0x30-byte matrix handed to PSMTXConcat. */
struct UnkMtx30 {
    u32 w[0xC];
};

extern "C" {
void PSMTXIdentity(void* m);
void fn_801EF574(void* a, void* b, f32* v, void* rec);
extern void* lbl_8053AB10;
}

class UnkDrawObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4(u32 fourcc, void* p);
};

extern "C" void fn_801F06F0(Actor* a, void* p2, void* p3, const void* p4, void* p5, f32 f6, f32 f7) {
    if (static_cast<s32>(a->field_04) > 8) {
        return;
    }
    if (a->field_138 == 0) {
        fn_801EF830(a->field_04, (f32*)&a->field_0C, (u8*)const_cast<void*>(p4), (u32)p5, (u8*)p2,
                        (u32)p3, (u8*)0);
    }

    UnkDrawRec local;
    *reinterpret_cast<u32*>(&local.field_10) = 0xFFFFFFFF;
    *reinterpret_cast<u32*>(&local.field_14) = 0xFFFFFFFF;
    for (u8 i = 0; i < 0x10; i++) {
        local.field_00[i] = i;
    }
    s32 d8 = static_cast<s32>(a->field_D8);
    *reinterpret_cast<u32*>(&local.field_10) = 0xFFFFFFFF;
    *reinterpret_cast<u32*>(&local.field_14) = 0;
    local.field_18 = 0;
    local.field_1C = 0;
    local.field_1D = 0;
    local.field_1E = 0;
    local.field_1F = 1;
    local.field_20 = 1;
    local.field_21 = 0;
    local.field_22 = 0;
    local.field_23 = 0;
    local.field_24 = 0;
    local.field_25 = 0;
    local.field_26 = 1;
    local.field_28 = 3;
    local.field_2C = 1;
    local.field_2D = 0;
    local.field_2E = 0;
    local.field_30 = -1;
    local.field_34 = 0;
    local.field_38 = 2;

    if (d8 > 0) {
        if (p4 != 0) {
            local = *reinterpret_cast<const UnkDrawRec*>(p4);
        }
        if (static_cast<s32>(a->field_D8) > static_cast<s32>(a->field_DC) - 25 ||
            static_cast<s32>(a->field_DC) < 25) {
            s32 amount;
            if (static_cast<s32>(a->field_DC) < 25) {
                amount = (static_cast<s32>(a->field_D8) * 0xff) / static_cast<s32>(a->field_DC);
            } else {
                amount = ((static_cast<s32>(a->field_D8) - (static_cast<s32>(a->field_DC) - 25)) * 0xff) / 25;
            }
            if (static_cast<s32>(a->field_F8) == 2) {
                amount = static_cast<s32>(static_cast<f32>(amount) - 6.0f * a->field_0C.z);
                amount = amount <= 0 ? 0 : amount;
            }
            if (static_cast<s32>(a->field_FC) == 5) {
                local.field_14 += amount;
                local.field_15 += amount >> 1;
            } else {
                local.field_14 += amount;
                local.field_15 += amount;
                local.field_16 += amount;
            }
        }
    } else {
        if (p4 != 0) {
            local = *reinterpret_cast<const UnkDrawRec*>(p4);
        } else {
            local.field_30 = a->field_150;
        }
        if (a->field_138 != 0) {
            if (local.field_18 != 0) {
                UnkMtx30 m;
                PSMTXIdentity(&m);
                u32 f138 = a->field_138;
                m = *reinterpret_cast<UnkMtx30*>(local.field_18);
                PSMTXConcat(&m, (void*)f138, &m);
                local.field_18 = reinterpret_cast<u32>(&m);
            } else {
                local.field_18 = a->field_138;
            }
        }
    }

    if (static_cast<s32>(a->field_04) < 8) {
        /* The inner test duplicates the outer one; retail emits the (dead but
         * present) extra `bge` this produces, so it is kept deliberately. */
        if (static_cast<s32>(a->field_04) < 8) {
            UnkDrawObj* draw =
                *reinterpret_cast<UnkDrawObj**>(static_cast<u8*>(lbl_8053AAF8) + 0xA4);
            u32 res = draw->v4(0x534F4220, p2);
            fn_802F86CC(*reinterpret_cast<void**>(static_cast<u8*>(lbl_8053AB10) + 0x20),
                        &a->field_0C, (void*)res, (u32)p3, &local, f6, f7);
        }
    } else if (static_cast<s32>(a->field_04) == 8 && static_cast<u8*>(p2)[6] != 'g') {
        u8* mgr = static_cast<u8*>(fn_802D6A9C());
        Vec pos;
        register f32* dst = reinterpret_cast<f32*>(&pos);
        pos.z = a->field_0C.z;
        {
            register Actor* t = a;
            register f32 xy;
            // clang-format off
            __asm {
                psq_l  xy, 0xc(t), 0, 0
                psq_st xy, 0x0(dst), 0, 0
            }
            // clang-format on
        }
        pos.x += *reinterpret_cast<f32*>(mgr + 0xCC);
        pos.y += *reinterpret_cast<f32*>(mgr + 0xD0);
        fn_801EF574(p2, p3, dst, &local);
    }
}
