// RNBW_80129B0C: .text 0x80129B0C-0x8012A5EC (actor RNBW)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#define Vec SDKVec
#include "JSystem/JGeometry/Vec.h"
#undef Vec
#include "Game/Actor.h"

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* manager, s32 kind);
extern "C" void* fn_8013CC50(u32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern const u16 lbl_80465098[];
extern const u16 lbl_804650A4[];
extern const f32 lbl_8053CB48;
extern const f32 lbl_8053CB4C;
extern const f32 lbl_8053CB50;
extern const f32 lbl_8053CB54;
extern const f32 lbl_8053CB58;

// ---- from Game/Rnbw_ctor_8012A364.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E610[];

extern "C" void* fn_8012A364(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E610;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = -1;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(s32*)((char*)this_ + 0x240) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    return this_;
}

extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void fn_801EE434(void* handle);
struct RnbwActor {
    u8 pad[0x23c];
    void* mHandles[5];
    void release(int i) { fn_801EE434(mHandles[i]); mHandles[i] = 0; }
};

inline void releaseHandle(void*& h) { fn_801EE434(h); h = 0; }

extern "C" s32 fn_8023DE58(s32 player);
extern "C" void fn_8022E088(s32 player, s32 index, JGeometry::TVec3f* out);
extern "C" void fn_8022DF48(s32 player);
extern "C" void fn_8023DF68(s32 player, JGeometry::TVec3f* delta);
extern "C" void fn_802D8050(void* mgr, s32 id, s32 state, s32 flag);
extern const f32 lbl_8053CB3C;


static inline void rnbwPolar(JGeometry::TVec3f& pos, const f32 radius, const s32 angle) {
    const f32* trig = &JMath::sincosTable_.mTable[(u16)angle >> 5].first;
    f32 y;
    f32 x;
    f32 sine;
    f32 cosine;
    cosine = *++trig;
    sine = *--trig;
    x = radius * cosine;
    y = radius * sine;
    pos.x = x;
    pos.y = y;
}

static inline bool rnbwContains(Actor* actor, s32 player, JGeometry::TVec3f& pos) {
    if (player < 0) return false;
    if ((s32)actor->field_04 != fn_8023DE58(player)) return false;
    f32 y1, x1, y0, x0;
    x0 = actor->field_60;
    y0 = actor->field_64;
    x1 = actor->field_68;
    y1 = actor->field_6C;
    for (s32 j = 0; j < 8; j++) {
        fn_8022E088(player, j, &pos);
        pos -= *(JGeometry::TVec3f*)&actor->field_0C;
        pos.z = 0.0f;
        f32 radians = JMath::atanTable_.atan2_(pos.y, pos.x);
        radians *= lbl_8053CB3C;
        s32 angle = radians;
        f32 radius = JGeometry::TUtilf::sqrt(pos.x * pos.x + pos.y * pos.y);
        pos.z = 0.0f;
        rnbwPolar(pos, radius, angle);
        bool hit = false;
        if (pos.x >= x0 && pos.y >= y0 && pos.x < x1 && pos.y < y1) hit = true;
        if (hit) {
            fn_8022DF48(player);
            return true;
        }
    }
    return false;
}

static inline void* rnbwEffect(u16 id, Actor* actor) {
    return fn_8013CC50(actor->field_04, &actor->field_0C, id, 0, -1, 0, 0, 1, lbl_8053CB48);
}
static inline void rnbwSpawn(Actor* actor, const u16* ids) {
    s32 i = 0;
    const u16* table = ids;
    void** hp = (void**)actor;
    for (; i < 5; i++, hp++, table++) {
        if (hp[0x8f] == 0) {
            u16 id = *table;
            hp[0x8f] = rnbwEffect(id, actor);
        }
    }
}
static inline void rnbwSpawn(const u16* ids, Actor* actor) {
    const u16* table = ids;
    void** hp = (void**)actor;
    s32 i = 0;
    for (; i < 5; i++, hp++, table++) {
        if (hp[0x8f] == 0) {
            u16 id = *table;
            hp[0x8f] = rnbwEffect(id, actor);
        }
    }
}
static inline void rnbwUpdateSpawn(const u16* ids, Actor* actor) {
    s32 i = 0;
    const u16* table = ids;
    void** hp = (void**)actor;
    for (; i < 5; i++, hp++, table++) {
        if (hp[0x8f] == 0) {
            u16 id = *table;
            hp[0x8f] = rnbwEffect(id, actor);
        }
    }
}
static inline void rnbwUpdateSpawn(Actor* actor, const u16* ids) {
    const u16* table = ids;
    void** hp = (void**)actor;
    s32 i = 0;
    for (; i < 5; i++, hp++, table++) {
        if (hp[0x8f] == 0) {
            u16 id = *table;
            hp[0x8f] = rnbwEffect(id, actor);
        }
    }
}
extern "C" void fn_80129B0C(void* this_) {
    JGeometry::TVec3f movement;
    JGeometry::TVec3f testPos;
    JGeometry::TVec3f delta;
    s32 id;
    Actor* actor = (Actor*)this_;
    actor->Actor::v03();
    s32 state = *(s32*)((char*)this_ + 0x238);
    switch (state) {
    case 0:
        if ((u8)actor->v11()) {
            *(s32*)((char*)this_ + 0x238) = 1;
            switch (*(s32*)((char*)this_ + 0x238)) {
            case 1:
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39f, 0, -1, 0, 0, 1, lbl_8053CB48);
                rnbwUpdateSpawn(lbl_80465098, actor);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x3a0, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39b, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39c, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39d, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39e, 0, -1, 0, 0, 1, lbl_8053CB48);
            } else {
                rnbwUpdateSpawn(actor, lbl_804650A4);
            }
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_801F0E34(this_, 0x5004d, 0);
                *(s32*)((char*)this_ + 0x234) = 0;
            }
            break;
            case 0:
            default:
                break;
            }
        }
        break;
    case 1:
        for (s32 i = 0; i < 4; i++) {
            if (rnbwContains(actor, i, testPos)) {
                delta = *(JGeometry::TVec3f*)&actor->field_0C;
                delta -= *(JGeometry::TVec3f*)&actor->field_18;
                movement = delta;
                fn_8023DF68(i, &movement);
            }
        }
        if (*(s32*)((char*)this_ + 0x234) >= 0) {
            (*(s32*)((char*)this_ + 0x234))++;
            if (*(s32*)((char*)this_ + 0x234) >= 420) {
                fn_801F0E34(this_, 0x5004e, 0);
                *(s32*)((char*)this_ + 0x234) = -1;
            }
        }
        {
            id = *(s32*)((char*)this_ + 0x230);
            if (id >= 0) fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
        }
        break;
    }
}

