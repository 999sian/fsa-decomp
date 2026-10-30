// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80149ba4-0x80149c88 (1 functions). split_file divides it into the game's real files.

extern short lbl_802FF400;
extern short lbl_802FF402;
extern short lbl_802FF404;
extern short lbl_802FF406;
extern short lbl_802FF408;
extern short lbl_802FF40A;
extern short lbl_802DCFA8[0x200][2];
extern "C" void fn_801581EC(void);
extern "C" void fn_80149BA4(void) {
    int i;
    lbl_802FF400 = 0;
    lbl_802FF402 = 0;
    lbl_802FF404 = 0;
    lbl_802FF406 = 0;
    lbl_802FF40A = 0;
    lbl_802FF408 = 0;
    for (i = 0; i < 0x200; i++) {
        lbl_802DCFA8[i][0] = 0;
        lbl_802DCFA8[i][1] = 0;
    }
    fn_801581EC();
}
