#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801a53a0-0x801a7b40 (33 functions). split_file divides it into the game's real files.

struct VObj_801A7A38 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

extern "C" void fn_801E10DC(void* p);
extern u8 lbl_8029B188[];

extern "C" void fn_801A59E8(void);
extern "C" void fn_801A59C8(void) {
    fn_801A59E8();
}

extern "C" BOOL fn_801A602C(u8* param_1) {
    if (param_1[1] >= 0x80 && param_1[1] <= 0xBB) {
        return TRUE;
    }
    return FALSE;
}

extern "C" void fn_80190684(void* param_1, u16 param_2);
extern u8 lbl_802EE470[];
extern "C" u16 fn_801A6050(void* param_1) {
    return *(u32*)((u8*)param_1 + 1);
}

extern "C" void fn_801A6214(void* param_1, const u16* param_2) {
    fn_80190684(param_1, *param_2);
}

extern "C" void fn_801A6238(u8* param_1) {
    if (*param_1 == 1) {
        *(u8**)(lbl_802EE470 + 0x118) = param_1 + 4;
    } else {
        *(u8**)(lbl_802EE470 + 0x118) = NULL;
    }
}

extern "C" BOOL fn_801A7990(u32** param_1, u32* param_2) {
    param_2[1] = 0;
    param_2[2] = 0;
    u32* p = (u32*)param_2[11];
    p[1] = 0;
    p[2] = 0;
    param_2[1] = (*param_1)[0];
    (*param_1)[0] = (u32)param_2;
    return TRUE;
}

extern "C" BOOL fn_801A79C4(u32** param_1, u32* param_2, u16 param_3) {
    param_2[1] = (*param_1)[param_3];
    (*param_1)[param_3] = (u32)param_2;
    return TRUE;
}

extern "C" void fn_801A79E4(u8* param_1) {
    fn_801E10DC(param_1);
}

