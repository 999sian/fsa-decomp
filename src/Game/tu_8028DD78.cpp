#include "types.h"


extern "C" char __vt__4RASN[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_8028DD78(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4RASN;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8028E1E8(void) {
}

extern "C" void fn_8028F890(u8* param_1) {
    s32 kind = *(s32*)(param_1 + 0x90) & 0xf;
    switch (kind) {
    case 0:
    case 1:
    case 4:
        *(f32*)(param_1 + 0x60) = -40.0f;
        *(f32*)(param_1 + 0x64) = -10.0f;
        *(f32*)(param_1 + 0x68) = 40.0f;
        *(f32*)(param_1 + 0x6c) = 8.0f;
        break;
    case 5:
        *(f32*)(param_1 + 0x60) = -40.0f;
        *(f32*)(param_1 + 0x64) = -8.0f;
        *(f32*)(param_1 + 0x68) = 40.0f;
        *(f32*)(param_1 + 0x6c) = 10.0f;
        break;
    case 6:
        *(f32*)(param_1 + 0x60) = -8.0f;
        *(f32*)(param_1 + 0x64) = -40.0f;
        *(f32*)(param_1 + 0x68) = 10.0f;
        *(f32*)(param_1 + 0x6c) = 40.0f;
        break;
    case 7:
        *(f32*)(param_1 + 0x60) = -10.0f;
        *(f32*)(param_1 + 0x64) = -40.0f;
        *(f32*)(param_1 + 0x68) = 8.0f;
        *(f32*)(param_1 + 0x6c) = 40.0f;
        break;
    }
    *(s32*)(param_1 + 0x108) = 0;
    *(s32*)(param_1 + 0x230) = 0;
    *(s32*)(param_1 + 0x234) = 0;
    *(s32*)(param_1 + 0x268) = 0xff;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
