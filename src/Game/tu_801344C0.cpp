#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JFramework/JFWSystem.h"
#include "JSystem/JFramework/JFWDisplay.h"
#include "JSystem/JUtility/JUTProcBar.h"
#include "dolphin/os.h"
#include "dolphin/dvd.h"
#include "JSystem/JKernel/JKRExpHeap.h"

struct FSAStackObj {
    u8 _00[0xa8];
    u8 _a8;
    u8 _a9[7];
};

extern "C" {
extern u8 lbl_80529DEC[];
extern const _GXRenderModeObj lbl_8048C1B8;
extern const _GXRenderModeObj lbl_8048C17C;
extern u8 lbl_8051C1A0[];
extern s32 lbl_8053ADE8;
extern u8* lbl_8053AAF0;
extern u8* lbl_8053AAF8;
extern void* lbl_8053ACA8;
void OSSetSaveRegion(void*, void*);
u32 OSGetResetCode(void);
u32 OSGetProgressiveMode(void);
void init__9JFWSystemFv(void);
void fn_8008E364(u32);
void fn_8008CF54(void*, s32);
void fn_803BA980(void*);
void* fn_8045A080(void*);
void* fn_804009CC(void*);
void fn_80401FEC(s32, void*, s32);
void fn_803B9E2C(void*);
void fn_8008D15C(void);
u8 fn_802B1DCC(void*);
u8 fn_802B1D7C(void*);
s32 fn_802B1D60(void*);
void* fn_8008E328(s32);
void fn_802B1D98(void*);
s32 fn_80401518(s32*);
void fn_80136828(void*);
void fn_80137300(void*);
void fn_803FF420(void*);
void fn_803FFAA8(void*);
void fn_803FF2C4(void);
void fn_80139300(void);
void fn_80138C9C(void*);
void* create__12JKRSolidHeapFUlP7JKRHeapb(u32, void*, bool);
void* create__10JKRExpHeapFUlP7JKRHeapb(u32, void*, bool);
void* __nw__FUlP7JKRHeapi(u32, void*, s32);
void* __nw__FUl(u32);
void becomeCurrentHeap__7JKRHeapFv(void*);
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void main(void)
{
    FSAStackObj obj0;
    FSAStackObj obj1;
    FSAStackObj obj2;
    FSAStackObj obj3;
    int i;
    s32 n;
    void* initObject;
    void* p;
    void* solidHeap;
    void* expHeap;
    bool bVar1;
    bool bVar2;
    s32 t;

    JFWSystem::CSetUpParam::maxStdHeaps = 1;
    JFWSystem::CSetUpParam::sysHeapSize = 0x200000;
    JFWSystem::CSetUpParam::fifoBufSize = 0x40000;

    for (i = 0; i < 32; ++i) {
        lbl_80529DEC[0x216 + i] = *(u8*)(0x80700000 + i);
    }

    OSSetSaveRegion((void*)0x80700000, (void*)0x8070001F);

    u8* reset = lbl_80529DEC;
    if (*(u16*)&reset[0x216] != 0xA759 || *(u16*)&reset[0x218] != 0xDC96) {
        *(u16*)&reset[0x216] = 0xA759;
        *(u16*)&lbl_80529DEC[0x218] = 0xDC96;
        lbl_80529DEC[0x21a] = 0;
        lbl_80529DEC[0x21b] = 0;
        lbl_80529DEC[0x21c] = 0;
        lbl_80529DEC[0x21d] = 0;
        lbl_80529DEC[0x21e] = 0;
        lbl_80529DEC[0x21f] = 0;
        lbl_80529DEC[0x220] = 0;
        lbl_80529DEC[0x221] = 0;
        lbl_80529DEC[0x222] = 0xff;
        lbl_80529DEC[0x223] = 0;
        lbl_80529DEC[0x225] = 0;
        lbl_80529DEC[0x226] = 0;
    }
    if (OSGetResetCode() == 0) {
        lbl_80529DEC[0x221] = 0;
        lbl_80529DEC[0x222] = 0xff;
        lbl_80529DEC[0x223] = 0;
        lbl_80529DEC[0x225] = 0;
        lbl_80529DEC[0x226] = 0;
    }

    if (lbl_80529DEC[0x226] == 1) {
        if (OSGetProgressiveMode() == 1) {
            JFWSystem::CSetUpParam::renderMode = &lbl_8048C1B8;
        } else {
            JFWSystem::CSetUpParam::renderMode = &lbl_8048C17C;
        }
    } else {
        JFWSystem::CSetUpParam::renderMode = &lbl_8048C17C;
    }

    JFWSystem::init();
    fn_8008E364(0xf0000000);
    fn_8008CF54(&obj0, 0);
    fn_8008CF54(&obj1, 1);
    fn_8008CF54(&obj2, 2);
    fn_8008CF54(&obj3, 3);
    obj1._a8 = 0;
    obj2._a8 = 0;
    obj3._a8 = 0;
    JFWDisplay::createManager(0, JKRHeap::sSystemHeap, JUTXfb::EXfbNumber(2), true);
    JFWDisplay::getManager()->clearAllXfb();
    fn_803BA980(lbl_8051C1A0);
    solidHeap = create__12JKRSolidHeapFUlP7JKRHeapb(0x180000, JKRHeap::sRootHeap, false);
    expHeap = create__10JKRExpHeapFUlP7JKRHeapb(0xffffffff, JKRHeap::sRootHeap, false);
    initObject = __nw__FUlP7JKRHeapi(0x90, expHeap, 0);
    if (initObject != NULL) {
        initObject = fn_8045A080(initObject);
    }
    becomeCurrentHeap__7JKRHeapFv(expHeap);
    *(void**)&lbl_80529DEC[4] = solidHeap;
    *(void**)&lbl_80529DEC[8] = expHeap;
    *(void**)&lbl_80529DEC[0xc] = initObject;
    *(u8*)((u8*)JUTProcBar::getManager() + 0x10c) = 0;
    *(u8*)((u8*)JUTProcBar::getManager() + 0x130) = 0;
    solidHeap = create__10JKRExpHeapFUlP7JKRHeapb(0x800, expHeap, false);
    fn_80401FEC(OSGetThreadPriority(OSGetCurrentThread()) - 1, solidHeap, 0);
    p = __nw__FUlP7JKRHeapi(0x7c, expHeap, 0);
    if (p != NULL) {
        p = fn_804009CC(p);
    }
    lbl_8053AAF0 = (u8*)p;
    bVar1 = false;

    for (;;) {
        do {
            fn_803B9E2C(lbl_8051C1A0);
            if (DVDGetDriveStatus() != -1) {
                fn_8008D15C();
            }
            if (!fn_802B1DCC(lbl_8053ACA8) && fn_802B1D7C(lbl_8053ACA8)) {
                t = fn_802B1D60(lbl_8053ACA8);
                if (t != 0 && t != 1 && t != 2 && t != 3) {
                    t = -1;
                }
                p = fn_8008E328(t);
                bVar2 = false;
                if (*(s16*)((u8*)p + 0x7c) != -1 && *((u8*)p + 0x98) != 0) {
                    bVar2 = true;
                }
                if (!bVar2) {
                    fn_802B1D98(lbl_8053ACA8);
                }
            }
            if (lbl_80529DEC[0x251] != 0 && lbl_80529DEC[0x251] <= 0x5a) {
                lbl_80529DEC[0x251]++;
            }
        } while (fn_80401518(&lbl_8053ADE8) != 0);

        if (lbl_8053AAF0[0x78] >= 4) {
            JFWDisplay::getManager()->beginRender();
            if (lbl_80529DEC[0x251] == 0) {
                fn_80136828(lbl_8053AAF8);
            }
            JFWDisplay::getManager()->endRender();
            fn_80137300(lbl_8053AAF8);
            JFWDisplay::getManager()->endFrame();
        } else {
            JFWDisplay::getManager()->beginRender();
            fn_803FF420(lbl_8053AAF0);
            JFWDisplay::getManager()->endRender();
            fn_803FFAA8(lbl_8053AAF0);
            u32 state = lbl_8053AAF0[0x78];
            if (((state | ~4U) - ((state - 4U) >> 1)) >> 31) {
                fn_803FF2C4();
                p = __nw__FUl(0x11c);
                if (p != NULL) fn_80139300();
                lbl_8053AAF8 = (u8*)p;
                fn_80138C9C(p);
                JFWDisplay::getManager()->endFrame();
            } else {
                if (!bVar1) bVar1 = true;
                JFWDisplay::getManager()->endFrame();
            }
        }
    }
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
void __sinit_tu_801344C0_cpp(void)
{
}
