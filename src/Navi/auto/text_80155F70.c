// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80155f70-0x8015627c (3 functions). split_file divides it into the game's real files.

extern unsigned char lbl_802EB850[];
extern unsigned char lbl_802EB7D0[];
extern "C" unsigned char* fn_801561FC(unsigned int param_1, unsigned int param_2)
{
    unsigned char b = param_2;
    return (b != 0xff) ? lbl_802EB7D0 + (b << 4) + (unsigned char)param_1 : lbl_802EB850 + (unsigned char)param_1;
}

extern "C" void fn_80156238(unsigned char param_1, unsigned char param_2)
{
    unsigned char* p;
    if (param_2 != 0xff) {
        p = lbl_802EB7D0 + (param_2 << 4) + param_1;
    } else {
        p = lbl_802EB850 + param_1;
    }
    *p = 2;
}

