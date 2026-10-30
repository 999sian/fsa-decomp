#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80041b7c-0x80041c10 (1 functions). split_file divides it into the game's real files.

extern "C" void __register_global_object(void* obj, void* dtor, void* handle);
extern "C" void fn_80041C4C(void);
extern "C" void fn_80041C10(void);
extern "C" void fn_8000CEC4(void);
extern "C" void fn_80041B34(void);
extern "C" void fn_8003D4C4(void);
extern u8 lbl_802BF0E8[];
extern u32 lbl_802FF074;
extern f32 lbl_802FEF5C;
extern f32 lbl_802FFDD0;
extern u32 lbl_802469E8;
extern "C" void fn_80041B7C(void)
{
    u8* p = lbl_802BF0E8;
    __register_global_object(p + 0x64, (void*)fn_80041C4C, p + 0x58);
    __register_global_object(p + 0xa0, (void*)fn_80041C10, p + 0x94);
    __register_global_object(p + 0x108, (void*)fn_8000CEC4, p + 0xfc);
    lbl_802FF074 = lbl_802469E8;
    lbl_802FEF5C = lbl_802FFDD0;
    fn_8003D4C4();
    __register_global_object(&lbl_802FF074, (void*)fn_80041B34, p + 0x128);
}
