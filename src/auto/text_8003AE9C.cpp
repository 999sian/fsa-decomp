// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" char lbl_80495450[];
extern "C" char lbl_80495480[];
extern "C" void __dt__11JAIAudienceFv(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" float lbl_8053B298;
extern "C" float lbl_8053B29C;
extern "C" float lbl_8053B2A0;
extern "C" void* fn_8003AF0C(void* p, short f) {
    if (p) {
        *(void**)p = lbl_80495450;
        __dt__11JAIAudienceFv(p, 0);
        if (f > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_8003B0B0(float* v) {
    v[0] = lbl_8053B298;
    v[2] = lbl_8053B298;
    v[1] = lbl_8053B29C;
    v[3] = lbl_8053B2A0;
    v[4] = lbl_8053B29C;
}
