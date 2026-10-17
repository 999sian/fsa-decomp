// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80115178-0x80115610 (9 functions). split_file divides it into the game's real files.

extern "C" void fn_801155E0(unsigned char* param_1, int param_2);
extern "C" int fn_80114C5C(void*, void*, void*);
extern "C" int fn_80114C94(void*, void*, void*);
#pragma push
#pragma use_lmw_stmw off
extern "C" int fn_80115178(int* param_1, void* param_2, void* param_3) {
    char* p = (char*)param_1[0];
    int n = param_1[1];
    int ret = 1;
    while (n-- > 0) {
        char* cur = p;
        p += 0xc;
        if (fn_80114C5C(cur, param_2, param_3) == 0) {
            ret = 0;
        }
    }
    return ret;
}
#pragma pop
extern "C" void* fn_801151EC(int* param_1, void* param_2, void* param_3) {
    char* p = (char*)param_1[0];
    int n = param_1[1];
    while (n-- > 0) {
        char* cur = p;
        p += 0xc;
        void* r = (void*)fn_80114C94(cur, param_2, param_3);
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

extern "C" int fn_80115564(unsigned char* param_1) {
    struct Flags {
        unsigned char b7 : 1;
        unsigned char b6 : 1;
        unsigned char rest : 6;
    };
    Flags* f = (Flags*)param_1;
    if (f->b6 == 1) {
        f->b6 = 0;
        return 1;
    }
    return 0;
}

extern "C" unsigned char* fn_80115590(unsigned char* param_1) {
    struct Flags {
        unsigned char b7 : 1;
        unsigned char b6 : 1;
        unsigned char rest : 6;
    };
    Flags* f = (Flags*)param_1;
    f->b7 = 0;
    f->b6 = 1;
    f->rest = 0;
    return param_1;
}

extern "C" void fn_801155C0(unsigned char* param_1, int param_2) {
    fn_801155E0(param_1, param_2);
}

extern "C" void fn_801155E0(unsigned char* param_1, int param_2) {
    *param_1 = (*param_1 & ~0x80) | ((1 << 7) & 0x80);
    *param_1 = (*param_1 & ~0x40) | ((0 << 6) & 0x40);
    *param_1 = (*param_1 & ~0x3f) | (param_2 & 0x3f);
}

