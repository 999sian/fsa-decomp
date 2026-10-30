// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80147740-0x8014780c (2 functions). split_file divides it into the game's real files.

typedef struct {
    unsigned char unk0[8];
    unsigned char unk8;
    unsigned char unk9[0x64 - 9];
} Unk802D5CA8;

extern unsigned char lbl_802FF3F8;
extern unsigned char lbl_802FF3F9;
extern int lbl_802FF3FC;
extern unsigned char lbl_802D4A80[];
extern Unk802D5CA8 lbl_802D5CA8[];

extern "C" void fn_80147740(void) {
    int i;
    lbl_802FF3F8 = 0;
    lbl_802FF3F9 = 3;
    for (i = 0; i < lbl_802D4A80[0x210]; i++) {
        lbl_802D5CA8[i].unk8 = 0;
    }
    lbl_802FF3FC = 0;
}

extern "C" void fn_80147808(void) {}
