#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

/* Actor with the 0x18 bytes of members that follow the base (size 0x250). */
struct ActorExt : Actor {
    /* 0x230 */ u32 m230;
    /* 0x234 */ u32 m234;
    /* 0x238 */ u32 m238;
    /* 0x23C */ u32 m23C;
    /* 0x240 */ s32 m240;
    /* 0x244 */ s32 m244;
    /* 0x248 */ u32 m248;
    /* 0x24C */ s32 m24C;
};


extern "C" char lbl_804A8010[];
extern "C" void __dt__5ActorFv(void* p, int how);
extern "C" Actor* fn_802A8220(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8010;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802A8280(void)
{
    return;
}

#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" void* lbl_8053AF80;
extern "C" u8* fn_802D6A9C();
extern "C" void fn_801F0D20(void*,s32);
extern "C" void fn_80458880(void*,s32,s32);
extern "C" s32 fn_80138A30(void*);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void*,u32,u32,void*,u32,s32,s32);
extern "C" Actor* fn_801F666C(void*,s32);
extern "C" s32 fn_801F8544(void*,u32,u32,void*,u32);
extern "C" void fn_802D8050(void*,u32,u8,u8);
extern "C" const f32 sincosTable___5JMath[];
extern "C" f32 lbl_80540840,lbl_80540844,lbl_80540848,lbl_8054084C,lbl_80540850,lbl_80540854,lbl_80540858,lbl_8054085C,lbl_80540860,lbl_80540864,lbl_80540868,lbl_8054086C,lbl_80540870;

extern "C" void fn_802A8284(u8* this_) {
    this_[0] = 0;
}

extern "C" void fn_802A92FC(ActorExt* param_1)
{
    param_1->m248 = 0;
    param_1->m24C = 0;
    param_1->m230 = 0;
    param_1->m23C = 0;
    param_1->m240 = 0;
    param_1->m244 = (u8)param_1->field_90;
    if (param_1->m244 != 3 && param_1->m244 != 0xc && (u8)param_1->v11()) {
        param_1->field_11C = 0;
    }
    param_1->m240 = (param_1->field_90 >> 12) & 0xff;
    if (param_1->m240 == 0) {
        param_1->m240 = 0x100;
    }
    param_1->m234 = 1;
    param_1->m238 = 0;
    switch (param_1->m240) {
    case 0x28:
        param_1->m238 = 1;
        break;
    case 0x78:
        param_1->m238 = 2;
        break;
    case 200:
        param_1->m238 = 3;
        break;
    }
    if (param_1->m244 == 2 || param_1->m244 == 4 || (u32)param_1->m244 <= 1 || (u32)param_1->m244 - 8 <= 3 || param_1->m244 == 0xd) {
        param_1->m24C = 0x28;
    }
}


