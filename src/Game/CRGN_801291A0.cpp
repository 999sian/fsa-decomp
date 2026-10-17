#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

extern "C" char lbl_8049E5B8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_80129200(Actor*);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
struct CRGNState {
    u8 pad00[0x90];
    u32 flags90;
    u8 pad94[0x234 - 0x94];
    u32 field234;
    u8 pad238[0x240 - 0x238];
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
                case 0x4352544c:
                    flag = 0;
                    break;
                case 0x4c535449:
                    flag = 0;
                    break;
                case 0x4e4e4a4e:
                    flag = 0;
                    break;
                default:
                    flag = 1;
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

    p->field234 = p->flags90 & 0xf;
    p->flags280 |= 2;
    p->list248[0] = 10;
    p->list248[1] = 10;
    p->list248[2] = 10;
    p->list248[3] = 10;
    p->list248[4] = 10;
    p->list248[5] = 10;
    p->list248[6] = 10;
    p->list248[7] = 10;
    p->list248[8] = 10;
    p->list248[9] = 10;
    for (i = 10; i < 11; i++) {
        p->list248[i] = 10;
    }
    a = lbl_80465000;
    b = lbl_80465000 + 11;
    c = lbl_80465000 + 22;
    for (i = 0; i < 11; i++) {
        if ((p->flags90 >> a[i]) & 1) {
            p->flags280 |= 1 << b[i];
            p->list248[p->count240] = c[i];
            p->count240++;
        }
    }
    p->list270[0] = 1;
    p->list270[1] = 1;
    p->list270[2] = 1;
    p->list270[3] = 1;
    for (i = 0; i < 4; i++) {
        if ((p->flags90 >> lbl_80465000[33 + i]) & 1) {
            p->list270[p->count244] = i;
            p->count244++;
        }
    }
    p->list248[0] = 150;
}

#pragma dont_inline reset
