#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158c28-0x80158c9c (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_80158C9C(void);
extern "C" void fn_80150958(void* p, u32 v);
extern "C" void PPCSync(void);
extern "C" void fn_801D134C(u32 v);
extern "C" u32 fn_801D1314(void);
extern u32 lbl_802FF4A8;
extern u32 lbl_802FF520;
extern u16 lbl_802FF4A4;
extern "C" void fn_80158C28(void* param_1) {
    u32 v;
    u8 pad[8];
    fn_80150958(param_1, fn_80158C9C());
    v = lbl_802FF4A8;
    lbl_802FF520 = 0;
    PPCSync();
    fn_801D134C(lbl_802FF4A4 | 0xbabe0000);
    while (fn_801D1314() != 0) {}
    fn_801D134C(v);
    while (fn_801D1314() != 0) {}
}
