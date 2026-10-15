#include "types.h"

extern void* lbl_804B2098;
extern void* lbl_80543ED8;
extern void* lbl_80543F0C;
extern void* lbl_80495470;
extern void* sInstance__33JASGlobalInstance__12JAISoundInfo;
extern void __dt__16JAIStreamDataMgrFv(void*, int);
extern void __dt__12JAISoundInfoFv(void*, int);
extern void __dl__FPv(void*);

extern "C" s32 fn_8045A6F4(void) {
    return -1;
}

extern "C" void fn_8045A6FC(void) {
}

extern "C" u32 fn_8045ACDC(void* param_1, u8* param_2) {
    u8 val = param_2[0];
    if (val == 0x1) {
        u32 (*fn)(void) = *(u32 (**)(void))((char*)(*(void**)param_1) + 0x4c);
        u32 result = fn();
        return (result & 0xff) - 1;
    } else {
        return param_2[1];
    }
}

extern "C" s32 fn_8045AD30(void* param_1, u8* param_2) {
    u8 val = param_2[0];
    if (val == 1) {
        return 1;
    } else if (val == 0) {
        return 0;
    } else {
        return -1;
    }
}

