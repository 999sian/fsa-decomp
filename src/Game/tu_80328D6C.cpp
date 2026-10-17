#include "Game/Actor.h"


extern "C" char lbl_804AB5D8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80328D6C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AB5D8;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, s32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" const f32 lbl_80541CE0;
extern "C" const char lbl_80471918[];
extern "C" void fn_80328DCC(u8* this_) {
    if (*(s32*)(this_ + 4) < 8) {
        void* res = ((void* (*)(void*, u32, const char*))(*(void***)(*(void**)(lbl_8053AAF8 + 0xA4)))[6])(*(void**)(lbl_8053AAF8 + 0xA4), 0x534F4220, lbl_80471918);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xC, res, 0x17A, lbl_80541CE0, lbl_80541CE0, 0);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xC, 0x17A, 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_803291D4(u8* p) {
    *(s32*)(p + 0x108) = 10000;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x238) = 0;
    *(u8*)(p + 0x239) = 0;
    *(u8*)(p + 0x23A) = 0;
    *(u8*)(p + 0x23B) = 0;
    *(s32*)(p + 0x114) = 4;
}

