// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bcfe0-0x801bd538 (3 functions). split_file divides it into the game's real files.

extern "C" unsigned short lbl_802FE978;
extern "C" unsigned short fn_801BD4E0(void) {
    if (lbl_802FE978 <= 1) {
        return lbl_802FE978;
    }
    switch (*(long*)0x800000CC) {
    case 0:
        if (*(volatile unsigned short*)0xCC00206E & 2) {
            lbl_802FE978 = 1;
        } else {
            lbl_802FE978 = 0;
        }
        break;
    default:
        lbl_802FE978 = 0;
        break;
    }
    return lbl_802FE978;
}
