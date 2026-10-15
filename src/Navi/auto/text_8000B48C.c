// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8000b48c-0x8000d388 (30 functions). split_file divides it into the game's real files.
#include "types.h"

extern f32 lbl_802F0BC0[][2];
extern const f32 lbl_802FFB64;
extern const f32 lbl_802FFB60;
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801C5DA8(const f32 (*)[4], const f32 (*)[4], f32 (*)[4]);

extern "C" void fn_8000CB28(f32 matrix[3][4], u32 angle) {
    f32 m[3][4];
    f32 c = lbl_802F0BC0[(angle >> 5) & 0x7FF][1];
    f32 s = lbl_802F0BC0[(angle >> 5) & 0x7FF][0];
    m[0][0] = c;
    m[0][1] = lbl_802FFB64;
    m[0][2] = s;
    m[0][3] = lbl_802FFB64;
    m[1][0] = lbl_802FFB64;
    m[1][1] = lbl_802FFB60;
    m[1][2] = lbl_802FFB64;
    m[1][3] = lbl_802FFB64;
    m[2][0] = -s;
    m[2][1] = lbl_802FFB64;
    m[2][2] = c;
    m[2][3] = lbl_802FFB64;
    fn_801C5DA8(matrix, m, matrix);
}

extern "C" void fn_8000CBA4(f32 m[3][4], u32 angle) {
    f32 c = lbl_802F0BC0[(angle >> 5) & 0x7FF][1];
    f32 s = lbl_802F0BC0[(angle >> 5) & 0x7FF][0];
    m[0][0] = c;
    m[0][1] = -s;
    m[0][2] = lbl_802FFB64;
    m[0][3] = lbl_802FFB64;
    m[1][0] = s;
    m[1][1] = c;
    m[1][2] = lbl_802FFB64;
    m[1][3] = lbl_802FFB64;
    m[2][0] = lbl_802FFB64;
    m[2][1] = lbl_802FFB64;
    m[2][2] = lbl_802FFB60;
    m[2][3] = lbl_802FFB64;
}

extern "C" void fn_8000CBFC(f32 matrix[3][4], u32 angle) {
    f32 m[3][4];
    fn_8000CBA4(m, angle);
    fn_801C5DA8(matrix, m, matrix);
}

extern "C" void* fn_8000CEC4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}
