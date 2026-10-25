#pragma exceptions off
#include "JSystem/JAudio/JAUSoundMgr.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" char lbl_80495450[];
extern "C" char lbl_80495480[];
extern "C" void __dt__11JAIAudienceFv(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" float lbl_8053B298;
extern "C" float lbl_8053B29C;
extern "C" float lbl_8053B2A0;
extern "C" void* dtor_8003AE9C(void* p, short f) {
    if (p) {
        *(void**)p = lbl_80495480;
        if (p) {
            *(void**)p = lbl_80495450;
            __dt__11JAIAudienceFv(p, 0);
        }
        if (f > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

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

extern "C" JAUSoundMgr* __dt__11JAUSoundMgrFv(JAUSoundMgr* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->~JAUSoundMgr();
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8003B0B0(float* v) {
    v[0] = 1.0f;
    v[2] = 1.0f;
    v[1] = 0.0f;
    v[3] = 0.5f;
    v[4] = 0.0f;
}
