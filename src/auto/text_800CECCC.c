

extern void* lbl_8049AE38[];
extern void* lbl_8049AE24[];
extern void* lbl_8049AE10[];
extern "C" void fn_800CF2B0(void*** p) {
    void** a = lbl_8049AE38;
    *p = a;
    *p = lbl_8049AE24;
}

extern "C" void fn_800CF370(void** p) {
    *p = lbl_8049AE10;
    *p = lbl_8049AE38;
}

extern "C" int fn_800D0618(void)
{
    return 6;
}

