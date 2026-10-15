// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern "C" void fn_8008E364(u32);
extern "C" void fn_8008E4A4(u32);
extern "C" void fn_8008DF30(int, int);
extern "C" void PADControlMotor(int, int);
extern "C" int OSGetResetSwitchState(void);
extern "C" u8 lbl_8053A950;
extern "C" u8 lbl_8053A951;
extern "C" u32 lbl_8053A93C;
extern "C" u32 lbl_8053A940;
extern "C" u32 lbl_8053A954;
extern "C" u32 lbl_8053A938;
extern "C" float lbl_8053B8A0;
extern "C" float lbl_80539DA4;
extern "C" float lbl_80539DA0;
extern "C" u8 lbl_8053A934[];
extern "C" u32 lbl_80499470[];

void fn_8008D864(void)
{
    u8 val = lbl_8053A951;
    
    if (val != 0) {
        if (lbl_8053A950 == 1) {
            lbl_8053A951 = 1;
            lbl_8053A954 = 0xffffffff;
            
            u32 fn_ptr = lbl_8053A93C;
            if (fn_ptr != 0) {
                void (*fn)(u32) = (void (*)(u32))fn_ptr;
                u32 param = lbl_8053A940;
                fn(param);
            }
            lbl_8053A950 = 0;
        }
    } else {
        int result = OSGetResetSwitchState();
        if (result != 0) {
            lbl_8053A950 = 1;
        }
    }
}

void fn_8008D8E4(void)
{
    fn_8008E364(0);
    fn_8008E4A4(0xf0000000);
}

void fn_8008D910(u32 *param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[6] = 0;
    *(u8 *)((u32)param_1 + 0xc) = 0;
    *(u8 *)((u32)param_1 + 0xd) = 0;
    *(u8 *)((u32)param_1 + 0xe) = 0;
    *(u8 *)((u32)param_1 + 0xf) = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[11] = 0;
}

extern "C" void fn_8008DADC(u32 *param_1) {
    float f = lbl_8053B8A0;
    *(float *)param_1 = f;
    *(float *)((char *)param_1 + 4) = f;
    *(float *)((char *)param_1 + 8) = f;
    *(u16 *)((char *)param_1 + 0xc) = 0;
}

extern "C" void fn_8008DE64(u32 *param_1, int param_2) {
    short idx = *(short *)(param_2 + 0x7c);
    if (idx >= 0 && idx < 4) {
        lbl_8053A934[idx] = 0;
        fn_8008DF30(idx, 1);
    }
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    lbl_8053A938 = 0xf0000000;
}

extern "C" void fn_8008DED8(u32 param_1) {
    u32 mask = lbl_80499470[param_1];
    if ((lbl_8053A938 & mask) != 0) {
        PADControlMotor(param_1, 1);
        lbl_8053A934[param_1] = 1;
    }
}

