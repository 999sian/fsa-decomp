// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80115178-0x80115610 (9 functions). split_file divides it into the game's real files.

extern "C" void fn_801155E0(void);
extern "C" int fn_80114C5C(void*, void*, void*);
extern "C" int fn_80114C94(void*, void*, void*);
extern "C" int fn_801151EC(int* param_1, void* param_2, void* param_3) {
    char* p = (char*)param_1[0];
    int n = param_1[1];
    while (n-- > 0) {
        char* cur = p;
        p += 0xc;
        int r = fn_80114C94(cur, param_2, param_3);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

extern "C" void fn_8011526C(int* param_1, int param_2) {
    param_1[0] = param_2;
    param_1[1] = 0;
}

extern "C" void fn_801155C0(void) {
    fn_801155E0();
}
