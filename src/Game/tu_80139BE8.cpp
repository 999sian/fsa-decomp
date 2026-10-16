#include "types.h"

class VObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
};

extern "C" void fn_8043D644(void*);
extern "C" void fn_8043D8B4(void*);
extern "C" void fn_8016DB60(void*);
extern void* lbl_8053AED0;
extern unsigned char* lbl_8053AB10;
extern "C" void fn_801F857C(void*);
extern "C" void fn_8030361C(void);
extern "C" void fn_8038D454(void);
extern "C" void* fn_8011921C(void);
extern "C" void fn_801184F0(void*, int);
extern unsigned char lbl_8053ACD0;
extern "C" void fn_80139BE8(unsigned char* p) {
    fn_801F857C(*(void**)(p + 8));
    lbl_8053ACD0 = 0;
    fn_8030361C();
    fn_8038D454();
    fn_801184F0(fn_8011921C(), 1);
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235c] = 0;
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235d] = 0;
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235e] = 0;
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235f] = 0;
}

extern "C" void fn_8043D5F0(void*);
extern "C" void fn_8038D4A8(void);
extern "C" void fn_8043DC98(void*);
extern "C" void fn_8044B8EC(void*);
extern "C" void fn_8013B438(void*);
extern "C" void fn_8023F2BC(void);
extern "C" void fn_801F8658(void*);
extern "C" void fn_801902D0(void*);
extern "C" void fn_8016DA6C(void*);
extern "C" void fn_80139C5C(void) {
    fn_8043D5F0(lbl_8053AED0);
    fn_8038D4A8();
}

extern "C" void fn_80139C84(unsigned char* p) {
    fn_8043DC98(lbl_8053AED0);
    if (*(void**)(p + 0x2c) != 0) {
        fn_8044B8EC(*(void**)(p + 0x2c));
    }
}

extern "C" void fn_80139CC4(unsigned char* p) {
    struct VObj { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); };
    fn_8013B438(lbl_8053AB10);
    (*(VObj**)(p + 0xc))->v0C();
    fn_8013B438(lbl_8053AB10);
    fn_8023F2BC();
    fn_801F8658(*(void**)(p + 8));
    fn_801902D0(*(void**)(p + 0x20));
    if (lbl_8053AB10[0x39] == 0) {
        fn_8016DA6C(*(void**)(p + 0x24));
    }
}

extern "C" void fn_80139D3C(unsigned char* p) {
    if (lbl_8053AB10[0x39] == 0) {
        fn_8016DB60(*(void**)(p + 0x24));
    }
}

extern "C" void fn_80139D70(void) {
    fn_8043D644(lbl_8053AED0);
    fn_8043D8B4(lbl_8053AED0);
}

extern "C" void fn_8016EDB0(void*);
extern "C" void fn_801F8E4C(void*);
extern "C" void fn_8023F088(void);
extern "C" void fn_8023F78C(void);
extern "C" void fn_8023F728(void);
extern "C" void fn_802A3D80(void*);
extern "C" void fn_8043EDF8(void*);
extern "C" void fn_80439AB0(void*);
extern "C" void fn_8037AFC0(void*);
extern "C" void fn_8019169C(void*);
extern "C" void fn_8038D870(void);
extern "C" unsigned char fn_803B8C90(void);
extern unsigned char* lbl_8053AAF8;
extern unsigned char lbl_80529DEC[];
extern "C" void fn_8013A1A4(unsigned char* p) {
    fn_8016EDB0(*(void**)(p + 0x24));
    fn_801F8E4C(*(void**)(p + 8));
    void* obj = *(void**)(p + 0xc);
    ((void (**)(void*))(*(void**)obj))[3](obj);
    if (lbl_8053AAF8[0x7e] == 1) {
        fn_8023F088();
    }
    fn_8023F78C();
    fn_8023F728();
    lbl_8053ACD0 = 1;
    fn_802A3D80(*(void**)(p + 0x10));
    fn_8043EDF8(*(void**)(p + 0x14));
    fn_80439AB0(*(void**)(p + 0x18));
    fn_8037AFC0(*(void**)(p + 0x1c));
    fn_8019169C(*(void**)(p + 0x20));
    fn_8038D870();
    *(void**)(p + 0x34) = 0;
    lbl_80529DEC[0x240] = 0;
    *(short*)(lbl_80529DEC + 0x1f4) = 0;
    *(short*)(lbl_80529DEC + 0x1f6) = 0;
    *(short*)(lbl_80529DEC + 0x1f8) = 0;
    *(short*)(lbl_80529DEC + 0x1fa) = 0;
    lbl_80529DEC[0x24f] = fn_803B8C90();
    lbl_80529DEC[0x253] = 0;
}

extern "C" void fn_8013A884(const unsigned char* src) {
    unsigned char* dst = *(unsigned char**)(lbl_8053AB10 + 0x2c);
    dst[4] = src[0];
    dst[5] = src[1];
    dst[6] = src[2];
    dst[7] = src[3];
}

