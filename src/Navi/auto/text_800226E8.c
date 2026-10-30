#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800226e8-0x800227c8 (1 functions). split_file divides it into the game's real files.

extern "C" u8 lbl_802BB0FC[];
extern "C" u8 lbl_802BB0F0[];
extern "C" void fn_80011688();
extern "C" void fn_8000CEC4();
extern "C" void fn_8002295C();
extern "C" void fn_80022920();
extern "C" void fn_80022904();
extern "C" void fn_800228C8();
extern "C" void fn_800228B4();
extern "C" void fn_80022878();
extern "C" void fn_80022874();
extern "C" void fn_800227C8();
extern "C" void fn_801E0DB8(void*, void*, void*, u32, u32);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_800226E8(void) {
    u8* p = lbl_802BB0FC;
    fn_801E0DB8(p, fn_80011688, fn_8000CEC4, 0xc, 4);
    fn_801E0DB8(p + 0x1a4, fn_8002295C, fn_80022920, 0x4c, 4);
    fn_801E0DB8(p + 0x2d4, fn_80022904, fn_800228C8, 0xc, 10);
    fn_801E0DB8(p + 0x34c, fn_800228B4, fn_80022878, 8, 0x10);
    fn_801E0DB8(p + 0x3cc, fn_80022874, 0, 4, 4);
    __register_global_object(p, fn_800227C8, lbl_802BB0F0);
}
