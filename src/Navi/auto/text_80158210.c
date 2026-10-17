// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158210-0x8015827c (5 functions). split_file divides it into the game's real files.

extern int lbl_802FF4AC;
extern "C" void fn_80158210(void)
{
}

extern int lbl_802FF4EC;
extern int lbl_802FF4F0;
extern int lbl_802FF4BC;
extern "C" void fn_80158214(int param_1)
{
    int a = *(int*)(param_1 + 0);
    int b = *(int*)(param_1 + 4);
    lbl_802FF4EC = a;
    lbl_802FF4F0 = b;
}

extern "C" void fn_80158228(void) {
    lbl_802FF4AC = 0;
}

extern "C" int fn_80158234(int param_1)
{
    unsigned char* p = (unsigned char*)lbl_802FF4BC + param_1 * 0xf4;
    if (p[0xec] == 0) {
        return -1;
    }
    return *(int*)(p + 0xe8);
}

extern "C" int fn_8015825C(int param_1)
{
    char* p = (char*)lbl_802FF4BC + param_1 * 0xf4;
    return p[0xec] == 0;
}

