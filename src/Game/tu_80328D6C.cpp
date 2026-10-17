#include "types.h"
#include "JSystem/JMath/Inline.h"

struct Actor;


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

extern "C" const f32 lbl_80541CE4;
extern "C" const f32 lbl_80541CE8;
extern "C" const f32 lbl_80541CEC;
extern "C" const f32 lbl_80541CF0;
extern "C" const f32 lbl_80541CF4;
extern "C" const f32 lbl_80541CF8;
extern "C" const f32 lbl_80541CFC;
extern "C" const f32 lbl_80541D00;
extern "C" u8 fn_801F2618(Actor* a, f32* out, u32 c);
extern "C" u8 fn_8023F264(s32 idx);
extern "C" u8 fn_8023EA28(s32 idx);
extern "C" void* fn_8023E724(s32 idx);
extern "C" u8 fn_8023B190(s32 idx, f32* rect, s32 room);
extern "C" u8 fn_80238548(s32 idx, s32 hit, f32* dst, s32 a3);
extern "C" void fn_802399D8(s32 idx, f32* rect, s32 room, s32 handle);
extern "C" u8 fn_80239718(s32 idx, s32 handle);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 zero, f32 a, f32 b);
extern "C" s32 fn_801F0E34(Actor* a, u32 code, u32 z);
extern "C" void fn_80328E7C(Actor* this_) {
    u8* p = (u8*)this_;
    f32* pos = (f32*)(p + 0xC);
    f32* vel = (f32*)(p + 0x3C);
    f32 rect[4];
    f32 out[2];
    u8 blocked;
    s32 i;
    u8 done = 0;

    rect[0] = *(f32*)(p + 0x60);
    rect[1] = *(f32*)(p + 0x64);
    rect[2] = *(f32*)(p + 0x68);
    rect[3] = *(f32*)(p + 0x6C);
    rect[0] += pos[0];
    rect[1] += pos[1];
    rect[2] += pos[0];
    rect[3] += pos[1];
    p[0x238] = 0;
    p[0x239] = 0;
    p[0x23A] = 0;
    p[0x23B] = 0;
    pos[0] += vel[0];
    pos[1] += vel[1];
    pos[2] += vel[2];
    blocked = fn_801F2618(this_, 0, 0);
    for (i = 0; i < 4; i++) {
        if (fn_8023F264(i)) {
            if (!fn_8023EA28(i)) {
                if (((f32*)fn_8023E724(i))[1] > pos[1]) {
                    if (pos[0] - lbl_80541CE4 < ((f32*)fn_8023E724(i))[0]) {
                        if (lbl_80541CE4 + pos[0] > ((f32*)fn_8023E724(i))[0]) {
                            if (*(s32*)(p + 0x230) == 1 && !blocked) {
                                if (fn_8023B190(i, rect, *(s32*)(p + 0x4))) {
                                    out[0] = lbl_80541CE8 * (rect[0] - rect[2]) + rect[2];
                                    out[1] = lbl_80541CE8 * (rect[1] - rect[3]) + rect[3];
                                    fn_80238548(i, *(s32*)(p + 0x114), out, 0x14);
                                    if (!done) {
                                        done = 1;
                                        fn_802399D8(i, rect, *(s32*)(p + 0x4), *(s32*)(p + 0x198));
                                        p[0x238 + i] = fn_80239718(i, *(s32*)(p + 0x198));
                                        if (*(s32*)(p + 0x230) == 0) {
                                            if (pos[0] - lbl_80541CEC < ((f32*)fn_8023E724(i))[0]) {
                                                if (lbl_80541CEC + pos[0] > ((f32*)fn_8023E724(i))[0]) {
                                                    *(s32*)(p + 0x230) = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    switch (*(s32*)(p + 0x230)) {
    case 0:
        break;
    case 1:
        if (blocked == 0) {
            if (done == 1) {
                fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, lbl_80541CF0, lbl_80541CF4);
                fn_801F0E34(this_, 0x3000F, 0);
                *(s32*)(p + 0x230) = 2;
                *(s32*)(p + 0x234) = 100;
            }
        } else {
            *(s32*)(p + 0x234) -= 1;
            if (*(s32*)(p + 0x234) <= 0) {
                *(s32*)(p + 0x230) = 3;
            }
        }
        break;
    case 2:
        if (pos[1] <= *(f32*)(p + 0x240)) {
            pos[1] = *(f32*)(p + 0x240);
            *(s32*)(p + 0x230) = 0;
        }
        break;
    case 3:
        break;
    }
    if (*(s32*)(p + 0x230) == 1) {
        if (vel[1] < lbl_80541CF8) {
            vel[1] = vel[1] + lbl_80541CFC;
        }
    } else if (*(s32*)(p + 0x230) == 3) {
        vel[1] = lbl_80541D00;
    } else {
        vel[1] = lbl_80541CF4;
    }
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

