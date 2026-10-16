// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void* lbl_804954D8[];
extern "C" void* lbl_804954F8[];
extern "C" void* lbl_80495480[];
extern "C" void* lbl_80495450[];
extern "C" void __dt__11JAIAudienceFv(void*, short);

class JAIAudience {
public:
    ~JAIAudience();
};

extern "C" void** fn_8003CAB0(void** p, short del) {
    if (p != 0) {
        *p = &lbl_804954D8;
        if (p != 0) {
            *p = &lbl_804954F8;
            if (p != 0) {
                *p = &lbl_80495480;
                if (p != 0) {
                    *p = &lbl_80495450;
                    ((JAIAudience*)p)->~JAIAudience();
                }
            }
        }
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void** fn_8003CB40(void** p, short del) {
    if (p != 0) {
        *p = lbl_804954F8;
        if (p != 0) {
            *p = lbl_80495480;
            if (p != 0) {
                *p = lbl_80495450;
                __dt__11JAIAudienceFv(p, 0);
            }
        }
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_8003CBC0(char* p) {
    return *(void**)(p + 0x50);
}

extern "C" void* fn_8003CE04(char* p, int i) {
    void* r = *(void**)(p + i * 4 + 0x18);
    if (r != 0) {
        return r;
    }
    return 0;
}

void fn_8003D260(void) {
}
