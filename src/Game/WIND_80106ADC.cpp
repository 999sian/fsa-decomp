// WIND_80106ADC: .text 0x80106ADC-0x80107360 (actor WIND)
// NOTE: all functions match except fn_80106EE0 (fmadds result registers f0/f1
// swapped vs f2/f0 when computing the room-centre position).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- shared declarations
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void fn_801EE434(void*);
void operator delete(void* p);
extern void* lbl_8049CC98[];

struct WIND_DeletableHead {
    u32 m0, m4;
};

struct WIND_Deletable : WIND_DeletableHead {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(s32);
};

extern "C" u8* fn_802D6A9C(void);

// ---- fn_80106ADC: push every player standing in this actor's room
extern "C" s32 fn_8023DE58(s32 player);
extern "C" u8 fn_8023F264(s32 player);
extern "C" u8 fn_80234D94(s32 player);
extern "C" u8 fn_8022D75C(s32 player);
extern "C" u8 fn_80230188(s32 player);
extern "C" s32 fn_8022CAF8(s32 player);
extern "C" u8 fn_8022F478(s32 player);
extern "C" void* fn_8023E724(s32 player);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" void fn_8023DFF4(s32 player, void* vel);

struct WIND_PushVec {
    void set(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; }
    void set2(f32 ax, f32 ay, f32 az) { z = az; x = ax; y = ay; }
    f32 x, y, z;
};

extern "C" void fn_80106ADC(u8* this_, s32 mode) {
    WIND_PushVec v;
    f32 speed = 1.0f;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    switch (mode) {
    case 0:
        break;
    case 2:
        speed *= 2.0f;
    case 1:
        switch (*(s32*)(this_ + 0x234)) {
        case 3:
            v.set(0.0f, -2.5f, 0.0f);
            break;
        case 2:
            v.set(0.0f, 2.5f, 0.0f);
            break;
        case 1:
            v.set(-speed, 0.0f, 0.0f);
            break;
        case 0:
            v.set(speed, 0.0f, 0.0f);
            break;
        }
        break;
    }
    s32 room;
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023DE58(i) != *(s32*)(this_ + 4)) continue;
        if (!fn_8023F264(i)) continue;
        if (fn_80234D94(i)) continue;
        if (fn_8022D75C(i)) continue;
        if (fn_80230188(i)) continue;
        if (fn_8022CAF8(i) == 4 && fn_8022F478(i)) continue;
        if ((u16)(fn_80226850(fn_8023E724(i), room = fn_8023DE58(i)) - 0x3EE) <= 1) continue;
        fn_8023DFF4(i, &v);
    }
}

// ---- fn_80106C84: toggles the wind on/off from its switch condition
extern "C" void v03__5ActorFv(void* this_);

class WIND_Actor {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual u8 vf34();
    virtual void vf38();
    virtual s32 vf3C();
};

struct WIND_Sound : WIND_DeletableHead {
    virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(void*);
};

static inline u8 WIND_isOn(u8* this_) {
    switch (*(s32*)(this_ + 0x238)) {
    case 1:
        if (fn_802D6A9C()[0x171] != 0) {
            return 1;
        }
        return 0;
    case 2:
        if (fn_802D6A9C()[0x171] == 0) {
            return 1;
        }
        return 0;
    case 0:
    default:
        if (((WIND_Actor*)this_)->vf3C() <= 0) {
            return 1;
        }
        return ((WIND_Actor*)this_)->vf34();
    }
}

extern "C" void fn_80106C84(u8* this_) {
    v03__5ActorFv(this_);
    s32 state = *(s32*)(this_ + 0x230);
    switch (state) {
    case 0:
        if (WIND_isOn(this_)) {
            if (*(u8**)(this_ + 0x240) != 0) {
                *(u32*)(*(u8**)(this_ + 0x240) + 0xF4) &= ~1;
            }
            *(s32*)(this_ + 0x230) = 1;
        }
        break;
    case 1:
        if (!WIND_isOn(this_)) {
            if (*(u8**)(this_ + 0x240) != 0) {
                *(u32*)(*(u8**)(this_ + 0x240) + 0xF4) |= 1;
            }
            *(s32*)(this_ + 0x230) = 0;
        }
        if (*(void**)(this_ + 0x244) != 0) {
            u32 id = 0x50027;
            (*(WIND_Sound**)(this_ + 0x244))->v14(&id);
        }
        fn_80106ADC(this_, *(s32*)(this_ + 0x230));
        break;
    case 2:
        fn_80106ADC(this_, state);
        break;
    }
    *(s32*)(this_ + 0x23C) += 1;
}

// ---- from Game/fn_80106EB0.cpp

extern "C" s32 fn_80456334(s32 a, void* ptr, s32 zero);

// fn_80106EB0(a, ptr): a small thunk - dereferences the first word of
// ptr into a stack temp and calls fn_80456334(a, &temp, 0). Reads as
// an "unwrap and forward" helper, likely a virtual-call trampoline or
// a param-adapter for fn_80456334.
extern "C" s32 fn_80106EB0(s32 a, void* ptr) {
    s32 temp = *(s32*)ptr;
    return fn_80456334(a, &temp, 0);
}

// ---- fn_80106EE0: init (spawns the wind effect at the room centre)
extern "C" void v01__5ActorFv(void* this_);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

struct WIND_Box {
    f32 x0, y0, x1, y1;
};

struct WIND_Vec {
    void set(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; }
    void set2(f32 ax, f32 ay, f32 az) { z = az; x = ax; y = ay; }
    f32 x, y, z;
};

extern "C" void fn_80106EE0(u8* this_) {
    v01__5ActorFv(this_);
    *(s32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xF;
    *(s32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 4) & 0xF;
    s32 state = *(s32*)(this_ + 0x234);
    WIND_Vec pos;
    WIND_Box b = *(WIND_Box*)(fn_802D6A9C() + 0xCC);
    f32 x1 = b.x1;
    f32 y1 = b.y1;
    pos.set(0.5f * (b.x0 - x1) + x1, 0.5f * (b.y0 - y1) + y1, 0.0f);
    switch (state) {
    case 0:
        *(void**)(this_ + 0x240) = fn_8013CC50(*(s32*)(this_ + 4), &pos, 0x505, 0, 0, 0, 0, 1, 1.0f);
        break;
    case 1:
        *(void**)(this_ + 0x240) = fn_8013CC50(*(s32*)(this_ + 4), &pos, 0x504, 0, 0, 0, 0, 1, 1.0f);
        break;
    }
    if (*(u8**)(this_ + 0x240) != 0) {
        *(u32*)(*(u8**)(this_ + 0x240) + 0xF4) |= 1;
    }
}

// ---- fn_80107014: WIND dtor
extern "C" void* fn_80107014(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CC98;
        fn_801EE434(*(void**)(p + 0x240));
        *(void**)(p + 0x240) = 0;
        WIND_Deletable* d = *(WIND_Deletable**)(p + 0x244);
        if (d != 0) {
            if (d != 0) {
                d->v30(1);
            }
            *(void**)(p + 0x244) = 0;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_801070B4_ctor.cpp

struct Actor {
    Actor();
    ~Actor();
};

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

extern void* lbl_8049CC98[];

class fn_801070B4_actor : public Actor {
public:
    fn_801070B4_actor();
};

fn_801070B4_actor::fn_801070B4_actor() : Actor() {
    *(void**)this = lbl_8049CC98;
    char* p = (char*)this;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 3;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(WaveController**)(p + 0x244) = new WaveController(0, 0, 8);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
