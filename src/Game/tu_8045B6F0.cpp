#include "types.h"


extern "C" void fn_80255AC0(char* p);
#pragma optimization_level 4
extern "C" void fn_8045B6F0(char* p) {
    fn_80255AC0(&p[-0x18]);
}

extern "C" u32 lbl_8052DEE0[49];
extern "C" void __sinit_tu_8045B6F0_cpp() {
    lbl_8052DEE0[0] = 0x1000002;
    lbl_8052DEE0[1] = 0x3;
    lbl_8052DEE0[2] = 0x20011;
    lbl_8052DEE0[3] = 0x20034;
    lbl_8052DEE0[4] = 0x9;
    lbl_8052DEE0[5] = 0x30009;
    lbl_8052DEE0[6] = 0x12;
    lbl_8052DEE0[7] = 0x400b9;
    lbl_8052DEE0[8] = 0x50004;
    lbl_8052DEE0[9] = 0x5000d;
    lbl_8052DEE0[10] = 0x1000023;
    lbl_8052DEE0[11] = 0x42;
    lbl_8052DEE0[12] = 0x60000;
    lbl_8052DEE0[13] = 0x60001;
    lbl_8052DEE0[14] = 0x60002;
    lbl_8052DEE0[15] = 0x60003;
    lbl_8052DEE0[16] = 0x60004;
    lbl_8052DEE0[17] = 0x60005;
    lbl_8052DEE0[18] = 0x60006;
    lbl_8052DEE0[19] = 0x60007;
    lbl_8052DEE0[20] = 0x60008;
    lbl_8052DEE0[21] = 0x60009;
    lbl_8052DEE0[22] = 0x6000a;
    lbl_8052DEE0[23] = 0x6000b;
    lbl_8052DEE0[24] = 0x6000c;
    lbl_8052DEE0[25] = 0x6000d;
    lbl_8052DEE0[26] = 0x6000e;
    lbl_8052DEE0[27] = 0x6000f;
    lbl_8052DEE0[28] = 0x60010;
    lbl_8052DEE0[29] = 0x60011;
    lbl_8052DEE0[30] = 0x60012;
    lbl_8052DEE0[31] = 0x60013;
    lbl_8052DEE0[32] = 0x60014;
    lbl_8052DEE0[33] = 0x60015;
    lbl_8052DEE0[34] = 0x60016;
    lbl_8052DEE0[35] = 0x60017;
    lbl_8052DEE0[36] = 0x60018;
    lbl_8052DEE0[37] = 0x60019;
    lbl_8052DEE0[38] = 0x6001a;
    lbl_8052DEE0[39] = 0x3a;
    lbl_8052DEE0[40] = 0x3b;
    lbl_8052DEE0[41] = 0x6001b;
    lbl_8052DEE0[42] = 0x6001c;
    lbl_8052DEE0[43] = 0x6001d;
    lbl_8052DEE0[44] = 0x6001e;
    lbl_8052DEE0[45] = 0x6001f;
    lbl_8052DEE0[46] = 0x60020;
    lbl_8052DEE0[47] = 0x60021;
    lbl_8052DEE0[48] = 0x60022;
}

#pragma optimization_level reset
