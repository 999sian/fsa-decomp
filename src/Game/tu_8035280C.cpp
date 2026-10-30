#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Box.h"


extern "C" char lbl_804ACBF0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8035280C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804ACBF0;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8035286C(void)
{
    return;
}

extern "C" char* lbl_8053AB10;
extern "C" char* lbl_8053AAF8;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
#include "JSystem/JMath/JMath.h"
#define I(p,o) (*(s32*)((char*)(p)+(o)))
#define U(p,o) (*(u32*)((char*)(p)+(o)))
#define F(p,o) (*(f32*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define V(p,o) (*(JGeometry::TVec3<f32>*)((char*)(p)+(o)))
extern "C" void* lbl_8053AD70;
extern "C" void* lbl_8053AED0;
extern "C" void fn_80134FC4(void*,s32);
extern "C" void fn_80134FBC(void*,s32);
extern "C" void fn_8037AE00(void*);
extern "C" void fn_8037AE30(void*);
extern "C" void fn_8030C380(void*,void*);
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" s32 fn_801F7A08(void*,u32);
extern "C" void fn_8043D67C(void*,s32,s32,s32);
extern "C" void fn_8043D874(void*,s32,s32,s32);
extern "C" u8 fn_8022F514(s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_8013A884(u32*);
#pragma auto_inline off
inline f32 turtleRand() {
    return ((JMARandFast*)(lbl_8053AAF8+0xb4))->get_ufloat_1();
}
extern "C" void fn_80352870(char* p)
{
    char* sub;
    s32 state = *(s32*)(p + 0x230);
    if (state != 0 && state != 7) {
        sub = *(char**)(lbl_8053AB10 + 0x30);
        if (*(u8*)(sub + 0x284) == 0) {
            *(u8*)(sub + 0x284) = 1;
            *(f32*)(sub + 0x28c) = 1.0f;
        }
        *(u8*)(*(char**)(lbl_8053AB10 + 0x20) + 0x216) = 1;
        *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x17d) = 1;
    }
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8018330C(u32* out);
#pragma peephole reset
#pragma opt_propagation reset
#pragma scheduling reset
#pragma exceptions reset
#pragma use_lmw_stmw reset
extern "C" void fn_8035335C(void* this_) {
    char* p = (char*)this_;
    char* mgr;
    u32 buf;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x238) = 0;
    mgr = (char*)fn_802D6A9C();
    *(JGeometry::TBox2f*)(p + 0x26c) = *(JGeometry::TBox2f*)(mgr + 0xcc);
    *(u32*)(p + 0x230) = 0;
    fn_8018330C(&buf);
    *(u32*)(p + 0x23c) = buf;
    *(u32*)(p + 0x240) = *(u32*)(p + 0x23c);
    *(f32*)(p + 0x244) = (f32)(*(u32*)(p + 0x23c) >> 24);
    *(f32*)(p + 0x248) = (f32)((*(u32*)(p + 0x23c) >> 16) & 0xff);
    *(f32*)(p + 0x24c) = (f32)((*(u32*)(p + 0x23c) >> 8) & 0xff);
    *(f32*)(p + 0x250) = (f32)(*(u32*)(p + 0x23c) & 0xff);
    *(f32*)(p + 0x254) = -(0.4f * *(f32*)(p + 0x244)) / 30.0f;
    *(f32*)(p + 0x258) = -(0.4f * *(f32*)(p + 0x248)) / 30.0f;
    *(f32*)(p + 0x25c) = -(0.4f * *(f32*)(p + 0x24c)) / 30.0f;
    *(f32*)(p + 0x264) = 0.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x260) = 0.0f;
}
extern "C" void fn_803534A0(void) {
}

