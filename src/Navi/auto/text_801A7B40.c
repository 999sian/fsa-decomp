// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801a7b40-0x801a7c3c (1 functions). split_file divides it into the game's real files.
#include "types.h"

typedef struct Words18 {
    u32 w[18];
} Words18;

typedef struct Words6 {
    u32 w[6];
} Words6;

typedef struct Navi801A7B40 {
    Words18 a;
    Words18 b;
    Words6 c;
    Words6 d;
} Navi801A7B40;

extern "C" Navi801A7B40 lbl_8029B0E0;

extern "C" void fn_801A7B40(void)
{
    u32* s = lbl_8029B0E0.a.w;
    u32* d = lbl_8029B0E0.b.w;
    u32 s0 = s[0], s1 = s[1], s2 = s[2], s3 = s[3], s4 = s[4], s5 = s[5], s6 = s[6], s7 = s[7], s8 = s[8];
    u32 s9 = s[9], s10 = s[10], s11 = s[11], s12 = s[12], s13 = s[13], s14 = s[14], s15 = s[15], s16 = s[16], s17 = s[17];
    u32 t0 = lbl_8029B0E0.c.w[0], t1 = lbl_8029B0E0.c.w[1], t2 = lbl_8029B0E0.c.w[2], t3 = lbl_8029B0E0.c.w[3], t4 = lbl_8029B0E0.c.w[4], t5 = lbl_8029B0E0.c.w[5];
    d[0] = s0; d[1] = s1; d[2] = s2; d[3] = s3; d[4] = s4; d[5] = s5; d[6] = s6; d[7] = s7; d[8] = s8;
    d[9] = s9; d[10] = s10; d[11] = s11; d[12] = s12; d[13] = s13; d[14] = s14; d[15] = s15; d[16] = s16; d[17] = s17;
    lbl_8029B0E0.d.w[0] = t0; lbl_8029B0E0.d.w[1] = t1; lbl_8029B0E0.d.w[2] = t2;
    lbl_8029B0E0.d.w[3] = t3; lbl_8029B0E0.d.w[4] = t4; lbl_8029B0E0.d.w[5] = t5;
}
