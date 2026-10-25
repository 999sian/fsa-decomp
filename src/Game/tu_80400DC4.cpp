#include "types.h"
#include "JSystem/J2D/J2DGrafContext.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/JFramework/JFWDisplay.h"
#include "JSystem/JUtility/JUTVideo.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JUtility/JUTFont.h"


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
extern "C" f32 lbl_80543830;
extern "C" f32 lbl_80543834;
extern "C" f32 lbl_80543838;
extern "C" f32 lbl_8054383C;
extern "C" f32 lbl_80543840;
extern "C" f64 lbl_80543850;
extern "C" u8 lbl_80479CA0[];
extern "C" u8 lbl_80479F00[];
extern "C" u8 lbl_80479C60[];
extern "C" f32 lbl_80543844;
extern "C" f32 lbl_80543848;
extern "C" f32 lbl_8054384C;
extern "C" void fn_80400DC4(s32 param_1, s32 param_2) {
    u8* base = lbl_80479CA0 + 0x20;
    u8* str = base + 8 + *(u32*)(base + 4) + *(u32*)(base + param_2 * 4 + 0x10);
    const GXRenderModeObj* mode = JUTVideo::getManager()->getRenderMode();
    f32 f31 = (f32)(s32)mode->fbWidth;
    f32 f30 = lbl_80543834 + f31;
    J2DTextBox tb1(0x5445585431ULL, JGeometry::TBox2f(lbl_80543834, lbl_80543834, f30, lbl_80543838), (ResFONT*)lbl_80479F00, (const char*)str, -1, (J2DTextBoxHBinding)0, (J2DTextBoxVBinding)0);
    J2DTextBox tb2(0x5445585432ULL, JGeometry::TBox2f(lbl_80543834, lbl_80543834, f30, lbl_80543838), (ResFONT*)lbl_80479F00, (const char*)str, -1, (J2DTextBoxHBinding)0, (J2DTextBoxVBinding)0);
    J2DPicture pic(0x5049435431ULL, JGeometry::TBox2f(lbl_80543830, lbl_80543830, lbl_8054383C, lbl_80543840), (ResTIMG*)lbl_80479C60, (ResTLUT*)0);
    JUTResFont font((ResFONT*)lbl_80479F00, (JKRHeap*)0);
    JUTFont::TWidth tw;
    f32 lines[6];
    f32 maxW;
    f32 f29;
    u8* p;
    f32* lp;
    s32 yy;

    for (int i = 0; i < 6; i++) {
        lines[i] = lbl_80543834;
    }
    yy = 0x1b;
    lp = lines;
    p = str;
    while (*p != 0) {
        if (*p == 0xa) {
            yy += 0x1b;
            lp++;
        } else {
            font.getWidthEntry(*p, &tw);
            *lp = *lp + (f32)(u8)tw.w1;
        }
        p++;
    }
    maxW = lbl_80543834;
    for (int i = 0; i < 6; i++) {
        if (maxW < lines[i]) {
            maxW = lines[i];
        }
    }
    mode = JUTVideo::getManager()->getRenderMode();
    f29 = ((f32)(s32)mode->fbWidth - maxW) * lbl_80543844;
    f30 = lbl_8054384C + (f32)((s32)mode->efbHeight - (s32)(s16)yy) * lbl_80543844;
    tb2.draw(lbl_80543848 + f29, lbl_80543848 + f30, f31, (J2DTextBoxHBinding)2);
    tb1.draw(f29, f30, f31, (J2DTextBoxHBinding)2);
}

extern "C" void fn_80401318(s32 param_1, s32 param_2) {
    JFWDisplay::getManager()->beginRender();
    if (lbl_80529DEC[0x251] == 0 || lbl_80529DEC[0x251] > 0x5a) {
        j3dSys.drawInit();
        GXRenderModeObj *mode = JUTVideo::getManager()->getRenderMode();
        J2DOrthoGraph ortho(0.0f, 0.0f, (s32)mode->fbWidth, (s32)mode->efbHeight, -1.0f, 1.0f);
        JFWDisplay::getManager()->setClearColor(JUtility::TColor(0, 0, 0, 0));
        ortho.setPort();
        if (param_2 == 4) {
            fn_80400DC4(param_1, 2);
        } else if (param_2 == 5) {
            fn_80400DC4(param_1, 1);
        } else if (param_2 == 6) {
            fn_80400DC4(param_1, 3);
        } else if (param_2 == 0xb) {
            fn_80400DC4(param_1, 4);
        } else if (param_2 == 1) {
            fn_80400DC4(param_1, 0);
        } else if (param_2 == -1) {
            fn_80400DC4(param_1, 5);
        }
    }
    JFWDisplay::getManager()->endRender();
    JFWDisplay::getManager()->endFrame();
    if (param_2 == -1 && *((u8*)lbl_8053ADD8 + 4) != 0) {
        fn_804595E4(lbl_8053AF80, 1);
    }
}

extern "C" s32 fn_80401518(s32 param_1) {
    s32 status;
    s32 status2;
    if (lbl_8053ADE4 == 0) {
        lbl_8053ADE0 = 0;
        lbl_8053ADE4 = 1;
    }
    status = DVDGetDriveStatus();
    if (status != 0 && status != 1) lbl_8053ADE0 = 1;
    if (lbl_8053ADE0 != 0) {
        if (status == 0) lbl_8053ADE0 = 0;
        else {
            status2 = DVDGetDriveStatus();
            if (status2 != -1 && (u8)fn_802B1DCC(lbl_8053ACA8)) {
                fn_802B1DE8(lbl_8053ACA8);
                fn_802B1BE0(lbl_8053ACA8, 1, 0x80000000, 0);
            } else fn_80401318(param_1, status);
        }
    }
    status2 = lbl_8053ADE0;
    if (status2 == 1) lbl_80529DEC[0x250] = 1;
    return status2;
}
