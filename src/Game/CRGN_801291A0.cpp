#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
extern "C" void* fn_802D6A9C(void);
extern "C" s32 Actor_CreateByID(void*, u32, u32, f32*, u32, s32, s32);
extern "C" void fn_801F0E34(Actor*, u32, s32);
extern void* lbl_8053AAF8;
extern const f32 lbl_8053CB24;
extern const f32 lbl_8053CB28;
#include "Game/SinitPoolChain.h"

extern "C" char lbl_8049E5B8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" s32 fn_80129200(Actor*);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
struct CRGNState {
    u8 pad00[0x90];
    u32 flags90;
    u8 pad94[0x234 - 0x94];
    u32 field234;
    s32 field238;
    u8 pad23c[0x240 - 0x23c];
    s32 count240;
    s32 count244;
    s32 list248[10];
    s32 list270[4];
    u32 flags280;
};

extern s32 lbl_80465000[];

extern "C" Actor* fn_801291A0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049E5B8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

#pragma opt_lifetimes off
extern "C" s32 fn_80129200(Actor* self)
{
    s32 item;
    s32 count;
    JGeometry::TVec3<f32> pos(self->field_0C);
    CRGNState* p = (CRGNState*)self;
    s32 room = self->field_04;
    u8* __restrict flags = (u8*)fn_802D6A9C() + 0x10000;
    if (flags[room + 0x31df] == 0) {
        pos.z = lbl_8053CB24;
    }
    s32 index = p->field234;
    if (index == 15) {
        if (p->count244 <= 0) {
            index = 1;
        } else {
            index = p->list270[(s32)((f32)p->count244 * ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1())];
        }
    }
    switch (index) {
    case 0:
        *(s32*)((u8*)self + 0x23c) = Actor_CreateByID(fn_801F856C(), 0x4352544c, self->field_04, &pos.x, p->flags280, -1, -1);
        break;
    case 2: {
        f32 random = ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1();
        count = p->count240;
        item = p->list248[(s32)((f32)count * random)];
        if (count == 0) {
            item = p->list248[(s32)(lbl_8053CB24 * ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1())];
        }
        u32 param;
        if ((((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() >= lbl_8053CB28 && item != 2) || item == 11) {
            param = item | 0x800180;
        } else {
            param = item | 0x400180;
        }
        *(s32*)((u8*)self + 0x23c) = Actor_CreateByID(fn_801F856C(), 0x4c535449, self->field_04, &pos.x, param, -1, -1);
        fn_801F0E34(self, 0x3004a, 0);
        break;
    }
    case 3:
        *(s32*)((u8*)self + 0x23c) = Actor_CreateByID(fn_801F856C(), 0x4e4e4a4e, self->field_04, &pos.x, 1, -1, -1);
        break;
    default:
        *(s32*)((u8*)self + 0x23c) = Actor_CreateByID(fn_801F856C(), 0x4352544c, self->field_04, &pos.x, 0, -1, -1);
        break;
    }
    *(s32*)((u8*)self + 0x238) = 0;
    return 1;
}
#pragma opt_lifetimes reset
extern "C" void fn_8012952C(Actor* p, s32 state) {
    switch (state) {
    case 0:
        break;
    case 1:
        *(s32*)((u8*)p + 0x23c) = -1;
        *(s32*)((u8*)p + 0x238) = 0;
        break;
    case 2:
        fn_80129200(p);
        break;
    }
    *(s32*)((u8*)p + 0x230) = state;
}

#pragma dont_inline on
extern "C" void fn_80129598(Actor* p) {
    s32 id;
    s32 threshold;
    s32 type;
    void* obj;
    u8 flag;

    if (p->v13() > 0 && (u8)p->v11() == 0) {
        return;
    }
    switch (*(s32*)((u8*)p + 0x230)) {
    case 0:
        id = *(s32*)((u8*)p + 0x23c);
        if (id < 0) {
            flag = 1;
        } else {
            obj = fn_801F666C(fn_801F856C(), id);
            if (obj == 0) {
                flag = 1;
            } else {
                type = *(s32*)((u8*)obj + 0x1a0);
                switch (type) {
                default:
                    flag = 1;
                    break;
                case 0x4352544c:
                case 0x4c535449:
                case 0x4e4e4a4e:
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            fn_8012952C(p, 1);
        }
        break;
    case 1:
        *(s32*)((u8*)p + 0x238) = *(s32*)((u8*)p + 0x238) + 1;
        threshold = 600;
        if (*(s32*)((u8*)p + 0x234) == 2) {
            threshold = 300;
        }
        if (*(s32*)((u8*)p + 0x238) >= threshold) {
            fn_8012952C(p, 2);
        }
        break;
    case 2:
        fn_8012952C(p, 0);
        break;
    }
}

extern "C" void fn_801296FC(CRGNState* p) {
    s32 i;
    s32* a;
    s32* b;
    s32* c;
    s32 v;

    p->field234 = p->flags90 & 0xf;
    p->flags280 |= 2;
    for (i = 0; i < 10; i++) {
        p->list248[i] = 10;
    }
    i = 10;
    do {
        p->list248[i] = 10;
        i++;
    } while (i < 11);
    a = lbl_80465000;
    b = lbl_80465000 + 11;
    c = lbl_80465000 + 22;
    for (i = 0; i < 11; i++) {
        if (((p->flags90 >> a[i]) & 1) == 1) {
            v = c[i];
            p->flags280 |= 1 << b[i];
            p->list248[p->count240] = v;
            p->count240++;
        }
    }
    p->list270[0] = 1;
    p->list270[1] = 1;
    p->list270[2] = 1;
    p->list270[3] = 1;
    for (i = 0; i < 4; i++) {
        if (((p->flags90 >> lbl_80465000[33 + i]) & 1) == 1) {
            p->list270[p->count244] = i;
            p->count244++;
        }
    }
    p->field238 = 150;
}

#pragma dont_inline reset
