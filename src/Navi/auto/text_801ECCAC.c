// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801eccac-0x801ee900 (31 functions). split_file divides it into the game's real files.

extern "C" void fn_801ECD7C(void* dst, int val, unsigned long n)
{
    unsigned long v = (unsigned char)val;
    unsigned long i;

    dst = (unsigned char*)dst - 1;

    if (n >= 32) {
        i = (~(unsigned long)dst) & 3;

        if (i) {
            n -= i;
            do {
                dst = (unsigned char*)dst + 1;
                *(unsigned char*)dst = v;
            } while (--i);
        }

        if (v)
            v |= v << 24 | v << 16 | v << 8;

        i = n >> 5;

        dst = (unsigned long*)((unsigned char*)dst + 1) - 1;

        if (i)
            do {
                ((unsigned long*)dst)[1] = v;
                ((unsigned long*)dst)[2] = v;
                ((unsigned long*)dst)[3] = v;
                ((unsigned long*)dst)[4] = v;
                ((unsigned long*)dst)[5] = v;
                ((unsigned long*)dst)[6] = v;
                ((unsigned long*)dst)[7] = v;
                dst = (unsigned long*)dst + 8;
                *(unsigned long*)dst = v;
            } while (--i);

        i = (n & 31) >> 2;

        if (i)
            do {
                dst = (unsigned long*)dst + 1;
                *(unsigned long*)dst = v;
            } while (--i);

        dst = (unsigned char*)((unsigned long*)dst + 1) - 1;

        n &= 3;
    }

    if (n)
        do {
            dst = (unsigned char*)dst + 1;
            *(unsigned char*)dst = v;
        } while (--n);

    return;
}

extern int lbl_8029F054[5];
extern char lbl_802030F8[];
extern unsigned char gTRKCPUState[];
extern unsigned char gTRKState[];
extern "C" void MWTRACE(int, const char*, ...);
extern "C" int fn_801ED468(unsigned long rangeStart, unsigned long rangeEnd, int stepOver)
{
    int result;

    if (stepOver) {
        result = 0x703;
    } else {
        lbl_8029F054[3] = rangeStart;
        lbl_8029F054[4] = rangeEnd;
        lbl_8029F054[1] = 1;
        lbl_8029F054[0] = 1;
        MWTRACE(1, lbl_802030F8);
        *(unsigned long*)(gTRKCPUState + 0x1f8) |= 0x400;
        if (lbl_8029F054[1] == 0 || lbl_8029F054[1] == 0x10) {
            lbl_8029F054[2]--;
        }
        *(int*)(gTRKState + 0x98) = 0;
        result = 0;
    }
    return result;
}

