#include "types.h"


extern void* lbl_8053AF80;
extern "C" int fn_804366B8(void* p);
extern "C" void fn_80436668(void* p);
extern "C" void fn_80458880(void* mgr, s32 id, s32 a);
extern void* lbl_8053AEC0;
extern "C" void fn_8043670C(void* p, s32 a);
extern "C" void fn_80431A9C(void* mgr, s32 id, u8 v, s32 a);
extern "C" void fn_803E29C8(u8* param_1) {
    fn_8043670C(*(void**)(param_1 + 0x5c), 0);
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xe;
}

extern "C" void fn_803E2A0C(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xd;
}

extern "C" void fn_803E3C80(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 7;
}

extern "C" void fn_803E3C94(u8* param_1) {
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 6;
}

extern "C" void fn_803E4308(u8* param_1) {
    *(s32*)(param_1 + 0x220) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1e0) = 5;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 4;
}

extern "C" void fn_803E4330(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 3;
}

extern "C" void fn_803E45FC(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 1;
}

extern "C" void fn_803E4610(u8* param_1) {
    *(s32*)(param_1 + 0x1e0) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0;
}

extern "C" void fn_803E462C(u8* param_1) {
    fn_80436668(*(void**)(param_1 + 0x5c));
}

extern "C" void fn_803E6A28(void) {}

extern "C" void fn_803E6A2C(u8* param_1) {
    if (fn_804366B8(*(void**)(param_1 + 0x5c)) != 0) {
        if (param_1[0x26e] == 0) {
            *(s32*)(param_1 + 0x1dc) = 9;
            param_1[0x26e] = 1;
        }
        if (*(s32*)(param_1 + 0x1bc) == 0) {
            *(s32*)(param_1 + 0x1b8) = 1;
        } else {
            *(s32*)(param_1 + 0x1b8) = 0;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" void fn_803ED5B4(u8* param_1) {
    if (param_1[0x26e] == 0) {
        *(s32*)(param_1 + 0x1dc) = 9;
        param_1[0x26e] = 1;
    }
    *(s32*)(param_1 + 0x1b8) = 1;
    fn_80458880(lbl_8053AF80, 0xb, -1);
}

