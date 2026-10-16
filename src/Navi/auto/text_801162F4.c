#include "types.h"

extern f32 lbl_80301470;  // SDA label
extern f32 lbl_80301498;  // SDA label

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801162f4-0x8011695c (12 functions). split_file divides it into the game's real files.

extern "C" void memset(void);
extern "C" void fn_801162F4(void) {
    memset();
}

extern "C" void fn_8011691C(unsigned short* param_1, unsigned short param_2);
extern "C" void* fn_801168BC(void* param_1) {
fn_8011691C((unsigned short*)param_1, 0);
    return param_1;
}

extern "C" void fn_8011691C(unsigned short* param_1, unsigned short param_2) {
    *param_1 = param_2;
}
extern "C" u8 lbl_802C5D58[];
extern "C" void* lbl_802FDC98;
extern "C" f32 lbl_80301470;
