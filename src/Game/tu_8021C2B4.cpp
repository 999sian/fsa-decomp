#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "Game/SinitPoolChain.h"


extern f32 lbl_8053FCFC;
void fn_8021CBA0(void* p);
extern "C" f32 lbl_8053FCFC;
extern "C" void fn_8021CBA0(void* p);
extern f32 lbl_8053FD18;
extern "C" u8 fn_8023F264(s32 idx);
extern "C" void* fn_8023E724(s32 idx);
extern "C" void* fn_801C0D70(void);
extern "C" u8 fn_801C0FEC(void* a, void* b, f32* out);
extern "C" s32 ClassifyBamAngleToQuadrant(s32 param);
extern "C" void fn_8021C9C4(int* param_1, int param_2);
extern "C" void fn_8021C468(u8* this_) {
    u8* obj = this_;
    s32 i;
    f32 pos[2];

    for (i = 0; i < 4; i++, obj += 0x48) {
        if (fn_8023F264(i) && fn_801C0FEC(fn_801C0D70(), fn_8023E724(i), pos)) {
            f32 f;
            obj[0] = 1;
            obj[1] = 0;
            *(s32*)(obj + 0x4) = i;
            f32* src = (f32*)fn_8023E724(*(s32*)(obj + 0x4));
            *(f32*)(obj + 0x8) = src[0];
            *(f32*)(obj + 0xc) = src[1];
            *(f32*)(obj + 0x10) = pos[0];
            *(f32*)(obj + 0x14) = pos[1];
            f32* src2 = (f32*)fn_8023E724(*(s32*)(obj + 0x4));
            f = lbl_8053FCFC;
            *(f32*)(obj + 0x18) = src2[0];
            *(f32*)(obj + 0x1c) = src2[1];
            *(f32*)(obj + 0x20) = src2[2];
            *(f32*)(obj + 0x24) = f;
            *(f32*)(obj + 0x28) = f;
            *(f32*)(obj + 0x2c) = f;
            f32 angle = JMath::atanTable_.atan2_(*(f32*)(obj + 0x8) - *(f32*)(obj + 0x10),
                                                 *(f32*)(obj + 0xc) - *(f32*)(obj + 0x14));
            fn_8021C9C4((int*)(obj + 0x30), ClassifyBamAngleToQuadrant((u16)(s32)(angle * lbl_8053FD18)));
        } else {
            obj[1] = 1;
        }
    }
}

extern "C" u8* fn_8021C5B0(u8* this_) {
    f32 f = lbl_8053FCFC;
    this_[0] = 0;
    this_[1] = 0;
    *(s32*)(this_ + 0x4) = -1;
    *(f32*)(this_ + 0x8) = f;
    *(f32*)(this_ + 0xc) = f;
    *(f32*)(this_ + 0x10) = f;
    *(f32*)(this_ + 0x14) = f;
    *(f32*)(this_ + 0x18) = f;
    *(f32*)(this_ + 0x1c) = f;
    *(f32*)(this_ + 0x20) = f;
    *(f32*)(this_ + 0x24) = f;
    *(f32*)(this_ + 0x28) = f;
    *(f32*)(this_ + 0x2c) = f;
    fn_8021CBA0(this_ + 0x30);
    return this_;
}
