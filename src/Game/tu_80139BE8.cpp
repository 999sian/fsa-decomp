#include "types.h"

extern "C" void fn_8043D644(void*);
extern "C" void fn_8043D8B4(void*);
extern "C" void fn_8016DB60(void*);
extern void* lbl_8053AED0;
extern unsigned char* lbl_8053AB10;
extern "C" void fn_80139D3C(unsigned char* p) {
    if (lbl_8053AB10[0x39] == 0) {
        fn_8016DB60(*(void**)(p + 0x24));
    }
}

extern "C" void fn_80139D70(void) {
    fn_8043D644(lbl_8053AED0);
    fn_8043D8B4(lbl_8053AED0);
}

extern "C" void fn_8013A884(const unsigned char* src) {
    unsigned char* dst = *(unsigned char**)(lbl_8053AB10 + 0x2c);
    dst[4] = src[0];
    dst[5] = src[1];
    dst[6] = src[2];
    dst[7] = src[3];
}

