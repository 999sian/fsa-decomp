// BTBZ_8012CF5C: .text 0x8012CF5C-0x8012DAC0 (actor BTBZ)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern "C" void v01__5ActorFv(void* this_);
extern "C" u8* fn_802D6A9C(void);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern void* lbl_8049E7F0[];
extern "C" void v03__5ActorFv(void* this_);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* a, u32 b);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_802B39E8(void);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void fn_801F0D20(void* this_, s32 a);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" u8 fn_80236D14(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_80238548(s32 i, s32 a, void* pos, s32 b);
extern u8 lbl_80529DEC[];
extern u8* lbl_8053AB10;
extern f32 lbl_8053CC20;
extern f32 lbl_8053CC24;
extern f32 lbl_8053CC2C;

struct BTBZ_VObj {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual u8 v13();
    virtual void v14();
    virtual s32 v15();
};

struct BTBZ_Box {
    f32 x0, y0, x1, y1;
};

struct BTBZ_Vec {
    BTBZ_Vec() {}
    void set(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; }
    f32 x, y, z;
};

// Inlined state setter: writes the state at +0x234, then runs that state's entry code.
static inline void BTBZ_setState(u8* this_, s32 s) {
    *(s32*)(this_ + 0x234) = s;
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
        if (*(u8**)(this_ + 0x23C) != 0) {
            *(u32*)(*(u8**)(this_ + 0x23C) + 0xF4) |= 1;
        }
        break;
    case 1:
        if (*(u8**)(this_ + 0x23C) != 0) {
            *(u32*)(*(u8**)(this_ + 0x23C) + 0xF4) &= ~1;
        }
        *(s32*)(this_ + 0x238) = 0;
        {
            void* manager = fn_801F856C();
            s32 index = fn_801F7A08(manager, 0x53574556);
            manager = fn_801F856C();
            void* actor = fn_801F666C(manager, index);
            if (actor != 0) fn_802B39E8();
        }
        break;
    case 2: {
        BTBZ_Vec v;
        f32 zero = 0.0f;
        v.set(zero, zero, zero);
        u8* q = *(u8**)(lbl_8053AB10 + 0x24);
        v.x = -*(f32*)(q + 0x10);
        v.y = -*(f32*)(q + 0x20);
        v.z = 0.0f;
        fn_801F0E34(this_, 0x30036, 0);
        fn_8013CC50(*(s32*)(this_ + 4), &v, 0x1BC, 2, 2, 0, 0, 1, lbl_8053CC24);
        *(s32*)(this_ + 0x238) = 0;
        break;
    }
    }
}

// ---- fn_8012D6E8: init (spawns effect 0x58 at the room centre)
extern "C" void fn_8012CF5C(u8* this_) {
    v03__5ActorFv(this_);
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
        if (((BTBZ_VObj*)this_)->v15() == 0) {
            BTBZ_setState(this_, 1);
        } else if (((BTBZ_VObj*)this_)->v13()) {
            BTBZ_setState(this_, 1);
            if (*(u8*)(this_ + 0x231) != 0) {
                fn_801F0D20(this_, 6);
            }
        }
        break;
    case 1:
        if (((BTBZ_VObj*)this_)->v15() > 0 &&
            !((BTBZ_VObj*)this_)->v13()) {
            BTBZ_setState(this_, 0);
        }
        fn_801F0E34(this_, 0x30032, 0);
        {
            s32 limit = 300;
            *(s32*)(this_ + 0x238) += 1;
            if (*(u8*)(this_ + 0x230) != 0) {
                limit = 1000;
            }
            if (*(s32*)(this_ + 0x238) >= limit) {
                BTBZ_setState(this_, 2);
            }
        }
        break;
    case 2: {
        fn_801F0E34(this_, 0x30032, 0);
        for (s32 i = 0; i < 4; i++) {
            if (*(s32*)(this_ + 4) == fn_8023DE58(i) && fn_8023F264(i) && !fn_80230188(i) &&
                !fn_8022F478(i) && !fn_80236D14(i)) {
                f32* pf = (f32*)fn_8023E724(i);
                f32 pos[2];
                f32 x,y;
                x=pf[0];
                pos[0]=x;
                y=pf[1];
                pos[1]=y;
                x+=lbl_8053CC2C;
                pos[0]=x;
                pos[1]=y-lbl_8053CC2C;
                fn_80238548(i, 1, pos, 1);
                lbl_80529DEC[0x239] |= (u8)(1 << i);
            }
        }
        *(s32*)(this_ + 0x238) += 1;
        if (*(s32*)(this_ + 0x238) >= 0xAA) {
            BTBZ_setState(this_, 1);
        }
        break;
    }
    }
}

extern "C" const f32 lbl_8053CC28;

static inline void spawnBTBZInner(u8* this_) {
    BTBZ_Box box = *(BTBZ_Box*)(fn_802D6A9C() + 0xCC);
    f32 pos[3];
    f32 cy = box.y1;
    f32 cx = box.x1;
    f32 k = lbl_8053CC28;
    f32 x, y;
    x = box.x0 - cx;
    x = k * x + cx;
    y = box.y0 - cy;
    y = k * y + cy;
    pos[0] = x;
    pos[1] = y;
    pos[2] = lbl_8053CC20;
    *(void**)(this_ + 0x23C) = fn_8013CC50(*(s32*)(this_ + 4), pos, 0x58, 1, 0, 0, 0, 1, lbl_8053CC24);
}

extern "C" void fn_8012D6E8(u8* this_) {
    v01__5ActorFv(this_);
    *(u8*)(this_ + 0x230) = *(u32*)(this_ + 0x90) & 1;
    *(u8*)(this_ + 0x231) = (*(u32*)(this_ + 0x90) >> 1) & 1;
    if (*(void**)(this_ + 0x23C) == 0) {
        spawnBTBZInner(this_);
    }
    if (*(u8**)(this_ + 0x23C) != 0) {
        *(u32*)(*(u8**)(this_ + 0x23C) + 0xF4) |= 1;
    }
}

// ---- fn_8012D7D4: BTBZ dtor
extern "C" void* fn_8012D7D4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049E7F0;
        fn_801EE434(*(void**)(p + 0x23C));
        *(void**)(p + 0x23C) = 0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from Game/Btbz_ctor_8012D848.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);

extern "C" void* fn_8012D848(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E7F0;
    *(u8*)((char*)this_ + 0x230) = 0;
    *(u8*)((char*)this_ + 0x231) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
