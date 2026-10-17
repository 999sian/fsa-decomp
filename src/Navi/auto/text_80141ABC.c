// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80141abc-0x80141b20 (1 functions). split_file divides it into the game's real files.

extern "C" {
extern int* lbl_802FF3AC;
extern int* lbl_802FF3A8;
}
void fn_80141ABC(int* param_1)
{
    int* next;

    if (param_1[1] != 0) {
        *(int*)param_1[1] = param_1[0];
    } else {
        lbl_802FF3AC = (int*)param_1[0];
    }
    next = (int*)param_1[0];
    if (next != 0) {
        next[1] = param_1[1];
    }
    param_1[0] = (int)lbl_802FF3A8;
    if (lbl_802FF3A8 != 0) {
        lbl_802FF3A8[1] = (int)param_1;
    }
    param_1[1] = 0;
    lbl_802FF3A8 = param_1;
    *((char*)param_1 + 8) = 2;
}
