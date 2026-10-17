#include "types.h"

extern "C" void fn_801EE434(void*);
extern "C" void __dl__FPv(void*);
extern const float lbl_8053F69C;
extern const float lbl_8053F6A0;
extern const float lbl_8053F6A4;
extern const float lbl_8053F6A8;
extern const float lbl_8053F6AC;
extern const float lbl_8053F6B0;
extern const float lbl_8053F678;
extern "C" u16 fn_801CD664(s32);
extern const float lbl_8053F67C;
extern const float lbl_8053F698;
extern "C" char sincosTable___5JMath[];
extern "C" void* fn_8013CC50(void* mgr, f32* pos, u16 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" int fn_801EB648(void* param_1) {
    int result = 0;
    if ((unsigned char)(int)*(float*)((char*)param_1 + 0x54) != 0) {
        if (*(unsigned int*)((char*)param_1 + 0x34) != 0) {
            result = 1;
        } else if (*(unsigned int*)((char*)param_1 + 0x38) != 0) {
            result = 1;
        } else if (*(unsigned int*)((char*)param_1 + 0x3c) != 0) {
            result = 1;
        } else if (*(unsigned int*)((char*)param_1 + 0x40) != 0) {
            result = 1;
        } else if (*(unsigned int*)((char*)param_1 + 0x44) != 0) {
            result = 1;
        } else if (*(unsigned int*)((char*)param_1 + 0x48) != 0) {
            result = 1;
        } else if (*(unsigned int*)((char*)param_1 + 0x4c) != 0) {
            result = 1;
        }
    }
    return result;
}

extern "C" char* dtor_801EB8CC(char* p, s16 freeFlag) {
    if (p != 0) {
        for (s32 i = 0; i < 7; i++) {
            fn_801EE434(*(void**)(p + 0x34 + i * 4));
        }
        fn_801EE434(*(void**)(p + 0x50));
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char* fn_801EB950(char* p) {
    *(f32*)(p + 0x0) = lbl_8053F678;
    *(f32*)(p + 0x4) = lbl_8053F678;
    *(f32*)(p + 0x8) = lbl_8053F678;
    *(s32*)(p + 0xC) = 1;
    *(s32*)(p + 0x10) = 1;
    *(f32*)(p + 0x14) = lbl_8053F69C;
    *(f32*)(p + 0x18) = lbl_8053F6A0;
    *(f32*)(p + 0x1C) = lbl_8053F6A4;
    *(f32*)(p + 0x20) = lbl_8053F6A8;
    *(f32*)(p + 0x24) = lbl_8053F6AC;
    *(f32*)(p + 0x28) = lbl_8053F6B0;
    *(f32*)(p + 0x2C) = lbl_8053F6AC;
    *(s16*)(p + 0x30) = 0x600;
    *(s32*)(p + 0x50) = 0;
    *(f32*)(p + 0x54) = lbl_8053F678;
    *(f32*)(p + 0x58) = lbl_8053F678;
    *(u8*)(p + 0x5C) = 0;
    *(s16*)(p + 0x5E) = fn_801CD664(0x10000);
    *(s32*)(p + 0x34) = 0;
    *(s32*)(p + 0x38) = 0;
    *(s32*)(p + 0x3C) = 0;
    *(s32*)(p + 0x40) = 0;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4C) = 0;
    return p;
}

extern "C" void fn_801EBA14(char* p) {
    *(s32*)(p + 0x0) = 1;
    *(s32*)(p + 0x4) = 1;
    *(f32*)(p + 0x8) = lbl_8053F69C;
    *(f32*)(p + 0xc) = lbl_8053F6A0;
    *(f32*)(p + 0x10) = lbl_8053F6A4;
    *(f32*)(p + 0x14) = lbl_8053F6A8;
    *(f32*)(p + 0x18) = lbl_8053F6AC;
    *(f32*)(p + 0x1c) = lbl_8053F6B0;
    *(f32*)(p + 0x20) = lbl_8053F6AC;
    *(s16*)(p + 0x24) = 0x600;
}
