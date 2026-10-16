#include "types.h"
#include "JSystem/J2D/J2DGrafContext.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/JFramework/JFWDisplay.h"
#include "JSystem/JUtility/JUTVideo.h"


extern "C" s32 DVDGetDriveStatus(void);
extern "C" u32 fn_802B1DCC(void*);
extern "C" void fn_802B1DE8(void*);
extern "C" void fn_802B1BE0(void*, s32, u32, s32);
extern "C" void fn_80401318(s32, s32);
extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_8053ACA8;
extern "C" s32 lbl_8053ADE0;
extern "C" s8 lbl_8053ADE4;
extern "C" void* lbl_8053ADD8;
extern "C" void* lbl_8053AF80;
extern "C" void fn_80400DC4(s32, s32);
extern "C" void fn_804595E4(void*, s32);
extern "C" void fn_80401518(s32 param_1) {
    s32 status;
    s32 status2;

    if (lbl_8053ADE4 == 0) {
        lbl_8053ADE0 = 0;
        lbl_8053ADE4 = 1;
    }
    status = DVDGetDriveStatus();
    if (status != 0 && status != 1) {
        lbl_8053ADE0 = 1;
    }
    if (lbl_8053ADE0 != 0) {
        if (status == 0) {
            lbl_8053ADE0 = 0;
        } else {
            status2 = DVDGetDriveStatus();
            if (status2 != -1 && (u8)fn_802B1DCC(lbl_8053ACA8)) {
                fn_802B1DE8(lbl_8053ACA8);
                fn_802B1BE0(lbl_8053ACA8, 1, 0x80000000, 0);
            } else {
                fn_80401318(param_1, status);
            }
        }
    }
    if (lbl_8053ADE0 == 1) {
        lbl_80529DEC[0x250] = 1;
    }
}
