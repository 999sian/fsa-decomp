#include "types.h"

extern "C" const float lbl_8053D628;
extern "C" char lbl_804A03A8[];
extern "C" void __dt__10JUTTextureFv(void*, int);
void operator delete(void*);
extern "C" void fn_801601E0(char* p) {
    u32* w = (u32*)(p + 0x204);
    for (int i = 0; i < 32; i++) w[i] = 0;
    p[0x284] = 0;
    *(float*)(p + 0x288) = lbl_8053D628;
    *(float*)(p + 0x28c) = lbl_8053D628;
}

extern "C" void* fn_80160278(void* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_804A03A8;
        __dt__10JUTTextureFv(*(void**)((char*)p + 0x294), 1);
        __dt__10JUTTextureFv(*(void**)((char*)p + 0x290), 1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

