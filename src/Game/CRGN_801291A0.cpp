#include "types.h"
#include "Game/Actor.h"

extern "C" char lbl_8049E5B8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_80129200(Actor*);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
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
#pragma dont_inline reset
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
    u8 pad280[0x284 - 0x280];
};

extern s32 lbl_80465000[];
