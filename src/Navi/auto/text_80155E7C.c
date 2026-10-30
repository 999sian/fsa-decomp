// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80155e7c-0x80155f70 (1 functions). split_file divides it into the game's real files.

extern "C" void* memcpy(void*, const void*, unsigned long);
extern unsigned char lbl_80202008[];
extern unsigned char lbl_80202090[];
extern unsigned char lbl_802E5150[];
extern unsigned char lbl_802E9450[];
extern "C" void fn_80156434(unsigned char, unsigned char, unsigned char);
extern "C" void fn_80155E7C(unsigned char a, unsigned char b, unsigned long flag)
{
    unsigned char* src;
    unsigned char* dst;
    int i;

    if (flag) {
        src = lbl_80202008;
    } else {
        src = lbl_80202090;
    }
    if (b != 0xff) {
        dst = lbl_802E5150 + b * 0x860 + a * 0x86;
    } else {
        dst = lbl_802E9450 + a * 0x86;
    }
    if (flag) {
        memcpy(dst, src, 0x86);
    } else {
        for (i = 0; i < 0x86; i++) {
            if (*src != 0xff) {
                *dst = *src;
            }
            dst++;
            src++;
        }
    }
    fn_80156434(a, b, 0xff);
}
