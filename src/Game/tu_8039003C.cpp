extern void* lbl_80557E40;
extern void* lbl_80558260;



typedef unsigned char u8;

struct VObj {
    virtual void v00(int);
    virtual void v01();
};
extern char lbl_804AF480[];
extern u8 lbl_80529DEC[];
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void __dl__FPv(void* p);
extern u8* lbl_8053AAF8;
extern u8* lbl_8053ADF8;
extern u8* lbl_8053AE00;
extern "C" void fn_8040F480(void*);
extern "C" void fn_80416BD0(void*);
extern u8* lbl_8053AD80;
extern "C" int fn_8040F474(void);
extern "C" int fn_80414F6C(void);
extern "C" int fn_8039003C(void) {
    if (lbl_8053AD80 != 0) {
        if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
            return fn_8040F474();
        } else {
            return fn_80414F6C();
        }
    }
    return 6;
}

extern void* lbl_80558268;
extern "C" void fn_8044A28C(void*);
extern "C" void fn_8044C994(void*);
extern "C" void fn_80390088(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_8044A28C(lbl_80558260);
    } else {
        fn_8044C994(lbl_80558268);
    }
}

extern "C" void fn_804108B4(void*);
extern "C" void fn_804170B0__10TU80414F6CFv(void*);
extern "C" void fn_803900C8(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_804108B4(lbl_8053ADF8);
    } else {
        fn_804170B0__10TU80414F6CFv(lbl_8053AE00);
    }
}

extern "C" void fn_804111C4(void*);
extern void* lbl_80557E40;
extern void* lbl_80558260;
extern "C" void fn_80444988(void*);
extern "C" void fn_80390108(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_80444988(lbl_80558260);
    }
}

extern "C" void fn_80411230(void*);
extern "C" void fn_804170EC(void*);
extern "C" void fn_8039013C(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_80411230(lbl_8053ADF8);
    } else {
        fn_804170EC(lbl_8053AE00);
    }
}

