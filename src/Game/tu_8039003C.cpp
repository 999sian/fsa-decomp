

typedef unsigned char u8;
extern u8* lbl_8053AAF8;
extern u8* lbl_8053ADF8;
extern u8* lbl_8053AE00;
extern "C" void fn_8040F480(void*);
extern "C" void fn_80416BD0(void*);
extern "C" void fn_80390088(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_8040F480(lbl_8053ADF8);
    } else {
        fn_80416BD0(lbl_8053AE00);
    }
}
