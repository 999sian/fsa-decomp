// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157f50-0x80157f78 (1 functions). split_file divides it into the game's real files.

extern "C" unsigned char lbl_802E3B10[];
extern "C" void fn_80157F50(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5)
{
    unsigned int off = (param_1 & 0xff) * 0xbc;
    unsigned char* p = lbl_802E3B10 + off;
    *(unsigned int*)(p + 0xac) = param_2;
    *(unsigned int*)(p + 0xb4) = param_3;
    *(unsigned int*)(p + 0xb0) = param_4;
    *(unsigned int*)(p + 0xb8) = param_5;
}