#pragma opt_propagation off
extern "C" void fn_8012A008(void* this_) {
    Actor* actor = (Actor*)this_;
    actor->Actor::v01();
    *(s32*)((char*)this_ + 0x230) = (*(u32*)((char*)this_ + 0x90) >> 22) & 0x1f;
    if ((u8)actor->v11()) {
        *(s32*)((char*)this_ + 0x238) = 1;
        switch (*(s32*)((char*)this_ + 0x238)) {
        case 1:
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39f, 0, -1, 0, 0, 1, lbl_8053CB48);
                rnbwSpawn(lbl_80465098, actor);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x3a0, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39b, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39c, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39d, 0, -1, 0, 0, 1, lbl_8053CB48);
                fn_8013CC50(actor->field_04, &actor->field_0C, 0x39e, 0, -1, 0, 0, 1, lbl_8053CB48);
            } else {
                rnbwSpawn(actor, lbl_804650A4);
            }
            if (fn_802D800C(fn_802D6A9C(), *(s32*)((char*)this_ + 0x230)) == 0) {
                fn_801F0E34(this_, 0x5004d, 0);
                *(s32*)((char*)this_ + 0x234) = 0;
            }
            break;
        case 0:
        default:
            break;
        }
    }
    *(f32*)((char*)this_ + 0x60) = lbl_8053CB4C;
    *(f32*)((char*)this_ + 0x64) = lbl_8053CB50;
    *(f32*)((char*)this_ + 0x68) = lbl_8053CB54;
    *(f32*)((char*)this_ + 0x6c) = lbl_8053CB58;
    *(f32*)((char*)this_ + 0x70) = *(f32*)((char*)this_ + 0x60);
    *(f32*)((char*)this_ + 0x74) = *(f32*)((char*)this_ + 0x64);
    *(f32*)((char*)this_ + 0x78) = *(f32*)((char*)this_ + 0x68);
    *(f32*)((char*)this_ + 0x7c) = *(f32*)((char*)this_ + 0x6c);
    *(f32*)((char*)this_ + 0x80) = *(f32*)((char*)this_ + 0x60);
    *(f32*)((char*)this_ + 0x84) = *(f32*)((char*)this_ + 0x64);
    *(f32*)((char*)this_ + 0x88) = *(f32*)((char*)this_ + 0x68);
    *(f32*)((char*)this_ + 0x8c) = *(f32*)((char*)this_ + 0x6c);
}
#pragma optimization_level 3
extern "C" void* fn_8012A2E0(void* this_, s16 freeFlag) {
    s32 i;
    void* self = this_;
    s16 flag = freeFlag;
    if (self != 0) {
        *(void**)self = lbl_8049E610;
        i = 0;
        void** p = (void**)self;
        s32 zero = i;
        do {
            releaseHandle(p[0x8f]);
            i++;
            p++;
        } while (i < 5);
        __dt__5ActorFv(self, 0);
    }
    if (flag > 0) __dl__FPv(self);
    return self;
}
#pragma optimization_level 4
#include "JSystem/JAudio/JASFakeMatchFSA.h"
