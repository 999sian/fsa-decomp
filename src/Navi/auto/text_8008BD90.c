#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008bd90-0x8008be14 (1 functions). split_file divides it into the game's real files.

extern s8 lbl_802C5394[];
extern u8 lbl_802C5388[];
extern f32 lbl_80300A48;
extern f32 lbl_80300A4C;
extern void* lbl_80284A14[];
extern "C" void fn_8008BD48(void);
extern "C" void* __register_global_object(void* object, void* destructor, void* registration);
extern "C" void fn_8008BD90(void) {
    *(void**)lbl_802C5394 = lbl_80284A14;
    lbl_802C5394[4] = -1;
    *(s32*)(lbl_802C5394 + 8) = 0;
    lbl_802C5394[36] = 0;
    lbl_802C5394[37] = 1;
    lbl_802C5394[38] = 0;
    *(u16*)(lbl_802C5394 + 20) = 0xff;
    *(u16*)(lbl_802C5394 + 22) = 0xff;
    *(u16*)(lbl_802C5394 + 24) = 0xff;
    *(u16*)(lbl_802C5394 + 26) = 0xff;
    *(f32*)(lbl_802C5394 + 12) = lbl_80300A48;
    *(f32*)(lbl_802C5394 + 16) = lbl_80300A4C;
    __register_global_object(lbl_802C5394, (void*)fn_8008BD48, lbl_802C5388);
}
__declspec(section ".ctors") void (*lbl_801F0C70)(void) = fn_8008BD90;
