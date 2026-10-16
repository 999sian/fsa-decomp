// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"
#include "JSystem/JAudio/System/JASHeapCtrl.h"

extern "C" const f32 lbl_8053B2CC;
extern "C" const f64 lbl_8053B2E0;
extern "C" void* lbl_8049552C[];
extern "C" void* lbl_80495518[];
extern "C" void __dt__10JAIAudibleFv(void*, short);

extern "C" void* lbl_804954D8[];
extern "C" void* lbl_804954F8[];
extern "C" void* lbl_80495480[];
extern "C" void* lbl_80495450[];
extern "C" void __dt__11JAIAudienceFv(void*, short);

class JAIAudience {
public:
    ~JAIAudience();
};

extern "C" void fn_8003C8D8(char* p) {
    *(f32*)(p + 0x3c) = (*(f32*)(p + 0x20) - *(f32*)(p + 0x1c)) / *(f32*)(p + 0x10);
    *(f32*)(p + 0x40) = (*(f32*)(p + 0x18) - *(f32*)(p + 0x1c)) / *(f32*)(p + 0x14);
    *(f32*)(p + 0x44) = (*(f32*)(p + 0xc) - lbl_8053B2CC) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
    *(f32*)(p + 0x48) = (f32)((f64)*(u32*)(p + 0x38) - lbl_8053B2E0) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
    *(f32*)(p + 0x4c) = (*(f32*)(p + 0x28) - *(f32*)(p + 0x24)) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
}

extern "C" void** fn_8003CAB0(void** p, short del) {
    if (p != 0) {
        *p = lbl_804954D8;
        if (p != 0) {
            *p = lbl_804954F8;
            if (p != 0) {
                *p = lbl_80495480;
                if (p != 0) {
                    *p = lbl_80495450;
                    __dt__11JAIAudienceFv(p, 0);
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
    void* r = ((void**)(p + 0x18))[i];
    if (r != 0) {
        return r;
    }
    return 0;
}

extern "C" void fn_8003CF84(void* param_1, void** param_2) {
    struct VObj {
        virtual void v00(int);
    };
    if (param_2 != 0) {
        ((VObj*)param_2)->v00(1);
    }
}

extern "C" void* lbl_80495518[];
extern "C" void __dt__10JAIAudibleFv(void*, short);
extern "C" void** fn_8003D200(void** p, short del) {
    if (p != 0) {
        *p = lbl_80495518;
        __dt__10JAIAudibleFv(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

void fn_8003D260(void) {
}
