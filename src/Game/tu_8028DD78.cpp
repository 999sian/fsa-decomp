#include "types.h"
#include "Game/Actor.h"


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

extern "C" f32* fn_8023E724(s32 index);
extern "C" s32 fn_80138A30(s32 value);
extern "C" s32 fn_8022E970(s32 value);
extern "C" u8 fn_8022F514(s32 index);
extern "C" s32 fn_8022F340(s32 index);
extern "C" s32 fn_8022F3DC(s32 value);
extern "C" s32 lbl_8053AAF8;
extern "C" void fn_8028DDD8(u8* param_1, s32* param_2) {
    f32 local[4];
    f32* pf;
    s32 i;
    s32 j;
    s32 k;
    s32 t;

    pf = local;
    for (i = 0; i < 4; i++, pf++) {
        s32 kind = *(s32*)(param_1 + 0x90) & 0xf;
        if (kind == 6 || kind == 7) {
            *pf = fn_8023E724(i)[1];
        } else {
            *pf = fn_8023E724(i)[0];
        }
    }

    switch (fn_80138A30(lbl_8053AAF8)) {
    case 2:
        k = 1;
        if (local[0] <= local[1]) {
            param_2[0] = 0;
            if (fn_8022E970(0) > 1) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022F514(i) && fn_8022F340(i) == 0) {
                        param_2[k++] = i;
                    }
                }
            }
            param_2[k++] = 1;
            if (fn_8022E970(1) > 1) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022F514(i) && fn_8022F340(i) == 1) {
                        param_2[k++] = i;
                    }
                }
            }
        } else {
            param_2[0] = 1;
            if (fn_8022E970(1) > 1) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022F514(i) && fn_8022F340(i) == 1) {
                        param_2[k++] = i;
                    }
                }
            }
            param_2[k++] = 0;
            if (fn_8022E970(0) > 1) {
                for (i = 0; i < 4; i++) {
                    if (fn_8022F514(i) && fn_8022F340(i) == 0) {
                        param_2[k++] = i;
                    }
                }
            }
        }
        break;
    case 3:
        param_2[0] = 0;
        param_2[1] = 1;
        param_2[2] = 2;
        param_2[3] = 3;
        for (i = 0; i < 2; i++) {
            if (local[param_2[i]] > local[param_2[i + 1]]) {
                t = param_2[i];
                param_2[i] = param_2[i + 1];
                param_2[i + 1] = t;
                i = -1;
            }
        }
        t = fn_8022F3DC(3);
        for (j = 0; j < 3; j++) {
            if (t == param_2[j]) {
                if (j == 2) {
                    param_2[3] = 3;
                } else {
                    for (k = 3; k > j + 1; k--) {
                        param_2[k] = param_2[k - 1];
                    }
                    param_2[j + 1] = 3;
                }
            }
        }
        break;
    case 4:
        param_2[0] = 0;
        param_2[1] = 1;
        param_2[2] = 2;
        param_2[3] = 3;
        for (i = 0; i < 3; i++) {
            if (local[param_2[i]] > local[param_2[i + 1]]) {
                t = param_2[i];
                param_2[i] = param_2[i + 1];
                param_2[i + 1] = t;
                i = -1;
            }
        }
        break;
    case 1:
    default:
        param_2[0] = 0;
        param_2[1] = 1;
        param_2[2] = 2;
        param_2[3] = 3;
        break;
    }
}

extern "C" void fn_8028E1E8(void) {
}

extern "C" void fn_8028E1EC(u8* this_) {
    s32 state = *(s32*)(this_ + 0x230);
    switch (state) {
    case 0:
        if (((Actor*)this_)->v13() == 0) {
            break;
        }
        *(s32*)(this_ + 0x230) = 2;
        break;
    case 2:
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 4:
        break;
    default:
        break;
    }
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
