#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JFramework/JFWSystem.h"
#include "JSystem/JFramework/JFWDisplay.h"
#include "JSystem/JUtility/JUTProcBar.h"
#include "dolphin/os.h"
#include "dolphin/dvd.h"

struct FSAStackObj {
    u8 _00[0xa8];
    u8 _a8;
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

void __sinit_tu_801344C0_cpp(void)
{
}
