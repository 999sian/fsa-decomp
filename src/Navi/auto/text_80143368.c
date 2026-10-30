// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80143368-0x8014342c (1 functions). split_file divides it into the game's real files.

extern unsigned char* lbl_802FF390;
extern "C" void* fn_801428B4(unsigned char);
extern "C" void fn_80142ACC(void*, void*);
extern "C" void fn_80143368(unsigned char id) {
    unsigned long i;
    void* p;
    if (*(unsigned char**)(lbl_802FF390 + 0x14e4) == 0) {
        for (i = 0; i < 0x40; i++) {
            p = fn_801428B4(i);
            if (p != 0) fn_80142ACC(lbl_802FF390 + 0x14e8, p);
        }
    } else {
        for (i = 0; i < 0x40; i++) {
            if (id == (*(unsigned char**)(lbl_802FF390 + 0x14e4))[i] && (p = fn_801428B4(i)) != 0)
                fn_80142ACC(lbl_802FF390 + id * 0x38 + 0x14e8, p);
        }
    }
}
